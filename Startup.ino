
void Startup()
{
  for (int i = 5; i >= 1; i--)                     // Count down for X seconds
  {
    Serial.print("Pause for Startup... ");       //****USED FOR DEBUG DELETE LATER(talking about serial.print here)
    Serial.print(i);
    delay(1000);
  }
  while (heading == 0)
  {
    heading = compass.readHeading();
    Serial.println("Compass is still calibrating...");
  }
  if (heading == 0) {
    Serial.println("Calibration Complete ");
  }

  Serial.println("Searching for Satellites ");

  while (Number_of_SATS <= 4)                        // Wait until x number of satellites are acquired before starting main loop******************DURUMA GÖRE 3 SAT KULLLAN
  {
    getGPS();                                         // Update gps data
    Number_of_SATS = fix.satellites;                  // Check the number of Satellites Acquired
  }


  setWaypoint();                                      // set intial waypoint to current location
  wpCount = 0;                                        // zero waypoint counter
  ac = 0;                                             // zero array counter


  Pointing();
  
  int inc = 0;
  for (inc = 0; inc < N + 1; inc++) {
    InsidePolygon(*noktalar, N, kare[inc], inc);
  }

  Serial.print(Number_of_SATS);
  Serial.print(" Satellites Acquired");
}
