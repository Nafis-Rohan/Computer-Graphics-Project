#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <cmath>
#include<windows.h>
#include<cstdio>
#include <GL/gl.h>
#include <vector>
#include <cstdlib>
using namespace std;


#define PI 3.141516

bool isRain=false;
bool isSnow=false;


int triangleAmount = 500;
float twicePi = 2.0f * PI;
float angle1=0.0;
float angle2=120.0;
float angle3=240.0;

void circle1(float p1, float q1, float r1)
{
    int i;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glVertex2f (p1,q1);
    for(i= 0; i<=tringle2; i++)
    {
        glVertex2f (
            p1+(r1*cos(i*tp2/tringle2)),
            q1+(r1*sin(i*tp2/tringle2))
        );
    }
    glEnd();
}

void renderBitmapString(float x, float y, float z, void *font, const char *string) {
    char *c;
    glRasterPos3f(x, y, z);
    for (c = (char*)string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void display1_view() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Set text color
    glColor3f(1, 1, 1); // Custom color

    renderBitmapString(-0.3f, 0.6f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Smart City");
    renderBitmapString(-0.5f, 0.50f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "COURSE TEACHER:   MAHFUJUR RAHMAN");
    renderBitmapString(-0.5f, 0.40f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-47900-2  -  ARIFUR RAHMAN Contribution:20%");
    renderBitmapString(-0.5f, 0.30f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-47908-2  -  MD NAFIS ISLAM Contribution:20%");
    renderBitmapString(-0.5f, 0.20f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-46180-1  -  MD. MERAZ AHASAN SHAH Contribution:20%");
    renderBitmapString(-0.5f, 0.10f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-46643-1   -  MD MOSTOFA AL AMIN Contribution:20%");
    renderBitmapString(-0.5f, 0.0f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-47052-1  - NASRUM SHARON Contribution:20%");

    glFlush(); // Render now
}




void sky()
{
    ///sky
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void bus_wheel_circle(GLfloat cx, GLfloat cy, GLfloat radius, int r, int g, int b)
{
    glColor3ub(r,g,b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            cx + (radius * cos(i *  twicePi / triangleAmount)),
            cy + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

void buildings1()                          ///OID-6
{
    ///1st
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(-0.91f, 0.4f);
    glVertex2f(-0.91f, 0.6f);
    glVertex2f(-1.0f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(-0.91f, 0.4f);
    glVertex2f(-0.89f, 0.4f);
    glVertex2f(-0.89f, 0.57f);
    glVertex2f(-0.91f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.47f);
    glVertex2f(-0.97f, 0.47f);
    glVertex2f(-0.97f, 0.52f);
    glVertex2f(-1.0f, 0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.96f, 0.47f);
    glVertex2f(-0.93f, 0.47f);
    glVertex2f(-0.93f, 0.52f);
    glVertex2f(-0.96f, 0.52f);
    glEnd();

    ///2
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(-0.86f, 0.4f);
    glVertex2f(-0.76f, 0.4f);
    glVertex2f(-0.76f, 0.65f);
    glVertex2f(-0.86f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(-0.76f, 0.4f);
    glVertex2f(-0.73f, 0.4f);
    glVertex2f(-0.73f, 0.62f);
    glVertex2f(-0.76f, 0.65f);
    glEnd();

    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.43f);
    glVertex2f(-0.81f, 0.43f);
    glVertex2f(-0.81f, 0.48f);
    glVertex2f(-0.84f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.43f);
    glVertex2f(-0.77f, 0.43f);
    glVertex2f(-0.77f, 0.48f);
    glVertex2f(-0.8f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.5f);
    glVertex2f(-0.81f, 0.5f);
    glVertex2f(-0.81f, 0.55f);
    glVertex2f(-0.84f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(-0.77f, 0.5f);
    glVertex2f(-0.77f, 0.55f);
    glVertex2f(-0.8f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.84f, 0.57f);
    glVertex2f(-0.81f, 0.57f);
    glVertex2f(-0.81f, 0.62f);
    glVertex2f(-0.84f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.57f);
    glVertex2f(-0.77f, 0.57f);
    glVertex2f(-0.77f, 0.62f);
    glVertex2f(-0.8f, 0.62f);
    glEnd();

    ///3
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.0f);
    glVertex2f(-0.72f, 0.4f);
    glVertex2f(-0.62f, 0.4f);
    glVertex2f(-0.62f, 0.71f);
    glVertex2f(-0.72f, 0.71f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex2f(-0.62f, 0.4f);
    glVertex2f(-0.59f, 0.4f);
    glVertex2f(-0.59f, 0.65f);
    glVertex2f(-0.62f, 0.71f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.43f);
    glVertex2f(-0.67f, 0.43f);
    glVertex2f(-0.67f, 0.48f);
    glVertex2f(-0.7f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.43f);
    glVertex2f(-0.63f, 0.43f);
    glVertex2f(-0.63f, 0.48f);
    glVertex2f(-0.66f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.5f);
    glVertex2f(-0.67f, 0.5f);
    glVertex2f(-0.67f, 0.55f);
    glVertex2f(-0.7f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.5f);
    glVertex2f(-0.63f, 0.5f);
    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.66f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.57f);
    glVertex2f(-0.67f, 0.57f);
    glVertex2f(-0.67f, 0.62f);
    glVertex2f(-0.7f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.57f);
    glVertex2f(-0.63f, 0.57f);
    glVertex2f(-0.63f, 0.62f);
    glVertex2f(-0.66f, 0.62f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.7f, 0.64f);
    glVertex2f(-0.67f, 0.64f);
    glVertex2f(-0.67f, 0.69f);
    glVertex2f(-0.7f, 0.69f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.66f, 0.64f);
    glVertex2f(-0.63f, 0.64f);
    glVertex2f(-0.63f, 0.69f);
    glVertex2f(-0.66f, 0.69f);
    glEnd();

    ///4
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2f(-0.58f, 0.4f);
    glVertex2f(-0.48f, 0.4f);
    glVertex2f(-0.48f, 0.5f);
    glVertex2f(-0.58f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2f(-0.48f, 0.4f);
    glVertex2f(-0.47f, 0.4f);
    glVertex2f(-0.47f, 0.48f);
    glVertex2f(-0.48f, 0.5f);
    glEnd();

    ///windows
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.56f, 0.43f);
    glVertex2f(-0.53f, 0.43f);
    glVertex2f(-0.53f, 0.48f);
    glVertex2f(-0.56f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.52f, 0.43f);
    glVertex2f(-0.49f, 0.43f);
    glVertex2f(-0.49f, 0.48f);
    glVertex2f(-0.52f, 0.48f);
    glEnd();

    ///5
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.45f, 0.4f);
    glVertex2f(-0.35f, 0.4f);
    glVertex2f(-0.35f, 0.72f);
    glVertex2f(-0.45f, 0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.35f, 0.4f);
    glVertex2f(-0.33f, 0.4f);
    glVertex2f(-0.33f, 0.67f);
    glVertex2f(-0.35f, 0.72f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.43f);
    glVertex2f(-0.4f, 0.43f);
    glVertex2f(-0.4f, 0.48f);
    glVertex2f(-0.43f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.43f);
    glVertex2f(-0.36f, 0.43f);
    glVertex2f(-0.36f, 0.48f);
    glVertex2f(-0.39f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.5f);
    glVertex2f(-0.4f, 0.5f);
    glVertex2f(-0.4f, 0.55f);
    glVertex2f(-0.43f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.5f);
    glVertex2f(-0.36f, 0.5f);
    glVertex2f(-0.36f, 0.55f);
    glVertex2f(-0.39f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.57f);
    glVertex2f(-0.4f, 0.57f);
    glVertex2f(-0.4f, 0.62f);
    glVertex2f(-0.43f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.57f);
    glVertex2f(-0.36f, 0.57f);
    glVertex2f(-0.36f, 0.62f);
    glVertex2f(-0.39f, 0.62f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.43f, 0.64f);
    glVertex2f(-0.4f, 0.64f);
    glVertex2f(-0.4f, 0.69f);
    glVertex2f(-0.43f, 0.69f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.39f, 0.64f);
    glVertex2f(-0.36f, 0.64f);
    glVertex2f(-0.36f, 0.69f);
    glVertex2f(-0.39f, 0.69f);
    glEnd();

    ///6
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.3f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.18f, 0.4f);
    glVertex2f(-0.18f, 0.57f);
    glVertex2f(-0.2f, 0.6f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.43f);
    glVertex2f(-0.25f, 0.43f);
    glVertex2f(-0.25f, 0.48f);
    glVertex2f(-0.28f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.43f);
    glVertex2f(-0.21f, 0.43f);
    glVertex2f(-0.21f, 0.48f);
    glVertex2f(-0.24f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.28f, 0.5f);
    glVertex2f(-0.25f, 0.5f);
    glVertex2f(-0.25f, 0.55f);
    glVertex2f(-0.28f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24f, 0.5f);
    glVertex2f(-0.21f, 0.5f);
    glVertex2f(-0.21f, 0.55f);
    glVertex2f(-0.24f, 0.55f);
    glEnd();

    ///7
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.0f);
    glVertex2f(-0.17f, 0.4f);
    glVertex2f(-0.07f, 0.4f);
    glVertex2f(-0.07f, 0.65f);
    glVertex2f(-0.17f, 0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.0f);
    glVertex2f(-0.07f, 0.4f);
    glVertex2f(-0.06f, 0.4f);
    glVertex2f(-0.06f, 0.62f);
    glVertex2f(-0.07f, 0.65f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.43f);
    glVertex2f(-0.13f, 0.43f);
    glVertex2f(-0.13f, 0.48f);
    glVertex2f(-0.16f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.43f);
    glVertex2f(-0.09f, 0.43f);
    glVertex2f(-0.09f, 0.48f);
    glVertex2f(-0.12f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.5f);
    glVertex2f(-0.13f, 0.5f);
    glVertex2f(-0.13f, 0.55f);
    glVertex2f(-0.16f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.5f);
    glVertex2f(-0.09f, 0.5f);
    glVertex2f(-0.09f, 0.55f);
    glVertex2f(-0.12f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.16f, 0.57f);
    glVertex2f(-0.13f, 0.57f);
    glVertex2f(-0.13f, 0.62f);
    glVertex2f(-0.16f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.57f);
    glVertex2f(-0.09f, 0.57f);
    glVertex2f(-0.09f, 0.62f);
    glVertex2f(-0.12f, 0.62f);
    glEnd();

    ///8
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.4f);
    glVertex2f(-0.04f, 0.4f);
    glVertex2f(0.04f, 0.4f);
    glVertex2f(0.04f, 0.71f);
    glVertex2f(-0.04f, 0.71f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.1f);
    glVertex2f(0.04f, 0.4f);
    glVertex2f(0.043f, 0.4f);
    glVertex2f(0.043f, 0.65f);
    glVertex2f(0.04f, 0.71f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.43f);
    glVertex2f(-0.01f, 0.43f);
    glVertex2f(-0.01f, 0.48f);
    glVertex2f(-0.03f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.43f);
    glVertex2f(0.03f, 0.43f);
    glVertex2f(0.03f, 0.48f);
    glVertex2f(0.01f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.5f);
    glVertex2f(-0.01f, 0.5f);
    glVertex2f(-0.01f, 0.55f);
    glVertex2f(-0.03f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.5f);
    glVertex2f(0.03f, 0.5f);
    glVertex2f(0.03f, 0.55f);
    glVertex2f(0.01f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.57f);
    glVertex2f(-0.01f, 0.57f);
    glVertex2f(-0.01f, 0.62f);
    glVertex2f(-0.03f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.57f);
    glVertex2f(0.03f, 0.57f);
    glVertex2f(0.03f, 0.62f);
    glVertex2f(0.01f, 0.62f);
    glEnd();

    ///p4
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.03f, 0.64f);
    glVertex2f(-0.01f, 0.64f);
    glVertex2f(-0.01f, 0.69f);
    glVertex2f(-0.03f, 0.69f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.01f, 0.64f);
    glVertex2f(0.03f, 0.64f);
    glVertex2f(0.03f, 0.69f);
    glVertex2f(0.01f, 0.69f);
    glEnd();

    ///9
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.08f, 0.4f);
    glVertex2f(0.18f, 0.4f);
    glVertex2f(0.18f, 0.6f);
    glVertex2f(0.08f, 0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(0.07f, 0.4f);
    glVertex2f(0.08f, 0.4f);
    glVertex2f(0.08f, 0.6f);
    glVertex2f(0.07f, 0.55f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.43f);
    glVertex2f(0.12f, 0.43f);
    glVertex2f(0.12f, 0.48f);
    glVertex2f(0.09f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.43f);
    glVertex2f(0.16f, 0.43f);
    glVertex2f(0.16f, 0.48f);
    glVertex2f(0.13f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.09f, 0.5f);
    glVertex2f(0.12f, 0.5f);
    glVertex2f(0.12f, 0.55f);
    glVertex2f(0.09f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.13f, 0.5f);
    glVertex2f(0.16f, 0.5f);
    glVertex2f(0.16f, 0.55f);
    glVertex2f(0.13f, 0.55f);
    glEnd();

    ///10
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2f(0.22f, 0.4f);
    glVertex2f(0.32f, 0.4f);
    glVertex2f(0.32f, 0.65f);
    glVertex2f(0.22f, 0.65f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.22f, 0.4f);
    glVertex2f(0.22f, 0.65f);
    glVertex2f(0.2f, 0.62f);
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.43f);
    glVertex2f(0.27f, 0.43f);
    glVertex2f(0.27f, 0.48f);
    glVertex2f(0.24f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.28f, 0.43f);
    glVertex2f(0.31f, 0.43f);
    glVertex2f(0.31f, 0.48f);
    glVertex2f(0.28f, 0.48f);
    glEnd();

    ///p2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.5f);
    glVertex2f(0.27f, 0.5f);
    glVertex2f(0.27f, 0.55f);
    glVertex2f(0.24f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.28f, 0.5f);
    glVertex2f(0.31f, 0.5f);
    glVertex2f(0.31f, 0.55f);
    glVertex2f(0.28f, 0.55f);
    glEnd();

    ///p3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.24f, 0.57f);
    glVertex2f(0.27f, 0.57f);
    glVertex2f(0.27f, 0.62f);
    glVertex2f(0.24f, 0.62f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.28f, 0.57f);
    glVertex2f(0.31f, 0.57f);
    glVertex2f(0.31f, 0.62f);
    glVertex2f(0.28f, 0.62f);
    glEnd();
}



/////////////////////////////////////train////////////////////////
float r_l_train_position=0;
float r_l_train_speed=0.0;

void r_l_train()
{
glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(r_l_train_position-0.8,0,0);
    glScalef(-1,1,0);

glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.695);
    glVertex2f(0.05, 0.695);
    glVertex2f(0.05 ,0.699);
    glVertex2f(0.01, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.025, 0.677);
    glVertex2f(0.028, 0.677);
    glVertex2f(0.05 ,0.685);
    glVertex2f(0.045, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.045, 0.685);
    glVertex2f(0.05, 0.685);
    glVertex2f(0.025 ,0.699);
    glVertex2f(0.023, 0.699);
    glEnd();

////////////////////////////////////////////body 1
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.0, 0.67);
    glVertex2f(0.1, 0.67);
    glVertex2f(.1 ,0.677);
    glVertex2f(0, 0.677);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.0, 0.63);
    glVertex2f(0.1, 0.63);
    glVertex2f(.1 ,0.67);
    glVertex2f(0, 0.67);
    glEnd();

    /////////////////////dore1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.635);
    glVertex2f(0.025, 0.635);
    glVertex2f(.025 ,0.665);
    glVertex2f(0.01, 0.665);
    glEnd();
    //////////////////////windows1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.03, 0.64);
    glVertex2f(0.06, 0.64);
    glVertex2f(.06 ,0.665);
    glVertex2f(0.03, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.065, 0.635);
    glVertex2f(0.08, 0.635);
    glVertex2f(.08 ,0.665);
    glVertex2f(0.065, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.085, 0.64);
    glVertex2f(0.1, 0.64);
    glVertex2f(.1,0.665);
    glVertex2f(0.085, 0.665);
    glEnd();
    /////////////////////////////////////////body 2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.105, 0.63);
    glVertex2f(0.2, 0.63);
    glVertex2f(.2 ,0.67);
    glVertex2f(0.105, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.105, 0.67);
    glVertex2f(0.2, 0.67);
    glVertex2f(.2 ,0.677);
    glVertex2f(0.105, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.11, 0.635);
    glVertex2f(0.125, 0.635);
    glVertex2f(.125 ,0.665);
    glVertex2f(0.11, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.13, 0.64);
    glVertex2f(0.16, 0.64);
    glVertex2f(.16 ,0.665);
    glVertex2f(0.13, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.165, 0.635);
    glVertex2f(0.18, 0.635);
    glVertex2f(.18 ,0.665);
    glVertex2f(0.165, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.185, 0.64);
    glVertex2f(0.2, 0.64);
    glVertex2f(.2,0.665);
    glVertex2f(0.185, 0.665);
    glEnd();
    /////////////////////////////body 3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.205, 0.63);
    glVertex2f(0.3, 0.63);
    glVertex2f(.3 ,0.67);
    glVertex2f(0.205, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.205, 0.67);
    glVertex2f(0.3, 0.67);
    glVertex2f(.3,0.677);
    glVertex2f(0.205, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.21, 0.635);
    glVertex2f(0.225, 0.635);
    glVertex2f(.225 ,0.665);
    glVertex2f(0.21, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.23, 0.64);
    glVertex2f(0.26, 0.64);
    glVertex2f(.26 ,0.665);
    glVertex2f(0.23, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.265, 0.635);
    glVertex2f(0.28, 0.635);
    glVertex2f(.28 ,0.665);
    glVertex2f(0.265, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.285, 0.64);
    glVertex2f(0.3, 0.64);
    glVertex2f(.3,0.665);
    glVertex2f(0.285, 0.665);
    glEnd();
    //////////////////////////////////////body 4

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.37, 0.695);
    glVertex2f(0.41, 0.695);
    glVertex2f(0.41 ,0.699);
    glVertex2f(0.37, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.389, 0.677);
    glVertex2f(0.391, 0.677);
    glVertex2f(0.41 ,0.685);
    glVertex2f(0.399, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.40, 0.685);
    glVertex2f(0.41, 0.685);
    glVertex2f(0.391 ,0.699);
    glVertex2f(0.389, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.305, 0.67);
    glVertex2f(0.41, 0.67);
    glVertex2f(.41 ,0.677);
    glVertex2f(0.305, 0.677);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.305, 0.63);
    glVertex2f(0.41, 0.63);
    glVertex2f(.41,0.67);
    glVertex2f(0.305, 0.67);
    glEnd();

    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.31, 0.635);
    glVertex2f(0.325, 0.635);
    glVertex2f(.325 ,0.665);
    glVertex2f(0.31, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.33, 0.64);
    glVertex2f(0.36, 0.64);
    glVertex2f(.36 ,0.665);
    glVertex2f(0.33, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.365, 0.635);
    glVertex2f(0.38, 0.635);
    glVertex2f(.38 ,0.665);
    glVertex2f(0.365, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.385, 0.64);
    glVertex2f(0.4, 0.64);
    glVertex2f(.4,0.665);
    glVertex2f(0.385, 0.665);
    glEnd();

    glPopMatrix();
    glLoadIdentity();
    //glPopMatrix();
}

