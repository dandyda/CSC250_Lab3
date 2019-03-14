#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFunctionLib.h"
#include "myGfxShapesLib.h"
#include "gfx2.h"

void printListOfDoubles (double* listOfDoubles, int COUNT)
{
    int i;
    for (i=0; i < COUNT; i++)  {
        printf("%lf\n", listOfDoubles[i]);
    }

}//end printListOfDoubles

void bubble_sort(long list[], long n)
{
  long c, d, t;
 
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}
