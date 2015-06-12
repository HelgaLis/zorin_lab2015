/*
 * SPI.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: helgalis
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <netdb.h>
#include "SPI.h"
using namespace std;
SPI::SPI(int client_sockt) {
this->client_socket= client_sockt;
}
SPI::~SPI(){
	close(client_socket);
}
void SPI::recieve(){}
void SPI::send_msg(string msg){
	send(client_socket,(void*)msg.c_str(),sizeof(msg),0);
}
void SPI::run(){
	send_msg("Connect to 0.005 server");
	bool exit = false;
	while(exit){

	}
}

