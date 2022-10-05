/********************************************************************************
* gpio.h: Definitioner, deklarationer samt inkluderingsdirektiv f�r 
*         GPIO-implementering med mikrodator ATmega328P.
********************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

/* Klockfrekvens: */
#define F_CPU 16000000UL /* 16 MHz klockfrekvens. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Bibliotek inneh�llande information om I/O-register. */
#include <util/delay.h> /* Bibliotek f�r implementering av f�rdr�jning. */

/* Makrodefinitioner: */
#define LED1 1    /* Lysdiod 1 ansluten till pin 9 / PORTB1. */
#define LED2 2    /* Lysdiod 2 ansluten till pin 10 / PORTB2. */
#define LED3 0    /* Lysdiod 3 ansluten till pin 8 / PORTB0. */

#define BUTTON1 5 /* Tryckknapp 1 ansluten till pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1) /* T�nder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2) /* T�nder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3) /* T�nder lysdiod 3. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Sl�cker lysdiod 2. */
#define LED3_OFF PORTB &= ~(1 << LED3) /* Sl�cker lysdiod 3. */

#define LEDS_ON PORTB |= ((1 << LED1) | (1 << LED2) | (1 << LED3))   /* T�nder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Sl�cker lysdioderna. */

#define BUTTON1_IS_PRESSED ((PINB & (1 << BUTTON1)) != 0) /* Indikerar nedtryckning av tryckknapp 1. */

/* Enumerationer: */
typedef enum { true = 1, false = 0 } bool; /* Realiserar datatypen bool. */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar.
********************************************************************************/
void setup(void);

/********************************************************************************
* delay_ms: Genererar angiven f�rdr�jning m�tt i millsekunder.
*
*           - delay_time_ms: F�rdr�jningstid m�tt i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms);

/********************************************************************************
* leds_blink_collectively: Genererar kollektiv (gemensam) blinkning av lysdioder 
*                          LED1 - LED2 anslutna till pin 9 - 10 (PORTB1 - PORTB2).
*
*                          - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_collectively(const uint16_t blink_speed_ms);

/********************************************************************************
* leds_blink_sequence: Genererar sekventiell blinkning av lysdioder LED1 - LED2 
*                      anslutna till pin 9 - 10 (PORTB1 - PORTB2).
*
*                      - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_sequence(const uint16_t blink_speed_ms);

#endif /* GPIO_H_ */