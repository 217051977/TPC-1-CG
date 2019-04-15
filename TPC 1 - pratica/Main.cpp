/***********************************************************************************************************************
*                                                                                                                      *
*                                                       Main.cpp                                                       *
*                                                                                                                      *
*                                               This program draws a grid                                              *
*                                                                                                                      *
************************************************************************************************************************
*                                                                         *                                            *
*                           Bruno Miguel Dias Leal                        *               Nº 21705197                  *
*                                                                         *                                            *
***********************************************************************************************************************/


//Check which type of machine the code is working in and include/import the necessary library(s)
#include <iostream>
#ifdef __APPLE__
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

//makes implicit the std:: instruction to all std namespace
using namespace std;

/*
 * background color value
 *      red
 *      green
 *      blue
 *      alpha
 * */
double B_RED = 1, B_GREEN = 1, B_BLUE = 1, B_ALPHA = 0;
/*
 * window size
 *      x
 *      y
 * */
double X_WINDOW_SIZE = 800, Y_WINDOW_SIZE = 820;
/*
 * window position
 *      x
 *      y
 * */
double X_WINDOW_POSITION = 100, Y_WINDOW_POSITION = 20;
/*
 * window minimum value view
 *      x
 *      y
 * */
GLfloat X_MIN_VIEW = -500, Y_MIN_VIEW = -500;
/*
 * window maximum value view
 *      x
 *      y
 * */
GLfloat X_MAX_VIEW = 500, Y_MAX_VIEW = 500;
/*
 * window near value view
 * */
GLfloat Z_NEAR_VIEW = -1;
/*
 * window far value view
 * */
GLfloat Z_FAR_VIEW = 1;

/***********************************************************************************************************************
*                                                                                                                      *
*                                                     Create lines                                                     *
*                                                                                                                      *
***********************************************************************************************************************/
//create line
void drawline(float x1, float y1, float x2, float y2) {

	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();

}

/***********************************************************************************************************************
*                                                                                                                      *
*                                                     Create grid                                                      *
*                                                                                                                      *
***********************************************************************************************************************/
//create grid
void drawgrid(int tamanho_quadricula) {

	for (int x = tamanho_quadricula, i = 1; x <= X_MAX_VIEW; x += tamanho_quadricula, i++) {

		if (i % 4 == 0) {

			glLineWidth(3);

		} else if (i % 2 == 0) {
		
			glLineWidth(2);
		
		} else {

			glLineWidth(1);

		}

		glColor3f(0, 0, 0);

		drawline(x, X_MIN_VIEW, x, X_MAX_VIEW);


	}

	for (int x = -tamanho_quadricula, i = 1; x >= X_MIN_VIEW; x -= tamanho_quadricula, i++) {

		if (i % 4 == 0) {

			glLineWidth(3);

		}
		else if (i % 2 == 0) {

			glLineWidth(2);

		}
		else {

			glLineWidth(1);

		}

		glColor3f(0, 0, 0);

		drawline(x, X_MIN_VIEW, x, X_MAX_VIEW);


	}

	for (int y = tamanho_quadricula, i = 1; y <= Y_MAX_VIEW; y += tamanho_quadricula, i++) {

		if (i % 4 == 0) {

			glLineWidth(3);

		}
		else if (i % 2 == 0) {

			glLineWidth(2);

		}
		else {

			glLineWidth(1);

		}

		glColor3f(0, 0, 0);

		drawline(Y_MIN_VIEW, y, Y_MAX_VIEW, y);


	}

	for (int y = -tamanho_quadricula, i = 1; y >= Y_MIN_VIEW; y -= tamanho_quadricula, i++) {

		if (i % 4 == 0) {

			glLineWidth(3);

		}
		else if (i % 2 == 0) {

			glLineWidth(2);

		}
		else {

			glLineWidth(1);

		}

		glColor3f(0, 0, 0);

		drawline(Y_MIN_VIEW, y, Y_MAX_VIEW, y);


	}

	glLineWidth(3);

	glColor3f(0, 1, 0);

	drawline(0, -500, 0, 500);

	glColor3f(1, 0, 0);

	drawline(-500, 0, 500, 0);
	
}

/***********************************************************************************************************************
*                                                                                                                      *
*                                                    Create Polygon                                                    *
*                                                                                                                      *
***********************************************************************************************************************/
//create polygon A
void drawA() {

	glVertex2d(0, 50);
	glVertex2d(0, 200);
	glVertex2d(200, 200);
	glVertex2d(200, 50);

}
//create polygon B
void drawB() {

	glVertex2d(-50, 0);
	glVertex2d(-20, 20);
	glVertex2d(-30, 100);
	glVertex2d(-50, 100);
	glVertex2d(-70, 100);

}

/***********************************************************************************************************************
*                                                                                                                      *
*                                               noun direct draw function                                              *
*                                                                                                                      *
***********************************************************************************************************************/

// Drawing routine.
void drawScene(void) {

	glMatrixMode(GL_MODELVIEW);

	//set the screen to the background color
	glClear(GL_COLOR_BUFFER_BIT);

	drawgrid(25);

	glColor3f(1, 0, 1);

	glBegin(GL_POLYGON);
	drawA();
	glEnd();

	glColor3f(1, 1, 0);

	glBegin(GL_POLYGON);
	drawB();
	glEnd();
	/*
	glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLES);
	drawA();
	glEnd();

	glColor3f(0, 1, 0);

	glBegin(GL_TRIANGLES);
	drawB();
	glEnd();
	*/
	//send the scene to be rendered
	glFlush();

}

// Initialization routine.
void setup(void) {

	//set the color of the background
	glClearColor(B_RED, B_GREEN, B_BLUE, B_ALPHA);

}

// reshapes the OpenGL window
void resize(int w, int h) {

	//set the view -> in this case it fills all the OpenGL Window
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//set to the matrix projection style
	glMatrixMode(GL_PROJECTION);
	//reset the matrix for an identity one
	glLoadIdentity();
	//set the orthographic view (perpendicular) with the size:
	//x_min, x_max, y_min, y_max, z_min, z_max (from the observer perspective!)
	//AKA -> left, right, top, down, near, far
	glOrtho(X_MIN_VIEW, X_MAX_VIEW, Y_MIN_VIEW, Y_MAX_VIEW, Z_NEAR_VIEW, Z_FAR_VIEW);
}

//keyboard input function
void keyInput(unsigned char key, int x, int y) {
	
	switch (key) {

		// if the key 27 (escape) has been pressed, the program ends
		case 27: {

			exit(0);

		} break;

	}

}

// starts the program
int main(int argc, char **argv) {

	//initialize the glut
	glutInit(&argc, argv);
	//set the display mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//set the size of the OpenGL window that it will be open
	glutInitWindowSize(X_WINDOW_SIZE, Y_WINDOW_SIZE);
	//sets the position of the window based on the top left corner
	glutInitWindowPosition(X_WINDOW_POSITION, Y_WINDOW_POSITION);
	//create the OpenGL window has been set up with the name
	glutCreateWindow("Castle.cpp");
	//call the function
	setup();
	//set the function which will get the Scene from
	glutDisplayFunc(drawScene);
	//set the function that is responsible to reshape the window
	glutReshapeFunc(resize);
	//set the function that it will receive from the keyboard
	glutKeyboardFunc(keyInput);
	//starts rendering the Scene
	glutMainLoop();

	//returns 0 when ended
	return 0;

}