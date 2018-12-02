#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 53 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 12/02/18
# Time: 10:35:34
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : translation_unit $end

    1  primary_expression : IDENTIFIER
    2                     | CONSTANT
    3                     | STRING_LITERAL
    4                     | '(' expression ')'

    5  postfix_expression : primary_expression
    6                     | postfix_expression '[' expression ']'
    7                     | postfix_expression '(' ')'
    8                     | postfix_expression '(' argument_expression_list ')'
    9                     | postfix_expression '.' IDENTIFIER
   10                     | postfix_expression PTR_OP IDENTIFIER
   11                     | postfix_expression INC_OP
   12                     | postfix_expression DEC_OP

   13  argument_expression_list : assignment_expression
   14                           | argument_expression_list ',' assignment_expression

   15  unary_expression : postfix_expression
   16                   | INC_OP unary_expression
   17                   | DEC_OP unary_expression
   18                   | unary_operator cast_expression
   19                   | SIZEOF unary_expression
   20                   | SIZEOF '(' type_name ')'

   21  unary_operator : '&'
   22                 | '*'
   23                 | '+'
   24                 | '-'
   25                 | '~'
   26                 | '!'

   27  cast_expression : unary_expression
   28                  | '(' type_name ')' cast_expression

   29  multiplicative_expression : cast_expression
   30                            | multiplicative_expression '*' cast_expression
   31                            | multiplicative_expression '/' cast_expression
   32                            | multiplicative_expression '%' cast_expression

   33  additive_expression : multiplicative_expression
   34                      | additive_expression '+' multiplicative_expression
   35                      | additive_expression '-' multiplicative_expression

   36  shift_expression : additive_expression
   37                   | shift_expression LEFT_OP additive_expression
   38                   | shift_expression RIGHT_OP additive_expression

   39  relational_expression : shift_expression
   40                        | relational_expression '<' shift_expression
   41                        | relational_expression '>' shift_expression
   42                        | relational_expression LE_OP shift_expression
   43                        | relational_expression GE_OP shift_expression

   44  equality_expression : relational_expression
   45                      | equality_expression EQ_OP relational_expression
   46                      | equality_expression NE_OP relational_expression

   47  and_expression : equality_expression
   48                 | and_expression '&' equality_expression

   49  exclusive_or_expression : and_expression
   50                          | exclusive_or_expression '^' and_expression

   51  inclusive_or_expression : exclusive_or_expression
   52                          | inclusive_or_expression '|' exclusive_or_expression

   53  logical_and_expression : inclusive_or_expression
   54                         | logical_and_expression AND_OP inclusive_or_expression

   55  logical_or_expression : logical_and_expression
   56                        | logical_or_expression OR_OP logical_and_expression

   57  conditional_expression : logical_or_expression
   58                         | logical_or_expression '?' expression ':' conditional_expression

   59  assignment_expression : conditional_expression
   60                        | unary_expression assignment_operator assignment_expression

   61  assignment_operator : '='
   62                      | MUL_ASSIGN
   63                      | DIV_ASSIGN
   64                      | MOD_ASSIGN
   65                      | ADD_ASSIGN
   66                      | SUB_ASSIGN
   67                      | LEFT_ASSIGN
   68                      | RIGHT_ASSIGN
   69                      | AND_ASSIGN
   70                      | XOR_ASSIGN
   71                      | OR_ASSIGN

   72  expression : assignment_expression
   73             | expression ',' assignment_expression

   74  constant_expression : conditional_expression

   75  declaration : declaration_specifiers ';'
   76              | declaration_specifiers init_declarator_list ';'

   77  declaration_specifiers : storage_class_specifier
   78                         | storage_class_specifier declaration_specifiers
   79                         | type_specifier
   80                         | type_specifier declaration_specifiers
   81                         | type_qualifier
   82                         | type_qualifier declaration_specifiers

   83  init_declarator_list : init_declarator
   84                       | init_declarator_list ',' init_declarator

   85  init_declarator : declarator
   86                  | declarator '=' initializer

   87  storage_class_specifier : TYPEDEF
   88                          | EXTERN
   89                          | STATIC
   90                          | AUTO
   91                          | REGISTER

   92  type_specifier : VOID
   93                 | CHAR
   94                 | SHORT
   95                 | INT
   96                 | LONG
   97                 | FLOAT
   98                 | DOUBLE
   99                 | SIGNED
  100                 | UNSIGNED
  101                 | struct_or_union_specifier
  102                 | enum_specifier
  103                 | TYPE_NAME

  104  struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}'
  105                            | struct_or_union '{' struct_declaration_list '}'
  106                            | struct_or_union IDENTIFIER

  107  struct_or_union : STRUCT
  108                  | UNION

  109  struct_declaration_list : struct_declaration
  110                          | struct_declaration_list struct_declaration

  111  struct_declaration : specifier_qualifier_list struct_declarator_list ';'

  112  specifier_qualifier_list : type_specifier specifier_qualifier_list
  113                           | type_specifier
  114                           | type_qualifier specifier_qualifier_list
  115                           | type_qualifier

  116  struct_declarator_list : struct_declarator
  117                         | struct_declarator_list ',' struct_declarator

  118  struct_declarator : declarator
  119                    | ':' constant_expression
  120                    | declarator ':' constant_expression

  121  enum_specifier : ENUM '{' enumerator_list '}'
  122                 | ENUM IDENTIFIER '{' enumerator_list '}'
  123                 | ENUM IDENTIFIER

  124  enumerator_list : enumerator
  125                  | enumerator_list ',' enumerator

  126  enumerator : IDENTIFIER
  127             | IDENTIFIER '=' constant_expression

  128  type_qualifier : CONST
  129                 | VOLATILE

  130  declarator : pointer direct_declarator
  131             | direct_declarator

  132  direct_declarator : IDENTIFIER
  133                    | '(' declarator ')'
  134                    | direct_declarator '[' constant_expression ']'
  135                    | direct_declarator '[' ']'
  136                    | direct_declarator '(' parameter_type_list ')'
  137                    | direct_declarator '(' identifier_list ')'
  138                    | direct_declarator '(' ')'

  139  pointer : '*'
  140          | '*' type_qualifier_list
  141          | '*' pointer
  142          | '*' type_qualifier_list pointer

  143  type_qualifier_list : type_qualifier
  144                      | type_qualifier_list type_qualifier

  145  parameter_type_list : parameter_list
  146                      | parameter_list ',' ELLIPSIS

  147  parameter_list : parameter_declaration
  148                 | parameter_list ',' parameter_declaration

  149  parameter_declaration : declaration_specifiers declarator
  150                        | declaration_specifiers abstract_declarator
  151                        | declaration_specifiers

  152  identifier_list : IDENTIFIER
  153                  | identifier_list ',' IDENTIFIER

  154  type_name : specifier_qualifier_list
  155            | specifier_qualifier_list abstract_declarator

  156  abstract_declarator : pointer
  157                      | direct_abstract_declarator
  158                      | pointer direct_abstract_declarator

  159  direct_abstract_declarator : '(' abstract_declarator ')'
  160                             | '[' ']'
  161                             | '[' constant_expression ']'
  162                             | direct_abstract_declarator '[' ']'
  163                             | direct_abstract_declarator '[' constant_expression ']'
  164                             | '(' ')'
  165                             | '(' parameter_type_list ')'
  166                             | direct_abstract_declarator '(' ')'
  167                             | direct_abstract_declarator '(' parameter_type_list ')'

  168  initializer : assignment_expression
  169              | '{' initializer_list '}'
  170              | '{' initializer_list ',' '}'

  171  initializer_list : initializer
  172                   | initializer_list ',' initializer

  173  statement : labeled_statement
  174            | compound_statement
  175            | expression_statement
  176            | selection_statement
  177            | iteration_statement
  178            | jump_statement

  179  labeled_statement : IDENTIFIER ':' statement
  180                    | CASE constant_expression ':' statement
  181                    | DEFAULT ':' statement

  182  compound_statement : '{' '}'
  183                     | '{' statement_list '}'
  184                     | '{' declaration_list '}'
  185                     | '{' declaration_list statement_list '}'

  186  declaration_list : declaration
  187                   | declaration_list declaration

  188  statement_list : statement
  189                 | statement_list statement

  190  expression_statement : ';'
  191                       | expression ';'

  192  selection_statement : IF '(' expression ')' statement
  193                      | IF '(' expression ')' statement ELSE statement
  194                      | SWITCH '(' expression ')' statement

  195  iteration_statement : WHILE '(' expression ')' statement
  196                      | DO statement WHILE '(' expression ')' ';'
  197                      | FOR '(' expression_statement expression_statement ')' statement
  198                      | FOR '(' expression_statement expression_statement expression ')' statement

  199  jump_statement : GOTO IDENTIFIER ';'
  200                 | CONTINUE ';'
  201                 | BREAK ';'
  202                 | RETURN ';'
  203                 | RETURN expression ';'

  204  translation_unit : external_declaration
  205                   | translation_unit external_declaration

  206  external_declaration : function_definition
  207                       | declaration

  208  function_definition : declaration_specifiers declarator declaration_list compound_statement
  209                      | declaration_specifiers declarator compound_statement
  210                      | declarator declaration_list compound_statement
  211                      | declarator compound_statement


