/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KLabel.hpp"
KLabel::KLabel(std::wstring text){
  _width = CW_USEDEFAULT;
  _height = CW_USEDEFAULT;
  _x = CW_USEDEFAULT;
  _y = CW_USEDEFAULT;
  _text = text;
  _font = NULL;
  _id = -1;
}
KLabel::KLabel(std::wstring text, int x, int y){
  _width = CW_USEDEFAULT;
  _height = CW_USEDEFAULT;
  _x = x;
  _y = y;
  _text = text;
  _font = NULL;
  _id = -1;
}
KLabel::KLabel(std::wstring text, int x, int y, int w, int h){
  _width = w;
  _height = h;
  _x = x;
  _y = y;
  _text = text;
  _font = NULL;
  _id = -1;
}
