/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KObject.hpp"

void KObject::quit(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  SendMessage(hwnd, WM_DESTROY, 0, 0);
}

void KObject::help(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == false){
    MessageBoxW(NULL, 
		KText("This software was designed by Kaïraba Cissé <ckairaba@gmail.com>."), 
		KText("Copyright"),  
		MB_ICONINFORMATION);
  }
}

void KObject::setTop(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == false){
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    activate = true;;
  }
  else{
    SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    activate = false;
  }
}

void KObject::nothing(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
}

void KObject::backspace(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == true){
    SendMessage(hwnd, WM_KILLFOCUS, 0,0);
    GenerateUnicodeKeyFromKeyboard('\b');
  }
}

void KObject::space(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == true){
    SendMessage(hwnd, WM_KILLFOCUS, 0,0);
    GenerateUnicodeKeyFromKeyboard(' ');
  }
}

void KObject::enter(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == true){
    SendMessage(hwnd, WM_KILLFOCUS, 0,0);
    GenerateUnicodeKeyFromKeyboard('\n');
  }
}

void KObject::shift_slot(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == true){
    shift = (!shift);
    PrintTextOnVK();
  }
}

void KObject::tabulation(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == true){
    SendMessage(hwnd, WM_KILLFOCUS, 0,0);
    GenerateUnicodeKeyFromKeyboard('\t');
  }
}

void KObject::onclick(HWND hwnd, WPARAM wParam, LPARAM lParam,KWidget * w)
{
  if(activate == true){
    SendMessage(hwnd, WM_KILLFOCUS, 0,0);
    if (w->text().compare(KText("RLM")) == 0){ // RLM
      GenerateUnicodeKeyFromKeyboard(RLM);
    }
    else if (w->text().compare(KText("LRM")) == 0){ // LRM
      GenerateUnicodeKeyFromKeyboard(LRM);
    }
    else if (w->text().compare(KText("RLE")) == 0){ // RLE
      GenerateUnicodeKeyFromKeyboard(RLE);
    }
    else if (w->text().compare(KText("LRE")) == 0){ // LRE
      GenerateUnicodeKeyFromKeyboard(LRE);
    }
    else if (w->text().compare(KText("RLO")) == 0){ // RLO
      GenerateUnicodeKeyFromKeyboard(RLO);
    }
    else if (w->text().compare(KText("LRO")) == 0){ // LRO
      GenerateUnicodeKeyFromKeyboard(LRO);
    }
    else if (w->text().compare(KText("PDF")) == 0){ // PDF
      GenerateUnicodeKeyFromKeyboard(PDF);
    }
    else if (w->text().compare(KText("ZWJ")) == 0){ // ZWJ
      GenerateUnicodeKeyFromKeyboard(ZWJ);
    }
    else if (w->text().compare(KText("ZWNJ")) == 0){ // ZWNJ
      GenerateUnicodeKeyFromKeyboard(ZWNJ);
    }
    else if (w->text().compare(KText("LRI")) == 0){ // LRI
      GenerateUnicodeKeyFromKeyboard(LRI);
    }
    else if (w->text().compare(KText("RLI")) == 0){ // RLI
      GenerateUnicodeKeyFromKeyboard(RLI);
    }
    else if (w->text().compare(KText("FSI")) == 0){ // FSI
      GenerateUnicodeKeyFromKeyboard(FSI);
    }
    else if (w->text().compare(KText("PDI")) == 0){ // PDI
      GenerateUnicodeKeyFromKeyboard(PDI);
    }
    else if (w->text().compare(KText("ALM")) == 0){ // ALM
      GenerateUnicodeKeyFromKeyboard(ALM);
    }
    else if (w->text()[0] != ' '){
      GenerateUnicodeKeyFromKeyboard(w->text()[0]);
    }
  }
}




void KObject::connect(KWidget *wid, void (*signal)(void), void (*slot)(HWND, WPARAM, LPARAM ,KWidget *), KWindow *win )
{
  if (wid->id() != -1)
    win->addNewFunction(wid,slot);
}

void KObject::clicked(void)
{
}


