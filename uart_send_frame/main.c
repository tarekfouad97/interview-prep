#include <stdio.h>


#define parity_type even 
#define even 0
#define odd  1

char UART_parityCheck(unsigned char data){
    data^=data>>4;
    data^=data>>2;
    data^=data>>1;

    #if     parity_type == even
            return (~data)&1;
    #elif   parity_type == odd
            return (data)&1;
    #else
        /*Error*/
    #endif
}
int UART_sendFrame(unsigned char data){
    unsigned int  frame  = 0;
    unsigned char start  = 0;
    unsigned char parity = UART_parityCheck(data);
    unsigned char stop   = 1;

    // /*0+data+parity+stop*/
    // frame =  (frame&(start<<9))  
    frame = 67;
    printf("%d\n", parity);
    printf("0b");
    for(int i=0 ;i<8;i++){
        if(frame&(1<<i)){
            printf("%d", 1);
        }
        else {
            printf("%d", 0);
        }
    }
}

int main(void){
    unsigned char data = 0b1100110;
    UART_sendFrame(data);

}