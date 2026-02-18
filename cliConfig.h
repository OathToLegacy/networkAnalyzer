#include <stdint.h>

#ifndef CLI_CONFIG_H
#define CLI_CONFIG_H

typedef struct //main struct taken from command line input. Use this to start TCP scan with these charcteristics
{                
//Add fields for target port range
    uint16_t start_port;
    uint16_t end_port;

    char ip[16]; //target IP
}cli_config_t;

#endif