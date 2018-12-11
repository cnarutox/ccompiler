/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 63 of your 30 day trial period.
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
* Date: 12/11/18
* Time: 22:19:54
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
extern int flag;
extern struct node {
	int id;
	string name;
	string value;
	int length;
	node** children;
	node(string n = "", string v = "")
	{
		length = 0;
		id = flag++;
		name = n;
		value = v;
	}
};

#line 65 "mylexer.cpp"
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
#line 40 ".\\mylexer.l"

	// place any extra initialisation code here

#line 89 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 45 ".\\mylexer.l"

	// place any extra cleanup code here

#line 101 "mylexer.cpp"
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
#line 63 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 172 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 69 ".\\mylexer.l"

#line 179 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 70 ".\\mylexer.l"

#line 186 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 71 ".\\mylexer.l"

#line 193 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 73 ".\\mylexer.l"
Line++;
#line 200 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 74 ".\\mylexer.l"
yylval.ntnode = new node("VOID"); 			return VOID; 
#line 207 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 75 ".\\mylexer.l"
yylval.ntnode = new node(":"); 		return ':'; 
#line 214 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 76 ".\\mylexer.l"
yylval.ntnode = new node(".");	    printf("99");		return '.';
#line 221 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 77 ".\\mylexer.l"
yylval.ntnode = new node(","); 		return ','; 
#line 228 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 78 ".\\mylexer.l"
yylval.ntnode = new node("("); 		return '('; 
#line 235 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 79 ".\\mylexer.l"
yylval.ntnode = new node(")"); 		return ')'; 
#line 242 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 80 ".\\mylexer.l"
yylval.ntnode = new node("{"); 		return '{'; 
#line 249 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 81 ".\\mylexer.l"
yylval.ntnode = new node("}"); 		return '}'; 
#line 256 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 82 ".\\mylexer.l"
yylval.ntnode = new node("["); 		return '['; 
#line 263 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 83 ".\\mylexer.l"
yylval.ntnode = new node("]"); 		return ']'; 
#line 270 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 84 ".\\mylexer.l"
yylval.ntnode = new node("INT"); 			return INT; 
#line 277 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 85 ".\\mylexer.l"
yylval.ntnode = new node("FLOAT"); 		return FLOAT; 
#line 284 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 86 ".\\mylexer.l"
yylval.ntnode = new node("CHAR"); 		return CHAR; 
#line 291 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 87 ".\\mylexer.l"
yylval.ntnode = new node("DOUBLE"); 		return DOUBLE; 
#line 298 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 88 ".\\mylexer.l"
yylval.ntnode = new node("SHORT"); 		return SHORT; 
#line 305 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 89 ".\\mylexer.l"
yylval.ntnode = new node(";"); 		return ';'; 
#line 312 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 90 ".\\mylexer.l"
yylval.ntnode = new node("FOR"); 			return FOR; 
#line 319 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 91 ".\\mylexer.l"
yylval.ntnode = new node("="); 		return '='; 
#line 326 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 92 ".\\mylexer.l"
return -1;
#line 333 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 93 ".\\mylexer.l"
yylval.ntnode = new node("CONSTANT", yytext);	return CONSTANT; 
#line 340 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 94 ".\\mylexer.l"
yylval.ntnode = new node("<");			return '<'; 
#line 347 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 95 ".\\mylexer.l"
yylval.ntnode = new node(">");			return '>'; 
#line 354 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 96 ".\\mylexer.l"
yylval.ntnode = new node("LE_OP");			return LE_OP; 
#line 361 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 97 ".\\mylexer.l"
yylval.ntnode = new node("GE_OP");			return GE_OP; 
#line 368 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 98 ".\\mylexer.l"
yylval.ntnode = new node("RIGHT_ASSIGN");return RIGHT_ASSIGN; 
#line 375 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 99 ".\\mylexer.l"
yylval.ntnode = new node("LEFT_ASSIGN");		return LEFT_ASSIGN; 
#line 382 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 100 ".\\mylexer.l"
yylval.ntnode = new node("NE_OP");			return NE_OP; 
#line 389 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 101 ".\\mylexer.l"
yylval.ntnode = new node("EQ_OP");			return EQ_OP; 
#line 396 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 102 ".\\mylexer.l"
yylval.ntnode = new node("+");			return '+'; 
#line 403 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 103 ".\\mylexer.l"
yylval.ntnode = new node("SUB_ASSIGN");	return SUB_ASSIGN;
#line 410 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 104 ".\\mylexer.l"
yylval.ntnode = new node("PTR_OP"); 		return PTR_OP;
#line 417 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 105 ".\\mylexer.l"
yylval.ntnode = new node("INC_OP"); 		return INC_OP;
#line 424 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 106 ".\\mylexer.l"
yylval.ntnode = new node("DEC_OP"); 		return DEC_OP;
#line 431 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 107 ".\\mylexer.l"
yylval.ntnode = new node("MUL_ASSIGN");	return MUL_ASSIGN;
#line 438 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 108 ".\\mylexer.l"
yylval.ntnode = new node("DIV_ASSIGN");	return DIV_ASSIGN;
#line 445 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 109 ".\\mylexer.l"
yylval.ntnode = new node("MOD_ASSIGN");	return MOD_ASSIGN;
#line 452 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 110 ".\\mylexer.l"
yylval.ntnode = new node("ADD_ASSIGN");    return ADD_ASSIGN;
#line 459 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 111 ".\\mylexer.l"
yylval.ntnode = new node("-");			return '-'; 
#line 466 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 112 ".\\mylexer.l"
yylval.ntnode = new node("/");			return '/'; 
#line 473 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 113 ".\\mylexer.l"
yylval.ntnode = new node("*");			return '*'; 
#line 480 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 114 ".\\mylexer.l"
yylval.ntnode = new node("&");			return '&'; 
#line 487 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 115 ".\\mylexer.l"
yylval.ntnode = new node("|");			return '|'; 
#line 494 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 116 ".\\mylexer.l"
yylval.ntnode = new node("~");			return '~'; 
#line 501 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 117 ".\\mylexer.l"
yylval.ntnode = new node("^");			return '^'; 
#line 508 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 118 ".\\mylexer.l"
yylval.ntnode = new node("AND_OP");	return AND_OP; 
#line 515 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 119 ".\\mylexer.l"
yylval.ntnode = new node("OR_OP");			return OR_OP; 
#line 522 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 121 ".\\mylexer.l"
yylval.ntnode = new node("IF");			return IF; 
#line 529 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 122 ".\\mylexer.l"
yylval.ntnode = new node("BREAK");			return BREAK;
#line 536 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 123 ".\\mylexer.l"
yylval.ntnode = new node("CASE");			return CASE;
#line 543 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 124 ".\\mylexer.l"
yylval.ntnode = new node("CONST");			return CONST;
#line 550 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 125 ".\\mylexer.l"
yylval.ntnode = new node("CONTINUE");		return CONTINUE;
#line 557 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 126 ".\\mylexer.l"
yylval.ntnode = new node("DEFAULT");		return DEFAULT;
#line 564 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 127 ".\\mylexer.l"
yylval.ntnode = new node("DO");			return DO;
#line 571 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 128 ".\\mylexer.l"
yylval.ntnode = new node("ELSE");			return ELSE;
#line 578 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 130 ".\\mylexer.l"
yylval.ntnode = new node("GOTO");			return GOTO;
#line 585 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 131 ".\\mylexer.l"
yylval.ntnode = new node("RETURN");		return RETURN;
#line 592 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 132 ".\\mylexer.l"
yylval.ntnode = new node("REGISTER");		return REGISTER;
#line 599 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 133 ".\\mylexer.l"
yylval.ntnode = new node("SIGNED");		return SIGNED;
#line 606 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 134 ".\\mylexer.l"
yylval.ntnode = new node("UNSIGNED");	return UNSIGNED;
#line 613 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 135 ".\\mylexer.l"
yylval.ntnode = new node("SIZEOF");		return SIZEOF;
#line 620 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 136 ".\\mylexer.l"
yylval.ntnode = new node("STATIC");		return STATIC;
#line 627 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 137 ".\\mylexer.l"
yylval.ntnode = new node("STRUCT");		return STRUCT;
#line 634 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 138 ".\\mylexer.l"
yylval.ntnode = new node("SWITCH");		return SWITCH;
#line 641 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 139 ".\\mylexer.l"
yylval.ntnode = new node("TYPEDEF");		return TYPEDEF;
#line 648 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 140 ".\\mylexer.l"
yylval.ntnode = new node("UNION");			return UNION;
#line 655 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 141 ".\\mylexer.l"
yylval.ntnode = new node("VOLATILE"); 		return VOLATILE;
#line 662 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 142 ".\\mylexer.l"
yylval.ntnode = new node("WHILE");			return WHILE;
#line 669 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 143 ".\\mylexer.l"
yylval.ntnode = new node("ENUM"); 			return ENUM;
#line 676 "mylexer.cpp"
		}
		break;
	case 73:
		{
#line 144 ".\\mylexer.l"
yylval.ntnode = new node("ELLIPSIS");	    return ELLIPSIS;
#line 683 "mylexer.cpp"
		}
		break;
	case 74:
		{
#line 145 ".\\mylexer.l"
yylval.ntnode = new node("ID", yytext);	return ID;
#line 690 "mylexer.cpp"
		}
		break;
	case 75:
		{
#line 146 ".\\mylexer.l"
return -1;
#line 697 "mylexer.cpp"
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

	yytransitionmax = 446;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 4, 4 },
		{ 53, 16 },
		{ 50, 14 },
		{ 65, 28 },
		{ 115, 83 },
		{ 109, 79 },
		{ 54, 16 },
		{ 48, 12 },
		{ 75, 33 },
		{ 117, 84 },
		{ 66, 28 },
		{ 111, 80 },
		{ 118, 84 },
		{ 89, 58 },
		{ 116, 83 },
		{ 89, 58 },
		{ 76, 33 },
		{ 67, 28 },
		{ 51, 14 },
		{ 52, 14 },
		{ 55, 16 },
		{ 4, 1 },
		{ 6, 1 },
		{ 4, 4 },
		{ 110, 79 },
		{ 49, 12 },
		{ 7, 1 },
		{ 8, 1 },
		{ 112, 80 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 126, 96 },
		{ 127, 96 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 92, 63 },
		{ 25, 1 },
		{ 26, 1 },
		{ 23, 1 },
		{ 93, 64 },
		{ 23, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 23, 1 },
		{ 33, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 39, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 40, 1 },
		{ 41, 1 },
		{ 42, 1 },
		{ 43, 1 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 87, 87 },
		{ 72, 31 },
		{ 62, 22 },
		{ 63, 22 },
		{ 73, 31 },
		{ 120, 87 },
		{ 94, 65 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 70, 30 },
		{ 95, 66 },
		{ 71, 30 },
		{ 96, 67 },
		{ 23, 196 },
		{ 97, 68 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 23, 196 },
		{ 0, 90 },
		{ 106, 77 },
		{ 0, 90 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 88, 88 },
		{ 68, 29 },
		{ 107, 77 },
		{ 99, 70 },
		{ 59, 20 },
		{ 60, 20 },
		{ 98, 69 },
		{ 61, 21 },
		{ 101, 71 },
		{ 102, 72 },
		{ 100, 70 },
		{ 69, 29 },
		{ 58, 88 },
		{ 103, 73 },
		{ 122, 90 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 122, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 104, 74 },
		{ 105, 76 },
		{ 74, 32 },
		{ 58, 88 },
		{ 57, 170 },
		{ 122, 90 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 122, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 170 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 57, 57 },
		{ 78, 35 },
		{ 79, 35 },
		{ 108, 78 },
		{ 45, 7 },
		{ 77, 34 },
		{ 113, 81 },
		{ 114, 82 },
		{ 64, 27 },
		{ 82, 36 },
		{ 119, 85 },
		{ 83, 37 },
		{ 57, 57 },
		{ 80, 35 },
		{ 84, 38 },
		{ 149, 122 },
		{ 81, 35 },
		{ 149, 122 },
		{ 85, 39 },
		{ 86, 41 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 90, 122 },
		{ 56, 17 },
		{ 123, 93 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 124, 94 },
		{ 125, 95 },
		{ 57, 57 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 121, 89 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 170, 149 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 88, 56 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 121, 121 },
		{ 87, 53 },
		{ 128, 97 },
		{ 129, 98 },
		{ 130, 99 },
		{ 131, 100 },
		{ 132, 101 },
		{ 133, 102 },
		{ 134, 104 },
		{ 135, 106 },
		{ 136, 107 },
		{ 137, 108 },
		{ 138, 109 },
		{ 139, 110 },
		{ 140, 111 },
		{ 141, 112 },
		{ 142, 113 },
		{ 143, 114 },
		{ 144, 115 },
		{ 145, 116 },
		{ 146, 117 },
		{ 147, 118 },
		{ 148, 119 },
		{ 0, 54 },
		{ 46, 8 },
		{ 150, 123 },
		{ 151, 126 },
		{ 152, 127 },
		{ 153, 128 },
		{ 154, 129 },
		{ 155, 130 },
		{ 156, 133 },
		{ 157, 135 },
		{ 158, 136 },
		{ 159, 137 },
		{ 160, 138 },
		{ 161, 139 },
		{ 162, 140 },
		{ 163, 141 },
		{ 164, 142 },
		{ 165, 143 },
		{ 166, 144 },
		{ 167, 145 },
		{ 168, 147 },
		{ 169, 148 },
		{ 47, 11 },
		{ 171, 152 },
		{ 172, 153 },
		{ 173, 154 },
		{ 174, 155 },
		{ 175, 157 },
		{ 176, 158 },
		{ 177, 160 },
		{ 178, 161 },
		{ 179, 162 },
		{ 180, 163 },
		{ 181, 164 },
		{ 182, 165 },
		{ 183, 167 },
		{ 184, 168 },
		{ 44, 6 },
		{ 185, 171 },
		{ 186, 172 },
		{ 187, 174 },
		{ 188, 175 },
		{ 189, 182 },
		{ 190, 183 },
		{ 191, 184 },
		{ 192, 185 },
		{ 193, 187 },
		{ 194, 188 },
		{ 195, 190 },
		{ 196, 191 },
		{ 91, 59 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 75 },
		{ 0, -6, 1 },
		{ 0, 0, 4 },
		{ 0, 371, 75 },
		{ 0, 231, 75 },
		{ 0, 358, 45 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 356, 44 },
		{ 0, -33, 33 },
		{ 0, 0, 8 },
		{ 0, -40, 42 },
		{ 0, 0, 7 },
		{ 0, -38, 43 },
		{ 88, 272, 24 },
		{ 0, 0, 6 },
		{ 0, 0, 20 },
		{ 0, 150, 25 },
		{ 0, 152, 22 },
		{ 0, 70, 26 },
		{ 196, 0, 74 },
		{ 0, 0, 13 },
		{ 0, 0, 14 },
		{ 0, 0, 48 },
		{ 196, 182, 74 },
		{ 196, -91, 74 },
		{ 196, 106, 74 },
		{ 196, 54, 74 },
		{ 196, 22, 74 },
		{ 196, 138, 74 },
		{ 196, -91, 74 },
		{ 196, 192, 74 },
		{ 196, 185, 74 },
		{ 196, 176, 74 },
		{ 196, 189, 74 },
		{ 196, 191, 74 },
		{ 196, 202, 74 },
		{ 0, 0, 11 },
		{ 0, 183, 46 },
		{ 0, 0, 12 },
		{ 0, 0, 47 },
		{ 0, 0, 31 },
		{ 0, 0, 40 },
		{ 0, 0, 49 },
		{ 0, 0, 38 },
		{ 0, 0, 36 },
		{ 0, 0, 41 },
		{ 0, 0, 37 },
		{ 0, 0, 34 },
		{ 0, 0, 35 },
		{ -53, 331, 0 },
		{ -54, 385, 3 },
		{ 0, 0, 39 },
		{ 0, 305, 0 },
		{ 170, 231, 23 },
		{ 122, -27, 23 },
		{ 0, 384, 0 },
		{ 0, 0, 27 },
		{ 0, 0, 32 },
		{ 0, 0, 28 },
		{ 0, 23, 0 },
		{ 196, -13, 74 },
		{ 196, 20, 74 },
		{ 196, 66, 74 },
		{ 196, 55, 74 },
		{ 196, 65, 74 },
		{ 196, 95, 57 },
		{ 196, 101, 74 },
		{ 196, 97, 74 },
		{ 196, 104, 74 },
		{ 196, 105, 74 },
		{ 196, 131, 74 },
		{ 196, 0, 51 },
		{ 196, 132, 74 },
		{ 196, 92, 74 },
		{ 196, 180, 74 },
		{ 196, -95, 74 },
		{ 196, -83, 74 },
		{ 196, 189, 74 },
		{ 196, 183, 74 },
		{ 196, -98, 74 },
		{ 196, -93, 74 },
		{ 196, 193, 74 },
		{ 0, 0, 50 },
		{ -53, 87, 0 },
		{ 170, 149, 24 },
		{ 0, 285, 0 },
		{ 122, 151, 23 },
		{ 0, 0, 30 },
		{ 0, 0, 29 },
		{ 196, 222, 74 },
		{ 196, 229, 74 },
		{ 196, 217, 74 },
		{ 196, -60, 74 },
		{ 196, 277, 74 },
		{ 196, 277, 74 },
		{ 196, 271, 74 },
		{ 196, 276, 74 },
		{ 196, 269, 74 },
		{ 196, 282, 74 },
		{ 196, 0, 21 },
		{ 196, 269, 74 },
		{ 196, 0, 15 },
		{ 196, 276, 74 },
		{ 196, 265, 74 },
		{ 196, 269, 74 },
		{ 196, 274, 74 },
		{ 196, 284, 74 },
		{ 196, 270, 74 },
		{ 196, 270, 74 },
		{ 196, 272, 74 },
		{ 196, 288, 74 },
		{ 196, 279, 74 },
		{ 196, 286, 74 },
		{ 196, 292, 74 },
		{ 196, 296, 74 },
		{ 196, 286, 74 },
		{ 0, 0, 2 },
		{ 170, 315, 24 },
		{ 57, 260, 23 },
		{ 196, 290, 74 },
		{ 196, 0, 53 },
		{ 196, 0, 17 },
		{ 196, 282, 74 },
		{ 196, 294, 74 },
		{ 196, 283, 74 },
		{ 196, 293, 74 },
		{ 196, 290, 74 },
		{ 196, 0, 58 },
		{ 196, 0, 72 },
		{ 196, 287, 74 },
		{ 196, 0, 59 },
		{ 196, 289, 74 },
		{ 196, 291, 74 },
		{ 196, 290, 74 },
		{ 196, 306, 74 },
		{ 196, 297, 74 },
		{ 196, 304, 74 },
		{ 196, 311, 74 },
		{ 196, 312, 74 },
		{ 196, 312, 74 },
		{ 196, 303, 74 },
		{ 196, 311, 74 },
		{ 196, 0, 5 },
		{ 196, 299, 74 },
		{ 196, 315, 74 },
		{ 0, 295, 0 },
		{ 196, 0, 52 },
		{ 196, 0, 54 },
		{ 196, 308, 74 },
		{ 196, 311, 74 },
		{ 196, 319, 74 },
		{ 196, 306, 74 },
		{ 196, 0, 16 },
		{ 196, 306, 74 },
		{ 196, 313, 74 },
		{ 196, 0, 19 },
		{ 196, 324, 74 },
		{ 196, 323, 74 },
		{ 196, 327, 74 },
		{ 196, 311, 74 },
		{ 196, 324, 74 },
		{ 196, 328, 74 },
		{ 196, 0, 69 },
		{ 196, 320, 74 },
		{ 196, 326, 74 },
		{ 196, 0, 71 },
		{ 149, 156, 0 },
		{ 196, 316, 74 },
		{ 196, 318, 74 },
		{ 196, 0, 18 },
		{ 196, 330, 74 },
		{ 196, 335, 74 },
		{ 196, 0, 60 },
		{ 196, 0, 62 },
		{ 196, 0, 64 },
		{ 196, 0, 65 },
		{ 196, 0, 66 },
		{ 196, 0, 67 },
		{ 196, 335, 74 },
		{ 196, 337, 74 },
		{ 196, 331, 74 },
		{ 196, 339, 74 },
		{ 196, 0, 56 },
		{ 196, 326, 74 },
		{ 196, 328, 74 },
		{ 196, 0, 68 },
		{ 196, 343, 74 },
		{ 196, 343, 74 },
		{ 196, 0, 55 },
		{ 196, 0, 73 },
		{ 196, 0, 61 },
		{ 196, 0, 63 },
		{ 0, 71, 70 }
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
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
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
#line 147 ".\\mylexer.l"
  
/////////////////////////////////////////////////////////////////////////////
// programs section
 
