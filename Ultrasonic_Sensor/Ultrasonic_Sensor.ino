const int pingPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
const int buzzerpin = 13; // Echo Pin of Ultrasonic Sensor

void setup() {
    pinMode(buzzerpin, OUTPUT);
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
    digitalWrite(buzzerpin, LOW);

   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
//   digitalWrite(buzzerpin, HIGH);
   if(cm<15){
      digitalWrite(buzzerpin, HIGH);
   }
   if(cm>15 && cm<30){
       digitalWrite(buzzerpin, HIGH);
       delay(300);
       digitalWrite(buzzerpin, LOW);
    }

   if(cm>30 && cm<45){
       digitalWrite(buzzerpin, HIGH);
       delay(600);
       digitalWrite(buzzerpin, LOW);
    }
   Serial.println();
   delay(200);

}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
