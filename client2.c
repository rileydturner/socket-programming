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
	if (soccet == -1)
	{
		printf("Socket has not been created yet \n");
		exit(0);
	}
	struct sockaddr_in serverAddr, client2Addr; //
	socklen_t client2_length = sizeof(client2Addr);//
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(32351);
	serverAddr.sin_addr.s_addr = inet_addr("130.191.166.3");
	int connecting_status = connect(soccet,(struct sockaddr *) &serverAddr,sizeof(serverAddr));
	if(connecting_status == -1)
	{
		printf("cannot connect");
		exit(-1);
	}
	for(;;)
	{
		FILE *ft;
		ft=fdopen(soccet,"r");
		if (ft == NULL)
		{
			printf("file NULL\n");
			exit(-1);
		}
		recv(soccet, &t1, sizeof(struct file_send), 0);
		fscanf(ft, "%c", &t1.m);
		fscanf(ft, "%d", &t1.n);
		fscanf(ft, "%f", &t1.f);
		printf("NEW character: %c NEW integer: %d NEW
		floatingpoint: %f", t1.m, t1.n, t1.f);
		printf("\n");
	}
	close(soccet);
	exit(0);
} 