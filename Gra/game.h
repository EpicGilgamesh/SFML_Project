//#ifndef GAME_H
//#define GAME_H
//#include "posrednik.h"
//#include "beings.h"
//#include "bullet.h"
//#include "assets.h"
//class Game
//{
//    Texturesinit alltextures;
//    Soundbuffersinit allbuffers;
//    //RenderWindow window(VideoMode(800, 600), "Space ranger!", Style::Default);


//public:
//    Game()
//    {   ///init textures
//        this->loadtextures();
//        ///init sound buffers
//        this->loadsoundbuffers();
//        //Init text
//        font.loadFromFile("Font/slkscreb.ttf");
//        //UI init
//        scoreText.setFont(font);
//        scoreText.setCharacterSize(20);
//        scoreText.setFillColor(Color::White);
//        scoreText.setPosition(10.f, 10.f);

//        ///lose init
//        gameOverText.setFont(font);
//        gameOverText.setCharacterSize(30);
//        gameOverText.setFillColor(Color::Red);
//        gameOverText.setPosition(window.getSize().x / 2-150, window.getSize().y / 2-25);
//        gameOverText.setString("GAME OVER!");

//        //win init
//        gamewonText.setFont(font);
//        gamewonText.setCharacterSize(30);
//        gamewonText.setFillColor(Color::Cyan);
//        gamewonText.setPosition(window.getSize().x / 2-250, window.getSize().y / 2-25);
//        gamewonText.setString("#1 VICTORY ROYALE!");

//        //Menu init
//        menuText.setFont(font);
//        menuText.setCharacterSize(20);
//        menuText.setFillColor(Color::Blue);
//        menuText.setPosition(window.getSize().x / 2-200, window.getSize().y / 2+15);
//        menuText.setString(">PRESS ENTER TO START<");

//        menu1Text.setFont(font);
//        menu1Text.setCharacterSize(40);
//        menu1Text.setFillColor(Color::Yellow);
//        menu1Text.setPosition(window.getSize().x / 2-230, window.getSize().y / 2-50);
//        menu1Text.setString("SPACE RANGER");
//        moonsprite.setTexture(moontex);
//        menusprite.setTexture(menutex);
//        ///enemyhp init
//        eHpText.setFont(font);
//        eHpText.setCharacterSize(12);
//        eHpText.setFillColor(Color::White);
//        //Init textures

//        playerTex.loadFromFile("tex/player1.png");
//        playerTexUp.loadFromFile("tex/playerup.png");
//        playerTexDown.loadFromFile("tex/playerdown.png");
//        enemyTex.loadFromFile("tex/enemy1.png");
//        bossTex.loadFromFile("tex/boss.png");
//        bulletTex.loadFromFile("tex/pulse1.png");
//        bossbulletTex.loadFromFile("tex/bossbullet.png");
//        spacebacktex.loadFromFile("tex/space2.png");
//        moontex.loadFromFile("tex/moon.png");
//        menutex.loadFromFile("tex/menuback.png");
//        loadtex.loadFromFile("tex/loading.png");


//        ///Init background
//        spacebacksprite.setTexture(spacebacktex);///!

//        ///Init sound
//        themebuffer.loadFromFile("snd/theme.wav");
//        pulsebuffer.loadFromFile("snd/shot2.wav");
//        explosionbuffer.loadFromFile("snd/explosion.wav");
//        gameoverbuffer.loadFromFile("snd/gameover.wav");
//        bossbuffer.loadFromFile("snd/bossmusic.wav");
//        winbuffer.loadFromFile("snd/win.wav");
//        themesound.setBuffer(themebuffer);
//        pulsesound.setBuffer(pulsebuffer);
//        explosionsound.setBuffer(explosionbuffer);///!!
//        gameoversound.setBuffer(gameoverbuffer);
//        bosssound.setBuffer(bossbuffer);
//        winsound.setBuffer(winbuffer);

//            //Player init
//            int score = 0;
//            Player player(&playerTex);
//            int shootTimer = 20;
//            Text hpText;
//            hpText.setFont(font);
//            hpText.setCharacterSize(12);
//            hpText.setFillColor(Color::White);


//        //Enemy init
//            int enemySpawnTimer = 0;
//            // int enemyrotationTimer = 0;
//            std::vector<Enemy> enemies;


