/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KWindow.hpp"

KWindow::KWindow(KApplication *app, const std::wstring name)
{
  _ids_size = FIRST_ID; // arbitrary value
  init_wcx(app->hinstance(), (name.c_str()));
  _title = name;
  _windowName = (name.c_str());
  _className = (name.c_str());
  _hInstance = app->hinstance();
  //_style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
  _style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
  _y = _x = CW_USEDEFAULT;
	
	
  _height = _width = CW_USEDEFAULT;
  _styleEx = 0;
  _hwndParent = 0;
  _hMenu = 0;
  _hwnd = CreateWindow(	_className, 
			_windowName,
			_style,
			CW_USEDEFAULT, 
			CW_USEDEFAULT, 
			CW_USEDEFAULT, 
			CW_USEDEFAULT,
			NULL, 
			NULL, 
			_hInstance, 
			(void *)this);
  _ids_func = std::vector <void ( *) (HWND, WPARAM, LPARAM, KWidget * )>(100);
  _widgets = std::vector <KWidget *>(100);
}

KWindow::KWindow(KApplication *app, const std::wstring name, const int width, const int height)
{
  _ids_size = FIRST_ID;
  init_wcx(app->hinstance(), (name.c_str()));
  _title = name;
  _windowName = (name.c_str());
  _className = (name.c_str()) ;
  _hInstance = app->hinstance();
  //_style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
  _style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
  _y = CW_USEDEFAULT;
  _x = CW_USEDEFAULT;
  _height = height;
  _width = width;
  _styleEx = 0;
  _hwndParent = 0;
  _hMenu = 0;
  _hwnd = CreateWindow(	_className, 
			_windowName,
			_style,
			_x, 
			_y, 
			_width, 
			_height,
			NULL, 
			NULL, 
			_hInstance, 
			(void *)this);
  _ids_func = std::vector <void ( *) (HWND, WPARAM, LPARAM, KWidget * )>(100);
  _widgets = std::vector <KWidget *>(100);
}

KWindow::KWindow(KApplication *app, const std::wstring name, const int x, const int y, const int width, const int height )
{
  _ids_size = FIRST_ID;
  init_wcx(app->hinstance(), (name.c_str()));
  _title = name;
  _windowName = (name.c_str());
  _className = (name.c_str()) ;
  _hInstance = app->hinstance();
  //_style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
  _style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
  _y = y;
  _x = x;
  _height = height;
  _width = width;
  _styleEx = 0;
  _hwndParent = 0;
  _hMenu = 0;
  _hwnd = CreateWindow(	_className, 
			_windowName,
			_style,
			_x ,
			_y, 
			_width, 
			_height,
			NULL, 
			NULL, 
			_hInstance, 
			(void *)this);
  _ids_func = std::vector <void ( *) (HWND, WPARAM, LPARAM, KWidget *)>(100);
  _widgets = std::vector <KWidget *>(100);
}


KWindow::~KWindow()
{
}
void KWindow::show () 
{
  ::ShowWindow (_hwnd, SW_SHOW);
  ::UpdateWindow (_hwnd);
}

bool KWindow::init_wcx(HINSTANCE hinstance, const TCHAR * name)
{
  wcx.style         = CS_HREDRAW | CS_VREDRAW;
  wcx.lpfnWndProc   = KWindow::MessagesRouter;   
  wcx.cbClsExtra    = 0;
  wcx.cbWndExtra    = 0;
  wcx.hInstance     = hinstance;
  wcx.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
  wcx.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wcx.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
  wcx.lpszMenuName  = NULL;
  wcx.lpszClassName = name;
  return (RegisterClass(&wcx) != 0) ? true : false;
}

void KWindow::setTitleBar(const std::wstring title)
{
  if (SetWindowText(_hwnd, (title.c_str())))
    _title = title;
}
std::wstring KWindow::titleBar()
{
  return _title;
}

void KWindow::setTopMost(bool val)
{
  if(val == true){
    if(SetWindowPos(_hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE) != 0)
      _topMost = true;
  }
  else{
    if(SetWindowPos(_hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE) != 0)
      _topMost = false;
  }
}

bool KWindow::topMost()
{
  return _topMost;
}



