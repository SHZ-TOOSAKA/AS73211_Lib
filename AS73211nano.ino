#include "AS73211.h"
uint8_t X = 0x03;
uint16_t test = 128;
AS73211 as = AS73211(0x74);    //此处使用从机地址
//AS73211的从机地址用A0、A1设置，此处为1，1，1，0，1，0，0，0x74
void setup(){
  //AS73211(12);
  Serial.begin(115200);
  Serial.print("Serial Started");
  as.begin();
  as.setGainAndTime(Gain64,_COLOR6_CREG1_TIME_128ms);
  Serial.print("as started");
}

void loop(){
  delay(1000);
//  Serial.print(as.convertingToEe(_COLOR6_MREG_MEASUREMENT_X_CHANNEL,as.color6_readData(_COLOR6_MREG_MEASUREMENT_X_CHANNEL)));
//  Serial.print("    ");
//  Serial.print(as.convertingToEe(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL,as.color6_readData(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL)));
//  Serial.print("    ");
//  Serial.println(as.convertingToEe(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL,as.color6_readData(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL)));


  Serial.print(as.color6_readData(_COLOR6_MREG_MEASUREMENT_X_CHANNEL));
  Serial.print("    ");
  Serial.print(as.color6_readData(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL));
  Serial.print("    ");
  Serial.println(as.color6_readData(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL));
  
}
