/*Determine the status code produced in the scanner. If the scanner produces a code that requires a graceful exit, handle it hear.
If it instead produces a code that requires it to print to a JSON file (like a good connection to a port & port status)*/
#include "cli_port_helper.h"

void port_status_helper(port_status_t status) 
{
    switch(status)
    {
        case STATUS_OPEN:
            //Print in JSON and continue

        case STATUS_CLOSED:
            //Print in JSON and continue

        case STATUS_TIMEOUT:
            //Print in JSON and continue

        case STATUS_ERR:
            //Print in JSON and continue

        case STATUS_SOCKET_CREATION_FAILED:
            //Print in console, and then exit gracefully

        case STATUS_SOCKET_CREATION_SUCCES:
            //Print in console and then continue program
    
      
    }
}