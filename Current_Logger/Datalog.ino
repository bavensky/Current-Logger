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
    myFile.println("W (A-RMS)");
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
    myFile.print(line1);
    myFile.print(",");
    myFile.print(line2);
    myFile.print(",");
    myFile.println(line3);
    delay(TIME);
    myFile.close();
  }
}
