ISR(TIMER1_COMPA_vect){ 
    interrupts();
    if (!--secondTimer){
        secondTimer =  _1_SECOND;
        secondService();    
    }     
    if(!--readTimer){
      //read
      readFlag = true;
      readTimer = _2m_SECOND;
    }
    if(!--printTimer){
      //print
      printFlag = true;
      printTimer = _2_SECOND;
    }
    if(tempFlag){
      if(!--tempTimer){
        tempFlag = false;
        tempTimer = _5_SECOND;
        line2Clear();
      }
    }
    if(!--saveTimer){
      //print
      saveFlag = true;
      saveTimer = _1_MIN;
    }
}

void secondService(){
    if(inputTimer){
        inputTimer--;
    }
}