float l_r_train_position=0;
float l_r_train_speed=0.02;


void l_r_train(){

glColor3ub(155,150,150);
glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(l_r_train_position-0.6,-0.0,0);




glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.695);
    glVertex2f(0.05, 0.695);
    glVertex2f(0.05 ,0.699);
    glVertex2f(0.01, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.025, 0.677);
    glVertex2f(0.028, 0.677);
    glVertex2f(0.05 ,0.685);
    glVertex2f(0.045, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.045, 0.685);
    glVertex2f(0.05, 0.685);
    glVertex2f(0.025 ,0.699);
    glVertex2f(0.023, 0.699);
    glEnd();

////////////////////////////////////////////body 1
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.0, 0.67);
    glVertex2f(0.1, 0.67);
    glVertex2f(.1 ,0.677);
    glVertex2f(0, 0.677);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.0, 0.63);
    glVertex2f(0.1, 0.63);
    glVertex2f(.1 ,0.67);
    glVertex2f(0, 0.67);
    glEnd();

    /////////////////////dore1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.01, 0.635);
    glVertex2f(0.025, 0.635);
    glVertex2f(.025 ,0.665);
    glVertex2f(0.01, 0.665);
    glEnd();
    //////////////////////windows1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.03, 0.64);
    glVertex2f(0.06, 0.64);
    glVertex2f(.06 ,0.665);
    glVertex2f(0.03, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.065, 0.635);
    glVertex2f(0.08, 0.635);
    glVertex2f(.08 ,0.665);
    glVertex2f(0.065, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.085, 0.64);
    glVertex2f(0.1, 0.64);
    glVertex2f(.1,0.665);
    glVertex2f(0.085, 0.665);
    glEnd();
    /////////////////////////////////////////body 2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.105, 0.63);
    glVertex2f(0.2, 0.63);
    glVertex2f(.2 ,0.67);
    glVertex2f(0.105, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.105, 0.67);
    glVertex2f(0.2, 0.67);
    glVertex2f(.2 ,0.677);
    glVertex2f(0.105, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.11, 0.635);
    glVertex2f(0.125, 0.635);
    glVertex2f(.125 ,0.665);
    glVertex2f(0.11, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.13, 0.64);
    glVertex2f(0.16, 0.64);
    glVertex2f(.16 ,0.665);
    glVertex2f(0.13, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.165, 0.635);
    glVertex2f(0.18, 0.635);
    glVertex2f(.18 ,0.665);
    glVertex2f(0.165, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.185, 0.64);
    glVertex2f(0.2, 0.64);
    glVertex2f(.2,0.665);
    glVertex2f(0.185, 0.665);
    glEnd();
    /////////////////////////////body 3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.205, 0.63);
    glVertex2f(0.3, 0.63);
    glVertex2f(.3 ,0.67);
    glVertex2f(0.205, 0.67);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.205, 0.67);
    glVertex2f(0.3, 0.67);
    glVertex2f(.3,0.677);
    glVertex2f(0.205, 0.677);
    glEnd();
    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.21, 0.635);
    glVertex2f(0.225, 0.635);
    glVertex2f(.225 ,0.665);
    glVertex2f(0.21, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.23, 0.64);
    glVertex2f(0.26, 0.64);
    glVertex2f(.26 ,0.665);
    glVertex2f(0.23, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.265, 0.635);
    glVertex2f(0.28, 0.635);
    glVertex2f(.28 ,0.665);
    glVertex2f(0.265, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.285, 0.64);
    glVertex2f(0.3, 0.64);
    glVertex2f(.3,0.665);
    glVertex2f(0.285, 0.665);
    glEnd();
    //////////////////////////////////////body 4

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.37, 0.695);
    glVertex2f(0.41, 0.695);
    glVertex2f(0.41 ,0.699);
    glVertex2f(0.37, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.389, 0.677);
    glVertex2f(0.391, 0.677);
    glVertex2f(0.41 ,0.685);
    glVertex2f(0.399, 0.685);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.40, 0.685);
    glVertex2f(0.41, 0.685);
    glVertex2f(0.391 ,0.699);
    glVertex2f(0.389, 0.699);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex2f(0.305, 0.67);
    glVertex2f(0.41, 0.67);
    glVertex2f(.41 ,0.677);
    glVertex2f(0.305, 0.677);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0.305, 0.63);
    glVertex2f(0.41, 0.63);
    glVertex2f(.41,0.67);
    glVertex2f(0.305, 0.67);
    glEnd();

    /////////////////////dore3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.31, 0.635);
    glVertex2f(0.325, 0.635);
    glVertex2f(.325 ,0.665);
    glVertex2f(0.31, 0.665);
    glEnd();
    //////////////////////windows3
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.33, 0.64);
    glVertex2f(0.36, 0.64);
    glVertex2f(.36 ,0.665);
    glVertex2f(0.33, 0.665);
    glEnd();
/////////////////////dore2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.365, 0.635);
    glVertex2f(0.38, 0.635);
    glVertex2f(.38 ,0.665);
    glVertex2f(0.365, 0.665);
    glEnd();
    //////////////////////windows2
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0.385, 0.64);
    glVertex2f(0.4, 0.64);
    glVertex2f(.4,0.665);
    glVertex2f(0.385, 0.665);
    glEnd();

    glPopMatrix();
    glLoadIdentity();
    // glPopMatrix();

}

void bridge()
{
   glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-1, 0.6);
    glVertex2f(1, 0.6);
    glVertex2f(1 ,0.63);
    glVertex2f(-1, 0.63);
    glEnd();


}

void Wire()
{glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-1, 0.7);
    glVertex2f(1, 0.7);
    glVertex2f(1 ,0.702);
    glVertex2f(-1, 0.702);
    glEnd();

}
void bridge_wirepillar()

{
float ww = 100;
    ///1
    ///pillar
    float L = 140.0;
    float l = 40.0;
    glScalef(0.005,0.005,0);
     ///1
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f,260.0f-L);
    glVertex2f(62.0f,282.0f-L);
    glEnd();



    ///2
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-l,260.0f-L);
    glVertex2f(62.0f-l,282.0f-L);
    glEnd();


    ///3

    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-2*l,260.0f-L);
    glVertex2f(62.0f-2*l,282.0f-L);
    glEnd();


    ///4
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-3*l,260.0f-L);
    glVertex2f(62.0f-3*l,282.0f-L);
    glEnd();





    ///5
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-4*l,260.0f-L);
    glVertex2f(62.0f-4*l,282.0f-L);
    glEnd();


    ///6
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-5*l,260.0f-L);
    glVertex2f(62.0f-5*l,282.0f-L);
    glEnd();

    ///7
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-6*l,260.0f-L);
    glVertex2f(62.0f-6*l,282.0f-L);
    glEnd();



    ///8
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+l,80.0f-L);
    glVertex2f(62.0f+l,282.0f-L);
    glEnd();


    ///9
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+2.2*l,260.0f-L);
    glVertex2f(62.0f+2.2*l,282.0f-L);
    glEnd();


    ///10
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+3*l,260.0f-L);
    glVertex2f(62.0f+3*l,282.0f-L);
    glEnd();

    glLoadIdentity();
}
////////////////////////////////bench

void road_border()
{ glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(-1, 0.49);
    glVertex2f(1, 0.49);
    glVertex2f(1 ,0.50);
    glVertex2f(-1, 0.50);
    glEnd();


//////////////////////////////////////white line
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-1, 0.49);
    glVertex2f(-0.98, 0.49);
    glVertex2f(-0.98 ,0.50);
    glVertex2f(-1, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.9, 0.49);
    glVertex2f(-0.8, 0.49);
    glVertex2f(-0.8 ,0.50);
    glVertex2f(-0.9, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.7, 0.49);
    glVertex2f(-0.6, 0.49);
    glVertex2f(-0.6 ,0.50);
    glVertex2f(-0.7, 0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.5, 0.49);
    glVertex2f(-0.4, 0.49);
    glVertex2f(-0.4 ,0.50);
    glVertex2f(-0.5, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.3, 0.49);
    glVertex2f(-0.2, 0.49);
    glVertex2f(-0.2 ,0.50);
    glVertex2f(-0.3, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.1, 0.49);
    glVertex2f(-0.05, 0.49);
    glVertex2f(-0.05 ,0.50);
    glVertex2f(-0.1, 0.50);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.0, 0.49);
    glVertex2f(0.05, 0.49);
    glVertex2f(0.05,0.50);
    glVertex2f(0.0, 0.50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.15, 0.49);
    glVertex2f(0.2, 0.49);
    glVertex2f(0.2 ,0.50);
    glVertex2f(0.15, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.35, 0.49);
    glVertex2f(0.4, 0.49);
    glVertex2f(0.4 ,0.50);
    glVertex2f(0.35, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.55, 0.49);
    glVertex2f(0.6, 0.49);
    glVertex2f(0.6 ,0.50);
    glVertex2f(0.55, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.65, 0.49);
    glVertex2f(0.7, 0.49);
    glVertex2f(0.7 ,0.50);
    glVertex2f(0.65, 0.50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0.85, 0.49);
    glVertex2f(0.9, 0.49);
    glVertex2f(0.9 ,0.50);
    glVertex2f(0.85, 0.50);
    glEnd();
    }


    void road1()
    {glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(-1, 0.30);
    glVertex2f(1, 0.30);
    glVertex2f(1 ,0.49);
    glVertex2f(-1, 0.49);
    glEnd();
        }
    float public_bus_position=0;
float public_bus_speed=0.01;
        void public_bus()
    {glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(public_bus_position-0.6,-0.0,0);
    ////////////////////////////body

        glBegin(GL_QUADS);
   glColor3f(1, 0, 0);
    glVertex2f(-.9, 0.47);
    glVertex2f(-0.67, 0.47);
    glVertex2f(-.67,0.55);
    glVertex2f(-0.9, 0.55);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
    glVertex2f(-.89, 0.49);
    glVertex2f(-0.695, 0.49);
    glVertex2f(-.695 ,0.53);
    glVertex2f(-0.89, 0.53);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
    glVertex2f(-.69, 0.48);
    glVertex2f(-0.67, 0.48);
    glVertex2f(-.67,0.53);
    glVertex2f(-0.69, 0.53);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
   glVertex2f(-0.68, 0.545);
    glVertex2f(-.65, 0.545);
    glVertex2f(-.65,0.55);
    glVertex2f(-0.68, 0.55);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(0, 0, 0);
   glVertex2f(-0.658, 0.52);
    glVertex2f(-.65, 0.52);
    glVertex2f(-.65,0.55);
    glVertex2f(-0.658, 0.55);
    glEnd();

    ///////GLfloat cx, GLfloat cy, GLfloat radius, int r, int g, int b
    bus_wheel_circle(-0.87,0.47,0.015,1,1,1);
    bus_wheel_circle(-0.83,0.47,0.015,1,1,1);
    bus_wheel_circle(-0.71,0.47,0.015,1,1,1);

     glPopMatrix();
    glLoadIdentity();
    }
void road_marking()
    {
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-1, 0.445);
    glVertex2f(-0.2, 0.445);
    glVertex2f(-.2 ,0.45);
    glVertex2f(-1, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-0.15, 0.445);
    glVertex2f(-0.1, 0.445);
    glVertex2f(-.1 ,0.45);
    glVertex2f(-0.15, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-0.08, 0.445);
    glVertex2f(-0.05, 0.445);
    glVertex2f(-.05,0.45);
    glVertex2f(-0.08, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(-0.03, 0.445);
    glVertex2f(0.01, 0.445);
    glVertex2f(0.01,0.45);
    glVertex2f(-0.03, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(0.03, 0.445);
    glVertex2f(0.07, 0.445);
    glVertex2f(.07,0.45);
    glVertex2f(0.03, 0.45);
    glEnd();
    glBegin(GL_QUADS);
   glColor3f(255, 255, 0);
    glVertex2f(0.1, 0.445);
    glVertex2f(1, 0.445);
    glVertex2f(1 ,0.45);
    glVertex2f(0.1, 0.45);
    glEnd();

        }////////////////////////////////////////////pillar fence
void p_fence()                            ///OID-15
{   glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(-1, 0.52);
    glVertex2f(-0.15, 0.52);
    glVertex2f(-0.15 ,0.522);
    glVertex2f(-1, 0.522);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0.15, 0.52);
    glVertex2f(1, 0.52);
    glVertex2f(1 ,0.522);
    glVertex2f(0.15, 0.522);
    glEnd();

    float L = 0.05;
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.98f,0.52f);
    glVertex2f(-0.98f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.94f,0.52f);
    glVertex2f(-0.94f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.9f,0.52f);
    glVertex2f(-0.9f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f,0.52f);
    glVertex2f(-0.85f,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+L,0.52f);
    glVertex2f(-0.85f+L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.84f+2*L,0.52f);
    glVertex2f(-0.84f+2*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+3*L,0.52f);
    glVertex2f(-0.85f+3*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+4*L,0.52f);
    glVertex2f(-0.85f+4*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+5*L,0.52f);
    glVertex2f(-0.85f+5*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.84f+6*L,0.52f);
    glVertex2f(-0.84f+6*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+7*L,0.52f);
    glVertex2f(-0.85f+7*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+8*L,0.52f);
    glVertex2f(-0.85f+8*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+9*L,0.52f);
    glVertex2f(-0.85f+9*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.84f+10*L,0.52f);
    glVertex2f(-0.84f+10*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+11*L,0.52f);
    glVertex2f(-0.85f+11*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+12*L,0.52f);
    glVertex2f(-0.85f+12*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+13*L,0.52f);
    glVertex2f(-0.85f+13*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+14*L,0.52f);
    glVertex2f(-0.85f+14*L,0.50f);
    glEnd();

    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+21*L,0.52f);
    glVertex2f(-0.85f+21*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+22*L,0.52f);
    glVertex2f(-0.85f+22*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+23*L,0.52f);
    glVertex2f(-0.85f+23*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+24*L,0.52f);
    glVertex2f(-0.85f+24*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+25*L,0.52f);
    glVertex2f(-0.85f+25*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+26*L,0.52f);
    glVertex2f(-0.85f+26*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+27*L,0.52f);
    glVertex2f(-0.85f+27*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+28*L,0.52f);
    glVertex2f(-0.85f+28*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+29*L,0.52f);
    glVertex2f(-0.85f+29*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+30*L,0.52f);
    glVertex2f(-0.85f+30*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+31*L,0.52f);
    glVertex2f(-0.85f+31*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+32*L,0.52f);
    glVertex2f(-0.85f+32*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+33*L,0.52f);
    glVertex2f(-0.85f+33*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+34*L,0.52f);
    glVertex2f(-0.85f+34*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+35*L,0.52f);
    glVertex2f(-0.85f+35*L,0.50f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+36*L,0.52f);
    glVertex2f(-0.85f+36*L,0.50f);
    glEnd();



}
//////////////////////////////////////////////////////
void pillar()
{   //////p1
glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.97, 0.57);
    glVertex2f(-0.95 ,0.57);
    glVertex2f(-0.92 ,0.63);
    glVertex2f(-1, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.97, 0.5);
    glVertex2f(-0.95, 0.5);
    glVertex2f(-0.95 ,0.57);
    glVertex2f(-0.97, 0.57);
    glEnd();

