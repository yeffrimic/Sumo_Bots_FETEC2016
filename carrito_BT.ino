#include <SoftwareSerial.h>
SoftwareSerial BT(2,3);//rx, tx

// Configuramos los pines que vamos a usar
int motorDer1=2;//El pin 2 a In1 del L298N
int motorDer2=3;//El pin 3 a In2 del L298N
int motorIzq1=7;//El pin 7 a In3 del L298N
int motorIzq2=4;//El pin 4 a In4 del L298N
int derecho=5;  //El pin 5 a EnA del L298N
int izquierdo=6;//El pin 6 aEnB del L298N

int velocidad=150;


void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  
  pinMode(motorDer1, OUTPUT); 
  pinMode(motorDer2, OUTPUT);
  pinMode(motorIzq1, OUTPUT); 
  pinMode(motorIzq2, OUTPUT); 
  pinMode(derecho, OUTPUT);
  pinMode(izquierdo, OUTPUT);
}

void atras(){ 
  digitalWrite(motorDer1,HIGH);
  digitalWrite(motorDer2,LOW);
  digitalWrite(motorIzq1,HIGH);
  digitalWrite(motorIzq2,LOW);
  analogWrite(derecho,200);//Velocidad motor
  analogWrite(izquierdo,200);
}
void adelante(){ 
  digitalWrite(motorDer1,LOW);
  digitalWrite(motorDer2,HIGH);
  digitalWrite(motorIzq1,LOW);
  digitalWrite(motorIzq2,HIGH);
  analogWrite(derecho,200);
  analogWrite(izquierdo,200);
}
void giraDerecha(){ 
  digitalWrite(motorDer1,HIGH);
  digitalWrite(motorDer2,LOW);
  digitalWrite(motorIzq1,LOW);
  digitalWrite(motorIzq2,HIGH);
  analogWrite(derecho,200);
  analogWrite(izquierdo,200);
}
void giraIzquierda(){ 
  digitalWrite(motorDer1,LOW);
  digitalWrite(motorDer2,HIGH);
  digitalWrite(motorIzq1,HIGH);
  digitalWrite(motorIzq2,LOW);
  analogWrite(derecho,200);
  analogWrite(izquierdo,200);
}
void parar(){ 
  digitalWrite(motorDer1,LOW);
  digitalWrite(motorDer2,LOW);
  digitalWrite(motorIzq1,LOW);
  digitalWrite(motorIzq2,LOW);
  analogWrite(derecho,200);
  analogWrite(izquierdo,200);

}

void loop() {

if(Serial.available()>0){
  char dato=Serial.read();
  switch(dato){
    case 'a':
    Serial.println("izquierda");
    giraIzquierda();
    break;
    case 's':
    Serial.println("atras");
    atras();
    break;
    case 'd':
    Serial.println("derecha");
    giraDerecha();
    break;
    case 'w':
    Serial.println("motor 2 atras");
    adelante();
    break;
  }
}
}



