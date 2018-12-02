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
	int length;
	node** children;
	node(int v = 0, string n = "")
	{
		value = v;
		name = n;
	}
	};
%}
%union {
	struct node* ntnode;
	int value;
}

%type <ntnode> primary_expression, postfix_expression,argument_expression_list
%type <ntnode> unary_expression,unary_operator,cast_expression,multiplicative_expression
%type <ntnode> additive_expression,shift_expression,relational_expression,equality_expression
%type <ntnode> and_expression,exclusive_or_expression,inclusive_or_expression
%type <ntnode> logical_and_expression,logical_or_expression,conditional_expression
%type <ntnode> assignment_expression,assignment_operator,expression
%type <ntnode> constant_expression,declaration,declaration_specifiers
%type <ntnode> init_declarator_list,init_declarator,storage_class_specifier
%type <ntnode> type_specifier,struct_or_union_specifier,struct_or_union,struct_declaration_list
%type <ntnode> struct_declaration,specifier_qualifier_list,struct_declarator_list,struct_declarator
%type <ntnode> enum_specifier,enumerator_list,enumerator,type_qualifier,declarator,direct_declarator
%type <ntnode> pointer,type_qualifier_list,parameter_type_list,parameter_list,parameter_declaration
%type <ntnode> identifier_list,type_name,abstract_declarator,direct_abstract_declarator
%type <ntnode> initializer,initializer_list,statement,labeled_statement,compound_statement
%type <ntnode> declaration_list,statement_list,expression_statement,selection_statement
%type <ntnode> iteration_statement,jump_statement,translation_unit,external_declaration
%type <ntnode> function_definition




/////////////////////////////////////////////////////////////////////////////
// declarations section
// parser name
%token NUMBER
%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token MAIN
%start translation_unit

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
primary_expression
	: IDENTIFIER{
		$$ = new node();
		$$ -> length = 1;
		$$->name="primary_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| CONSTANT{
		$$ = new node();
		$$ -> length = 1;
		$$->name="primary_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| STRING_LITERAL{
		$$ = new node();
		$$ -> length = 1;
		$$->name="primary_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
	}
	| '(' expression ')'{
		$$ = new node();
		$$ -> length = 3;
		$$->name="primary_expression";
		$$->children=new node* [3];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;	
	}
	;

