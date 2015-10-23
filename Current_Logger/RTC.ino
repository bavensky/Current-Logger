byte decToBcd(byte val)
{
  // Convert normal decimal numbers to binary coded decimal
  return ( (val / 10 * 16) + (val % 10) );
}

byte bcdToDec(byte val)
{
  // Convert binary coded decimal to normal decimal numbers
  return ( (val / 16 * 10) + (val % 16) );
}

/****** Set Date Time ***********************************/
void setDateTime(byte _second, byte _minute, byte _hour, byte _monthDay, byte _month, byte _year)
{
  /*******  Config to time *****************************/
  byte set_second =   _second;    // Set Second 0-59
  byte set_minute =   _minute;   // Set Minute 0-59
  byte set_hour   =   _hour;    // Set Hour   0-23
  byte set_monthDay =   _monthDay;   // Set Day of Month 1-31
  byte set_month    =   _month;   // Set Month  1-12
  byte set_year     =   _year;   // Set Year   0-99
  byte set_weekDay =     1;    // Set Day of Week  1-7

  //  byte set_weekDay =     2;    // Set Day of Week  1-7
  byte control  =    0b10010011;
  byte  d1;
  byte  d2;

  // Write to address ds1307
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);  //stop Oscillator

  Wire.write(decToBcd(set_second));
  Wire.write(decToBcd(set_minute));
  Wire.write(decToBcd(set_hour));
  Wire.write(decToBcd(set_weekDay));
  Wire.write(decToBcd(set_monthDay));
  Wire.write(decToBcd(set_month));
  Wire.write(decToBcd(set_year));

  Wire.write(control);
  Wire.write(zero);  //start
  Wire.endTransmission();

}

void now_datetime()
{
  //  Read from address ds1307
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 10);
  _second = bcdToDec(Wire.read());
  _minute = bcdToDec(Wire.read());
  _hour = bcdToDec(Wire.read() & 0b111111); // 24 hour time
  _weekDay = bcdToDec(Wire.read());         // 1-7 ->Sunday - Saturday
  _monthDay = bcdToDec(Wire.read());
  _month = bcdToDec(Wire.read());
  _year = bcdToDec(Wire.read());
  control = Wire.read();
}

