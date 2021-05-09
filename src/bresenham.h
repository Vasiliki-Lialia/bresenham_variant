/******************************************************************************
 * bresenham.h:                                                               *
 *                  Header file contains necessary include directives,        *
 *                  define directives, function signatures                    *
 *                  and their descriptions regarding the implementation       *
 *                  of a modified bresenham algorithm in the first octant     *
 *                  and with a thickness line attribute at pixel level        *
 *                  against the minor axis                                    *
 ******************************************************************************/

#ifndef BRESENHAM_H
#define BRESENHAM_H

#include "visuals.h"
#include <cstdio>
#include <cmath>

#define X_START 50        /* x-coordinate of starting point */
#define Y_START 50        /* y-coordinate of starting point */
#define X_END 351         /* x-coordinate of ending point */
#define Y_END 350         /* x-coordinate of ending point */
#define LINE_THICKNESS 8  /* line thickness measured in pixels */

/******************************************************************************
 * displayFnc:      Clears display-window and calls line3 fuction             *
 ******************************************************************************/
void displayFnc(void);

/******************************************************************************
 * line3:           Draws line according to Bresenham                         *
 *                  line-drawing procedure at first octant                    *
 *                  with line thickness attribute "thickness"                 *
 *                  at pixel level against the minor axis                     *
 *                  by calling function thicken                               *
 ******************************************************************************/
void line3(const int xs, const int ys, const int xe, const int ye,
           const int thickness);

/******************************************************************************
 * setPixel:        Stores the current color setting into the frame buffer,   *
 *                  at integer position (xCoord, yCoord)                      *
 *                  relative to the selected position                         *
 *                  of the screen-coordinate origin                           *
 ******************************************************************************/
void setPixel(const GLint xCoord, const GLint yCoord);

/******************************************************************************
 * errorCheck:      Error-reporting function                                  *
 *                  that retrieves the current error code,                    *
 *                  and prints the descriptive error string                   *
 ******************************************************************************/
void errorCheck(void);

/******************************************************************************
 * minor_axis:      Finds minor axis and returns 'y' for y minor axis         *
 *                  or 'x' for x minor axis                                   *
 ******************************************************************************/
char minor_axis(const int dx, const int dy);

/******************************************************************************
 * thicken:         Wrapper function                                          *
 *                  Either calls function parallel_y                          *
 *                  if function minor_axis returns 'y',                       *
 *                  or calls function parallel_x                              *
 *                  if function minor_axis returns 'x'                        *
 ******************************************************************************/
void thicken(const char axis, const int xs, const int ys, const int xe,
             const int ye, const int thickness);

/******************************************************************************
 * parallel_y:      Wrapper function                                          *
 *                  Either calls function draw_odd_y                          *
 *                  if thickness parameter is an odd number,                  *
 *                  or calls function draw_even_y                             *
 *                  if thickness paramenter is an even number                 *
 ******************************************************************************/
void parallel_y(const int xs, const int ys, const int xe, const int ye,
                const int thickness);

/******************************************************************************
 * draw_odd_y:      Draws alternate parallel lines to given points            *
 *                  against the y-axis by calling line3 function              *
 *                  and thus achieves as thicker line                         *
 *                  as specified by an odd thickness parameter                *
 ******************************************************************************/
void draw_odd_y(const int xs, const int ys, const int xe, const int ye,
                const int thickness);

/******************************************************************************
 * draw_even_y:     Draws alternate parallel lines to given points            *
 *                  against the y-axis by calling line3 function              *
 *                  and thus achieves as thicker line                         *
 *                  as specified by an even thickness parameter               *
 ******************************************************************************/
void draw_even_y(const int xs, const int ys, const int xe, const int ye,
                 const int thickness);

/******************************************************************************
 * parallel_x:      Wrapper function                                          *
 *                  Either calls function draw_odd_x                          *
 *                  if thickness parameter is an odd number,                  *
 *                  or calls function draw_even_x                             *
 *                  if thickness paramenter is an even number                 *
 ******************************************************************************/
void parallel_x(const int xs, const int ys, const int xe, const int ye,
                const int thickness);

/******************************************************************************
 * draw_odd_x:      Draws alternate parallel lines to given points            *
 *                  against the x-axis by calling line3 function              *
 *                  and thus achieves as thicker line                         *
 *                  as specified by an odd thickness parameter                *
 ******************************************************************************/
void draw_odd_x(const int xs, const int ys, const int xe, const int ye,
                const int thickness);

/******************************************************************************
 * draw_even_x:     Draws alternate parallel lines to given points            *
 *                  against the x-axis by calling line3 function              *
 *                  and thus achieves as thicker line                         *
 *                  as specified by an even thickness parameter               *
 ******************************************************************************/
void draw_even_x(const int xs, const int ys, const int xe, const int ye,
                 const int thickness);

#endif
