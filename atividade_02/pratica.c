#include <GL/glut.h>

GLsizei h = 800;
GLsizei w = 800;

double spin = 0.0;
double rotate = 0.001;

int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1, 50.0);
    //limpa o buffer

    //define que a matrix é a de modelo
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity();



    // Primeira projeção (canto superior esquerdo)
    gluLookAt(0.0, 3.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 0.0, -1.0);
    glViewport(0, h / 2.f, w / 2.f, h / 2.f);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(2.0f);


    // Segunda projeção (canto superior direito)
    glLoadIdentity();
    gluLookAt(5.0, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glViewport(h / 2.f, h / 2.f, w / 2.f, h / 2.f);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(2.0f);

    // Terceira projeção (canto inferior esquerdo)
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glViewport(0, 0, w / 2.f, h / 2.f);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(2.0f);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluPerspective(70, 1.0, 1.0, 50.0); 

    // Quarta projeção (canto inferior direito)
    gluLookAt(0.0, 0.0, 2.5,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity();
    glViewport(w / 2.f, 0, w / 2.f, h / 2.f);
    glRotatef(spin, 0.0, 0.0, 1.0);
    glRotatef(45, 1.0, 0.0, 0.0);

    // desenha um pote de cha
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1.0f);

    glFlush();
}


void Timer(int value) {
  spin += rotate;
  rotate += 0.001;
  glutPostRedisplay();
  glutTimerFunc(1, Timer, 1);
}

int main(int argc, char** argv){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(200,0);
  glutInitWindowSize(w, h);
  glutCreateWindow("Atividade 2");

  init();
  glutDisplayFunc(display);
  glutTimerFunc(1, Timer, 1);
  glutMainLoop();
  return 0;

}