/************       Read_ARMS       *************/
void Read_ARMS()
{
  int line1_a = 0;
  int line2_a = 0;
  int line3_a = 0;

  int line1_b = 1;
  int line2_b = 1;
  int line3_b = 1;

  uint8_t loop = 6;
  uint8_t reading_ok = 0;

  while (loop > 0 && reading_ok == 0)
  {
    loop --;

    if (line1_a != line1_b)
    {
      Wire.requestFrom(5, 2);
      delay(2);
      line1_a = Wire.read() << 8 | Wire.read();
      delay(10);
      Wire.requestFrom(5, 2);
      delay(2);
      line1_b = Wire.read() << 8 | Wire.read();
      delay(2);
    }

    if (line2_a != line2_b)
    {
      Wire.requestFrom(1, 2);
      delay(2);
      line2_a = Wire.read() << 8 | Wire.read();
      delay(10);
      Wire.requestFrom(1, 2);
      delay(2);
      line2_b = Wire.read() << 8 | Wire.read();
      delay(2);
    }

    if (line3_a != line3_b)
    {
      Wire.requestFrom(2, 2);
      delay(2);
      line3_a = Wire.read() << 8 | Wire.read();
      delay(10);
      Wire.requestFrom(2, 2);
      delay(2);
      line3_b = Wire.read() << 8 | Wire.read();
      delay(2);
    }

    if ((line2_a == line2_b) && (line2_a == line2_b) && ((line2_a == line2_b)))
    {
      reading_ok = 1;
      line1 = line1_a;
      line2 = line2_a;
      line3 = line3_a;
    }

  }
  Serial.print(line1);
  Serial.print(" ");
  Serial.print(line2);
  Serial.print(" ");
  Serial.println(line3);

}

void debug() {
  lcd.setCursor(0, 1);
  lcd.print("Calibration....");
  
  digitalWrite(CLAMP, HIGH);
  delay(5000);
  digitalWrite(CLAMP, LOW);
  delay(5000);
  digitalWrite(CLAMP, HIGH);
  delay(5000);
  lcd.clear();
}

///************       Read_ARMS       *************/
//void Read_ARMS()  {
//  Wire.requestFrom(5, 2);
//  delay(10);
//  line1 = Wire.read() << 8 | Wire.read();
//
//  Wire.requestFrom(1, 2);
//  delay(10);
//  line2 = Wire.read() << 8 | Wire.read();
//
//  Wire.requestFrom(2, 2);
//  delay(10);
//  line3 = Wire.read() << 8 | Wire.read();
//
//}
//
//void debug() {
//  digitalWrite(CLAMP, HIGH);
//  delay(5000);
//  digitalWrite(CLAMP, LOW);
//  delay(5000);
//  digitalWrite(CLAMP, HIGH);
//  delay(5000);
//}

