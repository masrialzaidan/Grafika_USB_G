#include <iostream>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the background color to white
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Calculate the position for the flag to be in the center
    int flagWidth = 500;  // Adjust this according to your flag's width
    int flagHeight = 300; // Adjust this according to your flag's height
    int canvasWidth = glutGet(GLUT_WINDOW_WIDTH);
    int canvasHeight = glutGet(GLUT_WINDOW_HEIGHT);
    int xOffset = (canvasWidth - flagWidth) / 2;
    int yOffset = (canvasHeight - flagHeight) / 2;

    // Draw the red and white stripes
    for (int i = 0; i < 13; i++) {
        if (i % 2 == 0) {
            glColor3f(1.0, 0.0, 0.0); // Red
        }
        else {
            glColor3f(1.0, 1.0, 1.0); // White
        }
        glBegin(GL_POLYGON);
        glVertex2f(xOffset, yOffset + (i * flagHeight / 13));
        glVertex2f(xOffset + flagWidth, yOffset + (i * flagHeight / 13));
        glVertex2f(xOffset + flagWidth, yOffset + ((i + 1) * flagHeight / 13));
        glVertex2f(xOffset, yOffset + ((i + 1) * flagHeight / 13));
        glEnd();
    }

    // Draw the blue rectangle in the upper left corner for the stars
    glColor3f(0.0, 0.0, 0.5); // Dark Blue
    glBegin(GL_POLYGON);
    glVertex2f(xOffset, yOffset + (2 * flagHeight / 5));
    glVertex2f(xOffset + (2 * flagWidth / 5), yOffset + (2 * flagHeight / 5));
    glVertex2f(xOffset + (2 * flagWidth / 5), yOffset + flagHeight);
    glVertex2f(xOffset, yOffset + flagHeight);
    glEnd();

    // Draw 50 white stars in the blue rectangle
    glColor3f(1.0, 1.0, 1.0); // White
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            glBegin(GL_POLYGON);
            for (int k = 0; k < 5; k++) {
                float theta = 6.28318530718 / 5 * k;
                float x = (j * 2 * flagWidth / 50) + (flagWidth / 25) + (flagWidth / 25) * cos(theta);
                float y = flagHeight - ((i * flagHeight / 10) + (flagHeight / 20) + (flagHeight / 20) * sin(theta));
                glVertex2f(xOffset + x, yOffset + y);
            }
            glEnd();
        }
    }

    glFlush();
}

void myinit() {
    // Set the initial background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0); // Red outline and points
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Adjusted the ortho values for the flag's dimensions
}

void myMouse(int button, int state, int x, int y) {
    std::cout << button << " " << state << " " << x << " " << y << std::endl;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600); // Adjusted the window size
    glutInitWindowPosition(100, 100); // Adjusted the window position
    glutCreateWindow("Amerika");
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);

    myinit();
    glutMainLoop();

    return 0;
}
