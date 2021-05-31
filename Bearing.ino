float BearingTo( const Location_t & p1, const Location_t & p2 )
{
  const float LOC_SCALE = 1.0e-7;
  const float RAD_PER_DEG = PI / 180.0;     
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

} 

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
} 
