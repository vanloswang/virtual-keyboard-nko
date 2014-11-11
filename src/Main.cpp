/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "KWindow.hpp"
#include "KApplication.hpp"
#include "KPushButton.hpp"
#include "KCheckBox.hpp"
#include "KRadioButton.hpp"
#include "KObject.hpp"
#include "KResource.hpp"
#include "KFont.hpp"
#include "KLabel.hpp"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

bool activate = false;
bool shift = false;
unsigned int KANJAMADI = 0;
unsigned int PHONETIC = 1;
unsigned int keyboard = KANJAMADI;
// The following vector modelizes my lines keyboard
std::vector<std::vector <KPushButton * > * > lines;
std::vector <KFont *> fonts;
KFont * default_font;
#define WINDOW_WIDTH 537
#define WINDOW_HEIGHT 248
#define B_HEIGHT_HEADER 30 
#define B_HEIGHT 35
#define B_WIDTH 35
#define BACKSPACE_WIDTH 62
#define HEADER_WIDTH 105
#define DATE_WIDTH (HEADER_WIDTH + HEADER_WIDTH + 45 + SPACE_SIZE)
#define HELP_WIDTH 105
#define EXIT_WIDTH 60
#define SPACE_SIZE 1
#define NB_LINES 4
#define NB_BUTTON_ON_FIRST_LINE_WITHOUT_BACKSPACE_BUTTON 13
#define NB_BUTTON_ON_SECOND_LINE_WITHOUT_TAB_BUTTON 12
#define NB_BUTTON_ON_THIRD_LINE_WITHOUT_CAPS_BUTTON  11
#define NB_BUTTON_ON_FOURTH_LINE_WITHOUT_SHIFT_BUTTON 10
#define SPACE_WIDTH 300
#define ENTER_WIDTH 79
#define TAB_WIDTH 44
#define LEFT_SHIFT_WIDTH 69
#define RIGHT_SHIFT_WIDTH 100

KLabel my_date(NkoDate(), 0, 0,DATE_WIDTH, B_HEIGHT_HEADER);

UINT TimerId;

VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime) {
  my_date.setText(NkoDate());	
}

