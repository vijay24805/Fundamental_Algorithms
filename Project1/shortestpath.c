
/* 
Course-Fundamental Algorithms
Name -Vijaya Kumar Venkatramanan
Homework Project 1
*/


/* Compiles with command line-   gcc shortestpath.c -lX11 -lm -L/usr/X11R6/lib 
   Runs with command line-       ./shortestpath input.txt 

Events::
   Left click to select the starting point. 
   Right click to end the program.
*/


#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


Display *display_ptr;
Screen *screen_ptr;
int screen_num;
char *display_name = NULL;
unsigned int display_width, display_height;
//used to store the current vertex
double qx, qy;		
//used to check the orientation.
double or1,or2,or3,or4;
//New start points
double xstart,ystart;
double xstrt,ystrt;
int ed;
//store the extended line vertex values.
double xx ,yy;
// to check the orientation value
double  xr1,xr2,xr3,xr4;
// The intersection points
double px,py;
// Used while solving two linear equations.
double sa,sb;
double ttx,tty;
double s;
double ax,ay,cx,cy,dx,dy;
double bx,by;
Window win;
int border_width;
unsigned int win_width, win_height;
int win_x, win_y;
double edx,edy,ex,ey;
double eo1,eo2,eo3,eo4;
double xt,yt;
double test1,test2;
//double tx,ty;
int kk;
int j;
double distx,disty;
double dist;
double pr1,pr2,pr3,pr4;
double xnew , ynew;
double ptest1,ptest2;

XWMHints *wm_hints;
XClassHint *class_hints;
XSizeHints *size_hints;
XTextProperty win_name, icon_name;
char *win_name_string = "Home Work 1-Fundamental Algorithms";
char *icon_name_string = "Fundamental Algorithms";

XEvent report;

GC gc, gc_yellow, gc_red, gc_grey,gc_dot,gc_green;
unsigned long valuemask = 0;
XGCValues gc_values, gc_yellow_values, gc_red_values, gc_grey_values,gc_dot_values,gc_green_values;
Colormap color_map;
XColor tmp_color1, tmp_color2;


int incr;
int incr_1;
int incr_2;
int incr_12;
int incr_base;
int incr_base1;
int incr_base2;
int incr01;
double chargx;
double chargy;
double chgx,chgy;
int incr_last;
int incr_ls;
int incrsa;

void Draw(int argc , char **argv)
{
int k,c;
int count=0;
FILE *pf;
//reading from the input file	
  
   pf = fopen(argv[1], "r");
    
    if(pf==NULL)
	{	
      printf("its null");
 	}
    else
	{
	rewind(pf);
	count=0;
   //iterate through input file and get all the coordinates in an array
	
        do
	{
	c=fgetc(pf);
	if(c=='\n')
	count++;

	}while(c!=EOF);

	rewind(pf);
	
	int *ptr_a = &count;

	int anew[count][2];
	//printf("\n count is------------%d\n",count);

     for(k=0;k<count;k++)
       {
	 fscanf(pf,"%d,%d" ,&anew[k][0],&anew[k][1]);

	//scaling the inputs.

	anew[k][0]=(anew[k][0]*4);
	anew[k][1]=(anew[k][1]*4);

    printf("\ncoordinates ---%d,%d\n" ,anew[k][0],anew[k][1]);
		
	}
	
	//printf("\n count is------------%d\n",count);
	
	//drawing the polygon
	for(k=0;k<count-1;k++)
	{
	XDrawLine(display_ptr, win, gc,anew[k][0],anew[k][1],anew[k+1][0],anew[k+1][1]);
	}
	XDrawLine(display_ptr, win, gc,anew[k][0],anew[k][1],anew[0][0],anew[0][1]);
	rewind(pf);
		
       }
	
	
	
	printf("file end");
	fclose(pf);	




}



void find(double vis1[][2],int orgcnt,int xsnew,int ysnew,double pxn1,double pyn1,double cxn1,double cyn1,double dxn1,double dyn1,double exn1,double eyn1,double chrgx,double chrgy,double xstart1,double ystart1)
{
double vchgx,vchgy;
double distch,distchx,distchy;
double chplx,chply,chmx,chmy,chqx,chqy;
double orch;
double oreint1;
double oreint2;
double oreint3,oreint4;
int f;
int oreint;
int orcnt=orgcnt;
double edxn1,edyn1;
int found_1;
found_1=0;
double fndvr[10][40][12];
double fndvr1[10][40][14];
double fndvr12[20][40][12];
double fndvrb2[20][40][12];
double fndvrls[10][40][14];
double fndsa[10][50][14];
int found2;
found2=0;

incr_base++;
incr_base1++;
incr_base2++;

int found_3,found_4,found_ls;
int found_sa,found_7,found_11;
int found_sa2,found_l2s,found_l3s;
int found_8,found_9,found_10;
int found_12;
found_12=0;
found_l2s=0;
found_11=0;
found_10=0;
found_l3s=0;
found_8=0;
found_9=0;
found_sa2=0;
found_7=0;
found_sa=0;
found_ls=0;
found_3=0;
found_4=0;
int found_5,found_6;
found_5=0;
found_6=0;
incr_2++;
incr01++;
int edd1;
int edn1;
int flag1,k;
double eo1n1,eo2n1;
int i;
double qxn1,qyn1;
double txn1,tyn1,san1,sbn1,sn1;
double axn,ayn,bxn,byn;

int pxcomp1,pycomp1;
pxcomp1=pxn1;
pycomp1=pyn1;
edd1=orgcnt;


or1=(xstart1*cyn1)-(ystart1*cxn1)-(pxn1*cyn1)+(pxn1*ystart1)+(pyn1*cxn1)-(pyn1*xstart1);
or2=(xstart1*eyn1)-(ystart1*exn1)-(pxn1*eyn1)+(pxn1*ystart1)+(pyn1*exn1)-(pyn1*xstart1);


if(or1>-0.1 && or1<0.1)
{
or1=-1.0;
}
else if(or2>-0.1 && or2<0.1)
{
or2=-1.0;
}


//printf("\n **********or1 and or2*********** %lf,%lf,%lf \n",or1,or2,(or1*or2));


int t;				
if(or1*or2<0)
{

for(i=0;i<orgcnt;i++)
{

if(dxn1==vis1[i][0] && dyn1==vis1[i][1])
{
t=i;
}
else
{

}

}

int spc;
if(t==0)
{
spc=orgcnt-1;
}
else
{
spc=32;
}

int ch=t;
int check;
check=t-1;


double dx,dx1,dy1,dy,d,d1;
dx=(vis1[t][0]-chrgx);
dy=(vis1[t][1]-chrgy);
dx=dx*dx;
dy=dy*dy;
d=dx+dy;
d=sqrt(d);

if(t!=orgcnt-1)
{
dx1=(vis1[t][0]-vis1[t+1][0]);
dy1=(vis1[t][1]-vis1[t+1][1]);
dx1=dx1*dx1;
dy1=dy1*dy1;
d1=dx1+dy1;
d1=sqrt(d1);
}
else
{
dx1=(vis1[t][0]-vis1[0][0]);
dy1=(vis1[t][1]-vis1[0][1]);
dx1=dx1*dx1;
dy1=dy1*dy1;
d1=dx1+dy1;
d1=sqrt(d1);
}



int loop=0;
if(d<d1 && chrgy!=0.0)
{
//printf("\nloop\n");
loop++;
}


if(((vis1[t-1][0]==cxn1 && vis1[t-1][1]==cyn1) || (cxn1==chrgx && cyn1==chrgy)  || (vis1[spc][0]==cxn1 && vis1[spc][1]==cyn1)) && loop==0)
{
//printf("\n ed++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

printf("new starting point %d,%d\n",xsnew,ysnew);
printf("i-1 %lf,%lf\n",cxn1,cyn1);
printf("i+1 %lf,%lf\n",dxn1,dyn1);
flag1=0;
while(vis1[t][0]!=xsnew || vis1[t][1]!=ysnew)
{
	
	if(flag1==0)
	{
	flag1=flag1+3;
	t++;
	}
	else if(t==orgcnt-1)
	{
	flag1++;
	t=0;
	}
	else
	{
	flag1++;
	t++;
	
	}
	
}
double vertex1[flag1][2];
k=1;
while(vis1[ch][0]!=xsnew || vis1[ch][1]!=ysnew)
{
vertex1[0][0]=pxn1;
vertex1[0][1]=pyn1;
if(k==1)
{
vertex1[1][0]=vis1[ch][0];
vertex1[1][1]=vis1[ch][1];
}
else if(ch==orgcnt-1)
{
vertex1[k][0]=vis1[0][0];
vertex1[k][1]=vis1[0][1];
}
else
{
vertex1[k][0]=vis1[ch][0];
vertex1[k][1]=vis1[ch][1];

}

if(ch==orgcnt-1)
{
ch=0;
k++;
}
else
{
if(k==1)
{
k++;
ch++;
}
else
{
ch++;
k++;
}

}
}
vertex1[k][0]=vis1[ch][0];
vertex1[k][1]=vis1[ch][1];

int kk;
for(kk=0;kk<flag1;kk++)
{
    xstrt=xsnew;
    ystrt=ysnew;
    qxn1=vertex1[kk][0];
    qyn1=vertex1[kk][1];


int edg;
for(edg=0;edg<flag1;edg++)
{

if(edg<flag1-1)
{
or1=(qxn1*vertex1[edg+1][1])+(xstrt*qyn1)+(ystrt*vertex1[edg+1][0]) -(vertex1[edg+1][0]*qyn1)-(xstrt*vertex1[edg+1][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*qxn1)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*qxn1)-(vertex1[edg+1][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*xstrt)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*xstrt)-(vertex1[edg+1][0]*ystrt);
}
else
{
or1=(qxn1*vertex1[0][1])+(xstrt*qyn1)+(ystrt*vertex1[0][0]) -(vertex1[0][0]*qyn1)-(xstrt*vertex1[0][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*qxn1)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*qxn1)-(vertex1[0][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*xstrt)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*xstrt)-(vertex1[0][0]*ystrt);

}

if((or3*or4)<0 && (or1*or2)<0)
    {
	
		break;
    }
else if(edg==flag1-1)	
{
int c,t;
t=0;
for(c=0;c<orgcnt;c++)
{
if(xstrt==vis1[c][0] && ystrt==vis1[c][1])
{
t=c;
}
else
{
}
}

distchx=(vis1[t][0]-vis1[t+1][0]);
distchy=(vis1[t][1]-vis1[t+1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);


chplx=(vis1[t+1][0]-vis1[t][0])/distch;
chply=(vis1[t+1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-vis1[t-1][0]);
distchy=(vis1[t][1]-vis1[t-1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chmx=(vis1[t-1][0]-vis1[t][0])/distch;
chmy=(vis1[t-1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-qxn1);
distchy=(vis1[t][1]-qyn1);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chqx=(qxn1-vis1[t][0])/distch;
chqy=(qyn1-vis1[t][1])/distch;

orch=(chmx*chqy)-(chqx*chmy)-(chplx*chqy)+(chplx*chmy)+(chply*chqx)-(chply*chmx);



oreint=0;
for(f=0;f<orgcnt-1;f++)
{

oreint1=(qxn1*vis1[f][1])-(vis1[f][0]*qyn1)-(vis1[t][0]*vis1[f][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f][0])-(vis1[t][1]*qxn1);

oreint2=(qxn1*vis1[f+1][1])-(vis1[f+1][0]*qyn1)-(vis1[t][0]*vis1[f+1][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f+1][0])-(vis1[t][1]*qxn1);

oreint3=(vis1[f+1][0]*qyn1)-(qxn1*vis1[f+1][1])-(vis1[f][0]*qyn1)+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*qxn1)-(vis1[f][1]*vis1[f+1][0]);

oreint4=(vis1[f+1][0]*vis1[t][1])-(vis1[t][0]*vis1[f+1][1])-(vis1[f][0]*vis1[t][1])+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*vis1[t][0])-(vis1[f][1]*vis1[f+1][0]);

if((oreint1*oreint2)<0 && (oreint3*oreint4)<0)
{
oreint++;
break;
}
else
{
}

}

if(orch<0 || oreint>0)
{
break;
}
else
{

//XDrawLine(display_ptr, win, gc_red, xstrt*4 , ystrt*4 ,qxn1*4,qyn1*4);
	distx=(qxn1-xstrt)*(qxn1-xstrt);
	disty=(qyn1-ystrt)*(qyn1-ystrt);
	dist=distx+disty;
	dist=sqrt(dist);
         
	//find xnew , qnew and ttx,tty
	xt=xstrt+(xstrt-qxn1)/dist*80;
	yt=ystrt+(ystrt-qyn1)/dist*80;

	xx=qxn1+(qxn1-xstrt)/dist*100;
	yy=qyn1+(qyn1-ystrt)/dist*100;

//XDrawLine(display_ptr, win, gc_dot, qxn1*4 , qyn1*4 ,xx*4,yy*4);
if(kk<flag1-1)
{
edxn1=vertex1[kk+1][0];
edyn1=vertex1[kk+1][1];
exn1=vertex1[kk-1][0];
eyn1=vertex1[kk-1][1];
}
else
{
edxn1=vertex1[0][0];
edyn1=vertex1[0][1];
exn1=vertex1[kk][0];
eyn1=vertex1[kk][1];
}
eo1n1=(xt*edyn1)-(yt*edxn1)-(xx*edyn1)+(xx*yt)+(yy*edxn1)-(yy*xt);
eo2n1=(xt*eyn1)-(yt*exn1)-(xx*eyn1)+(xx*yt)+(yy*exn1)-(yy*xt);
if(eo1n1>-0.1 && eo1n1<0.1)
{
eo1n1=1.0;
}
else if(eo2n1>-0.1 && eo2n1<0.1)
{
eo2n1=1.0;
}
double ee;
ee=eo1n1*eo2n1;
        if((ee)<0)
	{
	
	break;
	}
	else
	{
	


	    int edn1;
	    for(edn1=0;edn1<flag1;edn1++)
	    {				
		// first line
			axn=qxn1;
			ayn=qyn1;
			bxn=xx;
			byn=yy;
		// second line 
			if(edn1<flag1-1)
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[edn1+1][0];
			dyn1=vertex1[edn1+1][1];
			}
			else
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[0][0];
			dyn1=vertex1[0][1];
			}
	    

	xr1=(bxn*cyn1)-(cxn1*byn)-(axn*cyn1)+(axn*byn)+(ayn*cxn1)-(ayn*bxn);
	xr2=(bxn*dyn1)-(dxn1*byn)-(axn*dyn1)+(axn*byn)+(ayn*dxn1)-(ayn*bxn);

	xr3=(dxn1*ayn)-(axn*dyn1)-(cxn1*ayn)+(cxn1*dyn1)+(cyn1*axn)-(cyn1*dxn1);
	xr4=(dxn1*byn)-(bxn*dyn1)-(cxn1*byn)+(cxn1*dyn1)+(cyn1*bxn)-(cyn1*dxn1);
		
	
			


			if( ((xr1*xr2)<0 && (xr3*xr4)<0))
		 	{
			
		   	//	printf("\nintersectig this one\n");
			san1=(bxn-axn)*(cyn1-ayn)-(byn-ayn)*(cxn1-axn);
			sbn1=(bxn-axn)*(cyn1-dyn1)-(byn-ayn)*(cxn1-dxn1);

			sn1=san1/sbn1;
			//the intersection points on the edge1 of polygon are tx,ty

				txn1=cxn1+sn1*(dxn1-cxn1);
				tyn1=cyn1+sn1*(dyn1-cyn1);
			int j;
			for(j=0;j<flag1;j++)
			{
			
			if(j<flag1-1)
			{						
			/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn1*vertex1[j+1][1])+(txn1*qyn1)+(tyn1*vertex1[j+1][0]) -(vertex1[j+1][0]*qyn1)-(txn1*vertex1[j+1][1])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0]) -(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])-(tyn1*qxn1);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex1[j][0]*qyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*qxn1)-(vertex1[j][0]*vertex1[j+1][1])-(vertex1[j][1]*qxn1)-(vertex1[j+1][0]*qyn1);
    pr4=(vertex1[j][0]*tyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*txn1)-(vertex1[j][0]*vertex1[j+1][1])-(vertex1[j][1]*txn1)-(vertex1[j+1][0]*tyn1);			
			}

			else
			{
			/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn1*vertex1[0][1])+(txn1*qyn1)+(tyn1*vertex1[0][0]) -(vertex1[0][0]*qyn1)-(txn1*vertex1[0][1])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0]) -(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])-(tyn1*qxn1);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex1[j][0]*qyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*qxn1)-(vertex1[j][0]*vertex1[0][1])-(vertex1[j][1]*qxn1)-(vertex1[0][0]*qyn1);
    pr4=(vertex1[j][0]*tyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*txn1)-(vertex1[j][0]*vertex1[0][1])-(vertex1[j][1]*txn1)-(vertex1[0][0]*tyn1);			

}

if(pr4>-0.1 && pr4<0.1)
{
pr4=1.0;
}
else if(pr3>-0.1 && pr3<0.1)
{
pr3=1.0;
}
else if(pr2>-0.1 && pr2<0.1)
{
pr2=1.0;
}
else if(pr1>-0.1 && pr1<0.1)
{
pr1=1.0;
}



				if((pr3*pr4)<0 && (pr1*pr2)<0)
				{
				
				break;
				}
				else if(j==flag1-1)
				{
				if((qxn1==pxcomp1 && qyn1==pycomp1))
				{
				
				}
				else
				{
				
				XDrawLine(display_ptr, win, gc_dot, qxn1*4 , qyn1*4 ,txn1*4, tyn1*4);
				int h;
				int dot;
				dot=0;
				for(h=0;h<orgcnt;h++)
				{
				
				if(cxn1==vis1[h][0] && cyn1==vis1[h][1])
				{
				dot++;
				}
				else
				{
				dot=0;				
				}

				}	


				if(dot>0)
				{
				chgx=0;
				chgy=0;

				}
				else
				{
				chgx=cxn1;
				chgy=cyn1;
				}
				if(incr_base1==1)
				{
				fndvr[incr][found_1][0]=qxn1;
				fndvr[incr][found_1][1]=qyn1;
				fndvr[incr][found_1][2]=txn1;
				fndvr[incr][found_1][3]=tyn1;
				fndvr[incr][found_1][4]=cxn1;
				fndvr[incr][found_1][5]=cyn1;				
				fndvr[incr][found_1][6]=dxn1;
				fndvr[incr][found_1][7]=dyn1;				
				fndvr[incr][found_1][8]=exn1;
				fndvr[incr][found_1][9]=eyn1;				
				fndvr[incr][found_1][10]=chgx;
				fndvr[incr][found_1][11]=chgy;
				found_1++;
				}
				else if(incr_base1==2)
				{
				fndvrb2[incr01][found2][0]=qxn1;
				fndvrb2[incr01][found2][1]=qyn1;
				fndvrb2[incr01][found2][2]=txn1;
				fndvrb2[incr01][found2][3]=tyn1;
				fndvrb2[incr01][found2][4]=cxn1;
				fndvrb2[incr01][found2][5]=cyn1;				
				fndvrb2[incr01][found2][6]=dxn1;
				fndvrb2[incr01][found2][7]=dyn1;				
				fndvrb2[incr01][found2][8]=exn1;
				fndvrb2[incr01][found2][9]=eyn1;				
				fndvrb2[incr01][found2][10]=chgx;
				fndvrb2[incr01][found2][11]=chgy;				
				
				found2++;
				}

				}
				}

		  }

		}
		else
		{
		}
	
	    }
	}	



}
}

}


}

