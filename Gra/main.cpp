#include "posrednik.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "assets.h"
#include "Background.h"

 float enemyrotation=0;
 float bulletanim=0;

int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(800, 600), "Spaceship action!", Style::Default);
    window.setFramerateLimit(25);

    //Init text
    Font font;
    font.loadFromFile("Font/slkscreb.ttf");

    //Init textures
    Texture playerTex;
    playerTex.loadFromFile("tex/player1.png");
    Texture playerTexUp;
    playerTexUp.loadFromFile("tex/playerup.png");
    Texture playerTexDown;
    playerTexDown.loadFromFile("tex/playerdown.png");

    Texture enemyTex;
    enemyTex.loadFromFile("tex/enemy1.png");

    Texture bulletTex;
    bulletTex.loadFromFile("tex/pulse1.png");
    Texture spacebacktex;
    Sprite spacebacksprite;
    spacebacktex.loadFromFile("tex/space.png");
    ///background
    spacebacktex.setRepeated(true);
    spacebacksprite.setTexture(spacebacktex);
    spacebacksprite.setTextureRect(sf::IntRect(0, 0, 800,600));

    //UI init
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(10.f, 10.f);

    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(100.f, window.getSize().y / 2);
    gameOverText.setString("GAME OVER!");

    //Player init
    int score = 0;
    Player player(&playerTex);
    int shootTimer = 20;
    Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(12);
    hpText.setFillColor(Color::White);

    //Enemy init
    int enemySpawnTimer = 0;
    std::vector<Enemy> enemies;

    Text eHpText;
    eHpText.setFont(font);
    eHpText.setCharacterSize(12);
    eHpText.setFillColor(Color::White);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (player.HP > 0)
        {
            //Player
             player.shape.setTexture(playerTex);
            if ((Keyboard::isKeyPressed(Keyboard::W))||(Keyboard::isKeyPressed(Keyboard::Up)))
               { player.shape.move(0.f, -10.f);
                   player.shape.setTexture(playerTexUp); }
            if ((Keyboard::isKeyPressed(Keyboard::A))||(Keyboard::isKeyPressed(Keyboard::Left)))
               { player.shape.move(-10.f, 0.f);}
            if ((Keyboard::isKeyPressed(Keyboard::S))||(Keyboard::isKeyPressed(Keyboard::Down)))
               { player.shape.move(0.f, 10.f);
            player.shape.setTexture(playerTexDown);}
            if ((Keyboard::isKeyPressed(Keyboard::D))||(Keyboard::isKeyPressed(Keyboard::Right)))
               { player.shape.move(10.f, 0.f);}

            hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
            hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));

            //Collision with window
            if (player.shape.getPosition().x <= 0) //Left
                player.shape.setPosition(0.f, player.shape.getPosition().y);
            if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width) //Right
                player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
            if (player.shape.getPosition().y <= 0) //Top
                player.shape.setPosition(player.shape.getPosition().x, 0.f);
            if (player.shape.getPosition().y >= window.getSize().y - player.shape.getGlobalBounds().height) //Bottom
                player.shape.setPosition(player.shape.getPosition().x, window.getSize().y - player.shape.getGlobalBounds().height);

            //Update Controls
            if (shootTimer < 15)
                shootTimer++;

            if (Keyboard::isKeyPressed(Keyboard::Space) && shootTimer >= 15) //Shooting
            {
                player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                shootTimer = 0; //reset timer
            }

            //Bullets
            for (size_t i = 0; i < player.bullets.size(); i++)
            {
                //Move
                player.bullets[i].shape.move(20.f, 0.f);
                player.bullets[i].shape.setTextureRect(sf::IntRect(0,bulletanim, 63, 32));
                bulletanim+=32;
                if( bulletanim>128){ bulletanim=0;}

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
                        if (enemies[k].HP <= 1)
                        {
                            score += enemies[k].HPMax;
                            enemies.erase(enemies.begin() + k);
                        }
                        else
                            enemies[k].HP--; //ENEMY TAKE DAMAGE

                        player.bullets.erase(player.bullets.begin() + i);
                        break;
                    }
                }
            }

            //Enemy
            if (enemySpawnTimer < 25)
                enemySpawnTimer++;

            //enemy spawn
            if (enemySpawnTimer >= 25)
            {
                enemies.push_back(Enemy(&enemyTex, window.getSize()));
                enemySpawnTimer = 0; //reset timer
            }

            for (size_t i = 0; i < enemies.size(); i++)
            {
                enemies[i].shape.move(-6.f, 0.f);

                enemies[i].shape.setTextureRect(sf::IntRect(0,enemyrotation , 32, 32));
                enemyrotation+=32;
                if( enemyrotation>=160){ enemyrotation=0;}
                if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
                {
                    enemies.erase(enemies.begin() + i);
                    break;
                }

                if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                {
                    enemies.erase(enemies.begin() + i);

                    player.HP--; // PLAYER TAKE DAMAGE
                    break;
                }
            }

            //UI Update
            scoreText.setString("Score: " + std::to_string(score));
        }

        //Draw ===================================================================== DRAW
        window.clear();
        // spacebacksprite.move(2.f,0);
        window.draw(spacebacksprite);
        //player
        window.draw(player.shape);

        //Bullets
        for (size_t i = 0; i < player.bullets.size(); i++)
        {
            window.draw(player.bullets[i].shape);
        }

        //enemy
        for (size_t i = 0; i < enemies.size(); i++)
        {
            eHpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
            eHpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
            window.draw(eHpText);
            window.draw(enemies[i].shape);
        }

        //UI
        window.draw(scoreText);
        window.draw(hpText);

        if (player.HP <= 0)
            window.draw(gameOverText);

        window.display();
    }

    return 0;
}
