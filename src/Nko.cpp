/** Kaïraba Cissé <ckairaba@gmail.com>
 */
#include "Nko.hpp"

unsigned int kanjamadi_keyboard(unsigned int scancode, bool shift)
{
  // touche pour les chiffres
  if(shift == false){
    if((scancode >= 2) && (scancode <= 10)){
      return scancode - 1 + NKO_DIGIT_ZERO; // return NKO_DIGIT_ONE ... NKO_DIGIT_NINE
    }
    else {
      switch(scancode){
      case 11 : return NKO_DIGIT_ZERO;
      case 12 : return '-';
      case 13 : return '=';
      case 16 : return NKO_LETTER_PA;
      case 17 : return NKO_LETTER_NYA_WOLOSO;
      case 18 : return NKO_LETTER_NA_WOLOSO;
      case 19 : return NKO_LETTER_WA;
      case 20 : return NKO_LETTER_YA;
      case 21 : return NKO_LETTER_RA;
      case 22 : return NKO_LETTER_CHA;
      case 23 : return NKO_LETTER_GBA;
      case 24 : return NKO_LETTER_NYA;
      case 25 : return NKO_LETTER_MA;

      case 26 : return NKO_LETTER_HA;
      case 27 : return NKO_LETTER_N;

      case 30 : return NKO_LETTER_OO;
      case 31 : return NKO_LETTER_U;
      case 32 : return NKO_LETTER_E;
      case 33 : return NKO_LETTER_I;
      case 34 : return NKO_LETTER_EE;
      case 35 : return NKO_LETTER_A;
      case 36 : return NKO_LETTER_JA;
      case 37 : return NKO_LETTER_FA;
      case 38 : return NKO_LETTER_NA;

      case 39 : return NKO_LETTER_TA;
      case 40 : return NKO_LETTER_BA;

      case 41 : return NKO_SYMBOL_GBAKURUNEN;

      case 44 : return NKO_LETTER_O;
      case 45 : return NKO_COMBINING_NASALIZATION_MARK;
      case 46 : return NKO_LOW_TONE_APOSTROPHE;
      case 47 : return NKO_HIGH_TONE_APOSTROPHE;
      case 48 : return NKO_COMBINING_SHORT_LOW_TONE;
      case 49 : return NKO_COMBINING_SHORT_HIGH_TONE;
      case 50 : return NKO_LETTER_LA;
      case 51 : return NKO_LETTER_SA;
      case 52 : return NKO_LETTER_DA;
      case 53 : return NKO_LETTER_KA;

      }
    }
  }
  else { // shift == true
    switch(scancode){
    case 2 : return NKO_EXCLAMATION_MARK;
     
    case 6 : return 0x0025; // percent
    case 9 : return 0x2A;    // '*'
    case 10 : return 0x28;   // '('
    case 11 : return 0x29;   // ')'
	
    case 12 : return 0x5F;   // '_'
    case 13 : return 0x2B;   // '+'
	
    case 16 : return NKO_LETTER_JONA_CHA;
    case 17 : return NKO_LETTER_JONA_JA;

    case 18 : return LEFT_LOW_PARAPHRASE_BRACKET;
    case 19 : return RIGHT_LOW_PARAPHRASE_BRACKET;
	
    case 21 : return NKO_LETTER_RRA;
    case 23 : return DIVISION_SIGN;
    case 24 : return MULTIPLICATION_SIGN;
    case 25 : return NKO_LETTER_JONA_RA;
    case 26 : return '<';
    case 27 : return '>';

    case 30 : return NKO_SYMBOL_OO_DENNEN;
      //case 31 : return 0x00B0; // degre unicode symbol
    case 32 : return '[';
    case 33 : return ']';
    case 34 : return ARABIC_ORNATE_LEFT_PARENTHESIS;
    case 35 : return ARABIC_ORNATE_RIGHT_PARENTHESIS;
    case 36 : return NKO_LAJANYALAN;

    case 38 : return '/';

    case 39 : return ':';
    case 40 : return '"';
	
    case 44 : return NKO_COMBINING_DOUBLE_DOT_ABOVE;
    case 45 : return NKO_COMBINING_LONG_RISING_TONE;
    case 46 : return NKO_COMBINING_SHORT_RISING_TONE;
    case 47 : return NKO_COMBINING_LONG_DESCENDING_TONE;
    case 48 : return NKO_COMBINING_LONG_LOW_TONE;
    case 49 : return NKO_COMBINING_LONG_HIGH_TONE;
    case 50 : return NKO_COMMA;
    case 51 : return NKO_LETTER_DAGBASINNA;
    case 52 : return '.';
    case 53 : return ARABIC_QUESTION_MARK;
    }
  }
  return 0; // Never used
}
  
