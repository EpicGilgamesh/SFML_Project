#ifndef ENEMY_H
#define ENEMY_H
#include "posrednik.h"
#include "bullet.h"
class Enemybase
{protected:
    virtual int hp();
public:
};
class Enemy//:public Enemy
{
public:
    Sprite shape;

    int HP;
    int HPMax;


    Enemy(Texture *texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 3 + 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);

        this->shape.setScale(2.f, 2.f);

        this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
    }

    ~Enemy(){}
};
class Boss
{
public:
    Sprite shape;

    int HP;
    int HPMax;
    std::vector<Bullet> bulletsboss;

    Boss(Texture *texture, Vector2u windowSize)
    {
        this->HPMax =2;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);

       // this->shape.setScale(2.f, 2.f);

     this->shape.setPosition(windowSize.x + this->shape.getGlobalBounds().width, windowSize.y/2-100 );
//- this->shape.getGlobalBounds().height

    }

    ~Boss(){}
};

#endif // ENEMY_H
