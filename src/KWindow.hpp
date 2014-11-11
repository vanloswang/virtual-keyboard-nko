/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KWINDOW_H
#define KWINDOW_H

#include "KResource.hpp"
#include "KApplication.hpp"
#include "KWidget.hpp"
#include "KPushButton.hpp"
#include "KCheckBox.hpp"
#include "KLabel.hpp"
#include "KRadioButton.hpp"

class KWindow : public KWidget{
private :
  std::vector <void ( *) (HWND, WPARAM , LPARAM, KWidget * )> _ids_func;
  std::vector <KWidget *> _widgets;
  unsigned int _ids_size;
protected :
  WNDCLASS wcx;
  std::wstring _title;
  bool _topMost;
  bool init_wcx(HINSTANCE hinstance, const  TCHAR * name);
public:
  KWindow(KApplication *app, const std::wstring name);
  KWindow(KApplication *app, const std::wstring name, const int width, const int height);
  KWindow(KApplication *app, const std::wstring name, const int x, const int y, const int width, const int height);
  ~KWindow();
  // this will be WNDCLASSEX::lpfnWndProc
  static LRESULT CALLBACK MessagesRouter (HWND, UINT, WPARAM, LPARAM);
  void show ();
  void setTitleBar(const std::wstring title);
  std::wstring titleBar();
  void setTopMost(bool val);
  bool topMost();
  void addWidget(KPushButton *b);
  void addWidget(KCheckBox *b);
  void addWidget(KRadioButton *b);
  void addWidget(KLabel * l);
  void addNewFunction(KWidget *w, void (*f)(HWND, WPARAM, LPARAM,KWidget *));
  std::vector <unsigned int > ids();
  // this is the actual window procedure
  // this will be implemented in derived classes and will be called by messagesRouter
  LRESULT CALLBACK wndProc (HWND, UINT, WPARAM, LPARAM) ;

};

#endif
