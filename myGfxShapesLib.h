/*
 * myGfxShapesLib.c
 *
 *     A library of functions that draw various shapes using gfx2 library
 *     Author: Dino Dan
 *     Last Modified: 1/21/2019
 *
 */

// Header files normally contain constants, global variables, #define, as well as
// function headers


typedef struct GfxPoint
{
    //declare the component variables of the struct here...
    double x;
    double y;
} GfxPoint;

// Mostly function headers (prototypes, signatures) are listed in header file
void drawSquare(double xCenter, double yCenter, double side);

void drawCircle(double xCenter, double yCenter, double radius);

void drawBars( double * data, int dataCount, double lowerLeftX, double lowerLeftY, double width, double spacing );

void drawPolygonWithoutStructs(double * xCoords, double * yCoords, int coordCount);

void drawPolygon(GfxPoint * points, int pCount);

void drawCircleThing(double xCenter, double yCenter, double radius, double rlimit);

void drawDragon(GfxPoint a, GfxPoint b, double sizeLimit);

void bubble_sort(long list[], long n);