##############################################################################
# States
##############################################################################

state 0
	$accept : . translation_unit $end

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	translation_unit  goto 24
	external_declaration  goto 25
	declarator  goto 26
	direct_declarator  goto 27
	enum_specifier  goto 28
	type_qualifier  goto 29
	pointer  goto 30
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 34
	declaration_specifiers  goto 35
	struct_or_union  goto 36
	function_definition  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	declarator  goto 38
	direct_declarator  goto 27
	pointer  goto 30


state 2
	pointer : '*' .  (139)
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 139

	type_qualifier_list  goto 39
	type_qualifier  goto 40
	pointer  goto 41


state 3
	direct_declarator : IDENTIFIER .  (132)

	.  reduce 132


state 4
	type_specifier : TYPE_NAME .  (103)

	.  reduce 103


state 5
	storage_class_specifier : TYPEDEF .  (87)

	.  reduce 87


state 6
	storage_class_specifier : EXTERN .  (88)

	.  reduce 88


state 7
	storage_class_specifier : STATIC .  (89)

	.  reduce 89


state 8
	storage_class_specifier : AUTO .  (90)

	.  reduce 90


state 9
	storage_class_specifier : REGISTER .  (91)

	.  reduce 91


state 10
	type_specifier : CHAR .  (93)

	.  reduce 93


state 11
	type_specifier : SHORT .  (94)

	.  reduce 94


state 12
	type_specifier : INT .  (95)

	.  reduce 95


state 13
	type_specifier : LONG .  (96)

	.  reduce 96


state 14
	type_specifier : SIGNED .  (99)

	.  reduce 99


state 15
	type_specifier : UNSIGNED .  (100)

	.  reduce 100


state 16
	type_specifier : FLOAT .  (97)

	.  reduce 97


state 17
	type_specifier : DOUBLE .  (98)

	.  reduce 98


state 18
	type_qualifier : CONST .  (128)

	.  reduce 128


state 19
	type_qualifier : VOLATILE .  (129)

	.  reduce 129


state 20
	type_specifier : VOID .  (92)

	.  reduce 92


state 21
	struct_or_union : STRUCT .  (107)

	.  reduce 107


state 22
	struct_or_union : UNION .  (108)

	.  reduce 108


state 23
	enum_specifier : ENUM . IDENTIFIER
	enum_specifier : ENUM . IDENTIFIER '{' enumerator_list '}'
	enum_specifier : ENUM . '{' enumerator_list '}'

	'{'  shift 42
	IDENTIFIER  shift 43


state 24
	$accept : translation_unit . $end  (0)
	translation_unit : translation_unit . external_declaration

	$end  accept
	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	external_declaration  goto 44
	declarator  goto 26
	direct_declarator  goto 27
	enum_specifier  goto 28
	type_qualifier  goto 29
	pointer  goto 30
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 34
	declaration_specifiers  goto 35
	struct_or_union  goto 36
	function_definition  goto 37


state 25
	translation_unit : external_declaration .  (204)

	.  reduce 204


state 26
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

	'{'  shift 45
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	compound_statement  goto 46
	declaration_list  goto 47
	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 48
	declaration_specifiers  goto 49
	struct_or_union  goto 36


state 27
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	declarator : direct_declarator .  (131)
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'

	'('  shift 50
	'['  shift 51
	.  reduce 131


state 28
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 29
	declaration_specifiers : type_qualifier .  (81)
	declaration_specifiers : type_qualifier . declaration_specifiers

	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	.  reduce 81

	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 52
	struct_or_union  goto 36


state 30
	declarator : pointer . direct_declarator

	'('  shift 1
	IDENTIFIER  shift 3

	direct_declarator  goto 53


