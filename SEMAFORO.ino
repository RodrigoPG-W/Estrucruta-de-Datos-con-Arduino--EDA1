void setup() {
  // ESTABLECER PINES DE SALIDA
pinMode(2,OUTPUT);  //ROJO
pinMode(3,OUTPUT);  //AMARILLO
pinMode(4,OUTPUT);  //VERDE
}

void loop() {
  // SEMÁFORO CON LEDS.
  digitalWrite(4,HIGH);
  delay(2000);    //Retraso de 2 segundos
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  delay(1000);    //Retraso de 1 segundo
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  delay(2000);    //Retraso de 2 segundos
  digitalWrite(2,LOW);
}
