%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018年10月28日
****************************************************************************/

#include "mylexer.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%token object bracket
// parser name
%name myparser

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE int
#endif
}

// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

sectence	:	obj {}
	;
obj	:	object
	;
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
//  FILE *stream;
//	freopen_s(&stream, "in.txt", "r", stdin);
//	freopen_s(&stream, "out.txt", "w", stdout);
	cout << "单词\t\t词素\t\t属性\t\t行号" << endl;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	getchar();
	return n;
}

