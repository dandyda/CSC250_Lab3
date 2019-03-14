/*
 * myGfxShapesLib.c
 *
 *     A library of functions that draw various shapes using gfx2 library
 *     Author: Dino Dan
 *     Last Modified: 1/21/2019
 *
 */
#include "gfx2.h"
#include "myGfxShapesLib.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h> //usleep

const double PI = 3.1415927;
/*
 * drawSquare
 *     draws a square centered at given (x, y) coords, with size given by side parameters
 *
 */

void drawSquare(double xCenter, double yCenter, double side)

{
    // calculate x,y coordinates of all corners...ulx means upper left x, etc
    double ulx = xCenter - side/2;
    double uly = yCenter - side/2;
    double llx = xCenter - side/2;
    double lly = yCenter + side/2;
    double urx = xCenter + side/2;
    double ury = yCenter - side/2;
    double lrx = xCenter + side/2;
    double lry = yCenter + side/2;
    

    gfx_line(ulx,uly,llx,lly);
    gfx_line(urx,ury,lrx,lry);
    gfx_line(llx,lly,lrx,lry);
    gfx_line(ulx,uly,urx,ury);
}




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





//Dino Dan, CSC250-SP19
//Online#7350290
//drawBars.c

/*Google: command line arguments in C programming
  argv: a one-dimensional array of strings
       mean argv[someIndex] can be used anywhere you would use string
       anywhere "you could put something in double-quotes"
       anywhere you would use a plain char whatever[50] variable
       that stores a string value
      
  argc: a count of how many command line arguments were given when the program was invoked
        including the command name itself*/

/*declare array paramaters as "pointer to" the data type of the array cells
the * below means "pointer to"*/
void drawBars( double * data, int dataCount, double lowerLeftX, double lowerLeftY, double width, double spacing )
{

    //printf("********Draw bars: function not yet fully implemented********\n");
    double llx = lowerLeftX;
    double lly = lowerLeftY;
    int i;
    //loop for each bar we need draw:
    for( i = 0; i < dataCount; i++ ) {
    // draw rectangle for the correct height and width in the correct position
    gfx_line(llx,lly,llx,lly-data[i]); // draw left side of column rectangle
    gfx_line(llx,lly,llx+width,lly); //draw bottom
    gfx_line(llx+width,lly,llx+width,lly-data[i]); //draw right side
    gfx_line(llx,lly-data[i],llx+width,lly-data[i]); //draw top
    
    llx = llx + width + spacing;//update the x coord of lwr left corner for next time trough the loop
    }
        
    //gfx_flush();

}

//drawPolygon()
/*take a list of X coord, Y coord for points then plot lines from each point to the next
 *and a line from last point to first point
 *
 *
 */
 
 void drawPolygonWithoutStructs(double * xCoords, double * yCoords, int coordCount)
 {
    int i;
    int lastPointIndex = coordCount -1;
    int secondToLastIndex = lastPointIndex -1;
    //loop over index from 0 to coordCount - 1
    for (i=0; i <= secondToLastIndex; i++)
    {
        //draw line from index coord to index+1 coord
        gfx_line( xCoords[i], yCoords[i], xCoords[i+1], yCoords[i+1] );
    
    }//End for
        
    //draw a line from coordCount-1 index to the 0 index points
    //NOTE: i should equal last index, coordCount-1 at this point
    gfx_line( xCoords[i], yCoords[i], xCoords[0], yCoords[0] );
 
 }
 
 void drawPolygon(GfxPoint * points, int pCount)
 {
    int i;
    int lastPointIndex = pCount -1;
    int secondToLastIndex = lastPointIndex -1;
    //loop over index from 0 to coordCount - 1
    for (i=0; i <= lastPointIndex; i++)
    {
        //draw line from index coord to index+1 coord
        gfx_line( points[i].x, points[i].y, points[(i+1)%pCount].x, points[(i+1)%pCount].y );
    
    }//End for
        
    //draw a line from coordCount-1 index to the 0 index points
    //NOTE: i should equal last index, coordCount-1 at this point
    //gfx_line(points[i].x, points[i].y, points[0].x, points[0].y );
    //********above gfx_line is not needed because we used modulo operator to connect lines 
 }
 // How to use modulo operator % --> remainder after division
 // n = 7
 // 0 % n = 0
 // 1 % n = 1
 // 2 % n = 2
 // 3 % n = 3
 // 4 % n = 4
 // 5 % n = 5
 // 6 % n = 6 (last index for 5 points)
 // 7 % n = 0
 // 8 % n = 1
 // 9 % n = 2...


void drawCircle(double xCenter, double yCenter, double radius)
{
    // calculate x,y coordinates of circle's center...
    double x, y, xNext, yNext, theta, thetaNext;
    double thetaIncrement = 2.0 / ( 2 * PI * radius );
            
    for( theta = 0; theta < 2 * PI; theta = thetaNext )
    {
        thetaNext = theta + thetaIncrement;        
        x = xCenter + radius * cos(theta);
        y = yCenter + radius * sin(theta);
        xNext = xCenter + radius * cos(thetaNext);
        yNext = yCenter + radius * sin(thetaNext);
        
        gfx_line(x,y,xNext,yNext);
       
    }
    
}

 
 void drawCircleThing(double xCenter, double yCenter, double radius, double rlimit)
 {
    if ( radius >= rlimit ) {
    
        
        
        //draw circles on left, half as big
        drawCircleThing(xCenter-radius, yCenter, radius/2, rlimit );
        //draw circles on right, half as big
        drawCircleThing(xCenter+radius, yCenter, radius/2, rlimit );
        
        //draw vertical thing
        drawCircleThing(xCenter, yCenter-radius, radius/2, rlimit );
        drawCircleThing(xCenter, yCenter+radius, radius/2, rlimit );
        
        //draw big circle
        drawCircle(xCenter, yCenter, radius);
        
        gfx_flush();
        usleep(100000);
    } // base case:  do nothing
    
 
 }
 
 //draw Dragon
 
 void drawDragon(GfxPoint a, GfxPoint b, double sizeLimit)
 {
    GfxPoint newPoint;
    //base case: draw the line
    double dist = sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.x)*(b.y-a.x) );
    if ( dist <= sizeLimit ) {
        gfx_line(a.x, a.y, b.x, b.y);
    }
    else
    {
        //calculate x & y of the new point
        newPoint.x = a.x + (b.x-a.x)/2 + (b.y-a.y)/2;
        newPoint.y = a.y + (b.y-a.y)/2 - (b.x-a.x)/2;
        //recursively draw the sub dragons...
        drawDragon(a,newPoint, sizeLimit);
        drawDragon(b,newPoint, sizeLimit); 
    
    }
 
 
 }
 
 
