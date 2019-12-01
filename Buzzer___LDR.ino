
#define relay 10
int buzzer = 9;
int LDR = A0;
int TouchSensor = 3; //connected to Digital pin D3
int led = 2;
void setup() 
{
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(LDR, INPUT);
pinMode(led, OUTPUT);
  pinMode(TouchSensor, INPUT);
}

void loop() {
int LDRValue = analogRead(LDR);
Serial.print("sensor = ");
Serial.print(LDRValue);
if(digitalRead(TouchSensor)==HIGH)       //Read Touch sensor signal
   { 
    digitalWrite(led, HIGH);   // if Touch sensor is HIGH, then turn on
    Serial.println("Led ON");
   }
  else
   {
    digitalWrite(led, LOW);    // if Touch sensor is LOW, then turn off the led
    Serial.println("Led OFF");
   }
  delay(50); // Slow down the output for easier reading

if (LDRValue <=100)
{
  noTone(buzzer);
//digitalWrite(buzzer,LOW );
//digitalWrite(relay, LOW);
//Serial.println("It's Dark Outside; Lights status: OFF");
}
else 
{
  tone(buzzer, 1000);
//digitalWrite(buzzer, HIGH);
//digitalWrite(relay, HIGH);
//Serial.println("It's Bright Outside; Lights status: ON");
}
}
// Watch video here: https://www.youtube.com/watch?v=WdfA57TUyII

/*
Arduino     Touch Sensor
  5V         VCC
  GND        GND
  D3         SIG
*/
