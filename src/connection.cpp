/*
 * connection.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: helgalis
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "connection.h"
#include "SPI.h"
#include "error.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#define isvalidsock(s) ( ( s ) >= 0 )
int create_socket(){
struct sockaddr_in local;
	int server_sock;
	const int on = 1;
	local.sin_family=AF_INET;
	local.sin_port = htons(8656);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	server_sock = socket(AF_INET, SOCK_STREAM,0);
	if(!isvalidsock(server_sock))
		error(1, errno, "socket call failed");
	if(setsockopt( server_sock, SOL_SOCKET, SO_REUSEADDR, &on,sizeof( on )))
		   error( 1, errno, "set socket option call failure" );

	if(bind(server_sock,(struct sockaddr*)&local,sizeof(local)))
	   error(1, errno,"bind call failure");

	if(listen(server_sock,1))
		error(1,errno,"listen call failed");

return server_sock;

}
void start_client_session(int client_sock, int server_sock) {
	//недописано, нужно уточнять реализацию
	pid_t pid;
	        if ( (pid = fork()) == 0) {
	           close(server_sock);
	           SPI * spi = new SPI(client_sock);
	           spi->run();
	           delete spi;
	            exit(0);
	        } else {
	            close(client_sock);
	        }
}
void start_server(){
	int server_sock = create_socket();
	struct sockaddr client_address;
	socklen_t addrLen= sizeof(client_address);
	while (true) {
		int client_sock = accept(server_sock, &client_address,&addrLen);
		if (!isvalidsock(client_sock))
			error(1, errno, "accept call failed");
		start_client_session(client_sock,server_sock);
	}
}


