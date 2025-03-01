#include <LiquidCrystal.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = A3;
const int buttonPin4 = A2;
const int buttonPin5 = A1;

int buttonStatus1 = 0;
int buttonStatus2 = 0;
int buttonStatus3 = 0;
int buttonStatus4 = 0;
int buttonStatus5 = 0;

int cnt = 0;


MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
};

MyData data;

//SINGLE

String f1 = "I need Food";
String f2 = "I need Water";
String f3 = "I am a boy";
String f4 = "let us Play";
String f5 = "How are you";


//DOUBLE

String d12 = "Who are you?";
String d13 = "I dont know";
String d14 = "Where are you?";
String d15 = "Who was he";

String d23 = "It is working";
String d24 = "next";
String d25 = "India is my country";

String d34 = "Good job";
String d35 = "Nice work";

String d45 = "Get me a taxi";


//TRIPPLE

String t123 = "Where are you?";
String t134 = "Call mom!";
String t145 = "I know him";
String t124 = "My cat";
String t125 = "My Dog";
String t135 = "I am Sorry";

String t234 = "Get me that";
String t245 = "Are you ok";
String t235 = "I am a student";

String t345 = "Give me book";


//TETRA

String t1234 = "Beautiful";
String t1345 = "Nice car";
String t1245 = "Mobile Phone";
String t1235 = "Let us study";





//PENTA

String t12345 = "Wrong sentance";



void setup() {

  Wire.begin();
  mpu.initialize();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
}

void loop() {

  // //lcd.clear();
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255);  // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255);  // Y axis data
//  delay(500);
//Serial.print("X: ");
//Serial.println(data.X);
//Serial.print("Y: ");
//Serial.println(data.Y);

  if ((data.X >= 135 && data.X <= 165) && (data.Y >= 65 && data.Y <= 85)) {  //gesture : down
    lcd.clear();
    Serial.println("Hello. How are you");
    lcd.setCursor(0, 0);
    lcd.print("Hello. How are");
    lcd.setCursor(1, 1);  //(col.row)
    lcd.print(" you");
    delay(1500);
    //lcd.clear();
  }
  if ((data.X >= 135 && data.X <= 165) && (data.Y >= 230 && data.Y <= 255)) {  //gesture : up
    lcd.clear();
    Serial.println("Call an ambulance");
    lcd.setCursor(0, 0);
    lcd.print("Call an ");
    lcd.setCursor(1, 1);  //(col.row)
    lcd.print("ambulance");
    delay(1500);
    //lcd.clear();
  }
  if ((data.X >= 235 && data.X <= 255) && (data.Y >= 130 && data.Y <= 150)) {  //gesture : left
    lcd.clear();
    Serial.println("I need Help");
    lcd.setCursor(0, 0);
    lcd.print("I need Help");
    delay(1500);
    //lcd.clear();
  }
  if ((data.X >= 10 && data.X <= 35) && (data.Y >= 90 && data.Y <= 120)) {  //gesture : right
    lcd.clear();
    Serial.println("good morning");
    lcd.setCursor(0, 0);
    lcd.print("good morning");
    delay(1500);
    //lcd.clear();
  }

  buttonStatus1 = digitalRead(buttonPin1);
  buttonStatus2 = digitalRead(buttonPin2);
  buttonStatus3 = digitalRead(buttonPin3);
  buttonStatus4 = digitalRead(buttonPin4);
  buttonStatus5 = digitalRead(buttonPin5);

 

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == HIGH && buttonStatus4 == HIGH && buttonStatus5 == HIGH) {
    lcd.clear();
    Serial.println(f1);
    lcd.setCursor(0, 0);
    lcd.print(f1);
    delay(1500);
//    //lcd.clear();
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == HIGH && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(f2);
    lcd.setCursor(0, 0);
    lcd.print(f2);
    delay(1500);
    //lcd.clear();
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(f3);
    lcd.setCursor(0, 0);
    lcd.print(f3);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(f4);
    lcd.setCursor(0, 0);
    lcd.print(f4);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH && buttonStatus3 == HIGH && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(f5);
    lcd.setCursor(0, 0);
    lcd.print(f5);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }






  /////DOUBLE FINGERS


  if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == HIGH && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d12);
    lcd.setCursor(0, 0);
    lcd.print(d12);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d13);
    lcd.setCursor(0, 0);
    lcd.print(d13);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }
  //
  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d14);
    lcd.setCursor(0, 0);
    lcd.print(d14);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == HIGH && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d15);
    lcd.setCursor(0, 0);
    lcd.print(d15);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }



  if (buttonStatus1 == HIGH && buttonStatus2 == LOW && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d23);
    lcd.setCursor(0, 0);
    lcd.print(d23);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d24);
    lcd.setCursor(0, 0);
    lcd.print(d24);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d25);
    lcd.setCursor(0, 0);
    lcd.print(d25);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(d34);
    lcd.setCursor(0, 0);
    lcd.print(d34);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d35);
    lcd.setCursor(0, 0);
    lcd.print(d35);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(d45);
    lcd.setCursor(0, 0);
    lcd.print(d45);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  //Serial.println("LOOP");

  /////TRIPLE FINGERS


  if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t123);
    lcd.setCursor(0, 0);
    lcd.print(t123);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t134);
    lcd.setCursor(0, 0);
    lcd.print(t134);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }
  //
  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t145);
    lcd.setCursor(0, 0);
    lcd.print(t145);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


  if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t124);
    lcd.setCursor(0, 0);
    lcd.print(t124);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }



  if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t125);
    lcd.setCursor(0, 0);
    lcd.print(t125);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t135);
    lcd.setCursor(0, 0);
    lcd.print(t135);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }





  if (buttonStatus1 == HIGH && buttonStatus2 == LOW && buttonStatus3 == LOW && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t234);
    lcd.setCursor(0, 0);
    lcd.print(t234);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


  if (buttonStatus1 == HIGH && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t245);
    lcd.setCursor(0, 0);
    lcd.print(t245);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == LOW && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t235);
    lcd.setCursor(0, 0);
    lcd.print(t235);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }

  if (buttonStatus1 == HIGH && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == LOW && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t345);
    lcd.setCursor(0, 0);
    lcd.print(t345);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


//TETRA

if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == LOW && buttonStatus4 == LOW && buttonStatus5 == HIGH)

  {
    lcd.clear();
    Serial.println(t1234);
    lcd.setCursor(0, 0);
    lcd.print(t1234);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }





  if (buttonStatus1 == LOW && buttonStatus2 == HIGH && buttonStatus3 == LOW && buttonStatus4 == LOW && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t1345);
    lcd.setCursor(0, 0);
    lcd.print(t1345);
    delay(1500);
    //lcd.clear();
    //    cnt = 0;
  }


  if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == HIGH && buttonStatus4 == LOW && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t1245);
    lcd.setCursor(0, 0);
    lcd.print(t1245);
    delay(1500);
    //lcd.clear();
  }

  if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == LOW && buttonStatus4 == HIGH && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t1235);
    lcd.setCursor(0, 0);
    lcd.print(t1235);
    delay(1500);
    //lcd.clear();
  }

 

  //PENTA

  if (buttonStatus1 == LOW && buttonStatus2 == LOW && buttonStatus3 == LOW && buttonStatus4 == LOW && buttonStatus5 == LOW)

  {
    lcd.clear();
    Serial.println(t12345);
    lcd.setCursor(0, 0);
    lcd.print(t12345);
    delay(1500);
    //lcd.clear();
  }


}
