#ifndef _IRESOURCES_HPP_
#define _IRESOURCES_HPP_

/* The IResources interface handle visibility of Textures, Meshes & Animations*/

class IResources {
public:
  virtual void  hide(void);
  virtual void  display(void);
  virtual ~IResources () {}
};

#endif  /* !_IRESOURCES_HPP_ */
