xmin = alan[1].x;
xmax = alan[1].x;
ymin = alan[1].y;
ymax = alan[1].y;
// Alan noktalar olarak değiştirilecek
for (i = 0; i < 5; i++)
{

  xmin = MIN(xmin, alan[i].x);
  xmax = MAX(xmax, alan[i].x);
  ymin = MIN(ymin, alan[i].y);
  ymax = MAX(ymax, alan[i].y);

}


//solu = {xmin, ymin};
//sola = {xmin, ymax};
//sagu = {xmax, ymin};
//saga = {xmin, ymax};

for (j = ymin; j <= ymax; j = j + 20)
{
  a = j % 2;

  if (a == 1) {

    for (k = xmin; k <= xmax; k = k + 200)
    {
      kare[c].x = k;
      kare[c].y = j;
      c = c + 1;
    }
  }
  else {

    for (k = xmax; k >= xmin; k = k - 200)
    {
      kare[c].x = k;
      kare[c].y = j;
      c = c + 1;
    }
  }
}
