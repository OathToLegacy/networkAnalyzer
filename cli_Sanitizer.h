#include "enumErrors.h"
#include "cliConfig.h"
#include <stddef.h>

//CLI Sanitizer Prototype
#ifndef CLI_SANITIZER_H
#define CLI_SANITIZER_H
cli_error_t validate_port(char *start, char* end, uint16_t *out_start, uint16_t *out_end);
cli_error_t validate_IPV4(char* s, char *out_ip, size_t out_ip_size);
cli_error_t cli_sanitizer(int argc, char* argv[], cli_config_t *out_cfg);

#endif