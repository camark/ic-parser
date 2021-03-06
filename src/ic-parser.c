#define MODULE_API_EXPORTS
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "ic-parser.h"

MODULE_API IC_DATA ic_parse(uint8_t *reader_data, size_t size)
{
    IC_DATA res;
    memset(&res, 0, sizeof(res));

    //开始结束符
    uint8_t *terminator = reader_data + size - 1;
    if (*reader_data != 0x02 || *terminator != 0x03)
    {
        return res;
    }
    uint8_t *start = reader_data + 1;

    //卡号结束符
    const uint8_t end_sign[] = {0x0d, 0x0a};
    uint8_t *end = memmem(reader_data, size, end_sign, sizeof(end_sign));
    if (end == NULL)
    {
        return res;
    }
    uint8_t *device_id = end + sizeof(end_sign);

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