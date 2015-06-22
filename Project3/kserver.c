/* 
Course-Fundamental Algorithms
Name -Vijaya Kumar Venkatramanan
Homework Project 3
*/


/* Compiles with command line-   gcc kserver.c -lX11 -lm -L/usr/X11R6/lib 
   Runs with command line-      ./a.out

*/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



//Display *display;
Display *display_ptr;

//Window window;
Window win;

//XEvent event;
XEvent report;


GC yellowGC, redGC, blueGC,GreenGC;
GC gc, gc_yellow, gc_red, gc_grey , gc_green , gc_dot;

char yellowASCII[] = "#FFFF00";
char redASCII[] = "#FF0000";
char blueASCII[] = "#0000FF";
char greenASCII[] = "#00FF00";

XColor yellowColor, redColor, blueColor ,greenColor ,greenColor1;
XColor tmp_color1, tmp_color2,tmp_color11, tmp_color22;

Colormap colormap;
Colormap color_map;


Screen *screen_ptr;
int screen_num;
char *display_name = NULL;
unsigned int display_width, display_height;
int border_width;
unsigned int win_width, win_height;
int win_x, win_y;

XWMHints *wm_hints;
XClassHint *class_hints;
XSizeHints *size_hints;
XTextProperty win_name, icon_name;
char *win_name_string = "K ser";
char *icon_name_string = "Icon for Example Window";


GC gc_g ,gc_r,gc_y;
unsigned long valuemask = 0;
XGCValues gc_values, gc_yellow_values, gc_red_values, gc_grey_values,gc_green_values,gc_dot_values,gc_g_values,gc_r_values,gc_y_values;



unsigned long pixels[12];


double xr,yr,xy,yy,xg,yg;
double pts[3][2];
double dis[3];
double point[50][2];
int counter=0;
double onlineCost;
double tempcost;
int per=0;
int track[31];
int trk=0;
double myCalculatedCost=0;
double optimalCost=0;
double CompetitiveRatio;



void readcost(double cost[30][30][30][30], int count){
    double min;
    
    int I, J, K;
    int i,j,k,time;
    trk=0;
    for(time = 0; time <=count; time++){
        min = 7777777.0;
        for(i = 0; i <= time; i++){
            for(j = 0; j <= time; j++){
                for(k = 0; k <= time; k++){
	//printf("cost array %lf\n",cost[0][0][0][0]);
                    if(cost[i][j][k][time] < min && cost[i][j][k][time] >= 0){
                        min = cost[i][j][k][time];
                        I = i;
                        J = j;
                        K = k;
                    }
                }
            }
        }
        //printf("%d %d %d at t %d cost--> %lf\n", I, J, K, time, cost[I][J][K][time]);
	optimalCost = cost[I][J][K][time];
        track[trk]=I;
	track[trk+1]=J;
	track[trk+2]=K;
	trk=trk+3;
	}
}


	

double distance(double pt1x, double pt1y,double pt2x,double pt2y)
{
double dist1,dist2,dist;
dist1=(pt2x-pt1x);
dist2=(pt2y-pt1y);

dist1=dist1*dist1;

dist2=dist2*dist2;

dist=dist1+dist2;
dist=sqrt(dist);
return dist;
}

