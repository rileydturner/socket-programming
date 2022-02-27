#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
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
	printf("SERVER");
	struct sockaddr_in serverAddr, clientAddr,
	client2Addr;//clientAddr
	socklen_t client_length=sizeof(clientAddr);
	socklen_t client2_length=sizeof(client2Addr);//
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(32351);
	serverAddr.sin_addr.s_addr = inet_addr("130.191.166.3");
	if (bind(server_socket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) !=0)
	{
		exit(0);
	}
	for(;;)
	{
		if ((listen(server_socket, 5)) != 0)
		{
			exit(0);
		}
		int clientSocket;
		clientSocket = accept(server_socket,(struct sockaddr *) &clientAddr, &client_length);
		if (clientSocket < 0)
		{
			exit(0);
		}
		FILE *fn;
		fn=fdopen(clientSocket,"r");
		if (fn == NULL)
		{
			exit(-1);
		}
		recv(clientSocket, &t1, sizeof(struct file_send), 0);
		fscanf(fn, "%c", &t1.m);
		fscanf(fn, "%d", &t1.n);
		fscanf(fn, "%f", &t1.f);
		printf("OLD character: %c OLD integer: %d OLD
		floatingpoint: %f \n", t1.m, t1.n, t1.f);
		if(t1.m == 'z')
		{
			t1.m = 'a';
		}
		else
		{
			t1.m = t1.m + 1;
		}
		t1.n = t1.n + t1.n;
		t1.f = t1.f + 1;
		////////////////////////////////////////////////////////////////
		if ((listen(server_socket, 5)) != 0)
		{
			exit(0);
		}
		int client2Socket; //
		client2Socket = accept(server_socket,(struct sockaddr *) &client2Addr, &client2_length); //
		fn=fdopen(client2Socket,"w");
		if (fn == NULL)
		{
			exit(-1);
		}
		fprintf(fn, "%c ", t1.m);
		fprintf(fn, "%d ", t1.n);
		fprintf(fn, "%f ", t1.f);
		printf("NEW character: %c NEW integer: %d NEW
		floatingpoint: %f", t1.m, t1.n, t1.f);
		printf("\n");
		send(client2Socket, &t1, sizeof(struct file_send), 0);//
	}
	close(server_socket);
}
