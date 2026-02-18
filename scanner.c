#include "scanner.h"
void scanner_start(cli_config_t *cfg )
{
    int current_port_status = -1; //Read this status with the ports, to see if they are active or not.

    //Take the IP and use TCP protocol to read the ports for the selected IP.
    //When the ports are read, check if they are active or not and return the status of the ports to a .JSON status.
    //Read the ports at the designated address until the end_port.
}