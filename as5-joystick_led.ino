
int UpDown = 0;
int LeftRight = 0;
/* Arduino Micro output pins*/
int DWN = 13;
int UP = 12;
int LEFT = 11;
int RT = 10;
/* Arduino Micro Input Pins */
int X_PIN=A0;
int Y_PIN=A1;

int MID = 10; 
int LRMID = 0;
int UPMID = 0;


void setup(){
  
  pinMode(DWN, OUTPUT);
  pinMode(UP, OUTPUT);  
  pinMode(LEFT, OUTPUT); 
  pinMode(RT, OUTPUT);
   
  digitalWrite(DWN, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RT, HIGH);
  
  
  LRMID = analogRead(X_PIN);
  UPMID = analogRead(Y_PIN);
}

void loop(){

  UpDown = analogRead(X_PIN);
  LeftRight = analogRead(Y_PIN);
  // UP-DOWN
  if(UpDown < UPMID - MID){
   digitalWrite(DWN, LOW);
  }else{
   digitalWrite(DWN, HIGH);
  }
  
  if(UpDown > UPMID + MID){
   digitalWrite(UP, LOW);
  }else{
   digitalWrite(UP, HIGH);
  }
  // LEFT-RIGHT
  if(LeftRight < LRMID - MID){
   digitalWrite(LEFT, LOW);
  }else{
   digitalWrite(LEFT, HIGH);
  }
  
  if(LeftRight > LRMID + MID){
   digitalWrite(RT, LOW);
  }else{
   digitalWrite(RT, HIGH);
  }

  delay(400); 

}
