
/*****DINO DAN, CSC250-SP19
******LAB 3, SORT RANDOM NUMBER BAR GRAPH
******Major contribution by Noah Manter
******3/13/2019, version 1.0*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//usleep
#include <time.h>//random number generator header
#include "myFunctionLib.h"
#include "myGfxShapesLib.h"
#include "gfx2.h"



int main ()
{
    int COUNT=20;//limits array to quantity 20 elements
    double listOfDoubles[COUNT]; //array name is listOfDoubles with 20 indexes
    int xSize=600, ySize=600;  //used for screen size 
    
    
    srand(time(NULL));//generates a random number    
     
    
    //Function using simple bubble sort
    sortNumbers(listOfDoubles, COUNT);  
       
    
    //Function applies sortedNumbers to the drawBars and allows seeing the sort take place
    sortVisualize (listOfDoubles, COUNT);
    
    //graphic window command to open and color the bar graph
    gfx_open(xSize, ySize, "Random Sorted Bar Graph");
    gfx_color(255,0,0);//Red
    
    //calculates width to spacing ratio
    double spacePerBar = 500.0 / COUNT;
    
    //cause the calling thread to be suspended from execution until either the number of realtime microseconds specified by the argument
    usleep(1000000); 
    
    //drawBars function takes the array's 20 elements and establishes bar graph dimensions
    drawBars(listOfDoubles, COUNT, 50, 500, .7*spacePerBar, .3*spacePerBar);
    
    char c;
    
    while(1) {
        //wait for user to press a character.
        c = gfx_wait();
        usleep(1000000);
        
        //quit if it is the letter 'q'
        if(c=='q') break;
    }//end while
    
    return 0;   

}//end main

