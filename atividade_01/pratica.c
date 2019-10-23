#include <GL/glut.h>

GLfloat xf = 0;
GLfloat yf = 0;
GLfloat angulo = 0;

int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);     //define a cor de fundo
    glMatrixMode(GL_PROJECTION);          //carrega a matriz de projeção
    gluOrtho2D(0.0,100.0,0.0,100.0);      //define projeção ortogonal 2D
 
}

void display(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0,0.0,0.0);               //altera a cor para vermelho
    
    glTranslatef(xf + 5, yf + 5, 0);
    glRotatef(angulo + 0, 0, 0, 1);
    glTranslatef(-xf - 5, -yf - 5, 0); 

    glClear(GL_COLOR_BUFFER_BIT);         //desenha o fundo (limpa a janela)
    glBegin(GL_POLYGON);                        
        // glVertex2i(0 + xf, 0 + yf);               
        // glVertex2i(0 + xf, 10 + yf);
        // glVertex2i(10 + xf, 10 + yf);
        // glVertex2i(10 + xf, 0 + yf);
        glVertex2i(0 + xf, 0 + yf);               
        glVertex2i(10 + xf, 0 + yf);
        glVertex2i(10 + xf, 10 + yf);
        glVertex2i(0 + xf, 10 + yf);
    glEnd();
 
    glFlush();                            //desenha os comandos não executados
}


void rotacao(int key, int x, int y) {
    if(key == GLUT_KEY_LEFT) {
        angulo += 10;
        glLoadIdentity();
    }

    if(key == GLUT_KEY_RIGHT) {
        angulo -= 10;
        glLoadIdentity();
    }
    glutPostRedisplay();
}

void translacao(int key, int x, int y) {
    if(key == GLUT_KEY_UP) {
        yf++;
        glLoadIdentity();
    }

    if(key == GLUT_KEY_DOWN) {
        yf--;
        glLoadIdentity();
    }

    if(key == GLUT_KEY_RIGHT) {
        xf++;
        glLoadIdentity();
    }

    if(key == GLUT_KEY_LEFT) {
        xf--;
        glLoadIdentity();
    }
    glutPostRedisplay();
}

void eventoTeclado (unsigned char key, int x, int y) {
    switch (key) {
        case 'R' :  //muda para a funcao rotacao;
        case 'r' :    
            glutSpecialFunc(rotacao);
            break;

        case 'T' :  //muda para a funcao transalacao;
        case 't' :
            glutSpecialFunc(translacao);            
            break;
    }
    glutPostRedisplay();
}
    
int main(int argc, char** argv) {
 
    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowSize(500,500);                              //configura a largura e altura da janela de exibição
    glutInitWindowPosition(200,0);
    glutCreateWindow("Atividade 01");           //cria a janela de exibição
    
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutSpecialFunc(translacao);
    glutKeyboardFunc(eventoTeclado);
    init();                          //executa função de inicialização
    glutMainLoop();                  //mostre tudo e espere
    return 0;
}