unsigned int phonetic_keyboard(unsigned int scancode, bool shift)
{
  // touche pour les chiffres
  if(shift == false){
    if((scancode >= 2) && (scancode <= 10)){
      return scancode - 1 + NKO_DIGIT_ZERO; // return NKO_DIGIT_ONE ... NKO_DIGIT_NINE
    }
    else {
      switch(scancode){
      case 11 : return NKO_DIGIT_ZERO;
      case 12 : return '-';
      case 13 : return '+';
     
      case 16 : return NKO_LETTER_DAGBASINNA; 
      case 17 : return NKO_LETTER_WA;
      case 18 : return NKO_LETTER_E;
      case 19 : return NKO_LETTER_RA;
      case 20 : return NKO_LETTER_TA;
      case 21 : return NKO_LETTER_YA;
      case 22 : return NKO_LETTER_U;
      case 23 : return NKO_LETTER_I;
      case 24 : return NKO_LETTER_O;
      case 25 : return NKO_LETTER_PA;

      case 26 : return '(';
      case 27 : return ')';
      case 30 : return NKO_LETTER_A;
      case 31 : return NKO_LETTER_SA;
      case 32 : return NKO_LETTER_DA;
      case 33 : return NKO_LETTER_FA;
      case 34 : return NKO_LETTER_GBA;
      case 35 : return NKO_LETTER_HA;
      case 36 : return NKO_LETTER_JA;
      case 37 : return NKO_LETTER_KA;
      case 38 : return NKO_LETTER_LA;

      case 39 : return NKO_LETTER_MA;
      case 40 : return NKO_LOW_TONE_APOSTROPHE; 
      case 43 : return NKO_HIGH_TONE_APOSTROPHE; 

      case 44 : return NKO_LETTER_RRA;
      case 45 : return NKO_LETTER_NYA; 
      case 46 : return NKO_LETTER_CHA;
      case 47 : return NKO_LETTER_N; 
      case 48 : return NKO_LETTER_BA;
      case 49 : return NKO_LETTER_NA;
      case 50 : return NKO_COMMA;
      case 51 : return '.';
      case 52 : return NKO_EXCLAMATION_MARK;
      case 53 : return NKO_SYMBOL_OO_DENNEN;

      }
    }
  }
  else { // shift == true
    switch(scancode){
    case 2 : return NKO_COMBINING_SHORT_HIGH_TONE;
    case 3 : return NKO_COMBINING_SHORT_LOW_TONE;
    case 4 : return NKO_COMBINING_SHORT_RISING_TONE;
    case 5 : return NKO_COMBINING_LONG_DESCENDING_TONE ;
    case 6 : return NKO_COMBINING_LONG_HIGH_TONE;
    case 7 : return NKO_COMBINING_LONG_LOW_TONE;
    case 8 : return NKO_COMBINING_LONG_RISING_TONE;
    case 9 : return NKO_COMBINING_NASALIZATION_MARK;
    case 10 : return NKO_COMBINING_DOUBLE_DOT_ABOVE;
    case 13 : return '=';
	
    case 16 : return NKO_LAJANYALAN;
    case 18 : return NKO_LETTER_EE;
    case 19 : return NKO_LETTER_JONA_RA;
    case 24 : return NKO_LETTER_OO;
    
    case 26 : return ARABIC_ORNATE_LEFT_PARENTHESIS; 
    case 27 : return ARABIC_ORNATE_RIGHT_PARENTHESIS; 

    case 36 : return NKO_LETTER_JONA_JA; 
    case 40 : return LEFT_LOW_PARAPHRASE_BRACKET;
    case 43 : return RIGHT_LOW_PARAPHRASE_BRACKET;
	
    case 45 : return NKO_LETTER_NYA_WOLOSO;
    case 46 : return NKO_LETTER_JONA_CHA;

    case 49 : return NKO_LETTER_NA_WOLOSO; 
    case 50 : return ARABIC_SEMI_COLON;
    case 51 : return ':';
    case 52 : return ARABIC_QUESTION_MARK;
    case 53 : return NKO_SYMBOL_GBAKURUNEN; 

    }
  }
  return 0; // Never used
}

