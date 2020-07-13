#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/Nut/src/release/ -lnut
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/Nut/src/debug/ -lnut
#else:unix: LIBS += -L$$OUT_PWD/../libs/Nut/src/ -lnut

#INCLUDEPATH += $$PWD/../libs/Nut/src
#DEPENDPATH += $$PWD/../libs/Nut/src

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/Nut/src/release/libnut.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/Nut/src/debug/libnut.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/Nut/src/release/nut.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/Nut/src/debug/nut.lib
#else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libs/Nut/src/libnut.a

#DEFINES += NUT_SHARED_POINTER


win32 {
        CONFIG(debug,debug|release):   LIBDIR = $$absolute_path($$OUT_PWD/../libs/Nut/src/debug)
        CONFIG(release,debug|release): LIBDIR = $$absolute_path($$OUT_PWD/../libs/Nut/src/release)
} else {
        LIBDIR = $$absolute_path($$OUT_PWD/../libs/Nut/src/)
}

LIBS += -L$$LIBDIR -lnut
INCLUDEPATH += $$PWD/../libs/Nut/src/

DEFINES += NUT_SHARED_POINTER
