# Anteckningar 2022-10-05
Implementering av ett litet inbyggt system innehållande tre lysdioder samt en tryckknapp för mikrodator ATmega328P.
Programkod skriven i C via Microchip Studio.

Vid nedtryckning av tryckknappen blinkar lysdioderna i en sekvens (slinga) var 100:e millsekund, 
övrig tid blinkar de kollektivt (samtidigt) var 500:e millisekund.

Filen gpio.h innehåller inkluderingsdirektiv, makrodefinitioner samt funktionsdeklarationer för GPIO-implementeringen,
vilket innefattar initiering av I/O-portarna, blinkrutiner för lysdioderna samt en fördröjningsrutin.
Filen gpio.c innehåller motsvarande funktionsdefinitioner.

I filen main.c genomförs kontroll av tryckknappens insignal. Beroende på ifall nedtryckning äger rum eller inte så genomförs
sekventiell eller kollektiv blinkning av lysdioderna.