state 31
	declaration_specifiers : storage_class_specifier .  (77)
	declaration_specifiers : storage_class_specifier . declaration_specifiers

	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	.  reduce 77

	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 54
	struct_or_union  goto 36


state 32
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 33
	declaration_specifiers : type_specifier .  (79)
	declaration_specifiers : type_specifier . declaration_specifiers

	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	.  reduce 79

	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 55
	struct_or_union  goto 36


state 34
	external_declaration : declaration .  (207)

	.  reduce 207


state 35
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 56
	IDENTIFIER  shift 3

	declarator  goto 57
	direct_declarator  goto 27
	pointer  goto 30
	init_declarator  goto 58
	init_declarator_list  goto 59


state 36
	struct_or_union_specifier : struct_or_union . '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . IDENTIFIER
	struct_or_union_specifier : struct_or_union . IDENTIFIER '{' struct_declaration_list '}'

	'{'  shift 60
	IDENTIFIER  shift 61


state 37
	external_declaration : function_definition .  (206)

	.  reduce 206


state 38
	direct_declarator : '(' declarator . ')'

	')'  shift 62


state 39
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (140)
	type_qualifier_list : type_qualifier_list . type_qualifier

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 140

	type_qualifier  goto 63
	pointer  goto 64


state 40
	type_qualifier_list : type_qualifier .  (143)

	.  reduce 143


state 41
	pointer : '*' pointer .  (141)

	.  reduce 141


state 42
	enum_specifier : ENUM '{' . enumerator_list '}'

	IDENTIFIER  shift 65

	enumerator  goto 66
	enumerator_list  goto 67


state 43
	enum_specifier : ENUM IDENTIFIER .  (123)
	enum_specifier : ENUM IDENTIFIER . '{' enumerator_list '}'

	'{'  shift 68
	.  reduce 123


state 44
	translation_unit : translation_unit external_declaration .  (205)

	.  reduce 205


state 45
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list '}'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'}'  shift 76
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 106
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	declaration_list  goto 113
	statement_list  goto 114
	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 48
	declaration_specifiers  goto 49
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	struct_or_union  goto 36
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 46
	function_definition : declarator compound_statement .  (211)

	.  reduce 211


state 47
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

	'{'  shift 45
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	compound_statement  goto 122
	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 123
	declaration_specifiers  goto 49
	struct_or_union  goto 36


state 48
	declaration_list : declaration .  (186)

	.  reduce 186


state 49
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 56
	IDENTIFIER  shift 3

	declarator  goto 124
	direct_declarator  goto 27
	pointer  goto 30
	init_declarator  goto 58
	init_declarator_list  goto 59


state 50
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'
	direct_declarator : direct_declarator '(' . ')'

	')'  shift 125
	IDENTIFIER  shift 126
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	parameter_declaration  goto 127
	identifier_list  goto 128
	enum_specifier  goto 28
	type_qualifier  goto 29
	parameter_type_list  goto 129
	parameter_list  goto 130
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 131
	struct_or_union  goto 36


state 51
	direct_declarator : direct_declarator '[' . constant_expression ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	']'  shift 132
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	constant_expression  goto 135
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 136
	logical_or_expression  goto 121


state 52
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 53
	declarator : pointer direct_declarator .  (130)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'

	'('  shift 50
	'['  shift 51
	.  reduce 130


state 54
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 55
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 56
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 57
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 137
	'{'  shift 45
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	.  reduce 85

	compound_statement  goto 138
	declaration_list  goto 139
	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 48
	declaration_specifiers  goto 49
	struct_or_union  goto 36


state 58
	init_declarator_list : init_declarator .  (83)

	.  reduce 83


state 59
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 140
	';'  shift 141


state 60
	struct_or_union_specifier : struct_or_union '{' . struct_declaration_list '}'

	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	struct_declaration  goto 142
	enum_specifier  goto 28
	specifier_qualifier_list  goto 143
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	struct_declaration_list  goto 146
	struct_or_union  goto 36


state 61
	struct_or_union_specifier : struct_or_union IDENTIFIER .  (106)
	struct_or_union_specifier : struct_or_union IDENTIFIER . '{' struct_declaration_list '}'

	'{'  shift 147
	.  reduce 106


state 62
	direct_declarator : '(' declarator ')' .  (133)

	.  reduce 133


state 63
	type_qualifier_list : type_qualifier_list type_qualifier .  (144)

	.  reduce 144


state 64
	pointer : '*' type_qualifier_list pointer .  (142)

	.  reduce 142


state 65
	enumerator : IDENTIFIER .  (126)
	enumerator : IDENTIFIER . '=' constant_expression

	'='  shift 148
	.  reduce 126


state 66
	enumerator_list : enumerator .  (124)

	.  reduce 124


state 67
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM '{' enumerator_list . '}'

	','  shift 149
	'}'  shift 150


state 68
	enum_specifier : ENUM IDENTIFIER '{' . enumerator_list '}'

	IDENTIFIER  shift 65

	enumerator  goto 66
	enumerator_list  goto 151


state 69
	unary_operator : '!' .  (26)

	.  reduce 26


state 70
	unary_operator : '&' .  (21)

	.  reduce 21


state 71
	primary_expression : '(' . expression ')'
	cast_expression : '(' . type_name ')' cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	type_name  goto 152
	enum_specifier  goto 28
	specifier_qualifier_list  goto 153
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	expression  goto 154
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	struct_or_union  goto 36
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 72
	unary_operator : '*' .  (22)

	.  reduce 22


state 73
	unary_operator : '+' .  (23)

	.  reduce 23


state 74
	unary_operator : '-' .  (24)

	.  reduce 24


state 75
	expression_statement : ';' .  (190)

	.  reduce 190


state 76
	compound_statement : '{' '}' .  (182)

	.  reduce 182


state 77
	unary_operator : '~' .  (25)

	.  reduce 25


state 78
	primary_expression : IDENTIFIER .  (1)
	labeled_statement : IDENTIFIER . ':' statement

	':'  shift 155
	.  reduce 1


state 79
	primary_expression : CONSTANT .  (2)

	.  reduce 2


state 80
	primary_expression : STRING_LITERAL .  (3)

	.  reduce 3


state 81
	unary_expression : SIZEOF . unary_expression
	unary_expression : SIZEOF . '(' type_name ')'

	'!'  shift 69
	'&'  shift 70
	'('  shift 156
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 157
	unary_operator  goto 97
	postfix_expression  goto 103


