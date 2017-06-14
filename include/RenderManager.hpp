/*
** RenderManager.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 07 13:19:02 2017 Guillaume CAUCHOIS
** Last update Wed Jun 07 13:19:02 2017 Guillaume CAUCHOIS
*/

#ifndef		_RENDER_MANAGER__HPP_
# define	_RENDER_MANAGER__HPP_
# include	<map>
# include	<algorithm>
# include	<string>
# include	<functional>
# include	"IndieException.hpp"


/* GameObject / Character */
# include	"GameObject/GameObject.hpp"
# include	"GameObject/Character/Character.hpp"
/* PC */
# include	"GameObject/Character/Pc/Pc.hpp"
# include	"GameObject/Character/Pc/Tank.hpp"
# include	"GameObject/Character/Pc/Warrior.hpp"
# include	"GameObject/Character/Pc/Archer.hpp"
# include	"GameObject/Character/Pc/Mage.hpp"
/* NPC */
# include	"GameObject/Character/Npc/Npc.hpp"
# include	"GameObject/Character/Npc/Boss.hpp"
# include	"GameObject/Character/Npc/Skeleton.hpp"
# include	"GameObject/Character/Npc/Zombie.hpp"
# include	"GameObject/Character/Npc/Spawner.hpp"
/* LOOT */
# include	"GameObject/Loot/foodStack.hpp"
# include	"GameObject/Loot/goldStack.hpp"
# include	"GameObject/Doodad/Doodad.hpp"

class RenderManager
{
public:
  /* Canonical functions */
  RenderManager();
  virtual ~RenderManager();

  /* Public member functions */
  GameObject	*createGameObject(const std::string &, const Position &pos, const Position &scale, const std::string &texture);

  /* GameObject unit Factory */
  GameObject	*createDoodadObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createZombieObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createBossObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createSkeletonObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createSpawnerObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createFoodObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createGoldObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createWarriorObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createMageObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createArcherObject(int, const Position &, const Position &, const std::string &);
  GameObject	*createTankObject(int, const Position &, const Position &, const std::string &);

  /* _entities utils */
  std::vector<GameObject *>	&getEntitiesVector(void);

  template <typename UnaryFunction>
  void		forEachEntity(UnaryFunction f)
  {
    std::for_each(this->_entities.begin(), this->_entities.end(), f);
  }

private:
  /* Private attributs */
  std::map<std::string, std::function<GameObject*(int, const Position &, const Position &, const std::string &)> >	_factory;
  std::vector<GameObject *>	_entities;
};

#endif		/* _RENDER_MANAGER__HPP_ */