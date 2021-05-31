// Using Serial2 to receive outer edges via bluetooth
void bluetooth()
{
 while (Serial2.available() && (noktalar[4].y!=0) )
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
    
    noktalar[0].x = (noktalar[0].x/10000000)+40;
    noktalar[0].y = (noktalar[0].y/10000000)+29;
    noktalar[1].x = (noktalar[1].x/10000000)+40;
    noktalar[1].y = (noktalar[1].x/10000000)+29;
    noktalar[2].x = (noktalar[2].x/10000000)+40;
    noktalar[2].y = (noktalar[2].x/10000000)+29;
    noktalar[3].x = (noktalar[3].x/10000000)+40;
    noktalar[3].y = (noktalar[3].x/10000000)+29;
    noktalar[4].x = (noktalar[4].x/10000000)+40;
    noktalar[4].y = (noktalar[4].x/10000000)+29;
    
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

 }                                                                                                                           
