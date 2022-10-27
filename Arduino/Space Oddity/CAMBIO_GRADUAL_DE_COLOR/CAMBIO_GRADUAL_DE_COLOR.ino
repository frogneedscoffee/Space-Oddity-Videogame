int intensidadG = 255;
int intensidadR = 0;
int intensidadB = 0;
int pinR;
int pinG;
int pinB;
int Vida= Serial.read();
int numVida = 0;
 
void setup() {
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  pinR=intensidadR;
  pinG=intensidadG;
  pinB=intensidadB;
  if(Vida==("pierdeVida")){
   numVida = numVida + 1;
  }
    if(numVida== 0){
      intensidadG = 255;
    }

    while(numVida == 1 && intensidadG>215 && intensidadR<40){
      intensidadG = intensidadG -1;
      intensidadR = intensidadR +1;
      delay(1);
    }

    while(numVida == 2 && intensidadG>180 && intensidadR<75){
      intensidadG = intensidadG -1;
      intensidadR = intensidadR + 1;
      delay(1);
    }

    while(numVida == 3 && intensidadG>165 && intensidadR<90 ){
      intensidadG = intensidadG -1;
      intensidadR = intensidadR + 1;
      delay(1);
    }

    while(numVida == 4 && intensidadG>127 && intensidadR<127){
      intensidadG = intensidadG -1;
      intensidadR = intensidadR + 1;
      delay(1);
    }

    while(numVida == 5 && ){
      
      delay(1);
    }

    while(numVida == 6 && ){
      
      delay(1);
    }

    while(numVida == 7 && ){
      
      delay(1);
    }


//1, 2, 3 VERDE
//4, 5 AMARILLO/NARANJA
//6, 7 ROJO
    

    
  
  

}
