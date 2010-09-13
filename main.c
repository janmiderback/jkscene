/*
Copyright (c) 2010 Jan Miderbaeck and Karim Benchemsi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


#include "sdl.h"
#include "sdl_opengl.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int jklist_test( void );


#define WIDTH  640
#define HEIGHT 480

GLfloat yaw;
GLfloat pitch;
int     level;

static void subdivide
(
    GLfloat point0[3], 
    GLfloat point1[3], 
    GLfloat point2[3], 
    int level
)
{
    int coord;
    GLfloat midpoint[3][3];
    
    /* Don't subdivide any further; just draw the triangle */
    if (level==0) {
        glColor3fv(point0);
        glVertex3fv(point0);
        glColor3fv(point1);
        glVertex3fv(point1);
        glColor3fv(point2);
        glVertex3fv(point2);
        return;
    }

    /* Calculate a midpoint on each edge of the triangle */
    for(coord = 0; coord<3; coord++) {
        midpoint[0][coord] = (point0[coord] + point1[coord])*0.5;
        midpoint[1][coord] = (point1[coord] + point2[coord])*0.5;
        midpoint[2][coord] = (point2[coord] + point0[coord])*0.5;
    }

    /* Subdivide each triangle into three more */    /*     .      */
    level--;                                         /*    /X\     */
    subdivide(point0,midpoint[0],midpoint[2],level); /*   /xxx\    */
    subdivide(point1,midpoint[1],midpoint[0],level); /*  /X\ /X\   */
    subdivide(point2,midpoint[2],midpoint[1],level); /* /XXXVXXX\  */
}


static void repaint()
{
    int i;

    /* Coordinates of the 6 vertices of the octahedron */
    static GLfloat point[6][3] = { 
        {1.0f,0.0f,0.0f},{-1.0f,0.0f,0.0f},
        {0.0f,1.0f,0.0f},{0.0f,-1.0f,0.0f},
        {0.0f,0.0f,1.0f},{0.0f,0.0f,-1.0f}
    };

    /* indices of the vertices of the triangles which make up each of 
     * the 8 faces of the octahedron */
    static int triangle[8][3] = { 
        {2,4,0},{2,0,5},{2,5,1},{2,1,4},{3,0,4},{3,5,0},{3,1,5},{3,4,1}
    };
   
    /* Clear the color plane and the z-buffer */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    /* Move the object 2 units away from the camera */
    glTranslatef(0.0f, 0.0f, -2.0f);

    /* Rotate the object */
    glRotatef(pitch, 1.0f, 0.0f, 0.0f);
    glRotatef(yaw, 0.0f, 1.0f, 0.0f);

    /* Draw the triangles which make up the object */
    glBegin(GL_TRIANGLES);

    for (i=0; i<8; i++) {
        subdivide(point[triangle[i][0]],point[triangle[i][1]],point[triangle[i][2]],level);
    }
    
    glEnd();

    /* increment the rotation every frame */
    yaw = yaw + 0.05;

    /* finally, swap the back and front buffers */
    SDL_GL_SwapBuffers();
}


static void setup_sdl() 
{
    const SDL_VideoInfo *video;

    if( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
        
    /* Quit SDL properly on exit */
    atexit(SDL_Quit);

    /* Get the current video information */
    video = SDL_GetVideoInfo();
    if( video == NULL )
    {
        fprintf(stderr, "Couldn't get video information: %s\n", SDL_GetError());
        exit(1);
    }

    /* Set the minimum requirements for the OpenGL window */
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* Note the SDL_DOUBLEBUF flag is not required to enable double 
     * buffering when setting an OpenGL video mode. 
     * Double buffering is enabled or disabled using the 
     * SDL_GL_DOUBLEBUFFER attribute.
     */
    if( SDL_SetVideoMode( WIDTH, HEIGHT, video->vfmt->BitsPerPixel, SDL_OPENGL ) == 0 )
    {
        fprintf(stderr, "Couldn't set video mode: %s\n", SDL_GetError());
        exit(1);
    }
}


static void setup_opengl()
{
    float aspect = (float)WIDTH / (float)HEIGHT;

    /* Make the viewport cover the whole window */
    glViewport(0, 0, WIDTH, HEIGHT);

    /* Set the camera projection matrix:
     * field of view: 90 degrees
     * near clipping plane at 0.1
     * far clipping plane at 100.0
     */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 0.1, 100.0);
    
    /* We're done with the camera, now matrix operations 
     * will affect the modelview matrix
     * */
    glMatrixMode(GL_MODELVIEW);

    /* set the clear color to gray */
    glClearColor(0.5, 0.5 ,0.5, 0);
    
    /* We want z-buffer tests enabled*/
    glEnable(GL_DEPTH_TEST);

    /* Do draw back-facing polygons*/
    glDisable(GL_CULL_FACE);
}


static void main_loop() 
{
    SDL_Event event;

    while( 1 ) 
    {
        /* process pending events */
        while( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
                case SDL_KEYDOWN:
                    switch ( event.key.keysym.sym )
                    {
                        case SDLK_ESCAPE:
                            exit(0);
                            break;
                     
                        case SDLK_KP_PLUS:
                            level++;
                            if (level > 5) level=5;
                            break;
                    
                        case SDLK_KP_MINUS:
                            level--;
                            if (level < 0) level=0;
                            break;

                        default:
                            //no default key processing
                            //(stops compiler warnings for unhandled SDL keydefs
                            break;
                    }
                    break;

                    case SDL_MOUSEMOTION:
                        pitch += event.motion.yrel;
                        if (pitch < -70) pitch = -70;
                        if (pitch > 70) pitch = 70;
                        break;

                    case SDL_QUIT:
                        exit (0);
                        break;
            }
        }

        /* update the screen */    
        repaint();

        /* Wait 50ms to avoid using up all the CPU time */
        SDL_Delay( 50 );
    }
}


int main( void )
{
#ifdef UNIT_TEST
#define RUN_UNIT_TEST( testFunc ) \
    do { \
        if( testFunc() ) printf( #testFunc " OK\n"); \
        else     printf( #testFunc " FAILED!\n"); \
    } while( 0 )

    printf( "Runnning unit tests...\n" );
    RUN_UNIT_TEST( jklist_test );
    RUN_UNIT_TEST( jkstack_test );
    return 0;
#else
    setup_sdl();
    setup_opengl();

    yaw   = 45;
    pitch = 0;
    level = 2;
    
    main_loop();
        
    return 0;
#endif
}
