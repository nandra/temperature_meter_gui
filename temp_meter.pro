HEADERS += ui_mainwindow.h \
    temperature.h \
    mainwindow.h
SOURCES += temperature.cpp \
    mainwindow.cpp \
    main.cpp
OTHER_FILES += temp_meter.pro
FORMS += mainwindow.ui
LIBS += -L/usr/local/lib -liqrf -L/usr/lib -lusb
