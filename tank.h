#ifndef TANK_H
#define TANK_H
#include <string>
class Bullet
{
    std::string m_material;
public:
    Bullet(): m_material("wooden"){}

};


struct  Point
{
    int x;
    int y;    //у структури не ставити спеифікатор доступу всі поля public наслідування у структури паблик у класах privat
};

class Tank
{
    int m_hp;
    int m_damage;
    Point m_position;
    std::string m_name;
    //char *m_pWeapon;
public:
    Tank(int hp = 50+rand()%50,int dmg = 25+rand()%25, std::string  name ="");
    Tank(const Tank &othertank);
    ~Tank();
    Tank& operator=(const Tank &othertank);
    Tank operator+(int hp);
    Tank operator-(int hp);
    Tank operator+=(int hp);
    Tank operator-=(int hp);
    void shoot(Tank &othertank);
    void show() const;
    void live_tank();
    void showPosition() const;
    void move();
    Point getCoord() const;


};
Tank *amount_tanks(int amount);
void deleteTanks(Tank *pTanks);

#endif // TANK_H
