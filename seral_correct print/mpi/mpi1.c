#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _GNU_SOURCE
#define siz 1024
#define hash_siz 1024
#include "mpi.h"
void hash(char* string,char output_buffer[128]){
	//printf("\n\n\n%%%%%%%%%%%%%% hash function recievied %sand the difference in next line%%%%%%%%%%%%%%%%\n\n\n",string);
	//int t=strcmp(string,"hash");
	//printf("\n %d   \n",t);
	int l=0,k=0;
		l=strlen(string);
	for(int i=0;i<128;i++){
		output_buffer[i]=0;
		k=(i+1)%l;
		output_buffer[i]=string[k];
	}
	output_buffer[128]='\0';
	//printf("*the has of %s is %s\n",string,output_buffer);
}
int main(int argc,char* argv[]){
	int rank,size;
	FILE *fp;
	char filename[50];
	strcpy(filename,argv[1]);
	fp=fopen(filename,"r");
	char* line[siz];
	for(int i=0;i<siz;i++){
		line[i]=NULL;
	}
	if(fp==NULL)
		exit(EXIT_FAILURE);
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		//root process, reads and sends including itself the buffer
		//hash value and difference with the string has to be sent back
		size_t len=0;
		ssize_t read=0;
		int i=0;
		while((read = getline(&line[i],&len,fp))!=-1){
			printf("Retrieved line of lengeth %zu:\n",read);
			printf("%s",line[i]);
			int x=strlen(line[i]);
			line[i][x]='\0';
			line[i][x]='\0';
			MPI_Send(&x,1,MPI_INT,i,2*i,MPI_COMM_WORLD);
			printf("sent size to process %d and it is %d\n",i,x);
			MPI_Send(line[i],x,MPI_CHAR,i,i,MPI_COMM_WORLD);
			printf("the string sent is %s\n",line[i]);
			
			i++;

		}
		printf("********************** all sends done ***************");
	}
	char buf0[hash_siz],buf[hash_siz],buf2[hash_siz];
	int x1; //len of string
	printf(" \n \n \n \n");
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Recv(&x1,1,MPI_INT,0,2*rank,MPI_COMM_WORLD,&status);
	//printf("received size is %d,\n",x1);
	for(int i=0;i<hash_siz;i++){
		buf[i]='\0';
	}
	MPI_Recv(buf0,x1,MPI_CHAR,0,rank,MPI_COMM_WORLD,&status);
	
	buf0[x1]='\0';
	buf0[x1-1]='\0';
	//printf("************just filler open*********\n");
	//printf("this is process lalalla %d:      and the string received is %s\n",rank,buf0);
	
	hash(buf0,buf);
	//printf("\n ^^^^^^^^^^hash of buf done ^^^^^^^^^^\n");
	strcpy(buf2,argv[2]);
	//hash(argv[2],buf2);
	int u=strcmp(buf2,buf);
	printf("here is the difference %d\n",u);

 /*   int t=0;
    t=strcmp(buf,argv[2]);
	printf("the difference is %d\n",t);
*/	
    if(u==0){
			printf("string found, it is %s",buf0);
		}
	//printf("************just filler close*********\n");
	
		MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}