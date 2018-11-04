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
* Time: 11:22:31
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
int Line = 1;
string Words[] = {
    "ERROR", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID",
    "SEMICOL", "FOR", "ASSIGN", "NUMBER", "COMPARISON", "ADD", "MINUS", "IF", "ANNOTATION",
    "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST", "CONTINUE",
    "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "GOTO", "RETURN", "REGISTER",
    "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDE", "UNION ",
    "UNSIGN", "VOLATI", "WHILE", "COLON", "LITERAL", "LOGIC", "BOOLOP"
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


#line 150 "mylexer.cpp"
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
#line 125 ".\\mylexer.l"

	// place any extra initialisation code here

#line 174 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 130 ".\\mylexer.l"

	// place any extra cleanup code here

#line 186 "mylexer.cpp"
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
#line 148 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 257 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 154 ".\\mylexer.l"

#line 264 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 155 ".\\mylexer.l"
comment(yytext);
#line 271 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 156 ".\\mylexer.l"
printf("%s\n", yytext);
#line 278 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 157 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 285 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 158 ".\\mylexer.l"
Line++;
#line 292 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 159 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 299 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 160 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 306 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 161 ".\\mylexer.l"
reserve(COLON, yytext);
#line 313 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 162 ".\\mylexer.l"
reserve(LP, yytext); 
#line 320 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 163 ".\\mylexer.l"
reserve(RP, yytext); 
#line 327 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 164 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 334 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 165 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 341 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 166 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 348 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 167 ".\\mylexer.l"
reserve(SEMICOL, yytext); 
#line 355 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 168 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 362 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 169 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 369 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 170 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 376 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 171 ".\\mylexer.l"
reserve(NUMBER, yytext); 
#line 383 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 172 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 390 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 173 ".\\mylexer.l"
reserve(ADD, yytext); 
#line 397 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 174 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 404 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 175 ".\\mylexer.l"
reserve(DIVIDE, yytext);
#line 411 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 176 ".\\mylexer.l"
reserve(LOGIC, yytext);
#line 418 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 177 ".\\mylexer.l"
reserve(BOOLOP, yytext);
#line 425 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 178 ".\\mylexer.l"
reserve(IF, yytext); 
#line 432 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 179 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 439 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 180 ".\\mylexer.l"
reserve(THEN, yytext);
#line 446 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 181 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 453 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 182 ".\\mylexer.l"
reserve(CASE, yytext);
#line 460 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 183 ".\\mylexer.l"
reserve(CONST, yytext);
#line 467 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 184 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 474 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 185 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 481 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 186 ".\\mylexer.l"
reserve(DO, yytext);
#line 488 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 187 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 495 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 188 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 502 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 189 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 509 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 190 ".\\mylexer.l"
reserve(FOR, yytext);
#line 516 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 191 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 523 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 192 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 530 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 193 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 537 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 194 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 544 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 195 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 551 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 196 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 558 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 197 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 565 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 198 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 572 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 199 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 579 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 200 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 586 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 201 ".\\mylexer.l"
reserve(UNION, yytext);
#line 593 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 202 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 600 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 203 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 607 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 204 ".\\mylexer.l"
reserve(ID, yytext);
#line 614 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 205 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 621 "mylexer.cpp"
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

	yytransitionmax = 430;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 0, 77 },
		{ 95, 66 },
		{ 0, 77 },
		{ 65, 31 },
		{ 66, 31 },
		{ 4, 4 },
		{ 92, 64 },
		{ 102, 71 },
		{ 69, 32 },
		{ 44, 14 },
		{ 104, 72 },
		{ 112, 81 },
		{ 113, 81 },
		{ 105, 72 },
		{ 45, 14 },
		{ 67, 31 },
		{ 97, 67 },
		{ 103, 71 },
		{ 68, 31 },
		{ 93, 64 },
		{ 96, 66 },
		{ 4, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 41, 40 },
		{ 70, 32 },
		{ 109, 77 },
		{ 8, 1 },
		{ 4, 4 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 98, 67 },
		{ 13, 1 },
		{ 80, 51 },
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
		{ 81, 52 },
		{ 82, 53 },
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
		{ 74, 74 },
		{ 83, 54 },
		{ 42, 40 },
		{ 21, 1 },
		{ 20, 1 },
		{ 107, 74 },
		{ 20, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 20, 1 },
		{ 28, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 29, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 21, 1 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 58, 26 },
		{ 84, 55 },
		{ 76, 48 },
		{ 59, 26 },
		{ 76, 48 },
		{ 85, 56 },
		{ 86, 57 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 87, 58 },
		{ 88, 59 },
		{ 89, 60 },
		{ 90, 62 },
		{ 20, 177 },
		{ 91, 63 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 20, 177 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 109, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 49, 22 },
		{ 94, 65 },
		{ 43, 8 },
		{ 71, 33 },
		{ 47, 154 },
		{ 99, 68 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 47, 154 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 75, 75 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 47, 47 },
		{ 50, 23 },
		{ 48, 75 },
		{ 100, 69 },
		{ 53, 24 },
		{ 101, 70 },
		{ 72, 34 },
		{ 73, 35 },
		{ 51, 23 },
		{ 106, 73 },
		{ 43, 37 },
		{ 135, 109 },
		{ 47, 47 },
		{ 135, 109 },
		{ 54, 24 },
		{ 52, 23 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 77, 109 },
		{ 55, 25 },
		{ 61, 28 },
		{ 56, 25 },
		{ 60, 27 },
		{ 0, 42 },
		{ 74, 44 },
		{ 110, 78 },
		{ 111, 79 },
		{ 90, 80 },
		{ 62, 28 },
		{ 0, 45 },
		{ 46, 15 },
		{ 57, 25 },
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
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 108, 76 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 154, 135 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 75, 46 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 108, 108 },
		{ 114, 82 },
		{ 115, 83 },
		{ 116, 84 },
		{ 117, 85 },
		{ 118, 86 },
		{ 62, 87 },
		{ 119, 89 },
		{ 120, 91 },
		{ 121, 92 },
		{ 122, 93 },
		{ 62, 94 },
		{ 123, 95 },
		{ 124, 96 },
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
		{ 39, 19 },
		{ 63, 29 },
		{ 136, 110 },
		{ 137, 112 },
		{ 138, 113 },
		{ 139, 114 },
		{ 140, 115 },
		{ 141, 118 },
		{ 142, 121 },
		{ 143, 122 },
		{ 144, 123 },
		{ 145, 124 },
		{ 146, 125 },
		{ 147, 126 },
		{ 148, 127 },
		{ 149, 129 },
		{ 150, 130 },
		{ 151, 131 },
		{ 152, 133 },
		{ 153, 134 },
		{ 64, 30 },
		{ 155, 138 },
		{ 156, 139 },
		{ 90, 140 },
		{ 157, 141 },
		{ 158, 142 },
		{ 159, 143 },
		{ 160, 144 },
		{ 161, 145 },
		{ 162, 146 },
		{ 163, 147 },
		{ 164, 148 },
		{ 165, 149 },
		{ 166, 151 },
		{ 167, 152 },
		{ 78, 49 },
		{ 168, 155 },
		{ 169, 156 },
		{ 170, 158 },
		{ 171, 165 },
		{ 172, 166 },
		{ 173, 167 },
		{ 174, 168 },
		{ 175, 170 },
		{ 176, 172 },
		{ 177, 173 },
		{ 79, 50 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 52 },
		{ 0, -1, 1 },
		{ 0, 0, 5 },
		{ 19, 0, 24 },
		{ 40, 0, 52 },
		{ 0, 184, 23 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 0, 26 },
		{ 0, 0, 20 },
		{ 0, 0, 21 },
		{ 0, -30, 22 },
		{ 75, 262, 18 },
		{ 0, 0, 8 },
		{ 0, 0, 14 },
		{ 19, 0, 19 },
		{ 0, 322, 16 },
		{ 177, 0, 51 },
		{ 0, 0, 23 },
		{ 177, 106, 51 },
		{ 177, 175, 51 },
		{ 177, 174, 51 },
		{ 177, 189, 51 },
		{ 177, 21, 51 },
		{ 177, 189, 51 },
		{ 177, 196, 51 },
		{ 177, 287, 51 },
		{ 177, 302, 51 },
		{ 177, -98, 51 },
		{ 177, -93, 51 },
		{ 177, 113, 51 },
		{ 177, 166, 51 },
		{ 177, 174, 51 },
		{ 0, 0, 11 },
		{ 0, 157, 23 },
		{ 0, 0, 12 },
		{ 0, 0, 19 },
		{ -40, -7, 0 },
		{ 0, 0, 4 },
		{ -40, 291, 0 },
		{ 0, 0, 24 },
		{ -44, 260, 0 },
		{ -45, 297, 3 },
		{ 0, 292, 0 },
		{ 154, 214, 17 },
		{ 109, 88, 17 },
		{ 177, 317, 51 },
		{ 177, 314, 51 },
		{ 177, -59, 51 },
		{ 177, -55, 51 },
		{ 177, -46, 51 },
		{ 177, -33, 33 },
		{ 177, 15, 51 },
		{ 177, 17, 51 },
		{ 177, 19, 51 },
		{ 177, 51, 51 },
		{ 177, 49, 51 },
		{ 177, 48, 51 },
		{ 177, 0, 25 },
		{ 177, 49, 51 },
		{ 177, 62, 51 },
		{ 177, -94, 51 },
		{ 177, 110, 51 },
		{ 177, -99, 51 },
		{ 177, -78, 51 },
		{ 177, 120, 51 },
		{ 177, 173, 51 },
		{ 177, 164, 51 },
		{ 177, -95, 51 },
		{ 177, -92, 51 },
		{ 177, 175, 51 },
		{ -44, 41, 0 },
		{ 154, 204, 18 },
		{ 0, 272, 0 },
		{ 109, -40, 17 },
		{ 177, 206, 51 },
		{ 177, 203, 51 },
		{ 177, 191, 51 },
		{ 177, -101, 51 },
		{ 177, 263, 51 },
		{ 177, 263, 51 },
		{ 177, 261, 51 },
		{ 177, 254, 51 },
		{ 177, 263, 51 },
		{ 177, 268, 51 },
		{ 177, 0, 15 },
		{ 177, 255, 51 },
		{ 177, 0, 13 },
		{ 177, 257, 51 },
		{ 177, 263, 51 },
		{ 177, 252, 51 },
		{ 177, 256, 51 },
		{ 177, 261, 51 },
		{ 177, 271, 51 },
		{ 177, 257, 51 },
		{ 177, 257, 51 },
		{ 177, 259, 51 },
		{ 177, 266, 51 },
		{ 177, 276, 51 },
		{ 177, 267, 51 },
		{ 177, 274, 51 },
		{ 177, 280, 51 },
		{ 177, 284, 51 },
		{ 177, 274, 51 },
		{ 0, 0, 2 },
		{ 154, 302, 18 },
		{ 47, 239, 17 },
		{ 177, 278, 51 },
		{ 177, 0, 29 },
		{ 177, 270, 51 },
		{ 177, 282, 51 },
		{ 177, 271, 51 },
		{ 177, 281, 51 },
		{ 177, 0, 34 },
		{ 177, 0, 35 },
		{ 177, 276, 51 },
		{ 177, 0, 38 },
		{ 177, 0, 7 },
		{ 177, 276, 51 },
		{ 177, 278, 51 },
		{ 177, 292, 51 },
		{ 177, 283, 51 },
		{ 177, 290, 51 },
		{ 177, 297, 51 },
		{ 177, 298, 51 },
		{ 177, 0, 27 },
		{ 177, 298, 51 },
		{ 177, 289, 51 },
		{ 177, 297, 51 },
		{ 177, 0, 6 },
		{ 177, 285, 51 },
		{ 177, 301, 51 },
		{ 0, 282, 0 },
		{ 177, 0, 28 },
		{ 177, 0, 30 },
		{ 177, 294, 51 },
		{ 177, 297, 51 },
		{ 177, 305, 51 },
		{ 177, 297, 51 },
		{ 177, 292, 51 },
		{ 177, 299, 51 },
		{ 177, 310, 51 },
		{ 177, 309, 51 },
		{ 177, 313, 51 },
		{ 177, 297, 51 },
		{ 177, 310, 51 },
		{ 177, 314, 51 },
		{ 177, 0, 48 },
		{ 177, 306, 51 },
		{ 177, 312, 51 },
		{ 177, 0, 50 },
		{ 135, 129, 0 },
		{ 177, 302, 51 },
		{ 177, 304, 51 },
		{ 177, 0, 36 },
		{ 177, 320, 51 },
		{ 177, 0, 39 },
		{ 177, 0, 41 },
		{ 177, 0, 43 },
		{ 177, 0, 44 },
		{ 177, 0, 45 },
		{ 177, 0, 46 },
		{ 177, 320, 51 },
		{ 177, 322, 51 },
		{ 177, 316, 51 },
		{ 177, 324, 51 },
		{ 177, 0, 32 },
		{ 177, 312, 51 },
		{ 177, 0, 47 },
		{ 177, 327, 51 },
		{ 177, 327, 51 },
		{ 177, 0, 31 },
		{ 177, 0, 40 },
		{ 177, 0, 42 },
		{ 0, 71, 49 }
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
		0
	};
	yybackup = backup;
}
#line 206 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


