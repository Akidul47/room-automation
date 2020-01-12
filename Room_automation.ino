#include <SoftwareSerial.h>
int in1=7;
int in2=8;
int in3=9;
int in4=10;
int dummy_var;
String str;
char c;
SoftwareSerial HC(3,4);
void setup(){
  HC.begin(9600);
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}
void loop(){
  
  while(HC.available()>0){
    c=HC.read();
    str +=c;
    Serial.println(str);
    delay(100);
  }
  if(str=="Light 1 ON"){
    delay(250); 
    digitalWrite(in1,LOW);
  }
  else if(str=="Light 1 OFF"){
      delay(250); 
      digitalWrite(in1,HIGH);
  }
  else if(str=="Light 2 ON"){
      delay(250); 
      digitalWrite(in2,LOW);
  }
  else if(str=="Light 2 OFF"){
      delay(250); 
      digitalWrite(in2,HIGH);
  }
  
  else if(str=="Fan 1 ON"){
      delay(250); 
      digitalWrite(in3,LOW);
  }
  
   else if(str=="Fan 1 OFF"){
      delay(250); 
      digitalWrite(in3,HIGH);
   }
     else if(str=="Fan 2 ON"){
      delay(250); 
      digitalWrite(in4,LOW);
     }
       else if(str=="Fan 2 OFF"){
      delay(250); 
      digitalWrite(in4,HIGH);
     }
     
    str="";  

}
