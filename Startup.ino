
void Startup()
{        
  for (int i=5; i >= 1; i--)                       // Count down for X seconds
  {         
    Serial.print("Pause for Startup... ");       //****USED FOR DEBUG DELETE LATER(talking about serial.print here)
    Serial.print(i);
    delay(1000);                                   
  }    
   while (heading==0)
  {
   heading = compass.readHeading();
   Serial.println("Compass is still calibrating...");
  }
  if(heading==0){Serial.println("Calibration Complete ");}
  
  Serial.println("Searching for Satellites ");
      
  while (Number_of_SATS <= 4)                         // Wait until x number of satellites are acquired before starting main loop
  {                                  
   getGPS();                                         // Update gps data
   Number_of_SATS = fix.satellites;               // Check the number of Satellites Acquired       
   bluetooth();                                      // Check to see if there are any bluetooth commands being received     
  }
  
        
  setWaypoint();                                      // set intial waypoint to current location
  wpCount = 0;                                        // zero waypoint counter
  ac = 0;                                             // zero array counter
  
  Serial.print(Number_of_SATS);
  Serial.print(" Satellites Acquired");    
}    
 

  
    
  



   
 
  
