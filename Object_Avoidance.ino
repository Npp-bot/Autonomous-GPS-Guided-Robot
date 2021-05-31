#include <HCSR04.h>
HCSR04 hc(5,6);
long duration, inches;
int Ping_distance;

boolean pingOn = false;                                            // Turn Collision detection On or Off

void Ping()
{

    Ping_distance = hc.dist();
  }

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  Ping();
  Serial.println(Ping_distance);

}