//            ///Boss init
//            std::vector<Boss> boss;
//            Boss boss1(&bossTex,window.getSize());
//            int bossshootTimer = 20;



//        /////////////////////////////////////
//        while (window.isOpen())
//        {
//            Event event;
//            while (window.pollEvent(event))
//            {
//                if (event.type == Event::Closed)
//                    window.close();
//            }
//            ///menu
//            if(start==0)
//            {
//                menusprite.setScale(0.4,0.4);
//                moonsprite.setScale(3,3);
//                moonsprite.setPosition(window.getSize().x/2-moonsprite.getGlobalBounds().width/2-10,window.getSize().y/2+100);
//                moonsprite.setTextureRect(sf::IntRect(0,moonanim, 48, 48));
//                moonanim+=48;
//                if( moonanim>=2880){ moonanim=0;}
//                window.draw(menusprite);
//                window.draw(moonsprite);

//                window.draw(menu1Text);
//                window.draw(menuText);
//                if(Keyboard::isKeyPressed(Keyboard::Enter))
//                { start=1;}
//            }
//            if(start==1)
//            {   window.clear(Color::Black);
//                loadsprite.setScale(22,22);
//                // loadsprite.setRotation(0.1f);
//                loadsprite.setPosition(window.getSize().x/2-loadsprite.getGlobalBounds().width/2,window.getSize().y/2-loadsprite.getGlobalBounds().height/2);
//                loadsprite.setTextureRect(sf::IntRect(0,loadanim, 32, 32));
//                loadanim+=32;
//                window.draw(loadsprite);
//                if( loadanim>=736){ loadanim=0; przejscie++;}
//                if(przejscie==6)
//                {start=2;}
//            }
//            if(start==2)    ///game
//            {   window.clear(Color::Black);

//                if ((player.HP > 0)&&(victory==0))
//                {
//                    this->playermoves(player,hpText);
//                    this->playercollision(player);
//                    this->playershoot(player,shootTimer);
//                    this->bulletsshoot(player,score,enemies,boss);
//                    this->bossshoot(boss1,bossshootTimer);
//                    this->bossbullets(player,boss1);
//                    this->enemyspawn(enemies,enemySpawnTimer);
//                    this->enemyingame(player,enemies);
//                    this->bossingame(boss,boss1,player);// mozna dac do srodka bossinit

//                    //UI Update
//                    scoreText.setString("Score: " + std::to_string(score));
//                }
//                this->backanim();
//                this->display(player,hpText,boss,boss1,enemies);
//                this->winorlose(player);

//            }
//            window.display();
//        }
//        //////////////////////////////////
//    }
//    void loadtextures()
//    {
//        this->alltextures.addTex(Textures::playerTex,"tex/player1.png");
//        this->alltextures.addTex(Textures::playerTexUp,"tex/playerup.png");
//        this->alltextures.addTex(Textures::playerTexDown,"tex/playerdown.png");
//        this->alltextures.addTex(Textures::enemyTex,"tex/enemy1.png");
//        this->alltextures.addTex(Textures::bossTex,"tex/boss.png");
//        this->alltextures.addTex(Textures::bulletTex,"tex/pulse1.png");
//        this->alltextures.addTex(Textures::bossbulletTex,"tex/bossbullet.png");
//        this->alltextures.addTex(Textures::spacebacktex,"tex/space2.png");
//        this->alltextures.addTex(Textures::moontex,"tex/moon.png");
//        this->alltextures.addTex(Textures::menutex,"tex/menuback.png");
//        this->alltextures.addTex(Textures::loadtex,"tex/loading.png");
//    }
//    void loadsoundbuffers()
//    {
//        this->allbuffers.addBuffer(Soundbuffers::themebuffer,"snd/theme.wav");
//        this->allbuffers.addBuffer(Soundbuffers::pulsebuffer,"snd/shot2.wav");
//        this->allbuffers.addBuffer(Soundbuffers::explosionbuffer,"snd/explosion.wav");
//        this->allbuffers.addBuffer(Soundbuffers::gameoverbuffer,"snd/gameover.wav");
//        this->allbuffers.addBuffer(Soundbuffers::bossbuffer,"snd/bossmusic.wav");
//        this->allbuffers.addBuffer(Soundbuffers:: winbuffer,"snd/win.wav");

//    }


