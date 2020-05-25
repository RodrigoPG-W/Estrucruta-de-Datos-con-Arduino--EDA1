int brillo; //Al utilizar enteros, se desprecian los puntos decimales de las divisiones
/*SIMULACIÓN DE CONTROL DE VOLUMEN*/
void setup() {
pinMode(3,OUTPUT);
pinMode(5,OUTPUT); //Declara los 3 LED que se ocupan
pinMode(6,OUTPUT);  
}

void loop() {
  //Lectura [0-1023], por lo tanto 1023/3 = 341
  //Escritura [0-225], por lo tanto 225/3 = 85
  
//Permite controlar el volumen en cada tercio de la lectura
  if (analogRead(A0)>=0 && analogRead(A0)<=341){  
  brillo=analogRead(A0)/4;
  analogWrite(3,brillo);
  }
  //Control del segundo LED sobre el segundo tercio del potenciómetro                                      
  else if (analogRead(A0)>341 && analogRead(A0)<=682){  //341*2 = 682
  brillo=((analogRead(A0)/4)-85);  //Se restan 85 pues así se mantendrá el LED apagado
  analogWrite(5,brillo);          //(341/4) = 85-85 = 0
  }
  //Control del tercer LED sobre el último tercio del potenciómetro
  else if (analogRead(A0)>682 && analogRead(A0)<1023){  //341*3 = 1023. Se restringe para evitar fallos con el potenciómetro.
  brillo=((analogRead(A0)/4)-170);//(682/4) = 170-170 = 0
  analogWrite(6,brillo);
  }
}
