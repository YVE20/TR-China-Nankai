#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define M_PI 3.14

void init(void);
void tampil(void);
void keyboard(unsigned char,int, int);
void mouse (int button, int state, int x, int y);
void ukuran(int,int);
void mouseMotion(int x,int y);
void idle();

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int i;

int main (int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Nankai University");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void ngon (int n,float cx, float cy,float radius, float rotAngle) {
    double angle,angleInc;
    int x;
    if(n<2) return;
    angle = rotAngle*3.14159265/180;
    angleInc = 2*3.14159265/n;
    glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,-9.9);
    for (x=0;x<n;x++){
        angle +=angleInc;
        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,-9.9);
    }
}

void jamdinding(void){
    int a,b=0;
    glBegin(GL_POLYGON);
    for (a=0;a<10;a++){
        glColor3f(1.0,1.0,1.0);
        ngon(100,-3,3,2,20);
        a++;
    }
    glEnd();

    //jarum menit
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0,3.0,-9.8);
    glVertex3f(-3.2,4.0,-9.8);
    glVertex3f(-3.0,5.0,-9.8);
    glVertex3f(-2.8,4.0,-9.8);
    glEnd();
    //jarum jam
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0,3.0,-9.8);
    glVertex3f(-2.5,3.2,-9.8);
    glVertex3f(-2.0,3.0,-9.8);
    glVertex3f(-2.5,2.8,-9.8);
    glEnd();
}

void loker (void){
    //KANAN
    glBegin(GL_QUADS);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-9.9); //KANAN BAWAH
    glVertex3f(20,0,-9.9); //KANAN ATAS
    glVertex3f(20,0,-7); //KIRI ATAS
    glVertex3f(20,-9.9,-7); //KIRI BAWAH
    glEnd();
    //KIRI
    glBegin(GL_QUADS);
    glColor3ub(188, 188, 188);
    glVertex3f(10,-9.9,-9.9); //KANAN BAWAH
    glVertex3f(10,0,-9.9); //KANAN ATAS
    glVertex3f(10,0,-7); //KIRI ATAS
    glVertex3f(10,-9.9,-7); //KIRI BAWAH
    glEnd();
    //DEPAN
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-7); //KANAN BAWAH
    glVertex3f(20,0,-7); //KANAN ATAS
    glVertex3f(10,0,-7); //KIRI ATAS
    glVertex3f(10,-9.9,-7); //KIRI BAWAH
    glEnd();
    //BELAKANG
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-9.9); //KANAN BAWAH
    glVertex3f(20,0,-9.9); //KANAN ATAS
    glVertex3f(10,0,-9.9); //KIRI ATAS
    glVertex3f(10,-9.9,-9.9); //KIRI BAWAH
    glEnd();
    //ATAS
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,0,-7); //KANAN BAWAH
    glVertex3f(20,0,-9.9); //KANAN ATAS
    glVertex3f(10,0,-9.9); //KIRI ATAS
    glVertex3f(10,0,-7); //KIRI BAWAH
    glEnd();
    //BAWAH
    glBegin(GL_POLYGON);
    glColor3ub(188, 188, 188);
    glVertex3f(20,-9.9,-7); //KANAN BAWAH
    glVertex3f(20,-9.9,-9.9); //KANAN ATAS
    glVertex3f(10,-9.9,-9.9); //KIRI ATAS
    glVertex3f(10,-9.9,-7); //KIRI BAWAH
    glEnd();
    //PINTU
        glBegin(GL_QUADS);
        glColor3ub(227, 227, 227);

        //Kanan Bawah
        glVertex3f(17,-8,-6.8); //KANAN BAWAH
        glVertex3f(17,-6,-6.8); //KANAN ATAS
        glVertex3f(19,-6,-6.8); //KIRI ATAS
        glVertex3f(19,-8,-6.8); //KIRI BAWAH

        //Kanan Atas
        glVertex3f(17,-4,-6.8); //KANAN BAWAH
        glVertex3f(17,-1,-6.8); //KANAN ATAS
        glVertex3f(19,-1,-6.8); //KIRI ATAS
        glVertex3f(19,-4,-6.8); //KIRI BAWAH

        //Tengah Bawah
        glVertex3f(14,-8,-6.8); //KANAN BAWAH
        glVertex3f(14,-6,-6.8); //KANAN ATAS
        glVertex3f(16,-6,-6.8); //KIRI ATAS
        glVertex3f(16,-8,-6.8); //KIRI BAWAH

        //Tengah Atas
        glVertex3f(14,-4,-6.8); //KANAN BAWAH
        glVertex3f(14,-1,-6.8); //KANAN ATAS
        glVertex3f(16,-1,-6.8); //KIRI ATAS
        glVertex3f(16,-4,-6.8); //KIRI BAWAH

        //Kiri Bawah
        glVertex3f(11,-8,-6.8); //KANAN BAWAH
        glVertex3f(11,-6,-6.8); //KANAN ATAS
        glVertex3f(13,-6,-6.8); //KIRI ATAS
        glVertex3f(13,-8,-6.8); //KIRI BAWAH

        //Kiri Atas
        glVertex3f(11,-4,-6.8); //KANAN BAWAH
        glVertex3f(11,-1,-6.8); //KANAN ATAS
        glVertex3f(13,-1,-6.8); //KIRI ATAS
        glVertex3f(13,-4,-6.8); //KIRI BAWAH


        glEnd();

}

void meja (void){
    //KAKI TAMPAK DEPAN
        //KIRI
            glBegin(GL_QUADS);
            glColor3f(0.0,0.0,.0);
            glVertex3f(-9,-10,-2.5); //KIRI BAWAH
            glVertex3f(-9,-4,-2.5); //KIRI ATAS
            glVertex3f(-8.5,-4,-2.5); //KANAN ATAS
            glVertex3f(-8.5,-10,-2.5); //KANAN BAWAH
            //DEPAN
            glVertex3f(-9,-10,-2); //KIRI BAWAH
            glVertex3f(-9,-4,-2); //KIRI ATAS
            glVertex3f(-8.5,-4,-2); //KANAN ATAS
            glVertex3f(-8.5,-10,-2); //KANAN BAWAH
            glEnd();
            //KANAN
            glBegin(GL_QUADS);
            glColor3f(0.0,0.0,0.0);
            glVertex3f(-8.5,-10,-2); //KIRI BAWAH
            glVertex3f(-8.5,-4,-2); //KIRI ATAS
            glVertex3f(-8.5,-4,-2.5); //KANAN ATAS
            glVertex3f(-8.5,-10,-2.5); //KANAN BAWAH
            //KIRI
            glVertex3f(-9,-10,-2); //KIRI BAWAH
            glVertex3f(-9,-4,-2); //KIRI ATAS
            glVertex3f(-9,-4,-2.5); //KANAN ATAS
            glVertex3f(-9,-10,-2.5); //KANAN BAWAH
            glEnd();

        //KANAN
            glBegin(GL_QUADS);
            glColor3f(0.0,0.0,.0);
            glVertex3f(-7,-10,-2.5); //KIRI BAWAH
            glVertex3f(-7,-4,-2.5); //KIRI ATAS
            glVertex3f(-6.5,-4,-2.5); //KANAN ATAS
            glVertex3f(-6.5,-10,-2.5); //KANAN BAWAH
            //DEPAN
            glVertex3f(-7,-10,-2); //KIRI BAWAH
            glVertex3f(-7,-4,-2); //KIRI ATAS
            glVertex3f(-6.5,-4,-2); //KANAN ATAS
            glVertex3f(-6.5,-10,-2); //KANAN BAWAH
            glEnd();
            //KANAN
            glBegin(GL_QUADS);
            glColor3f(0.0,0.0,0.0);
            glVertex3f(-6.5,-10,-2); //KIRI BAWAH
            glVertex3f(-6.5,-4,-2); //KIRI ATAS
            glVertex3f(-6.5,-4,-2.5); //KANAN ATAS
            glVertex3f(-6.5,-10,-2.5); //KANAN BAWAH
            //KIRI
            glVertex3f(-7,-10,-2); //KIRI BAWAH
            glVertex3f(-7,-4,-2); //KIRI ATAS
            glVertex3f(-7,-4,-2.5); //KANAN ATAS
            glVertex3f(-7,-10,-2.5); //KANAN BAWAH
            glEnd();

    //TAMPAK BELAKANG
            //KIRI
                glBegin(GL_QUADS);
                glColor3f(0.0,0.0,.0);
                glVertex3f(-9,-10,-6.5); //KIRI BAWAH
                glVertex3f(-9,-4,-6.5); //KIRI ATAS
                glVertex3f(-8.5,-4,-6.5); //KANAN ATAS
                glVertex3f(-8.5,-10,-6.5); //KANAN BAWAH
                //DEPAN
                glVertex3f(-9,-10,-6); //KIRI BAWAH
                glVertex3f(-9,-4,-6); //KIRI ATAS
                glVertex3f(-8.5,-4,-6); //KANAN ATAS
                glVertex3f(-8.5,-10,-6); //KANAN BAWAH
                glEnd();
                //KANAN
                glBegin(GL_QUADS);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-8.5,-10,-6); //KIRI BAWAH
                glVertex3f(-8.5,-4,-6); //KIRI ATAS
                glVertex3f(-8.5,-4,-6.5); //KANAN ATAS
                glVertex3f(-8.5,-10,-6.5); //KANAN BAWAH
                //KIRI
                glVertex3f(-9,-10,-6); //KIRI BAWAH
                glVertex3f(-9,-4,-6); //KIRI ATAS
                glVertex3f(-9,-4,-6.5); //KANAN ATAS
                glVertex3f(-9,-10,-6.5); //KANAN BAWAH
                glEnd();

            //KANAN
                glBegin(GL_QUADS);
                glColor3f(0.0,0.0,.0);
                glVertex3f(-7,-10,-6.5); //KIRI BAWAH
                glVertex3f(-7,-4,-6.5); //KIRI ATAS
                glVertex3f(-6.5,-4,-6.5); //KANAN ATAS
                glVertex3f(-6.5,-10,-6.5); //KANAN BAWAH
                //DEPAN
                glVertex3f(-7,-10,-6); //KIRI BAWAH
                glVertex3f(-7,-4,-6); //KIRI ATAS
                glVertex3f(-6.5,-4,-6); //KANAN ATAS
                glVertex3f(-6.5,-10,-6); //KANAN BAWAH
                glEnd();
                //KANAN
                glBegin(GL_QUADS);
                glColor3f(0.0,0.0,0.0);
                glVertex3f(-6.5,-10,-6); //KIRI BAWAH
                glVertex3f(-6.5,-4,-6); //KIRI ATAS
                glVertex3f(-6.5,-4,-6.5); //KANAN ATAS
                glVertex3f(-6.5,-10,-6.5); //KANAN BAWAH
                //KIRI
                glVertex3f(-7,-10,-6); //KIRI BAWAH
                glVertex3f(-7,-4,-6); //KIRI ATAS
                glVertex3f(-7,-4,-6.5); //KANAN ATAS
                glVertex3f(-7,-10,-6.5); //KANAN BAWAH
                glEnd();
    //ATAS
        //TAMPAK DEPAN
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.1);
        glVertex3f(-9,-4.0,-2); //KIRI BAWAH
        glVertex3f(-9,-3.5,-2); //KIRI ATAS
        glVertex3f(-6.5,-3.5,-2); //KANAN ATAS
        glVertex3f(-6.5,-4.0,-2); //KANAN BAWAH
        //TAMPAK BELAKANG
        glVertex3f(-9,-4.0,-6.5); //KIRI BAWAH
        glVertex3f(-9,-3.5,-6.5); //KIRI ATAS
        glVertex3f(-6.5,-3.5,-6.5); //KANAN ATAS
        glVertex3f(-6.5,-4.0,-6.5); //KANAN BAWAH
        //TAMPAK KANAN
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-6.5,-4.0,-2); //KIRI BAWAH
        glVertex3f(-6.5,-3.5,-2); //KIRI ATAS
        glVertex3f(-6.5,-3.5,-6.5); //KANAN ATAS
        glVertex3f(-6.5,-4.0,-6.5); //KANAN BAWAH
        //TAMPAK KIRI
        glVertex3f(-9,-4.0,-2); //KANAN BAWAH
        glVertex3f(-9,-3.5,-2); //KANAN ATAS
        glVertex3f(-9,-3.5,-6.5); //KIRI ATAS
        glVertex3f(-9,-4.0,-6.5); //KIRI BAWAH
        //ATAS
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-9,-3.5,-2); //KIRI BAWAH
        glVertex3f(-9,-3.5,-6.5); //KIRI ATAS
        glVertex3f(-6.5,-3.5,-6.5); //KANAN ATAS
        glVertex3f(-6.5,-3.5,-2); //KANAN BAWAH
        glEnd();

}

