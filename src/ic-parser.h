#include <stdio.h>

#ifndef IC_PARSER_H
#define IC_PARSER_H

typedef struct{
    u_int32_t card_id;
    u_int16_t device_id;
} IC_DATA;

IC_DATA ic_parse(u_int8_t *reader_data, size_t size);

#endif