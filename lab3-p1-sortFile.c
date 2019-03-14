#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myGfxShapesLib.h"
#include "gfx2.h"



void printListOfDoubles (double* listOfDoubles, int COUNT)
{
    int i;
    for (i=0; i < COUNT; i++)  {
        printf("%lf\n", listOfDoubles[i]);
    }

}

int main ()
{
    int COUNT=20;
    double listOfDoubles[COUNT];
    int i, j;
    int xSize=600, ySize=600;
    int temp=0;
    int num;
    
    
    
    srand(time(NULL));
    
    for (i=0; i < COUNT; i++)  {
        num = rand() / (double) RAND_MAX * 200.0;
        listOfDoubles[i] = num;
    }
    
    for (i=0; i < COUNT; i++)  {
        
    for (j=0; j < COUNT - 1; j++)  {
        if (listOfDoubles[j] > listOfDoubles[j+1])  {
            temp=listOfDoubles[j];
            listOfDoubles[j] = listOfDoubles[j+1];
            listOfDoubles[j+1]=temp;
        } //end if
    }//end for    
    }//end for

    printListOfDoubles (listOfDoubles, COUNT);
    
    gfx_open(xSize, ySize, "BarChart");
    gfx_color(255,0,0);
    
    double spacePerBar = 500.0 / COUNT;
    drawBars(listOfDoubles, COUNT, 50, 500, .7*spacePerBar, .3*spacePerBar);
    
    char c;
    
    while(1) {
        //wait for user to press a character.
        c = gfx_wait();
        
        //quit if it is the letter 'q'
        if(c=='q') break;
    }//end while
    
    return 0;   

}//end main























