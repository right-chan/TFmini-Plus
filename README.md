# TFmini-Plus

```C++
#include "TFmini.h"

TFmini TF;
uint16_t distance, strength;

void setup() {
  Serial.begin(115200);
  TF.begin(Serial3);
}

void loop() {
  if(TF.measure()){
    distance = TF.getDistance();
    strength = TF.getStrength();

    Serial.print("Distance = "); Serial.println(distance);
    Serial.print("   Strength = "); Serial.println(strength);
  }
  else
  {
    Serial.println("no data");
  }
  delay(50);
}
```
