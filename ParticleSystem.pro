TEMPLATE = app
TARGET = cube
CONFIG += debug
CONFIG += console c++11
INCLUDEPATH += . /usr/include packages/obj-0.1

OBJECTS_DIR = obj
LIBS += -F/Library/Frameworks -framework SDL2
LIBS += -F/Library/Frameworks -framework SDL2_image
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/SDL2
INCLUDEPATH += /Library/Frameworks/SDL2_image.framework/Headers

INCLUDEPATH +=$$PWD/include
INCLUDEPATH +=$$PWD/GLFunctionsLib/include
LIBS += -L $$PWD/GLFunctionsLib/lib -lGLFunctionsLib

SOURCES += src/main.cpp \
    src/scene.cpp \
    src/particle.cpp \
    GLFunctionsLib/src/GLFunctions.cpp \
    GLFunctionsLib/src/Mat4.cpp \
    GLFunctionsLib/src/Vec4.cpp \
    src/particlesystem.cpp

HEADERS += \
    src/scene.h \
    src/particle.h \
    GLFunctionsLib/include/GLFunctions.h \
    GLFunctionsLib/include/Mat4.h \
    GLFunctionsLib/include/Vec4.h \
    src/particlesystem.h

DISTFILES += \
    README.md \
    Doxyfile.txt
