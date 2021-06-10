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
    beings.h \
    bullet.h \
    game.h \
    posrednik.h \
    shooting.h

DISTFILES += \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/Font/slkscreb.ttf \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/Dire Straits - Sultans of swing 8-bit.mp3 \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/bossmusic.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/explosion.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/gameover.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/laser.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/shot1.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/shot2.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/theme.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/snd/win.wav \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/HP.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/asteroid-small.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/asteroid.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/asteroidabum.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/boss.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/bossbullet.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/bossbum.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/crossed.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/enemy1.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/enemybum.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/graczbum.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/graczbum2.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/loading.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/menuback.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/moon.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/player1.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/player2.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/playerdown.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/playerdown2.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/playerup.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/playerup2.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/pulse1.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/pulse2.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/space2.png \
    ../build-Gra-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tex/space.png

