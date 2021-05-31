void getGPS()                                                 // Get Latest GPS coordinates
{
   while (gps.available( gpsPort )) {
   if (fix.valid.location) {fix = gps.read();}
   }
}  
void getCompass()                                               // get latest compass value
{    
     
    for (int i=0; i <= 5; i++)                                    // Take several readings from the compass to insure accuracy
      { 
        compass_heading += compass.readHeading();                                          
      }
     compass_heading = compass_heading/6;        
//     Serial.println("heading :");
//     Serial.print(compass_heading);                                                                                                
}
