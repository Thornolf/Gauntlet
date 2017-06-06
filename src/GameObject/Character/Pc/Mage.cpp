/*
** Mage.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:28:05 2017 Pierre
** Last update Tue May 30 10:41:19 2017 Pierre
*/

#include "Mage.hpp"

Mage::Mage(int x, int y, int z) : Ranged(x, y, z)
{
  _health = 80;
  _attack = 175;
}

Mage::Mage(Mage const &)
{

}

Mage::Mage& operator=(Mage const &)
{

}

Mage::~Mage()
{

}

void Mage::getDamage()
{

}

void Mage::attack()
{

}

bool Mage::isAlive()
{

}

void Mage::getDistance()
{

}

size_t Mage::getRange()
{

}
