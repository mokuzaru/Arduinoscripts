
int motor1Pin1 = 3; // pin In1
int motor1Pin2 = 4; // pin In2
int enablePin1 = 5; // pin enA
int motor2Pin1 = 6; //pin In3
int motor2Pin2 = 7; //pin In4
int enablePin2 = 8; //pin ENB
int state;
int flag=0;        //makes sure that the serial only prints once the state

void setup() {
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enablePin1, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enablePin2, OUTPUT);
    // sets enablePin high so that motor can turn on:
    digitalWrite(enablePin1, HIGH);
    digitalWrite(enablePin2, HIGH);    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is '0' the DC motor will turn off
    if (state == '0') {
        digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D low
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Motores: off");
          flag=1;
        }
    }
    // if the state is '1' the motor will turn right
    else if (state == '1') {
        digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
        digitalWrite(motor1Pin2, HIGH); // set pin 7 on L293D high
        digitalWrite(motor2Pin1,LOW);
        digitalWrite(motor2Pin2,HIGH);
        if(flag == 0){
          Serial.println("Motores: derecha");
          flag=1;
        }
    }
    // if the state is '2' the motor will turn left
    else if (state == '2') {
        digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D high
        digitalWrite(motor1Pin2, LOW); // set pin 7 on L293D low
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Motores: izquierda");
          flag=1;
        }
    }
 // if (ard_comman == CMD_ANALOGWRITE) {   
   // analogWrite (pin_num, pin_value);  
    // añadir aquí el código 
    //de regreso; // Hecho. volver a loop (); 
  //}
    // 4) enviar datos a ARDUDROID 
 // if (ard_command == CMD_READ_ARDUDROID) {  
    // char send_to_android [] = "Coloca el texto aquí." ; 
    // Serial.println (send_to_android) / / Ejemplo: Si envía texto 
  //  Serial.print ("analógica 0 =");  
  //  Serial.println (analogRead (A0)) // Ejemplo: Leer y enviar valor pin analógico a Arduino 
  //  retorno // Listo. volver a loop (); 
 // }}
}