LRESULT CALLBACK KWindow::MessagesRouter (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  KWindow *wnd = 0;        // pointer to the window that should receive the message

  if (message == WM_NCCREATE) {  
    // if this message gets sent then a new window has just been created,
    // so we'll asociate its handle with its AbstractWindow instance pointer
    ::SetWindowLong (hwnd, GWL_USERDATA, long((LPCREATESTRUCT(lParam))->lpCreateParams));
  }

  // --- messages different from WN_NCCREATE / or WM_NCCREATE was just processed ---
  // we retrieve the instance of AbstractWindow that corresponds to the destination window's HWND
  wnd = (KWindow *) (::GetWindowLong (hwnd, GWL_USERDATA));

  // we then route the message to the wndProc method defined in the derived AbstractWindow class
  if (wnd)
    wnd->wndProc (hwnd, message, wParam, lParam);
  else
    // for messages that arrive prior to WM_NCCREATE
    // and the HWND <-> AbstractWindow * association was not made
    return ::DefWindowProc (hwnd, message, wParam, lParam);
}

LRESULT CALLBACK KWindow::wndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  UINT iId=LOWORD(wParam);
  //HWND hCtl=(HWND)lParam;
  HWND hwndGetFocus = (HWND) wParam;
  switch (message)
    {
    case WM_CREATE:
      return 0;
    case WM_KILLFOCUS:
      hwndGetFocus = (HWND) wParam;
      SetActiveWindow(hwndGetFocus);
      return 0;
    case WM_COMMAND:
      for(unsigned int i=FIRST_ID; i<_ids_size; i++){
	if (iId == i){
	  _ids_func[i-FIRST_ID](hwnd, wParam, lParam,_widgets[i-FIRST_ID]);
	  break;
	}
      }
      return 0;
    case WM_DESTROY:
      ::PostQuitMessage (0);
      return 0;
    default:
      return ::DefWindowProc (hwnd, message, wParam, lParam);
    }
}

void KWindow::addWidget(KPushButton *b)
{
  b->setId(_ids_size);
  _ids_size++;
  _ids_func.push_back(NULL);
  _widgets.push_back(NULL);
  b->setHwnd (CreateWindow(	KText("BUTTON"),
				(b->text().c_str()),
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
				b->x(),
				b->y(),
				b->width(),
				b->height(),
				_hwnd,
				(HMENU)b->id(),
				_hInstance,
				NULL));
}
void KWindow::addWidget(KCheckBox *b)
{
  b->setId(_ids_size);
  _ids_size++;
  _ids_func.push_back(NULL);
  _widgets.push_back(NULL);
  b->setHwnd (CreateWindow(	KText("BUTTON"),
				(b->text().c_str()),
				WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX,
				b->x(),
				b->y(),
				b->width(),
				b->height(),
				_hwnd,
				(HMENU)b->id(),
				_hInstance,
				NULL));
}

void KWindow::addWidget(KRadioButton *b)
{
  b->setId(_ids_size);
  _ids_size++;
  _ids_func.push_back(NULL);
  _widgets.push_back(NULL);
  b->setHwnd (CreateWindow(	KText("BUTTON"),
				(b->text().c_str()),
				WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,
				b->x(),
				b->y(),
				b->width(),
				b->height(),
				_hwnd,
				(HMENU)b->id(),
				_hInstance,
				NULL));	
}

void KWindow::addWidget(KLabel * b)
{
  b->setId(_ids_size);
  _ids_size++;
  _ids_func.push_back(NULL);
  _widgets.push_back(NULL);

  b->setHwnd (CreateWindow(	KText("STATIC"),
				(b->text().c_str()),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP|SS_CENTER|SS_CENTERIMAGE,
				b->x(),
				b->y(),
				b->width(),
				b->height(),
				_hwnd,
				(HMENU)b->id(),
				_hInstance,
				NULL));	
}

void KWindow::addNewFunction(KWidget *w, void (*f)(HWND, WPARAM, LPARAM,KWidget * ))
{
  _ids_func[w->id()-FIRST_ID] = (f);	
  _widgets[w->id()-FIRST_ID] = w;
}


