#ifndef PORT_STATUS_ENUMS_H
#define PORT_STATUS_ENUMS_H

typedef enum
{
    STATUS_OPEN = 0,
    STATUS_CLOSED = 1,
    STATUS_TIMEOUT = 2,
    STATUS_ERR = 3
}port_status_t;

#endif