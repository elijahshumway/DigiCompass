#include <Adafruit_LSM303DLH_Mag.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_LSM303DLH_Mag_Unified mag = Adafruit_LSM303DLH_Mag_Unified(12345); //set up sensor using Adafruit universal library

void setup(void) {
  Serial.begin(115200); //initialize Serial connection between laptop and hardware
  /* Initialise the sensor */
  if (!mag.begin()) {
    /* There was a problem detecting the LSM303 ... check your connections */
    //Serial.println("LSM303 Not Detected");
    while (1)
      ;
  }
}

void loop(void) {
  /* Get a new sensor event */
  sensors_event_t event; 
  mag.getEvent(&event);

  float Pi = 3.14159;

  // Calculate the angle of the vector y,x
  float heading = (atan2(event.magnetic.y, event.magnetic.x) * 180) / Pi;
  
  // Normalize to 0-360
  if (heading < 0) {
    heading = 360 + heading;
  }

  Serial.println(heading); //send data via Serial to computer
  delay(10);
}