//////p2

glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.77, 0.57);
    glVertex2f(-0.75 ,0.57);
    glVertex2f(-0.72 ,0.63);
    glVertex2f(-0.8, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.77, 0.5);
    glVertex2f(-0.75, 0.5);
    glVertex2f(-0.75 ,0.57);
    glVertex2f(-0.77, 0.57);
    glEnd();
    //////p3


glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.57, 0.57);
    glVertex2f(-0.55 ,0.57);
    glVertex2f(-0.52 ,0.63);
    glVertex2f(-0.6, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.57, 0.5);
    glVertex2f(-0.55, 0.5);
    glVertex2f(-0.55 ,0.57);
    glVertex2f(-0.57, 0.57);
    glEnd();
    //////p4

glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.37, 0.57);
    glVertex2f(-0.35 ,0.57);
    glVertex2f(-0.32 ,0.63);
    glVertex2f(-0.4, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.37, 0.5);
    glVertex2f(-0.35, 0.5);
    glVertex2f(-0.35 ,0.57);
    glVertex2f(-0.37, 0.57);
    glEnd();
    //////p5

glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
     glVertex2f(-0.17, 0.57);
    glVertex2f(-0.15 ,0.57);
    glVertex2f(-0.12 ,0.63);
    glVertex2f(-0.2, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(-0.17, 0.5);
    glVertex2f(-0.15, 0.5);
    glVertex2f(-0.15 ,0.57);
    glVertex2f(-0.17, 0.57);
    glEnd();
    //////p6


glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.15 ,0.57);
     glVertex2f(0.17, 0.57);
    glVertex2f(0.2 ,0.63);
    glVertex2f(0.12, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.17, 0.5);
    glVertex2f(0.15, 0.5);
    glVertex2f(0.15 ,0.57);
    glVertex2f(0.17, 0.57);
    glEnd();
    //////p7
glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.35 ,0.57);
     glVertex2f(0.37, 0.57);
    glVertex2f(0.4 ,0.63);
    glVertex2f(0.32, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.37, 0.5);
    glVertex2f(0.35, 0.5);
    glVertex2f(0.35 ,0.57);
    glVertex2f(0.37, 0.57);
    glEnd();
    //////p9
glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);
    glVertex2f(0.65 ,0.57);
     glVertex2f(0.67, 0.57);
    glVertex2f(0.7 ,0.63);
    glVertex2f(0.62, 0.63);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00,0.17,0.20);

    glVertex2f(0.65, 0.5);
    glVertex2f(0.67, 0.5);
     glVertex2f(0.67, 0.57);
    glVertex2f(0.65 ,0.57);

    glEnd();


}

void buildings()                          ///OID-6
{   ///////////////////////////////1st
  glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.6f);
    glVertex2f(0.0f, 0.50f);
    glVertex2f(0.1f, 0.50f);
    glVertex2f(0.1f, 0.80f);
    glVertex2f(0.0f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(0.1f, 0.50f);
    glVertex2f(0.15f, 0.50f);
    glVertex2f(0.15f, 0.78f);
    glVertex2f(0.1f, 0.80f);
    glEnd();
    //////////////////////////////////1st windows

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.05f, 0.60f);
    glVertex2f(0.0f, 0.60f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05f, 0.60f);
    glVertex2f(0.1f, 0.60f);
    glVertex2f(0.1f, 0.65f);
    glVertex2f(0.05f, 0.65f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.005f, 0.65f);
    glVertex2f(0.05f, 0.65f);
    glVertex2f(0.05f, 0.70f);
    glVertex2f(0.005f, 0.70f);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05f, 0.70f);
    glVertex2f(0.1f, 0.70f);
    glVertex2f(0.1f, 0.75f);
    glVertex2f(0.05f, 0.75f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.005f, 0.75f);
    glVertex2f(0.05f, 0.75f);
    glVertex2f(0.05f, 0.795f);
    glVertex2f(0.005f, 0.795f);
    glEnd();



    ///////////////////////////////1st
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(0.2f, 0.50f);
    glVertex2f(0.3f, 0.50f);
    glVertex2f(0.3f, 0.80f);
    glVertex2f(0.2f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.6f);
    glVertex2f(0.2f, 0.50f);
    glVertex2f(0.3f, 0.50f);
    glVertex2f(0.3f, 0.80f);
    glVertex2f(0.2f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.4f, 0.0f, 0.4f);
    glVertex2f(0.2f, 0.50f);
    glVertex2f(0.22f, 0.50f);
    glVertex2f(0.22f, 0.78f);
    glVertex2f(0.2f, 0.80f);
    glEnd();

    ///////////////////////////////1st
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(0.35f, 0.50f);
    glVertex2f(0.65f, 0.50f);
    glVertex2f(0.65f, 0.80f);
    glVertex2f(0.35f, 0.80f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.50f);
    glVertex2f(0.64f, 0.50f);
    glVertex2f(0.64f, 0.54f);
    glVertex2f(0.36f, 0.54f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.55f);
    glVertex2f(0.64f, 0.55f);
    glVertex2f(0.64f, 0.59f);
    glVertex2f(0.36f, 0.59f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.60f);
    glVertex2f(0.64f, 0.60f);
    glVertex2f(0.64f, 0.64f);
    glVertex2f(0.36f, 0.64f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.65f);
    glVertex2f(0.64f, 0.65f);
    glVertex2f(0.64f, 0.69f);
    glVertex2f(0.36f, 0.69f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.70f);
    glVertex2f(0.64f, 0.70f);
    glVertex2f(0.64f, 0.74f);
    glVertex2f(0.36f, 0.74f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.36f, 0.75f);
    glVertex2f(0.64f, 0.75f);
    glVertex2f(0.64f, 0.79f);
    glVertex2f(0.36f, 0.79f);
    glEnd();

    glBegin(GL_QUADS);
     glColor3f(0.00,0.40,0.80);
    glVertex2f(0.42f, 0.50f);
    glVertex2f(0.45f, 0.50f);
    glVertex2f(0.45f, 0.79f);
    glVertex2f(0.42f, 0.79f);
    glEnd();
     glBegin(GL_QUADS);
     glColor3f(0.00,0.40,0.80);
    glVertex2f(0.55f, 0.50f);
    glVertex2f(0.57f, 0.50f);
    glVertex2f(0.57f, 0.79f);
    glVertex2f(0.55f, 0.79f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.0f, 0.3f);
    glVertex2f(0.42f, 0.80f);
    glVertex2f(0.57f, 0.80f);
    glVertex2f(0.57f, 0.85f);
    glVertex2f(0.42f, 0.85f);
    glEnd();
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.6f, 0.6f);
   glVertex2f(0.42f, 0.85f);
    glVertex2f(0.57f, 0.85f);

     glVertex2f(0.5f, 0.90f);
    glVertex2f(0.5f, 0.90f);
    glEnd();

///////////////////////////////1st
    glBegin(GL_QUADS);
     glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(0.7f, 0.50f);
    glVertex2f(0.85f, 0.50f);
    glVertex2f(0.85f, 0.90f);
    glVertex2f(0.7f, 0.90f);
    glEnd();
    //windows 4
    glBegin(GL_QUADS);
     glColor3f(0.00f,0.50f,0.60f);
    glVertex2f(0.77f, 0.50f);
    glVertex2f(0.79f, 0.50f);
    glVertex2f(0.79f, 0.90f);
    glVertex2f(0.77f, 0.90f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.50f);
    glVertex2f(0.85f, 0.50f);
    glVertex2f(0.85f, 0.550f);
    glVertex2f(0.7f, 0.550f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.560f);
    glVertex2f(0.85f, 0.560f);
    glVertex2f(0.85f, 0.60f);
    glVertex2f(0.7f, 0.600f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.620f);
    glVertex2f(0.85f, 0.620f);
    glVertex2f(0.85f, 0.670f);
    glVertex2f(0.7f, 0.67f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.690f);
    glVertex2f(0.85f, 0.690f);
    glVertex2f(0.85f, 0.740f);
    glVertex2f(0.7f, 0.74f);
    glEnd();
glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.760f);
    glVertex2f(0.85f, 0.760f);
    glVertex2f(0.85f, 0.810f);
    glVertex2f(0.7f, 0.810f);
    glEnd();

glBegin(GL_QUADS);
     glColor3f(0.00,0.35,0.70);
    glVertex2f(0.7f, 0.830f);
    glVertex2f(0.85f, 0.830f);
    glVertex2f(0.85f, 0.880f);
    glVertex2f(0.7f, 0.88f);
    glEnd();







    glBegin(GL_QUADS);
     glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.85f, 0.50f);
    glVertex2f(0.9f, 0.50f);
    glVertex2f(0.9f, 0.88f);
    glVertex2f(0.85f, 0.90f);
    glEnd();


}


float ship_position = -0.3f;
float ship_speed = 0.01f;
float move_ship_container =-0.0f;
float container_ship_speed = 0.5f;
float move_flow = 0.0f;
float move_speed_boat =1.0f;
float speedboat_speed =0.5f;

void river()                              ///OID-9
{
    ///river
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.8f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(-1.0f, 0.4f);
    glEnd();

    ///bank river
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-1.0,0.4);
    glVertex2f(1.0, 0.4);
    glEnd();
}

void flow()                                  ///OID-10
{
    float x=0.1,y=0.1;
    ///flow
    glPushMatrix();
    glTranslatef(move_flow, 0.0f, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5,0.3);
    glVertex2f(0.6, 0.3);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.3-x);
    glVertex2f(0.6-x, 0.3-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x,0.3-x-x);
    glVertex2f(0.6-x-x, 0.3-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x,0.3-x-x-x+0.05);
    glVertex2f(0.6-x-x-x-2*x, 0.3-x-x-x+0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x+0.15);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12, 0.3-x-x-x+0.15);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x-0.05);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x-0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x,0.3-x-x-x+0.1);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x, 0.3-x-x-x+0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x,0.3-x-x-x-0.08);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x, 0.3-x-x-x-0.08);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17,0.3);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17, 0.3);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.3+0.06);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.3+0.06);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.2);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.2);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.2);
    glVertex2f(0.6-x,0.2);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x,0.1);
    glVertex2f(0.6-x+2*x,0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x,0.1+y);
    glVertex2f(0.6-x+2*x+x,0.1+y);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.1+y+y);
    glVertex2f(0.6-x+2*x+x+x,0.1+y+y);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.0);
    glVertex2f(0.6-x+2*x+x+x,0.0);
    glEnd();
    glPopMatrix();
}
void ships()                                    ///OID-11
{
/// ship1

    float Z=200.00;

    glColor3ub(155,150,150);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.0055,0.0025,0);
    glTranslatef(move_ship_container, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(10.0f,-170.0f+Z);
    glVertex2f(110.0f,-170.0f+Z);
    glVertex2f(110.0f,-140.0f+Z);
    glVertex2f(10.0f,-140.0f+Z);
    glEnd();

    ///middle white
    glColor3ub(155,155,255);
    glBegin(GL_POLYGON);
    glVertex2f(10.0f,-140.0f+Z);
    glVertex2f(110.0f,-140.0f+Z);
    glVertex2f(110.0f,-120.0f+Z);
    glVertex2f(10.0f,-120.0f+Z);
    glEnd();

    ///deck room
    glColor3ub(70,130,180);
    glBegin(GL_POLYGON);
    glVertex2f(18.0f,-120.0f+Z);
    glVertex2f(40.0f,-120.0f+Z);
    glVertex2f(40.0f,-50.0f+Z);
    glVertex2f(18.0f,-50.0f+Z);
    glEnd();

    ///deck room 2D
    glColor3ub(72,61,139);
    glBegin(GL_POLYGON);
    glVertex2f(40.0f,-120.0f+Z);
    glVertex2f(41.0f,-120.0f+Z);
    glVertex2f(41.0f,-50.0f+Z);
    glVertex2f(40.0f,-50.0f+Z);
    glEnd();

    ///deck room light

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3ub(255,228,181);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.8f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+22,y-60+Z );
    }
    glEnd();

    ///deck room light
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3ub(255,228,181);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.8f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+29,y-60+Z );
    }
    glEnd();

    ///deck room light
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3ub(255,228,181);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2.8f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+36,y-60+Z );
    }
    glEnd();

    ///control room
    glColor3ub(155,155,255);
    glBegin(GL_POLYGON);
    glVertex2f(23.0f,-50.0f+Z);
    glVertex2f(40.0f,-50.0f+Z);
    glVertex2f(42.0f,10.0f+Z);
    glVertex2f(23.0f,10.0f+Z);
    glEnd();

    ///control room 2D
    glColor3ub(155,155,255);
    glBegin(GL_POLYGON);
    glVertex2f(40.0f,-50.0f+Z);
    glVertex2f(41.0f,-50.0f+Z);
    glVertex2f(42.0f,10.0f+Z);
    glVertex2f(41.0f,10.0f+Z);
    glEnd();

    ///control room left first window
    glColor3ub(0,206,209);
    glBegin(GL_POLYGON);
    glVertex2f(24.0f,-10.0f+Z);
    glVertex2f(27.0f,-10.0f+Z);
    glVertex2f(27.0f,8.0f+Z);
    glVertex2f(24.0f,8.0f+Z);
    glEnd();

    ///control room left second window
    glColor3ub(0,206,209);
    glBegin(GL_POLYGON);
    glVertex2f(28.0f,-10.0f+Z);
    glVertex2f(31.0f,-10.0f+Z);
    glVertex2f(31.0f,8.0f+Z);
    glVertex2f(28.0f,8.0f+Z);
    glEnd();

    ///control room left third window
    glColor3ub(0,206,209);
    glBegin(GL_POLYGON);
    glVertex2f(32.0f,-10.0f+Z);
    glVertex2f(35.0f,-10.0f+Z);
    glVertex2f(35.0f,8.0f+Z);
    glVertex2f(32.0f,8.0f+Z);
    glEnd();

    ///control room left fourth window
    glColor3ub(0,206,209);
    glBegin(GL_POLYGON);
    glVertex2f(36.0f,-10.0f+Z);
    glVertex2f(39.5f,-10.0f+Z);
    glVertex2f(40.0f,8.0f+Z);
    glVertex2f(36.0f,8.0f+Z);
    glEnd();

    ///control room roof top
    glColor3ub(70,130,180);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(21.0f,10.0f+Z);
    glVertex2f(43.0f,10.0f+Z);
    glEnd();

    ///control room top light holder
    glColor3ub(192,192,192);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
    glVertex2f(33.0f,13.0f+Z);
    glVertex2f(33.0f,55.0f+Z);
    glEnd();

    ///exhaust white part
    glColor3ub(57,43,23);
    glBegin(GL_QUADS);
    glVertex2f(25.0f,15.0f+Z);
    glVertex2f(30.0f,15.0f+Z);
    glVertex2f(30.0f,40.0f+Z);
    glVertex2f(25.0f,40.0f+Z);
    glEnd();

    ///exhaust black part
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(25.0f,40.0f+Z);
    glVertex2f(30.0f,40.0f+Z);
    glVertex2f(30.0f,45.0f+Z);
    glVertex2f(25.0f,50.0f+Z);
    glEnd();

    ///control room front glass
    glColor3ub(0,206,209);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(41.0f,-16.0f+Z);
    glVertex2f(41.5f,2.0f+Z);
    glEnd();

    ///deck roof top
    glColor3ub(209,174,31);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(13.0f,-50.0f+Z);
    glVertex2f(43.0f,-50.0f+Z);
    glEnd();

    ///deck roof top 2D
    glColor3ub(57,43,23);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(43.0f,-50.0f+Z);
    glVertex2f(44.0f,-50.0f+Z);
    glEnd();

    ///body to deck line1
    glColor3ub(209,174,31);
    glLineWidth(15.0f);
    glBegin(GL_LINES);
    glVertex2f(14.0f,-100.0f+Z);
    glVertex2f(14.0f,-50.0f+Z);
    glEnd();

    ///body to deck line2
    glColor3ub(209,174,31);
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glVertex2f(18.0f,-100.0f+Z);
    glVertex2f(18.0f,-50.0f+Z);
    glEnd();

    ///upper white tail part
    glColor3ub(209,174,31);
    glBegin(GL_POLYGON);
    glVertex2f(10.0f,-120.0f+Z);
    glVertex2f(40.0f,-120.0f+Z);
    glVertex2f(35.0f,-100.0f+Z);
    glVertex2f(10.0f,-100.0f+Z);
    glEnd();

    ///upper white front part
    glColor3ub(155,155,255);
    glBegin(GL_POLYGON);
    glVertex2f(85.0f,-120.0f+Z);
    glVertex2f(110.0f,-120.0f+Z);
    glVertex2f(120.0f,-90.0f+Z);
    glVertex2f(90.0f,-90.0f+Z);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

    ///Container
    glColor3ub(0,0,255);
    glMatrixMode(GL_MODELVIEW);
    glScalef(0.0055,0.0025,0);
    glPushMatrix();
    glTranslatef(move_ship_container, 0.0f, 0.0f);//for move

    ///left first container
    glBegin(GL_POLYGON);
    glVertex2f(45.0f,-120.0f+Z);
    glVertex2f(62.0f,-120.0f+Z);
    glVertex2f(62.0f,-85.0f+Z);
    glVertex2f(45.0f,-85.0f+Z);
    glEnd();

    ///left first container 2D
    glColor3ub(0,0,100);
    glBegin(GL_POLYGON);
    glVertex2f(62.0f,-85.0f+Z);
    glVertex2f(63.0f,-85.0f+Z);
    glVertex2f(63.0f,-120.0f+Z);
    glVertex2f(62.0f,-120.0f+Z);
    glEnd();

    ///left second container
    glColor3ub(255,165,0);
    glBegin(GL_POLYGON);
    glVertex2f(65.0f,-120.0f+Z);
    glVertex2f(82.0f,-120.0f+Z);
    glVertex2f(82.0f,-85.0f+Z);
    glVertex2f(65.0f,-85.0f+Z);
    glEnd();

    ///left second container 2D
    glColor3ub(150,105,0);
    glBegin(GL_POLYGON);

    glVertex2f(82.0f,-85.0f+Z);
    glVertex2f(83.0f,-85.0f+Z);
    glVertex2f(83.0f,-120.0f+Z);
    glVertex2f(82.0f,-120.0f+Z);
    glEnd();

    ///top container
    glColor3ub(255,127,80);
    glBegin(GL_POLYGON);
    glVertex2f(56.5f,-85.0f+Z);
    glVertex2f(73.5f,-85.0f+Z);
    glVertex2f(73.5f,-50.0f+Z);
    glVertex2f(56.5f,-50.0f+Z);
    glEnd();

    ///top container 2D
    glColor3ub(130,70,50);
    glBegin(GL_POLYGON);
    glVertex2f(73.5f,-50.0f+Z);
    glVertex2f(74.5f,-50.0f+Z);
    glVertex2f(74.5f,-85.0f+Z);
    glVertex2f(73.5f,-85.0f+Z);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}



