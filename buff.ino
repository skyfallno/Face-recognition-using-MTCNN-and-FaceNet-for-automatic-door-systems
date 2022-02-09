#include <string.h>
int led=13;             //Khai báo chân Led 4
//String buff;            //Biến dùng để lưu dữ liệu từ Raspberry Pi
int buff=0;
void setup() {
  
 Serial.begin(9600);   //Bật cổng Serial Baudrate 9600
  pinMode(led,OUTPUT);  //Khai báo chân OUTPUT
}

void loop() {
  if (Serial.available()) //Nếu có tín hiệu từ Pi
  {
   // buff = Serial.readStringUntil('\r'); //Đọc vào đến khi gặp \r (xuống dòng)
    buff= Serial.read();
    if (buff=='1')             //Nếu dữ liệu = "Led On"
    {
      digitalWrite(led,HIGH);       //Bật HIGH chân led
      Serial.println("Turned On");  //Trả ngược về "Turned On"
    } else
    
       if   (buff=='0')  //Nếu dữ liệu = "Led Off"
    {
      digitalWrite(led,LOW);        //Bật LOW chân led
      Serial.println("Turned Off"); //Trả ngược về "Turned Off"
    }

  
  }
}
