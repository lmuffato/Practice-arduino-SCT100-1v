//Programa : Medidor de energia elétrica com Arduino e SCT-013
//Autor : FILIPEFLOP
 
//Baseado no programa exemplo da biblioteca EmonLib
 
//Carrega as bibliotecas
#include "EmonLib.h" 
 
EnergyMonitor emon1;
 
//Tensao da rede eletrica
int rede = 110.0;
 
//Pino do sensor SCT
int pino_sct = 1;
 
void setup() 
{
  Serial.begin(9600);   
} 
  
void loop() 
{ 
  float Va;
  Va = analogRead(A1);
  
  //Calcula a corrente  
  double Irms = emon1.calcIrms(1480);
  //Mostra o valor da corrente
  Serial.print("PortaA0 : ");
  Serial.println(Va);
  
  Serial.print("Corrente : ");
  Serial.println(Irms); // Irms
   
  //Calcula e mostra o valor da potencia
  Serial.print(" Potencia : ");
  Serial.println(Irms*rede); 
  delay(1000);
}
