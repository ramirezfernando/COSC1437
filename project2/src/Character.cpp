#include "Character.h"
#include "Textures.h"


void Character::Update() 
{
    
    // implement movement animation
    if (count <= frames)
    {
        // conversions because "LoadTexture" takes a "const char*" as input
        // ex path = "assests/FireKnight/1_atk"
        // then filename would be "assests/FireKnight/1_atk/(count).png"
        string filename = path+"/"+ to_string(count) + ".png";
        const char* file = filename.c_str();
        /*
        if (enemy) 
        {
            // invert image
        }
        */
        //else
        //{
            characterTexture = Textures::LoadTexture(file);
        //}
        SDL_Delay(speed);
        count++;
    } 
    else if (repeat) 
    {
        // count = 1 because all my file names start at 1
        count = 1;
    }
   

    srcRect.h = 200;
    srcRect.w = 300;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w * 2;
}


void Character::Render()
{
    SDL_RenderCopy(Game::renderer, characterTexture, &srcRect, &destRect);
}

void Character::Clean()
{
    SDL_DestroyTexture(characterTexture);
}
// Setters 
void Character::SetTexture(const char* texture)
{
    characterTexture = Textures::LoadTexture(texture);
}
void Character::SetSourceRect(SDL_Rect src)
{
    srcRect = src;
}
void Character::SetDestinationRect(SDL_Rect dest)
{
    destRect = dest;
}
void Character::SetXPos(int x)
{
    xpos = x;
}
void Character::SetYPos(int y)
{
    ypos = y;
}
void Character::SetPath(string _path)
{
    path = _path;
}
void Character::SetFrames(int _frames)
{
    frames = _frames;
}
void Character::SetSpeed(int _speed)
{
    speed = _speed;
}
void Character::SetCount(int _count)
{
    count = _count;
}
void Character::SetRepeat(bool _repeat)
{
    repeat = _repeat;
}
void Character::SetName(string _name)
{
    name = _name;
}
void Character::SetLevel(int _level)
{
    level = _level;
}
void Character::SetHealth(int _health)
{
    health = _health;
}
void Character::SetEnemy(bool _enemy)
{
    enemy = _enemy;
}

// Getters
string Character::GetPath()
{
    return path;
}
int Character::GetFrames()
{
    return frames;
}
int Character::GetSpeed()
{
    return speed;
}
int Character::GetCount()
{
    return count;
}
bool Character::GetRepeat()
{
    return repeat;
}
string Character::GetName()
{
    return name;
}
int Character::GetLevel()
{
    return level;
}
int Character::GetHealth()
{
    return health;
}
bool Character::GetEnemy()
{
    return enemy;
}
// Save/Load data 
void Character::SaveProgress()
{

}
void Character::LoadProgress(string file)
{

}