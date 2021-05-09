/******************************************************************************
 * main.c:                                                                    *
 *             Executable code.                                               *
 *                                                                            *
 *             Contains the necessary library include directive,              *
 *             calls the appropriate GLUT functions                           *
 *             to set up the graphics environment                             *
 *             and the init() function that initializes the procedure         *
 ******************************************************************************/

#include "visuals.h"

int main(int argc, char** argv)
{
    glutInit (&argc, argv);                         /* Initialize GLUT */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    /* Set display mode */
    /* Set top-left display-window position */
    glutInitWindowPosition(INIT_WINDOW_X_POS, INIT_WINDOW_Y_POS);
    /* Set display-window thickness and height */
    glutInitWindowSize((GLsizei) WIN_THICKNESS, (GLsizei) WIN_HEIGHT);
    /* Create display window */
    glutCreateWindow("Bresenham with thickness attribute"); 
    init();       /* Execute initialization procedure */
    /* 
     * Register display callback function 
     * to send graphics to display-window
     */
    glutDisplayFunc(displayFnc);
    /* compensation for a change in display-window dimensions */
    glutReshapeFunc(winReshapeFnc);
    glutMainLoop();    /* Display everything and wait */

    return 0;
}