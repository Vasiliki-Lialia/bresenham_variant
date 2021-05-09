# Bresenham algorithm variant

Authors: Lialia D. Vasiliki, Liapis Charilaos, Topalis N. Nikolaos

e-mails: livasiliki@uth.gr, chliapis@o365.uth.gr, ntopalis@o365.uth.gr

## Implementation:
**Programming Language: ISO/IEC 14882:199 (C++98)**<br/>
**Reguires OpenGL and freeGLUT**

Draws a red line according to a modified Bresenham algorithm
that works in the first octant with a specific line thickness,
against the minor axis.
Output is displayed inside a window with the help of OpenGL and freeGLUT.

## Default settings:
* Window Thickness: 400<br/>
<em>specified in ./src/visuals.h at ln. 15</em>
* Window Height: 400<br/>
<em>specified in ./src/visuals.h at ln. 16</em>
* Initial Window Position: (1, 1)<br/>
<em>specified in ./src/visuals.h at ln. 17 and ln. 18</em>
* Window Background Color: White<br/>
<em>specified in ./src/visuals.cpp in init() at ln. 6 and ln. 7</em>
* (x1, y1) = (50, 50)<br/>
<em>specified in ./src/bresenham.h at ln. 18 and ln. 19</em>
* (x2, y2) = (351, 350)<br/>
<em>specified in ./src/bresenham.h at ln. 20 and ln. 21</em>
* Line Thickness: 8<br/>
<em>specified in ./src/bresenham.h at ln. 22)</em>
* Line Color: Red<br/>
<em>specified in ./src/bresenham.cpp in setPixel() at ln. 37</em>

## Compile/Run Code via terminal
### Windows (cl compiler needed):
`cls && cl /W4 main.cpp visuals.cpp bresenham.cpp && main`

### Linux (g++ compiler needed):
`clear && g++ -Wall -ansi main.cpp visuals.cpp bresenham.cpp -o main.out -lglut -lGLU -lGL && ./main.out`

## Installing g++ and OpenGL in Linux:
`sudo apt-get install g++`
`sudo apt-get update`
`sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev`
