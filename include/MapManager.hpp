/*
** MapManager.hpp for cpp_indie_studio
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed May 31 15:49:11 2017 Quentin Baudet
** Last update Wed May 31 16:24:21 2017 Quentin Baudet
*/

#ifndef		_MAP_MANAGER_HPP_
# define	_MAP_MANAGER_HPP_

# define	REGEX_SECTION	"[\\[].*[\\]]"
# define	REGEX_PARAM	"^[A-Z_]*[ \\t]*[A-Za-z0-9_\\/\\-.]*$"
# define	REGEX_OBJECT	"^[ \t]*[A-Za-z0-9]*[ \t]*[A-Za-z0-9]*[ \t]*[0-9]*[,][0-9]*[,][0-9]*[ \t]*[0-9]*[,][0-9]*[,][0-9]*[ \t]*[A-Za-z0-9/.]*$"

# include	<string>
# include	<vector>
# include	<iostream>
# include	<regex>
# include	"GameObject/GameObject.hpp"
# include	"IndieException.hpp"

enum class	ASTNodeType : int
{
  HEAD = -1,
  SECTION = 0,
  OBJECT,
  TYPE,
  NAME,
  POSITION,
  SCALE,
  TEXTURE
};

typedef enum	ObjectField
{
  TYPE = 0,
  NAME,
  POSITION,
  SCALE,
  TEXTURE
}		ObjectField;

typedef enum	ObjectType
{
  WALL = 0,
  DOOR,
  ZOMBIE,
  BOSS,
  SKELTON,
  SPAWNER,
  PLAYER_1,
  PLAYER_2,
  PLAYER_3,
  PLAYER_4,
  FOOD,
  GOLD,
  TRAP
}		ObjectType;

typedef struct	s_ast_node
{
  s_ast_node(std::vector<struct s_ast_node*> *children) : children(children) {}

  ASTNodeType				type;
  std::string				lexeme;
  std::string				value;
  std::vector<struct s_ast_node *>	*children;
}		t_ast_node;

class MapManager
{
public:
  /* Canonical functions */
  MapManager(std::string);
  virtual ~MapManager ();

  /* Public member functions */
  void				computeAbstractTree(void);
  void				generateMap(void);
  std::vector<GameObject>	getGeneratedMap(void) const;
  void				dumpASTContent(void) const;

private:
  /* Loading */
  void	feed(const std::string &line);
  void	loadFromFile();

  /* AST Computation */
  bool		isSectionDeclaration(const std::string &) const;
  bool		isParameterDeclaration(const std::string &) const;
  bool		isObjectDeclaration(const std::string &) const;
  void		addObjectASTNode(t_ast_node *, const std::string);
  void		addParameterASTNode(t_ast_node *section, const std::string &);
  t_ast_node	*addSectionASTNode(const std::string);
  void		addObjectFieldASTNode(t_ast_node *, const std::string &, ObjectField, ASTNodeType) const;

  /* Get Data from Line _buffer */
  std::string	*getFieldFromObjectDeclarationLine(const std::string &, ObjectField) const;
  std::string	getSectionName(const std::string &) const;

private:
  std::string			_path;
  std::vector<std::string>	_buffer;
  std::vector<GameObject>	_map;
  s_ast_node			*_tree;
  std::vector<std::string>	_ground_texture;
};

#endif		/* !_MAP_MANAGER_HPP_ */
