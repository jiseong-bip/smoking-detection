#include<LiquidCrystal_I2C.h>
#include "MQ135.h"
#include "gas.h"

MQ135 gasSensor = MQ135(ANALOGPIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void loop() {

  menuService();
  
  if(readFlag){
    readFlag = false;
    _sData = gasSensor.getPPM();
    //lcd update
    updateLcd();
  }
  
  if(printFlag){
    printFlag = false;
    Serial.print("Gas ppm value : ");
    Serial.println(_sData);
  }
  
  if(!tempFlag) temp(_sData);

  
}
