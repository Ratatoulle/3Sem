TEMPLATE = app
TARGET = player

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

INCLUDEPATH += \
    src/

HEADERS = \
    src/player.h \
    src/playercontrols.h \
    src/playlistmodel.h \
    src/videowidget.h
SOURCES = main.cpp \
    src/cpp/player.cpp \
    src/cpp/playercontrols.cpp \
    src/cpp/playlistmodel.cpp \
    src/cpp/videowidget.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/player
INSTALLS += target
