#include "posrednik.h"
#include "beings.h"
#include "bullet.h"
#include "assets.h"
#include "shooting.h"


///TO DO
/// virtualisation(1object methods-bullets), new weapons if, fix hitboxes,death explosions, hit asteroid and enemy at once


int main()
{
    srand(time(NULL));
    window.setFramerateLimit(frames);

    //Init text
    font.loadFromFile("Font/slkscreb.ttf");

    //Init textures
    Texturesinit alltextures;
    alltextures.addTex(Textures::playerTex,"tex/player1.png");
    alltextures.addTex(Textures::playerTexUp,"tex/playerup.png");
    alltextures.addTex(Textures::playerTexDown,"tex/playerdown.png");
    alltextures.addTex(Textures::playerTex2,"tex/player2.png");
    alltextures.addTex(Textures::playerTexUp2,"tex/playerup2.png");
    alltextures.addTex(Textures::playerTexDown2,"tex/playerdown2.png");
    alltextures.addTex(Textures::enemyTex,"tex/enemy1.png");
    alltextures.addTex(Textures::bossTex,"tex/boss.png");
    alltextures.addTex(Textures::bulletTex,"tex/pulse1.png");
    alltextures.addTex(Textures::bulletTex2,"tex/pulse2.png");
    alltextures.addTex(Textures::bossbulletTex,"tex/bossbullet.png");
    alltextures.addTex(Textures::asteroidTex,"tex/asteroid.png");
    alltextures.addTex(Textures::asteroid_smallTex,"tex/asteroid-small.png");
    alltextures.addTex(Textures::asteroidexpTex,"tex/asteroidabum.png");
    alltextures.addTex(Textures::bossexpTex,"tex/bossbum.png");
    alltextures.addTex(Textures::enemyexpTex,"tex/enemybum.png");
    alltextures.addTex(Textures::graczexpTex,"tex/graczbum2.png");
    alltextures.addTex(Textures::hitexpTex,"tex/graczbum.png");
    spacebacktex.loadFromFile("tex/space2.png");
    moontex.loadFromFile("tex/moon.png");
    menutex.loadFromFile("tex/menuback.png");
    loadtex.loadFromFile("tex/loading.png");

    ///Init background
    spacebacktex.loadFromFile("tex/space2.png");
    spacebacksprite.setTexture(spacebacktex);

    ///Init sound
    themebuffer.loadFromFile("snd/theme.wav");
    pulsebuffer.loadFromFile("snd/shot2.wav");
    pulsebuffer2.loadFromFile("snd/shot1.wav");
    explosionbuffer.loadFromFile("snd/explosion.wav");
    gameoverbuffer.loadFromFile("snd/gameover.wav");
    bossbuffer.loadFromFile("snd/bossmusic.wav");
    winbuffer.loadFromFile("snd/win.wav");
    laserbuffer.loadFromFile("snd/laser.wav");
    themesound.setBuffer(themebuffer);
    pulsesound.setBuffer(pulsebuffer);
    pulsesound2.setBuffer(pulsebuffer2);
    explosionsound.setBuffer(explosionbuffer);
    gameoversound.setBuffer(gameoverbuffer);
    bosssound.setBuffer(bossbuffer);
    winsound.setBuffer(winbuffer);
    lasersound.setBuffer(laserbuffer);


    //UI init
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(10.f, 10.f);

    ///lose init
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(window.getSize().x / 2-150, window.getSize().y / 2-25);
    gameOverText.setString("GAME OVER!");

    //win init
    gamewonText.setFont(font);
    gamewonText.setCharacterSize(30);
    gamewonText.setFillColor(Color::Cyan);
    gamewonText.setPosition(window.getSize().x / 2-250, window.getSize().y / 2-25);
    gamewonText.setString("#1 VICTORY ROYALE!");

    //Menu init
    menuText.setFont(font);
    menuText.setCharacterSize(20);
    menuText.setFillColor(Color::Blue);
    menuText.setPosition(window.getSize().x / 2-200, window.getSize().y / 2+15);
    menuText.setString(">PRESS ENTER TO START<");

    menu1Text.setFont(font);
    menu1Text.setCharacterSize(40);
    menu1Text.setFillColor(Color::Yellow);
    menu1Text.setPosition(window.getSize().x / 2-230, window.getSize().y / 2-50);
    menu1Text.setString("SPACE RANGER");
    moonsprite.setTexture(moontex);
    menusprite.setTexture(menutex);

    player2Text.setFont(font);
    player2Text.setCharacterSize(20);
    player2Text.setFillColor(Color::Magenta);
    player2Text.setPosition(window.getSize().x / 2-240, window.getSize().y / 2+40);
    player2Text.setString(">PRESS SPACE TO PLAY CO-OP<");



    //Loading init

    loadsprite.setTexture(loadtex);

    //Players init

    Player player(alltextures.GetTexture(Textures::playerTex));
    Player player2(alltextures.GetTexture(Textures::playerTex2));


    //Enemy init
    std::vector<Enemy> enemies;

    ///Boss init
    std::vector<Boss> boss;
    Boss boss1(alltextures.GetTexture(Textures::bossTex),window.getSize());

    //Asteroids init
    std::vector<Asteroid> asteroids;

    //Death init
   std::vector<Deathanim> enemiesdeath;

    themesound.play();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        ///menu
        if(start==0)
        {
            menusprite.setScale(0.4,0.4);
            moonsprite.setScale(3,3);
            moonsprite.setPosition(window.getSize().x/2-moonsprite.getGlobalBounds().width/2-10,window.getSize().y/2+100);
            moonsprite.setTextureRect(sf::IntRect(0,moonanim, 48, 48));
            moonanim+=48;
            if( moonanim>=2880){ moonanim=0;}
            window.draw(menusprite);
            window.draw(moonsprite);
            window.draw(menu1Text);
            window.draw(menuText);
            window.draw(player2Text);
            if(Keyboard::isKeyPressed(Keyboard::Enter))
            { start=1;}
            else if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                start=1;
                gracz2=1;

            }
        }
        if(start==1)
        {   window.clear(Color::Black);
            loadsprite.setScale(22,22);
            loadsprite.setPosition(window.getSize().x/2-loadsprite.getGlobalBounds().width/2,window.getSize().y/2-loadsprite.getGlobalBounds().height/2);
            loadsprite.setTextureRect(sf::IntRect(0,loadanim, 32, 32));
            loadanim+=32;
            window.draw(loadsprite);
            if( loadanim>=736){ loadanim=0; przejscie++;}
            if(przejscie==2)
            {start=2;}
        }
        if(start==2)    ///game
        {   window.clear(Color::Black);

            if (((gracz1==1)||(gracz2==1))&&(victory==false))
            {
                if(gracz1){
                    player.moves(alltextures.GetTexture(Textures::playerTex),alltextures.GetTexture(Textures::playerTexDown),alltextures.GetTexture(Textures::playerTexUp));

                    //Collision with window
                    player.collision(window.getSize());
                    //Update Controls
                    if (player.showshoottime() < 15)
                        player.shoottimeincrease();

                    if (Keyboard::isKeyPressed(Keyboard::Space) && player.showshoottime() >= 15) //Shooting
                    {
                        player.bullets.push_back(Bullet(alltextures.GetTexture(Textures::bulletTex), player.shape.getPosition()));
                        pulsesound.play();
                        player.shoottimezero(); //reset timer

                    }


                    //Bullets
                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(20.f, 0.f);
                        player.bullets[i].shape.setTextureRect(sf::IntRect(0,bulletanim, 63, 32));
                        bulletanim+=32;
                        if( bulletanim>=128){ bulletanim=0;}

                        //Out of window bounds
                        if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }


                        //Enemy collision
                        for (size_t k = 0; k < enemies.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                            {
                                if (enemies[k].showHP() <= 1)
                                {


                                    enemiesdeath.push_back(Deathanim(alltextures.GetTexture(Textures::enemyexpTex), enemies[k].shape.getPosition()));

                                    score += enemies[k].showmaxHP();
                                    bossloading++;
                                    explosionsound.play();
                                    enemies.erase(enemies.begin() + k);
                                }
                                else
                                    enemies[k].damage(); //ENEMY TAKE DAMAGE

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }



                           // enemies[k].death(alltextures.GetTexture(Textures::enemyexpTex), enemies[k].shape.getPosition(),explosionsound);
                           // score += enemies[k].showmaxHP();
                           //enemies.erase(enemies.begin() + k);
                           // explosionsound.play();
                          // bossloading++;



                        }
                        //Boss collision&Win

                        for (size_t k = 0; k < boss.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(boss[k].shape.getGlobalBounds()))
                            {
                                if (boss[k].showHP() <= 1)
                                {
                                    score += boss[k].showmaxHP();
                                    bosssound.stop();
                                    boss.erase(boss.begin() + k);
                                    explosionsound.play();
                                    victory=true;
                                }
                                else
                                    boss[k].damage(); //ENEMY TAKE DAMAGE

                                //player.bullets.erase(player.bullets.begin() + i);
                                player.bullets[i].gone=1;
                                break;
                            }


                        }
                        ///Asteroid collision
                        for (size_t k = 0; k < asteroids.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(asteroids[k].shape.getGlobalBounds()))
                            {
                                if (asteroids[k].showHP() <= 1)
                                {
                                    score += asteroids[k].showmaxHP();
                                    asteroids.erase(asteroids.begin() + k);
                                    explosionsound.play();
                                    bossloading++;
                                    asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroid_smallTex), window.getSize()));
                                   /* astx=rand() % 5 + 1;
                                    asty=rand() % 4 + 1;
                                    asteroids[k+1].shape.move(astx,asty);*/
                                    asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroid_smallTex), window.getSize()));
                                   // asteroids[k+2].shape.move(-astx,-asty);
                                }
                                else
                                    asteroids[k].damage(); //ENEMY TAKE DAMAGE

                                //player.bullets.erase(player.bullets.begin() + i);
                                player.bullets[i].gone=1;
                                break;
                            }
                        }
                            if(player.bullets[i].gone==1)
                                player.bullets.erase(player.bullets.begin() + i);
                    }}
                //Boss shooting
                if (boss1.showshoottime() < 50)
                    boss1.shoottimeincrease();
                if ((bossexist==true) && (boss1.showshoottime() >= 50)) //Shooting
                {
                    boss1.bulletsboss.push_back(Bullet(alltextures.GetTexture(Textures::bossbulletTex), v1));
                    lasersound.play();
                    boss1.shoottimezero(); //reset timer

                }
                //BossBullets
                for (size_t i = 0; i < boss1.bulletsboss.size(); i++)
                {
                    //Move
                    if(gracz1==1)
                    {boss1.bossx=(player.shape.getPosition().x-boss1.shape.getPosition().x)/(5*frames);
                        boss1.bossy=(player.shape.getPosition().y-boss1.shape.getPosition().y)/(5*frames);
                        boss1.bulletsboss[i].shape.move(boss1.bossx, boss1.bossy);

                    }
                    if(gracz1==0)
                    {
                        boss1.bossx=(player2.shape.getPosition().x-boss1.shape.getPosition().x)/(5*frames);
                        boss1.bossy=(player2.shape.getPosition().y-boss1.shape.getPosition().y)/(5*frames);
                        boss1.bulletsboss[i].shape.move(boss1.bossx, boss1.bossy);
                    }

                    boss1.bulletsboss[i].shape.setTextureRect(sf::IntRect(0,bossbulletanim, 604, 64));
                    bossbulletanim+=64;
                    if( bossbulletanim>=3840){ bossbulletanim=0;}

                    //Out of window bounds
                    if (boss1.bulletsboss[i].shape.getPosition().x < 0)
                    {
                        boss1.bulletsboss.erase(boss1.bulletsboss.begin() + i);
                        break;
                    }


                    //player collision
                    if(gracz1){
                        if (boss1.bulletsboss[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            player.damage(); //PLAYER TAKE DAMAGE
                            boss1.bulletsboss.erase(boss1.bulletsboss.begin() + i);
                            break;
                        }}
                    if(gracz2)
                    {
                        if (boss1.bulletsboss[i].shape.getGlobalBounds().intersects(player2.shape.getGlobalBounds()))
                        {
                            player2.damage(); //PLAYER TAKE DAMAGE
                            boss1.bulletsboss.erase(boss1.bulletsboss.begin() + i);
                            break;
                        }
                    }


                }
                ///Asteroids spawn
                if (asteroidSpawnTimer < 25)
                    asteroidSpawnTimer++;
                if(asteroidSpawnTimer >= 25)
                {
                    asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroidTex), window.getSize()));
                    asteroidSpawnTimer = 0; //reset timer

                }
                for (size_t i = 0; i < asteroids.size(); i++)
                {
                    asteroids[i].moves();

                    if ((asteroids[i].shape.getPosition().x <= 0- asteroids[i].shape.getGlobalBounds().width)||
                            //(asteroids[i].shape.getPosition().x >= windowW - asteroids[i].shape.getGlobalBounds().width)||
                            (asteroids[i].shape.getPosition().y <= 0)||
                            (asteroids[i].shape.getPosition().y >= windowH - asteroids[i].shape.getGlobalBounds().height))
                    {
                        asteroids.erase(asteroids.begin() + i);
                        break;
                    }
                    if(gracz1)
                    {
                        if (asteroids[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            asteroids.erase(asteroids.begin() + i);
                            explosionsound.play();
                            player.damage(); // PLAYER TAKE DAMAGE
                            break;
                        }}
                    if(gracz2)
                    {
                        if (asteroids[i].shape.getGlobalBounds().intersects(player2.shape.getGlobalBounds()))
                        {
                            asteroids.erase(asteroids.begin() + i);
                            explosionsound.play();
                            player2.damage(); // PLAYER2 TAKE DAMAGE
                            break;
                        }
                    }
                }



                //Enemy
                if (enemySpawnTimer < 25)
                    enemySpawnTimer++;

                //enemy spawn
                if ((bossexist==false) &&(enemySpawnTimer >= 25))
                {
                    enemies.push_back(Enemy(alltextures.GetTexture(Textures::enemyTex), window.getSize()));
                    enemySpawnTimer = 0; //reset timer

                }

                for (size_t i = 0; i < enemies.size(); i++)
                {
                    enemies[i].moves();

                    if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
                    {
                        enemies.erase(enemies.begin() + i);
                        break;
                    }
                    if(gracz1)
                    {
                        if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemies.erase(enemies.begin() + i);
                            explosionsound.play();
                            player.damage(); // PLAYER TAKE DAMAGE
                            break;
                        }}
                    if(gracz2)
                    {
                        if (enemies[i].shape.getGlobalBounds().intersects(player2.shape.getGlobalBounds()))
                        {
                            enemies.erase(enemies.begin() + i);
                            explosionsound.play();
                            player2.damage(); // PLAYER2 TAKE DAMAGE
                            break;
                        }
                    }
                }
                //Big szef
                if(bossloading>50){
                    if (!initialized1) {
                        initialized1 = true;
                        themesound.stop();
                        bosssound.play();
                        boss.emplace_back(boss1);

                    }}


                for (size_t i = 0; i < boss.size(); i++)
                {
                    if (boss[i].shape.getPosition().x <= 150+ boss[i].shape.getGlobalBounds().width)
                    {
                        boss[i].shape.move(0.f, 0.f);
                        bossexist=1;

                    }
                    else{boss[i].shape.move(-3.f, 0.f); }

                    boss[i].shape.setTextureRect(sf::IntRect(0,bossrotation , 329, 160));
                    bossrotation+=160;
                    if( bossrotation>=480){ bossrotation=0;}
                    if(gracz1)
                    { if (boss[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {

                            player.damage(); // PLAYER TAKE DAMAGE
                            break;
                        }}
                    if(gracz2)
                    {if (boss[i].shape.getGlobalBounds().intersects(player2.shape.getGlobalBounds()))
                        {

                            player2.damage(); // PLAYER TAKE DAMAGE
                            break;
                        }}
                }
                ///PLAYER2
                if(gracz2)
                {
                    player2.moves2(alltextures.GetTexture(Textures::playerTex2),alltextures.GetTexture(Textures::playerTexDown2),alltextures.GetTexture(Textures::playerTexUp2));
                    player2.collision(window.getSize());
                    if (player2.showshoottime() < 15)
                        player2.shoottimeincrease();

                    if (Keyboard::isKeyPressed(Keyboard::RShift) && player2.showshoottime() >= 15) //Shooting
                    {
                        player2.bullets.push_back(Bullet(alltextures.GetTexture(Textures::bulletTex2), player2.shape.getPosition()));
                        pulsesound2.play();
                        player2.shoottimezero(); //reset timer

                    }
                    //Bullets
                    for (size_t i = 0; i < player2.bullets.size(); i++)
                    {
                        //Move
                        player2.bullets[i].shape.move(20.f, 0.f);
                        player2.bullets[i].shape.setTextureRect(sf::IntRect(0,bulletanim2, 63, 32));
                        bulletanim2+=32;
                        if( bulletanim2>=128){ bulletanim2=0;}

                        //Out of window bounds
                        if (player2.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player2.bullets.erase(player2.bullets.begin() + i);
                            break;
                        }


                        //Enemy collision
                        for (size_t k = 0; k < enemies.size(); k++)
                        {
                            if (player2.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                            {
                                if (enemies[k].showHP() <= 1)
                                {
                                    score += enemies[k].showmaxHP();
                                    //enemies[k].dead=1;
                                    enemies.erase(enemies.begin() + k);
                                    explosionsound.play();
                                    bossloading++;
                                }
                                else
                                    enemies[k].damage(); //ENEMY TAKE DAMAGE

                                //player2.bullets.erase(player2.bullets.begin() + i);
                                player2.bullets[i].gone=1;
                                break;
                            }
                        }
                        //Asteroid collision
                        for (size_t k = 0; k < asteroids.size(); k++)
                        {
                            if (player2.bullets[i].shape.getGlobalBounds().intersects(asteroids[k].shape.getGlobalBounds()))
                            {
                                if (asteroids[k].showHP() <= 1)
                                {
                                    score += asteroids[k].showmaxHP();
                                    //asteroids[k].dead=1;
                                    asteroids.erase(asteroids.begin() + k);
                                    explosionsound.play();
                                    bossloading++;
                                    asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroid_smallTex), window.getSize()));
//                                    astx=rand() % 5 + 1;
//                                    asty=rand() % 4 + 1;
                                    asteroids[k+1].shape.move(astx,asty);
                                    asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroid_smallTex), window.getSize()));
                                  //  asteroids[k+2].shape.move(-astx,-asty);
                                }
                                else
                                    asteroids[k].damage(); //ENEMY TAKE DAMAGE

                               // player2.bullets.erase(player2.bullets.begin() + i);
                                player2.bullets[i].gone=1;
                                break;
                            }
                        }
                        //Boss collision&Win

                        for (size_t k = 0; k < boss.size(); k++)
                        {
                            if (player2.bullets[i].shape.getGlobalBounds().intersects(boss[k].shape.getGlobalBounds()))
                            {
                                if (boss[k].showHP() <= 1)
                                {
                                    score += boss[k].showmaxHP();
                                    bosssound.stop();
                                    boss.erase(boss.begin() + k);
                                    explosionsound.play();
                                    victory=true;
                                }
                                else
                                    boss[k].damage(); //ENEMY TAKE DAMAGE

                               // player2.bullets.erase(player2.bullets.begin() + i);
                                player2.bullets[i].gone=1;
                                break;
                            }


                        }
                        if(player2.bullets[i].gone==1)
                             player2.bullets.erase(player2.bullets.begin() + i);

                    }


                }


                if(player.showHP()<=0)
                {   gracz1=0;

                   explosionsound.play();



            }

                if(player2.showHP()<=0)
                {
                    gracz2=0;
                    explosionsound.play();

                }



                //UI Update
                scoreText.setString("Score: " + std::to_string(score));
            }
            ////window anim
            spacebacksprite.setTextureRect(sf::IntRect(mapanim, 0, 800,600));
            mapanim+=10;
            if( mapanim>=800){ mapanim=200;}

            ///Death anim
            for (size_t i = 0; i < enemiesdeath.size(); i++){
                 enemiesdeath[i].shape.setTextureRect(sf::IntRect(22,enemydeathanim, 50,50));
                   enemydeathanim+=400;

                   if( enemydeathanim>=6500){
                       enemydeathanim=22;
                      enemiesdeath.erase(enemiesdeath.begin() + i);


                   break;
                   }}


            //Draw ===================================================================== DRAW
            window.clear();

            window.draw(spacebacksprite);
            //players
            if(gracz1){
                player.display();
                //Bullets
                for (size_t i = 0; i < player.bullets.size(); i++)
                {
                    window.draw(player.bullets[i].shape);
                }
            }


            if(gracz2)
            { player2.display();
                for (size_t i = 0; i < player2.bullets.size(); i++)
                {
                    window.draw(player2.bullets[i].shape);
                }
            }






            for (size_t i = 0; i < boss1.bulletsboss.size(); i++)
            {
                window.draw(boss1.bulletsboss[i].shape);
            }

            //enemy

            for (size_t i = 0; i < enemies.size(); i++)
            {
                enemies[i].display();
                /*for (size_t k = 0; k < enemies[i].death.size(); k++)
                {
                    window.draw(enemies[i].death[k].shape);
                }*/
            }

            //Asteroids

            for (size_t i = 0; i < asteroids.size(); i++)
            {
                //asteroids[i].display();
                window.draw(asteroids[i].shape);
            }
            //Death
            for (size_t k = 0; k < enemiesdeath.size(); k++)
            {
                window.draw(enemiesdeath[k].shape);
            }

            //boss


            for (size_t i = 0; i < boss.size(); i++)
            {
                boss[i].display();
            }

            //UI
            window.draw(scoreText);


            if (((gracz1==0)&&(gracz2==0)))
            {
                if (!initialized) {
                    initialized = true;
                    gameoversound.play();
                }
                window.draw(gameOverText);
            }
            if (victory==true)
            {
                if (!initialized) {
                    initialized = true;
                    winsound.play();
                }
                window.draw(gamewonText);
            }

        }
        window.display();
    }


}
