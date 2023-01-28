#include "Robolito.h"

Robolito Alice; //Batiza o robolito com o nome Alice
int AnguloDaCabeca = 0;

void setup() {
  
Alice.Iniciar(); //Manda a Alice iniciar

}

void loop() {

  for(int i = 0; i < 10; i++)Serial.println();
 
  
  if(Alice.MedeDistancia() < 50){ 
    Alice.LigaLuz();
    Alice.GiraACabeca(0);
  }  else {
    Alice.DesligaLuz();
    Alice.GiraACabeca(180);
    }

  if(Alice.OlhoDireitoEnxerga() == PRETO ){
    Alice.DesligaMotorDireito();    
  }else{
    Alice.LigaMotorDireito(Para_Frente, 100);    
    }

  if(Alice.OlhoEsquerdoEnxerga() == PRETO){
    Alice.DesligaMotorEsquerdo();    
  }else{
    Alice.LigaMotorEsquerdo(Para_Frente, 100);
    }
  
// Alice.Espera(1);
}
