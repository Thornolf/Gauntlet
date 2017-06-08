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
# include	<string>
# include	<functional>
# include	"GameObject/GameObject.hpp"
# include	"GameObject/Character/Character.hpp"
# include	"GameObject/Character/Pc/Pc.hpp"
# include	"GameObject/Character/Pc/Tank.hpp"
# include	"GameObject/Character/Npc/Npc.hpp"
# include	"GameObject/Character/Npc/Boss.hpp"
# include	"GameObject/Character/Npc/Skeleton.hpp"
# include	"GameObject/Character/Npc/Zombie.hpp"
# include	"GameObject/Character/Npc/Spawner.hpp"
# include	"GameObject/Loot/foodStack.hpp"
# include	"GameObject/Loot/goldStack.hpp"

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

private:
  /* Private attributs */
  std::map<std::string, std::function<GameObject*(int, const Position &, const Position &, const std::string &)> >	_factory;
  std::vector<GameObject *>	_entities;
};

#endif		/* _RENDER_MANAGER__HPP_ */