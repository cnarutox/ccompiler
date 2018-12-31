/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 42 of your 30 day trial period.
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
* Date: 12/31/18
* Time: 21:09:57
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
extern int offset;
extern struct typenode
{
    int addr;
    int width;
    string name;
    typenode *left;
    typenode *right;
    typenode(string n = "", int w = 0)
    {
        name = n;
        left = NULL;
        right = NULL;
        width = w;
        addr = offset;
        // cout << endl << "------------------offset:" << offset <<"-----------------"<<endl;
    }
    void copy(const typenode &type)
    {
        name = type.name;
        width = type.width;
        left = type.left;
        right = type.right;
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
    varmap *args;
    int instr;
    vector<int>* nextlist;
    vector<int>* falselist;
    vector<int>* truelist;
    node(string n = "")
    {
        length = 0;
        name = n;
        nextlist = new vector<int>();
        falselist = new vector<int>();
        truelist = new vector<int>();
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

#line 131 "mylexer.cpp"
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
#line 106 ".\\mylexer.l"

	// place any extra initialisation code here

#line 155 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 111 ".\\mylexer.l"

	// place any extra cleanup code here

#line 167 "mylexer.cpp"
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
#line 129 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 238 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 135 ".\\mylexer.l"

#line 245 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 136 ".\\mylexer.l"

#line 252 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 137 ".\\mylexer.l"

#line 259 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 139 ".\\mylexer.l"
Line++;
#line 266 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 140 ".\\mylexer.l"
Lex(yylval, "VOID"); 			return VOID; 
#line 273 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 141 ".\\mylexer.l"
Lex(yylval, ":"); 		        return ':'; 
#line 280 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 142 ".\\mylexer.l"
Lex(yylval, ".");	            return '.';
#line 287 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 143 ".\\mylexer.l"
Lex(yylval, ","); 		        return ','; 
#line 294 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 144 ".\\mylexer.l"
Lex(yylval, "(");              push_into_s(yylval.ntnode->args);       return '('; 
#line 301 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 145 ".\\mylexer.l"
Lex(yylval, ")"); 		        return ')'; 
#line 308 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 146 ".\\mylexer.l"
Lex(yylval, "{");              push_into_s(yylval.ntnode->args);       return '{'; 
#line 315 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 147 ".\\mylexer.l"
Lex(yylval, "}");              varmap_temp = s[s.size() - 1];     s.pop_back();   return '}'; 
#line 322 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 148 ".\\mylexer.l"
Lex(yylval, "["); 		        return '['; 
#line 329 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 149 ".\\mylexer.l"
Lex(yylval, "]"); 		        return ']'; 
#line 336 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 150 ".\\mylexer.l"
Lex(yylval, "INT"); 		    return INT; 
#line 343 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 151 ".\\mylexer.l"
Lex(yylval, "FLOAT"); 	        return FLOAT; 
#line 350 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 152 ".\\mylexer.l"
Lex(yylval, "CHAR"); 		    return CHAR; 
#line 357 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 153 ".\\mylexer.l"
Lex(yylval, "DOUBLE"); 	    return DOUBLE; 
#line 364 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 154 ".\\mylexer.l"
Lex(yylval, "SHORT"); 		    return SHORT; 
#line 371 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 155 ".\\mylexer.l"
Lex(yylval, ";"); 		        return ';'; 
#line 378 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 156 ".\\mylexer.l"
Lex(yylval, "FOR");            push_into_s(yylval.ntnode->args);       return FOR; 
#line 385 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 157 ".\\mylexer.l"
Lex(yylval, "="); 		        return '='; 
#line 392 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 158 ".\\mylexer.l"
return -1;
#line 399 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 159 ".\\mylexer.l"
Lex(yylval, yytext);           yylval.ntnode->dvalue = atof(yytext);   return CONSTANT; 
#line 406 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 160 ".\\mylexer.l"
Lex(yylval, "<");			    return '<'; 
#line 413 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 161 ".\\mylexer.l"
Lex(yylval, ">");			    return '>'; 
#line 420 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 162 ".\\mylexer.l"
Lex(yylval, "LE_OP");			return LE_OP; 
#line 427 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 163 ".\\mylexer.l"
Lex(yylval, "GE_OP");			return GE_OP; 
#line 434 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 164 ".\\mylexer.l"
Lex(yylval, "AND_ASSIGN");     return AND_ASSIGN; 
#line 441 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 165 ".\\mylexer.l"
Lex(yylval, "OR_ASSIGN");      return OR_ASSIGN; 
#line 448 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 166 ".\\mylexer.l"
Lex(yylval, "XOR_ASSIGN");     return XOR_ASSIGN; 
#line 455 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 167 ".\\mylexer.l"
Lex(yylval, "RIGHT_ASSIGN");   return RIGHT_ASSIGN; 
#line 462 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 168 ".\\mylexer.l"
Lex(yylval, "LEFT_ASSIGN");	return LEFT_ASSIGN; 
#line 469 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 169 ".\\mylexer.l"
Lex(yylval, "NE_OP");			return NE_OP; 
#line 476 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 170 ".\\mylexer.l"
Lex(yylval, "EQ_OP");			return EQ_OP; 
#line 483 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 171 ".\\mylexer.l"
Lex(yylval, "+");			    return '+'; 
#line 490 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 172 ".\\mylexer.l"
Lex(yylval, "%");			    return '%'; 
#line 497 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 173 ".\\mylexer.l"
Lex(yylval, "SUB_ASSIGN");	    return SUB_ASSIGN;
#line 504 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 174 ".\\mylexer.l"
Lex(yylval, "PTR_OP"); 		return PTR_OP;
#line 511 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 175 ".\\mylexer.l"
Lex(yylval, "INC_OP"); 		return INC_OP;
#line 518 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 176 ".\\mylexer.l"
Lex(yylval, "DEC_OP"); 		return DEC_OP;
#line 525 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 177 ".\\mylexer.l"
Lex(yylval, "MUL_ASSIGN");     return MUL_ASSIGN;
#line 532 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 178 ".\\mylexer.l"
Lex(yylval, "DIV_ASSIGN");	    return DIV_ASSIGN;
#line 539 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 179 ".\\mylexer.l"
Lex(yylval, "MOD_ASSIGN");	    return MOD_ASSIGN;
#line 546 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 180 ".\\mylexer.l"
Lex(yylval, "ADD_ASSIGN");     return ADD_ASSIGN;
#line 553 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 181 ".\\mylexer.l"
Lex(yylval, "-");			    return '-'; 
#line 560 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 182 ".\\mylexer.l"
Lex(yylval, "/");			    return '/'; 
#line 567 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 183 ".\\mylexer.l"
Lex(yylval, "*");			    return '*'; 
#line 574 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 184 ".\\mylexer.l"
Lex(yylval, "&");			    return '&'; 
#line 581 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 185 ".\\mylexer.l"
Lex(yylval, "|");			    return '|'; 
#line 588 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 186 ".\\mylexer.l"
Lex(yylval, "~");			    return '~'; 
#line 595 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 187 ".\\mylexer.l"
Lex(yylval, "^");			    return '^'; 
#line 602 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 188 ".\\mylexer.l"
Lex(yylval, "AND_OP");	        return AND_OP; 
#line 609 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 189 ".\\mylexer.l"
Lex(yylval, "OR_OP");			return OR_OP; 
#line 616 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 190 ".\\mylexer.l"
Lex(yylval, "!");			    return '!';
#line 623 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 191 ".\\mylexer.l"
Lex(yylval, "IF");             return IF; 
#line 630 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 192 ".\\mylexer.l"
Lex(yylval, "BREAK");			return BREAK;
#line 637 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 193 ".\\mylexer.l"
Lex(yylval, "CASE");			return CASE;
#line 644 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 194 ".\\mylexer.l"
Lex(yylval, "CONST");			return CONST;
#line 651 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 195 ".\\mylexer.l"
Lex(yylval, "CONTINUE");		return CONTINUE;
#line 658 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 196 ".\\mylexer.l"
Lex(yylval, "DEFAULT");		return DEFAULT;
#line 665 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 197 ".\\mylexer.l"
Lex(yylval, "DO");			    return DO;
#line 672 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 198 ".\\mylexer.l"
Lex(yylval, "ELSE");			return ELSE;
#line 679 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 200 ".\\mylexer.l"
Lex(yylval, "GOTO");			return GOTO;
#line 686 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 201 ".\\mylexer.l"
Lex(yylval, "RETURN");		    return RETURN;
#line 693 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 202 ".\\mylexer.l"
Lex(yylval, "REGISTER");		return REGISTER;
#line 700 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 203 ".\\mylexer.l"
Lex(yylval, "SIGNED");		    return SIGNED;
#line 707 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 204 ".\\mylexer.l"
Lex(yylval, "UNSIGNED");	    return UNSIGNED;
#line 714 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 205 ".\\mylexer.l"
Lex(yylval, "SIZEOF");		    return SIZEOF;
#line 721 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 206 ".\\mylexer.l"
Lex(yylval, "STATIC");		    return STATIC;
#line 728 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 207 ".\\mylexer.l"
Lex(yylval, "STRUCT");		    return STRUCT;
#line 735 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 208 ".\\mylexer.l"
Lex(yylval, "SWITCH");		    return SWITCH;
#line 742 "mylexer.cpp"
		}
		break;
	case 73:
		{
#line 209 ".\\mylexer.l"
Lex(yylval, "TYPEDEF");		return TYPEDEF;
#line 749 "mylexer.cpp"
		}
		break;
	case 74:
		{
#line 210 ".\\mylexer.l"
Lex(yylval, "UNION");			return UNION;
#line 756 "mylexer.cpp"
		}
		break;
	case 75:
		{
#line 211 ".\\mylexer.l"
Lex(yylval, "VOLATILE"); 		return VOLATILE;
#line 763 "mylexer.cpp"
		}
		break;
	case 76:
		{
#line 212 ".\\mylexer.l"
Lex(yylval, "WHILE");          push_into_s(yylval.ntnode->args);  return WHILE;
#line 770 "mylexer.cpp"
		}
		break;
	case 77:
		{
#line 213 ".\\mylexer.l"
Lex(yylval, "ENUM"); 			return ENUM;
#line 777 "mylexer.cpp"
		}
		break;
	case 78:
		{
#line 214 ".\\mylexer.l"
Lex(yylval, "ELLIPSIS");	    return ELLIPSIS;
#line 784 "mylexer.cpp"
		}
		break;
	case 79:
		{
#line 215 ".\\mylexer.l"
Lex(yylval, "TRUE");	    return TRUE;
#line 791 "mylexer.cpp"
		}
		break;
	case 80:
		{
#line 216 ".\\mylexer.l"
Lex(yylval, "FALSE");	    return FALSE;
#line 798 "mylexer.cpp"
		}
		break;
	case 81:
		{
#line 217 ".\\mylexer.l"
Lex(yylval, yytext);	        return ID;
#line 805 "mylexer.cpp"
		}
		break;
	case 82:
		{
#line 218 ".\\mylexer.l"
return -1;
#line 812 "mylexer.cpp"
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

	yytransitionmax = 456;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 4, 4 },
		{ 46, 8 },
		{ 49, 12 },
		{ 74, 31 },
		{ 81, 35 },
		{ 82, 35 },
		{ 54, 16 },
		{ 78, 33 },
		{ 92, 92 },
		{ 115, 82 },
		{ 94, 59 },
		{ 55, 16 },
		{ 94, 59 },
		{ 127, 92 },
		{ 75, 31 },
		{ 79, 33 },
		{ 83, 35 },
		{ 76, 31 },
		{ 90, 41 },
		{ 84, 35 },
		{ 50, 12 },
		{ 4, 1 },
		{ 6, 1 },
		{ 4, 4 },
		{ 47, 8 },
		{ 56, 16 },
		{ 7, 1 },
		{ 8, 1 },
		{ 116, 82 },
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
		{ 133, 101 },
		{ 134, 101 },
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
		{ 91, 41 },
		{ 25, 1 },
		{ 26, 1 },
		{ 23, 1 },
		{ 99, 67 },
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
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 124, 88 },
		{ 100, 68 },
		{ 72, 30 },
		{ 125, 88 },
		{ 73, 30 },
		{ 63, 22 },
		{ 64, 22 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 60, 20 },
		{ 61, 20 },
		{ 101, 69 },
		{ 102, 70 },
		{ 23, 206 },
		{ 103, 71 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 23, 206 },
		{ 0, 95 },
		{ 51, 14 },
		{ 0, 95 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 122, 87 },
		{ 85, 36 },
		{ 70, 29 },
		{ 65, 26 },
		{ 52, 14 },
		{ 53, 14 },
		{ 106, 73 },
		{ 107, 74 },
		{ 86, 36 },
		{ 108, 75 },
		{ 123, 87 },
		{ 59, 93 },
		{ 71, 29 },
		{ 129, 95 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 129, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 109, 76 },
		{ 110, 77 },
		{ 111, 79 },
		{ 59, 93 },
		{ 58, 180 },
		{ 129, 95 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 129, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 180 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 58, 58 },
		{ 117, 83 },
		{ 112, 80 },
		{ 67, 28 },
		{ 104, 72 },
		{ 80, 34 },
		{ 114, 81 },
		{ 66, 27 },
		{ 45, 7 },
		{ 119, 84 },
		{ 68, 28 },
		{ 105, 72 },
		{ 58, 58 },
		{ 120, 85 },
		{ 158, 129 },
		{ 113, 80 },
		{ 158, 129 },
		{ 69, 28 },
		{ 118, 83 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 95, 129 },
		{ 57, 17 },
		{ 121, 86 },
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
		{ 87, 37 },
		{ 88, 38 },
		{ 126, 89 },
		{ 58, 58 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 128, 94 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 180, 158 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 93, 57 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 128, 128 },
		{ 89, 39 },
		{ 44, 6 },
		{ 92, 54 },
		{ 0, 55 },
		{ 130, 98 },
		{ 131, 99 },
		{ 132, 100 },
		{ 62, 21 },
		{ 135, 102 },
		{ 136, 103 },
		{ 137, 104 },
		{ 138, 105 },
		{ 139, 106 },
		{ 140, 107 },
		{ 141, 108 },
		{ 142, 110 },
		{ 143, 112 },
		{ 144, 113 },
		{ 145, 114 },
		{ 146, 115 },
		{ 147, 116 },
		{ 148, 117 },
		{ 149, 118 },
		{ 150, 119 },
		{ 151, 120 },
		{ 152, 121 },
		{ 153, 122 },
		{ 154, 123 },
		{ 155, 124 },
		{ 156, 125 },
		{ 157, 126 },
		{ 48, 11 },
		{ 77, 32 },
		{ 159, 130 },
		{ 160, 133 },
		{ 161, 134 },
		{ 162, 135 },
		{ 163, 136 },
		{ 164, 137 },
		{ 165, 140 },
		{ 166, 141 },
		{ 167, 143 },
		{ 168, 144 },
		{ 169, 145 },
		{ 170, 146 },
		{ 171, 147 },
		{ 172, 148 },
		{ 173, 149 },
		{ 174, 150 },
		{ 175, 152 },
		{ 176, 153 },
		{ 177, 154 },
		{ 178, 156 },
		{ 179, 157 },
		{ 96, 60 },
		{ 181, 161 },
		{ 182, 162 },
		{ 183, 163 },
		{ 184, 164 },
		{ 185, 167 },
		{ 186, 168 },
		{ 187, 170 },
		{ 188, 171 },
		{ 189, 172 },
		{ 190, 173 },
		{ 191, 174 },
		{ 192, 175 },
		{ 193, 177 },
		{ 194, 178 },
		{ 97, 64 },
		{ 195, 181 },
		{ 196, 182 },
		{ 197, 184 },
		{ 198, 185 },
		{ 199, 192 },
		{ 200, 193 },
		{ 201, 194 },
		{ 202, 195 },
		{ 203, 197 },
		{ 204, 198 },
		{ 205, 200 },
		{ 206, 201 },
		{ 98, 66 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 82 },
		{ 0, -6, 1 },
		{ 0, 0, 4 },
		{ 0, 313, 55 },
		{ 0, 235, 37 },
		{ 0, -34, 49 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 0, 343, 48 },
		{ 0, -38, 36 },
		{ 0, 0, 8 },
		{ 0, 150, 46 },
		{ 0, 0, 7 },
		{ 0, -33, 47 },
		{ 93, 271, 24 },
		{ 0, 0, 6 },
		{ 0, 0, 20 },
		{ 0, 102, 25 },
		{ 0, 319, 22 },
		{ 0, 73, 26 },
		{ 206, 0, 81 },
		{ 0, 0, 13 },
		{ 0, 0, 14 },
		{ 0, 149, 52 },
		{ 206, 181, 81 },
		{ 206, 194, 81 },
		{ 206, 108, 81 },
		{ 206, 23, 81 },
		{ 206, -91, 81 },
		{ 206, 294, 81 },
		{ 206, -92, 81 },
		{ 206, 192, 81 },
		{ 206, -97, 81 },
		{ 206, 94, 81 },
		{ 206, 219, 81 },
		{ 206, 219, 81 },
		{ 206, 269, 81 },
		{ 0, 0, 11 },
		{ 0, -40, 50 },
		{ 0, 0, 12 },
		{ 0, 0, 51 },
		{ 0, 0, 34 },
		{ 0, 0, 44 },
		{ 0, 0, 53 },
		{ 0, 0, 29 },
		{ 0, 0, 42 },
		{ 0, 0, 40 },
		{ 0, 0, 45 },
		{ 0, 0, 41 },
		{ 0, 0, 38 },
		{ 0, 0, 39 },
		{ -54, 333, 0 },
		{ -55, 366, 3 },
		{ 0, 0, 43 },
		{ 0, 305, 0 },
		{ 180, 231, 23 },
		{ 129, -30, 23 },
		{ 0, 366, 0 },
		{ 0, 0, 27 },
		{ 0, 0, 35 },
		{ 0, 0, 28 },
		{ 0, 381, 0 },
		{ 0, 0, 31 },
		{ 206, 354, 81 },
		{ 206, -27, 81 },
		{ 206, 33, 81 },
		{ 206, 54, 81 },
		{ 206, 63, 81 },
		{ 206, 50, 62 },
		{ 206, 184, 81 },
		{ 206, 96, 81 },
		{ 206, 106, 81 },
		{ 206, 105, 81 },
		{ 206, 133, 81 },
		{ 206, 132, 81 },
		{ 206, 0, 56 },
		{ 206, 133, 81 },
		{ 206, 187, 81 },
		{ 206, 183, 81 },
		{ 206, -91, 81 },
		{ 206, 192, 81 },
		{ 206, 192, 81 },
		{ 206, 184, 81 },
		{ 206, 206, 81 },
		{ 206, 102, 81 },
		{ 206, 24, 81 },
		{ 206, 226, 81 },
		{ 0, 0, 30 },
		{ 0, 0, 54 },
		{ -54, -31, 0 },
		{ 180, 149, 24 },
		{ 0, 285, 0 },
		{ 129, 151, 23 },
		{ 0, 0, 33 },
		{ 0, 0, 32 },
		{ 206, 280, 81 },
		{ 206, 277, 81 },
		{ 206, 265, 81 },
		{ 206, -60, 81 },
		{ 206, 284, 81 },
		{ 206, 284, 81 },
		{ 206, 278, 81 },
		{ 206, 283, 81 },
		{ 206, 276, 81 },
		{ 206, 271, 81 },
		{ 206, 290, 81 },
		{ 206, 0, 21 },
		{ 206, 277, 81 },
		{ 206, 0, 15 },
		{ 206, 284, 81 },
		{ 206, 273, 81 },
		{ 206, 277, 81 },
		{ 206, 282, 81 },
		{ 206, 292, 81 },
		{ 206, 278, 81 },
		{ 206, 278, 81 },
		{ 206, 280, 81 },
		{ 206, 296, 81 },
		{ 206, 297, 81 },
		{ 206, 288, 81 },
		{ 206, 295, 81 },
		{ 206, 301, 81 },
		{ 206, 305, 81 },
		{ 206, 295, 81 },
		{ 0, 0, 2 },
		{ 180, 315, 24 },
		{ 58, 259, 23 },
		{ 206, 299, 81 },
		{ 206, 0, 58 },
		{ 206, 0, 17 },
		{ 206, 291, 81 },
		{ 206, 303, 81 },
		{ 206, 292, 81 },
		{ 206, 302, 81 },
		{ 206, 299, 81 },
		{ 206, 0, 63 },
		{ 206, 0, 77 },
		{ 206, 311, 81 },
		{ 206, 297, 81 },
		{ 206, 0, 64 },
		{ 206, 299, 81 },
		{ 206, 301, 81 },
		{ 206, 300, 81 },
		{ 206, 316, 81 },
		{ 206, 307, 81 },
		{ 206, 314, 81 },
		{ 206, 321, 81 },
		{ 206, 322, 81 },
		{ 206, 0, 79 },
		{ 206, 322, 81 },
		{ 206, 313, 81 },
		{ 206, 321, 81 },
		{ 206, 0, 5 },
		{ 206, 309, 81 },
		{ 206, 325, 81 },
		{ 0, 295, 0 },
		{ 206, 0, 57 },
		{ 206, 0, 59 },
		{ 206, 318, 81 },
		{ 206, 321, 81 },
		{ 206, 329, 81 },
		{ 206, 316, 81 },
		{ 206, 0, 80 },
		{ 206, 0, 16 },
		{ 206, 316, 81 },
		{ 206, 323, 81 },
		{ 206, 0, 19 },
		{ 206, 334, 81 },
		{ 206, 333, 81 },
		{ 206, 337, 81 },
		{ 206, 321, 81 },
		{ 206, 334, 81 },
		{ 206, 338, 81 },
		{ 206, 0, 74 },
		{ 206, 330, 81 },
		{ 206, 336, 81 },
		{ 206, 0, 76 },
		{ 158, 156, 0 },
		{ 206, 326, 81 },
		{ 206, 328, 81 },
		{ 206, 0, 18 },
		{ 206, 340, 81 },
		{ 206, 345, 81 },
		{ 206, 0, 65 },
		{ 206, 0, 67 },
		{ 206, 0, 69 },
		{ 206, 0, 70 },
		{ 206, 0, 71 },
		{ 206, 0, 72 },
		{ 206, 345, 81 },
		{ 206, 347, 81 },
		{ 206, 341, 81 },
		{ 206, 349, 81 },
		{ 206, 0, 61 },
		{ 206, 336, 81 },
		{ 206, 338, 81 },
		{ 206, 0, 73 },
		{ 206, 353, 81 },
		{ 206, 353, 81 },
		{ 206, 0, 60 },
		{ 206, 0, 78 },
		{ 206, 0, 66 },
		{ 206, 0, 68 },
		{ 0, 71, 75 }
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
#line 219 ".\\mylexer.l"
  
/////////////////////////////////////////////////////////////////////////////
// programs section

