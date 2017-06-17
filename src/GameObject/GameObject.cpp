/*
** GameObject.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Fri Jun 16 16:52:47 2017 Thomas Fossaert
*/

#include "GameObject/GameObject.hpp"

GameObject::GameObject(int x, int y, int z)
{
  mPosition = new Position(x, y, z);
  this->_isBusy = false;
}

GameObject::GameObject(GameObject const & other)
{
  mPosition = other.mPosition;
}

GameObject& GameObject::operator=(GameObject const & other)
{
  mPosition = other.mPosition;
  return *this;
}

GameObject::~GameObject() {}

Position*	GameObject::getPosition() const
{
  return (this->mPosition);
}

void	GameObject::hide(void) {}

const std::string& GameObject::getNodeName() const
{
  return (mNodeName);
}

Ogre::Entity* GameObject::getEntity() const
{
  return (mEntity);
}

Ogre::SceneNode* GameObject::getSceneNode() const
{
  return (mNode);
}

void GameObject::setAnimationState()
{
  this->mAnimationState = this->mAnimation->getAnimationState();
}

bool GameObject::isCasted()
{
  float len;

  len = this->_animations[this->_busyAnimation]->getAnimationState()->getLength();
  if (this->_busyAnimation == DIE)
    len = len / 3;
  return (this->mAnimationState->getTimePosition() / this->mAnimationState->getLength() > len);
}

void GameObject::setAnimation(const Ogre::FrameEvent& fe, State state)
{
  if (state == ATTACK || state == DIE)
  {
    if (!this->_isBusy){
      this->_isBusy = true;
      this->_busyAnimation = state;
    }
    this->launchAnimation(fe, state);
  }
  else if (state != ATTACK && state != DIE && this->_isBusy)
  {
    if (isCasted())
    {
      this->_isBusy = false;
      this->launchAnimation(fe, state);
      return ;
    }
    this->mAnimation->addTime(fe.timeSinceLastFrame);
  }
  else{
    this->launchAnimation(fe, state);
  }
}

void GameObject::launchAnimation(const Ogre::FrameEvent& fe, State state)
{
  if (this->mAnimation && (!this->mAnimation->isLooping() || this->mAnimation->hasEnded()))
    {
      this->_animations[state]->launch(fe, this->mEntity);
      this->_state = state;
      this->mAnimation->disable();
      this->mAnimation = this->_animations[state];
      this->mAnimation->enable();
    }
}

void GameObject::destroySpecificEntity(Ogre::SceneManager *mSceneMgr, Ogre::Entity *ent)
{
  mSceneMgr->destroyEntity(ent);
}
