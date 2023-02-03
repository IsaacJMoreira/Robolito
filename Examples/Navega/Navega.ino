#include "Robolito.h"

Robolito Alice; //Batiza o robolito com o nome Alice
int dirRadar = 6;
int anguloRadar = 90;

void setup() {
  
Alice.Iniciar(); //Manda a Alice iniciar

}

void loop() {

 
 dirRadar = (anguloRadar > 120 || anguloRadar < 60)? -dirRadar : dirRadar;
 anguloRadar += dirRadar;
 Alice.GiraACabeca(anguloRadar);
 
 if( Alice.MedeDistancia() < 30){
  Alice.DesligaMotorEsquerdo();
  Alice.DesligaMotorDireito();
  Alice.Espera(0.1);

  Alice.LigaMotorEsquerdo(Para_Tras, 100);
  Alice.LigaMotorDireito(Para_Tras, 100);
  Alice.Espera(0.5);
  Alice.DesligaMotorEsquerdo();
  Alice.DesligaMotorDireito();
  

  int dist[2] ={0,0};
  
  for(int i = 0; i < 2; i++){
    Alice.GiraACabeca(i*180);
    Alice.Espera(0.5);
    dist[i]  = Alice.MedeDistancia();
  }  

  anguloRadar = 90;
  Alice.GiraACabeca(90);
  Alice.Espera(0.5);
  
  if(dist[1] >= dist[0]){
    Alice.LigaMotorDireito(Para_Frente, 100);
    Alice.Espera(0.6);
    Alice.DesligaMotorDireito();
    } else{
      Alice.LigaMotorEsquerdo(Para_Frente, 100);
      Alice.Espera(0.6);
      Alice.DesligaMotorEsquerdo();
    } 
 }else{
  Alice.LigaMotorEsquerdo(Para_Frente, 100);
  Alice.LigaMotorDireito(Para_Frente, 100);
  }
}