void speed_boat()                           ///OID-14
{
    ///SpeedBoat
    float I = 60.0;
    ///deck
    glColor3ub(0,0,128);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.0055,0.0020,0);
    glTranslatef(move_speed_boat, 0.0f, 0.0f);//for move
    glBegin(GL_QUADS);
    glVertex2f(135.0f, -44.0f+I);
    glVertex2f(167.0f, -60.0f+I);
    glVertex2f(164.0f, -30.0f+I);
    glVertex2f(140.0f, -10.0f+I);
    glEnd();

    ///windows
    glColor3ub(72,209,204);
    glBegin(GL_QUADS);
    glVertex2f(137.0f, -39.0f+I);
    glVertex2f(165.0f, -51.0f+I);
    glVertex2f(163.0f, -34.0f+I);
    glVertex2f(141.0f, -15.0f+I);
    glEnd();

//window line

    glColor3ub(0,0,128);
    glLineWidth(8.0f);
    glBegin(GL_LINES);
    glVertex2f(145.0f, -52.0f+I);
    glVertex2f(145.0f, -16.0f+I);

    glVertex2f(151.0f, -52.0f+I);
    glVertex2f(151.0f, -19.0f+I);

    glVertex2f(157.0f, -52.0f+I);
    glVertex2f(157.0f, -25.5f+I);
    glEnd();
//middle body
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(132.0f, -85.0f+I);
    glVertex2f(173.0f, -85.0f+I);
    glVertex2f(177.0f, -60.0f+I);
    glVertex2f(123.0f, -38.0f+I);
    glEnd();

    ///bottom body
    glColor3ub(0,0,128);
    glBegin(GL_QUADS);
    glVertex2f(135.0f, -105.0f+I);
    glVertex2f(170.0f, -105.0f+I);
    glVertex2f(173.0f, -85.0f+I);
    glVertex2f(130.0f, -76.0f+I);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}


void update_speed_boat(int value)               ///AFID-3
{
    move_speed_boat -= speedboat_speed;
    if(move_speed_boat<-360)
    {
        move_speed_boat =70;
    }
    glutPostRedisplay();
    glutTimerFunc(8, update_speed_boat, 0);
}


void update_ship(int value)                     ///AFID-4
{
    if(move_ship_container>=211.90)
    {
        move_ship_container = -320;
    }
    glutPostRedisplay();
    move_ship_container += container_ship_speed ;
    glutTimerFunc(20, update_ship, 0);
}

void updateFlow(int value)                      ///AFID-5
{
    move_flow -=0.001;
    if (move_flow < -0.1)
    {
        move_flow = 0.001;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateFlow, 0);
}
void HalfCircle(float r1,float r,float g,float b)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416/2;
        float A=(i*2*pi)/200;
        float r=r1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
}
void window()
{
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(0.015,-0.04);
    glVertex2f(-0.015, -0.04);
    glColor3ub(160,160,160);
    glVertex2f(-0.015, -0.00);
    glVertex2f(0.015, -0.00);
    glEnd();
    glTranslatef(-0.0005,0,0);
    HalfCircle(0.015,160,160,160);
    glLoadIdentity();
}


///----------------------------------------------------------------------------------------------------------

float man1Position=0.3f;
float man1Speed=0.008;
float man2Position=-0.4f;
float man2Speed=0.012;
float man3Position=0.8f;
float man3Speed=0.01;
float man4Position=0.9f;
float man4Speed=0.015;
float ambulance_position=0;
float ambulance_speed=0.01;
float police_car_position=0;
float police_car_speed=0.01;
float suv_car_position = 0;
float suv_car_speed=0.01;
float car_position = 0;
float car_speed=0.01;

void road()
{
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(-1.0f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-1.0f, -0.35f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-1.0f, -0.35f);
    glVertex2f(-0.80f, -0.35f);
    glVertex2f(-0.80f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.35f);
    glVertex2f(-0.40f, -0.35f);
    glVertex2f(-0.40f, -0.3f);
    glVertex2f(-0.60f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.35f);
    glVertex2f(0.00f, -0.35f);
    glVertex2f(0.00f, -0.3f);
    glVertex2f(-0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.35f);
    glVertex2f(0.40f, -0.35f);
    glVertex2f(0.40f, -0.3f);
    glVertex2f(0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.35f);
    glVertex2f(0.80f, -0.35f);
    glVertex2f(0.80f, -0.3f);
    glVertex2f(0.60f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-1.0f, -0.67f);
    glVertex2f(-0.80f, -0.67f);
    glVertex2f(-0.80f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.60f, -0.67f);
    glVertex2f(-0.40f, -0.67f);
    glVertex2f(-0.40f, -0.7f);
    glVertex2f(-0.60f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.20f, -0.67f);
    glVertex2f(0.00f, -0.67f);
    glVertex2f(0.00f, -0.7f);
    glVertex2f(-0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(0.20f, -0.67f);
    glVertex2f(0.40f, -0.67f);
    glVertex2f(0.40f, -0.7f);
    glVertex2f(0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.67f);
    glVertex2f(0.80f, -0.67f);
    glVertex2f(0.80f, -0.7f);
    glVertex2f(0.60f, -0.7f);
    glEnd();

}

void circle(float radius, float cX, float cY, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);
    }
}

void footpath()                             ///OID-17
{
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 0.5f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();


}


void lamp_post()                              ///OID-20
{
    float ww = 100;
    ///lamp1
    ///pillar
    float L = 140.0;
    float l = 40.0;
    glScalef(0.005,0.005,0);
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f,80.0f-L);
    glVertex2f(62.0f,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f,160.0f-L);
    glVertex2f(54.0f,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f,158.0f-L);
    glVertex2f(57.0f,158.0f-L);
    glEnd();

    ///lamp2
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-l,80.0f-L);
    glVertex2f(62.0f-l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-l,160.0f-L);
    glVertex2f(54.0f-l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-l,158.0f-L);
    glVertex2f(57.0f-l,158.0f-L);
    glEnd();

    ///lamp3
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-2*l,80.0f-L);
    glVertex2f(62.0f-2*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-2*l,160.0f-L);
    glVertex2f(54.0f-2*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-2*l,158.0f-L);
    glVertex2f(57.0f-2*l,158.0f-L);
    glEnd();

    ///lamp4
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-3*l,80.0f-L);
    glVertex2f(62.0f-3*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-3*l,160.0f-L);
    glVertex2f(54.0f-3*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-3*l,158.0f-L);
    glVertex2f(57.0f-3*l,158.0f-L);
    glEnd();

    ///lamp5
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-4*l,80.0f-L);
    glVertex2f(62.0f-4*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-4*l,160.0f-L);
    glVertex2f(54.0f-4*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-4*l,158.0f-L);
    glVertex2f(57.0f-4*l,158.0f-L);
    glEnd();

    ///lamp6
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-5*l,80.0f-L);
    glVertex2f(62.0f-5*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-5*l,160.0f-L);
    glVertex2f(54.0f-5*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-5*l,158.0f-L);
    glVertex2f(57.0f-5*l,158.0f-L);
    glEnd();

    ///lamp7
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-6*l,80.0f-L);
    glVertex2f(62.0f-6*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f-6*l,160.0f-L);
    glVertex2f(54.0f-6*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-6*l,158.0f-L);
    glVertex2f(57.0f-6*l,158.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f-5*l,158.0f-L);
    glVertex2f(57.0f-5*l,158.0f-L);
    glEnd();

    ///lamp8
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+l,80.0f-L);
    glVertex2f(62.0f+l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+l,160.0f-L);
    glVertex2f(54.0f+l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f+l,158.0f-L);
    glVertex2f(57.0f+l,158.0f-L);
    glEnd();

    ///lamp9
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+2*l,80.0f-L);
    glVertex2f(62.0f+2*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+2*l,160.0f-L);
    glVertex2f(54.0f+2*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f+2*l,158.0f-L);
    glVertex2f(57.0f+2*l,158.0f-L);
    glEnd();

    ///lamp10
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+3*l,80.0f-L);
    glVertex2f(62.0f+3*l,162.5f-L);
    glEnd();

    ///light holder
    glColor3ub(0,0,0);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(62.0f+3*l,160.0f-L);
    glVertex2f(54.0f+3*l,160.0f-L);
    glEnd();

    ///light
    glColor3ub(255-ww,255-ww,255-ww);
    glLineWidth(7.0f);
    glBegin(GL_LINES);
    glVertex2f(54.0f+3*l,158.0f-L);
    glVertex2f(57.0f+3*l,158.0f-L);
    glEnd();

    glLoadIdentity();

}



void tree()                                 ///OID-18
{
    ///tree1
    float t = 0.5;
    glScalef(1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree2
    glPushMatrix();
    glScalef(-1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree3
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(-0.6f,-0.15f);
    glVertex2f(-0.624f,-0.15f);
    glVertex2f(-0.624f,0.08f);
    glVertex2f(-0.6f,0.08f);
    glEnd();

    circle(0.04,-0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,-0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,-0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,-0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.615,0.1,0.0, 0.6, 0.0);
    glEnd();

    ///tree4
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.6f,-0.15f);
    glVertex2f(0.624f,-0.15f);
    glVertex2f(0.624f,0.08f);
    glVertex2f(0.6f,0.08f);
    glEnd();

    circle(0.04,0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.615,0.1,0.0, 0.6, 0.0);
    glEnd();


}


void treeSnows(){

    ///tree1
    float t = 0.5;
    glScalef(1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree2
    glPushMatrix();
    glScalef(-1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree3
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(-0.6f,-0.15f);
    glVertex2f(-0.624f,-0.15f);
    glVertex2f(-0.624f,0.08f);
    glVertex2f(-0.6f,0.08f);
    glEnd();

    circle(0.04,-0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,-0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,-0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,-0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.615,0.1,0.0, 0.6, 0.0);
    glEnd();

    ///tree4
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.6f,-0.15f);
    glVertex2f(0.624f,-0.15f);
    glVertex2f(0.624f,0.08f);
    glVertex2f(0.6f,0.08f);
    glEnd();

    circle(0.04,0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.615,0.1,0.0, 0.6, 0.0);
    glEnd();


}



void bench()                                ///OID-19
{
    float B = 115.0;
    float b = 50.0;

    ///bench2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.005,0.005,0);
    ///left leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(41.0f+b,80.0f-B);
    glVertex2f(41.0f+b,92.0f-B);
    glEnd();
    ///right leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(57.0f+b,80.0f-B);
    glVertex2f(57.0f+b,92.0f-B);
    glEnd();
    ///upper part
    glColor3f(0.3f, 0.3f, 0.0f);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(40.0f+b,92.0f-B);
    glVertex2f(58.0f+b,92.0f-B);
    glEnd();
    glLoadIdentity();

    ///bench2
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(-0.005,0.005,0);
    ///left leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(41.0f+b,80.0f-B);
    glVertex2f(41.0f+b,92.0f-B);
    glEnd();
    ///right leg
    glColor3ub(0,0,0);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(57.0f+b,80.0f-B);
    glVertex2f(57.0f+b,92.0f-B);
    glEnd();
    ///upper part
    glColor3f(0.3f, 0.3f, 0.0f);
    glLineWidth(12.0f);
    glBegin(GL_LINES);
    glVertex2f(40.0f+b,92.0f-B);
    glVertex2f(58.0f+b,92.0f-B);
    glEnd();
    glLoadIdentity();
}


void fence()                            ///OID-15
{
    float L = 0.05;
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.95f,-0.01f);
    glVertex2f(-0.95f,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.9f,-0.01f);
    glVertex2f(-0.9f,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f,-0.01f);
    glVertex2f(-0.85f,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+L,-0.01f);
    glVertex2f(-0.85f+L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+2*L,-0.01f);
    glVertex2f(-0.85f+2*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+3*L,-0.01f);
    glVertex2f(-0.85f+3*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+4*L,-0.01f);
    glVertex2f(-0.85f+4*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+5*L,-0.01f);
    glVertex2f(-0.85f+5*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+6*L,-0.01f);
    glVertex2f(-0.85f+6*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+7*L,-0.01f);
    glVertex2f(-0.85f+7*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+8*L,-0.01f);
    glVertex2f(-0.85f+8*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+9*L,-0.01f);
    glVertex2f(-0.85f+9*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+10*L,-0.01f);
    glVertex2f(-0.85f+10*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+11*L,-0.01f);
    glVertex2f(-0.85f+11*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+12*L,-0.01f);
    glVertex2f(-0.85f+12*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+13*L,-0.01f);
    glVertex2f(-0.85f+13*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+14*L,-0.01f);
    glVertex2f(-0.85f+14*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+15*L,-0.01f);
    glVertex2f(-0.85f+15*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+16*L,-0.01f);
    glVertex2f(-0.85f+16*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+17*L,-0.01f);
    glVertex2f(-0.85f+17*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+18*L,-0.01f);
    glVertex2f(-0.85f+18*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+19*L,-0.01f);
    glVertex2f(-0.85f+19*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+20*L,-0.01f);
    glVertex2f(-0.85f+20*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+21*L,-0.01f);
    glVertex2f(-0.85f+21*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+22*L,-0.01f);
    glVertex2f(-0.85f+22*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+23*L,-0.01f);
    glVertex2f(-0.85f+23*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+24*L,-0.01f);
    glVertex2f(-0.85f+24*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+25*L,-0.01f);
    glVertex2f(-0.85f+25*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+26*L,-0.01f);
    glVertex2f(-0.85f+26*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+27*L,-0.01f);
    glVertex2f(-0.85f+27*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+28*L,-0.01f);
    glVertex2f(-0.85f+28*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+29*L,-0.01f);
    glVertex2f(-0.85f+29*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+30*L,-0.01f);
    glVertex2f(-0.85f+30*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+31*L,-0.01f);
    glVertex2f(-0.85f+31*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+32*L,-0.01f);
    glVertex2f(-0.85f+32*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+33*L,-0.01f);
    glVertex2f(-0.85f+33*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+34*L,-0.01f);
    glVertex2f(-0.85f+34*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+35*L,-0.01f);
    glVertex2f(-0.85f+35*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f+36*L,-0.01f);
    glVertex2f(-0.85f+36*L,-0.1f);
    glEnd();

    glColor3ub(57,43,23);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(-1.0,-0.01f);
    glVertex2f(1.0f,-0.01f);
    glEnd();

}

void human(float red, float green, float blue, float x, float y)    ///OID-21
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(65, 0,1,0);
    ///shirt
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);

    glVertex2f(0.0f, -0.13f);
    glVertex2f(0.07f, -0.13f);

    glVertex2f(0.07f, -0.06f);
    glVertex2f(0.0f, -0.06f);
    glEnd();

    ///left hand
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.7f);

    glVertex2f(0.0f,-0.145f);
    glVertex2f(-0.015f,-0.145f);
    glVertex2f(-0.012f,-0.06f);
    glVertex2f(0.0f,-0.06f);
    glEnd();

    ///left hand sleave
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);

    glVertex2f(0.0f,-0.1f);
    glVertex2f(-0.015f,-0.1f);
    glVertex2f(-0.012f,-0.06f);
    glVertex2f(0.0f,-0.06f);
    glEnd();

    ///right hand
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.7f);

    glVertex2f(0.07f,-0.145f);
    glVertex2f(0.085f,-0.145f);
    glVertex2f(0.082f,-0.06f);
    glVertex2f(0.07f,-0.06f);
    glEnd();

    ///right hand sleave
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);

    glVertex2f(0.07f,-0.1f);
    glVertex2f(0.085f,-0.1f);
    glVertex2f(0.082f,-0.06f);
    glVertex2f(0.07f,-0.06f);
    glEnd();

    ///leg
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.6f);

    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.02f, -0.2f);

    glVertex2f(0.07f, -0.13f);
    glVertex2f(0.0f, -0.13f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.6f);

    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.07f, -0.2f);

    glVertex2f(0.07f, -0.13f);
    glVertex2f(0.03f, -0.16f);
    glEnd();
    ///shoe
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.0f, -0.22f);
    glVertex2f(0.02f, -0.22f);

    glVertex2f(0.02f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.05f, -0.22f);
    glVertex2f(0.07f, -0.22f);

    glVertex2f(0.07f, -0.2f);
    glVertex2f(0.05f, -0.2f);
    glEnd();

    ///neck
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.025f, -0.06f);
    glVertex2f(0.045f, -0.06f);

    glVertex2f(0.045f, -0.04f);
    glVertex2f(0.025f, -0.04f);
    glEnd();

    ///face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.01f, -0.04f);
    glVertex2f(0.06f, -0.04f);

    glVertex2f(0.06f, 0.0f);
    glVertex2f(0.01f, 0.0f);
    glEnd();

    ///hat
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.01f, 0.0f);
    glVertex2f(0.06f, 0.0f);

    glVertex2f(0.05f, 0.03f);
    glVertex2f(0.02f, 0.03f);
    glEnd();
    glPopMatrix();
}
void updateHuman(int value)                 ///AFID-6
{

    man2Position+=man2Speed;
    if(man2Position>1.0)
    {
        man2Position=-1.0;
    }
    man3Position-=man3Speed;
    if(man1Position<-1.0)
    {
        man3Position=+1.0;
    }
    man4Position-=man4Speed;
    if(man4Position<-1.0)
    {
        man4Position=+1.0;
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateHuman, 0);
}