void kursi (void){
    //KAKI TAMPAK DEPAN
        //KIRI
            glBegin(GL_QUADS);
            glColor3f(0.5,0.5,.0);
            glVertex3f(-3,-10,-3.5); //KIRI BAWAH
            glVertex3f(-3,-7,-3.5); //KIRI ATAS
            glVertex3f(-2.5,-7,-3.5); //KANAN ATAS
            glVertex3f(-2.5,-10,-3.5); //KANAN BAWAH
            //DEPAN
            glVertex3f(-3,-10,-3); //KIRI BAWAH
            glVertex3f(-3,-7,-3); //KIRI ATAS
            glVertex3f(-2.5,-7,-3); //KANAN ATAS
            glVertex3f(-2.5,-10,-3); //KANAN BAWAH
            glEnd();
            //KANAN
            glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-2.5,-10,-3); //KIRI BAWAH
            glVertex3f(-2.5,-7,-3); //KIRI ATAS
            glVertex3f(-2.5,-7,-3.5); //KANAN ATAS
            glVertex3f(-2.5,-10,-3.5); //KANAN BAWAH
            //KIRI
            glVertex3f(-3,-10,-3); //KIRI BAWAH
            glVertex3f(-3,-7,-3); //KIRI ATAS
            glVertex3f(-3,-7,-3.5); //KANAN ATAS
            glVertex3f(-3,-10,-3.5); //KANAN BAWAH
            glEnd();

        //KANAN
            glBegin(GL_QUADS);
            glColor3f(0.5,0.5,.0);
            glVertex3f(-1,-10,-3.5); //KIRI BAWAH
            glVertex3f(-1,-4,-3.5); //KIRI ATAS
            glVertex3f(-0.5,-4,-3.5); //KANAN ATAS
            glVertex3f(-0.5,-10,-3.5); //KANAN BAWAH
            //DEPAN
            glVertex3f(-1,-10,-3); //KIRI BAWAH
            glVertex3f(-1,-3,-3); //KIRI ATAS
            glVertex3f(-0.5,-3,-3); //KANAN ATAS
            glVertex3f(-0.5,-10,-3); //KANAN BAWAH
            glEnd();
            //KANAN
            glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.5,-10,-3); //KIRI BAWAH
            glVertex3f(-0.5,-4,-3); //KIRI ATAS
            glVertex3f(-0.5,-4,-3.5); //KANAN ATAS
            glVertex3f(-0.5,-10,-3.5); //KANAN BAWAH
            //KIRI
            glVertex3f(-1,-10,-3); //KIRI BAWAH
            glVertex3f(-1,-4,-3); //KIRI ATAS
            glVertex3f(-1,-4,-3.5); //KANAN ATAS
            glVertex3f(-1,-10,-3.5); //KANAN BAWAH
            glEnd();

    //TAMPAK BELAKANG
            //KIRI
                glBegin(GL_QUADS);
                glColor3f(0.5,0.5,.0);
                glVertex3f(-3,-10,-4.5); //KIRI BAWAH
                glVertex3f(-3,-7,-4.5); //KIRI ATAS
                glVertex3f(-2.5,-7,-4.5); //KANAN ATAS
                glVertex3f(-2.5,-10,-4.5); //KANAN BAWAH
                //DEPAN
                glVertex3f(-3,-10,-5); //KIRI BAWAH
                glVertex3f(-3,-7,-5); //KIRI ATAS
                glVertex3f(-2.5,-7,-5); //KANAN ATAS
                glVertex3f(-2.5,-10,-5); //KANAN BAWAH
                glEnd();
                //KANAN
                glBegin(GL_QUADS);
                glColor3f(1.0,0.0,0.0);
                glVertex3f(-2.5,-10,-5); //KIRI BAWAH
                glVertex3f(-2.5,-7,-5); //KIRI ATAS
                glVertex3f(-2.5,-7,-4.5); //KANAN ATAS
                glVertex3f(-2.5,-10,-4.5); //KANAN BAWAH
                //KIRI
                glVertex3f(-3,-10,-5); //KIRI BAWAH
                glVertex3f(-3,-7,-5); //KIRI ATAS
                glVertex3f(-3,-7,-4.5); //KANAN ATAS
                glVertex3f(-3,-10,-4.5); //KANAN BAWAH
                glEnd();

            //KANAN
                glBegin(GL_QUADS);
                glColor3f(0.5,0.5,.0);
                glVertex3f(-1,-10,-4.5); //KIRI BAWAH
                glVertex3f(-1,-4,-4.5); //KIRI ATAS
                glVertex3f(-0.5,-4,-4.5); //KANAN ATAS
                glVertex3f(-0.5,-10,-4.5); //KANAN BAWAH
                //DEPAN
                glVertex3f(-1,-10,-5); //KIRI BAWAH
                glVertex3f(-1,-3,-5); //KIRI ATAS
                glVertex3f(-0.5,-3,-5); //KANAN ATAS
                glVertex3f(-0.5,-10,-5); //KANAN BAWAH
                glEnd();
                //KANAN
                glBegin(GL_QUADS);
                glColor3f(1.0,0.0,0.0);
                glVertex3f(-0.5,-10,-5); //KIRI BAWAH
                glVertex3f(-0.5,-4,-5); //KIRI ATAS
                glVertex3f(-0.5,-4,-4.5); //KANAN ATAS
                glVertex3f(-0.5,-10,-4.5); //KANAN BAWAH
                //KIRI
                glVertex3f(-1,-10,-5); //KIRI BAWAH
                glVertex3f(-1,-4,-5); //KIRI ATAS
                glVertex3f(-1,-4,-4.5); //KANAN ATAS
                glVertex3f(-1,-10,-4.5); //KANAN BAWAH
                glEnd();
    //ATAS
        //TAMPAK DEPAN
        glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.1);
        glVertex3f(-3,-7.0,-3); //KIRI BAWAH
        glVertex3f(-3,-6.5,-3); //KIRI ATAS
        glVertex3f(-1,-6.5,-3); //KANAN ATAS
        glVertex3f(-1,-7.0,-3); //KANAN BAWAH
        //TAMPAK BELAKANG
        glVertex3f(-3,-7.0,-5); //KIRI BAWAH
        glVertex3f(-3,-6.5,-5); //KIRI ATAS
        glVertex3f(-1,-6.5,-5); //KANAN ATAS
        glVertex3f(-1,-7.0,-5); //KANAN BAWAH
        //TAMPAK KANAN
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-0.5,-7.0,-3.5); //KIRI BAWAH
        glVertex3f(-0.5,-6.5,-3.5); //KIRI ATAS
        glVertex3f(-0.5,-6.5,-4.5); //KANAN ATAS
        glVertex3f(-0.5,-7.0,-4.5); //KANAN BAWAH
        //TAMPAK KIRI
        glVertex3f(-3,-7.0,-3); //KANAN BAWAH
        glVertex3f(-3,-6.5,-3); //KANAN ATAS
        glVertex3f(-3,-6.5,-5); //KIRI ATAS
        glVertex3f(-3,-7.0,-5); //KIRI BAWAH
        //ATAS1
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-3,-6.5,-3); //KIRI BAWAH
        glVertex3f(-3,-6.5,-5); //KIRI ATAS
        glVertex3f(-0.5,-6.5,-5); //KANAN ATAS
        glVertex3f(-0.5,-6.5,-3); //KANAN BAWAH
        //ATAS KANAN
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-0.5,-4,-3); //KIRI BAWAH
        glVertex3f(-0.5,-3,-3); //KIRI ATAS
        glVertex3f(-0.5,-3,-5); //KANAN ATAS
        glVertex3f(-0.5,-4,-5); //KANAN BAWAH
        //ATAS KIRI
        glVertex3f(-1,-4,-3); //KIRI BAWAH
        glVertex3f(-1,-3,-3); //KIRI ATAS
        glVertex3f(-1,-3,-5); //KANAN ATAS
        glVertex3f(-1,-4,-5); //KANAN BAWAH
        //ATAS2
        glVertex3f(-1,-3,-3); //KIRI BAWAH
        glVertex3f(-1,-3,-5); //KIRI ATAS
        glVertex3f(-0.5,-3,-5); //KANAN ATAS
        glVertex3f(-0.5,-3,-3); //KANAN BAWAH
        glEnd();
}

