/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 43 of your 30 day trial period.
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
* Date: 11/21/18
* Time: 21:05:54
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
#include "define.h"
extern struct node {
	string name;
	int value;
	node** children;
	node(int v = 0)
	{
		value = v;
	}
	};

#line 59 "mylexer.cpp"
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
#line 34 ".\\mylexer.l"

	// place any extra initialisation code here

#line 83 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 39 ".\\mylexer.l"

	// place any extra cleanup code here

#line 95 "mylexer.cpp"
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
#line 57 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 166 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 63 ".\\mylexer.l"

#line 173 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 64 ".\\mylexer.l"
comment(yytext);
#line 180 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 65 ".\\mylexer.l"
comment(yytext);
#line 187 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 66 ".\\mylexer.l"
reserve(LITERAL, yytext);
#line 194 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 67 ".\\mylexer.l"
Line++;
#line 201 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 68 ".\\mylexer.l"
reserve(VOID, yytext); 
#line 208 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 69 ".\\mylexer.l"
reserve(MAIN, yytext); 
#line 215 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 70 ".\\mylexer.l"
reserve(COLON, yytext);
#line 222 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 71 ".\\mylexer.l"
reserve(LP, yytext); 
#line 229 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 72 ".\\mylexer.l"
reserve(RP, yytext); 
#line 236 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 73 ".\\mylexer.l"
reserve(LBRACE, yytext); 
#line 243 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 74 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 250 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 75 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 257 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 76 ".\\mylexer.l"
reserve(RBRACE, yytext); 
#line 264 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 77 ".\\mylexer.l"
reserve(TYPE, yytext); 
#line 271 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 78 ".\\mylexer.l"
reserve(SEMICOL, yytext);yylval.ntnode = new node(yytext[0]); return yytext[0];
#line 278 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 79 ".\\mylexer.l"
reserve(FOR, yytext); 
#line 285 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 80 ".\\mylexer.l"
reserve(ASSIGN, yytext); 
#line 292 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 81 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 299 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 82 ".\\mylexer.l"
reserve(NUMBER, yytext); yylval.ntnode = new node(atoi(yytext)); return NUMBER; 
#line 306 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 83 ".\\mylexer.l"
reserve(COMPARISON, yytext);
#line 313 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 84 ".\\mylexer.l"
reserve(ADD, yytext); yylval.ntnode = new node(yytext[0]); return yytext[0];
#line 320 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 85 ".\\mylexer.l"
reserve(MINUS, yytext); 
#line 327 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 86 ".\\mylexer.l"
reserve(DIVIDE, yytext);
#line 334 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 87 ".\\mylexer.l"
reserve(LOGIC, yytext);
#line 341 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 88 ".\\mylexer.l"
reserve(BOOLOP, yytext);
#line 348 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 89 ".\\mylexer.l"
reserve(IF, yytext); 
#line 355 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 90 ".\\mylexer.l"
reserve(MUTIPLY, yytext); 
#line 362 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 91 ".\\mylexer.l"
reserve(THEN, yytext);
#line 369 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 92 ".\\mylexer.l"
reserve(BREAK, yytext);
#line 376 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 93 ".\\mylexer.l"
reserve(CASE, yytext);
#line 383 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 94 ".\\mylexer.l"
reserve(CONST, yytext);
#line 390 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 95 ".\\mylexer.l"
reserve(CONTINUE, yytext);
#line 397 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 96 ".\\mylexer.l"
reserve(DEFAULT, yytext);
#line 404 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 97 ".\\mylexer.l"
reserve(DO, yytext);
#line 411 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 98 ".\\mylexer.l"
reserve(ELSE, yytext);
#line 418 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 99 ".\\mylexer.l"
reserve(ENUM, yytext);
#line 425 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 100 ".\\mylexer.l"
reserve(EXTERN, yytext);
#line 432 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 101 ".\\mylexer.l"
reserve(GOTO, yytext);
#line 439 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 102 ".\\mylexer.l"
reserve(RETURN, yytext);
#line 446 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 103 ".\\mylexer.l"
reserve(REGISTER, yytext);
#line 453 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 104 ".\\mylexer.l"
reserve(SIGNED, yytext);
#line 460 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 105 ".\\mylexer.l"
reserve(UNSIGNED, yytext);
#line 467 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 106 ".\\mylexer.l"
reserve(SIZEOF, yytext);
#line 474 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 107 ".\\mylexer.l"
reserve(STATIC, yytext);
#line 481 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 108 ".\\mylexer.l"
reserve(STRUCT, yytext);
#line 488 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 109 ".\\mylexer.l"
reserve(SWITCH, yytext);
#line 495 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 110 ".\\mylexer.l"
reserve(TYPEDEF, yytext);
#line 502 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 111 ".\\mylexer.l"
reserve(UNION, yytext);
#line 509 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 112 ".\\mylexer.l"
reserve(VOLATILE, yytext);
#line 516 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 113 ".\\mylexer.l"
reserve(WHILE, yytext);
#line 523 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 114 ".\\mylexer.l"
reserve(ID, yytext);
#line 530 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 115 ".\\mylexer.l"
reserve(ERROR, yytext);
#line 537 "mylexer.cpp"
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
		{ 0, 0, 53 },
		{ 0, -5, 1 },
		{ 0, 0, 5 },
		{ 19, 0, 26 },
		{ 42, 0, 53 },
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
		{ 179, 0, 52 },
		{ 0, 0, 13 },
		{ 0, 0, 14 },
		{ 0, 0, 25 },
		{ 179, 95, 52 },
		{ 179, -92, 52 },
		{ 179, -80, 52 },
		{ 179, 205, 52 },
		{ 179, 22, 52 },
		{ 179, 143, 52 },
		{ 179, -93, 52 },
		{ 179, 292, 52 },
		{ 179, 307, 52 },
		{ 179, 103, 52 },
		{ 179, -98, 52 },
		{ 179, 102, 52 },
		{ 179, 105, 52 },
		{ 179, 113, 52 },
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
		{ 179, 322, 52 },
		{ 179, 319, 52 },
		{ 179, -83, 52 },
		{ 179, -81, 52 },
		{ 179, -18, 52 },
		{ 179, -29, 35 },
		{ 179, 16, 52 },
		{ 179, 15, 52 },
		{ 179, 19, 52 },
		{ 179, 51, 52 },
		{ 179, 50, 52 },
		{ 179, 49, 52 },
		{ 179, 0, 27 },
		{ 179, 51, 52 },
		{ 179, 90, 52 },
		{ 179, -96, 52 },
		{ 179, 99, 52 },
		{ 179, -100, 52 },
		{ 179, -86, 52 },
		{ 179, 108, 52 },
		{ 179, 113, 52 },
		{ 179, 103, 52 },
		{ 179, -97, 52 },
		{ 179, -92, 52 },
		{ 179, 144, 52 },
		{ -46, 87, 0 },
		{ 156, 149, 20 },
		{ 0, 297, 0 },
		{ 111, 151, 19 },
		{ 179, 196, 52 },
		{ 179, 193, 52 },
		{ 179, 181, 52 },
		{ 179, -60, 52 },
		{ 179, 200, 52 },
		{ 179, 201, 52 },
		{ 179, 200, 52 },
		{ 179, 205, 52 },
		{ 179, 215, 52 },
		{ 179, 220, 52 },
		{ 179, 0, 17 },
		{ 179, 207, 52 },
		{ 179, 0, 15 },
		{ 179, 209, 52 },
		{ 179, 215, 52 },
		{ 179, 204, 52 },
		{ 179, 208, 52 },
		{ 179, 213, 52 },
		{ 179, 223, 52 },
		{ 179, 210, 52 },
		{ 179, 210, 52 },
		{ 179, 212, 52 },
		{ 179, 219, 52 },
		{ 179, 229, 52 },
		{ 179, 220, 52 },
		{ 179, 227, 52 },
		{ 179, 285, 52 },
		{ 179, 289, 52 },
		{ 179, 279, 52 },
		{ 0, 0, 2 },
		{ 156, 327, 20 },
		{ 49, 255, 19 },
		{ 179, 283, 52 },
		{ 179, 0, 31 },
		{ 179, 275, 52 },
		{ 179, 287, 52 },
		{ 179, 276, 52 },
		{ 179, 286, 52 },
		{ 179, 0, 36 },
		{ 179, 0, 37 },
		{ 179, 281, 52 },
		{ 179, 0, 39 },
		{ 179, 0, 7 },
		{ 179, 281, 52 },
		{ 179, 283, 52 },
		{ 179, 297, 52 },
		{ 179, 288, 52 },
		{ 179, 295, 52 },
		{ 179, 302, 52 },
		{ 179, 303, 52 },
		{ 179, 0, 29 },
		{ 179, 303, 52 },
		{ 179, 294, 52 },
		{ 179, 302, 52 },
		{ 179, 0, 6 },
		{ 179, 290, 52 },
		{ 179, 306, 52 },
		{ 0, 307, 0 },
		{ 179, 0, 30 },
		{ 179, 0, 32 },
		{ 179, 299, 52 },
		{ 179, 302, 52 },
		{ 179, 310, 52 },
		{ 179, 302, 52 },
		{ 179, 297, 52 },
		{ 179, 304, 52 },
		{ 179, 315, 52 },
		{ 179, 314, 52 },
		{ 179, 318, 52 },
		{ 179, 302, 52 },
		{ 179, 315, 52 },
		{ 179, 319, 52 },
		{ 179, 0, 49 },
		{ 179, 311, 52 },
		{ 179, 317, 52 },
		{ 179, 0, 51 },
		{ 137, 158, 0 },
		{ 179, 307, 52 },
		{ 179, 309, 52 },
		{ 179, 0, 38 },
		{ 179, 325, 52 },
		{ 179, 0, 40 },
		{ 179, 0, 42 },
		{ 179, 0, 44 },
		{ 179, 0, 45 },
		{ 179, 0, 46 },
		{ 179, 0, 47 },
		{ 179, 325, 52 },
		{ 179, 327, 52 },
		{ 179, 321, 52 },
		{ 179, 329, 52 },
		{ 179, 0, 34 },
		{ 179, 317, 52 },
		{ 179, 0, 48 },
		{ 179, 332, 52 },
		{ 179, 332, 52 },
		{ 179, 0, 33 },
		{ 179, 0, 41 },
		{ 179, 0, 43 },
		{ 0, 71, 50 }
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
		0
	};
	yybackup = backup;
}
#line 116 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