void ambulance()                            ///OID-22
{
    /// ambulance
    glPushMatrix();
    glRotatef(0,0,1,0);
    glTranslatef(ambulance_position-0.6,-0.0,0);
    glBegin(GL_QUADS);/// white ambulance down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.7f, -0.45f);
    glVertex2f(-0.35f, -0.45f);
    glVertex2f(-0.36f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);/// yellow quads
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(-0.39f, -0.35f);
    glVertex2f(-0.39f, -0.37f);
    glVertex2f(-0.357f, -0.37f);
    glVertex2f(-0.36f, -0.35f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance start
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.71f, -0.43f);
    glVertex2f(-0.71f, -0.45f);
    glVertex2f(-0.69f, -0.45f);
    glVertex2f(-0.69f, -0.43f);
    glEnd();

    glBegin(GL_QUADS);/// black ambulance end
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(-0.36f, -0.43f);
    glVertex2f(-0.36f, -0.45f);
    glVertex2f(-0.34f, -0.45f);
    glVertex2f(-0.34f, -0.43f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.7f, -0.35f);
    glVertex2f(-0.36f, -0.35f);
    glVertex2f(-0.363f, -0.343f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance middle body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.363f, -0.343f);
    glVertex2f(-0.39f, -0.31f);
    glEnd();

    glBegin(GL_QUADS);    ///ambulance middle body end
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.7f, -0.343f);
    glVertex2f(-0.69f, -0.343f);
    glVertex2f(-0.69f, -0.31f);
    glEnd();



    glBegin(GL_QUADS);/// white ambulance up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.65f, -0.17f);
    glVertex2f(-0.7f, -0.31f);
    glVertex2f(-0.39f, -0.31f);
    glVertex2f(-0.43f, -0.17f);
    glEnd();


    glBegin(GL_QUADS);   ///ambulance up body alarm
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.55f, -0.15f);
    glVertex2f(-0.55f, -0.17f);
    glVertex2f(-0.53f, -0.17f);
    glVertex2f(-0.53f, -0.15f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue right quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.49f, -0.19f);
    glVertex2f(-0.49f, -0.31f);
    glVertex2f(-0.41f, -0.31f);
    glVertex2f(-0.45f, -0.19f);
    glEnd();

    glBegin(GL_QUADS);/// white ambulance up body blue left quads
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(-0.57f, -0.19f);
    glVertex2f(-0.57f, -0.31f);
    glVertex2f(-0.5f, -0.31f);
    glVertex2f(-0.5f, -0.19f);
    glEnd();


    glBegin(GL_QUADS);/// ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.65f, -0.24f);
    glVertex2f(-0.65f, -0.26f);
    glVertex2f(-0.58f, -0.26f);
    glVertex2f(-0.58f, -0.24f);
    glEnd();

    glBegin(GL_QUADS);///  ambulance up body red
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.62f, -0.19f);
    glVertex2f(-0.62f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.61f, -0.19f);
    glEnd();

    ///Wheel
    glScalef(0.2,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-3.05,y-2.2);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-3.05,y-2.2);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-2.2,y-2.2);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-2.2,y-2.2);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glLoadIdentity();
}

void policeCar()                                ///OID-25
{
    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(police_car_position-0.8,0,0);
    glScalef(-1,1,0);
    ///police car
    glBegin(GL_QUADS);/// white policeCar down body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.37f, -0.77f);
    glVertex2f(0.35f, -0.89f);
    glVertex2f(0.7f, -0.89f);
    glVertex2f(0.69f, -0.77f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down start line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.34f, -0.87f);
    glVertex2f(0.34f, -0.89f);
    glVertex2f(0.37f, -0.89f);
    glVertex2f(0.37f, -0.87f);
    glEnd();

    glBegin(GL_QUADS);/// black policeCar down end line
    glColor3f(0.2f, 0.2f, 0.2f);

    glVertex2f(0.68f, -0.87f);
    glVertex2f(0.68f, -0.89f);
    glVertex2f(0.72f, -0.89f);
    glVertex2f(0.72f, -0.87f);
    glEnd();

    glBegin(GL_QUADS);    ///policeCar middle line
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(0.366f, -0.79f);
    glVertex2f(0.363f, -0.81f);
    glVertex2f(0.39f, -0.81f);
    glVertex2f(0.39f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar middle line
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.4f, -0.79f);
    glVertex2f(0.4f, -0.81f);
    glVertex2f(0.66f, -0.81f);
    glVertex2f(0.66f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);   ///policeCar middle line
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.67f, -0.79f);
    glVertex2f(0.67f, -0.81f);
    glVertex2f(0.695f, -0.81f);
    glVertex2f(0.693f, -0.79f);
    glEnd();

    glBegin(GL_QUADS);/// white policeCar up body
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.46f, -0.7f);
    glVertex2f(0.41f, -0.77f);
    glVertex2f(0.65f, -0.77f);
    glVertex2f(0.62f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.465f, -0.715f);
    glVertex2f(0.42f, -0.77f);
    glVertex2f(0.52f, -0.77f);
    glVertex2f(0.52f, -0.715f);
    glEnd();

    glBegin(GL_QUADS);/// cyan policeCar up body
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex2f(0.53f, -0.715f);
    glVertex2f(0.53f, -0.77f);
    glVertex2f(0.64f, -0.77f);
    glVertex2f(0.615f, -0.715f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.475f, -0.68f);
    glVertex2f(0.475f, -0.7f);
    glVertex2f(0.49f, -0.7f);
    glVertex2f(0.49f, -0.68f);
    glEnd();

    glBegin(GL_QUADS);/// blue policeCar upper light
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex2f(0.49f, -0.68f);
    glVertex2f(0.49f, -0.7f);
    glVertex2f(0.505f, -0.7f);
    glVertex2f(0.505f, -0.68f);
    glEnd();

    glBegin(GL_QUADS);  ///policeCar upper light
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.505f, -0.68f);
    glVertex2f(0.505f, -0.7f);
    glVertex2f(0.52f, -0.7f);
    glVertex2f(0.52f, -0.68f);
    glEnd();

    ///Wheel
    glScalef(0.2,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-4.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-4.45);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-4.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-4.45);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glLoadIdentity();
}


void suv()                                  ///OID-24
{
    float cx = 5.5;
    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(suv_car_position-2.0,0,0);
    glScalef(0.14,0.14,0);
    ///car Body
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.90,0.3,0.0);
    glVertex2f(-3.0f, 0.0-cx);
    glVertex2f(-3.0f, 0.8-cx);
    glVertex2f(-0.7f, 0.8-cx);
    glVertex2f(-0.5f, 0.55-cx);
    glVertex2f(-0.5f, 0.0-cx);
    glEnd();

    ///car UP
    glBegin(GL_QUADS);
    glColor3f(1.,1.0,1.0);
    glVertex2f(-3.0f, 0.8f-cx);
    glVertex2f(-2.7f, 1.3f-cx);
    glVertex2f(-1.7f, 1.3f-cx);
    glVertex2f(-1.35f, 0.8f-cx);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-2.9f, 0.8f-cx);
    glVertex2f(-2.6f, 1.23f-cx);
    glVertex2f(-2.15f, 1.23f-cx);
    glVertex2f(-2.15f, 0.8f-cx);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-2.05f, 0.8f-cx);
    glVertex2f(-2.05f, 1.23f-cx);
    glVertex2f(-1.75f, 1.23f-cx);
    glVertex2f(-1.45f, 0.8f-cx);
    glEnd();

    ///Wheel
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.38;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.05-cx,y-5.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.05-cx,y-5.45);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.38;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.45-cx,y-5.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.45-cx,y-5.45);
    }
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}

void car()
{
    float cy=0.3;
    glPushMatrix();
    glRotatef(-1,0,1,0);
    glTranslatef(car_position+0.5,0,0);
    glScalef(-1,1,0);
    ///police car
    glBegin(GL_QUADS);/// white car down body
    glColor3f(0.6f, 0.0f, 1.0f);
    glVertex2f(0.37f, -0.77f+cy);
    glVertex2f(0.35f, -0.89f+cy);
    glVertex2f(0.7f, -0.89f+cy);
    glVertex2f(0.69f, -0.77f+cy);
    glEnd();

    glBegin(GL_QUADS);/// black car down start line
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.34f, -0.87f+cy);
    glVertex2f(0.34f, -0.89f+cy);
    glVertex2f(0.37f, -0.89f+cy);
    glVertex2f(0.37f, -0.87f+cy);
    glEnd();

    glBegin(GL_QUADS);/// black car down end line
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.68f, -0.87f+cy);
    glVertex2f(0.68f, -0.89f+cy);
    glVertex2f(0.72f, -0.89f+cy);
    glVertex2f(0.72f, -0.87f+cy);
    glEnd();

    glBegin(GL_QUADS);   ///car middle line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.366f, -0.79f+cy);
    glVertex2f(0.363f, -0.81f+cy);
    glVertex2f(0.39f, -0.81f+cy);
    glVertex2f(0.39f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);/// blue car middle line
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4f, -0.79f+cy);
    glVertex2f(0.4f, -0.81f+cy);
    glVertex2f(0.66f, -0.81f+cy);
    glVertex2f(0.66f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);///red car middle line
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.67f, -0.79f+cy);
    glVertex2f(0.67f, -0.81f+cy);
    glVertex2f(0.695f, -0.81f+cy);
    glVertex2f(0.693f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);/// white car up body
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.46f, -0.7f+cy);
    glVertex2f(0.41f, -0.77f+cy);
    glVertex2f(0.65f, -0.77f+cy);
    glVertex2f(0.62f, -0.7f+cy);
    glEnd();

    glBegin(GL_QUADS);/// cyan car up body
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.465f, -0.715f+cy);
    glVertex2f(0.42f, -0.77f+cy);
    glVertex2f(0.52f, -0.77f+cy);
    glVertex2f(0.52f, -0.715f+cy);
    glEnd();

    glBegin(GL_QUADS);/// cyan car up body
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.53f, -0.715f+cy);
    glVertex2f(0.53f, -0.77f+cy);
    glVertex2f(0.64f, -0.77f+cy);
    glVertex2f(0.615f, -0.715f+cy);
    glEnd();

    ///Wheel
    glScalef(0.2,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-2.95);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-2.95);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-2.95);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-2.95);
    }
    glEnd();
    glLoadIdentity();
}

void updateVehicals(int value)                  ///AFID-7
{
if (public_bus_position>=2.5)
    {
        public_bus_position=-1;
    }
    public_bus_position+=public_bus_speed;
    if (r_l_train_position>=2.5)
    {
        r_l_train_position=-1;
    }
    r_l_train_position+=r_l_train_speed;
if (l_r_train_position>=2.5)
    {
        l_r_train_position=-1;
    }
    l_r_train_position+=l_r_train_speed;
    if (ambulance_position>=2.5)
    {
        ambulance_position=-1;
    }
    ambulance_position+=ambulance_speed;

    if (police_car_position>=2.5)
    {
        police_car_position=-1;
    }
    police_car_position+=police_car_speed;

    if (suv_car_position>=3.5)
    {
        suv_car_position=-0.2;
    }
    suv_car_position+=suv_car_speed;

    if (car_position>=3.5)
    {
        car_position=-1.2;
    }
    car_position+=car_speed;

    glutPostRedisplay();
    glutTimerFunc(30, updateVehicals, 0);
}
float rainPosition=1;
float rainSpeed=0.02;
float icePosition=1;
float iceSpeed=0.02;




void warehouse()                            ///OID-26
{
    ///Top
    glBegin(GL_TRIANGLES);
    glColor3ub(155,155,255);
    glVertex2f(0.75,0.6);
    glColor3ub(55,55,255);
    glVertex2f(0.93, 0.7);
    glVertex2f(1.15,0.6);
    glEnd();
    ///Body
    glBegin(GL_QUADS);
    glColor3ub(55,55,55);
    glVertex2f(0.75,0.4);
    glColor3ub(204,204,204);
    glVertex2f(0.75, 0.6);
    glVertex2f(1.0,0.6);
    glVertex2f(1.0,0.4);
    glEnd();
    ///Door
    glBegin(GL_QUADS);
    glColor3ub(00,00,00);
    glVertex2f(0.8,0.4);
    glColor3ub(0,0,0);
    glVertex2f(0.8, 0.57);
    glVertex2f(1.0,0.57);
    glVertex2f(1.0,0.4);
    glEnd();
}


///-------------------------------------------------2nd--------------------------------------------------------------//////



void rain(float x_axis, float y_axis)
{
    glLineWidth(1);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(0+x_axis,0+y_axis);
    glVertex2f(0.01+x_axis, 0.06+y_axis);
    glEnd();
}
void rain_fall()
{
    glPushMatrix();
    glTranslatef(0, rainPosition, 0);
    for(float x=-1; x<=1; x+=0.04)
    {
        for(float y=-1; y<=1; y+=0.1)
        {
            rain(x,y);
            rain(x,y+1.0);
            rain(x,y-1.0);
        }
    }
    glPopMatrix();
}

void snow_fall()
{
    glPushMatrix();
    glTranslatef(0,icePosition, 0);
    for(float x=-0.95; x<=1; x+=0.1)
    {
        glPointSize(4.0);
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
        for(float y=-1; y<=1; y+=0.1)
        {
            glVertex2f(0.0+x, -1.0+y);
            glVertex2f(0.0+x, 0.0+y);
            glVertex2f(0.0+x, 1.0+y);
        }
        glEnd();
    }
    glPopMatrix();
}


void weather_update(int value)          ///AFID-9
{
    rainPosition-=rainSpeed;
    if(rainPosition<-1.0)
    {
        rainPosition=1;
    }

    icePosition-=iceSpeed;
    if(icePosition<-1.0)
    {
        icePosition=1;
    }

    glutPostRedisplay();
    glutTimerFunc(60, weather_update, 0);
}




void day_Display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /// Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);       /// Clear the color buffer (background)


    sky();
    buildings();
    buildings1();
    r_l_train();
    l_r_train();
    Wire();
    bridge_wirepillar();
    bridge();
    road_border();
    p_fence() ;
    pillar();
    road1();
    public_bus();
    road_marking();
    river();
    flow();
    warehouse();
    ships();
    speed_boat();
    fence();
    road();
    footpath();
    tree();
    bench();
    lamp_post();
    ambulance();
    car();
    policeCar();




    glFlush();  /// Render now
}
///-------------------------------------------------------------------------------------------------------------------------------------------------------------------


GLfloat position22 = 0.0f;
GLfloat speed22 = 0.007f;
void birdd(int value) {
    if(position22 > 1.0)
        position22 =-1.0f;
    position22 += speed22;
	glutPostRedisplay();
	glutTimerFunc(100, birdd, 0);
}
GLfloat position4 = 0.0f;
GLfloat speed4 =-0.01f;
void sunn(int value)
{
   if(position4 > 1.0)
        position4 = 0.0f;

    position4 += speed4;

	glutPostRedisplay();



	glutTimerFunc(100, sunn, 0);
}
GLfloat position3 = 0.0f;
GLfloat speed3 =- 1.0f;
void rain(int value) {
    if(position3 <- 1.0)
        position3 = 1.0f;
    position3 += speed3;
	glutPostRedisplay();
	glutTimerFunc(100, rain, 0);
}
GLfloat position2 = 0.0f;
GLfloat speed2 = 0.004f;
void cloud(int value) {
    if(position2 > 1.0)
        position2 =-1.0f;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, cloud, 0);
}
GLfloat position1 = 1.0f;
GLfloat speed1 =-0.005f;
void boat(int value)
{
   if(position1 <- 1.0)
        position1 = 1.0f;

    position1 += speed1;

	glutPostRedisplay();



	glutTimerFunc(100, boat, 0);
}
void cloud1()
{
    int i;

	GLfloat x=.5f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.55f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=.45f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.52f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.6f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}

