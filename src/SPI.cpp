/*
 * SPI.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: helgalis
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include "SPI.h"
using namespace std;
SPI::SPI(int client_sockt) {
this->client_socket= client_sockt;
}
SPI::~SPI(){
	close(client_socket);
}
void SPI::recieve(){}
void SPI::send(string msg){}
void SPI::run(){}

