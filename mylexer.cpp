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
* Time: 22:45:36
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

void comment()
{
	char c;
	cin >> c;
    while (c != '\n')
        cin >> c;
}


#line 148 "mylexer.cpp"
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
#line 123 ".\\mylexer.l"

	// place any extra initialisation code here

#line 172 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 128 ".\\mylexer.l"

	// place any extra cleanup code here

#line 184 "mylexer.cpp"
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
#line 145 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 255 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 151 ".\\mylexer.l"

#line 262 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 152 ".\\mylexer.l"

#line 269 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 153 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 276 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 154 ".\\mylexer.l"
comment();
#line 283 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 155 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 290 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 156 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 297 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 157 ".\\mylexer.l"
reserve(COLON, yytext);
#line 304 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 158 ".\\mylexer.l"
reserve(LP, yytext); 
#line 311 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 159 ".\\mylexer.l"
reserve(RP, yytext); 
#line 318 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 160 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 325 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 161 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 332 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 162 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 339 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 163 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 346 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 164 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 353 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 165 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 360 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 166 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 367 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 167 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 374 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 168 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 381 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 169 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 388 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 170 ".\\mylexer.l"
reserve(IF, yytext); 
#line 395 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 171 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 402 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 172 ".\\mylexer.l"
reserve(THEN, yytext);
#line 409 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 173 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 416 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 174 ".\\mylexer.l"
reserve(CASE, yytext);
#line 423 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 175 ".\\mylexer.l"
reserve(CONST, yytext);
#line 430 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 176 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 437 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 177 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 444 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 178 ".\\mylexer.l"
reserve(DO, yytext);
#line 451 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 179 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 458 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 180 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 465 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 181 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 472 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 182 ".\\mylexer.l"
reserve(FOR, yytext);
#line 479 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 183 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 486 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 184 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 493 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 185 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 500 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 186 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 507 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 187 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 514 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 188 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 521 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 189 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 528 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 190 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 535 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 191 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 542 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 192 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 549 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 193 ".\\mylexer.l"
reserve(UNION, yytext);
#line 556 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 194 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 563 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 195 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 570 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 196 ".\\mylexer.l"
reserve(ID, yytext);
#line 577 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 197 ".\\mylexer.l"
reserve(END, yytext);
#line 584 "mylexer.cpp"
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
		{ 89, 60 },
		{ 63, 29 },
		{ 4, 4 },
		{ 4, 4 },
		{ 86, 58 },
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
		{ 57, 26 },
		{ 91, 61 },
		{ 87, 58 },
		{ 64, 29 },
		{ 90, 60 },
		{ 55, 25 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 37, 36 },
		{ 4, 4 },
		{ 42, 69 },
		{ 72, 43 },
		{ 56, 25 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 92, 61 },
		{ 11, 1 },
		{ 73, 44 },
		{ 12, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 16, 1 },
		{ 104, 75 },
		{ 105, 75 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 68, 68 },
		{ 70, 42 },
		{ 38, 36 },
		{ 70, 42 },
		{ 18, 1 },
		{ 101, 68 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 18, 1 },
		{ 25, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 26, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 33, 1 },
		{ 74, 45 },
		{ 34, 1 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 39, 12 },
		{ 52, 23 },
		{ 75, 46 },
		{ 98, 66 },
		{ 53, 23 },
		{ 40, 12 },
		{ 99, 66 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 76, 47 },
		{ 77, 48 },
		{ 78, 49 },
		{ 79, 50 },
		{ 18, 167 },
		{ 80, 51 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 18, 167 },
		{ 59, 28 },
		{ 60, 28 },
		{ 44, 20 },
		{ 47, 21 },
		{ 96, 65 },
		{ 49, 22 },
		{ 81, 52 },
		{ 50, 22 },
		{ 82, 53 },
		{ 45, 20 },
		{ 83, 54 },
		{ 84, 56 },
		{ 61, 28 },
		{ 48, 21 },
		{ 97, 65 },
		{ 62, 28 },
		{ 46, 20 },
		{ 51, 22 },
		{ 41, 13 },
		{ 85, 57 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 13, 13 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 58, 27 },
		{ 88, 59 },
		{ 43, 19 },
		{ 54, 24 },
		{ 93, 62 },
		{ 94, 63 },
		{ 95, 64 },
		{ 65, 30 },
		{ 66, 31 },
		{ 100, 67 },
		{ 67, 32 },
		{ 35, 17 },
		{ 0, 38 },
		{ 102, 72 },
		{ 103, 73 },
		{ 84, 74 },
		{ 68, 39 },
		{ 106, 76 },
		{ 107, 77 },
		{ 108, 78 },
		{ 109, 79 },
		{ 110, 80 },
		{ 56, 81 },
		{ 111, 83 },
		{ 112, 85 },
		{ 113, 86 },
		{ 114, 87 },
		{ 56, 88 },
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
		{ 125, 99 },
		{ 126, 100 },
		{ 127, 102 },
		{ 128, 104 },
		{ 129, 105 },
		{ 130, 106 },
		{ 131, 107 },
		{ 132, 110 },
		{ 133, 113 },
		{ 134, 114 },
		{ 135, 115 },
		{ 136, 116 },
		{ 137, 117 },
		{ 138, 118 },
		{ 139, 119 },
		{ 140, 121 },
		{ 141, 122 },
		{ 142, 123 },
		{ 143, 125 },
		{ 144, 126 },
		{ 145, 129 },
		{ 146, 130 },
		{ 84, 131 },
		{ 147, 132 },
		{ 148, 133 },
		{ 149, 134 },
		{ 150, 135 },
		{ 151, 136 },
		{ 152, 137 },
		{ 153, 138 },
		{ 154, 139 },
		{ 155, 140 },
		{ 156, 142 },
		{ 157, 143 },
		{ 158, 145 },
		{ 159, 146 },
		{ 160, 148 },
		{ 161, 155 },
		{ 162, 156 },
		{ 163, 157 },
		{ 164, 158 },
		{ 165, 160 },
		{ 166, 162 },
		{ 167, 163 },
		{ 0, 41 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 47 },
		{ 0, -4, 1 },
		{ 17, 0, 47 },
		{ 36, 0, 47 },
		{ 0, 0, 8 },
		{ 0, 0, 9 },
		{ 0, 0, 21 },
		{ 0, 0, 18 },
		{ 0, 0, 19 },
		{ 0, 86, 47 },
		{ 69, 165, 16 },
		{ 0, 0, 7 },
		{ 0, 0, 13 },
		{ 17, 0, 17 },
		{ 0, 183, 15 },
		{ 167, 0, 46 },
		{ 167, 121, 46 },
		{ 167, 98, 46 },
		{ 167, 95, 46 },
		{ 167, 90, 46 },
		{ 167, 21, 46 },
		{ 167, 125, 46 },
		{ 167, -79, 46 },
		{ 167, -79, 46 },
		{ 167, 132, 46 },
		{ 167, 89, 46 },
		{ 167, -100, 46 },
		{ 167, 130, 46 },
		{ 167, 130, 46 },
		{ 167, 139, 46 },
		{ 0, 0, 10 },
		{ 0, 0, 11 },
		{ 0, 0, 17 },
		{ -36, -7, 0 },
		{ 0, 0, 3 },
		{ -36, 235, 0 },
		{ -39, 207, 0 },
		{ 0, 0, 4 },
		{ 69, 246, 0 },
		{ 71, 41, 0 },
		{ 167, -71, 46 },
		{ 167, -77, 46 },
		{ 167, 19, 46 },
		{ 167, 20, 46 },
		{ 167, 59, 46 },
		{ 167, 45, 28 },
		{ 167, 48, 46 },
		{ 167, 47, 46 },
		{ 167, 50, 46 },
		{ 167, 88, 46 },
		{ 167, 87, 46 },
		{ 167, 87, 46 },
		{ 167, 0, 20 },
		{ 167, 88, 46 },
		{ 167, 107, 46 },
		{ 167, -96, 46 },
		{ 167, 123, 46 },
		{ 167, -100, 46 },
		{ 167, -78, 46 },
		{ 167, 132, 46 },
		{ 167, 137, 46 },
		{ 167, 127, 46 },
		{ 167, 92, 46 },
		{ 167, 26, 46 },
		{ 167, 137, 46 },
		{ -39, 41, 0 },
		{ 0, -40, 16 },
		{ 71, 0, 0 },
		{ 0, 175, 16 },
		{ 167, 149, 46 },
		{ 167, 146, 46 },
		{ 167, 134, 46 },
		{ 167, -60, 46 },
		{ 167, 153, 46 },
		{ 167, 153, 46 },
		{ 167, 151, 46 },
		{ 167, 144, 46 },
		{ 167, 153, 46 },
		{ 167, 158, 46 },
		{ 167, 0, 14 },
		{ 167, 145, 46 },
		{ 167, 0, 12 },
		{ 167, 147, 46 },
		{ 167, 153, 46 },
		{ 167, 142, 46 },
		{ 167, 146, 46 },
		{ 167, 151, 46 },
		{ 167, 161, 46 },
		{ 167, 147, 46 },
		{ 167, 147, 46 },
		{ 167, 149, 46 },
		{ 167, 156, 46 },
		{ 167, 166, 46 },
		{ 167, 157, 46 },
		{ 167, 164, 46 },
		{ 167, 170, 46 },
		{ 167, 174, 46 },
		{ 167, 164, 46 },
		{ 0, 0, 2 },
		{ 167, 166, 46 },
		{ 167, 0, 24 },
		{ 167, 158, 46 },
		{ 167, 170, 46 },
		{ 167, 159, 46 },
		{ 167, 169, 46 },
		{ 167, 0, 29 },
		{ 167, 0, 30 },
		{ 167, 164, 46 },
		{ 167, 0, 33 },
		{ 167, 0, 6 },
		{ 167, 164, 46 },
		{ 167, 166, 46 },
		{ 167, 180, 46 },
		{ 167, 171, 46 },
		{ 167, 178, 46 },
		{ 167, 185, 46 },
		{ 167, 186, 46 },
		{ 167, 0, 22 },
		{ 167, 186, 46 },
		{ 167, 177, 46 },
		{ 167, 185, 46 },
		{ 167, 0, 5 },
		{ 167, 173, 46 },
		{ 167, 189, 46 },
		{ 167, 0, 23 },
		{ 167, 0, 25 },
		{ 167, 181, 46 },
		{ 167, 184, 46 },
		{ 167, 192, 46 },
		{ 167, 184, 46 },
		{ 167, 179, 46 },
		{ 167, 186, 46 },
		{ 167, 197, 46 },
		{ 167, 196, 46 },
		{ 167, 200, 46 },
		{ 167, 184, 46 },
		{ 167, 197, 46 },
		{ 167, 201, 46 },
		{ 167, 0, 43 },
		{ 167, 193, 46 },
		{ 167, 199, 46 },
		{ 167, 0, 45 },
		{ 167, 188, 46 },
		{ 167, 190, 46 },
		{ 167, 0, 31 },
		{ 167, 206, 46 },
		{ 167, 0, 34 },
		{ 167, 0, 36 },
		{ 167, 0, 38 },
		{ 167, 0, 39 },
		{ 167, 0, 40 },
		{ 167, 0, 41 },
		{ 167, 206, 46 },
		{ 167, 208, 46 },
		{ 167, 202, 46 },
		{ 167, 210, 46 },
		{ 167, 0, 27 },
		{ 167, 198, 46 },
		{ 167, 0, 42 },
		{ 167, 213, 46 },
		{ 167, 213, 46 },
		{ 167, 0, 26 },
		{ 167, 0, 35 },
		{ 167, 0, 37 },
		{ 0, 70, 44 }
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
#line 198 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


