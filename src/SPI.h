/*
 * SPI.h
 *
 *  Created on: Jun 12, 2015
 *      Author: helgalis
 */

#ifndef SPI_H_
#define SPI_H_
#include <string>
using  namespace std;
class SPI {
private:
	int client_socket;
	std::string get_cmd(string &fisrt_line);
public:
	SPI(int client_sock);
	~SPI();
	void send_msg(string msg);
	void recieve();
	char* get_msg_line();
	void run();
};

#endif /* SPI_H_ */
