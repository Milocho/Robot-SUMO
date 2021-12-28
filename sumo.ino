/*Sumobot sobre suelo blanco y círculo negro
el valor de color negro en los sensores infrarrojos
es de 480 .Se usó la comunicación serial para obtener estos valores.
/*
Instituto tecnologico de Pachuca
Elaboro: Emilio Montaño
*/*/
//Declaración de los pines
int IN1 = 13;    // Input1 conectada al pin 5
int IN2 = 12;    // Input2 conectada al pin 6 MOTOR DERECHO
int ENA = 11;    // ENB conectada al pin 12 de Arduino

int IN3 = 9;    // Input3 conectada al pin 3
int IN4 = 8;    // Input4 conectada al pin 4 MOTOR IZQUIERDO
int ENB = 10;    // ENB conectada al pin 11 de Arduino

int sensFs = 7; //sensor frontal delantero salida del pulso trig 
int sensFe = 6; //sensor frontal delantero entrada del pulso

                                      int sensTs = 9; // sensor trasero salida del pulso trig 
                                      int sensTe = 12; //sensor trasero entrada del pulso

int sensDeli = 0; //sensor IR delantero
int sensDeld = 2; //sensor IR delantero

                                       int sensTrasi = 1; //sensor IR trasero
                                       int sensTrasd = 13; //sensor IR trasero

long distancia;
long tiempo;


//Declaración de I/O's
void setup()
{

pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT); //Motor derecho
pinMode (ENA, OUTPUT); 

pinMode (IN3, OUTPUT); 
pinMode (IN4, OUTPUT); //Motor izquierdo
pinMode (ENB, OUTPUT); 

pinMode (sensFs, OUTPUT);  /*activación del pin 7 como salida: para el pulso ultrasónico*/
pinMode (sensFe, INPUT);   /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/

                               
pinMode (sensDeli, INPUT);  /*activación del pin 0 como salida*/
pinMode (sensDeld, INPUT);  /*activación del pin 2 como salida*/

                              

void loop()
{

  // lectura del pin 0
int buttonStateDi = digitalRead(sensDeli);

// imprision del resultado
Serial.println(buttonStateDi);
delay(100);        // delay in between reads for stability

if(buttonStateDi=0){
  
  blancodelanteizq();
  
}/*
else
{
Buscar();
}*/

}
  // lectura del pin 0
int buttonStateDd = digitalRead(sensDeld);

// imprision del resultado
Serial.println(buttonStateDd);
delay(100);        // delay in between reads for stability

if(buttonStateDd=0){
  
blancodelanteder();
  
}/*
else
{
Buscar();
}*/


  // lectura del pin 1
int buttonStateTi = digitalRead(sensTrasi);

// imprision del resultado
Serial.println(buttonStateTi);
delay(100);        // delay in between reads for stability

if(buttonStateTi=1){
  
 blancoatrasizquierda();
  
}/*
else

{

Buscar();

}*/

{
  // lectura del pin 1
int buttonStateTd = digitalRead(sensTrasd);

// imprision del resultado
Serial.println(buttonStateTd);
delay(100);        // delay in between reads for stability

if(buttonStateTd=1){
  
 blancoatrasderecha();
  
}
}



//----------- ACCIONES IMPACTO-------------

digitalWrite(sensFs,LOW); /* Por cuestión de estabilización del sensor*/
delayMicroseconds(5);
digitalWrite(sensFs, HIGH); /* envío del pulso ultrasónico trig*/
delayMicroseconds(10);
tiempo=pulseIn(sensFe, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
deja de hacerlo, LOW, la longitud del pulso entrante*/
distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
/*Monitorización en centímetros por el monitor serial*/
Serial.println("Distancia ");
Serial.println(distancia);
Serial.println(" cm");
delay(100);

if(distancia< 25)
{
golpeFder(); 
}
else 
{
Buscar();
}





//---------------MOVIMIENTOS--------------
int adelante () {
digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW); //motor izquierdo
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
analogWrite(ENB,70);
delay(2);
analogWrite(ENB,120);
delay(2);*/
analogWrite(ENB,160);
delay(2);
analogWrite(ENB,255);
delay(2000);*/

digitalWrite (IN1, HIGH);
digitalWrite (IN2, LOW); //motor derecho
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
analogWrite(ENA,70);
delay(2);
analogWrite(ENA,120);
delay(2);
analogWrite(ENA,160);
delay(2);
analogWrite(ENA,255);
delay(2000);
}

int atras()
{
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH); //motor izquierdo
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
analogWrite(ENB,70);
delay(2);
analogWrite(ENB,120);
delay(2);
analogWrite(ENB,160);
delay(2);
analogWrite(ENB,255);
delay(2000);

/*digitalWrite (IN1, LOW);
digitalWrite (IN2, HIGH); //motor derecho
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
 analogWrite(ENA,70);
delay(2);
analogWrite(ENA,120);
delay(2);*/
analogWrite(ENA,160);
/*delay(2);
analogWrite(ENA,255);
delay(2000);*/
}

int izquierda()
{

delay(100);
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH); //motor izquierdo
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
analogWrite(ENB,70);
delay(2);
analogWrite(ENB,120);
delay(2);
analogWrite(ENB,100);
delay(2);
analogWrite(ENB,255);
delay(2000);

digitalWrite (IN1, HIGH);
digitalWrite (IN2, LOW); //motor derecho
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
analogWrite(ENA,70);
delay(2);
analogWrite(ENA,120);
delay(2);
analogWrite(ENA,100);
delay(2);
analogWrite(ENA,255);
delay(2000);
}

int derecha()
{
digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW); //motor izquierdo
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
analogWrite(ENB,70);
delay(2);
analogWrite(ENB,120);
delay(2);
analogWrite(ENB,100);
delay(2);
analogWrite(ENB,255);
delay(2000);

digitalWrite (IN1, LOW);
digitalWrite (IN2, HIGH); //motor derecho
// Aplicamos PWM al pin ENB, haciendo girar el motor, cada 0.2 seg aumenta la velocidad
analogWrite(ENA,70);
delay(2);
analogWrite(ENA,120);
delay(2);
analogWrite(ENA,100);
delay(2);
analogWrite(ENA,255);
delay(2000);
}
//--------------GOLPES-------------------

int Buscar()
{
izquierda();
delay(2000);
adelante();
delay(2000);
}


int golpeFder()
{
adelante();
delay(2000);
adelante();
delay(2000);
atras();
delay(2000);

}

int golpeFizq()
{
atras();
delay(1000) ;
izquierda();
delay(300);
adelante();
}

int golpeTder()
{
atras();
delay(2000);
atras();
delay(2000);
adelante();
delay(2000);
}


int golpeTizq()
{
adelante();
delay(1000);
derecha();
delay(300);
atras();
}

int blancodelanteizq()
{
atras();
delay(1000);
derecha();
delay(2000);
adelante();
delay(1000);
}

int blancodelanteder()
{
atras();
delay(1000);
izquierda();
delay(2000);
adelante();
delay(1000);
}
