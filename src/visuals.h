/******************************************************************************
 * visuals.h:                                                                 *
 *                    Header file contains necessary include directives,      *
 *                    define directives, function signatures                  *
 *                    and their descriptions regarding the display-window     *
 ******************************************************************************/

#ifndef VISUALS_H
#define VISUALS_H

#include <GL/glut.h>
#include "visuals.h"
#include "bresenham.h"

#define WIN_THICKNESS 400     /* Initial display-window thickness */
#define WIN_HEIGHT 400        /* Initial display-window height */
#define INIT_WINDOW_X_POS 1   /* Initial window x position from the top left */
#define INIT_WINDOW_Y_POS 1   /* Initial window y position from the top left */

/******************************************************************************
 * init:              Initiliazes display-window color, projection parameters *
 *                    and world-coordinate reference frame                    *
 ******************************************************************************/
void init(void);

/******************************************************************************
 * winReshapeFnc:     Compensates for a change in display-window dimensions   *
 ******************************************************************************/
void winReshapeFnc(const int newthickness, const int newHeight);

#endif