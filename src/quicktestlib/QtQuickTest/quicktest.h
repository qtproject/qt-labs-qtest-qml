/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QUICKTEST_H
#define QUICKTEST_H

#include <QtQuickTest/quicktestglobal.h>
#include <QtGui/qwidget.h>
#ifdef QT_OPENGL_LIB
#include <QtOpenGL/qgl.h>
#endif

QT_BEGIN_NAMESPACE

typedef QWidget *(*quick_test_viewport_create)();

Q_QUICK_TEST_EXPORT int quick_test_main(int argc, char **argv, const char *name, quick_test_viewport_create createViewport, const char *sourceDir);

#ifdef QUICK_TEST_SOURCE_DIR

#define QUICK_TEST_MAIN(name) \
    int main(int argc, char **argv) \
    { \
        return quick_test_main(argc, argv, #name, 0, QUICK_TEST_SOURCE_DIR); \
    }

#define QUICK_TEST_OPENGL_MAIN(name) \
    static QWidget *name##_create_viewport() \
    { \
        return new QGLWidget(); \
    } \
    int main(int argc, char **argv) \
    { \
        return quick_test_main(argc, argv, #name, name##_create_viewport, QUICK_TEST_SOURCE_DIR); \
    }

#else

#define QUICK_TEST_MAIN(name) \
    int main(int argc, char **argv) \
    { \
        return quick_test_main(argc, argv, #name, 0, 0); \
    }

#define QUICK_TEST_OPENGL_MAIN(name) \
    static QWidget *name##_create_viewport() \
    { \
        return new QGLWidget(); \
    } \
    int main(int argc, char **argv) \
    { \
        return quick_test_main(argc, argv, #name, name##_create_viewport, 0); \
    }

#endif

QT_END_NAMESPACE

#endif
