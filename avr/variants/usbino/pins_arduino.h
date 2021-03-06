/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/
  Copyright (c) 2007 David A. Mellis 
  Edited By Md. Khairul hasan
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  Changelog
  -----------
  11/25/11  - ryan@ryanmsutton.com - Add pins for Sanguino 644P and 1284P
  07/15/12  - ryan@ryanmsutton.com - Updated for arduino0101
  12/14/13  - khairulhasanmd@gmail.com - Modified it for supporting Atmega32A

  Improvements by Kristian Sloth Lauszus, lauszus@gmail.com
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>


#define PIN_SPI_SS   (4)
#define PIN_SPI_MOSI (5)
#define PIN_SPI_MISO (6)
#define PIN_SPI_SCK  (7)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_WIRE_SDA (17)
#define PIN_WIRE_SCL (16)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define LED_BUILTIN 0 //this pin has changed

#define PIN_A0 (31) //analog pins are reversely oriented 
#define PIN_A1 (30)
#define PIN_A2 (29)
#define PIN_A3 (28)
#define PIN_A4 (27)
#define PIN_A5 (26)
#define PIN_A6 (25)
#define PIN_A7 (24)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

//                      +-----\/-----+
//          (D 0) PB0  1|            |40  PA0 (D 31)(AI 0)
//          (D 1) PB1  2|            |39  PA1 (D 30)(AI 1)
//     INT2 (D 2) PB2  3|            |38  PA2 (D 29)(AI 2)
//      PWM (D 3) PB3  4|            |37  PA3 (D 28)(AI 3)
//          (D 4) PB4  5|            |36  PA4 (D 27)(AI 4)
//          (D 5) PB5  6|            |35  PA5 (D 26)(AI 5)
//          (D 6) PB6  7|            |34  PA6 (D 25)(AI 6)
//          (D 7) PB7  8|            |33  PA7 (D 24)(AI 7)
//              RESET  9|            |32  AREF
//                VCC 10| ATMEGA 32A |31  GND
//                GND 11|            |30  AVCC
//              XTAL2 12|            |29  PC7 (D 23)
//              XTAL1 13|            |28  PC6 (D 22)
//          (D 8) PD0 14|            |27  PC5 (D 21)
//          (D 9) PD1 15|            |26  PC4 (D 20)
//    INT0 (D 10) PD2 16|            |25  PC3 (D 19)
//    INT1 (D 11) PD3 17|            |24  PC2 (D 18)
//     PWM (D 12) PD4 18|            |23  PC1 (D 17)
//     PWM (D 13) PD5 19|            |22  PC0 (D 16)
//         (D 14) PD6 20|            |21  PD7 (D 15) PWM
//                      +------------+
//


#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? 31 - (p): -1) // ((p < 8) ? (p) + 24 : -1) was this
#define analogPinToChannel(p)       ((p) < 8 ? (p) : (p) >= 24 ? 31 - (p) : -1) //


#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 12 || (p) == 13 || (p) == 15)//done

#define digitalPinToPCICR(p)        ( (((p) >= 0) && ((p) <= 31)) ? (&PCICR) : ((uint8_t *)0) )
//                                  ( ((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))

//                                  ( ((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCICRbit(p)     ( (((p) >= 24) && ((p) <= 31)) ? 0 : \
                                    ( (((p) >=  0) && ((p) <=  7)) ? 1 : \
                                    ( (((p) >= 16) && ((p) <= 23)) ? 2 : \
                                    ( (((p) >=  8) && ((p) <= 15)) ? 3 : \
                                    0 ) ) ) )

//                                  (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSK(p)        ( (((p) >= 24) && ((p) <= 31)) ? (&PCMSK0) : \
                                    ( (((p) >=  0) && ((p) <=  7)) ? (&PCMSK1) : \
                                    ( (((p) >= 16) && ((p) <= 23)) ? (&PCMSK2) : \
                                    ( (((p) >=  8) && ((p) <= 15)) ? (&PCMSK3) : \
                                    ((uint8_t *)0) ) ) ) )

