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
* Date: 11/04/18
* Time: 09:35:38
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
#define COMPARISON 13
#define ADD 14
#define MINUS 15
#define IF 16
#define ANNOTATION 17
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
#define LITERAL 44
string Words[] = {
    "END", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID",
    "SEMICOL", "FOR", "ASSIGN", "NUMBER", "COMPARISON", "ADD", "MINUS", "IF", "ANNOTATION",
    "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST", "CONTINUE",
    "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "GOTO", "RETURN", "REGISTER",
    "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDE", "UNION ",
    "UNSIGN", "VOLATI", "WHILE", "COLON", "LITERAL"
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
				case NUMBER: 
				case LITERAL: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
				default:
					cout << Words[word] << "\t\t" << element << endl; return;
			}
		}
	//δ���ڷ��ű���
	symbols.push_back(Symbol(word, element));
	switch (word)
	{
		case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols.back() << endl; return;
		case NUMBER: 
		case LITERAL: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
		default:
			cout << Words[word] << "\t\t" << element << endl; return;
	}
}


#line 140 "mylexer.cpp"
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
#line 115 ".\\mylexer.l"

	// place any extra initialisation code here

#line 164 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 120 ".\\mylexer.l"

	// place any extra cleanup code here

#line 176 "mylexer.cpp"
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
#line 138 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 247 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 144 ".\\mylexer.l"

#line 254 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 145 ".\\mylexer.l"

#line 261 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 146 ".\\mylexer.l"