int i;
if(incr_base1==1)
{	
	for(i=0;i<found_1;i++)
	{
	
find(vis1,orcnt,fndvr[incr][i][0],fndvr[incr][i][1],fndvr[incr][i][2],fndvr[incr][i][3],fndvr[incr][i][4],fndvr[incr][i][5],fndvr[incr][i][6],fndvr[incr][i][7],fndvr[incr][i][8],fndvr[incr][i][9],fndvr[incr][i][10],fndvr[incr][i][11],xstrt,ystrt);

	}


}

}
else
{

//printf("\n ed ---------------------------------------------------\n");
printf("new starting point %d,%d\n",xsnew,ysnew);
printf("i-1 %lf,%lf\n",cxn1,cyn1);
printf("i+1 %lf,%lf\n",dxn1,dyn1);

incr_1++;
flag1=0;
while(vis1[t][0]!=xsnew || vis1[t][1]!=ysnew)
{
	
	if(flag1==0)
	{
	flag1=flag1+3;
	t--;
	
	}
	else if(t==0)
	{
	
	flag1++;
	t=orgcnt-1;
	
	}
	else
	{
	
	flag1++;
	t--;
	
	
	}
}
int vertex1[flag1][2];
k=1;
while(vis1[ch][0]!=xsnew || vis1[ch][1]!=ysnew)
{

vertex1[0][0]=pxn1;
vertex1[0][1]=pyn1;

if(k==1)
{
vertex1[1][0]=vis1[ch][0];
vertex1[1][1]=vis1[ch][1];
}
else
{
vertex1[k][0]=vis1[ch][0];
vertex1[k][1]=vis1[ch][1];
}

if(ch==0)
{
ch=orgcnt-1;
k++;
}
else
{
ch--;
k++;
}

}
vertex1[k][0]=vis1[ch][0];
vertex1[k][1]=vis1[ch][1];

int kk;
for(kk=0;kk<flag1;kk++)
{
    xstrt=xsnew;
    ystrt=ysnew;
    qxn1=vertex1[kk][0];
    qyn1=vertex1[kk][1];


int edg;
for(edg=0;edg<flag1;edg++)
{

if(edg<flag1-1)
{
or1=(qxn1*vertex1[edg+1][1])+(xstrt*qyn1)+(ystrt*vertex1[edg+1][0]) -(vertex1[edg+1][0]*qyn1)-(xstrt*vertex1[edg+1][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*qxn1)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*qxn1)-(vertex1[edg+1][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*xstrt)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*xstrt)-(vertex1[edg+1][0]*ystrt);
}
else
{
or1=(qxn1*vertex1[0][1])+(xstrt*qyn1)+(ystrt*vertex1[0][0]) -(vertex1[0][0]*qyn1)-(xstrt*vertex1[0][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*qxn1)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*qxn1)-(vertex1[0][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*xstrt)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*xstrt)-(vertex1[0][0]*ystrt);

}

if((or3*or4)<0 && (or1*or2)<0)
    {
	
		break;
    }
else if(edg==flag1-1)	
{
int c,t;
t=0;
for(c=0;c<orgcnt;c++)
{
if(xstrt==vis1[c][0] && ystrt==vis1[c][1])
{
t=c;
}
else
{
}
}

distchx=(vis1[t][0]-vis1[t+1][0]);
distchy=(vis1[t][1]-vis1[t+1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);


chplx=(vis1[t+1][0]-vis1[t][0])/distch;
chply=(vis1[t+1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-vis1[t-1][0]);
distchy=(vis1[t][1]-vis1[t-1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chmx=(vis1[t-1][0]-vis1[t][0])/distch;
chmy=(vis1[t-1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-qxn1);
distchy=(vis1[t][1]-qyn1);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chqx=(qxn1-vis1[t][0])/distch;
chqy=(qyn1-vis1[t][1])/distch;

orch=(chmx*chqy)-(chqx*chmy)-(chplx*chqy)+(chplx*chmy)+(chply*chqx)-(chply*chmx);



oreint=0;
for(f=0;f<orgcnt-1;f++)
{

oreint1=(qxn1*vis1[f][1])-(vis1[f][0]*qyn1)-(vis1[t][0]*vis1[f][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f][0])-(vis1[t][1]*qxn1);

oreint2=(qxn1*vis1[f+1][1])-(vis1[f+1][0]*qyn1)-(vis1[t][0]*vis1[f+1][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f+1][0])-(vis1[t][1]*qxn1);

oreint3=(vis1[f+1][0]*qyn1)-(qxn1*vis1[f+1][1])-(vis1[f][0]*qyn1)+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*qxn1)-(vis1[f][1]*vis1[f+1][0]);

oreint4=(vis1[f+1][0]*vis1[t][1])-(vis1[t][0]*vis1[f+1][1])-(vis1[f][0]*vis1[t][1])+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*vis1[t][0])-(vis1[f][1]*vis1[f+1][0]);

if((oreint1*oreint2)<0 && (oreint3*oreint4)<0)
{
oreint++;
break;
}
else
{
}

}

if(orch<0 || oreint>0)
{
break;
}
else
{
//XDrawLine(display_ptr, win, gc, xstrt*4 , ystrt*4 ,qxn1*4,qyn1*4);
	distx=(qxn1-xstrt)*(qxn1-xstrt);
	disty=(qyn1-ystrt)*(qyn1-ystrt);
	dist=distx+disty;
	dist=sqrt(dist);
         
	//find xnew , qnew and ttx,tty
	xt=xstrt+(xstrt-qxn1)/dist*40;
	yt=ystrt+(ystrt-qyn1)/dist*40;

	xx=qxn1+(qxn1-xstrt)/dist*100;
	yy=qyn1+(qyn1-ystrt)/dist*100;

//XDrawLine(display_ptr, win, gc_dot, qxn1*4 , qyn1*4 ,xx*4,yy*4);
if(kk<flag1-1)
{
edxn1=vertex1[kk+1][0];
edyn1=vertex1[kk+1][1];
exn1=vertex1[kk-1][0];
eyn1=vertex1[kk-1][1];
}
else
{
edxn1=vertex1[0][0];
edyn1=vertex1[0][1];
exn1=vertex1[kk][0];
eyn1=vertex1[kk][1];
}
eo1n1=(xt*edyn1)-(yt*edxn1)-(xx*edyn1)+(xx*yt)+(yy*edxn1)-(yy*xt);
eo2n1=(xt*eyn1)-(yt*exn1)-(xx*eyn1)+(xx*yt)+(yy*exn1)-(yy*xt);
double ee;
ee=eo1n1*eo2n1;
        if((ee)<0)
	{
	break;
	}
	else
	{   
	
	int edn1;
	    for(edn1=0;edn1<flag1;edn1++)
	    {				
		// first line
			axn=qxn1;
			ayn=qyn1;
			bxn=xx;
			byn=yy;
		// second line 
			if(edn1<flag1-1)
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[edn1+1][0];
			dyn1=vertex1[edn1+1][1];
			}
			else
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[0][0];
			dyn1=vertex1[0][1];
			}
	    

	xr1=(bxn*cyn1)-(cxn1*byn)-(axn*cyn1)+(axn*byn)+(ayn*cxn1)-(ayn*bxn);
	xr2=(bxn*dyn1)-(dxn1*byn)-(axn*dyn1)+(axn*byn)+(ayn*dxn1)-(ayn*bxn);

	xr3=(dxn1*ayn)-(axn*dyn1)-(cxn1*ayn)+(cxn1*dyn1)+(cyn1*axn)-(cyn1*dxn1);
	xr4=(dxn1*byn)-(bxn*dyn1)-(cxn1*byn)+(cxn1*dyn1)+(cyn1*bxn)-(cyn1*dxn1);
	

//printf("\n___ qxn1,qyn1,xr1,xr2,xr3,xr4 %d,%d,%lf,%lf,%lf,%lf\n",qxn1,qyn1,xr1,xr2,xr3,xr4);	
	
			if( ((xr1*xr2)<0 && (xr3*xr4)<0))
		 	{
		   		//printf("\nintersectig this one\n");
			san1=(bxn-axn)*(cyn1-ayn)-(byn-ayn)*(cxn1-axn);
			sbn1=(bxn-axn)*(cyn1-dyn1)-(byn-ayn)*(cxn1-dxn1);

			sn1=san1/sbn1;

			
			//the intersection points on the edge1 of polygon are tx,ty

				txn1=cxn1+sn1*(dxn1-cxn1);
				tyn1=cyn1+sn1*(dyn1-cyn1);
		  int j;
		  for(j=0;j<flag1;j++)
		  {
			
			if(j<flag1-1)
			{						
			/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn1*vertex1[j+1][1])+(txn1*qyn1)+(tyn1*vertex1[j+1][0]) -(vertex1[j+1][0]*qyn1)-(txn1*vertex1[j+1][1])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0]) -(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])-(tyn1*qxn1);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex1[j][0]*qyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*qxn1)-(vertex1[j][0]*vertex1[j+1][1])-(vertex1[j][1]*qxn1)-(vertex1[j+1][0]*qyn1);
    pr4=(vertex1[j][0]*tyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*txn1)-(vertex1[j][0]*vertex1[j+1][1])-(vertex1[j][1]*txn1)-(vertex1[j+1][0]*tyn1);			
			}

			else
			{
			/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn1*vertex1[0][1])+(txn1*qyn1)+(tyn1*vertex1[0][0]) -(vertex1[0][0]*qyn1)-(txn1*vertex1[0][1])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0]) -(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])-(tyn1*qxn1);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex1[j][0]*qyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*qxn1)-(vertex1[j][0]*vertex1[0][1])-(vertex1[j][1]*qxn1)-(vertex1[0][0]*qyn1);
    pr4=(vertex1[j][0]*tyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*txn1)-(vertex1[j][0]*vertex1[0][1])-(vertex1[j][1]*txn1)-(vertex1[0][0]*tyn1);			

			}

