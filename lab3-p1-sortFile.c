
/*****DINO DAN, CSC250-SP19
******LAB 3, SORT RANDOM NUMBER BAR GRAPH
******Major contribution by Noah Manter
******3/13/2019, version 1.0*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFunctionLib.h"
#include "myGfxShapesLib.h"
#include "gfx2.h"



int main ()
{
    int COUNT=20;
    double listOfDoubles[COUNT];
    int xSize=600, ySize=600;
    
    
    
    
    srand(time(NULL));
    
    sortNumbers(listOfDoubles, COUNT);
        

    sortVisualize (listOfDoubles, COUNT);
    
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







