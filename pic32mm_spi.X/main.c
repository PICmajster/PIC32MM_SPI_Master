/*
    File Name:        :  main.c

    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/

#include "mcc_generated_files/mcc.h"
#include "xc.h" /* wykrywa rodzaj procka i includuje odpowiedni plik naglowkowy "pic32mm0256gpm048.h"*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> /*definicje uint8_t itp*/
#include "delay.h"
#include "dogm162.h"

#define LED1_TOG PORTB ^= (1<<_PORTB_RB6_POSITION) /*zmienia stan bitu na przeciwny*/

uint8_t myWriteBuffer[] = "Witaj SPI"; /*bufor nadawczy*/
uint8_t myReadBuffer[15] ; /*bufor odbiorczy, nie uzywamy*/
int main(void)
{
    /*initialize the device*/
    SYSTEM_Initialize();
    SPI2_Initialize(); /*Master*/
    /*When using interrupts, you need to set the Global Interrupt Enable bits
      Use the following macros to:*/
   
    /* Enable the Global Interrupts*/
    /*INTERRUPT_GlobalEnable();*/

    /*Disable the Global Interrupts*/
    /*INTERRUPT_GlobalDisable();*/
    
    TRISBbits.TRISB6 = 0; /*set RB6 out*/
    delayMs(2000);
    /*wysylamy do Slave zawartosc bufora nadawczego*/
    /*do funkcji podajemy trzy argumenty : wskaznik na bufor nadawczy, rozmiar
     bufora nadawczego, sizeof() oblicza nam go, wskaznik na bufor odbiorczy*/
     SPI2_Exchange8bitBuffer(myWriteBuffer, sizeof(myWriteBuffer), myReadBuffer);
     LED1_TOG;
   
     while (1)
     {
   
     }
}
