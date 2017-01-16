/*
 * File:   main.c
 * Author: hexfox
 *
 * Created on 10 ноября 2014 г., 17:11
 */

#include <stdio.h>
#include <stdlib.h>
#define OCTET 4

void convert( unsigned int addr )
{
    unsigned int num[OCTET],
                next_addr[OCTET];
    int bits = 8;
    unsigned int shift_bits;
    int i;

    next_addr[0] = addr;
    shift_bits -= bits;
    num[0] = next_addr[0] >> shift_bits;

    for ( i = 0; i < OCTET-1; i ++ )
    {
        next_addr[i + 1] = next_addr[i] - ( num[i] << shift_bits ); // next subaddr
        shift_bits -= bits; // next shift
        num[i + 1] = next_addr[i + 1] >> shift_bits; // octet
    }

    printf( "%d.%d.%d.%d\n", num[0], num[1], num[2], num[3] );

}

int main(int argc, char** argv) {

    convert( 1336228747 );
    return (EXIT_SUCCESS);
}
