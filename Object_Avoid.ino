void Ping()
{ 

Ping_distance1 = us1.dist(); // sol ön
Ping_distance2 = us2.dist(); // orta ön
Ping_distance3 = us3.dist(); // sag ön
Ping_distance4 = us4.dist(); // sol arka
Ping_distance5 = us5.dist(); // sag arka

 
    if (Ping_distance1 <= 20 || Ping_distance2 <= 20 || Ping_distance3 <= 20)
      {
        Reverse();                                        // Quick reverse to Stop quickly
        delay(100);
        StopCar();
        avoid();
      } 
  }

void avoid()
{
  while(true){
    if(Ping_distance4 < Ping_distance5){
      CompassTurnRight();
      Forward_Meter();
      break;
      }
    else if(Ping_distance4 > Ping_distance5){
      CompassTurnLeft();
      Forward_Meter();
      break;
      }
      else{
      CompassTurnLeft();
      Forward_Meter();
      break;
        }
    }
  }
