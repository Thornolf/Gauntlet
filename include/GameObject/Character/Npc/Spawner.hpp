/*
** Spawner.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 07 16:02:23 2017 Guillaume CAUCHOIS
** Last update Wed Jun 07 16:02:23 2017 Guillaume CAUCHOIS
*/

#ifndef		_SPAWNER__H_
# define	_SPAWNER__H_
# include	"RenderManager.hpp"
# include	<ctime>

class RenderManager;

class Spawner : public Npc
{
public:
  /* Canonical functions */
  Spawner(int, int, int, int);
  Spawner(const Spawner &);
  virtual ~Spawner();
  Spawner	&operator=(const Spawner &);

  /* Public member functions */
  void		makeSpawnZombie(RenderManager &rManager) const;
  void		makeSpawnSkeleton(RenderManager &rManager) const;
  void		makeSpawnBoss(RenderManager &rManager) const;
  void		makeSpawnRandomEntity(RenderManager &rManager) const;
};

#endif		/* !_SPAWNER__H_! */