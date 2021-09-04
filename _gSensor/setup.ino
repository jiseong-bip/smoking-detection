void setup(){
  Serial.begin(9600);
  pinMode(ANALOGPIN,INPUT);
  pinMode(BUZ_Pin,OUTPUT);
  delay(3000);
  lcd.begin();
  lcd.backlight();
  lcd.noCursor();
  startTimer40ms();
  
  Serial.println("Setup Done..");
}

void startTimer40ms() {
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
    
    // set compare match register to desired timer count:
    OCR1A = 620;    // 40ms
    
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
  
    // Set CS10 and CS12 bits for 1024 prescaler:
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
  
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
}  
