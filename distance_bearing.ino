#include <NMEAGPS.h>
using namespace NeoGPS;
#include <GPSport.h>
NMEAGPS gps;

const float LOC_SCALE = 1.0e-7;
const float RAD_PER_DEG = PI / 180.0;
gps_fix  fix; 


void setup() {
  Serial.begin(9600);
  gpsPort.begin(9600);

}

void loop() {
  while (gps.available( gpsPort )) {
  fix = gps.read(); // save the latest
  }
   //Serial.println( fix.latitude(),7 );
  //Serial.println( fix.longitude(),7 );
 double lat = fix.latitude();
 double lng = fix.longitude();
 Location_t p1(fix.latitude(),fix.longitude());
double lat_dest=40.6928510;
 double lng_dest=29.8331020;
 Location_t p2(lat_dest,lng_dest);
 double x = abs(lat - lat_dest);
  double y = abs(lng - lng_dest);
  double z=sqrt( pow(x,2)+ pow(y,2));
  //Serial.println( lat,7 );
  //Serial.println( lat_dest,7 );
  //Serial.println( z*100000,7 );
   float bearing = BearingTo(p1,p2);
   Serial.println( bearing,7 );
   Serial.println( lat );
   Serial.println( lng );
  //**********************************************************
}   
 //******************************************************************
float BearingTo( const Location_t & p1, const Location_t & p2 )
{
  int32_t dLonL   = safeDLong( p2.lon(), p1.lon() );
  float   dLon    = dLonL * RAD_PER_DEG * LOC_SCALE;
  int32_t dLatL   = p2.lat() - p1.lat();
  float   lat1    = p1.lat() * RAD_PER_DEG * LOC_SCALE;
  float   cosLat1 = cos( lat1 );
  float   x, y, bearing;

  if ((abs(dLatL)+abs(dLonL)) < 1000) {
    //  VERY close together.  Just use equirect approximation with precise integers.
    x       = dLonL * cosLat1;
    y       = dLatL;
    bearing = PI/2.0 - atan2(y, x);

  } else {
    float lat2    = p2.lat() * RAD_PER_DEG * LOC_SCALE;
    float cosLat2 = cos(lat2);
    y             = sin(dLon) * cosLat2;
    x             = cosLat1   * sin(lat2) - sin(lat1) * cosLat2 * cos(dLon);
    bearing       = atan2(y, x);
  }

  if (bearing < 0.0)
    bearing += TWO_PI;

  return bearing*(180/PI);

} // BearingTo


int32_t safeDLong( int32_t p2, int32_t p1 )
{
  int32_t dLonL;
  int32_t halfDLon = (p2/2 - p1/2);
  if (halfDLon < -1800000000L/2) {
    dLonL = (p2 + 1800000000L) - (p1 - 1800000000L);
  } else if (1800000000L/2 < halfDLon) {
    dLonL = (p2 - 1800000000L) - (p1 + 1800000000L);
  } else {
    dLonL = p2 - p1;
  }
  return dLonL;
  

} // safeDLon
