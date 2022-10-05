/********************************************************************************
* error_code1: Enkel GPIO-implementering innehållande ett flertal fel, som
*              skall korrigeras av den studerande. Koden är här korrigerad.
********************************************************************************/
#include "gpio.h"

/********************************************************************************
* main: Initierar mikrodatorns I/O-portar vid start. Lysdioderna blinkar sedan
*       kontinuerligt så länge matningsspänning tillförs. Vid nedtryckning av
*       tryckknappen blinkar lysdioderna i en sekvens var 100:e millisekund,
*       annars blinkar de kollektivt var 500:e millisekund.
********************************************************************************/
int main(void)
{
    setup();

    while (1) 
    {
       if (BUTTON1_IS_PRESSED)
       {
          leds_blink_sequence(100);
       }
       else
       {
          leds_blink_collectively(500);
       }
    }

    return 0;
}

