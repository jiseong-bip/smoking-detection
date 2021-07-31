#include<LiquidCrystal_I2C.h>
#include "MQ135.h"
#define ANALOGPIN A0    
#define RZERO 206.85    
MQ135 gasSensor = MQ135(ANALOGPIN);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float co2(float a){
  return a*100;
}
