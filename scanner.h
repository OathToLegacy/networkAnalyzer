//This is the scanner that the port range and the ip will be filtered into.
//This will only run if the IP and port are correct and have been correctly sanitized and checked for errors.
#include "cliConfig.h"
#include "port_status_enums.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>


#ifndef SCANNER_H
#define SCANNER_H
void scanner_run(); //This is what scans the ports


#endif