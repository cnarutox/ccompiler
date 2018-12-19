%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018��10��28��
****************************************************************************/
#include "define.h"
#include "mylexer.h"

void traverse(typenode *root) {
	if(root!=NULL)
		cout << root->name << endl;
	if(root->left!=NULL)
	{
		cout << "left ";
		traverse(root->left);
	}
	if(root->right!=NULL)
	{
		cout << "right ";
		traverse(root->right);	
	}	
}

%}
%union {
	struct node* ntnode;
	int value;
}

%type <ntnode> primary_exp, postfix_exp,argument_exp_list
%type <ntnode> unary_exp,unary_operator,cast_exp,multiplicative_exp
%type <ntnode> additive_exp,shift_exp,relational_exp,equality_exp
%type <ntnode> and_exp,exclusive_or_exp,inclusive_or_exp
%type <ntnode> logical_and_exp,logical_or_exp,conditional_exp
%type <ntnode> assignment_exp,assignment_operator,exp
%type <ntnode> constant_exp,declaration,declaration_specifiers
%type <ntnode> init_declarator_list,init_declarator,storage_class_specifier
%type <ntnode> type_specifier,struct_or_union_specifier,struct_or_union,struct_declaration_list
%type <ntnode> struct_declaration,specifier_qualifier_list,struct_declarator_list,struct_declarator
%type <ntnode> enum_specifier,enumerator_list,enumerator,type_qualifier,declarator,direct_declarator
%type <ntnode> pointer,type_qualifier_list,parameter_type_list,parameter_list,parameter_declaration
%type <ntnode> identifier_list,type_name,abstract_declarator,direct_abstract_declarator
%type <ntnode> initializer,initializer_list,statement,labeled_statement,compound_statement
%type <ntnode> declaration_list,statement_list,exp_statement
%type <ntnode> iteration_statement,jump_statement,translation_unit,external_declaration
%type <ntnode> function_definition,selection_statement
%type <ntnode> open_statement, matched_statement, stmt,other





/////////////////////////////////////////////////////////////////////////////
// declarations section
// parser name
%token ID CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN DIV_ASSIGN AND_ASSIGN
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
primary_exp
	: ID{
		$$ = new node();
		printf("108 ");
		$$ -> length = 1;
		$$->name="primary_exp";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	

		//$$->type = $1.ntnode;
	}
	| CONSTANT{
		$$ = new node();
		printf("116 ");
		$$ -> length = 1;
		$$->name="primary_exp";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;

		$$->dvalue = $1.ntnode->dvalue;
	}
	| STRING_LITERAL{
		$$ = new node();
		printf("123 ");
		$$ -> length = 1;
		$$->name="primary_exp";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
	}
	| '(' exp ')'{
		$$ = new node();
		printf("130 ");
		$$ -> length = 3;
		$$->name="primary_exp";
		$$->children=new node* [3];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;	
	}

	;

