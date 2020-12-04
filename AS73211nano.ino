#include "AS73211.h"
uint8_t X = 0x03;
uint16_t test = 128;
float xvalue,yvalue,zvalue;
AS73211 as = AS73211(0x74);    //此处使用从机地址
//AS73211的从机地址用A0、A1设置，此处为1，1，1，0，1，0，0，0x74// 通用设置手法为1，1，1，0，1，A0，A1
void setup(){
  //AS73211(12);
  Serial.begin(115200);
  Serial.print("Serial Started");
  as.begin();
  Serial.print("as started");
}
//Ee: Input light irradiance regarding to the photodiode’s area within the conversion time interval
void loop(){
  delay(1000);
  xvalue = as.convertingToEe(_COLOR6_MREG_MEASUREMENT_X_CHANNEL,as.color6_readData(_COLOR6_MREG_MEASUREMENT_X_CHANNEL));
  Serial.print(xvalue,8);
  Serial.print("    ");
  yvalue = as.convertingToEe(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL,as.color6_readData(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL));
  Serial.print(yvalue,8);
  Serial.print("    ");
  zvalue = as.convertingToEe(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL,as.color6_readData(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL));
  Serial.println(zvalue,8);
  Serial.print(as.color6_readData(_COLOR6_MREG_MEASUREMENT_X_CHANNEL));
  Serial.print("    ");
  Serial.print(as.color6_readData(_COLOR6_MREG_MEASUREMENT_Y_CHANNEL));
  Serial.print("    ");
  Serial.println(as.color6_readData(_COLOR6_MREG_MEASUREMENT_Z_CHANNEL));
  Serial.println(as.getTemperature(),4);
}
