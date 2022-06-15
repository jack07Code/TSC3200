//Library made by Martinelli Giacomo on 15 June 2022. Licence MIT
//This library includes parts of a code taken by the Arduino Project Hub linked in README
//and works only with the TSC3200 sensor

#include <TSC3200.h>

TSC3200 color(8, 9, 10, 11, 12);   //the pin Are(in order) s0, s1, s2, s3, out

void setup() {
  color.begin();    //Sets s0 and s1 to HIGH
  Serial.begin(9600);
}

void loop() {
  color.readColor();  //updates all the values
  Serial.print("Red=");
  Serial.print(color.red);   //red value
  Serial.print(" Blue=");
  Serial.print(color.blue);  //blue value
  Serial.print(" Green=");
  Serial.println(color.green);  //green value
  Serial.print("Color=");
  Serial.println(color.colorName());  //returns a String that could have 4 values: Red, Blue, Green, Unknown
  delay(1000);
}
