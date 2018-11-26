int PotensioPin1 = A0;
int PotensioPin2 = A2;

long value = 0;
long realValue = 0;
long value2 = 0;
long realValue2 = 0;
unsigned long current_time;
unsigned long last_time;
bool turnOn = true;

int ToT[10][8] = { {0, 0, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 1, 1, 0, 1, 1}, 
                   {0, 0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 0, 1, 0, 0, 1},
                   {0, 1, 0, 0, 1, 0, 1, 1},
                   {1, 0, 0, 0, 1, 0, 0, 1},
                   {1, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0, 1} };
int output[8];

void displayNum(int value){
  if(value>99){
    value=99;
  }
  int satuan;
  int puluhan;
  satuan = value%10;
  puluhan = (value-satuan)/10;
  for(int i = 0; i < 7; i++) {
    digitalWrite(i, ToT[puluhan][i]);
  }
  for(int i = 0; i < 7; i++) {
    digitalWrite(i+7, ToT[satuan][i]);
  }
}

void displayNone(){
  for(int i = 0; i < 14; i++) {
    digitalWrite(i, 1);
    }
  }

void setup() {
  for (int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void handleDisplay(int delayValue){
  if(current_time - last_time > delayValue){
      if(turnOn){
        displayNum(realValue);  
        }
      else{
        displayNone();
      }
      turnOn = not turnOn;
      last_time = current_time;
  }
}

void loop() {
  current_time = millis();
  
  value = analogRead(PotensioPin1);
  value2 = analogRead(PotensioPin2);
  realValue = floor(value*99/1007);
  realValue2 = floor(value2*20/1020);

  handleDisplay(realValue2*100);
  
}
