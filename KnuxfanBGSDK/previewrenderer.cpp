// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "../src/utils.h"
#include "../src/cube.h"
#include "../src/mesh.h"
#include <glm/glm.hpp>
#include <time.h>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>
#include "previewrenderer.h"
int _fpsCount = 0;
int fps = 0; // this will store the final fps for the last second
glm::vec3 rainbow[6] = {
    glm::vec3(1.0,0.0,0.0),
    glm::vec3(1.0,1.0,0.0),
    glm::vec3(0.0,1.0,0.0),
    glm::vec3(0.0,1.0,1.0),
    glm::vec3(0.0,0.0,1.0),
    glm::vec3(1.0,0.0,1.0)
                       };
int color = 0;
std::chrono::time_point<std::chrono::steady_clock> lastTime = std::chrono::steady_clock::now();

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    connect(&timer, &QTimer::timeout, this, [&]() {
        QElapsedTimer elapsedtimer;
        elapsedtimer.start();
        update();
        //qDebug() << elapsedtimer.elapsed();
    });
    timer.setInterval(0);
    timer.start();
}

GLWidget::~GLWidget()
{
    cleanup();
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(640, 480);
}

QSize GLWidget::sizeHint() const
{
    return QSize(640, 480);
}

void GLWidget::cleanup()
{
    doneCurrent();
}


void GLWidget::initializeGL()
{
    // In this example the widget's corresponding top-level window can change
    // several times during the widget's lifetime. Whenever this happens, the
    // QOpenGLWidget's associated context is destroyed and a new one is created.
    // Therefore we have to be prepared to clean up the resources on the
    // aboutToBeDestroyed() signal, instead of the destructor. The emission of
    // the signal will be followed by an invocation of initializeGL() where we
    // can recreate all resources.

    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK)
    {
        printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
    }
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glFrontFace(GL_CW);

    shad = new shader("/home/knucklesfan/KnuxfanBGSDK/shaders/vertex_unlit.shader", "/home/knucklesfan/KnuxfanBGSDK/shaders/fragment_unlit.shader");
    litshad = new shader("/home/knucklesfan/KnuxfanBGSDK/shaders/vertex_lit.shader", "/home/knucklesfan/KnuxfanBGSDK/shaders/fragment_lit.shader");

    mod = new model("/home/knucklesfan/KnuxfanBGSDK/models/checkerboard/checkerboard.obj",glm::vec3(0.0f,-0.0f,0.0f),
                    glm::vec3(1.0f,1.0f,1.0f),glm::vec3((0.0f), 45.0f, 0.0f));

    heavy = new model("/home/knucklesfan/KnuxfanBGSDK/models/hvyweapon/heavy.obj",glm::vec3(2.0f,1.0f,1.0f),
                    glm::vec3(0.5f,0.5f,0.5f),glm::vec3((0.0f), 45.0f, 0.0f));
    petah = new model("/home/knucklesfan/KnuxfanBGSDK/models/peetah/peetah.obj",glm::vec3(2.0f,1.0f,-1.0f),
                    glm::vec3(1.0f,0.5f,1.0f),glm::vec3((0.0f), 45.0f, 0.0f));
    cam = new previewCamera(glm::vec3(0,2,0),glm::vec3(0,0,0),45,nullptr,640,480,0.00001f,100000.0f,0.05f);
    //i hate qt SO MUCH. I HATE IT SO MUCH I HATE IT SO MUCH ASDKLFJASDLKFJ;ASLKDJFA;KSLDJFA;S
    elements.push_back(new Light(LIGHTTYPE::DIRECTIONAL,glm::vec3(0.0f,45.0f,0.0f)));
}

