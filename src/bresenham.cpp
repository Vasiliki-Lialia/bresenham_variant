#include "bresenham.h"

void displayFnc(void)
{
    glClear(GL_COLOR_BUFFER_BIT);     /* Clear display window */
    line3(X_START, Y_START, X_END, Y_END, LINE_THICKNESS);
    glFlush();     /* Proccess all OpenGL routine as quickly as possible */
}

void line3(const int xs, const int ys, const int xe, const int ye,
           const int thickness)
{
    int x, y, e, dx, dy;

    dx = (xe - xs);
    dy = (ye - ys);
    e = - (dx >> 1);     /* e = - dx / 2 */
    x = xs;
    y = ys;
    while (x <= xe) {
        /* -dx <= e < 0 */
        setPixel(x, y);

        x = x + 1;
        e = e + dy;
        if (e >= 0) {
            y = y + 1;
            e = e - dx;
        }
    }
    thicken(minor_axis(dx, dy), xs, ys, xe, ye, thickness);
}

void setPixel(const GLint xCoord, const GLint yCoord)
{
    /* Set line segment color to red */
    glColor3f((GLfloat) 1.0, (GLfloat) 0.0, (GLfloat) 0.0);
    glBegin(GL_POINTS);     /* Plotting points */
        /* State the coordinate values for a single position */
        glVertex2i(xCoord, yCoord);
    glEnd();
    errorCheck();
}

void errorCheck(void)
{
    GLenum code;
    const GLubyte *string;

    /* Return the current error code and clear the internal error flag */
    code = glGetError();
    if (code != GL_NO_ERROR) {
        string = gluErrorString(code);
        fprintf(stderr, "OpenGL error: %s\n", string);
    }
}

char minor_axis(const int dx, const int dy)
{
    if (fabs(dx) > fabs(dy))     // minor axis is y
        return 'y';
    else
        return 'x';
}

void thicken(const char axis, const int xs, const int ys, const int xe,
             const int ye, const int thickness)
{
    if (axis == 'y') {
        parallel_y(xs, ys, xe, ye, thickness);
    } else {
        parallel_x(xs, ys, xe, ye, thickness);
    }
}

void parallel_y(const int xs, const int ys, const int xe, const int ye,
                const int thickness)
{
        if (thickness % 2 == 1)
            draw_odd_y(xs, ys, xe, ye, thickness);
        else
            draw_even_y(xs, ys, xe, ye, thickness);
}

void draw_odd_y(const int xs, const int ys, const int xe, const int ye,
                const int thickness)
{
    int l;

    for (l = 1; l <= thickness / 2; l++) {
        line3(xs + l, ys, xe + l, ye, 1);
        line3(xs - l, ys, xe - l, ye, 1);
    }
}

void draw_even_y(const int xs, const int ys, const int xe, const int ye,
                 const int thickness)
{
    int l, d = 1;

    for (l = 1; l < thickness; l++) {
        if ((l % 2 == 1) && l > 1)
            d++;
        line3(int (xs + pow(-1, l) * d), ys, int (xe + pow(-1, l) * d), ye, 1);
    }
}

void parallel_x(const int xs, const int ys, const int xe, const int ye,
                const int thickness)
{
        if (thickness % 2 == 1)
            draw_odd_x(xs, ys, xe, ye, thickness);
        else
            draw_even_x(xs, ys, xe, ye, thickness);
}

void draw_odd_x(const int xs, const int ys, const int xe, const int ye,
                const int thickness)
{
    int l;

    for (l = 1; l <= thickness / 2; l++) {
        line3(xs, ys + l, xe, ye + l, 1);
        line3(xs, ys - l, xe, ye - l, 1);
    }
}

void draw_even_x(const int xs, const int ys, const int xe, const int ye,
                 const int thickness)
{
    int l, d = 1;

    for (l = 1; l < thickness; l++) {
        if ((l % 2 == 1) && l > 1)
            d++;
        line3(xs, int (ys + pow(-1, l) * d), xe, int (ye + pow(-1, l) * d), 1);
    }
}