void GenerateUnicodeKeyFromKeyboard( unsigned int code)
{
  KEYBDINPUT  kb={0};
  INPUT    Input={0};

  kb.wScan = code;
	
  kb.dwFlags = KEYEVENTF_UNICODE; // KEYEVENTF_UNICODE=4

  Input.type  = INPUT_KEYBOARD;

  Input.ki  = kb;
  SendInput(1,&Input,sizeof(Input));

  // generate up 
  ZeroMemory(&kb,sizeof(KEYBDINPUT));
  ZeroMemory(&Input,sizeof(INPUT));

  kb.wScan = code;

	
  kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP; //KEYEVENTF_UNICODE=4
  Input.type  = INPUT_KEYBOARD;
  Input.ki  =  kb;
  SendInput(1,&Input,sizeof(Input));
}

void PrintTextOnVKPhonetic()
{

}


void PrintTextOnVKKanjamadi()
{
  std::wstring str = KText(" ");
	
  if (shift == false){
    /* first line */
    unsigned int keys0 [] ={NKO_SYMBOL_GBAKURUNEN, 
			    NKO_DIGIT_ONE,
			    NKO_DIGIT_TWO,
			    NKO_DIGIT_THREE,
			    NKO_DIGIT_FOUR,
			    NKO_DIGIT_FIVE,
			    NKO_DIGIT_SIX,
			    NKO_DIGIT_SEVEN,
			    NKO_DIGIT_EIGHT,
			    NKO_DIGIT_NINE,
			    NKO_DIGIT_ZERO,
			    '-',
			    '='
    };
    for(unsigned int i=0; i <= 12; ++i){
      str[0] = keys0[i];
      lines[0]->at(i)->setText(str.c_str());
      lines[0]->at(i)->setFont(default_font);
    }	
    // NKO_SYMBOL_GBAKURUNEN gets the font Conakry .ttf and the rest buttons get the default font
    lines[0]->at(0)->setFont(fonts[1]);  // fonts[1] == Conakry.ttf
		
    /* second line */
    unsigned int keys1 [] ={NKO_LETTER_PA,
			    NKO_LETTER_NYA_WOLOSO,
			    NKO_LETTER_NA_WOLOSO,
			    NKO_LETTER_WA,
			    NKO_LETTER_YA,
			    NKO_LETTER_RA,
			    NKO_LETTER_CHA,
			    NKO_LETTER_GBA,
			    NKO_LETTER_NYA,
			    NKO_LETTER_MA,
			    NKO_LETTER_HA,
			    NKO_LETTER_N};
    for(unsigned int i=0; i <= 11; ++i){
      str[0] = keys1[i];
      lines[1]->at(i)->setText(str.c_str());
      lines[1]->at(i)->setFont(default_font);
    }	
		
    /* third line */
    unsigned int keys2 [] ={NKO_LETTER_OO,
			    NKO_LETTER_U,
			    NKO_LETTER_E,
			    NKO_LETTER_I,
			    NKO_LETTER_EE,
			    NKO_LETTER_A,
			    NKO_LETTER_JA,
			    NKO_LETTER_FA,
			    NKO_LETTER_NA,
			    NKO_LETTER_TA,
			    NKO_LETTER_BA};
    for(unsigned int i=0; i <= 10; ++i){
      str[0] = keys2[i];
      lines[2]->at(i)->setText(str.c_str());
      lines[2]->at(i)->setFont(default_font);
    }
    /* fourth line */
    unsigned int keys3 [] ={NKO_LETTER_O,
			    NKO_COMBINING_NASALIZATION_MARK,
			    NKO_LOW_TONE_APOSTROPHE,
			    NKO_HIGH_TONE_APOSTROPHE,
			    NKO_COMBINING_SHORT_LOW_TONE,
			    NKO_COMBINING_SHORT_HIGH_TONE,
			    NKO_LETTER_LA,
			    NKO_LETTER_SA,
			    NKO_LETTER_DA,
			    NKO_LETTER_KA};
    for(unsigned int i=0; i <= 9; ++i){
      str[0] = keys3[i];
      lines[3]->at(i)->setText(str.c_str());
      lines[3]->at(i)->setFont(default_font);
    }	
  }
  else{ //shift == true
    // clear
    for(unsigned int i = 0; i < lines.size(); ++i)
      {
	for(unsigned int j = 0; j < lines[i]->size(); ++j)
	  {
	    lines[i]->at(j)->setText(KText(" "));
	  }
      }
    unsigned int keys0 [] ={' ',
			    NKO_EXCLAMATION_MARK, 
			    ' ',
			    ' ',
			    ' ',
			    '%',
			    ' ',
			    ' ',
			    '*',
			    '(',
			    ')',
			    '_',
			    '+',
			    ' '};
    for(unsigned int i=0; i <= 12; ++i){
      str[0] = keys0[i];
      lines[0]->at(i)->setText(str.c_str());
      lines[0]->at(i)->setFont(default_font);
    }	
		
    unsigned int keys1[] = {NKO_LETTER_JONA_CHA,
			    NKO_LETTER_JONA_JA,
			    LEFT_LOW_PARAPHRASE_BRACKET,
			    RIGHT_LOW_PARAPHRASE_BRACKET,
			    ' ',
			    NKO_LETTER_RRA,
			    ' ',
			    DIVISION_SIGN,
			    MULTIPLICATION_SIGN,
			    NKO_LETTER_JONA_RA,
			    '<',
			    '>'};
    for(unsigned int i=0; i <= 11; ++i){
      str[0] = keys1[i] ;
      lines[1]->at(i)->setText(str.c_str());
      lines[1]->at(i)->setFont(((i==5 || i==7 || i==8|| i==10 || i==11) ? default_font : fonts[1])); // fonts[1] == Conakry.ttf
    }
    unsigned int keys2[] = {NKO_SYMBOL_OO_DENNEN,
			    ' ',
			    '[',
			    ']',
			    ARABIC_ORNATE_LEFT_PARENTHESIS,
			    ARABIC_ORNATE_RIGHT_PARENTHESIS,
			    NKO_LAJANYALAN,
			    ' ',
			    '/',
			    ':',
			    '"'};
    for(unsigned int i=0; i <= 10; ++i){
      str[0] = keys2[i] ;
      lines[2]->at(i)->setText(str.c_str());
      lines[2]->at(i)->setFont(((i==0) ?  fonts[1] :default_font));
    }
		
    unsigned int keys3[] = {NKO_COMBINING_DOUBLE_DOT_ABOVE,
			    NKO_COMBINING_LONG_RISING_TONE, 
			    NKO_COMBINING_SHORT_RISING_TONE,
			    NKO_COMBINING_LONG_DESCENDING_TONE,
			    NKO_COMBINING_LONG_LOW_TONE,
			    NKO_COMBINING_LONG_HIGH_TONE,
			    NKO_COMMA,
			    NKO_LETTER_DAGBASINNA,
			    '.',
			    ARABIC_QUESTION_MARK};
    for(unsigned int i=0; i <= 9; ++i){
      str[0] = keys3[i] ;
      lines[3]->at(i)->setText(str.c_str());
      lines[3]->at(i)->setFont(default_font);
    }
  }
}

