
void Startup()
{        
  for (int i=3; i >= 1; i--)                       // Count down for X seconds
  {         
    Serial.print("Pause for Startup... ");       //****USED FOR DEBUG DELETE LATER(talking about serial.print here)
    Serial.print(i);
    delay(500);                                   
  }    
   while (compass_counter<250)
  {
    compass_counter=compass_counter+1;
    compass_heading = compass.readHeading();
    Serial.println("Compass is still calibrating...");
  }
  if(compass_heading!=0){Serial.println("Calibration Complete ");}  
                
  setWaypoint();                                      // set intial waypoint to current location
  wpCount = 0;                                        // zero waypoint counter
  ac = 0;                                             // zero array counter
  
     
}    
 

  
    
  



   
 
  
