
int output1 = 7;
int output2 = 6;
int output3 = 4;
int led4 = 10;
int input1 = 8;
int input2 = 5;
int input3 = 2;
int pir = 9;
int buzzer = 3;
int buzzerState = 0;
int val = 0;
void setup() {

  // put your setup code here, to run once:
   pinMode(input1,INPUT);
   pinMode(output1,OUTPUT);
   pinMode(output2,OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(input2,INPUT);
   pinMode(pir,INPUT);
   pinMode(output3,OUTPUT);
   pinMode(buzzer,OUTPUT);
   pinMode(input3,INPUT);

    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val == digitalRead(input1);
  if(digitalRead(input1) || digitalRead(input2)||digitalRead(input3)){
        tone(buzzer,1000);
        }
    else{
        noTone(buzzer);
        }
 if(digitalRead(input1)){
        digitalWrite(output1,HIGH);
        }
    else{
        digitalWrite(output1,LOW);
        }
  if(digitalRead(input2)){
        digitalWrite(output2,HIGH);
        }
    else{
        digitalWrite(output2,LOW);
        }
  if(digitalRead(input3)){
        digitalWrite(output3,HIGH);
        }
    else{
        digitalWrite(output3,LOW);
        }
        if(digitalRead(pir)){
          digitalWrite(led4,HIGH);
          }
          else{
            digitalWrite(led4,LOW);
            }
      }
