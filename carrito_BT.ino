/*********************************
 **  sumobots Fetec 2016       **
 * *******************************
 * 
 * Firmware hecho para el control de un sumobot o carrito con bluetooth
 * utilizando el driver L298N, HC-05 o hc-06 y arduino uno
 * 
 * Hecho por Yeffri J Salazar.
 * Comunidad Arduino Guatemala y Najt Labs.
 * github.com/yeffrimic
 * 
 */


#include <SoftwareSerial.h>
SoftwareSerial BT(2,3);//rx, tx

// Configuramos los pines que vamos a usar
int motorDer1=11;//El pin 2 a In1 del L298N
int motorDer2=10;//El pin 3 a In2 del L298N
int motorIzq1=9;//El pin 7 a In3 del L298N
int motorIzq2=8;//El pin 4 a In4 del L298N

int velocidad=150;


void setup() {
 // BT.begin(9600);
  BT.begin(9600);
  
  pinMode(motorDer1, OUTPUT); 
  pinMode(motorDer2, OUTPUT);
  pinMode(motorIzq1, OUTPUT); 
  pinMode(motorIzq2, OUTPUT); 
}

void atras(){ 
  digitalWrite(motorDer1,HIGH);
  digitalWrite(motorDer2,LOW);
  digitalWrite(motorIzq1,HIGH);
  digitalWrite(motorIzq2,LOW);
}
void adelante(){ 
  digitalWrite(motorDer1,LOW);
  digitalWrite(motorDer2,HIGH);
  digitalWrite(motorIzq1,LOW);
  digitalWrite(motorIzq2,HIGH);
}
void giraDerecha(){ 
  digitalWrite(motorDer1,HIGH);
  digitalWrite(motorDer2,LOW);
  digitalWrite(motorIzq1,LOW);
  digitalWrite(motorIzq2,HIGH);
}
void giraIzquierda(){ 
  digitalWrite(motorDer1,LOW);
  digitalWrite(motorDer2,HIGH);
  digitalWrite(motorIzq1,HIGH);
  digitalWrite(motorIzq2,LOW);
}
void parar(){ 
  digitalWrite(motorDer1,LOW);
  digitalWrite(motorDer2,LOW);
  digitalWrite(motorIzq1,LOW);
  digitalWrite(motorIzq2,LOW);

}

void loop() {

if(BT.available()>0){
  char dato=BT.read();
  switch(dato){
    case 'a':
    BT.println("izquierda");
    giraIzquierda();
    break;
    case 's':
    BT.println("atras");
    atras();
    break;
    case 'd':
    BT.println("derecha");
    giraDerecha();
    break;
    case 'w':
    BT.println("motor 2 atras");
    adelante();
    break;
    default:
    parar();
    break;
  }
}
}



