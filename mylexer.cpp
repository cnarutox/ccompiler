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
* Time: 12:08:44
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
	Symbol(int word, string element, int line, string value = "") :word(word), element(element), value(value), line(line) {}
	int word;
	string element;
	string value;
	int line;
};
vector<Symbol> symbols;
void reserve(int word, string element, int line = Line)
{
	// �Ѵ��ڷ��ű���
	for (int i = 0; i < symbols.size(); i++)
		if (symbols[i].element == element)
		{
			switch (word)
			{
				case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols[i] << "\t\t" << line << endl; return;
				case NUMBER: 
				case LITERAL: cout << Words[word] << "\t\t" << element << "\t\t" << element << "\t\t" << line << endl; return;
				default:
					cout << Words[word] << "\t\t" << element << "\t\t\t\t" << line << endl; return;
			}
		}
	//δ���ڷ��ű���
	symbols.push_back(Symbol(word, element, line));
	switch (word)
	{
		case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols.back() << "\t\t" << line << endl; return;
		case NUMBER: 
		case LITERAL: cout << Words[word] << "\t\t" << element << "\t\t" << element << "\t\t" << line << endl; return;
		default:
			cout << Words[word] << "\t\t" << element << "\t\t\t\t" << line << endl; return;
	}
}
void comment(string val)
{
	for (int i = 0; i < val.length(); i++)
		if(val[i] == '\n')
			Line++;
}


#line 153 "mylexer.cpp"
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
#line 128 ".\\mylexer.l"

	// place any extra initialisation code here

#line 177 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 133 ".\\mylexer.l"

	// place any extra cleanup code here

#line 189 "mylexer.cpp"
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
#line 151 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 260 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 157 ".\\mylexer.l"

