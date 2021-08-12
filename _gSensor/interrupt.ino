ISR(TIMER1_COMPA_vect){ 
    interrupts();     
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
}

void secondService(){
    if(inputTimer){
        inputTimer--;
    }
}
