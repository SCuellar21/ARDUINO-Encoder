int pos;
bool v1, v2, v3;

void setup() {
  pinMode(7,INPUT); //sensores
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  
  // Pin 11 es la potencia de giro del motor!
  pinMode(10,OUTPUT); //sentido de giro
  pinMode(9,OUTPUT);  //sentido de giro
  
  // **INICIO CON EL MOTOR APAGADO!**
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  //Serial.begin(9600);
}

void loop() {
  //analogWrite(11, 150);//171= 3/4 de frecuencia
  do{
    SelectPos();
  }while(pos==0);
  delay(3000);
  SelectPos();
  
  if(pos != 0){
    if(pos <= 4){                //gira a la derecha
      digitalWrite(10,HIGH);
      do{
        analogWrite(11,100);
        SelectPos();
        if(pos==0){
          delay(270);
        }
      }while(pos != 0);
      digitalWrite(10,LOW);
    }else{                      //gira a la izquierda
      digitalWrite(9,HIGH);
      do{
        analogWrite(11,100);
        SelectPos();
        if(pos==0){
          delay(270);
        }
      }while(pos != 0);
      digitalWrite(9,LOW);
    }
  }
  /*
  char ch;
  if (Serial.available() > 0) {
    ch = Serial.read();
  }
  if(ch == 'I' || ch == 'i'){
    analogWrite(11, 70); // *65 MINIMO DE POTENCIA PARA PWM!!
    Serial.println(ch);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
  }else if(ch == 'D' || ch == 'd'){
    analogWrite(11, 151);
    Serial.println(ch);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
  }
  */
}
/*
  if (Serial.available()) { //Si el puerto serie esta disponible?
  ch = Serial.read(); //variable tipo char desde puerto serial
  if(ch >= ‘0’ && ch <= ‘9’){ //Si ch es un numero?
    int speed = map(ch, ‘0’, ‘9’, 0, 255); //Re-mapea un numero desde un rango a otro
    analogWrite(enPin, speed); //’0′ a 0 ‘9’ a 255
    Serial.println(speed); //Escribe el valor analogico PWM enPin
  }else if (ch == ‘+’) {//Si el caracter es ‘+’ //el motor avanza Clockwise
    Serial.println(“CW”);
    digitalWrite(in1Pin,LOW);
    digitalWrite(in2Pin,HIGH);
  }else if (ch == ‘-‘) {//Si el caracter es –//el motor avanza CounterClockwise
    Serial.println(“CCW”);
    digitalWrite(in1Pin,HIGH);
    digitalWrite(in2Pin,LOW);
  }
}
*/
void ReadBit(){
  v1=digitalRead(7);
  v2=digitalRead(6);
  v3=digitalRead(5);
}
void SelectPos(){
  ReadBit();
  if(!v1 && v2 && v3){
    pos = 1;
  } else if(v1 && !v2 && v3){
    pos = 2;
  } else if(!v1 && !v2 && v3){
    pos = 3;
  } else if(v1 && v2 && !v3){
    pos = 4;
  } else if(!v1 && v2 && !v3){
    pos = 5;
  } else if(v1 && !v2 && !v3){
    pos = 6;
  } else if(!v1 && !v2 && !v3){
    pos = 7;
  } else{
    pos = 0;
  }
  
  /*
  if(!v1 && v2){
    pos = 1;
  } else if(v1 && !v2){
    pos = 2;
  } else if(!v1 && !v2){
    pos = 3;
  } else{
    pos = 0;
  }
  */

}

/*  //PARA BORRAR LA PANTALLA SERIAL (OTRA COSA)
void clearAndHome() 
{ 
  Serial.write(27); 
  Serial.print("[2J"); // clear screen 
  Serial.write(27); // ESC 
  Serial.print("[H"); // cursor to home 
} 
*/
