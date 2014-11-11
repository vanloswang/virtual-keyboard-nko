/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KWIDGET_H
#define KWIDGET_H

#include "KResource.hpp"
#include "KFont.hpp"

class KWidget
{
public :
  KWidget();
  int height ();
  int width ();
  int x ();
  int y ();
  void setX(int x);
  void setY(int y);
  void hide(bool val);
  void resize(int width, int height);
  void setFont(KFont *font);
  void setColor(unsigned int a, unsigned int b, unsigned int c);
  void setHwnd(HWND h);
  KFont* font();
  HWND hwnd();
  HINSTANCE hinstance();
  int id();
  void setId(int id);
  std::wstring text();
  void setText(std::wstring text);
protected :
  std::wstring _text;
  bool _hide;
  int _height;
  int _width;
  int _x;
  int _y;
  HWND _hwnd;
  DWORD _styleEx;
  LPCTSTR _className;
  LPCTSTR _windowName;
  DWORD _style;
  HWND _hwndParent;
  HMENU _hMenu;
  HINSTANCE _hInstance;
  KFont *_font;
  int _id;
};
#endif
