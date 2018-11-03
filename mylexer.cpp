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
* Time: 23:13:16
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
#line 146 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 255 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 152 ".\\mylexer.l"

#line 262 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 153 ".\\mylexer.l"

#line 269 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 154 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 276 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 155 ".\\mylexer.l"
comment();
#line 283 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 156 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 290 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 157 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 297 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 158 ".\\mylexer.l"
reserve(COLON, yytext);
#line 304 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 159 ".\\mylexer.l"
reserve(LP, yytext); 
#line 311 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 160 ".\\mylexer.l"
reserve(RP, yytext); 
#line 318 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 161 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 325 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 162 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 332 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 163 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 339 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 164 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 346 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 165 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 353 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 166 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 360 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 167 ".\\mylexer.l"
reserve(END, yytext);
#line 367 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 168 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 374 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 169 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 381 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 170 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 388 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 171 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 395 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 172 ".\\mylexer.l"
reserve(IF, yytext); 
#line 402 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 173 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 409 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 174 ".\\mylexer.l"
reserve(THEN, yytext);
#line 416 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 175 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 423 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 176 ".\\mylexer.l"
reserve(CASE, yytext);
#line 430 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 177 ".\\mylexer.l"
reserve(CONST, yytext);
#line 437 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 178 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 444 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 179 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 451 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 180 ".\\mylexer.l"
reserve(DO, yytext);
#line 458 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 181 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 465 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 182 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 472 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 183 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 479 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 184 ".\\mylexer.l"
reserve(FOR, yytext);
#line 486 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 185 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 493 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 186 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 500 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 187 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 507 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 188 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 514 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 189 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 521 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 190 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 528 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 191 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 535 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 192 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 542 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 193 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 549 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 194 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 556 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 195 ".\\mylexer.l"
reserve(UNION, yytext);
#line 563 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 196 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 570 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 197 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 577 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 198 ".\\mylexer.l"
reserve(ID, yytext);
#line 584 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 199 ".\\mylexer.l"
reserve(END, yytext);
#line 591 "mylexer.cpp"
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

	yytransitionmax = 424;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 4, 1 },
		{ 0, 72 },
		{ 90, 61 },
		{ 0, 72 },
		{ 78, 49 },
		{ 4, 4 },
		{ 4, 4 },
		{ 87, 59 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 56, 25 },
		{ 64, 29 },
		{ 88, 59 },
		{ 91, 61 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 37, 36 },
		{ 57, 25 },
		{ 104, 72 },
		{ 4, 4 },
		{ 43, 70 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 79, 50 },
		{ 11, 1 },
		{ 65, 29 },
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
		{ 107, 76 },
		{ 108, 76 },
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
		{ 39, 12 },
		{ 71, 43 },
		{ 38, 36 },
		{ 71, 43 },
		{ 18, 1 },
		{ 40, 12 },
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
		{ 92, 62 },
		{ 34, 1 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 99, 67 },
		{ 69, 69 },
		{ 80, 51 },
		{ 100, 67 },
		{ 81, 52 },
		{ 93, 62 },
		{ 102, 69 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 53, 23 },
		{ 82, 53 },
		{ 83, 54 },
		{ 54, 23 },
		{ 18, 172 },
		{ 84, 55 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 18, 172 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 104, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 85, 57 },
		{ 86, 58 },
		{ 55, 24 },
		{ 89, 60 },
		{ 42, 149 },
		{ 66, 30 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 149 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 42, 42 },
		{ 60, 28 },
		{ 61, 28 },
		{ 45, 20 },
		{ 97, 66 },
		{ 48, 21 },
		{ 67, 31 },
		{ 50, 22 },
		{ 94, 63 },
		{ 51, 22 },
		{ 46, 20 },
		{ 95, 64 },
		{ 42, 42 },
		{ 62, 28 },
		{ 98, 66 },
		{ 49, 21 },
		{ 63, 28 },
		{ 47, 20 },
		{ 130, 104 },
		{ 52, 22 },
		{ 130, 104 },
		{ 96, 65 },
		{ 68, 32 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 72, 104 },
		{ 41, 13 },
		{ 35, 17 },
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
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 103, 71 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 149, 130 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 70, 41 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 101, 68 },
		{ 0, 38 },
		{ 69, 39 },
		{ 58, 26 },
		{ 59, 27 },
		{ 105, 73 },
		{ 106, 74 },
		{ 85, 75 },
		{ 44, 19 },
		{ 109, 77 },
		{ 110, 78 },
		{ 111, 79 },
		{ 112, 80 },
		{ 113, 81 },
		{ 57, 82 },
		{ 114, 84 },
		{ 115, 86 },
		{ 116, 87 },
		{ 117, 88 },
		{ 57, 89 },
		{ 118, 90 },
		{ 119, 91 },
		{ 120, 92 },
		{ 121, 93 },
		{ 122, 94 },
		{ 123, 95 },
		{ 124, 96 },
		{ 125, 97 },
		{ 126, 98 },
		{ 127, 99 },
		{ 128, 100 },
		{ 129, 101 },
		{ 73, 44 },
		{ 74, 45 },
		{ 131, 105 },
		{ 132, 107 },
		{ 133, 108 },
		{ 134, 109 },
		{ 135, 110 },
		{ 136, 113 },
		{ 137, 116 },
		{ 138, 117 },
		{ 139, 118 },
		{ 140, 119 },
		{ 141, 120 },
		{ 142, 121 },
		{ 143, 122 },
		{ 144, 124 },
		{ 145, 125 },
		{ 146, 126 },
		{ 147, 128 },
		{ 148, 129 },
		{ 75, 46 },
		{ 150, 133 },
		{ 151, 134 },
		{ 85, 135 },
		{ 152, 136 },
		{ 153, 137 },
		{ 154, 138 },
		{ 155, 139 },
		{ 156, 140 },
		{ 157, 141 },
		{ 158, 142 },
		{ 159, 143 },
		{ 160, 144 },
		{ 161, 146 },
		{ 162, 147 },
		{ 76, 47 },
		{ 163, 150 },
		{ 164, 151 },
		{ 165, 153 },
		{ 166, 160 },
		{ 167, 161 },
		{ 168, 162 },
		{ 169, 163 },
		{ 170, 165 },
		{ 171, 167 },
		{ 172, 168 },
		{ 77, 48 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 48 },
		{ 0, -2, 1 },
		{ 17, 0, 48 },
		{ 36, 0, 48 },
		{ 0, 0, 8 },
		{ 0, 0, 9 },
		{ 0, 0, 22 },
		{ 0, 0, 19 },
		{ 0, 0, 20 },
		{ 0, 41, 48 },
		{ 70, 247, 17 },
		{ 0, 0, 7 },
		{ 0, 0, 13 },
		{ 17, 0, 18 },
		{ 0, 233, 15 },
		{ 172, 0, 47 },
		{ 172, 239, 47 },
		{ 172, 166, 47 },
		{ 172, 164, 47 },
		{ 172, 159, 47 },
		{ 172, 53, 47 },
		{ 172, 110, 47 },
		{ 172, -82, 47 },
		{ 172, 251, 47 },
		{ 172, 248, 47 },
		{ 172, 157, 47 },
		{ 172, -83, 47 },
		{ 172, 114, 47 },
		{ 172, 155, 47 },
		{ 172, 178, 47 },
		{ 0, 0, 10 },
		{ 0, 0, 11 },
		{ 0, 0, 18 },
		{ -36, -7, 0 },
		{ 0, 0, 3 },
		{ -36, 336, 0 },
		{ -39, 305, 0 },
		{ 0, 0, 4 },
		{ 0, 277, 0 },
		{ 149, 203, 16 },
		{ 104, 41, 16 },
		{ 172, 276, 47 },
		{ 172, 263, 47 },
		{ 172, 300, 47 },
		{ 172, 302, 47 },
		{ 172, 321, 47 },
		{ 172, -111, 29 },
		{ 172, -79, 47 },
		{ 172, 13, 47 },
		{ 172, 16, 47 },
		{ 172, 51, 47 },
		{ 172, 49, 47 },
		{ 172, 50, 47 },
		{ 172, 0, 21 },
		{ 172, 103, 47 },
		{ 172, 115, 47 },
		{ 172, -94, 47 },
		{ 172, 111, 47 },
		{ 172, -99, 47 },
		{ 172, 19, 47 },
		{ 172, 163, 47 },
		{ 172, 170, 47 },
		{ 172, 169, 47 },
		{ 172, 159, 47 },
		{ 172, 23, 47 },
		{ 172, 240, 47 },
		{ -39, 87, 0 },
		{ 149, -38, 17 },
		{ 0, 257, 0 },
		{ 104, -40, 16 },
		{ 172, 253, 47 },
		{ 172, 250, 47 },
		{ 172, 238, 47 },
		{ 172, -60, 47 },
		{ 172, 257, 47 },
		{ 172, 257, 47 },
		{ 172, 255, 47 },
		{ 172, 248, 47 },
		{ 172, 257, 47 },
		{ 172, 262, 47 },
		{ 172, 0, 14 },
		{ 172, 249, 47 },
		{ 172, 0, 12 },
		{ 172, 251, 47 },
		{ 172, 257, 47 },
		{ 172, 246, 47 },
		{ 172, 250, 47 },
		{ 172, 255, 47 },
		{ 172, 265, 47 },
		{ 172, 251, 47 },
		{ 172, 251, 47 },
		{ 172, 253, 47 },
		{ 172, 260, 47 },
		{ 172, 270, 47 },
		{ 172, 261, 47 },
		{ 172, 268, 47 },
		{ 172, 274, 47 },
		{ 172, 278, 47 },
		{ 172, 268, 47 },
		{ 0, 0, 2 },
		{ 149, 287, 17 },
		{ 42, 235, 16 },
		{ 172, 272, 47 },
		{ 172, 0, 25 },
		{ 172, 264, 47 },
		{ 172, 276, 47 },
		{ 172, 265, 47 },
		{ 172, 275, 47 },
		{ 172, 0, 30 },
		{ 172, 0, 31 },
		{ 172, 270, 47 },
		{ 172, 0, 34 },
		{ 172, 0, 6 },
		{ 172, 270, 47 },
		{ 172, 272, 47 },
		{ 172, 286, 47 },
		{ 172, 277, 47 },
		{ 172, 284, 47 },
		{ 172, 291, 47 },
		{ 172, 292, 47 },
		{ 172, 0, 23 },
		{ 172, 292, 47 },
		{ 172, 283, 47 },
		{ 172, 291, 47 },
		{ 172, 0, 5 },
		{ 172, 279, 47 },
		{ 172, 295, 47 },
		{ 0, 267, 0 },
		{ 172, 0, 24 },
		{ 172, 0, 26 },
		{ 172, 288, 47 },
		{ 172, 291, 47 },
		{ 172, 299, 47 },
		{ 172, 291, 47 },
		{ 172, 286, 47 },
		{ 172, 293, 47 },
		{ 172, 304, 47 },
		{ 172, 303, 47 },
		{ 172, 307, 47 },
		{ 172, 291, 47 },
		{ 172, 304, 47 },
		{ 172, 308, 47 },
		{ 172, 0, 44 },
		{ 172, 300, 47 },
		{ 172, 306, 47 },
		{ 172, 0, 46 },
		{ 130, 128, 0 },
		{ 172, 296, 47 },
		{ 172, 298, 47 },
		{ 172, 0, 32 },
		{ 172, 314, 47 },
		{ 172, 0, 35 },
		{ 172, 0, 37 },
		{ 172, 0, 39 },
		{ 172, 0, 40 },
		{ 172, 0, 41 },
		{ 172, 0, 42 },
		{ 172, 314, 47 },
		{ 172, 316, 47 },
		{ 172, 310, 47 },
		{ 172, 318, 47 },
		{ 172, 0, 28 },
		{ 172, 306, 47 },
		{ 172, 0, 43 },
		{ 172, 321, 47 },
		{ 172, 321, 47 },
		{ 172, 0, 27 },
		{ 172, 0, 36 },
		{ 172, 0, 38 },
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
		0,
		0
	};
	yybackup = backup;
}
#line 200 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


