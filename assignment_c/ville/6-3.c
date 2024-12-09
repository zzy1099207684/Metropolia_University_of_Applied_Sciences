//
// Created by zhiyo on 2024/10/14.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>


typedef struct {
    const char *text;
    int position;
} text_reader_ctx;


// implement the following two functions
void text_reader_init(text_reader_ctx *ctc, const char *str);

int text_reader_read(text_reader_ctx *ctx, char *buffer, int size);

void text_reader_init(text_reader_ctx *ctc, const char *str) {
    ctc->position = 0;
    ctc->text = str;
}

int text_reader_read(text_reader_ctx *ctx, char *buffer, int size) {
    const char *context = ctx->text;
    int pos = ctx->position;
    if(context[pos] == '\0') {
        return 0;
    }
    int buffer_index = 0;
    int i;
    for (i = pos; context[i] != '\0' && buffer_index < size - 1; i++) {
        buffer[buffer_index] = context[i];
        buffer_index++;

        if (context[i] == '\n') {
            ctx->position = i+1;
            buffer[buffer_index] = '\0';
            return buffer_index;
        }

    }
    buffer[buffer_index] = '\0';
    ctx->position = i;
    return buffer_index;
}