state 82
	unary_expression : INC_OP . unary_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 158
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 159
	unary_operator  goto 97
	postfix_expression  goto 103


state 83
	unary_expression : DEC_OP . unary_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 158
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 160
	unary_operator  goto 97
	postfix_expression  goto 103


state 84
	labeled_statement : CASE . constant_expression ':' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	constant_expression  goto 161
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 136
	logical_or_expression  goto 121


state 85
	labeled_statement : DEFAULT . ':' statement

	':'  shift 162


state 86
	selection_statement : IF . '(' expression ')' statement ELSE statement
	selection_statement : IF . '(' expression ')' statement

	'('  shift 163


state 87
	selection_statement : SWITCH . '(' expression ')' statement

	'('  shift 164


state 88
	iteration_statement : WHILE . '(' expression ')' statement

	'('  shift 165


state 89
	iteration_statement : DO . statement WHILE '(' expression ')' ';'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 166
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 90
	iteration_statement : FOR . '(' expression_statement expression_statement ')' statement
	iteration_statement : FOR . '(' expression_statement expression_statement expression ')' statement

	'('  shift 167


state 91
	jump_statement : GOTO . IDENTIFIER ';'

	IDENTIFIER  shift 168


state 92
	jump_statement : CONTINUE . ';'

	';'  shift 169


state 93
	jump_statement : BREAK . ';'

	';'  shift 170


state 94
	jump_statement : RETURN . ';'
	jump_statement : RETURN . expression ';'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 171
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 172
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 95
	postfix_expression : primary_expression .  (5)

	.  reduce 5


state 96
	cast_expression : unary_expression .  (27)
	assignment_expression : unary_expression . assignment_operator assignment_expression

	'='  shift 173
	MUL_ASSIGN  shift 174
	DIV_ASSIGN  shift 175
	MOD_ASSIGN  shift 176
	ADD_ASSIGN  shift 177
	SUB_ASSIGN  shift 178
	LEFT_ASSIGN  shift 179
	RIGHT_ASSIGN  shift 180
	AND_ASSIGN  shift 181
	XOR_ASSIGN  shift 182
	OR_ASSIGN  shift 183
	.  reduce 27

	assignment_operator  goto 184


state 97
	unary_expression : unary_operator . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 185
	postfix_expression  goto 103


state 98
	multiplicative_expression : cast_expression .  (29)

	.  reduce 29


state 99
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : additive_expression .  (36)
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 186
	'-'  shift 187
	.  reduce 36


state 100
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : shift_expression .  (39)
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 39


state 101
	equality_expression : relational_expression .  (44)
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 190
	'>'  shift 191
	LE_OP  shift 192
	GE_OP  shift 193
	.  reduce 44


state 102
	and_expression : equality_expression .  (47)
	equality_expression : equality_expression . EQ_OP relational_expression
	equality_expression : equality_expression . NE_OP relational_expression

	EQ_OP  shift 194
	NE_OP  shift 195
	.  reduce 47


state 103
	postfix_expression : postfix_expression . '[' expression ']'
	postfix_expression : postfix_expression . '(' ')'
	postfix_expression : postfix_expression . '(' argument_expression_list ')'
	postfix_expression : postfix_expression . '.' IDENTIFIER
	postfix_expression : postfix_expression . PTR_OP IDENTIFIER
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (15)

	'('  shift 196
	'.'  shift 197
	'['  shift 198
	PTR_OP  shift 199
	INC_OP  shift 200
	DEC_OP  shift 201
	.  reduce 15


state 104
	additive_expression : multiplicative_expression .  (33)
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression

	'%'  shift 202
	'*'  shift 203
	'/'  shift 204
	.  reduce 33


state 105
	exclusive_or_expression : and_expression .  (49)
	and_expression : and_expression . '&' equality_expression

	'&'  shift 205
	.  reduce 49


state 106
	statement_list : statement .  (188)

	.  reduce 188


state 107
	statement : expression_statement .  (175)

	.  reduce 175


state 108
	statement : selection_statement .  (176)

	.  reduce 176


state 109
	statement : compound_statement .  (174)

	.  reduce 174


state 110
	statement : jump_statement .  (178)

	.  reduce 178


state 111
	statement : iteration_statement .  (177)

	.  reduce 177


state 112
	statement : labeled_statement .  (173)

	.  reduce 173


state 113
	compound_statement : '{' declaration_list . statement_list '}'
	compound_statement : '{' declaration_list . '}'
	declaration_list : declaration_list . declaration

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'}'  shift 206
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 106
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	statement_list  goto 207
	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 123
	declaration_specifiers  goto 49
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	struct_or_union  goto 36
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 114
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'}'  shift 208
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 209
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 115
	expression : expression . ',' assignment_expression
	expression_statement : expression . ';'

	','  shift 210
	';'  shift 211


state 116
	expression : assignment_expression .  (72)

	.  reduce 72


state 117
	inclusive_or_expression : exclusive_or_expression .  (51)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 212
	.  reduce 51


state 118
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : inclusive_or_expression .  (53)

	'|'  shift 213
	.  reduce 53


state 119
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_and_expression .  (55)

	AND_OP  shift 214
	.  reduce 55


state 120
	assignment_expression : conditional_expression .  (59)

	.  reduce 59


state 121
	conditional_expression : logical_or_expression . '?' expression ':' conditional_expression
	conditional_expression : logical_or_expression .  (57)
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression

	'?'  shift 215
	OR_OP  shift 216
	.  reduce 57


state 122
	function_definition : declarator declaration_list compound_statement .  (210)

	.  reduce 210


state 123
	declaration_list : declaration_list declaration .  (187)

	.  reduce 187


state 124
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer

	'='  shift 137
	.  reduce 85


state 125
	direct_declarator : direct_declarator '(' ')' .  (138)

	.  reduce 138


state 126
	identifier_list : IDENTIFIER .  (152)

	.  reduce 152


state 127
	parameter_list : parameter_declaration .  (147)

	.  reduce 147


state 128
	direct_declarator : direct_declarator '(' identifier_list . ')'
	identifier_list : identifier_list . ',' IDENTIFIER

	')'  shift 217
	','  shift 218


state 129
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 219


state 130
	parameter_type_list : parameter_list .  (145)
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 220
	.  reduce 145


state 131
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (151)
	parameter_declaration : declaration_specifiers . declarator

	'('  shift 221
	'*'  shift 2
	'['  shift 222
	IDENTIFIER  shift 3
	.  reduce 151

	abstract_declarator  goto 223
	direct_abstract_declarator  goto 224
	declarator  goto 225
	direct_declarator  goto 27
	pointer  goto 226


