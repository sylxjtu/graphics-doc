// ---------------------------------
// main.cpp 主程序
// Created by sylxjtu on 2016/11/17.
// ---------------------------------

#include <GL/glew.h>
#include <GL/glut.h>
#include "TextureImage.h"

// 定义初始角度，角速度，角加速度，FPS
double angle = 0;
double speed = 5;
double accelerate = 0;
const double FPS = 60;

// 定义贴图对象
TextureImage t;

void display();

// 初始化绘图环境
void init() {
    // 载入贴图文件
    t.loadFile("earth.bmp", 1024, 1024);
    t.loadTexture();
    // 初始化光照
    GLfloat light_position[] = {1.0, 0.3, 0.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // 启用颜色、深度测试、光照
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

// 动画函数
void idle() {
    // 改变旋转角
    speed += accelerate / FPS;
    angle += speed / FPS;
    display();
}

// 画地球函数
void drawSphere(int radius) {
    // 配置贴图
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, t.textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // 画球体
    GLUquadricObj *sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricTexture(sphere, TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluSphere(sphere, radius, 1024, 1024);
}

// 显示函数
void display() {
    // 清空缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // 初始化视角
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 100);
    // 初始化视点
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -10, 0, 0, 0, 0, 0, 0, 1);
    // 旋转球体
    glRotated(angle, 0, 0, 1);
    // 画球
    drawSphere(5);
    // 显示
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char **argv) {
    // 初始化显示
    glutInit(&argc, argv);
    glutInitDisplayMode(GL_DOUBLE | GL_RGB | GL_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Title");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    // 进入主循环
    glutMainLoop();
}
