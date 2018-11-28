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
primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression{
		$$ -> length = 1;
		$$ = new node();
		$$->name="conditional_expression";		
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| logical_or_expression '?' expression ':' conditional_expression{
		$$ -> length = 5;
		$$ = new node();
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
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| unary_expression assignment_operator assignment_expression{
		$$ -> length = 3;
		$$ = new node();
		$$->name="conditional_expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;	
	}
	;

assignment_operator
	: '='{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| MUL_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| DIV_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| MOD_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| ADD_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| SUB_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| LEFT_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| RIGHT_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| AND_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| XOR_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| OR_ASSIGN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="assignment_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	;

expression
	: assignment_expression{
		$$ -> length = 1;
		$$ = new node();
		$$->name="expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| expression ',' assignment_expression{
		$$ -> length = 3;
		$$ = new node();
		$$->name="expression";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

constant_expression
	: conditional_expression{
		$$ -> length = 1;
		$$ = new node();
		$$->name="constant_expression";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	;

declaration
	: declaration_specifiers ';'{
		$$ -> length = 2;
		$$ = new node();
		$$->name="declaration";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	| declaration_specifiers init_declarator_list ';'{
		$$ -> length = 3;
		$$ = new node();
		$$->name="declaration";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;		
	}
	;

declaration_specifiers
	: storage_class_specifier{
		$$ -> length = 1;
		$$ = new node();
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| storage_class_specifier declaration_specifiers
	{
		$$ -> length = 2;
		$$ = new node();
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	| type_specifier{
		$$ -> length = 1;
		$$ = new node();
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| type_specifier declaration_specifiers{
		$$ -> length = 2;
		$$ = new node();
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	| type_qualifier{
		$$ -> length = 1;
		$$ = new node();
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| type_qualifier declaration_specifiers{
		$$ -> length = 2;
		$$ = new node();
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	;

init_declarator_list
	: init_declarator{
		$$ -> length = 1;
		$$ = new node();
		$$->name="init_declarator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| init_declarator_list ',' init_declarator{
		$$ -> length = 3;
		$$ = new node();
		$$->name="init_declarator_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;		
	}
	;

init_declarator
	: declarator{
		$$ -> length = 1;
		$$ = new node();
		$$->name="init_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| declarator '=' initializer{
		$$ -> length = 3;
		$$ = new node();
		$$->name="init_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;							
	}
	;

storage_class_specifier
	: TYPEDEF{
		$$ -> length = 1;
		$$ = new node();
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| EXTERN{
		$$ -> length = 1;
		$$ = new node();
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| STATIC{
		$$ -> length = 1;
		$$ = new node();
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| AUTO{
		$$ -> length = 1;
		$$ = new node();
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| REGISTER{
		$$ -> length = 1;
		$$ = new node();
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	;

type_specifier
	: VOID{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| CHAR{
		$$ -> length = 1;
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| SHORT{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| INT{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| LONG{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| FLOAT{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| DOUBLE{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier"
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| SIGNED{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| UNSIGNED{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| struct_or_union_specifier{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| enum_specifier{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| TYPE_NAME{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}' {
		$$ -> length = 5;
		$$ = new node();
		$$->name="struct_or_union_specifier";
		$$->children=new node* [5];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
		$$->children[3] = $4;
		$$->children[4] = $5.ntnode;		
	}
	| struct_or_union '{' struct_declaration_list '}' {
		$$ -> length = 4;
		$$ = new node();
		$$->name="struct_or_union_specifier";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;		
	}
	| struct_or_union IDENTIFIER {
		$$ -> length = 2;
		$$ = new node();
		$$->name="struct_or_union_specifier";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	;

struct_or_union
	: STRUCT{
		$$ -> length = 1;
		$$ = new node();
		$$->name="struct_or_union";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| UNION{
		$$ -> length = 1;
		$$ = new node();
		$$->name="struct_or_union";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	;

struct_declaration_list
	: struct_declaration{
		$$ -> length = 1;
		$$ = new node();
		$$->name="struct_declaration_list";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| struct_declaration_list struct_declaration{
		$$ -> length = 2;
		$$ = new node();
		$$->name="struct_declaration_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {
		$$ -> length = 3;
		$$ = new node();
		$$->name="struct_declaration_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list{
		$$ -> length = 2;
		$$ = new node();
		$$->name="specifier_qualifier_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| type_specifier{
		$$ -> length = 1;
		$$ = new node();
		$$->name="specifier_qualifier_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| type_qualifier specifier_qualifier_list{
		$$ -> length = 2;
		$$ = new node();
		$$->name="specifier_qualifier_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| type_qualifier{
		$$ -> length = 1;
		$$ = new node();
		$$->name="specifier_qualifier_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	;

struct_declarator_list
	: struct_declarator{
		$$ -> length = 1;
		$$ = new node();
		$$->name="struct_declarator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| struct_declarator_list ',' struct_declarator{
		$$ -> length = 3;
		$$ = new node();
		$$->name="struct_declarator_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

struct_declarator
	: declarator{
		$$ -> length = 1;
		$$ = new node();
		$$->name="struct_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| ':' constant_expression{
		$$ -> length = 2;
		$$ = new node();
		$$->name="struct_declarator";
		$$->children=new node* [2];
		$$->children[0] = $1.ntcode;
		$$->children[1] = $2;
	}
	| declarator ':' constant_expression{
		$$ -> length = 3;
		$$ = new node();
		$$->name="struct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntcode;
		$$->children[2] = $3;
	}
	;

enum_specifier
	: ENUM '{' enumerator_list '}' {
		$$ -> length = 4;
		$$ = new node();
		$$->name="enum_specifier";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntcode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| ENUM IDENTIFIER '{' enumerator_list '}' {
		$$ -> length = 5;
		$$ = new node();
		$$->name="enum_specifier";
		$$->children=new node* [5];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntcode;
		$$->children[3] = $4;
		$$->children[4] = $5.ntcode;
	}
	| ENUM IDENTIFIER {
		$$ -> length = 2;
		$$ = new node();
		$$->name="enum_specifier";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	;

enumerator_list
	: enumerator{
		$$ -> length = 1;
		$$ = new node();
		$$->name="enumerator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| enumerator_list ',' enumerator{
		$$ -> length = 3;
		$$ = new node();
		$$->name="enumerator_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[1] = $2;
	}
	;

enumerator
	: IDENTIFIER{
		$$ -> length = 1;
		$$ = new node();
		$$->name="enumerator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| IDENTIFIER '=' constant_expression{
		$$ -> length = 3;
		$$ = new node();
		$$->name="enumerator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

type_qualifier
	: CONST{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_qualifier";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| VOLATILE{
		$$ -> length = 1;
		$$ = new node();
		$$->name="type_qualifier";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	;

declarator
	: pointer direct_declarator{
		$$ -> length = 2;
		$$ = new node();
		$$->name="declarator";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| direct_declarator{
		$$ -> length = 1;
		$$ = new node();
		$$->name="declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	;

direct_declarator
	: IDENTIFIER{
		$$ -> length = 1;
		$$ = new node();
		$$->name="direct_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| '(' declarator ')' {
		$$ -> length = 3;
		$$ = new node();
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
	}
	| direct_declarator '[' constant_expression ']' {
		$$ -> length = 4;
		$$ = new node();
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| direct_declarator '[' ']' {
		$$ -> length = 3;
		$$ = new node();
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| direct_declarator '(' parameter_type_list ')' {
		$$ -> length = 4;
		$$ = new node();
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| direct_declarator '(' identifier_list ')' {
		$$ -> length = 4;
		$$ = new node();
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| direct_declarator '(' ')' {
		$$ -> length = 3;
		$$ = new node();
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
		$$ -> children[0] = $1;
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
		$$ -> children[4] = $4;
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
		$$ -> children[5] = $6;
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