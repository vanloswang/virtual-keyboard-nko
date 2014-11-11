/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KFONT_H
#define KFONT_H

#include "KResource.hpp"

class KFont
{
public :
  KFont();
  KFont(std::wstring path, std::wstring fontname);
  HFONT hfont();
protected:
  HFONT _hfont;

};
#endif
