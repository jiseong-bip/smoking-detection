    String mCommand = "";
    String argument = "";
    String argument1 = "";
    String argument2 = "";
    String argument3 = "";
    boolean spaceEntered = false;
    boolean noArgument; 
    boolean numberArgument = false;
    boolean numberArgument1 = false;
    boolean numberArgument2 = false;
    byte serialChar = '\0';
    
void menuService(){ 
        if (!Serial.available()) {
            return;
        }
        char _input[50];
        String _sinput;
        char c; 
        int t, t1, t2, t3, t4, i, ii;
       if (!readSerialLine(_input, 48, INPUT_TIME, false)){
            return;
       }
       mCommand = strtok (_input, " ");
       argument = (String) strtok (NULL, " ");
       argument1 = (String) strtok (NULL, " ");
       argument2 = (String) strtok (NULL, " ");
       argument3 = (String) strtok (NULL, " ");
      if (argument == NULL){  
          noArgument = true;
      } else {
          noArgument = false;
          argument.toCharArray(_input, 20);
      }
          
      numberArgument = parseIntInput (argument, &t);
      numberArgument1 = parseIntInput (argument1, &t1);
      numberArgument2 = parseIntInput (argument2, &t2);
      if(argument == "0"){
          numberArgument = true;
      }
      if(argument1 == "0"){
          numberArgument1 = true;
      }
      if(!numberArgument){
          t = 0;
      }
      if(!numberArgument1){
          t1 = -999;
      }
     if(mCommand == "@test"){
         Serial.println("test ok");
         return;
     }else if(mCommand == "@change"){
         if(numberArgument && numberArgument1 && numberArgument2){
           Serial.println(t);
           Serial.println(t1);
           Serial.println(t2);
           th_Arr[0] = t;
           th_Arr[1] = t1;
           th_Arr[2] = t2;
         }
         return;
     }else if(mCommand == "-=-="){
        Serial.println(F("ADMIN MODE.."));
        adminMode = true;
        return;
    }else if(mCommand == "exit"){
        Serial.println(F("USER MODE.."));
        adminMode = false;
        return;
    }
     
     
     /*else if(mCommand == "@i"){
     
        Serial.print(F("INPUT TIME INTERVER (1~24 )")); 
        Serial.printf("\nCurrent Setting : %d Hour \n", _myCycle/6); 
        Serial.printf("Current Cnt : %d \n", _cycleCnt); 
        readSerialLine(_input, 6, INPUT_TIME, true);
        if (!parseIntInput(_input, &t)){
            warnInvalidInput();
            return;
        } else if (t<1 || t>24){
            warnInvalidInput();
            return;
        }
        if(readAnswer(INPUT_TIME)){
            _sinput = String (_input);
            _myCycle = _sinput.toInt()*6;
            _cycleCnt = _myCycle;
            writeEEPROM(CYCLE_BASE, _myCycle);
            Serial.printf("changed to: %d", _myCycle/6);
            Serial.println();
        }
        return;    
    }*/
    
}

boolean readSerialLine(char* _input, int _bufSize, int _timer, boolean _echo){
    char _c = 0;
    inputTimer = _timer;
    byte i = 0;
    _input[0] = 0;
    
    while((_c != '\r')&&(_c!='\n')){
         if(!inputTimer){
             Serial.print (F("\r\ntime-out... try again.\r\n"));            // Serial.print ("User input time-out");
             _input[0] = '\0'; 
             return false;
         }
         if(Serial.available()){
             if(serialChar){                    // this is to resolve the issue with lines with or without /r/n 
                 _c = serialChar;               // left over character from the previous reading 
                 serialChar = 0;
             } else {
                _c = Serial.read();
             }
             
             if (_echo){
                 Serial.write (_c);
             }
             if((_c != '\r')&&(_c!='\n')){
                 _input[i]= _c;
                 if (i < _bufSize-1){
                    i++;                      // overwrite 
                 }
             }
             
        }// if Serial.available()
    } // while 

    // see if there's any unnecessary \r or \n at once
    delay(10);                                // do not change this unless you're sure
    if(Serial.available()){
        serialChar = Serial.read();
        if(serialChar=='\n' || serialChar=='\r'){
            serialChar = '\0';      // discard. Otherwise, it will be used at the next readline command 
        }
    }
    
    _input[i] = '\0';
    //if (i>0 && _input[0]!= '\r' && _input[0]!= '\n' && _input[0]!= ' '){
    if (i>0){
        return true;
    } else {
        return false;
    }
}
boolean readAnswer(int _time){
    char _buf[25];
    Serial.print (F(" are you sure? ")); 
    inputTimer = _time;
    while(1){
       if(inputTimer == 0){
       return false;
       }
       readSerialLine(_buf, 23, _time, true);
       if (_buf[0] == 'y') {
               Serial.println (F(" -> confirmed."));
               return true;
        } else {
               Serial.println (F(" -> cancelled."));
               return false;
        }
    }
}

void warnInvalidInput(){
    Serial.println (F("invalid input -> cancelled"));
}

void clearSerial(){
    delay(10);  
    while(Serial.available()){
        Serial.read();
        delay(10);  
    }
}
