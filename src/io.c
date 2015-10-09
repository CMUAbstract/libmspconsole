#include <stdint.h>
#include <wisp-base.h>

#include <stdlib.h>

int putchar(int c)
{
    uint8_t ch = c;
    UART_send(&ch, 1);
    return c;
}

int puts_no_newline(const char *ptr)
{
    unsigned len = 0;
    const char *p = ptr;

    while (*p++ != '\0')
        len++;

    UART_send((uint8_t *)ptr, len);
    return len;
}

int puts(const char *ptr)
{
    unsigned len;

    len = puts_no_newline(ptr);

    // Semantics of puts are annoying...
    putchar('\n');

    return len;
}
