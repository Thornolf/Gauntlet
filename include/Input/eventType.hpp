/*
** eventType.hpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 09:00:10 2017 Guillaume CAUCHOIS
** Last update Wed May 31 09:00:10 2017 Guillaume CAUCHOIS
*/

#ifndef		_EVENT_TYPE__H_
# define	_EVENT_TYPE__H_

typedef enum	eventType
{
  EVENT_TYPE_MIN = 0,
  MOVE_UP = 0,
  MOVE_DOWN,
  MOVE_LEFT,
  MOVE_RIGHT,
  EVENT_TYPE_MAX = MOVE_RIGHT
}		eventType;

#endif		/* _EVENT_TYPE__H_ */