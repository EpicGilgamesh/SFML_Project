#ifndef BULLET_H
#define BULLET_H
#include "posrednik.h"

class Bullet
{
public:
    Sprite shape;

    Bullet(Texture *texture, Vector2f pos)
    {
        this->shape.setTexture(*texture);

        this->shape.setScale(2.f, 2.f);

        this->shape.setPosition(pos);
    }

    ~Bullet(){}
};

#endif // BULLET_H
