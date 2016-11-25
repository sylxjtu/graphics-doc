#include <GL/glut.h>
#include <cstring>

GLubyte mask[128];

void initMask() {
  std::memset(mask, 0b00110011, sizeof(mask));
}

void myDisplay() {
  // Initialize canvas
  glClear(GL_COLOR_BUFFER_BIT);
  
  // Points
  // Draw point at (0.5, 0.5)
  glPointSize(5.0f);
  glBegin(GL_POINTS);
    glVertex2f(0.5f, 0.5f);
  glEnd();

  // Lines
  // Draw solid lines from (-1, 0) to (1, 0) and from (0, -1) to (0, 1)
  glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
  glEnd();
  // Draw stipple lines from (-1, -1) to (1, 1)
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(4, 0xAAAA);
  glBegin(GL_LINES);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
  glEnd();
  glDisable(GL_LINE_STIPPLE);

  // Polygons
  // Initialize fill methods
  glPolygonMode(GL_FRONT, GL_FILL);
  glPolygonMode(GL_BACK, GL_LINE);
  glFrontFace(GL_CCW);
  // Draw a triangle at (0, 0), (0, 1), (-1, 0), we see its front face
  glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-1.0f, 0.0f);
  glEnd();
  // Draw a rectangle at (0, 0), (-0.5, -0.5), (0, -0.5), (-0.5, 0), we see its back face
  glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, 0.0f);
  glEnd();
  // Stipple polygon
  glEnable(GL_POLYGON_STIPPLE);
  glPolygonStipple(mask);
  glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);
  glEnd();
  glDisable(GL_POLYGON_STIPPLE);
  
  // Flush to output
  glFlush();
}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 800);
  glutCreateWindow("shape");
  glutDisplayFunc(&myDisplay);

  initMask();

  glutMainLoop();
  return 0;
}
