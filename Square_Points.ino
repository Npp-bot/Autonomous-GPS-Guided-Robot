void pointing()
{
  double k,j,a;
  int i,c=0;
  
  xmin = noktalar[1].x;
  xmax = noktalar[1].x;
  ymin = noktalar[1].y;
  ymax = noktalar[1].y;
  // Alan, noktalar olarak değiştirilecek
  for (i = 0; i < 5; i++)
  {

    xmin = MIN(xmin, noktalar[i].x);
    xmax = MAX(xmax, noktalar[i].x);
    ymin = MIN(ymin, noktalar[i].y);
    ymax = MAX(ymax, noktalar[i].y);

  }
  for (j = ymin; j <= ymax; j = j + 0.0000020)
  {
    a = (long(j*10000000))% 2;                              //TEST THIS LINE******************************

    if (a == 1) {

      for (k = xmin; k <= xmax; k = k + 0.0000200)
      {
        kare[c].x = k;
        kare[c].y = j;
        c = c + 1;
      }
    }
    else {

      for (k = xmax; k >= xmin; k = k - 0.0000200)
      {
        kare[c].x = k;
        kare[c].y = j;
        c = c + 1;
      }
    }
  }
}
