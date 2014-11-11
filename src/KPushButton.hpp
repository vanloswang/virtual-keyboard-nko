/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KPUSHBUTTON_H
#define KPUSHBUTTON_H

#include "KResource.hpp"
#include "KButton.hpp"

class KPushButton : public KButton{
public :
  KPushButton(std::wstring text);
  KPushButton(std::wstring text, int x, int y);
  KPushButton(std::wstring text, int x, int y, int width, int height);
};

#endif
