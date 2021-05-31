
void Forward()
{
  //Ping(); 
  analogWrite(M1_Backward, 0);
  analogWrite(M2_Backward, 0);
  delay(1);
  analogWrite(M1_Forward, set_pwm);
  analogWrite(M2_Forward, set_pwm);
}

// **********************************************************************************************************************************************************************

void Forward_Meter() 
{
  analogWrite(M1_Backward, 0);
  analogWrite(M2_Backward, 0);
  delay(1);
  analogWrite(M1_Forward, set_pwm);
  analogWrite(M2_Forward, set_pwm);
  delay(3000);
  Reverse();
  StopCar();
 
}

// **********************************************************************************************************************************************************************

void Reverse()
{
  analogWrite(M1_Forward, 0);
  analogWrite(M2_Forward, 0);
  delay(1);
  analogWrite(M1_Backward, set_pwm);
  analogWrite(M2_Backward, set_pwm);
}

// **********************************************************************************************************************************************************************

void LeftTurn()
{
  analogWrite(M1_Forward, 0);
  analogWrite(M2_Backward, 0);
  delay(1);
  analogWrite(M1_Backward, turn_pwm);
  analogWrite(M2_Forward, turn_pwm);
}

// **********************************************************************************************************************************************************************

void RightTurn()
{
  analogWrite(M1_Backward, 0);
  analogWrite(M2_Forward, 0);
  delay(1);
  analogWrite(M1_Forward, turn_pwm);            
  analogWrite(M2_Backward, turn_pwm);                                   
}

// **********************************************************************************************************************************************************************

void StopCar()
{ 
  analogWrite(M1_Backward, 0);
  analogWrite(M2_Backward, 0);
  delay(1);
  analogWrite(M1_Forward, 0);
  analogWrite(M2_Forward, 0);
}

// **********************************************************************************************************************************************************************
void CompassTurnRight()                                                          // This Function Turns the car 90 degrees to the right based on the current desired heading
{
  StopCar();    
  getCompass();                                                                  // get current compass heading      

  desired_heading = (compass_heading + 90);                                      // set desired_heading to plus 90 degrees ********************Buarada compass+90 kısmındaki compass aslında desired'tı. Yanlış gördüğüm için değiştirildi. Porblem çıkarsa geri al
  if (desired_heading >= 360) {desired_heading = (desired_heading - 360);}       // if the desired heading is greater than 360 then subtract 360 from it

  while ( abs(desired_heading - compass_heading) >= compass_dev)                 // If the desired heading is more than Compass Deviation in degrees from the actual compass heading then
      {                                                                          // correct direction by turning left or right

    getCompass();                                                                // Update compass heading during While Loop
   
        
    if (desired_heading >= 360) {desired_heading = (desired_heading - 360);}     // if the desired heading is greater than 360 then subtract 360 from it                                            
                                                                
    int x = (desired_heading - 359);                                             // x = the GPS desired heading - 360    
    int y = (compass_heading - (x));                                             // y = the Compass heading - x
    int z = (y - 360);                                                           // z = y - 360
            
        if ((z <= 180) && (z >= 0))                                              // if z is less than 180 and not a negative value then turn left 
            {                                                                    // otherwise turn right
              LeftTurn();                            
            } 
            else
            {
              RightTurn();        
            }  
        }    
    {
      StopCar();                                                                  // Stop the Car when desired heading and compass heading match
    }
 }    


// **********************************************************************************************************************************************************************

void CompassTurnLeft()                                                           // This procedure turns the car 90 degrees to the left based on the current desired heading
{
  StopCar();    
  getCompass();                                                                  // get current compass heading                                                                                  
  //desired_heading = (compass_heading - 90);                                    // set desired_heading to compass value minus 90 degrees

  desired_heading = (compass_heading - 90);                                      // set desired_heading to minus 90 degrees
  if (desired_heading <= 0) {desired_heading = (desired_heading + 360);}         // if the desired heading is greater than 360 then add 360 to it
  while ( abs(desired_heading - compass_heading) >= compass_dev)                 // If the desired heading is more than Compass Deviation in degrees from the actual compass heading then
      {                                                                          // correct direction by turning left or right
    getCompass();                                                                // Get compass heading again during While Loop
    
    if (desired_heading >= 360) {desired_heading = (desired_heading - 360);}     // if the desired heading is greater than 360 then subtract 360 from it                                            
                                                                
    int x = (desired_heading - 359);                                             // x = the desired heading - 360    
    int y = (compass_heading - (x));                                             // y = the Compass heading - x
    int z = (y - 360);                                                           // z = y - 360
        if (z <= 180)                                                            // if z is less than 180 and not a negative value then turn left         
       // if ((z <= 180) && (z >= 0))                                             
            {                                                                    // otherwise turn right
              LeftTurn();                             
            } 
            else
            {
              RightTurn();              
            }  
        }    
    {
      StopCar();                                                                 // Stop the Car when desired heading and compass heading match
    }
 }   