if(pr4>-0.1 && pr4<0.1)
{
pr4=-1.0;
}
else if(pr3>-0.1 && pr3<0.1)
{
pr3=-1.0;
}
else if(pr2>-0.1 && pr2<0.1)
{
pr2=-1.0;
}
else if(pr1>-0.1 && pr1<0.1)
{
pr1=-1.0;
}


               	    
				if((pr3*pr4)<0 && (pr1*pr2)<0)
				{
				
				break;
				}
				else if(j==flag1-1)
				{
				if((qxn1==pxcomp1 && qyn1==pycomp1))
				{
				
				}
				else
				{
				
				XDrawLine(display_ptr, win, gc_dot, qxn1*4 , qyn1*4 ,txn1*4, tyn1*4);
				
				int h;
				int dot=0;
				
				for(h=0;h<orgcnt;h++)
				{
				
				if(cxn1==vis1[h][0] && cyn1==vis1[h][1])
				{
				dot++;
				
				}
				else
				{
						
				}

				}	

				if(dot>0)
				{
				chgx=0;
				chgy=0;

				}
				else
				{
				chgx=cxn1;
				chgy=cyn1;
				}
				
				if(incr_1==1)
				{	
				fndvr1[incr_1][found_3][0]=qxn1;
				fndvr1[incr_1][found_3][1]=qyn1;
				fndvr1[incr_1][found_3][2]=txn1;
				fndvr1[incr_1][found_3][3]=tyn1;
				fndvr1[incr_1][found_3][4]=cxn1;
				fndvr1[incr_1][found_3][5]=cyn1;				
				fndvr1[incr_1][found_3][6]=dxn1;
				fndvr1[incr_1][found_3][7]=dyn1;				
				fndvr1[incr_1][found_3][8]=exn1;
				fndvr1[incr_1][found_3][9]=eyn1;				
				fndvr1[incr_1][found_3][10]=chgx;
				fndvr1[incr_1][found_3][11]=chgy;
				fndvr1[incr_1][found_3][12]=xstrt;
				fndvr1[incr_1][found_3][13]=ystrt;
				found_3++;
				}
				else if(incr_1==2)
				{
				fndvr1[incr_1][found_4][0]=qxn1;
				fndvr1[incr_1][found_4][1]=qyn1;
				fndvr1[incr_1][found_4][2]=txn1;
				fndvr1[incr_1][found_4][3]=tyn1;
				fndvr1[incr_1][found_4][4]=cxn1;
				fndvr1[incr_1][found_4][5]=cyn1;				
				fndvr1[incr_1][found_4][6]=dxn1;
				fndvr1[incr_1][found_4][7]=dyn1;				
				fndvr1[incr_1][found_4][8]=exn1;
				fndvr1[incr_1][found_4][9]=eyn1;				
				fndvr1[incr_1][found_4][10]=chgx;
				fndvr1[incr_1][found_4][11]=chgy;
				fndvr1[incr_1][found_4][12]=xstrt;
				fndvr1[incr_1][found_4][13]=ystrt;
				found_4++;

				}
				else if(incr_1==3)
				{
				fndvr1[incr_1][found_7][0]=qxn1;
				fndvr1[incr_1][found_7][1]=qyn1;
				fndvr1[incr_1][found_7][2]=txn1;
				fndvr1[incr_1][found_7][3]=tyn1;
				fndvr1[incr_1][found_7][4]=cxn1;
				fndvr1[incr_1][found_7][5]=cyn1;				
				fndvr1[incr_1][found_7][6]=dxn1;
				fndvr1[incr_1][found_7][7]=dyn1;				
				fndvr1[incr_1][found_7][8]=exn1;
				fndvr1[incr_1][found_7][9]=eyn1;				
				fndvr1[incr_1][found_7][10]=chgx;
				fndvr1[incr_1][found_7][11]=chgy;
				fndvr1[incr_1][found_7][12]=xstrt;
				fndvr1[incr_1][found_7][13]=ystrt;
				found_7++;

				}
				else if(incr_1==4)
				{
				fndvr1[incr_1][found_9][0]=qxn1;
				fndvr1[incr_1][found_9][1]=qyn1;
				fndvr1[incr_1][found_9][2]=txn1;
				fndvr1[incr_1][found_9][3]=tyn1;
				fndvr1[incr_1][found_9][4]=cxn1;
				fndvr1[incr_1][found_9][5]=cyn1;				
				fndvr1[incr_1][found_9][6]=dxn1;
				fndvr1[incr_1][found_9][7]=dyn1;				
				fndvr1[incr_1][found_9][8]=exn1;
				fndvr1[incr_1][found_9][9]=eyn1;				
				fndvr1[incr_1][found_9][10]=chgx;
				fndvr1[incr_1][found_9][11]=chgy;
				fndvr1[incr_1][found_9][12]=xstrt;
				fndvr1[incr_1][found_9][13]=ystrt;
				found_9++;

				}
	
				else if(incr_1==5)
				{
				fndvr1[incr_1][found_12][0]=qxn1;
				fndvr1[incr_1][found_12][1]=qyn1;
				fndvr1[incr_1][found_12][2]=txn1;
				fndvr1[incr_1][found_12][3]=tyn1;
				fndvr1[incr_1][found_12][4]=cxn1;
				fndvr1[incr_1][found_12][5]=cyn1;				
				fndvr1[incr_1][found_12][6]=dxn1;
				fndvr1[incr_1][found_12][7]=dyn1;				
				fndvr1[incr_1][found_12][8]=exn1;
				fndvr1[incr_1][found_12][9]=eyn1;				
				fndvr1[incr_1][found_12][10]=chgx;
				fndvr1[incr_1][found_12][11]=chgy;
				fndvr1[incr_1][found_12][12]=xstrt;
				fndvr1[incr_1][found_12][13]=ystrt;
				found_12++;

				}



				}

		
				}
				else
				{
				}

		     }
		  }

		  else
		   {
		   }


	  }
		
	
	}

}

}

}

}

int i;
if(incr_1==1)
{
	for(i=0;i<found_3;i++)
	{
	
find(vis1,orcnt,fndvr1[1][i][0],fndvr1[1][i][1],fndvr1[1][i][2],fndvr1[1][i][3],fndvr1[1][i][4],fndvr1[1][i][5],fndvr1[1][i][6],fndvr1[1][i][7],fndvr1[1][i][8],fndvr1[1][i][9],fndvr1[1][i][10],fndvr1[1][i][11],fndvr1[1][i][12],fndvr1[1][i][13]);
	
	}


}
if(incr_1==2)
{

	for(i=0;i<found_4;i++)
	{
	
	
find(vis1,orcnt,fndvr1[2][i][0],fndvr1[2][i][1],fndvr1[2][i][2],fndvr1[2][i][3],fndvr1[2][i][4],fndvr1[2][i][5],fndvr1[2][i][6],fndvr1[2][i][7],fndvr1[2][i][8],fndvr1[2][i][9],fndvr1[2][i][10],fndvr1[2][i][11],fndvr1[2][i][12],fndvr1[2][i][13]);
	
	}


}

if(incr_1==3)
{
	if(found_7>0)
	{
	for(i=0;i<found_7;i++)
	{
	
	
find(vis1,orcnt,fndvr1[3][i][0],fndvr1[3][i][1],fndvr1[3][i][2],fndvr1[3][i][3],fndvr1[3][i][4],fndvr1[3][i][5],fndvr1[3][i][6],fndvr1[3][i][7],fndvr1[3][i][8],fndvr1[3][i][9],fndvr1[3][i][10],fndvr1[3][i][11],fndvr1[3][i][12],fndvr1[3][i][13]);
	
	}
	
	}
	else
	{
	}

}