void PrintTextOnVK()
{
  if (keyboard == KANJAMADI){
    PrintTextOnVKKanjamadi();
  }
  else {
    PrintTextOnVKPhonetic();
  }
}

std::wstring NkoDate() 
{
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int year = 1900 + ltm->tm_year;
  int month = 1 + ltm->tm_mon;
  int day = ltm->tm_mday;
  int hour = ltm->tm_hour;
  int min = ltm->tm_min;
  int sec = ltm->tm_sec;
  std::wstring res = KText("");
	
#ifdef _WINDOWS_8
  res +=
    IntegerToNkoString(year,true) + KText(" ") +
    Nko_Month(month) + KText(" ");
  if (day == 2 || day == 3 || day == 9 || (day >= 20 && day <= 29)){
    res += KText(NKO_DATE_LINK_2);
    res += KText(" ");
  }
  else{
    res += KText(NKO_DATE_LINK);
    res += KText(" ");
  }
  if (day == 1){
    res += IntegerToNkoString(day,false);
    res += KText("߭");
    res += KText(" ");
  }
  else{
    res += IntegerToNkoString(day,true);
    res +=  KText(" ");
  }
			
  res +=	
    IntegerToNkoString(hour,true) + KText(":")+ 
    IntegerToNkoString(min,true) + KText(":") +
    IntegerToNkoString(sec, true)
    ; 
#else
  res +=
    IntegerToNkoString(sec, true) + KText(":") + 
    IntegerToNkoString(min,true) + KText(":") + 
    IntegerToNkoString(hour,true) + KText(" ");
  if (day == 1){
    res += KText("߭");
    res += IntegerToNkoString(day,false);
    res += KText(" ");
  }
  else{
    res += IntegerToNkoString(day,true) +  KText(" ");
  }
  if (day == 2 || day == 3 || day == 9 || (day >= 20 && day <= 29)){
    res += KText(NKO_DATE_LINK_2);
    res += KText(" ");
  }
  else{
    res += KText(NKO_DATE_LINK);
    res += KText(" ");
  }
  res += 
    Nko_Month(month) + KText(" ") + 
    IntegerToNkoString(year,true);
#endif
  return res;
}

