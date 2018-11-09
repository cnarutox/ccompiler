/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 31 of your 30 day trial period.
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
* Date: 11/09/18
* Time: 20:10:07
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

Date: 2018锟斤拷10锟斤拷28锟斤拷
****************************************************************************/

#include "myparser.h"
#include <vector>
#include <string>
using namespace std;
#define ERROR 0
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
#define LOGIC 45
#define BOOLOP 46
#define LSQUBRAC 47
#define RSQUBRAC 48
int Line = 1;
string Words[] = {
    "ERROR", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID",
    "SEMICOL", "FOR", "ASSIGN", "NUMBER", "COMPARISON", "ADD", "MINUS", "IF",
    "ANNOTATION", "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST",
    "CONTINUE", "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "GOTO", "RETURN",
    "REGISTER", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDE",
    "UNION ", "UNSIGN", "VOLATI", "WHILE", "COLON", "LITERAL", "LOGIC",
    "BOOLOP", "LSQUBRAC", "RSQUBRAC"
};
struct Symbol
{
	Symbol(int word, string element, int line, void* value = NULL) :word(word), element(element), value(value), line(line) 
	{
		if (value)
			value = new string(element);
	}
	int word;
	string element;
	void* value;
	int line;
};
vector<Symbol> symbols;
void reserve(int word, string element, int line = Line)
{
	// 如果符号表内已存该项
	for (int i = 0; i < symbols.size(); i++)
		if (symbols[i].element == element)
		{
			switch (word)
			{
				case ID: cout << Words[word] << "\t\t" << element << "\t\t" << symbols[i].value << "\t\t" << line << endl; return;
				case NUMBER: 
				case LITERAL: cout << Words[word] << "\t\t" << element << "\t\t" << *(string*)(symbols.back().value) << "\t\t" << line << endl; return;
				default:
					cout << Words[word] << "\t\t" << element << "\t\t\t\t" << line << endl; return;
			}
		}
	//如果符号表内未存该项
	switch (word)
	{
		case ID: symbols.push_back(Symbol(word, element, line)); symbols.back().value = &symbols.back().value;
			cout << Words[word] << "\t\t" << element << "\t\t" << symbols.back().value << "\t\t" << line << endl; return;
		case NUMBER: 
		case LITERAL: symbols.push_back(Symbol(word, element, line, &element));
			cout << Words[word] << "\t\t" << element << "\t\t" << *(string*)(symbols.back().value) << "\t\t" << line << endl; return;
		default:
			cout << Words[word] << "\t\t" << element << "\t\t\t\t" << line << endl; return;
	}
}
void comment(string val)
{
	for (int i = 0; i < val.length(); i++)
		if(val[i] == '\n')
			Line++;
	cout << val << endl;
}


#line 159 "mylexer.cpp"
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
#line 134 ".\\mylexer.l"

	// place any extra initialisation code here

#line 183 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 139 ".\\mylexer.l"

	// place any extra cleanup code here

#line 195 "mylexer.cpp"
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
#line 157 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 266 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 163 ".\\mylexer.l"

