#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
	int s;
	struct sockaddr_in server,client;
	int c,l;
	s = socket(AF_INET,SOCK_STREAM,0);
	if(s < 0){
		printf("Eroare la creare socket");
		return 1;
	}
	memset(&server,0,sizeof(server));
	server.sin_port = htons(1234);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	if(bind(s,(struct sockaddr*) &server, sizeof(server)) <0){
		printf("Eroare la bind");
		return 1;
	}
	listen(s,5);

    l = sizeof(client);
    memset(&client,0,sizeof(client));

    while(1){
        size_t size_a,size_b;
        char* a;
        char* b;
        c = accept(s,(struct sockaddr *)&client,&l);
        printf("S-a conectat un client.\n");

        recv(c,&size_a,sizeof(size_a),MSG_WAITALL);
        ntohl(size_a);
        printf("S-a primit:%d",size_a);
        
        recv(c,&a,size_a * sizeof(char),MSG_WAITALL);
        ntohl(size_a);
        printf("S-a primit:%s",a);
        
        recv(c,&size_b,sizeof(size_b),MSG_WAITALL);
        printf("S-a primit:%d",size_b);
        
        recv(c,&a,size_a * sizeof(char),MSG_WAITALL);
        printf("S-a primit:%s",b);

    }
}
