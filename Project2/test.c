#include <stdio.h>

 void circumcircle(int n, double *pts, double *radius, double *center)
main()
{  double pts[200000][2], radius, center[2];
   long i, j; double x,y;
   printf("Preparing test1\n");
   i=0;
   for( j= 0; j < 100000; j++)
   {  x = 10.0 - ((double) j/ 100000.0 );
      y = 0.0;
      pts[i][0] = x; pts[i][1] = y; i++;
   }
   for( j= 0; j < 50000; j++)
   {  y = 10.0 - ((double) j/ 50000.0 );
      x = 0.0;
      pts[i][0] = x; pts[i][1] = y; i++;
   }
   for( j= 0; j < 50000; j++)
   {  x = 5.0 + 2.0*sin( (j/50000.0)*360.0) ; 
      y = 5.0 + 2.0*cos( (j/50000.0)*360.0) ; 
      pts[i][0] = x; pts[i][1] = y; i++;
   }
   printf("Running test1: %d pts\n", i);
   circumcircle( i, &(pts[0][0]), &radius, &(center[0]) );
   printf("Found center (%f,%f), radius %f; should be (%f,%f), %f\n", 
          center[0], center[1], radius, 5.0, 5.0, 5.0*sqrt(2) );
   printf("Preparing test2\n");
   i=0; j= 0;
   while (i < 199998 )
   {  x = ((j*j) % 300001) /200000.0;
      y = (j+i)% 300007 / 200000.0;
      if( (x-0.6)*(x-0.6) + (y-0.7)*(y-0.7) <= 0.25 )
      {  pts[i][0] = x; pts[i][1] = y; i++; 
      }
      j++;
   }
   pts[199998][0]=0.1; pts[199998][1] = 0.7;
   pts[199999][0]=1.1; pts[199999][1] = 0.7;
   i+=2;
   printf("Running test2: %d pts\n", i);
   circumcircle( i, &(pts[0][0]), &radius, &(center[0]) );
   printf("Found center (%f,%f), radius %f; should be (%f,%f), %f\n", 
          center[0], center[1], radius, 0.6, 0.7, 0.5 );
}

