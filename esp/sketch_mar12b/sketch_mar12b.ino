#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
// Replace with your network credentials
//const char* ssid     = "Dom";
//const char* password = "Wifi2004";
//

SoftwareSerial SUART(D7,D8);
  //NodeMCU prefers higher Bd to work

void setup() {
  Serial.begin(115200);
  SUART.begin(115200);
}
String msg="";
void loop(){
  byte a=SUART.available();
if(a != 0)
  {
    char ch=SUART.read();
    if(ch=='/'){
      Serial.println(msg);
      msg="";
    } else {
      msg+=ch;
    }
  }
}
