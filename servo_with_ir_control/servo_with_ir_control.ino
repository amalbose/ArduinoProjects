#include <IRremote.h>
#include <Servo.h>
  
Servo servo;

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

//unsigned long ONE = OxFF30CF;
//unsigned long TWO = OxF7906F;

String type = "";

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  servo.attach(7);
  servo.write(0);
    Serial.println("starting");

}

void loop()
{
  checkInput();
  if(type == "one") {
    Serial.println("in one");
    servo.write(90);
    delay(100);
    servo.write(0);
    delay(100);
  } else if(type == "two") {
        Serial.println("in two");

    servo.write(20);
    delay(500);
    servo.write(0);
    delay(500);
  } else {
    servo.write(45);
    delay(500);
//    servo.write(90);
//    delay(100);
     servo.write(0);
    delay(100);
  
  }
}

void checkInput() {
    if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     Serial.println(results.value);

     switch(results.value) {
      case 16191727 :
      type = "one";
      Serial.println("Setting one");
      break;
      case 16224367:
      type = "two";
      Serial.println("Setting two");
      break;
      default:
      type="";
     }
     
     irrecv.resume(); // Receive the next value
    }
}
