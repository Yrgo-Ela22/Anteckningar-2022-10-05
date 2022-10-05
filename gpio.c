#include "gpio.h"

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar. Lysdiodernas pinnar 9 - 10 sätts
*        till utportar, medan den interna pullup-resistorn på tryckknappens 
*        pin 13 aktiveras för att insignalen alltid skall bli hög eller låg.
********************************************************************************/
void setup(void)
{
   DDRB = ((1 << LED1) | (1 << LED2) | (1 << LED3));
   PORTB = (1 << BUTTON1);
   return;
}

/********************************************************************************
* delay_ms: Genererar angiven fördröjning mätt i millsekunder.
*
*           - delay_time_ms: Fördröjningstid mätt i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms) 
{
   for (uint16_t i = 0; i < delay_time_ms; ++i)
   {
      _delay_ms(1);
   }

   return;
}

/********************************************************************************
* leds_blink_collectively: Genererar kollektiv (gemensam) blinkning av lysdioder
*                          LED1 - LED2 anslutna till pin 9 - 10 (PORTB1 - PORTB2).
*
*                          - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_collectively(const uint16_t blink_speed_ms)
{
   LEDS_ON;
   delay_ms(blink_speed_ms);
   LEDS_OFF;
   delay_ms(blink_speed_ms);
   return;
}

/********************************************************************************
* leds_blink_sequence: Genererar sekventiell blinkning av lysdioder LED1 - LED2
*                      anslutna till pin 9 - 10 (PORTB1 - PORTB2).
*
*                      - blink_speed_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_sequence(const uint16_t blink_speed_ms)
{
   LED1_ON;
   LED2_OFF;
   LED3_OFF;
   delay_ms(blink_speed_ms);

   LED1_OFF;
   LED2_ON;
   LED3_OFF;
   delay_ms(blink_speed_ms);

   LED1_OFF;
   LED2_OFF;
   LED3_ON;
   delay_ms(blink_speed_ms);

   return;
}