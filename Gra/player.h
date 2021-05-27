#ifndef PLAYER_H
#define PLAYER_H
#include "posrednik.h"
#include "enemy.h"
#include "bullet.h"
class Player
{
public:
    Sprite shape;
    Texture *texture;

    int HP;
    int HPMax;

    std::vector<Bullet> bullets;

    Player(Texture *texture)
    {
        this->HPMax = 10;
        this->HP = this->HPMax;

        this->texture = texture;
        this->shape.setTexture(*texture);
        this->shape.setScale(2.f, 2.f);
        ///this->moves();
    }
    void moves()
    {
        if ((Keyboard::isKeyPressed(Keyboard::W))||(Keyboard::isKeyPressed(Keyboard::Up)))
           { this->shape.move(0.f, -10.f);
             this->shape.setTexture(*texture);   }
        if ((Keyboard::isKeyPressed(Keyboard::A))||(Keyboard::isKeyPressed(Keyboard::Left)))
           { this->shape.move(-10.f, 0.f);}
        if ((Keyboard::isKeyPressed(Keyboard::S))||(Keyboard::isKeyPressed(Keyboard::Down)))
           { this->shape.move(0.f, 10.f);
        }
        if ((Keyboard::isKeyPressed(Keyboard::D))||(Keyboard::isKeyPressed(Keyboard::Right)))
           { this->shape.move(10.f, 0.f);}
    }

    ~Player() {}
};

#endif // PLAYER_H