state 132
	direct_declarator : direct_declarator '[' ']' .  (135)

	.  reduce 135


state 133
	primary_expression : IDENTIFIER .  (1)

	.  reduce 1


state 134
	cast_expression : unary_expression .  (27)

	.  reduce 27


state 135
	direct_declarator : direct_declarator '[' constant_expression . ']'

	']'  shift 227


state 136
	constant_expression : conditional_expression .  (74)

	.  reduce 74


state 137
	init_declarator : declarator '=' . initializer

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'{'  shift 228
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	initializer  goto 229
	assignment_expression  goto 230
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 138
	function_definition : declaration_specifiers declarator compound_statement .  (209)

	.  reduce 209


state 139
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

	'{'  shift 45
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	compound_statement  goto 231
	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration  goto 123
	declaration_specifiers  goto 49
	struct_or_union  goto 36


state 140
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	declarator  goto 124
	direct_declarator  goto 27
	pointer  goto 30
	init_declarator  goto 232


state 141
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 142
	struct_declaration_list : struct_declaration .  (109)

	.  reduce 109


state 143
	struct_declaration : specifier_qualifier_list . struct_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	':'  shift 233
	IDENTIFIER  shift 3

	struct_declarator_list  goto 234
	struct_declarator  goto 235
	declarator  goto 236
	direct_declarator  goto 27
	pointer  goto 30


state 144
	specifier_qualifier_list : type_qualifier . specifier_qualifier_list
	specifier_qualifier_list : type_qualifier .  (115)

	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	.  reduce 115

	enum_specifier  goto 28
	specifier_qualifier_list  goto 237
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	struct_or_union  goto 36


state 145
	specifier_qualifier_list : type_specifier .  (113)
	specifier_qualifier_list : type_specifier . specifier_qualifier_list

	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	.  reduce 113

	enum_specifier  goto 28
	specifier_qualifier_list  goto 238
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	struct_or_union  goto 36


state 146
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list . '}'

	'}'  shift 239
	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	struct_declaration  goto 240
	enum_specifier  goto 28
	specifier_qualifier_list  goto 143
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	struct_or_union  goto 36


state 147
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' . struct_declaration_list '}'

	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	struct_declaration  goto 142
	enum_specifier  goto 28
	specifier_qualifier_list  goto 143
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	struct_declaration_list  goto 241
	struct_or_union  goto 36


state 148
	enumerator : IDENTIFIER '=' . constant_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	constant_expression  goto 242
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 136
	logical_or_expression  goto 121


state 149
	enumerator_list : enumerator_list ',' . enumerator

	IDENTIFIER  shift 65

	enumerator  goto 243


state 150
	enum_specifier : ENUM '{' enumerator_list '}' .  (121)

	.  reduce 121


state 151
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM IDENTIFIER '{' enumerator_list . '}'

	','  shift 149
	'}'  shift 244


state 152
	cast_expression : '(' type_name . ')' cast_expression

	')'  shift 245


state 153
	type_name : specifier_qualifier_list .  (154)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 246
	'*'  shift 2
	'['  shift 222
	.  reduce 154

	abstract_declarator  goto 247
	direct_abstract_declarator  goto 224
	pointer  goto 248


state 154
	primary_expression : '(' expression . ')'
	expression : expression . ',' assignment_expression

	')'  shift 249
	','  shift 210


state 155
	labeled_statement : IDENTIFIER ':' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 250
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 156
	primary_expression : '(' . expression ')'
	unary_expression : SIZEOF '(' . type_name ')'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	type_name  goto 251
	enum_specifier  goto 28
	specifier_qualifier_list  goto 153
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	expression  goto 154
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	struct_or_union  goto 36
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 157
	unary_expression : SIZEOF unary_expression .  (19)

	.  reduce 19


state 158
	primary_expression : '(' . expression ')'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 154
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 159
	unary_expression : INC_OP unary_expression .  (16)

	.  reduce 16


state 160
	unary_expression : DEC_OP unary_expression .  (17)

	.  reduce 17


state 161
	labeled_statement : CASE constant_expression . ':' statement

	':'  shift 252


state 162
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 253
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 163
	selection_statement : IF '(' . expression ')' statement ELSE statement
	selection_statement : IF '(' . expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 254
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 164
	selection_statement : SWITCH '(' . expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 255
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 165
	iteration_statement : WHILE '(' . expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 256
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 166
	iteration_statement : DO statement . WHILE '(' expression ')' ';'

	WHILE  shift 257


state 167
	iteration_statement : FOR '(' . expression_statement expression_statement ')' statement
	iteration_statement : FOR '(' . expression_statement expression_statement expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression_statement  goto 258
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 168
	jump_statement : GOTO IDENTIFIER . ';'

	';'  shift 259


state 169
	jump_statement : CONTINUE ';' .  (200)

	.  reduce 200


state 170
	jump_statement : BREAK ';' .  (201)

	.  reduce 201


state 171
	jump_statement : RETURN ';' .  (202)

	.  reduce 202


state 172
	expression : expression . ',' assignment_expression
	jump_statement : RETURN expression . ';'

	','  shift 210
	';'  shift 260


state 173
	assignment_operator : '=' .  (61)

	.  reduce 61


state 174
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 175
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 176
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 177
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 178
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 179
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 180
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 181
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 182
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 183
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 184
	assignment_expression : unary_expression assignment_operator . assignment_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	assignment_expression  goto 261
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 185
	unary_expression : unary_operator cast_expression .  (18)

	.  reduce 18


state 186
	additive_expression : additive_expression '+' . multiplicative_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	postfix_expression  goto 103
	multiplicative_expression  goto 262


state 187
	additive_expression : additive_expression '-' . multiplicative_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	postfix_expression  goto 103
	multiplicative_expression  goto 263


state 188
	shift_expression : shift_expression LEFT_OP . additive_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 264
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 189
	shift_expression : shift_expression RIGHT_OP . additive_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 265
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 190
	relational_expression : relational_expression '<' . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 266
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 191
	relational_expression : relational_expression '>' . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 267
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 192
	relational_expression : relational_expression LE_OP . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 268
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 193
	relational_expression : relational_expression GE_OP . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 269
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 194
	equality_expression : equality_expression EQ_OP . relational_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 270
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 195
	equality_expression : equality_expression NE_OP . relational_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 271
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 196
	postfix_expression : postfix_expression '(' . ')'
	postfix_expression : postfix_expression '(' . argument_expression_list ')'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	')'  shift 272
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	argument_expression_list  goto 273
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	assignment_expression  goto 274
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 197
	postfix_expression : postfix_expression '.' . IDENTIFIER

	IDENTIFIER  shift 275


