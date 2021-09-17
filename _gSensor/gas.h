#define _2m_SECOND           200/40    
#define _2_SECOND            2000/40                       
#define _10_SECOND           10000/40
#define _1_SECOND            1000/40
#define _5_SECOND            5000/40
#define _1_MIN               60000/40



#define INPUT_TIME           30
#define ANALOGPIN A0    
#define RZERO 206.85 
#define arrSize              60
#define BUZ_Pin              9


unsigned int inputTimer = 0;
unsigned int readTimer = _2m_SECOND;
unsigned int printTimer = _1_SECOND;
unsigned int tempTimer = _5_SECOND;
unsigned int secondTimer = _1_SECOND;
unsigned int saveTimer = _1_MIN;
unsigned int buzTimer = _2_SECOND;


boolean readFlag = false;
boolean printFlag = false;
boolean tempFlag = false;
boolean saveFlag = false;
boolean adminMode = false;
boolean buzFlag = false;


int th_Arr[3] = {42, 65, 70};
float _DataArr[arrSize];

int _rzero; 
float _sData;
