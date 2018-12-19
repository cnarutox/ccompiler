/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 70 of your 30 day trial period.
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
* Date: 12/19/18
* Time: 08:54:26
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

Date:2018��10��28��
****************************************************************************/
#include <map>
#include <vector>
#include "myparser.h"
#include "stdlib.h"
int Line = 1;

extern struct typenode
{
    string name;
    typenode *left;
    typenode *right;
    typenode(string n = "")
    {
        name = n;
        left = NULL;
        right = NULL;
    }
};
extern struct varmap
{
    int name;
    varmap *parent;
    map<string, typenode*> vartable;
    varmap(int n = 0, varmap *p = NULL)
    {
        name = n;
        parent = p;
    }
};
extern varmap *varmap_temp;
extern vector<varmap*> s;
extern struct node
{
    int id;
    string name;
    double dvalue;
    int length;
    node **children;
    typenode type;
    string code;
    varmap *args;
    node(string n = "")
    {
        length = 0;
        name = n;
    }
};


void comment(string val)
{
    for (int i = 0; i < val.length(); i++)
        if (val[i] == '\n')
            Line++;
    ////cout << val << endl;
}
int sign=0;
void push_into_s(varmap *args) {
    args = new varmap(sign++, s[s.size() - 1]);
    s.push_back(args);
}

void Lex(YYSTYPE YYFAR& yylval, string s)
{
    yylval.ntnode = new node(s);
}

#line 113 "mylexer.cpp"
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
#line 88 ".\\mylexer.l"

	// place any extra initialisation code here

#line 137 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 93 ".\\mylexer.l"

	// place any extra cleanup code here

#line 149 "mylexer.cpp"
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
#line 111 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 220 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 117 ".\\mylexer.l"

#line 227 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 118 ".\\mylexer.l"

#line 234 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 119 ".\\mylexer.l"

