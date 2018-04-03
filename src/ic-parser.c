#include <stdlib.h>
#include <string.h>
#include "ic-parser.h"

IC_DATA ic_parse(u_int8_t *reader_data, size_t size)
{
    IC_DATA res;
    memset(&res, 0, sizeof(res));

    //开始结束符
    u_int8_t *terminator = reader_data + size - 1;
    if (*reader_data != 0x02 || *terminator != 0x03)
    {
        return res;
    }
    u_int8_t *start = reader_data + 1;

    //卡号结束符
    const u_int8_t end_sign[] = {0x0d, 0x0a};
    u_int8_t *end = memmem(reader_data, size, end_sign, sizeof(end_sign));
    if (end == NULL)
    {
        return res;
    }
    u_int8_t *device_id = end + sizeof(end_sign);

    //机号
    if(device_id != terminator){
        res.device_id = *device_id;
    }

    //卡号
    char *card_id[end - start];
    memcpy(card_id, start, end - start);

    res.card_id = atoi(card_id);
    return res;
}