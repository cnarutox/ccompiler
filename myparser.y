%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018��10��28��
****************************************************************************/

#include "mylexer.h"
#include <string>
struct node {
	string name;
	int value;
	node** children;
	node(int v = 0)
	{
		value = v;
	}
	};
%}
%union {
	struct node* ntnode;
	int value;
}

%type <ntnode> stmt, expr

/////////////////////////////////////////////////////////////////////////////
// declarations section
// parser name
%token  NUMBER
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

// %token <ival> NUMBER


%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
stmt	:   expr ';' expr	{
			$$ = new node($1->value + $3->value);
			printf("%d\n", $$->value) ;
			$$->children=new node* [3];
			$$->children[0] = $1;
			$$->children[1] = $2.ntnode;
			$$->children[2] = $3;
		}
		|   stmt ';' expr	{
			$$ = new node($1->value + $3->value);
			printf("%d\n", $$->value) ;
			$$->children=new node* [3];
			$$->children[0] = $1;
			$$->children[1] = $2.ntnode;
			$$->children[2] = $3;
		}
		;
expr	:	NUMBER '+' NUMBER	{
			$$ = new node($1.ntnode->value + $3.ntnode->value);
			printf("%d\n", $$->value) ;
			$$->children=new node* [3];
			$$->children[0] = $1.ntnode;
			$$->children[1] = $2.ntnode;
			$$->children[2] = $3.ntnode;
				
			}
		|   expr '+' NUMBER		{
		        $$ = new node($1->value + $3.ntnode->value);
				printf("%d\n", $$->value) ;
				$$->children=new node* [3];
				$$->children[0] = $1;
				$$->children[1] = $2.ntnode;
				$$->children[2] = $3.ntnode;
		}
		;
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	
//  FILE *stream;
//	freopen_s(&stream, "in.txt", "r", stdin);
//	freopen_s(&stream, "out.txt", "w", stdout);
	cout << "Name\t\tElement\t\tValue\t\tLine" << endl;
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	getchar();
	return 0;
}