void cloud2()
{
   // glLoadIdentity();
    int i;

	GLfloat x=-.5f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=-.55f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.45f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.52f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.6f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void cloud3()
{
    // glLoadIdentity();
    int i;

	GLfloat x=0.0f; GLfloat y=.86f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.05f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-0.05f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.02f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.1f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 217, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


}
void skyM()
{
    glBegin(GL_QUADS);
    glColor3ub(51, 204, 255);
	glVertex2f(-1.0f, 0.45f);
	glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void sky2()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 51, 204);
	glVertex2f(-1.0f, 0.45f);
	glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void sky3()
{
    glBegin(GL_QUADS);
    glColor3ub(2,0,108);
	glVertex2f(-1.0f, 0.45f);
	glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}
void backgroundtree()
{


    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
	glVertex2f(0.52f,0.45f);
	glVertex2f(0.48f, 0.45f);
	glVertex2f(0.48f,0.62f);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glEnd();
     glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
    glVertex2f(0.5f,0.64f);
    glVertex2f(0.52f,0.62f);
    glVertex2f(0.58f,0.6f);
	glVertex2f(0.55f, 0.63f);
	glVertex2f(0.58f,0.66f);
	glVertex2f(0.52f,0.66f);
	glVertex2f(0.52f, 0.72f);
	glVertex2f(0.5f,0.62f);///
	glVertex2f(0.48f,0.72f);
	glVertex2f(0.48f, 0.66f);
	glVertex2f(0.42f,0.66f);
	glVertex2f(0.45f,0.63f);
	glVertex2f(0.42f, 0.6f);
	glVertex2f(0.48f,0.62f);
    glEnd();

  	glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
	glVertex2f(-1.0f,0.45f);
	glVertex2f(-0.98f, 0.5f);
    glVertex2f(-0.93f, 0.56);
    glVertex2f(-0.9f,0.6f);
    glVertex2f(-0.82f, 0.65);
    glVertex2f(-0.75f, 0.70);///
    glVertex2f(-0.68f, 0.67);
     glVertex2f(-0.6f,0.6f);
     glVertex2f(-0.57f, 0.56);
     glVertex2f(-0.52f, 0.5f);
     glVertex2f(-0.5f,0.45f);
     glVertex2f(-1.0f,0.45f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
	glVertex2f(1.0f,0.45f);
	glVertex2f(0.98f, 0.5f);
    glVertex2f(0.93f, 0.56);
    glVertex2f(0.9f,0.6f);
    glVertex2f(0.82f, 0.64);
    glVertex2f(0.75f, 0.66);///
    glVertex2f(0.68f, 0.64);
     glVertex2f(0.6f,0.6f);
     glVertex2f(0.57f, 0.56);
     glVertex2f(0.52f, 0.5f);
     glVertex2f(0.5f,0.45f);
     glVertex2f(1.0f,0.45f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
	glVertex2f(-0.5f,0.45f);
	glVertex2f(-0.48f, 0.5f);
    glVertex2f(-0.45f, 0.56);
    glVertex2f(-0.42f,0.6f);
    glVertex2f(-0.37f, 0.68);///
    glVertex2f(-0.32f, 0.6);
    glVertex2f(-0.29f, 0.56f);
     glVertex2f(-0.27f, 0.5f);
    glVertex2f(-0.25f,0.45f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
	glVertex2f(0.5f,0.45f);
	glVertex2f(0.48f, 0.5f);
    glVertex2f(0.45f, 0.56);
    glVertex2f(0.42f,0.6f);
    glVertex2f(0.37f, 0.65);///
    glVertex2f(0.32f, 0.6);
    glVertex2f(0.29f, 0.56f);
     glVertex2f(0.27f, 0.5f);
    glVertex2f(0.25f,0.45f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(34,139,34);
	glVertex2f(-.25f,0.45f);
	glVertex2f(-0.23f, 0.5f);
    glVertex2f(-0.18f, 0.56);
    glVertex2f(-0.15f,0.6f);
    glVertex2f(-0.07f, 0.64);
    glVertex2f(-0.00f, 0.70);///
    glVertex2f(0.07f, 0.64);
    glVertex2f(0.15f,0.6f);
    glVertex2f(0.18f, 0.56);
    glVertex2f(0.23f, 0.5f);
    glVertex2f(.25f,0.45f);
	glEnd();

}
void bird()
{
       int i;

	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();


}
void stars()
{
    glPointSize( 2.5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f,0.95f);
    glVertex2f(0.9f,0.9f);
    glVertex2f(0.95f,0.7f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.7f,0.9f);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.5f,0.75f);
    glVertex2f(0.4f,0.9f);
    glVertex2f(0.3f,0.7f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(0.15f,0.75f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.4f,0.8f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.9f,0.9f);
    glVertex2f(-0.95f,0.7f);
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.5f,0.75f);
    glVertex2f(-0.4f,0.9f);
    glVertex2f(-0.3f,0.7f);
    glVertex2f(-0.25f,0.9f);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.15f,0.75f);
    glVertex2f(-0.1f,0.9f);
    glEnd();

}
void sun()
{
    int i;

	GLfloat x=.0f; GLfloat y=.9f; GLfloat radius =.06f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void moon()
{
    int i;

    GLfloat xx=-.5f; GLfloat yx=.93f; GLfloat radiusx =.06f;
    int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(0, 51, 204);
		glVertex2f(xx, yx); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            xx + (radiusx * cos(i *  twicePi / triangleAmount)),
			    yx + (radiusx * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x=-.5f; GLfloat y=.9f; GLfloat radius =.06f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(242, 242, 242);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

}

void ground()
{
    glBegin(GL_POLYGON);
	glColor3ub(34, 200, 34);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, -0.03);
    glVertex2f(1.0f, -0.07);
    glVertex2f(1.0f, -0.1);//6
    glVertex2f(1.0f, -0.13);
    glVertex2f(1.0f, -0.17);
    glVertex2f(1.0f, -0.2);
    glVertex2f(1.0f, -0.23);
    glVertex2f(1.0f, -0.25);
    glVertex2f(1.0f, -0.28);//12
    glVertex2f(1.0f, -0.32);
    glVertex2f(1.0f, -0.35);
    glVertex2f(1.0f, -0.4);
    glVertex2f(1.0f, -0.6);
    glVertex2f(1.0f, -0.65);
    glVertex2f(1.0f, -0.7);
    glVertex2f(1.0f, -0.75);
    glVertex2f(1.0f, -0.8);
    glVertex2f(1.0f, -0.85);
    glVertex2f(1.05f, -0.9);
    glVertex2f(1.0f, -0.95);
    glVertex2f(1.0f, -1.0);
    glEnd();




}
void ground1()
{
    glBegin(GL_POLYGON);
	glColor3ub(34, 139, 34);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(-1.0f,0.0f);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, -0.03);
    glVertex2f(1.0f, -0.07);
    glVertex2f(1.0f, -0.1);//6
    glVertex2f(1.0f, -0.13);
    glVertex2f(1.0f, -0.17);
    glVertex2f(1.0f, -0.2);
    glVertex2f(1.0f, -0.23);
    glVertex2f(1.0f, -0.25);
    glVertex2f(1.0f, -0.28);//12
    glVertex2f(1.0f, -0.32);
    glVertex2f(1.0f, -0.35);
    glVertex2f(1.0f, -0.4);
    glVertex2f(1.0f, -0.6);
    glVertex2f(1.0f, -0.65);
    glVertex2f(1.0f, -0.7);
    glVertex2f(1.0f, -0.75);
    glVertex2f(1.0f, -0.8);
    glVertex2f(1.0f, -0.85);
    glVertex2f(1.05f, -0.9);
    glVertex2f(1.0f, -0.95);
    glVertex2f(1.0f, -1.0);
    glEnd();




}
void riverM()
{
   glBegin(GL_QUADS);
   glColor3ub(38, 154, 214);
	//glColor3ub(0,122,204);
	glVertex2f(-1.0f,0.45f);
	glVertex2f(1.0f,0.45f);
	glVertex2f(1.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);
    glEnd();
}
void riverN()
{
   glBegin(GL_QUADS);
   glColor3ub(0, 0, 51);
	//glColor3ub(0,122,204);
	glVertex2f(-1.0f,0.45f);
	glVertex2f(1.0f,0.45f);
	glVertex2f(1.0f,-1.0f);
    glVertex2f(-1.0f,-1.0f);
    glEnd();
}
void hut()
{

    glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.1f,0.0f);
    glVertex2f(-0.18f,0.3f);
    glVertex2f(-0.58f,0.3f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(-0.49f,0.0f);
    glVertex2f(-0.13f,0.0f);
    glVertex2f(-0.13f,-0.4f);
    glVertex2f(-0.49f,-0.4f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(-0.58f,0.3f);
    glVertex2f(-0.63f,0.0f);
    glVertex2f(-0.61f,0.0f);
    glVertex2f(-0.61f,-0.35f);
    glVertex2f(-0.49f,-0.4f);
    glVertex2f(-0.17f,-0.4f);

    glEnd();
    glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.1f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.49f,0.0f);
    glVertex2f(-0.49f,-0.4f);

    glColor3ub(0,0,0);
     glVertex2f(-0.13f,-0.4f);
    glVertex2f(-0.49f,-0.4f);

     glColor3ub(0,0,0);
     glVertex2f(-0.13f,-0.4f);
    glVertex2f(-0.13f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.58f,0.3f);

    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.3f);
    glVertex2f(-0.63f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.57f,0.245f);
    glVertex2f(-0.61f,0.0f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,0.0f);
    glVertex2f(-0.61f,-0.35f);

    glColor3ub(0,0,0);
    glVertex2f(-0.61f,-0.35f);
    glVertex2f(-0.49f,-0.4f);

    glColor3ub(0,0,0);
    glVertex2f(-0.1f,0.0f);
    glVertex2f(-0.18f,0.3f);

    glColor3ub(0,0,0);
    glVertex2f(-0.18f,0.3f);
    glVertex2f(-0.58f,0.3f);

    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.35f,-0.1f);
    glVertex2f(-0.22f,-0.1f);    //main door
    glVertex2f(-0.22f,-0.4f);
    glVertex2f(-0.35f,-0.4f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,-0.1f);
    glVertex2f(-0.22f,-0.1f);
    glVertex2f(-0.22f,-0.1f);
    glVertex2f(-0.22f,-0.4f);
    glVertex2f(-0.35f,-0.1f);
    glVertex2f(-0.35f,-0.4f);
    glVertex2f(-0.285f,-0.1f);
    glVertex2f(-0.285f,-0.4f);
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.38f,-0.15f); //left window
    glVertex2f(-0.38f,-0.25f);
    glVertex2f(-0.44f,-0.25f);
    glEnd();
     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.44f,-0.25f);
    glVertex2f(-0.38f,-0.15f);
    glVertex2f(-0.38f,-0.25f);
    glVertex2f(-0.44f,-0.15f);
    glVertex2f(-0.38f,-0.15f);
    glVertex2f(-0.44f,-0.25f);
    glVertex2f(-0.38f,-0.25f);
    glVertex2f(-0.41f,-0.15f);
    glVertex2f(-0.41f,-0.25f);
    glEnd();

glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
     glVertex2f(-0.51f,-0.08f); //2nd door
    glVertex2f(-0.58f,-0.06f);
    glVertex2f(-0.58f,-0.37f);
    glVertex2f(-0.51f,-0.4f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f,-0.06f);
    glVertex2f(-0.58f,-0.37f);
    glVertex2f(-0.51f,-0.08f);
    glVertex2f(-0.51f,-0.4f);
    glVertex2f(-0.58f,-0.06f);
    glVertex2f(-0.51f,-0.08f);
    glVertex2f(-0.545f,-0.07f);
    glVertex2f(-0.545f,-0.385f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.14f,-0.15f);
    glVertex2f(-0.2f,-0.15f);   //rightwindow
    glVertex2f(-0.2f,-0.25f);
    glVertex2f(-0.14f,-0.25f);
    glEnd();
     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.14f,-0.15f);
    glVertex2f(-0.14f,-0.25f);
    glVertex2f(-0.2f,-0.15f);
    glVertex2f(-0.2f,-0.25f);
    glVertex2f(-0.14f,-0.15f);
    glVertex2f(-0.2f,-0.15f);
    glVertex2f(-0.14f,-0.25f);
    glVertex2f(-0.2f,-0.25f);
    glVertex2f(-0.17f,-0.15f);
    glVertex2f(-0.17f,-0.25f);
    glEnd();
}
void hut1()
{
  glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.285f,0.1f);
    glVertex2f(-0.285f,-0.2f);
    glEnd();

   /* glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
     glVertex2f(-0.51f,0.12f); //left door
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.58f,-0.17f);
    glVertex2f(-0.51f,-0.2f);
    glEnd();*/
     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,0.1f);
    glVertex2f(-0.22f,-0.2f);
    glVertex2f(-0.35f,0.1f);
    glVertex2f(-0.35f,-0.2f);
    glVertex2f(-0.285f,0.1f);
    glVertex2f(-0.285f,-0.2f);
    glEnd();

    /*glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f); //left window
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.44f,-0.05f);
    glEnd();*/

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.44f,0.05f);
    glVertex2f(-0.38f,0.05f);
    glVertex2f(-0.44f,-0.05f);
    glVertex2f(-0.38f,-0.05f);
    glVertex2f(-0.41f,0.05f);
    glVertex2f(-0.41f,-0.05f);
    glEnd();


     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.58f,-0.17f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.51f,-0.2f);
    glVertex2f(-0.58f,0.14f);
    glVertex2f(-0.51f,0.12f);
    glVertex2f(-0.545f,0.13f);
    glVertex2f(-0.545f,-0.185f);
    glEnd();

     /*glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(-0.14f,0.05f); ///right window
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,-0.05f);
    glEnd();*/


     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.14f,0.05f);
    glVertex2f(-0.2f,0.05f);
    glVertex2f(-0.14f,-0.05f);
    glVertex2f(-0.2f,-0.05f);
    glVertex2f(-0.17f,0.05f);
    glVertex2f(-0.17f,-0.05f);
    glEnd();

    glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.49f,-0.2f);
     glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);
     glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.13f,0.2f);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);
    glVertex2f(-0.57f,0.445f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.5f,0.2f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.18f,0.5f);
    glVertex2f(-0.58f,0.5f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.49f,0.2f);
    glVertex2f(-0.13f,0.2f);
    glVertex2f(-0.13f,-0.2f);
    glVertex2f(-0.49f,-0.2f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(-0.58f,0.5f);
    glVertex2f(-0.63f,0.2f);
    glVertex2f(-0.61f,0.2f);
    glVertex2f(-0.61f,-0.15f);
    glVertex2f(-0.49f,-0.2f);
    glVertex2f(-0.17f,-0.2f);
    glEnd();



}
void hut2()
{

    glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(0.4f,0.2f);
    glVertex2f(0.0f,0.2f);
    glVertex2f(0.08f,0.5f);
    glVertex2f(0.48f,0.5f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(0.39f,0.2f);
    glVertex2f(0.03f,0.2f);
    glVertex2f(0.03f,-0.2f);
    glVertex2f(0.39f,-0.2f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(70, 35, 10);
    glVertex2f(0.48f,0.5f);
    glVertex2f(0.53f,0.2f);
    glVertex2f(0.51f,0.2f);
    glVertex2f(0.51f,-0.15f);
    glVertex2f(0.39f,-0.2f);
    glVertex2f(0.07f,-0.2f);

    glEnd();
    glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.4f,0.2f);
    glVertex2f(0.0f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(0.39f,0.2f);
    glVertex2f(0.39f,-0.2f);

    glColor3ub(0,0,0);
     glVertex2f(0.03f,-0.2f);
    glVertex2f(0.39f,-0.2f);

     glColor3ub(0,0,0);
     glVertex2f(0.03f,-0.2f);
    glVertex2f(0.03f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(0.4f,0.2f);
    glVertex2f(0.48f,0.5f);

    glColor3ub(0,0,0);
    glVertex2f(0.48f,0.5f);
    glVertex2f(0.53f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(0.47f,0.445f);
    glVertex2f(0.51f,0.2f);

    glColor3ub(0,0,0);
    glVertex2f(0.51f,0.2f);
    glVertex2f(0.51f,-0.15f);

    glColor3ub(0,0,0);
    glVertex2f(0.51f,-0.15f);
    glVertex2f(0.39f,-0.2f);

    glColor3ub(0,0,0);
    glVertex2f(0.0f,0.2f);
    glVertex2f(0.08f,0.5f);

    glColor3ub(0,0,0);
    glVertex2f(0.08f,0.5f);
    glVertex2f(0.48f,0.5f);

    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(0.25f,0.1f);
    glVertex2f(0.12f,0.1f);    //main door
    glVertex2f(0.12f,-0.2f);
    glVertex2f(0.25f,-0.2f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.25f,0.1f);
    glVertex2f(0.12f,0.1f);
    glVertex2f(0.12f,0.1f);
    glVertex2f(0.12f,-0.2f);
    glVertex2f(0.25f,0.1f);
    glVertex2f(0.25f,-0.2f);
    glVertex2f(0.185f,0.1f);
    glVertex2f(0.185f,-0.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(0.34f,0.05f);
    glVertex2f(0.28f,0.05f); //left window
    glVertex2f(0.28f,-0.05f);
    glVertex2f(0.34f,-0.05f);
    glEnd();
     glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.34f,0.05f);
    glVertex2f(0.34f,-0.05f);
    glVertex2f(0.28f,0.05f);
    glVertex2f(0.28f,-0.05f);
    glVertex2f(0.34f,0.05f);
    glVertex2f(0.28f,0.05f);
    glVertex2f(0.34f,-0.05f);
    glVertex2f(0.28f,-0.05f);
    glVertex2f(0.31f,0.05f);
    glVertex2f(0.31f,-0.05f);
    glEnd();

glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
     glVertex2f(0.41f,0.12f); //2nd door
    glVertex2f(0.48f,0.14f);
    glVertex2f(0.48f,-0.17f);
    glVertex2f(0.41f,-0.2f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.48f,0.14f);
    glVertex2f(0.48f,-0.17f);
    glVertex2f(0.41f,0.12f);
    glVertex2f(0.41f,-0.2f);
    glVertex2f(0.48f,0.14f);
    glVertex2f(0.41f,0.12f);
    glVertex2f(0.445f,0.13f);
    glVertex2f(0.445f,-0.185f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(153, 115, 0);
    glVertex2f(0.04f,0.05f);
    glVertex2f(0.1f,0.05f);   //rightwindow
    glVertex2f(0.1f,-0.05f);
    glVertex2f(0.04f,-0.05f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.04f,0.05f);
    glVertex2f(0.04f,-0.05f);
    glVertex2f(0.1f,0.05f);
    glVertex2f(0.1f,-0.05f);
    glVertex2f(0.04f,0.05f);
    glVertex2f(0.1f,0.05f);
    glVertex2f(0.04f,-0.05f);
    glVertex2f(0.1f,-0.05f);
    glVertex2f(0.07f,0.05f);
    glVertex2f(0.07f,-0.05f);
    glEnd();
}
void hut3()
{
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.35f,0.1f);
    glVertex2f(0.22f,0.1f);
    glVertex2f(0.22f,0.1f);
    glVertex2f(0.22f,-0.2f);
    glVertex2f(0.35f,0.1f);
    glVertex2f(0.35f,-0.2f);
    glEnd();

     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.35f,0.1f);
    glVertex2f(0.22f,0.1f);
    glVertex2f(0.22f,0.1f);
    glVertex2f(0.22f,-0.2f);
    glVertex2f(0.35f,0.1f);
    glVertex2f(0.35f,-0.2f);
    glVertex2f(0.285f,0.1f);
    glVertex2f(0.285f,-0.2f);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.44f,0.05f);
    glVertex2f(0.44f,-0.05f);
    glVertex2f(0.38f,0.05f);
    glVertex2f(0.38f,-0.05f);
    glVertex2f(0.44f,0.05f);
    glVertex2f(0.38f,0.05f);
    glVertex2f(0.44f,-0.05f);
    glVertex2f(0.38f,-0.05f);
    glVertex2f(0.41f,0.05f);
    glVertex2f(0.41f,-0.05f);
    glEnd();


     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.58f,0.14f);
    glVertex2f(0.58f,-0.17f);
    glVertex2f(0.51f,0.12f);
    glVertex2f(0.51f,-0.2f);
    glVertex2f(0.58f,0.14f);
    glVertex2f(0.51f,0.12f);
    glVertex2f(0.545f,0.13f);
    glVertex2f(0.545f,-0.185f);
    glEnd();



     glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.14f,0.05f);
    glVertex2f(0.14f,-0.05f);
    glVertex2f(0.2f,0.05f);
    glVertex2f(0.2f,-0.05f);
    glVertex2f(0.14f,0.05f);
    glVertex2f(0.2f,0.05f);
    glVertex2f(0.14f,-0.05f);
    glVertex2f(0.2f,-0.05f);
    glVertex2f(0.17f,0.05f);
    glVertex2f(0.17f,-0.05f);
    glEnd();

    glLineWidth(2);
     glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.5f,0.2f);
    glVertex2f(0.1f,0.2f);
    glVertex2f(0.49f,0.2f);
    glVertex2f(0.49f,-0.2f);
     glVertex2f(0.13f,-0.2f);
    glVertex2f(0.49f,-0.2f);
     glVertex2f(0.13f,-0.2f);
    glVertex2f(0.13f,0.2f);
    glVertex2f(0.5f,0.2f);
    glVertex2f(0.58f,0.5f);
    glVertex2f(0.58f,0.5f);
    glVertex2f(0.63f,0.2f);
    glVertex2f(0.57f,0.445f);
    glVertex2f(0.61f,0.2f);
    glVertex2f(0.61f,0.2f);
    glVertex2f(0.61f,-0.15f);
    glVertex2f(0.61f,-0.15f);
    glVertex2f(0.49f,-0.2f);
    glVertex2f(0.1f,0.2f);
    glVertex2f(0.18f,0.5f);
    glVertex2f(0.18f,0.5f);
    glVertex2f(0.58f,0.5f);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(0.5f,0.2f);
    glVertex2f(0.1f,0.2f);
    glVertex2f(0.18f,0.5f);
    glVertex2f(0.58f,0.5f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(0.49f,0.2f);
    glVertex2f(0.13f,0.2f);
    glVertex2f(0.13f,-0.2f);
    glVertex2f(0.49f,-0.2f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(204, 153, 0);
    glVertex2f(0.58f,0.5f);
    glVertex2f(0.63f,0.2f);
    glVertex2f(0.61f,0.2f);
    glVertex2f(0.61f,-0.15f);
    glVertex2f(0.49f,-0.2f);
    glVertex2f(0.17f,-0.2f);
    glEnd();



}

void treeM()
{
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

     int i;

	GLfloat x=-.75f; GLfloat y=.33f; GLfloat radius =.1f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e11=-.64f; GLfloat f11=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void treeN()
{
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    //glVertex2f(-0.7f,-0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();

     int i;

	GLfloat x=-.75f; GLfloat y=.33f; GLfloat radius =.1f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(34, 139, 34);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=-.68f; GLfloat b=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-.81f; GLfloat d=.31f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=-.87f; GLfloat f=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=-.61f; GLfloat h=.35f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat a1=-.61f; GLfloat b1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(a1, b1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a1 + (radius * cos(i *  twicePi / triangleAmount)),
			    b1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c1=-.88f; GLfloat d1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c1 + (radius * cos(i *  twicePi / triangleAmount)),
			    d1 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e1=-.87f; GLfloat f1=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1, f1); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g1=-.61f; GLfloat h1=.4f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g1 + (radius * cos(i *  twicePi / triangleAmount)),
			    h1+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e11=-.64f; GLfloat f11=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e11, f11); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e11 + (radius * cos(i *  twicePi / triangleAmount)),
			    f11+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e12=-.75f; GLfloat f12=.44f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e12, f12); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e12 + (radius * cos(i *  twicePi / triangleAmount)),
			    f12+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(-0.85f,0.33f);
    glVertex2f(-0.85f,0.44f);
    glVertex2f(-0.65f,0.44f);
    glVertex2f(-0.65f,0.33f);
    glEnd();

    GLfloat e123=-.8f; GLfloat f123=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e123, f123); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e123 + (radius * cos(i *  twicePi / triangleAmount)),
			    f123+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	GLfloat e1232=-.7f; GLfloat f1232=.5f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(51, 204, 51);
		glVertex2f(e1232, f1232); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e1232 + (radius * cos(i *  twicePi / triangleAmount)),
			    f1232+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}


void boat()
{
    glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(-0.2f, 0.4f);
	glVertex2f(-0.15f, 0.35f);
	glVertex2f(0.15f, 0.35f);
    glVertex2f(0.2f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 153, 0);
	glVertex2f(-0.13f, 0.4f);
	glVertex2f(-0.11f,0.48f);
	glVertex2f(-0.088f, 0.52f);
	glVertex2f(0.13f, 0.52f);
	glVertex2f(0.14f, 0.49f);
    glVertex2f(0.15f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2f(-0.038f, 0.57f);
	glVertex2f(-0.038f, 0.73f);
	glVertex2f(-0.035f, 0.75f);
	glVertex2f(0.064f, 0.73f);
	glVertex2f(0.065f, 0.71f);
    glVertex2f(0.065f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(136,204,0);
	glVertex2f(0.0f, 0.52f);
	glVertex2f(0.0f, 0.79f);
	glVertex2f(0.01f, 0.79f);
	glVertex2f(0.01f, 0.52f);
	glEnd();
}



void boat4()
{
    glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(-0.2f, 0.4f);
	glVertex2f(-0.15f, 0.35f);
	glVertex2f(0.15f, 0.35f);
    glVertex2f(0.2f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 153, 0);
	glVertex2f(-0.13f, 0.4f);
	glVertex2f(-0.11f,0.48f);
	glVertex2f(-0.088f, 0.52f);
	glVertex2f(0.13f, 0.52f);
	glVertex2f(0.14f, 0.49f);
    glVertex2f(0.15f, 0.4f);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255,25,25);
	glVertex2f(-0.038f, 0.57f);
	glVertex2f(-0.038f, 0.73f);
	glVertex2f(-0.035f, 0.75f);
	glVertex2f(0.064f, 0.73f);
	glVertex2f(0.065f, 0.71f);
    glVertex2f(0.065f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(136,204,0);
	glVertex2f(0.0f, 0.52f);
	glVertex2f(0.0f, 0.79f);
	glVertex2f(0.01f, 0.79f);
	glVertex2f(0.01f, 0.52f);
	glEnd();
}
void Straw()
{
    glBegin(GL_POLYGON);
	glColor3ub(204, 153, 0);
	glVertex2f(-0.2f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(0.07f, 0.25f);
	glVertex2f(0.02f, 0.32f);
	glVertex2f(-0.05f, 0.37f);
	glVertex2f(-0.12f, 0.32f);
	glVertex2f(-0.17f, 0.25f);
	glVertex2f(-0.2f, 0.2f);
	glEnd();
	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
	glVertex2f(-0.05f, 0.37f);
	glVertex2f(-0.05f, 0.41f);
    glEnd();
}
void Straw1()
{
    glBegin(GL_POLYGON);
	glColor3ub(139, 69, 19);
	glVertex2f(-0.2f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(0.07f, 0.25f);
	glVertex2f(0.02f, 0.32f);
	glVertex2f(-0.05f, 0.37f);
	glVertex2f(-0.12f, 0.32f);
	glVertex2f(-0.17f, 0.25f);
	glVertex2f(-0.2f, 0.2f);
	glEnd();
	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
	glVertex2f(-0.05f, 0.37f);
	glVertex2f(-0.05f, 0.41f);
    glEnd();
}
void way()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.25f,-0.2f);
    glVertex2f(0.12f,-0.2f);
    glVertex2f(0.18f,-0.5f);
    glVertex2f(0.33f,-0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(0.33f,-0.5f);
    glVertex2f(0.65f,-1.0f);
    glVertex2f(0.46f,-1.0f);
    glVertex2f(0.18f,-0.5f);
    glEnd();

}
void way1()
{
    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.30f,-0.2f);
    glVertex2f(-0.17f,-0.2f);
    glVertex2f(-0.23f,-0.5f);
    glVertex2f(-0.38f,-0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.38f,-0.5f);
    glVertex2f(-0.70f,-1.0f);
    glVertex2f(-0.51f,-1.0f);
    glVertex2f(-0.23f,-0.5f);
    glEnd();

}


void fenceM()
{
     glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

     glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

     glColor3ub(255, 255, 102);
    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

     glColor3ub(255, 255, 102);
    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
}
void fence2()
{
      glLineWidth(5);
     glBegin(GL_LINES);
     glColor3ub(255, 255, 102);
    glVertex2f(0.9f,-0.1f);
    glVertex2f(0.5f,-0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(1.0f,-0.1f);
    glVertex2f(0.6f,-0.1f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,-0.05f);
    glVertex2f(0.5f,-0.05f);


    glColor3ub(255, 255, 102);
    glVertex2f(1.0f,-0.05f);
    glVertex2f(0.6f,-0.05f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.0f);
    glVertex2f(0.5f,0.0f);

    glColor3ub(255, 255, 102);
    glVertex2f(1.0f,0.0f);
    glVertex2f(0.6f,0.0f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.05f);
    glVertex2f(0.5f,0.05f);

     glColor3ub(255, 255, 102);
    glVertex2f(1.0f,0.05f);
    glVertex2f(0.6f,0.05f);

      glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.1f);
    glVertex2f(0.5f,0.1f);

     glColor3ub(255, 255, 102);
    glVertex2f(1.0f,0.1f);
    glVertex2f(0.6f,0.1f);

     glColor3ub(255, 255, 102);
    glVertex2f(0.95f,0.13f);
    glVertex2f(0.95f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.9f,0.13f);
    glVertex2f(0.9f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.85f,0.13f);
    glVertex2f(0.85f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.8f,0.13f);
    glVertex2f(0.8f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.75f,0.13f);
    glVertex2f(0.75f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.7f,0.13f);
    glVertex2f(0.7f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.65f,0.13f);
    glVertex2f(0.65f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.60f,0.13f);
    glVertex2f(0.60f,-0.12f);

    glColor3ub(255, 255, 102);
    glVertex2f(0.55f,0.13f);
    glVertex2f(0.55f,-0.12f);

    glEnd();
}


void well()
{

glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(204, 51, 0);
     glVertex2f(0.9f,-0.35f);
    glVertex2f(0.85f,-0.33f);//
    glVertex2f(0.85f,-0.33f);
    glVertex2f(0.8f,-0.325f);//
    glVertex2f(0.8f,-0.325f);
    glVertex2f(0.7f,-0.325f);//
    glVertex2f(0.7f,-0.325f);
    glVertex2f(0.65f,-0.33f);//
     glVertex2f(0.65f,-0.33f);
     glVertex2f(0.6f,-0.35f);
    glEnd();

    glLineWidth(3);
     glBegin(GL_LINES);
    glColor3ub(194, 194, 163);
    glVertex2f(0.59f,-0.43f);
    glVertex2f(0.57f,-0.39f);//
    glVertex2f(0.57f,-0.39f);
    glVertex2f(0.55f,-0.39f);//
    glVertex2f(0.55f,-0.39f);
    glVertex2f(0.52f,-0.39f);//
    glVertex2f(0.52f,-0.39f);
    glVertex2f(0.5f,-0.43f);//
    glEnd();

    glLineWidth(2.5);
     glBegin(GL_LINES);
    glColor3ub(230, 172, 0);
    glVertex2f(0.545f,-0.385f);
    glVertex2f(0.57f,-0.45f);//
    glVertex2f(0.57f,-0.45f);
    glVertex2f(0.575f,-0.5f);//
    glVertex2f(0.575f,-0.5f);
    glVertex2f(0.58f,-0.53f);//
    glVertex2f(0.58f,-0.53f);
    glVertex2f(0.57f,-0.55f);//
    glVertex2f(0.57f,-0.55f);
    glVertex2f(0.48f,-0.53f);//
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(0.585f,-0.43f);
    glVertex2f(0.568f,-0.44f);
    glVertex2f(0.528f,-0.44f);
    glVertex2f(0.505f,-0.43f);
    glVertex2f(0.528f,-0.425f);
    glVertex2f(0.57f,-0.425f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(0.9f,-0.35f);
    glVertex2f(0.9f,-0.55f);
    glVertex2f(0.85f,-0.575f);
    glVertex2f(0.8f,-0.59f);
    glVertex2f(0.7f,-0.59f);
    glVertex2f(0.65f,-0.575f);
    glVertex2f(0.6f,-0.55f);
    glVertex2f(0.6f,-0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 51);
    glVertex2f(0.9f,-0.35f);
    glVertex2f(0.85f,-0.375f);
    glVertex2f(0.8f,-0.38f);
    glVertex2f(0.7f,-0.38f);
    glVertex2f(0.65f,-0.375f);
    glVertex2f(0.6f,-0.35f);
    glVertex2f(0.65f,-0.33f);
    glVertex2f(0.7f,-0.325f);
     glVertex2f(0.8f,-0.325f);
     glVertex2f(0.85f,-0.33f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(194, 194, 163);
    glVertex2f(0.59f,-0.43f);
    glVertex2f(0.57f,-0.5f);
    glVertex2f(0.52f,-0.5f);
    glVertex2f(0.5f,-0.43f);
    glVertex2f(0.52f,-0.42f);
    glVertex2f(0.57f,-0.42f);
    glEnd();
}

void well1()
{

     glLineWidth(5);
     glBegin(GL_LINES);
    glColor3ub(204, 51, 0);
     glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.33f);//
    glVertex2f(-0.85f,-0.33f);
    glVertex2f(-0.8f,-0.325f);//
    glVertex2f(-0.8f,-0.325f);
    glVertex2f(-0.7f,-0.325f);//
    glVertex2f(-0.7f,-0.325f);
    glVertex2f(-0.65f,-0.33f);//
     glVertex2f(-0.65f,-0.33f);
     glVertex2f(-0.6f,-0.35f);
    glEnd();

    glLineWidth(3);
     glBegin(GL_LINES);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.39f);//
    glVertex2f(-0.57f,-0.39f);
    glVertex2f(-0.55f,-0.39f);//
    glVertex2f(-0.55f,-0.39f);
    glVertex2f(-0.52f,-0.39f);//
    glVertex2f(-0.52f,-0.39f);
    glVertex2f(-0.5f,-0.43f);//
    glEnd();

    glLineWidth(2.5);
     glBegin(GL_LINES);
    glColor3ub(230, 172, 0);
    glVertex2f(-0.545f,-0.385f);
    glVertex2f(-0.57f,-0.45f);//
    glVertex2f(-0.57f,-0.45f);
    glVertex2f(-0.575f,-0.5f);//
    glVertex2f(-0.575f,-0.5f);
    glVertex2f(-0.58f,-0.53f);//
    glVertex2f(-0.58f,-0.53f);
    glVertex2f(-0.57f,-0.55f);//
    glVertex2f(-0.57f,-0.55f);
    glVertex2f(-0.48f,-0.53f);//
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 154, 214);
    glVertex2f(-0.585f,-0.43f);
    glVertex2f(-0.568f,-0.44f);
    glVertex2f(-0.528f,-0.44f);
    glVertex2f(-0.505f,-0.43f);
    glVertex2f(-0.528f,-0.425f);
    glVertex2f(-0.57f,-0.425f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 51, 0);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.9f,-0.55f);
    glVertex2f(-0.85f,-0.575f);
    glVertex2f(-0.8f,-0.59f);
    glVertex2f(-0.7f,-0.59f);
    glVertex2f(-0.65f,-0.575f);
    glVertex2f(-0.6f,-0.55f);
    glVertex2f(-0.6f,-0.35f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 51);
    glVertex2f(-0.9f,-0.35f);
    glVertex2f(-0.85f,-0.375f);
    glVertex2f(-0.8f,-0.38f);
    glVertex2f(-0.7f,-0.38f);
    glVertex2f(-0.65f,-0.375f);
    glVertex2f(-0.6f,-0.35f);
    glVertex2f(-0.65f,-0.33f);
    glVertex2f(-0.7f,-0.325f);
     glVertex2f(-0.8f,-0.325f);
     glVertex2f(-0.85f,-0.33f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(194, 194, 163);
    glVertex2f(-0.59f,-0.43f);
    glVertex2f(-0.57f,-0.5f);
    glVertex2f(-0.52f,-0.5f);
    glVertex2f(-0.5f,-0.43f);
    glVertex2f(-0.52f,-0.42f);
    glVertex2f(-0.57f,-0.42f);
    glEnd();
}

void DrawSphere()
{
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
    glEnable ( GL_COLOR_MATERIAL ) ;
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    cloud3();
    glPopMatrix();
    moon();
    boat4();
    hut1();
    treeM();
    backgroundtree();
    fenceM();
    way();
    well1();
    Straw();
    ground();
    river();
    glPushMatrix();
    glTranslatef(0.0f,position4, 0.0f);
    sun();
    glPopMatrix();
    stars();
    sky2();
    glFlush();

}

void displayN()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(2);
    sky2();
    moon();
    stars();
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position22,0.0f, 0.0f);
    //bird();
    glPopMatrix();
    backgroundtree();
    riverN();
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    boat();
    glPopMatrix();
    ground1();
    way();
    fence2();
    hut2();
