<h1>Opengl description</h1>


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

    glGenBuffers() -> returns a newly generated/allocated id of memory location. 

    glGenVertexArrays() -> returns a newly generated/allocated vao



<h1>VAO vs VBO</h1>
VBO is just a buffer, array of bytes.
VAO is just a template,specification that tells us who to use bytes in VBO

Example
| 0 	| VBO 	| POSTION 	|
|---	|---	|---	|
| 1 	| VBO 	| COLOR 	|
| 2 	| VBO 	| TEXTURE 	|
| 3 	| VBO 	| NORMALS 	|

One VAO containing multiple vbo's