int APIENTRY WinMain (HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  KApplication app(hinstance);
  // Fonts
  KFont kanjamadi1Font(KText("fonts\\kanjamadi1.ttf"), KText("kanjamadi1"));
  KFont ConakryFont(KText("fonts\\Conakry.ttf"), KText("Conakry"));
  KFont kanjamadiFont(KText("fonts\\kanjamadi.ttf"), KText("kanjamadi"));
  KFont Code2000Font(KText("fonts\\code2000.ttf"), KText("Code2000"));
  KFont DejaVuSansBoldFont(KText("fonts\\DejaVuSans-Bold.ttf"), KText("DejaVu Sans Bold"));
  KFont DejaVuSansBoldObliqueFont(KText("fonts\\DejaVuSans-BoldOblique.ttf"), KText("DejaVu Sans"));
  KFont DejaVuSansObliqueFont(KText("fonts\\DejaVuSans-Oblique.ttf"), KText("DejaVu Sans"));
  KFont DejaVuSansFont(KText("fonts\\DejaVuSans.ttf"), KText("DejaVu Sans"));
  KFont DejaVuSansCondensedBoldFont(KText("fonts\\DejaVuSansCondensed-Bold.ttf"), KText("DejaVu Sans Condensed")); // ++
  KFont DejaVuSansCondensedBoldObliqueFont(KText("fonts\\DejaVuSansCondensed-BoldOblique.ttf"), KText("DejaVu Sans Condensed"));
  KFont DejaVuSansCondensedObliqueFont(KText("fonts\\DejaVuSansCondensed-Oblique.ttf"), KText("DejaVu Sans Condensed"));
  KFont DejaVuSansCondensedFont(KText("fonts\\DejaVuSansCondensed.ttf"), KText("DejaVu Sans Condensed"));
	 
  fonts.push_back(&kanjamadi1Font);
  fonts.push_back(&ConakryFont);
  fonts.push_back(&kanjamadiFont);
  fonts.push_back(&Code2000Font);
  fonts.push_back(&DejaVuSansBoldFont);
  fonts.push_back(&DejaVuSansBoldObliqueFont);
  fonts.push_back(&DejaVuSansObliqueFont);
  fonts.push_back(&DejaVuSansFont);
  fonts.push_back(&DejaVuSansCondensedBoldFont);
  fonts.push_back(&DejaVuSansCondensedBoldObliqueFont);
  fonts.push_back(&DejaVuSansCondensedObliqueFont);
  fonts.push_back(&DejaVuSansCondensedFont);

  default_font = &DejaVuSansCondensedBoldFont;
	
#ifdef _WINDOWS_8
  KWindow w (&app, KText("ߒߞߏ ߛߓߍߘߋ߲ߥߟߊ"),WINDOW_WIDTH + 112, WINDOW_HEIGHT);
#else
  KWindow w (&app, KText("N'ko keyboard"),WINDOW_WIDTH + 112, WINDOW_HEIGHT);
#endif
  TimerId = SetTimer(NULL, 0, 1000, &TimerProc);	
  unsigned int x = 0;
  unsigned int y = 0;
	
  // Header
  /*
    KRadioButton kanjamadi(KText("Kanjamadi"), x, y,HEADER_WIDTH , B_HEIGHT);
    x+=(HEADER_WIDTH +SPACE_SIZE);
    KRadioButton phonetic(KText("Phonetic"),  x, y,HEADER_WIDTH , B_HEIGHT);
    x+=(HEADER_WIDTH +SPACE_SIZE);
  */
	

  x+=(DATE_WIDTH);
#ifdef _WINDOWS_8
  KCheckBox on_top(KText("ߊ߬ ߓߌ߬ߟߵߊ߬ ߟߊ߫"), x, y,HEADER_WIDTH , B_HEIGHT_HEADER);
#else
  KCheckBox on_top(KText("߫ߊߟ ߬ߊߵߟ߬ߌߓ ߬ߊ"), x, y,HEADER_WIDTH , B_HEIGHT_HEADER);
#endif
  x+=(HEADER_WIDTH +SPACE_SIZE);
#ifdef _WINDOWS_8
  KPushButton help(KText("ߘߍ߬ߡߍ߲߬ߠߌ"),  x, y,HELP_WIDTH , B_HEIGHT_HEADER);
#else
  KPushButton help(KText("ߌߠ߲߬ߍߡ߬ߍߘ"),  x, y,HELP_WIDTH , B_HEIGHT_HEADER);
#endif
  x+=(HEADER_WIDTH +SPACE_SIZE);
#ifdef _WINDOWS_8
  KPushButton exit(KText("ߓߐߟߌ"), x, y,EXIT_WIDTH , B_HEIGHT_HEADER);
#else
  KPushButton exit(KText("ߌߟߐߓ"), x, y,EXIT_WIDTH , B_HEIGHT_HEADER);
#endif
	
  w.addWidget(&my_date);
  w.addWidget(&on_top);
  w.addWidget(&help);
  w.addWidget(&exit);
	
  my_date.setFont(&kanjamadi1Font);
  on_top.setFont(&kanjamadi1Font);
  help.setFont(&kanjamadi1Font);
  exit.setFont(&kanjamadi1Font);
	

  for(unsigned int i = 0; i < NB_LINES; i++){
    std::vector <KPushButton *> * tmp = new std::vector <KPushButton *>();
    lines.push_back(tmp);
  }
	
  // First line
  x = 0;
  y = 35; 
  for(unsigned int i = 0;  i <  NB_BUTTON_ON_FIRST_LINE_WITHOUT_BACKSPACE_BUTTON;  i++){
    KPushButton *b = new KPushButton (KText(" "), x, y,B_WIDTH, B_HEIGHT);
    lines[0]->push_back(b);
    x+=(B_WIDTH+SPACE_SIZE);
    w.addWidget(b);
    b->setFont(default_font);
  }
  x = WINDOW_WIDTH -3 ;
  // RLI
  KPushButton RLI_BUTTON(KText("RLI"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&RLI_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // RLM
  KPushButton RLM_BUTTON(KText("RLM"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&RLM_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // RLE
  KPushButton RLE_BUTTON(KText("RLE"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&RLE_BUTTON);
	

  // Second line
  x = 0;
  y += B_HEIGHT + SPACE_SIZE;
  KPushButton tabulation(KText("↹"), x, y,TAB_WIDTH, B_HEIGHT);
  w.addWidget(&tabulation);
  tabulation .setFont(&DejaVuSansBoldFont);
  x += (TAB_WIDTH+SPACE_SIZE);

  for(unsigned int i = 0;  i <  NB_BUTTON_ON_SECOND_LINE_WITHOUT_TAB_BUTTON;  i++){
    KPushButton *b = new KPushButton (KText(" "), x, y,B_WIDTH, B_HEIGHT);
    lines[1]->push_back(b);
    x+=(B_WIDTH+SPACE_SIZE);
    w.addWidget(b);
    b->setFont(default_font);
  }
  x = WINDOW_WIDTH -3 ;
  // LRI
  KPushButton LRI_BUTTON(KText("LRI"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&LRI_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // LRM
  KPushButton LRM_BUTTON(KText("LRM"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&LRM_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // LRE
  KPushButton LRE_BUTTON(KText("LRE"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&LRE_BUTTON);
	
	
  // Third line
  x = B_WIDTH + 20;
  y += B_HEIGHT + SPACE_SIZE;
	
  for(unsigned int i = 0;  i <  NB_BUTTON_ON_THIRD_LINE_WITHOUT_CAPS_BUTTON;  i++){
    KPushButton *b = new KPushButton (KText(" "), x, y,B_WIDTH, B_HEIGHT);
    lines[2]->push_back(b);
    x+=(B_WIDTH+SPACE_SIZE);
    w.addWidget(b);
    b->setFont(default_font);
  }
  KPushButton enter(KText("↵"), x, y,ENTER_WIDTH, B_HEIGHT);
  w.addWidget(&enter);
  enter.setFont(&DejaVuSansBoldFont);
  x = WINDOW_WIDTH -3 ;
  // FSI
  KPushButton FSI_BUTTON(KText("FSI"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&FSI_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // ALM
  KPushButton ALM_BUTTON(KText("ALM"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&ALM_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // RLO
  KPushButton RLO_BUTTON(KText("RLO"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&RLO_BUTTON);

	
  // Fourth line
  x = 0;
  y += B_HEIGHT + SPACE_SIZE;
  KPushButton leftshift(KText("↑"), x, y,LEFT_SHIFT_WIDTH, B_HEIGHT);
  w.addWidget(&leftshift);
  leftshift .setFont(&DejaVuSansBoldFont);
  x += (LEFT_SHIFT_WIDTH+SPACE_SIZE);

  for(unsigned int i = 0;  i <  NB_BUTTON_ON_FOURTH_LINE_WITHOUT_SHIFT_BUTTON;  i++){
    KPushButton *b = new KPushButton (KText(" "), x, y,B_WIDTH, B_HEIGHT);
    lines[3]->push_back(b);
    x+=(B_WIDTH+SPACE_SIZE);
    w.addWidget(b);
    b->setFont(default_font);
  }
  KPushButton rightshift(KText("↑"), x, y,RIGHT_SHIFT_WIDTH, B_HEIGHT);
  w.addWidget(&rightshift);
  rightshift .setFont(&DejaVuSansBoldFont);
  x += (RIGHT_SHIFT_WIDTH+SPACE_SIZE);
	
  x = WINDOW_WIDTH -3 ;
  // PDI
  KPushButton PDI_BUTTON(KText("PDI"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&PDI_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // PDF
  KPushButton PDF_BUTTON(KText("PDF"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&PDF_BUTTON);
  x+=(B_WIDTH+SPACE_SIZE);
  // LRO
  KPushButton LRO_BUTTON(KText("LRO"), x, y,B_WIDTH, B_HEIGHT);
  w.addWidget(&LRO_BUTTON);
  w.setColor(0,0,0);
  // Space
  x = B_WIDTH + 50;
  y += B_HEIGHT + SPACE_SIZE;
  KPushButton space(KText(" "), x, y,SPACE_WIDTH , B_HEIGHT);
  w.addWidget(&space);
  x = WINDOW_WIDTH -3 ;
  /*	// ZWJ
	KPushButton ZWJ_BUTTON(KText("ZWJ"), x, y,B_WIDTH+18, B_HEIGHT);
	w.addWidget(&ZWJ_BUTTON);
	x+=(B_WIDTH+18+SPACE_SIZE);
	// ZWNJ
	KPushButton ZWNJ_BUTTON(KText("ZWNJ"), x, y,B_WIDTH+18, B_HEIGHT);
	w.addWidget(&ZWNJ_BUTTON);
  */
  PrintTextOnVK();
	
	
  // Connections
  KObject::connect(&help, KObject::clicked, KObject::help, &w);
  KObject::connect(&on_top, KObject::clicked, KObject::setTop, &w);
  //KObject::connect(&kanjamadi, KObject::clicked, KObject::help, &w);
  KObject::connect(&exit, KObject::clicked, KObject::quit, &w);
  KObject::connect(&enter, KObject::clicked, KObject::enter, &w);
  //KObject::connect(&backspace, KObject::clicked, KObject::backspace, &w);
  KObject::connect(&space, KObject::clicked, KObject::space, &w);
  KObject::connect(&tabulation, KObject::clicked, KObject::tabulation, &w);
  KObject::connect(&leftshift, KObject::clicked, KObject::shift_slot, &w);
  KObject::connect(&rightshift, KObject::clicked, KObject::shift_slot, &w);
	
  KObject::connect(&RLE_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&LRE_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&RLM_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&LRM_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&RLO_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&LRO_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&PDF_BUTTON, KObject::clicked, KObject::onclick, &w);
  //KObject::connect(&ZWJ_BUTTON, KObject::clicked, KObject::onclick, &w);
  //KObject::connect(&ZWNJ_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&ALM_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&PDI_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&FSI_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&LRI_BUTTON, KObject::clicked, KObject::onclick, &w);
  KObject::connect(&RLI_BUTTON, KObject::clicked, KObject::onclick, &w);
	
  for(unsigned int i = 0; i < lines.size(); ++i)
    {
      for(unsigned int j = 0; j < lines[i]->size(); ++j)
	{
	  KObject::connect(lines[i]->at(j), KObject::clicked, KObject::onclick, &w);
	}
    }

  w.show ();
  return app.exec();
}
