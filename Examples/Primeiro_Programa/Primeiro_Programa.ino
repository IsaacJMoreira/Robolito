#include "Robolito.h"

Robolito Alice;
  
void setup() {

Alice.Iniciar();

Alice.LigaLuz();
Alice.Espera(1);
Alice.DesligaLuz();
Alice.GiraACabeca(0);
Alice.Espera(1);
Alice.GiraACabeca(180);
Alice.Espera(1);
Alice.LevantaACabeca(0);
Alice.Espera(5);
Alice.LevantaACabeca(180);
Alice.Espera(2);
Alice.LevantaACabeca(90);
Alice.Espera(5);


}

void loop() {

}
