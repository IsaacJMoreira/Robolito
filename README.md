  # Biblioteca Robolito

Pequena biblioteca que fornece uma camada de abstração de hardware (HAL) para 
facilitar o ensino de programação para crianças a partir de 8 anos de idade.
A biblioteca foi criada na IDE Arduino, requerendo um arduino UNO ou similar, 
um kit de robótica simples, consistindo de um chassi, 2 motores com redução e 
o driver L298, 2 servomotores 9g, um sensor de ultrasom, 2 sensores de proximidade
infravermelho.

O kit é bastante acessível, como o desse link:
https://shopee.com.br/Kit-Chassi-Carro-Robotico-2-Motores-Inteligente-Smart-PARA-Arduino-UNO-i.345633532.14916840381?sp_atk=04d5cd0c-cef9-4319-bf81-8c8e873a2ac2&xptdk=04d5cd0c-cef9-4319-bf81-8c8e873a2ac2

A biblioteca abstrai todo o funcionamento do hardware em apenas 13 funções intuitivas:

  #void Iniciar();//inicia todos os pinos usados para controlar o robolito;

  #void LigaLuz();//Liga a luzinha amarela 
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
