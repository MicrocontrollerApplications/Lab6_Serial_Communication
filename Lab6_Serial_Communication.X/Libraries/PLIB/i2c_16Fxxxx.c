/** INCLUDES *******************************************************/

#include <xc.h>
#include "i2c_16Fxxxx.h"

//#define SDA TRISBbits.TRISB4 // I2C bus
//#define SCL TRISBbits.TRISB6 //
//#define SCL_IN PORTBbits.RB6 //
//#define SDA_IN PORTBbits.RB4 //

#define _XTAL_FREQ 48000000

/*I2C Implementation*/
void InitI2C1(void)
{
    ANSELBbits.ANSB4 = 0;

    SSP1CON1bits.SSPEN = 1;

    SSP1ADD = 0x1D;//0x77; // 100kHz  TODO outside

    SSPCON1 = 0x28;
    SSPSTAT = 0x00;

}

/*
Function: I2CSend
Return:
Arguments: dat - 8-bit data to be sent on bus
data can be either address/data byte
Description: Send 8-bit data on I2C bus
 */
void WriteI2C1(unsigned char dat)
{
    SSP1BUF = dat; /* Move data to SSPBUF */
//    while (BF); /* wait till complete data is sent from buffer */
    while (SSP1STATbits.BF); /* wait till complete data is sent from buffer */
    IdleI2C1();
    __delay_us(5);/* wait for any pending transfer */
}

/*
Function: I2CRead
Return: 8-bit data read from I2C bus
Arguments:
Description: read 8-bit data from I2C bus
 */
unsigned char ReadI2C1(void)
{
    /* Reception works if transfer is initiated in read mode */
    SSP1CON2bits.RCEN = 1; /* Enable data reception */
    while (!SSP1STATbits.BF); /* wait for buffer full */
    return SSP1BUF; /* Read and return buffer */
}


///*
//Function: I2CStart
//Return:
//Arguments:
//Description: Send a start condition on I2C Bus
// */
//void StartI2C1()
//{
//
//    SSP1CON2bits.SEN = 1; /* Start condition enabled */
//    while (SSP1CON2bits.SEN); /* automatically cleared by hardware */
//}
//
///*
//Function: I2CStop
//Return:
//Arguments:
//Description: Send a stop condition on I2C Bus
// */
//void StopI2C1()
//{
//    SSP1CON2bits.PEN = 1; /* Stop condition enabled */
//    while (SSP1CON2bits.PEN); /* Wait for stop condition to finish */
//}
//
///*
//Function: I2CRestart
//Return:
//Arguments:
//Description: Sends a repeated start condition on I2C Bus
// */
//void RestartI2C1() {
//    SSP1CON2bits.RSEN = 1; /* Repeated start enabled */
//    while (SSP1CON2bits.RSEN); /* wait for condition to finish */
//}
//
///*
//Function: I2CAck
//Return:
//Arguments:
//Description: Generates acknowledge for a transfer
// */
//void AckI2C1() {
//
//    SSP1CON2bits.ACKDT = 0; /* Acknowledge data bit, 0 = ACK */
//    SSP1CON2bits.ACKEN = 1; /* Ack data enabled */
//    while (SSPCON2bits.ACKEN); /* wait for ack data to send on bus */
//}
//
///*
//Function: I2CNck
//Return:
//Arguments:
//Description: Generates Not-acknowledge for a transfer
// */
//void NotAckI2C1() {
//    SSP1CON2bits.ACKDT = 1; /* Acknowledge data bit, 1 = NAK */
//    SSP1CON2bits.ACKEN = 1; /* Ack data enabled */
//    while (SSP1CON2bits.ACKEN); /* wait for ack data to send on bus */
//}
//
///*
//Function: I2CWait
//Return:
//Arguments:
//Description: wait for transfer to finish
// */
//void IdleI2C1() {
//    while ((SSP1CON2 == 0x1F) || (SSP1STAT == 0x04));
//    /* wait for any pending transfer */
//}
