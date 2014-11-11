/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KLABEL_H
#define KLABEL_H

#include "KResource.hpp"
#include "KWidget.hpp"

class KLabel : public KWidget {
public : 
  KLabel(std::wstring text);
  KLabel(std::wstring text, int x, int y);
  KLabel(std::wstring text, int x, int y, int width, int height);
};

#endif //KLABEL_H
