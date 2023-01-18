// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "../src/utils.h"
#include "../src/cube.h"
#include "../src/skybox.h"

#include <glm/glm.hpp>
#include <time.h>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>
#include "editorutils.h"
#include "texturepreview.h"
TexturePreview::TexturePreview(QWidget *parent)
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

TexturePreview::~TexturePreview()
{
    cleanup();
}

QSize TexturePreview::minimumSizeHint() const
{
    return QSize(640, 480);
}

QSize TexturePreview::sizeHint() const
{
    return QSize(640, 480);
}

void TexturePreview::cleanup()
{
    doneCurrent();
}


void TexturePreview::initializeGL()
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

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    shad = new shader("/home/knucklesfan/KnuxfanBGSDK/shaders/vertex_unlit.shader", "/home/knucklesfan/KnuxfanBGSDK/shaders/fragment_unlit.shader");
    skyshad = new shader("/home/knucklesfan/KnuxfanBGSDK/shaders/vertex_background.shader", "/home/knucklesfan/KnuxfanBGSDK/shaders/fragment_background.shader");


    //i hate qt SO MUCH. I HATE IT SO MUCH I HATE IT SO MUCH ASDKLFJASDLKFJ;ASLKDJFA;KSLDJFA;S
    cub = new cube(glm::vec3(0.0f,0.0f,-2.0f),glm::vec3(0.0f,0.0f,0.0f),
    glm::vec3(1.0f,1.0f,1.0f),glm::vec3((-85.0f), 45.0f, 0.0f));
    box = new skybox();

}

void TexturePreview::setupVertexAttribs()
{  
    //just pretend that "cub" was here, and you'd know why the comment above is so angry.
}

void TexturePreview::paintGL()
{
    if(previewtexture < editorutils::textures.size()) {
        rotate+=2;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(backgroundtexture < editorutils::textures.size()) {
            box->render(skyshad,editorutils::textures[backgroundtexture]);
        }
        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), (float)256 / (float)256, 0.001f, 10000.0f);
        glm::mat4 view = glm::mat4(1.0f); //view is the **Camera**'s perspective
        view = glm::translate(view, glm::vec3(0.0, 0, -0.0));
        cub->rotation[0] = ((float)rotate/10 * glm::radians(50.0f))/2;
        cub->rotation[1] = ((float)rotate/10 * glm::radians(50.0f));
        cub->render(shad,editorutils::textures[previewtexture],projection,view);
    }
}

void TexturePreview::resizeGL(int w, int h)
{

}

void TexturePreview::mousePressEvent(QMouseEvent *event)
{
}

void TexturePreview::mouseMoveEvent(QMouseEvent *event)
{
}
