/*
** MapManager.cpp for  in /home/baudet_q/rendu/CPP/cpp_indie_studio/src/Parsing
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed May 31 15:48:44 2017 Quentin Baudet
** Last update Wed May 31 16:28:02 2017 Quentin Baudet
*/

#include "MapManager.hpp"

/**
 * Constructor MapManager
 * @param path
 */
MapManager::MapManager(std::string path)
{
  this->_path		= path;
  this->_tree		= new t_ast_node(new std::vector<struct s_ast_node*>);
  this->_tree->lexeme	= "HEAD";
  this->_tree->value	= path;
  this->_tree->type	= ASTNodeType::HEAD;
}

/**
 * Destructor MapManager
 */
MapManager::~MapManager() {}

/**
 * Permit to append a new line to the _buffer variable (use for generate the AST)
 * @param lineToAppend
 */
void	MapManager::feed(const std::string &line)
{
  if (line.find_first_of("#", 0, 1) == std::string::npos && !line.empty())
    this->_buffer.push_back(line);
}

/**
 * Permit to open the file specified in the constructor
 * Append each line of the file in the _buffer variable via feed method
 */
void	MapManager::loadFromFile(void)
{
  std::ifstream		cfgFile(this->_path);

  if (!cfgFile.is_open())
    throw IndieException("Cannot load the map " + this->_path);
  for (std::string line; std::getline(cfgFile, line);)
    this->feed(line);
}

void	MapManager::computeAbstractTree(void)
{
  t_ast_node	*current_section = nullptr;

  this->loadFromFile();
  for (auto it = this->_buffer.begin(); it != this->_buffer.end(); ++it)
  {
    if (this->isSectionDeclaration(*it))
      current_section = this->addSectionASTNode(*it);
    else if (current_section != nullptr)
    {
      if (this->isObjectDeclaration(*it))
	this->addObjectASTNode(current_section, *it);
      else if (this->isParameterDeclaration(*it))
	this->addParameterASTNode(current_section, *it);
      else
	throw IndieException("Invalid file format at line \"" + *it + "\"");
    }
    else
      throw IndieException("You need to put the line \"" + *it + "\" in a section");
  }
}

void	MapManager::ObjASTNodeToGameObj(RenderManager &rManager, t_ast_node *object)
{
  Position		pos;
  Position		scale;
  std::string		texture;
  std::string		name;
  std::string		ObjectType;
  Ogre::Quaternion	orientation;

  if (object == nullptr)
    throw IndieException("Cannot null ast node");
  for (auto it_objField = object->children->begin(); it_objField != object->children->end(); ++it_objField)
  {
    if ((*it_objField)->type == ASTNodeType::NAME)
      name = (*it_objField)->value;
    else if ((*it_objField)->type == ASTNodeType::TYPE)
      ObjectType = (*it_objField)->value;
    else if ((*it_objField)->type == ASTNodeType::POSITION)
      pos.stringToPosition((*it_objField)->value);
    else if ((*it_objField)->type == ASTNodeType::SCALE)
      scale.stringToPosition((*it_objField)->value);
    else if ((*it_objField)->type == ASTNodeType::ORIENTATION)
      orientation = stringToOgreQuaternion((*it_objField)->value);
    else if ((*it_objField)->type == ASTNodeType::TEXTURE)
      texture = (*it_objField)->value;
    else
      throw IndieException("Invalid AST data found");
  }
  rManager.createGameObject(ObjectType, pos, scale, orientation, texture);
}

bool		MapManager::stringIsNumber(char *line) const
{
  int		i = -1;

  if (line[0] == '-')
    i = 0;
  while (line[++i])
  {
    if (i != 0 && line[i] < '0' || line[i] > '9')
      return (false);
  }
  return (true);
}

Ogre::Quaternion	MapManager::stringToOgreQuaternion(const std::string &line) const
{
  char		*part;
  char		*line_c = new char[line.length() + 1];
  double	w, x, y, z;

  std::strcpy(line_c, line.c_str());
  part = std::strtok(line_c, ",");
  if (!part || !stringIsNumber(part))
    return Ogre::Quaternion(0, 0, 0, 0);
  w = std::atof(part);
  part = std::strtok(NULL, ",");
  if (!part || !stringIsNumber(part))
    return Ogre::Quaternion(0, 0, 0, 0);
  x = std::atof(part);
  part = std::strtok(NULL, ",");
  if (!part || !stringIsNumber(part))
    return Ogre::Quaternion(0, 0, 0, 0);
  y = std::atof(part);
  part = std::strtok(NULL, ",");
  if (!part || !stringIsNumber(part))
    return Ogre::Quaternion(0, 0, 0, 0);
  z = std::atof(part);
  delete[] line_c;
  return (Ogre::Quaternion(Ogre::Real(w), Ogre::Real(x), Ogre::Real(y), Ogre::Real(z)));
}

/**
 * Compute a map from the datas store in the _ast
 */
void	MapManager::generateMap(RenderManager &rManager)
{
  if (!this->_tree)
    throw IndieException("The AST has not been computed");
  for (auto it_section = this->_tree->children->begin(); it_section != this->_tree->children->end(); ++it_section)
  {
    if ((*it_section)->value == "OBJECTS")
    {
      for (auto it_object = (*it_section)->children->begin(); it_object != (*it_section)->children->end(); ++it_object)
	this->ObjASTNodeToGameObj(rManager, *it_object);
    }
    if ((*it_section)->value == "OPTIONS")
    {
      for (auto it_object = (*it_section)->children->begin(); it_object != (*it_section)->children->end(); ++it_object)
	this->_options[(*it_object)->lexeme] = (*it_object)->value;
    }
  }
}

