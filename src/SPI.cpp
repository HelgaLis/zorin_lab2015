/*
 * SPI.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: helgalis
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <netinet/in.h>
#include <netdb.h>
#include "SPI.h"
#include "global.h"
using namespace std;
SPI::SPI(int client_sockt) {
this->client_socket= client_sockt;
}
SPI::~SPI(){
	close(client_socket);
}
void SPI::recieve(){
	char buffer[MAX_LINE_LEN];
	unsigned int offset;
	char current_char[1];
	for(offset=0; offset<sizeof(buffer);offset++){
		if(recv(client_socket,current_char,1,0)>0){

		}
		else
			break;

	}
}
void SPI::send_msg(string msg){
	send(client_socket,(void*)msg.c_str(),sizeof(msg),0);
}
void SPI::run(){
	send_msg("Connect to 0.005 server");
	bool exit = false;
	while(exit){

	}
}

