
#include "Robolito.h"//O Header inclui as bibliotecas Servo.h e Ultrasound.h

Servo ServoDaCabecaP; //cria oS objeto para controle dos servos da cabeça
Servo ServoDaCabecaY;

void Robolito::Iniciar(){

  //Define todos os pinos usados no Robolito
  Serial.begin(115200);//Usado em todo o código para passar informações diretopara o computador
  delay(10);
  Serial.println("*****************************************************************");
  Serial.println("*                                                               *");
  Serial.println("*   ####    ###   ####    ###   #       ###   #####   ###   #   *");
  Serial.println("*   #   #  #   #  #   #  #   #  #        #      #    #   #  #   *");
  Serial.println("*   #####  #   #  #   #  #   #  #        #      #    #   #  #   *");
  Serial.println("*   ##     #   #  ####   #   #  #        #      #    #   #  #   *");
  Serial.println("*   # #    #   #  #   #  #   #  #        #      #    #   #  #   *");
  Serial.println("*   #  #   #   #  #   #  #   #  #        #      #    #   #      *");
  Serial.println("*   #   #   ###   ####    ###   #####   ###     #     ###   #   *");
  Serial.println("*                                                               *");
  Serial.println("*****************************************************************");
  Serial.println("Por: ISAAC MOREIRA");
  Serial.println("VER. 1.1 - JANEIRO DE 2023");
  Serial.println();
  
  pinMode(LED, OUTPUT);
  
  pinMode(MotorEsquerdoP0, OUTPUT);
  pinMode(MotorEsquerdoP1, OUTPUT);
  pinMode(MotorEsquerdoEncoder, INPUT);
  pinMode(MotorEsquerdoPWM, OUTPUT);

  pinMode(MotorDireitoP0, OUTPUT);
  pinMode(MotorDireitoP1, OUTPUT);
  pinMode(MotorDireitoEncoder, INPUT);
  pinMode(MotorDireitoPWM, OUTPUT);

  pinMode(ServoDaCabecaPAN, OUTPUT);
  pinMode(ServoDaCabecaYAW, OUTPUT);

  pinMode(SensorUltrasomTrig, OUTPUT);
  pinMode(SensorUltrasomEcho, INPUT);

  pinMode(SensorIREsquerdo, INPUT);
  pinMode(SensorIRDireito, INPUT);

  //Cria as interrupções para os encoders;

  
  //Inicia um objeto do tipo Servo com o nome ServoDaCabeca
  //para controlar o servo que move o sensor de ultrasom

 
  ServoDaCabecaP.attach(ServoDaCabecaPAN);//inicia o servo "ROTAÇÃO DE CABEÇA"
  ServoDaCabecaY.attach(ServoDaCabecaYAW);//inicia o servo "LEVANTAMENTO DE CABEÇA"

  

 //Move a cabeça de um lado para outra bem devagar e depois a move para o centro
  
  Robolito::LigaLuz();
  Serial.println("Vou fazer um giro de cabeca.");
  for(float i = 0; i <= 2*PI; i = i + 0.0628) {
    ServoDaCabecaP.write(map(100*(sin(i)+1), 0, 200, 0, 180));
    ServoDaCabecaY.write(map(100*(cos(i)+1), 0, 200, 0, 180));
    Serial.print(".");
    delay(30);
     }
   Robolito::LevantaACabeca(90);
   Serial.println();
   Serial.println("Pronto!");
   Robolito::DesligaLuz();
  
  
  
 /*DEBUG*/

  //Dá uma leve mexida nas rodinhas pra testar os motores
  Robolito::LigaMotorEsquerdo(Para_Frente, 100);
  Robolito::LigaMotorDireito(Para_Tras, 100);
  Robolito::Espera(0.1);
  Robolito::LigaMotorEsquerdo(Para_Tras, 100);
  Robolito::LigaMotorDireito(Para_Frente, 100);
  Robolito::Espera(0.1);
  Robolito::DesligaMotorEsquerdo();
  Robolito::DesligaMotorDireito();

  Robolito::MedeDistancia();
  Robolito::OlhoEsquerdoEnxerga();
  Robolito::OlhoDireitoEnxerga();

  Robolito::Espera(0.5);
  Serial.println("****************************************");
  Serial.println("*   Robolito iniciado com sucesso!!!   *");
  Serial.println("****************************************");
  //Inicia as interrupções
}

//Tradução entre a função delay e a sua versão em português
void Robolito::Espera(float tempo){
  Serial.print("Eu vou esperar ");
  Serial.print(tempo);
  Serial.println(" segundos sem fazer mais nada.");
  delay(1000 * tempo);//converte se segundos para milesegundos
  Serial.println("Pronto!");
}

