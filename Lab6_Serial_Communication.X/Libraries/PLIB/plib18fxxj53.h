/* 
 * File:   plib18fxxj53.h
 * Author: vschilli
 *
 * Created on 9. März 2016, 16:16
 */

#ifndef PLIB18FXXJ53_H
#define	PLIB18FXXJ53_H


//  Pin Remapping	example SCK/SD0/SDI lines   B1/2/3 RP4/5/6
//		RPOR4 = PPSO_SCK2;  // RP4 as SCK2 (out)
//		RPOR5 = PPSO_SDO2;  // RP5 as SDO2 (out)
//		PPSI_SDI2 = RP6;    // RP6 as SDI2 (in)

typedef enum {
    RP1     = 1,
    RP2,
    RP3,
    RP4,
    RP5,
    RP6,
    RP7,
    RP8,
    RP9,
    RP10,
    RP11,
    RP12,
    RP13,
    RP17    = 17,
#if defined(__18F47J53)
    RP18,
    RP19,
    RP20,
    RP21,
    RP22,
    RP23,
    RP24
#else
    RP18
#endif
}TYPE_PPSPIN;


typedef enum {
    PPSO_NULL       = 0,
    PPSO_C1OUT,
    PPSO_C2OUT,
    PPSO__C3OUT,
    PPSO_TX2_CK2    = 6,
    PPSO_DT2,
    PPSO_SDO2       = 10,
    PPSO_SCK2,
    PPSO_SSDMA,
    PPSO_ULPOUT,
    PPSO_CCP1_P1A,
    PPSO_P1B,
    PPSO_P1C,
    PPSO_P1D,
    PPSO_CCP2_P2A,
    PPSO_P2B,
    PPSO_P2C,
    PPSO_P2D,
    PPSO_CCP3_P3A,
    PPSO_P3B,
    PPSO_P3C,
    PPSO_P3D
}TYPE_PPSOUT;

#define PPSI_INT1       RPINR1
#define PPSI_INT2       RPINR2
#define PPSI_INT3       RPINR3
#define PPSI_T0CKI      RPINR4
#define PPSI_T3CKI      RPINR6
#define PPSI_T5CKI      RPINR15
#define PPSI_CCP1       RPINR7
#define PPSI_CCP2       RPINR8
#define PPSI_CCP3       RPINR9
#define PPSI_T1G        RPINR12
#define PPSI_T3G        RPINR13
#define PPSI_T5G        RPINR14
#define PPSI_RX2_DT2    RPINR16
#define PPSI_CK2        RPINR17
#define PPSI_SDI2       RPINR21
#define PPSI_SCK2IN     RPINR22
#define PPSI_SS2IN      RPINR23
#define PPSI_FLT0       RPINR24


#endif  /* PLIB18FXXJ53_H */
