//DECLARACIÓN DE VARIABLES
int led0=0;
int led1=-1; //Debido a la iteración en el orden en el que se mostrarán
int estado=0;
int estadoAnterior=0; //auxiliares para la detección de pulsación del botón

void setup() {
 // ESTABLECER PINES DE ENTRADA/SALIDA
pinMode(3,INPUT);  //BOTÓN
pinMode(4,OUTPUT);  //LED 0 (rojo)
pinMode(5,OUTPUT);  //LED 1 (azul)
}

void loop() {
//ESTABLECIENDO SISTEMA BOOLEANO
if((led1==0)&&(led0==1))  //Rojo prende
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
else if((led1==1)&&(led0==0)) //Azul prende
{
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
else if ((led1==2)&&(led0==1))  //Ambos prenden
{
  digitalWrite(4,HIGH);
  //digitalWrite(5,HIGH);
}
else  //Ambos apagados. En este estado será iniciado puesto que led1=-1 y led0=0
{
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}

estado=digitalRead(3); //Se lee el estado del botón

//Se apreta el botón
if((estado==HIGH)&&(estadoAnterior==LOW)) //Se suma una unidad a cada led.
{
  led0=led0+1;
  led1=led1+1;
  delay(50);
}

estadoAnterior=estado;  //Pasando el estado

//Manteniendo suma binaria
if (led0==2) //El LED 0 sólamente cambia de 1 a 0 por pulsación, pues al llegar al 2 se reinicia en 0.
{
  led0=0;
}

if (led1>2) //El LED 1 tiene valores de 0 a 2 para su selección, al llegar a 3 se restablece en -1
{
  led1=-1;
}
}