//    boat2();
    fenceM();
    treeN();
    well();
    Straw1();
    way1();
    hut();
    hut2();
    if(isRain){
     rain_fall();
    }

	glFlush();
	glutSwapBuffers();


}

struct Point
{
    float x, y;
    unsigned char r, g, b, a;
};

vector< Point > points;
void displayR(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glLineWidth(2);
    sky3();
    cloud1();
    cloud2();
    cloud3();
    backgroundtree();
    river();
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    boat();
    glPopMatrix();

    ground();
    way();
    way1();
if (isRain){
    rain_fall();
}

    fenceM();
    fence2();
    treeM();
    well();
    Straw();
    hut();
    hut2();
    glOrtho(-50, 50, -50, 50, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   // draw
    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glColor3ub( 255, 255, 255 );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
    glVertexPointer( 2, GL_FLOAT, sizeof(Point), &points[0].x );
    glColorPointer( 4, GL_UNSIGNED_BYTE, sizeof(Point), &points[0].r );
    glPointSize( 2.5 );
    glDrawArrays( GL_POINTS, 0, points.size() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState( GL_COLOR_ARRAY );
    glPopMatrix();
    glFlush();
    glutSwapBuffers();

}
///--------------------------------------------------------------2nd---------------------------------------------------------------

///-------------------------------------------------------------3rd-----------------------------------------------------------------


float _move = 0.0f;
float _move2 = 0.0f;
float _moves =0.005;
float _move2s=0.005;

float cloudPosition=-1.0;
float cloudSpeed=0.005;

void circle2(){
glBegin(GL_POLYGON);
float xOffa = 0.744;
float yOffa = -0.229;
for (int i = 0; i < 500; i++)
{
glColor3ub(255,255,255);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = -0.054;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}

void circle3(){
glBegin(GL_POLYGON);
float xOffa = 0.745;
float yOffa = -0.335;
for (int i = 0; i < 500; i++)
{
glColor3ub(255,255,255);
float pi = 3.1416;
float a = (i * 2 * pi) / 300;
float r = -0.075;
float x = r * cos(a) + xOffa;
float y = r * sin(a) + yOffa;
glVertex2f(x, y);
}
glEnd();
}
void cloud(float xc, float yc)
{
    glColor3f(1, 1, 1);
    circle1(xc-0.12, yc-0.05, 0.05f);
    circle1(xc-0.16, yc-0.1, 0.05f);
    circle1(xc-0.09, yc-0.1, 0.05f);
}


void sky19()                             ///OID-1
{
    ///sky
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    glColor3ub(200,224,232);
    glVertex2f(1.0f, 1.0f);
    glColor3ub(255,255,255);
    glVertex2f(-1.0f, 1.0f);

    glEnd();
}


void hills()                              ///OID-4
{
    ///left1
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-1.1,0.40);
    glColor3ub(176,196,222);
    glVertex2f(-0.85,0.9);
    glColor3ub(34,139,34);
    glVertex2f(-0.70,0.40);
    glEnd();

    ///left2
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.8,0.40);
    glVertex2f(-0.65,0.7);
    glVertex2f(-0.50,0.40);
    glEnd();

    ///left3
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.6,0.40);
    glVertex2f(-0.35,0.8);
    glVertex2f(-0.20,0.40);
    glEnd();

    ///left3
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.35,0.40);
    glVertex2f(-0.0,0.65);
    glVertex2f(0.20,0.40);
    glEnd();

    ///left4
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.10,0.40);
    glVertex2f(0.25,0.55);
    glVertex2f(0.40,0.40);
    glEnd();

    ///left5
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.40,0.40);
    glVertex2f(0.55,0.65);
    glVertex2f(0.75,0.40);
    glEnd();

    ///left6
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.70,0.40);
    glColor3ub(176,196,222);
    glVertex2f(0.95,0.82);
    glColor3ub(34,139,34);
    glVertex2f(1.1,0.40);
    glEnd();


}




void Cloud()                          ///OID-3
{
    ///cloud
    glPushMatrix();
    glTranslatef(cloudPosition+0.48,0.9,0);
    cloud(-0.3,0.0);
    cloud(0.2,0.1);
    cloud(0.5,-0.05);
    glPopMatrix();
}
void update_cloud(int value)        ///AFID-1
{
    cloudPosition+=cloudSpeed;
    if(cloudPosition>1.0)
    {
        cloudPosition=-1.7;
    }

    glutPostRedisplay();
    glutTimerFunc(80, update_cloud, 0);
}

void skatingroad()                             ///OID-17
{
    glBegin(GL_QUADS);
    glColor3f(209.0f / 255.0f, 227.0f / 255.0f, 255.0f / 255.0f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();


}

void road19()                             ///OID-16
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.35f);
    glVertex2f(-0.40f, -0.35f);
    glVertex2f(-0.40f, -0.3f);
    glVertex2f(-0.60f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.35f);
    glVertex2f(0.00f, -0.35f);
    glVertex2f(0.00f, -0.3f);
    glVertex2f(-0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.35f);
    glVertex2f(0.40f, -0.35f);
    glVertex2f(0.40f, -0.3f);
    glVertex2f(0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.35f);
    glVertex2f(0.80f, -0.35f);
    glVertex2f(0.80f, -0.3f);
    glVertex2f(0.60f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-1.0f, -0.67f);
    glVertex2f(-0.80f, -0.67f);
    glVertex2f(-0.80f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.60f, -0.67f);
    glVertex2f(-0.40f, -0.67f);
    glVertex2f(-0.40f, -0.7f);
    glVertex2f(-0.60f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.20f, -0.67f);
    glVertex2f(0.00f, -0.67f);
    glVertex2f(0.00f, -0.7f);
    glVertex2f(-0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(0.20f, -0.67f);
    glVertex2f(0.40f, -0.67f);
    glVertex2f(0.40f, -0.7f);
    glVertex2f(0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.67f);
    glVertex2f(0.80f, -0.67f);
    glVertex2f(0.80f, -0.7f);
    glVertex2f(0.60f, -0.7f);
    glEnd();

}





void cable(){
    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(-0.9696, 0.702);
    glVertex2f(-0.9596, 0.702);
    glVertex2f(-0.9584950286975, 0.644888102843);
    glVertex2f(-0.96982461821, 0.644888102843);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub		(255,255,255);
     glVertex2f(-1.0127577995204, 0.6454843970279);
     glVertex2f(-0.9233611918577, 0.6451961499495);
     glVertex2f(-0.9059953634307, 0.5929886490722);
     glVertex2f(-1.0280481778946, 0.5937889953966);
        glEnd();



                  glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
     glVertex2f(-1.0280481778946, 0.5937889953966);
     glVertex2f(-0.9059953634307, 0.5929886490722);
     glVertex2f(-0.9208017704313, 0.5541718523411);
     glVertex2f(-1.015242636705, 0.5549721986654);
           glEnd();

           glBegin(GL_LINES);
    glColor3ub(128,0,0);

            glVertex2f(-0.99,0.59);
                  glVertex2f (-0.997,0.64);
             glEnd();

            glBegin(GL_LINES);
    glColor3ub(128,0,0);
              glVertex2f(-0.935,0.59);
           glVertex2f (-0.93,0.64);

             glEnd();
}
void cable2(){

    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(0.96, 0.702);
    glVertex2f(0.9681, 0.702);
    glVertex2f(0.9677206393564, 0.6422895175778);
    glVertex2f(0.9598433631957, 0.6430772451939);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.9117919786159, 0.6422895175778);
    glVertex2f(1.0047438373113, 0.6418956537698);
     glVertex2f(1.0189229344005, 0.5906933587257);
    glVertex2f(0.8980067453348, 0.5899056311096);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(0.8980067453348, 0.5899056311096);
     glVertex2f(1.0189229344005, 0.5906933587257);
      glVertex2f(1.007105317983, 0.5492227572163);
      glVertex2f(0.9099011999664, 0.5507415715603);
      glEnd();

       glBegin(GL_LINES);
    glColor3ub(128,0,0);
       glVertex2f(0.9269333376212, 0.6434318867888);
      glVertex2f (0.92,0.59);
          glEnd();

       glBegin(GL_LINES);
    glColor3ub(128,0,0);
         glVertex2f(0.98,0.64);
         glVertex2f(0.99,0.590);
          glEnd();

}
void drawcable(){
    glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
cable();
glPopMatrix();
}

void drawcable2(){
     glPushMatrix();
glTranslatef(_move2, 0.0f, 0.0f);
cable2();
glPopMatrix();


}
void update2(int value) {
_move += 0.002;

if (_move > 1.96) {
_move = -1.0f;
}
_move2 -= 0.002;
if(_move2 <-1.96)
{
_move2= +1.0;
}


glutPostRedisplay();
glutTimerFunc(20, update2, 0); // Update every 20 milliseconds
}


void snowman(){



    circle2();
    circle3();
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.72,-0.18);
    glVertex2f(0.74,-0.15);
    glVertex2f(0.79,-0.15);
    glVertex2f(0.84,-0.18);
    glVertex2f(0.80,-0.18);
    glVertex2f(0.78,-0.19);

    glEnd();


}


void Display3(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /// Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);       /// Clear the color buffer (background)

    sky19();
    hills();
    river();
    flow();
    Cloud();
    Wire();
    drawcable();
    drawcable2();
    road19();
    skatingroad();
    tree();
    human(1,0,1,man1Position,0);
    human(0.5,0.2,0.6, man4Position,0);
    human(0,1,1,man2Position,0);
    human(1,0.5,0.5,man3Position,0);
    snowman();
    car();
    suv();

    if(isSnow)
    {
        snow_fall();
    }





    glFlush();  /// Render now
}





///-------------------------------------------------------------3rdend-------------------------------------------------------------


void Display1() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(2);
    skyM();
    sun();
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    cloud1();
    cloud2();
    cloud3();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position22,0.0f, 0.0f);
    bird();
    glPopMatrix();
    backgroundtree();
    riverM();
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    boat();
    glPopMatrix();
    ground();
    way();
    way1();
    well();
    Straw();
    fenceM();
    fence2();
    treeM();
    hut();
    hut2();
    if (isRain){
        rain_fall();
    }
    glFlush();
	glutSwapBuffers();
}


void handleMouse(int button, int state, int x, int y)       ///AFID-10
{
    if (button == GLUT_LEFT_BUTTON)
    {

          public_bus_speed+=0.001;
        ambulance_speed+=0.001;
        r_l_train_speed+=0.001;
        police_car_speed+=0.001;
        suv_car_speed+=0.001;
        car_speed+=0.001;
        man1Speed+=0.0012;
        man2Speed+=0.001;
        man3Speed+=0.0015;
        ship_speed+=0.001f;
        container_ship_speed+=0.05f;
        speedboat_speed+=0.05f;

    }
    if (button == GLUT_RIGHT_BUTTON)
    {

       public_bus_speed-=0.001;
        ambulance_speed-=0.001;
        police_car_speed-=0.001;
        suv_car_speed-=0.001;
        car_speed-=0.001;
        man1Speed-=0.0008;
        man2Speed-=0.0012;
        man3Speed-=0.0001;
        man4Speed-=0.0015;
        ship_speed-=0.001f;
        container_ship_speed-=0.05f;
        speedboat_speed-=0.05f;

    }
    glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y)    ///AFID-11
{

    switch (key)
    {
       case '1':
        glutDisplayFunc(display1_view);
        break;
    case '2':
        glutDisplayFunc(day_Display);
        break;
    case '3':
        glutDisplayFunc(Display1);

        break;
    case '4':
        glutDisplayFunc(Display3);
        break;
    case 'r':
        if(isRain)
        {
            isRain=false;
        }
        else
        {
            isRain=true;
            isSnow=false;
        }
        break;
    case 's':
        if(isSnow)
        {
            isSnow=false;
        }
        else
        {
            isSnow=true;
            isRain=false;
        }
        break;
    case '0':
        r_l_train_speed-=0.002;
        break;
    case '9':
        r_l_train_speed-=-0.002;
        break;
    case 'o':
        l_r_train_speed-=0.002;
        break;
    case 'p':
        l_r_train_speed-=-0.002;
        break;

    }
    glutPostRedisplay();
}

void myInit (void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("City");
    for( size_t i = 0; i < 1000; ++i )
    {
        Point pt;
        pt.x = -50 + (rand() % 100);
        pt.y = -50 + (rand() % 100);
        pt.r = 255;
        pt.g = 255;
        pt.b = 255;
        pt.a = 255;
        points.push_back(pt);
    }
    glMatrixMode(GL_PROJECTION);
    glutDisplayFunc(display1_view); /// default display
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(80, update_cloud, 0);
    glutTimerFunc(30, updateFlow, 0);
    glutTimerFunc(100, update_ship, 0);
    glutTimerFunc(10, update_speed_boat, 0);
    glutTimerFunc(150, updateHuman, 0);
    glutTimerFunc(60, updateVehicals, 0);
    glutTimerFunc(60, weather_update, 0);
    glutTimerFunc(100, cloud, 0);
    glutTimerFunc(100, sunn, 0);
    glutTimerFunc(100, boat, 0);
    glutTimerFunc(100, rain, 0);
    glutTimerFunc(100, birdd, 0);
    glutTimerFunc(10, update2, 0);
    glutMainLoop();
    glutDisplayFunc(Display1);

    myInit ();
    return 0;
}
