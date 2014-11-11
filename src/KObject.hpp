/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KOBJECT_H
#define KOBJECT_H

#include "KResource.hpp"
#include "KWidget.hpp"
#include "KWindow.hpp"
#include "Nko.hpp"
extern bool activate;
extern bool shift;
class KObject {
public:
  static void quit(HWND, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void help(HWND, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void setTop(HWND, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void clicked(void);
  static void nothing(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void backspace(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void space(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void enter(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void shift_slot(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void tabulation(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void onclick(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w);
  static void connect(KWidget *wid, void (*signal)(void), void (*slot)(HWND, WPARAM, LPARAM,KWidget * ), KWindow *win );
};

#endif
