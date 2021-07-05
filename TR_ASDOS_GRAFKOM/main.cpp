#include<windows.h>
#include<GL/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0,0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar / tinggi, 5.0, 750.0);
    glTranslatef(0.0, -10.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(3.0);
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    glBegin(GL_QUADS);// ALAS DEPAN
    glColor3ub(255, 205, 255);
    glVertex3f(150.0, -24.0, 30.0); //PANJANG,Y,X
    glVertex3f(-70.0, -24.0, 30.0);
    glVertex3f(-70.0, -24.0, -80.0);
    glVertex3f(150.0, -24.0, -80.0);
    glEnd();

     glBegin(GL_QUADS);// GEDUNG UNIV
    glColor3ub(255, 205, 255);
    glVertex3f(300.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0,50.0, 300.0);
    glVertex3f(300.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //tembok kanan
    glColor3ub(255, 200, 155);
    glVertex3f(-150.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, -24.0, 30.0);
    glVertex3f(-150.0,-24.0, 300.0);
    glVertex3f(-150.0, 50.0, 300.0);
    glEnd();


    glBegin(GL_QUADS); //tembok kiri
    glColor3ub(255, 200, 155);
    glVertex3f(300.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(300.0, -24.0, 30.0);
    glVertex3f(300.0,-24.0, 300.0);
    glVertex3f(300.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //tembok depan
    glColor3ub(255, 200, 155);
    glVertex3f(-50.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-50.0, -24.0, 30.0);
    glVertex3f(-50.0,-24.0, 300.0);
    glVertex3f(-50.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS);//ALAS TANAH
    glColor3ub(105, 105, 105);
    glVertex3f(300.0, -24.0, 30.0);
    glVertex3f(-150.0, -24.0, 30.0);
    glVertex3f(-150.0, -24.0, 300.0);
    glVertex3f(300.0, -24.0, 300.0);
    glEnd();



    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 250);
    glutCreateWindow("TR_ASDOS_GRAFKOM_F");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
