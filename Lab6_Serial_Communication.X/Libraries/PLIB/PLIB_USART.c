/*
 * File:   PLIB_USART.c
 * Author: blero
 *
 * Created on 5. Mai 2019, 12:07
 */

//#include <xc.h> // not needed in PLIB_USART.h
#include "PLIB_USART.h"

union USART1 USART1_Status;

/* I M P L E M E N T A T I O N S */

void Open1USART(unsigned char config, unsigned int spbrg) {
    TXSTA1 = 0; // Reset USART registers to POR state
    RCSTA1 = 0;

    if (config & 0x01) // Sync or async operation
        TXSTA1bits.SYNC = 1;

    if (config & 0x02) // 8- or 9-bit mode
    {
        TXSTA1bits.TX9 = 1;
        RCSTA1bits.RX9 = 1;
    }

    if (config & 0x04) // Master or Slave (sync only)
        TXSTA1bits.CSRC = 1;

    if (config & 0x08) // Continuous or single reception
        RCSTA1bits.CREN = 1;
    else
        RCSTA1bits.SREN = 1;

    if (config & 0x10) // Baud rate select (asychronous mode only)
        TXSTA1bits.BRGH = 1;

    if (config & 0x20) // Address Detect Enable
        RCSTA1bits.ADDEN = 1;

    // SENDB (asychronous mode only)  - need to be added

    if (config & 0x40) // Interrupt on receipt
        PIE1bits.RC1IE = 1;
    else
        PIE1bits.RC1IE = 0;

    if (config & 0x80) // Interrupt on transmission
        PIE1bits.TX1IE = 1;
    else
        PIE1bits.TX1IE = 0;

    SPBRG1 = spbrg; // Write baudrate to SPBRG1
    SPBRGH1 = spbrg >> 8; // For 16-bit baud rate generation

    TXSTA1bits.TXEN = 1; // Enable transmitter
    RCSTA1bits.SPEN = 1; // Enable receiver
}

char Read1USART(void) {
    char data; // Holds received data

    USART1_Status.val &= 0xf2; // Clear previous status flags

    if (RCSTA1bits.RX9) // If 9-bit mode
    {
        USART1_Status.RX_NINE = 0; // Clear the recieve bit 9 for USART1
        if (RCSTA1bits.RX9D) // according to the RX9D bit
            USART1_Status.RX_NINE = 1;
    }

    if (RCSTA1bits.FERR) // If a framing error occured
        USART1_Status.FRAME_ERROR = 1; // Set the status bit

    if (RCSTA1bits.OERR) // If an overrun error occured
        USART1_Status.OVERRUN_ERROR = 1; // Set the status bit

    data = RCREG1; // Read data

    return (data); // Return the received data
}

void Write1USART(char data) {
    if (TXSTA1bits.TX9) // 9-bit mode?
    {
        TXSTA1bits.TX9D = 0; // Set the TX9D bit according to the
        if (USART1_Status.TX_NINE) // USART1 Tx 9th bit in status reg
            TXSTA1bits.TX9D = 1;
    }

    TXREG1 = data; // Write the data byte to the USART2
}

void puts1USART(char *data) {
    while (*data) { // Transmit a byte
        while (Busy1USART());
        Write1USART(*data);
        data++;
    }
}

void putrs1USART(const char *data) {
    while (*data) { // Transmit a byte
        while (Busy1USART());
        Write1USART(*data);
        data++;
    }
}


