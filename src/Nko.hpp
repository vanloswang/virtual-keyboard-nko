/** Ka�raba Ciss� <ckairaba@gmail.com>
*/
#ifndef NKO_H
#define NKO_H
#define def_nko_digit(integer) ((1984 + integer))
									
#define NKO_DIGIT_ZERO    0x07C0 // 1984
#define NKO_DIGIT_ONE     0x07C1 // 1985
#define NKO_DIGIT_TWO     0x07C2 // 1986
#define NKO_DIGIT_THREE   0x07C3 // 1987
#define NKO_DIGIT_FOUR    0x07C4 // 1988
#define NKO_DIGIT_FIVE    0x07C5 // 1989
#define NKO_DIGIT_SIX     0x07C6 // 1990
#define NKO_DIGIT_SEVEN   0x07C7 // 1991
#define NKO_DIGIT_EIGHT   0x07C8 // 1992
#define NKO_DIGIT_NINE    0x07C9 // 1993

#define NKO_LETTER_A              0x07CA // 1994
#define NKO_LETTER_EE             0x07CB // 1995
#define NKO_LETTER_I              0x07CC // 1996
#define NKO_LETTER_E              0x07CD // 1997
#define NKO_LETTER_U              0x07CE // 1998
#define NKO_LETTER_OO             0x07CF // 1999
#define NKO_LETTER_O              0x07D0 // 2000
#define NKO_LETTER_DAGBASINNA     0x07D1 // 2001
#define NKO_LETTER_N              0x07D2 // 2002
#define NKO_LETTER_BA             0x07D3 // 2003
#define NKO_LETTER_PA             0x07D4 // 2004
#define NKO_LETTER_TA             0x07D5 // 2005
#define NKO_LETTER_JA             0x07D6 // 2006
#define NKO_LETTER_CHA            0x07D7 // 2007
#define NKO_LETTER_DA             0x07D8 // 2008
#define NKO_LETTER_RA             0x07D9 // 2009
#define NKO_LETTER_RRA            0x07DA // 2010
#define NKO_LETTER_SA             0x07DB // 2011
#define NKO_LETTER_GBA            0x07DC // 2012
#define NKO_LETTER_FA             0x07DD // 2013
#define NKO_LETTER_KA             0x07DE // 2014
#define NKO_LETTER_LA             0x07DF // 2015
#define NKO_LETTER_NA_WOLOSO      0x07E0 // 2016
#define NKO_LETTER_MA             0x07E1 // 2017
#define NKO_LETTER_NYA            0x07E2 // 2018
#define NKO_LETTER_NA             0x07E3 // 2019
#define NKO_LETTER_HA             0x07E4 // 2020
#define NKO_LETTER_WA             0x07E5 // 2021
#define NKO_LETTER_YA             0x07E6 // 2022
#define NKO_LETTER_NYA_WOLOSO     0x07E7 // 2023
#define NKO_LETTER_JONA_JA        0x07E8 // 2024
#define NKO_LETTER_JONA_CHA       0x07E9 // 2025
#define NKO_LETTER_JONA_RA        0x07EA // 2026

#define NKO_COMBINING_SHORT_HIGH_TONE          0x07EB // 2027
#define NKO_COMBINING_SHORT_LOW_TONE           0x07EC // 2028
#define NKO_COMBINING_SHORT_RISING_TONE        0x07ED // 2029
#define NKO_COMBINING_LONG_DESCENDING_TONE     0x07EE // 2030
#define NKO_COMBINING_LONG_HIGH_TONE           0x07EF // 2031
#define NKO_COMBINING_LONG_LOW_TONE            0x07F0 // 2032
#define NKO_COMBINING_LONG_RISING_TONE         0x07F1 // 2033
#define NKO_COMBINING_NASALIZATION_MARK        0x07F2 // 2034
#define NKO_COMBINING_DOUBLE_DOT_ABOVE         0x07F3 // 2035
#define NKO_HIGH_TONE_APOSTROPHE               0x07F4 // 2036
#define NKO_LOW_TONE_APOSTROPHE                0x07F5 // 2037
#define NKO_SYMBOL_OO_DENNEN                   0x07F6 // 2038
#define NKO_SYMBOL_GBAKURUNEN                  0x07F7 // 2039
#define NKO_COMMA                              0x07F8 // 2040
#define NKO_EXCLAMATION_MARK                   0x07F9 // 2041
#define NKO_LAJANYALAN                         0x07FA // 2042

#define LEFT_LOW_PARAPHRASE_BRACKET            0x2E1C // 11804 
#define RIGHT_LOW_PARAPHRASE_BRACKET           0x2E1D // 11805

