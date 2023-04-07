<h1>Opengl description</h1>


TABLE 2.2 Colors
TABLE 2.2 Some Common Composite Colors
Composite color  Red Green Blue
Black 0.0 0.0 0.0
Red 1.0 0.0 0.0
Green 0.0 1.0 0.0
Yellow 1.0 1.0 0.0
Blue 0.0 0.0 1.0
Magenta 1.0 0.0 1.0
Cyan 0.0 1.0 1.0
Dark gray 0.25 0.25 0.25
Light gray 0.75 0.75 0.75
Brown 0.60 0.40 0.12
Pumpkin orange 0.98 0.625 0.12
Pastel pink 0.98 0.04 0.7
Barney purple 0.60 0.40 0.70
White 1.0 1.0 1.0


**Types**
GLclampf -> is defined as float under most implementations of OpenGl 




**Functions**

    glClearColor()-> this function sets the color used for clearing the window.
                     void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) - each color can vary from 0.0 to 1.0
                     the last argument is alpha, which is used for blending and special. Transparency refers to an objects capability to allow 
                     light to pass through it.

    glClear() ->    The glClear function clears a particular buffer or combination of buffers. A buffer is a
                    storage area for image information. The red,green,blue components of drawing are usually collectively 
                    referred to as the color buffer or pixel buffer. Color buffer is the place where the displayed image is 
                    stored internally and that clearing the buffer with glClear removes the last drawing from the window.

                    SIDE NOTE ---- glClearColor vs glClear
                        glClear is a Command: which clears the buffer.
                        glClearColor is State Setting: which sets the color value to buffer.



    glFlush() ->    This function casues any unexecuted OpenGLc commands to be executed. 