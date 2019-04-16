#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _GNU_SOURCE
#define siz 1024
#define hash_siz 1024
void hash(char* string,char output_buffer[128]){
	//printf("hash funciton reached \n");
	int l=0,k=0;
		l=strlen(string);
	for(int i=0;i<128;i++){
	//	printf("for loop inside \n");
	//	printf("%d \n",i);
		output_buffer[i]=0;
		
		k=(i+1)%l;
	//	printf("this is the k %d\n",k);

		output_buffer[i]=string[k];
	//	printf("the buffer output char %c ",string[k]);
	}
	//printf("for loop ended");
	output_buffer[128]='\0';
	//printf("the hash is %s",output_buffer);
}
int main(int argc, char* argv[]){

	FILE *fp;
	char filename[50];
	strcpy(filename,argv[1]);
	fp=fopen(filename,"r");
    char* line[siz];
    //char** line;
    //printf("done 1\n");
    for(int i=0;i<siz;i++){

    	line[i]=NULL;
    }
    //printf("while finished \n");
	size_t len=0;
	ssize_t read=0;
	if(fp == NULL)
		exit(EXIT_FAILURE);
	int i=0;
	printf("the input line is %s\n",argv[2]);
	//printf("while part before \n");
//	read = getline(&line[i],&len,fp);
//	printf(" this is the line %zu:\n",read);
	while((read = getline(&line[i], &len,fp))!=-1){
		printf("Retrieved line of length %zu:\n",read);
		printf("%s",line[i]);
		int x=strlen(line[i]);
		line[i][x]='\0';
		line[i][x-1]='\0';
		char buf0[hash_siz],buf[hash_siz],buf2[hash_siz];
		strcpy(buf,line[i]);
		//printf(" this is the line in the buffer %s",buf);
		hash(line[i],buf);
		//printf(" the has for this is buf %s\n",buf);
		//printf("hash out \n");
		//char* buf2=NULL;
		
		strcpy(buf2,argv[2]);
		//printf("the buffer 2 content is %s\n",buf2);
		hash(argv[2],buf2);
		int u=strcmp(buf2,buf);
		printf("here is the difference %d\n",u);
		if(strcmp(buf2,buf)==0){
			printf("string found, it is %s",argv[2]);
			break;
		}

		i++;
	}
	fclose(fp);
	//if(line)
	//	free(line);
	exit(EXIT_SUCCESS);

} 