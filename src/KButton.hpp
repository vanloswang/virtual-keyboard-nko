/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KBUTTON_H
#define KBUTTON_H

#include "KResource.hpp"
#include "KWidget.hpp"

class KButton : public KWidget{
public :
  KButton();
  std::wstring systemClass();
protected :
  std::wstring  _system_class;
  int _id;
};

#endif
