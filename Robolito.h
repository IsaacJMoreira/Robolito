/*************************************************************
  
   ####    ###   ####    ###   #       ###   #####   ###   #
   #   #  #   #  #   #  #   #  #        #      #    #   #  #
   #####  #   #  #   #  #   #  #        #      #    #   #  #  
   ##     #   #  ####   #   #  #        #      #    #   #  #
   # #    #   #  #   #  #   #  #        #      #    #   #  #
   #  #   #   #  #   #  #   #  #        #      #    #   #        
   #   #   ###   ####    ###   #####   ###     #     ###   #    

***************************************************************
POR ISAAC JERÔNIMO MOREIRA

VER. 1.1
19 de Janeiro de 2023

*/


#ifndef Rblt
#define Rblt

#if (ARDUINO > 100)
  #include "Arduino.h"
#else
  #include "Wprogram.h"
#endif

#include <Servo.h>

 
//Todos os defies necessários

//Defines dos pinos

//Pino do LED
#define LED 13
#define PinoLivre 11 //PIN 11 - LIVRE, COM POSSIBILIDADE DE USAR PWM
                     //Os pinhos A4 e A5 estão livres para comunicação I2C.

//Pinos para o motor esquerdo
#define MotorEsquerdoP0        4 //PIN 4
#define MotorEsquerdoP1        7 //PIN 7
#define MotorEsquerdoEncoder   2 // PRECISA DESENCADEAR UMA INTERRUPÇÃO
#define MotorEsquerdoPWM       5 //PIN 5 PWM


//pinos para do motor direito
#define MotorDireitoP0         8 //PIN 8
#define MotorDireitoP1         9 //PIN 9
#define MotorDireitoEncoder    3 // PRECISA DESENCADEAR UMA INTERRUPÇÃO
#define MotorDireitoPWM        6 //PIN 6 PWM

#define VoltasPorPulso  1/20 //Mudar esse valor de acordo com a realidade

//Pino para o controle dos servos da cabeça
#define ServoDaCabecaPAN         10 //PIN 10 - Servo PAN (CUIDADO!!! Esse pino não pode ser PWM com a biblioteca Servo.h)
#define ServoDaCabecaYAW         12 //PIN 12 - Servo YAW

//Pinos para o controle do sensor de ultrasom
//estão definidos de acordo com a SensorShield v5.0
#define SensorUltrasomTrig    A0 
#define SensorUltrasomEcho    A1 

//Pinos para os sensores Infravermelhos

#define SensorIREsquerdo          A2
#define SensorIRDireito           A3

//Defines para melhor entendimento e escrita do código

//Controle do motor
#define Para_Frente true 
#define Para_Tras   false

//Controle do LED
#define Ligado      HIGH
#define Desligado   LOW

//Controle de sensores IR
#define BRANCO HIGH
#define PRETO  LOW

//


//Criação da Classe Robolito
class Robolito{

  public:

 //Variáveis globais
 

 //Essa classe não precisa de contrutor
  void Iniciar();//inicia todos os pinos usados para controlar o robolito;

  void LigaLuz();//Liga a luzinha amarela 
  void DesligaLuz();//Desliga a luzinha da placa
  
  void LigaMotorEsquerdo(bool direcao, int velocidade);//Liga o motor esquerdo, na direção determinada pelo 
                                                      //usuário e na velocidade determinada pelo usuário
  void DesligaMotorEsquerdo();//Desliga o motor esquerdo. 
  
  void LigaMotorDireito(bool direcao, int velocidade); //Liga o motor direito, na direção determinada pelo 
                                                       //usuário e na velocidade determinada pelo usuário
  void DesligaMotorDireito();//Desliga o motor direito.

  void Espera(float tempo);//Espera quantos segundo o usuário mandar

  void GiraACabeca(float angulo);//Move a cabeça do robolito por um determinado ângulo.
  void LevantaACabeca(float angulo);

  long MedeDistancia();//Mede a distância entre o sensor do Robolito e retorna o valor em centímetros

  int OlhoDireitoEnxerga();
  int OlhoEsquerdoEnxerga();
   
  private:

  //Variáveis privadas

  //Variáveis para guardar o estado de funcionamento das rodas, assim como a direção de rotação.

  
  //Metodos Privados

 
};


#endif
