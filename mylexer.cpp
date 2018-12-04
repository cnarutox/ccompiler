/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 56 of your 30 day trial period.
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
* Time: 02:44:48
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
#line 73 ".\\mylexer.l"
Line++;
#line 186 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 74 ".\\mylexer.l"
yylval.ntnode = new node("VOID"); 			return VOID; 
#line 193 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 75 ".\\mylexer.l"
yylval.ntnode = new node(":"); 		return ':'; 
#line 200 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 76 ".\\mylexer.l"
yylval.ntnode = new node(","); 		return ','; 
#line 207 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 77 ".\\mylexer.l"
yylval.ntnode = new node("("); 		return '('; 
#line 214 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 78 ".\\mylexer.l"
yylval.ntnode = new node(")"); 		return ')'; 
#line 221 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 79 ".\\mylexer.l"
yylval.ntnode = new node("{"); 		return '{'; 
#line 228 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 80 ".\\mylexer.l"
yylval.ntnode = new node("}"); 		return '}'; 
#line 235 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 81 ".\\mylexer.l"
yylval.ntnode = new node("["); 		return '['; 
#line 242 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 82 ".\\mylexer.l"
yylval.ntnode = new node("]"); 		return ']'; 
#line 249 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 83 ".\\mylexer.l"
yylval.ntnode = new node("INT"); 			return INT; 
#line 256 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 84 ".\\mylexer.l"
yylval.ntnode = new node("FLOAT"); 		return FLOAT; 
#line 263 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 85 ".\\mylexer.l"
yylval.ntnode = new node("CHAR"); 		return CHAR; 
#line 270 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 86 ".\\mylexer.l"
yylval.ntnode = new node("DOUBLE"); 		return DOUBLE; 
#line 277 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 87 ".\\mylexer.l"
yylval.ntnode = new node("SHORT"); 		return SHORT; 
#line 284 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 88 ".\\mylexer.l"
yylval.ntnode = new node(";"); 		return ';'; 
#line 291 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 89 ".\\mylexer.l"
yylval.ntnode = new node("FOR"); 			return FOR; 
#line 298 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 90 ".\\mylexer.l"
yylval.ntnode = new node("="); 		return '='; 
#line 305 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 91 ".\\mylexer.l"
return -1;
#line 312 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 92 ".\\mylexer.l"
yylval.ntnode = new node("CONSTANT", yytext);	return CONSTANT; 
#line 319 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 93 ".\\mylexer.l"
yylval.ntnode = new node("<");			return '<'; 
#line 326 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 94 ".\\mylexer.l"
yylval.ntnode = new node(">");			return '>'; 
#line 333 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 95 ".\\mylexer.l"
yylval.ntnode = new node("LE_OP");			return LE_OP; 
#line 340 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 96 ".\\mylexer.l"
yylval.ntnode = new node("GE_OP");			return GE_OP; 
#line 347 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 97 ".\\mylexer.l"
yylval.ntnode = new node("RIGHT_ASSIGN");return RIGHT_ASSIGN; 
#line 354 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 98 ".\\mylexer.l"
yylval.ntnode = new node("LEFT_ASSIGN");		return LEFT_ASSIGN; 
#line 361 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 99 ".\\mylexer.l"
yylval.ntnode = new node("NE_OP");			return NE_OP; 
#line 368 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 100 ".\\mylexer.l"
yylval.ntnode = new node("EQ_OP");			return EQ_OP; 
#line 375 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 101 ".\\mylexer.l"
yylval.ntnode = new node("+");			return '+'; 
#line 382 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 102 ".\\mylexer.l"
yylval.ntnode = new node("SUB_ASSIGN");	return SUB_ASSIGN;
#line 389 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 103 ".\\mylexer.l"
yylval.ntnode = new node("PTR_OP"); 		return PTR_OP;
#line 396 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 104 ".\\mylexer.l"
yylval.ntnode = new node("INC_OP"); 		return INC_OP;
#line 403 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 105 ".\\mylexer.l"
yylval.ntnode = new node("DEC_OP"); 		return DEC_OP;
#line 410 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 106 ".\\mylexer.l"
yylval.ntnode = new node("MUL_ASSIGN");	return MUL_ASSIGN;
#line 417 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 107 ".\\mylexer.l"
yylval.ntnode = new node("DIV_ASSIGN");	return DIV_ASSIGN;
#line 424 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 108 ".\\mylexer.l"
yylval.ntnode = new node("MOD_ASSIGN");	return MOD_ASSIGN;
#line 431 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 109 ".\\mylexer.l"
yylval.ntnode = new node("ADD_ASSIGN");    return ADD_ASSIGN;
#line 438 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 110 ".\\mylexer.l"
yylval.ntnode = new node("-");			return '-'; 
#line 445 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 111 ".\\mylexer.l"
yylval.ntnode = new node("/");			return '/'; 
#line 452 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 112 ".\\mylexer.l"
yylval.ntnode = new node("*");			return '*'; 
#line 459 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 113 ".\\mylexer.l"
yylval.ntnode = new node("&");			return '&'; 
#line 466 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 114 ".\\mylexer.l"
yylval.ntnode = new node("|");			return '|'; 
#line 473 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 115 ".\\mylexer.l"
yylval.ntnode = new node("~");			return '~'; 
#line 480 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 116 ".\\mylexer.l"
yylval.ntnode = new node("^");			return '^'; 
#line 487 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 117 ".\\mylexer.l"
yylval.ntnode = new node("AND_OP");	return AND_OP; 
#line 494 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 118 ".\\mylexer.l"
yylval.ntnode = new node("OR_OP");			return OR_OP; 
#line 501 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 120 ".\\mylexer.l"
yylval.ntnode = new node("IF");			return IF; 
#line 508 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 121 ".\\mylexer.l"
yylval.ntnode = new node("BREAK");			return BREAK;
#line 515 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 122 ".\\mylexer.l"
yylval.ntnode = new node("CASE");			return CASE;
#line 522 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 123 ".\\mylexer.l"
yylval.ntnode = new node("CONST");			return CONST;
#line 529 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 124 ".\\mylexer.l"
yylval.ntnode = new node("CONTINUE");		return CONTINUE;
#line 536 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 125 ".\\mylexer.l"
yylval.ntnode = new node("DEFAULT");		return DEFAULT;
#line 543 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 126 ".\\mylexer.l"
yylval.ntnode = new node("DO");			return DO;
#line 550 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 127 ".\\mylexer.l"
yylval.ntnode = new node("ELSE");			return ELSE;
#line 557 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 129 ".\\mylexer.l"
yylval.ntnode = new node("GOTO");			return GOTO;
#line 564 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 130 ".\\mylexer.l"
yylval.ntnode = new node("RETURN");		return RETURN;
#line 571 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 131 ".\\mylexer.l"
yylval.ntnode = new node("REGISTER");		return REGISTER;
#line 578 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 132 ".\\mylexer.l"
yylval.ntnode = new node("SIGNED");		return SIGNED;
#line 585 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 133 ".\\mylexer.l"
yylval.ntnode = new node("UNSIGNED");	return UNSIGNED;
#line 592 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 134 ".\\mylexer.l"
yylval.ntnode = new node("SIZEOF");		return SIZEOF;
#line 599 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 135 ".\\mylexer.l"
yylval.ntnode = new node("STATIC");		return STATIC;
#line 606 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 136 ".\\mylexer.l"
yylval.ntnode = new node("STRUCT");		return STRUCT;
#line 613 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 137 ".\\mylexer.l"
yylval.ntnode = new node("SWITCH");		return SWITCH;
#line 620 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 138 ".\\mylexer.l"
yylval.ntnode = new node("TYPEDEF");		return TYPEDEF;
#line 627 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 139 ".\\mylexer.l"
yylval.ntnode = new node("UNION");			return UNION;
#line 634 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 140 ".\\mylexer.l"
yylval.ntnode = new node("VOLATILE"); 		return VOLATILE;
#line 641 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 141 ".\\mylexer.l"
yylval.ntnode = new node("WHILE");			return WHILE;
#line 648 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 142 ".\\mylexer.l"
yylval.ntnode = new node("ENUM"); 			return ENUM;
#line 655 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 143 ".\\mylexer.l"
yylval.ntnode = new node("ELLIPSIS");	    return ELLIPSIS;
#line 662 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 144 ".\\mylexer.l"
yylval.ntnode = new node("ID", yytext);	return ID;
#line 669 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 145 ".\\mylexer.l"
return -1;
#line 676 "mylexer.cpp"
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

	yytransitionmax = 439;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 4, 4 },
		{ 105, 76 },
		{ 49, 14 },
		{ 62, 27 },
		{ 111, 80 },
		{ 72, 32 },
		{ 47, 12 },
		{ 88, 60 },
		{ 107, 77 },
		{ 95, 67 },
		{ 63, 27 },
		{ 121, 92 },
		{ 122, 92 },
		{ 73, 32 },
		{ 112, 80 },
		{ 102, 74 },
		{ 96, 67 },
		{ 64, 27 },
		{ 50, 14 },
		{ 51, 14 },
		{ 106, 76 },
		{ 4, 1 },
		{ 6, 1 },
		{ 4, 4 },
		{ 48, 12 },
		{ 108, 77 },
		{ 7, 1 },
		{ 8, 1 },
		{ 103, 74 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 89, 61 },
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
		{ 56, 19 },
		{ 57, 19 },
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
		{ 90, 62 },
		{ 24, 1 },
		{ 25, 1 },
		{ 22, 1 },
		{ 91, 63 },
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
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 69, 30 },
		{ 113, 81 },
		{ 92, 64 },
		{ 70, 30 },
		{ 114, 81 },
		{ 59, 21 },
		{ 60, 21 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 67, 29 },
		{ 85, 55 },
		{ 68, 29 },
		{ 85, 55 },
		{ 22, 191 },
		{ 93, 65 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 22, 191 },
		{ 0, 86 },
		{ 94, 66 },
		{ 0, 86 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 84, 84 },
		{ 65, 28 },
		{ 45, 8 },
		{ 97, 68 },
		{ 98, 69 },
		{ 99, 70 },
		{ 100, 71 },
		{ 101, 73 },
		{ 46, 11 },
		{ 104, 75 },
		{ 71, 31 },
		{ 66, 28 },
		{ 55, 84 },
		{ 58, 20 },
		{ 117, 86 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 117, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 109, 78 },
		{ 110, 79 },
		{ 74, 33 },
		{ 55, 84 },
		{ 54, 165 },
		{ 117, 86 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 117, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 165 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 75, 34 },
		{ 76, 34 },
		{ 43, 6 },
		{ 115, 82 },
		{ 79, 35 },
		{ 80, 36 },
		{ 81, 37 },
		{ 118, 89 },
		{ 119, 90 },
		{ 120, 91 },
		{ 82, 38 },
		{ 54, 54 },
		{ 77, 34 },
		{ 123, 93 },
		{ 144, 117 },
		{ 78, 34 },
		{ 144, 117 },
		{ 124, 94 },
		{ 125, 95 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 86, 117 },
		{ 53, 16 },
		{ 126, 96 },
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
		{ 127, 97 },
		{ 128, 98 },
		{ 54, 54 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 116, 85 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 165, 144 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 84, 53 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 129, 100 },
		{ 130, 102 },
		{ 131, 103 },
		{ 132, 104 },
		{ 133, 105 },
		{ 134, 106 },
		{ 135, 107 },
		{ 136, 108 },
		{ 137, 109 },
		{ 138, 110 },
		{ 139, 111 },
		{ 140, 112 },
		{ 141, 113 },
		{ 142, 114 },
		{ 143, 115 },
		{ 83, 40 },
		{ 61, 26 },
		{ 145, 118 },
		{ 146, 121 },
		{ 147, 122 },
		{ 148, 123 },
		{ 149, 124 },
		{ 150, 125 },
		{ 151, 128 },
		{ 152, 130 },
		{ 153, 131 },
		{ 154, 132 },
		{ 155, 133 },
		{ 156, 134 },
		{ 157, 135 },
		{ 158, 136 },
		{ 159, 137 },
		{ 160, 138 },
		{ 161, 139 },
		{ 162, 140 },
		{ 163, 142 },
		{ 164, 143 },
		{ 44, 7 },
		{ 166, 147 },
		{ 167, 148 },
		{ 168, 149 },
		{ 169, 150 },
		{ 170, 152 },
		{ 171, 153 },
		{ 172, 155 },
		{ 173, 156 },
		{ 174, 157 },
		{ 175, 158 },
		{ 176, 159 },
		{ 177, 160 },
		{ 178, 162 },
		{ 179, 163 },
		{ 52, 15 },
		{ 180, 166 },
		{ 181, 167 },
		{ 182, 169 },
		{ 183, 170 },
		{ 184, 177 },
		{ 185, 178 },
		{ 186, 179 },
		{ 187, 180 },
		{ 188, 182 },
		{ 189, 183 },
		{ 190, 185 },
		{ 191, 186 },
		{ 87, 56 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 72 },
		{ 0, -6, 1 },
		{ 0, 0, 2 },
		{ 0, 230, 72 },
		{ 0, 349, 72 },
		{ 0, 170, 42 },
		{ 0, 0, 6 },
		{ 0, 0, 7 },
		{ 0, 153, 41 },
		{ 0, -34, 30 },
		{ 0, 0, 5 },
		{ 0, -40, 39 },
		{ 0, 364, 40 },
		{ 84, 272, 21 },
		{ 0, 0, 4 },
		{ 0, 0, 17 },
		{ 0, -5, 22 },
		{ 0, 158, 19 },
		{ 0, 73, 23 },
		{ 191, 0, 71 },
		{ 0, 0, 10 },
		{ 0, 0, 11 },
		{ 0, 0, 45 },
		{ 191, 275, 71 },
		{ 191, -91, 71 },
		{ 191, 106, 71 },
		{ 191, 54, 71 },
		{ 191, 21, 71 },
		{ 191, 105, 71 },
		{ 191, -94, 71 },
		{ 191, 148, 71 },
		{ 191, 185, 71 },
		{ 191, 172, 71 },
		{ 191, 184, 71 },
		{ 191, 184, 71 },
		{ 191, 195, 71 },
		{ 0, 0, 8 },
		{ 0, 264, 43 },
		{ 0, 0, 9 },
		{ 0, 0, 44 },
		{ 0, 0, 28 },
		{ 0, 0, 37 },
		{ 0, 0, 46 },
		{ 0, 0, 35 },
		{ 0, 0, 33 },
		{ 0, 0, 38 },
		{ 0, 0, 34 },
		{ 0, 0, 31 },
		{ 0, 0, 32 },
		{ 0, 0, 36 },
		{ 0, 305, 0 },
		{ 165, 231, 20 },
		{ 117, 120, 20 },
		{ 0, 377, 0 },
		{ 0, 0, 24 },
		{ 0, 0, 29 },
		{ 0, 0, 25 },
		{ 0, -51, 0 },
		{ 191, -63, 71 },
		{ 191, -31, 71 },
		{ 191, -9, 71 },
		{ 191, 21, 71 },
		{ 191, 65, 71 },
		{ 191, 78, 54 },
		{ 191, -96, 71 },
		{ 191, 92, 71 },
		{ 191, 99, 71 },
		{ 191, 97, 71 },
		{ 191, 96, 71 },
		{ 191, 0, 48 },
		{ 191, 97, 71 },
		{ 191, -85, 71 },
		{ 191, 104, 71 },
		{ 191, -99, 71 },
		{ 191, -86, 71 },
		{ 191, 142, 71 },
		{ 191, 136, 71 },
		{ 191, -98, 71 },
		{ 191, 25, 71 },
		{ 191, 187, 71 },
		{ 0, 0, 47 },
		{ 165, 149, 21 },
		{ 0, 285, 0 },
		{ 117, 151, 20 },
		{ 0, 0, 27 },
		{ 0, 0, 26 },
		{ 191, 199, 71 },
		{ 191, 196, 71 },
		{ 191, 184, 71 },
		{ 191, -101, 71 },
		{ 191, 205, 71 },
		{ 191, 208, 71 },
		{ 191, 202, 71 },
		{ 191, 218, 71 },
		{ 191, 221, 71 },
		{ 191, 234, 71 },
		{ 191, 0, 18 },
		{ 191, 262, 71 },
		{ 191, 0, 12 },
		{ 191, 269, 71 },
		{ 191, 258, 71 },
		{ 191, 262, 71 },
		{ 191, 267, 71 },
		{ 191, 277, 71 },
		{ 191, 263, 71 },
		{ 191, 263, 71 },
		{ 191, 265, 71 },
		{ 191, 281, 71 },
		{ 191, 272, 71 },
		{ 191, 279, 71 },
		{ 191, 285, 71 },
		{ 191, 289, 71 },
		{ 191, 279, 71 },
		{ 165, 315, 21 },
		{ 54, 260, 20 },
		{ 191, 283, 71 },
		{ 191, 0, 50 },
		{ 191, 0, 14 },
		{ 191, 275, 71 },
		{ 191, 287, 71 },
		{ 191, 276, 71 },
		{ 191, 286, 71 },
		{ 191, 283, 71 },
		{ 191, 0, 55 },
		{ 191, 0, 69 },
		{ 191, 280, 71 },
		{ 191, 0, 56 },
		{ 191, 282, 71 },
		{ 191, 284, 71 },
		{ 191, 283, 71 },
		{ 191, 299, 71 },
		{ 191, 290, 71 },
		{ 191, 297, 71 },
		{ 191, 304, 71 },
		{ 191, 305, 71 },
		{ 191, 305, 71 },
		{ 191, 296, 71 },
		{ 191, 304, 71 },
		{ 191, 0, 3 },
		{ 191, 292, 71 },
		{ 191, 308, 71 },
		{ 0, 295, 0 },
		{ 191, 0, 49 },
		{ 191, 0, 51 },
		{ 191, 301, 71 },
		{ 191, 304, 71 },
		{ 191, 312, 71 },
		{ 191, 299, 71 },
		{ 191, 0, 13 },
		{ 191, 299, 71 },
		{ 191, 306, 71 },
		{ 191, 0, 16 },
		{ 191, 317, 71 },
		{ 191, 316, 71 },
		{ 191, 320, 71 },
		{ 191, 304, 71 },
		{ 191, 317, 71 },
		{ 191, 321, 71 },
		{ 191, 0, 66 },
		{ 191, 313, 71 },
		{ 191, 319, 71 },
		{ 191, 0, 68 },
		{ 144, 156, 0 },
		{ 191, 309, 71 },
		{ 191, 311, 71 },
		{ 191, 0, 15 },
		{ 191, 323, 71 },
		{ 191, 328, 71 },
		{ 191, 0, 57 },
		{ 191, 0, 59 },
		{ 191, 0, 61 },
		{ 191, 0, 62 },
		{ 191, 0, 63 },
		{ 191, 0, 64 },
		{ 191, 328, 71 },
		{ 191, 330, 71 },
		{ 191, 324, 71 },
		{ 191, 332, 71 },
		{ 191, 0, 53 },
		{ 191, 319, 71 },
		{ 191, 321, 71 },
		{ 191, 0, 65 },
		{ 191, 336, 71 },
		{ 191, 336, 71 },
		{ 191, 0, 52 },
		{ 191, 0, 70 },
		{ 191, 0, 58 },
		{ 191, 0, 60 },
		{ 0, 71, 67 }
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
		0
	};
	yybackup = backup;
}
#line 146 ".\\mylexer.l"
  
/////////////////////////////////////////////////////////////////////////////
// programs section
 
