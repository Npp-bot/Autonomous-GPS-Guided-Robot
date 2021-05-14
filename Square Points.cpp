#include <stdio.h>

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

int i;
int a;
int j;
int k;
int c=0;

double xmin;
double xmax;
double ymin;
double ymax;


typedef struct {
   double x,y;
} Point;

Point alan[]={{1,1},{2,1},{2,5},{3,4},{5,2}};
Point kare[5];
Point solu,sagu,sola,saga;

int main() {
	
	xmin=alan[1].x;
 	xmax=alan[1].x;
 	ymin=alan[1].y;
 	ymax=alan[1].y;
 	
  for (i=0;i<5;i++) 
 {
 	
    xmin = MIN(xmin,alan[i].x);
    xmax = MAX(xmax,alan[i].x);
    ymin = MIN(ymin,alan[i].y);
    ymax = MAX(ymax,alan[i].y);
    
  }
   printf("%f %f %f %f \n",xmin,xmax,ymin,ymax);
 
 solu = {xmin,ymin};
 sola = {xmin,ymax};
 sagu = {xmax,ymin};
 saga = {xmin,ymax};
 
  for (j=ymin;j<=ymax;j++)
  {
  	a=j%2;
  	
	  if (a==1){
  		
  	for (k=xmin;k<=xmax;k++)
	  {
	  	kare[c].x = k;
		kare[c].y = j;
		printf("%f,%f \n",kare[c].x,kare[c].y);
		  c= c+1;
	  }
	}
	  else{
	  
	  for (k=xmax;k>=xmin;k--)
	  {
	  	kare[c].x = k;
		kare[c].y = j;
		printf("%f,%f \n",kare[c].x,kare[c].y);
		  c= c+1;
  }
  }
}
}



