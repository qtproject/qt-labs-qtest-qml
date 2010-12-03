TEMPLATE = lib
TARGET  = qmltestplugin
CONFIG += qt plugin

symbian {
    CONFIG += epocallowdlldata
    contains(QT_EDITION, OpenSource) {
        TARGET.CAPABILITY = LocalServices NetworkServices ReadUserData UserEnvironment WriteUserData
    } else {
        TARGET.CAPABILITY = All -Tcb
    }
}

QT += declarative

SOURCES += main.cpp
HEADERS +=

qdeclarativesources.files += \
    qmldir \
    TestCase.qml \
    testlogger.js

qdeclarativesources.path += $$[QT_INSTALL_IMPORTS]/QtTest
target.path += $$[QT_INSTALL_IMPORTS]/QtTest
INSTALLS += qdeclarativesources target

include(../../quicktestlib/quicktestlib_dep.pri)