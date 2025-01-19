#include <Servo.h> 

#define pinServ1 3
#define pinServ2 5
#define pinServ3 6
#define pinServ4 9

#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A3

Servo serv1,serv2,serv3,serv4;

int motor1,motor2,motor3,motor4;

String modo;

void setup() {

  Serial.begin(9600); 

  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);
  
}

void loop(){

Manual();

  Debug();

}

void Debug()
{

  Serial.print("motor1: ");
  Serial.println(motor1);
  Serial.print("motor2: ");
  Serial.println(motor2);
  Serial.print("motor3: ");
  Serial.println(motor3);
  Serial.print("motor4: ");
  Serial.println(motor4);
  Serial.println(">>>>>>>>>>>>>>>");
  delay(100);

}

void Manual()
{

  serv1.write(motor1);
  serv2.write(motor2);
  serv3.write(motor3);
  serv4.write(motor4);

  motor1 = map(analogRead(pot1),0,1023,0,180);
  motor2 = map(analogRead(pot2),0,1023,10,95);
  motor3 = map(analogRead(pot3),0,1023,85,180);
  motor4 = map(analogRead(pot4),0,1023,0,100);

}

void Carregar()
{
    serv1.write(177);
  serv2.write(37);
  serv3.write(85);
  serv4.write(0);
  
  delay(1000);

  for (int i = 177; i >= 2; i--)
  {
    serv1.write(i);
    delay(10);
  }  

  delay(300);  
  
  for (int i = 37; i <= 82; i++)
  {
    serv2.write(i);
    delay(10);
  }  
  
  serv4.write(75);

  delay(300);  

  for (int i = 82; i >= 37; i--)
  {  
    serv2.write(i);
    delay(10);
  }
  delay(600);

  for (int i = 2; i <= 177; i++)
  {
    serv1.write(i);
    delay(10);
  }
  delay(600);  
  
  for (int i = 37; i <= 94; i++)
  {
    serv2.write(i);
    delay(10);
  }
  delay(300);

  serv4.write(0);

  delay(300);

  serv2.write(37);

  delay(300);
}