QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += opengl

CONFIG += c++17

LIBS += -lGLEW -lassimp
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Documents/GitHub/SDLTrisRewritten/src/light.cpp \
    TexturePreview.cpp \
    editorutils.cpp \
    main.cpp \
    mainwindow.cpp \
    previewrenderer.cpp \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/texture.cpp \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/shader.cpp \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/utils.cpp \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/cube.cpp \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/skybox.cpp \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/mesh.cpp \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/stbi_image.c \
    wizard.cpp



HEADERS += \
    ../Documents/GitHub/SDLTrisRewritten/src/camera.h \
    ../Documents/GitHub/SDLTrisRewritten/src/object.h \
    editorutils.h \
    mainwindow.h \
    previewrenderer.h \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/texture.h \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/shader.h \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/utils.h \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/cube.h \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/skybox.h \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/mesh.h \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/src/stb_image.h \
    texturepreview.h \
    wizard.h

INCLUDEPATH += \
    /home/knucklesfan/Documents/GitHub/SDLTrisRewritten/include/

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
