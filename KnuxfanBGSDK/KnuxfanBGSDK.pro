QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += opengl

CONFIG += c++17

LIBS += -lGLEW -lassimp
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/light.cpp \
    TexturePreview.cpp \
    editorutils.cpp \
    main.cpp \
    mainwindow.cpp \
    previewcamera.cpp \
    previewrenderer.cpp \
    ../src/texture.cpp \
    ../src/shader.cpp \
    ../src/utils.cpp \
    ../src/cube.cpp \
    ../src/skybox.cpp \
    ../src/mesh.cpp \
    ../src/stbi_image.c \
    wizard.cpp



HEADERS += \
    ../src/object.h \
    editorutils.h \
    mainwindow.h \
    previewcamera.h \
    previewrenderer.h \
    ../src/texture.h \
    ../src/shader.h \
    ../src/utils.h \
    ../src/cube.h \
    ../src/skybox.h \
    ../src/mesh.h \
    ../src/stb_image.h \
    texturepreview.h \
    wizard.h

INCLUDEPATH += \
    ../include/

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
