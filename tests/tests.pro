include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra #-Werror
QMAKE_CFLAGS += -Wall -Wextra #-Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     save_test.h \
               p1_test.h \
               ple_test.h \
               showalphaonly_test.h \
               m_test.h \
               ../app/common.h \
               ../app/text/text.h \
               ../app/text/_text.h


SOURCES +=     main.cpp \
    ../app/load.cpp \
    ../app/show.cpp \
    ../app/p1.cpp \
    ../app/ple.cpp \
    ../app/save.cpp \
    ../app/showalphaonly.cpp \
    ../app/text/m.cpp \
    ../app/text/process_forward.cpp \
    ../app/text/remove_all.cpp \
    ../app/text/append_line.cpp \
    ../app/text/create_text.cpp

INCLUDEPATH += ../app
