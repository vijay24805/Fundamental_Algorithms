#include <stdlib.h>
#include <stdio.h>
#define PATNUMBER 100
#define PATLENGTH 200
/*#define DEBUG*/

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
