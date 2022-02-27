#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SIZE 1
struct file_send {
	char m;
	int n;
	float f;
};
void main()
{
	struct file_send t1;
	int soccet;
	soccet = socket(AF_INET,SOCK_STREAM,0);
	if (soccet == -1) {
	printf("Socket has not been created yet \n");
	exit(0);
	}
	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(32351);
	serverAddr.sin_addr.s_addr = inet_addr("130.191.166.3");
	int connecting_status = connect(soccet,(struct sockaddr *) &serverAddr,sizeof(serverAddr));
	if(connecting_status == -1)
	{
		exit(-1);
	}
	printf("please enter a lower case character: ");
	scanf("%c", &t1.m);
	printf("please enter a integer: ");
	scanf("%d", &t1.n);
	printf("please enter a floating point number: ");
	scanf("%f", &t1.f);
	printf("character: %c integer: %d floatingpoint: %f",
	t1.m, t1.n, t1.f);
	printf("\n");
	FILE *fp;
	fp=fdopen(soccet,"w");
	if (fp == NULL)
	{
		exit(-1);
	}
	fprintf(fp, "%c\n", t1.m);
	fprintf(fp, "%d\n", t1.n);
	fprintf(fp, "%f\n", t1.f);
	//send(soccet, &t1.m, sizeof(char), 0);
	//send(soccet, &t1.n, sizeof(int), 0);
	//send(soccet, &t1.f, sizeof(float), 0);
	send(soccet, &t1, sizeof(struct file_send), 0);
	close(soccet);
}
