#ifndef __DFRobot_TFmini_H__
#define __DFRobot_TFmini_H__

#include <Arduino.h>
#include <SoftwareSerial.h>

#define FRAME_HEADER 0x59

class TFmini
{
  public:
    void begin(SoftwareSerial& A);
    void begin(HardwareSerial& A);
    bool measure();
    uint16_t getDistance();
    uint16_t getStrength();
  private:
    Stream* SerialX;
    uint16_t distance = 0;
    uint16_t strength = 0;
};

#endif
