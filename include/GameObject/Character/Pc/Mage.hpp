/*
** Mage.hpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/include
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:26:19 2017 Pierre
** Last update Fri Jun 16 14:36:41 2017 Pierre
*/

#ifndef		_MAGE__HPP_
# define	_MAGE__HPP_

# include	<iostream>
# include	"Pc.hpp"
# include	"GameObject/Character/Pc/Ranged.hpp"

class Mage : public Ranged
{
public:
  Mage(const std::string &, int x, int y, int z);
  Mage(Mage const &);
  Mage& operator=(Mage const &);
  virtual ~Mage();

  void		setOgreBase(Ogre::SceneManager*);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);
};

#endif		/* !_MAGE__HPP_ */
