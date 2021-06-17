#ifndef ASSETS_H
#define ASSETS_H
#include "posrednik.h"

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
