#include<LiquidCrystal_I2C.h>
#include "gas.h"





LiquidCrystal_I2C lcd(0x27, 16, 2);

void loop() {
  menuService();
  if (readFlag) {
    readFlag = false;
    _sData = analogRead(0);
    //lcd update
    updateLcd();
  }

  if (printFlag) {
    printFlag = false;
    if (adminMode) {
      Serial.print("Gas ppm value : ");
      Serial.println(_sData);
    }
    newData(_sData);
  }

  if (saveFlag) {
    saveFlag = false;
    //Serial.printf("[D] %.2f [L] %d\n",getMax(),_level);
    Serial.print("[D] ");
    Serial.print(getMax());
    _level();


  }// 1분에 한번 [D] max [L] level

  if (!tempFlag) temp(_sData);
  //if(!tempFlag) c_Arr();
  if (!buzFlag) BUZ(_sData);
}
