//**************************************************************************************************************************************************
// This procedure reads the serial port - Serial1 - for bluetooth commands being sent from the Android device

void bluetooth()
{
 while (Serial2.available())
  {
    veri = Serial2.readStringUntil('\n');

    v1 = veri.indexOf('v');
    pp1 = veri.substring(0, v1);
    v2 = veri.indexOf('v', v1 + 1 );
    pp2 = veri.substring(v1 + 1, v2);
    v3 = veri.indexOf('v', v2 + 1 );
    pp3 = veri.substring(v2 + 1, v3);
    v4 = veri.indexOf('v', v3 + 1 );
    pp4 = veri.substring(v3 + 1, v4);
    v5 = veri.indexOf('v', v4 + 1 );
    pp5 = veri.substring(v4 + 1, v5);

    pp1.remove(0, 3); pp1.remove(8, 3);
    pp2.remove(0, 3); pp2.remove(8, 3);
    pp3.remove(0, 3); pp3.remove(8, 3);
    pp4.remove(0, 3); pp4.remove(8, 3);
    pp5.remove(0, 3); pp5.remove(8, 3);

    v = 7;

    noktalar[0].x = pp1.substring(0, v).toInt();
    noktalar[0].y = pp1.substring(v + 1).toInt();
    noktalar[1].x = pp2.substring(0, v).toInt();
    noktalar[1].y = pp2.substring(v + 1).toInt();
    noktalar[2].x = pp3.substring(0, v).toInt();
    noktalar[2].y = pp3.substring(v + 1).toInt();
    noktalar[3].x = pp4.substring(0, v).toInt();
    noktalar[3].y = pp4.substring(v + 1).toInt();
    noktalar[4].x = pp5.substring(0, v).toInt();
    noktalar[4].y = pp5.substring(v + 1).toInt();
    
//    Serial.println(noktalar[0].x, 7);
//    Serial.println(noktalar[0].y, 7);
//    Serial.println(noktalar[1].x, 7);
//    Serial.println(noktalar[1].y, 7);
//    Serial.println(noktalar[2].x, 7);
//    Serial.println(noktalar[2].y, 7);
//    Serial.println(noktalar[3].x, 7);
//    Serial.println(noktalar[3].y, 7);
//    Serial.println(noktalar[4].x, 7);
//    Serial.println(noktalar[4].y, 7);
//    Serial.println(veri);
  }   

// **************************************************************************************************************************************************
/*
 switch (blueToothVal) 
 {
      case 1:                                
        Serial1.println("Forward");
        Forward();
        break;

      case 2:                 
        Serial1.println("Reverse");
        Reverse();
        break;

      case 3:         
        Serial1.println("Left");
        LeftTurn();
        StopCar();
        break;
        
      case 4:                     
        Serial1.println("Right");
        RightTurn();
        StopCar();
        break;
        
      case 5:                                            
        Serial1.println("Stop Car ");
        StopCar();
        break; 

      case 6:                 
        setWaypoint();
        break;
      
      case 7:        
        goWaypoint();
        break;  
      
      case 8:        
        Serial1.println("Turn Around");
        turnAround();
        break;
      
      case 9:        
         Serial1.println("Compass Forward");
        setHeading();
        Compass_Forward();
        break;
      
      case 10:
        setHeading();
        break; 

      case 11:
         gpsInfo();
        break;
      
      case 12:  
        Serial1.println("Compass Turn Right");
        CompassTurnRight();
        break;
      
      case 13:  
        Serial1.println("Compass Turn Left");
        CompassTurnLeft();
        break;
        
      case 14:  
        Serial1.println("Calibrate Compass");
        calibrateCompass();
        break;

      case 15:  
        pingToggle();
        break;  

      case 16:
        clearWaypoints();
        break;  

      case 17:                    // finish with waypoints
        ac = 0;
        Serial1.print("Waypoints Complete");
        break;
      

 } // end of switch case
*/
// **************************************************************************************************************************************************   

 }                                                              // end of while loop Serial1 read
 
                                                               // if no data from Bluetooth 
   if (Serial2.available() < 0)                                 // if an error occurs, confirm that the arduino mega board is selected in the Tools Menu
    {
     Serial.println("No Bluetooth Data ");          
    }
  
} // end of bluetooth procedure
