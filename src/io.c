#include <stdint.h>
#include <msp430.h>
#include <wisp-base.h>

#include <stdlib.h>

int putc(int c, void *stream)
{
    uint8_t ch = c;
    
    UART_send(&ch, 1);

    return c;
}

int puts(const char *ptr)
{
    unsigned len = 0;

    while (*ptr != '\0')
        len++;

    UART_send((uint8_t *)ptr, len);

    return len;
}
