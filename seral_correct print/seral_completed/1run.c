#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash1.h"
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
    int c;
    printf("enter the hash function to be used \n1 for my hash \n2 for md5\n3 for sha1\n4 for sha256 \n5 for sha512\n");
    scanf("%d",&c);
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
	switch(c){
		case 1:while((read = getline(&line[i], &len,fp))!=-1){
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
			          printf("string found, it is ***** %s *******\n",argv[2]);
			          printf("The hashes computed are \nbuf_the read string %s ::::   %s\n",line[i],buf);
			          printf("buf2 the input string %s ::::   %s",argv[2],buf2);
			          break;
		            }

		            i++;
	            }
	            break;

	    case 2:    printf("case 2 entered");
	               while((read = getline(&line[i], &len,fp))!=-1){
		           printf("Retrieved line of length %zu:\n",read);
		           printf("%s",line[i]);
		           int x=strlen(line[i]);
		           line[i][x]='\0';
		           line[i][x-1]='\0';
		           char buf0[hash_siz],buf[hash_siz],buf2[hash_siz];
		           strcpy(buf,line[i]);
		           //printf(" this is the line in the buffer %s",buf);
		           md5(line[i],buf);
		           //printf(" the has for this is buf %s\n",buf);
		           //printf("hash out \n");
		           //char* buf2=NULL;
		
		           strcpy(buf2,argv[2]);
		           //printf("the buffer 2 content is %s\n",buf2);
		           md5(argv[2],buf2);
		           int u=strcmp(buf2,buf);
		           printf("here is the difference %d\n",u);
		           if(strcmp(buf2,buf)==0){
			          printf("string found, it is ***** %s ******\n",argv[2]);
			          printf("The hashes computed are \nbuf_the read string %s ::::   %s\n",line[i],buf);
			          printf("buf2 the input string %s ::::   %s",argv[2],buf2);
			          break;
		            }

		            i++;
	            }
	            break;

	    case 3:printf("case 3 entered");
	               while((read = getline(&line[i], &len,fp))!=-1){
		           printf("Retrieved line of length %zu:\n",read);
		           printf("%s",line[i]);
		           int x=strlen(line[i]);
		           line[i][x]='\0';
		           line[i][x-1]='\0';
		           char buf0[hash_siz],buf[hash_siz],buf2[hash_siz];
		           strcpy(buf,line[i]);
		           //printf(" this is the line in the buffer %s",buf);
		           sha1(line[i],buf);
		           //printf(" the has for this is buf %s\n",buf);
		           //printf("hash out \n");
		           //char* buf2=NULL;
		
		           strcpy(buf2,argv[2]);
		           //printf("the buffer 2 content is %s\n",buf2);
		           sha1(argv[2],buf2);
		           int u=strcmp(buf2,buf);
		           printf("here is the difference %d\n",u);
		           if(strcmp(buf2,buf)==0){
			          printf("string found, it is ******* %s *******\n",argv[2]);
			          printf("The hashes computed are \nbuf_the read string %s ::::   %s\n",line[i],buf);
			          printf("buf2 the input string %s ::::   %s",argv[2],buf2);
			          break;
		            }

		            i++;
	            }
	            break;

	    case 4:printf("case 4 entered");
	               while((read = getline(&line[i], &len,fp))!=-1){
		           printf("Retrieved line of length %zu:\n",read);
		           printf("%s",line[i]);
		           int x=strlen(line[i]);
		           line[i][x]='\0';
		           line[i][x-1]='\0';
		           char buf0[hash_siz],buf[hash_siz],buf2[hash_siz];
		           strcpy(buf,line[i]);
		           //printf(" this is the line in the buffer %s",buf);
		           sha256(line[i],buf);
		           //printf(" the has for this is buf %s\n",buf);
		           //printf("hash out \n");
		           //char* buf2=NULL;
		
		           strcpy(buf2,argv[2]);
		           //printf("the buffer 2 content is %s\n",buf2);
		           sha256(argv[2],buf2);
		           int u=strcmp(buf2,buf);
		           printf("here is the difference %d\n",u);
		           if(strcmp(buf2,buf)==0){
			          printf("string found, it is ******** %s *******\n",argv[2]);
			          printf("The hashes computed are \nbuf_the read string %s ::::   %s\n",line[i],buf);
			          printf("buf2 the input string %s ::::   %s",argv[2],buf2);
			          break;
		            }

		            i++;
	            }
	            break;
	    case 5:printf("case 5 entered");
	               while((read = getline(&line[i], &len,fp))!=-1){
		           printf("Retrieved line of length %zu:\n",read);
		           printf("%s",line[i]);
		           int x=strlen(line[i]);
		           line[i][x]='\0';
		           line[i][x-1]='\0';
		           char buf0[hash_siz],buf[hash_siz],buf2[hash_siz];
		           strcpy(buf,line[i]);
		           //printf(" this is the line in the buffer %s",buf);
		           sha512(line[i],buf);
		           //printf(" the has for this is buf %s\n",buf);
		           //printf("hash out \n");
		           //char* buf2=NULL;
		
		           strcpy(buf2,argv[2]);
		           //printf("the buffer 2 content is %s\n",buf2);
		           sha512(argv[2],buf2);
		           int u=strcmp(buf2,buf);
		           printf("here is the difference %d\n",u);
		           if(strcmp(buf2,buf)==0){
			          printf("string found, it is ****** %s ******\n",argv[2]);
			          printf("The hashes computed are \nbuf_the read string %s ::::   %s\n",line[i],buf);
			          printf("buf2 the input string %s ::::   %s",argv[2],buf2);
			          break;
		            }

		            i++;
	            }
	            break;
	



}

	fclose(fp);
	//if(line)
	//	free(line);
	exit(EXIT_SUCCESS);

} 
