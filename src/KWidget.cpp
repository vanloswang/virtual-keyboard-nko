/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KWidget.hpp"

KWidget::KWidget()
{
}

int KWidget::height ()
{
  return _height;
}

int KWidget::width  ()
{
  return _width;
}
int KWidget::x  ()
{
  return _x;
}
int KWidget::y  ()
{
  return _y;
}

void KWidget::hide(bool val)
{
  if(val == true){
    if(SetWindowPos(_hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_HIDEWINDOW) != 0)
      _hide = true;
  }
  else{
    if(SetWindowPos(_hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW) != 0)
      _hide = false;
  }
}

void KWidget::setX (int x)
{
  if(SetWindowPos(_hwnd, HWND_TOP, x, _y, _width, _height, SWP_NOZORDER | SWP_NOSIZE) != 0)
    _x = x;
}
void KWidget::setY (int y)
{
  if(SetWindowPos(_hwnd, HWND_TOP, _x, y, _width, _height, SWP_NOZORDER | SWP_NOSIZE) != 0)
    _y = y;
}

void KWidget::resize(int width, int height)
{
  if(SetWindowPos(_hwnd, HWND_TOP, _x, _y, width, height, SWP_NOZORDER | SWP_NOMOVE) != 0){
    _width = width;
    _height = height;
  }
}

std::wstring  KWidget::text()
{
  return _text;
}
 
void KWidget::setText(std::wstring text){
  _text = text;
  SetWindowText(_hwnd, text.c_str());
}

void KWidget::setFont(KFont* font){
  _font = font;
  if(_hwnd != NULL)
    SendMessage (_hwnd, WM_SETFONT, (WPARAM)font->hfont(), TRUE);
}

void KWidget::setColor(unsigned int a, unsigned int b, unsigned int c){
  if(_hwnd != NULL){
    HDC hdc = GetDC(_hwnd);
    SetBkColor (hdc, RGB(0, 0, 255));
    ReleaseDC(_hwnd, hdc);
  }
}



void KWidget::setHwnd(HWND h)
{
  _hwnd = h;
}

HWND KWidget::hwnd()
{
  return _hwnd;
}

HINSTANCE KWidget::hinstance()
{
  return _hInstance;
}

KFont* KWidget::font()
{
  return _font;
}


int KWidget::id()
{
  return _id;
}

void KWidget::setId(int id)
{
  _id = id;
}