//    void playermoves(Player player,Text hpText)
//    {
//        player.moves(playerTex,playerTexDown,playerTexUp);
//        hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
//        hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));
//    }
//    void playercollision(Player player)
//    {if (player.shape.getPosition().x <= 0) //Left
//            player.shape.setPosition(0.f, player.shape.getPosition().y);
//        if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width) //Right
//            player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
//        if (player.shape.getPosition().y <= 0) //Top
//            player.shape.setPosition(player.shape.getPosition().x, 0.f);
//        if (player.shape.getPosition().y >= window.getSize().y - player.shape.getGlobalBounds().height) //Bottom
//            player.shape.setPosition(player.shape.getPosition().x, window.getSize().y - player.shape.getGlobalBounds().height);}

//    void playershoot(Player player,int shootTimer)
//    {//Update Controls
//        if (shootTimer < 15)
//            shootTimer++;

//        if (Keyboard::isKeyPressed(Keyboard::Space) && shootTimer >= 15) //Shooting
//        {
//            player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
//            pulsesound.play();
//            shootTimer = 0; //reset timer

//        }}

//    void bulletsshoot(Player player,int score,std::vector<Enemy> enemies,std::vector<Boss> boss)
//    {
//        for (size_t i = 0; i < player.bullets.size(); i++)
//        {
//            //Move
//            player.bullets[i].shape.move(20.f, 0.f);
//            player.bullets[i].shape.setTextureRect(sf::IntRect(0,bulletanim, 63, 32));
//            bulletanim+=32;
//            if( bulletanim>=128){ bulletanim=0;}

//            //Out of window bounds
//            if (player.bullets[i].shape.getPosition().x > window.getSize().x)
//            {
//                player.bullets.erase(player.bullets.begin() + i);
//                break;
//            }


//            //Enemy collision
//            for (size_t k = 0; k < enemies.size(); k++)
//            {
//                if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
//                {
//                    if (enemies[k].HP <= 1)
//                    {
//                        score += enemies[k].HPMax;
//                        enemies.erase(enemies.begin() + k);
//                        explosionsound.play();
//                    }
//                    else
//                        enemies[k].HP--; //ENEMY TAKE DAMAGE

//                    player.bullets.erase(player.bullets.begin() + i);
//                    break;
//                }
//            }
//            //Boss collision&Win

//            for (size_t k = 0; k < boss.size(); k++)
//            {
//                if (player.bullets[i].shape.getGlobalBounds().intersects(boss[k].shape.getGlobalBounds()))
//                {
//                    if (boss[k].HP <= 1)
//                    {
//                        score += boss[k].HPMax;
//                        bosssound.stop();
//                        boss.erase(boss.begin() + k);
//                        explosionsound.play();
//                        victory=true;
//                    }
//                    else
//                        boss[k].HP--; //ENEMY TAKE DAMAGE

//                    player.bullets.erase(player.bullets.begin() + i);
//                    break;
//                }
//            }
//        }}

//    void bossshoot(Boss boss1,int bossshootTimer)
//    {
//        if (bossshootTimer < 50)
//            bossshootTimer++;
//        if ((bossexist==true) && (bossshootTimer >= 50)) //Shooting
//        {
//            boss1.bulletsboss.push_back(Bullet(&bossbulletTex, boss1.shape.getPosition()));
//            pulsesound.play();
//            bossshootTimer = 0; //reset timer

//        }
//    }
//    void bossbullets(Player player,Boss boss1)
//    {
//        for (size_t i = 0; i < boss1.bulletsboss.size(); i++)
//        {
//            //Move
//            boss1.bossx=(player.shape.getPosition().x-boss1.shape.getPosition().x)/(5*frames);
//            boss1.bossy=(player.shape.getPosition().y-boss1.shape.getPosition().y)/(5*frames);
//            boss1.bulletsboss[i].shape.move(boss1.bossx, boss1.bossy);
//            //boss1.bulletsboss[i].shape.move(-20.f, 0.f);
//            boss1.bulletsboss[i].shape.setTextureRect(sf::IntRect(0,bossbulletanim, 604, 64));
//            bossbulletanim+=64;
//            if( bossbulletanim>=3840){ bossbulletanim=0;}

//            //Out of window bounds
//            if (boss1.bulletsboss[i].shape.getPosition().x < 0)
//            {
//                boss1.bulletsboss.erase(boss1.bulletsboss.begin() + i);
//                break;
//            }


//            //player collision

