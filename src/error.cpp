/*
 * error.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: helgalis
 */

#include "error.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void error(int status, int err, const char* msg) {
	printf(msg, "%s \n");
	if (err)
		fprintf( stderr, ": %s (%d)\n", strerror(err), err);
	if (status)
		exit(status);
}




