#include <stdio.h>

#define parity_type even
#define even 0
#define odd 1

char UART_parityCheck(unsigned char data)
{
    unsigned char count;
    for (int i = 0; i < 8; i++)
    {
        if (data & (1 << i))
        {
            count++;
        }
        else
        {
            // error
        }
    }

    if (count % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int UART_sendFrame(unsigned char data)
{
    unsigned int frame = 0;
    unsigned char start = 0;
    unsigned char parity = UART_parityCheck(data);
    unsigned char stop = 1;

    frame |= (start << 8);
    frame |= (data << 2);
    frame |= (parity << 1);
    frame |= (stop << 0);

    printf("%d\n", parity);
    printf("%d\n", frame);

    return frame;
}

int main(void)
{
    unsigned char data = 0b11001;
    unsigned int x = UART_sendFrame(data);

    printf("0b");
    for (int i = (sizeof(x) * 4); i > 0; i--)
    {
        if ((x & (1 << i)))
        {
            printf("%d", 1);
        }

        else
        {
            printf("%d", 0);
        }
    }
}