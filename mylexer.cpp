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
* Time: 10:55:54
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
int Line = 1;
string Words[] = {
    "ERROR", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID",
    "SEMICOL", "FOR", "ASSIGN", "NUMBER", "COMPARISON", "ADD", "MINUS", "IF", "ANNOTATION",
    "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST", "CONTINUE",
    "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "GOTO", "RETURN", "REGISTER",
    "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDE", "UNION ",
    "UNSIGN", "VOLATI", "WHILE", "COLON", "LITERAL"
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
comment(yytext);
#line 269 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 154 ".\\mylexer.l"
printf("%s\n", yytext);
#line 276 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 155 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 283 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 156 ".\\mylexer.l"
Line++;
#line 290 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 157 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 297 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 158 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 304 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 159 ".\\mylexer.l"
reserve(COLON, yytext);
#line 311 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 160 ".\\mylexer.l"
reserve(LP, yytext); 
#line 318 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 161 ".\\mylexer.l"
reserve(RP, yytext); 
#line 325 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 162 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 332 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 163 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 339 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 164 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 346 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 165 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 353 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 166 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 360 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 167 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 367 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 168 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 374 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 169 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 381 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 170 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 388 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 171 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 395 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 172 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 402 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 173 ".\\mylexer.l"
reserve(DIVIDE, yytext);
#line 409 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 174 ".\\mylexer.l"
reserve(IF, yytext); 
#line 416 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 175 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 423 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 176 ".\\mylexer.l"
reserve(THEN, yytext);
#line 430 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 177 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 437 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 178 ".\\mylexer.l"
reserve(CASE, yytext);
#line 444 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 179 ".\\mylexer.l"
reserve(CONST, yytext);
#line 451 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 180 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 458 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 181 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 465 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 182 ".\\mylexer.l"
reserve(DO, yytext);
#line 472 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 183 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 479 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 184 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 486 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 185 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 493 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 186 ".\\mylexer.l"
reserve(FOR, yytext);
#line 500 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 187 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 507 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 188 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 514 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 189 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 521 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 190 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 528 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 191 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 535 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 192 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 542 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 193 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 549 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 194 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 556 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 195 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 563 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 196 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 570 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 197 ".\\mylexer.l"
reserve(UNION, yytext);
#line 577 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 198 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 584 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 199 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 591 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 200 ".\\mylexer.l"
reserve(ID, yytext);
#line 598 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 201 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 605 "mylexer.cpp"
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
		{ 5, 1 },
		{ 0, 73 },
		{ 91, 62 },
		{ 0, 73 },
		{ 72, 44 },
		{ 4, 4 },
		{ 72, 44 },
		{ 88, 60 },
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
		{ 57, 26 },
		{ 65, 30 },
		{ 89, 60 },
		{ 92, 62 },
		{ 4, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 38, 37 },
		{ 58, 26 },
		{ 105, 73 },
		{ 4, 4 },
		{ 44, 71 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 78, 49 },
		{ 12, 1 },
		{ 66, 30 },
		{ 13, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 17, 1 },
		{ 108, 77 },
		{ 109, 77 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 40, 13 },
		{ 79, 50 },
		{ 39, 37 },
		{ 80, 51 },
		{ 19, 1 },
		{ 41, 13 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 19, 1 },
		{ 26, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 27, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 34, 1 },
		{ 93, 63 },
		{ 35, 1 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 100, 68 },
		{ 70, 70 },
		{ 81, 52 },
		{ 101, 68 },
		{ 82, 53 },
		{ 94, 63 },
		{ 103, 70 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 54, 24 },
		{ 83, 54 },
		{ 84, 55 },
		{ 55, 24 },
		{ 19, 173 },
		{ 85, 56 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 19, 173 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 105, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 86, 58 },
		{ 87, 59 },
		{ 56, 25 },
		{ 90, 61 },
		{ 43, 150 },
		{ 67, 31 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 150 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 61, 29 },
		{ 62, 29 },
		{ 46, 21 },
		{ 98, 67 },
		{ 49, 22 },
		{ 68, 32 },
		{ 51, 23 },
		{ 95, 64 },
		{ 52, 23 },
		{ 47, 21 },
		{ 96, 65 },
		{ 43, 43 },
		{ 63, 29 },
		{ 99, 67 },
		{ 50, 22 },
		{ 64, 29 },
		{ 48, 21 },
		{ 131, 105 },
		{ 53, 23 },
		{ 131, 105 },
		{ 97, 66 },
		{ 69, 33 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 73, 105 },
		{ 42, 14 },
		{ 36, 18 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 14, 14 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 104, 72 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 150, 131 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 71, 42 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 104, 104 },
		{ 102, 69 },
		{ 0, 39 },
		{ 70, 40 },
		{ 0, 41 },
		{ 59, 27 },
		{ 106, 74 },
		{ 107, 75 },
		{ 86, 76 },
		{ 60, 28 },
		{ 110, 78 },
		{ 111, 79 },
		{ 112, 80 },
		{ 113, 81 },
		{ 114, 82 },
		{ 58, 83 },
		{ 115, 85 },
		{ 116, 87 },
		{ 117, 88 },
		{ 118, 89 },
		{ 58, 90 },
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
		{ 130, 102 },
		{ 45, 20 },
		{ 74, 45 },
		{ 132, 106 },
		{ 133, 108 },
		{ 134, 109 },
		{ 135, 110 },
		{ 136, 111 },
		{ 137, 114 },
		{ 138, 117 },
		{ 139, 118 },
		{ 140, 119 },
		{ 141, 120 },
		{ 142, 121 },
		{ 143, 122 },
		{ 144, 123 },
		{ 145, 125 },
		{ 146, 126 },
		{ 147, 127 },
		{ 148, 129 },
		{ 149, 130 },
		{ 75, 46 },
		{ 151, 134 },
		{ 152, 135 },
		{ 86, 136 },
		{ 153, 137 },
		{ 154, 138 },
		{ 155, 139 },
		{ 156, 140 },
		{ 157, 141 },
		{ 158, 142 },
		{ 159, 143 },
		{ 160, 144 },
		{ 161, 145 },
		{ 162, 147 },
		{ 163, 148 },
		{ 76, 47 },
		{ 164, 151 },
		{ 165, 152 },
		{ 166, 154 },
		{ 167, 161 },
		{ 168, 162 },
		{ 169, 163 },
		{ 170, 164 },
		{ 171, 166 },
		{ 172, 168 },
		{ 173, 169 },
		{ 77, 48 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 50 },
		{ 0, -2, 1 },
		{ 0, 0, 5 },
		{ 18, 0, 50 },
		{ 37, 0, 50 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 0, 24 },
		{ 0, 0, 20 },
		{ 0, 0, 21 },
		{ 0, 41, 22 },
		{ 71, 247, 18 },
		{ 0, 0, 8 },
		{ 0, 0, 14 },
		{ 18, 0, 19 },
		{ 0, 233, 16 },
		{ 173, 0, 49 },
		{ 173, 263, 49 },
		{ 173, 166, 49 },
		{ 173, 164, 49 },
		{ 173, 159, 49 },
		{ 173, 53, 49 },
		{ 173, 110, 49 },
		{ 173, -82, 49 },
		{ 173, 252, 49 },
		{ 173, 252, 49 },
		{ 173, 157, 49 },
		{ 173, -83, 49 },
		{ 173, 114, 49 },
		{ 173, 155, 49 },
		{ 173, 178, 49 },
		{ 0, 0, 11 },
		{ 0, 0, 12 },
		{ 0, 0, 19 },
		{ -37, -7, 0 },
		{ 0, 0, 4 },
		{ -37, 336, 0 },
		{ -40, 305, 0 },
		{ -41, 338, 3 },
		{ 0, 277, 0 },
		{ 150, 203, 17 },
		{ 105, -37, 17 },
		{ 173, 277, 49 },
		{ 173, 282, 49 },
		{ 173, 315, 49 },
		{ 173, 313, 49 },
		{ 173, -66, 49 },
		{ 173, -33, 31 },
		{ 173, -29, 49 },
		{ 173, 13, 49 },
		{ 173, 16, 49 },
		{ 173, 51, 49 },
		{ 173, 49, 49 },
		{ 173, 50, 49 },
		{ 173, 0, 23 },
		{ 173, 103, 49 },
		{ 173, 115, 49 },
		{ 173, -94, 49 },
		{ 173, 111, 49 },
		{ 173, -99, 49 },
		{ 173, 19, 49 },
		{ 173, 163, 49 },
		{ 173, 170, 49 },
		{ 173, 169, 49 },
		{ 173, 159, 49 },
		{ 173, 23, 49 },
		{ 173, 240, 49 },
		{ -40, 87, 0 },
		{ 150, -38, 18 },
		{ 0, 257, 0 },
		{ 105, -40, 17 },
		{ 173, 253, 49 },
		{ 173, 250, 49 },
		{ 173, 238, 49 },
		{ 173, -60, 49 },
		{ 173, 257, 49 },
		{ 173, 257, 49 },
		{ 173, 255, 49 },
		{ 173, 248, 49 },
		{ 173, 257, 49 },
		{ 173, 262, 49 },
		{ 173, 0, 15 },
		{ 173, 249, 49 },
		{ 173, 0, 13 },
		{ 173, 251, 49 },
		{ 173, 257, 49 },
		{ 173, 246, 49 },
		{ 173, 250, 49 },
		{ 173, 255, 49 },
		{ 173, 265, 49 },
		{ 173, 251, 49 },
		{ 173, 251, 49 },
		{ 173, 253, 49 },
		{ 173, 260, 49 },
		{ 173, 270, 49 },
		{ 173, 261, 49 },
		{ 173, 268, 49 },
		{ 173, 274, 49 },
		{ 173, 278, 49 },
		{ 173, 268, 49 },
		{ 0, 0, 2 },
		{ 150, 287, 18 },
		{ 43, 235, 17 },
		{ 173, 272, 49 },
		{ 173, 0, 27 },
		{ 173, 264, 49 },
		{ 173, 276, 49 },
		{ 173, 265, 49 },
		{ 173, 275, 49 },
		{ 173, 0, 32 },
		{ 173, 0, 33 },
		{ 173, 270, 49 },
		{ 173, 0, 36 },
		{ 173, 0, 7 },
		{ 173, 270, 49 },
		{ 173, 272, 49 },
		{ 173, 286, 49 },
		{ 173, 277, 49 },
		{ 173, 284, 49 },
		{ 173, 291, 49 },
		{ 173, 292, 49 },
		{ 173, 0, 25 },
		{ 173, 292, 49 },
		{ 173, 283, 49 },
		{ 173, 291, 49 },
		{ 173, 0, 6 },
		{ 173, 279, 49 },
		{ 173, 295, 49 },
		{ 0, 267, 0 },
		{ 173, 0, 26 },
		{ 173, 0, 28 },
		{ 173, 288, 49 },
		{ 173, 291, 49 },
		{ 173, 299, 49 },
		{ 173, 291, 49 },
		{ 173, 286, 49 },
		{ 173, 293, 49 },
		{ 173, 304, 49 },
		{ 173, 303, 49 },
		{ 173, 307, 49 },
		{ 173, 291, 49 },
		{ 173, 304, 49 },
		{ 173, 308, 49 },
		{ 173, 0, 46 },
		{ 173, 300, 49 },
		{ 173, 306, 49 },
		{ 173, 0, 48 },
		{ 131, 128, 0 },
		{ 173, 296, 49 },
		{ 173, 298, 49 },
		{ 173, 0, 34 },
		{ 173, 314, 49 },
		{ 173, 0, 37 },
		{ 173, 0, 39 },
		{ 173, 0, 41 },
		{ 173, 0, 42 },
		{ 173, 0, 43 },
		{ 173, 0, 44 },
		{ 173, 314, 49 },
		{ 173, 316, 49 },
		{ 173, 310, 49 },
		{ 173, 318, 49 },
		{ 173, 0, 30 },
		{ 173, 306, 49 },
		{ 173, 0, 45 },
		{ 173, 321, 49 },
		{ 173, 321, 49 },
		{ 173, 0, 29 },
		{ 173, 0, 38 },
		{ 173, 0, 40 },
		{ 0, 70, 47 }
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
		0
	};
	yybackup = backup;
}
#line 202 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


