/*
 * ProcessingStr.h
 *
 *  Created on: Jun 12, 2015
 *      Author: helgalis
 */

#ifndef PROCESSINGSTR_H_
#define PROCESSINGSTR_H_
#include <string>
class ProcessingStr {
public:
	ProcessingStr();
	std::string get_first_word(std::string &line);
	std::string get_rest_of_line(std::string line);
	void get_statistics();
};


#endif /* PROCESSINGSTR_H_ */