state 198
	postfix_expression : postfix_expression '[' . expression ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 276
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 199
	postfix_expression : postfix_expression PTR_OP . IDENTIFIER

	IDENTIFIER  shift 277


state 200
	postfix_expression : postfix_expression INC_OP .  (11)

	.  reduce 11


state 201
	postfix_expression : postfix_expression DEC_OP .  (12)

	.  reduce 12


state 202
	multiplicative_expression : multiplicative_expression '%' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 278
	postfix_expression  goto 103


state 203
	multiplicative_expression : multiplicative_expression '*' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 279
	postfix_expression  goto 103


state 204
	multiplicative_expression : multiplicative_expression '/' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 280
	postfix_expression  goto 103


state 205
	and_expression : and_expression '&' . equality_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 281
	postfix_expression  goto 103
	multiplicative_expression  goto 104


state 206
	compound_statement : '{' declaration_list '}' .  (184)

	.  reduce 184


state 207
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'}'  shift 282
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 209
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 208
	compound_statement : '{' statement_list '}' .  (183)

	.  reduce 183


state 209
	statement_list : statement_list statement .  (189)

	.  reduce 189


state 210
	expression : expression ',' . assignment_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	assignment_expression  goto 283
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 211
	expression_statement : expression ';' .  (191)

	.  reduce 191


state 212
	exclusive_or_expression : exclusive_or_expression '^' . and_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 284


state 213
	inclusive_or_expression : inclusive_or_expression '|' . exclusive_or_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	exclusive_or_expression  goto 285


state 214
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 286


state 215
	conditional_expression : logical_or_expression '?' . expression ':' conditional_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 287
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 216
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 288


state 217
	direct_declarator : direct_declarator '(' identifier_list ')' .  (137)

	.  reduce 137


state 218
	identifier_list : identifier_list ',' . IDENTIFIER

	IDENTIFIER  shift 289


state 219
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (136)

	.  reduce 136


state 220
	parameter_type_list : parameter_list ',' . ELLIPSIS
	parameter_list : parameter_list ',' . parameter_declaration

	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23
	ELLIPSIS  shift 290

	parameter_declaration  goto 291
	enum_specifier  goto 28
	type_qualifier  goto 29
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 131
	struct_or_union  goto 36


state 221
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 221
	')'  shift 292
	'*'  shift 2
	'['  shift 222
	IDENTIFIER  shift 3
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	abstract_declarator  goto 293
	parameter_declaration  goto 127
	direct_abstract_declarator  goto 224
	declarator  goto 38
	direct_declarator  goto 27
	enum_specifier  goto 28
	type_qualifier  goto 29
	pointer  goto 226
	parameter_type_list  goto 294
	parameter_list  goto 130
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 131
	struct_or_union  goto 36


state 222
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_expression ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	']'  shift 295
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	constant_expression  goto 296
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 136
	logical_or_expression  goto 121


state 223
	parameter_declaration : declaration_specifiers abstract_declarator .  (150)

	.  reduce 150


state 224
	abstract_declarator : direct_abstract_declarator .  (157)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 297
	'['  shift 298
	.  reduce 157


state 225
	parameter_declaration : declaration_specifiers declarator .  (149)

	.  reduce 149


state 226
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 221
	'['  shift 222
	IDENTIFIER  shift 3
	.  reduce 156

	direct_abstract_declarator  goto 299
	direct_declarator  goto 53


state 227
	direct_declarator : direct_declarator '[' constant_expression ']' .  (134)

	.  reduce 134


state 228
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'{'  shift 228
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	initializer  goto 300
	initializer_list  goto 301
	assignment_expression  goto 230
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 229
	init_declarator : declarator '=' initializer .  (86)

	.  reduce 86


state 230
	initializer : assignment_expression .  (168)

	.  reduce 168


state 231
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (208)

	.  reduce 208


state 232
	init_declarator_list : init_declarator_list ',' init_declarator .  (84)

	.  reduce 84


state 233
	struct_declarator : ':' . constant_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	constant_expression  goto 302
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 136
	logical_or_expression  goto 121


state 234
	struct_declarator_list : struct_declarator_list . ',' struct_declarator
	struct_declaration : specifier_qualifier_list struct_declarator_list . ';'

	','  shift 303
	';'  shift 304


state 235
	struct_declarator_list : struct_declarator .  (116)

	.  reduce 116


state 236
	struct_declarator : declarator . ':' constant_expression
	struct_declarator : declarator .  (118)

	':'  shift 305
	.  reduce 118


state 237
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (114)

	.  reduce 114


state 238
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (112)

	.  reduce 112


state 239
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}' .  (105)

	.  reduce 105


state 240
	struct_declaration_list : struct_declaration_list struct_declaration .  (110)

	.  reduce 110


state 241
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list . '}'

	'}'  shift 306
	TYPE_NAME  shift 4
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	struct_declaration  goto 240
	enum_specifier  goto 28
	specifier_qualifier_list  goto 143
	type_qualifier  goto 144
	struct_or_union_specifier  goto 32
	type_specifier  goto 145
	struct_or_union  goto 36


state 242
	enumerator : IDENTIFIER '=' constant_expression .  (127)

	.  reduce 127


state 243
	enumerator_list : enumerator_list ',' enumerator .  (125)

	.  reduce 125


state 244
	enum_specifier : ENUM IDENTIFIER '{' enumerator_list '}' .  (122)

	.  reduce 122


state 245
	cast_expression : '(' type_name ')' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 307
	postfix_expression  goto 103


state 246
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 246
	')'  shift 292
	'*'  shift 2
	'['  shift 222
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	abstract_declarator  goto 293
	parameter_declaration  goto 127
	direct_abstract_declarator  goto 224
	enum_specifier  goto 28
	type_qualifier  goto 29
	pointer  goto 248
	parameter_type_list  goto 294
	parameter_list  goto 130
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 131
	struct_or_union  goto 36


state 247
	type_name : specifier_qualifier_list abstract_declarator .  (155)

	.  reduce 155


state 248
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 246
	'['  shift 222
	.  reduce 156

	direct_abstract_declarator  goto 299


state 249
	primary_expression : '(' expression ')' .  (4)

	.  reduce 4


