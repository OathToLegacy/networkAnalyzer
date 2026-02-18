//**THIS HELPER IS ONLY FOR MESSAGES, WHILE MAIN HANDLES EXIT CODES**/
#include "cli_error_helper.h"
#include <stdio.h>

int cli_error_helper(cli_error_t err)
{
    switch (err)
    {
    case ERR_OK:
        
        return 0;
        
    case ERR_INVALIDFORMAT:
        printf("The argument format is invalid. Make sure IPs are in A.B.C.D format\n");
        return 1;
        
    case ERR_OUTOFBOUNDS:
        printf("The input IP has a number out of bounds. Make sure the IP is valid and between 0 & 255\n");
        return 2;
        
    case ERR_INVALIDCHARACTER:
        printf("There is an invalid character in the argument. Make sure to only use numerics separated by '.'\n");
        return 3;
        
    case ERR_LEADINGZERO:
        printf("There is a leading 0 in the argument. Make sure IP format is no 0A.B.C.D\n");
        return 4;
        
    case ERR_BADLENGTH:
        printf("There is too many or too few octets in the argument make sure your IP is in format A.B.C.D\n");
        return 5;
        
    case ERR_BADARGCOUNT:
        printf("There are too many or too few arguments in the input. Make sure the only arguments are program name and IP\n");
        return 6;
        
    case ERR_BADOCTET:
        printf("One or more of your octets are an invalid form. Make sure octets are 1 through 3 numbers per octet\n");
        return 7;
        
    case ERR_BADPORTRANGE:
        printf("One or more of your port range inputs is out of bounds. Supports scanning 1 <= start range <= end <= 65335 ");
        return 8;

    case ERR_INVALIDPORTCHAR:
        printf("There is an invalid character in your port range input. Make sure to only use 0-9");
        return 9;
    case ERR_NOPORTDIGITS:
        printf("There was an input of arguments, but they don't contain any digits");
        return 10;
    default:
        printf("An unexpected error has occurred. Exiting program\n");
        return 99;
        
    }
    return 9; //Another unexpected error has occured
}