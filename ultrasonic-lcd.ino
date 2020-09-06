int redPin = 11;   // R petal on RGB LED module connected to digital pin 11 
int greenPin = 10; // G petal on RGB LED module connected to digital pin 9 
int bluePin = 9;   // B petal on RGB LED module connected to digital pin 10
#define trigPin 13
#define echoPin 12 
int buzzerPin=8;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);   // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
  pinMode(bluePin, OUTPUT);  // sets the bluePin to be an output 
  pinMode(buzzerPin,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 30 and distance >20)
{
  color(255, 255, 0);
  digitalWrite(buzzerPin,LOW); 
}
else if (distance < 10)
{
  color(255,0,0);
  digitalWrite(buzzerPin,HIGH); 
  
}
else if (distance > 30){
  color(0,255,0);
  digitalWrite(buzzerPin,LOW); 
  
}
Serial.print(distance);
Serial.println(" cm");
delay(500);

}


void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, red);     // PWM signal output   
     analogWrite(greenPin, green); // PWM signal output
     analogWrite(bluePin, blue);   // PWM signal output
}     
