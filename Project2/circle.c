/*
CScI0600-Fundamental Algorithms
Home work project -2
Name - Vijaya Kumar Venkatramanan

Compile- gcc circle.c -lm -o circle
Run - ./circle

Note:- ulimit -s 32768 (To increase the memory size)


*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
double distx,disty;
double dist;


void smallest_circle_two_fixed(double pix,double piy,double qix,double qiy,long nm,double pts5[][2],double ***radius,double *center)
{
double distx1,disty1;
double dist1;

double x1,x2,y1,y2,c1,c2,obj1,obj2,obj3,obj4,s,tt;
double cx,cy,a1,a2,b1,b2,a3;
double radius1,radius2;

center[0]=(qix+pix)/2;
center[1]=(qiy+piy)/2;



distx1=(pix-(center[0]));
disty1=(piy-(center[1]));
dist1=(distx1*distx1)+(disty1*disty1);
***radius=sqrt(dist1);


long t;
for(t=0;t<nm;t++)
{

distx1=(center[0]-pts5[t][0]);
disty1=(center[1]-pts5[t][1]);
dist1=(distx1*distx1)+(disty1*disty1);
dist1=sqrt(dist1);

if(dist1<(***radius))
{
//printf("\n lesssss\n");


}
else
{

x1=(pts5[t][1]-piy);
y1=(piy-qiy);
x2=(pix-pts5[t][0]);
y2=(qix-pix);

c1=(0.5*pts5[t][0])-(0.5*qix);
c2=(0.5*pts5[t][1])-(0.5*qiy);


obj1=(y2*c1)-(c2*y1);	
obj2=(y2*x1)-(y1*x2);
obj3=(c2*x1)-(c1*x2);

s=obj1/obj2;
tt=obj3/obj2;


a1=(0.5*pix)+(0.5*qix);
a2=(piy-qiy);
b2=(qix-pix);
a3=(0.5*piy)+(0.5*qiy);



center[0]=a1+(tt*a2);
center[1]=a3+(tt*b2);

distx1=(pix-center[0]);
disty1=(piy-center[1]);
dist1=(distx1*distx1)+(disty1*disty1);
***radius=sqrt(dist1);
	

}

}


}



void smallest_circle_one_fixed(double pix,double piy,long num,double pts3[][2],double **radius,double *center)
{

double qix,qiy;
double max;

long p;
long k;
long r;
srand(time(NULL));
double sx,sy;
for(p=num-1;p>0;p--)
{
r= rand() % p;

sx=pts3[r][0];
sy=pts3[r][1];
pts3[r][0]=pts3[p][0];
pts3[r][1]=pts3[p][1];
pts3[p][0]=sx;
pts3[p][1]=sy;
}


for(k=0;k<num;k++)
{
if(k==0)
{
distx=(pts3[k][0]-pix)*(pts3[k][0]-pix);
disty=(pts3[k][1]-piy)*(pts3[k][1]-piy);
dist=distx+disty;
dist=sqrt(dist);
max=dist;
qix=pts3[k][0];
qiy=pts3[k][1];
}
else
{
distx=(pts3[k][0]-pix)*(pts3[k][0]-pix);
disty=(pts3[k][1]-piy)*(pts3[k][1]-piy);
dist=distx+disty;
dist=sqrt(dist);

if(dist>max)
{
max=dist;
qix=pts3[k][0];
qiy=pts3[k][1];

}
else
{
//printf("\n no change\n");
}

}

}

long flag;
long t;
flag=0;
for(t=0;t<num;t++)
{
if(pts3[t][0]==qix && pts3[t][1]==qiy)
{
}
else
{
flag++;
}

}



double pts4[flag][2];
long c;
long g;
c=0;
for(g=0;g<num;g++)
{
if(pts3[g][0]==qix && pts3[g][1]==qiy)
{

}
else
{

pts4[c][0]=pts3[g][0];
pts4[c][1]=pts3[g][1];
c++;
}

}

/*
printf("\n qix,qiy %lf,%lf\n",qix,qiy);
printf("\n pix,piy %lf,%lf\n",pix,piy);
*/


smallest_circle_two_fixed(pix,piy,qix,qiy,c,pts4,&radius,&(center[0]));


}



void circumcircle(long n, double *pts,double *radius,double *center)
{
long i;



//permutation of n numbers

long p;
time_t t;
long r;
srand(time(NULL));
double sx,sy;
for(p=n-1;p>1;p--)
{
r= rand() % p;

sx=pts[2*r];
sy=pts[2*r+1];
pts[2*r]=pts[2*p];
pts[2*r+1]=pts[2*p+1];
pts[2*p]=sx;
pts[2*p+1]=sy;

}



double max;
double pix;
double piy;
long k;
for(k=1;k<n;k++)
{
if(k==1)
{
distx=(pts[2*k]-pts[0])*(pts[2*k]-pts[0]);
disty=(pts[2*k+1]-pts[1])*(pts[2*k+1]-pts[1]);
dist=distx+disty;
dist=sqrt(dist);
max=dist;
pix=pts[2*k];
piy=pts[2*k+1];
}
else
{
distx=(pts[2*k]-pts[0])*(pts[2*k]-pts[0]);
disty=(pts[2*k+1]-pts[1])*(pts[2*k+1]-pts[1]);
dist=distx+disty;
dist=sqrt(dist);
if(dist>max)
{
max=dist;
pix=pts[2*k];
piy=pts[2*k+1];

}
else
{
//printf("\n no change\n");
}

}

}


long g,flag;
flag=0;
for(g=0;g<n;g++)
{
if(pts[2*g]==pix && pts[2*g+1]==piy)
{

}
else
{
flag++;
}

}

//printf("\n2ndst set flag value %ld\n",flag);


double pts2[flag][2];
long c=0;
for(t=0;t<n;t++)
{
if(pts[2*t]==pix && pts[2*t+1]==piy)
{

}
else
{
pts2[c][0]=pts[2*t];
pts2[c][1]=pts[2*t+1];
c++;
}

}

smallest_circle_one_fixed(pix,piy,c,pts2,&radius,&(center[0]));

}

main()
{  double pts[200000][2], radius, center[2];
   long i, j; 
   double x,y;
 
   printf("Preparing test1\n");
   i=0;
   for( j= 0; j <100000; j++)
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
   printf("Running test1: %ld pts\n", i);
   circumcircle( i, &pts[0][0], &radius, &(center[0]) );	
   printf("Found Center (%lf,%lf), radius value is %lf; should be (%f,%f), %f",center[0],center[1],radius, 5.0, 5.0, 5.0*sqrt(2) );
      	

printf("\n-------------------------------\n");

   printf("Preparing test2\n");
   i=0; j= 0;
   while (i < 199998 )
   {  x = ((j*j) % 300001)/200000.0;
      y = (j+i)% 300007 / 200000.0;

      if( (x-0.6)*(x-0.6) + (y-0.7)*(y-0.7) <= 0.25 )
      {  pts[i][0] = x; pts[i][1] = y; i++; 
      }
      j++;
   }
   pts[199998][0]=0.1; pts[199998][1] = 0.7;
   pts[199999][0]=1.1; pts[199999][1] = 0.7;
   i+=2;
   printf("Running test2: %ld pts\n", i);
   circumcircle( i,&(pts[0][0]), &radius, &(center[0]) );
   printf("Found Center (%lf,%lf), radius value is %lf; should be (%f,%f), %f",center[0],center[1],radius,0.6, 0.7, 0.5 );


}

