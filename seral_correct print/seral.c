#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _GNU_SOURCE
#define siz 1024
#define hash_siz 1024
void hash(char* string,char output_buffer[128]){
	int l=0,k=0;
		l=strlen(string);
	for(int i=0;i<128;i++){
		output_buffer[i]=0;
		k=(i+1)%l;
		output_buffer[i]=string[k];
	}
	output_buffer[128]='\0';
	printf("the hash of %s is %s \n",string,output_buffer);
}
int main(int argc, char* argv[]){
	FILE *fp;
	char filename[50];
	strcpy(filename,argv[1]);
	fp=fopen(filename,"r");
    char* line[siz];
    for(int i=0;i<siz;i++){

    	line[i]=NULL;
    }
	size_t len=0;
	ssize_t read=0;
	if(fp == NULL)
		exit(EXIT_FAILURE);
	int i=0;
	printf("the input line is %s\n",argv[2]);
	while((read = getline(&line[i], &len,fp))!=-1){
		printf("Retrieved line of length %zu:\n",read);
		printf("%s",line[i]);
		int x=strlen(line[i]);
		line[i][x]='\0';
		line[i][x-1]='\0';
		char buf0[hash_siz],buf[hash_siz],buf2[hash_siz];
		strcpy(buf,line[i]);
		hash(line[i],buf);
		strcpy(buf2,argv[2]);
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
	exit(EXIT_SUCCESS);

} 