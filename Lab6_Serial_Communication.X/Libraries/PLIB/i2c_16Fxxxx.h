/* 
* File: i2C_16Fxxxx.h.h
*
*
* Created on Nov. 16, 2016, 12:09 PM
*/
#ifndef I2C_16F_H
#define I2C_16F_H

void InitI2C1();
void WriteI2C1(unsigned char dat);
unsigned char ReadI2C1();

//void StopI2C1();
//void StartI2C1();
//void RestartI2C1();
//void AckI2C1();
//void NotAckI2C1();
//void IdleI2C1();

/*
Function: I2CStart
Return:
Arguments:
Description: Send a start condition on I2C Bus
 */
#define StartI2C1() { SSP1CON2bits.SEN = 1; while (SSP1CON2bits.SEN); }

/*
Function: I2CStop
Return:
Arguments:
Description: Send a stop condition on I2C Bus
 */
#define StopI2C1() { SSP1CON2bits.PEN = 1;  while (SSP1CON2bits.PEN); }

/*
Function: I2CRestart
Return:
Arguments:
Description: Sends a repeated start condition on I2C Bus
 */
#define RestartI2C1() { SSP1CON2bits.RSEN = 1; while (SSP1CON2bits.RSEN); }

/*
Function: I2CAck
Return:
Arguments:
Description: Generates acknowledge for a transfer
 */
#define AckI2C1() { SSP1CON2bits.ACKDT = 0; SSP1CON2bits.ACKEN = 1; \
                    while (SSPCON2bits.ACKEN); }

/*
Function: I2CNck
Return:
Arguments:
Description: Generates Not-acknowledge for a transfer
 */
#define NotAckI2C1() { SSP1CON2bits.ACKDT = 1; SSP1CON2bits.ACKEN = 1; \
                       while (SSP1CON2bits.ACKEN); }

/*
Function: I2CWait
Return:
Arguments:
Description: wait for transfer to finish
 */
#define IdleI2C1() { while ((SSP1CON2 == 0x1F) || (SSP1STAT == 0x04)); }


#endif /* I2C_16F_H */
