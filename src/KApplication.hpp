/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KAPPLICATION_H
#define KAPPLICATION_H

#include "KResource.hpp"
#include "Nko.hpp"

extern bool activate;
extern bool shift;
extern unsigned int KANJAMADI;
extern unsigned int PHONETIC;
extern unsigned int keyboard;

class KApplication
{
public :
  KApplication(HINSTANCE h);
  KApplication(HINSTANCE h, int argc, char ** argv);
  int exec();
  int argc();
  char ** argv();
  HINSTANCE hinstance();
  static LRESULT CALLBACK HookProc ( int nCode, WPARAM wParam, LPARAM lParam);

private : // later protected
  int _argc;
  char ** _argv;
  // common controls.
  INITCOMMONCONTROLSEX _icc;
  HINSTANCE _hinstance;
};

#endif
