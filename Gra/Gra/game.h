#ifndef GAME_H
#define GAME_H
#include "posrednik.h"
#include "beings.h"
#include "bullet.h"
#include "assets.h"

//variables:
///window
#define windowH 600
#define windowW 800
#define frames 25
class Game
{

    RenderWindow window;
    ///animations
    float enemyrotation;
    float bossrotation;
    float bulletanim;
    float bulletanim2;
    float bossbulletanim;
    float enemydeathanim;
    float bossdeathanim;
    float playerdeathanim;
    float hitanim;
    float asteroiddeathanim;
    float moonanim;
    float mapanim;
    float loadanim;
    sf::Vector2f v1;
    ///systems
    bool victory;
    bool bossexist;
    bool gracz1;
    bool gracz2;
    int score;
    int start;
    int przejscie;
    int enemySpawnTimer ;
    int hpSpawnTimer ;
    int asteroidSpawnTimer ;
    int bossloading;
    ///fonts
    Font font;
    ///textures
    Texturesinit alltextures;
    Texture loadtex;
    Sprite  loadsprite;
    Texture menutex;
    Sprite  menusprite;
    Texture moontex;
    Sprite moonsprite;
    Texture spacebacktex;
    Sprite spacebacksprite;

    //Sounds
    sf::SoundBuffer themebuffer;
    sf::SoundBuffer pulsebuffer;
    sf::SoundBuffer pulsebuffer2;
    sf::SoundBuffer explosionbuffer;
    sf::SoundBuffer gameoverbuffer;
    sf::SoundBuffer bossbuffer;
    sf::SoundBuffer winbuffer;
    sf::SoundBuffer laserbuffer;
    sf::Sound themesound;
    sf::Sound pulsesound;
    sf::Sound pulsesound2;
    sf::Sound explosionsound;
    sf::Sound gameoversound;
    sf::Sound bosssound;
    sf::Sound winsound;
    sf::Sound lasersound;
    ///texts
    Text scoreText;
    Text gameOverText;
    Text gamewonText;
    Text menuText;
    Text menu1Text;
    Text player2Text;
    ///entities
    Player* player;
    Player* player2;
    //Asteroids init
    std::vector<Asteroid> asteroids;

    //Hpbags init
    std::vector<Healthbag> hpbags;

    //Death init
    std::vector<Deathanim> enemiesdeath;
    std::vector<Deathanim> asteroiddeath;

    ///hit anim init
    std::vector<Deathanim> hits;

    //Enemy init
    std::vector<Enemy> enemies;

    ///Boss init
    std::vector<Boss> boss;


public:

    void menu()
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

    void loading()
    {
        window.clear(Color::Black);
        loadsprite.setScale(22,22);
        loadsprite.setPosition(window.getSize().x/2-loadsprite.getGlobalBounds().width/2,window.getSize().y/2-loadsprite.getGlobalBounds().height/2);
        loadsprite.setTextureRect(sf::IntRect(0,loadanim, 32, 32));
        loadanim+=32;
        window.draw(loadsprite);
        if( loadanim>=736){ loadanim=0; przejscie++;}
        if(przejscie==2)
        {start=2;}
    }


