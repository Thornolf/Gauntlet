/*
** Npc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Thu Jun 08 09:06:48 2017 fossae_t
*/

#include "GameObject/Character/Npc/Npc.hpp"

Npc::Npc(int x, int y, int z) : Character(x, y, z)
{
}

Npc::Npc(Npc const & other) : Character(other)
{
  (void) other;
}

Npc& Npc::operator=(Npc const & other)
{
  (void) other;
  return *this;
}

Npc::~Npc()
{

}

void Npc::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  (void)mSceneMgr;
}

Ogre::Vector3 Npc::launchScript(Ogre::SceneManager *mSceneMgr, Ogre::SceneNode *target)
{
  Ogre::Vector3 nextMove = Ogre::Vector3::ZERO;
  (void)mSceneMgr;
  (void)target;
  return (nextMove);
}

void Npc::Animate(const Ogre::FrameEvent& fe)
{
  (void)fe;
  //mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
}

void Npc::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  (void)mSceneMgr;
  //mSceneMgr->destroyEntity(mEntity);
}
