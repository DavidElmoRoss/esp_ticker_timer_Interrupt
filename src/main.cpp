/*
  TITLE: Program to TURN ON/OFF LED using Timer Interrupt
  Author: David Elmo Ross
  Date:   March 3rd, 2025
  Description:  This program will use a TIMER INTERRUPT to change
                the colours on the RGB LED from RED to GREEN to BLUE
                continuously every 1.5 seconds.
                You will notice that in the LOOP() code there is nothing
                to change the value of count.
                A timer interrupt will do a special bit of code called
                an Interrupt service routine after a specified amount
                of time has passed.
                void COUNTER() is the periodic interrupt Service Routine
                in this case.
                The statement up_count.attach(1.5,COUNTER) makes sure that
                the COUNTER periodic interrupt is executed every 1.5 
                seconds, no matter what the loop() code is doing, hence
                the name interrupt.
*/

// Include Section
#include <Ticker.h>                     // include the TICKER Library
#include <Arduino.h>                    // include the Arduino Library

// DEFINE SECTION
#define RED_LED 25                        // RED Pin connected to PIN 25
#define GREEN_LED 26                      // GREEN PIN connected to PIN 26
#define BLUE_LED 27                       // BLUE PIN connected to PIN 27

// Global Variables Section
volatile short count=0;                 // set Global Variable count to 0

Ticker up_count;                        // make up_count an instance of Ticker

void COUNTER()                          // Timer Interrupt Service Routine
{
    count++;                            // increment count variable
}

void setup() 
{
    Serial.begin(9600);                 // Set Baud rate to 9600
    up_count.attach(1.5, COUNTER);      // Calls COUNT Interrupt service routine every 1.5 second
                                        // after 1.5 seconds, no matter which instruction was
                                        // about to be executed, the COUNTER IRQ code gets
                                        // executed, which adds 1 to the GLOBAL variable count
    pinMode(RED_LED, OUTPUT);           // set RED_LED output pin to output
    pinMode(GREEN_LED, OUTPUT);         // set GREEN_LED output pin to output
    pinMode(BLUE_LED, OUTPUT);          // set BLUE_LED output pin to output
    digitalWrite(RED_LED,1);            // shut off the RED LED
    digitalWrite(GREEN_LED,1);          // shut off GREEN LED
    digitalWrite(BLUE_LED,1);           // shut off BLUE LED
}

void loop() 
{
    printf("\e[2J\e[1;35HLED is");      // Clear screen and set LED IS to (1,35)
    fflush(stdout);                     // flush output to screen
    for(;;)                             // set up endless loop
    {
      if(count==0)                      // if count is 0 turn on RED led 
      {
        digitalWrite(BLUE_LED,HIGH);    // turn OFF BLUE_LED
        digitalWrite(RED_LED,LOW);      // turn ON RED_LED 
      }
      else
      if(count==1)                      // of count == 1
      {
        digitalWrite(RED_LED,HIGH);     // turn OFF RED_LED
        digitalWrite(GREEN_LED,LOW);    // turn ON GREEN_LED
      }
      else
      if(count==2)                      // if count == 2
      {
        digitalWrite(GREEN_LED,HIGH);   // turn OFF GREEN_LED
        digitalWrite(BLUE_LED,LOW);     // turn ON BLUE_LIGHT
      }
      else                              // if count > 2 then reset
      {                                 // count to 0
         count=0;
      }
    }   
}