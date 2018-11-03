/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 25 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 11/03/18
* Time: 21:30:32
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018��10��28��
****************************************************************************/

#include "myparser.h"
#include <vector>
#include <string>
using namespace std;
#define END 0
#define VOID 1
#define MAIN 2
#define LP 3  
#define RP 4
#define LBRACE 5
#define RBRACE 6
#define TYPE 7
#define ID 8
#define SEMICOL 9
#define FOR 10
#define ASSIGN 11
#define NUMBER 12
#define LESS 13
#define ADD 14
#define MINUS 15
#define IF 16
#define MORE 17
#define MUTIPLY 18
#define DIVIDE 19
#define THEN 20
#define BREAK 21
#define CASE 22
#define CONST 23
#define CONTINUE 24
#define DEFAULT 25
#define DO 26
#define ELSE 27
#define ENUM 28
#define EXTERN 29
#define GOTO 30
#define RETURN 31
#define REGISTER 32
#define SIGNED 33
#define SIZEOF 34
#define STATIC 35
#define STRUCT 36
#define SWITCH 37
#define TYPEDEF 38
#define UNION 39
#define UNSIGNED 40
#define VOLATILE 41
#define WHILE 42
#define COLON 43
string Words[] = {
    "END", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID",
    "SEMICOL", "FOR", "ASSIGN", "NUMBER", "LESS", "ADD", "MINUS", "IF", "MORE",
    "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST", "CONTINUE",
    "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "GOTO", "RETURN", "REGISTER",
    "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDE", "UNION ",
    "UNSIGN", "VOLATI", "WHILE", "COLON"
};
struct Symbol
{
	Symbol(int word, string element, string value = "") :word(word), element(element), value(value) {}
	int word;
	string element;
	string value;
};
vector<Symbol> symbols;
void reserve(int word, string element)
{
	// �Ѵ��ڷ��ű���
	for (int i = 0; i < symbols.size(); i++)
		if (symbols[i].element == element)
		{
			switch (word)
			{
				case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols[i] << endl; return;
				case NUMBER: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
				default:
					cout << Words[word] << "\t\t" << element << endl; return;
			}
		}
	//δ���ڷ��ű���
	symbols.push_back(Symbol(word, element));
	switch (word)
	{
		case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols.back() << endl; return;
		case NUMBER: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
		default:
			cout << Words[word] << "\t\t" << element << endl; return;
	}
}


#line 137 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 112 ".\\mylexer.l"

	// place any extra initialisation code here

#line 161 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 117 ".\\mylexer.l"

	// place any extra cleanup code here

#line 173 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 132 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 244 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 138 ".\\mylexer.l"

