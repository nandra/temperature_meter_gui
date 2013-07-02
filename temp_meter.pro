HEADERS += temperature.h \
    mainwindow.h
SOURCES += temperature.cpp \
    mainwindow.cpp \
    main.cpp
OTHER_FILES += temp_meter.pro
FORMS += mainwindow.ui
LIBS += -L/usr/local/lib -liqrf -L/usr/lib/i386-linux-gnu/ -lusb-1.0
