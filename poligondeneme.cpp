#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define INSIDE 0
#define OUTSIDE 1
#include<stdio.h>

typedef struct {
   double x,y;
} Point;



int InsidePolygon(Point *polygon,int N,Point p)
{
  int counter = 0;
  int i;
  double xinters;
  Point p1,p2;

  p1 = polygon[0];
  for (i=1;i<=N;i++) {
    p2 = polygon[i % N];
    if (p.y > MIN(p1.y,p2.y)) {
      if (p.y <= MAX(p1.y,p2.y)) {
        if (p.x <= MAX(p1.x,p2.x)) {
          if (p1.y != p2.y) {
            xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
            if (p1.x == p2.x || p.x <= xinters)
              counter++;
          }
        }
      }
    }
    p1 = p2;
  }

  if (counter % 2 == 0){
  
  	printf("outside");
    return(OUTSIDE);
	}
  else{
  
  	printf("inside");
    return(INSIDE);
	}
}


int main(){
	int N = 5;
	Point noktam={1.563,1.973};
	Point poligonum[]={(0,0),(1,3),(4,3),(2,2),(5,2)};
	
	InsidePolygon(poligonum,N,noktam);
	
}