void lobby (void){
    //LOBBY
                //ATAP
                    //ATAS
                    glBegin(GL_QUADS);
                    glColor3ub(186, 115, 69);
                    glVertex3f(-6.0,0.0,26.0); //KIRI BAWAH
                    glVertex3f(-6.0,0.0,15.0); //KIRI ATAS
                    glVertex3f(6.0,0.0,15.0); //KANAN ATAS
                    glVertex3f(6.0,0.0,26.0); //KIRI ATAS
                    //BAWAH
                    glVertex3f(-5.0,-1.0,25.0); //KIRI BAWAH
                    glVertex3f(-5.0,-1.0,15.0); //KIRI ATAS
                    glVertex3f(5.0,-1.0,15.0); //KANAN ATAS
                    glVertex3f(5.0,-1.0,25.0); //KIRI ATAS
                    //SAMBUNGAN ATAS BAWAH
                        //KIRI
                        glColor3ub(194, 111, 30);
                        glVertex3f(-5.0,-1.0,15.0); //KIRI BAWAH
                        glVertex3f(-5.0,-0.5,15.0); //KIRI ATAS
                        glVertex3f(-5.0,-0.5,25.0); //KANAN ATAS
                        glVertex3f(-5.0,-1.0,25.0); //KANAN BAWAH

                        glVertex3f(-5.0,-0.5,26.0); //KANAN BAWAH
                        glVertex3f(-5.0,-0.5,15.0); //KANAN ATAS
                        glVertex3f(-6.0,-0.5,15.0); //KIRI ATAS
                        glVertex3f(-6.0,-0.5,26.0); //KIRI BAWAH

                        glColor3ub(126, 52, 12);
                        glVertex3f(-6.0,0.0,15.0); //KIRI ATAS
                        glVertex3f(-6.0,-0.5,15.0); //KIRI BAWAH
                        glVertex3f(-6.0,-0.5,26.0); //KANAN BAWAH
                        glVertex3f(-6.0,0.0,26.0); //KANAN ATAS
                        //KANAN (KANAN KIRINYA SAMA SEPERTI ATAS)
                        glColor3ub(194, 111, 30);
                        glVertex3f(5.0,-1.0,15.0); //KIRI BAWAH
                        glVertex3f(5.0,-0.5,15.0); //KIRI ATAS
                        glVertex3f(5.0,-0.5,25.0); //KANAN ATAS
                        glVertex3f(5.0,-1.0,25.0); //KANAN BAWAH

                        glVertex3f(5.0,-0.5,26.0); //KANAN BAWAH
                        glVertex3f(5.0,-0.5,15.0); //KANAN ATAS
                        glVertex3f(6.0,-0.5,15.0); //KIRI ATAS
                        glVertex3f(6.0,-0.5,26.0); //KIRI BAWAH

                        glColor3ub(126, 52, 12);
                        glVertex3f(6.0,0.0,15.0); //KIRI ATAS
                        glVertex3f(6.0,-0.5,15.0); //KIRI BAWAH
                        glVertex3f(6.0,-0.5,26.0); //KANAN BAWAH
                        glVertex3f(6.0,0.0,26.0); //KANAN ATAS
                        //DEPAN
                        glColor3ub(194, 111, 30);
                        glVertex3f(-5.0,-1.0,25.0); //KIRI BAWAH
                        glVertex3f(-5.0,-0.5,25.0); //KIRI ATAS
                        glVertex3f(5.0,-0.5,25.0); //KANAN ATAS
                        glVertex3f(5.0,-1.0,25.0); //KANAN BAWAH

                        glColor3ub(194, 111, 30);
                        glVertex3f(-5.0,-0.5,25.0); //KIRI ATAS
                        glVertex3f(5.0,-0.5,25.0); //KANAN ATAS
                        glVertex3f(6.0,-0.5,26.0); //KANAN BAWAH
                        glVertex3f(-6.0,-0.5,26.0); //KIRI BAWAH

                        glColor3ub(126, 52, 12);
                        glVertex3f(-6.0,-0.5,26.0); //KIRI BAWAH
                        glVertex3f(-6.0,0.0,26.0); //KIRI ATAS
                        glVertex3f(6.0,0.0,26.0); //KANAN ATAS
                        glVertex3f(6.0,-0.5,26.0); //KANAN BAWAH
            //TIANG
                   //KIRI
                        //TAMPAK KIRI
                        glColor3ub(208, 163, 97);
                        glVertex3f(-5.0,-10.0,15.0); //KIRI BAWAH
                        glVertex3f(-5.0,-1.0,15.0); //KIRI ATAS
                        glVertex3f(-5.0,-1.0,17.0); //KANAN ATAS
                        glVertex3f(-5.0,-10.0,17.0); //KANAN BAWAH
                        //TAMPAK DEPAN
                        glVertex3f(-5.0,-10.0,17.0); //KIRI BAWAH
                        glVertex3f(-5.0,-1.0,17.0); //KIRI ATAS
                        glVertex3f(-4.0,-1.0,17.0); //KANAN ATAS
                        glVertex3f(-4.0,-10.0,17.0); //KANAN BAWAH
                        //TAMPAK KANAN
                        glColor3ub(208, 163, 97);
                        glVertex3f(-4.0,-10.0,15.0); //KANAN BAWAH
                        glVertex3f(-4.0,-1.0,15.0); //KANAN ATAS
                        glVertex3f(-4.0,-1.0,17.0); //KIRI ATAS
                        glVertex3f(-4.0,-10.0,17.0); //KIRI BAWAH
                        //SAMBUNGAN
                            //KIRI
                            glColor3ub(208, 163, 97);
                            glVertex3f(-5.0,-2.0,17.0); //KIRI BAWAH
                            glVertex3f(-5.0,-1.0,17.0); //KIRI ATAS
                            glVertex3f(-5.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(-5.0,-2.0,23.0); //KANAN BAWAH
                            //KANAN
                            glVertex3f(-4.0,-2.0,17.0); //KIRI BAWAH
                            glVertex3f(-4.0,-1.0,17.0); //KIRI ATAS
                            glVertex3f(-4.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(-4.0,-2.0,23.0); //KANAN BAWAH
                            //BAWAH
                            glColor3ub(208, 163, 97);
                            glVertex3f(-5.0,-2.0,17.0); //KIRI ATAS
                            glVertex3f(-5.0,-2.0,23.0); //KIRI BAWAH
                            glVertex3f(-4.0,-2.0,23.0); //KANAN BAWAH
                            glVertex3f(-4.0,-2.0,17.0); //KANAN BAWAH

                    //KANAN
                        //TAMPAK KIRI
                        glColor3ub(208, 163, 97);
                        glVertex3f(5.0,-10.0,15.0); //KIRI BAWAH
                        glVertex3f(5.0,-1.0,15.0); //KIRI ATAS
                        glVertex3f(5.0,-1.0,17.0); //KANAN ATAS
                        glVertex3f(5.0,-10.0,17.0); //KANAN BAWAH
                        //TAMPAK DEPAN
                        glVertex3f(5.0,-10.0,17.0); //KIRI BAWAH
                        glVertex3f(5.0,-1.0,17.0); //KIRI ATAS
                        glVertex3f(4.0,-1.0,17.0); //KANAN ATAS
                        glVertex3f(4.0,-10.0,17.0); //KANAN BAWAH
                        //TAMPAK KANAN
                        glColor3ub(208, 163, 97);
                        glVertex3f(4.0,-10.0,15.0); //KANAN BAWAH
                        glVertex3f(4.0,-1.0,15.0); //KANAN ATAS
                        glVertex3f(4.0,-1.0,17.0); //KIRI ATAS
                        glVertex3f(4.0,-10.0,17.0); //KIRI BAWAH
                        //SAMBUNGAN
                            //KIRI
                            glColor3ub(208, 163, 97);
                            glVertex3f(5.0,-2.0,17.0); //KIRI BAWAH
                            glVertex3f(5.0,-1.0,17.0); //KIRI ATAS
                            glVertex3f(5.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(5.0,-2.0,23.0); //KANAN BAWAH
                            //KANAN
                            glVertex3f(4.0,-2.0,17.0); //KIRI BAWAH
                            glVertex3f(4.0,-1.0,17.0); //KIRI ATAS
                            glVertex3f(4.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(4.0,-2.0,23.0); //KANAN BAWAH
                            //BAWAH
                            glColor3ub(208, 163, 97);
                            glVertex3f(5.0,-2.0,17.0); //KIRI ATAS
                            glVertex3f(5.0,-2.0,23.0); //KIRI BAWAH
                            glVertex3f(4.0,-2.0,23.0); //KANAN BAWAH
                            glVertex3f(4.0,-2.0,17.0); //KANAN BAWAH

                    //DEPAN
                        //TIANG 1 DARI KIRI
                            //TAMPAK KIRI
                            glColor3ub(208, 163, 97);
                            glVertex3f(-5.0,-10.0,23.0); //KIRI BAWAH
                            glVertex3f(-5.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(-5.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(-5.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK KANAN
                            glVertex3f(-4.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(-4.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(-4.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(-4.0,-10.0,25.0); //KIRI BAWAH
                            //TAMPAK DEPAN
                            glColor3ub(208, 163, 97);
                            glVertex3f(-5.0,-10.0,25.0); //KIRI BAWAH
                            glVertex3f(-5.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(-4.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(-4.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK BELAKANG
                            glColor3ub(208, 163, 97);
                            glVertex3f(-5.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(-5.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(-4.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(-4.0,-10.0,23.0); //KIRI BAWAH
                            //SAMBUNGAN
                                //DEPAN
                                glColor3ub(208, 163, 97);
                                glVertex3f(-4.0,-2.0,25); //KIRI BAWAH
                                glVertex3f(-4.0,-1.0,25); //KIRI ATAS
                                glVertex3f(-2.0,-1.0,25); //KANAN ATAS
                                glVertex3f(-2.0,-2.0,25); //KANAN BAWAH
                                //BELAKANG
                                glVertex3f(-4.0,-2.0,23); //KIRI BAWAH
                                glVertex3f(-4.0,-1.0,23); //KIRI ATAS
                                glVertex3f(-2.0,-1.0,23); //KANAN ATAS
                                glVertex3f(-2.0,-2.0,23); //KANAN BAWAH
                                //BAWAH
                                glColor3ub(208, 163, 97);
                                glVertex3f(-4.0,-2.0,25); //KIRI ATAS
                                glVertex3f(-2.0,-2.0,25); //KANAN ATAS
                                glVertex3f(-2.0,-2.0,23); //KANAN BAWAH
                                glVertex3f(-4.0,-2.0,23); //KIRI BAWAH

                        //TIANG 2
                            //TAMPAK KIRI
                            glColor3ub(208, 163, 97);
                            glVertex3f(-2.0,-10.0,23.0); //KIRI BAWAH
                            glVertex3f(-2.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(-2.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(-2.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK KANAN
                            glVertex3f(-1.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(-1.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(-1.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(-1.0,-10.0,25.0); //KIRI BAWAH
                            //TAMPAK DEPAN
                            glColor3ub(208, 163, 97);
                            glVertex3f(-2.0,-10.0,25.0); //KIRI BAWAH
                            glVertex3f(-2.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(-1.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(-1.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK BELAKANG
                            glColor3ub(208, 163, 97);
                            glVertex3f(-2.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(-2.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(-1.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(-1.0,-10.0,23.0); //KIRI BAWAH
                            //SAMBUNGAN
                                //DEPAN
                                glColor3ub(208, 163, 97);
                                glVertex3f(-1.0,-2.0,25); //KIRI BAWAH
                                glVertex3f(-1.0,-1.0,25); //KIRI ATAS
                                glVertex3f(1.0,-1.0,25); //KANAN ATAS
                                glVertex3f(1.0,-2.0,25); //KANAN BAWAH
                                //BELAKANG
                                glVertex3f(-1.0,-2.0,23); //KIRI BAWAH
                                glVertex3f(-1.0,-1.0,23); //KIRI ATAS
                                glVertex3f(1.0,-1.0,23); //KANAN ATAS
                                glVertex3f(1.0,-2.0,23); //KANAN BAWAH
                                //BAWAH
                                glColor3ub(208, 163, 97);
                                glVertex3f(-1.0,-2.0,25); //KIRI ATAS
                                glVertex3f(1.0,-2.0,25); //KANAN ATAS
                                glVertex3f(1.0,-2.0,23); //KANAN BAWAH
                                glVertex3f(-1.0,-2.0,23); //KIRI BAWAH

                        //TIANG 3
                            //TAMPAK KIRI
                            glColor3ub(208, 163, 97);
                            glVertex3f(2.0,-10.0,23.0); //KIRI BAWAH
                            glVertex3f(2.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(2.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(2.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK KANAN
                            glVertex3f(1.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(1.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(1.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(1.0,-10.0,25.0); //KIRI BAWAH
                            //TAMPAK DEPAN
                            glColor3ub(208, 163, 97);
                            glVertex3f(2.0,-10.0,25.0); //KIRI BAWAH
                            glVertex3f(2.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(1.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(1.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK BELAKANG
                            glColor3ub(208, 163, 97);
                            glVertex3f(2.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(2.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(1.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(1.0,-10.0,23.0); //KIRI BAWAH
                            //SAMBUNGAN
                                //DEPAN
                                glColor3ub(208, 163, 97);
                                glVertex3f(4.0,-2.0,25); //KIRI BAWAH
                                glVertex3f(4.0,-1.0,25); //KIRI ATAS
                                glVertex3f(2.0,-1.0,25); //KANAN ATAS
                                glVertex3f(2.0,-2.0,25); //KANAN BAWAH
                                //BELAKANG
                                glVertex3f(4.0,-2.0,23); //KIRI BAWAH
                                glVertex3f(4.0,-1.0,23); //KIRI ATAS
                                glVertex3f(2.0,-1.0,23); //KANAN ATAS
                                glVertex3f(2.0,-2.0,23); //KANAN BAWAH
                                //BAWAH
                                glColor3ub(208, 163, 97);
                                glVertex3f(4.0,-2.0,25); //KIRI ATAS
                                glVertex3f(2.0,-2.0,25); //KANAN ATAS
                                glVertex3f(2.0,-2.0,23); //KANAN BAWAH
                                glVertex3f(4.0,-2.0,23); //KIRI BAWAH

                        //TIANG 4
                            //TAMPAK KIRI
                            glColor3ub(208, 163, 97);
                            glVertex3f(5.0,-10.0,23.0); //KIRI BAWAH
                            glVertex3f(5.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(5.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(5.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK KANAN
                            glVertex3f(4.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(4.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(4.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(4.0,-10.0,25.0); //KIRI BAWAH
                            //TAMPAK DEPAN
                            glColor3ub(208, 163, 97);
                            glVertex3f(5.0,-10.0,25.0); //KIRI BAWAH
                            glVertex3f(5.0,-1.0,25.0); //KIRI ATAS
                            glVertex3f(4.0,-1.0,25.0); //KANAN ATAS
                            glVertex3f(4.0,-10.0,25.0); //KANAN BAWAH
                            //TAMPAK BELAKANG
                            glColor3ub(208, 163, 97);
                            glVertex3f(5.0,-10.0,23.0); //KANAN BAWAH
                            glVertex3f(5.0,-1.0,23.0); //KANAN ATAS
                            glVertex3f(4.0,-1.0,23.0); //KIRI ATAS
                            glVertex3f(4.0,-10.0,23.0); //KIRI BAWAH
                            glEnd();
           //LANTAI
                //LOBBY
                glBegin(GL_QUADS);
                glColor3ub(251, 208, 159);
                glVertex3f(-5.0,-10.0,25.0); //KIRI BAWAH
                glVertex3f(-5.0,-10.0,15.0); //KIRI ATAS
                glVertex3f(5.0,-10.0,15.0); //KANAN ATAS
                glVertex3f(5.0,-10.0,25.0); //KIRI ATAS
                glEnd();
}

void papantulis (void){
    //TEMBOK LIHAT DARI KANAN
    glBegin(GL_QUADS);
    glColor3f(0.5,0.0,0.0);
    glVertex3f(-20.0,-10.0,-10.0); //KANAN BAWAH
    glVertex3f(-20.0,10.0,-10.0); //KANAN ATAS
    glVertex3f(-20.0,10.0,5.0); //KIRI ATAS
    glVertex3f(-20.0,-10.0,5.0); //KIRI BAWAH
    //PAPAN TULIS
        //HADAP KURSI
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-19.5,-2.0,-8.0); //KANAN BAWAH
        glVertex3f(-19.5,5.0,-8.0); //KANAN ATAS
        glVertex3f(-19.5,5.0,3.0); //KIRI ATAS
        glVertex3f(-19.5,-2.0,3.0); //KIRI BAWAH
        //KIRI
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,-2.0,3.0); //KANAN BAWAH
        glVertex3f(-19.5,5.0,3.0); //KANAN ATAS
        glVertex3f(-20.0,5.0,3.0); //KIRI ATAS
        glVertex3f(-20.0,-2.0,3.0); //KIRI BAWAH
        //KANAN
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,-2.0,-8.0); //KANAN BAWAH
        glVertex3f(-19.5,5.0,-8.0); //KANAN ATAS
        glVertex3f(-20.0,5.0,-8.0); //KIRI ATAS
        glVertex3f(-20.0,-2.0,-8.0); //KIRI BAWAH
        //ATAS
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,5.0,3.0); //KIRI BAWAH
        glVertex3f(-20.0,5.0,3.0); //KIRI ATAS
        glVertex3f(-20.0,5.0,-8.0); //KANAN ATAS
        glVertex3f(-19.5,5.0,-8.0); //KANAN BAWAH
        //BAWAH
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,-2.0,3.0); //KIRI BAWAH
        glVertex3f(-20.0,-2.0,3.0); //KIRI ATAS
        glVertex3f(-20.0,-2.0,-8.0); //KANAN ATAS
        glVertex3f(-19.5,-2.0,-8.0); //KANAN BAWAH
    glEnd();
    //TULISAN
        //HURUF P
        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,2.0,2.5); //BAWAH KIRI
        glVertex3f(-19.5,4.0,2.5); //ATAS KIRI
        glVertex3f(-19.5,4.0,1.0); //ATAS KANAN
        glVertex3f(-19.5,3.0,1.0); // KANAN BAWAH
        glVertex3f(-19.5,3.0,2.5); // KIRI TENGAH
        glEnd();
        //HURUF A
        glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        glVertex3f(-19.5,2.0,0.5); //KIRI
        glVertex3f(-19.5,4.0,-0.25); //PUNCAK
        glVertex3f(-19.5,2.0,-1.0); //KANAN
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,3.0,0.5); //KIRI
        glVertex3f(-19.5,3.0,-1.0); //KANAN
        glEnd();
        //HURUF P
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,2.0,-1.5); //BAWAH KIRI
        glVertex3f(-19.5,4.0,-1.5); //ATAS KIRI
        glVertex3f(-19.5,4.0,-3.0); //ATAS KANAN
        glVertex3f(-19.5,3.0,-3.0); // KANAN BAWAH
        glVertex3f(-19.5,3.0,-1.5); // KIRI TENGAH
        glEnd();
        //HURUF A
        glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        glVertex3f(-19.5,2.0,-3.5); //KIRI
        glVertex3f(-19.5,4.0,-4.25); //PUNCAK
        glVertex3f(-19.5,2.0,-5.0); //KANAN
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-19.5,3.0,-3.5); //KIRI
        glVertex3f(-19.5,3.0,-5.0); //KANAN
        glEnd();
        //HURUF N
        glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        glVertex3f(-19.5,2.0,-5.5); //KIRI BAWAH
        glVertex3f(-19.5,4.0,-5.5); // KIRI ATAS
        glVertex3f(-19.5,2.0,-7.5); //KANAN BAWAH
        glVertex3f(-19.5,4.0,-7.5); //KANAN ATAS
        glEnd();
        //HURUF T
        glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-19.5,-1.25,1.75); //BAWAH
        glVertex3f(-19.5,1.20,1.75); //ATAS
        glVertex3f(-19.5,1.20,2.5); //KIRI
        glVertex3f(-19.5,1.20,1.0); //KANAN
        glEnd();
        //HURUF U
        glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        glVertex3f(-19.5,1.20,0.0); //ATAS KIRI
        glVertex3f(-19.5,-1.25,0.0); //BAWAH KIRI
        glVertex3f(-19.5,-1.25,-1.5); //BAWAH KANAN
        glVertex3f(-19.5,1.20,-1.5); //ATAS KANAN
        glEnd();
        //HURUF L
        glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        glVertex3f(-19.5,1.20,-2.5); //ATAS KIRI
        glVertex3f(-19.5,-1.25,-2.5); //BAWAH KIRI
        glVertex3f(-19.5,-1.25,-4.0); //BAWAH KANAN
        glEnd();
        //HURUF I
        glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        glVertex3f(-19.5,1.20,-4.5); //ATAS
        glVertex3f(-19.5,-1.25,-4.5); //BAWAH
        glEnd();
        //HURUF S
        glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        glVertex3f(-19.5,1.0,-7.0); //KANAN ATAS
        glVertex3f(-19.5,1.0,-5.5); //KIRI ATAS
        glVertex3f(-19.5,0.0,-5.5); //KIRI TENGAH
        glVertex3f(-19.5,0.0,-7.0); //KANAN TENGAH
        glVertex3f(-19.5,-1.0,-7.0); //KANAN BAWAH
        glVertex3f(-19.5,-1.0,-5.5); //KIRI BAWAH
        glEnd();
}

void nankaiuniversity(void){
//LANTAI DASAR
    // DEPAN
    lobby();
        //KIRI
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(-20.0,-10.0,10.0); // KIRI BAWAH
        glVertex3f(-20.0,10.0,10.0); // KIRI ATAS
        glVertex3f(-5.0,10.0,10.0); // KANAN ATAS
        glVertex3f(-5.0,-10.0,10.0); // KANAN BAWAH

            //Jendela Tengah

                //Jendela Lt 6
                float cEnam=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-19.5+cEnam,7.5,10.5); // KIRI BAWAH
                            glVertex3f(-19.5+cEnam,9.0,10.5); // KIRI ATAS
                            glVertex3f(-18+cEnam,9.0,10.5); // KANAN ATAS
                            glVertex3f(-18+cEnam,7.5,10.5); // KANAN BAWAH
                            cEnam+=2.5;
                    }

                //Jendela Lt 5
                float cLima=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-19.5+cLima,5,10.5); // KIRI BAWAH
                            glVertex3f(-19.5+cLima,6.5,10.5); // KIRI ATAS
                            glVertex3f(-18+cLima,6.5,10.5); // KANAN ATAS
                            glVertex3f(-18+cLima,5,10.5); // KANAN BAWAH
                            cLima+=2.5;
                    }

                //Jendela Lt 4
                float cEmpat=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-19.5+cEmpat,2.5,10.5); // KIRI BAWAH
                            glVertex3f(-19.5+cEmpat,4.0,10.5); // KIRI ATAS
                            glVertex3f(-18+cEmpat,4.0,10.5); // KANAN ATAS
                            glVertex3f(-18+cEmpat,2.5,10.5); // KANAN BAWAH
                            cEmpat+=2.5;
                    }

                //Jendela Lt 3
                float cTiga=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-19.5+cTiga,0,10.5); // KIRI BAWAH
                            glVertex3f(-19.5+cTiga,1.5,10.5); // KIRI ATAS
                            glVertex3f(-18+cTiga,1.5,10.5); // KANAN ATAS
                            glVertex3f(-18+cTiga,0,10.5); // KANAN BAWAH
                            cTiga+=2.5;
                    }

                //Jendela Lt 2
                float cDua=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-19.5+cDua,-1.0,10.5); // KIRI BAWAH
                            glVertex3f(-19.5+cDua,-2.5,10.5); // KIRI ATAS
                            glVertex3f(-18+cDua,-2.5,10.5); // KANAN ATAS
                            glVertex3f(-18+cDua,-1.0,10.5); // KANAN BAWAH
                            cDua+=2.5;
                    }

                //Jendela Lt 1
                float cSatu=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-19.5+cSatu,-3.5,10.5); // KIRI BAWAH
                            glVertex3f(-19.5+cSatu,-5,10.5); // KIRI ATAS
                            glVertex3f(-18+cSatu,-5,10.5); // KANAN ATAS
                            glVertex3f(-18+cSatu,-3.5,10.5); // KANAN BAWAH
                            cSatu+=2.5;
                    }

                //Jendela Lt 0
                float cEnol=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-19.5+cEnol,-6,10.5); // KIRI BAWAH
                            glVertex3f(-19.5+cEnol,-7.5,10.5); // KIRI ATAS
                            glVertex3f(-18+cEnol,-7.5,10.5); // KANAN ATAS
                            glVertex3f(-18+cEnol,-6,10.5); // KANAN BAWAH
                            cEnol+=2.5;
                    }

        //TENGAH
        glColor3ub(219, 172, 129);
        glVertex3f(-5.0,0.0,15.0); // KIRI BAWAH
        glVertex3f(-5.0,10.0,15.0); // KIRI ATAS
        glVertex3f(5.0,10.0,15.0); // KANAN ATAS
        glVertex3f(5.0,0.0,15.0); // KANAN BAWAH
            //JENDELA TENGAH
                //Jendela lt 4
                    int jEmpat=0;
                    for(i=0;i<=4;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-4.5+jEmpat,8,15.5); // KIRI BAWAH
                            glVertex3f(-4.5+jEmpat,9.0,15.5); // KIRI ATAS
                            glVertex3f(-3.5+jEmpat,9.0,15.5); // KANAN ATAS
                            glVertex3f(-3.5+jEmpat,8.0,15.5); // KANAN BAWAH
                            jEmpat+=2;
                    }

                //Jendela lt 3
                    int jTiga=0;
                    for(i=0;i<=4;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-4.5+jTiga,6,15.5); // KIRI BAWAH
                            glVertex3f(-4.5+jTiga,7.0,15.5); // KIRI ATAS
                            glVertex3f(-3.5+jTiga,7.0,15.5); // KANAN ATAS
                            glVertex3f(-3.5+jTiga,6.0,15.5); // KANAN BAWAH
                            jTiga+=2;
                    }

                //Jendela lt 2
                    int jDua=0;
                    for(i=0;i<=4;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-4.5+jDua,4,15.5); // KIRI BAWAH
                            glVertex3f(-4.5+jDua,5.0,15.5); // KIRI ATAS
                            glVertex3f(-3.5+jDua,5.0,15.5); // KANAN ATAS
                            glVertex3f(-3.5+jDua,4.0,15.5); // KANAN BAWAH
                            jDua+=2;
                    }


                //Jendela lt 1
                    int jSatu=0;
                    for(i=0;i<=4;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-4.5+jSatu,2,15.5); // KIRI BAWAH
                            glVertex3f(-4.5+jSatu,3.0,15.5); // KIRI ATAS
                            glVertex3f(-3.5+jSatu,3.0,15.5); // KANAN ATAS
                            glVertex3f(-3.5+jSatu,2.0,15.5); // KANAN BAWAH
                            jSatu+=2;
                    }

            //SAMPING KANAN
            glColor3ub(219, 172, 129);
            glVertex3f(5.0,10.0,15.0); // KIRI ATAS
            glVertex3f(5.0,-10.0,15.0); // KIRI BAWAH
            glVertex3f(5.0,-10.0,10.0); // KANAN BAWAH
            glVertex3f(5.0,10.0,10.0); // KANAN ATAS

            //SAMPING KIRI
            glColor3ub(219, 172, 129);
            glVertex3f(-5.0,10.0,15.0); // KANAN ATAS
            glVertex3f(-5.0,-10.0,15.0); // KANAN BAWAH
            glVertex3f(-5.0,-10.0,10.0); // KIRI BAWAH
            glVertex3f(-5.0,10.0,10.0); // KIRI ATAS

        //KANAN
        glColor3ub(219, 172, 129);
        glVertex3f(5.0,-10.0,10.0); // KIRI BAWAH
        glVertex3f(5.0,10.0,10.0); // KIRI ATAS
        glVertex3f(20.0,10.0,10.0); // KANAN ATAS
        glVertex3f(20.0,-10.0,10.0); // KANAN BAWAH

             //Jendela Tengah

                //Jendela Lt 6
                float dEnam=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(5.5+dEnam,7.5,10.5); // KIRI BAWAH
                            glVertex3f(5.5+dEnam,9.0,10.5); // KIRI ATAS
                            glVertex3f(7+dEnam,9.0,10.5); // KANAN ATAS
                            glVertex3f(7+dEnam,7.5,10.5); // KANAN BAWAH
                            dEnam+=2.5;
                    }

                //Jendela Lt 5
                float dLima=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(5.5+dLima,5,10.5); // KIRI BAWAH
                            glVertex3f(5.5+dLima,6.5,10.5); // KIRI ATAS
                            glVertex3f(7+dLima,6.5,10.5); // KANAN ATAS
                            glVertex3f(7+dLima,5,10.5); // KANAN BAWAH
                            dLima+=2.5;
                    }

                //Jendela Lt 4
                float dEmpat=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(5.5+dEmpat,2.5,10.5); // KIRI BAWAH
                            glVertex3f(5.5+dEmpat,4.0,10.5); // KIRI ATAS
                            glVertex3f(7+dEmpat,4.0,10.5); // KANAN ATAS
                            glVertex3f(7+dEmpat,2.5,10.5); // KANAN BAWAH
                            dEmpat+=2.5;
                    }

                //Jendela Lt 3
                float dTiga=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(5.5+dTiga,0,10.5); // KIRI BAWAH
                            glVertex3f(5.5+dTiga,1.5,10.5); // KIRI ATAS
                            glVertex3f(7+dTiga,1.5,10.5); // KANAN ATAS
                            glVertex3f(7+dTiga,0,10.5); // KANAN BAWAH
                            dTiga+=2.5;
                    }

                //Jendela Lt 2
                float dDua=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(5.5+dDua,-1.0,10.5); // KIRI BAWAH
                            glVertex3f(5.5+dDua,-2.5,10.5); // KIRI ATAS
                            glVertex3f(7+dDua,-2.5,10.5); // KANAN ATAS
                            glVertex3f(7+dDua,-1.0,10.5); // KANAN BAWAH
                            dDua+=2.5;
                    }

                //Jendela Lt 1
                float dSatu=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(5.5+dSatu,-3.5,10.5); // KIRI BAWAH
                            glVertex3f(5.5+dSatu,-5,10.5); // KIRI ATAS
                            glVertex3f(7+dSatu,-5,10.5); // KANAN ATAS
                            glVertex3f(7+dSatu,-3.5,10.5); // KANAN BAWAH
                            dSatu+=2.5;
                    }

                //Jendela Lt 0
                float dEnol=0;
                    for(i=0;i<6;i++){
                            glColor3f(1,1,1);
                            glVertex3f(5.5+dEnol,-6,10.5); // KIRI BAWAH
                            glVertex3f(5.5+dEnol,-7.5,10.5); // KIRI ATAS
                            glVertex3f(7+dEnol,-7.5,10.5); // KANAN ATAS
                            glVertex3f(7+dEnol,-6,10.5); // KANAN BAWAH
                            dEnol+=2.5;
                    }


        glEnd();
    //BANGUNAN ATAS
        //KIRI
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(-20.0,8.0,5.0); //KANAN BAWAH
        glVertex3f(-20.0,10.0,5.0); //KANAN ATAS
        glVertex3f(-20.0,10.0,-10.0); //KIRI ATAS
        glVertex3f(-20.0,8.0,-10.0); //KIRI BAWAH
        //KANAN
        glVertex3f(20.0,8.0,5.0); //KIRI BAWAH
        glVertex3f(20.0,10.0,5.0); //KIRI ATAS
        glVertex3f(20.0,10.0,-10.0); //KANAN ATAS
        glVertex3f(20.0,8.0,-10.0); //KANAN BAWAH
        glEnd();
    //BELAKANG
        //TENGAH
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(-20.0,-10.0,-10.0); //KANAN BAWAH
        glVertex3f(-20.0,10.0,-10.0); //KANAN ATAS
        glVertex3f(20.0,10.0,-10.0); // KIRI ATAS
        glVertex3f(20.0,-10.0,-10.0); // KIRI BAWAH
        //KIRI
        glColor3ub(219, 172, 129);
        glVertex3f(-20.0,-10.0,-10.0); //KANAN BAWAH
        glVertex3f(-20.0,8.0,-10.0); //KANAN ATAS
        glVertex3f(-50.0,8.0,-10.0); //KIRI ATAS
        glVertex3f(-50.0,-10.0,-10.0); //KIRI BAWAH
        //KANAN
        glColor3ub(219, 172, 129);
        glVertex3f(20.0,-10.0,-10.0); //KIRI BAWAH
        glVertex3f(20.0,8.0,-10.0); //KIRI ATAS
        glVertex3f(50.0,8.0,-10.0); //KANAN ATAS
        glVertex3f(50.0,-10.0,-10.0); //KANAN BAWAH
        glEnd();

    //BANGUNAN KIRI
    //SATU
        //TAMPAK KIRI
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(-20.0,-10.0,10.0); //KANAN BAWAH
        glVertex3f(-20.0,10.0,10.0); //KANAN ATAS
        glVertex3f(-20.0,10.0,5.0); //KIRI ATAS
        glVertex3f(-20.0,-10.0,5.0); //KIRI BAWAH
        //TAMPAK DEPAN
        glColor3ub(219, 172, 129);
        glVertex3f(-20.0,-10.0,5.0); //KANAN BAWAH
        glVertex3f(-20.0,8.0,5.0); //KANAN ATAS
        glVertex3f(-40.0,8.0,5.0); //KIRI ATAS
        glVertex3f(-40.0,-10.0,5.0); //KIRI BAWAH

            //Jendela Kanan

                //Jendela lt 5

                float gLima=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-39+gLima,5,5.5); // KIRI BAWAH
                            glVertex3f(-39+gLima,7.0,5.5); // KIRI ATAS
                            glVertex3f(-38+gLima,7.0,5.5); // KANAN ATAS
                            glVertex3f(-38+gLima,5,5.5); // KANAN BAWAH
                            gLima+=1.7;
                    }

                //Jendela lt 4

                float gEmpat=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-39+gEmpat,2.5,5.5); // KIRI BAWAH
                            glVertex3f(-39+gEmpat,4.5,5); // KIRI ATAS
                            glVertex3f(-38+gEmpat,4.5,5.5); // KANAN ATAS
                            glVertex3f(-38+gEmpat,2.5,5.5); // KANAN BAWAH
                            gEmpat+=1.7;
                    }

                //Jendela lt 3

                float gTiga=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-39+gTiga,-0.5,5.5); // KIRI BAWAH
                            glVertex3f(-39+gTiga,2,5.5); // KIRI ATAS
                            glVertex3f(-38+gTiga,2,5.5); // KANAN ATAS
                            glVertex3f(-38+gTiga,-0.5,5.5); // KANAN BAWAH
                            gTiga+=1.7;
                    }

                //Jendela lt 2

                float gDua=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-39+gDua,-3,5.5); // KIRI BAWAH
                            glVertex3f(-39+gDua,-1,5.5); // KIRI ATAS
                            glVertex3f(-38+gDua,-1,5.5); // KANAN ATAS
                            glVertex3f(-38+gDua,-3,5.5); // KANAN BAWAH
                            gDua+=1.7;
                    }

                //Jendela lt 1

                float gSatu=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-39+gSatu,-5.5,5.5); // KIRI BAWAH
                            glVertex3f(-39+gSatu,-3.5,5.5); // KIRI ATAS
                            glVertex3f(-38+gSatu,-3.5,5.5); // KANAN ATAS
                            glVertex3f(-38+gSatu,-5.5,5.5); // KANAN BAWAH
                            gSatu+=1.7;
                    }

                //Jendela lt 0

                float fEnol=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(21+fEnol,-8,5.5); // KIRI BAWAH
                            glVertex3f(21+fEnol,-6,5.5); // KIRI ATAS
                            glVertex3f(22+fEnol,-6,5.5); // KANAN ATAS
                            glVertex3f(22+fEnol,-8,5.5); // KANAN BAWAH
                            fEnol+=1.7;
                    }



        //DINDING KIRI
        glColor3ub(219, 172, 129);
        glVertex3f(-50.0,-10.0,-10.0); //KIRI BAWAH
        glVertex3f(-50.0,8.0,-10.0); //KIRI ATAS
        glVertex3f(-50.0,8.0,10.0); //KANAN ATAS
        glVertex3f(-50.0,-10.0,10.0); //KANAN BAWAH
        glEnd();
    //DUA
        //HADAP KANAN
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(-40.0,-10.0,5.0); //KANAN BAWAH
        glVertex3f(-40.0,8.0,5.0); //KANAN ATAS
        glVertex3f(-40.0,8.0,10.0); //KIRI ATAS
        glVertex3f(-40.0,-10.0,10.0); //KIRI BAWAH
        //HADAP DEPAN
        glColor3ub(219, 172, 129);
        glVertex3f(-40.0,-10.0,10.0); //KANAN BAWAH
        glVertex3f(-40.0,8.0,10.0); //KANAN ATAS
        glVertex3f(-50.0,8.0,10.0); //KIRI ATAS
        glVertex3f(-50.0,-10.0,10.0); //KIRI BAWAH

            //Jendela DUA DEPAN

                //Jendela Lt 6
                int hEnam=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-49.5+hEnam,5,10.5); // KIRI BAWAH
                            glVertex3f(-49.5+hEnam,7.0,10.5); // KIRI ATAS
                            glVertex3f(-48.5+hEnam,7.0,10.5); // KANAN ATAS
                            glVertex3f(-48.5+hEnam,5,10.5); // KANAN BAWAH
                            hEnam+=2;
                    }

                //Jendela Lt 5
                int hLima=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-49.5+hLima,2.5,10.5); // KIRI BAWAH
                            glVertex3f(-49.5+hLima,4.5,10.5); // KIRI ATAS
                            glVertex3f(-48.5+hLima,4.5,10.5); // KANAN ATAS
                            glVertex3f(-48.5+hLima,2.5,10.5); // KANAN BAWAH
                            hLima+=2;
                    }

                //Jendela Lt 4
                int hEmpat=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-49.5+hEmpat,-0.5,10.5); // KIRI BAWAH
                            glVertex3f(-49.5+hEmpat,2,10.5); // KIRI ATAS
                            glVertex3f(-48.5+hEmpat,2,10.5); // KANAN ATAS
                            glVertex3f(-48.5+hEmpat,-0.5,10.5); // KANAN BAWAH
                            hEmpat+=2;
                    }

                //Jendela Lt 3
                int hTiga=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-49.5+hTiga,-3,10.5); // KIRI BAWAH
                            glVertex3f(-49.5+hTiga,-1,10.5); // KIRI ATAS
                            glVertex3f(-48.5+hTiga,-1,10.5); // KANAN ATAS
                            glVertex3f(-48.5+hTiga,-3,10.5); // KANAN BAWAH
                            hTiga+=2;
                    }

                //Jendela Lt 2
                int hDua=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-49.5+hDua,-5.5,10.5); // KIRI BAWAH
                            glVertex3f(-49.5+hDua,-3.5,10.5); // KIRI ATAS
                            glVertex3f(-48.5+hDua,-3.5,10.5); // KANAN ATAS
                            glVertex3f(-48.5+hDua,-5.5,10.5); // KANAN BAWAH
                            hDua+=2;
                    }

                 //Jendela Lt 1
                int hSatu=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-49.5+hSatu,-8,10.5); // KIRI BAWAH
                            glVertex3f(-49.5+hSatu,-6,10.5); // KIRI ATAS
                            glVertex3f(-48.5+hSatu,-6,10.5); // KANAN ATAS
                            glVertex3f(-48.5+hSatu,-8,10.5); // KANAN BAWAH
                            hSatu+=2;
                    }
        glEnd();


    //BANGUNAN KANAN
    //SATU
        //TAMPAK DARI KANAN
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(20.0,-10.0,10.0); //KIRI BAWAH
        glVertex3f(20.0,10.0,10.0); //KIRI ATAS
        glVertex3f(20.0,10.0,5.0); //KANAN ATAS
        glVertex3f(20.0,-10.0,5.0); //KANAN BAWAH
        //TAMPAK DEPAN
        glColor3ub(219, 172, 129);
        glVertex3f(20.0,-10.0,5.0); //KIRI BAWAH
        glVertex3f(20.0,8.0,5.0); //KIRI ATAS
        glVertex3f(40.0,8.0,5.0); //KANAN ATAS
        glVertex3f(40.0,-10.0,5.0); //KANAN BAWAH

            //Jendela Kanan

                //Jendela lt 5

                float fLima=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(21+fLima,5,5.5); // KIRI BAWAH
                            glVertex3f(21+fLima,7.0,5.5); // KIRI ATAS
                            glVertex3f(22+fLima,7.0,5.5); // KANAN ATAS
                            glVertex3f(22+fLima,5,5.5); // KANAN BAWAH
                            fLima+=1.7;
                    }

                //Jendela lt 4

                float fEmpat=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(21+fEmpat,2.5,5.5); // KIRI BAWAH
                            glVertex3f(21+fEmpat,4.5,5); // KIRI ATAS
                            glVertex3f(22+fEmpat,4.5,5.5); // KANAN ATAS
                            glVertex3f(22+fEmpat,2.5,5.5); // KANAN BAWAH
                            fEmpat+=1.7;
                    }

                //Jendela lt 3

                float fTiga=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(21+fTiga,-0.5,5.5); // KIRI BAWAH
                            glVertex3f(21+fTiga,2,5.5); // KIRI ATAS
                            glVertex3f(22+fTiga,2,5.5); // KANAN ATAS
                            glVertex3f(22+fTiga,-0.5,5.5); // KANAN BAWAH
                            fTiga+=1.7;
                    }

                //Jendela lt 2

                float fDua=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(21+fDua,-3,5.5); // KIRI BAWAH
                            glVertex3f(21+fDua,-1,5.5); // KIRI ATAS
                            glVertex3f(22+fDua,-1,5.5); // KANAN ATAS
                            glVertex3f(22+fDua,-3,5.5); // KANAN BAWAH
                            fDua+=1.7;
                    }

                //Jendela lt 1

                float fSatu=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(21+fSatu,-5.5,5.5); // KIRI BAWAH
                            glVertex3f(21+fSatu,-3.5,5.5); // KIRI ATAS
                            glVertex3f(22+fSatu,-3.5,5.5); // KANAN ATAS
                            glVertex3f(22+fSatu,-5.5,5.5); // KANAN BAWAH
                            fSatu+=1.7;
                    }

                //Jendela lt 0

                float gEnol=0;
                    for(i=0;i<11;i++){
                            glColor3f(1,1,1);
                            glVertex3f(-39+gEnol,-8,5.5); // KIRI BAWAH
                            glVertex3f(-39+gEnol,-6,5.5); // KIRI ATAS
                            glVertex3f(-38+gEnol,-6,5.5); // KANAN ATAS
                            glVertex3f(-38+gEnol,-8,5.5); // KANAN BAWAH
                            gEnol+=1.7;
                    }

        //DINDING KANAN
        glColor3ub(219, 172, 129);
        glVertex3f(50.0,-10.0,10.0); //KIRI BAWAH
        glVertex3f(50.0,8.0,10.0); //KIRI ATAS
        glVertex3f(50.0,8.0,-10.0); //KANAN ATAS
        glVertex3f(50.0,-10.0,-10.0); //KANAN BAWAH
        glEnd();
    //DUA
        //HADAP KIRI
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(40.0,-10.0,5.0); //KIRI BAWAH
        glVertex3f(40.0,8.0,5.0); //KIRI ATAS
        glVertex3f(40.0,8.0,10.0); //KANAN ATAS
        glVertex3f(40.0,-10.0,10.0); //KANAN BAWAH
        //HADAP DEPAN
        glColor3ub(219, 172, 129);
        glVertex3f(40.0,-10.0,10.0); //KIRI BAWAH
        glVertex3f(40.0,8.0,10.0); //KIRI ATAS
        glVertex3f(50.0,8.0,10.0); //KANAN ATAS
        glVertex3f(50.0,-10.0,10.0); //KANAN BAWAH

            //Jendela DUA DEPAN

                //Jendela Lt 6
                int iEnam=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(40.5+iEnam,5,10.5); // KIRI BAWAH
                            glVertex3f(40.5+iEnam,7.0,10.5); // KIRI ATAS
                            glVertex3f(41.5+iEnam,7.0,10.5); // KANAN ATAS
                            glVertex3f(41.5+iEnam,5,10.5); // KANAN BAWAH
                            iEnam+=2;
                    }

                //Jendela Lt 5
                int iLima=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(40.5+iLima,2.5,10.5); // KIRI BAWAH
                            glVertex3f(40.5+iLima,4.5,10.5); // KIRI ATAS
                            glVertex3f(41.5+iLima,4.5,10.5); // KANAN ATAS
                            glVertex3f(41.5+iLima,2.5,10.5); // KANAN BAWAH
                            iLima+=2;
                    }

                //Jendela Lt 4
                int iEmpat=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(40.5+iEmpat,-0.5,10.5); // KIRI BAWAH
                            glVertex3f(40.5+iEmpat,2,10.5); // KIRI ATAS
                            glVertex3f(41.5+iEmpat,2,10.5); // KANAN ATAS
                            glVertex3f(41.5+iEmpat,-0.5,10.5); // KANAN BAWAH
                            iEmpat+=2;
                    }

                //Jendela Lt 3
                int iTiga=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(40.5+iTiga,-3,10.5); // KIRI BAWAH
                            glVertex3f(40.5+iTiga,-1,10.5); // KIRI ATAS
                            glVertex3f(41.5+iTiga,-1,10.5); // KANAN ATAS
                            glVertex3f(41.5+iTiga,-3,10.5); // KANAN BAWAH
                            iTiga+=2;
                    }

                //Jendela Lt 2
                int iDua=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(40.5+iDua,-5.5,10.5); // KIRI BAWAH
                            glVertex3f(40.5+iDua,-3.5,10.5); // KIRI ATAS
                            glVertex3f(41.5+iDua,-3.5,10.5); // KANAN ATAS
                            glVertex3f(41.5+iDua,-5.5,10.5); // KANAN BAWAH
                            iDua+=2;
                    }

                 //Jendela Lt 1
                int iSatu=0;
                    for(i=0;i<5;i++){
                            glColor3f(1,1,1);
                            glVertex3f(40.5+iSatu,-8,10.5); // KIRI BAWAH
                            glVertex3f(40.5+iSatu,-6,10.5); // KIRI ATAS
                            glVertex3f(41.5+iSatu,-6,10.5); // KANAN ATAS
                            glVertex3f(41.5+iSatu,-8,10.5); // KANAN BAWAH
                            iSatu+=2;
                    }
        glEnd();

    //BAWAH
        //TENGAH
        glBegin(GL_QUADS);
        glColor3ub(180, 157, 143);
        glVertex3f(-20.0,-10.0,10.0); //KIRI ATAS
        glVertex3f(20.0,-10.0,10.0); //KANAN ATAS
        glVertex3f(20.0,-10.0,-10.0); // KANAN BAWAH
        glVertex3f(-20.0,-10.0,-10.0); //KIRI BAWAH
        //DEPAN
        glColor3ub(180, 157, 143);
        glVertex3f(5.0,-10.0,15.0); //KANAN BAWAH
        glVertex3f(5.0,-10.0,10.0); //KANAN ATAS
        glVertex3f(-5.0,-10.0,10.0); // KIRI ATAS
        glVertex3f(-5.0,-10.0,15.0); // KIRI BAWAH
        //KANAN
        glColor3ub(180, 157, 143);
        glVertex3f(20.0,-10.0,5.0); //KIRI ATAS
        glVertex3f(40.0,-10.0,5.0); //KANAN ATAS
        glVertex3f(40.0,-10.0,-10.0); //KANAN BAWAH
        glVertex3f(20.0,-10.0,-10.0); //KIRI BAWAH
            //PALING KANAN
            glColor3ub(180, 157, 143);
            glVertex3f(40.0,-10.0,10.0); //KIRI ATAS
            glVertex3f(40.0,-10.0,-10.0); //KIRI BAWAH
            glVertex3f(50.0,-10.0,-10.0); //KANAN BAWAH
            glVertex3f(50.0,-10.0,10.0); //KANAN ATAS
        //KIRI
        glColor3ub(180, 157, 143);
        glVertex3f(-20.0,-10.0,5.0); //KANAN ATAS
        glVertex3f(-40.0,-10.0,5.0); //KIRI ATAS
        glVertex3f(-40.0,-10.0,-10.0); //KIRI BAWAH
        glVertex3f(-20.0,-10.0,-10.0); //KANAN BAWAH
            //PALING KIRI
            glColor3ub(180, 157, 143);
            glVertex3f(-40.0,-10.0,10.0); //KANAN ATAS
            glVertex3f(-40.0,-10.0,-10.0); //KANAN BAWAH
            glVertex3f(-50.0,-10.0,-10.0); //KIRI BAWAH
            glVertex3f(-50.0,-10.0,10.0); //KIRI ATAS
        glEnd();

    //ATAP
        //BANGUNAN MIRING
            //DEPAN
            glBegin(GL_QUADS);
            glColor3ub(182, 153, 137);
            glVertex3f(-5.0,10.0,15.0); //KIRI BAWAH
            glVertex3f(-6.0,11.0,16.0); //KIRI ATAS
            glVertex3f(6.0,11.0,16.0); //KANAN ATAS
            glVertex3f(5.0,10.0,15.0); //KANAN BAWAH
            //KIRI1
            glVertex3f(-5.0,10.0,10.0); //KIRI BAWAH
            glVertex3f(-6.0,11.0,11.0); //KIRI ATAS
            glVertex3f(-6.0,11.0,16.0); //KANAN ATAS
            glVertex3f(-5.0,10.0,15.0); //KANAN BAWAH
            //KANAN1
            glVertex3f(5.0,10.0,15.0); //KIRI BAWAH
            glVertex3f(6.0,11.0,16.0); //KIRI ATAS
            glVertex3f(6.0,11.0,11.0); //KANAN ATAS
            glVertex3f(5.0,10.0,10.0); //KANAN BAWAH
            //KIRI2
            glColor3ub(182, 153, 137);
            glVertex3f(-5.0,10.0,10.0); //KANAN BAWAH
            glVertex3f(-6.0,11.0,11.0); //KANAN ATAS
            glVertex3f(-21.0,11.0,11.0); //KIRI ATAS
            glVertex3f(-20.0,10.0,10.0); //KIRI BAWAH
            //KANAN2
            glVertex3f(5.0,10.0,10.0); //KIRI BAWAH
            glVertex3f(6.0,11.0,11.0); //KIRI ATAS
            glVertex3f(21.0,11.0,11.0); //KANAN ATAS
            glVertex3f(20.0,10.0,10.0); //KANAN BAWAH
            glEnd();
            //KIRI3
            glBegin(GL_QUADS);
            glColor3ub(182, 153, 137);
            glVertex3f(-20.0,10.0,10.0); //KANAN BAWAH
            glVertex3f(-21.0,11.0,11.0); //KANAN BAWAH
            glVertex3f(-21.0,11.0,-11.0); //KIRI ATAS
            glVertex3f(-20.0,10.0,-10.0); //KIRI BAWAH
            //KANAN3
            glVertex3f(20.0,10.0,10.0); //KIRI BAWAH
            glVertex3f(21.0,11.0,11.0); //KIRI ATAS
            glVertex3f(21.0,11.0,-11.0); //KANAN ATAS
            glVertex3f(20.0,10.0,-10.0); //KANAN BAWAH
            glEnd();
            //KIRI4
            glBegin(GL_QUADS);
            glColor3ub(182, 153, 137);
            glVertex3f(-20.0,8.0,5.0); //KANAN BAWAH
            glVertex3f(-20.0,9.0,6.0); //KANAN ATAS
            glVertex3f(-39.0,9.0,6.0); //KIRI ATAS
            glVertex3f(-40.0,8.0,5.0); //KIRI BAWAH
            //KANAN 4
            glVertex3f(20.0,8.0,5.0); //KIRI BAWAH
            glVertex3f(20.0,9.0,6.0); //KIRI ATAS
            glVertex3f(39.0,9.0,6.0); //KANAN ATAS
            glVertex3f(40.0,8.0,5.0); //KANAN BAWAH
            glEnd();
            //BANGUNAN KIRI 2
                //HADAP KANAN
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(-40.0,8.0,5.0); //KANAN BAWAH
                glVertex3f(-39.0,9.0,6.0); //KANAN ATAS
                glVertex3f(-39.0,9.0,11.0); //KIRI ATAS
                glVertex3f(-40.0,8.0,10.0); //KIRI BAWAH
                glEnd();
                //HADAP DEPAN
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(-40.0,8.0,10.0); //KANAN BAWAH
                glVertex3f(-39.0,9.0,11.0); //KANAN ATAS
                glVertex3f(-51.0,9.0,11.0); //KIRI ATAS
                glVertex3f(-50.0,8.0,10.0); //KIRI BAWAH
                glEnd();
            //BANGUNAN KANAN 2
                //HADAP KIRI
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(40.0,8.0,5.0); //KIRI BAWAH
                glVertex3f(39.0,9.0,6.0); //KIRI ATAS
                glVertex3f(39.0,9.0,11.0); //KANAN ATAS
                glVertex3f(40.0,8.0,10.0); //KANAN BAWAH
                glEnd();
                //HADAP DEPAN
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(40.0,8.0,10.0); //KIRI BAWAH
                glVertex3f(39.0,9.0,11.0); //KIRI ATAS
                glVertex3f(51.0,9.0,11.0); //KANAN ATAS
                glVertex3f(50.0,8.0,10.0); //KANAN BAWAH
            //TAMPAK KIRI
            glColor3ub(182, 153, 137);
            glVertex3f(-50.0,8.0,10.0); //KANAN BAWAH
            glVertex3f(-51.0,9.0,11.0); //KANAN ATAS
            glVertex3f(-51.0,9.0,-11.0); //KIRI ATAS
            glVertex3f(-50.0,8.0,-10.0); //KIRI BAWAH
            //TAMPAK KANAN
            glVertex3f(50.0,8.0,10.0); //KIRI BAWAH
            glVertex3f(51.0,9.0,11.0); //KIRI ATAS
            glVertex3f(51.0,9.0,-11.0); //KANAN ATAS
            glVertex3f(50.0,8.0,-10.0); //KANAN BAWAH

            //TAMPAK BELAKANG
            //TENGAH
            glVertex3f(-20.0,10.0,-10.0); //KANAN BAWAH
            glVertex3f(-21.0,11.0,-11.0); //KANAN ATAS
            glVertex3f(21.0,11.0,-11.0); //KIRI ATAS
            glVertex3f(20.0,10.0,-10.0); //KIRI BAWAH
            //KANAN
            glColor3ub(182, 153, 137);
            glVertex3f(50.0,8.0,-10.0); //KIRI BAWAH
            glVertex3f(51.0,9.0,-11.0); //KANAN ATAS
            glVertex3f(20.0,9.0,-11.0); //KIRI ATAS
            glVertex3f(20.0,8.0,-10.0); //KIRI BAWAH
            //KIRI
            glVertex3f(-50.0,8.0,-10.0); //KANAN BAWAH
            glVertex3f(-51.0,9.0,-11.0); //KANAN ATAS
            glVertex3f(-20.0,9.0,-11.0); //KIRI ATAS
            glVertex3f(-20.0,8.0,-10.0); //KIRI BAWAH
            glEnd();
                //SEGITIGA KECIL
                    //KANAN
                    glBegin(GL_TRIANGLES);
                    glColor3ub(182, 153, 137);
                    glVertex3f(20.0,9.0,-11.0); //KIRI
                    glVertex3f(20.0,9.0,-10.0); //KANAN
                    glVertex3f(20.0,8.0,-10.0); //BAWAH
                    //KIRI
                    glVertex3f(-20.0,9.0,-11.0); //KANAN
                    glVertex3f(-20.0,9.0,-10.0); //KIRI
                    glVertex3f(-20.0,8.0,-10.0); //BAWAH
                    glEnd();

        //TENGAH
        glBegin(GL_QUADS);
        glColor3ub(186, 115, 69);
        glVertex3f(-21.0,11.0,11.0); //KIRI BAWAH
        glVertex3f(21.0,11.0,11.0); //KANAN BAWAH
        glVertex3f(21.0,11.0,-11.0); // KANAN ATAS
        glVertex3f(-21.0,11.0,-11.0); //KIRI ATAS
        //DEPAN
        glColor3ub(186, 115, 69);
        glVertex3f(-6.0,11.0,16.0); //KIRI BAWAH
        glVertex3f(-6.0,11.0,11.0); //KIRI ATAS
        glVertex3f(6.0,11.0,11.0); // KANAN ATAS
        glVertex3f(6.0,11.0,16.0); // KANAN BAWAH
        //KANAN
        glColor3ub(186, 115, 69);
        glVertex3f(20.0,9.0,6.0); //KIRI BAWAH
        glVertex3f(39.0,9.0,6.0); //KANAN BAWAH
        glVertex3f(39.0,9.0,-11.0); //KANAN ATAS
        glVertex3f(20.0,9.0,-11.0); //KIRI ATAS
            //PALING KANAN
            glColor3ub(186, 115, 69);
            glVertex3f(39.0,9.0,11.0); //KIRI BAWAH
            glVertex3f(39.0,9.0,-11.0); //KIRI ATAS
            glVertex3f(51.0,9.0,-11.0); //KANAN ATAS
            glVertex3f(51.0,9.0,11.0); //KANAN BAWAH
        //KIRI
        glColor3ub(186, 115, 69);
        glVertex3f(-20.0,9.0,6.0); //KANAN ATAS
        glVertex3f(-39.0,9.0,6.0); //KIRI ATAS
        glVertex3f(-39.0,9.0,-11.0); //KIRI BAWAH
        glVertex3f(-20.0,9.0,-11.0); //KANAN BAWAH
            //PALING KIRI
            glColor3ub(186, 115, 69);
            glVertex3f(-39.0,9.0,11.0); //KANAN BAWAH
            glVertex3f(-39.0,9.0,-11.0); //KANAN ATAS
            glVertex3f(-51.0,9.0,-11.0); //KIRI ATAS
            glVertex3f(-51.0,9.0,11.0); //KIRI BAWAH
        glEnd();
