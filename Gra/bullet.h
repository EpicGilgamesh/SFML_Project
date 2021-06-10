#ifndef BULLET_H
#define BULLET_H
#include "posrednik.h"
#include "beings.h"

class Bullet
{
public:
bool gone=0;
Sprite shape;
    Bullet(Texture *texture, Vector2f pos)
    {
        this->shape.setTexture(*texture);

        this->shape.setScale(1.5f, 1.5f);

        this->shape.setPosition(pos);
    }





    ~Bullet(){}
};

class Deathanim
{

    public:
Sprite shape;

        Deathanim(Texture *texture, Vector2f pos)
        {
            this->shape.setTexture(*texture);
           this->shape.setScale(2.f, 2.f);
            this->shape.setPosition(pos);

        }





        ~Deathanim(){}
};

#endif // BULLET_H
