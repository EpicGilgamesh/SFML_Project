//#ifndef SHOOTING_H
//#define SHOOTING_H
//#include "posrednik.h"
//#include "beings.h"
//#include "bullet.h"


//void bullets_pl_enemy(Player player,std::vector<Boss> boss,std::vector<Enemy> enemies,Texturesinit alltextures)
//{

//    if (player.showshoottime() < 15)
//        player.shoottimeincrease();

//    if (Keyboard::isKeyPressed(Keyboard::Space) && player.showshoottime() >= 15) //Shooting
//    {
//        player.bullets.push_back(Bullet(alltextures.GetTexture(Textures::bulletTex), player.shape.getPosition()));
//        pulsesound.play();
//        player.shoottimezero(); //reset timer

//    }
//    for (size_t i = 0; i < player.bullets.size(); i++)
//    {
//        //Move
//        player.bullets[i].shape.move(20.f, 0.f);
//        player.bullets[i].shape.setTextureRect(sf::IntRect(0,bulletanim, 63, 32));
//        bulletanim+=32;
//        if( bulletanim>=128){ bulletanim=0;}

//        //Out of window bounds
//        if (player.bullets[i].shape.getPosition().x > window.getSize().x)
//        {
//            player.bullets.erase(player.bullets.begin() + i);
//            break;
//        }


//        //Enemy collision
//        for (size_t k = 0; k < enemies.size(); k++)
//        {
//            if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
//            {
//                if (enemies[k].showHP() <= 1)
//                {
//                    score += enemies[k].showmaxHP();
//                    enemies.erase(enemies.begin() + k);
//                    explosionsound.play();
//                }
//                else
//                    enemies[k].damage(); //ENEMY TAKE DAMAGE

//                player.bullets.erase(player.bullets.begin() + i);
//                break;
//            }
//        }
//        //Boss collision&Win

//        for (size_t k = 0; k < boss.size(); k++)
//        {
//            if (player.bullets[i].shape.getGlobalBounds().intersects(boss[k].shape.getGlobalBounds()))
//            {
//                if (boss[k].showHP() <= 1)
//                {
//                    score += boss[k].showmaxHP();
//                    bosssound.stop();
//                    boss.erase(boss.begin() + k);
//                    explosionsound.play();
//                    victory=true;
//                }
//                else
//                    boss[k].damage(); //ENEMY TAKE DAMAGE

//                player.bullets.erase(player.bullets.begin() + i);
//                break;
//            }
//        }
//    }
//}

//void bullets_boss_pl()
//{

//}
//class Deathanim
//{

//    public:
//Sprite shape;

//        Deathanim(Texture *texture, Vector2f pos)
//        {
//            this->shape.setTexture(*texture);
//           /// this->shape.setScale(2.f, 2.f);
//            this->shape.setPosition(pos);

//        }





//        ~Deathanim(){}
//};
//#endif // SHOOTING_H
