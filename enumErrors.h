//List of error enumerables for CLI sanitization
#ifndef ENUM_ERRORS_H
#define ENUM_ERRORS_H

typedef enum 
{
    ERR_OK = 0, //0 means to continue with Scan
    ERR_INVALIDFORMAT =     1,
    ERR_OUTOFBOUNDS =       2,
    ERR_INVALIDCHARACTER =  3,
    ERR_LEADINGZERO =       4,
    ERR_BADLENGTH =         5,
    ERR_ARGOVERFLOW =       6,
    ERR_BADOCTET =          7
}cli_error_t;

#endif