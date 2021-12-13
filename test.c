#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include  <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/wait.h>
#define _GNU_SOURCE

struct Student{
    int ID;
    float avg;
    char section[2];
    int Assignment1;
    int Assignment2;
    int Assignment3;
    int Assignment4;
};

int main(){

	pid_t fd = fork();

	if(fd==0)
	{
		struct Student student[401];
		int sz,fp;
		fp = open("test1.csv", O_RDONLY);

		if(fp == -1){
			printf("%s\n", "Failed to find file \n");
			exit(0);
		}

		char *buf = (char *) calloc(9000, sizeof(char));
		sz = read(fp, buf, 9000);

		buf[sz]='\0';

		close(fp);
		char arr[401][200];
		int j=0;
		int k=0;
		int count=0;

		for(int i=0;buf[i]!='\0';i++){
			arr[j][k++] = buf[i];
			if(buf[i]=='\n'){
				k=0;
				j++;
			}
		}

		char * delimiter = " ";

		for(int i=1;i<=400;i++){

			student[j].ID = atoi(strtok(arr[i],delimiter));
			strcpy(student[j].section,strtok(NULL,delimiter));
		    student[j].Assignment1 = atoi(strtok(NULL, delimiter));
		    student[j].Assignment2 = atoi(strtok(NULL, delimiter));
		    student[j].Assignment3 = atoi(strtok(NULL, delimiter));
		    student[j].Assignment4 = atoi(strtok(NULL, delimiter));
		    student[j].avg = (float)(student[j].Assignment1+student[j].Assignment2+student[j].Assignment3+student[j].Assignment4)/4;

		    if(student[j].section[0]=='A')
		    	printf("%d  %s  %d  %d  %d  %d   %f\n",student[j].ID,student[j].section,student[j].Assignment1,student[j].Assignment2,student[j].Assignment3,student[j].Assignment4,student[j].avg);

		}
		exit(0);
	}
	else if(fd>0){
		waitpid(fp,NULL,0);
		struct Student student[401];
		int sz,fp;
		fp = open("test1.csv", O_RDONLY);

		if(fp == -1){
			printf("%s\n", "Failed to find file \n");
			exit(0);
		}

		char *buf = (char *) calloc(9000, sizeof(char));

		sz = read(fp, buf, 9000);

		buf[sz]='\0';

		close(fp);
		char arr[401][200];
		int j=0;
		int k=0;
		int count=0;

		for(int i=0;buf[i]!='\0';i++){
			arr[j][k++] = buf[i];
			if(buf[i]=='\n'){
				k=0;
				j++;
			}
		}

		char * delimiter = " ";

		for(int i=1;i<=400;i++){

			student[j].ID = atoi(strtok(arr[i],delimiter));
			strcpy(student[j].section,strtok(NULL,delimiter));
		    student[j].Assignment1 = atoi(strtok(NULL, delimiter));
		    student[j].Assignment2 = atoi(strtok(NULL, delimiter));
		    student[j].Assignment3 = atoi(strtok(NULL, delimiter));
		    student[j].Assignment4 = atoi(strtok(NULL, delimiter));
		    student[j].avg = (float)(student[j].Assignment1+student[j].Assignment2+student[j].Assignment3+student[j].Assignment4)/4;
		    if(student[j].section[0]=='B')
		    	printf("%d  %s  %d  %d  %d  %d   %f\n",student[j].ID,student[j].section,student[j].Assignment1,student[j].Assignment2,student[j].Assignment3,student[j].Assignment4,student[j].avg);

		}

	}
	else{

		printf("forking failed\n");
	}


return 0;

}
