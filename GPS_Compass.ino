void getGPS()                                                 // Get Latest GPS coordinates
{
   while (gps.available( gpsPort )) {
   if (fix.valid.location) {fix = gps.read();}
   }
} 

// *************************************************************************************************************************************************
 
void setWaypoint()                                           
{

//if ((wpCount >= 0) && (wpCount < 50))
if (wpCount >= 0)                                            
  {
    Serial.print("GPS Waypoint ");
    Serial.print(wpCount + 1);
    Serial.print(" Set ");
    getGPS();                                                 
    getCompass();                                              
                                               
    Latarray[ac] = fix.latitude();                     
    Lonarray[ac] = fix.longitude();                    
                                                              
    Serial.print("Waypoint #1: ");
    Serial.print(Latarray[0],6);
    Serial.print(" ");
    Serial.println(Lonarray[0],6);
    Serial.print("Waypoint #2: ");
    Serial.print(Latarray[1],6);
    Serial.print(" ");
    Serial.println(Lonarray[1],6);
    Serial.print("Waypoint #3: ");
    Serial.print(Latarray[2],6);
    Serial.print(" ");
    Serial.println(Lonarray[2],6);
    Serial.print("Waypoint #4: ");
    Serial.print(Latarray[3],6);
    Serial.print(" ");
    Serial.println(Lonarray[3],6);
    Serial.print("Waypoint #5: ");
    Serial.print(Latarray[4],6);
    Serial.print(" ");
    Serial.println(Lonarray[4],6);

    wpCount++;                                                  // increment waypoint counter
    ac++;                                                       // increment array counter
        
  }         
  else {Serial.print("Waypoints Full");}
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
