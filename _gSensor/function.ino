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