state 250
	labeled_statement : IDENTIFIER ':' statement .  (179)

	.  reduce 179


state 251
	unary_expression : SIZEOF '(' type_name . ')'

	')'  shift 308


state 252
	labeled_statement : CASE constant_expression ':' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 309
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 253
	labeled_statement : DEFAULT ':' statement .  (181)

	.  reduce 181


state 254
	expression : expression . ',' assignment_expression
	selection_statement : IF '(' expression . ')' statement ELSE statement
	selection_statement : IF '(' expression . ')' statement

	')'  shift 310
	','  shift 210


state 255
	expression : expression . ',' assignment_expression
	selection_statement : SWITCH '(' expression . ')' statement

	')'  shift 311
	','  shift 210


state 256
	expression : expression . ',' assignment_expression
	iteration_statement : WHILE '(' expression . ')' statement

	')'  shift 312
	','  shift 210


state 257
	iteration_statement : DO statement WHILE . '(' expression ')' ';'

	'('  shift 313


state 258
	iteration_statement : FOR '(' expression_statement . expression_statement ')' statement
	iteration_statement : FOR '(' expression_statement . expression_statement expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression_statement  goto 314
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 259
	jump_statement : GOTO IDENTIFIER ';' .  (199)

	.  reduce 199


state 260
	jump_statement : RETURN expression ';' .  (203)

	.  reduce 203


state 261
	assignment_expression : unary_expression assignment_operator assignment_expression .  (60)

	.  reduce 60


state 262
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : additive_expression '+' multiplicative_expression .  (34)

	'%'  shift 202
	'*'  shift 203
	'/'  shift 204
	.  reduce 34


state 263
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : additive_expression '-' multiplicative_expression .  (35)

	'%'  shift 202
	'*'  shift 203
	'/'  shift 204
	.  reduce 35


state 264
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : shift_expression LEFT_OP additive_expression .  (37)
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 186
	'-'  shift 187
	.  reduce 37


state 265
	shift_expression : shift_expression RIGHT_OP additive_expression .  (38)
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 186
	'-'  shift 187
	.  reduce 38


state 266
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : relational_expression '<' shift_expression .  (40)
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 40


state 267
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '>' shift_expression .  (41)

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 41


state 268
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : relational_expression LE_OP shift_expression .  (42)
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 42


state 269
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (43)
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 43


state 270
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	equality_expression : equality_expression EQ_OP relational_expression .  (45)
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 190
	'>'  shift 191
	LE_OP  shift 192
	GE_OP  shift 193
	.  reduce 45


state 271
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	equality_expression : equality_expression NE_OP relational_expression .  (46)
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 190
	'>'  shift 191
	LE_OP  shift 192
	GE_OP  shift 193
	.  reduce 46


state 272
	postfix_expression : postfix_expression '(' ')' .  (7)

	.  reduce 7


state 273
	postfix_expression : postfix_expression '(' argument_expression_list . ')'
	argument_expression_list : argument_expression_list . ',' assignment_expression

	')'  shift 315
	','  shift 316


state 274
	argument_expression_list : assignment_expression .  (13)

	.  reduce 13


state 275
	postfix_expression : postfix_expression '.' IDENTIFIER .  (9)

	.  reduce 9


state 276
	postfix_expression : postfix_expression '[' expression . ']'
	expression : expression . ',' assignment_expression

	','  shift 210
	']'  shift 317


state 277
	postfix_expression : postfix_expression PTR_OP IDENTIFIER .  (10)

	.  reduce 10


state 278
	multiplicative_expression : multiplicative_expression '%' cast_expression .  (32)

	.  reduce 32


state 279
	multiplicative_expression : multiplicative_expression '*' cast_expression .  (30)

	.  reduce 30


state 280
	multiplicative_expression : multiplicative_expression '/' cast_expression .  (31)

	.  reduce 31


state 281
	equality_expression : equality_expression . EQ_OP relational_expression
	and_expression : and_expression '&' equality_expression .  (48)
	equality_expression : equality_expression . NE_OP relational_expression

	EQ_OP  shift 194
	NE_OP  shift 195
	.  reduce 48


state 282
	compound_statement : '{' declaration_list statement_list '}' .  (185)

	.  reduce 185


state 283
	expression : expression ',' assignment_expression .  (73)

	.  reduce 73


state 284
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : exclusive_or_expression '^' and_expression .  (50)

	'&'  shift 205
	.  reduce 50


state 285
	inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression .  (52)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 212
	.  reduce 52


state 286
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (54)

	'|'  shift 213
	.  reduce 54


state 287
	conditional_expression : logical_or_expression '?' expression . ':' conditional_expression
	expression : expression . ',' assignment_expression

	','  shift 210
	':'  shift 318


state 288
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (56)
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression

	AND_OP  shift 214
	.  reduce 56


state 289
	identifier_list : identifier_list ',' IDENTIFIER .  (153)

	.  reduce 153


state 290
	parameter_type_list : parameter_list ',' ELLIPSIS .  (146)

	.  reduce 146


state 291
	parameter_list : parameter_list ',' parameter_declaration .  (148)

	.  reduce 148


state 292
	direct_abstract_declarator : '(' ')' .  (164)

	.  reduce 164


state 293
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 319


state 294
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 320


state 295
	direct_abstract_declarator : '[' ']' .  (160)

	.  reduce 160


state 296
	direct_abstract_declarator : '[' constant_expression . ']'

	']'  shift 321


state 297
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

	')'  shift 322
	TYPE_NAME  shift 4
	TYPEDEF  shift 5
	EXTERN  shift 6
	STATIC  shift 7
	AUTO  shift 8
	REGISTER  shift 9
	CHAR  shift 10
	SHORT  shift 11
	INT  shift 12
	LONG  shift 13
	SIGNED  shift 14
	UNSIGNED  shift 15
	FLOAT  shift 16
	DOUBLE  shift 17
	CONST  shift 18
	VOLATILE  shift 19
	VOID  shift 20
	STRUCT  shift 21
	UNION  shift 22
	ENUM  shift 23

	parameter_declaration  goto 127
	enum_specifier  goto 28
	type_qualifier  goto 29
	parameter_type_list  goto 323
	parameter_list  goto 130
	storage_class_specifier  goto 31
	struct_or_union_specifier  goto 32
	type_specifier  goto 33
	declaration_specifiers  goto 131
	struct_or_union  goto 36


