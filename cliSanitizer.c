#include "cliSanitizer.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

cli_error_t cli_sanitizer(int argc, char* argv[], cli_config_t *out_cfg) //Takes CLI arg count, arg strings, and a struct to save OK IP to
{
    //Validate in this order Length, characters, format
    //Make sure argument count is not 0, nor > 1 ~FOR NOW~
    //Check that the IP is in proper format and is an actual IP.
        //Check that there is four total numbers seperated by '.'
        //Each number 0 <= x <= 255
        //Only digits no other chracters
        //No number has a leading 0.
        //Enumerate exact errors

    if(argc != 2) {return ERR_ARGOVERFLOW;}
    
    
    cli_error_t err = validate_IPV4(argv[1]);
    if(err != ERR_OK){return err;}

    //Only after successful sanitization
    strncpy(out_cfg->ip, argv[1], sizeof(out_cfg->ip));
    out_cfg->ip[sizeof(out_cfg->ip) - 1] = '\0';

    return err;

}

cli_error_t validate_IPV4(char* s)
{
    int dotCount = 0;
    int octetCount = 0;
    int i = 0;
    int n = strlen(s);

    while(i < n)
    {
        if(s[i] == '.'){return ERR_BADOCTET;}
        int value = 0;
        int digitCount = 0;
        bool leadingZero = false;

        while ( i < n && isdigit((unsigned char)s[i]))
        {
            if(digitCount == 0 && s[i] == '0'){leadingZero = true;}
            value = value *10 + (s[i] - '0');
            digitCount++;
            i++;
        }
        if(digitCount == 0){return ERR_BADLENGTH;}

        if(value < 0 || value > 255){return ERR_OUTOFBOUNDS;}

        if(leadingZero == true && digitCount > 1){return ERR_LEADINGZERO;}

        octetCount++;

        if(i < n)
        {
            if(s[i] == '.'){dotCount++; i++;}
            else{return ERR_INVALIDCHARACTER;}
        }
    
    }
    if(dotCount != 3 || octetCount != 4){return ERR_INVALIDFORMAT;}
    
    return ERR_OK;
}