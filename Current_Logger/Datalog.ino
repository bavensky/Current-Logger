void main_name() {
  myFile = SD.open(OUTPUT_FILE, FILE_WRITE);
  if (myFile)
  {
    myFile.print("Date");
    myFile.print(",");
    myFile.print("Time");
    myFile.print(",");
    myFile.print("U (A-RMS)");
    myFile.print(",");
    myFile.print("V (A-RMS)");
    myFile.print(",");
    myFile.print("W (A-RMS)");
    myFile.print(",");
    myFile.print("Power U (kW)");
    myFile.print(",");
    myFile.print("Power V (kW)");
    myFile.print(",");
    myFile.println("Power W (kW)");
    delay(TIME);
    myFile.close();
  }
}

void writing(float line1, float line2, float line3)  {
  now_datetime();
  myFile = SD.open(OUTPUT_FILE, FILE_WRITE);
  if (myFile)
  {
    myFile.print(_monthDay);
    myFile.print("/");
    myFile.print(_month);
    myFile.print("/");
    myFile.print(_year);
    myFile.print(",");
    myFile.print(_hour);
    myFile.print(":");
    myFile.print(_minute);
    myFile.print(":");
    myFile.print(_second);
    myFile.print(",");
    if (line1 >= 601) line1 = 0;
    myFile.print(line1);
    myFile.print(",");
    if (line2 >= 601) line2 = 0;
    myFile.print(line2);
    myFile.print(",");
    if (line3 >= 601) line3 = 0;
    myFile.print(line3);
    myFile.print(",");
    myFile.print(power_U = 0.22f * line1);
    myFile.print(",");
    myFile.print(power_V = 0.22f * line2);
    myFile.print(",");
    myFile.println(power_W = 0.22f * line3);
    delay(TIME);
    myFile.close();
  }
}
