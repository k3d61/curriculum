//Tutorial by RoboIndia on Motor Control
//Hardware Require: Motor Driver(By RoboIndia) & Arduino

//#define sensor A0 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)


//Motor B
const int inputPin3  = 8;
const int inputPin4  = 9; 
const int inputPinLimit  = 10; 
const int inputPinLimit2  = 11; 


const int analogPin = A0;

const int upThreshold = 500;
const int downThreshold = 300;

void setup() 
{
  pinMode(inputPin3, OUTPUT);
  pinMode(inputPin4, OUTPUT); 
  pinMode(inputPinLimit, INPUT_PULLUP); 
  pinMode(inputPinLimit2, INPUT_PULLUP); 
  
    Serial.begin(9600); // start the serial port 
  }

  void loop() 
  {
 //float volts = analogRead(analogPin)*0.0048828125;  // value from sensor * (5/1024)
 // int distance = 13*pow(volts, -1); // worked out from datasheet graph
    
   int sharp_sen = analogRead(analogPin);
 int flagTurn = 1; // 1 UP  0 Down

 int limit = digitalRead(inputPinLimit);
 int limitD = digitalRead(inputPinLimit2);
 
 Serial.print(limit);
 Serial.print(" ");
 Serial.print(limitD);
 Serial.print(" ");
 Serial.print(sharp_sen);
 Serial.print("\t->");
 
 //if (sharp_sen < upThreshold && flagTurn == 1)
 if (limit== 1)
 {
  sharp_sen = analogRead(analogPin);
  Serial.println(" Up \t" );
/*  
  Serial.print(sharp_sen);
  Serial.print(" ");
  Serial.print(flagTurn);
  Serial.print(" ");
  Serial.println(digitalRead(inputPinLimit));
  */
  digitalWrite(inputPin3, HIGH);
  digitalWrite(inputPin4, LOW);
}
else if(sharp_sen > upThreshold && flagTurn == 1 ){
  flagTurn = 0;
}
if( limit == 0 ){
  Serial.println(" STOP\t");
  digitalWrite(inputPin3, HIGH);
  digitalWrite(inputPin4, HIGH);
}

/*  if (sharp_sen > downThreshold && flagTurn == 0)
  {
  sharp_sen = analogRead(analogPin);
  Serial.println(" DOWN\t");
  Serial.print(" ");
  Serial.print(sharp_sen);
  Serial.print(" ");
  Serial.print(flagTurn);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, HIGH);
    delay(2000);
 }
  else if( (sharp_sen < downThreshold) && (flagTurn == 0) ){
    
    flagTurn = 1;
}

*/
}