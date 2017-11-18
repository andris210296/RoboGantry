#include <Servo.h>

Servo servo;

//variáveis do motor dc
int pino13 = 13;

// conexões e variáveis do motor de passo
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int tempo = 10;
int contador = 25;
int intervalo = 1000;

void setup() {  
  pinMode(pino13, OUTPUT);
  digitalWrite(pino13,HIGH);
  servo.attach(8);
  servo.write(0);

  // Define os pinos como saida
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT); 
    
}

void loop() {
  

  servo.write(180); //abrir garra
  
   
  digitalWrite(pino13,LOW); //move carrinho completamente para a esquerda
  delay(4000);

  delay(9000); //esperar para que dê tempo de ligar na tomada a ponte

  descerGarra(0);
  pararGarra();   
  
  servo.write(0); ///fechar garra
  delay(2000);

  subirGarra(0);
  pararGarra();
 
  digitalWrite(pino13,HIGH); //voltar para a posição inicial
  delay(4000);
  
  descerGarra(-7);
  pararGarra(); 

  servo.write(160); //abrir garra
  delay(2000);

  subirGarra(-7);
  pararGarra();
     
}


void descerGarra(int adicional){
   // Descer
  for (int i=0; i <= contador+adicional; i++){
  // Passo 1  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  delay(tempo);  

  // Passo 2
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  delay(tempo);

  // Passo 3
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  delay(tempo);

  // Passo 4
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  delay(tempo);
  }
}

void subirGarra(int adicional){
  //Subir  
for (int i=0; i <= contador+adicional; i++){

 // Passo 4
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  delay(tempo);

// Passo 3
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  delay(tempo);

   // Passo 2
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  delay(tempo);

  // Passo 1
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  delay(tempo); 

}
}

void pararGarra(){

// Passo 0
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
  delay(intervalo);

}
