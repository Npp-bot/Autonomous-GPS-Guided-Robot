#include "Wire.h"                                                
#include <QMC5883L.h>                                          
#include <NMEAGPS.h>
using namespace NeoGPS;
#include <GPSport.h>
#include <HCSR04.h>
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
// Ping Sensor for Collision Avoidance

int trigPin1 = 31;
int echoPin1 = A0;
int trigPin2 = 33;
int echoPin2 = A1;
int trigPin3 = 35;
int echoPin3 = A2;
int trigPin4 = 37;
int echoPin4 = A3;
int trigPin5 = 39;
int echoPin5 = A4;

HCSR04 us1(trigPin1,echoPin1);
HCSR04 us2(trigPin2,echoPin2);
HCSR04 us3(trigPin3,echoPin3);
HCSR04 us4(trigPin4,echoPin4);
HCSR04 us5(trigPin5,echoPin5);

int Ping_distance1;
int Ping_distance2;
int Ping_distance3;
int Ping_distance4;
int Ping_distance5;
 
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
  Ping();                                                        
  goWaypoint();  
}
