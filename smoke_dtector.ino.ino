int smokeSensor = A0;
int buzzer = 9;
int threshold = 400; // Adjust as per testing

void setup() {
  pinMode(smokeSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);  // HC-05 communication
}

void loop() {
  int smokeLevel = analogRead(smokeSensor);
  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  if (smokeLevel > threshold) {
    digitalWrite(buzzer, HIGH);
    Serial.println("ALERT: Smoke Detected!");
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(1000);
}
