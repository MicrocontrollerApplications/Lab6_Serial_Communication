
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PLIB_USART_H
#define	PLIB_USART_H

#include <xc.h> // include processor files - each processor file is guarded.  

/* ***D E F I N I T I O N S *** */
#define USART_TX_INT_ON     0b11111111  // Transmit interrupt on
#define USART_TX_INT_OFF    0b01111111  // Transmit interrupt off
#define USART_RX_INT_ON     0b11111111  // Receive interrupt on
#define USART_RX_INT_OFF    0b10111111  // Receive interrupt off
#define USART_BRGH_HIGH     0b11111111  // High baud rate
#define USART_BRGH_LOW      0b11101111  // Low baud rate
#define USART_CONT_RX       0b11111111  // Continuous reception
#define USART_SINGLE_RX     0b11110111  // Single reception
#define USART_SYNC_MASTER   0b11111111  // Synchrounous master mode
#define USART_SYNC_SLAVE    0b11111011  // Synchrounous slave mode
#define USART_NINE_BIT      0b11111111  // 9-bit data
#define USART_EIGHT_BIT     0b11111101  // 8-bit data
#define USART_SYNCH_MODE    0b11111111  // Synchronous mode
#define USART_ASYNCH_MODE   0b11111110  // Asynchronous mode
#define USART_ADDEN_ON      0b11111111  // Enables address detection
#define USART_ADDEN_OFF     0b11011111  // Disables address detection
#define BAUD_IDLE_CLK_HIGH  0b11111111  // idle state for clock is a high level
#define BAUD_IDLE_CLK_LOW   0b11101111  // idle state for clock is a low level
#define BAUD_16_BIT_RATE    0b11111111  // 16-bit baud generation rate
#define BAUD_8_BIT_RATE     0b11110111  // 8-bit baud generation rate
#define BAUD_WAKEUP_ON      0b11111111  // RX pin monitored
#define BAUD_WAKEUP_OFF     0b11111101  // RX pin not monitored
#define BAUD_AUTO_ON        0b11111111  // auto baud rate measurement enabled
#define BAUD_AUTO_OFF       0b11111110  // auto baud rate measurement disabled
#define BAUD_IDLE_RX_PIN_STATE_HIGH     0b11011111  // idle state for RX pin is high level
#define BAUD_IDLE_RX_PIN_STATE_LOW      0b11111111  // idle state for RX pin is low level
#define BAUD_IDLE_TX_PIN_STATE_HIGH     0b11101111  // idle state for TX pin is high level
#define BAUD_IDLE_TX_PIN_STATE_LOW      0b11111111  // idle state for TX pin is low level

/* status bits */
union USART1
{
  unsigned char val;
  struct
  {
    unsigned RX_NINE:1;         // Receive Bit 8 if 9-bit mode is enabled
    unsigned TX_NINE:1;         // Transmit Bit 8 if 9-bit mode is enabled
    unsigned FRAME_ERROR:1;     // Framing Error for usart
    unsigned OVERRUN_ERROR:1;   // Overrun Error for usart
    unsigned fill:4;
  };
};
extern union USART1 USART1_Status;

/* P R O T O T Y P E S */
#define baud1USART(config)  BAUDCON1 = config
void Open1USART(unsigned char, unsigned int);
#define DataRdy1USART()     (PIR1bits.RC1IF)
#define Busy1USART()        (!TXSTA1bits.TRMT)
#define Close1USART()       RCSTA1&=0b01001111; TXSTA1bits.TXEN=0; PIE1&=0b11001111
char Read1USART (void);
void Write1USART ( char data);
void puts1USART ( char *data);
void putrs1USART ( const char *data);

#endif	/* PLIB_USART_H */

