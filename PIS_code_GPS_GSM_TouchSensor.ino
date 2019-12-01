#include <TinyGPS++.h>
#include <SoftwareSerial.h>


SoftwareSerial GPS_SoftSerial(4, 3);
SoftwareSerial SIM900(7,8);
TinyGPSPlus gps;      

void setup() {
  pinMode(2,OUTPUT); // Touch Sensor attached here
  Serial.begin(9600);
  GPS_SoftSerial.begin(9600);
  SIM900.begin(19200);
  delay(20000);
}
void loop() {
        delay(1000);
        double lat_val, lng_val;
        lat_val = gps.location.lat();
        lng_val = gps.location.lng();

        // If touch Sensor reading is high, then send help message
        if(digitalRead(2) == HIGH)
        {
            ask_for_HELP();
        }

        //App picks data from the messages it receives from here.
        // I have removed my phone number from the string below, 
        // as a concern of privacy.
        SIM900.println("AT + CMGS = \"+91858793****\""); 
        delay(100);
        String txt=String(lat_val) +','+ String(lng_val) ;
        SIM900.println("lat_val"); 
        delay(100);
        
}
void ask_for_HELP() {
  SIM900.print("AT+CMGF=1"); 
  delay(100);

  SIM900.println("AT + CMGS = \"+91858793****\""); 
  delay(100);
  
  SIM900.println("Help !! I might be in trouble. Please keep a check on my location"); 
  delay(100);
  
  // GSM module requires time to send sms.
  delay(5000); 
}
