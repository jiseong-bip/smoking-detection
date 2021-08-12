#define _2m_SECOND           200/40    
#define _2_SECOND            2000/40                       
#define _10_SECOND           10000/40
#define _1_SECOND            1000/40
#define _5_SECOND            5000/40


#define ANALOGPIN A0    
#define RZERO 206.85 

unsigned int inputTimer = 0;
unsigned int readTimer = _2m_SECOND;
unsigned int printTimer = _2_SECOND;
unsigned int tempTimer = _5_SECOND;


boolean readFlag = false;
boolean printFlag = false;
boolean tempFlag = false;



int th_Arr[3] = {70, 150, 200};

int _rzero; 
float _sData;
