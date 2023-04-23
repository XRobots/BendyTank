float stick1;
float stick2;
float stick1Filtered;
float stick2Filtered;

void setup() {

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(115200);

}

void loop() {

  stick1 = analogRead(A0);
  stick2 = analogRead(A1);

  stick1 = thresholdStick(stick1);
  stick2 = thresholdStick(stick2);

  stick1Filtered = filter(stick1, stick1Filtered, 15);
  stick2Filtered = filter(stick2, stick2Filtered, 15);

  Serial.print(stick1Filtered);
  Serial.print(",");
  Serial.print(stick2Filtered);
  Serial.println();

  // drive motor

  if (stick1Filtered > 0) {
    analogWrite(3, stick1Filtered);
    analogWrite(5, 0);    
  }
  else if (stick1Filtered < 0) {
    float stick1Filtereda;
    stick1Filtereda = abs(stick1Filtered);
    analogWrite(5, stick1Filtereda);
    analogWrite(3, 0);    
  }
  else {
    analogWrite(5, 0);
    analogWrite(3, 0);
  }

  //steering

  if (stick2Filtered > 0) {
    analogWrite(9, stick2Filtered);
    analogWrite(6, 0);    
  }
  else if (stick2Filtered < 0) {
    float stick2Filtereda;
    stick2Filtereda = abs(stick2Filtered);
    analogWrite(6, stick2Filtereda);
    analogWrite(9, 0);    
  }
  else {
    analogWrite(6, 0);
    analogWrite(9, 0);
  }

  delay(10);
  


}
