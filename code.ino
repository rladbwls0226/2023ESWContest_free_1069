#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
#include "Servo.h" //서보 라이브러리

int angle1 = 0;
Servo myservo1; //grip
Servo myservo2; //wrist pitch
Servo myservo3; //wrist roll
Servo myservo4; //elbow slide
Servo myservo5; //shoulder slide
Servo myservo6; //waist slide
int blueTx=2;   //Tx (블투 보내는핀 설정)
int blueRx=3;   //Rx (블투 받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString=""; //받는 문자열저장
 
void setup() {
  myservo1.attach(5);   
  myservo2.attach(6);
  myservo3.attach(7);
  myservo4.attach(8);
  myservo5.attach(9);
  myservo6.attach(10);
  
  myservo1.write(55);
  myservo2.write(66);
  myservo3.write(55);
  myservo4.write(39);
  myservo5.write(138);
  myservo6.write(55);

  mySerial.begin(9600); //블루투스 시리얼 개방

}
void loop() {
  while (mySerial.available()) { //블루투스 값 받음
    char myChar = mySerial.read(); //받은 값을 문자로 바꿈
    myString += myChar; //문자열을 계속 갱신
    delay(15);
  }

  if (!myString.equals("")) { //받은 값이 있으면 if 실행
          if (myString.startsWith("a")) { //받은 값의 첫글자가a값이면 실행
                                                               //(앱인벤터로 여러가지 모터를 조정하기위해 사용)
      String value = myString.substring(1, myString.length());//첫글자 제외하고 나머지 문자열 값을 value에 저장
     int servo1Pos = value.toInt(); //value 문자값을 int로 바꿈
     myservo1.write(servo1Pos);
     }
     if (myString.startsWith("b")) { //받은 값의 첫글자가a값이면 실행
                                                               //(앱인벤터로 여러가지 모터를 조정하기위해 사용)
      String value = myString.substring(1, myString.length());//첫글자 제외하고 나머지 문자열 값을 value에 저장
     int servo2Pos = value.toInt(); //value 문자값을 int로 바꿈
     myservo2.write(servo2Pos);
     }
     if (myString.startsWith("c")) { //받은 값의 첫글자가a값이면 실행
                                                               //(앱인벤터로 여러가지 모터를 조정하기위해 사용)
      String value = myString.substring(1, myString.length());//첫글자 제외하고 나머지 문자열 값을 value에 저장
     int servo3Pos = value.toInt(); //value 문자값을 int로 바꿈
     myservo3.write(servo3Pos);
     }
     if (myString.startsWith("d")) { //받은 값의 첫글자가a값이면 실행
                                                               //(앱인벤터로 여러가지 모터를 조정하기위해 사용)
      String value = myString.substring(1, myString.length());//첫글자 제외하고 나머지 문자열 값을 value에 저장
     int servo4Pos = value.toInt(); //value 문자값을 int로 바꿈
     myservo4.write(servo4Pos);
     }
          if (myString.startsWith("e")) { //받은 값의 첫글자가a값이면 실행
                                                               //(앱인벤터로 여러가지 모터를 조정하기위해 사용)
      String value = myString.substring(1, myString.length());//첫글자 제외하고 나머지 문자열 값을 value에 저장
     int servo5Pos = value.toInt(); //value 문자값을 int로 바꿈
     myservo5.write(servo5Pos);
     }
          if (myString.startsWith("f")) { //받은 값의 첫글자가a값이면 실행
                                                               //(앱인벤터로 여러가지 모터를 조정하기위해 사용)
      String value = myString.substring(1, myString.length());//첫글자 제외하고 나머지 문자열 값을 value에 저장
     int servo6Pos = value.toInt(); //value 문자값을 int로 바꿈
     myservo6.write(servo6Pos);
     }
    }
    myString = "";//블루투스 받은값을 초기화
  }
