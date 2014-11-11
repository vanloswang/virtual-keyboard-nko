/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KApplication.hpp"
HHOOK _hHook;
KApplication::KApplication(HINSTANCE h)
{
  _argc = 0;
  _argv = 0; 
  _icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  _icc.dwICC = ICC_WIN95_CLASSES;
  InitCommonControlsEx(&_icc);
  _hinstance = h;
  _hHook= SetWindowsHookEx( WH_KEYBOARD_LL, (HOOKPROC) HookProc, _hinstance, 0); 
}
 
KApplication::KApplication(HINSTANCE h, int argc, char **argv)
{
  _argc = argc;
  _argv = argv; 
  _hinstance = h;
  _icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  _icc.dwICC = ICC_WIN95_CLASSES;
  InitCommonControlsEx(&_icc);
  _hHook= SetWindowsHookEx( WH_KEYBOARD_LL, (HOOKPROC) HookProc, _hinstance, 0);
}
 
 
int KApplication::exec()
{
  MSG  msg;
  int status;
  while ((status = ::GetMessage (&msg, 0, 0, 0 )) != 0)
    {
      if (status == -1) {
	// handle the error, break
	break;
      }
      ::TranslateMessage (&msg);
      ::DispatchMessage (&msg);                              
    }
  UnhookWindowsHookEx(_hHook);
  return msg.wParam;
}


int KApplication::argc()
{
  return _argc;
}

char ** KApplication::argv()
{
  return _argv;
}

HINSTANCE KApplication::hinstance()
{
  return _hinstance;
}



LRESULT CALLBACK KApplication::HookProc ( int nCode, WPARAM wParam, LPARAM lParam)
{
  // check that a key is down
  if ((nCode == HC_ACTION) && (wParam == WM_KEYDOWN))
    {
      if (activate == true){

	unsigned int code, scancode;
	// get the pointer in structure KBDLLHOOKSTRUCT:
	KBDLLHOOKSTRUCT* hookstruct = ((KBDLLHOOKSTRUCT*)lParam);
	// if there is a correcpndance between the code and the unicode letter 
	// go to others hooks
	code = hookstruct->vkCode;
	scancode = hookstruct->scanCode;
	if((code == VK_PACKET))
	  return CallNextHookEx(_hHook, nCode, wParam, lParam);
	// ensure that the key is not a simulated key
	if(hookstruct->dwExtraInfo!=255){
	  ////////////////////////////////////////////////////////////////////////////////////////////
	  //// CTRL+Q shortcut quit this applicattion
	  unsigned int code = hookstruct->vkCode;
	  // Vérifier si la touche "Q" est appuyée:
	  if(code==0x51 ){
	    if (GetKeyState(VK_SHIFT) & 0x8000)
	      PrintTextOnVK();
	    // ensure that ctrl is down			
	    if(GetKeyState(VK_CONTROL) & 0x8000){
	      // send closed state
	      PostThreadMessage(GetCurrentThreadId(),WM_QUIT,0,0);
	      // avoid others hooks
	      return 1;
	    }
	  }
			
	  ////////////////////////////////////////////////////////////////////////////////////////////
	  printf("%d %d\n", code , scancode); // just for debug purpose
	  // if the key is \in 0 .... 9 ou A ... Z ...
	  if(	((scancode >= 2) && (scancode <= 13)) ||
		((scancode >= 16) && (scancode <= 27)) ||
		((scancode >= 30) && (scancode <= 41)) ||
		((scancode >= 43) && (scancode <= 53))){
	    // if ctrl is down
	    if(GetKeyState(VK_CONTROL) & 0x8000){
	      // do nothing
	    }
	    else {
	      // if shift is down
	      if((GetKeyState(VK_SHIFT) & 0x8000)){
		// simulate the corresponding character
		if(keyboard == KANJAMADI){
		  GenerateUnicodeKeyFromKeyboard(kanjamadi_keyboard(scancode, true));
		}
		else if(keyboard == PHONETIC){
		  // LoadPhoneticKeyboardLayout(true);
		  GenerateUnicodeKeyFromKeyboard(phonetic_keyboard(scancode, true));
		}
	      }
	      // if shift is not down
	      else{
		// simulate the corresponding character
		if(keyboard == KANJAMADI){
		  GenerateUnicodeKeyFromKeyboard(kanjamadi_keyboard(scancode, false));
		}
		else if(keyboard == PHONETIC){
		  GenerateUnicodeKeyFromKeyboard(phonetic_keyboard(scancode, false));
		}
	      }
	    }
	    // avoid others hooks
	    return 1;
	  }	    
	}
      }
    }
  // Renvoi des messages au sytème pour permettre d'autres hooks
  return CallNextHookEx(_hHook, nCode, wParam, lParam);
}