//LANTAI 2
    //DEPAN
        //HADAP DEPAN
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(-5.0,11.0,8.0); //KIRI BAWAH
        glVertex3f(-5.0,14.0,8.0); //KIRI ATAS
        glVertex3f(5.0,14.0,8.0); //KANAN ATAS
        glVertex3f(5.0,11.0,8.0); //KANAN BAWAH

            //Jendela Tengah
            int a=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+a,11.5,8.5); // KIRI BAWAH
                glVertex3f(-2.5+a,13,8.5); // KIRI ATAS
                glVertex3f(-1.5+a,13,8.5); // KANAN ATAS
                glVertex3f(-1.5+a,11.5,8.5); // KANAN BAWAH
                a+=2;
            }


        //KANAN
        glColor3ub(219, 172, 129);
        glVertex3f(5.0,11.0,8.0); //KIRI BAWAH
        glVertex3f(5.0,14.0,8.0); //KIRI ATAS
        glVertex3f(5.0,14.0,5.0); //KANAN ATAS
        glVertex3f(5.0,11.0,5.0); //KANAN BAWAH
        //KIRI
        glVertex3f(-5.0,11.0,8.0); //KANAN BAWAH
        glVertex3f(-5.0,14.0,8.0); //KANAN ATAS
        glVertex3f(-5.0,14.0,5.0); //KIRI ATAS
        glVertex3f(-5.0,11.0,5.0); //KIRI BAWAH
        glEnd();
    //KIRI
        //HADAP KIRI
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(-8.0,11.0,-5.0); //KIRI BAWAH
        glVertex3f(-8.0,14.0,-5.0); //KIRI ATAS
        glVertex3f(-8.0,14.0,5.0); //KANAN ATAS
        glVertex3f(-8.0,11.0,5.0); //KANAN BAWAH
        //KANAN
        glVertex3f(-8.0,11.0,5.0); //KIRI BAWAH
        glVertex3f(-8.0,14.0,5.0); //KIRI ATAS
        glVertex3f(-5.0,14.0,5.0); //KANAN ATAS
        glVertex3f(-5.0,11.0,5.0); //KANAN BAWAH
        //KIRI
        glVertex3f(-8.0,11.0,-5.0); //KANAN BAWAH
        glVertex3f(-8.0,14.0,-5.0); //KANAN ATAS
        glVertex3f(-5.0,14.0,-5.0); //KIRI ATAS
        glVertex3f(-5.0,11.0,-5.0); //KIRI BAWAH
        glEnd();
    //KANAN
        //HADAP KANAN
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(8.0,11.0,5.0); //KIRI BAWAH
        glVertex3f(8.0,14.0,5.0); //KIRI ATAS
        glVertex3f(8.0,14.0,-5.0); //KANAN ATAS
        glVertex3f(8.0,11.0,-5.0); //KANAN BAWAH
        //KANAN
        glVertex3f(8.0,11.0,-5.0); //KIRI BAWAH
        glVertex3f(8.0,14.0,-5.0); //KIRI ATAS
        glVertex3f(5.0,14.0,-5.0); //KANAN ATAS
        glVertex3f(5.0,11.0,-5.0); //KANAN BAWAH
        //KIRI
        glVertex3f(8.0,11.0,5.0); //KANAN BAWAH
        glVertex3f(8.0,14.0,5.0); //KANAN ATAS
        glVertex3f(5.0,14.0,5.0); //KIRI ATAS
        glVertex3f(5.0,11.0,5.0); //KIRI BAWAH
        glEnd();
    //BELAKANG
        //HADAP BELAKANG
        glBegin(GL_QUADS);
        glColor3ub(219, 172, 129);
        glVertex3f(5.0,11.0,-8.0); //KIRI BAWAH
        glVertex3f(5.0,14.0,-8.0); //KIRI ATAS
        glVertex3f(-5.0,14.0,-8.0); //KANAN ATAS
        glVertex3f(-5.0,11.0,-8.0); //KANAN BAWAH
        //KANAN
        glVertex3f(-5.0,11.0,-8.0); //KIRI BAWAH
        glVertex3f(-5.0,14.0,-8.0); //KIRI ATAS
        glVertex3f(-5.0,14.0,-5.0); //KANAN ATAS
        glVertex3f(-5.0,11.0,-5.0); //KANAN BAWAH
        //KIRI
        glVertex3f(5.0,11.0,-8.0); //KANAN BAWAH
        glVertex3f(5.0,14.0,-8.0); //KANAN ATAS
        glVertex3f(5.0,14.0,-5.0); //KIRI ATAS
        glVertex3f(5.0,11.0,-5.0); //KIRI BAWAH
        glEnd();
    //ATAP
        //MIRING
            //DEPAN
                //HADAP DEPAN
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(-5.0,14.0,8.0); //KIRI BAWAH
                glVertex3f(-6.0,15.0,9.0); //KIRI ATAS
                glVertex3f(6.0,15.0,9.0); //KANAN ATAS
                glVertex3f(5.0,14.0,8.0); //KANAN BAWAH
                //KANAN
                glColor3ub(182, 153, 137);
                glVertex3f(5.0,14.0,8.0); //KIRI BAWAH
                glVertex3f(6.0,15.0,9.0); //KIRI ATAS
                glVertex3f(6.0,15.0,6.0); //KANAN ATAS
                glVertex3f(5.0,14.0,5.0); //KANAN BAWAH
                //KIRI
                glVertex3f(-5.0,14.0,8.0); //KANAN BAWAH
                glVertex3f(-6.0,15.0,9.0); //KANAN ATAS
                glVertex3f(-6.0,15.0,6.0); //KIRI ATAS
                glVertex3f(-5.0,14.0,5.0); //KIRI BAWAH
            //KIRI
                //HADAP KIRI
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(-8.0,14.0,-5.0); //KIRI BAWAH
                glVertex3f(-9.0,15.0,-6.0); //KIRI ATAS
                glVertex3f(-9.0,15.0,6.0); //KANAN ATAS
                glVertex3f(-8.0,14.0,5.0); //KANAN BAWAH
                //KANAN
                glColor3ub(182, 153, 137);
                glVertex3f(-8.0,14.0,5.0); //KIRI BAWAH
                glVertex3f(-9.0,15.0,6.0); //KIRI ATAS
                glVertex3f(-6.0,15.0,6.0); //KANAN ATAS
                glVertex3f(-5.0,14.0,5.0); //KANAN BAWAH
                //KIRI
                glVertex3f(-8.0,14.0,-5.0); //KANAN BAWAH
                glVertex3f(-9.0,15.0,-6.0); //KANAN ATAS
                glVertex3f(-6.0,15.0,-6.0); //KIRI ATAS
                glVertex3f(-5.0,14.0,-5.0); //KIRI BAWAH
            //KANAN
                //HADAP KANAN
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(8.0,14.0,5.0); //KANAN BAWAH
                glVertex3f(9.0,15.0,6.0); //KANAN ATAS
                glVertex3f(9.0,15.0,-6.0); //KIRI ATAS
                glVertex3f(8.0,14.0,-5.0); //KIRI BAWAH
                //KIRI
                glColor3ub(182, 153, 137);
                glVertex3f(8.0,14.0,-5.0); //KANAN BAWAH
                glVertex3f(9.0,15.0,-6.0); //KANAN ATAS
                glVertex3f(6.0,15.0,-6.0); //KIRI ATAS
                glVertex3f(5.0,14.0,-5.0); //KIRI BAWAH
                //KANAN
                glVertex3f(8.0,14.0,5.0); //KIRI BAWAH
                glVertex3f(9.0,15.0,6.0); //KIRI ATAS
                glVertex3f(6.0,15.0,6.0); //KANAN ATAS
                glVertex3f(5.0,14.0,5.0); //KANAN BAWAH
            //BELAKANG
                //HADAP BELAKANG
                glBegin(GL_QUADS);
                glColor3ub(182, 153, 137);
                glVertex3f(5.0,14.0,-8.0); //KANAN BAWAH
                glVertex3f(6.0,15.0,-9.0); //KANAN ATAS
                glVertex3f(-6.0,15.0,-9.0); //KIRI ATAS
                glVertex3f(-5.0,14.0,-8.0); //KIRI BAWAH
                //KIRI
                glColor3ub(182, 153, 137);
                glVertex3f(-5.0,14.0,-8.0); //KANAN BAWAH
                glVertex3f(-6.0,15.0,-9.0); //KANAN ATAS
                glVertex3f(-6.0,15.0,-6.0); //KIRI ATAS
                glVertex3f(-5.0,14.0,-5.0); //KIRI BAWAH
                //KANAN
                glVertex3f(5.0,14.0,-8.0); //KIRI BAWAH
                glVertex3f(6.0,15.0,-9.0); //KIRI ATAS
                glVertex3f(6.0,15.0,-6.0); //KANAN ATAS
                glVertex3f(5.0,14.0,-5.0); //KANAN BAWAH

        //VERTIKAL
        glColor3ub(186, 115, 69);
        glVertex3f(-6.0,15.0,9.0); //KIRI BAWAH
        glVertex3f(-6.0,15.0,-9.0); //KIRI ATAS
        glVertex3f(6.0,15.0,-9.0); //KANAN ATAS
        glVertex3f(6.0,15.0,9.0); //KANAN BAWAH
        //HORISONTAL
        glColor3ub(186, 115, 69);
        glVertex3f(-9.0,15.0,6.0); //KIRI BAWAH
        glVertex3f(9.0,15.0,6.0); //KANAN BAWAH
        glVertex3f(9.0,15.0,-6.0); //KANAN ATAS
        glVertex3f(-9.0,15.0,-6.0); //KIRI ATAS
        glEnd();