/**
 * Does the line pass in param math with the format "[ALPHANUM]" ?
 * @param line
 * @return status_match
 */
bool	MapManager::isSectionDeclaration(const std::string &line) const
{
  std::regex	regex(REGEX_SECTION);
  return (std::regex_match(line, regex));
}

/**
 * Does the line pass in param math with the format of object declaration ?
 * @param line
 * @return status_match
 */
bool	MapManager::isObjectDeclaration(const std::string &line) const
{
  std::regex	regex(REGEX_OBJECT);
  return (std::regex_match(line, regex));
}

/**
 * Does the line pass in param math with the format of parameter declaration ?
 * @param line
 * @return status_match
 */
bool	MapManager::isParameterDeclaration(const std::string &line) const
{
  std::regex	regex(REGEX_PARAM);
  return (std::regex_match(line, regex));
}

std::string	MapManager::getSectionName(const std::string &line) const
{
  size_t	pos_s;
  size_t	pos_e;

  if ((pos_s = line.find_first_not_of("[")) == std::string::npos)
    return "";
  if ((pos_e = line.find_last_not_of("]")) == std::string::npos)
    return "";
  return (line.substr(pos_s, pos_e));
}

/**
 * Add a Section Node to the Abstract Tree _tree
 * @param line
 * @return current_section
 */
t_ast_node	*MapManager::addSectionASTNode(const std::string line)
{
  t_ast_node	*section_node = nullptr;

  section_node = new t_ast_node(new std::vector<struct s_ast_node*>);
  section_node->type = ASTNodeType::SECTION;
  section_node->value = this->getSectionName(line);
  section_node->lexeme = "SECTION";
  this->_tree->children->push_back(section_node);
  return (section_node);
}

/**
 * Add a Section Node to the Abstract Tree _tree
 * @param line
 * @return current_section
 */
void	MapManager::addParameterASTNode(t_ast_node *section, const std::string &line)
{
  t_ast_node	*section_node = nullptr;
  std::string	lexeme;
  std::string	value;
  std::regex	regex_lexeme("^[A-Z_]*");
  std::regex	regex_value("[A-Za-z0-9_\\/\\-.]*$");
  std::smatch	match;

  if (!std::regex_search(line.begin(), line.end(), match, regex_lexeme))
    return ;
  lexeme = match[0];
  if (!std::regex_search(line.begin(), line.end(), match, regex_value))
    return ;
  value = match[0];
  section_node = new t_ast_node(new std::vector<struct s_ast_node*>);
  section_node->type = ASTNodeType::SECTION;
  section_node->lexeme = lexeme;
  section_node->value = value;
  section->children->push_back(section_node);
}

/**
 * Permit to get an information form a Object Declaration
 * (TYPE/NAME/POSITION/SCALE/TEXTURE) line format
 * @param line
 * @param field
 * @return field_information
 */
std::string	*MapManager::getFieldFromObjectDeclarationLine(const std::string &line, ObjectField field) const
{
  char					*line_c = new char[line.length() + 1];
  char					*tok;
  std::map<int, std::string>		objectInformations;
  std::stringstream			ss;
  std::string				*res;
  int					pos = 0;

  std::strcpy(line_c, line.c_str());
  tok = std::strtok(line_c, " \t");
  while (tok)
  {
    ss << tok;
    objectInformations.insert(std::make_pair(pos, ss.str()));
    ss.clear();
    ss.str("");
    tok = std::strtok(NULL, " \t");
    pos++;
  }
  if (objectInformations.size() < field)
    throw IndieException("Invalid line");
  res = new std::string(objectInformations[field]);
  delete[] line_c;
  return (res);
}

/**
 * Permit to add an ObjectField node to a Object node on the AST
 * @param objectNode
 * @param line
 * @param typeObject
 * @param nodeTypeObject
 */
void		MapManager::addObjectFieldASTNode(t_ast_node *objectNode, const std::string &line,
						      ObjectField type, ASTNodeType nodeType) const
{
  std::string	*field_value		= nullptr;
  t_ast_node	*object_field		= nullptr;

  object_field = new t_ast_node(new std::vector<struct s_ast_node*>);
  object_field->type = nodeType;
  field_value = this->getFieldFromObjectDeclarationLine(line, type);
  object_field->lexeme = "ObjectField";
  object_field->value = *field_value;
  objectNode->children->push_back(object_field);
  delete field_value;
}

/**
 * Add an Object Node to the Abstract Tree _tree
 * @param line
 * @return current_section
 */
void		MapManager::addObjectASTNode(t_ast_node *section, const std::string line)
{
  t_ast_node	*object			= nullptr;

  object = new t_ast_node(new std::vector<struct s_ast_node*>);
  object->type = ASTNodeType::OBJECT;
  object->lexeme = "Object";
  object->value = line;
  this->addObjectFieldASTNode(object, line, ObjectField::TYPE, ASTNodeType::TYPE);
  this->addObjectFieldASTNode(object, line, ObjectField::NAME, ASTNodeType::NAME);
  this->addObjectFieldASTNode(object, line, ObjectField::POSITION, ASTNodeType::POSITION);
  this->addObjectFieldASTNode(object, line, ObjectField::ORIENTATION, ASTNodeType::ORIENTATION);
  this->addObjectFieldASTNode(object, line, ObjectField::SCALE, ASTNodeType::SCALE);
  this->addObjectFieldASTNode(object, line, ObjectField::TEXTURE, ASTNodeType::TEXTURE);
  section->children->push_back(object);
}

std::string	MapManager::getOption(const std::string &label)
{
  if (this->_options.find(label) == this->_options.end())
    return ("");
  return (this->_options[label]);
}