#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>


int main() {
	int c;
	struct sockaddr_in server;
	c = socket(AF_INET, SOCK_STREAM,0);
	if(c< 0){
		printf("Eroare la creaer socketului client \n");
		return 1;
	}
	memset(&server,0,sizeof(server));
	server.sin_port = htons(1234);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(connect(c,(struct sockaddr *) &server,sizeof(server)) < 0){
		printf("Eroare la conectarea la server \n");
		return 1;
	}

}