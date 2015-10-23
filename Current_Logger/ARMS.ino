/************       Read_ARMS       *************/
void Read_ARMS()  {
  Wire.requestFrom(5, 2);
  delay(10);
  line1 = Wire.read() << 8 | Wire.read();

  Wire.requestFrom(1, 2);
  delay(10);
  line2 = Wire.read() << 8 | Wire.read();

  Wire.requestFrom(2, 2);
  delay(10);
  line3 = Wire.read() << 8 | Wire.read();

}

void debug() {
  digitalWrite(CLAMP, HIGH);
  delay(5000);
  digitalWrite(CLAMP, LOW);
  delay(5000);
  digitalWrite(CLAMP, HIGH);
  delay(5000);
}

