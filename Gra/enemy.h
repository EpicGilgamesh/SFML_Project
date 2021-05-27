#ifndef ENEMY_H
#define ENEMY_H
#include "posrednik.h"

class Enemy
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

#endif // ENEMY_H
