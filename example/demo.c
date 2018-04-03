#include <stdio.h>
#include <stdint.h>
#include "../src/ic-parser.h"

int main(){
    IC_DATA data;
    uint8_t reader_data[] = {0x02, 0x30, 0x30, 0x31, 0x32, 0x33, 0x38, 0x37, 0x39, 0x33, 0x32, 0x0D, 0x0A, 0x01, 0x03};
    data = ic_parse(reader_data, sizeof(reader_data));
    printf("card_id: %d\ndevice_id: %d\n", data.card_id, data.device_id);
}