    void playerbulspawn(Player *p)
    {
        if (p->showshoottime() < 15)
            p->shoottimeincrease();

        if (Keyboard::isKeyPressed(Keyboard::Space) && p->showshoottime() >= 15) //Shooting
        {
            p->getbullets().push_back(Bullet(alltextures.GetTexture(Textures::bulletTex), p->shape.getPosition()));
            pulsesound.play();
            p->shoottimezero(); //reset timer

        }
    }
    void playerbulspawn2(Player *p)
    {
        if (p->showshoottime() < 15)
            p->shoottimeincrease();

        if (Keyboard::isKeyPressed(Keyboard::RShift) && p->showshoottime() >= 15) //Shooting
        {
            p->getbullets().push_back(Bullet(alltextures.GetTexture(Textures::bulletTex2), p->shape.getPosition()));
            pulsesound.play();
            p->shoottimezero(); //reset timer

        }
    }
    void playershooting(Player *p)
    {   for(auto&bul:p->getbullets()){
            //Move
            bul.shape.move(20.f, 0.f);
            bul.shape.setTextureRect(sf::IntRect(0,bulletanim, 63, 32));
            bulletanim+=32;
            if( bulletanim>=128){ bulletanim=0;}

            //Out of window bounds
            if (bul.shape.getPosition().x > window.getSize().x)
            {
                bul.gone=1;
                continue;
            }


            for (size_t k = 0; k < boss.size(); k++)
            {
                if (bul.shape.getGlobalBounds().intersects(boss[k].shape.getGlobalBounds()))
                {
                    if (boss[k].showHP() <= 1)
                    {
                        score += boss[k].showmaxHP();
                        bosssound.stop();
                        boss.erase(boss.begin() + k);
                        explosionsound.play();
                        Deathanim(alltextures.GetTexture(Textures::bossexpTex), v1);
                        victory=true;
                    }
                    else
                    {boss[k].damage(); //BOSS TAKES DAMAGE
                        hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), boss[k].shape.getPosition()));}

                    bul.gone=1;
                    continue;
                }}


            for (size_t k = 0; k < asteroids.size(); k++)
            {
                if (bul.shape.getGlobalBounds().intersects(asteroids[k].shape.getGlobalBounds()))
                {
                    if (asteroids[k].showHP() <= 1)
                    {
                        score += asteroids[k].showmaxHP();
                        asteroids.erase(asteroids.begin() + k);
                        explosionsound.play();
                        bossloading++;
                        asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroid_smallTex), window.getSize(),&font));
                        asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroid_smallTex), window.getSize(),&font));

                    }
                    else
                    {asteroids[k].damage(); //ENEMY TAKE DAMAGE
                        hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), asteroids[k].shape.getPosition()));
                    }
                    bul.gone=1;
                    continue;
                }}
            for (size_t k = 0; k < enemies.size(); k++)
            {
                if (bul.shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
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
                    { enemies[k].damage(); //ENEMY TAKE DAMAGE
                        hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), enemies[k].shape.getPosition()));}


                    bul.gone=1;
                    continue;
                }   }

        }}
    void bossshooting()
    {
        for(auto& b:boss){
            if (b.showshoottime() < 50)
                b.shoottimeincrease();
            if ((bossexist==true) && (b.showshoottime() >= 50)) //Shooting
            {
                b.bulletsboss.push_back(Bullet(alltextures.GetTexture(Textures::bossbulletTex), b.shape.getPosition()));
                lasersound.play();
                b.shoottimezero(); //reset timer

            }
            //BossBullets

            for (size_t i = 0; i < b.bulletsboss.size(); i++)
            {
                //Move
                if(gracz1==1)
                {
                    b.bossx=-4.f;
                    b.bossy=(player->shape.getPosition().y-b.shape.getPosition().y)/(2*frames);
                    b.bulletsboss[i].shape.move(b.bossx, b.bossy);

                }
                if(gracz1==0)
                {
                    b.bossx=-4.f;
                    b.bossy=(player->shape.getPosition().y-b.shape.getPosition().y)/(2*frames);
                    b.bulletsboss[i].shape.move(b.bossx, b.bossy);
                }

                b.bulletsboss[i].shape.setTextureRect(sf::IntRect(10,bossbulletanim, 30, 30));
                bossbulletanim+=64;
                if( bossbulletanim>=3840){ bossbulletanim=15;}

                //Out of window bounds
                if (b.bulletsboss[i].shape.getPosition().x+100 < 0)
                {
                    b.bulletsboss.erase(b.bulletsboss.begin() + i);
                    break;
                }


                //player collision
                if(gracz1){

                    if (b.bulletsboss[i].shape.getGlobalBounds().intersects(player->shape.getGlobalBounds()))
                    {
                        player->damage(); //PLAYER TAKE DAMAGE
                        hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player->shape.getPosition()));
                        b.bulletsboss.erase(b.bulletsboss.begin() + i);
                        break;
                    }}
                if(gracz2)
                {
                    if (b.bulletsboss[i].shape.getGlobalBounds().intersects(player2->shape.getGlobalBounds()))
                    {
                        player2->damage(); //PLAYER TAKE DAMAGE
                        hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player2->shape.getPosition()));
                        b.bulletsboss.erase(b.bulletsboss.begin() + i);
                        break;
                    }
                }


            }}
    }

    void asteroidspawn()
    {
        if (asteroidSpawnTimer < 25)
            asteroidSpawnTimer++;
        if(asteroidSpawnTimer >= 25)
        {
            asteroids.push_back(Asteroid(alltextures.GetTexture(Textures::asteroidTex), window.getSize(),&font));
            asteroidSpawnTimer = 0; //reset timer

        }
    }

    void asteroidcol()
    {
        for (size_t i = 0; i < asteroids.size(); i++)
        {
            asteroids[i].moves();

            if ((asteroids[i].shape.getPosition().x <= 0- asteroids[i].shape.getGlobalBounds().width)||
                    (asteroids[i].shape.getPosition().y <= 0)||
                    (asteroids[i].shape.getPosition().y >= windowH - asteroids[i].shape.getGlobalBounds().height))
            {
                asteroids.erase(asteroids.begin() + i);
                break;
            }
            if(gracz1)
            {
                if (asteroids[i].shape.getGlobalBounds().intersects(player->shape.getGlobalBounds()))
                {
                    asteroids.erase(asteroids.begin() + i);
                    explosionsound.play();
                    player->damage(); // PLAYER TAKE DAMAGE
                    hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player->shape.getPosition()));
                    break;
                }}
            if(gracz2)
            {
                if (asteroids[i].shape.getGlobalBounds().intersects(player2->shape.getGlobalBounds()))
                {
                    asteroids.erase(asteroids.begin() + i);
                    explosionsound.play();
                    player2->damage(); // PLAYER2 TAKE DAMAGE
                    hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player2->shape.getPosition()));
                    break;
                }
            }
        }
    }

    void hpspawn()
    {
        if (hpSpawnTimer < 500)
            hpSpawnTimer++;
        if(hpSpawnTimer >= 500)
        {
            hpbags.push_back(Healthbag(alltextures.GetTexture(Textures::HPTex), window.getSize(),&font));
            hpSpawnTimer = 0; //reset timer

        }
    }

    void hpcol()
    {
        for (size_t i = 0; i < hpbags.size(); i++)
        {
            hpbags[i].moves();

            if ((hpbags[i].shape.getPosition().x <= 0- hpbags[i].shape.getGlobalBounds().width)||
                    (hpbags[i].shape.getPosition().y <= 0)||
                    (hpbags[i].shape.getPosition().y >= windowH - hpbags[i].shape.getGlobalBounds().height))
            {
                hpbags.erase(hpbags.begin() + i);
                break;
            }
            if(gracz1)
            {
                if (hpbags[i].shape.getGlobalBounds().intersects(player->shape.getGlobalBounds()))
                {
                    hpbags.erase(hpbags.begin() + i);
                    if(player->showHP()<player->showmaxHP())
                    {player->heal();} // PLAYER HEALS
                    break;
                }}
            if(gracz2)
            {
                if (hpbags[i].shape.getGlobalBounds().intersects(player2->shape.getGlobalBounds()))
                {
                    hpbags.erase(hpbags.begin() + i);
                    if(player2->showHP()<player2->showmaxHP())
                    {player2->heal();} // PLAYER2 HEALS
                    break;
                }
            }
        }
    }


    void enemyspawn()
    {
        if (enemySpawnTimer < 25)
            enemySpawnTimer++;
    }

    void enemycol()
    {
        if ((bossexist==false) &&(enemySpawnTimer >= 25))
        {
            enemies.push_back(Enemy(alltextures.GetTexture(Textures::enemyTex), window.getSize(),&font));
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
                if (enemies[i].shape.getGlobalBounds().intersects(player->shape.getGlobalBounds()))
                {
                    enemies.erase(enemies.begin() + i);
                    explosionsound.play();
                    player->damage(); // PLAYER TAKE DAMAGE
                    hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player->shape.getPosition()));
                    break;
                }}
            if(gracz2)
            {
                if (enemies[i].shape.getGlobalBounds().intersects(player2->shape.getGlobalBounds()))
                {
                    enemies.erase(enemies.begin() + i);
                    explosionsound.play();
                    player2->damage(); // PLAYER2 TAKE DAMAGE
                    hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player2->shape.getPosition()));
                    break;
                }
            }
        }
    }

    void bossspawn()
    {
        if(bossloading>1){
            //
            themesound.stop();
            if(bosssound.getStatus()!=sf::Sound::Status::Playing)
            {bosssound.play();
                boss.emplace_back(alltextures.GetTexture(Textures::bossTex),window.getSize(),&font);
            }
        }
    }

    void bosscol()
    {
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
            { if (boss[i].shape.getGlobalBounds().intersects(player->shape.getGlobalBounds()))
                {

                    player->damage(); // PLAYER TAKE DAMAGE
                    hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player->shape.getPosition()));
                    break;
                }}
            if(gracz2)
            {if (boss[i].shape.getGlobalBounds().intersects(player2->shape.getGlobalBounds()))
                {

                    player2->damage(); // PLAYER TAKE DAMAGE
                    hits.push_back(Deathanim(alltextures.GetTexture(Textures::hitexpTex), player2->shape.getPosition()));
                    break;
                }}
        }
    }
    void playerterms()
    {
        if(player->showHP()<=0)
        {   gracz1=0;
            explosionsound.play();
        }

        if(player2->showHP()<=0)
        {
            gracz2=0;
            explosionsound.play();

        }
        for(auto it=player->getbullets().begin(); it!=player->getbullets().end();)
            if((*it).gone)
            {
                it=player->getbullets().erase(it);
            }
            else
            {
                it++;
            }

        for(auto it=player2->getbullets().begin(); it!=player2->getbullets().end();)
            if((*it).gone)
            {
                it=player2->getbullets().erase(it);
            }
            else
            {
                it++;
            }

        //UI Update
        scoreText.setString("Score: " + std::to_string(score));
    }
    void backgroundanim()
    {
        spacebacksprite.setTextureRect(sf::IntRect(mapanim, 0, 800,600));
        mapanim+=10;
        if( mapanim>=800){ mapanim=200;}
    }
    void deathanim()
    {
        for (size_t i = 0; i < enemiesdeath.size(); i++){
            enemiesdeath[i].shape.setTextureRect(sf::IntRect(22,enemydeathanim, 50,50));
            enemydeathanim+=400;

            if( enemydeathanim>=6500){
                enemydeathanim=11;
                enemiesdeath.erase(enemiesdeath.begin() + i);
                break;
            }}
    }
    void hitsanim()
    {
        for (size_t i = 0; i < hits.size(); i++){
            hits[i].shape.setScale(1.f,1.f);
            hits[i].shape.setTextureRect(sf::IntRect(22,hitanim, 50,70));
            hitanim+=400;

            if( hitanim>=6500){
                hitanim=11;
                hits.erase(hits.begin() + i);


                break;
            }}
    }

    void drawing()
    {
        window.clear();

        window.draw(spacebacksprite);
        //players
        if(gracz1){
            player->display(window);
            //Bullets
            for (size_t i = 0; i < player->getbullets().size(); i++)
            {
                window.draw(player->getbullets()[i].shape);
            }
        }

        if(gracz2)
        { player2->display(window);
            for (size_t i = 0; i < player2->getbullets().size(); i++)
            {
                window.draw(player2->getbullets()[i].shape);
            }
        }

        for(auto&b:boss){
            for (size_t i = 0; i < b.bulletsboss.size(); i++)
            {
                window.draw(b.bulletsboss[i].shape);
            }}

        //enemy

        for (size_t i = 0; i < enemies.size(); i++)
        {
            enemies[i].display(window);

        }

        //Asteroids

        for (size_t i = 0; i < asteroids.size(); i++)
        {

            window.draw(asteroids[i].shape);
        }

        //hpbags

        for (size_t i = 0; i < hpbags.size(); i++)
        {

            window.draw(hpbags[i].shape);
        }

        //Death
        for (size_t k = 0; k < enemiesdeath.size(); k++)
        {
            window.draw(enemiesdeath[k].shape);
        }
        //Hits

        for (size_t k = 0; k < hits.size(); k++)
        {
            window.draw(hits[k].shape);
        }


        //boss


        for (size_t i = 0; i < boss.size(); i++)
        {
            boss[i].display(window);
        }

        //UI
        window.draw(scoreText);
    }

    void winlosedraw()
    {
        if (((gracz1==0)&&(gracz2==0)))
        {
            if(gameoversound.getStatus()!=sf::Sound::Status::Playing)
            {gameoversound.play();}

            window.draw(gameOverText);
        }
        if (victory==true)
        {
            if(winsound.getStatus()!=sf::Sound::Status::Playing)
            {winsound.play(); }
            window.draw(gamewonText);
        }
    }


    inline void inittextures()
    {
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
        alltextures.addTex(Textures::bossexpTex,"tex/graczbum.png");
        alltextures.addTex(Textures::enemyexpTex,"tex/enemybum.png");
        alltextures.addTex(Textures::graczexpTex,"tex/graczbum2.png");
        alltextures.addTex(Textures::hitexpTex,"tex/bossbum.png");
        alltextures.addTex(Textures::HPTex,"tex/HP.png");
        spacebacktex.loadFromFile("tex/space2.png");
        moontex.loadFromFile("tex/moon.png");
        menutex.loadFromFile("tex/menuback.png");
        loadtex.loadFromFile("tex/loading.png");
        ///Init background
        spacebacktex.loadFromFile("tex/space2.png");
        spacebacksprite.setTexture(spacebacktex);
        //Loading init
        loadsprite.setTexture(loadtex);

    }

    inline void initsound()
    {
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
    }

    inline void initsubs()
    {
        font.loadFromFile("Font/slkscreb.ttf");
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
    }

    Game(): window(VideoMode(windowW, windowH), "Space ranger!", Style::Default)
    {
        this->init();
        srand(time(NULL));
        window.setFramerateLimit(frames);
        inittextures();
        initsound();
        initsubs();

        //Players init
        player=new Player(alltextures.GetTexture(Textures::playerTex),&font);
        player2=new Player(alltextures.GetTexture(Textures::playerTex2),&font);
        themesound.play();
    }


    void init()
    {
        ///animations
        enemyrotation=0;
        bossrotation=0;
        bulletanim=0;
        bulletanim2=0;
        bossbulletanim=15;
        enemydeathanim=11;
        bossdeathanim=11;
        playerdeathanim=11;
        hitanim=11;
        asteroiddeathanim=11;
        moonanim=0;
        mapanim=200;
        loadanim=0;
        sf::Vector2f v1(windowW/2+100.f, windowH/2-20);

        ///systems
        victory=0;
        bossexist=false;
        gracz1=1;
        gracz2=0;
        score = 0;
        start=0;
        przejscie=0;
        enemySpawnTimer = 0;
        hpSpawnTimer = 0;
        asteroidSpawnTimer = 0;
        bossloading=0;

    }

    void loop()
    {
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
                menu();
            }
            if(start==1)
            {
                loading();
            }
            if(start==2)    ///game
            {   window.clear(Color::Black);

                if (((gracz1==1)||(gracz2==1))&&(victory==false))
                {
                    ///Gracze są zainicjowani osobno, ponieważ posiadają inne modele, animacje oraz sterowanie

                    if(gracz1){
                        player->moves(alltextures.GetTexture(Textures::playerTex),alltextures.GetTexture(Textures::playerTexDown),alltextures.GetTexture(Textures::playerTexUp));
                        //Collision with window
                        player->collision(window.getSize());
                        //Playershooting
                        playerbulspawn(player);
                        playershooting(player);

                    }
                    ///PLAYER2
                    if(gracz2)
                    {
                        player2->moves2(alltextures.GetTexture(Textures::playerTex2),alltextures.GetTexture(Textures::playerTexDown2),alltextures.GetTexture(Textures::playerTexUp2));
                        //Collision with window
                        player2->collision(window.getSize());
                        // Playershooting
                        playerbulspawn2(player2);
                        playershooting(player2);

                    }
                    //Boss shooting
                    bossshooting();


                    ///Asteroids spawn
                    asteroidspawn();
                    asteroidcol();


                    ///Hp bags

                    hpspawn();
                    hpcol();

                    //Enemy spawn
                    enemyspawn();
                    enemycol();
                    //Big szef
                    bossspawn();
                    bosscol();


                    //check if player is dead, erasing bullets, showing score
                    playerterms();

                }
                //// Anims
                backgroundanim();


                ///Death anim
                deathanim();

                ///hit anim
                hitsanim();



                //Draw =====================================================================

                drawing();
                winlosedraw();


            }
            window.display();
        }
    }

    ~Game()
    {
        delete player;
        delete player2;
    }
};

#endif // GAME_H

