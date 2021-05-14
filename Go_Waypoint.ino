
void goWaypoint()
{   
 Serial.println("Go to Waypoint");
//Serial.print("Home_Latarray ");
//Serial.print(Home_LATarray[ac],6);
//Serial.print(" ");
//Serial.println(Home_LONarray[ac],6);   

//Serial1.print("Distance to Home");   
//Serial1.print(Distance_To_Home);

//Serial1.print("ac= ");
//Serial1.print(ac);

 while (true)  
  {                                                                // Start of Go_Home procedure 
  //bluetooth();                                                     // Run the Bluetooth procedure to see if there is any data being sent via BT
  //if (blueToothVal == 5){break;}                                   // If a 'Stop' Bluetooth command is received then break from the Loop
  getCompass();                                                    // Update Compass heading                                          
  getGPS();                                                        // Function to retrieves GPS data 
  
 
  
      distance = fix.location.DistanceKm(to_waypoint)*1000;
      bearing = fix.location.BearingToDegrees(to_waypoint);   
   
    if (distance == 0)                                           // If the Vehicle has reached it's Destination, then Stop
        {
        StopCar();                                               // Stop the robot after each waypoint is reached
        Serial.println("You have arrived!");                     // Print to Bluetooth device - "You have arrived"          
        ac++;                                                    // increment counter for next waypoint
        break;                                                   // Break from Go_Home procedure and send control back to the Void Loop 
                                                                 // go to next waypoint
        }   
   
   
   if ( abs(bearing - compass_heading) <= 15)                  // If GPS Course and the Compass Heading are within x degrees of each other then go Forward                                                                  
                                                                  // otherwise find the shortest turn radius and turn left or right  
       {
         Forward();                                               // Go Forward
       } else 
         {                                                       
            int x = (bearing - 360);                           // x = the GPS desired heading - 360
            int y = (compass_heading - (x));                      // y = the Compass heading - x
            int z = (y - 360);                                    // z = y - 360
            
            if ((z <= 180) && (z >= 0))                           // if z is less than 180 and not a negative value then turn left otherwise turn right
                  { LeftTurn();  }
             else { RightTurn(); }               
        } 
    

  }                                                              // End of While Loop

  
}                                                                // End of Go_Home procedure
