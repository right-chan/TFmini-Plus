#include "TFmini.h"

void TFmini::begin(SoftwareSerial& A)
{
  A.listen();
  A.begin(115200);
  SerialX = (Stream*)(&A);
}

void TFmini::begin(HardwareSerial& A)
{
  A.begin(115200);
  SerialX = (Stream*)(&A);
}

bool TFmini::measure()
{
  uint8_t buf[9] = {};

  long checksum = 0;
  while (SerialX -> available()) {
    buf[0] = SerialX -> read();
    checksum += buf[0];
    if (buf[0] == FRAME_HEADER) {
      buf[1] = SerialX->read();
      checksum += buf[1];
      if (buf[1] == FRAME_HEADER) {
        for (int i = 2; i < 8; i++) {
          buf[i] = SerialX->read();
          checksum += buf[i];
        }
        buf[8] = SerialX->read();
        checksum &= 0xff;
        if (checksum == buf[8]) {
//          Serial.print(buf[2]+buf[3]*256);
//          Serial.print(" ");
//          Serial.println((buf[3]<<8)|buf[2]);
          distance = (buf[3]<<8)|buf[2];
          strength = buf[4] + buf[5] *256;
          return true;
        }
        else
          checksum = 0;

      }
      else
        checksum = 0;
    }
    else
      checksum = 0;
  }
  return false;
}

uint16_t TFmini::getDistance()
{
  return distance;
}

uint16_t TFmini::getStrength()
{
  return strength;
}
