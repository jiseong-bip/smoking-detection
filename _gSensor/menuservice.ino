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
