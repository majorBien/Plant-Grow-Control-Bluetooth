int sensorPin = A1;
int sensorValue = 0;
int value1;
unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas = 0;
unsigned long licznik = 0;
unsigned long dzien = 43200;
unsigned long  noc = 43200;
int wybrany_cykl;
boolean  znacznik=0;
char wartosc_odbierana;
float temperatura;
 int wilgotnosc;
int e=-1;
int f=-1;
int g=-1;
int h=-1;
int mode = 0;

void setup()
{
 
  Serial.begin(9600);

  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
}

void loop()
{
  odbieranie_danych();
  odliczanie_czasu();
  sterowanie_przekaznikami();
  pomiar_temperatury();
  pomiar_wilgotnosci_gelby();
  delay(1000);
}



void odliczanie_czasu()
{
 aktualnyCzas = millis();
 

  if (aktualnyCzas - zapamietanyCzas >= 1000UL)
  {

    zapamietanyCzas = aktualnyCzas;
    licznik++;
  }

}
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
    digitalWrite(8,LOW);

    licznik = 0;
    znacznik = 1;

  }


  if(licznik == noc&&znacznik==1&&mode==0)
  {
 
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);

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


  void pomiar_temperatury()
  {
    float zapis;
    int odczyt = analogRead(temperatura_adc);
    float napiecie = odczyt * (5000 / 1024);
    temperatura = napiecie / 10;
    if(temperatura>17&&temperatura<26)
    {
      zapis = temperatura;
    }
    if(temperatura<17||temperatura>26)
    {
      temperatura=zapis;
    }  
    Serial.print(temperatura);
    Serial.print(" \xC2\xB0");
    Serial.print("/");
   
   
 
  }


  void pomiar_wilgotnosci_gelby()
  {
sensorValue = analogRead(sensorPin);
value1 = map(sensorValue, 0, 1023, 100, 0);
Serial.print(value1);
    Serial.print("%");
    Serial.print("/");
   
   
  }