//                                  (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))
#define digitalPinToPCMSKbit(p)     ( (((p) >= 24) && ((p) <= 31)) ? (31 - (p)) : \
                                    ( (((p) >=  0) && ((p) <=  7)) ? (p) : \
                                    ( (((p) >= 16) && ((p) <= 23)) ? ((p) - 16) : \
                                    ( (((p) >=  8) && ((p) <= 15)) ? ((p) - 8) : \
                                    0 ) ) ) )
                                    
//                                  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))
#define digitalPinToInterrupt(p)    ((p) == 10 ? 0 : ((p) == 11 ? 1 : ((p) == 2 ? 2 : NOT_AN_INTERRUPT)))

#ifdef ARDUINO_MAIN
// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &DDRA,
        (uint16_t) &DDRB,
        (uint16_t) &DDRC,
        (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &PORTA,
        (uint16_t) &PORTB,
        (uint16_t) &PORTC,
        (uint16_t) &PORTD,
};
const uint16_t PROGMEM port_to_input_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &PINA,
        (uint16_t) &PINB,
        (uint16_t) &PINC,
        (uint16_t) &PIND,
};
const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
        PB, /* 0 */
        PB,
        PB,
        PB,
        PB,
        PB,
        PB,
        PB,
        PD, /* 8 */
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PC, /* 16 */
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PA, /* 24 */
        PA,
        PA,
        PA,
        PA,
        PA,
        PA,
        PA  /* 31 */
};
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
        _BV(0), /* 0, port B */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 8, port D */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 16, port C */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(7), /* 24, port A */
        _BV(6),
        _BV(5),
        _BV(4),
        _BV(3),
        _BV(2),
        _BV(1),
        _BV(0)
};
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
        NOT_ON_TIMER,   /* 0  - PB0 */
        NOT_ON_TIMER,   /* 1  - PB1 */
        NOT_ON_TIMER,   /* 2  - PB2 */
        TIMER0A,        /* 3  - PB3 */
        NOT_ON_TIMER,   /* 4  - PB4 */
        NOT_ON_TIMER,   /* 5  - PB5 */
        NOT_ON_TIMER,   /* 6  - PB6 */
        NOT_ON_TIMER,   /* 7  - PB7 */
        NOT_ON_TIMER,   /* 8  - PD0 */
        NOT_ON_TIMER,   /* 9  - PD1 */
        NOT_ON_TIMER,   /* 10 - PD2 */
        NOT_ON_TIMER,   /* 11 - PD3 */
        TIMER1B,        /* 12 - PD4 */
        TIMER1A,        /* 13 - PD5 */
        NOT_ON_TIMER,   /* 14 - PD6 */
        TIMER2,         /* 15 - PD7 */ //or timer2a?
        NOT_ON_TIMER,   /* 16 - PC0 */
        NOT_ON_TIMER,   /* 17 - PC1 */
        NOT_ON_TIMER,   /* 18 - PC2 */
        NOT_ON_TIMER,   /* 19 - PC3 */
        NOT_ON_TIMER,   /* 20 - PC4 */
        NOT_ON_TIMER,   /* 21 - PC5 */
        NOT_ON_TIMER,   /* 22 - PC6 */
        NOT_ON_TIMER,   /* 23 - PC7 */
        NOT_ON_TIMER,   /* 24 - PA0 */
        NOT_ON_TIMER,   /* 25 - PA1 */
        NOT_ON_TIMER,   /* 26 - PA2 */
        NOT_ON_TIMER,   /* 27 - PA3 */
        NOT_ON_TIMER,   /* 28 - PA4 */
        NOT_ON_TIMER,   /* 29 - PA5 */
        NOT_ON_TIMER,   /* 30 - PA6 */
        NOT_ON_TIMER   /* 31 - PA7 */
};
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.

#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial

#if defined(UBRR1H)
    #define SERIAL_PORT_HARDWARE1       Serial1
    #define SERIAL_PORT_HARDWARE_OPEN   Serial1
#endif

#endif