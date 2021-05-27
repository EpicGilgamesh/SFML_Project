TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
 INCLUDEPATH += "C:/Qt/SFML-2.5.1/include"
 LIBS += -L"C:/Qt/SFML-2.5.1/lib"
 CONFIG(debug, debug|release){
     LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
 } else {
     LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
 }



HEADERS += \
    assets.h \
    background.h \
    bullet.h \
    enemy.h \
    player.h \
    posrednik.h

DISTFILES += \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/Font/slkscreb.ttf \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/Dire Straits - Sultans of swing 8-bit.mp3 \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/enemy1.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/moon.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/player1.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/playerdown.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/playerup.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/pulse1.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/space.png

