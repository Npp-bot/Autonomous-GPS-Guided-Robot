#include "Wire.h"                                                
#include <QMC5883L.h>                                          
#include <NMEAGPS.h>
using namespace NeoGPS;
#include <GPSport.h>
//******************************************************************************************************
#define MIN(x,y) (x < y ? x : y)   //max min functions
#define MAX(x,y) (x > y ? x : y)

typedef struct {
  double x, y;
} Point;                      
//******************************************************************************************************  
// GPS Locations                                                                                                         
double Latarray[50];                                                
double Lonarray[50];                                                
int inc = 1;
int ac =0;    
//******************************************************************************************************                                                                  
// GPS Variables & Setup
double lat,lon;
//int Number_of_SATS;                                             //Unused.                               
float bearing;
float distance;
NMEAGPS  gps;
gps_fix  fix;                                                      
                                                              
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
int compass_dev = 5;                                               // the amount of deviation that is allowed in the compass heading 
int heading = 0;                                                   
int compass_counter=0;                                                                 

//******************************************************************************************************
//// Ping Sensor for Collision Avoidance  ***************BURAYA SONRA BAKILACAK
//
//boolean pingOn = false;                                            // Turn Collision detection On or Off
//
//int trigPin = 43;                                                  // Trig - Orange
//int echoPin = 42;                                                  // Echo - Yellow
//long duration, inches;
//int Ping_distance;
//
//unsigned long currentMillis = 0;
//unsigned long previousMillis = 0;                                  // Store last time Ping was updated
//const long interval = 200;                                         // Ping the Distance every X miliseconds
 
//******************************************************************************************************
// Bluetooth Variables & Setup
String veri;
int v1;
int v2;
int v3;
int v4;
int v5;

int v;

String pp1;
String pp2;
String pp3;
String pp4;
String pp5;

Point noktalar[5];

//*****************************************************************************************************
//Pointing Variables & Setup
double xmin;
double xmax;
double ymin;
double ymax;
Point alan[5];
Point kare[200];                              //Default array size is 200. Value can be increased according to the size of the operation. 
Point polygon_[200];                          //Be careful about reserved memory size to not exceed max memory.
#define INSIDE 0
#define OUTSIDE 1

int N=200;

//*****************************************************************************************************
void setup() 
{  
  Serial.begin(9600);
  Serial2.begin(9600);                                           
  gpsPort.begin(9600);
  
  while (!Serial)
    ;

  // Compass I2C Connection
  Wire.begin();

  compass.init();
  compass.setSamplingRate(50);
  compass.setOversampling(256);
  compass.setRange(8);

  Startup();                                                       // Run the startup process once
}


// Main Loop
void loop()
{                                                                                                  
  getGPS();                                                        // Update GPS location
  getCompass();                                                    // Update heading
  //Ping();                                                        
  goWaypoint();  
}
