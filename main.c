#include "cliSanitizer.h"
#include "cli_error_helper.h"
#include "cliConfig.h"
#include <stdio.h>

int main(int argc, char *argv[]) //Check enumErrors.h for exit codes
{
    cli_config_t cfg; //run through the scan
    cli_error_t err = cli_sanitizer(argc, argv, &cfg);
    int err_check = cli_error_helper(err);
    if(err_check != 0){return err_check;}
    
    //Call scanner function

    return 0; //clean exit of program
}