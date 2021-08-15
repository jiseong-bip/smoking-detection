#define _2m_SECOND           200/40    
#define _2_SECOND            2000/40                       
#define _10_SECOND           10000/40
#define _1_SECOND            1000/40
#define _5_SECOND            5000/40

#define INPUT_TIME           30
#define ANALOGPIN A0    
#define RZERO 206.85 
#define arrSize              60

unsigned int inputTimer = 0;
unsigned int readTimer = _2m_SECOND;
unsigned int printTimer = _2_SECOND;
unsigned int tempTimer = _5_SECOND;
unsigned int secondTimer = _1_SECOND;
unsigned int saveTimer = _1_MIN;

boolean readFlag = false;
boolean printFlag = false;
boolean tempFlag = false;
boolean saveFlag = false;
boolean adminMode = false;


int th_Arr[3] = {10, 30, 50};
float _DataArr[arrSize];

int _rzero; 
float _sData;
