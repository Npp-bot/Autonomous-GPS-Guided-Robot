void goWaypoint()
{
  while (true)
  {                         
    getCompass();                                                    
    getGPS();
    double lat = fix.latitude();
    double lng = fix.longitude();
    double lat_dest = Latarray[ac];
    double lng_dest = Lonarray[ac];
    //************************************************                                                        
    Location_t p1(lat, lng);                                //Code piece to assign the inputs for the BearingTo function
    Location_t p2(lat_dest, lng_dest);                    
    float bearing = BearingTo(p1,p2);
    //*************************************************
    double x = abs(lat - lat_dest);                         //Pythagorean theorem is used to calculate the distance between current
    double y = abs(lng - lng_dest);                         // location and the next waypoint.
    double distance=sqrt( pow(x,2)+ pow(y,2));
    //*************************************************
      
    Serial.print("distance :");                               //************DEBUG
    Serial.println(distance);

    Serial.print("bearing :");
    Serial.println(bearing);

    Serial.print("compassg :");
    Serial.println(compass_heading);


    if (distance == 0)                                           // If the Vehicle has reached it's Destination, then Stop
    {
      StopCar();                                               
      Serial.println("You have arrived!");                    
      ac++;                                                    // increment counter for next waypoint
      break;                                                   // Go back to the Void Loop
      // go to next waypoint
    }

    if ( abs(bearing - compass_heading) <= 15)                        
    {
      Forward();                                              
    } else
    {
      int x = (bearing - 360);                              // This code piece calculates the shortest way to get to desired bearing
      int y = (compass_heading - (x));                       
      int z = (y - 360);                                     

      if ((z <= 180) && (z >= 0))                            
      {
        LeftTurn();
      }
      else {
        RightTurn();
      }
    }
  }                                                              
}                                                               
