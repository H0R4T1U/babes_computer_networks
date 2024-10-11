#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>

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
    char* a;
    char* b;
    size_t size_a = 0;
    size_t size_b = 0;
    
    printf("Sirul a:");
    getline(&a,&size_a,stdin);
    printf("Sirul b:");
    getline(&b,&size_b,stdin);

    htonl(size_a);
    htonl(size_b);
    
    send(c,&size_a,sizeof(size_a),0);
    send(c,a,size_a * sizeof(char),0);
    send(c,&size_b,sizeof(size_a),0);
    send(c,b,size_b * sizeof(char),0);



}