//LANTAI 3
    //HADAP DEPAN
    glBegin(GL_QUADS);
    glColor3ub(219, 172, 129);
    glVertex3f(-4.0,15.0,4.0); //KIRI BAWAH
    glVertex3f(-4.0,24.0,4.0); //KIRI ATAS
    glVertex3f(4.0,24.0,4.0); //KANAN ATAS
    glVertex3f(4.0,15.0,4.0); //KANAN BAWAH

        //Jendela Tengah

            //Jendela Lt 1
            int bSatu=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+bSatu,22.5,4.5); // KIRI BAWAH
                glVertex3f(-2.5+bSatu,23,4.5); // KIRI ATAS
                glVertex3f(-1.5+bSatu,23,4.5); // KANAN ATAS
                glVertex3f(-1.5+bSatu,22.5,4.5); // KANAN BAWAH
                bSatu+=2;
            }

            //Jendela Lt 2
            int bDua=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+bDua,21.5,4.5); // KIRI BAWAH
                glVertex3f(-2.5+bDua,22,4.5); // KIRI ATAS
                glVertex3f(-1.5+bDua,22,4.5); // KANAN ATAS
                glVertex3f(-1.5+bDua,21.5,4.5); // KANAN BAWAH
                bDua+=2;
            }

            //Jendela Lt 3
            int bTiga=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+bTiga,20.5,4.5); // KIRI BAWAH
                glVertex3f(-2.5+bTiga,21,4.5); // KIRI ATAS
                glVertex3f(-1.5+bTiga,21,4.5); // KANAN ATAS
                glVertex3f(-1.5+bTiga,20.5,4.5); // KANAN BAWAH
                bTiga+=2;
            }

            //Jendela Lt 4
            int bEmpat=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+bEmpat,19.5,4.5); // KIRI BAWAH
                glVertex3f(-2.5+bEmpat,20,4.5); // KIRI ATAS
                glVertex3f(-1.5+bEmpat,20,4.5); // KANAN ATAS
                glVertex3f(-1.5+bEmpat,19.5,4.5); // KANAN BAWAH
                bEmpat+=2;
            }

            //Jendela Lt 5
            int bLima=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+bLima,18.5,4.5); // KIRI BAWAH
                glVertex3f(-2.5+bLima,19,4.5); // KIRI ATAS
                glVertex3f(-1.5+bLima,19,4.5); // KANAN ATAS
                glVertex3f(-1.5+bLima,18.5,4.5); // KANAN BAWAH
                bLima+=2;
            }

            //Jendela Lt 6
            int bEnam=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+bEnam,17.5,4.5); // KIRI BAWAH
                glVertex3f(-2.5+bEnam,18,4.5); // KIRI ATAS
                glVertex3f(-1.5+bEnam,18,4.5); // KANAN ATAS
                glVertex3f(-1.5+bEnam,17.5,4.5); // KANAN BAWAH
                bEnam+=2;
            }

             //Jendela Lt 7
            int bTujuh=0;
            for(i=0;i<3;i++){
                glColor3f(1,1,1);
                glVertex3f(-2.5+bTujuh,16.5,4.5); // KIRI BAWAH
                glVertex3f(-2.5+bTujuh,17,4.5); // KIRI ATAS
                glVertex3f(-1.5+bTujuh,17,4.5); // KANAN ATAS
                glVertex3f(-1.5+bTujuh,16.5,4.5); // KANAN BAWAH
                bTujuh+=2;
            }


    //HADAP KANAN
    glColor3ub(219, 172, 129);
    glVertex3f(4.0,15.0,4.0); //KIRI BAWAH
    glVertex3f(4.0,24.0,4.0); //KIRI ATAS
    glVertex3f(4.0,24.0,-4.0); //KANAN ATAS
    glVertex3f(4.0,15.0,-4.0); //KANAN BAWAH
    //HADAP KIRI
    glColor3ub(219, 172, 129);
    glVertex3f(-4.0,15.0,-4.0); //KIRI BAWAH
    glVertex3f(-4.0,24.0,-4.0); //KIRI ATAS
    glVertex3f(-4.0,24.0,4.0); //KANAN ATAS
    glVertex3f(-4.0,15.0,4.0); //KANAN BAWAH
    //HADAP BELAKANG
    glColor3ub(219, 172, 129);
    glVertex3f(4.0,15.0,-4.0); //KIRI BAWAH
    glVertex3f(4.0,24.0,-4.0); //KIRI ATAS
    glVertex3f(-4.0,24.0,-4.0); //KANAN ATAS
    glVertex3f(-4.0,15.0,-4.0); //KANAN BAWAH
    //ATAP
        //MIRING
            //DEPAN
            glColor3ub(182, 153, 137);
            glVertex3f(-4.0,24.0,4.0); //KIRI BAWAH
            glVertex3f(-5.0,25.0,5.0); //KIRI ATAS
            glVertex3f(5.0,25.0,5.0); //KANAN ATAS
            glVertex3f(4.0,24.0,4.0); //KANAN BAWAH
            //BELAKANG
            glVertex3f(4.0,24.0,-4.0); //KIRI BAWAH
            glVertex3f(5.0,25.0,-5.0); //KIRI ATAS
            glVertex3f(-5.0,25.0,-5.0); //KANAN ATAS
            glVertex3f(-4.0,24.0,-4.0); //KANAN BAWAH
            //KANAN
            glColor3ub(182, 153, 137);
            glVertex3f(4.0,24.0,4.0); //KIRI BAWAH
            glVertex3f(5.0,25.0,5.0); //KIRI ATAS
            glVertex3f(5.0,25.0,-5.0); //KANAN ATAS
            glVertex3f(4.0,24.0,-4.0); //KANAN BAWAH
            //KIRI
            glVertex3f(-4.0,24.0,4.0); //KANAN BAWAH
            glVertex3f(-5.0,25.0,5.0); //KANAN ATAS
            glVertex3f(-5.0,25.0,-5.0); //KIRI ATAS
            glVertex3f(-4.0,24.0,-4.0); //KIRI BAWAH

    glColor3ub(186, 115, 69);
    glVertex3f(-5.0,25.0,5.0); //KIRI BAWAH
    glVertex3f(-5.0,25.0,-5.0); //KIRI ATAS
    glVertex3f(5.0,25.0,-5.0); //KANAN ATAS
    glVertex3f(5.0,25.0,5.0); //KANAN BAWAH
    glEnd();

