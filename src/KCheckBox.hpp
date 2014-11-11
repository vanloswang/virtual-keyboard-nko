/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KCHECKBOX_H
#define KCHECKBOX_H

#include "KResource.hpp"
#include "KButton.hpp"

class KCheckBox : public KButton{
public :
  KCheckBox(std::wstring text);
  KCheckBox(std::wstring text, int x, int y);
  KCheckBox(std::wstring text, int x, int y, int width, int height);
};

#endif
