#ifndef ASSETS_H
#define ASSETS_H
#include "posrednik.h"
//variables:
///window
float windowH=600;
float windowW=800;
RenderWindow window(VideoMode(windowW, windowH), "Space ranger!", Style::Default);
int frames=25;
///animations
float enemyrotation=0;
float bossrotation=0;
float bulletanim=0;
float bulletanim2=0;
float bossbulletanim=15;
float enemydeathanim=11;
float bossdeathanim=11;
float playerdeathanim=11;
float hitanim=11;
float asteroiddeathanim=11;
float moonanim=0;
float mapanim=200;
float loadanim=0;
int astx;
int asty;
sf::Vector2f v1(windowW/2+100.f, windowH/2-20);
///systems
static bool initialized;
static bool initialized1;
bool victory=0;
bool bossexist=false;
bool gracz1=1;
bool gracz2=0;
int score = 0;
int start=2;
int przejscie=0;
int enemySpawnTimer = 0;
int hpSpawnTimer = 0;
int asteroidSpawnTimer = 0;
int bossloading=0;
///fonts
Font font;
///textures

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




///textures
enum class Textures
{
     playerTex,
     playerTexDown,
     playerTexUp,
    playerTex2,
    playerTexDown2,
    playerTexUp2,
     enemyTex,
     bossTex,
     loadtex,
     menutex,
     moontex,
     bossbulletTex,
     bulletTex,
    bulletTex2,
    asteroidTex,
    asteroid_smallTex,
    asteroidexpTex,
    bossexpTex,
    enemyexpTex,
    graczexpTex,
    hitexpTex,
    HPTex
};
class Texturesinit
{
 std::map<Textures,sf::Texture> tekstury;
  public:
 Texturesinit(){}
 ~Texturesinit(){}

 void addTex(const Textures& texturekey,const std::string& filename)
 {
     if(this->tekstury.find(texturekey)!=this->tekstury.end())
     {
         throw std::invalid_argument("Element exists");
     }
     Texture kupskotekstur;



     this->tekstury.insert(std::pair<Textures,sf::Texture>(texturekey,kupskotekstur));
     this->tekstury[texturekey].loadFromFile(filename);
 }
 sf::Texture* GetTexture(const Textures& texturekey)
 {
     if(this->tekstury.find(texturekey)==this->tekstury.end())
     {
         throw std::out_of_range("Out of scope");
     }
     return  &this->tekstury.at(texturekey);
 }
};
///sounds
enum class Soundbuffers
{
   themebuffer,
   pulsebuffer,
   explosionbuffer,
   gameoverbuffer,
   bossbuffer,
   winbuffer
};
class Soundbuffersinit
{
 std::map<Soundbuffers,sf::Sound> dzwieki;
  public:
 Soundbuffersinit(){}
 ~Soundbuffersinit(){}

 void addBuffer(const Soundbuffers& sbufferkey,const std::string& filename)
 {
     if(this->dzwieki.find(sbufferkey)!=this->dzwieki.end())
     {
         throw std::invalid_argument("Element exists");
     }
     sf::SoundBuffer kupskobuffow;
     if(!kupskobuffow.loadFromFile(filename))
     {
         throw std::invalid_argument("Unable to open file");
     }
     this->dzwieki.insert(std::pair<Soundbuffers,sf::Sound>(sbufferkey,kupskobuffow));
 }
 sf::Sound& GetBuffer(const Soundbuffers& sbufferkey)
 {
     if(this->dzwieki.find(sbufferkey)==this->dzwieki.end())
     {
         throw std::out_of_range("Out of scope");
     }
     return this->dzwieki.at(sbufferkey);
 }
};


#endif // ASSETS_H