postfix_expression
	: primary_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="postfix_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| postfix_expression '[' expression ']'{	
		$$ = new node();
		$$ -> length = 4;
		$$->name="postfix_expression";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| postfix_expression '(' ')'{
		$$ = new node();
		$$ -> length = 3;
		$$->name="postfix_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| postfix_expression '(' argument_expression_list ')'{
		$$ = new node();
		$$ -> length = 4;
		$$->name="postfix_expression";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| postfix_expression '.' IDENTIFIER{
		$$ = new node();
		$$ -> length = 3;
		$$->name="postfix_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| postfix_expression PTR_OP IDENTIFIER{
		$$ = new node();
		$$ -> length = 3;
		$$->name="postfix_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| postfix_expression INC_OP{
		$$ = new node();
		$$ -> length = 2;
		$$->name="postfix_expression";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
	}
	| postfix_expression DEC_OP{
		$$ = new node();
		$$ -> length = 2;
		$$->name="postfix_expression";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
	}
	;

argument_expression_list
	: assignment_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="argument_expression_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| argument_expression_list ',' assignment_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="argument_expression_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

unary_expression
	: postfix_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="unary_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| INC_OP unary_expression{
		$$ = new node();
		$$ -> length = 2;
		$$->name="unary_expression";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| DEC_OP unary_expression{
		$$ = new node();
		$$ -> length = 2;
		$$->name="unary_expression";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| unary_operator cast_expression{
		$$ = new node();
		$$ -> length = 2;
		$$->name="unary_expression";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| SIZEOF unary_expression{
		$$ = new node();
		$$ -> length = 2;
		$$->name="unary_expression";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| SIZEOF '(' type_name ')'{
		$$ = new node();
		$$ -> length = 4;
		$$->name="unary_expression";
		$$->children=new node* [4];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	;

unary_operator
	: '&'{
		$$ = new node();
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '*'{
		$$ = new node();
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '+'{
		$$ = new node();
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '-'{
		$$ = new node();
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '~'{
		$$ = new node();
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '!'{
		$$ = new node();
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	;

cast_expression
	: unary_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="cast_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| '(' type_name ')' cast_expression{
		$$ = new node();
		$$ -> length = 4;
		$$->name="cast_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
		$$->children[3] = $4;
	}
	;

multiplicative_expression
	: cast_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="multiplicative_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| multiplicative_expression '*' cast_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="multiplicative_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| multiplicative_expression '/' cast_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="multiplicative_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| multiplicative_expression '%' cast_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="multiplicative_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

additive_expression
	: multiplicative_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="additive_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| additive_expression '+' multiplicative_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="additive_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| additive_expression '-' multiplicative_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="additive_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

shift_expression
	: additive_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="shift_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| shift_expression LEFT_OP additive_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="shift_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| shift_expression RIGHT_OP additive_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="shift_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

relational_expression
	: shift_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="relational_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| relational_expression '<' shift_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="relational_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| relational_expression '>' shift_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="relational_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| relational_expression LE_OP shift_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="relational_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| relational_expression GE_OP shift_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="relational_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

equality_expression
	: relational_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="equality_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| equality_expression EQ_OP relational_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="equality_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| equality_expression NE_OP relational_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="equality_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

and_expression
	: equality_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="and_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| and_expression '&' equality_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="and_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

exclusive_or_expression
	: and_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="exclusive_or_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| exclusive_or_expression '^' and_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="exclusive_or_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

inclusive_or_expression
	: exclusive_or_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="inclusive_or_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| inclusive_or_expression '|' exclusive_or_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="inclusive_or_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

logical_and_expression
	: inclusive_or_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="logical_and_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| logical_and_expression AND_OP inclusive_or_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="logical_and_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

logical_or_expression
	: logical_and_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="logical_or_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| logical_or_expression OR_OP logical_and_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="logical_or_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

conditional_expression
	: logical_or_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="conditional_expression";		
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| logical_or_expression '?' expression ':' conditional_expression{
		$$ = new node();
		$$ -> length = 5;
		$$->name="conditional_expression";
		$$->children=new node* [5];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
		$$->children[4] = $5;				
	}
	;

assignment_expression
	: conditional_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| unary_expression assignment_operator assignment_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="conditional_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;	
	}
	;

assignment_operator
	: '='{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| MUL_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| DIV_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| MOD_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| ADD_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| SUB_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| LEFT_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| RIGHT_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| AND_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| XOR_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| OR_ASSIGN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	;

expression
	: assignment_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| expression ',' assignment_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

constant_expression
	: conditional_expression{
		$$ = new node();
		$$ -> length = 1;
		$$->name="constant_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	;

declaration
	: declaration_specifiers ';'{
		$$ = new node();
		$$ -> length = 2;
		$$->name="declaration";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;		
	}
	| declaration_specifiers init_declarator_list ';'{
		$$ = new node();
		$$ -> length = 3;
		$$->name="declaration";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;		
	}
	;

declaration_specifiers
	: storage_class_specifier{
		$$ = new node();
		$$ -> length = 1;
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| storage_class_specifier declaration_specifiers
	{
		$$ = new node();
		$$ -> length = 2;
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	| type_specifier{
		$$ = new node();
		$$ -> length = 1;
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| type_specifier declaration_specifiers{
		$$ = new node();
		$$ -> length = 2;
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	| type_qualifier{
		$$ = new node();
		$$ -> length = 1;
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| type_qualifier declaration_specifiers{
		$$ = new node();
		$$ -> length = 2;
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	;

init_declarator_list
	: init_declarator{
		$$ = new node();
		$$ -> length = 1;
		$$->name="init_declarator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| init_declarator_list ',' init_declarator{
		$$ = new node();
		$$ -> length = 3;
		$$->name="init_declarator_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;		
	}
	;

init_declarator
	: declarator{
		$$ = new node();
		$$ -> length = 1;
		$$->name="init_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| declarator '=' initializer{
		$$ = new node();
		$$ -> length = 3;
		$$->name="init_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;							
	}
	;

storage_class_specifier
	: TYPEDEF{
		$$ = new node();
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| EXTERN{
		$$ = new node();
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| STATIC{
		$$ = new node();
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| AUTO{
		$$ = new node();
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| REGISTER{
		$$ = new node();
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	;

type_specifier
	: VOID{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| CHAR{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| SHORT{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| INT{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| LONG{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| FLOAT{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| DOUBLE{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		// $$->children=new node* [1];
		// $$->children[0] = $1.ntnode;		
	}
	| SIGNED{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| UNSIGNED{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| struct_or_union_specifier{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| enum_specifier{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| TYPE_NAME{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}' {
		$$ = new node();
		$$ -> length = 5;
		$$->name="struct_or_union_specifier";
		$$->children=new node* [5];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
		$$->children[3] = $4;
		$$->children[4] = $5.ntnode;		
	}
	| struct_or_union '{' struct_declaration_list '}' {
		$$ = new node();
		$$ -> length = 4;
		$$->name="struct_or_union_specifier";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;		
	}
	| struct_or_union IDENTIFIER {
		$$ = new node();
		$$ -> length = 2;
		$$->name="struct_or_union_specifier";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;		
	}
	;

struct_or_union
	: STRUCT{
		$$ = new node();
		$$ -> length = 1;
		$$->name="struct_or_union";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
	}
	| UNION{
		$$ = new node();
		$$ -> length = 1;
		$$->name="struct_or_union";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
	}
	;

struct_declaration_list
	: struct_declaration{
		$$ = new node();
		$$ -> length = 1;
		$$->name="struct_declaration_list";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| struct_declaration_list struct_declaration{
		$$ = new node();
		$$ -> length = 2;
		$$->name="struct_declaration_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {
		$$ = new node();
		$$ -> length = 3;
		$$->name="struct_declaration_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list{
		$$ = new node();
		$$ -> length = 2;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| type_specifier{
		$$ = new node();
		$$ -> length = 1;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| type_qualifier specifier_qualifier_list{
		$$ = new node();
		$$ -> length = 2;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| type_qualifier{
		$$ = new node();
		$$ -> length = 1;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	;

struct_declarator_list
	: struct_declarator{
		$$ = new node();
		$$ -> length = 1;
		$$->name="struct_declarator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| struct_declarator_list ',' struct_declarator{
		$$ = new node();
		$$ -> length = 3;
		$$->name="struct_declarator_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

struct_declarator
	: declarator{
		$$ = new node();
		$$ -> length = 1;
		$$->name="struct_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| ':' constant_expression{
		$$ = new node();
		$$ -> length = 2;
		$$->name="struct_declarator";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| declarator ':' constant_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="struct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

enum_specifier
	: ENUM '{' enumerator_list '}' {
		$$ = new node();
		$$ -> length = 4;
		$$->name="enum_specifier";
		$$->children=new node* [4];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| ENUM IDENTIFIER '{' enumerator_list '}' {
		$$ = new node();
		$$ -> length = 5;
		$$->name="enum_specifier";
		$$->children=new node* [5];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
		$$->children[3] = $4;
		$$->children[4] = $5.ntnode;
	}
	| ENUM IDENTIFIER {
		$$ = new node();
		$$ -> length = 2;
		$$->name="enum_specifier";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2.ntnode;
	}
	;

enumerator_list
	: enumerator{
		$$ = new node();
		$$ -> length = 1;
		$$->name="enumerator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| enumerator_list ',' enumerator{
		$$ = new node();
		$$ -> length = 3;
		$$->name="enumerator_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

enumerator
	: IDENTIFIER{
		$$ = new node();
		$$ -> length = 1;
		$$->name="enumerator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| IDENTIFIER '=' constant_expression{
		$$ = new node();
		$$ -> length = 3;
		$$->name="enumerator";
		$$->children=new node* [3];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

type_qualifier
	: CONST{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_qualifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| VOLATILE{
		$$ = new node();
		$$ -> length = 1;
		$$->name="type_qualifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	;

declarator
	: pointer direct_declarator{
		$$ = new node();
		$$ -> length = 2;
		$$->name="declarator";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| direct_declarator{
		$$ = new node();
		$$ -> length = 1;
		$$->name="declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	;

direct_declarator
	: IDENTIFIER{
		$$ = new node();
		$$ -> length = 1;
		$$->name="direct_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '(' declarator ')' {
		$$ = new node();
		$$ -> length = 3;
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
	}
	| direct_declarator '[' constant_expression ']' {
		$$ = new node();
		$$ -> length = 4;
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| direct_declarator '[' ']' {
		$$ = new node();
		$$ -> length = 3;
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| direct_declarator '(' parameter_type_list ')' {
		$$ = new node();
		$$ -> length = 4;
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| direct_declarator '(' identifier_list ')' {
		$$ = new node();
		$$ -> length = 4;
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| direct_declarator '(' ')' {
		$$ = new node();
		$$ -> length = 3;
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	;

pointer
	: '*' {
		$$ = new node();
		$$ -> name = "pointer";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1.ntnode;
	}
	| '*' type_qualifier_list {
		$$ = new node ();
		$$ -> name = "pointer";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
	}
	| '*' pointer {
		$$ = new node ();
		$$ -> name = "pointer";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
	}
	| '*' type_qualifier_list pointer {
		$$ = new node ();
		$$ -> name = "pointer";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
	}
	;

type_qualifier_list
	: type_qualifier {
		$$ = new node();
		$$ -> name = "type_qualifier_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| type_qualifier_list type_qualifier {
		$$ = new node();
		$$ -> name = "type_qualifier_list";
		$$ -> children = new node* [2];
		$$ -> length = 2;
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	;


parameter_type_list
	: parameter_list {
		$$ = new node();
		$$ -> name = "parameter_type_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| parameter_list ',' ELLIPSIS {
		$$ = new node();
		$$ -> name = "parameter_type_list";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	;

parameter_list
	: parameter_declaration {
		$$ = new node();
		$$ -> name = "parameter_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| parameter_list ',' parameter_declaration {
		$$ = new node();
		$$ -> name = "parameter_list";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		$$ = new node();
		$$ -> name = "parameter_declaration";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	| declaration_specifiers abstract_declarator {
		$$ = new node();
		$$ -> name = "parameter_declaration";
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	| declaration_specifiers {
		$$ = new node();
		$$ -> name = "parameter_declaration";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	;

identifier_list
	: IDENTIFIER {
		$$ = new node();
		$$ -> name = "type_qualifier_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1.ntnode;
	}
	| identifier_list ',' IDENTIFIER {
		$$ = new node();
		$$ -> name = "type_qualifier_list";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	;

type_name
	: specifier_qualifier_list  {
		$$ = new node();
		$$ -> name = "type_name";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| specifier_qualifier_list abstract_declarator  {
		$$ = new node();
		$$ -> name = "type_name";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	;

abstract_declarator
	: pointer {
		$$ = new node();
		$$ -> name = "abstract_declarator";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| direct_abstract_declarator {
		$$ = new node();
		$$ -> name = "abstract_declarator";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| pointer direct_abstract_declarator {
		$$ = new node();
		$$ -> name = "abstract_declarator";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '[' ']' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 2;		
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| '[' constant_expression ']' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '[' ']' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '[' constant_expression ']' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 4;
		$$ -> children = new node* [4];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
	}
	| '(' ')' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| '(' parameter_type_list ')' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '(' ')' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '(' parameter_type_list ')' {
		$$ = new node();
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 4;
		$$ -> children = new node* [4];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
	}
	;

initializer
	: assignment_expression  {
		$$ = new node();
		$$ -> name = "initializer";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| '{' initializer_list '}'  {
		$$ = new node();
		$$ -> name = "initializer";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '{' initializer_list ',' '}'  {
		$$ = new node();
		$$ -> name = "initializer";
		$$ -> length = 4;
		$$ -> children = new node* [4];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
		$$ -> children[3] = $4.ntnode;
	}
	;

initializer_list
	: initializer  {
		$$ = new node();
		$$ -> name = "initializer_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| initializer_list ',' initializer  {
		$$ = new node();
		$$ -> name = "initializer_list";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
	}
	;

statement
	: labeled_statement {
		$$ = new node();
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| compound_statement {
		$$ = new node();
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| expression_statement {
		$$ = new node();
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| selection_statement {
		$$ = new node();
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| iteration_statement {
		$$ = new node();
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| jump_statement {
		$$ = new node();
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	;

labeled_statement
	: IDENTIFIER ':' statement  {
		$$ = new node();
		$$ -> name = "labeled_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
	}
	| CASE constant_expression ':' statement  {
		$$ = new node();
		$$ -> name = "labeled_statement";
		$$ -> length = 4;
		$$ -> children = new node* [4];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
		$$ -> children[3] = $4;
	}
	| DEFAULT ':' statement  {
		$$ = new node();
		$$ -> name = "labeled_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
	}
	;

compound_statement
	: '{' '}' {
		$$ = new node();
		$$ -> name = "compound_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| '{' statement_list '}' {
		$$ = new node();
		$$ -> name = "compound_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '{' declaration_list '}' {
		$$ = new node();
		$$ -> name = "compound_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '{' declaration_list statement_list '}' {
		$$ = new node();
		$$ -> name = "compound_statement";
		$$ -> length = 4;		
		$$ -> children = new node* [4];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
	}
	;

declaration_list
	: declaration {
		$$ = new node();
		$$ -> name = "declaration_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| declaration_list declaration {
		$$ = new node();
		$$ -> name = "declaration_list";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	;

statement_list
	: statement {
		$$ = new node();
		$$ -> name = "statement_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| statement_list statement {
		$$ = new node();
		$$ -> name = "statement_list";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	;

expression_statement
	: ';' {
		$$ = new node();
		$$ -> name = "expression_statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1.ntnode;
	}
	| expression ';' {
		$$ = new node();
		$$ -> name = "expression_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
	}
	;

selection_statement
	: IF '(' expression ')' statement {
		$$ = new node();
		$$ -> name = "selection_statement";
		$$ -> length = 5;
		$$ -> children = new node* [5];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
		$$ -> children[4] = $5;
	}
	| IF '(' expression ')' statement ELSE statement {
		$$ = new node();
		$$ -> name = "selection_statement";
		$$ -> length = 7;
		$$ -> children = new node* [7];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
		$$ -> children[4] = $5;
		$$ -> children[5] = $6.ntnode;
		$$ -> children[6] = $7;
	}
	| SWITCH '(' expression ')' statement {
		$$ = new node();
		$$ -> name = "selection_statement";
		$$ -> length = 5;
		$$ -> children = new node* [5];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
		$$ -> children[4] = $5;
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement {
		$$ = new node();
		$$ -> name = "iteration_statement";
		$$ -> length = 5;
		$$ -> children = new node* [5];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
		$$ -> children[4] = $5;
	}
	| DO statement WHILE '(' expression ')' ';' {
		$$ = new node();
		$$ -> name = "iteration_statement";
		$$ -> length = 7;
		$$ -> children = new node* [7];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
		$$ -> children[3] = $4.ntnode;
		$$ -> children[4] = $5;
		$$ -> children[5] = $6.ntnode;
		$$ -> children[6] = $7.ntnode;
	}
	| FOR '(' expression_statement expression_statement ')' statement {
		$$ = new node();
		$$ -> name = "iteration_statement";
		$$ -> length = 6;
		$$ -> children = new node* [6];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4;
		$$ -> children[4] = $5.ntnode;
		$$ -> children[5] = $6;
	}
	| FOR '(' expression_statement expression_statement expression ')' statement {
		$$ = new node();
		$$ -> name = "iteration_statement";
		$$ -> length = 7;
		$$ -> children = new node* [7];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4;
		$$ -> children[4] = $5;
		$$ -> children[5] = $6.ntnode;
		$$ -> children[6] = $7;
	}
	;

jump_statement
	: GOTO IDENTIFIER ';'  {
		$$ = new node();
		$$ -> name = "jump_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	| CONTINUE ';'  {
		$$ = new node();
		$$ -> name = "jump_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| BREAK ';'  {
		$$ = new node();
		$$ -> name = "jump_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| RETURN ';'  {
		$$ = new node();
		$$ -> name = "jump_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| RETURN expression ';'  {
		$$ = new node();
		$$ -> name = "jump_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	;

translation_unit
	: external_declaration {
		$$ = new node();
		$$ -> name = "translation_unit";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| translation_unit external_declaration {
		$$ = new node();
		$$ -> name = "translation_unit";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	;

external_declaration
	: function_definition {
		$$ = new node();
		$$ -> name = "external_declaration";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| declaration {
		$$ = new node();
		$$ -> name = "external_declaration";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
		$$ = new node();
		$$ -> name = "function_definition";
		$$ -> length = 4;
		$$ -> children = new node* [4];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4;
	}
	| declaration_specifiers declarator compound_statement {
		$$ = new node();
		$$ -> name = "function_definition";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3;
	}
	| declarator declaration_list compound_statement {
		$$ = new node();
		$$ -> name = "function_definition";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3;
	}
	| declarator compound_statement {
		$$ = new node();
		$$ -> name = "function_definition";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
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