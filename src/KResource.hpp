/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#ifndef KRESOURCE_H
#define KRESOURCE_H

#ifndef UNICODE
#define UNICODE
#endif // UNICODE
#ifndef _UNICODE
#define _UNICODE
#endif // _UNICODE

#ifndef _WIN32_IE 
#define _WIN32_IE 0x0500
#endif
#ifndef WINVER
#define WINVER 0x0500
#endif

#ifndef _KTEXT
#define KText(str) (TEXT(str))
#endif // KTEXT

#define FIRST_ID 117

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <stdio.h>
#include <vector>
#include <windows.h>
#include <commctrl.h>
#include <ctime>
typedef std::basic_string<WCHAR> wstring;

#endif
