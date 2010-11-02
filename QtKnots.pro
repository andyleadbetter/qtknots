# Add more folders to ship with the application, here
folder_01.source = ./res
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve Qml modules in Creator's code model
QML_IMPORT_PATH =

# Avoid auto screen rotation
#DEFINES += ORIENTATIONLOCK

# Needs to be defined for Symbian
#DEFINES += NETWORKACCESS

symbian:TARGET.UID3 = 0xEB530529

# Define QMLJSDEBUGGER to allow debugging of QML
# (This might significantly increase build time)
#DEFINES += QMLJSDEBUGGER

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    knots.cpp \
    profile.cpp \
    saxprofilehandler.cpp \
    knotsdeclarative.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    knots.h \
    profile.h \
    saxprofilehandler.h \
    knotsdeclarative.h

QT           += xml network
