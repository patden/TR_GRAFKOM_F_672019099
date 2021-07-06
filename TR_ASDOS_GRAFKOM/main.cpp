#include<windows.h>
#include<GL/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;
int h, j, g, k, l, m;


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
    glClearColor(0.0, 0.0, 0.0,0.0);
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

void building() {
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
    glVertex3f(-10.0, -24.0, 30.0);
    glVertex3f(-10.0, -24.0, -80.0);
    glVertex3f(150.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);//ALAS TANAH
    glColor3ub(105, 105, 105);
    glVertex3f(300.0, -24.0, 30.0);
    glVertex3f(-150.0, -24.0, 30.0);
    glVertex3f(-150.0, -24.0, 300.0);
    glVertex3f(300.0, -24.0, 300.0);
    glEnd();

    glBegin(GL_QUADS);// atap gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(150.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, 30.0);
    glVertex3f(-10.0, 50.0, -80.0);
    glVertex3f(150.0, 50.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kiri gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(150.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, -70.0);
    glVertex3f(150.0, 50.0, -80.0);
    glVertex3f(150.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kiri gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(145.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(145.0, 50.0, -70.0);
    glVertex3f(145.0, 50.0, -80.0);
    glVertex3f(145.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kiri gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(150.0, -24.0, -80.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, -80.0);
    glVertex3f(145.0, 50.0, -80.0);
    glVertex3f(145.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kiri gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(150.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(150.0, 50.0, -70.0);
    glVertex3f(145.0, 50.0, -70.0);
    glVertex3f(145.0, -24.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kanan gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(-10.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, -70.0);
    glVertex3f(-10.0, 50.0, -80.0);
    glVertex3f(-10.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kanan gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(-5.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(-5.0, 50.0, -70.0);
    glVertex3f(-5.0, 50.0, -80.0);
    glVertex3f(-5.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kanan gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(-10.0, -24.0, -80.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, -80.0);
    glVertex3f(-5.0, 50.0, -80.0);
    glVertex3f(-5.0, -24.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);// tembok kanan gerbang
    glColor3ub(255, 205, 255);
    glVertex3f(-10.0, -24.0, -70.0); //PANJANG,Y,X
    glVertex3f(-10.0, 50.0, -70.0);
    glVertex3f(-5.0, 50.0, -70.0);
    glVertex3f(-5.0, -24.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);// GEDUNG UNIV
    glColor3ub(255, 205, 255);
    glVertex3f(300.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0,50.0, 300.0);
    glVertex3f(300.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //tembok kanan
    glColor3ub(209, 118, 118);
    glVertex3f(-150.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, -24.0, 30.0);
    glVertex3f(-150.0,-24.0, 300.0);
    glVertex3f(-150.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //tembok kiri
    glColor3ub(209, 118, 118);
    glVertex3f(300.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(300.0, -24.0, 30.0);
    glVertex3f(300.0,-24.0, 300.0);
    glVertex3f(300.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //tembok dalam lantai 1
    glColor3ub(255, 200, 155);
    glVertex3f(-50.0, 50.0, 30.0); //PANJANG,Y,X
    glVertex3f(-50.0, -24.0, 30.0);
    glVertex3f(-50.0,-24.0, 300.0);
    glVertex3f(-50.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK DEPAN 1
    glColor3ub(209, 118, 118);
    glVertex3f(300.0, -24.0, 30.0);
    glVertex3f(-150.0, -24.0, 30.0);
    glVertex3f(-150.0, 50.0,30.0);
    glVertex3f(300.0, 50.0, 30.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK BELAKANG 1
    glColor3ub(209, 118, 118);
    glVertex3f(300.0, -24.0, 300.0);
    glVertex3f(-150.0, -24.0, 300.0);
    glVertex3f(-150.0, 50.0, 300.0);
    glVertex3f(300.0, 50.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //atap LANTAI 2
    glColor3ub(255, 153, 153);
    glVertex3f(300.0, 200.0, 30.0);
    glVertex3f(-150.0, 200.0, 30.0);
    glVertex3f(-150.0, 200.0, 300.0);
    glVertex3f(300.0, 200.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK KIRI 2
    glColor3ub(255, 243, 243);
    glVertex3f(300.0, 100.0, 30.0); //PANJANG,Y,X
    glVertex3f(300.0, 50.0, 30.0);
    glVertex3f(300.0, 50.0, 300.0);
    glVertex3f(300.0, 100.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK KANAN 2
    glColor3ub(255, 243, 243);
    glVertex3f(-150.0, 100.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 300.0);
    glVertex3f(-150.0, 100.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Belakang Lantai2
    glColor3ub(255, 243, 243);
    glVertex3f(300.0, 50.0, 300.0);
    glVertex3f(-150.0, 50.0, 300.0);
    glVertex3f(-150.0, 100.0,300.0);
    glVertex3f(300.0, 100.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Depan lantai2
    glColor3ub(255, 243, 243);
    glVertex3f(300.0, 50.0, 30.0);
    glVertex3f(-150.0, 50.0, 30.0);
    glVertex3f(-150.0, 100.0,30.0);
    glVertex3f(300.0, 100.0, 30.0);
    glEnd();

    glBegin(GL_QUADS); //atap LANTAI 3
    glColor3ub(255, 153, 153);
    glVertex3f(300.0, 100.0, 30.0);
    glVertex3f(-150.0, 100.0, 30.0);
    glVertex3f(-150.0, 100.0, 300.0);
    glVertex3f(300.0, 100.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Depan lantai3
    glColor3ub(255, 228, 228);
    glVertex3f(300.0, 100.0, 30.0);
    glVertex3f(-150.0, 100.0, 30.0);
    glVertex3f(-150.0, 150.0,30.0);
    glVertex3f(300.0, 150.0, 30.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Belakang Lantai3
    glColor3ub(255, 228, 228);
    glVertex3f(300.0, 100.0, 300.0);
    glVertex3f(-150.0, 100.0, 300.0);
    glVertex3f(-150.0, 150.0,300.0);
    glVertex3f(300.0, 150.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK KIRI 3
    glColor3ub(255, 228, 228);
    glVertex3f(300.0, 150.0, 30.0); //PANJANG,Y,X
    glVertex3f(300.0, 100.0, 30.0);
    glVertex3f(300.0, 100.0, 300.0);
    glVertex3f(300.0, 150.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK KANAN 3
    glColor3ub(255, 228, 228);
    glVertex3f(-150.0, 150.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, 100.0, 30.0);
    glVertex3f(-150.0, 100.0, 300.0);
    glVertex3f(-150.0, 150.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //atap LANTAI 4
    glColor3ub(255, 153, 153);
    glVertex3f(300.0, 150.0, 30.0);
    glVertex3f(-150.0, 150.0, 30.0);
    glVertex3f(-150.0, 150.0, 300.0);
    glVertex3f(300.0, 150.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Depan lantai3
    glColor3ub(255, 229, 229);
    glVertex3f(300.0, 200.0, 30.0);
    glVertex3f(-150.0, 200.0, 30.0);
    glVertex3f(-150.0, 150.0,30.0);
    glVertex3f(300.0, 150.0, 30.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK Belakang Lantai3
    glColor3ub(255, 229, 229);
    glVertex3f(300.0, 200.0, 300.0);
    glVertex3f(-150.0, 200.0, 300.0);
    glVertex3f(-150.0, 150.0,300.0);
    glVertex3f(300.0, 150.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK KIRI 3
    glColor3ub(255, 229, 229);
    glVertex3f(300.0, 150.0, 30.0); //PANJANG,Y,X
    glVertex3f(300.0, 200.0, 30.0);
    glVertex3f(300.0, 200.0, 300.0);
    glVertex3f(300.0, 150.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //TEMBOK KANAN 3
    glColor3ub(255, 229, 229);
    glVertex3f(-150.0, 200.0, 30.0); //PANJANG,Y,X
    glVertex3f(-150.0, 150.0, 30.0);
    glVertex3f(-150.0, 150.0, 300.0);
    glVertex3f(-150.0, 200.0, 300.0);
    glEnd();

    glBegin(GL_QUADS); //kotak atap kiri -depan
    glColor3ub(209, 118, 118);
    glVertex3f(300.0, 260.0, 30.0);
    glVertex3f(230.0, 260.0, 30.0);
    glVertex3f(230.0, 200.0, 30.0);
    glVertex3f(300.0, 200.0, 30.0);

    glColor3ub(209, 118, 118);//samping kiri
    glVertex3f(300.0, 260.0, 100.0);
    glVertex3f(300.0, 260.0, 30.0);
    glVertex3f(300.0, 200.0, 30.0);
    glVertex3f(300.0, 200.0, 100.0);

    glColor3ub(209, 118, 118);//samping kanan
    glVertex3f(230.0, 260.0, 100.0);
    glVertex3f(230.0, 260.0, 30.0);
    glVertex3f(230.0, 200.0, 30.0);
    glVertex3f(230.0, 200.0, 100.0);

    glColor3ub(217, 17, 61);//tutup atas
    glVertex3f(305.0, 260.0, 25.0);
    glVertex3f(225.0, 260.0, 25.0);
    glVertex3f(225.0, 260.0, 105.0);
    glVertex3f(305.0, 260.0, 105.0);

    glColor3ub(209, 118, 118);//kotak Atap kiri -belkang
    glVertex3f(300.0, 260.0, 100.0);
    glVertex3f(230.0, 260.0, 100.0);
    glVertex3f(230.0, 200.0, 100.0);
    glVertex3f(300.0, 200.0, 100.0);

    glColor3ub(209, 197, 163);//PUCUK KOTAK SITIK depan
    glVertex3f(305.0, 260.0, 25.5);
    glVertex3f(225.0, 260.0, 25.5);
    glVertex3f(225.0, 280.0, 25.5);
    glVertex3f(305.0, 280.0, 25.5);

    glColor3ub(209, 197, 163);//// PUCUK KOTAK SITIK belakang
    glVertex3f(305.0, 260.0, 105.0);
    glVertex3f(225.0, 260.0, 105.0);
    glVertex3f(225.0, 280.0, 105.0);
    glVertex3f(305.0, 280.0, 105.0);

    glColor3ub(209, 197, 163);// PUCUK KOTAK SITIK KANAN
    glVertex3f(225.0, 260.0, 105.0);
    glVertex3f(225.0, 260.0, 25.0);
    glVertex3f(225.0, 280.0, 25.0);
    glVertex3f(225.0, 280.0, 105.0);

    glColor3ub(209, 197, 163);//// PUCUK KOTAK SITIK KIRI
    glVertex3f(305.0, 260.0, 105.0);
    glVertex3f(305.0, 260.0, 25.0);
    glVertex3f(305.0, 280.0, 25.0);
    glVertex3f(305.0, 280.0, 105.0);
    glEnd();


    glBegin(GL_QUADS); //kotak atap tengah -depan
    glColor3ub(209, 118, 118);
    glVertex3f(10.0, 250.0, 30.0);
    glVertex3f(110.0, 250.0, 30.0);
    glVertex3f(110.0, 200.0,30.0);
    glVertex3f(10.0, 200.0, 30.0);

    glColor3ub(209, 118, 118);//samping kanan
    glVertex3f(10.0, 250.0, 100.0);
    glVertex3f(10.0, 250.0, 30.0);
    glVertex3f(10.0, 200.0, 30.0);
    glVertex3f(10.0, 200.0, 100.0);

    glColor3ub(209, 118, 118);//samping kanan
    glVertex3f(110.0, 250.0, 100.0);
    glVertex3f(110.0, 250.0, 30.0);
    glVertex3f(110.0, 200.0, 30.0);
    glVertex3f(110.0, 200.0, 100.0);

    glColor3ub(2209, 118, 118);//tutup atas
    glVertex3f(10.0, 250.0, 30.0);
    glVertex3f(110.0, 250.0, 30.0);
    glVertex3f(110.0, 250.0, 100.0);
    glVertex3f(10.0, 250.0, 100.0);

    glColor3ub(209, 118, 118);//kotak Atap kiri -belkang
    glVertex3f(10.0, 250.0, 100.0);
    glVertex3f(110.0, 250.0, 100.0);
    glVertex3f(110.0, 200.0, 100.0);
    glVertex3f(10.0, 200.0, 100.0);

     glColor3ub(209, 118, 118);//Atap samping kIri
    glVertex3f(110.0, 250.0, 100.0);
    glVertex3f(110.0, 250.0, 30.0);
    glVertex3f(60.0, 290.0, 30.0);
    glVertex3f(60.0, 290.0, 100.0);

    glColor3ub(209, 118, 118);//Atap samping kanan
    glVertex3f(10.0, 250.0, 100.0);
    glVertex3f(10.0, 250.0, 30.0);
    glVertex3f(60.0, 290.0, 30.0);
    glVertex3f(60.0, 290.0, 100.0);
    glEnd();

    glBegin(GL_TRIANGLES);//ATAP SEGITIGA TENGAH depan
    glColor3ub(255, 234, 171);
    glVertex3f(10.0, 250.0, 30.0);
    glVertex3f(60.0, 290.0, 30.0);
    glVertex3f(110.0, 250.0, 30.0);

    glColor3ub(255, 234, 171);//ATAP SEGITIGA TENGAH belakang
    glVertex3f(10.0, 250.0, 100.0);
    glVertex3f(60.0, 290.0, 100.0);
    glVertex3f(110.0, 250.0, 100.0);
    glEnd();

    glBegin(GL_QUADS); //kotak atap Kanan -depan
    glColor3ub(209, 118, 118);
    glVertex3f(-150.0, 260.0, 30.0);
    glVertex3f(-80.0, 260.0, 30.0);
    glVertex3f(-80.0, 200.0,30.0);
    glVertex3f(-150.0, 200.0, 30.0);

    glColor3ub(209, 118, 118);//samping kanan
    glVertex3f(-150.0, 260.0, 100.0);
    glVertex3f(-150.0, 260.0, 30.0);
    glVertex3f(-150.0, 200.0, 30.0);
    glVertex3f(-150.0, 200.0, 100.0);

    glColor3ub(209, 118, 118);//samping kanan
    glVertex3f(-80.0, 260.0, 100.0);
    glVertex3f(-80.0, 260.0, 30.0);
    glVertex3f(-80.0, 200.0, 30.0);
    glVertex3f(-80.0, 200.0, 100.0);

    glColor3ub(217, 17, 61);//tutup atas
    glVertex3f(-155.0, 260.0, 25.0);
    glVertex3f(-75.0, 260.0, 25.0);
    glVertex3f(-75.0, 260.0, 105.0);
    glVertex3f(-155.0, 260.0, 105.0);

    glColor3ub(209, 118, 118);//kotak Atap kanan -belkang
    glVertex3f(-150.0, 260.0, 100.0);
    glVertex3f(-80.0, 260.0, 100.0);
    glVertex3f(-80.0, 200.0, 100.0);
    glVertex3f(-150.0, 200.0, 100.0);

    glColor3ub(209, 197, 163);//PUCUK KOTAK SITIK depan
    glVertex3f(-155.0, 260.0, 25.5);
    glVertex3f(-75.0, 260.0, 25.5);
    glVertex3f(-75.0, 280.0, 25.5);
    glVertex3f(-155.0, 280.0, 25.5);

    glColor3ub(209, 197, 163);// PUCUK KOTAK SITIK KANAN
    glVertex3f(-75.0, 260.0, 105.0);
    glVertex3f(-75.0, 260.0, 25.0);
    glVertex3f(-75.0, 280.0, 25.0);
    glVertex3f(-75.0, 280.0, 105.0);

    glColor3ub(209, 197, 163);//// PUCUK KOTAK SITIK KIRI
    glVertex3f(-155.0, 260.0, 105.0);
    glVertex3f(-155.0, 260.0, 25.0);
    glVertex3f(-155.0, 280.0, 25.0);
    glVertex3f(-155.0, 280.0, 105.0);

    glColor3ub(209, 197, 163);//// PUCUK KOTAK SITIK belakang
    glVertex3f(-155.0, 260.0, 105.0);
    glVertex3f(-75.0, 260.0, 105.0);
    glVertex3f(-75.0, 280.0, 105.0);
    glVertex3f(-155.0, 280.0, 105.0);

    glEnd();

}

void kursi(int h, int j, int g) {
    //PERABOTAN
    glBegin(GL_QUADS);
    glColor3ub(130, 73, 9);
    glVertex3d(h, j, g);
    glVertex3d(h + 20, j, g);
    glVertex3d(h + 20, j+10, g);
    glVertex3d(h, j+10, g);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g+2);
    glVertex3d(h + 20, j, g+2);
    glVertex3d(h + 20, j+10, g+2);
    glVertex3d(h, j+10, g+2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h + 20, j, g);
    glVertex3d(h + 20, j, g + 2 );
    glVertex3d(h + 20, j + 10, g + 2);
    glVertex3d(h + 20, j + 10, g);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g);
    glVertex3d(h, j, g + 2);
    glVertex3d(h, j + 10, g + 2);
    glVertex3d(h, j + 10, g);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j + 10, g);
    glVertex3d(h, j + 10, g + 2);
    glVertex3d(h+20, j + 10, g + 2);
    glVertex3d(h+20, j + 10, g);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3d(h, j + 4, g + 2);
    glVertex3d(h, j + 4, g + 7);
    glVertex3d(h + 20, j + 4, g +7);
    glVertex3d(h + 20, j + 4, g +2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g + 7);
    glVertex3d(h, j + 4, g + 7);
    glVertex3d(h + 20, j + 4, g + 7);
    glVertex3d(h + 20, j, g + 7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h +20, j, g + 2);
    glVertex3d(h +20, j + 4, g + 2);
    glVertex3d(h + 20, j + 4, g + 7);
    glVertex3d(h + 20, j, g + 7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(h, j, g + 2);
    glVertex3d(h, j + 4, g + 2);
    glVertex3d(h, j + 4, g + 7);
    glVertex3d(h, j, g + 7);
    glEnd();
}
void pintu(int o,int p,int q) {
    glBegin(GL_QUADS);
    glColor3ub(130, 73, 9);
    glVertex3d(o - 5.5, p-5, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q + 0.5);
    glVertex3d(o + 6.5, p + 23, q + 0.5);
    glVertex3d(o + 6.5, p-5, q + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p-5, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q - 0.25);
    glVertex3d(o - 5.5, p-5, q - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p-5, q - 0.25);
    glVertex3d(o - 5.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p-5, q - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o + 6.5, p-5, q + 0.5);
    glVertex3d(o + 6.5, p + 23, q + 0.5);
    glVertex3d(o + 6.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p-5, q - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p + 23, q + 0.5);
    glVertex3d(o - 5.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p + 23, q - 0.25);
    glVertex3d(o + 6.5, p + 23, q + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5.5, p-5, q + 0.5);
    glVertex3d(o - 5.5, p-5, q - 0.25);
    glVertex3d(o + 6.5, p-5, q - 0.25);
    glVertex3d(o + 6.5, p-5, q + 0.5);
    glEnd();

    //gagang pintu
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3d(o - 5, p + 10, q + 0.7);
    glVertex3d(o - 5, p + 14, q + 0.7);
    glVertex3d(o - 4, p + 14, q + 0.7);
    glVertex3d(o - 4, p + 10, q + 0.7);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(o - 5, p + 10, q - 0.27);
    glVertex3d(o - 5, p + 14, q - 0.27);
    glVertex3d(o - 4, p + 14, q - 0.27);
    glVertex3d(o - 4, p + 10, q - 0.27);
    glEnd();
}
void jendela(int k,int l,int m){
    glBegin(GL_QUADS);
    glColor3ub(130, 73, 9);
    glVertex3d(k - 5.5, l+1, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m + 0.5);
    glVertex3d(k + 6.5, l + 23, m + 0.5);
    glVertex3d(k + 6.5, l+1, m + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l+1, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m - 0.25);
    glVertex3d(k - 5.5, l+1, m - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l+1, m - 0.25);
    glVertex3d(k - 5.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l+1, m - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k + 6.5,l+1, m + 0.5);
    glVertex3d(k + 6.5, l + 23, m + 0.5);
    glVertex3d(k + 6.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l+1, m - 0.25);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l + 23, m + 0.5);
    glVertex3d(k - 5.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l + 23, m - 0.25);
    glVertex3d(k + 6.5, l + 23, m + 0.5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(k - 5.5, l+1, m + 0.5);
    glVertex3d(k - 5.5, l+1, m - 0.25);
    glVertex3d(k + 6.5, l+1, m - 0.25);
    glVertex3d(k + 6.5, l+1, m + 0.5);
    glEnd();

    //kacakiri
    glBegin(GL_POLYGON);
    glColor3ub(38, 38, 38);
    glVertex3d(k - 4.5, l + 16, m + 0.55);
    glVertex3d(k - 4.5, l + 22, m + 0.55);
    glVertex3d(k - 0.5, l + 22, m + 0.55);
    glVertex3d(k - 0.5, l + 16, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 9, m + 0.55);
    glVertex3d(k - 4.5, l + 15, m + 0.55);
    glVertex3d(k - 0.5, l + 15, m + 0.55);
    glVertex3d(k - 0.5, l + 9, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 2, m + 0.55);
    glVertex3d(k - 4.5, l + 8, m + 0.55);
    glVertex3d(k - 0.5, l + 8, m + 0.55);
    glVertex3d(k - 0.5, l + 2, m + 0.55);
    glEnd();

    //kaca kanan
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 16, m + 0.55);
    glVertex3d(k + 1.5, l + 22, m + 0.55);
    glVertex3d(k + 5.5, l + 22, m + 0.55);
    glVertex3d(k + 5.5, l + 16, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 9, m + 0.55);
    glVertex3d(k + 1.5, l + 15, m + 0.55);
    glVertex3d(k + 5.5, l + 15, m + 0.55);
    glVertex3d(k + 5.5, l + 9, m + 0.55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 2, m + 0.55);
    glVertex3d(k + 1.5, l + 8, m + 0.55);
    glVertex3d(k + 5.5, l + 8, m + 0.55);
    glVertex3d(k + 5.5, l + 2, m + 0.55);
    glEnd();

    //kaca kiri belakang
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 16, m - 0.255);
    glVertex3d(k - 4.5, l + 22, m - 0.255);
    glVertex3d(k - 0.5, l + 22, m - 0.255);
    glVertex3d(k - 0.5, l + 16, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 9, m - 0.255);
    glVertex3d(k - 4.5, l + 15, m - 0.255);
    glVertex3d(k - 0.5, l + 15, m - 0.255);
    glVertex3d(k - 0.5, l + 9, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k - 4.5, l + 2, m - 0.255);
    glVertex3d(k - 4.5, l + 8, m - 0.255);
    glVertex3d(k - 0.5, l + 8, m - 0.255);
    glVertex3d(k - 0.5, l + 2, m - 0.255);
    glEnd();

    //kaca kanan belakang
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 16, m - 0.255);
    glVertex3d(k + 1.5, l + 22, m - 0.255);
    glVertex3d(k + 5.5, l + 22, m - 0.255);
    glVertex3d(k + 5.5, l + 16, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 9, m - 0.255);
    glVertex3d(k + 1.5, l + 15, m - 0.255);
    glVertex3d(k + 5.5, l + 15, m - 0.255);
    glVertex3d(k + 5.5, l + 9, m - 0.255);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(k + 1.5, l + 2, m - 0.255);
    glVertex3d(k + 1.5, l + 8, m - 0.255);
    glVertex3d(k + 5.5, l + 8, m - 0.255);
    glVertex3d(k + 5.5, l + 2, m - 0.255);
    glEnd();



}
void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    building();
    glScalef(1.5f, 1.5f, 1.0f);
    pintu(40,-10,30);
    jendela(10, -6, 30);//lantai1
    jendela(-20, -6, 30);
    jendela(-50, -6, 30);
    jendela(-80, -6, 30);
    jendela(70, -6, 30);
    jendela(100, -6, 30);
    jendela(130, -6, 30);
    jendela(160, -6, 30);

    jendela(10, 37, 30);//lantai2
    jendela(-20, 37, 30);
    jendela(-50, 37, 30);
    jendela(-80, 37, 30);
    jendela(40,37,30);
    jendela(70, 37, 30);
    jendela(100, 37, 30);
    jendela(130, 37, 30);
    jendela(160, 37, 30);

    jendela(10, 70, 30);//lantai3
    jendela(-20, 70, 30);
    jendela(-50, 70, 30);
    jendela(-80, 70, 30);
    jendela(40,70,30);
    jendela(70, 70, 30);
    jendela(100, 70, 30);
    jendela(130, 70, 30);
    jendela(160, 70, 30);

    jendela(10, 105, 30);//lantai4
    jendela(-20, 105, 30);
    jendela(-50, 105, 30);
    jendela(-80, 105, 30);
    jendela(40,105,30);
    jendela(70, 105, 30);
    jendela(100, 105, 30);
    jendela(130, 105, 30);
    jendela(160, 105, 30);

    kursi(-100,-16,35);//lantai1baris1
    kursi(-60,-16,35);
    kursi(0,-16,35);
    kursi(50,-16,35);
    kursi(100,-16,35);
    kursi(150,-16,35);

    kursi(-100,-16,70);//lantai1baris2
    kursi(-60,-16,70);
    kursi(0,-16,70);
    kursi(50,-16,70);
    kursi(100,-16,70);
    kursi(150,-16,70);

    kursi(-100,-16,105);//lantai1baris3
    kursi(-60,-16,105);
    kursi(0,-16,105);
    kursi(50,-16,105);
    kursi(100,-16,105);
    kursi(150,-16,105);

    kursi(-100,-16,140);//lantai1baris4
    kursi(-60,-16,140);
    kursi(0,-16,140);
    kursi(50,-16,140);
    kursi(100,-16,140);
    kursi(150,-16,140);

    kursi(-100,34,35);//lantai2baris1
    kursi(-60,34,35);
    kursi(0,34,35);
    kursi(50,34,35);
    kursi(100,34,35);
    kursi(150,34,35);

    kursi(-100,34,70);//lantai2baris2
    kursi(-60,34,70);
    kursi(0,34,70);
    kursi(50,34,70);
    kursi(100,34,70);
    kursi(150,34,70);

    kursi(-100,34,105);//lantai2baris3
    kursi(-60,34,105);
    kursi(0,34,105);
    kursi(50,34,105);
    kursi(100,34,105);
    kursi(150,34,105);

    kursi(-100,34,140);//lantai2baris4
    kursi(-60,34,140);
    kursi(0,-16,140);
    kursi(50,34,140);
    kursi(100,34,140);
    kursi(150,34,140);
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