//LANTAI 4
    //HADAP DEPAN
    glBegin(GL_QUADS);
    glColor3ub(219, 172, 129);
    glVertex3f(-2.0,25.0,2.0); //KIRI BAWAH
    glVertex3f(-2.0,29.0,2.0); //KIRI ATAS
    glVertex3f(2.0,29.0,2.0); //KANAN ATAS
    glVertex3f(2.0,25.0,2.0); //KANAN BAWAH

    //Jendela Tengah

            //Jendela Lt 1
                //KIRI
                    glColor3f(1,1,1);
                    glVertex3f(-1.5,26,2.5); // KIRI BAWAH
                    glVertex3f(-1.5,28,2.5); // KIRI ATAS
                    glVertex3f(-1,28,2.5); // KANAN ATAS
                    glVertex3f(-1,26,2.5); // KANAN BAWAH

                //TENGAH
                    glColor3f(1,1,1);
                    glVertex3f(-0.5,26,2.5); // KIRI BAWAH
                    glVertex3f(-0.5,28,2.5); // KIRI ATAS
                    glVertex3f(0.5,28,2.5); // KANAN ATAS
                    glVertex3f(0.5,26,2.5); // KANAN BAWAH

                //KANAN
                    glColor3f(1,1,1);
                    glVertex3f(1,26,2.5); // KIRI BAWAH
                    glVertex3f(1,28,2.5); // KIRI ATAS
                    glVertex3f(1.5,28,2.5); // KANAN ATAS
                    glVertex3f(1.5,26,2.5); // KANAN BAWAH

    //HADAP KANAN
    glColor3ub(219, 172, 129);
    glVertex3f(2.0,25.0,2.0); //KIRI BAWAH
    glVertex3f(2.0,29.0,2.0); //KIRI ATAS
    glVertex3f(2.0,29.0,-2.0); //KANAN ATAS
    glVertex3f(2.0,25.0,-2.0); //KANAN BAWAH
    //HADAP KIRI
    glColor3ub(219, 172, 129);
    glVertex3f(-2.0,25.0,-2.0); //KIRI BAWAH
    glVertex3f(-2.0,29.0,-2.0); //KIRI ATAS
    glVertex3f(-2.0,29.0,2.0); //KANAN ATAS
    glVertex3f(-2.0,25.0,2.0); //KANAN BAWAH
    //HADAP BELAKANG
    glColor3ub(219, 172, 129);
    glVertex3f(2.0,25.0,-2.0); //KIRI BAWAH
    glVertex3f(2.0,29.0,-2.0); //KIRI ATAS
    glVertex3f(-2.0,29.0,-2.0); //KANAN ATAS
    glVertex3f(-2.0,25.0,-2.0); //KANAN BAWAH
    //ATAP
    glColor3ub(186, 115, 69);
    glVertex3f(-3.0,30.0,3.0); //KIRI BAWAH
    glVertex3f(-3.0,30.0,-3.0); //KIRI ATAS
    glVertex3f(3.0,30.0,-3.0); //KANAN ATAS
    glVertex3f(3.0,30.0,3.0); //KANAN BAWAH
        //MIRING
            //DEPAN
            glColor3ub(182, 153, 137);
            glVertex3f(-2.0,29.0,2.0); //KIRI BAWAH
            glVertex3f(-3.0,30.0,3.0); //KIRI ATAS
            glVertex3f(3.0,30.0,3.0); //KANAN ATAS
            glVertex3f(2.0,29.0,2.0); //KANAN BAWAH
            //BELAKANG
            glVertex3f(2.0,29.0,-2.0); //KANAN BAWAH
            glVertex3f(3.0,30.0,-3.0); //KANAN ATAS
            glVertex3f(-3.0,30.0,-3.0); //KIRI ATAS
            glVertex3f(-2.0,29.0,-2.0); //KIRI BAWAH
            //KANAN
            glColor3ub(182, 153, 137);
            glVertex3f(2.0,29.0,-2.0); //KANAN BAWAH
            glVertex3f(3.0,30.0,-3.0); //KANAN ATAS
            glVertex3f(3.0,30.0,3.0); //KIRI ATAS
            glVertex3f(2.0,29.0,2.0); //KIRI BAWAH
            //KIRI
            glColor3ub(182, 153, 137);
            glVertex3f(-2.0,29.0,-2.0); //KIRI BAWAH
            glVertex3f(-3.0,30.0,-3.0); //KIRI ATAS
            glVertex3f(-3.0,30.0,3.0); //KANAN ATAS
            glVertex3f(-2.0,29.0,2.0); //KANAN BAWAH
            glEnd();