if(incr_1==4)
{

	for(i=0;i<found_9;i++)
	{
	
	
find(vis1,orcnt,fndvr1[4][i][0],fndvr1[4][i][1],fndvr1[4][i][2],fndvr1[4][i][3],fndvr1[4][i][4],fndvr1[4][i][5],fndvr1[4][i][6],fndvr1[4][i][7],fndvr1[4][i][8],fndvr1[4][i][9],fndvr1[4][i][10],fndvr1[4][i][11],fndvr1[4][i][12],fndvr1[4][i][13]);
	
	}


}
/*
if(incr_1==5)
{

	for(i=0;i<found_12;i++)
	{	
find(vis1,orcnt,fndvr1[5][i][0],fndvr1[5][i][1],fndvr1[5][i][2],fndvr1[5][i][3],fndvr1[5][i][4],fndvr1[5][i][5],fndvr1[5][i][6],fndvr1[5][i][7],fndvr1[5][i][8],fndvr1[5][i][9],fndvr1[5][i][10],fndvr1[5][i][11],fndvr1[5][i][12],fndvr1[5][i][13]);
	
	}


}
*/

	
}

}
else
{
printf("\n next \n");
printf("new starting point %d,%d\n",xsnew,ysnew);
printf("i-1 %lf,%lf\n",cxn1,cyn1);
printf("i+1 %lf,%lf\n",dxn1,dyn1);
int spcl;
int chv;
int l;
t=l;
for(i=0;i<orgcnt;i++)
{

if(cxn1==vis1[i][0] && cyn1==vis1[i][1])
{
l=i;
chv=i;
}
else
{

}

}

if(l==0)
{
spcl=orgcnt;
}
else
{
spcl=34;
}



if((vis1[l-1][0]==dxn1 && vis1[l-1][1]==dyn1) || (vis1[spcl-1][0]==dxn1 && vis1[spcl-1][1]==dyn1))
{
//printf("\n MOVE FORWARD FORWARD \n");
incr_last++;
flag1=0;
while(vis1[l][0]!=xsnew || vis1[l][1]!=ysnew)
{
	
	if(flag1==0)
	{
	flag1=flag1+3;
	l++;
	}
	else if(l==orgcnt-1)
	{
	flag1++;
	l=0;
	}
	else
	{
	flag1++;
	l++;
	
	}
	
}

double vertex1[flag1][2];
k=1;
while(vis1[chv][0]!=xsnew || vis1[chv][1]!=ysnew)
{
vertex1[0][0]=pxn1;
vertex1[0][1]=pyn1;
if(k==1)
{
vertex1[1][0]=vis1[chv][0];
vertex1[1][1]=vis1[chv][1];
}
else if(chv==orgcnt-1)
{
vertex1[k][0]=vis1[0][0];
vertex1[k][1]=vis1[0][1];
}
else
{
vertex1[k][0]=vis1[chv][0];
vertex1[k][1]=vis1[chv][1];

}

if(chv==orgcnt-1)
{
chv=0;
k++;
}
else
{
if(k==1)
{
k++;
chv++;
}
else
{
chv++;
k++;
}

}
}
vertex1[k][0]=vis1[chv][0];
vertex1[k][1]=vis1[chv][1];


int kk;
for(kk=0;kk<flag1;kk++)
{
    xstrt=xsnew;
    ystrt=ysnew;
    qxn1=vertex1[kk][0];
    qyn1=vertex1[kk][1];


int edg;
for(edg=0;edg<flag1;edg++)
{

if(edg<flag1-1)
{
or1=(qxn1*vertex1[edg+1][1])+(xstrt*qyn1)+(ystrt*vertex1[edg+1][0]) -(vertex1[edg+1][0]*qyn1)-(xstrt*vertex1[edg+1][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*qxn1)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*qxn1)-(vertex1[edg+1][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*xstrt)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*xstrt)-(vertex1[edg+1][0]*ystrt);
}
else
{
or1=(qxn1*vertex1[0][1])+(xstrt*qyn1)+(ystrt*vertex1[0][0]) -(vertex1[0][0]*qyn1)-(xstrt*vertex1[0][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*qxn1)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*qxn1)-(vertex1[0][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*xstrt)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*xstrt)-(vertex1[0][0]*ystrt);

}

if((or3*or4)<0 && (or1*or2)<0)
    {
	
		break;
    }
else if(edg==flag1-1)	
{
int c,t;
t=0;
for(c=0;c<orgcnt;c++)
{
if(xstrt==vis1[c][0] && ystrt==vis1[c][1])
{
t=c;
}
else
{
}
}

distchx=(vis1[t][0]-vis1[t+1][0]);
distchy=(vis1[t][1]-vis1[t+1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);


chplx=(vis1[t+1][0]-vis1[t][0])/distch;
chply=(vis1[t+1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-vis1[t-1][0]);
distchy=(vis1[t][1]-vis1[t-1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chmx=(vis1[t-1][0]-vis1[t][0])/distch;
chmy=(vis1[t-1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-qxn1);
distchy=(vis1[t][1]-qyn1);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chqx=(qxn1-vis1[t][0])/distch;
chqy=(qyn1-vis1[t][1])/distch;

orch=(chmx*chqy)-(chqx*chmy)-(chplx*chqy)+(chplx*chmy)+(chply*chqx)-(chply*chmx);

if(((vis1[t+1][0]==qxn1) && (vis1[t+1][1]==qyn1)) || ((vis1[t-1][0]==qxn1) && (vis1[t-1][1]==qyn1)))
{
orch=0.2;
}



oreint=0;
for(f=0;f<orgcnt-1;f++)
{

oreint1=(qxn1*vis1[f][1])-(vis1[f][0]*qyn1)-(vis1[t][0]*vis1[f][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f][0])-(vis1[t][1]*qxn1);

oreint2=(qxn1*vis1[f+1][1])-(vis1[f+1][0]*qyn1)-(vis1[t][0]*vis1[f+1][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f+1][0])-(vis1[t][1]*qxn1);

oreint3=(vis1[f+1][0]*qyn1)-(qxn1*vis1[f+1][1])-(vis1[f][0]*qyn1)+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*qxn1)-(vis1[f][1]*vis1[f+1][0]);

oreint4=(vis1[f+1][0]*vis1[t][1])-(vis1[t][0]*vis1[f+1][1])-(vis1[f][0]*vis1[t][1])+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*vis1[t][0])-(vis1[f][1]*vis1[f+1][0]);

if((oreint1*oreint2)<0 && (oreint3*oreint4)<0)
{
oreint++;
break;
}
else
{
}

}

if(orch<0 || oreint>0)
{
break;
}
else
{

//XDrawLine(display_ptr, win, gc_red, xstrt*4 , ystrt*4 ,qxn1*4,qyn1*4);
        distx=(qxn1-xstrt)*(qxn1-xstrt);
	disty=(qyn1-ystrt)*(qyn1-ystrt);
	dist=distx+disty;
	dist=sqrt(dist);
         
	//find xnew , qnew and ttx,tty
	xt=xstrt+(xstrt-qxn1)/dist*30;
	yt=ystrt+(ystrt-qyn1)/dist*30;

	xx=qxn1+(qxn1-xstrt)/dist*50;
	yy=qyn1+(qyn1-ystrt)/dist*50;

//XDrawLine(display_ptr, win, gc_dot, qxn1*4 , qyn1*4 ,xx*4,yy*4);
if(kk<flag1-1)
{
edxn1=vertex1[kk+1][0];
edyn1=vertex1[kk+1][1];
exn1=vertex1[kk-1][0];
eyn1=vertex1[kk-1][1];
}
else
{
edxn1=vertex1[0][0];
edyn1=vertex1[0][1];
exn1=vertex1[kk][0];
eyn1=vertex1[kk][1];
}



eo1n1=(xt*edyn1)-(yt*edxn1)-(xx*edyn1)+(xx*yt)+(yy*edxn1)-(yy*xt);
eo2n1=(xt*eyn1)-(yt*exn1)-(xx*eyn1)+(xx*yt)+(yy*exn1)-(yy*xt);
if(eo1n1>-0.1 && eo1n1<0.1)
{
eo1n1=1.0;
}
else if(eo2n1>-0.1 && eo2n1<0.1)
{
eo2n1=1.0;
}



double ee;
ee=eo1n1*eo2n1;
        if((ee)<0)
	{
			
	break;
	}
	else
	{   
	
	    int edn1;
	    for(edn1=0;edn1<flag1;edn1++)
	    {				
		// first line
			axn=qxn1;
			ayn=qyn1;
			bxn=xx;
			byn=yy;
		// second line 
			if(edn1<flag1-1)
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[edn1+1][0];
			dyn1=vertex1[edn1+1][1];
			}
			else
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[0][0];
			dyn1=vertex1[0][1];
			}
	    

	xr1=(bxn*cyn1)-(cxn1*byn)-(axn*cyn1)+(axn*byn)+(ayn*cxn1)-(ayn*bxn);
	xr2=(bxn*dyn1)-(dxn1*byn)-(axn*dyn1)+(axn*byn)+(ayn*dxn1)-(ayn*bxn);

	xr3=(dxn1*ayn)-(axn*dyn1)-(cxn1*ayn)+(cxn1*dyn1)+(cyn1*axn)-(cyn1*dxn1);
	xr4=(dxn1*byn)-(bxn*dyn1)-(cxn1*byn)+(cxn1*dyn1)+(cyn1*bxn)-(cyn1*dxn1);
	
		
		if( ((xr1*xr2)<0 && (xr3*xr4)<0))
		 {
			
		
		   		//printf("\nintersectig this one\n");
			san1=(bxn-axn)*(cyn1-ayn)-(byn-ayn)*(cxn1-axn);
			sbn1=(bxn-axn)*(cyn1-dyn1)-(byn-ayn)*(cxn1-dxn1);

			sn1=san1/sbn1;

			
			//the intersection points on the edge1 of polygon are tx,ty

				txn1=cxn1+sn1*(dxn1-cxn1);
				tyn1=cyn1+sn1*(dyn1-cyn1);
		  int j;
		  for(j=0;j<flag1;j++)
		  {
			
			if(j<flag1-1)
			{						
    pr1=(qxn1*vertex1[j+1][1])+(txn1*qyn1)+(tyn1*vertex1[j+1][0]) -(vertex1[j+1][0]*qyn1)-(txn1*vertex1[j+1][1])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0]) -(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])-(tyn1*qxn1);

    pr3=(vertex1[j][0]*qyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*qxn1)-(vertex1[j][0]*vertex1[j+1][1])-(vertex1[j][1]*qxn1)-(vertex1[j+1][0]*qyn1);
    pr4=(vertex1[j][0]*tyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*txn1)-(vertex1[j][0]*vertex1[j+1][1])-(vertex1[j][1]*txn1)-(vertex1[j+1][0]*tyn1);			
			}

			else
			{
    pr1=(qxn1*vertex1[0][1])+(txn1*qyn1)+(tyn1*vertex1[0][0]) -(vertex1[0][0]*qyn1)-(txn1*vertex1[0][1])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0]) -(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])-(tyn1*qxn1);

    pr3=(vertex1[j][0]*qyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*qxn1)-(vertex1[j][0]*vertex1[0][1])-(vertex1[j][1]*qxn1)-(vertex1[0][0]*qyn1);
    pr4=(vertex1[j][0]*tyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*txn1)-(vertex1[j][0]*vertex1[0][1])-(vertex1[j][1]*txn1)-(vertex1[0][0]*tyn1);			
			}

if(pr4>-0.1 && pr4<0.1)
{
pr4=1.0;
}
else if(pr3>-0.1 && pr3<0.1)
{
pr3=1.0;
}
else if(pr2>-0.1 && pr2<0.1)
{
pr2=1.0;
}
else if(pr1>-0.1 && pr1<0.1)
{
pr1=1.0;
}

	
				if((pr3*pr4)<0 && (pr1*pr2)<0)
				{
				
				break;
				}
				else if(j==flag1-1)
				{
				if((qxn1==pxcomp1 && qyn1==pycomp1))
				{
				
				}
				else
				{
				XDrawLine(display_ptr, win, gc_dot, qxn1*4 , qyn1*4 ,txn1*4, tyn1*4);
				int h;
				int dot;
				dot=0;
					for(h=0;h<orgcnt;h++)
					{
				
						if(cxn1==vis1[h][0] && cyn1==vis1[h][1])
						{
						dot++;
						}
						else
						{
						}

					}	


					if(dot>0)
					{
					vchgx=0;
					vchgy=0;

					}
					else
					{
					vchgx=cxn1;
					vchgy=cyn1;
					}
				
				if(incr_last==1)
				{					
				fndvrls[incr_last][found_ls][0]=qxn1;
				fndvrls[incr_last][found_ls][1]=qyn1;
				fndvrls[incr_last][found_ls][2]=txn1;
				fndvrls[incr_last][found_ls][3]=tyn1;
				fndvrls[incr_last][found_ls][4]=cxn1;
				fndvrls[incr_last][found_ls][5]=cyn1;				
				fndvrls[incr_last][found_ls][6]=dxn1;
				fndvrls[incr_last][found_ls][7]=dyn1;				
				fndvrls[incr_last][found_ls][8]=exn1;
				fndvrls[incr_last][found_ls][9]=eyn1;				
				fndvrls[incr_last][found_ls][10]=vchgx;
				fndvrls[incr_last][found_ls][11]=vchgy;
				fndvrls[incr_last][found_ls][12]=xstrt;
				fndvrls[incr_last][found_ls][13]=ystrt;
				
				found_ls++;
				}
				else if(incr_last==2)
				{
				fndvrls[incr_last][found_l2s][0]=qxn1;
				fndvrls[incr_last][found_l2s][1]=qyn1;
				fndvrls[incr_last][found_l2s][2]=txn1;
				fndvrls[incr_last][found_l2s][3]=tyn1;
				fndvrls[incr_last][found_l2s][4]=cxn1;
				fndvrls[incr_last][found_l2s][5]=cyn1;				
				fndvrls[incr_last][found_l2s][6]=dxn1;
				fndvrls[incr_last][found_l2s][7]=dyn1;				
				fndvrls[incr_last][found_l2s][8]=exn1;
				fndvrls[incr_last][found_l2s][9]=eyn1;				
				fndvrls[incr_last][found_l2s][10]=vchgx;
				fndvrls[incr_last][found_l2s][11]=vchgy;
				fndvrls[incr_last][found_l2s][12]=xstrt;
				fndvrls[incr_last][found_l2s][13]=ystrt;
				
				found_l2s++;

				}
				else if(incr_last==3)
				{
				fndvrls[incr_last][found_l3s][0]=qxn1;
				fndvrls[incr_last][found_l3s][1]=qyn1;
				fndvrls[incr_last][found_l3s][2]=txn1;
				fndvrls[incr_last][found_l3s][3]=tyn1;
				fndvrls[incr_last][found_l3s][4]=cxn1;
				fndvrls[incr_last][found_l3s][5]=cyn1;				
				fndvrls[incr_last][found_l3s][6]=dxn1;
				fndvrls[incr_last][found_l3s][7]=dyn1;				
				fndvrls[incr_last][found_l3s][8]=exn1;
				fndvrls[incr_last][found_l3s][9]=eyn1;				
				fndvrls[incr_last][found_l3s][10]=vchgx;
				fndvrls[incr_last][found_l3s][11]=vchgy;
				fndvrls[incr_last][found_l3s][12]=xstrt;
				fndvrls[incr_last][found_l3s][13]=ystrt;
				
				found_l3s++;

				}
				else if(incr_last==4)
				{
				fndvrls[incr_last][found_10][0]=qxn1;
				fndvrls[incr_last][found_10][1]=qyn1;
				fndvrls[incr_last][found_10][2]=txn1;
				fndvrls[incr_last][found_10][3]=tyn1;
				fndvrls[incr_last][found_10][4]=cxn1;
				fndvrls[incr_last][found_10][5]=cyn1;				
				fndvrls[incr_last][found_10][6]=dxn1;
				fndvrls[incr_last][found_10][7]=dyn1;				
				fndvrls[incr_last][found_10][8]=exn1;
				fndvrls[incr_last][found_10][9]=eyn1;				
				fndvrls[incr_last][found_10][10]=vchgx;
				fndvrls[incr_last][found_10][11]=vchgy;
				fndvrls[incr_last][found_10][12]=xstrt;
				fndvrls[incr_last][found_10][13]=ystrt;
				
				found_10++;

				}


				}//closing else

				}//closing else-if

			



		   }

		}//closing the big if
		
		else
		{

		}

	     }//edn for loop close





	}//else loop of edn


}


}
}



}
if(incr_last==1)
{	
	for(i=0;i<found_ls;i++)
	{
find(vis1,orcnt,fndvrls[1][i][0],fndvrls[1][i][1],fndvrls[1][i][2],fndvrls[1][i][3],fndvrls[1][i][4],fndvrls[1][i][5],fndvrls[1][i][6],fndvrls[1][i][7],fndvrls[1][i][8],fndvrls[1][i][9],fndvrls[1][i][10],fndvrls[1][i][11],fndvrls[1][i][12],fndvrls[1][i][13]);

	}

}

if(incr_last==2)
{	
	for(i=0;i<found_l2s;i++)
	{
	

find(vis1,orcnt,fndvrls[2][i][0],fndvrls[2][i][1],fndvrls[2][i][2],fndvrls[2][i][3],fndvrls[2][i][4],fndvrls[2][i][5],fndvrls[2][i][6],fndvrls[2][i][7],fndvrls[2][i][8],fndvrls[2][i][9],fndvrls[2][i][10],fndvrls[2][i][11],fndvrls[2][i][12],fndvrls[2][i][13]);

	}

}

if(incr_last==3)
{	
	
	for(i=0;i<found_l3s;i++)
	{
	

find(vis1,orcnt,fndvrls[3][i][0],fndvrls[3][i][1],fndvrls[3][i][2],fndvrls[3][i][3],fndvrls[3][i][4],fndvrls[3][i][5],fndvrls[3][i][6],fndvrls[3][i][7],fndvrls[3][i][8],fndvrls[3][i][9],fndvrls[3][i][10],fndvrls[3][i][11],fndvrls[3][i][12],fndvrls[3][i][13]);

	}


}

if(incr_last==4)
{	
	
	for(i=0;i<found_10;i++)
	{
	

find(vis1,orcnt,fndvrls[4][i][0],fndvrls[4][i][1],fndvrls[4][i][2],fndvrls[4][i][3],fndvrls[4][i][4],fndvrls[4][i][5],fndvrls[4][i][6],fndvrls[4][i][7],fndvrls[4][i][8],fndvrls[4][i][9],fndvrls[4][i][10],fndvrls[4][i][11],fndvrls[4][i][12],fndvrls[4][i][13]);

	}

}



}