#define ARABIC_QUESTION_MARK                   0x061F // 1567 

#define ARABIC_ORNATE_LEFT_PARENTHESIS         0xFD3E // 64830
#define ARABIC_ORNATE_RIGHT_PARENTHESIS        0xFD3F // 64831

#define ARABIC_SEMI_COLON                      0x061B // 1563 
#define DIVISION_SIGN                          0x00F7 // 247
#define MULTIPLICATION_SIGN                    0x00D7 // 215
#define WIN_K_0 0x30
#define WIN_K_1 0x31
#define WIN_K_2 0x32
#define WIN_K_3 0x33
#define WIN_K_4 0x34
#define WIN_K_5 0x35
#define WIN_K_6 0x36
#define WIN_K_7 0x37
#define WIN_K_8 0x38
#define WIN_K_9 0x39

// Zero width characters control
#define LRM 0x200E
#define RLM 0x200F
#define ALM 0x061C

#define LRE 0x202A
#define RLE 0x202B

#define LRO 0x202D
#define RLO 0x202E

#define LRI 0x2066
#define RLI 0x2067
#define FSI 0x2068

#define PDF 0x202C
#define PDI 0x2069

#define ZWJ 0x200D
#define ZWNJ 0x200C



#ifdef _WINDOWS_8
	#define NKO_JANUARY				"ߓߌ߲ߠߊߥߎߟߋ߲"
	#define NKO_FEBRUARY				"ߞߏ߲ߞߏߜߍ" 
	#define NKO_MARCH					"ߕߙߊߓߊ"
	#define NKO_APRIL						"ߞߏ߲ߞߏߘߌ߬ߓߌ"
	#define NKO_MAY						"ߘߓߊ߬ߕߊ"
	#define NKO_JUNE						"ߥߊ߬ߛߌߥߊ߬ߙߊ"
	#define NKO_JULY						"ߞߊ߬ߙߌߝߐ߭"
	#define NKO_AUGUST					"ߘߓߊ߬ߓߌߟߊ"
	#define NKO_SEPTEMBER			"ߕߎߟߊߝߌ߲"
	#define NKO_OCTOBER				"ߞߏ߲ߓߌߕߌ߮"
	#define NKO_NOVEMBER			"ߣߍߣߍߓߊ"
	#define NKO_DECEMBER				"ߞߏ߬ߟߌ߲߬ߞߏߟߌ߲"
	#define NKO_DATE_LINK	"ߕߟߋ߬"
	#define NKO_DATE_LINK_2 "ߕߋ߬ߟߋ߫"
#else
	#define NKO_JANUARY				"߲ߋߟߎߥߊߠ߲ߌߓ"
	#define NKO_FEBRUARY				"ߍߜߏߞ߲ߏߞ"
	#define NKO_MARCH					"ߊߓߊߙߕ"
	#define NKO_APRIL						"ߌߓ߬ߌߘߏߞ߲ߏߞ"
	#define NKO_MAY						"ߊߕ߬ߊߓߘ"
	#define NKO_JUNE						"ߊߙ߬ߊߥߌߛ߬ߊߥ"
	#define NKO_JULY						"߭ߐߝߌߙ߬ߊߞ"
	#define NKO_AUGUST					"ߊߟߌߓ߬ߊߓߘ"
	#define NKO_SEPTEMBER			"߲ߌߝߊߟߎߕ"
	#define NKO_OCTOBER				"߮ߌߕߌߓ߲ߏߞ"
	#define NKO_NOVEMBER			"ߊߓߍߣߍߣ"
	#define NKO_DECEMBER				"߲ߌߟߏߞ߲߬ߌߟ߬ߏߞ"
	#define NKO_DATE_LINK	"߬ߋߟߕ"
	#define NKO_DATE_LINK_2 "߫ߋߟ߬ߋߕ"
#endif // _WINDOWS_8


#include "KResource.hpp"
#include "KPushButton.hpp"
#include "KFont.hpp"
extern bool shift;
extern KFont * default_font;
extern unsigned int keyboard;
extern unsigned int KANJAMADI;
extern unsigned int PHONETIC;
extern std::vector<std::vector <KPushButton * > * > lines;
extern std::vector <KFont *> fonts;
unsigned int phonetic_keyboard(unsigned int scancode, bool shift);
unsigned int kanjamadi_keyboard(unsigned int scancode, bool shift);
void GenerateUnicodeKeyFromKeyboard( unsigned int code);
void PrintTextOnVK();
std::wstring NkoDate() ;
std::wstring Nko_Month(unsigned int month);
std::wstring IntegerToNkoString(int n, bool zero_mark);
#endif