#line 241 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 121 ".\\mylexer.l"
Line++;
#line 248 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 122 ".\\mylexer.l"
Lex(yylval, "VOID"); 			return VOID; 
#line 255 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 123 ".\\mylexer.l"
Lex(yylval, ":"); 		        return ':'; 
#line 262 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 124 ".\\mylexer.l"
Lex(yylval, ".");	            return '.';
#line 269 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 125 ".\\mylexer.l"
Lex(yylval, ","); 		        return ','; 
#line 276 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 126 ".\\mylexer.l"
Lex(yylval, "(");              push_into_s(yylval.ntnode->args);       return '('; 
#line 283 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 127 ".\\mylexer.l"
Lex(yylval, ")"); 		        s.pop_back();                                return ')'; 
#line 290 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 128 ".\\mylexer.l"
Lex(yylval, "{");              push_into_s(yylval.ntnode->args);       return '{'; 
#line 297 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 129 ".\\mylexer.l"
Lex(yylval, "}");              varmap_temp = s[s.size() - 1];     s.pop_back();   return '}'; 
#line 304 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 130 ".\\mylexer.l"
Lex(yylval, "["); 		        return '['; 
#line 311 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 131 ".\\mylexer.l"
Lex(yylval, "]"); 		        return ']'; 
#line 318 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 132 ".\\mylexer.l"
Lex(yylval, "INT"); 		    return INT; 
#line 325 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 133 ".\\mylexer.l"
Lex(yylval, "FLOAT"); 	        return FLOAT; 
#line 332 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 134 ".\\mylexer.l"
Lex(yylval, "CHAR"); 		    return CHAR; 
#line 339 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 135 ".\\mylexer.l"
Lex(yylval, "DOUBLE"); 	    return DOUBLE; 
#line 346 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 136 ".\\mylexer.l"
Lex(yylval, "SHORT"); 		    return SHORT; 
#line 353 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 137 ".\\mylexer.l"
Lex(yylval, ";"); 		        return ';'; 
#line 360 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 138 ".\\mylexer.l"
Lex(yylval, "FOR");            push_into_s(yylval.ntnode->args);       return FOR; 
#line 367 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 139 ".\\mylexer.l"
Lex(yylval, "="); 		        return '='; 
#line 374 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 140 ".\\mylexer.l"
return -1;
#line 381 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 141 ".\\mylexer.l"
Lex(yylval, yytext);           yylval.ntnode->dvalue = atof(yytext);   return CONSTANT; 
#line 388 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 142 ".\\mylexer.l"
Lex(yylval, "<");			    return '<'; 
#line 395 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 143 ".\\mylexer.l"
Lex(yylval, ">");			    return '>'; 
#line 402 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 144 ".\\mylexer.l"
Lex(yylval, "LE_OP");			return LE_OP; 
#line 409 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 145 ".\\mylexer.l"
Lex(yylval, "GE_OP");			return GE_OP; 
#line 416 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 146 ".\\mylexer.l"
Lex(yylval, "RIGHT_ASSIGN");   return RIGHT_ASSIGN; 
#line 423 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 147 ".\\mylexer.l"
Lex(yylval, "LEFT_ASSIGN");	return LEFT_ASSIGN; 
#line 430 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 148 ".\\mylexer.l"
Lex(yylval, "NE_OP");			return NE_OP; 
#line 437 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 149 ".\\mylexer.l"
Lex(yylval, "EQ_OP");			return EQ_OP; 
#line 444 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 150 ".\\mylexer.l"
Lex(yylval, "+");			    return '+'; 
#line 451 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 151 ".\\mylexer.l"
Lex(yylval, "SUB_ASSIGN");	    return SUB_ASSIGN;
#line 458 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 152 ".\\mylexer.l"
Lex(yylval, "PTR_OP"); 		return PTR_OP;
#line 465 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 153 ".\\mylexer.l"
Lex(yylval, "INC_OP"); 		return INC_OP;
#line 472 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 154 ".\\mylexer.l"
Lex(yylval, "DEC_OP"); 		return DEC_OP;
#line 479 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 155 ".\\mylexer.l"
Lex(yylval, "MUL_ASSIGN");     return MUL_ASSIGN;
#line 486 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 156 ".\\mylexer.l"
Lex(yylval, "DIV_ASSIGN");	    return DIV_ASSIGN;
#line 493 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 157 ".\\mylexer.l"
Lex(yylval, "MOD_ASSIGN");	    return MOD_ASSIGN;
#line 500 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 158 ".\\mylexer.l"
Lex(yylval, "ADD_ASSIGN");     return ADD_ASSIGN;
#line 507 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 159 ".\\mylexer.l"
Lex(yylval, "-");			    return '-'; 
#line 514 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 160 ".\\mylexer.l"
Lex(yylval, "/");			    return '/'; 
#line 521 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 161 ".\\mylexer.l"
Lex(yylval, "*");			    return '*'; 
#line 528 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 162 ".\\mylexer.l"
Lex(yylval, "&");			    return '&'; 
#line 535 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 163 ".\\mylexer.l"
Lex(yylval, "|");			    return '|'; 
#line 542 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 164 ".\\mylexer.l"
Lex(yylval, "~");			    return '~'; 
#line 549 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 165 ".\\mylexer.l"
Lex(yylval, "^");			    return '^'; 
#line 556 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 166 ".\\mylexer.l"
Lex(yylval, "AND_OP");	        return AND_OP; 
#line 563 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 167 ".\\mylexer.l"
Lex(yylval, "OR_OP");			return OR_OP; 
#line 570 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 169 ".\\mylexer.l"
Lex(yylval, "IF");              return IF; 
#line 577 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 170 ".\\mylexer.l"
Lex(yylval, "BREAK");			return BREAK;
#line 584 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 171 ".\\mylexer.l"
Lex(yylval, "CASE");			return CASE;
#line 591 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 172 ".\\mylexer.l"
Lex(yylval, "CONST");			return CONST;
#line 598 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 173 ".\\mylexer.l"
Lex(yylval, "CONTINUE");		return CONTINUE;
#line 605 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 174 ".\\mylexer.l"
Lex(yylval, "DEFAULT");		return DEFAULT;
#line 612 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 175 ".\\mylexer.l"
Lex(yylval, "DO");			    return DO;
#line 619 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 176 ".\\mylexer.l"
Lex(yylval, "ELSE");			return ELSE;
#line 626 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 178 ".\\mylexer.l"
Lex(yylval, "GOTO");			return GOTO;
#line 633 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 179 ".\\mylexer.l"
Lex(yylval, "RETURN");		    return RETURN;
#line 640 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 180 ".\\mylexer.l"
Lex(yylval, "REGISTER");		return REGISTER;
#line 647 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 181 ".\\mylexer.l"
Lex(yylval, "SIGNED");		    return SIGNED;
#line 654 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 182 ".\\mylexer.l"
Lex(yylval, "UNSIGNED");	    return UNSIGNED;
#line 661 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 183 ".\\mylexer.l"
Lex(yylval, "SIZEOF");		    return SIZEOF;
#line 668 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 184 ".\\mylexer.l"
Lex(yylval, "STATIC");		    return STATIC;
#line 675 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 185 ".\\mylexer.l"
Lex(yylval, "STRUCT");		    push_into_s(yylval.ntnode->args);       return STRUCT;
#line 682 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 186 ".\\mylexer.l"
Lex(yylval, "SWITCH");		    return SWITCH;
#line 689 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 187 ".\\mylexer.l"
Lex(yylval, "TYPEDEF");		return TYPEDEF;
#line 696 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 188 ".\\mylexer.l"
Lex(yylval, "UNION");			return UNION;
#line 703 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 189 ".\\mylexer.l"
Lex(yylval, "VOLATILE"); 		return VOLATILE;
#line 710 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 190 ".\\mylexer.l"
Lex(yylval, "WHILE");          push_into_s(yylval.ntnode->args);  return WHILE;
#line 717 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 191 ".\\mylexer.l"
Lex(yylval, "ENUM"); 			return ENUM;
#line 724 "mylexer.cpp"
		}
		break;
	case 73:
		{
#line 192 ".\\mylexer.l"
Lex(yylval, "ELLIPSIS");	    return ELLIPSIS;
#line 731 "mylexer.cpp"
		}
		break;
	case 74:
		{
#line 193 ".\\mylexer.l"
Lex(yylval, yytext);	        return ID;
#line 738 "mylexer.cpp"
		}
		break;
	case 75:
		{
#line 194 ".\\mylexer.l"
return -1;
#line 745 "mylexer.cpp"
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
#line 195 ".\\mylexer.l"
  
/////////////////////////////////////////////////////////////////////////////
// programs section