else
{
//printf("\n USUAL SAMESAME same same same side \n");
printf("new starting point %d,%d\n",xsnew,ysnew);
printf("i-1 %d,%d\n",cxn1,cyn1);
printf("i+1 %d,%d\n",dxn1,dyn1);

flag1=0;
incrsa++;
while(vis1[l][0]!=xsnew || vis1[l][1]!=ysnew)
{
  
	if(flag1==0)
	{
	flag1=flag1+3;
	l--;
	}
	else if(l==0)
	{
	
	flag1++;
	l=orgcnt-1;
	
	}
	else
	{
	
	flag1++;
	l--;
	
	
	}
  
   
}

double vertex1[flag1][2];
k=1;
while(vis1[chv][0]!=xsnew || vis1[chv][1]!=ysnew)
{

vertex1[0][0]=pxn1;
vertex1[0][1]=pyn1;

if(k==1)
{
vertex1[1][0]=vis1[chv][0];
vertex1[1][1]=vis1[chv][1];
}
else
{
vertex1[k][0]=vis1[chv][0];
vertex1[k][1]=vis1[chv][1];
}

if(chv==0)
{
chv=orgcnt-1;
k++;
}
else
{
chv--;
k++;
}

}
vertex1[k][0]=vis1[chv][0];
vertex1[k][1]=vis1[chv][1];

int kk;
for(kk=0;kk<flag1;kk++)
{
    xstrt=xsnew;
    ystrt=ysnew;
    qxn1=vertex1[kk][0];
    qyn1=vertex1[kk][1];


int edg;
for(edg=0;edg<flag1;edg++)
{

if(edg<flag1-1)
{
or1=(qxn1*vertex1[edg+1][1])+(xstrt*qyn1)+(ystrt*vertex1[edg+1][0]) -(vertex1[edg+1][0]*qyn1)-(xstrt*vertex1[edg+1][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*qxn1)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*qxn1)-(vertex1[edg+1][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[edg+1][0]*vertex1[edg][1])+(vertex1[edg+1][1]*xstrt)-(vertex1[edg][0]*vertex1[edg+1][1])-(vertex1[edg][1]*xstrt)-(vertex1[edg+1][0]*ystrt);
}
else
{
or1=(qxn1*vertex1[0][1])+(xstrt*qyn1)+(ystrt*vertex1[0][0]) -(vertex1[0][0]*qyn1)-(xstrt*vertex1[0][1])-(ystrt*qxn1);
or2=(qxn1*vertex1[edg][1])+(xstrt*qyn1)+(ystrt*vertex1[edg][0]) -(vertex1[edg][0]*qyn1)-(xstrt*vertex1[edg][1])-(ystrt*qxn1);
	
or3=(vertex1[edg][0]*qyn1)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*qxn1)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*qxn1)-(vertex1[0][0]*qyn1);
or4=(vertex1[edg][0]*ystrt)+(vertex1[0][0]*vertex1[edg][1])+(vertex1[0][1]*xstrt)-(vertex1[edg][0]*vertex1[0][1])-(vertex1[edg][1]*xstrt)-(vertex1[0][0]*ystrt);

}

if((or3*or4)<0 && (or1*or2)<0)
    {
	
		break;
    }
else if(edg==flag1-1)	
{
int c,t;
t=0;
for(c=0;c<orgcnt;c++)
{
if(xstrt==vis1[c][0] && ystrt==vis1[c][1])
{
t=c;
}
else
{
}
}

distchx=(vis1[t][0]-vis1[t+1][0]);
distchy=(vis1[t][1]-vis1[t+1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);


chplx=(vis1[t+1][0]-vis1[t][0])/distch;
chply=(vis1[t+1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-vis1[t-1][0]);
distchy=(vis1[t][1]-vis1[t-1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chmx=(vis1[t-1][0]-vis1[t][0])/distch;
chmy=(vis1[t-1][1]-vis1[t][1])/distch;

distchx=(vis1[t][0]-qxn1);
distchy=(vis1[t][1]-qyn1);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chqx=(qxn1-vis1[t][0])/distch;
chqy=(qyn1-vis1[t][1])/distch;

orch=(chmx*chqy)-(chqx*chmy)-(chplx*chqy)+(chplx*chmy)+(chply*chqx)-(chply*chmx);

if(((vis1[t+1][0]==qxn1) && (vis1[t+1][1]==qyn1)) || ((vis1[t-1][0]==qxn1) && (vis1[t-1][1]==qyn1)))
{
orch=0.2;
}


oreint=0;
for(f=0;f<orgcnt-1;f++)
{

oreint1=(qxn1*vis1[f][1])-(vis1[f][0]*qyn1)-(vis1[t][0]*vis1[f][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f][0])-(vis1[t][1]*qxn1);

oreint2=(qxn1*vis1[f+1][1])-(vis1[f+1][0]*qyn1)-(vis1[t][0]*vis1[f+1][1])+(vis1[t][0]*qyn1)+(vis1[t][1]*vis1[f+1][0])-(vis1[t][1]*qxn1);

oreint3=(vis1[f+1][0]*qyn1)-(qxn1*vis1[f+1][1])-(vis1[f][0]*qyn1)+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*qxn1)-(vis1[f][1]*vis1[f+1][0]);

oreint4=(vis1[f+1][0]*vis1[t][1])-(vis1[t][0]*vis1[f+1][1])-(vis1[f][0]*vis1[t][1])+(vis1[f][0]*vis1[f+1][1])+(vis1[f][1]*vis1[t][0])-(vis1[f][1]*vis1[f+1][0]);

if((oreint1*oreint2)<0 && (oreint3*oreint4)<0)
{
oreint++;
break;
}
else
{
}

}

if(orch<0 || oreint>0)
{
break;
}
else
{

//XDrawLine(display_ptr, win, gc_red, xstrt*4 , ystrt*4 ,qxn1*4,qyn1*4);
        distx=(qxn1-xstrt)*(qxn1-xstrt);
	disty=(qyn1-ystrt)*(qyn1-ystrt);
	dist=distx+disty;
	dist=sqrt(dist);
         
	//find xnew , qnew and ttx,tty
	xt=xstrt+(xstrt-qxn1)/dist*10;
	yt=ystrt+(ystrt-qyn1)/dist*10;

	xx=qxn1+(qxn1-xstrt)/dist*50;
	yy=qyn1+(qyn1-ystrt)/dist*50;

//XDrawLine(display_ptr, win, gc_red, qxn1*4 , qyn1*4 ,xx*4,yy*4);
if(kk<flag1-1)
{
edxn1=vertex1[kk+1][0];
edyn1=vertex1[kk+1][1];
exn1=vertex1[kk-1][0];
eyn1=vertex1[kk-1][1];
}
else
{
edxn1=vertex1[0][0];
edyn1=vertex1[0][1];
exn1=vertex1[kk][0];
eyn1=vertex1[kk][1];
}
eo1n1=(xt*edyn1)-(yt*edxn1)-(xx*edyn1)+(xx*yt)+(yy*edxn1)-(yy*xt);
eo2n1=(xt*eyn1)-(yt*exn1)-(xx*eyn1)+(xx*yt)+(yy*exn1)-(yy*xt);
if(eo1n1>-0.1 && eo1n1<0.1)
{
eo1n1=-1.0;
}



double ee;
ee=eo1n1*eo2n1;
        if((ee)<0)
	{
	
	break;
	}
	else
	{   
	
	    int edn1;
	    for(edn1=0;edn1<flag1;edn1++)
	    {				
		//printf("\nenetering to find the point\n");
		// first line
			axn=qxn1;
			ayn=qyn1;
			bxn=xx;
			byn=yy;
		// second line 
			if(edn1<flag1-1)
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[edn1+1][0];
			dyn1=vertex1[edn1+1][1];
			}
			else
			{
			cxn1=vertex1[edn1][0];
			cyn1=vertex1[edn1][1];
			dxn1=vertex1[0][0];
			dyn1=vertex1[0][1];
			}
	    

	xr1=(bxn*cyn1)-(cxn1*byn)-(axn*cyn1)+(axn*byn)+(ayn*cxn1)-(ayn*bxn);
	xr2=(bxn*dyn1)-(dxn1*byn)-(axn*dyn1)+(axn*byn)+(ayn*dxn1)-(ayn*bxn);

	xr3=(dxn1*ayn)-(axn*dyn1)-(cxn1*ayn)+(cxn1*dyn1)+(cyn1*axn)-(cyn1*dxn1);
	xr4=(dxn1*byn)-(bxn*dyn1)-(cxn1*byn)+(cxn1*dyn1)+(cyn1*bxn)-(cyn1*dxn1);
	
		
	
		if( ((xr1*xr2)<0 && (xr3*xr4)<0))
		 {
		 
			 
	  		//printf("\nintersectig this one\n");
			san1=(bxn-axn)*(cyn1-ayn)-(byn-ayn)*(cxn1-axn);
			sbn1=(bxn-axn)*(cyn1-dyn1)-(byn-ayn)*(cxn1-dxn1);

			sn1=san1/sbn1;

			
			//the intersection points on the edge1 of polygon are tx,ty

				txn1=cxn1+sn1*(dxn1-cxn1);
				tyn1=cyn1+sn1*(dyn1-cyn1);
		  int j;
		  for(j=0;j<flag1;j++)
		  {
			
			if(j<flag1-1)
			{						
    pr1=(qxn1*vertex1[j+1][1])-(vertex1[j+1][0]*qyn1)-(txn1*vertex1[j+1][1])+(txn1*qyn1)+(tyn1*vertex1[j+1][0])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])-(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0])-(tyn1*qxn1);

    pr3=(vertex1[j][0]*qyn1)-(vertex1[j][1]*qxn1)-(vertex1[j+1][0]*qyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*qxn1)-(vertex1[j][0]*vertex1[j+1][1]);
    pr4=(vertex1[j][0]*tyn1)-(vertex1[j][1]*txn1)-(vertex1[j+1][0]*tyn1)+(vertex1[j+1][0]*vertex1[j][1])+(vertex1[j+1][1]*txn1)-(vertex1[j][0]*vertex1[j+1][1]);		
			}

			else
			{
    pr1=(qxn1*vertex1[0][1])-(vertex1[0][0]*qyn1)-(txn1*vertex1[0][1])+(txn1*qyn1)+(tyn1*vertex1[0][0])-(tyn1*qxn1);
    pr2=(qxn1*vertex1[j][1])-(vertex1[j][0]*qyn1)-(txn1*vertex1[j][1])+(txn1*qyn1)+(tyn1*vertex1[j][0])-(tyn1*qxn1);

    pr3=(vertex1[j][0]*qyn1)-(vertex1[j][1]*qxn1)-(vertex1[0][0]*qyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*qxn1)-(vertex1[j][0]*vertex1[0][1]);
    pr4=(vertex1[j][0]*tyn1)-(vertex1[j][1]*txn1)-(vertex1[0][0]*tyn1)+(vertex1[0][0]*vertex1[j][1])+(vertex1[0][1]*txn1)-(vertex1[j][0]*vertex1[0][1]);		
}

/*
if(pr4>-0.1 && pr4<0.1)
{
pr4=-1.0;
}
*/





				if((pr3*pr4)<0 && (pr1*pr2)<0)
				{
				//printf("\n there is an edge1 intersecting this line \n");
				break;
				}
				else if(j==flag1-1)
				{
				if((qxn1==pxcomp1 && qyn1==pycomp1))
				{
				
				}
				else
				{
		XDrawLine(display_ptr, win, gc_dot, qxn1*4 , qyn1*4 ,txn1*4, tyn1*4);
				int h;
				int dot;
				dot=0;
					for(h=0;h<orgcnt;h++)
					{
				
						if(cxn1==vis1[h][0] && cyn1==vis1[h][1])
						{
						dot++;
						}
						else
						{
						
						}

					}	


					if(dot>0)
					{
					vchgx=0;
					vchgy=0;

					}
					else
					{
					vchgx=cxn1;
					vchgy=cyn1;
					}

				if(incrsa==1)
				{	
				fndsa[incrsa][found_sa][0]=qxn1;
				fndsa[incrsa][found_sa][1]=qyn1;
				fndsa[incrsa][found_sa][2]=txn1;
				fndsa[incrsa][found_sa][3]=tyn1;
				fndsa[incrsa][found_sa][4]=cxn1;
				fndsa[incrsa][found_sa][5]=cyn1;				
				fndsa[incrsa][found_sa][6]=dxn1;
				fndsa[incrsa][found_sa][7]=dyn1;				
				fndsa[incrsa][found_sa][8]=exn1;
				fndsa[incrsa][found_sa][9]=eyn1;				
				fndsa[incrsa][found_sa][10]=vchgx;
				fndsa[incrsa][found_sa][11]=vchgy;
				fndsa[incrsa][found_sa][12]=xstrt;
				fndsa[incrsa][found_sa][13]=ystrt;
				
				found_sa++;
				}
				else if(incrsa==2)
				{
				
				fndsa[incrsa][found_sa2][0]=qxn1;
				fndsa[incrsa][found_sa2][1]=qyn1;
				fndsa[incrsa][found_sa2][2]=txn1;
				fndsa[incrsa][found_sa2][3]=tyn1;
				fndsa[incrsa][found_sa2][4]=cxn1;
				fndsa[incrsa][found_sa2][5]=cyn1;				
				fndsa[incrsa][found_sa2][6]=dxn1;
				fndsa[incrsa][found_sa2][7]=dyn1;				
				fndsa[incrsa][found_sa2][8]=exn1;
				fndsa[incrsa][found_sa2][9]=eyn1;				
				fndsa[incrsa][found_sa2][10]=vchgx;
				fndsa[incrsa][found_sa2][11]=vchgy;
				fndsa[incrsa][found_sa2][12]=xstrt;
				fndsa[incrsa][found_sa2][13]=ystrt;

				found_sa2++;
				}
				else if(incrsa==3)
				{
				
				fndsa[incrsa][found_11][0]=qxn1;
				fndsa[incrsa][found_11][1]=qyn1;
				fndsa[incrsa][found_11][2]=txn1;
				fndsa[incrsa][found_11][3]=tyn1;
				fndsa[incrsa][found_11][4]=cxn1;
				fndsa[incrsa][found_11][5]=cyn1;				
				fndsa[incrsa][found_11][6]=dxn1;
				fndsa[incrsa][found_11][7]=dyn1;				
				fndsa[incrsa][found_11][8]=exn1;
				fndsa[incrsa][found_11][9]=eyn1;				
				fndsa[incrsa][found_11][10]=vchgx;
				fndsa[incrsa][found_11][11]=vchgy;
				fndsa[incrsa][found_11][12]=xstrt;
				fndsa[incrsa][found_11][13]=ystrt;

				found_11++;
				}






				}//closing else

				}//closing else-if

			



		   }

		}//closing the big if
		
		else
		{

		}

	     }//edn for loop close


	}//else loop of edn

}

}//closing first else if

// 2nd last
}
///last one
}
}
///********************

if(incrsa==1)
{	
	for(i=0;i<found_sa;i++)
	{
	

find(vis1,orcnt,fndsa[1][i][0],fndsa[1][i][1],fndsa[1][i][2],fndsa[1][i][3],fndsa[1][i][4],fndsa[1][i][5],fndsa[1][i][6],fndsa[1][i][7],fndsa[1][i][8],fndsa[1][i][9],fndsa[1][i][10],fndsa[1][i][11],fndsa[1][i][12],fndsa[1][i][13]);

	}

}

if(incrsa==2)
{	
	for(i=0;i<found_sa2;i++)
	{
find(vis1,orcnt,fndsa[2][i][0],fndsa[2][i][1],fndsa[2][i][2],fndsa[2][i][3],fndsa[2][i][4],fndsa[2][i][5],fndsa[2][i][6],fndsa[2][i][7],fndsa[2][i][8],fndsa[2][i][9],fndsa[2][i][10],fndsa[2][i][11],fndsa[2][i][12],fndsa[2][i][13]);

	}

}

