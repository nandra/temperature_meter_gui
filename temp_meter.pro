HEADERS += iqrf_core/spi.h \
    iqrf_core/lusb.h \
    iqrf_core/iqrf_dev.h \
    ui_mainwindow.h \
    temperature.h \
    mainwindow.h
SOURCES += iqrf_core/spi.cpp \
    iqrf_core/lusb.cpp \
    iqrf_core/iqrf_dev.cpp \
    temperature.cpp \
    mainwindow.cpp \
    main.cpp
OTHER_FILES += temp_meter.pro
FORMS += mainwindow.ui