#line 268 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 147 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 275 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 148 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 282 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 149 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 289 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 150 ".\\mylexer.l"
reserve(COLON, yytext);
#line 296 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 151 ".\\mylexer.l"
reserve(LP, yytext); 
#line 303 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 152 ".\\mylexer.l"
reserve(RP, yytext); 
#line 310 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 153 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 317 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 154 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 324 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 155 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 331 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 156 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 338 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 157 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 345 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 158 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 352 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 159 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 359 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 160 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 366 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 161 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 373 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 162 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 380 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 163 ".\\mylexer.l"
reserve(DIVIDE, yytext);
#line 387 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 164 ".\\mylexer.l"
reserve(IF, yytext); 
#line 394 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 165 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 401 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 166 ".\\mylexer.l"
reserve(THEN, yytext);
#line 408 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 167 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 415 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 168 ".\\mylexer.l"
reserve(CASE, yytext);
#line 422 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 169 ".\\mylexer.l"
reserve(CONST, yytext);
#line 429 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 170 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 436 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 171 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 443 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 172 ".\\mylexer.l"
reserve(DO, yytext);
#line 450 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 173 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 457 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 174 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 464 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 175 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 471 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 176 ".\\mylexer.l"
reserve(FOR, yytext);
#line 478 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 177 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 485 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 178 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 492 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 179 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 499 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 180 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 506 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 181 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 513 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 182 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 520 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 183 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 527 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 184 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 534 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 185 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 541 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 186 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 548 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 187 ".\\mylexer.l"
reserve(UNION, yytext);
#line 555 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 188 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 562 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 189 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 569 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 190 ".\\mylexer.l"
reserve(ID, yytext);
#line 576 "mylexer.cpp"
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

	yytransitionmax = 277;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 35, 5 },
		{ 3, 3 },
		{ 3, 3 },
		{ 61, 28 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 87, 58 },
		{ 84, 56 },
		{ 45, 20 },
		{ 94, 63 },
		{ 89, 59 },
		{ 0, 39 },
		{ 62, 28 },
		{ 3, 1 },
		{ 4, 1 },
		{ 5, 1 },
		{ 3, 3 },
		{ 40, 67 },
		{ 46, 20 },
		{ 95, 63 },
		{ 85, 56 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 88, 58 },
		{ 10, 1 },
		{ 90, 59 },
		{ 11, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 15, 1 },
		{ 57, 27 },
		{ 58, 27 },
		{ 42, 19 },
		{ 53, 24 },
		{ 34, 16 },
		{ 47, 21 },
		{ 36, 5 },
		{ 48, 21 },
		{ 66, 66 },
		{ 43, 19 },
		{ 70, 41 },
		{ 54, 24 },
		{ 59, 27 },
		{ 99, 66 },
		{ 37, 11 },
		{ 60, 27 },
		{ 44, 19 },
		{ 49, 21 },
		{ 39, 12 },
		{ 38, 11 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 12, 12 },
		{ 50, 22 },
		{ 96, 64 },
		{ 71, 42 },
		{ 51, 22 },
		{ 97, 64 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 68, 40 },
		{ 24, 1 },
		{ 68, 40 },
		{ 102, 73 },
		{ 103, 73 },
		{ 25, 1 },
		{ 72, 43 },
		{ 73, 44 },
		{ 74, 45 },
		{ 75, 46 },
		{ 26, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 76, 47 },
		{ 77, 48 },
		{ 78, 49 },
		{ 32, 1 },
		{ 79, 50 },
		{ 33, 1 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 80, 51 },
		{ 81, 52 },
		{ 82, 54 },
		{ 83, 55 },
		{ 55, 25 },
		{ 86, 57 },
		{ 56, 26 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 41, 18 },
		{ 91, 60 },
		{ 92, 61 },
		{ 93, 62 },
		{ 52, 23 },
		{ 63, 29 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 17, 165 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 98, 65 },
		{ 64, 30 },
		{ 65, 31 },
		{ 0, 36 },
		{ 100, 70 },
		{ 101, 71 },
		{ 82, 72 },
		{ 66, 37 },
		{ 104, 74 },
		{ 105, 75 },
		{ 106, 76 },
		{ 107, 77 },
		{ 108, 78 },
		{ 54, 79 },
		{ 109, 81 },
		{ 110, 83 },
		{ 111, 84 },
		{ 112, 85 },
		{ 54, 86 },
		{ 113, 87 },
		{ 114, 88 },
		{ 115, 89 },
		{ 116, 90 },
		{ 117, 91 },
		{ 118, 92 },
		{ 119, 93 },
		{ 120, 94 },
		{ 121, 95 },
		{ 122, 96 },
		{ 123, 97 },
		{ 124, 98 },
		{ 125, 100 },
		{ 126, 102 },
		{ 127, 103 },
		{ 128, 104 },
		{ 129, 105 },
		{ 130, 108 },
		{ 131, 111 },
		{ 132, 112 },
		{ 133, 113 },
		{ 134, 114 },
		{ 135, 115 },
		{ 136, 116 },
		{ 137, 117 },
		{ 138, 119 },
		{ 139, 120 },
		{ 140, 121 },
		{ 141, 123 },
		{ 142, 124 },
		{ 143, 127 },
		{ 144, 128 },
		{ 82, 129 },
		{ 145, 130 },
		{ 146, 131 },
		{ 147, 132 },
		{ 148, 133 },
		{ 149, 134 },
		{ 150, 135 },
		{ 151, 136 },
		{ 152, 137 },
		{ 153, 138 },
		{ 154, 140 },
		{ 155, 141 },
		{ 156, 143 },
		{ 157, 144 },
		{ 158, 146 },
		{ 159, 153 },
		{ 160, 154 },
		{ 161, 155 },
		{ 162, 156 },
		{ 163, 158 },
		{ 164, 160 },
		{ 165, 161 },
		{ 0, 38 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 165, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -5, 1 },
		{ 16, 0, 0 },
		{ -5, -31, 0 },
		{ 0, 0, 8 },
		{ 0, 0, 9 },
		{ 0, 0, 22 },
		{ 0, 0, 18 },
		{ 0, 0, 19 },
		{ 0, 27, 20 },
		{ 67, 27, 16 },
		{ 0, 0, 7 },
		{ 0, 0, 13 },
		{ 16, 0, 17 },
		{ 0, -2, 15 },
		{ 165, 0, 47 },
		{ 165, 47, 47 },
		{ 165, -40, 47 },
		{ 165, -82, 47 },
		{ 165, -48, 47 },
		{ 165, -23, 47 },
		{ 165, 54, 47 },
		{ 165, -44, 47 },
		{ 165, 35, 47 },
		{ 165, 33, 47 },
		{ 165, -49, 47 },
		{ 165, -98, 47 },
		{ 165, 56, 47 },
		{ 165, 93, 47 },
		{ 165, 101, 47 },
		{ 0, 0, 10 },
		{ 0, 0, 11 },
		{ 0, 0, 17 },
		{ 0, 0, 4 },
		{ -5, 196, 0 },
		{ -37, 168, 0 },
		{ -38, 266, 3 },
		{ 67, -47, 0 },
		{ 69, 53, 0 },
		{ 165, -36, 47 },
		{ 165, -28, 47 },
		{ 165, 5, 47 },
		{ 165, -7, 47 },
		{ 165, 2, 47 },
		{ 165, -12, 29 },
		{ 165, -3, 47 },
		{ 165, -4, 47 },
		{ 165, -2, 47 },
		{ 165, 5, 47 },
		{ 165, 14, 47 },
		{ 165, 13, 47 },
		{ 165, 0, 21 },
		{ 165, 14, 47 },
		{ 165, 26, 47 },
		{ 165, -85, 47 },
		{ 165, 22, 47 },
		{ 165, -86, 47 },
		{ 165, -76, 47 },
		{ 165, 57, 47 },
		{ 165, 62, 47 },
		{ 165, 52, 47 },
		{ 165, -85, 47 },
		{ 165, -19, 47 },
		{ 165, 98, 47 },
		{ -37, 21, 0 },
		{ 0, -41, 16 },
		{ 69, 0, 0 },
		{ 0, 145, 16 },
		{ 165, 110, 47 },
		{ 165, 107, 47 },
		{ 165, 95, 47 },
		{ 165, -16, 47 },
		{ 165, 114, 47 },
		{ 165, 114, 47 },
		{ 165, 112, 47 },
		{ 165, 105, 47 },
		{ 165, 114, 47 },
		{ 165, 119, 47 },
		{ 165, 0, 14 },
		{ 165, 106, 47 },
		{ 165, 0, 12 },
		{ 165, 108, 47 },
		{ 165, 114, 47 },
		{ 165, 103, 47 },
		{ 165, 107, 47 },
		{ 165, 112, 47 },
		{ 165, 122, 47 },
		{ 165, 108, 47 },
		{ 165, 108, 47 },
		{ 165, 110, 47 },
		{ 165, 117, 47 },
		{ 165, 127, 47 },
		{ 165, 118, 47 },
		{ 165, 125, 47 },
		{ 165, 131, 47 },
		{ 165, 135, 47 },
		{ 165, 125, 47 },
		{ 0, 0, 2 },
		{ 165, 127, 47 },
		{ 165, 0, 25 },
		{ 165, 119, 47 },
		{ 165, 131, 47 },
		{ 165, 120, 47 },
		{ 165, 130, 47 },
		{ 165, 0, 30 },
		{ 165, 0, 31 },
		{ 165, 125, 47 },
		{ 165, 0, 34 },
		{ 165, 0, 6 },
		{ 165, 125, 47 },
		{ 165, 127, 47 },
		{ 165, 141, 47 },
		{ 165, 132, 47 },
		{ 165, 139, 47 },
		{ 165, 146, 47 },
		{ 165, 147, 47 },
		{ 165, 0, 23 },
		{ 165, 147, 47 },
		{ 165, 138, 47 },
		{ 165, 146, 47 },
		{ 165, 0, 5 },
		{ 165, 134, 47 },
		{ 165, 150, 47 },
		{ 165, 0, 24 },
		{ 165, 0, 26 },
		{ 165, 142, 47 },
		{ 165, 145, 47 },
		{ 165, 153, 47 },
		{ 165, 145, 47 },
		{ 165, 140, 47 },
		{ 165, 147, 47 },
		{ 165, 158, 47 },
		{ 165, 157, 47 },
		{ 165, 161, 47 },
		{ 165, 145, 47 },
		{ 165, 158, 47 },
		{ 165, 162, 47 },
		{ 165, 0, 44 },
		{ 165, 154, 47 },
		{ 165, 160, 47 },
		{ 165, 0, 46 },
		{ 165, 149, 47 },
		{ 165, 151, 47 },
		{ 165, 0, 32 },
		{ 165, 167, 47 },
		{ 165, 0, 35 },
		{ 165, 0, 37 },
		{ 165, 0, 39 },
		{ 165, 0, 40 },
		{ 165, 0, 41 },
		{ 165, 0, 42 },
		{ 165, 167, 47 },
		{ 165, 169, 47 },
		{ 165, 163, 47 },
		{ 165, 171, 47 },
		{ 165, 0, 28 },
		{ 165, 159, 47 },
		{ 165, 0, 43 },
		{ 165, 174, 47 },
		{ 165, 174, 47 },
		{ 165, 0, 27 },
		{ 165, 0, 36 },
		{ 165, 0, 38 },
		{ 0, 70, 45 }
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
		0,
		0
	};
	yybackup = backup;
}
#line 191 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


