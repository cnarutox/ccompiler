/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 57 of your 30 day trial period.
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
* Date: 12/05/18
* Time: 16:41:02
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
yylval.ntnode = new node(","); 		return ','; 
#line 221 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 77 ".\\mylexer.l"
yylval.ntnode = new node("("); 		return '('; 
#line 228 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 78 ".\\mylexer.l"
yylval.ntnode = new node(")"); 		return ')'; 
#line 235 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 79 ".\\mylexer.l"
yylval.ntnode = new node("{"); 		return '{'; 
#line 242 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 80 ".\\mylexer.l"
yylval.ntnode = new node("}"); 		return '}'; 
#line 249 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 81 ".\\mylexer.l"
yylval.ntnode = new node("["); 		return '['; 
#line 256 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 82 ".\\mylexer.l"
yylval.ntnode = new node("]"); 		return ']'; 
#line 263 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 83 ".\\mylexer.l"
yylval.ntnode = new node("INT"); 			return INT; 
#line 270 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 84 ".\\mylexer.l"
yylval.ntnode = new node("FLOAT"); 		return FLOAT; 
#line 277 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 85 ".\\mylexer.l"
yylval.ntnode = new node("CHAR"); 		return CHAR; 
#line 284 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 86 ".\\mylexer.l"
yylval.ntnode = new node("DOUBLE"); 		return DOUBLE; 
#line 291 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 87 ".\\mylexer.l"
yylval.ntnode = new node("SHORT"); 		return SHORT; 
#line 298 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 88 ".\\mylexer.l"
yylval.ntnode = new node(";"); 		return ';'; 
#line 305 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 89 ".\\mylexer.l"
yylval.ntnode = new node("FOR"); 			return FOR; 
#line 312 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 90 ".\\mylexer.l"
yylval.ntnode = new node("="); 		return '='; 
#line 319 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 91 ".\\mylexer.l"
return -1;
#line 326 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 92 ".\\mylexer.l"
yylval.ntnode = new node("CONSTANT", yytext);	return CONSTANT; 
#line 333 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 93 ".\\mylexer.l"
yylval.ntnode = new node("<");			return '<'; 
#line 340 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 94 ".\\mylexer.l"
yylval.ntnode = new node(">");			return '>'; 
#line 347 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 95 ".\\mylexer.l"
yylval.ntnode = new node("LE_OP");			return LE_OP; 
#line 354 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 96 ".\\mylexer.l"
yylval.ntnode = new node("GE_OP");			return GE_OP; 
#line 361 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 97 ".\\mylexer.l"
yylval.ntnode = new node("RIGHT_ASSIGN");return RIGHT_ASSIGN; 
#line 368 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 98 ".\\mylexer.l"
yylval.ntnode = new node("LEFT_ASSIGN");		return LEFT_ASSIGN; 
#line 375 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 99 ".\\mylexer.l"
yylval.ntnode = new node("NE_OP");			return NE_OP; 
#line 382 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 100 ".\\mylexer.l"
yylval.ntnode = new node("EQ_OP");			return EQ_OP; 
#line 389 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 101 ".\\mylexer.l"
yylval.ntnode = new node("+");			return '+'; 
#line 396 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 102 ".\\mylexer.l"
yylval.ntnode = new node("SUB_ASSIGN");	return SUB_ASSIGN;
#line 403 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 103 ".\\mylexer.l"
yylval.ntnode = new node("PTR_OP"); 		return PTR_OP;
#line 410 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 104 ".\\mylexer.l"
yylval.ntnode = new node("INC_OP"); 		return INC_OP;
#line 417 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 105 ".\\mylexer.l"
yylval.ntnode = new node("DEC_OP"); 		return DEC_OP;
#line 424 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 106 ".\\mylexer.l"
yylval.ntnode = new node("MUL_ASSIGN");	return MUL_ASSIGN;
#line 431 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 107 ".\\mylexer.l"
yylval.ntnode = new node("DIV_ASSIGN");	return DIV_ASSIGN;
#line 438 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 108 ".\\mylexer.l"
yylval.ntnode = new node("MOD_ASSIGN");	return MOD_ASSIGN;
#line 445 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 109 ".\\mylexer.l"
yylval.ntnode = new node("ADD_ASSIGN");    return ADD_ASSIGN;
#line 452 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 110 ".\\mylexer.l"
yylval.ntnode = new node("-");			return '-'; 
#line 459 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 111 ".\\mylexer.l"
yylval.ntnode = new node("/");			return '/'; 
#line 466 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 112 ".\\mylexer.l"
yylval.ntnode = new node("*");			return '*'; 
#line 473 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 113 ".\\mylexer.l"
yylval.ntnode = new node("&");			return '&'; 
#line 480 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 114 ".\\mylexer.l"
yylval.ntnode = new node("|");			return '|'; 
#line 487 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 115 ".\\mylexer.l"
yylval.ntnode = new node("~");			return '~'; 
#line 494 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 116 ".\\mylexer.l"
yylval.ntnode = new node("^");			return '^'; 
#line 501 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 117 ".\\mylexer.l"
yylval.ntnode = new node("AND_OP");	return AND_OP; 
#line 508 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 118 ".\\mylexer.l"
yylval.ntnode = new node("OR_OP");			return OR_OP; 
#line 515 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 120 ".\\mylexer.l"
yylval.ntnode = new node("IF");			return IF; 
#line 522 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 121 ".\\mylexer.l"
yylval.ntnode = new node("BREAK");			return BREAK;
#line 529 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 122 ".\\mylexer.l"
yylval.ntnode = new node("CASE");			return CASE;
#line 536 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 123 ".\\mylexer.l"
yylval.ntnode = new node("CONST");			return CONST;
#line 543 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 124 ".\\mylexer.l"
yylval.ntnode = new node("CONTINUE");		return CONTINUE;
#line 550 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 125 ".\\mylexer.l"
yylval.ntnode = new node("DEFAULT");		return DEFAULT;
#line 557 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 126 ".\\mylexer.l"
yylval.ntnode = new node("DO");			return DO;
#line 564 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 127 ".\\mylexer.l"
yylval.ntnode = new node("ELSE");			return ELSE;
#line 571 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 129 ".\\mylexer.l"
yylval.ntnode = new node("GOTO");			return GOTO;
#line 578 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 130 ".\\mylexer.l"
yylval.ntnode = new node("RETURN");		return RETURN;
#line 585 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 131 ".\\mylexer.l"
yylval.ntnode = new node("REGISTER");		return REGISTER;
#line 592 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 132 ".\\mylexer.l"
yylval.ntnode = new node("SIGNED");		return SIGNED;
#line 599 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 133 ".\\mylexer.l"
yylval.ntnode = new node("UNSIGNED");	return UNSIGNED;
#line 606 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 134 ".\\mylexer.l"
yylval.ntnode = new node("SIZEOF");		return SIZEOF;
#line 613 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 135 ".\\mylexer.l"
yylval.ntnode = new node("STATIC");		return STATIC;
#line 620 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 136 ".\\mylexer.l"
yylval.ntnode = new node("STRUCT");		return STRUCT;
#line 627 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 137 ".\\mylexer.l"
yylval.ntnode = new node("SWITCH");		return SWITCH;
#line 634 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 138 ".\\mylexer.l"
yylval.ntnode = new node("TYPEDEF");		return TYPEDEF;
#line 641 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 139 ".\\mylexer.l"
yylval.ntnode = new node("UNION");			return UNION;
#line 648 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 140 ".\\mylexer.l"
yylval.ntnode = new node("VOLATILE"); 		return VOLATILE;
#line 655 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 141 ".\\mylexer.l"
yylval.ntnode = new node("WHILE");			return WHILE;
#line 662 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 142 ".\\mylexer.l"
yylval.ntnode = new node("ENUM"); 			return ENUM;
#line 669 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 143 ".\\mylexer.l"
yylval.ntnode = new node("ELLIPSIS");	    return ELLIPSIS;
#line 676 "mylexer.cpp"
		}
		break;
	case 73:
		{
#line 144 ".\\mylexer.l"
yylval.ntnode = new node("ID", yytext);	return ID;
#line 683 "mylexer.cpp"
		}
		break;
	case 74:
		{
#line 145 ".\\mylexer.l"
return -1;
#line 690 "mylexer.cpp"
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

	yytransitionmax = 445;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 4, 4 },
		{ 52, 15 },
		{ 49, 14 },
		{ 64, 27 },
		{ 114, 82 },
		{ 108, 78 },
		{ 53, 15 },
		{ 47, 12 },
		{ 74, 32 },
		{ 116, 83 },
		{ 65, 27 },
		{ 110, 79 },
		{ 117, 83 },
		{ 88, 57 },
		{ 115, 82 },
		{ 88, 57 },
		{ 75, 32 },
		{ 66, 27 },
		{ 50, 14 },
		{ 51, 14 },
		{ 54, 15 },
		{ 4, 1 },
		{ 6, 1 },
		{ 4, 4 },
		{ 109, 78 },
		{ 48, 12 },
		{ 7, 1 },
		{ 8, 1 },
		{ 111, 79 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 91, 62 },
		{ 15, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 125, 95 },
		{ 126, 95 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 92, 63 },
		{ 24, 1 },
		{ 25, 1 },
		{ 22, 1 },
		{ 93, 64 },
		{ 22, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 22, 1 },
		{ 32, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 22, 1 },
		{ 39, 1 },
		{ 40, 1 },
		{ 41, 1 },
		{ 42, 1 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 86, 86 },
		{ 71, 30 },
		{ 61, 21 },
		{ 62, 21 },
		{ 72, 30 },
		{ 119, 86 },
		{ 94, 65 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 69, 29 },
		{ 95, 66 },
		{ 70, 29 },
		{ 96, 67 },
		{ 22, 195 },
		{ 97, 68 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 22, 195 },
		{ 0, 89 },
		{ 105, 76 },
		{ 0, 89 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 87, 87 },
		{ 67, 28 },
		{ 106, 76 },
		{ 98, 69 },
		{ 58, 19 },
		{ 59, 19 },
		{ 60, 20 },
		{ 100, 70 },
		{ 101, 71 },
		{ 102, 72 },
		{ 99, 69 },
		{ 68, 28 },
		{ 57, 87 },
		{ 103, 73 },
		{ 121, 89 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 121, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 104, 75 },
		{ 73, 31 },
		{ 107, 77 },
		{ 57, 87 },
		{ 56, 169 },
		{ 121, 89 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 121, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 169 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 56, 56 },
		{ 77, 34 },
		{ 78, 34 },
		{ 44, 7 },
		{ 76, 33 },
		{ 112, 80 },
		{ 113, 81 },
		{ 63, 26 },
		{ 81, 35 },
		{ 118, 84 },
		{ 82, 36 },
		{ 83, 37 },
		{ 56, 56 },
		{ 79, 34 },
		{ 84, 38 },
		{ 148, 121 },
		{ 80, 34 },
		{ 148, 121 },
		{ 85, 40 },
		{ 122, 92 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 89, 121 },
		{ 55, 16 },
		{ 123, 93 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 124, 94 },
		{ 86, 52 },
		{ 56, 56 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 120, 88 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 169, 148 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 87, 55 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 120, 120 },
		{ 127, 96 },
		{ 128, 97 },
		{ 129, 98 },
		{ 130, 99 },
		{ 131, 100 },
		{ 132, 101 },
		{ 133, 103 },
		{ 134, 105 },
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
		{ 0, 53 },
		{ 45, 8 },
		{ 149, 122 },
		{ 150, 125 },
		{ 151, 126 },
		{ 152, 127 },
		{ 153, 128 },
		{ 154, 129 },
		{ 155, 132 },
		{ 156, 134 },
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
		{ 167, 146 },
		{ 168, 147 },
		{ 46, 11 },
		{ 170, 151 },
		{ 171, 152 },
		{ 172, 153 },
		{ 173, 154 },
		{ 174, 156 },
		{ 175, 157 },
		{ 176, 159 },
		{ 177, 160 },
		{ 178, 161 },
		{ 179, 162 },
		{ 180, 163 },
		{ 181, 164 },
		{ 182, 166 },
		{ 183, 167 },
		{ 43, 6 },
		{ 184, 170 },
		{ 185, 171 },
		{ 186, 173 },
		{ 187, 174 },
		{ 188, 181 },
		{ 189, 182 },
		{ 190, 183 },
		{ 191, 184 },
		{ 192, 186 },
		{ 193, 187 },
		{ 194, 189 },
		{ 195, 190 },
		{ 90, 58 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 74 },
		{ 0, -6, 1 },
		{ 0, 0, 4 },
		{ 0, 370, 74 },
		{ 0, 230, 74 },
		{ 0, 357, 44 },
		{ 0, 0, 8 },
		{ 0, 0, 9 },
		{ 0, 355, 43 },
		{ 0, -33, 32 },
		{ 0, 0, 7 },
		{ 0, -40, 41 },
		{ 0, -38, 42 },
		{ 87, 272, 23 },
		{ 0, 0, 6 },
		{ 0, 0, 19 },
		{ 0, 150, 24 },
		{ 0, 151, 21 },
		{ 0, 70, 25 },
		{ 195, 0, 73 },
		{ 0, 0, 12 },
		{ 0, 0, 13 },
		{ 0, 0, 47 },
		{ 195, 181, 73 },
		{ 195, -91, 73 },
		{ 195, 106, 73 },
		{ 195, 54, 73 },
		{ 195, 22, 73 },
		{ 195, 137, 73 },
		{ 195, -91, 73 },
		{ 195, 191, 73 },
		{ 195, 185, 73 },
		{ 195, 175, 73 },
		{ 195, 188, 73 },
		{ 195, 188, 73 },
		{ 195, 198, 73 },
		{ 0, 0, 10 },
		{ 0, 182, 45 },
		{ 0, 0, 11 },
		{ 0, 0, 46 },
		{ 0, 0, 30 },
		{ 0, 0, 39 },
		{ 0, 0, 48 },
		{ 0, 0, 37 },
		{ 0, 0, 35 },
		{ 0, 0, 40 },
		{ 0, 0, 36 },
		{ 0, 0, 33 },
		{ 0, 0, 34 },
		{ -52, 289, 0 },
		{ -53, 384, 3 },
		{ 0, 0, 38 },
		{ 0, 305, 0 },
		{ 169, 231, 22 },
		{ 121, -27, 22 },
		{ 0, 383, 0 },
		{ 0, 0, 26 },
		{ 0, 0, 31 },
		{ 0, 0, 27 },
		{ 0, -23, 0 },
		{ 195, -17, 73 },
		{ 195, -27, 73 },
		{ 195, 38, 73 },
		{ 195, 53, 73 },
		{ 195, 63, 73 },
		{ 195, 50, 56 },
		{ 195, 101, 73 },
		{ 195, 96, 73 },
		{ 195, 103, 73 },
		{ 195, 101, 73 },
		{ 195, 103, 73 },
		{ 195, 0, 50 },
		{ 195, 131, 73 },
		{ 195, 92, 73 },
		{ 195, 138, 73 },
		{ 195, -95, 73 },
		{ 195, -83, 73 },
		{ 195, 188, 73 },
		{ 195, 182, 73 },
		{ 195, -98, 73 },
		{ 195, -93, 73 },
		{ 195, 192, 73 },
		{ 0, 0, 49 },
		{ -52, 87, 0 },
		{ 169, 149, 23 },
		{ 0, 285, 0 },
		{ 121, 151, 22 },
		{ 0, 0, 29 },
		{ 0, 0, 28 },
		{ 195, 210, 73 },
		{ 195, 218, 73 },
		{ 195, 216, 73 },
		{ 195, -60, 73 },
		{ 195, 276, 73 },
		{ 195, 276, 73 },
		{ 195, 270, 73 },
		{ 195, 275, 73 },
		{ 195, 268, 73 },
		{ 195, 281, 73 },
		{ 195, 0, 20 },
		{ 195, 268, 73 },
		{ 195, 0, 14 },
		{ 195, 275, 73 },
		{ 195, 264, 73 },
		{ 195, 268, 73 },
		{ 195, 273, 73 },
		{ 195, 283, 73 },
		{ 195, 269, 73 },
		{ 195, 269, 73 },
		{ 195, 271, 73 },
		{ 195, 287, 73 },
		{ 195, 278, 73 },
		{ 195, 285, 73 },
		{ 195, 291, 73 },
		{ 195, 295, 73 },
		{ 195, 285, 73 },
		{ 0, 0, 2 },
		{ 169, 315, 23 },
		{ 56, 260, 22 },
		{ 195, 289, 73 },
		{ 195, 0, 52 },
		{ 195, 0, 16 },
		{ 195, 281, 73 },
		{ 195, 293, 73 },
		{ 195, 282, 73 },
		{ 195, 292, 73 },
		{ 195, 289, 73 },
		{ 195, 0, 57 },
		{ 195, 0, 71 },
		{ 195, 286, 73 },
		{ 195, 0, 58 },
		{ 195, 288, 73 },
		{ 195, 290, 73 },
		{ 195, 289, 73 },
		{ 195, 305, 73 },
		{ 195, 296, 73 },
		{ 195, 303, 73 },
		{ 195, 310, 73 },
		{ 195, 311, 73 },
		{ 195, 311, 73 },
		{ 195, 302, 73 },
		{ 195, 310, 73 },
		{ 195, 0, 5 },
		{ 195, 298, 73 },
		{ 195, 314, 73 },
		{ 0, 295, 0 },
		{ 195, 0, 51 },
		{ 195, 0, 53 },
		{ 195, 307, 73 },
		{ 195, 310, 73 },
		{ 195, 318, 73 },
		{ 195, 305, 73 },
		{ 195, 0, 15 },
		{ 195, 305, 73 },
		{ 195, 312, 73 },
		{ 195, 0, 18 },
		{ 195, 323, 73 },
		{ 195, 322, 73 },
		{ 195, 326, 73 },
		{ 195, 310, 73 },
		{ 195, 323, 73 },
		{ 195, 327, 73 },
		{ 195, 0, 68 },
		{ 195, 319, 73 },
		{ 195, 325, 73 },
		{ 195, 0, 70 },
		{ 148, 156, 0 },
		{ 195, 315, 73 },
		{ 195, 317, 73 },
		{ 195, 0, 17 },
		{ 195, 329, 73 },
		{ 195, 334, 73 },
		{ 195, 0, 59 },
		{ 195, 0, 61 },
		{ 195, 0, 63 },
		{ 195, 0, 64 },
		{ 195, 0, 65 },
		{ 195, 0, 66 },
		{ 195, 334, 73 },
		{ 195, 336, 73 },
		{ 195, 330, 73 },
		{ 195, 338, 73 },
		{ 195, 0, 55 },
		{ 195, 325, 73 },
		{ 195, 327, 73 },
		{ 195, 0, 67 },
		{ 195, 342, 73 },
		{ 195, 342, 73 },
		{ 195, 0, 54 },
		{ 195, 0, 72 },
		{ 195, 0, 60 },
		{ 195, 0, 62 },
		{ 0, 71, 69 }
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
		0
	};
	yybackup = backup;
}
#line 146 ".\\mylexer.l"
  
/////////////////////////////////////////////////////////////////////////////
// programs section
 
