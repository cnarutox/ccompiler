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
* Time: 22:34:06
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
	case 46:
		{
#line 183 ".\\mylexer.l"
reserve(END, yytext);
#line 566 "mylexer.cpp"
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

	yytransitionmax = 316;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 4, 1 },
		{ 4, 4 },
		{ 4, 4 },
		{ 59, 29 },
		{ 84, 56 },
		{ 81, 54 },
		{ 38, 38 },
		{ 43, 21 },
		{ 65, 36 },
		{ 86, 57 },
		{ 65, 36 },
		{ 38, 38 },
		{ 38, 38 },
		{ 51, 25 },
		{ 38, 38 },
		{ 67, 39 },
		{ 38, 38 },
		{ 44, 21 },
		{ 82, 54 },
		{ 38, 38 },
		{ 60, 29 },
		{ 52, 25 },
		{ 4, 1 },
		{ 85, 56 },
		{ 4, 4 },
		{ 38, 38 },
		{ 87, 57 },
		{ 38, 38 },
		{ 98, 70 },
		{ 99, 70 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 38, 38 },
		{ 9, 1 },
		{ 38, 38 },
		{ 10, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 68, 40 },
		{ 69, 41 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 93, 62 },
		{ 70, 42 },
		{ 48, 23 },
		{ 94, 62 },
		{ 18, 1 },
		{ 49, 23 },
		{ 17, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 17, 1 },
		{ 25, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 26, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 33, 1 },
		{ 71, 43 },
		{ 34, 1 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 72, 44 },
		{ 73, 45 },
		{ 74, 46 },
		{ 75, 47 },
		{ 76, 48 },
		{ 77, 49 },
		{ 78, 50 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 79, 52 },
		{ 80, 53 },
		{ 50, 24 },
		{ 83, 55 },
		{ 17, 161 },
		{ 39, 19 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 17, 161 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 55, 28 },
		{ 56, 28 },
		{ 40, 20 },
		{ 91, 61 },
		{ 61, 30 },
		{ 45, 22 },
		{ 88, 58 },
		{ 46, 22 },
		{ 89, 59 },
		{ 41, 20 },
		{ 90, 60 },
		{ 36, 64 },
		{ 57, 28 },
		{ 92, 61 },
		{ 62, 31 },
		{ 58, 28 },
		{ 42, 20 },
		{ 47, 22 },
		{ 35, 11 },
		{ 63, 32 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 66, 66 },
		{ 95, 63 },
		{ 0, 35 },
		{ 53, 26 },
		{ 96, 67 },
		{ 97, 68 },
		{ 79, 69 },
		{ 37, 37 },
		{ 100, 71 },
		{ 101, 72 },
		{ 102, 73 },
		{ 103, 74 },
		{ 104, 75 },
		{ 52, 76 },
		{ 105, 78 },
		{ 106, 80 },
		{ 107, 81 },
		{ 108, 82 },
		{ 52, 83 },
		{ 109, 84 },
		{ 110, 85 },
		{ 111, 86 },
		{ 112, 87 },
		{ 113, 88 },
		{ 114, 89 },
		{ 115, 90 },
		{ 116, 91 },
		{ 117, 92 },
		{ 118, 93 },
		{ 119, 94 },
		{ 120, 95 },
		{ 121, 96 },
		{ 122, 98 },
		{ 123, 99 },
		{ 124, 100 },
		{ 125, 101 },
		{ 126, 104 },
		{ 127, 107 },
		{ 128, 108 },
		{ 129, 109 },
		{ 130, 110 },
		{ 131, 111 },
		{ 132, 112 },
		{ 133, 113 },
		{ 134, 115 },
		{ 135, 116 },
		{ 136, 117 },
		{ 137, 119 },
		{ 138, 120 },
		{ 139, 123 },
		{ 140, 124 },
		{ 79, 125 },
		{ 141, 126 },
		{ 142, 127 },
		{ 143, 128 },
		{ 144, 129 },
		{ 145, 130 },
		{ 146, 131 },
		{ 147, 132 },
		{ 148, 133 },
		{ 149, 134 },
		{ 150, 136 },
		{ 151, 137 },
		{ 152, 139 },
		{ 153, 140 },
		{ 154, 142 },
		{ 155, 149 },
		{ 156, 150 },
		{ 157, 151 },
		{ 158, 152 },
		{ 159, 154 },
		{ 160, 156 },
		{ 161, 157 },
		{ 54, 27 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 46 },
		{ 0, -6, 1 },
		{ 0, 0, 5 },
		{ 0, 0, 6 },
		{ 0, 0, 19 },
		{ 0, 0, 15 },
		{ 0, 0, 16 },
		{ 0, 0, 20 },
		{ 64, 175, 13 },
		{ 0, 0, 4 },
		{ 0, 0, 10 },
		{ 0, 0, 14 },
		{ 0, 0, 12 },
		{ 0, 0, 18 },
		{ 161, 0, 45 },
		{ 37, 0, 46 },
		{ 161, 52, 45 },
		{ 161, 108, 45 },
		{ 161, -92, 45 },
		{ 161, 100, 45 },
		{ 161, -23, 45 },
		{ 161, 52, 45 },
		{ 161, -87, 45 },
		{ 161, 148, 45 },
		{ 161, 214, 45 },
		{ 161, 99, 45 },
		{ 161, -99, 45 },
		{ 161, 97, 45 },
		{ 161, 106, 45 },
		{ 161, 118, 45 },
		{ 0, 0, 7 },
		{ 0, 0, 8 },
		{ 64, 175, 0 },
		{ 66, -33, 0 },
		{ 38, 154, 0 },
		{ 0, -87, 45 },
		{ 161, -84, 45 },
		{ 161, -60, 45 },
		{ 161, -41, 45 },
		{ 161, -26, 45 },
		{ 161, 14, 45 },
		{ 161, 11, 27 },
		{ 161, 14, 45 },
		{ 161, 13, 45 },
		{ 161, 15, 45 },
		{ 161, 21, 45 },
		{ 161, 19, 45 },
		{ 161, 18, 45 },
		{ 161, 0, 17 },
		{ 161, 45, 45 },
		{ 161, 57, 45 },
		{ 161, -96, 45 },
		{ 161, 53, 45 },
		{ 161, -97, 45 },
		{ 161, -86, 45 },
		{ 161, 104, 45 },
		{ 161, 110, 45 },
		{ 161, 101, 45 },
		{ 161, 101, 45 },
		{ 161, -22, 45 },
		{ 161, 138, 45 },
		{ 0, 145, 13 },
		{ 66, 0, 0 },
		{ 0, 185, 13 },
		{ 161, 149, 45 },
		{ 161, 146, 45 },
		{ 161, 134, 45 },
		{ 161, -85, 45 },
		{ 161, 153, 45 },
		{ 161, 153, 45 },
		{ 161, 151, 45 },
		{ 161, 144, 45 },
		{ 161, 153, 45 },
		{ 161, 158, 45 },
		{ 161, 0, 11 },
		{ 161, 145, 45 },
		{ 161, 0, 9 },
		{ 161, 147, 45 },
		{ 161, 153, 45 },
		{ 161, 142, 45 },
		{ 161, 146, 45 },
		{ 161, 151, 45 },
		{ 161, 161, 45 },
		{ 161, 147, 45 },
		{ 161, 147, 45 },
		{ 161, 149, 45 },
		{ 161, 156, 45 },
		{ 161, 166, 45 },
		{ 161, 157, 45 },
		{ 161, 164, 45 },
		{ 161, 170, 45 },
		{ 161, 174, 45 },
		{ 161, 164, 45 },
		{ 161, 166, 45 },
		{ 161, 0, 23 },
		{ 161, 158, 45 },
		{ 161, 170, 45 },
		{ 161, 159, 45 },
		{ 161, 169, 45 },
		{ 161, 0, 28 },
		{ 161, 0, 29 },
		{ 161, 164, 45 },
		{ 161, 0, 32 },
		{ 161, 0, 3 },
		{ 161, 164, 45 },
		{ 161, 166, 45 },
		{ 161, 180, 45 },
		{ 161, 171, 45 },
		{ 161, 178, 45 },
		{ 161, 185, 45 },
		{ 161, 186, 45 },
		{ 161, 0, 21 },
		{ 161, 186, 45 },
		{ 161, 177, 45 },
		{ 161, 185, 45 },
		{ 161, 0, 2 },
		{ 161, 173, 45 },
		{ 161, 189, 45 },
		{ 161, 0, 22 },
		{ 161, 0, 24 },
		{ 161, 181, 45 },
		{ 161, 184, 45 },
		{ 161, 192, 45 },
		{ 161, 184, 45 },
		{ 161, 179, 45 },
		{ 161, 186, 45 },
		{ 161, 197, 45 },
		{ 161, 196, 45 },
		{ 161, 200, 45 },
		{ 161, 184, 45 },
		{ 161, 197, 45 },
		{ 161, 201, 45 },
		{ 161, 0, 42 },
		{ 161, 193, 45 },
		{ 161, 199, 45 },
		{ 161, 0, 44 },
		{ 161, 188, 45 },
		{ 161, 190, 45 },
		{ 161, 0, 30 },
		{ 161, 206, 45 },
		{ 161, 0, 33 },
		{ 161, 0, 35 },
		{ 161, 0, 37 },
		{ 161, 0, 38 },
		{ 161, 0, 39 },
		{ 161, 0, 40 },
		{ 161, 206, 45 },
		{ 161, 208, 45 },
		{ 161, 202, 45 },
		{ 161, 210, 45 },
		{ 161, 0, 26 },
		{ 161, 198, 45 },
		{ 161, 0, 41 },
		{ 161, 213, 45 },
		{ 161, 213, 45 },
		{ 161, 0, 25 },
		{ 161, 0, 34 },
		{ 161, 0, 36 },
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
		0,
		0
	};
	yybackup = backup;
}
#line 184 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