/*
if(incrsa==3)
{	
	for(i=0;i<found_11;i++)
	{
	
find(vis1,orcnt,fndsa[3][i][0],fndsa[3][i][1],fndsa[3][i][2],fndsa[3][i][3],fndsa[3][i][4],fndsa[3][i][5],fndsa[3][i][6],fndsa[3][i][7],fndsa[3][i][8],fndsa[3][i][9],fndsa[3][i][10],fndsa[3][i][11],fndsa[3][i][12],fndsa[3][i][13]);

	}
}
*/
}
}

void find_visiblity(double vis[][2],int count,double qxnew,double qynew,double pxn,double pyn,int pkx,int pky,int pk1x,int pk1y,int i1x,int i1y,int ix,int iy,int edge,int x,int y)
{
double oreint1;
double oreint2;
double oreint3,oreint4;
int f;
int oreint;
int edn;
int flag,k;
int edxn,edyn,exn,eyn;
double eo1n,eo2n;
int i,edd;

double distch,distchx,distchy;
double chplx,chply,chmx,chmy,chqx,chqy;
double orch;

double qxn,qyn;
double txn,tyn,san,sbn,sn;
double axn,ayn,bxn,byn;
double cxn,cyn,dxn,dyn;
double pxcomp,pycomp;

pxcomp=pxn;
pycomp=pyn;
edd=edge;
int found;
found=0;
double fndver[30][12];
int found1;
found1=0;
double fndver2[40][12];

or1=(x*cy)-(y*cx)-(px*cy)+(px*y)+(py*cx)-(py*x);
or2=(x*edy)-(y*edx)-(px*edy)+(px*y)+(py*edx)-(py*x);


if(or1*or2<0)
{
flag=0;
while(vis[edd][0]!=qxnew || vis[edd][1]!=qynew)
{
	if(flag==0)
	{
	flag=flag+2;
	if(edd==count-1)
	{
	edd==0;
	flag--;
	}
	else
	{
	edd++;
	}	
	}
	else if(edd==count-1)
	{
	
	flag++;
	edd=0;
	}
	else
	{
	flag++;
	edd++;
	
	}
	
}
k=1;
double vertex[flag][2];
while(vis[edge][0]!=qxnew || vis[edge][1]!=qynew)
{
vertex[0][0]=pxn;
vertex[0][1]=pyn;
if(k==1)
{
if(ed==count-1)
{
edge=0;
vertex[1][0]=vis[edge][0];
vertex[1][1]=vis[edge][1];
}
else
{
vertex[1][0]=vis[edge+1][0];
vertex[1][1]=vis[edge+1][1];
edge++;
}
}
else if(edge==count-1)
{
vertex[k][0]=vis[edge][0];
vertex[k][1]=vis[edge][1];

}
else
{
vertex[k][0]=vis[edge][0];
vertex[k][1]=vis[edge][1];

}

if(edge==count-1)
{
edge=0;
k++;
}
else
{
edge++;
k++;
}

}
if(vis[edge][0]==qxnew && vis[edge][1]==qynew)
{
vertex[k][0]=qxnew;
vertex[k][1]=qynew;
					
}




int kk;
for(kk=0;kk<flag;kk++)
{
    xstart=qxnew;
    ystart=qynew;
    qxn=vertex[kk][0];
    qyn=vertex[kk][1];
int edg;
for(edg=0;edg<flag;edg++)
{

if(edg<flag-1)
{
or1=(qxn*vertex[edg+1][1])+(xstart*qyn)+(ystart*vertex[edg+1][0]) -(vertex[edg+1][0]*qyn)-(xstart*vertex[edg+1][1])-(ystart*qxn);
or2=(qxn*vertex[edg][1])+(xstart*qyn)+(ystart*vertex[edg][0]) -(vertex[edg][0]*qyn)-(xstart*vertex[edg][1])-(ystart*qxn);
	
or3=(vertex[edg][0]*qyn)+(vertex[edg+1][0]*vertex[edg][1])+(vertex[edg+1][1]*qxn)-(vertex[edg][0]*vertex[edg+1][1])-(vertex[edg][1]*qxn)-(vertex[edg+1][0]*qyn);
or4=(vertex[edg][0]*ystart)+(vertex[edg+1][0]*vertex[edg][1])+(vertex[edg+1][1]*xstart)-(vertex[edg][0]*vertex[edg+1][1])-(vertex[edg][1]*xstart)-(vertex[edg+1][0]*ystart);
}
else
{

or1=(qxn*vertex[0][1])+(xstart*qyn)+(ystart*vertex[0][0]) -(vertex[0][0]*qyn)-(xstart*vertex[0][1])-(ystart*qxn);
or2=(qxn*vertex[edg][1])+(xstart*qyn)+(ystart*vertex[edg][0]) -(vertex[edg][0]*qyn)-(xstart*vertex[edg][1])-(ystart*qxn);
	
or3=(vertex[edg][0]*qyn)+(vertex[0][0]*vertex[edg][1])+(vertex[0][1]*qxn)-(vertex[edg][0]*vertex[0][1])-(vertex[edg][1]*qxn)-(vertex[0][0]*qyn);
or4=(vertex[edg][0]*ystart)+(vertex[0][0]*vertex[edg][1])+(vertex[0][1]*xstart)-(vertex[edg][0]*vertex[0][1])-(vertex[edg][1]*xstart)-(vertex[0][0]*ystart);

}

if((or3*or4)<0 && (or1*or2)<0)
    {
	
	break;
    }
else if(edg==flag-1)	
{
int c,t;
t=0;
for(c=0;c<count;c++)
{
if(xstart==vis[c][0] && ystart==vis[c][1])
{
t=c;
}
else
{
}
}

distchx=(vis[t][0]-vis[t+1][0]);
distchy=(vis[t][1]-vis[t+1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);


chplx=(vis[t+1][0]-vis[t][0])/distch;
chply=(vis[t+1][1]-vis[t][1])/distch;

distchx=(vis[t][0]-vis[t-1][0]);
distchy=(vis[t][1]-vis[t-1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chmx=(vis[t-1][0]-vis[t][0])/distch;
chmy=(vis[t-1][1]-vis[t][1])/distch;

distchx=(vis[t][0]-qxn);
distchy=(vis[t][1]-qyn);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chqx=(qxn-vis[t][0])/distch;
chqy=(qyn-vis[t][1])/distch;

orch=(chmx*chqy)-(chqx*chmy)-(chplx*chqy)+(chplx*chmy)+(chply*chqx)-(chply*chmx);

oreint=0;
for(f=0;f<count-1;f++)
{

oreint1=(qxn*vis[f][1])-(vis[f][0]*qyn)-(vis[t][0]*vis[f][1])+(vis[t][0]*qyn)+(vis[t][1]*vis[f][0])-(vis[t][1]*qxn);

oreint2=(qxn*vis[f+1][1])-(vis[f+1][0]*qyn)-(vis[t][0]*vis[f+1][1])+(vis[t][0]*qyn)+(vis[t][1]*vis[f+1][0])-(vis[t][1]*qxn);

oreint3=(vis[f+1][0]*qyn)-(qxn*vis[f+1][1])-(vis[f][0]*qyn)+(vis[f][0]*vis[f+1][1])+(vis[f][1]*qxn)-(vis[f][1]*vis[f+1][0]);

oreint4=(vis[f+1][0]*vis[t][1])-(vis[t][0]*vis[f+1][1])-(vis[f][0]*vis[t][1])+(vis[f][0]*vis[f+1][1])+(vis[f][1]*vis[t][0])-(vis[f][1]*vis[f+1][0]);

if((oreint1*oreint2)<0 && (oreint3*oreint4)<0)
{
oreint++;
break;
}
else
{
}

}

if(orch<0 || oreint>0)
{
break;
}
else
{
	distx=(qxn-xstart)*(qxn-xstart);
	disty=(qyn-ystart)*(qyn-ystart);
	dist=distx+disty;
	dist=sqrt(dist);
	xt=xstart+(xstart-qxn)/dist*30;
	yt=ystart+(ystart-qyn)/dist*30;

	xx=qxn+(qxn-xstart)/dist*100;
	yy=qyn+(qyn-ystart)/dist*100;
//XDrawLine(display_ptr, win, gc_red, qxn*4 , qyn*4 ,xstart*4, ystart*4);
//XDrawLine(display_ptr, win, gc_yellow, qxn*4 , qyn*4 ,xx*4, yy*4);

if(kk<flag)
{
edxn=vertex[kk+1][0];
edyn=vertex[kk+1][1];
exn=vertex[kk-1][0];
eyn=vertex[kk-1][1];
}
else
{
edxn=vertex[0][0];
edyn=vertex[0][1];
exn=vertex[kk-1][0];
eyn=vertex[kk-1][1];
}
eo1n=(xt*edyn)-(yt*edxn)-(xx*edyn)+(xx*yt)+(yy*edxn)-(yy*xt);
eo2n=(xt*eyn)-(yt*exn)-(xx*eyn)+(xx*yt)+(yy*exn)-(yy*xt);
if(eo1n>-0.1 && eo1n<0.1)
{
eo1n=1.0;
}
else if(eo2n>-0.1 && eo2n<0.1)
{
eo2n=1.0;
}
double eoo;
eoo=eo1n*eo2n;
if(eoo<0)
	{

	break;
	}
	else
	{
	
	for(edn=0;edn<flag-1;edn++)
	    {
		// first line
			axn=qxn;
			ayn=qyn;
			bxn=xx;
			byn=yy;
		// second line 
			if(edn<flag-1)
			{
			cxn=vertex[edn][0];
			cyn=vertex[edn][1];
			dxn=vertex[edn+1][0];
			dyn=vertex[edn+1][1];
			}
			else
			{
			cxn=vertex[edn][0];
			cyn=vertex[edn][1];
			dxn=vertex[0][0];
			dyn=vertex[0][1];
			}
	xr1=(bxn*cyn)-(cxn*byn)-(axn*cyn)+(axn*byn)+(ayn*cxn)-(ayn*bxn);
	xr2=(bxn*dyn)-(dxn*byn)-(axn*dyn)+(axn*byn)+(ayn*dxn)-(ayn*bxn);

	xr3=(dxn*ayn)-(axn*dyn)-(cxn*ayn)+(cxn*dyn)+(cyn*axn)-(cyn*dxn);
	xr4=(dxn*byn)-(bxn*dyn)-(cxn*byn)+(cxn*dyn)+(cyn*bxn)-(cyn*dxn);
	
	if( ((xr1*xr2)<0 && (xr3*xr4)<0))
		 		{
//		   		printf("\nintersecting line is there\n");
			
			san=(bxn-axn)*(cyn-ayn)-(byn-ayn)*(cxn-axn);
			sbn=(bxn-axn)*(cyn-dyn)-(byn-ayn)*(cxn-dxn);

			sn=san/sbn;

			
			//the intersection points on the edge of polygon are tx,ty

				txn=cxn+sn*(dxn-cxn);
				tyn=cyn+sn*(dyn-cyn);

		//XDrawLine(display_ptr, win, gc_dot, qxn , qyn ,txn, tyn);

		for(j=0;j<flag;j++)
			{
			
if(j<flag-1)									
{
		/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn*vertex[j+1][1])-(vertex[j+1][0]*qyn)-(txn*vertex[j+1][1])+(txn*qyn)+(tyn*vertex[j+1][0])-(tyn*qxn);
    pr2=(qxn*vertex[j][1])-(vertex[j][0]*qyn)-(txn*vertex[j][1])+(txn*qyn)+(tyn*vertex[j][0])-(tyn*qxn);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex[j+1][0]*qyn)-(vertex[j+1][1]*qxn)-(vertex[j][0]*qyn)+(vertex[j][0]*vertex[j+1][1])+(vertex[j][1]*qxn)-(vertex[j][1]*vertex[j+1][0]);
 pr4=(vertex[j+1][0]*tyn)-(vertex[j+1][1]*txn)-(vertex[j][0]*tyn)+(vertex[j][0]*vertex[j+1][1])+(vertex[j][1]*txn)-(vertex[j][1]*vertex[j+1][0]);			
}
else
{

		/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn*vertex[j+1][1])-(vertex[0][0]*qyn)-(txn*vertex[0][1])+(txn*qyn)+(tyn*vertex[0][0])-(tyn*qxn);
    pr2=(qxn*vertex[j][1])-(vertex[j][0]*qyn)-(txn*vertex[j][1])+(txn*qyn)+(tyn*vertex[j][0])-(tyn*qxn);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex[0][0]*qyn)-(vertex[0][1]*qxn)-(vertex[j][0]*qyn)+(vertex[j][0]*vertex[0][1])+(vertex[j][1]*qxn)-(vertex[j][1]*vertex[0][0]);
 pr4=(vertex[0][0]*tyn)-(vertex[0][1]*txn)-(vertex[j][0]*tyn)+(vertex[j][0]*vertex[0][1])+(vertex[j][1]*txn)-(vertex[j][1]*vertex[0][0]);			

}


if(pr4>-0.1 && pr4<0.1)
{
pr4=-1.0;
}
else if(pr3>-0.1 && pr3<0.1)
{
pr3=-1.0;
}
else if(pr2>-0.1 && pr2<0.1)
{
pr2=-1.0;
}
else if(pr1>-0.1 && pr1<0.1)
{
pr1=-1.0;
}


				if((pr3*pr4)<0 && (pr1*pr2)<0)
				{

				break;
				}
				else if((j==flag-1))
				{
				
				if((qxn==pxcomp && qyn==pycomp))
				{
				}
				else
				{

			XDrawLine(display_ptr, win, gc_dot, qxn*4 , qyn*4 ,txn*4, tyn*4);
				int h;
				int dot;
				dot=0;
				for(h=0;h<count;h++)
				{
				
				if(cxn==vis[h][0] && cyn==vis[h][1])
				{
				dot++;
				}
				else
				{
				//dot=0;
				}
				}
				if(dot>0)
				{
				chargx=0.0;
				chargy=0.0;
				
				}	
				else if(dot==0)
				{
				
				chargy=cyn;
				chargx=cxn;
			
				}		
				
				fndver2[found1][0]=qxn;
				fndver2[found1][1]=qyn;
				fndver2[found1][2]=txn;
				fndver2[found1][3]=tyn;
				fndver2[found1][4]=cxn;
				fndver2[found1][5]=cyn;				
				fndver2[found1][6]=dxn;
				fndver2[found1][7]=dyn;				
				fndver2[found1][8]=exn;
				fndver2[found1][9]=eyn;				
				fndver2[found1][10]=chargx;
				fndver2[found1][11]=chargy;
				found1++;

				
				}
				}
				
				
			}
			
			}
			else
			{
			}		



	
          }
	

}
}
}
}






}

int i;
for(i=0;i<found1;i++)
{
find(vis,count,fndver2[i][0],fndver2[i][1],fndver2[i][2],fndver2[i][3],fndver2[i][4],fndver2[i][5],fndver2[i][6],fndver2[i][7],fndver2[i][8],fndver2[i][9],fndver2[i][10],fndver2[i][11],xstart,ystart);

}
}