state 298
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_expression ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	']'  shift 324
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	constant_expression  goto 325
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 136
	logical_or_expression  goto 121


state 299
	abstract_declarator : pointer direct_abstract_declarator .  (158)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 297
	'['  shift 298
	.  reduce 158


state 300
	initializer_list : initializer .  (171)

	.  reduce 171


state 301
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 326
	'}'  shift 327


state 302
	struct_declarator : ':' constant_expression .  (119)

	.  reduce 119


state 303
	struct_declarator_list : struct_declarator_list ',' . struct_declarator

	'('  shift 1
	'*'  shift 2
	':'  shift 233
	IDENTIFIER  shift 3

	struct_declarator  goto 328
	declarator  goto 236
	direct_declarator  goto 27
	pointer  goto 30


state 304
	struct_declaration : specifier_qualifier_list struct_declarator_list ';' .  (111)

	.  reduce 111


state 305
	struct_declarator : declarator ':' . constant_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	constant_expression  goto 329
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 136
	logical_or_expression  goto 121


state 306
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}' .  (104)

	.  reduce 104


state 307
	cast_expression : '(' type_name ')' cast_expression .  (28)

	.  reduce 28


state 308
	unary_expression : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 309
	labeled_statement : CASE constant_expression ':' statement .  (180)

	.  reduce 180


state 310
	selection_statement : IF '(' expression ')' . statement ELSE statement
	selection_statement : IF '(' expression ')' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 330
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 311
	selection_statement : SWITCH '(' expression ')' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 331
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 312
	iteration_statement : WHILE '(' expression ')' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 332
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 313
	iteration_statement : DO statement WHILE '(' . expression ')' ';'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 333
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 314
	iteration_statement : FOR '(' expression_statement expression_statement . ')' statement
	iteration_statement : FOR '(' expression_statement expression_statement . expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	')'  shift 334
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	expression  goto 335
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 315
	postfix_expression : postfix_expression '(' argument_expression_list ')' .  (8)

	.  reduce 8


state 316
	argument_expression_list : argument_expression_list ',' . assignment_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	assignment_expression  goto 336
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 317
	postfix_expression : postfix_expression '[' expression ']' .  (6)

	.  reduce 6


state 318
	conditional_expression : logical_or_expression '?' expression ':' . conditional_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 134
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 337
	logical_or_expression  goto 121


state 319
	direct_abstract_declarator : '(' abstract_declarator ')' .  (159)

	.  reduce 159


state 320
	direct_abstract_declarator : '(' parameter_type_list ')' .  (165)

	.  reduce 165


state 321
	direct_abstract_declarator : '[' constant_expression ']' .  (161)

	.  reduce 161


state 322
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (166)

	.  reduce 166


state 323
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 338


state 324
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (162)

	.  reduce 162


state 325
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression . ']'

	']'  shift 339


state 326
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'{'  shift 228
	'}'  shift 340
	'~'  shift 77
	IDENTIFIER  shift 133
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	initializer  goto 341
	assignment_expression  goto 230
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 327
	initializer : '{' initializer_list '}' .  (169)

	.  reduce 169


state 328
	struct_declarator_list : struct_declarator_list ',' struct_declarator .  (117)

	.  reduce 117


state 329
	struct_declarator : declarator ':' constant_expression .  (120)

	.  reduce 120


330: shift-reduce conflict (shift 342, reduce 192) on ELSE
state 330
	selection_statement : IF '(' expression ')' statement . ELSE statement
	selection_statement : IF '(' expression ')' statement .  (192)

	ELSE  shift 342
	.  reduce 192


state 331
	selection_statement : SWITCH '(' expression ')' statement .  (194)

	.  reduce 194


state 332
	iteration_statement : WHILE '(' expression ')' statement .  (195)

	.  reduce 195


state 333
	expression : expression . ',' assignment_expression
	iteration_statement : DO statement WHILE '(' expression . ')' ';'

	')'  shift 343
	','  shift 210


state 334
	iteration_statement : FOR '(' expression_statement expression_statement ')' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 344
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 335
	expression : expression . ',' assignment_expression
	iteration_statement : FOR '(' expression_statement expression_statement expression . ')' statement

	')'  shift 345
	','  shift 210


state 336
	argument_expression_list : argument_expression_list ',' assignment_expression .  (14)

	.  reduce 14


state 337
	conditional_expression : logical_or_expression '?' expression ':' conditional_expression .  (58)

	.  reduce 58


state 338
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (167)

	.  reduce 167


state 339
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']' .  (163)

	.  reduce 163


state 340
	initializer : '{' initializer_list ',' '}' .  (170)

	.  reduce 170


state 341
	initializer_list : initializer_list ',' initializer .  (172)

	.  reduce 172


state 342
	selection_statement : IF '(' expression ')' statement ELSE . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 346
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 343
	iteration_statement : DO statement WHILE '(' expression ')' . ';'

	';'  shift 347


state 344
	iteration_statement : FOR '(' expression_statement expression_statement ')' statement .  (197)

	.  reduce 197


state 345
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' . statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'~'  shift 77
	IDENTIFIER  shift 78
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83
	CASE  shift 84
	DEFAULT  shift 85
	IF  shift 86
	SWITCH  shift 87
	WHILE  shift 88
	DO  shift 89
	FOR  shift 90
	GOTO  shift 91
	CONTINUE  shift 92
	BREAK  shift 93
	RETURN  shift 94

	primary_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	relational_expression  goto 101
	equality_expression  goto 102
	postfix_expression  goto 103
	multiplicative_expression  goto 104
	and_expression  goto 105
	statement  goto 348
	expression_statement  goto 107
	selection_statement  goto 108
	compound_statement  goto 109
	jump_statement  goto 110
	iteration_statement  goto 111
	labeled_statement  goto 112
	expression  goto 115
	assignment_expression  goto 116
	exclusive_or_expression  goto 117
	inclusive_or_expression  goto 118
	logical_and_expression  goto 119
	conditional_expression  goto 120
	logical_or_expression  goto 121


state 346
	selection_statement : IF '(' expression ')' statement ELSE statement .  (193)

	.  reduce 193


state 347
	iteration_statement : DO statement WHILE '(' expression ')' ';' .  (196)

	.  reduce 196


state 348
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement .  (198)

	.  reduce 198


##############################################################################
# Summary
##############################################################################

State 330 contains 1 shift-reduce conflict(s)


84 token(s), 64 nonterminal(s)
212 grammar rule(s), 349 state(s)


##############################################################################
# End of File
##############################################################################
