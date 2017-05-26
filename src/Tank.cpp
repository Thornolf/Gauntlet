/*
** Tank.cpp for Tank in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 15:37:31 2017 Adrien Warin
** Last update Fri May 26 14:18:58 2017 Adrien Warin
*/

Tank::Tank(int x, int y, int z)
{
    this->_hp = 150;
    this->attack = 50;
}

Tank::Tank(Tank const & other)
{
    this->_hp = other.hp;
    this->_attack = other.attack;
}

Tank::Tank& operator=(Tank const & other)
{
    this->_hp = other.hp;
    this->_attack = other.attack;
    return (*this);
}

Tank::~Tank()
{

}

void Tank::getDamage(int damage)
{
    this->_hp -= damage;
}

void Tank::attack()
{

}

bool Tank::isAlive()
{

}

void Tank::getDistance()
{

}

size_t Tank::getRange()
{

}
