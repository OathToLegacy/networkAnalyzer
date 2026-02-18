#include "cli_Sanitizer.h"
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

    if(argc != 4) {return ERR_BADARGCOUNT;} //Track to make sure there is an IP and a port range
    
    
    cli_error_t err = validate_IPV4(argv[1], out_cfg->ip, sizeof(out_cfg->ip));
    if(err != ERR_OK){return err;}
    err = validate_port(argv[2], argv[3], &out_cfg->start_port, &out_cfg->end_port);
    if(err != ERR_OK){return err;}
    
    //strncpy(out_cfg->start_port, argv[2], sizeof(out_cfg ->start_port));
    //strncpy(out_cfg->end_port, argv[3], sizeof(out_cfg->end_port));
    //Only after successful sanitization
    
    
    //out_cfg->start_port[sizeof(out_cfg->start_port) -1] = '\0';
    //out_cfg->end_port[sizeof(out_cfg->end_port) -1] = '\0';

    return err; //WITH ERR_OK, this means that both IP and port range are valid and to continue operating normally

}

static cli_error_t validate_IPV4(char* s, char *out_ip, size_t out_ip_size) //Validate the IPV4 that the use gave to make sure there is no errors before usage
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
        if(leadingZero == true && digitCount > 1){return ERR_LEADINGZERO;}

        if(digitCount == 0){return ERR_BADLENGTH;}

        if(value < 0 || value > 255){return ERR_OUTOFBOUNDS;}

        

        octetCount++;

        if(i < n)
        {
            if(s[i] == '.'){dotCount++; i++;}
            else{return ERR_INVALIDCHARACTER;}
        }
    
    }
    if(dotCount != 3 || octetCount != 4){return ERR_INVALIDFORMAT;}

    strncpy(out_ip, s, out_ip_size);
    out_ip[out_ip_size - 1] = '\0';

    return ERR_OK;
}

static cli_error_t validate_port(char *start, char* end, uint16_t *out_start, uint16_t *out_end)
{
    int max_port_range = 65535;
    int min_port_range = 0;
    //Validate in this order format, characters, bounds
    //Make sure that there is only numerics 0-9
   //Make sure that the port numbers are in range 
   //Make sure that the start port is less than the end port
   int i = 0;
   int n = strlen(start);
   int m =  strlen(end);
   int current_digit = 0;
   int start_int = 0;
   int end_int = 0;
   if(n == 0 || m == 0){return ERR_NOPORTDIGITS;} //No port range has been specified but is nothing.
    while(i < n)
    {
        if(!isdigit((unsigned char)start[i])){return ERR_INVALIDPORTCHAR;}
        current_digit = start[i] - '0';
        if(start_int > max_port_range / 10){return ERR_OUTOFBOUNDS;}
        if(start_int == max_port_range / 10 && current_digit > max_port_range  % 10){return ERR_OUTOFBOUNDS;}
        start_int = start_int * 10 + (current_digit);
        
        i++;
    }
    i = 0;
    while(i < m)
    {
        if(!isdigit((unsigned char)end[i])){return ERR_INVALIDPORTCHAR;}
        current_digit = end[i] - '0';
        if(end_int > max_port_range / 10){return ERR_OUTOFBOUNDS;}
        if(end_int == max_port_range / 10 && current_digit > max_port_range  % 10){return ERR_OUTOFBOUNDS;}
        end_int = end_int * 10 + (current_digit);
        
        i++;
    }
    if(start_int < min_port_range || start_int > max_port_range){ return ERR_OUTOFBOUNDS;}
    if(end_int < min_port_range || end_int > max_port_range ){return ERR_OUTOFBOUNDS;}
    if(start_int >= end_int){return ERR_BADPORTRANGE;}

    
    *out_start = (uint16_t) start_int; //save the start port to the config struct
    *out_end = (uint16_t) end_int; //save the end port to the config struct

    return ERR_OK; //The port range is valid and able to be used to scan.

}