//            if (boss1.bulletsboss[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
//            {
//                player.HP--; //PLAYER TAKE DAMAGE
//                boss1.bulletsboss.erase(boss1.bulletsboss.begin() + i);
//                break;
//            }


//        }
//    }
//    void enemyspawn(std::vector<Enemy> enemies,int enemySpawnTimer)
//    {
//        //Enemy
//        if (enemySpawnTimer < 25)
//            enemySpawnTimer++;

//        //enemy spawn
//        if ((bossexist==false) &&(enemySpawnTimer >= 25))
//        {
//            enemies.push_back(Enemy(&enemyTex, window.getSize()));
//            enemySpawnTimer = 0; //reset timer

//        }
//    }


//    void enemyingame(Player player,std::vector<Enemy> enemies)
//    {
//        for (size_t i = 0; i < enemies.size(); i++)
//        {

//            enemies[i].shape.move(-6.f, 0.f);
//            enemies[i].shape.setTextureRect(sf::IntRect(0,enemyrotation , 32, 32));
//            enemyrotation+=32;
//            if( enemyrotation>=160){ enemyrotation=0;}

//            if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
//            {
//                enemies.erase(enemies.begin() + i);
//                break;
//            }

//            if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
//            {
//                enemies.erase(enemies.begin() + i);
//                explosionsound.play();
//                player.HP--; // PLAYER TAKE DAMAGE
//                break;
//            }
//        }
//    }
//    void bossingame(std::vector<Boss> boss,Boss boss1,Player player)
//    {
//        //Big szef
//        if (!initialized1) {
//            initialized1 = true;
//            themesound.stop();
//            bosssound.play();
//            boss.emplace_back(boss1);

//        }


//        for (size_t i = 0; i < boss.size(); i++)
//        {
//            if (boss[i].shape.getPosition().x <= 100+ boss[i].shape.getGlobalBounds().width)
//            {
//                boss[i].shape.move(0.f, 0.f);
//                bossexist=1;

//            }
//            else{boss[i].shape.move(-3.f, 0.f); }

//            boss[i].shape.setTextureRect(sf::IntRect(0,bossrotation , 329, 160));
//            bossrotation+=160;
//            if( bossrotation>=480){ bossrotation=0;}

//            if (boss[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
//            {

//                player.HP--; // PLAYER TAKE DAMAGE
//                break;
//            }
//        }
//    }


//    void backanim()
//    {
//        ////window anim
//        spacebacksprite.setTextureRect(sf::IntRect(mapanim, 0, 800,600));
//        mapanim+=10;
//        if( mapanim>=800){ mapanim=200;}
//    }
//    void display(Player player, Text hpText,std::vector<Boss> boss,Boss boss1,std::vector<Enemy> enemies)
//    {
//        //UI
//        window.draw(scoreText);
//        window.draw(hpText);
//        //Draw ===================================================================== DRAW
//        window.clear();

//        window.draw(spacebacksprite);
//        //player
//        window.draw(player.shape);

//        //Bullets
//        for (size_t i = 0; i < player.bullets.size(); i++)
//        {
//            window.draw(player.bullets[i].shape);
//        }
//        //Bullets
//        for (size_t i = 0; i < boss1.bulletsboss.size(); i++)
//        {
//            window.draw(boss1.bulletsboss[i].shape);
//        }

//        //enemy
//        for (size_t i = 0; i < enemies.size(); i++)
//        {
//            eHpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
//            eHpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
//            window.draw(eHpText);
//            window.draw(enemies[i].shape);
//        }
//        //boss

//        for (size_t i = 0; i < boss.size(); i++)
//        {
//            eHpText.setString(std::to_string(boss[i].HP) + "/" + std::to_string(boss[i].HPMax));
//            eHpText.setPosition(boss[i].shape.getPosition().x+boss[i].shape.getGlobalBounds().width/2, boss[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
//            window.draw(eHpText);
//            window.draw(boss[i].shape);
//        }

//    }



//    void winorlose(Player player)
//    {
//        if (player.HP <= 0)
//        {
//            if (!initialized) {
//                initialized = true;
//                gameoversound.play();
//            }

//            window.draw(gameOverText);
//        }
//        if (victory==true)
//        {
//            if (!initialized) {
//                initialized = true;
//                winsound.play();
//            }

//            window.draw(gamewonText);
//        }
//    }




//};


//#endif // GAME_H

