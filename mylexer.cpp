/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 53 of your 30 day trial period.
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
* Date: 12/01/18
* Time: 18:00:06
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
	int length;
	node** children;
	node(int v = 0, string n = "")
	{
		value = v;
		name = n;
	}
	};

#line 61 "mylexer.cpp"
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
#line 36 ".\\mylexer.l"

	// place any extra initialisation code here

#line 85 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 41 ".\\mylexer.l"

	// place any extra cleanup code here

#line 97 "mylexer.cpp"
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
#line 59 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 168 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 65 ".\\mylexer.l"

#line 175 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 66 ".\\mylexer.l"

#line 182 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 67 ".\\mylexer.l"

#line 189 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 68 ".\\mylexer.l"

#line 196 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 69 ".\\mylexer.l"
Line++;
#line 203 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 70 ".\\mylexer.l"
yylval.ntnode = new node(VOID); 	return VOID; 
#line 210 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 71 ".\\mylexer.l"
yylval.ntnode = new node(MAIN); 	return MAIN; 
#line 217 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 72 ".\\mylexer.l"
yylval.ntnode = new node(':'); 	return ':'; 
#line 224 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 73 ".\\mylexer.l"
yylval.ntnode = new node('('); 	return '('; 
#line 231 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 74 ".\\mylexer.l"
yylval.ntnode = new node(')'); 	return ')'; 
#line 238 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 75 ".\\mylexer.l"
yylval.ntnode = new node('{'); 	return '{'; 
#line 245 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 76 ".\\mylexer.l"
yylval.ntnode = new node('}'); 	return '}'; 
#line 252 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 77 ".\\mylexer.l"
yylval.ntnode = new node('['); 	return '['; 
#line 259 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 78 ".\\mylexer.l"
yylval.ntnode = new node(']'); 	return ']'; 
#line 266 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 79 ".\\mylexer.l"
yylval.ntnode = new node(INT); 	return INT; 
#line 273 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 80 ".\\mylexer.l"
yylval.ntnode = new node(FLOAT); 	return FLOAT; 
#line 280 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 81 ".\\mylexer.l"
yylval.ntnode = new node(CHAR); 	return CHAR; 
#line 287 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 82 ".\\mylexer.l"
yylval.ntnode = new node(DOUBLE); 	return DOUBLE; 
#line 294 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 83 ".\\mylexer.l"
yylval.ntnode = new node(SHORT); 	return SHORT; 
#line 301 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 84 ".\\mylexer.l"
yylval.ntnode = new node(';'); 	return ';'; 
#line 308 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 85 ".\\mylexer.l"
yylval.ntnode = new node(FOR); 	return FOR; 
#line 315 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 86 ".\\mylexer.l"
yylval.ntnode = new node(FOR); 	return FOR; 
#line 322 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 87 ".\\mylexer.l"
return -1;
#line 329 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 88 ".\\mylexer.l"
yylval.ntnode = new node(NUMBER);	return NUMBER; 
#line 336 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 95 ".\\mylexer.l"
yylval.ntnode = new node('+');		return '+'; 
#line 343 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 96 ".\\mylexer.l"
yylval.ntnode = new node('-');		return '-'; 
#line 350 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 97 ".\\mylexer.l"
yylval.ntnode = new node('/');		return '/'; 
#line 357 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 98 ".\\mylexer.l"
yylval.ntnode = new node('*');		return '*'; 
#line 364 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 101 ".\\mylexer.l"
yylval.ntnode = new node(IF);		return IF; 
#line 371 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 102 ".\\mylexer.l"
yylval.ntnode = new node(BREAK);	return BREAK;
#line 378 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 103 ".\\mylexer.l"
yylval.ntnode = new node(CASE);	return CASE;
#line 385 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 104 ".\\mylexer.l"
yylval.ntnode = new node(CONST);	return CONST;
#line 392 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 105 ".\\mylexer.l"
yylval.ntnode = new node(CONTINUE);return CONTINUE;
#line 399 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 106 ".\\mylexer.l"
yylval.ntnode = new node(DEFAULT);	return DEFAULT;
#line 406 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 107 ".\\mylexer.l"
yylval.ntnode = new node(DO);		return DO;
#line 413 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 108 ".\\mylexer.l"
yylval.ntnode = new node(ELSE);	return ELSE;
#line 420 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 109 ".\\mylexer.l"
yylval.ntnode = new node(ENUM);	return ENUM;
#line 427 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 110 ".\\mylexer.l"
yylval.ntnode = new node(EXTERN);	return EXTERN;
#line 434 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 111 ".\\mylexer.l"
yylval.ntnode = new node(GOTO);	return GOTO;
#line 441 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 112 ".\\mylexer.l"
yylval.ntnode = new node(RETURN);	return RETURN;
#line 448 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 113 ".\\mylexer.l"
yylval.ntnode = new node(REGISTER);return REGISTER;
#line 455 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 114 ".\\mylexer.l"
yylval.ntnode = new node(SIGNED);	return SIGNED;
#line 462 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 115 ".\\mylexer.l"
yylval.ntnode = new node(UNSIGNED);return UNSIGNED;
#line 469 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 116 ".\\mylexer.l"
yylval.ntnode = new node(SIZEOF);	return SIZEOF;
#line 476 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 117 ".\\mylexer.l"
yylval.ntnode = new node(STATIC);	return STATIC;
#line 483 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 118 ".\\mylexer.l"
yylval.ntnode = new node(STRUCT);	return STRUCT;
#line 490 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 119 ".\\mylexer.l"
yylval.ntnode = new node(SWITCH);	return SWITCH;
#line 497 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 120 ".\\mylexer.l"
yylval.ntnode = new node(TYPEDEF);	return TYPEDEF;
#line 504 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 121 ".\\mylexer.l"
yylval.ntnode = new node(UNION);	return UNION;
#line 511 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 122 ".\\mylexer.l"
yylval.ntnode = new node(VOLATILE);return VOLATILE;
#line 518 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 123 ".\\mylexer.l"
yylval.ntnode = new node(WHILE);	return WHILE;
#line 525 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 125 ".\\mylexer.l"
return -1;
#line 532 "mylexer.cpp"
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

	yytransitionmax = 330;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 36, 35 },
		{ 0, 71 },
		{ 92, 62 },
		{ 0, 71 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 41, 41 },
		{ 90, 61 },
		{ 68, 68 },
		{ 48, 21 },
		{ 108, 76 },
		{ 109, 76 },
		{ 93, 62 },
		{ 101, 68 },
		{ 4, 1 },
		{ 87, 59 },
		{ 6, 1 },
		{ 56, 25 },
		{ 41, 41 },
		{ 49, 21 },
		{ 103, 71 },
		{ 4, 4 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 57, 25 },
		{ 91, 61 },
		{ 10, 1 },
		{ 88, 59 },
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
		{ 4, 4 },
		{ 53, 23 },
		{ 98, 66 },
		{ 74, 45 },
		{ 54, 23 },
		{ 99, 66 },
		{ 41, 41 },
		{ 37, 35 },
		{ 103, 71 },
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
		{ 45, 20 },
		{ 60, 28 },
		{ 61, 28 },
		{ 50, 22 },
		{ 38, 11 },
		{ 51, 22 },
		{ 70, 42 },
		{ 46, 20 },
		{ 70, 42 },
		{ 39, 11 },
		{ 17, 1 },
		{ 42, 69 },
		{ 18, 1 },
		{ 62, 28 },
		{ 47, 20 },
		{ 52, 22 },
		{ 63, 28 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 75, 46 },
		{ 25, 1 },
		{ 76, 47 },
		{ 77, 48 },
		{ 78, 49 },
		{ 26, 1 },
		{ 96, 65 },
		{ 79, 50 },
		{ 80, 51 },
		{ 81, 52 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 97, 65 },
		{ 82, 53 },
		{ 84, 55 },
		{ 33, 1 },
		{ 42, 69 },
		{ 34, 1 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 103, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 83, 54 },
		{ 85, 57 },
		{ 86, 58 },
		{ 44, 19 },
		{ 41, 154 },
		{ 89, 60 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 103, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 41, 154 },
		{ 132, 103 },
		{ 64, 29 },
		{ 132, 103 },
		{ 65, 30 },
		{ 94, 63 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 71, 103 },
		{ 40, 12 },
		{ 95, 64 },
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
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 102 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 102, 70 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 154, 132 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 69, 40 },
		{ 66, 31 },
		{ 67, 32 },
		{ 100, 67 },
		{ 55, 24 },
		{ 0, 37 },
		{ 68, 38 },
		{ 0, 39 },
		{ 104, 72 },
		{ 105, 73 },
		{ 106, 74 },
		{ 107, 75 },
		{ 43, 15 },
		{ 110, 77 },
		{ 111, 78 },
		{ 112, 79 },
		{ 113, 80 },
		{ 114, 81 },
		{ 115, 82 },
		{ 116, 84 },
		{ 117, 86 },
		{ 118, 87 },
		{ 119, 88 },
		{ 120, 89 },
		{ 121, 90 },
		{ 122, 91 },
		{ 123, 92 },
		{ 124, 93 },
		{ 125, 94 },
		{ 126, 95 },
		{ 127, 96 },
		{ 128, 97 },
		{ 129, 98 },
		{ 130, 99 },
		{ 131, 100 },
		{ 58, 26 },
		{ 59, 27 },
		{ 133, 104 },
		{ 134, 105 },
		{ 135, 108 },
		{ 136, 109 },
		{ 137, 110 },
		{ 138, 111 },
		{ 139, 114 },
		{ 140, 115 },
		{ 141, 118 },
		{ 142, 119 },
		{ 143, 120 },
		{ 144, 121 },
		{ 145, 122 },
		{ 146, 123 },
		{ 147, 124 },
		{ 148, 125 },
		{ 149, 126 },
		{ 150, 127 },
		{ 151, 128 },
		{ 152, 130 },
		{ 153, 131 },
		{ 72, 43 },
		{ 155, 133 },
		{ 156, 136 },
		{ 157, 137 },
		{ 158, 138 },
		{ 159, 139 },
		{ 160, 141 },
		{ 161, 142 },
		{ 162, 144 },
		{ 163, 145 },
		{ 164, 146 },
		{ 165, 147 },
		{ 166, 148 },
		{ 167, 149 },
		{ 168, 151 },
		{ 169, 152 },
		{ 73, 44 },
		{ 170, 155 },
		{ 171, 156 },
		{ 172, 157 },
		{ 173, 160 },
		{ 174, 167 },
		{ 175, 168 },
		{ 176, 169 },
		{ 177, 170 },
		{ 178, 171 },
		{ 179, 173 },
		{ 180, 175 },
		{ 181, 176 },
		{ 182, 177 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 52 },
		{ 0, 22, 1 },
		{ 0, 0, 5 },
		{ 35, 0, 52 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 0, 28 },
		{ 0, 0, 26 },
		{ 0, 35, 27 },
		{ 69, 145, 24 },
		{ 0, 0, 8 },
		{ 0, 0, 20 },
		{ 0, 192, 52 },
		{ 0, 0, 22 },
		{ 0, 0, 13 },
		{ 0, 0, 14 },
		{ 0, 33, 52 },
		{ 0, -24, 52 },
		{ 0, -82, 52 },
		{ 0, -32, 52 },
		{ 0, -53, 52 },
		{ 0, 135, 52 },
		{ 0, -75, 52 },
		{ 0, 180, 52 },
		{ 0, 177, 52 },
		{ 0, -30, 52 },
		{ 0, 56, 52 },
		{ 0, 69, 52 },
		{ 0, 132, 52 },
		{ 0, 140, 52 },
		{ 0, 0, 11 },
		{ 0, 0, 12 },
		{ -35, -31, 0 },
		{ 0, 0, 4 },
		{ -35, 237, 0 },
		{ -38, 206, 0 },
		{ -39, 239, 3 },
		{ 0, 185, 0 },
		{ 154, -41, 23 },
		{ 103, 36, 23 },
		{ 0, 240, 0 },
		{ 0, 215, 0 },
		{ 0, -58, 0 },
		{ 0, -1, 0 },
		{ 0, -12, 0 },
		{ 0, -3, 0 },
		{ 0, -17, 35 },
		{ 0, -12, 0 },
		{ 0, -13, 0 },
		{ 0, -11, 0 },
		{ 0, 2, 0 },
		{ 0, 30, 0 },
		{ 0, -2, 0 },
		{ 0, 0, 29 },
		{ 0, 29, 0 },
		{ 0, 41, 0 },
		{ 0, -78, 0 },
		{ 0, 38, 0 },
		{ 0, -86, 0 },
		{ 0, -92, 0 },
		{ 0, 75, 0 },
		{ 0, 80, 0 },
		{ 0, -3, 0 },
		{ 0, -49, 0 },
		{ 0, 140, 0 },
		{ -38, -24, 0 },
		{ 154, 15, 24 },
		{ 0, 165, 0 },
		{ 103, -39, 23 },
		{ 0, 189, 0 },
		{ 0, 154, 0 },
		{ 0, 151, 0 },
		{ 0, 139, 0 },
		{ 0, -95, 0 },
		{ 0, 158, 0 },
		{ 0, 158, 0 },
		{ 0, 156, 0 },
		{ 0, 149, 0 },
		{ 0, 158, 0 },
		{ 0, 163, 0 },
		{ 0, 0, 21 },
		{ 0, 150, 0 },
		{ 0, 0, 15 },
		{ 0, 152, 0 },
		{ 0, 158, 0 },
		{ 0, 147, 0 },
		{ 0, 151, 0 },
		{ 0, 156, 0 },
		{ 0, 166, 0 },
		{ 0, 152, 0 },
		{ 0, 152, 0 },
		{ 0, 154, 0 },
		{ 0, 170, 0 },
		{ 0, 161, 0 },
		{ 0, 168, 0 },
		{ 0, 174, 0 },
		{ 0, 178, 0 },
		{ 0, 168, 0 },
		{ 0, 0, 2 },
		{ 154, 155, 24 },
		{ 41, 133, 23 },
		{ 0, 217, 0 },
		{ 0, 173, 0 },
		{ 0, 0, 31 },
		{ 0, 0, 17 },
		{ 0, 165, 0 },
		{ 0, 177, 0 },
		{ 0, 166, 0 },
		{ 0, 176, 0 },
		{ 0, 0, 36 },
		{ 0, 0, 37 },
		{ 0, 171, 0 },
		{ 0, 170, 0 },
		{ 0, 0, 39 },
		{ 0, 0, 7 },
		{ 0, 172, 0 },
		{ 0, 174, 0 },
		{ 0, 173, 0 },
		{ 0, 189, 0 },
		{ 0, 180, 0 },
		{ 0, 187, 0 },
		{ 0, 194, 0 },
		{ 0, 195, 0 },
		{ 0, 195, 0 },
		{ 0, 186, 0 },
		{ 0, 194, 0 },
		{ 0, 0, 6 },
		{ 0, 182, 0 },
		{ 0, 198, 0 },
		{ 0, 175, 0 },
		{ 0, 240, 0 },
		{ 0, 0, 30 },
		{ 0, 0, 32 },
		{ 0, 192, 0 },
		{ 0, 195, 0 },
		{ 0, 203, 0 },
		{ 0, 195, 0 },
		{ 0, 0, 16 },
		{ 0, 190, 0 },
		{ 0, 197, 0 },
		{ 0, 0, 19 },
		{ 0, 208, 0 },
		{ 0, 207, 0 },
		{ 0, 211, 0 },
		{ 0, 195, 0 },
		{ 0, 208, 0 },
		{ 0, 212, 0 },
		{ 0, 0, 49 },
		{ 0, 204, 0 },
		{ 0, 210, 0 },
		{ 0, 0, 51 },
		{ 132, 53, 0 },
		{ 0, 284, 0 },
		{ 0, 201, 0 },
		{ 0, 203, 0 },
		{ 0, 0, 18 },
		{ 0, 0, 38 },
		{ 0, 219, 0 },
		{ 0, 0, 40 },
		{ 0, 0, 42 },
		{ 0, 0, 44 },
		{ 0, 0, 45 },
		{ 0, 0, 46 },
		{ 0, 0, 47 },
		{ 0, 219, 0 },
		{ 0, 221, 0 },
		{ 0, 215, 0 },
		{ 0, 263, 0 },
		{ 0, 224, 0 },
		{ 0, 0, 34 },
		{ 0, 212, 0 },
		{ 0, 0, 48 },
		{ 0, 227, 0 },
		{ 0, 227, 0 },
		{ 0, 286, 0 },
		{ 0, 0, 33 },
		{ 0, 0, 41 },
		{ 0, 0, 43 },
		{ 0, 0, 50 },
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
		0
	};
	yybackup = backup;
}
#line 126 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section


