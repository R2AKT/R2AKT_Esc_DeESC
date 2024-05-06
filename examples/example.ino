#include <r2akt_esc_deesc.h>

void setup() {
  Serial.begin (9600);
  Serial.println ("All serial data will passthru, except byte 0xC0. Byte 0xC0 will be escaped.");
}

void loop() {
  const uint8_t Buff_Len = 10;
  uint8_t BuffCount = 0;
  uint8_t DataBuff[Buff_Len] = {};
  uint8_t DataEscBuff[Buff_Len*2] = {};
  uint8_t DataDeEscBuff[Buff_Len] = {};
  size_t EscCount = 0;
  size_t DeEscCount = 0;

  BuffCount = Serial.readBytes (DataBuff, Buff_Len);
  if (BuffCount > 0) {
    Serial.print ("Readed bytes - ");
    Serial.println (BuffCount);
    Serial.print ("RAW data: ");
    for (uint8_t Count = 0; Count < BuffCount; Count++) {
      Serial.print (DataBuff[Count], HEX);
    }
    Serial.print ("\n");
    
    EscCount = _ESCBuff (DataEscBuff , DataBuff, BuffCount);
    Serial.print ("ESC bytes - ");
    Serial.print (EscCount);
    Serial.print (" , add bytes - ");
    Serial.println (EscCount - BuffCount);
    Serial.print ("ESC data: ");
    for (uint8_t Count = 0; Count < EscCount; Count++) {
      Serial.print (DataEscBuff[Count], HEX);
    }
    Serial.print ("\n");

    DeEscCount = _DeESCBuff (DataDeEscBuff , DataEscBuff, EscCount);
    Serial.print ("DeESC bytes - ");
    Serial.print (DeEscCount);
    Serial.print (" , remove bytes - ");
    Serial.println (EscCount - DeEscCount);
    Serial.print ("DeESC data: ");
    for (uint8_t Count = 0; Count < DeEscCount; Count++) {
      Serial.print (DataDeEscBuff[Count], HEX);
    }
    Serial.print ("\n");
  }
}
