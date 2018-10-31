/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 22 of your 30 day trial period.
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
* Date: 10/31/18
* Time: 16:01:31
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

Date: 2018年10月28日
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
#define FOR 30
#define GOTO 31
#define RETURN 32
#define REGISTER 33
#define SIGNED 34
#define SIZEOF 35
#define STATIC 36
#define STRUCT 37
#define SWITCH 38
#define TYPEDEF 39
#define UNION 40
#define UNSIGNED 41
#define VOLATILE 42
#define WHILE 43
#define COLON 44
string Words[] = { "END", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID", "SEMICOL", "FOR", "ASSIGN", "NUMBER", "LESS", "ADD", "MINUS", "IF", "MORE", "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST", "CONTINUE", "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "FOR", "GOTO", "RETURN", "REGISTER", "COLON"};
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
	// 已存在符号表中
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
	//未存在符号表中
	symbols.push_back(Symbol(word, element));
	switch (word)
	{
		case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols.back() << endl; return;
		case NUMBER: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
		default:
			cout << Words[word] << "\t\t" << element << endl; return;
	}
}


#line 131 "mylexer.cpp"
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
#line 106 ".\\mylexer.l"

	// place any extra initialisation code here

#line 155 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 111 ".\\mylexer.l"

	// place any extra cleanup code here

#line 167 "mylexer.cpp"
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
#line 126 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 238 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 132 ".\\mylexer.l"

#line 245 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 133 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 252 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 134 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 259 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 135 ".\\mylexer.l"
reverve(COLON, yytext);
#line 266 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 136 ".\\mylexer.l"
reserve(LP, yytext); 
#line 273 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 137 ".\\mylexer.l"
reserve(RP, yytext); 
#line 280 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 138 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 287 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 139 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 294 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 140 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 301 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 141 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 308 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 142 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 315 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 143 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 322 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 144 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 329 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 145 ".\\mylexer.l"
reserve(LESS, yytext); 
#line 336 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 146 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 343 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 147 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 350 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 148 ".\\mylexer.l"
reserve(IF, yytext); 
#line 357 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 149 ".\\mylexer.l"
reserve(MORE, yytext); 
#line 364 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 150 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 371 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 151 ".\\mylexer.l"
reserve(DIVIDE, yytext); 
#line 378 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 152 ".\\mylexer.l"
reverve(THEN, yytext);
#line 385 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 153 ".\\mylexer.l"
reverve(BREAK, yytext);
#line 392 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 154 ".\\mylexer.l"
reverve(CASE, yytext);
#line 399 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 155 ".\\mylexer.l"
reverve(CONST, yytext);
#line 406 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 156 ".\\mylexer.l"
reverve(CONTINUE, yytext);
#line 413 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 157 ".\\mylexer.l"
reverve(DEFAULT, yytext);
#line 420 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 158 ".\\mylexer.l"
reverve(DO, yytext);
#line 427 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 159 ".\\mylexer.l"
reverve(DOUBLE, yytext);
#line 434 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 160 ".\\mylexer.l"
reverve(ENUM, yytextt);
#line 441 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 161 ".\\mylexer.l"
reverve(EXTERN, yytext);
#line 448 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 162 ".\\mylexer.l"
reverve(FLOAT, yytext);
#line 455 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 163 ".\\mylexer.l"
reverve(GOTO, yytext);
#line 462 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 164 ".\\mylexer.l"
reverve(RETURN, yytext);
#line 469 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 165 ".\\mylexer.l"
reverve(REGISTER, yytext);
#line 476 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 166 ".\\mylexer.l"
reverve(SHORT, yytext);
#line 483 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 167 ".\\mylexer.l"
reverve(UNSIGNED, yytext);
#line 490 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 168 ".\\mylexer.l"
reverve(SIZEOF, yytext);
#line 497 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 169 ".\\mylexer.l"
reverve(STATIC, yytext);
#line 504 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 170 ".\\mylexer.l"
reverve(STRUCT, yytext);
#line 511 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 171 ".\\mylexer.l"
reverve(SWITVH, yytext);
#line 518 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 172 ".\\mylexer.l"
reverve(TYPEDEF, yytext);
#line 525 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 173 ".\\mylexer.l"
reverve(TYPEDEF, yytext);
#line 532 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 174 ".\\mylexer.l"
reverve(VOLATILE, yytext);
#line 539 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 175 ".\\mylexer.l"
reverve(WHILE, yytext);
#line 546 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 176 ".\\mylexer.l"
reserve(ID, yytext);
#line 553 "mylexer.cpp"
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
#line 177 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