void GLWidget::setupVertexAttribs()
{  
    //just pretend that "cub" was here, and you'd know why the comment above is so angry.
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    color++;
    glm::vec3 lightPos = glm::vec3(((float)cos(((float)rotate/1000 * glm::radians(50.0f))/2)*2) * 10,2.0f,((float)sin(((float)rotate/1000 * glm::radians(50.0f))/2)*2) * 10);

    rotate+=15;

    QPoint mouse = mapFromGlobal(QCursor::pos());
    if(move) {
        std::cout << "rotation" << mouse.x() << " " << mouse.y() <<"\n";
        cam->rotate(width()/2-(float)((int)mouse.x()),height()/2-(float)((int)mouse.y()));
        QCursor::setPos(mapToGlobal(QPoint(width()/2,height()/2)));
    }

//    glm::mat4 projection;
//    projection = glm::perspective(glm::radians(45.0f), (float)INTERNAL_WIDTH / (float)INTERNAL_HEIGHT, 0.001f, 10000.0f);
//    glm::mat4 view = glm::mat4(1.0f); //the actual transform of the model itself
//    view = glm::rotate(view, glm::radians(camerarot[0]), glm::vec3(1.0f, 0.0f, 0.0f));
//    view = glm::rotate(view, glm::radians(camerarot[1]), glm::vec3(0.0f, 1.0f, 0.0f));
//    view = glm::rotate(view, glm::radians(camerarot[2]), glm::vec3(0.0f, 0.0f, 1.0f));
//    //view = glm::rotate(view, glm::radians(-45.0f),glm::vec3(1.0f,0.0f,1.0f));

//    view = glm::translate(view,camerapos);

    //cub->rotation[0] = ((float)rotate/10 * glm::radians(50.0f))/2;
    //cub->rotation[1] = ((float)rotate/10 * glm::radians(50.0f));
    //mod->rotation[0] = 0;
    petah->rotation[1] = ((float)rotate/10 * glm::radians(50.0f));
    heavy->rotation[1] = -((float)rotate/10 * glm::radians(50.0f));
    petah->position.x = 2*cos((float)rotate/1000)+2.0;
    petah->position.z = 2*sin((float)rotate/2000)+1.0;
    petah->render(shad,cam->projection,cam->view());
    petah->position.x = 3*cos((float)rotate/3000)+2.0;
    petah->position.z = 3*sin((float)rotate/1000)+1.0;
    petah->render(shad,cam->projection,cam->view());
    petah->position.x = 4*cos((float)rotate/5000)+2.0;
    petah->position.z = 4*sin((float)rotate/1000)+1.0;
    petah->render(shad,cam->projection,cam->view());

    heavy->position.x = 2*sin((float)rotate/1000)+2.0;
        heavy->position.y = 0.5*sin((float)rotate/200)+2.0;
    heavy->position.z = 2*cos((float)rotate/1000)-1.0;

    for(int i = 0; i < elements.size(); i++) {
        elements.at(i)->render(litshad,cam->projection,cam->view(),i);
    }
    litshad->setVec3("viewPos",glm::value_ptr(camerapos));
    mod->render(shad,cam->projection,cam->view());
    heavy->render(shad,cam->projection,cam->view());

    //    mod->rotation[0] = -((float)rotate/50 * glm::radians(50.0f))/2;
//    mod->rotation[1] = -((float)rotate/50 * glm::radians(50.0f));

//    mod->postposition = glm::vec3(2.0f,0.0f,0.0f);
//    mod->render(shad,projection,view);

//    mod->rotation[0] = ((float)rotate/100 * glm::radians(50.0f))/2;
//    mod->rotation[1] = ((float)rotate/100 * glm::radians(50.0f));
//    mod->postposition = glm::vec3(-3.0f,0.0f,0.0f);
//    mod->render(shad,projection,view);

//    mod->rotation[0] = -((float)rotate/200 * glm::radians(50.0f))/2;
//    mod->rotation[1] = -((float)rotate/200 * glm::radians(50.0f));
//    mod->postposition = glm::vec3(4.0f,0.0f,0.0f);
//    mod->render(shad,projection,view);
    auto currentTime = std::chrono::steady_clock::now();

    const auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime).count();
    ++_fpsCount;

    if (elapsedTime > 1000000000) {
        lastTime = currentTime;
        fps = _fpsCount;
        _fpsCount = 0;

        std::cout << fps << "\n"; // print out fps in every second (or you can use it elsewhere)
    }
}

void GLWidget::resizeGL(int w, int h)
{

}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()== Qt::RightButton) {
        move = true;
    }
    else {
        move = false;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
}

void GLWidget::keyPressEvent(QKeyEvent *event) {
    keys[event->key()] = true;
}
void GLWidget::keyReleaseEvent(QKeyEvent *event) {
    keys[event->key()] = false;
}