void optimalStratergy(double points[][2] , int count,double xr,double yr,double xg,double yg,double xx,double xy)
{
printf("\n-----------------K Server problem-------------------------------------------\n");
double cost[30][30][30][30]; 
double nwpoints[count][2];
double min;
int m;
int tmp=1;
double found[count][2];
nwpoints[0][0]=0;
nwpoints[0][1]=0;
double min1,min2,min3;


/// nwpoints stores the points, starting from 1st index leaving zero index as zero.
for(m=0;m<count;m++)
{
nwpoints[tmp][0]=points[m][0];
nwpoints[tmp][1]=points[m][1];
tmp++;

}

for(m=0;m<tmp;m++)
{

//printf("\n New points--> %lf,%lf \n",nwpoints[m][0],nwpoints[m][1]);


}



		
int i,j,k,t,l;



for(t=0;t<tmp;t++)
{

//minDist

min=7777777;

if(t==0)
{

cost[0][0][0][0]=0;
tempcost=cost[0][0][0][0];
min=cost[0][0][0][0];
//printf("\nmin=%lf i=%d , j=%d ,k=%d\n",min,0,0,0); 	 

}
else
{


for(i=0;i<=t;i++)
{

  for(j=0;j<=t;j++)
  {

    for(k=0;k<=t;k++)
    {


   // to record number of permutation 
    per++;
   

    // at time =1
    if(t==1)
    {
	//001- red-3rd server , 010 - yellow , 100- green-1st server

	if( (i==1 && j==0 && k==0))
	{
	
	cost[1][0][0][t]= distance(148,158,nwpoints[t][0],nwpoints[t][1]);
	
	//printf("cost1, i,j,k,t %d,%d,%d,%d, %lf\n",i,j,k,t,cost[1][0][0][t]);
     	//printf("\nmin=%lf i=%d , j=%d ,k=%d\n",min,i,j,k);	
		if(cost[1][0][0][t]<min)
		{
		min=cost[1][0][0][t];
		track[trk]=i;
		track[trk+1]=j;
		track[trk+2]=k;	
		
		//printf("\nmin=%lf i=%d , j=%d ,k=%d\n",min,i,j,k);
		}


	
	}
	else if((i==0 && j==1 && k==0))
	{

	cost[0][1][0][t]= distance(513,158,nwpoints[t][0],nwpoints[t][1]);
	//printf("cost2, i,j,k,t %d,%d,%d,%d,%lf\n",i,j,k,t,cost[0][1][0][t]);	

		if(cost[0][1][0][t]<min)
		{
		min=cost[0][1][0][t];
		track[trk]=i;
		track[trk+1]=j;
		track[trk+2]=k;
		
		//printf("\nmin=%lf i=%d , j=%d ,k=%d\n",min,i,j,k);	
		}
		

	}
	else if((i==0 && j==0 && k==1))
	{
	cost[0][0][1][t]= distance(359,485,nwpoints[t][0],nwpoints[t][1]);
	//printf("cost3, i,j,k,t %d,%d,%d,%d,%lf\n",i,j,k,t,cost[0][0][1][t]);	
	

		if(cost[0][0][1][t]<min)
		{
		min=cost[0][0][1][t];	
		
		//printf("\nmin=%lf i=%d , j=%d ,k=%d\n",min,i,j,k);
		
		}


	}
	else
    	{
	//printf(" at t=%d i,j,k %d,%d,%d\n",t,i,j,k);
    	cost[i][j][k][t]=999999.0;
    	}

	
	





    }
 // for time = 2....N
    else
    {
    	
    if(i!=t && j!=t && k!=t)
    {
    // infinity
    cost[i][j][k][t]=999999.0;
    
    }
    else
    {
	min=77777777;
//	printf("<-----i,j,k,t--------->%d,%d,%d,%d\n",i,j,k,t);
    for(l=0;l<t;l++)
    {   
    	
		
	if(cost[l][j][k][t-1]>0 && cost[l][j][k][t-1]<999999.0)
	{

	
	if(l==0)
	{
//cost[i][j][k][t]=cost[l][j][k][t-1] + distance(148,158,nwpoints[i][0],nwpoints[i][1]);
min1=cost[l][j][k][t-1] + distance(148,158,nwpoints[i][0],nwpoints[i][1]);
//printf("\ni,j,k,t, i->l Newcost(at l=%d) is %lf,%d,%d,%d,%d\n",l,min1,i,j,k,t);		
	}


	else
	{
//cost[i][j][k][t]=cost[l][j][k][t-1] + distance(nwpoints[l][0],nwpoints[l][1],nwpoints[i][0],nwpoints[i][1]);
min1=cost[l][j][k][t-1] + distance(nwpoints[l][0],nwpoints[l][1],nwpoints[i][0],nwpoints[i][1]);
//printf("\ni,j,k,t, i->l Newcost(at l=%d) is %lf %d,%d,%d,%d\n",l,min1,i,j,k,t);		
	}		

			
			// min1<minDist
			if(min1<min)
			{
			min=min1;
			
			//printf("\nmin=%lf i=%d , j=%d ,k=%d\n",min,i,j,k);
			}

		
	}






	if(cost[i][l][k][t-1]>0 && cost[i][l][k][t-1]<999999.0)
	{
	
	
	if(l==0)
	{
//cost[i][j][k][t]=cost[i][l][k][t-1] + distance(513,158,nwpoints[j][0],nwpoints[j][1]);
min2=cost[i][l][k][t-1] + distance(513,158,nwpoints[j][0],nwpoints[j][1]);
//printf("\ni,j,k,t, j->l Newcost(at l=%d) is %lf ,%d,%d,%d,%d\n",l,min2,i,j,k,t);
	}
	else
	{
//cost[i][j][k][t]=cost[i][l][k][t-1] + distance(nwpoints[l][0],nwpoints[l][1],nwpoints[j][0],nwpoints[j][1]);
min2=cost[i][l][k][t-1] + distance(nwpoints[l][0],nwpoints[l][1],nwpoints[j][0],nwpoints[j][1]);
//printf("\ni,j,k,t, j->l Newcost(at l=%d) is %lf,%d,%d,%d,%d\n",l,min2,i,j,k,t);
	}	

			// min2<minDist
			if(min2<min)
			{
			min=min2;
			
			}





	}
	if(cost[i][j][l][t-1]>0 && cost[i][j][l][t-1]<999999.0)
	{



	if(l==0)
	{
//cost[i][j][k][t]=cost[i][j][l][t-1] + distance(359,485,nwpoints[k][0],nwpoints[k][1]);
min3=cost[i][j][l][t-1] + distance(359,485,nwpoints[k][0],nwpoints[k][1]);
//printf("\ni,j,k,t, k->l Newcost(at l=%d) is %lf,%d,%d,%d,%d\n",l,min3,i,j,k,t);
 	}
	else
	{
//cost[i][j][k][t]=cost[i][j][l][t-1] + distance(nwpoints[l][0],nwpoints[l][1],nwpoints[k][0],nwpoints[k][1]);
min3=cost[i][j][l][t-1] + distance(nwpoints[l][0],nwpoints[l][1],nwpoints[k][0],nwpoints[k][1]);
//printf("\ni,j,k,t, k>l Newcost(at l=%d)  is %lf,%d,%d,%d,%d\n",l,min3,i,j,k,t);

	}
			// min3<minDist

			if(min3<min)
			{
			min=min3;			
			
			}







		}
		

	

      




    }


cost[i][j][k][t]=min;
//printf("\nfinal minimum is %lf at %d,%d,%d,%d\n",min,i,j,k,t);


    }      
      
    }






    }  


  }


}







}





}






readcost(cost,count);

int final[100];
int fn=0;
int time=0;

// prints out the recorded optimal points.
//printf("track is %d\n",trk);
m=0;
while(m<trk)
{
//printf("points are= %d,%d,%d\n",track[m],track[m+1],track[m+2]);

if(time==0)
{
final[fn]=track[m];
final[fn+1]=track[m+1];
final[fn+2]=track[m+2];
}
else
{

  if(time==track[m])
  {
  final[fn]=track[m];
  final[fn+1]=final[fn-2];
  final[fn+2]=final[fn-1];
  }
  else if(time==track[m+1])
  {
  final[fn]=final[fn-3];
  final[fn+1]=track[m+1];
  final[fn+2]=final[fn-1];
  }
  else if(time==track[m+2])
  {
  
  final[fn]=final[fn-3];
  final[fn+1]=final[fn-2]; 
  final[fn+2]=track[m+2];
  }



}

fn=fn+3;
m=m+3;
time++;
}

XSetLineAttributes(display_ptr, redGC, 4, LineSolid, CapRound, JoinRound);
XSetLineAttributes(display_ptr, yellowGC, 4, LineSolid, CapRound, JoinRound);
XSetLineAttributes(display_ptr, GreenGC, 4, LineSolid, CapRound, JoinRound);

//printf("\n final %d\n",fn);
m=0;
//int coordinates[count][2];
int cr=1;
long position=0;

long chx,chy;
while(m<fn)
{
double xnw,ynw;

printf("%d,%d,%d\n",final[m],final[m+1],final[m+2]);

//printf("m value--->%d ,%ld\n",m,position);

if(position==1)
{
//printf("\nenter at position %d\n",position);
 if(position==final[m])
 {
 XDrawLine(display_ptr, win, GreenGC,148,158,nwpoints[position][0],nwpoints[position][1]);

 }
 else if(position==final[m+1])
 {
 XDrawLine(display_ptr, win, yellowGC,513,158,nwpoints[position][0],nwpoints[position][1]);
 }
 else if(position==final[m+2])
 {
 XDrawLine(display_ptr, win,redGC,359,485,nwpoints[position][0],nwpoints[position][1]);
 }
 else
 {

 }



}

else if(position>1)
{
int val;
 if(position==final[m])
 {
 // printf("at m and m-3 %d,%d\n", final[m] , final[m-3]);
 if(final[m-3]==0)
 {
 xnw=148.0;
 ynw=158.0;
 }
 else
 {
 xnw=nwpoints[final[m-3]][0];
 ynw=nwpoints[final[m-3]][1];
 }
 chx=nwpoints[position][0];
 chy=nwpoints[position][1];

 //printf("xnw,ynw values %lf,%lf,%lf,%lf\n",xnw,ynw,nwpoints[position][0],nwpoints[position][1]);
 XDrawLine(display_ptr, win, GreenGC,nwpoints[position][0],nwpoints[position][1],xnw,ynw);

 }
 
 else if(position==final[m+1])
 {
 //printf("at m and m-2 %d,%d\n",final[m+1] , final[m-2]);
 if(final[m-2]==0)
 {
 xnw=513.0;
 ynw=158.0;
 }
 else
 {
 xnw=nwpoints[final[m-2]][0];
 ynw=nwpoints[final[m-2]][1];
 }


 XDrawLine(display_ptr, win, yellowGC,xnw,ynw,nwpoints[position][0],nwpoints[position][1]);

 }
 else if(position==final[m+2])
 {

// printf("at m and m-1 %d,%d\n",final[m+2] , final[m-1]);
 if(final[m-1]==0)
 {
 xnw=359.0;
 ynw=485.0;
 }
 else
 {
 xnw=nwpoints[final[m-1]][0];
 ynw=nwpoints[final[m-1]][1];
 }
 XDrawLine(display_ptr, win, redGC,xnw,ynw,nwpoints[position][0],nwpoints[position][1]);

 }
 else
 {
 printf("\n");
 }
 

}

position++;
m=m+3;
}




printf("\nMy calculatedCost--------------------->%lf\n",myCalculatedCost);
printf(" \n optimalCost    --------------------->%lf\n",optimalCost);
CompetitiveRatio=myCalculatedCost/optimalCost;
printf("\n Competitive Ratio--------------------->%lf\n",CompetitiveRatio);

	
}		



