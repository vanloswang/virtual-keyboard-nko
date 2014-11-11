/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KRADIOBUTTON_H
#define KRADIOBUTTON_H

#include "KResource.hpp"
#include "KButton.hpp"

class KRadioButton : public KButton{
public :
  KRadioButton(std::wstring text);
  KRadioButton(std::wstring text, int x, int y);
  KRadioButton(std::wstring text, int x, int y, int width, int height);
};

#endif
