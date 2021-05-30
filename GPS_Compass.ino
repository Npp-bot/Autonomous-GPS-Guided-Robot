void getGPS()                                                 // Get Latest GPS coordinates
{
   while (gps.available( gpsPort )) {
   if (fix.valid.location) {fix = gps.read();}
   }
} 

// *************************************************************************************************************************************************
 
void setWaypoint()                                            // Set up to 5 GPS waypoints
{

//if ((wpCount >= 0) && (wpCount < 50))
if (wpCount >= 0)                                            //Set the current location as a waypoint at the start. probably used to determine how to get to the real first waypoint
  {
    Serial.print("GPS Waypoint ");
    Serial.print(wpCount + 1);
    Serial.print(" Set ");
    getGPS();                                                 // get the latest GPS coordinates
    getCompass();                                             // update latest compass heading     
                                               
    Home_LATarray[ac] = fix.latitude();                   // store waypoint in an array   
    Home_LONarray[ac] = fix.longitude();                   // store waypoint in an array   
                                                              
    Serial.print("Waypoint #1: ");
    Serial.print(Home_LATarray[0],6);
    Serial.print(" ");
    Serial.println(Home_LONarray[0],6);
    Serial.print("Waypoint #2: ");
    Serial.print(Home_LATarray[1],6);
    Serial.print(" ");
    Serial.println(Home_LONarray[1],6);
    Serial.print("Waypoint #3: ");
    Serial.print(Home_LATarray[2],6);
    Serial.print(" ");
    Serial.println(Home_LONarray[2],6);
    Serial.print("Waypoint #4: ");
    Serial.print(Home_LATarray[3],6);
    Serial.print(" ");
    Serial.println(Home_LONarray[3],6);
    Serial.print("Waypoint #5: ");
    Serial.print(Home_LATarray[4],6);
    Serial.print(" ");
    Serial.println(Home_LONarray[4],6);

    wpCount++;                                                  // increment waypoint counter
    ac++;                                                       // increment array counter
        
  }         
  else {Serial.print("Waypoints Full");}
}

// ************************************************************************************************************************************************* 

void clearWaypoints()
{
   memset(Home_LATarray, 0, sizeof(Home_LATarray));             // clear the array
   memset(Home_LONarray, 0, sizeof(Home_LONarray));             // clear the array
   wpCount = 0;                                                 // reset increment counter to 0
   ac = 0;
   
   Serial.print("GPS Waypoints Cleared");                      // display waypoints cleared
  
}

 // *************************************************************************************************************************************************
 
void getCompass()                                               // get latest compass value
{    
     
    for (int i=0; i <= 5; i++)                                    // Take several readings from the compass to insure accuracy
      { 
        compass_heading += compass.readHeading();                                          
      }
     compass_heading = compass_heading/6;        //******6ya kadar saymıyorsa 5e böl. şuan c'yi unuttum
//     Serial.println("heading :");
//     Serial.print(compass_heading);                                                                                                
}
