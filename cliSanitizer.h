#include "enumErrors.h"
#include "cliConfig.h"

//CLI Sanitizer Prototype
#ifndef CLI_SANITIZER_H
#define CLI_SANITIZER_H
cli_error_t validate_IPV4(char *s);
cli_error_t cli_sanitizer(int argc, char* argv[], cli_config_t *out_cfg);

#endif