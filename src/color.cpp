#include <GL/glut.h>

void myDisplay() {
  // Initialize canvas
  glClear(GL_COLOR_BUFFER_BIT);

  // Color a polygon with RGBA color
  glColor3f(1.0f, 0.0f, 1.0f);
  glRectf(0.0f, 0.0f, 1.0f, 1.0f);

  // Color a polygon with different color smoothing model
  // GL_SMOOTH model
  glShadeModel(GL_SMOOTH);
  glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
  glEnd();
  // GL_FLAT model
  glShadeModel(GL_FLAT);
  glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-1.0f, 0.0f);
  glEnd();

  // Flush to output
  glFlush();
}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 800);
  glutCreateWindow("color");
  glutDisplayFunc(&myDisplay);
  glutMainLoop();
  return 0;
}
