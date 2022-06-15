#include <TSC3200.h>

TSC3200 color(8, 9, 10, 11, 12);

void setup() {
  color.begin();
  Serial.begin(9600);
}

void loop() {
  color.readColor();
  Serial.print("Red=");
  Serial.print(color.red);
  Serial.print(" Blue=");
  Serial.print(color.blue);
  Serial.print(" Green=");
  Serial.println(color.green);
  Serial.print("Color=");
  Serial.println(color.colorName());
  delay(1000);
}