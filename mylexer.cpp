/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 50 of your 30 day trial period.
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
* Date: 11/28/18
* Time: 20:34:03
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
	node(int v = 0, string n = '')
	{
		value = v;
		name = n;
	}
	};

#line 60 "mylexer.cpp"
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
#line 35 ".\\mylexer.l"

	// place any extra initialisation code here

#line 84 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 40 ".\\mylexer.l"

	// place any extra cleanup code here

#line 96 "mylexer.cpp"
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
#line 58 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 167 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 64 ".\\mylexer.l"

#line 174 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 65 ".\\mylexer.l"

#line 181 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 66 ".\\mylexer.l"

#line 188 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 67 ".\\mylexer.l"

#line 195 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 68 ".\\mylexer.l"
Line++;
#line 202 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 69 ".\\mylexer.l"
yylval.ntnode = new node(VOID); 	return VOID; 
#line 209 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 70 ".\\mylexer.l"
yylval.ntnode = new node(MAIN); 	return MAIN; 
#line 216 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 71 ".\\mylexer.l"
yylval.ntnode = new node(COLON); 	return COLON; 
#line 223 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 72 ".\\mylexer.l"
yylval.ntnode = new node(LBRACE); 	return LBRACE; 
#line 230 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 73 ".\\mylexer.l"
yylval.ntnode = new node(RBRACE); 	return RBRACE; 
#line 237 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 74 ".\\mylexer.l"
yylval.ntnode = new node(LP); 		return LP; 
#line 244 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 75 ".\\mylexer.l"
yylval.ntnode = new node(RP); 		return RP; 
#line 251 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 76 ".\\mylexer.l"
yylval.ntnode = new node(LS); 		return LSQUBRAC; 
#line 258 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 77 ".\\mylexer.l"
yylval.ntnode = new node(RS); 		return RSQUBRAC; 
#line 265 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 78 ".\\mylexer.l"
yylval.ntnode = new node(INT); 	return INT; 
#line 272 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 79 ".\\mylexer.l"
yylval.ntnode = new node(FLOAT); 	return FLOAT; 
#line 279 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 80 ".\\mylexer.l"
yylval.ntnode = new node(CHAR); 	return CHAR; 
#line 286 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 81 ".\\mylexer.l"
yylval.ntnode = new node(DOUBLE); 	return DOUBLE; 
#line 293 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 82 ".\\mylexer.l"
yylval.ntnode = new node(SHORT); 	return SHORT; 
#line 300 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 83 ".\\mylexer.l"
yylval.ntnode = new node(SEMICOL); return SHORT; 
#line 307 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 84 ".\\mylexer.l"
yylval.ntnode = new node(FOR); 	return FOR; 
#line 314 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 85 ".\\mylexer.l"
yylval.ntnode = new node(FOR); 	return FOR; 
#line 321 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 86 ".\\mylexer.l"
retrun ERROR;
#line 328 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 87 ".\\mylexer.l"
yylval.ntnode = new node(NUMBER);	return NUMBER; 
#line 335 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 93 ".\\mylexer.l"
yylval.ntnode = new node(COMPARISON);	retrun COMPARISON; 
#line 342 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 94 ".\\mylexer.l"
yylval.ntnode = new node(ADD);		retrun ADD; return ADD; 
#line 349 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 95 ".\\mylexer.l"
yylval.ntnode = new node(MINUS);	retrun MINUS; 
#line 356 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 96 ".\\mylexer.l"
yylval.ntnode = new node(DIVIDE);	retrun DIVIDE; 
#line 363 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 97 ".\\mylexer.l"
yylval.ntnode = new node(LOGIC);	retrun LOGIC; 
#line 370 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 98 ".\\mylexer.l"
yylval.ntnode = new node(BOOLOP);	retrun BOOLOP; 
#line 377 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 99 ".\\mylexer.l"
yylval.ntnode = new node(IF);		retrun IF; 
#line 384 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 100 ".\\mylexer.l"
yylval.ntnode = new node(MUTIPLY);	retrun MUTIPLY; 
#line 391 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 101 ".\\mylexer.l"
yylval.ntnode = new node(THEN);	retrun THEN;
#line 398 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 102 ".\\mylexer.l"
yylval.ntnode = new node(BREAK);	retrun BREAK;
#line 405 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 103 ".\\mylexer.l"
yylval.ntnode = new node(CASE);	retrun CASE;
#line 412 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 104 ".\\mylexer.l"
yylval.ntnode = new node(CONST);	retrun CONST;
#line 419 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 105 ".\\mylexer.l"
yylval.ntnode = new node(CONTINUE);retrun CONTINUE;
#line 426 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 106 ".\\mylexer.l"
yylval.ntnode = new node(DEFAULT);	retrun DEFAULT;
#line 433 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 107 ".\\mylexer.l"
yylval.ntnode = new node(DO);		retrun DO;
#line 440 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 108 ".\\mylexer.l"
yylval.ntnode = new node(ELSE);	retrun ELSE;
#line 447 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 109 ".\\mylexer.l"
yylval.ntnode = new node(ENUM);	retrun ENUM;
#line 454 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 110 ".\\mylexer.l"
yylval.ntnode = new node(EXTERN);	retrun EXTERN;
#line 461 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 111 ".\\mylexer.l"
yylval.ntnode = new node(GOTO);	retrun GOTO;
#line 468 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 112 ".\\mylexer.l"
yylval.ntnode = new node(RETURN);	retrun RETURN;
#line 475 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 113 ".\\mylexer.l"
yylval.ntnode = new node(REGISTER);retrun REGISTER;
#line 482 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 114 ".\\mylexer.l"
yylval.ntnode = new node(SIGNED);	retrun SIGNED;
#line 489 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 115 ".\\mylexer.l"
yylval.ntnode = new node(UNSIGNED);retrun UNSIGNED;
#line 496 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 116 ".\\mylexer.l"
yylval.ntnode = new node(SIZEOF);	retrun SIZEOF;
#line 503 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 117 ".\\mylexer.l"
yylval.ntnode = new node(STATIC);	retrun STATIC;
#line 510 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 118 ".\\mylexer.l"
yylval.ntnode = new node(STRUCT);	retrun STRUCT;
#line 517 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 119 ".\\mylexer.l"
yylval.ntnode = new node(SWITCH);	retrun SWITCH;
#line 524 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 120 ".\\mylexer.l"
yylval.ntnode = new node(TYPEDEF);	retrun TYPEDEF;
#line 531 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 121 ".\\mylexer.l"
yylval.ntnode = new node(UNION);	retrun UNION;
#line 538 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 122 ".\\mylexer.l"
yylval.ntnode = new node(VOLATILE);retrun VOLATILE;
#line 545 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 123 ".\\mylexer.l"
yylval.ntnode = new node(WHILE);	retrun WHILE;
#line 552 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 124 ".\\mylexer.l"
reserve(ID, yytext); yylval.ntnode = new node(ID);	retrun ID;
#line 559 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 125 ".\\mylexer.l"
retrun ERROR;
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

	yytransitionmax = 444;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 97, 67 },
		{ 4, 4 },
		{ 51, 25 },
		{ 70, 34 },
		{ 94, 65 },
		{ 104, 72 },
		{ 62, 30 },
		{ 44, 14 },
		{ 99, 68 },
		{ 52, 25 },
		{ 106, 73 },
		{ 81, 51 },
		{ 45, 14 },
		{ 107, 73 },
		{ 63, 30 },
		{ 105, 72 },
		{ 53, 25 },
		{ 95, 65 },
		{ 54, 26 },
		{ 98, 67 },
		{ 71, 34 },
		{ 4, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 4, 4 },
		{ 100, 68 },
		{ 82, 52 },
		{ 8, 1 },
		{ 55, 26 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 77, 48 },
		{ 13, 1 },
		{ 77, 48 },
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
		{ 116, 83 },
		{ 117, 83 },
		{ 83, 53 },
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
		{ 84, 54 },
		{ 22, 1 },
		{ 23, 1 },
		{ 20, 1 },
		{ 85, 55 },
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
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 75, 75 },
		{ 59, 28 },
		{ 86, 56 },
		{ 87, 57 },
		{ 60, 28 },
		{ 109, 75 },
		{ 88, 58 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 89, 59 },
		{ 42, 41 },
		{ 90, 60 },
		{ 91, 61 },
		{ 20, 190 },
		{ 92, 63 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 20, 190 },
		{ 0, 78 },
		{ 93, 64 },
		{ 0, 78 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 76, 76 },
		{ 66, 33 },
		{ 67, 33 },
		{ 50, 24 },
		{ 96, 66 },
		{ 6, 8 },
		{ 72, 35 },
		{ 101, 69 },
		{ 102, 70 },
		{ 103, 71 },
		{ 73, 36 },
		{ 74, 37 },
		{ 48, 76 },
		{ 68, 33 },
		{ 111, 78 },
		{ 43, 41 },
		{ 69, 33 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 111, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 108, 74 },
		{ 48, 76 },
		{ 6, 39 },
		{ 111, 78 },
		{ 47, 163 },
		{ 61, 29 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 111, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
		{ 47, 163 },
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
		{ 0, 43 },
		{ 75, 44 },
		{ 112, 79 },
		{ 113, 80 },
		{ 114, 81 },
		{ 115, 82 },
		{ 0, 45 },
		{ 141, 111 },
		{ 118, 84 },
		{ 141, 111 },
		{ 119, 85 },
		{ 47, 47 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 78, 111 },
		{ 56, 27 },
		{ 120, 86 },
		{ 57, 27 },
		{ 121, 87 },
		{ 122, 88 },
		{ 123, 89 },
		{ 124, 91 },
		{ 125, 93 },
		{ 126, 94 },
		{ 127, 95 },
		{ 128, 96 },
		{ 129, 97 },
		{ 58, 27 },
		{ 130, 98 },
		{ 131, 99 },
		{ 132, 100 },
		{ 133, 101 },
		{ 134, 102 },
		{ 135, 103 },
		{ 136, 104 },
		{ 46, 15 },
		{ 47, 47 },
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
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 110, 77 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 163, 141 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
		{ 76, 46 },
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
		{ 137, 105 },
		{ 138, 106 },
		{ 139, 107 },
		{ 140, 108 },
		{ 49, 18 },
		{ 64, 31 },
		{ 142, 112 },
		{ 143, 113 },
		{ 144, 116 },
		{ 145, 117 },
		{ 146, 118 },
		{ 147, 119 },
		{ 148, 122 },
		{ 149, 123 },
		{ 150, 126 },
		{ 151, 127 },
		{ 152, 128 },
		{ 153, 129 },
		{ 154, 130 },
		{ 155, 131 },
		{ 156, 132 },
		{ 157, 133 },
		{ 158, 135 },
		{ 159, 136 },
		{ 160, 137 },
		{ 161, 139 },
		{ 162, 140 },
		{ 65, 32 },
		{ 164, 142 },
		{ 165, 145 },
		{ 166, 146 },
		{ 167, 147 },
		{ 168, 148 },
		{ 169, 150 },
		{ 170, 151 },
		{ 171, 153 },
		{ 172, 154 },
		{ 173, 155 },
		{ 174, 156 },
		{ 175, 157 },
		{ 176, 158 },
		{ 177, 160 },
		{ 178, 161 },
		{ 79, 49 },
		{ 179, 164 },
		{ 180, 165 },
		{ 181, 166 },
		{ 182, 169 },
		{ 183, 176 },
		{ 184, 177 },
		{ 185, 178 },
		{ 186, 179 },
		{ 187, 180 },
		{ 188, 182 },
		{ 189, 184 },
		{ 190, 185 },
		{ 191, 186 },
		{ 80, 50 },
		{ 192, 191 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 57 },
		{ 0, -5, 1 },
		{ 0, 0, 5 },
		{ 0, 0, 30 },
		{ 41, 0, 57 },
		{ 0, 173, 29 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 0, 32 },
		{ 0, 0, 26 },
		{ 0, 0, 27 },
		{ 0, -32, 28 },
		{ 76, 287, 24 },
		{ 0, 0, 8 },
		{ 0, 0, 20 },
		{ 0, 327, 57 },
		{ 0, 0, 22 },
		{ 190, 0, 56 },
		{ 0, 0, 13 },
		{ 0, 0, 14 },
		{ 0, 0, 29 },
		{ 190, 95, 56 },
		{ 190, -92, 56 },
		{ 190, -80, 56 },
		{ 190, 205, 56 },
		{ 190, 22, 56 },
		{ 190, 143, 56 },
		{ 190, -93, 56 },
		{ 190, 293, 56 },
		{ 190, 311, 56 },
		{ 190, 103, 56 },
		{ 190, -98, 56 },
		{ 190, 102, 56 },
		{ 190, 105, 56 },
		{ 190, 113, 56 },
		{ 0, 0, 11 },
		{ 0, 127, 29 },
		{ 0, 0, 12 },
		{ -41, 129, 0 },
		{ 0, 0, 4 },
		{ -41, 281, 0 },
		{ -44, 250, 0 },
		{ -45, 287, 3 },
		{ 0, 317, 0 },
		{ 163, 233, 23 },
		{ 111, -7, 23 },
		{ 0, 368, 0 },
		{ 190, 341, 56 },
		{ 190, -101, 56 },
		{ 190, -68, 56 },
		{ 190, -54, 56 },
		{ 190, -18, 56 },
		{ 190, -29, 39 },
		{ 190, 16, 56 },
		{ 190, 15, 56 },
		{ 190, 19, 56 },
		{ 190, 51, 56 },
		{ 190, 50, 56 },
		{ 190, 49, 56 },
		{ 190, 0, 31 },
		{ 190, 51, 56 },
		{ 190, 90, 56 },
		{ 190, -96, 56 },
		{ 190, 99, 56 },
		{ 190, -100, 56 },
		{ 190, -86, 56 },
		{ 190, 108, 56 },
		{ 190, 113, 56 },
		{ 190, 103, 56 },
		{ 190, -97, 56 },
		{ 190, -92, 56 },
		{ 190, 144, 56 },
		{ -44, 87, 0 },
		{ 163, 149, 24 },
		{ 0, 297, 0 },
		{ 111, 151, 23 },
		{ 0, 232, 0 },
		{ 190, 197, 56 },
		{ 190, 194, 56 },
		{ 190, 182, 56 },
		{ 190, -61, 56 },
		{ 190, 202, 56 },
		{ 190, 203, 56 },
		{ 190, 213, 56 },
		{ 190, 207, 56 },
		{ 190, 216, 56 },
		{ 190, 221, 56 },
		{ 190, 0, 21 },
		{ 190, 208, 56 },
		{ 190, 0, 15 },
		{ 190, 210, 56 },
		{ 190, 216, 56 },
		{ 190, 205, 56 },
		{ 190, 209, 56 },
		{ 190, 214, 56 },
		{ 190, 225, 56 },
		{ 190, 211, 56 },
		{ 190, 211, 56 },
		{ 190, 213, 56 },
		{ 190, 220, 56 },
		{ 190, 230, 56 },
		{ 190, 221, 56 },
		{ 190, 280, 56 },
		{ 190, 286, 56 },
		{ 190, 290, 56 },
		{ 190, 280, 56 },
		{ 0, 0, 2 },
		{ 163, 327, 24 },
		{ 47, 255, 23 },
		{ 0, 329, 0 },
		{ 190, 285, 56 },
		{ 190, 0, 35 },
		{ 190, 0, 17 },
		{ 190, 277, 56 },
		{ 190, 289, 56 },
		{ 190, 278, 56 },
		{ 190, 288, 56 },
		{ 190, 0, 40 },
		{ 190, 0, 41 },
		{ 190, 283, 56 },
		{ 190, 282, 56 },
		{ 190, 0, 43 },
		{ 190, 0, 7 },
		{ 190, 284, 56 },
		{ 190, 286, 56 },
		{ 190, 285, 56 },
		{ 190, 301, 56 },
		{ 190, 292, 56 },
		{ 190, 299, 56 },
		{ 190, 306, 56 },
		{ 190, 307, 56 },
		{ 190, 0, 33 },
		{ 190, 307, 56 },
		{ 190, 298, 56 },
		{ 190, 306, 56 },
		{ 190, 0, 6 },
		{ 190, 294, 56 },
		{ 190, 310, 56 },
		{ 0, 307, 0 },
		{ 0, 352, 0 },
		{ 190, 0, 34 },
		{ 190, 0, 36 },
		{ 190, 304, 56 },
		{ 190, 307, 56 },
		{ 190, 315, 56 },
		{ 190, 307, 56 },
		{ 190, 0, 16 },
		{ 190, 302, 56 },
		{ 190, 309, 56 },
		{ 190, 0, 19 },
		{ 190, 320, 56 },
		{ 190, 319, 56 },
		{ 190, 323, 56 },
		{ 190, 307, 56 },
		{ 190, 320, 56 },
		{ 190, 324, 56 },
		{ 190, 0, 53 },
		{ 190, 316, 56 },
		{ 190, 322, 56 },
		{ 190, 0, 55 },
		{ 141, 158, 0 },
		{ 0, 396, 0 },
		{ 190, 313, 56 },
		{ 190, 315, 56 },
		{ 190, 0, 18 },
		{ 190, 0, 42 },
		{ 190, 331, 56 },
		{ 190, 0, 44 },
		{ 190, 0, 46 },
		{ 190, 0, 48 },
		{ 190, 0, 49 },
		{ 190, 0, 50 },
		{ 190, 0, 51 },
		{ 190, 331, 56 },
		{ 190, 333, 56 },
		{ 190, 327, 56 },
		{ 0, 375, 0 },
		{ 190, 336, 56 },
		{ 190, 0, 38 },
		{ 190, 324, 56 },
		{ 190, 0, 52 },
		{ 190, 339, 56 },
		{ 190, 339, 56 },
		{ 0, 380, 0 },
		{ 190, 0, 37 },
		{ 190, 0, 45 },
		{ 190, 0, 47 },
		{ 0, 71, 54 },
		{ 0, 382, 0 },
		{ 0, 0, 25 }
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
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 126 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