//LANTAI 5
    //DEPAN
    glBegin(GL_QUADS);
    glColor3ub(219, 172, 129);
    glVertex3f(-0.5,30,0.5); //KIRI BAWAH
    glVertex3f(-0.5,40,0.5); //KIRI ATAS
    glVertex3f(0.5,40,0.5); //KANAN ATAS
    glVertex3f(0.5,30,0.5); //KANAN BAWAH
    //BELAKANG
    glColor3ub(219, 172, 129);
    glVertex3f(0.5,30,-0.5); //KIRI BAWAH
    glVertex3f(0.5,40,-0.5); //KIRI ATAS
    glVertex3f(-0.5,40,-0.5); //KANAN ATAS
    glVertex3f(-0.5,30,-0.5); //KANAN BAWAH
    //KANAN
    glColor3ub(219, 172, 129);
    glVertex3f(0.5,30,0.5); //KIRI BAWAH
    glVertex3f(0.5,40,0.5); //KIRI ATAS
    glVertex3f(0.5,40,-0.5); //KANAN ATAS
    glVertex3f(0.5,30,-0.5); //KANAN BAWAH
    //KIRI
    glVertex3f(-0.5,30,0.5); //KANAN BAWAH
    glVertex3f(-0.5,40,0.5); //KANAN ATAS
    glVertex3f(-0.5,40,-0.5); //KIRI ATAS
    glVertex3f(-0.5,30,-0.5); //KIRI BAWAH
    glEnd();