#line 273 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 164 ".\\mylexer.l"
comment(yytext);
#line 280 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 165 ".\\mylexer.l"
comment(yytext);
#line 287 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 166 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 294 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 167 ".\\mylexer.l"
Line++;
#line 301 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 168 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 308 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 169 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 315 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 170 ".\\mylexer.l"
reserve(COLON, yytext);
#line 322 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 171 ".\\mylexer.l"
reserve(LP, yytext); 
#line 329 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 172 ".\\mylexer.l"
reserve(RP, yytext); 
#line 336 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 173 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 343 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 174 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 350 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 175 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 357 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 176 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 364 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 177 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 371 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 178 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 378 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 179 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 385 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 180 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 392 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 181 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 399 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 182 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 406 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 183 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 413 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 184 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 420 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 185 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 427 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 186 ".\\mylexer.l"
reserve(DIVIDE, yytext);
#line 434 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 187 ".\\mylexer.l"
reserve(LOGIC, yytext);
#line 441 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 188 ".\\mylexer.l"
reserve(BOOLOP, yytext);
#line 448 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 189 ".\\mylexer.l"
reserve(IF, yytext); 
#line 455 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 190 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 462 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 191 ".\\mylexer.l"
reserve(THEN, yytext);
#line 469 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 192 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 476 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 193 ".\\mylexer.l"
reserve(CASE, yytext);
#line 483 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 194 ".\\mylexer.l"
reserve(CONST, yytext);
#line 490 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 195 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 497 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 196 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 504 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 197 ".\\mylexer.l"
reserve(DO, yytext);
#line 511 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 198 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 518 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 199 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 525 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 200 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 532 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 201 ".\\mylexer.l"
reserve(FOR, yytext);
#line 539 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 202 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 546 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 203 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 553 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 204 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 560 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 205 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 567 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 206 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 574 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 207 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 581 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 208 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 588 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 209 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 595 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 210 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 602 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 211 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 609 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 212 ".\\mylexer.l"
reserve(UNION, yytext);
#line 616 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 213 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 623 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 214 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 630 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 215 ".\\mylexer.l"
reserve(ID, yytext);
#line 637 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 216 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 644 "mylexer.cpp"
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

	yytransitionmax = 435;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 97, 68 },
		{ 4, 4 },
		{ 52, 25 },
		{ 71, 34 },
		{ 94, 66 },
		{ 104, 73 },
		{ 63, 30 },
		{ 46, 14 },
		{ 99, 69 },
		{ 53, 25 },
		{ 106, 74 },
		{ 82, 53 },
		{ 47, 14 },
		{ 107, 74 },
		{ 64, 30 },
		{ 105, 73 },
		{ 54, 25 },
		{ 95, 66 },
		{ 55, 26 },
		{ 98, 68 },
		{ 72, 34 },
		{ 4, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 4, 4 },
		{ 100, 69 },
		{ 83, 54 },
		{ 8, 1 },
		{ 56, 26 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 78, 50 },
		{ 13, 1 },
		{ 78, 50 },
		{ 14, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 18, 1 },
		{ 114, 83 },
		{ 115, 83 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 84, 55 },
		{ 22, 1 },
		{ 23, 1 },
		{ 20, 1 },
		{ 85, 56 },
		{ 20, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 20, 1 },
		{ 30, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 31, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 38, 1 },
		{ 39, 1 },
		{ 40, 1 },
		{ 23, 1 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 76, 76 },
		{ 60, 28 },
		{ 86, 57 },
		{ 87, 58 },
		{ 61, 28 },
		{ 109, 76 },
		{ 88, 59 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 89, 60 },
		{ 43, 42 },
		{ 90, 61 },
		{ 91, 62 },
		{ 20, 179 },
		{ 92, 64 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 20, 179 },
		{ 0, 79 },
		{ 93, 65 },
		{ 0, 79 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 67, 33 },
		{ 68, 33 },
		{ 51, 24 },
		{ 96, 67 },
		{ 45, 8 },
		{ 73, 35 },
		{ 101, 70 },
		{ 102, 71 },
		{ 103, 72 },
		{ 74, 36 },
		{ 75, 37 },
		{ 50, 77 },
		{ 69, 33 },
		{ 111, 79 },
		{ 44, 42 },
		{ 70, 33 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 111, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 108, 75 },
		{ 50, 77 },
		{ 45, 39 },
		{ 111, 79 },
		{ 49, 156 },
		{ 62, 29 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 111, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 156 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 49, 49 },
		{ 0, 44 },
		{ 76, 46 },
		{ 112, 80 },
		{ 113, 81 },
		{ 92, 82 },
		{ 0, 47 },
		{ 116, 84 },
		{ 137, 111 },
		{ 117, 85 },
		{ 137, 111 },
		{ 118, 86 },
		{ 49, 49 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 79, 111 },
		{ 57, 27 },
		{ 119, 87 },
		{ 58, 27 },
		{ 120, 88 },
		{ 64, 89 },
		{ 121, 91 },
		{ 122, 93 },
		{ 123, 94 },
		{ 124, 95 },
		{ 64, 96 },
		{ 125, 97 },
		{ 126, 98 },
		{ 59, 27 },
		{ 127, 99 },
		{ 128, 100 },
		{ 129, 101 },
		{ 130, 102 },
		{ 131, 103 },
		{ 132, 104 },
		{ 133, 105 },
		{ 48, 15 },
		{ 49, 49 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 110, 78 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 156, 137 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 77, 48 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 110, 110 },
		{ 134, 106 },
		{ 135, 107 },
		{ 136, 108 },
		{ 41, 19 },
		{ 65, 31 },
		{ 138, 112 },
		{ 139, 114 },
		{ 140, 115 },
		{ 141, 116 },
		{ 142, 117 },
		{ 143, 120 },
		{ 144, 123 },
		{ 145, 124 },
		{ 146, 125 },
		{ 147, 126 },
		{ 148, 127 },
		{ 149, 128 },
		{ 150, 129 },
		{ 151, 131 },
		{ 152, 132 },
		{ 153, 133 },
		{ 154, 135 },
		{ 155, 136 },
		{ 66, 32 },
		{ 157, 140 },
		{ 158, 141 },
		{ 92, 142 },
		{ 159, 143 },
		{ 160, 144 },
		{ 161, 145 },
		{ 162, 146 },
		{ 163, 147 },
		{ 164, 148 },
		{ 165, 149 },
		{ 166, 150 },
		{ 167, 151 },
		{ 168, 153 },
		{ 169, 154 },
		{ 80, 51 },
		{ 170, 157 },
		{ 171, 158 },
		{ 172, 160 },
		{ 173, 167 },
		{ 174, 168 },
		{ 175, 169 },
		{ 176, 170 },
		{ 177, 172 },
		{ 178, 174 },
		{ 179, 175 },
		{ 81, 52 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 54 },
		{ 0, -5, 1 },
		{ 0, 0, 5 },
		{ 19, 0, 26 },
		{ 42, 0, 54 },
		{ 0, 173, 25 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 0, 28 },
		{ 0, 0, 22 },
		{ 0, 0, 23 },
		{ 0, -32, 24 },
		{ 77, 287, 20 },
		{ 0, 0, 8 },
		{ 0, 0, 16 },
		{ 19, 0, 21 },
		{ 0, 327, 18 },
		{ 179, 0, 53 },
		{ 0, 0, 13 },
		{ 0, 0, 14 },
		{ 0, 0, 25 },
		{ 179, 95, 53 },
		{ 179, -92, 53 },
		{ 179, -80, 53 },
		{ 179, 205, 53 },
		{ 179, 22, 53 },
		{ 179, 143, 53 },
		{ 179, -93, 53 },
		{ 179, 292, 53 },
		{ 179, 307, 53 },
		{ 179, 103, 53 },
		{ 179, -98, 53 },
		{ 179, 102, 53 },
		{ 179, 105, 53 },
		{ 179, 113, 53 },
		{ 0, 0, 11 },
		{ 0, 127, 25 },
		{ 0, 0, 12 },
		{ 0, 0, 21 },
		{ -42, 129, 0 },
		{ 0, 0, 4 },
		{ -42, 281, 0 },
		{ 0, 0, 26 },
		{ -46, 250, 0 },
		{ -47, 286, 3 },
		{ 0, 317, 0 },
		{ 156, 233, 19 },
		{ 111, -7, 19 },
		{ 179, 322, 53 },
		{ 179, 319, 53 },
		{ 179, -83, 53 },
		{ 179, -81, 53 },
		{ 179, -18, 53 },
		{ 179, -29, 35 },
		{ 179, 16, 53 },
		{ 179, 15, 53 },
		{ 179, 19, 53 },
		{ 179, 51, 53 },
		{ 179, 50, 53 },
		{ 179, 49, 53 },
		{ 179, 0, 27 },
		{ 179, 51, 53 },
		{ 179, 90, 53 },
		{ 179, -96, 53 },
		{ 179, 99, 53 },
		{ 179, -100, 53 },
		{ 179, -86, 53 },
		{ 179, 108, 53 },
		{ 179, 113, 53 },
		{ 179, 103, 53 },
		{ 179, -97, 53 },
		{ 179, -92, 53 },
		{ 179, 144, 53 },
		{ -46, 87, 0 },
		{ 156, 149, 20 },
		{ 0, 297, 0 },
		{ 111, 151, 19 },
		{ 179, 196, 53 },
		{ 179, 193, 53 },
		{ 179, 181, 53 },
		{ 179, -60, 53 },
		{ 179, 200, 53 },
		{ 179, 201, 53 },
		{ 179, 200, 53 },
		{ 179, 205, 53 },
		{ 179, 215, 53 },
		{ 179, 220, 53 },
		{ 179, 0, 17 },
		{ 179, 207, 53 },
		{ 179, 0, 15 },
		{ 179, 209, 53 },
		{ 179, 215, 53 },
		{ 179, 204, 53 },
		{ 179, 208, 53 },
		{ 179, 213, 53 },
		{ 179, 223, 53 },
		{ 179, 210, 53 },
		{ 179, 210, 53 },
		{ 179, 212, 53 },
		{ 179, 219, 53 },
		{ 179, 229, 53 },
		{ 179, 220, 53 },
		{ 179, 227, 53 },
		{ 179, 285, 53 },
		{ 179, 289, 53 },
		{ 179, 279, 53 },
		{ 0, 0, 2 },
		{ 156, 327, 20 },
		{ 49, 255, 19 },
		{ 179, 283, 53 },
		{ 179, 0, 31 },
		{ 179, 275, 53 },
		{ 179, 287, 53 },
		{ 179, 276, 53 },
		{ 179, 286, 53 },
		{ 179, 0, 36 },
		{ 179, 0, 37 },
		{ 179, 281, 53 },
		{ 179, 0, 40 },
		{ 179, 0, 7 },
		{ 179, 281, 53 },
		{ 179, 283, 53 },
		{ 179, 297, 53 },
		{ 179, 288, 53 },
		{ 179, 295, 53 },
		{ 179, 302, 53 },
		{ 179, 303, 53 },
		{ 179, 0, 29 },
		{ 179, 303, 53 },
		{ 179, 294, 53 },
		{ 179, 302, 53 },
		{ 179, 0, 6 },
		{ 179, 290, 53 },
		{ 179, 306, 53 },
		{ 0, 307, 0 },
		{ 179, 0, 30 },
		{ 179, 0, 32 },
		{ 179, 299, 53 },
		{ 179, 302, 53 },
		{ 179, 310, 53 },
		{ 179, 302, 53 },
		{ 179, 297, 53 },
		{ 179, 304, 53 },
		{ 179, 315, 53 },
		{ 179, 314, 53 },
		{ 179, 318, 53 },
		{ 179, 302, 53 },
		{ 179, 315, 53 },
		{ 179, 319, 53 },
		{ 179, 0, 50 },
		{ 179, 311, 53 },
		{ 179, 317, 53 },
		{ 179, 0, 52 },
		{ 137, 158, 0 },
		{ 179, 307, 53 },
		{ 179, 309, 53 },
		{ 179, 0, 38 },
		{ 179, 325, 53 },
		{ 179, 0, 41 },
		{ 179, 0, 43 },
		{ 179, 0, 45 },
		{ 179, 0, 46 },
		{ 179, 0, 47 },
		{ 179, 0, 48 },
		{ 179, 325, 53 },
		{ 179, 327, 53 },
		{ 179, 321, 53 },
		{ 179, 329, 53 },
		{ 179, 0, 34 },
		{ 179, 317, 53 },
		{ 179, 0, 49 },
		{ 179, 332, 53 },
		{ 179, 332, 53 },
		{ 179, 0, 33 },
		{ 179, 0, 42 },
		{ 179, 0, 44 },
		{ 0, 71, 51 }
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
#line 217 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


