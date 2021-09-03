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

//2
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
      Serial.println(" [L] 3");
    }else if(getMax() > th_Arr[1]){
      Serial.println(" [L] 2");
    }else if(getMax() > th_Arr[0]){
      Serial.println(" [L] 1");
    }else if(getMax()){
      Serial.println(" [L] 0");
    }  
}

float getMin(){
  float _min = _DataArr[0];
  for(int y = 1; y<arrSize; y++){
    if(_DataArr[y] < _min) _min = _DataArr[y];
  }
  return _min;
}

float getAvg(){
  float sum = _DataArr[0];
  for(int z = 1; z<arrSize; z++){
    sum += _DataArr[z];
  }
  return sum / arrSize;
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

void PlayAlert(){
  for (int i = 0;i<=100;i++){
    int f = i * i;
    tone(BUZ_Pin,f,100);
    delay(10);
  }
}

void BUZ(float _data){  
    if(_data > th_Arr[2]){
      PlayAlert();
      buzFlag = true;
    }else if(_data > th_Arr[1]){
        PlayAlert();
        buzFlag = true;
    }else if(_data > th_Arr[0]){
        PlayAlert();
        buzFlag = true;
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
  lcd.print("                ");
}

void line2Clear(){
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
