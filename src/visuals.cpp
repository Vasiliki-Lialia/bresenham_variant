#include "visuals.h"

void init(void)
{
    /* Set display-window color to white */
    glClearColor((GLclampf) 1.0, (GLclampf) 1.0,
                 (GLclampf) 1.0, (GLclampf) 1.0);
    /* Set projection parameters */
    glMatrixMode(GL_PROJECTION);
    /* Define world-coordinate reference frame */
    gluOrtho2D((GLdouble) 0.0, (GLdouble) WIN_THICKNESS,
               (GLdouble) 0.0, (GLdouble) WIN_HEIGHT);
}

void winReshapeFnc(const int newthickness, const int newHeight)
{
    glMatrixMode(GL_PROJECTION);    /* Use orthogonal projection */
    /* 
     * Make sure any previous values for the projection parameters
     * will not affect the new projection settings.
     */
    glLoadIdentity();
    /* Define world-coordinate reference frame */
    gluOrtho2D((GLdouble) 0.0, (GLdouble) newthickness,
               (GLdouble) 0.0, (GLdouble) newHeight);

    glClear(GL_COLOR_BUFFER_BIT);    /* Clear display window */
}