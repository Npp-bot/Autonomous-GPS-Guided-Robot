#include "Wire.h"                                                
#include <QMC5883L.h>                                          
#include <NMEAGPS.h>
#include <GPSport.h>
                      
//******************************************************************************************************  
// GPS Locations
int ac =0;                                                         // GPS array counter
int wpCount = 0;                                                   // GPS waypoint counter
double Home_LATarray[50];                                          // variable for storing the destination Latitude - Only Programmed for 50 waypoint
double Home_LONarray[50];                                          // variable for storing the destination Longitude - up to 50 waypoints


int increment = 0;
//******************************************************************************************************                                                                  
// GPS Variables & Setup

double lat,lon;
int Number_of_SATS;                                                // variable to hold the number of satellites acquired
float bearing;
float distance;
NMEAGPS  gps;
gps_fix  fix;                                                      // gps = instance of NEOGPS
NeoGPS::Location_t to_waypoint(Home_LATarray[ac], Home_LONarray[ac]); 
                                                                   // pin 18 is connected to the TX on the GPS
                                                                   // pin 19 is connected to the RX on the GPS

//******************************************************************************************************
// Motor Setup 
int M1_Forward = 2;       // Left-side Motors
int M1_Backward = 3;      // Left-side Motors
int M2_Forward = 4;       // Right-side Motors
int M2_Backward = 5;      // Right-side Motors


int turn_pwm = 125;                                              // motor pwm for turns 
int set_pwm = 200;                                               // motor pwm when moving forward and reverse

//******************************************************************************************************
// Compass Variables & Setup

QMC5883L compass;                                                  // QMC5883L compass
int compass_heading;
int desired_heading;                                               // initialize variable - stores value for the new desired heading                                             
int compass_dev = 5;                                               // the amount of deviation that is allowed in the compass heading - Adjust as Needed
int heading = 0;                                                   // setting this variable too low will cause the robot to continuously pivot left and right*****************************
                                                                   // setting this variable too high will cause the robot to veer off course

//******************************************************************************************************
// Ping Sensor for Collision Avoidance  ***************BURAYA SONRA BAKILACAK

boolean pingOn = false;                                            // Turn Collision detection On or Off

int trigPin = 43;                                                  // Trig - Orange
int echoPin = 42;                                                  // Echo - Yellow
long duration, inches;
int Ping_distance;

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;                                  // Store last time Ping was updated
const long interval = 200;                                         // Ping the Distance every X miliseconds
 
//******************************************************************************************************
// Bluetooth Variables & Setup    *********************GRUPLA İLETİŞİMİ KONUŞUP BURAYA ÖYLE BAK, NOKTALARI GÖNDERİRKEN BLUE. KULLANILMAYACAKSA SİL

String str;                                                        // raw string received from android to arduino
int blueToothVal;                                                  // stores the last value sent over via bluetooth
int bt_Pin = 34;                                                   // Pin 34 of the Aruino Mega used to test the Bluetooth connection status - Not Used

//*****************************************************************************************************


void setup() 
{  
  Serial.begin(9600);                                           
  gpsPort.begin(9600);
  
  while (!Serial)
    ;
  

  // Ping Sensor
  //pinMode(trigPin, OUTPUT);                                        // Ping Sensor
  //pinMode(echoPin, INPUT);                                         // Ping Sensor

  // Compass
  Wire.begin();

  compass.init();
  compass.setSamplingRate(50);
  compass.setOversampling(256);
  compass.setRange(8);

  Startup();                                                       // Run the Startup procedure on power-up one time

  //*****************************
  Home_LATarray[1]=40692902;
  Home_LONarray[1]=29833365;
  Home_LATarray[2]=40692675;
  Home_LONarray[2]=29833243;
  //*****************************
}

//********************************************************************************************************
// Main Loop

void loop()
{ 
  
  //bluetooth();                                                     // Run the Bluetooth procedure to see if there is any data being sent via BT                                                    
  getGPS();                                                        // Update the GPS location
  getCompass();                                                    // Update the Compass Heading
  //Ping();                                                        //*************************************** Collision Detection will have something to do with this. check later
  goWaypoint();
}