//Funções para controlar o led da placa, ligado ao pino 13, como em todo arduino.
void Robolito::LigaLuz(){
  digitalWrite(LED, HIGH);
  Serial.println("Eu liguei a luzinha.");
}

void Robolito::DesligaLuz(){
  digitalWrite(LED, LOW);
  Serial.println("Eu desliguei a luzinha.");
}

//Faz com que o robolito mova a cabeça
void Robolito::GiraACabeca(float angulo){
  angulo = (angulo > 180)? 180 : angulo;//garate que o ângulo escrito esteja dentro dos valores adequados
  angulo = (angulo < 0)  ?   0 : angulo;
  ServoDaCabecaP.write(angulo);//manda esse ângulo para o servo
  Serial.print("Eu GIREI minha cabeca para a posicao ");
  Serial.print(angulo);
  Serial.println(" graus.");
}

void Robolito::LevantaACabeca(float angulo){
  angulo = (angulo > 180)? 180 : angulo;//garate que o ângulo escrito esteja dentro dos valores adequados
  angulo = (angulo < 0)  ?   0 : angulo;
  ServoDaCabecaY.write(angulo);//manda esse ângulo para o servo
  Serial.print("Eu LEVANTEI minha cabeca para a posicao ");
  Serial.print(angulo);
  Serial.println(" graus.");
}


//funções para mover os motores 

void Robolito::LigaMotorEsquerdo(bool direcao, int velocidade){   //especificamente para o motor esquerdo
  Serial.print("Eu liguei meu motor ESQUERDO ");
  if(direcao){//se está indo para frente (ver os defines)
    digitalWrite(MotorEsquerdoP0, HIGH);
    digitalWrite(MotorEsquerdoP1, LOW);
    Serial.print("para FRENTE com "); 
  }else{
    digitalWrite(MotorEsquerdoP0, LOW);
    digitalWrite(MotorEsquerdoP1, HIGH);
    Serial.print("para TRAS com"); 
    }

    analogWrite(MotorEsquerdoPWM, map(velocidade, 0, 100, 0, 255));

    Serial.print(velocidade);
    Serial.println("% de velocidade.");  
}  


  void Robolito::DesligaMotorEsquerdo(){ 
    digitalWrite(MotorEsquerdoP0, LOW);
    digitalWrite(MotorEsquerdoP1, LOW); 
    analogWrite(MotorEsquerdoPWM, 0);
    Serial.println("Eu desliguei o motor ESQUERDO.");
  }



void Robolito::LigaMotorDireito(bool dir, int vel){   //especificamente para o motor direito
  Serial.print("Eu liguei meu motor DIREITO ");
  if(dir){//se está indo para frente (ver os defines)
    digitalWrite(MotorDireitoP0, HIGH);
    digitalWrite(MotorDireitoP1, LOW); 
    Serial.print("para FRENTE com ");
  }else{
    digitalWrite(MotorDireitoP0, LOW);
    digitalWrite(MotorDireitoP1, HIGH); 
    Serial.print("para TRAS com ");
    }

  analogWrite(MotorDireitoPWM, map(vel, 0, 100, 0, 255));

  Serial.print(vel);
  Serial.println("% de velocidade.");
  
}


  void Robolito::DesligaMotorDireito(){
    digitalWrite(MotorDireitoP0, LOW);
    digitalWrite(MotorDireitoP1, LOW); 
    analogWrite(MotorDireitoPWM, 0);
    Serial.println("Eu desliguei o motor DIREITO.");
  }

//Função para medir a distância do sensor Ultrasom
long Robolito::MedeDistancia(){
  digitalWrite(SensorUltrasomTrig, LOW);//garante que o pino Trig esteja em estado LOW
  delay(5);
  digitalWrite(SensorUltrasomTrig, HIGH);
  delay(10);                             //pulsa HIGH por 10ms
  digitalWrite(SensorUltrasomTrig, LOW);

  long distancia = ((pulseIn(SensorUltrasomEcho, HIGH))/58.2);//retorna o valor em centímetros
   
  Serial.print("Eu vi que tem alguma coisa a ");
  Serial.print(distancia);
  Serial.println("cm da minha cabeca.");

  return distancia;
}

int Robolito::OlhoEsquerdoEnxerga(){
 int enxerguei = digitalRead(SensorIREsquerdo); 

 if(enxerguei)Serial.println("Eu vi algo BRANCO no meu olho ESQUERDO.");
 else Serial.println("Eu vi algo PRETO no meu olho ESQUERDO.");

 return enxerguei;
}

int Robolito::OlhoDireitoEnxerga(){
  int enxerguei = digitalRead(SensorIRDireito); 

  if(enxerguei)Serial.println("Eu vi algo BRANCO no meu olho DIREITO.");
  else Serial.println("Eu vi algo PRETO no meu olho DIREITO.");

  return enxerguei;
}



  