postfix_exp
	: primary_exp{
		$$ = new node();
		printf("142 ");
		$$ -> length = 1;
		$$->name="postfix_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| postfix_exp '[' exp ']'{	
		$$ = new node();
		printf("149 ");
		$$ -> length = 4;
		$$->name="postfix_exp";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| postfix_exp '(' ')'{
		$$ = new node();
		printf("159 ");
		$$ -> length = 3;
		$$->name="postfix_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| postfix_exp '(' argument_exp_list ')'{
		$$ = new node();
		printf("168 ");
		$$ -> length = 4;
		$$->name="postfix_exp";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| postfix_exp '.' ID{
		$$ = new node();
		printf("178 ");
		$$ -> length = 3;
		$$->name="postfix_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| postfix_exp PTR_OP ID{
		$$ = new node();
		printf("187 ");
		$$ -> length = 3;
		$$->name="postfix_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| postfix_exp INC_OP{
		$$ = new node();
		printf("196 ");
		$$ -> length = 2;
		$$->name="postfix_exp";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
	}
	| postfix_exp DEC_OP{
		$$ = new node();
		printf("204 ");
		$$ -> length = 2;
		$$->name="postfix_exp";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
	}
	;

argument_exp_list
	: assignment_exp{
		$$ = new node();
		printf("215 ");
		$$ -> length = 1;
		$$->name="argument_exp_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| argument_exp_list ',' assignment_exp{
		$$ = new node();
		printf("222 ");
		$$ -> length = 3;
		$$->name="argument_exp_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

unary_exp
	: postfix_exp{
		$$ = new node();
		printf("234 ");
		$$ -> length = 1;
		$$->name="unary_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| INC_OP unary_exp{
		$$ = new node();
		printf("241 ");
		$$ -> length = 2;
		$$->name="unary_exp";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| DEC_OP unary_exp{
		$$ = new node();
		printf("249 ");
		$$ -> length = 2;
		$$->name="unary_exp";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| unary_operator cast_exp{
		//cast_exp:单目表达式/强制类型转换
		$$ = new node();
		printf("257 ");
		$$ -> length = 2;
		$$->name="unary_exp";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| SIZEOF unary_exp{
		$$ = new node();
		printf("265 ");
		$$ -> length = 2;
		$$->name="unary_exp";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| SIZEOF '(' type_name ')'{
		$$ = new node();
		printf("273 ");
		$$ -> length = 4;
		$$->name="unary_exp";
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
		printf("286 ");
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '*'{
		$$ = new node();
		printf("293 ");
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '+'{
		printf("777");
		$$ = new node();
		printf("301 ");
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '-'{
		$$ = new node();
		printf("308 ");
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '~'{
		$$ = new node();
		printf("315 ");
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| '!'{
		$$ = new node();
		printf("322 ");
		$$ -> length = 1;
		$$->name="unary_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	;

cast_exp
	: unary_exp{
		$$ = new node();
		printf("332 ");
		$$ -> length = 1;
		$$->name="cast_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| '(' type_name ')' cast_exp{
		$$ = new node();
		printf("339 ");
		$$ -> length = 4;
		$$->name="cast_exp";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
		$$->children[3] = $4;
	}
	;

multiplicative_exp
	: cast_exp{
		$$ = new node();
		printf("352 ");
		$$ -> length = 1;
		$$->name="multiplicative_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| multiplicative_exp '*' cast_exp{
		$$ = new node();
		printf("359 ");
		$$ -> length = 3;
		$$->name="multiplicative_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| multiplicative_exp '/' cast_exp{
		$$ = new node();
		printf("368 ");
		$$ -> length = 3;
		$$->name="multiplicative_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| multiplicative_exp '%' cast_exp{
		$$ = new node();
		printf("377 ");
		$$ -> length = 3;
		$$->name="multiplicative_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

additive_exp
	: multiplicative_exp{
		$$ = new node();
		printf("389 ");
		$$ -> length = 1;
		$$->name="additive_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| additive_exp '+' multiplicative_exp{
		$$ = new node();
		printf("396 ");
		$$ -> length = 3;
		$$->name="additive_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| additive_exp '-' multiplicative_exp{
		$$ = new node();
		printf("405 ");
		$$ -> length = 3;
		$$->name="additive_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

shift_exp
	: additive_exp{
		$$ = new node();
		printf("417 ");
		$$ -> length = 1;
		$$->name="shift_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| shift_exp LEFT_OP additive_exp{
		$$ = new node();
		printf("424 ");
		$$ -> length = 3;
		$$->name="shift_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| shift_exp RIGHT_OP additive_exp{
		$$ = new node();
		printf("433 ");
		$$ -> length = 3;
		$$->name="shift_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

relational_exp
	: shift_exp{
		$$ = new node();
		printf("445 ");
		$$ -> length = 1;
		$$->name="relational_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| relational_exp '<' shift_exp{
		$$ = new node();
		printf("452 ");
		$$ -> length = 3;
		$$->name="relational_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| relational_exp '>' shift_exp{
		$$ = new node();
		printf("461 ");
		$$ -> length = 3;
		$$->name="relational_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| relational_exp LE_OP shift_exp{
		$$ = new node();
		printf("470 ");
		$$ -> length = 3;
		$$->name="relational_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| relational_exp GE_OP shift_exp{
		$$ = new node();
		printf("479 ");
		$$ -> length = 3;
		$$->name="relational_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

equality_exp
	: relational_exp{
		$$ = new node();
		printf("491 ");
		$$ -> length = 1;
		$$->name="equality_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| equality_exp EQ_OP relational_exp{
		$$ = new node();
		printf("498 ");
		$$ -> length = 3;
		$$->name="equality_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	| equality_exp NE_OP relational_exp{
		$$ = new node();
		printf("507 ");
		$$ -> length = 3;
		$$->name="equality_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

and_exp
	: equality_exp{
		$$ = new node();
		printf("519 ");
		$$ -> length = 1;
		$$->name="and_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| and_exp '&' equality_exp{
		$$ = new node();
		printf("526 ");
		$$ -> length = 3;
		$$->name="and_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

exclusive_or_exp
	: and_exp{
		$$ = new node();
		printf("538 ");
		$$ -> length = 1;
		$$->name="exclusive_or_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| exclusive_or_exp '^' and_exp{
		$$ = new node();
		printf("545 ");
		$$ -> length = 3;
		$$->name="exclusive_or_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

inclusive_or_exp
	: exclusive_or_exp{
		$$ = new node();
		printf("557 ");
		$$ -> length = 1;
		$$->name="inclusive_or_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| inclusive_or_exp '|' exclusive_or_exp{
		$$ = new node();
		printf("564 ");
		$$ -> length = 3;
		$$->name="inclusive_or_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

logical_and_exp
	: inclusive_or_exp{
		$$ = new node();
		printf("576 ");
		$$ -> length = 1;
		$$->name="logical_and_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| logical_and_exp AND_OP inclusive_or_exp{
		$$ = new node();
		printf("583 ");
		$$ -> length = 3;
		$$->name="logical_and_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

logical_or_exp
	: logical_and_exp{
		$$ = new node();
		printf("595 ");
		$$ -> length = 1;
		$$->name="logical_or_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;

		$$->dvalue = $1->dvalue;
	}
	| logical_or_exp OR_OP logical_and_exp{
		$$ = new node();
		printf("602 ");
		$$ -> length = 3;
		$$->name="logical_or_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

conditional_exp
	: logical_or_exp{
		$$ = new node();
		printf("614 ");
		$$ -> length = 1;
		$$->name="conditional_exp";		
		$$->children=new node* [1];
		$$->children[0] = $1;	

		$$->dvalue = $1->dvalue;	
	}
	| logical_or_exp '?' exp ':' conditional_exp{
		$$ = new node();
		printf("621 ");
		$$ -> length = 5;
		$$->name="conditional_exp";
		$$->children=new node* [5];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
		$$->children[4] = $5;				
	}
	;

assignment_exp
	: conditional_exp{
		//(1)谓词表达式

		//(2)条件表达式 a<b?a:b
		$$ = new node();
		printf("635 ");
		$$ -> length = 1;
		$$->name="assignment_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| unary_exp assignment_operator assignment_exp{
		$$ = new node();
		printf("642 ");
		$$ -> length = 3;
		$$->name="assignment_exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3;	
	}
	;

assignment_operator
	: '='{
		$$ = new node();
		printf("654 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| MUL_ASSIGN{
		$$ = new node();
		printf("661 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| DIV_ASSIGN{
		$$ = new node();
		printf("668 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| MOD_ASSIGN{
		$$ = new node();
		printf("675 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| ADD_ASSIGN{
		$$ = new node();
		printf("682 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| SUB_ASSIGN{
		$$ = new node();
		printf("689 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| LEFT_ASSIGN{
		$$ = new node();
		printf("696 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| RIGHT_ASSIGN{
		$$ = new node();
		printf("703 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| AND_ASSIGN{
		$$ = new node();
		printf("710 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| XOR_ASSIGN{
		$$ = new node();
		printf("717 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| OR_ASSIGN{
		$$ = new node();
		printf("724 ");
		$$ -> length = 1;
		$$->name="assignment_operator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	} 
	;

exp
	: assignment_exp{
		$$ = new node();
		printf(" ");
		$$ -> length = 1;
		$$->name="exp";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| exp ',' assignment_exp{
		$$ = new node();
		printf("741 ");
		$$ -> length = 3;
		$$->name="exp";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

constant_exp
	: conditional_exp{
		$$ = new node();
		printf("753 ");
		$$ -> length = 1;
		$$->name="constant_exp";
		$$->children=new node* [1];
		$$->children[0] = $1;		

		$$->dvalue = $1->dvalue;
	}
	;

declaration
	: declaration_specifiers ';'{
		$$ = new node();
		printf("763 ");
		$$ -> length = 2;
		$$->name="declaration";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;		
	}
	| declaration_specifiers init_declarator_list ';'{
		$$ = new node();
		printf("771 ");
		$$ -> length = 3;
		$$->name="declaration";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;		
	}
	// | ID ID ';'{
	// 	printf("772");
	// }
	;

declaration_specifiers
	: storage_class_specifier{ //static
		$$ = new node();
		printf("783 ");
		$$ -> length = 1;
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| storage_class_specifier declaration_specifiers //extern static
	{
		$$ = new node();
		printf("791 ");
		$$ -> length = 2;
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	| type_specifier{ // int
		$$ = new node();
		printf("799 ");
		$$ -> length = 1;
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;
		type3->right = rFlag();	
	}
	| type_specifier declaration_specifiers{ // lont int
		$$ = new node();
		printf("806 ");
		$$ -> length = 2;
		$$->name="declaration_specifiers";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;		
	}
	| type_qualifier{ //const
		$$ = new node();
		printf("814 ");
		$$ -> length = 1;
		$$->name="declaration_specifiers";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| type_qualifier declaration_specifiers{ //const int
		$$ = new node();
		printf("821 ");
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
		printf("832 ");
		$$ -> length = 1;
		$$->name="init_declarator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| init_declarator_list ',' init_declarator{
		$$ = new node();
		printf("839 ");
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
		printf("851 ");
		$$ -> length = 1;
		$$->name="init_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| declarator '=' initializer{
		$$ = new node();
		printf("858 ");
		$$ -> length = 3;
		$$->name="init_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;	

		//s.back()
	}
	;

storage_class_specifier
	: TYPEDEF{
		$$ = new node();
		printf("870 ");
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| EXTERN{
		$$ = new node();
		printf("877 ");
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| STATIC{
		$$ = new node();
		printf("884 ");
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| AUTO{
		$$ = new node();
		printf("891 ");
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| REGISTER{
		$$ = new node();
		printf("898 ");
		$$ -> length = 1;
		$$->name="storage_class_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	;

type_specifier
	: VOID{
		$$ = new node();
		printf("908 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
		wFlag(voidnode);
	}
	| CHAR{
		$$ = new node();
		printf("915 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
		wFlag(charnode);
	}
	| SHORT{
		$$ = new node();
		printf("922 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
		wFlag(shortnode);
	}
	| INT{
		$$ = new node();
		printf("929 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
		wFlag(intnode);
	}
	| LONG{
		$$ = new node();
		printf("936 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
		wFlag(longnode);
	}
	| FLOAT{
		$$ = new node();
		printf("943 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
		wFlag(floatnode);
	}
	| DOUBLE{
		$$ = new node();
		printf("950 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
		wFlag(doublenode);
	}
	| SIGNED{
		$$ = new node();
		printf("957 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
		wFlag(signednode);
	}
	| UNSIGNED{
		$$ = new node();
		printf("964 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
		wFlag(unsignednode);
	}
	| struct_or_union_specifier{
		$$ = new node();
		printf("971 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| enum_specifier{
		$$ = new node();
		printf("978 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1;		
	}
	| TYPE_NAME{
		$$ = new node();
		printf("985 ");
		$$ -> length = 1;
		$$->name="type_specifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;		
	}
	| type_specifier pointer{
		printf("999");
	}
	;

struct_or_union_specifier
	: struct_or_union ID '{' declaration_list '}' ';' {  //struct a { int a = 0;};
		$$ = new node();
		printf("995 ");
		$$ -> length = 6;
		$$->name="struct_or_union_specifier";
		$$->children=new node* [6];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
		$$->children[3] = $4;
		$$->children[4] = $5.ntnode;		
		$$->children[5] = $6.ntnode;

		map<string, typenode*>::iterator iter;
		typenode* temp_ptr;
		typenode* temp1;
		typenode* temp2;
		typenode* temp3=new typenode("?");
		for(iter = varmap_temp->vartable.begin(); iter!=varmap_temp->vartable.end(); ++iter){
				cout<<iter->first<<' '<<iter->second->name<<' ';
				temp_ptr = new typenode(string(iter->first));
				typenode* root = new typenode("X");
				root->left = temp_ptr;
				root->right = iter->second;
				struct_stack.push(root);
		}
		cout<<endl;
		while(struct_stack.size()>=1){
			cout<<struct_stack.size()<<endl;
			if(struct_stack.size() !=1){
				temp1 = struct_stack.top();struct_stack.pop();
				temp2 = struct_stack.top();struct_stack.pop();
				typenode* temp_ptr2 = new typenode("X");
				temp_ptr2->left = temp1;
				temp_ptr2->right = temp2;											
				struct_stack.push(temp_ptr2);				
			}
			else{
				temp3 = struct_stack.top();struct_stack.pop();
				break;
			}
		}
		typenode* temp = new typenode("record");
		temp->left = temp3;
		auto_define_type[$2.ntnode->name] = temp;	
		traverse(temp);
		s.pop_back();
	}
	| struct_or_union ID '{' declaration_list '}' init_declarator_list ';' { // struct a {int a = 0;} b[2];
		$$ = new node();
		printf("1006 ");
		$$ -> length = 7;
		$$->name="struct_or_union_specifier";
		$$->children=new node* [7];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;		
		$$->children[3] = $4;
		$$->children[4] = $5.ntnode;
		$$->children[5] = $6;
		$$->children[6] = $7.ntnode;
	}
	| struct_or_union '{' declaration_list '}' ';' { // struct a {int a = 0;};
		$$ = new node();
		printf("1007 ");
		$$ -> length = 5;
		$$->name="struct_or_union_specifier";
		$$->children=new node* [5];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
		$$->children[4] = $5.ntnode;
	}
	| struct_or_union '{' declaration_list '}' init_declarator_list ';' { //struct {int a = 0;}a[2];
		$$ = new node();
		printf("1008 ");
		$$ -> length = 6;
		$$->name="struct_or_union_specifier";
		$$->children=new node* [6];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
		$$->children[4] = $5;
		$$->children[5] = $6.ntnode;
	}
	| struct_or_union ID { // struct a
		$$ = new node();
		printf("1016 ");
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
		printf("1027 ");
		$$ -> length = 1;
		$$->name="struct_or_union";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
	}
	| UNION{
		$$ = new node();
		printf("1034 ");
		$$ -> length = 1;
		$$->name="struct_or_union";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;	
	}
	;

struct_declaration_list
	: struct_declaration{
		$$ = new node();
		printf("1044 ");
		$$ -> length = 1;
		$$->name="struct_declaration_list";
		$$->children=new node* [1];
		$$->children[0] = $1;	
	}
	| struct_declaration_list struct_declaration{
		$$ = new node();
		printf("1051 ");
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
		printf("1062 ");
		$$ -> length = 3;
		$$->name="struct_declaration";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
	}
	| assignment_exp struct_declarator_list ';' {
		$$ = new node();
		printf("1062 ");
		$$ -> length = 3;
		$$->name="struct_declaration";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list{
		$$ = new node();
		printf("1074 ");
		$$ -> length = 2;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| type_specifier{
		$$ = new node();
		printf("1082 ");
		$$ -> length = 1;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| type_qualifier specifier_qualifier_list{
		$$ = new node();
		printf("1089 ");
		$$ -> length = 2;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| type_qualifier{
		$$ = new node();
		printf("1097 ");
		$$ -> length = 1;
		$$->name="specifier_qualifier_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	;

struct_declarator_list
	: struct_declarator{
		$$ = new node();
		printf("1107 ");
		$$ -> length = 1;
		$$->name="struct_declarator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| struct_declarator_list ',' struct_declarator{
		$$ = new node();
		printf("1114 ");
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
		printf("1126 ");
		$$ -> length = 1;
		$$->name="struct_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| ':' constant_exp{
		$$ = new node();
		printf("1133 ");
		$$ -> length = 2;
		$$->name="struct_declarator";
		$$->children=new node* [2];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
	}
	| declarator ':' constant_exp{
		$$ = new node();
		printf("1141 ");
		$$ -> length = 3;
		$$->name="struct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

enum_specifier
	: ENUM '{' enumerator_list '}' { //enum {a=1,b}
		$$ = new node();
		printf("1153 ");
		$$ -> length = 4;
		$$->name="enum_specifier";
		$$->children=new node* [4];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
	}
	| ENUM ID '{' enumerator_list '}' { //enum q{a,b}
		$$ = new node();
		printf("1163 ");
		$$ -> length = 5;
		$$->name="enum_specifier";
		$$->children=new node* [5];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
		$$->children[3] = $4;
		$$->children[4] = $5.ntnode;
	}
	| ENUM ID {
		$$ = new node();
		printf("1174 ");
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
		printf("1185 ");
		$$ -> length = 1;
		$$->name="enumerator_list";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	| enumerator_list ',' enumerator{
		$$ = new node();
		printf("1192 ");
		$$ -> length = 3;
		$$->name="enumerator_list";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
	}
	;

enumerator
	: ID{
		$$ = new node();
		printf("1204 ");
		$$ -> length = 1;
		$$->name="enumerator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| ID '=' constant_exp{
		$$ = new node();
		printf("1211 ");
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
		printf("1223 ");
		$$ -> length = 1;
		$$->name="type_qualifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	| VOLATILE{
		$$ = new node();
		printf("1230 ");
		$$ -> length = 1;
		$$->name="type_qualifier";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;
	}
	;

declarator
	: pointer direct_declarator{
		$$ = new node();
		printf("1240 ");
		$$ -> length = 2;
		$$->name="declarator";
		$$->children=new node* [2];
		$$->children[0] = $1;
		$$->children[1] = $2;
	}
	| direct_declarator{
		$$ = new node();
		printf("1248 ");
		$$ -> length = 1;
		$$->name="declarator";
		$$->children=new node* [1];
		$$->children[0] = $1;
	}
	;


direct_declarator
	: ID{
		$$ = new node();
		printf("1258 ");
		$$ -> length = 1;
		$$->name="direct_declarator";
		$$->children=new node* [1];
		$$->children[0] = $1.ntnode;

		var_name = $1.ntnode->name;
		s.back()->vartable[$1.ntnode->name] = rFlag();
	}
	| '(' declarator ')' {
		$$ = new node();
		printf("1265 ");
		$$ -> length = 3;
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1.ntnode;
		$$->children[1] = $2;
		$$->children[2] = $3.ntnode;
	}
	| direct_declarator '[' constant_exp ']' {
		$$ = new node();
		printf("1274 ");
		$$ -> length = 4;
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;

		typenode temp("array");
		char num[25];
		_itoa_s(int($3->dvalue), num, 10);
		temp.left = new typenode(string(num));
		temp.right = rFlag();
		type = &temp;
		traverse(type);
	}
	| direct_declarator '[' ']' {
		$$ = new node();
		printf("1284 ");
		$$ -> length = 3;
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3.ntnode;
	}
	| direct_declarator '(' parameter_type_list ')' {
		$$ = new node();
		printf("1293 ");
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
		printf("1303 ");
		$$ -> length = 4;
		$$->name="direct_declarator";
		$$->children=new node* [4];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode;
		$$->children[2] = $3;
		$$->children[3] = $4.ntnode;
		map<string, typenode*>::iterator iter;
		for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
			s[s.size()-2]->vartable[iter->first] = iter->second;
		}	
	}
	| direct_declarator '(' ')' {
		$$ = new node();
		printf("1313 ");
		$$ -> length = 3;
		$$->name="direct_declarator";
		$$->children=new node* [3];
		$$->children[0] = $1;
		$$->children[1] = $2.ntnode; 
		$$->children[2] = $3.ntnode;

		typenode* temp = new typenode("fun");
		temp->right = rFlag();	
		s.back()->vartable[var_name] = temp;			
	}
	;

pointer
	: '*' {
		$$ = new node();
		printf("1325 ");
		$$ -> name = "pointer";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1.ntnode;

		typenode* temp = new typenode("pointer");
		temp->left=rFlag();
		flag = !flag;
		wFlag(*temp);
		//traverse(temp);
	}
	| '*' type_qualifier_list { // *const
		$$ = new node ();
		$$ -> name = "pointer";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
	}
	| '*' pointer { // **
		$$ = new node ();
		$$ -> name = "pointer";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;

		typenode* temp = new typenode("pointer");
		temp->left = rFlag();
		flag = !flag;
		wFlag(*temp);
	}
	| '*' type_qualifier_list pointer { //*const*
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
		printf("1359 ");
		$$ -> name = "type_qualifier_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| type_qualifier_list type_qualifier {
		$$ = new node();
		printf("1366 ");
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
		printf("1378 ");
		$$ -> name = "parameter_type_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;

		type3->left = rFlag();
		s.back()->vartable[var_name] = type3;
		traverse(type3);
	}
	| parameter_list ',' ELLIPSIS {
		$$ = new node();
		printf("1385 ");
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
		printf("1397 ");
		$$ -> name = "parameter_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| parameter_list ',' parameter_declaration {
		$$ = new node();
		printf("1404 ");
		$$ -> name = "parameter_list";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		typenode *temp = new typenode("X");
		flag = !flag;
		temp->left = rFlag();
		cout<<"left"<<endl;
		traverse(rFlag());
		flag = !flag;
		temp->right = rFlag();
		cout<<"right"<<endl;
		traverse(rFlag());	
		wFlag(*temp);
	}
	;		

parameter_declaration
	: declaration_specifiers declarator {
		$$ = new node();
		printf("1416 ");
		$$ -> name = "parameter_declaration";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	| declaration_specifiers abstract_declarator {
		$$ = new node();
		printf("1424 ");
		$$ -> name = "parameter_declaration";
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	| declaration_specifiers {
		$$ = new node();
		printf("1431 ");
		$$ -> name = "parameter_declaration";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	;

identifier_list
	: ID {
		$$ = new node();
		printf("1441 ");
		$$ -> name = "identifier_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1.ntnode;
		s.back()->vartable[$1.ntnode->name] = rFlag();
	}
	| identifier_list ',' ID {
		$$ = new node();
		printf("1448 ");   
		$$ -> name = "identifier_list";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
		s.back()->vartable[$3.ntnode->name] = rFlag();	
	}
	;

type_name
	: specifier_qualifier_list  {
		$$ = new node();
		printf("1460 ");
	  	$$ -> name = "type_name";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}  
	| specifier_qualifier_list abstract_declarator  {
		$$ = new node();
		printf("1467 ");  
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
		printf("1478 ");
		$$ -> name = "abstract_declarator";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| direct_abstract_declarator {
		$$ = new node();
		printf("1485 ");
		$$ -> name = "abstract_declarator";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| pointer direct_abstract_declarator {
		$$ = new node();
		printf("1492 ");
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
		printf("1503 ");
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '[' ']' {
		$$ = new node();
		printf("1512 ");
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 2;		
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| '[' constant_exp ']' {
		$$ = new node();
		printf("1520 ");
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '[' ']' {
		$$ = new node();
		printf("1529 ");
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '[' constant_exp ']' {
		$$ = new node();
		printf("1538 ");
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
		printf("1548 ");
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| '(' parameter_type_list ')' {
		$$ = new node();
		printf("1556 ");
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '(' ')' {
		$$ = new node();
		printf("1565 ");
		$$ -> name = "direct_abstract_declarator";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	| direct_abstract_declarator '(' parameter_type_list ')' {
		$$ = new node();
		printf("1574 ");
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
	: assignment_exp  {
		$$ = new node();
		printf("1587 ");
		$$ -> name = "initializer";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| '{' initializer_list '}'  {
		$$ = new node();
		printf("1594 ");
		$$ -> name = "initializer";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '{' initializer_list ',' '}'  {
		$$ = new node();
		printf("1603 ");
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
		printf("1616 ");
		$$ -> name = "initializer_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| initializer_list ',' initializer  {
		$$ = new node();
		printf("1623 ");
		$$ -> name = "initializer_list";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
	}
	;
other
	:labeled_statement {
		$$ = new node();
		printf("1635 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| compound_statement {
		$$ = new node();
		printf("1642 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| exp_statement {
		$$ = new node();
		printf("1649 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| iteration_statement {
		$$ = new node();
		printf("1663 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| jump_statement {
		$$ = new node();
		printf("1670 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	;
statement
	: labeled_statement {
		$$ = new node();
		printf("1635 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| compound_statement {
		$$ = new node();
		printf("1642 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| exp_statement {
		$$ = new node();
		printf("1649 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| selection_statement {
		$$ = new node();
		printf("1656 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| iteration_statement {
		$$ = new node();
		printf("1663 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| jump_statement {
		$$ = new node();
		printf("1670 ");
		$$ -> name = "statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	;

labeled_statement
	: ID ':' statement  {
		$$ = new node();
		printf("1680 ");
		$$ -> name = "labeled_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
	}
	| CASE constant_exp ':' statement  {
		$$ = new node();
		printf("1689 ");
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
		printf("1699 ");
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
		printf("1711 ");
		$$ -> name = "compound_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| '{' statement_list '}' {
		$$ = new node();
		printf("1719 ");
		$$ -> name = "compound_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '{' declaration_list '}' {
		$$ = new node();
		printf("1728 ");
		$$ -> name = "compound_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3.ntnode;
	}
	| '{' declaration_list statement_list '}' {
		$$ = new node();
		printf("1737 ");
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
		printf("1750 ");
		$$ -> name = "declaration_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| declaration_list declaration {
		$$ = new node();
		printf("1757 ");
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
		printf("1768 ");
		$$ -> name = "statement_list";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| statement_list statement {
		$$ = new node();
		printf("1775 ");
		$$ -> name = "statement_list";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
	}
	;

exp_statement
	: ';' {
		$$ = new node();
		printf("1786 ");
		$$ -> name = "exp_statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1.ntnode;
	}
	| exp ';' {
		$$ = new node();
		printf("1793 ");
		$$ -> name = "exp_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2.ntnode;
	}
	;
stmt 
	: matched_statement {
		$$ = new node();
		printf("1794 ");
		$$ -> name = "stmt";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| open_statement {
		$$ = new node();
		printf("1795 ");
		$$ -> name = "stmt";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	;
matched_statement
	: IF '(' exp ')' matched_statement ELSE matched_statement{
		$$ = new node();
		printf("1803 ");
		$$ -> name = "matched_statement";
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
	| other {
		$$ = new node();
		printf("1815 ");
		$$ -> name = "matched_statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	;
open_statement
	: IF '(' exp ')' stmt {
		$$ = new node();
		printf("1816 ");
		$$ -> name = "open_statement";
		$$ -> length = 5;
		$$ -> children = new node* [5];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
		$$ -> children[4] = $5;
	}
	| IF '(' exp ')' matched_statement ELSE open_statement {
		$$ = new node();
		printf("1817@ ");
		$$ -> name = "open_statement";
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
	;
selection_statement
	: stmt {
		$$ = new node();
		printf("1816 ");
		$$ -> name = "selection_statement";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| SWITCH '(' exp ')' statement {
		$$ = new node();
		printf("1825 ");
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
	: WHILE '(' exp ')' statement {
		$$ = new node();
		printf("1839 ");
		$$ -> name = "iteration_statement";
		$$ -> length = 5;
		$$ -> children = new node* [5];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4.ntnode;
		$$ -> children[4] = $5;
	}
	| DO statement WHILE '(' exp ')' ';' {
		$$ = new node();
		printf("1850 ");
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
	| FOR '(' exp_statement exp_statement ')' statement {
		$$ = new node();
		printf("1863 ");
		$$ -> name = "iteration_statement";
		$$ -> length = 6;
		$$ -> children = new node* [6];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3;
		$$ -> children[3] = $4;
		$$ -> children[4] = $5.ntnode;
		$$ -> children[5] = $6;
		map<string, typenode*>::iterator iter;
		for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
			s[s.size()-2]->vartable[iter->first] = iter->second;
		}
		s.pop_back();		
	}
	| FOR '(' exp_statement exp_statement exp ')' statement {
		$$ = new node();
		printf("1875 ");
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
		map<string, typenode*>::iterator iter;
		for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++)
		{
			s[s.size()-2]->vartable[iter->first] = iter->second;
		}
		s.pop_back();
	}
	;

jump_statement
	: GOTO ID ';'  {
		$$ = new node();
		printf("1891 ");
		$$ -> name = "jump_statement";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
		$$ -> children[2] = $3.ntnode;
	}
	| CONTINUE ';'  {
		$$ = new node();
		printf("1900 ");
		$$ -> name = "jump_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| BREAK ';'  {
		$$ = new node();
		printf("1908 ");
		$$ -> name = "jump_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| RETURN ';'  {
		$$ = new node();
		printf("1916 ");
		$$ -> name = "jump_statement";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1.ntnode;
		$$ -> children[1] = $2.ntnode;
	}
	| RETURN exp ';'  {
		$$ = new node();
		printf("1924 ");
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
		printf("1946 ");
		$$ -> name = "translation_unit";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
		cout<<endl;
		// traverse($$);
	}
	| translation_unit external_declaration {
		$$ = new node();
		printf("1953 ");
		$$ -> name = "translation_unit";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
		cout<<endl;
		// traverse($$);
	}
	;

external_declaration
	: function_definition {
		$$ = new node();
		printf("1964 ");
		$$ -> name = "external_declaration";
		$$ -> length = 1;
		$$ -> children = new node* [1];
		$$ -> children[0] = $1;
	}
	| declaration {
		$$ = new node();
		printf("1971 ");
		$$ -> name = "external_declaration";
		$$ -> length = 2;
		$$ -> children = new node* [2];
		$$ -> children[0] = $1;
	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
		$$ = new node();
		printf("1981 ");
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
		printf("1991 ");
		$$ -> name = "function_definition";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3;
	}
	| declarator declaration_list compound_statement {
		$$ = new node();
		printf("2000 ");
		$$ -> name = "function_definition";
		$$ -> length = 3;
		$$ -> children = new node* [3];
		$$ -> children[0] = $1;
		$$ -> children[1] = $2;
		$$ -> children[2] = $3;
	}
	| declarator compound_statement {
		$$ = new node();
		printf("2009 ");
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
	s.push_back(new varmap());
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