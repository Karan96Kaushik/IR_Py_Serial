#include <IRremote.h>
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;
String type;
long int data, bits;

void setup()
{
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  
  if (irrecv.decode(&results)) {
    dump(&results);
    Serial.print(results.value, DEC);
    Serial.print("$");
    Serial.print(results.bits, DEC);
    Serial.println("%");
    irrecv.resume(); // Receive the next value
  }

  if (Serial.available() > 0) {
    Serial.print("Data=");
    type = Serial.readStringUntil(':');
    Serial.println(type);
    data = Serial.parseInt();
    Serial.println(data);
    bits = Serial.parseInt();
    Serial.println(bits);
    Serial.read();
    Serial.read();
    Serial.read();
    Serial.read();
    Serial.read();
    
    if (type == "PANASONIC") {
    } else if (type == "SONY") {
    } else if (type == "NEC") {
      irsend.sendNEC(data, bits);
    } else if (type == "RC5") {
    } else if (type == "RC6") {
    }

    irrecv.enableIRIn();
    
    delay(50);
  }
  delay(10);
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