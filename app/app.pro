TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += \
    load.cpp \
    show.cpp \
    p1.cpp \
    ple.cpp \
    save.cpp \
    showalphaonly.cpp \
    text/m.cpp \
    text/process_forward.cpp \
    text/remove_all.cpp \
    text/append_line.cpp \
    text/create_text.cpp \
    editor.cpp \




HEADERS += \
    text/text.h \
    text/_text.h \
    common.h \

QMAKE_CFLAGS += -Wall -Wextra #-Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
