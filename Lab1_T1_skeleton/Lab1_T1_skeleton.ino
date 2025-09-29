include "Arduino.h"

#define Vin  //*** Define the GPIO pin 12 as Vin ***
#define Vout   //*** Define the GPIO pin 27 as Vout ***


//float R_SERIES = ; //*** Resistance between Vin and DUT is the sum of serial-connected resistors (in ohms) ***

float x;
float y;

void setup() {

  Serial.begin(); //*** Define the data rate as 115200 ***
  pinMode(Vin,); //*** Set Vin as OUTPUT ***
  pinMode(Vout,); //*** Set Vout as INPUT ***

  
  delay(100);   //*** Set 100 ms delay ***
  //This task only needs to be done once, thus it is placed in setup().
  Serial.println("duty cycle,Vout"); // display duty cycle,Vout: for TASK 1 or current,Vout: for Task 2 3 4
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) 
    {
    
    analogWrite(Vin,onPeriod);// Output PWM at Vin      
    int Vout_value = analogRead(Vout); // read the voltage level at Vout 
    x = float(onPeriod)*100/255 ; // calculate duty cycle for TASK 1 or current for Task 2 3 4
    y = float(Vout_value*3.3)/4095 ; // calculate the voltage at Vout
    Serial.print(); //print the value of duty cycle
    Serial.print("%,"); 
    Serial.println();// print the Vout
  }

  // Press reset button for a new sweep
}

void loop() {
  // Code for continuous operation can be added here
 
}