#line 251 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 139 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 258 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 140 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 265 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 141 ".\\mylexer.l"
reserve(COLON, yytext);
#line 272 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 142 ".\\mylexer.l"
reserve(LP, yytext); 
#line 279 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 143 ".\\mylexer.l"
reserve(RP, yytext); 
#line 286 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 144 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 293 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 145 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 300 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 146 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 307 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 147 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 314 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 148 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 321 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 149 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 328 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 150 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 335 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 151 ".\\mylexer.l"
reserve(LESS, yytext); 
#line 342 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 152 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 349 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 153 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 356 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 154 ".\\mylexer.l"
reserve(IF, yytext); 
#line 363 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 155 ".\\mylexer.l"
reserve(MORE, yytext); 
#line 370 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 156 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 377 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 157 ".\\mylexer.l"
reserve(DIVIDE, yytext); 
#line 384 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 158 ".\\mylexer.l"
reserve(THEN, yytext);
#line 391 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 159 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 398 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 160 ".\\mylexer.l"
reserve(CASE, yytext);
#line 405 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 161 ".\\mylexer.l"
reserve(CONST, yytext);
#line 412 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 162 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 419 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 163 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 426 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 164 ".\\mylexer.l"
reserve(DO, yytext);
#line 433 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 165 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 440 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 166 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 447 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 167 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 454 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 168 ".\\mylexer.l"
reserve(FOR, yytext);
#line 461 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 169 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 468 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 170 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 475 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 171 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 482 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 172 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 489 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 173 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 496 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 174 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 503 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 175 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 510 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 176 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 517 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 177 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 524 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 178 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 531 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 179 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 538 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 180 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 545 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 181 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 552 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 182 ".\\mylexer.l"
reserve(ID, yytext);
#line 559 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 265;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 3, 3 },
		{ 3, 3 },
		{ 55, 27 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 60, 60 },
		{ 36, 18 },
		{ 80, 52 },
		{ 77, 50 },
		{ 39, 19 },
		{ 47, 23 },
		{ 82, 53 },
		{ 56, 27 },
		{ 37, 18 },
		{ 3, 1 },
		{ 64, 36 },
		{ 3, 3 },
		{ 34, 60 },
		{ 48, 23 },
		{ 40, 19 },
		{ 38, 18 },
		{ 78, 50 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 81, 52 },
		{ 8, 1 },
		{ 83, 53 },
		{ 9, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 51, 26 },
		{ 52, 26 },
		{ 41, 20 },
		{ 87, 57 },
		{ 42, 20 },
		{ 89, 58 },
		{ 44, 21 },
		{ 65, 37 },
		{ 90, 58 },
		{ 45, 21 },
		{ 94, 66 },
		{ 95, 66 },
		{ 53, 26 },
		{ 88, 57 },
		{ 43, 20 },
		{ 54, 26 },
		{ 33, 10 },
		{ 66, 38 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 10, 10 },
		{ 61, 34 },
		{ 67, 39 },
		{ 61, 34 },
		{ 68, 40 },
		{ 69, 41 },
		{ 70, 42 },
		{ 71, 43 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 72, 44 },
		{ 23, 1 },
		{ 73, 45 },
		{ 74, 46 },
		{ 75, 48 },
		{ 24, 1 },
		{ 76, 49 },
		{ 50, 25 },
		{ 79, 51 },
		{ 46, 22 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 35, 17 },
		{ 84, 54 },
		{ 85, 55 },
		{ 31, 1 },
		{ 86, 56 },
		{ 32, 1 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 57, 28 },
		{ 58, 29 },
		{ 91, 59 },
		{ 59, 30 },
		{ 0, 33 },
		{ 92, 63 },
		{ 93, 64 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 75, 65 },
		{ 49, 24 },
		{ 96, 67 },
		{ 97, 68 },
		{ 98, 69 },
		{ 99, 70 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 16, 157 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 100, 71 },
		{ 48, 72 },
		{ 101, 74 },
		{ 102, 76 },
		{ 103, 77 },
		{ 104, 78 },
		{ 48, 79 },
		{ 105, 80 },
		{ 106, 81 },
		{ 107, 82 },
		{ 108, 83 },
		{ 109, 84 },
		{ 110, 85 },
		{ 111, 86 },
		{ 112, 87 },
		{ 113, 88 },
		{ 114, 89 },
		{ 115, 90 },
		{ 116, 91 },
		{ 117, 92 },
		{ 118, 94 },
		{ 119, 95 },
		{ 120, 96 },
		{ 121, 97 },
		{ 122, 100 },
		{ 123, 103 },
		{ 124, 104 },
		{ 125, 105 },
		{ 126, 106 },
		{ 127, 107 },
		{ 128, 108 },
		{ 129, 109 },
		{ 130, 111 },
		{ 131, 112 },
		{ 132, 113 },
		{ 133, 115 },
		{ 134, 116 },
		{ 135, 119 },
		{ 136, 120 },
		{ 75, 121 },
		{ 137, 122 },
		{ 138, 123 },
		{ 139, 124 },
		{ 140, 125 },
		{ 141, 126 },
		{ 142, 127 },
		{ 143, 128 },
		{ 144, 129 },
		{ 145, 130 },
		{ 146, 132 },
		{ 147, 133 },
		{ 148, 135 },
		{ 149, 136 },
		{ 150, 138 },
		{ 151, 145 },
		{ 152, 146 },
		{ 153, 147 },
		{ 154, 148 },
		{ 155, 150 },
		{ 156, 152 },
		{ 157, 153 },
		{ 63, 35 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 157, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 1 },
		{ 0, 0, 5 },
		{ 0, 0, 6 },
		{ 0, 0, 19 },
		{ 0, 0, 15 },
		{ 0, 0, 16 },
		{ 0, 0, 20 },
		{ 60, 25, 13 },
		{ 0, 0, 4 },
		{ 0, 0, 10 },
		{ 0, 0, 14 },
		{ 0, 0, 12 },
		{ 0, 0, 18 },
		{ 157, 0, 45 },
		{ 157, -2, 45 },
		{ 157, -81, 45 },
		{ 157, -82, 45 },
		{ 157, -51, 45 },
		{ 157, -47, 45 },
		{ 157, -6, 45 },
		{ 157, -82, 45 },
		{ 157, 65, 45 },
		{ 157, 2, 45 },
		{ 157, -49, 45 },
		{ 157, -99, 45 },
		{ 157, 18, 45 },
		{ 157, 18, 45 },
		{ 157, 27, 45 },
		{ 0, 0, 7 },
		{ 0, 0, 8 },
		{ 60, 63, 0 },
		{ 62, 40, 0 },
		{ 157, 163, 45 },
		{ 157, -90, 45 },
		{ 157, -35, 45 },
		{ 157, -38, 45 },
		{ 157, -18, 45 },
		{ 157, -31, 27 },
		{ 157, -28, 45 },
		{ 157, -29, 45 },
		{ 157, -27, 45 },
		{ 157, -15, 45 },
		{ 157, -16, 45 },
		{ 157, -17, 45 },
		{ 157, 0, 17 },
		{ 157, -16, 45 },
		{ 157, -3, 45 },
		{ 157, -85, 45 },
		{ 157, -7, 45 },
		{ 157, -86, 45 },
		{ 157, -76, 45 },
		{ 157, 8, 45 },
		{ 157, 13, 45 },
		{ 157, 4, 45 },
		{ 157, -47, 45 },
		{ 157, -45, 45 },
		{ 157, 25, 45 },
		{ 0, -42, 13 },
		{ 62, 0, 0 },
		{ 0, 145, 13 },
		{ 157, 36, 45 },
		{ 157, 33, 45 },
		{ 157, 47, 45 },
		{ 157, -50, 45 },
		{ 157, 66, 45 },
		{ 157, 66, 45 },
		{ 157, 64, 45 },
		{ 157, 57, 45 },
		{ 157, 102, 45 },
		{ 157, 107, 45 },
		{ 157, 0, 11 },
		{ 157, 94, 45 },
		{ 157, 0, 9 },
		{ 157, 96, 45 },
		{ 157, 102, 45 },
		{ 157, 91, 45 },
		{ 157, 95, 45 },
		{ 157, 100, 45 },
		{ 157, 110, 45 },
		{ 157, 96, 45 },
		{ 157, 96, 45 },
		{ 157, 98, 45 },
		{ 157, 105, 45 },
		{ 157, 115, 45 },
		{ 157, 106, 45 },
		{ 157, 113, 45 },
		{ 157, 119, 45 },
		{ 157, 123, 45 },
		{ 157, 113, 45 },
		{ 157, 115, 45 },
		{ 157, 0, 23 },
		{ 157, 107, 45 },
		{ 157, 119, 45 },
		{ 157, 108, 45 },
		{ 157, 118, 45 },
		{ 157, 0, 28 },
		{ 157, 0, 29 },
		{ 157, 113, 45 },
		{ 157, 0, 32 },
		{ 157, 0, 3 },
		{ 157, 113, 45 },
		{ 157, 115, 45 },
		{ 157, 129, 45 },
		{ 157, 120, 45 },
		{ 157, 127, 45 },
		{ 157, 134, 45 },
		{ 157, 135, 45 },
		{ 157, 0, 21 },
		{ 157, 135, 45 },
		{ 157, 126, 45 },
		{ 157, 134, 45 },
		{ 157, 0, 2 },
		{ 157, 122, 45 },
		{ 157, 138, 45 },
		{ 157, 0, 22 },
		{ 157, 0, 24 },
		{ 157, 130, 45 },
		{ 157, 133, 45 },
		{ 157, 141, 45 },
		{ 157, 133, 45 },
		{ 157, 128, 45 },
		{ 157, 135, 45 },
		{ 157, 146, 45 },
		{ 157, 145, 45 },
		{ 157, 149, 45 },
		{ 157, 133, 45 },
		{ 157, 146, 45 },
		{ 157, 150, 45 },
		{ 157, 0, 42 },
		{ 157, 142, 45 },
		{ 157, 148, 45 },
		{ 157, 0, 44 },
		{ 157, 137, 45 },
		{ 157, 139, 45 },
		{ 157, 0, 30 },
		{ 157, 155, 45 },
		{ 157, 0, 33 },
		{ 157, 0, 35 },
		{ 157, 0, 37 },
		{ 157, 0, 38 },
		{ 157, 0, 39 },
		{ 157, 0, 40 },
		{ 157, 155, 45 },
		{ 157, 157, 45 },
		{ 157, 151, 45 },
		{ 157, 159, 45 },
		{ 157, 0, 26 },
		{ 157, 147, 45 },
		{ 157, 0, 41 },
		{ 157, 162, 45 },
		{ 157, 162, 45 },
		{ 157, 0, 25 },
		{ 157, 0, 34 },
		{ 157, 0, 36 },
		{ 0, 70, 43 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 183 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


