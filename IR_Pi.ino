#include <IRremote.h>
int RECV_PIN = 11; 

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;
String data, type; 


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print(results.value, HEX);
    Serial.print("#");
    //Serial.println("$");
    dump(&results);
    Serial.println("$");
    irrecv.resume(); // Receive the next value
  }

  if (Serial.available() > 0) {
  	type = Serial.readStringUntil(':');
  	Serial.println(type);
  	data = Serial.readStringUntil('$');
    Serial.println(data);
    
    if (type == "PANASONIC") {
    } else if (type == "SONY") {
    } else if (type == "NEC") {
    } else if (type == "RC5") {
    } else if (type == "RC6") {
    }
  }
}








void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown:");
  }
  else if (results->decode_type == NEC) {
    Serial.print("NEC:");

  }
  else if (results->decode_type == SONY) {
    Serial.print("SONY:");
  }
  else if (results->decode_type == RC5) {
    Serial.print("RC5:");
  }
  else if (results->decode_type == RC6) {
    Serial.print("RC6:");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("PANASONIC-");
    Serial.print(results->address, HEX);
    Serial.print(":");
  }
  else if (results->decode_type == LG) {
    Serial.print("LG:");
  }
  else if (results->decode_type == JVC) {
    Serial.print("JVC:");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("AIWA RC T501:");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Whynter:");
  }
}