//SEGITIGA PUNCAK
    //DEPAN
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-0.5,40,0.5); //KIRI
    glVertex3f(0.5,40,0.5); //KANAN
    glVertex3f(0,43,0); //PUNCAK
    //KANAN
    glVertex3f(0.5,40,0.5); //KIRI
    glVertex3f(0.5,40,-0.5); //KANAN
    glVertex3f(0,43,0); //PUNCAK
    //KIRI
    glVertex3f(-0.5,40,-0.5); //KIRI
    glVertex3f(-0.5,40,0.5); //KANAN
    glVertex3f(0,43,0); //KAKI KANAN
    //BELAKANG
    glVertex3f(0.5,40,-0.5); //KIRI
    glVertex3f(-0.5,40,-0.5); //KANAN
    glVertex3f(0,43,0); //KAKI KANAN

    glEnd();
}

void tampil(void){
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    nankaiuniversity();

//ALAT
    meja();
    kursi();
    papantulis();
    jamdinding();
    loker();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y){
    switch(key){
        case 'w':
        case 'W':
            glTranslatef(0.0,0.0,3.0);
            break;
        case 'd' :
        case 'D' :
            glTranslatef(3.0,0.0,0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(0.0,0.0,-3.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(-3.0,0.0,0.0);
            break;
        case '7':
            glTranslatef(0.0,3.0,0.0);
            break;
        case '9':
            glTranslatef(0.0,-3.0,0.0);
            break;
        case '2':
            glRotatef(2.0,1.0,0.0,0.0);
            break;
        case '8':
            glRotatef(-2.0,1.0,0.0,0.0);
            break;
        case '6':
            glRotatef(2.0,0.0,1.0,0.0);
            break;
        case '4':
            glRotatef(-2.0,0.0,1.0,0.0);
            break;
        case '1':
            glRotatef(2.0,0.0,0.0,1.0);
            break;
        case '3':
            glRotatef(-2.0,0.0,0.0,1.0);
            break;
        case '5':
            if(is_depth){
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void idle(){
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
glutPostRedisplay();
}


void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y+xrot;
    }
    else
        mouseDown = false;
}


void mouseMotion(int x,int y){
    glLoadIdentity();
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glRotatef(xrot,1.0f,0.0f,0.0f);
    glRotatef(yrot,0.0f,1.0f,0.0f);
    if(mouseDown)
    {
        yrot = x-xdiff;
        xrot = y+ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar,int tinggi){
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, lebar, tinggi);
    glLoadIdentity();
    gluPerspective(50.0,lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
