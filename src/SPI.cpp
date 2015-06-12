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
	this->client_socket = client_sockt;
}
SPI::~SPI() {
	close(client_socket);
}
void SPI::recieve() {
	char buffer[MAX_LINE_LEN];
	unsigned int offset = 0;
	char current_char[1];
	while (offset < sizeof(buffer)) {
		if (recv(client_socket, current_char, 1, 0) > 0) {
			if (offset == 0
					&& (current_char[0] == END_OF_LINE[0]
							|| END_OF_LINE[1] == current_char[0]))
				continue;
			else {
				offset++;
				buffer[offset] = current_char[0];
			}
			if (offset >= 2 && (buffer[offset - 1] == END_OF_LINE[0]
						&& buffer[offset] == END_OF_LINE[1]))
					break;
		}
	}
	std::cout<<buffer<<endl;
}
void SPI::send_msg(string msg) {
	send(client_socket, (void*) msg.c_str(), sizeof(msg), 0);
}
void SPI::run() {
	send_msg("Connect to 0.005 server");
	bool exit = false;
	while (exit) {

	}
}