else
{
flag=0;
while(vis[edd][0]!=qxnew || vis[edd][1]!=qynew)
{

	if(flag==0)
	{
	flag=flag+3;
	if(edd==0)
	{
	edd=0;
	flag--;	
	}
	else
	{
	edd--;
	
	}
	}
	else if(edd==0)
	{
	
	flag++;
	edd=count-1;
	
	}
	else
	{

	flag++;
	edd--;

	}

}

double vertex[flag][2];
k=1;
while(vis[edge][0]!=qxnew || vis[edge][1]!=qynew)
{

vertex[0][0]=pxn;
vertex[0][1]=pyn;

if(k==1)
{
vertex[1][0]=vis[edge][0];
vertex[1][1]=vis[edge][1];
}
else
{
vertex[k][0]=vis[edge][0];
vertex[k][1]=vis[edge][1];
}

if(edge==0)
{
edge=count-1;
k++;
}
else
{
edge--;
k++;
}

}

if(vis[edge][0]==qxnew && vis[edge][1]==qynew)
{
vertex[k][0]=qxnew;
vertex[k][1]=qynew;					
}
else
{
}



int kk;
for(kk=0;kk<flag;kk++)
{
    xstart=qxnew;
    ystart=qynew;
    qxn=vertex[kk][0];
    qyn=vertex[kk][1];

int edg;
for(edg=0;edg<flag;edg++)
{

if(edg<flag-1)
{
or1=(qxn*vertex[edg+1][1])+(xstart*qyn)+(ystart*vertex[edg+1][0]) -(vertex[edg+1][0]*qyn)-(xstart*vertex[edg+1][1])-(ystart*qxn);
or2=(qxn*vertex[edg][1])+(xstart*qyn)+(ystart*vertex[edg][0]) -(vertex[edg][0]*qyn)-(xstart*vertex[edg][1])-(ystart*qxn);
	
or3=(vertex[edg][0]*qyn)+(vertex[edg+1][0]*vertex[edg][1])+(vertex[edg+1][1]*qxn)-(vertex[edg][0]*vertex[edg+1][1])-(vertex[edg][1]*qxn)-(vertex[edg+1][0]*qyn);
or4=(vertex[edg][0]*ystart)+(vertex[edg+1][0]*vertex[edg][1])+(vertex[edg+1][1]*xstart)-(vertex[edg][0]*vertex[edg+1][1])-(vertex[edg][1]*xstart)-(vertex[edg+1][0]*ystart);
}
else
{
or1=(qxn*vertex[0][1])+(xstart*qyn)+(ystart*vertex[0][0]) -(vertex[0][0]*qyn)-(xstart*vertex[0][1])-(ystart*qxn);
or2=(qxn*vertex[edg][1])+(xstart*qyn)+(ystart*vertex[edg][0]) -(vertex[edg][0]*qyn)-(xstart*vertex[edg][1])-(ystart*qxn);
	
or3=(vertex[edg][0]*qyn)+(vertex[edg+1][0]*vertex[edg][1])+(vertex[0][1]*qxn)-(vertex[edg][0]*vertex[0][1])-(vertex[edg][1]*qxn)-(vertex[0][0]*qyn);
or4=(vertex[edg][0]*ystart)+(vertex[0][0]*vertex[edg][1])+(vertex[0][1]*xstart)-(vertex[edg][0]*vertex[0][1])-(vertex[edg][1]*xstart)-(vertex[0][0]*ystart);
}

if((or3*or4)<0 && (or1*or2)<0)
    {
	
	break;
    }
else if(edg==flag-1)	
{


int c,t;

for(c=0;c<count;c++)
{
if(xstart==vis[c][0] && ystart==vis[c][1])
{
t=c;
}
else
{
}
}
if(t==count-1)
{
distchx=(vis[t][0]-vis[0][0]);
distchy=(vis[t][1]-vis[0][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
}
else
{
distchx=(vis[t][0]-vis[t+1][0]);
distchy=(vis[t][1]-vis[t+1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
}

chplx=(vis[t+1][0]-vis[t][0])/distch;
chply=(vis[t+1][1]-vis[t][1])/distch;

distchx=(vis[t][0]-vis[t-1][0]);
distchy=(vis[t][1]-vis[t-1][1]);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chmx=(vis[t-1][0]-vis[t][0])/distch;
chmy=(vis[t-1][1]-vis[t][1])/distch;

distchx=(vis[t][0]-qxn);
distchy=(vis[t][1]-qyn);
distch=(distchx*distchx)+(distchy*distchy);
distch=sqrt(distch);
chqx=(qxn-vis[t][0])/distch;
chqy=(qyn-vis[t][1])/distch;

orch=(chmx*chqy)-(chqx*chmy)-(chplx*chqy)+(chplx*chmy)+(chply*chqx)-(chply*chmx);
if(((vis[t+1][0]==qxn) && (vis[t+1][1]==qyn)) || ((vis[t-1][0]==qxn) && (vis[t-1][1]==qyn)))
{
orch=0.2;
}

oreint=0;

for(f=0;f<count-1;f++)
{

oreint1=(qxn*vis[f][1])-(vis[f][0]*qyn)-(vis[t][0]*vis[f][1])+(vis[t][0]*qyn)+(vis[t][1]*vis[f][0])-(vis[t][1]*qxn);

oreint2=(qxn*vis[f+1][1])-(vis[f+1][0]*qyn)-(vis[t][0]*vis[f+1][1])+(vis[t][0]*qyn)+(vis[t][1]*vis[f+1][0])-(vis[t][1]*qxn);

oreint3=(vis[f+1][0]*qyn)-(qxn*vis[f+1][1])-(vis[f][0]*qyn)+(vis[f][0]*vis[f+1][1])+(vis[f][1]*qxn)-(vis[f][1]*vis[f+1][0]);

oreint4=(vis[f+1][0]*vis[t][1])-(vis[t][0]*vis[f+1][1])-(vis[f][0]*vis[t][1])+(vis[f][0]*vis[f+1][1])+(vis[f][1]*vis[t][0])-(vis[f][1]*vis[f+1][0]);

if((oreint1*oreint2)<0 && (oreint3*oreint4)<0)
{
oreint++;
break;
}
else
{
}

}


if(orch<0 || oreint>0 )
{
break;
}
else
{
	distx=(qxn-xstart)*(qxn-xstart);
	disty=(qyn-ystart)*(qyn-ystart);
	dist=distx+disty;
	dist=sqrt(dist);

	xt=xstart+(xstart-qxn)/dist*20;
	yt=ystart+(ystart-qyn)/dist*20;

	xx=qxn+(qxn-xstart)/dist*100;
	yy=qyn+(qyn-ystart)/dist*100;

//XDrawLine(display_ptr, win, gc_yellow ,xstart*4, ystart*4 , qxn*4 , qyn*4);
//XDrawLine(display_ptr, win, gc_yellow, qxn*4 , qyn*4 ,xx*4,yy*4);
	


if(kk<flag-1)
{
edxn=vertex[kk+1][0];
edyn=vertex[kk+1][1];
exn=vertex[kk-1][0];
eyn=vertex[kk-1][1];
}
else
{
edxn=vertex[0][0];
edyn=vertex[0][1];
exn=vertex[kk][0];
eyn=vertex[kk][1];

}


eo1n=(xt*edyn)-(yt*edxn)-(xx*edyn)+(xx*yt)+(yy*edxn)-(yy*xt);
eo2n=(xt*eyn)-(yt*exn)-(xx*eyn)+(xx*yt)+(yy*exn)-(yy*xt);
if(eo1n>-0.1 && eo1n<0.1)
{
eo1n=-1.0;
}
else if(eo2n>-0.1 && eo2n<0.1)
{
eo2n=-1.0;
}

double epro=eo1n*eo2n;
        if((epro<0))
	{
	break;
	}
	else
	{
	
	for(edn=0;edn<flag;edn++)
	    {
	
		// first line
			axn=qxn;
			ayn=qyn;
			bxn=xx;
			byn=yy;
		// second line 
			if(edn<flag-1)
			{
			cxn=vertex[edn][0];
			cyn=vertex[edn][1];
			dxn=vertex[edn+1][0];
			dyn=vertex[edn+1][1];

			}
			else
			{
			cxn=vertex[edn][0];
			cyn=vertex[edn][1];
			dxn=vertex[0][0];
			dyn=vertex[0][1];
			}
	
	xr1=(bxn*cyn)-(cxn*byn)-(axn*cyn)+(axn*byn)+(ayn*cxn)-(ayn*bxn);
	xr2=(bxn*dyn)-(dxn*byn)-(axn*dyn)+(axn*byn)+(ayn*dxn)-(ayn*bxn);

	xr3=(dxn*ayn)-(axn*dyn)-(cxn*ayn)+(cxn*dyn)+(cyn*axn)-(cyn*dxn);
	xr4=(dxn*byn)-(bxn*dyn)-(cxn*byn)+(cxn*dyn)+(cyn*bxn)-(cyn*dxn);
		
	
			if( ((xr1*xr2)<0.0 && (xr3*xr4)<0.0))
		 		{
	
			
			san=(bxn-axn)*(cyn-ayn)-(byn-ayn)*(cxn-axn);
			sbn=(bxn-axn)*(cyn-dyn)-(byn-ayn)*(cxn-dxn);

			sn=san/sbn;

			

				txn=cxn+sn*(dxn-cxn);
				tyn=cyn+sn*(dyn-cyn);
	
				


			int j;
			for(j=0;j<flag;j++)
			{
			
if(j<flag-1)									
{
		/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn*vertex[j+1][1])-(vertex[j+1][0]*qyn)-(txn*vertex[j+1][1])+(txn*qyn)+(tyn*vertex[j+1][0])-(tyn*qxn);
    pr2=(qxn*vertex[j][1])-(vertex[j][0]*qyn)-(txn*vertex[j][1])+(txn*qyn)+(tyn*vertex[j][0])-(tyn*qxn);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex[j+1][0]*qyn)-(vertex[j+1][1]*qxn)-(vertex[j][0]*qyn)+(vertex[j][0]*vertex[j+1][1])+(vertex[j][1]*qxn)-(vertex[j][1]*vertex[j+1][0]);
 pr4=(vertex[j+1][0]*tyn)-(vertex[j+1][1]*txn)-(vertex[j][0]*tyn)+(vertex[j][0]*vertex[j+1][1])+(vertex[j][1]*txn)-(vertex[j][1]*vertex[j+1][0]);			
}
else
{

		/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qxn*vertex[j+1][1])-(vertex[0][0]*qyn)-(txn*vertex[0][1])+(txn*qyn)+(tyn*vertex[0][0])-(tyn*qxn);
    pr2=(qxn*vertex[j][1])-(vertex[j][0]*qyn)-(txn*vertex[j][1])+(txn*qyn)+(tyn*vertex[j][0])-(tyn*qxn);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(vertex[0][0]*qyn)-(vertex[0][1]*qxn)-(vertex[j][0]*qyn)+(vertex[j][0]*vertex[0][1])+(vertex[j][1]*qxn)-(vertex[j][1]*vertex[0][0]);
 pr4=(vertex[0][0]*tyn)-(vertex[0][1]*txn)-(vertex[j][0]*tyn)+(vertex[j][0]*vertex[0][1])+(vertex[j][1]*txn)-(vertex[j][1]*vertex[0][0]);			

}

if(pr4>-0.1 && pr4<0.1)
{
pr4=1.0;
}
else if(pr3>-0.1 && pr3<0.1)
{
pr3=1.0;
}
else if(pr2>-0.1 && pr2<0.1)
{
pr2=1.0;
}
else if(pr1>-0.1 && pr1<0.1)
{
pr1=1.0;
}


ptest1=pr3*pr4;
ptest2=pr1*pr2;



				if(ptest1<0.0 && ptest2<0.0)
				{	
				//printf("\n there is an edge intersecting this line \n");

				break;
				}

				else if(j==flag-1)
				{
				if((qxn==pxcomp && qyn==pycomp))
				{

				}
				else
				{
//			printf("\n enter the else if****** \n");
	XDrawLine(display_ptr, win, gc_dot, qxn*4 , qyn*4 ,txn*4, tyn*4);
				int h;
				int dot;
				dot=0;
				for(h=0;h<count;h++)
				{
				
				if(cxn==vis[h][0] && cyn==vis[h][1])
				{
				dot++;
				}
				else
				{
				//dot=0;
				}
				}
				if(dot>0)
				{
				chargx=0;
				chargy=0;
				}	
				else if(dot==0)
				{
				chargx=cxn;
				chargy=cyn;
				}		


				fndver[found][0]=qxn;
				fndver[found][1]=qyn;
				fndver[found][2]=txn;
				fndver[found][3]=tyn;
				fndver[found][4]=cxn;
				fndver[found][5]=cyn;				
				fndver[found][6]=dxn;
				fndver[found][7]=dyn;				
				fndver[found][8]=exn;
				fndver[found][9]=eyn;	
				fndver[found][10]=chargx;
				fndver[found][11]=chargy;			
				found++;
				}
				}



			
			}


			}
			else
			{
			}




}



}
}
}

}
}
for(i=0;i<found;i++)
{
find(vis,count,fndver[i][0],fndver[i][1],fndver[i][2],fndver[i][3],fndver[i][4],fndver[i][5],fndver[i][6],fndver[i][7],fndver[i][8],fndver[i][9],fndver[i][10],fndver[i][11],xstart,ystart);
}

}
}
int main(int argc, char **argv)
{
    
	int ad=0;
    int k;
    int c;
    int l;	
    int m;
    int count=0;
    int counter=0;
    FILE *pf;
    	

	
  /* opening display: basic connection to X Server */
  if( (display_ptr = XOpenDisplay(display_name)) == NULL )
    { printf("Could not open display. \n");exit(-1);}
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
  win_height = (int) (win_width); /*rectangular window*/
  
  win= XCreateSimpleWindow( display_ptr, RootWindow( display_ptr, screen_num),
                            win_x, win_y, win_width, win_height, border_width,
                            BlackPixel(display_ptr, screen_num),
                            WhitePixel(display_ptr, screen_num) );
  /* putting on screen */
  size_hints = XAllocSizeHints();
  wm_hints = XAllocWMHints();
  class_hints = XAllocClassHint();
  if( size_hints == NULL || wm_hints == NULL || class_hints == NULL )
    { printf("Error allocating memory for hints. \n");exit(-1);}

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

  /* events we want to receive */
  XSelectInput( display_ptr, win, 
            ExposureMask | StructureNotifyMask | ButtonPressMask );
  
  /* put window on screen */
  XMapWindow( display_ptr, win );

  XFlush(display_ptr);

  /* create graphics context, so that we may draw in this window 
	Add graphic context to get dotted lines
  */

  gc = XCreateGC( display_ptr, win, valuemask, &gc_values);
  XSetForeground( display_ptr, gc, BlackPixel( display_ptr, screen_num ) );
  XSetLineAttributes( display_ptr, gc, 1, LineSolid, CapProjecting, JoinRound);

  /* Graphics context to draw dotted lines */
   gc_dot=XCreateGC( display_ptr, win, valuemask, &gc_dot_values);
   XSetForeground( display_ptr, gc_dot, BlackPixel( display_ptr, screen_num ) );
  XSetLineAttributes( display_ptr, gc_dot, 3, LineOnOffDash, CapProjecting, JoinRound);
  /*green*/

  
  /* green*/

  /* and three other graphics contexts, to draw in yellow and red and grey*/
  gc_yellow = XCreateGC( display_ptr, win, valuemask, &gc_yellow_values);
  XSetLineAttributes(display_ptr, gc_yellow, 6, LineSolid,CapRound, JoinRound);
  if( XAllocNamedColor( display_ptr, color_map, "yellow", 
			&tmp_color1, &tmp_color2 ) == 0 )
    {printf("failed to get color yellow\n");exit(-1);} 
  else
    XSetForeground( display_ptr, gc_yellow, tmp_color1.pixel );
  gc_red = XCreateGC( display_ptr, win, valuemask, &gc_red_values);
  XSetLineAttributes( display_ptr, gc_red, 6, LineSolid, CapRound, JoinRound);
  if( XAllocNamedColor( display_ptr, color_map, "red", 
			&tmp_color1, &tmp_color2 ) == 0 )
    {printf("failed to get color red\n");exit(-1);} 
  else
    XSetForeground( display_ptr, gc_red, tmp_color1.pixel );
  gc_grey = XCreateGC( display_ptr, win, valuemask, &gc_grey_values);
  if( XAllocNamedColor( display_ptr, color_map, "light grey", 
			&tmp_color1, &tmp_color2 ) == 0 )
    {printf("failed to get color grey\n");exit(-1);} 
  else	
    XSetForeground( display_ptr, gc_grey, tmp_color1.pixel );
  gc_green = XCreateGC( display_ptr, win, valuemask, &gc_green_values);
  XSetLineAttributes(display_ptr, gc_yellow, 6, LineSolid,CapRound, JoinRound);
  if( XAllocNamedColor( display_ptr, color_map, "green", 
			&tmp_color1, &tmp_color2 ) == 0 )
    {printf("failed to get color green\n");exit(-1);} 
  else
    XSetForeground( display_ptr, gc_green, tmp_color1.pixel );

   
	

  /* the event loop */
  while(1)
    { XNextEvent( display_ptr, &report );
	
      switch( report.type )
	{
	case Expose:
	{
         
	Draw(argc,argv);
	
	}
	break;
        case ButtonPress:
          /* This event is used to select a starting point on left click mouse
             and a Right click mouse event will end the program  
	  */
          {  
        
             double x, y;
	
  	     x = report.xbutton.x;
             y = report.xbutton.y;
incr=0;
incr_1=0;
incr_2=0;
incr_12=0;
incr_base=0;
incr_base1=0;
incr_base2=0;
incr01=0;
incr_last=0;
incr_ls=0;
incrsa=0;

		if (report.xbutton.button == Button1 )

		{
		XClearWindow(display_ptr, win);
		Draw(argc,argv);	       
	        XFillArc( display_ptr, win, gc_red, 
                       x, y,
                       win_height/150, win_height/150, 0, 360*64);
		}         
				
		else
	        {
		XFreeGC(display_ptr,gc);
		XDestroyWindow(display_ptr,win);
		XCloseDisplay(display_ptr);
		exit(1);
		}		
	
   pf = fopen(argv[1], "r");
    
    if(pf==NULL)
	{	
      printf("its null");
 	}
    else
	{

   //iterate through input file and get all the coordinates in an array
	counter=0;
        do
	{
	c=fgetc(pf);
	if(c=='\n')
	counter++;

	}while(c!=EOF);

	rewind(pf);
	
	int *ptr_a = &counter;

	double a[counter][2];
     for(k=0;k<counter;k++)
       {
	 fscanf(pf,"%lf,%lf" ,&a[k][0],&a[k][1]);

	//scaling the inputs.

	a[k][0]=(a[k][0]);
	a[k][1]=(a[k][1]);

    //printf("\n2nd set ---->\n%lf,%lf\n" ,a[k][0],a[k][1]);
	
	}
	printf("end of reading file");	  


 //Take each vertex of the polygon and iterate them through the loop to find visible vertex from point selected.

 printf("starting point x = %lf ,starting point y= %lf" , x, y);
x=x/4;
y=y/4;
int found=0;
int i;
int flag=0;
int b[counter][2];
int visit=0;
//int vis[counter][2];
int f=0;
for(i=0;i<counter; i++)
{
	
	//current vertex points- qx,qy
	
	qx =a[i][0];
	qy =a[i][1];

	// iterate through each edge
  for(ed=0;ed<counter;ed++)
  {

    if(ed<counter-1)
    {
	    /* determinant for abc and abd for lines ab and cd*/	
    or1=(qx*a[ed+1][1])+(x*qy)+(y*a[ed+1][0]) -(a[ed+1][0]*qy)-(x*a[ed+1][1])-(y*qx);
    or2=(qx*a[ed][1])+(x*qy)+(y*a[ed][0]) -(a[ed][0]*qy)-(x*a[ed][1])-(y*qx);

    /* determinant for cda and cdb for lines ab and cd*/	
    or3=(a[ed][0]*qy)+(a[ed+1][0]*a[ed][1])+(a[ed+1][1]*qx)-(a[ed][0]*a[ed+1][1])-(a[ed][1]*qx)-(a[ed+1][0]*qy);
    or4=(a[ed][0]*y)+(a[ed+1][0]*a[ed][1])+(a[ed+1][1]*x)-(a[ed][0]*a[ed+1][1])-(a[ed][1]*x)-(a[ed+1][0]*y);

     }
  
     else
     {	
    /* determinant for abc and abd for lines ab and cd*/	
    or1=(qx*a[0][1])+(x*qy)+(y*a[0][0]) -(a[0][0]*qy)-(x*a[0][1])-(y*qx);
    or2=(qx*a[ed][1])+(x*qy)+(y*a[ed][0]) -(a[ed][0]*qy)-(x*a[ed][1])-(y*qx);

    /* determinant for cda and cdb for lines ab and cd*/	
    or3=(a[ed][0]*qy)+(a[0][0]*a[ed][1])+(a[0][1]*qx)-(a[ed][0]*a[0][1])-(a[ed][1]*qx)-(a[0][0]*qy);
    or4=(a[ed][0]*y)+(a[0][0]*a[ed][1])+(a[0][1]*x)-(a[ed][0]*a[0][1])-(a[ed][1]*x)-(a[0][0]*y);
	}
  

	if((or3*or4)<0 && (or1*or2)<0)
	{
	//printf("\n false \n");
	//flag=0;
	break;
	}
	else if(ed==counter-1)
	{
	//printf("\n ***** EDGE VALUE IS ****** %d,%d \n",a[ed][0],a[ed][1]);
         //XDrawLine(display_ptr, win, gc, qx*4 , qy*4 ,x*4, y*4);
	  //used to extend the line out of the polygon.
          
	  //double ttx,tty;

	  //calculating a value till which the lines will be extended
	

	distx=(qx-x)*(qx-x);
	disty=(qy-y)*(qy-y);
	dist=distx+disty;
	dist=sqrt(dist);
         
	//find xnew , qnew and ttx,tty
	ttx=x+(x-qx)/dist*30;
	tty=y+(y-qy)/dist*30;
	
	xnew=qx+(qx-x)/dist*100;
	ynew=qy+(qy-y)/dist*100;
	
	//XDrawLine(display_ptr, win, gc, qx*4 , qy*4 ,xnew*4, ynew*4);
//to check whether the two points i+1,i-1 lie on same side or opposite side.
if(i<counter-1)
{
edx=a[i+1][0];
edy=a[i+1][1];
ex=a[i-1][0];
ey=a[i-1][1];
}
else
{
edx=a[0][0];
edy=a[0][1];
ex=a[i-1][0];
ey=a[i-1][1];

}


eo1=(ttx*edy)-(tty*edx)-(xnew*edy)+(xnew*tty)+(ynew*edx)-(ynew*ttx);
eo2=(ttx*ey)-(tty*ex)-(xnew*ey)+(xnew*tty)+(ynew*ex)-(ynew*ttx);

eo3=(ex*tty)-(ey*ttx)-(edx*tty)+(edx*ey)+(edy*ttx)-(edy*ex);
eo4=(ex*ynew)-(ey*xnew)-(edx*ynew)+(edx*ey)+(edy*xnew)-(edy*ex);


	if((eo1*eo2)<0)
	{
	
	break;
	}

	else
	{
	//printf("\n counter %d\n",counter);
	

   //XDrawLine(display_ptr, win, gc, qx , qy ,xnew, ynew);
	    for(ed=0;ed<counter;ed++)
	    {
	     
		
		// first line
			ax=qx;
			ay=qy;
			bx=xnew;
			by=ynew;
	//XDrawLine(display_ptr, win, gc_green, ax*4 , ay*4 ,bx*4, by*4);
		// second line 
			if(ed<counter-1)
			{		
			cx=a[ed][0];
			cy=a[ed][1];
			dx=a[ed+1][0];
			dy=a[ed+1][1];
			}
			else
			{
			cx=a[counter-1][0];
			cy=a[counter-1][1];
			dx=a[0][0];
			dy=a[0][1];	
			}

	xr1=(bx*cy)-(cx*by)-(ax*cy)+(ax*by)+(ay*cx)-(ay*bx);
	xr2=(bx*dy)-(dx*by)-(ax*dy)+(ax*by)+(ay*dx)-(ay*bx);

	xr3=(dx*ay)-(ax*dy)-(cx*ay)+(cx*dy)+(cy*ax)-(cy*dx);
	xr4=(dx*by)-(bx*dy)-(cx*by)+(cx*dy)+(cy*bx)-(cy*dx);

	
	test1=xr1*xr2;
	test2=xr3*xr4;
	
		if(test1<0 && test2<0)
 		{
		  
		 // printf("\n Intersection here %lf,%lf__,%lf,%lf,%lf,%lf \n " ,qx,qy,cx,cy,dx,dy); 
		       
  //solving the linear equation formed by two lines using CRAMERS RULE and finding the value of variable s
			sa=(bx-ax)*(cy-ay)-(by-ay)*(cx-ax);
			sb=(bx-ax)*(cy-dy)-(by-ay)*(cx-dx);

			s=sa/sb;


				px=cx+s*(dx-cx);
				py=cy+s*(dy-cy);
		//printf("\n px,py %lf,%lf\n",px,py);

			int j;		
			for(j=0;j<counter;j++)
			{
			

if(j<counter-1)									
{
		/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qx*a[j+1][1])-(a[j+1][0]*qy)-(px*a[j+1][1])+(px*qy)+(py*a[j+1][0])-(py*qx);
    pr2=(qx*a[j][1])-(a[j][0]*qy)-(px*a[j][1])+(px*qy)+(py*a[j][0])-(py*qx);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(a[j+1][0]*qy)-(a[j+1][1]*qx)-(a[j][0]*qy)+(a[j][0]*a[j+1][1])+(a[j][1]*qx)-(a[j][1]*a[j+1][0]);
 pr4=(a[j+1][0]*py)-(a[j+1][1]*px)-(a[j][0]*py)+(a[j][0]*a[j+1][1])+(a[j][1]*px)-(a[j][1]*a[j+1][0]);			
}
else
{

		/* determinant with abc and abd for lines ab and cd*/	
    pr1=(qx*a[j+1][1])-(a[0][0]*qy)-(px*a[0][1])+(px*qy)+(py*a[0][0])-(py*qx);
    pr2=(qx*a[j][1])-(a[j][0]*qy)-(px*a[j][1])+(px*qy)+(py*a[j][0])-(py*qx);

    /* determinant for cda and cdb for line ab and cd*/	
    pr3=(a[0][0]*qy)-(a[0][1]*qx)-(a[j][0]*qy)+(a[j][0]*a[0][1])+(a[j][1]*qx)-(a[j][1]*a[0][0]);
 pr4=(a[0][0]*py)-(a[0][1]*px)-(a[j][0]*py)+(a[j][0]*a[0][1])+(a[j][1]*px)-(a[j][1]*a[0][0]);			

}


if(pr4>-0.1 && pr4<0.1)
{
pr4=-1.0;
}
else if(pr3>-0.1 && pr3<0.1)
{
pr3=-1.0;
}
else if(pr2>-0.1 && pr2<0.1)
{
pr2=-1.0;
}
else if(pr1>-0.1 && pr1<0.1)
{
pr1=-1.0;
}



ptest1=pr3*pr4;
ptest2=pr1*pr2;







				if((ptest1<0.0) && (ptest2<0.0))
				{
									


				break;		
				}
				else if(j==counter-1)
				{
	    XDrawLine(display_ptr, win, gc_dot, (qx*4) , (qy*4) ,(px*4), (py*4));
   find_visiblity(a,counter,qx,qy,px,py,cx,cy,dx,dy,edx,edy,ex,ey,ed,x,y);				
				
				
				
				}	
			}

		
		
		}/// outer if
                else
                {
                }
		
	     }
	
	}
		

   	}

    }

}
rewind(pf);
}//closing file else
fclose(pf);

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
