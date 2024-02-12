#include <FastLED.h>
#include <DHT.h>
#include <Wire.h>
#include "Adafruit_SGP40.h"
#include <LiquidCrystal_I2C.h>


Adafruit_SGP40 sgp;

#define num_of_leds 60 //number of leds
#define pin_leds 5 // data pin for led strip
#define Type DHT22
#define pin_soil A1  // data pin for soil sensor
#define button1_pin 11 //main windows navigation ZMIANA
#define relay_pin 7 // realy data pin ZMIANA
#define relay_pin2 8 // chose button ZMIANA
#define relay_pin3 9 // right navigation ZMIANA
#define relay_pin4 10 // realy data pin ZMIANA

unsigned long dzien = 43200;
unsigned long  noc = 43200;
boolean  znacznik=0;
int e=-1;
int f=-1;
int g=-1;
int h=-1;
int mode = 0;
void odbieranie_danych()
{
  if(Serial.available()>0)
  {
    wartosc_odbierana = Serial.read();
    if(wartosc_odbierana=='A')
    {
      dzien = 43200;
      noc = 43200;
    }
    if(wartosc_odbierana=='B')
    {
    dzien = 50400;
    noc = 36000;
    }
    if(wartosc_odbierana=='C')
   {
     dzien = 57600;
     noc = 28800;
    }
     if(wartosc_odbierana=='D')
   {
       dzien = 64800;
       noc = 21600;
   }

       if(wartosc_odbierana=='E')
   {
       e++;
       delay(100);
   }
        if(wartosc_odbierana=='F')
   {
        f++;
       delay(100);
   }
        if(wartosc_odbierana=='G')
   {
        g++;
       delay(100);
   }
        if(wartosc_odbierana=='H')
   {
       h++;
       delay(100);
   }
        if(wartosc_odbierana=='I')
   {
       mode++;
       delay(100);
   }
   
  }
 
}


void sterowanie_przekaznikami()
{

  if(licznik == dzien&&znacznik==0&&mode==0)
  {
 
    digitalWrite(7,HIGH);

    licznik = 0;
    znacznik = 1;

  }


  if(licznik == noc&&znacznik==1&&mode==0)
  {
 
    digitalWrite(7,LOW);

    licznik = 0;
    znacznik = 0;
   
  }

  if(e>1)
  {
    e=0;
  }
  if(f>1)
  {
    f=0;
  }
  if(g>1)
  {
    g=0;
  }
  if(h>1)
  {
    h=0;
  }
  if(mode>1)
  {
    mode=0;
  }

 
  if(e==1&&mode==1)
  {
    digitalWrite(7,HIGH);
 
  }
  if(e==0&&mode==1)
  {
    digitalWrite(7,LOW);
   
  }  

    if(f==1&&mode==1)
  {
    digitalWrite(8,HIGH);
 
  }
  if(f==0&&mode==1)
  {
    digitalWrite(8,LOW);
   
  }  

    if(g==1&&mode==1)
  {
    digitalWrite(9,HIGH);
 
  }
  if(g==0&&mode==1)
  {
    digitalWrite(9,LOW);
   
  }  

    if(h==1&&mode==1)
  {
    digitalWrite(10,HIGH);
 
  }
  if(h==0&&mode==1)
  {
    digitalWrite(10,LOW);
   
  }  
}
