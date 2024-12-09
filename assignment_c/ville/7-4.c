#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


#define SLIP_END 0xC0
#define SLIP_ESC 0xDB
#define SLIP_ESC_END 0xDC
#define SLIP_ESC_ESC 0xDD

void (*global_call_back)(const unsigned char *, int);

void register_slip_frame_callback(void (*call_back)(const unsigned char *, int)) {
    global_call_back = call_back;
}

void process_slip_data(int (*read_byte)(void)) {
    int bytecode = read_byte();
    int last_bytecode = 0;
    unsigned char data[256];
    memset(data, 0, 256);
    int data_index = 0;

    while (bytecode != EOF) {
        if (bytecode == SLIP_END) {
            if (data_index > 0) {
                // send data to callback
                if (global_call_back) {
                    global_call_back(data, data_index);
                }
                last_bytecode = 0;
                memset(data, 0, 256);
                data_index = 0;
            }
        } else if (bytecode == SLIP_ESC) {
            last_bytecode = SLIP_ESC; //219
        } else if (last_bytecode == SLIP_ESC && bytecode == SLIP_ESC_END) {
            //219 220
            // printf("data: %d; data_index:%d\n", SLIP_END, data_index);
            data[data_index] = SLIP_END;
            data_index++;
            last_bytecode = 0;
        } else if (last_bytecode == SLIP_ESC && bytecode == SLIP_ESC_ESC) {
            //219 221
            // printf("data: %d; data_index:%d\n", SLIP_ESC, data_index);
            data[data_index] = SLIP_ESC;
            // data[data_index] = 0;
            data_index++;
            last_bytecode = 0;
        } else {
            // printf("data: %d; data_index:%d\n", bytecode, data_index);
            data[data_index] = bytecode;
            data_index++;
            last_bytecode = 0;
        }
        bytecode = read_byte();
    }
}

// int main(void) {
//     printf("%X\n", 192);
//     printf("%X\n", 182);
//     printf("%X\n", 34);
//     printf("%X\n", 228);
//     printf("%X\n", 221);
// }