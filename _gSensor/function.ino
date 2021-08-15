void updateLcd(){
  line1Clear();
  lcd.setCursor(0, 0);
  lcd.print("ppm: ");
  lcd.print(_sData);
}

boolean parseIntInput(String s, int* t){
    if(s == "00"){        // toint doesn't work for 00
        t[0] = 0;
        return true;
    }
    t[0] = s.toInt();
    if (t[0] == 0){
        return false;
    } else {
        return true;
    }
}

void newData(float _data){
  for(int i=arrSize-1; i>0; i--){
    _DataArr[i] = _DataArr[i-1];
  }
  _DataArr[0] = _data;
}

float getMax(){  
  float _max = 0;
  for(int x=0; x<arrSize; x++){
    if(_DataArr[x] > _max) _max = _DataArr[x];
  }
  return _max;
}

void _level(){
  if(getMax() > th_Arr[2]){
      Serial.println("[L] level 3");
    }else if(getMax() > th_Arr[1]){
      Serial.println("[L] level 2");
    }else if(getMax() > th_Arr[0]){
      Serial.println("[L] level 1");
    }else if(getMax()){
      Serial.println("[L] level 0");
    }  
}

void temp(float _data){  
    if(_data > th_Arr[2]){
      line2Clear();
      lcd.setCursor(0, 1);
      lcd.print("get out!!");
      tempFlag = true;
    }else if(_data > th_Arr[1]){
        line2Clear();
        lcd.setCursor(0, 1);
        lcd.print("danger!!");
        tempFlag = true;
    }else if(_data > th_Arr[0]){
        line2Clear();
        lcd.setCursor(0, 1);
        lcd.print("warning");
        tempFlag = true;
    }  
}

void line1Clear(){
  lcd.setCursor(0, 0);
  lcd.print("                ");
}

void line2Clear(){
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