#line 267 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 158 ".\\mylexer.l"
comment(yytext);
#line 274 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 159 ".\\mylexer.l"
printf("%s\n", yytext);
#line 281 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 160 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 288 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 161 ".\\mylexer.l"
Line++;
#line 295 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 162 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 302 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 163 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 309 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 164 ".\\mylexer.l"
reserve(COLON, yytext);
#line 316 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 165 ".\\mylexer.l"
reserve(LP, yytext); 
#line 323 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 166 ".\\mylexer.l"
reserve(RP, yytext); 
#line 330 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 167 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 337 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 168 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 344 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 169 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 351 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 170 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 358 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 171 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 365 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 172 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 372 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 173 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 379 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 174 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 386 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 175 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 393 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 176 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 400 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 177 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 407 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 178 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 414 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 179 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 421 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 180 ".\\mylexer.l"
reserve(DIVIDE, yytext);
#line 428 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 181 ".\\mylexer.l"
reserve(LOGIC, yytext);
#line 435 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 182 ".\\mylexer.l"
reserve(BOOLOP, yytext);
#line 442 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 183 ".\\mylexer.l"
reserve(IF, yytext); 
#line 449 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 184 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 456 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 185 ".\\mylexer.l"
reserve(THEN, yytext);
#line 463 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 186 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 470 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 187 ".\\mylexer.l"
reserve(CASE, yytext);
#line 477 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 188 ".\\mylexer.l"
reserve(CONST, yytext);
#line 484 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 189 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 491 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 190 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 498 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 191 ".\\mylexer.l"
reserve(DO, yytext);
#line 505 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 192 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 512 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 193 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 519 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 194 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 526 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 195 ".\\mylexer.l"
reserve(FOR, yytext);
#line 533 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 196 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 540 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 197 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 547 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 198 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 554 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 199 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 561 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 200 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 568 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 201 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 575 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 202 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 582 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 203 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 589 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 204 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 596 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 205 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 603 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 206 ".\\mylexer.l"
reserve(UNION, yytext);
#line 610 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 207 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 617 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 208 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 624 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 209 ".\\mylexer.l"
reserve(ID, yytext);
#line 631 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 210 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 638 "mylexer.cpp"
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

	yytransitionmax = 432;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 0, 79 },
		{ 4, 4 },
		{ 0, 79 },
		{ 71, 34 },
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
		{ 97, 68 },
		{ 94, 66 },
		{ 106, 74 },
		{ 82, 53 },
		{ 99, 69 },
		{ 107, 74 },
		{ 72, 34 },
		{ 4, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 4, 4 },
		{ 50, 77 },
		{ 111, 79 },
		{ 8, 1 },
		{ 95, 66 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 98, 68 },
		{ 13, 1 },
		{ 100, 69 },
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
		{ 83, 54 },
		{ 22, 1 },
		{ 23, 1 },
		{ 20, 1 },
		{ 84, 55 },
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
		{ 46, 14 },
		{ 76, 76 },
		{ 78, 50 },
		{ 85, 56 },
		{ 78, 50 },
		{ 47, 14 },
		{ 109, 76 },
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
		{ 43, 42 },
		{ 86, 57 },
		{ 60, 28 },
		{ 87, 58 },
		{ 20, 179 },
		{ 61, 28 },
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
		{ 44, 42 },
		{ 88, 59 },
		{ 89, 60 },
		{ 90, 61 },
		{ 49, 156 },
		{ 91, 62 },
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
		{ 67, 33 },
		{ 68, 33 },
		{ 52, 25 },
		{ 104, 73 },
		{ 55, 26 },
		{ 92, 64 },
		{ 57, 27 },
		{ 93, 65 },
		{ 58, 27 },
		{ 53, 25 },
		{ 51, 24 },
		{ 49, 49 },
		{ 69, 33 },
		{ 105, 73 },
		{ 56, 26 },
		{ 70, 33 },
		{ 54, 25 },
		{ 137, 111 },
		{ 59, 27 },
		{ 137, 111 },
		{ 96, 67 },
		{ 45, 8 },
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
		{ 48, 15 },
		{ 73, 35 },
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
		{ 63, 30 },
		{ 101, 70 },
		{ 102, 71 },
		{ 103, 72 },
		{ 74, 36 },
		{ 75, 37 },
		{ 108, 75 },
		{ 45, 39 },
		{ 64, 30 },
		{ 62, 29 },
		{ 0, 44 },
		{ 76, 46 },
		{ 112, 80 },
		{ 113, 81 },
		{ 92, 82 },
		{ 0, 47 },
		{ 116, 84 },
		{ 117, 85 },
		{ 118, 86 },
		{ 119, 87 },
		{ 120, 88 },
		{ 64, 89 },
		{ 121, 91 },
		{ 122, 93 },
		{ 123, 94 },
		{ 124, 95 },
		{ 64, 96 },
		{ 125, 97 },
		{ 126, 98 },
		{ 127, 99 },
		{ 128, 100 },
		{ 129, 101 },
		{ 130, 102 },
		{ 131, 103 },
		{ 132, 104 },
		{ 133, 105 },
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
		{ 0, 245, 25 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 0, 28 },
		{ 0, 0, 22 },
		{ 0, 0, 23 },
		{ 0, 87, 24 },
		{ 77, 248, 20 },
		{ 0, 0, 8 },
		{ 0, 0, 16 },
		{ 19, 0, 21 },
		{ 0, 324, 18 },
		{ 179, 0, 53 },
		{ 0, 0, 13 },
		{ 0, 0, 14 },
		{ 0, 0, 25 },
		{ 179, 158, 53 },
		{ 179, 167, 53 },
		{ 179, 165, 53 },
		{ 179, 160, 53 },
		{ 179, 56, 53 },
		{ 179, 244, 53 },
		{ 179, 244, 53 },
		{ 179, 289, 53 },
		{ 179, 304, 53 },
		{ 179, 158, 53 },
		{ 179, -98, 53 },
		{ 179, 185, 53 },
		{ 179, 239, 53 },
		{ 179, 247, 53 },
		{ 0, 0, 11 },
		{ 0, 229, 25 },
		{ 0, 0, 12 },
		{ 0, 0, 21 },
		{ -42, 128, 0 },
		{ 0, 0, 4 },
		{ -42, 346, 0 },
		{ 0, 0, 26 },
		{ -46, 315, 0 },
		{ -47, 351, 3 },
		{ 0, 278, 0 },
		{ 156, 204, 19 },
		{ 111, 88, 19 },
		{ 179, 319, 53 },
		{ 179, 316, 53 },
		{ 179, -77, 53 },
		{ 179, -26, 53 },
		{ 179, -14, 53 },
		{ 179, 15, 35 },
		{ 179, 48, 53 },
		{ 179, 48, 53 },
		{ 179, 105, 53 },
		{ 179, 111, 53 },
		{ 179, 109, 53 },
		{ 179, 109, 53 },
		{ 179, 0, 27 },
		{ 179, 151, 53 },
		{ 179, 164, 53 },
		{ 179, -85, 53 },
		{ 179, 171, 53 },
		{ 179, -86, 53 },
		{ 179, -76, 53 },
		{ 179, 242, 53 },
		{ 179, 247, 53 },
		{ 179, 237, 53 },
		{ 179, 160, 53 },
		{ 179, -86, 53 },
		{ 179, 247, 53 },
		{ -46, 88, 0 },
		{ 156, -41, 20 },
		{ 0, 258, 0 },
		{ 111, -40, 19 },
		{ 179, 261, 53 },
		{ 179, 258, 53 },
		{ 179, 246, 53 },
		{ 179, -60, 53 },
		{ 179, 265, 53 },
		{ 179, 265, 53 },
		{ 179, 263, 53 },
		{ 179, 256, 53 },
		{ 179, 265, 53 },
		{ 179, 270, 53 },
		{ 179, 0, 17 },
		{ 179, 257, 53 },
		{ 179, 0, 15 },
		{ 179, 259, 53 },
		{ 179, 265, 53 },
		{ 179, 254, 53 },
		{ 179, 258, 53 },
		{ 179, 263, 53 },
		{ 179, 273, 53 },
		{ 179, 259, 53 },
		{ 179, 259, 53 },
		{ 179, 261, 53 },
		{ 179, 268, 53 },
		{ 179, 278, 53 },
		{ 179, 269, 53 },
		{ 179, 276, 53 },
		{ 179, 282, 53 },
		{ 179, 286, 53 },
		{ 179, 276, 53 },
		{ 0, 0, 2 },
		{ 156, 288, 20 },
		{ 49, 236, 19 },
		{ 179, 280, 53 },
		{ 179, 0, 31 },
		{ 179, 272, 53 },
		{ 179, 284, 53 },
		{ 179, 273, 53 },
		{ 179, 283, 53 },
		{ 179, 0, 36 },
		{ 179, 0, 37 },
		{ 179, 278, 53 },
		{ 179, 0, 40 },
		{ 179, 0, 7 },
		{ 179, 278, 53 },
		{ 179, 280, 53 },
		{ 179, 294, 53 },
		{ 179, 285, 53 },
		{ 179, 292, 53 },
		{ 179, 299, 53 },
		{ 179, 300, 53 },
		{ 179, 0, 29 },
		{ 179, 300, 53 },
		{ 179, 291, 53 },
		{ 179, 299, 53 },
		{ 179, 0, 6 },
		{ 179, 287, 53 },
		{ 179, 303, 53 },
		{ 0, 268, 0 },
		{ 179, 0, 30 },
		{ 179, 0, 32 },
		{ 179, 296, 53 },
		{ 179, 299, 53 },
		{ 179, 307, 53 },
		{ 179, 299, 53 },
		{ 179, 294, 53 },
		{ 179, 301, 53 },
		{ 179, 312, 53 },
		{ 179, 311, 53 },
		{ 179, 315, 53 },
		{ 179, 299, 53 },
		{ 179, 312, 53 },
		{ 179, 316, 53 },
		{ 179, 0, 50 },
		{ 179, 308, 53 },
		{ 179, 314, 53 },
		{ 179, 0, 52 },
		{ 137, 129, 0 },
		{ 179, 304, 53 },
		{ 179, 306, 53 },
		{ 179, 0, 38 },
		{ 179, 322, 53 },
		{ 179, 0, 41 },
		{ 179, 0, 43 },
		{ 179, 0, 45 },
		{ 179, 0, 46 },
		{ 179, 0, 47 },
		{ 179, 0, 48 },
		{ 179, 322, 53 },
		{ 179, 324, 53 },
		{ 179, 318, 53 },
		{ 179, 326, 53 },
		{ 179, 0, 34 },
		{ 179, 314, 53 },
		{ 179, 0, 49 },
		{ 179, 329, 53 },
		{ 179, 329, 53 },
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
#line 211 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