int main(int argc, char **argv)
{
  /* opening display: basic connection to X Server */
  if( (display_ptr = XOpenDisplay(display_name)) == NULL )
    { printf("Could not open display. \n"); exit(-1);}
  printf("Connected to X server  %s\n", XDisplayName(display_name) );
  screen_num = DefaultScreen( display_ptr );
  screen_ptr = DefaultScreenOfDisplay( display_ptr );
  color_map  = XDefaultColormap( display_ptr, screen_num );
  display_width  = DisplayWidth( display_ptr, screen_num );
  display_height = DisplayHeight( display_ptr, screen_num );

  printf("Width %d, Height %d, Screen Number %d\n", 
           display_width, display_height, screen_num);
  /* creating the window */
  border_width = 10;
  win_x = 0; win_y = 0;
  win_width = display_width;
  win_height = (int) (win_width / 1.7); /*rectangular window*/
  
  win= XCreateSimpleWindow( display_ptr, RootWindow( display_ptr, screen_num),
                            win_x, win_y, win_width, win_height, border_width,
                            BlackPixel(display_ptr, screen_num),
                            WhitePixel(display_ptr, screen_num) );
  /* now try to put it on screen, this needs cooperation of window manager */
  size_hints = XAllocSizeHints();
  wm_hints = XAllocWMHints();
  class_hints = XAllocClassHint();
  if( size_hints == NULL || wm_hints == NULL || class_hints == NULL )
    { printf("Error allocating memory for hints. \n"); exit(-1);}

  size_hints -> flags = PPosition | PSize | PMinSize  ;
  size_hints -> min_width = 60;
  size_hints -> min_height = 60;

  XStringListToTextProperty( &win_name_string,1,&win_name);
  XStringListToTextProperty( &icon_name_string,1,&icon_name);
  
  wm_hints -> flags = StateHint | InputHint ;
  wm_hints -> initial_state = NormalState;
  wm_hints -> input = False;

  class_hints -> res_name = "x_use_example";
  class_hints -> res_class = "examples";

  XSetWMProperties( display_ptr, win, &win_name, &icon_name, argv, argc,
                 size_hints, wm_hints, class_hints );

  /* what events do we want to receive */
  XSelectInput( display_ptr, win, 
            ExposureMask | StructureNotifyMask | ButtonPressMask );
  


  /* finally: put window on screen */
  XMapWindow( display_ptr, win );

  XFlush(display_ptr);



	yellowGC = XCreateGC(display_ptr, win, 0, 0);
	redGC = XCreateGC(display_ptr, win, 0, 0);
	blueGC = XCreateGC(display_ptr, win, 0, 0);
	GreenGC = XCreateGC(display_ptr, win, 0, 0);
		

	colormap = DefaultColormap(display_ptr, 0);
	
	XParseColor(display_ptr, colormap, yellowASCII, &yellowColor);
	XParseColor(display_ptr, colormap, redASCII, &redColor);
	XParseColor(display_ptr, colormap, blueASCII, &blueColor);
	XParseColor(display_ptr, colormap, greenASCII, &greenColor);
	

	XAllocColor(display_ptr, colormap, &yellowColor);
	XAllocColor(display_ptr, colormap, &redColor);
	XAllocColor(display_ptr, colormap, &blueColor);
	XAllocColor(display_ptr, colormap, &greenColor);
	

	XSetForeground(display_ptr, yellowGC, yellowColor.pixel);
	XSetForeground(display_ptr, redGC, redColor.pixel);
	XSetForeground(display_ptr, blueGC, blueColor.pixel);
	XSetForeground(display_ptr, GreenGC, greenColor.pixel);
	
	XSetLineAttributes(display_ptr, yellowGC, 2, LineSolid, CapRound, JoinRound);
	XSetLineAttributes(display_ptr, redGC, 2, LineSolid, CapRound, JoinRound);
	XSetLineAttributes(display_ptr, blueGC, 2, LineSolid, CapRound, JoinRound);
	XSetLineAttributes(display_ptr, GreenGC, 2, LineSolid, CapRound, JoinRound);
	


	





  /* create graphics context, so that we may draw in this window */
  gc = XCreateGC( display_ptr, win, valuemask, &gc_values);
  XSetForeground( display_ptr, gc, DefaultColormap( display_ptr, screen_num ) );
  XSetLineAttributes( display_ptr, gc, 4, LineSolid, CapRound, JoinRound);
  XSetStandardProperties(display_ptr,win,"Kserver","MyJoint",None,NULL,0,NULL);
      

  /* Graphics context to draw dotted lines */
   gc_dot =XCreateGC( display_ptr, win, valuemask, &gc_dot_values);
   XSetForeground( display_ptr, gc_dot, BlackPixel( display_ptr, screen_num ) );
  XSetLineAttributes( display_ptr, gc_dot, 1, LineOnOffDash, CapProjecting, JoinRound);

  
 

        //XClearWindow(display_ptr, win);
	

  	
  /* and now it starts: the event loop */
  while(1)
    { XNextEvent( display_ptr, &report );
      switch( report.type )
	{
	case Expose:
          /* (re-)draw the example figure. This event happens
             each time some part ofthe window gets exposed (becomes visible) */
		  
	
	  XFillArc( display_ptr, win, GreenGC, 140, 
                       154,
                       win_height/30, win_height/30, 0, 360*64);
	  
	  XFillArc( display_ptr, win, redGC, 355, 
                       485,
                       win_height/30, win_height/30, 0, 360*64);

	  XFillArc( display_ptr, win, yellowGC,507,157,
                       win_height/30, win_height/30, 0, 360*64);	  

	  xr=359;yr=485;xg=148;yg=158;xy=513;yy=158;
	/*
        printf(" Red %lf,%lf \n",xr,yr);
	printf(" Green %lf,%lf \n",xg,yg);
    	printf(" Yellow %lf,%lf \n",xy,yy);
	*/
        pts[0][0]=xr;pts[0][1]=yr;
	pts[1][0]=xy;pts[1][1]=yy;
	pts[2][0]=xg;pts[2][1]=yg;
  
	        
	  break;
        case ConfigureNotify:
          /* This event happens when the user changes the size of the window*/
          win_width = report.xconfigure.width;
          win_height = report.xconfigure.height;
          break;
        case ButtonPress:
          /* This event happens when the user pushes a mouse button. I draw
            a circle to show the point where it happened, but do not save 
            the position; so when the next redraw event comes, these circles
	    disappear again. */
          {  
	     int end;
             double x, y;
	     
	     
  	     x = report.xbutton.x;
             y = report.xbutton.y;
             
		
		if (report.xbutton.button == Button1 )
	        {
		//printf("\n start %lf,%lf \n",x,y);
		point[counter][0]=x;
		point[counter][1]=y;
		counter++;
		end=0;            	
		}
		else
	        {
		
		optimalStratergy(point,counter,xr,yr,xg,yg,xy,yy);
                	
		break;
		}	  

	
	double dist1,dist2,dr,dg,dy;
	double min=0;

	dist1=(pts[0][0]-x)*(pts[0][0]-x);
	dist2=(pts[0][1]-y)*(pts[0][1]-y);
	dr=dist1+dist2;
	dr=sqrt(dr);				

	dist1=(pts[1][0]-x)*(pts[1][0]-x);
	dist2=(pts[1][1]-y)*(pts[1][1]-y);
	dy=dist1+dist2;
	dy=sqrt(dy);

	dist1=(pts[2][0]-x)*(pts[2][0]-x);
	dist2=(pts[2][1]-y)*(pts[2][1]-y);
	dg=dist1+dist2;
	dg=sqrt(dg);
	
	dis[0]=dr;dis[1]=dy;dis[2]=dg;
	
	
	//printf("\n dr,dy,dg %lf,%lf,%lf\n",dr,dy,dg);
	int i,j;


	// Calculate the list distance.      

	if(dr<dy)
	{
	min=dr;
	}
	else
	{
	min=dy;
	}

	if(min<dg)
	{
	
	}
	else
	{
	min=dg;
	}
	//printf("minimum %lf\n",min);

 
	for(i=0;i<3;i++)
	{	
	if(min==dis[i])
	{
	
	if(i==0)
	{
	XDrawLine(display_ptr, win,redGC, pts[i][0] , pts[i][1] ,x, y);
        myCalculatedCost=min+myCalculatedCost;
	}
	else if(i==1)
	{
	XDrawLine(display_ptr, win, yellowGC, pts[i][0] , pts[i][1] ,x, y);
	myCalculatedCost=min+myCalculatedCost;
        }
	else if(i==2)
	{
	XDrawLine(display_ptr, win, GreenGC, pts[i][0] , pts[i][1] ,x, y);
	myCalculatedCost=min+myCalculatedCost;
        }	
	pts[i][0]=x;
	pts[i][1]=y;		
	}
		
	}


	

         }
          break;
        default:
	  /* this is a catch-all for other events; it does not do anything.
             One could look at the report type to see what the event was */ 
          break;
	}

    }
  exit(0);
}
