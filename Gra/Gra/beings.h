#ifndef BEINGS_H
#define BEINGS_H
#include "posrednik.h"
#include "bullet.h"
#include "assets.h"

class Being
{
protected:
    int shoottime;
    int HP;
    int HPMax;
    int rotation;
    int rotationtimer;
    float deathanim;

public:
    bool dead=0;
    Sprite shape;
    Text HPtext;

    virtual void damage()
    {
        HP--;
    }
    virtual void heal()
    {
        HP=HP+rand()%(HPMax-HP)+1;
    }
    virtual bool alive()
    {
        if(HP>0)
            return 1;
        else
            return 0;
    }
    virtual int showHP()
    {
        return HP;
    }
    virtual int showmaxHP()
    {
        return HPMax;
    }
    virtual int showshoottime()
    {
        return shoottime;
    }
    virtual void shoottimeincrease()
    {
        shoottime++;
    }
    virtual void shoottimezero()
    {
        shoottime=0;
    }

    virtual void display(sf::RenderWindow &window)
    {
        this-> HPtext.setPosition(this->shape.getPosition().x+this->shape.getGlobalBounds().width/4, this->shape.getPosition().y - HPtext.getGlobalBounds().height-10);
        this-> HPtext.setString(std::to_string(this->HP) + "/" + std::to_string(this->HPMax));
        window.draw(this->HPtext);
        window.draw(this->shape);

    }



};
class Player:public Being
{

std::vector<Bullet> bullets;

public:

    Texture *texture;




    std::vector<Bullet> &getbullets()
    {
        return bullets;
    }

    Player(Texture *texture1,Font* font):Being()
    {
        this->shoottime=15;
        this->HPMax = 10;
        this->HP = this->HPMax;
        this->texture = texture1;
        this->shape.setTexture(*texture1);
        this->shape.setScale(2.f, 2.f);
        this->shape.setPosition(0,200);
        this->HPtext.setFont(*font);
        this->HPtext.setCharacterSize(12);
        this->HPtext.setFillColor(Color::Yellow);
        this-> HPtext.setPosition(this->shape.getPosition().x+this->shape.getGlobalBounds().width/2, this->shape.getPosition().y - HPtext.getGlobalBounds().height);
        this->HPtext.setString(std::to_string(this->HP) + "/" + std::to_string(this->HPMax));
    }
    //virtual
    void moves(Texture *playerTex,Texture *playerTexDown,Texture *playerTexUp)///override
    {   this->shape.setTexture(*playerTex);
        if (Keyboard::isKeyPressed(Keyboard::W))
        { shape.move(0.f, -10.f);
            this->shape.setTexture(*playerTexUp);
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        { this->shape.move(-10.f, 0.f);}
        if (Keyboard::isKeyPressed(Keyboard::S))
        { this->shape.move(0.f, 10.f);
            this->shape.setTexture(*playerTexDown);
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        { this->shape.move(10.f, 0.f);}
    }

    void moves2(Texture *playerTex,Texture *playerTexDown,Texture *playerTexUp)
    {   this->shape.setTexture(*playerTex);
        if (Keyboard::isKeyPressed(Keyboard::Up))
        { shape.move(0.f, -10.f);
            this->shape.setTexture(*playerTexUp);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        { this->shape.move(-10.f, 0.f);}
        if (Keyboard::isKeyPressed(Keyboard::Down))
        { this->shape.move(0.f, 10.f);
            this->shape.setTexture(*playerTexDown);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        { this->shape.move(10.f, 0.f);}
    }

    void collision(Vector2u windowSize)
    {
        if (this->shape.getPosition().x <= 0) //Left
            this->shape.setPosition(0.f, this->shape.getPosition().y);
        if (this->shape.getPosition().x >= windowSize.x - this->shape.getGlobalBounds().width) //Right
            this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, this->shape.getPosition().y);
        if (this->shape.getPosition().y <= 0) //Top
            this->shape.setPosition(this->shape.getPosition().x, 0.f);
        if (this->shape.getPosition().y >= windowSize.y - this->shape.getGlobalBounds().height) //Bottom
            this->shape.setPosition(this->shape.getPosition().x, windowSize.y - this->shape.getGlobalBounds().height);

    }


    ~Player() {}
};
class Enemy:public Being
{
public:


    Enemy(Texture *texture, Vector2u windowSize,Font* font)
    {
        this->HPMax = rand() % 3 + 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);

        this->shape.setScale(2.f, 2.f);

        this->shape.setPosition(windowSize.x + this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));

        this->HPtext.setFont(*font);
        this->HPtext.setCharacterSize(12);
        this->HPtext.setFillColor(Color::Red);


    }

    void moves()
    {
        this->shape.move(-6.f, 0.f);
        if (rotationtimer < 2)
            rotationtimer++;


        if (rotationtimer >= 2)
        {
            this->shape.setTextureRect(sf::IntRect(0,rotation , 32, 32));
            rotation+=32;
            if( rotation>=160){ rotation=0;
                rotationtimer = 0;
            }
        }}


    ~Enemy(){}
};
class Boss:public Being
{
public:



    ///shooting
    float bossx;
    float bossy;


    std::vector<Bullet> bulletsboss;

    Boss(Texture *texture, Vector2u windowSize,Font* font)
    {
        this->shoottime=20;
        this->HPMax =30;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);

        this->HPtext.setFont(*font);
        this->HPtext.setCharacterSize(12);
        this->HPtext.setFillColor(Color::Red);
        this->shape.setPosition(windowSize.x + this->shape.getGlobalBounds().width, windowSize.y/2-100 );




    }



    ~Boss(){}
};
class Asteroid:public Being
{
public:






    Asteroid(Texture *texture, Vector2u windowSize,Font* font)
    {
        this->HPMax = rand() % 2 + 1;
        this->HP = this->HPMax;
        this->shape.setTexture(*texture);
        this->shape.setScale(2.f, 2.f);
        this->shape.setPosition(windowSize.x + this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
        this->HPtext.setFont(*font);
        this->HPtext.setCharacterSize(12);
        this->HPtext.setFillColor(Color::White);


    }

    void moves()
    {
        this->shape.move(-3.f, 0.f);
        this->shape.rotate(0.4f);

    }

    ~Asteroid()
    {

    }
};
class Healthbag:public Asteroid
{
public:
    Healthbag (Texture *texture, Vector2u windowSize,Font* font):Asteroid(texture,windowSize, font)
    {
        this->shape.setScale(1.f,1.f);
    }

    ~Healthbag()
    {}

};

#endif // BEINGS_H
