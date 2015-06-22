/*

Fundamental Algorithm Homework 4
Name -Vijaya Kumar Venkatramanan

Compile - gcc rabinkarp1.c -o rabinkarp1
Run - ./rabinkarp1


*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PATNUMBER 100
#define PATLENGTH 200
/*#define DEBUG*/


int multi_string_search(char *s,char **t,int k, int l)
{

long x=30;
long hash;
long hashp;
// prime number
int mod=23;
int fnd;
int n=strlen(s);

int trk=0;
long hashptable[k];

printf("\n-------------------------------------------\n");
//printf("\nDATA STRING--> %s\n",s);

// to calculate the hash function of the sliding window.

//printf("\n 1st element of s %c\n",s[0]);
int j,m;

char *fn;

int i,p;

char *store[k*l];
char *tempstore;

int seq[k];
int indextrk=0;

for(i=0;i<k;i++)
{
fnd=0;
  //printf("\npattern string--> %s\n",t[i]);
  char *temp=t[i];
  store[i]=t[i];
  //printf("%s\n",store[i]);
  if(i==0)
  {
  seq[i]=indextrk;
  
  }
  else
  {
  seq[i]=indextrk;
  
  }
  indextrk=indextrk+l;
 /*

    Calculating hash value using HORNER's RULE for a pattern window.

 */

    for(p=0;p<l;p++)
    {
 
     if(p==0)
     {
       hashp=temp[p];
     }

     hashp=temp[p]+x*hashp;

    }
    hashp=hashp%mod;
   // printf("hashp value is %ld\n",hashp);
    hashptable[trk]=hashp;
    trk++;

}

seq[i]=indextrk;
seq[i+1]=indextrk+l;

int chk=0;
int prnt=0;
int prnt1=0;
for(chk=0;chk<trk;chk++)
{

printf("hastable value %ld\n",hashptable[chk]);


prnt=0;

//printf("\n <--%s-->\n",store[chk]);
tempstore=store[chk];


while(prnt<l)
{
//printf("%c",tempstore[prnt]);
prnt++;
}

}
printf("\n---------End of hash table------------------\n");


for(i=0;i<k;i++)
{
  fnd=0;
  

  for(m=0;m<=(n-l);m++)
  {
     //printf("\n for m = %d\n",m);
     char temp1[l];     
     int tp=0;
     for(j=m;j<l+m;j++)
     {
  
      if(j==m)
      {
       hash=s[j];
       temp1[tp]=s[j];
       tp++;
      }
      hash=s[j]+x*hash;
      if(j==m)
      {

      }
      else
      {
      temp1[tp]=s[j];
      tp++;
      }
      
     
     }
     hash=hash%mod;
     
  	


//	Check if the hash values are same. if Yes then check string patter with
//	the found data string.



	//printf("hash value is  %ld at m ,%d \n",hash,m);
	int newm;
	int ntfnd;
	for(newm=0;newm<trk;newm++)
	{
	ntfnd=0;
	if(hashptable[newm]==hash)
	{
	prnt=0;
	tempstore=store[newm];


	while(prnt<l)
	{
	//printf("%c",tempstore[prnt]);

	
	int tmp;
		
	//printf("elem are %c\n",temp[tmp]);
	//printf("string part %c\n",temp1[tmp]);
	if(tempstore[prnt]!=temp1[prnt])
	{
	ntfnd++;
		    
	}
	else
	{

	}
		
	prnt++;
	}
	
		if(ntfnd>0)
		{
		
		}
		else
		{
		
		// return the found index value
		return m;		
		fnd++;
		fn="";
		}		
	
	}
	else
	{
	//printf("not found\n");
	
	}
	
	
  
	
 
      }

	
  }

}

if(fnd==0)
{

return -1;
}


}

int main(void)
{  char sequence[100001];
   char *patterns[PATNUMBER];
   char t[PATNUMBER*PATLENGTH];
   int i, j;
   for(i=0; i<100000; i++)
      sequence[i] = 'a';
   sequence[100000]='\0';
   for(i=0; i<4000; i++)
   {  j = rand()%100000;
      sequence[j]='b';      
   }
   for(i=0; i<PATNUMBER; i++)
   {  patterns[i] = t + PATLENGTH*i;
      for(j=0; j< PATLENGTH-1; j++)
         t[PATLENGTH*i+j] = sequence[PATLENGTH*i+j];
      t[PATLENGTH*i+PATLENGTH -1] = '\0';

   }
   for(i=0; i<PATNUMBER-1; i++)
   {  t[PATLENGTH*i+PATLENGTH -15] = 'b';
      t[PATLENGTH*i+PATLENGTH -14] = 'b';
      t[PATLENGTH*i+PATLENGTH -13] = 'b';
   }
#ifdef DEBUG
   { FILE *fp1, *fp2;
       fp1 = fopen("sequence", "w");
       fprintf(fp1, "%s\n", sequence);
       fclose(fp1);
       fp2 = fopen("patterns", "w");
       for(i=0; i<100; i++)
	 fprintf(fp2, "%s\n", patterns[i]);
       fclose(fp2);
   }
#else
   if(multi_string_search(sequence, patterns, PATNUMBER, PATLENGTH-1) == (PATNUMBER-1)*PATLENGTH )
     printf("accepted\n");
   else
     printf("needs check?\n");
#endif
}
