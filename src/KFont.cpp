/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KFont.hpp"

KFont::KFont()
{

}

KFont::KFont(std::wstring path, std::wstring fontname)
{
  AddFontResource ((path.c_str()));
  SendMessage(   HWND_BROADCAST,   WM_FONTCHANGE, 0, 0 );
  _hfont =  CreateFont(	0, 
			0, 
			0, 
			0, 
			0, 
			0, 
			0, 
			0, 
			DEFAULT_CHARSET, 
			OUT_DEFAULT_PRECIS, 
			CLIP_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, 
			DEFAULT_PITCH | FF_DONTCARE, 
			fontname.c_str());	   
}

HFONT KFont::hfont()
{
  return _hfont;
}
