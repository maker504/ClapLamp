/*
CLAP LAMP
Aplicacion del sensor de audio con arduino para hacer una lampara activada por sonido.
 */

//IOs
int Clap=0; //Entrada discreta del sensor de audio
int LP=1; //Salida para el led LP

//Variables
bool EstLuz=LOW; //Para llevar el estado de la Luz
unsigned long TClap=0; //Hora en que se hace el primer clap
int NClaps=0; //Cuantos claps van en el periodo de espera
unsigned long Espera=2000; //Cuantos ms esperar para el segundo clap

void setup() 
{
pinMode(Clap,INPUT_PULLUP);
pinMode(LP,OUTPUT);

digitalWrite(LP,HIGH);
delay(1000);
digitalWrite(LP,LOW);
delay(Espera);

}

void loop() 
{
  if(digitalRead(Clap)==HIGH)
  {
    if(EstLuz==HIGH)
    {
      if((millis()-TClap)<Espera)
      {
        TClap=0;
        EstLuz=LOW;
        digitalWrite(LP, EstLuz);
        delay(1000);
      }
      else
      {
        TClap=millis();
        delay(10);
      }
    }
    else
    {
      TClap=0; //millis();
      EstLuz=HIGH;
      digitalWrite(LP,EstLuz);
      delay(1000);
    }
  }
}