std::wstring Nko_Month(unsigned int month)
{
  switch (month){
  case 1 : 			return KText(NKO_JANUARY);
  case 2 : 			return KText(NKO_FEBRUARY);
  case 3 : 			return KText(NKO_MARCH);
  case 4 : 			return KText(NKO_APRIL);
  case 5 : 			return KText(NKO_MAY);
  case 6 : 			return KText(NKO_JUNE);
  case 7 : 			return KText(NKO_JULY);
  case 8 : 			return KText(NKO_AUGUST);
  case 9 : 			return KText(NKO_SEPTEMBER);
  case 10 : 		return KText(NKO_OCTOBER);
  case 11 : 		return KText(NKO_NOVEMBER);
  case 12 : 		return KText(NKO_DECEMBER);
  }
  return KText("");
}

std::wstring IntegerToNkoString(int n, bool zero_mark)
{
  std::stringstream ss;
  ss << n;
  std::wstring res = KText("");
  for (unsigned int i =1; i<=ss.str().length(); i++){
#ifdef _WINDOWS_8
    std::wstring tmp = KText("");
    tmp += (0x07C0 + ss.str().c_str()[ss.str().length()-i] -  48) ;
    res = tmp + res ;
#else
    res+= 0x07C0 + ss.str().c_str()[ss.str().length()-i] -  48;
#endif // _WINDOWS_8
  }
  if (n<=9 && zero_mark == true){
#ifdef _WINDOWS_8
    std::wstring tmp = KText("");
    tmp += (0x07C0) ;
    res = tmp + res ;
#else
    res += 0x07C0;
#endif // _WINDOWS_8
  }
  if (n < 0){
#ifdef _WINDOWS_8
    std::wstring tmp = KText("-");
    tmp += (RLE) ;
    res = tmp + res;
#else
    res += KText("-");
#endif // _WINDOWS_8
  }
  return res;
}
