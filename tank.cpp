#include "tank.h"
#include <iostream>
#include <cstring>
#include "bullet.h"

using namespace std;

Tank::Tank(int hp,int dmg,std::string name): m_hp(hp), m_damage(dmg),m_name(name) //список ініціалізації
{
    string array[11]={"t1","t2","t3","t4","t5","t6","t7","t8","t9","t10","t11"};//massive symbols
    if(hp<0){
        hp = -1*hp;
    }
    m_hp = hp;
    if(dmg<0){
        dmg = -1*dmg;
    }
    m_damage = dmg;
    int a = rand()%11;
    name = array[a];
    m_name = name;
    m_position.x = rand()%50;
    m_position.y = rand()%50;
   //m_pWeapon = new char[50];
    //strcpy(m_pWeapon,"miniGun");
}

Tank::Tank(const Tank &othertank)
{
    m_hp = othertank.m_hp;
    m_damage = othertank.m_damage; //передати танк в конструктор
    m_name = othertank.m_name;
    cout<<"copy const"<<endl;

}
Tank::~Tank(){
    //cout<<"<Destructor for T:"<<endl;
    //delete [] m_pWeapon;
};

void Tank::shoot(Tank &othertank)
{
    othertank.m_hp -= this->m_damage;
}

void Tank::show() const
{
    cout<<"Name = "<<m_name<<endl;
    cout<<"HP = "<<m_hp<<endl;
    cout<<"DMG = "<<m_damage<<endl;
}

void Tank::live_tank()
{
    if(m_hp <= 0){
        cout<<"Tank dead "<<m_name<<endl;
    }
    else {
        cout<<"Tank live "<<m_name<<endl;
    }
}

Tank *amount_tanks( int amount){
    cout<<"amount tanks "<<amount<<endl<<endl;
    Tank *mas_tanks = new Tank[amount];
    for (int i=0;i<amount;i++) {
        //mas_tanks[i].show();
        //mas_tanks[i].showPosition();
        //cout<<endl<<endl;
    }
    return mas_tanks;
}

void Tank::showPosition() const{
    cout<<"Pos X = "<<m_position.x<<endl;
    cout<<"Pos Y = "<<m_position.y<<endl;
};

void deleteTanks(Tank *pTanks){
    delete [] pTanks ;
};

void Tank::move()
{
    int moveVectorX = rand()%3-1;
    int moveVectorY = rand()%3-1;
    m_position.x+=moveVectorX;//+1 0 -1
    m_position.y+=moveVectorY;
}

Point Tank::getCoord() const
{
    return m_position;
}
Tank Tank::operator+(int hp){

    Tank newtank(*this);
    newtank.m_hp+=hp;
    return newtank;
};
Tank& Tank::operator=(const Tank & othertank){
    if(this==&othertank)
    {
        return *this;
    }
    m_hp = othertank.m_hp;
    m_damage = othertank.m_damage;
    m_position = othertank.m_position;
    m_name = othertank.m_name;
    return *this;
}
Tank Tank::operator-(int hp){

    Tank newtank(*this);
    newtank.m_hp-=hp;
    return newtank;

};
Tank Tank::operator+=(int hp){

    m_hp += hp;
    return *this;
};
Tank Tank::operator-=(int hp){
    m_hp -= hp;
    return *this;

};
