/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KButton.hpp"
KButton::KButton()
{
  _system_class= KText("BUTTON");
  _id = -1;
}
 

std::wstring   KButton::systemClass(){
  return _system_class;
}

