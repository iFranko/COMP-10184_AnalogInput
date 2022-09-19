#include <Arduino.h>

void setup() {
   // configure the USB serial monitor 
  Serial.begin(115200); 
}

void loop() {

  // read digitized value from the D1 Mini's A/D convertor 
  int iVal = analogRead(A0); 
  float voltage = (iVal * (3300.0 / 1024.0))/1000.0;
  float temp = (float)iVal / 1024;
  temp = temp * 50.0;
  String status;

  if(temp<10){
    status = "Cold!";
  }

  if(temp>=10.0 && temp<=15.0){
    status = "Cool";
  }
  if(temp>15.0 && temp<=25.0){
    status = "Perfect";
  }
  if(temp>25.0 && temp<=30.0){
    status = "Warm";
  }
  if(temp>30.0 && temp<=35.0){
    status = "Hot";
  }
  if(temp>35.0){
    status = "Too Hot!";
  }
  // print value to the USB port 
  Serial.println("Digitized Value = " + String(iVal)+ " is equivalent to " + String(voltage) +"V which temp is " + String(temp)+" Deg. C. which is "+ String(status)); 
 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
}