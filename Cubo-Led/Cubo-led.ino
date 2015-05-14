int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
byte sequencia[] = {0,1,2,3,4,5,6,7,8,9,10}; //vetor com ordem dos leds
byte circulo[] = {2,3,4,7,10,9,8,5,6}; //vetor com ordem dos leds
byte layers[] = {11,12,13}; //vetor com ordem das camadas

void setup() //funçao que executa toda vez
{
  
}

void loop() //fica executanto os codigos em loop
{
  
  
//for(variavel e valor; condicao de parada; incrementador e decrementador)
//{} se tiver chaves executa passo a passo, caso contrario carrega tudo e executa no final da condicao


// ----->>>>> EFEITO 1 <<<<<-----

  //SEQUENCIA LEDS (1,2,3,4,5,6,7,8,9)
  for(int layer = 0; layer <= 2; layer++) //variavel e valor; condicao de parada; incrementador
  {
    delay(10);
    analogWrite(layers[layer], OUTPUT);
    for(int pino = 2; pino <= 10; pino++)
    {
      analogWrite(sequencia[pino], 255);
      delay(70);
      
      for(int pino = 2; pino <= 10; pino++)
      {
        analogWrite(sequencia[pino], 0);
      }
    }
    pinMode(layers[layer], false);
  }
  delay(1000);  //tempo de espera (ms) */
  
  
// ----->>>>> EFEITO 2 <<<<<-----

  //CAMADAS DESCE E SOBE
  for(int layer = 0; layer <= 2; layer++)
  {
    pinMode(layers[layer], OUTPUT);
    for(int leds = 2; leds <= 10; leds++)
      analogWrite(sequencia[leds], 255);
    delay(100);
    pinMode(layers[layer], false);
  }
  for(int layer = 2; layer >= 0; layer--)
  {
    pinMode(layers[layer], OUTPUT);
    for(int leds = 2; leds <= 10; leds++)
      analogWrite(sequencia[leds], 255);
    delay(100);
    pinMode(layers[layer], false);
  }
  for(int layer = 0; layer <= 2; layer++)
    pinMode(layers[layer], false);
  for(int leds = 2; leds <= 10; leds++)
    analogWrite(sequencia[leds], 0);
  delay(1000);  //tempo de espera (ms) */



// ----->>>>> EFEITO 3 <<<<<-----

  //CHUVA ALEATORIA
  for(int vezes = 0; vezes < 10; vezes++)
  {
    int ledRandom = random(2, 10);
    for(int layer = 0; layer <= 2; layer++)
      {
        pinMode(layers[layer], OUTPUT);
        analogWrite(sequencia[ledRandom], 255);
        delay(130);
        analogWrite(sequencia[ledRandom], 0);
        pinMode(layers[layer], false);
      }
  delay(20);
  }
  delay(1000);  //tempo de espera (ms) */
  

// ----->>>>> EFEITO 4 <<<<<-----

  //CIRULO COMPLETO DESCENDO
  for(int layer = 0; layer <= 2; layer++)
  {
    delay(10);
    pinMode(layers[layer], OUTPUT);
    for(int pino = 0; pino <= 7; pino++)
    {
      analogWrite(circulo[pino], 255);
      delay(70);
      
      for(int pino = 0; pino <= 7; pino++)
      {
        analogWrite(circulo[pino], 0);
      }
    }
  }
  //CIRULO POR CAMADA DESCENDO
  for(int layer = 0; layer <= 2; layer++)
  {
    delay(10);  //tempo de espera (ms)
    pinMode(layers[layer], OUTPUT);
    for(int pino = 0; pino <= 7; pino++)
    {
      analogWrite(circulo[pino], 255);
      delay(70);  //tempo de espera (ms)
      
      for(int pino = 0; pino <= 7; pino++)
      {
        analogWrite(circulo[pino], 0);
      }
    }
    pinMode(layers[layer], false);
  }
  //CIRCULO COMPLETO SUBINDO
  for(int layer = 2; layer >= 0; layer--)
  {
    delay(10);
    pinMode(layers[layer], 250);
    for(int pino = 0; pino <= 7; pino++)
    {
      analogWrite(circulo[pino], 255);
      delay(70);
      
      for(int pino = 0; pino <= 7; pino++)
      {
        analogWrite(circulo[pino], 0);
      }
    }
  }
  //CIRCULO POR CAMADA SUBINDO
  for(int layer = 2; layer >= 0; layer--)
  {
    delay(10);
    pinMode(layers[layer], OUTPUT);
    for(int pino = 0; pino <= 7; pino++)
    {
      analogWrite(circulo[pino], 255);
      delay(70);
      
      for(int pino = 0; pino <= 7; pino++)
      {
        analogWrite(circulo[pino], 0);
      }
    }
    pinMode(layers[layer], false);
  }
  delay(1000);  //tempo de espera (ms)*/
  
  
  
// ----->>>>> EFEITO 5 <<<<<-----  
  
  //CIRULO POR CAMADA DESCENDO
  for(int layer = 0; layer <= 2; layer++)
  {
    delay(10);
    pinMode(layers[layer], OUTPUT);
    for(int pino = 0; pino <= 7; pino++)
    {
      analogWrite(circulo[pino], 255);
      delay(70);
      
      for(int pino = 0; pino <= 7; pino++)
      {
        analogWrite(circulo[pino], 0);
      }
    }
    pinMode(layers[layer], false);
  }
   //CIRCULO POR CAMADA SUBINDO
  for(int layer = 2; layer >= 0; layer--)
  {
    delay(10);
    pinMode(layers[layer], OUTPUT);
    for(int pino = 0; pino <= 7; pino++)
    {
      analogWrite(circulo[pino], 255);
      delay(70);
      
      for(int pino = 0; pino <= 7; pino++)
      {
        analogWrite(circulo[pino], 0);
      }
    }
    pinMode(layers[layer], false);
  }
  delay(1000);  //tempo de espera (ms)*/
  
  
  
 // ----->>>>> EFEITO 6 <<<<<----- 
  
  //EXPLOSAO
  for(int vezes = 0; vezes < 3; vezes++)
  {
    pinMode(layers[1], OUTPUT);
    analogWrite(led5, 255);
    delay(50);
    for(int layer = 0; layer <= 2; layer++)
    {
      pinMode(layers[layer], OUTPUT);
    }
    analogWrite(led2, 255);
    analogWrite(led4, 255);
    analogWrite(led6, 255);
    analogWrite(led8, 255);
    delay(100);
    for(int leds = 2; leds <= 10; leds++)
      analogWrite(sequencia[leds], 255);
    delay(400);
    analogWrite(led1, 0);
    analogWrite(led3, 0);
    analogWrite(led7, 0);
    analogWrite(led9, 0);
    delay(200);
    pinMode(layers[0], false);
    pinMode(layers[2], false);
    analogWrite(led2, 0);
    analogWrite(led4, 0);
    analogWrite(led6, 0);
    analogWrite(led8, 0);
    delay(200);
    analogWrite(led5, 0);
    delay(200);
    pinMode(layers[1], false);
  }
  
  delay(1000);  //tempo de espera (ms)*/
}
