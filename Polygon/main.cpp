#include <GL/glut.h>
#include <math.h>

const int steps=10;
const float angle=3.1416*2/steps;
float p=0.0;
void init()
{
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
}
void display()
{
float theta;
float lastX =0, lastY=0;
float radius=1;

glClear(GL_COLOR_BUFFER_BIT);

/*
glBegin(GL_POLYGON);
for(int i=0;i<steps;i++)
{

    theta=i*3.1416/180;
    glVertex2f(0.5+radius*sin(theta),0.5-radius*cos(theta));
}
glEnd();
*/

if(p<=0) //moving limit with the display measurement
        p=p+.005; // changing the object position for redisplaying

    else
        p=-2; // For backing the object continuously


glutPostRedisplay(); // To redraw the object in the display

glBegin(GL_TRIANGLES);
for (float i=0; i<=steps;i++)
{
    float newX= radius*sin(angle*i)+p;
    float newY= -radius*cos(angle*i)-p;
    float color=i/10;
    glColor3f(1-color, 1-color, 0.0);

    glVertex3f(0.0f,0.0f,0.0f);  //center
    glVertex3f(lastX, lastY, 0.f);
    glVertex3f(newX, newY, 0.f);
    lastX=newX;
    lastY=newY;

}
 glEnd();

glFlush();
}

int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
