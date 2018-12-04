#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 56 of your 30 day trial period.
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
# Date: 12/05/18
# Time: 02:40:52
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : start_translation $end

    1  primary_expression : ID
    2                     | CONSTANT
    3                     | STRING_LITERAL
    4                     | '(' expression ')'

    5  postfix_expression : primary_expression
    6                     | postfix_expression '[' expression ']'
    7                     | postfix_expression '(' ')'
    8                     | postfix_expression '(' argument_expression_list ')'
    9                     | postfix_expression '.' ID
   10                     | postfix_expression PTR_OP ID
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

  104  struct_or_union_specifier : struct_or_union ID '{' struct_declaration_list '}'
  105                            | struct_or_union '{' struct_declaration_list '}'
  106                            | struct_or_union ID

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
  122                 | ENUM ID '{' enumerator_list '}'
  123                 | ENUM ID

  124  enumerator_list : enumerator
  125                  | enumerator_list ',' enumerator

  126  enumerator : ID
  127             | ID '=' constant_expression

  128  type_qualifier : CONST
  129                 | VOLATILE

  130  declarator : pointer direct_declarator
  131             | direct_declarator

  132  direct_declarator : ID
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

  152  identifier_list : ID
  153                  | identifier_list ',' ID

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

  179  labeled_statement : ID ':' statement
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

  192  if_statement : IF '(' expression ')' statement

  193  selection_statement : if_statement ELSE statement
  194                      | SWITCH '(' expression ')' statement

  195  iteration_statement : WHILE '(' expression ')' statement
  196                      | DO statement WHILE '(' expression ')' ';'
  197                      | FOR '(' expression_statement expression_statement ')' statement
  198                      | FOR '(' expression_statement expression_statement expression ')' statement

  199  jump_statement : GOTO ID ';'
  200                 | CONTINUE ';'
  201                 | BREAK ';'
  202                 | RETURN ';'
  203                 | RETURN expression ';'

  204  start_translation : translation_unit

  205  translation_unit : external_declaration
  206                   | translation_unit external_declaration

  207  external_declaration : function_definition
  208                       | declaration

  209  function_definition : declaration_specifiers declarator declaration_list compound_statement
  210                      | declaration_specifiers declarator compound_statement
  211                      | declarator declaration_list compound_statement
  212                      | declarator compound_statement


##############################################################################
# States
##############################################################################

state 0
	$accept : . start_translation $end

	'('  shift 1
	'*'  shift 2
	ID  shift 3
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

	type_qualifier  goto 24
	translation_unit  goto 25
	external_declaration  goto 26
	function_definition  goto 27
	enum_specifier  goto 28
	declarator  goto 29
	direct_declarator  goto 30
	pointer  goto 31
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 34
	struct_or_union  goto 35
	declaration  goto 36
	storage_class_specifier  goto 37
	start_translation  goto 38


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 39
	direct_declarator  goto 30
	pointer  goto 31


state 2
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' .  (139)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 139

	type_qualifier  goto 40
	type_qualifier_list  goto 41
	pointer  goto 42


state 3
	direct_declarator : ID .  (132)

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
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID

	'{'  shift 43
	ID  shift 44


state 24
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

	type_qualifier  goto 24
	enum_specifier  goto 28
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 45
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 25
	start_translation : translation_unit .  (204)
	translation_unit : translation_unit . external_declaration

	'('  shift 1
	'*'  shift 2
	ID  shift 3
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
	.  reduce 204

	type_qualifier  goto 24
	external_declaration  goto 46
	function_definition  goto 27
	enum_specifier  goto 28
	declarator  goto 29
	direct_declarator  goto 30
	pointer  goto 31
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 34
	struct_or_union  goto 35
	declaration  goto 36
	storage_class_specifier  goto 37


state 26
	translation_unit : external_declaration .  (205)

	.  reduce 205


state 27
	external_declaration : function_definition .  (207)

	.  reduce 207


state 28
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 29
	function_definition : declarator . compound_statement
	function_definition : declarator . declaration_list compound_statement

	'{'  shift 47
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

	declaration_list  goto 48
	type_qualifier  goto 24
	enum_specifier  goto 28
	compound_statement  goto 49
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 50
	struct_or_union  goto 35
	declaration  goto 51
	storage_class_specifier  goto 37


state 30
	direct_declarator : direct_declarator . '[' ']'
	declarator : direct_declarator .  (131)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'

	'('  shift 52
	'['  shift 53
	.  reduce 131


state 31
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 54


state 32
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

	type_qualifier  goto 24
	enum_specifier  goto 28
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 55
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 33
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 34
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 56
	ID  shift 3

	declarator  goto 57
	direct_declarator  goto 30
	pointer  goto 31
	init_declarator_list  goto 58
	init_declarator  goto 59


state 35
	struct_or_union_specifier : struct_or_union . ID '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID

	'{'  shift 60
	ID  shift 61


state 36
	external_declaration : declaration .  (208)

	.  reduce 208


state 37
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

	type_qualifier  goto 24
	enum_specifier  goto 28
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 62
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 38
	$accept : start_translation . $end  (0)

	$end  accept


state 39
	direct_declarator : '(' declarator . ')'

	')'  shift 63


state 40
	type_qualifier_list : type_qualifier .  (143)

	.  reduce 143


state 41
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (140)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 140

	type_qualifier  goto 64
	pointer  goto 65


state 42
	pointer : '*' pointer .  (141)

	.  reduce 141


state 43
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 66

	enumerator  goto 67
	enumerator_list  goto 68


state 44
	enum_specifier : ENUM ID . '{' enumerator_list '}'
	enum_specifier : ENUM ID .  (123)

	'{'  shift 69
	.  reduce 123


state 45
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 46
	translation_unit : translation_unit external_declaration .  (206)

	.  reduce 206


state 47
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'}'  shift 77
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
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
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	declaration_list  goto 107
	expression_statement  goto 108
	iteration_statement  goto 109
	type_qualifier  goto 24
	jump_statement  goto 110
	enum_specifier  goto 28
	statement  goto 111
	compound_statement  goto 112
	statement_list  goto 113
	labeled_statement  goto 114
	type_specifier  goto 32
	expression  goto 115
	struct_or_union_specifier  goto 33
	exclusive_or_expression  goto 116
	declaration_specifiers  goto 50
	logical_and_expression  goto 117
	struct_or_union  goto 35
	assignment_expression  goto 118
	conditional_expression  goto 119
	declaration  goto 51
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	storage_class_specifier  goto 37
	if_statement  goto 122
	selection_statement  goto 123


state 48
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

	'{'  shift 47
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

	type_qualifier  goto 24
	enum_specifier  goto 28
	compound_statement  goto 124
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 50
	struct_or_union  goto 35
	declaration  goto 125
	storage_class_specifier  goto 37


state 49
	function_definition : declarator compound_statement .  (212)

	.  reduce 212


state 50
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 56
	ID  shift 3

	declarator  goto 126
	direct_declarator  goto 30
	pointer  goto 31
	init_declarator_list  goto 58
	init_declarator  goto 59


state 51
	declaration_list : declaration .  (186)

	.  reduce 186


state 52
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'

	')'  shift 127
	ID  shift 128
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

	type_qualifier  goto 24
	identifier_list  goto 129
	parameter_list  goto 130
	enum_specifier  goto 28
	parameter_declaration  goto 131
	parameter_type_list  goto 132
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 133
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 53
	direct_declarator : direct_declarator '[' . ']'
	direct_declarator : direct_declarator '[' . constant_expression ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	']'  shift 134
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 137
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	constant_expression  goto 138


state 54
	direct_declarator : direct_declarator . '[' ']'
	declarator : pointer direct_declarator .  (130)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'

	'('  shift 52
	'['  shift 53
	.  reduce 130


state 55
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 56
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 57
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (85)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 139
	'{'  shift 47
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

	declaration_list  goto 140
	type_qualifier  goto 24
	enum_specifier  goto 28
	compound_statement  goto 141
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 50
	struct_or_union  goto 35
	declaration  goto 51
	storage_class_specifier  goto 37


state 58
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 142
	';'  shift 143


state 59
	init_declarator_list : init_declarator .  (83)

	.  reduce 83


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

	type_qualifier  goto 144
	specifier_qualifier_list  goto 145
	enum_specifier  goto 28
	struct_declaration  goto 146
	type_specifier  goto 147
	struct_or_union_specifier  goto 33
	struct_declaration_list  goto 148
	struct_or_union  goto 35


state 61
	struct_or_union_specifier : struct_or_union ID . '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union ID .  (106)

	'{'  shift 149
	.  reduce 106


state 62
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 63
	direct_declarator : '(' declarator ')' .  (133)

	.  reduce 133


state 64
	type_qualifier_list : type_qualifier_list type_qualifier .  (144)

	.  reduce 144


state 65
	pointer : '*' type_qualifier_list pointer .  (142)

	.  reduce 142


state 66
	enumerator : ID .  (126)
	enumerator : ID . '=' constant_expression

	'='  shift 150
	.  reduce 126


state 67
	enumerator_list : enumerator .  (124)

	.  reduce 124


state 68
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 151
	'}'  shift 152


state 69
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 66

	enumerator  goto 67
	enumerator_list  goto 153


state 70
	unary_operator : '!' .  (26)

	.  reduce 26


state 71
	unary_operator : '&' .  (21)

	.  reduce 21


state 72
	primary_expression : '(' . expression ')'
	cast_expression : '(' . type_name ')' cast_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
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

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	type_name  goto 154
	type_qualifier  goto 144
	specifier_qualifier_list  goto 155
	enum_specifier  goto 28
	type_specifier  goto 147
	expression  goto 156
	struct_or_union_specifier  goto 33
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	struct_or_union  goto 35
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 73
	unary_operator : '*' .  (22)

	.  reduce 22


state 74
	unary_operator : '+' .  (23)

	.  reduce 23


state 75
	unary_operator : '-' .  (24)

	.  reduce 24


state 76
	expression_statement : ';' .  (190)

	.  reduce 190


state 77
	compound_statement : '{' '}' .  (182)

	.  reduce 182


state 78
	unary_operator : '~' .  (25)

	.  reduce 25


state 79
	primary_expression : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 157
	.  reduce 1


state 80
	primary_expression : CONSTANT .  (2)

	.  reduce 2


state 81
	primary_expression : STRING_LITERAL .  (3)

	.  reduce 3


state 82
	unary_expression : SIZEOF . unary_expression
	unary_expression : SIZEOF . '(' type_name ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 158
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	unary_expression  goto 159
	unary_operator  goto 102


state 83
	unary_expression : INC_OP . unary_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 160
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	unary_expression  goto 161
	unary_operator  goto 102


state 84
	unary_expression : DEC_OP . unary_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 160
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	unary_expression  goto 162
	unary_operator  goto 102


state 85
	labeled_statement : CASE . constant_expression ':' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 137
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	constant_expression  goto 163


state 86
	labeled_statement : DEFAULT . ':' statement

	':'  shift 164


state 87
	if_statement : IF . '(' expression ')' statement

	'('  shift 165


state 88
	selection_statement : SWITCH . '(' expression ')' statement

	'('  shift 166


state 89
	iteration_statement : WHILE . '(' expression ')' statement

	'('  shift 167


state 90
	iteration_statement : DO . statement WHILE '(' expression ')' ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 168
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 91
	iteration_statement : FOR . '(' expression_statement expression_statement ')' statement
	iteration_statement : FOR . '(' expression_statement expression_statement expression ')' statement

	'('  shift 169


state 92
	jump_statement : GOTO . ID ';'

	ID  shift 170


state 93
	jump_statement : CONTINUE . ';'

	';'  shift 171


state 94
	jump_statement : BREAK . ';'

	';'  shift 172


state 95
	jump_statement : RETURN . ';'
	jump_statement : RETURN . expression ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 173
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 174
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 96
	postfix_expression : primary_expression .  (5)

	.  reduce 5


state 97
	postfix_expression : postfix_expression . '[' expression ']'
	postfix_expression : postfix_expression . '(' ')'
	postfix_expression : postfix_expression . '(' argument_expression_list ')'
	postfix_expression : postfix_expression . '.' ID
	postfix_expression : postfix_expression . PTR_OP ID
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (15)

	'('  shift 175
	'.'  shift 176
	'['  shift 177
	PTR_OP  shift 178
	INC_OP  shift 179
	DEC_OP  shift 180
	.  reduce 15


state 98
	multiplicative_expression : cast_expression .  (29)

	.  reduce 29


state 99
	additive_expression : additive_expression . '-' multiplicative_expression
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : additive_expression .  (36)

	'+'  shift 181
	'-'  shift 182
	.  reduce 36


state 100
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : shift_expression .  (39)
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 183
	RIGHT_OP  shift 184
	.  reduce 39


state 101
	cast_expression : unary_expression .  (27)
	assignment_expression : unary_expression . assignment_operator assignment_expression

	'='  shift 185
	MUL_ASSIGN  shift 186
	DIV_ASSIGN  shift 187
	MOD_ASSIGN  shift 188
	ADD_ASSIGN  shift 189
	SUB_ASSIGN  shift 190
	LEFT_ASSIGN  shift 191
	RIGHT_ASSIGN  shift 192
	AND_ASSIGN  shift 193
	XOR_ASSIGN  shift 194
	OR_ASSIGN  shift 195
	.  reduce 27

	assignment_operator  goto 196


state 102
	unary_expression : unary_operator . cast_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 197
	unary_expression  goto 136
	unary_operator  goto 102


state 103
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : multiplicative_expression .  (33)
	multiplicative_expression : multiplicative_expression . '/' cast_expression

	'%'  shift 198
	'*'  shift 199
	'/'  shift 200
	.  reduce 33


state 104
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	equality_expression : relational_expression .  (44)
	relational_expression : relational_expression . LE_OP shift_expression

	'<'  shift 201
	'>'  shift 202
	LE_OP  shift 203
	GE_OP  shift 204
	.  reduce 44


state 105
	equality_expression : equality_expression . EQ_OP relational_expression
	and_expression : equality_expression .  (47)
	equality_expression : equality_expression . NE_OP relational_expression

	EQ_OP  shift 205
	NE_OP  shift 206
	.  reduce 47


state 106
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : and_expression .  (49)

	'&'  shift 207
	.  reduce 49


state 107
	compound_statement : '{' declaration_list . statement_list '}'
	compound_statement : '{' declaration_list . '}'
	declaration_list : declaration_list . declaration

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'}'  shift 208
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
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
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	type_qualifier  goto 24
	jump_statement  goto 110
	enum_specifier  goto 28
	statement  goto 111
	compound_statement  goto 112
	statement_list  goto 209
	labeled_statement  goto 114
	type_specifier  goto 32
	expression  goto 115
	struct_or_union_specifier  goto 33
	exclusive_or_expression  goto 116
	declaration_specifiers  goto 50
	logical_and_expression  goto 117
	struct_or_union  goto 35
	assignment_expression  goto 118
	conditional_expression  goto 119
	declaration  goto 125
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	storage_class_specifier  goto 37
	if_statement  goto 122
	selection_statement  goto 123


state 108
	statement : expression_statement .  (175)

	.  reduce 175


state 109
	statement : iteration_statement .  (177)

	.  reduce 177


state 110
	statement : jump_statement .  (178)

	.  reduce 178


state 111
	statement_list : statement .  (188)

	.  reduce 188


state 112
	statement : compound_statement .  (174)

	.  reduce 174


state 113
	statement_list : statement_list . statement
	compound_statement : '{' statement_list . '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'}'  shift 210
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 211
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 114
	statement : labeled_statement .  (173)

	.  reduce 173


state 115
	expression : expression . ',' assignment_expression
	expression_statement : expression . ';'

	','  shift 212
	';'  shift 213


state 116
	inclusive_or_expression : exclusive_or_expression .  (51)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 214
	.  reduce 51


state 117
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_and_expression .  (55)

	AND_OP  shift 215
	.  reduce 55


state 118
	expression : assignment_expression .  (72)

	.  reduce 72


state 119
	assignment_expression : conditional_expression .  (59)

	.  reduce 59


state 120
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : inclusive_or_expression .  (53)

	'|'  shift 216
	.  reduce 53


state 121
	conditional_expression : logical_or_expression . '?' expression ':' conditional_expression
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression
	conditional_expression : logical_or_expression .  (57)

	'?'  shift 217
	OR_OP  shift 218
	.  reduce 57


state 122
	selection_statement : if_statement . ELSE statement

	ELSE  shift 219


state 123
	statement : selection_statement .  (176)

	.  reduce 176


state 124
	function_definition : declarator declaration_list compound_statement .  (211)

	.  reduce 211


state 125
	declaration_list : declaration_list declaration .  (187)

	.  reduce 187


state 126
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (85)

	'='  shift 139
	.  reduce 85


state 127
	direct_declarator : direct_declarator '(' ')' .  (138)

	.  reduce 138


state 128
	identifier_list : ID .  (152)

	.  reduce 152


state 129
	direct_declarator : direct_declarator '(' identifier_list . ')'
	identifier_list : identifier_list . ',' ID

	')'  shift 220
	','  shift 221


state 130
	parameter_type_list : parameter_list .  (145)
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 222
	.  reduce 145


state 131
	parameter_list : parameter_declaration .  (147)

	.  reduce 147


state 132
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 223


state 133
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (151)
	parameter_declaration : declaration_specifiers . declarator

	'('  shift 224
	'*'  shift 2
	'['  shift 225
	ID  shift 3
	.  reduce 151

	direct_abstract_declarator  goto 226
	declarator  goto 227
	abstract_declarator  goto 228
	direct_declarator  goto 30
	pointer  goto 229


state 134
	direct_declarator : direct_declarator '[' ']' .  (135)

	.  reduce 135


state 135
	primary_expression : ID .  (1)

	.  reduce 1


state 136
	cast_expression : unary_expression .  (27)

	.  reduce 27


state 137
	constant_expression : conditional_expression .  (74)

	.  reduce 74


state 138
	direct_declarator : direct_declarator '[' constant_expression . ']'

	']'  shift 230


state 139
	init_declarator : declarator '=' . initializer

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 231
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	initializer  goto 232
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 233
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 140
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

	'{'  shift 47
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

	type_qualifier  goto 24
	enum_specifier  goto 28
	compound_statement  goto 234
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 50
	struct_or_union  goto 35
	declaration  goto 125
	storage_class_specifier  goto 37


state 141
	function_definition : declaration_specifiers declarator compound_statement .  (210)

	.  reduce 210


state 142
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 126
	direct_declarator  goto 30
	pointer  goto 31
	init_declarator  goto 235


state 143
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


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

	type_qualifier  goto 144
	specifier_qualifier_list  goto 236
	enum_specifier  goto 28
	type_specifier  goto 147
	struct_or_union_specifier  goto 33
	struct_or_union  goto 35


state 145
	struct_declaration : specifier_qualifier_list . struct_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	':'  shift 237
	ID  shift 3

	struct_declarator_list  goto 238
	struct_declarator  goto 239
	declarator  goto 240
	direct_declarator  goto 30
	pointer  goto 31


state 146
	struct_declaration_list : struct_declaration .  (109)

	.  reduce 109


state 147
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

	type_qualifier  goto 144
	specifier_qualifier_list  goto 241
	enum_specifier  goto 28
	type_specifier  goto 147
	struct_or_union_specifier  goto 33
	struct_or_union  goto 35


state 148
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list . '}'

	'}'  shift 242
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

	type_qualifier  goto 144
	specifier_qualifier_list  goto 145
	enum_specifier  goto 28
	struct_declaration  goto 243
	type_specifier  goto 147
	struct_or_union_specifier  goto 33
	struct_or_union  goto 35


state 149
	struct_or_union_specifier : struct_or_union ID '{' . struct_declaration_list '}'

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

	type_qualifier  goto 144
	specifier_qualifier_list  goto 145
	enum_specifier  goto 28
	struct_declaration  goto 146
	type_specifier  goto 147
	struct_or_union_specifier  goto 33
	struct_declaration_list  goto 244
	struct_or_union  goto 35


state 150
	enumerator : ID '=' . constant_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 137
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	constant_expression  goto 245


state 151
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 66

	enumerator  goto 246


state 152
	enum_specifier : ENUM '{' enumerator_list '}' .  (121)

	.  reduce 121


state 153
	enum_specifier : ENUM ID '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 151
	'}'  shift 247


state 154
	cast_expression : '(' type_name . ')' cast_expression

	')'  shift 248


state 155
	type_name : specifier_qualifier_list .  (154)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 249
	'*'  shift 2
	'['  shift 225
	.  reduce 154

	direct_abstract_declarator  goto 226
	abstract_declarator  goto 250
	pointer  goto 251


state 156
	primary_expression : '(' expression . ')'
	expression : expression . ',' assignment_expression

	')'  shift 252
	','  shift 212


state 157
	labeled_statement : ID ':' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 253
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 158
	primary_expression : '(' . expression ')'
	unary_expression : SIZEOF '(' . type_name ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
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

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	type_name  goto 254
	type_qualifier  goto 144
	specifier_qualifier_list  goto 155
	enum_specifier  goto 28
	type_specifier  goto 147
	expression  goto 156
	struct_or_union_specifier  goto 33
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	struct_or_union  goto 35
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 159
	unary_expression : SIZEOF unary_expression .  (19)

	.  reduce 19


state 160
	primary_expression : '(' . expression ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 156
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 161
	unary_expression : INC_OP unary_expression .  (16)

	.  reduce 16


state 162
	unary_expression : DEC_OP unary_expression .  (17)

	.  reduce 17


state 163
	labeled_statement : CASE constant_expression . ':' statement

	':'  shift 255


state 164
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 256
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 165
	if_statement : IF '(' . expression ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 257
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 166
	selection_statement : SWITCH '(' . expression ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 258
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 167
	iteration_statement : WHILE '(' . expression ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 259
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 168
	iteration_statement : DO statement . WHILE '(' expression ')' ';'

	WHILE  shift 260


state 169
	iteration_statement : FOR '(' . expression_statement expression_statement ')' statement
	iteration_statement : FOR '(' . expression_statement expression_statement expression ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 261
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 170
	jump_statement : GOTO ID . ';'

	';'  shift 262


state 171
	jump_statement : CONTINUE ';' .  (200)

	.  reduce 200


state 172
	jump_statement : BREAK ';' .  (201)

	.  reduce 201


state 173
	jump_statement : RETURN ';' .  (202)

	.  reduce 202


state 174
	expression : expression . ',' assignment_expression
	jump_statement : RETURN expression . ';'

	','  shift 212
	';'  shift 263


state 175
	postfix_expression : postfix_expression '(' . ')'
	postfix_expression : postfix_expression '(' . argument_expression_list ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	')'  shift 264
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	argument_expression_list  goto 265
	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 266
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 176
	postfix_expression : postfix_expression '.' . ID

	ID  shift 267


state 177
	postfix_expression : postfix_expression '[' . expression ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 268
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 178
	postfix_expression : postfix_expression PTR_OP . ID

	ID  shift 269


state 179
	postfix_expression : postfix_expression INC_OP .  (11)

	.  reduce 11


state 180
	postfix_expression : postfix_expression DEC_OP .  (12)

	.  reduce 12


state 181
	additive_expression : additive_expression '+' . multiplicative_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 270


state 182
	additive_expression : additive_expression '-' . multiplicative_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 271


state 183
	shift_expression : shift_expression LEFT_OP . additive_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 272
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103


state 184
	shift_expression : shift_expression RIGHT_OP . additive_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 273
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103


state 185
	assignment_operator : '=' .  (61)

	.  reduce 61


state 186
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 187
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 188
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 189
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 190
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 191
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 192
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 193
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 194
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 195
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 196
	assignment_expression : unary_expression assignment_operator . assignment_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 274
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 197
	unary_expression : unary_operator cast_expression .  (18)

	.  reduce 18


state 198
	multiplicative_expression : multiplicative_expression '%' . cast_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 275
	unary_expression  goto 136
	unary_operator  goto 102


state 199
	multiplicative_expression : multiplicative_expression '*' . cast_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 276
	unary_expression  goto 136
	unary_operator  goto 102


state 200
	multiplicative_expression : multiplicative_expression '/' . cast_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 277
	unary_expression  goto 136
	unary_operator  goto 102


state 201
	relational_expression : relational_expression '<' . shift_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 278
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103


state 202
	relational_expression : relational_expression '>' . shift_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 279
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103


state 203
	relational_expression : relational_expression LE_OP . shift_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 280
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103


state 204
	relational_expression : relational_expression GE_OP . shift_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 281
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103


state 205
	equality_expression : equality_expression EQ_OP . relational_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 282


state 206
	equality_expression : equality_expression NE_OP . relational_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 283


state 207
	and_expression : and_expression '&' . equality_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 284


state 208
	compound_statement : '{' declaration_list '}' .  (184)

	.  reduce 184


state 209
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'}'  shift 285
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 211
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 210
	compound_statement : '{' statement_list '}' .  (183)

	.  reduce 183


state 211
	statement_list : statement_list statement .  (189)

	.  reduce 189


state 212
	expression : expression ',' . assignment_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 286
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 213
	expression_statement : expression ';' .  (191)

	.  reduce 191


state 214
	exclusive_or_expression : exclusive_or_expression '^' . and_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 287


state 215
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	inclusive_or_expression  goto 288


state 216
	inclusive_or_expression : inclusive_or_expression '|' . exclusive_or_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 289


state 217
	conditional_expression : logical_or_expression '?' . expression ':' conditional_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 290
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 218
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 291
	inclusive_or_expression  goto 120


state 219
	selection_statement : if_statement ELSE . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 292
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 220
	direct_declarator : direct_declarator '(' identifier_list ')' .  (137)

	.  reduce 137


state 221
	identifier_list : identifier_list ',' . ID

	ID  shift 293


state 222
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
	ELLIPSIS  shift 294

	type_qualifier  goto 24
	enum_specifier  goto 28
	parameter_declaration  goto 295
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 133
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 223
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (136)

	.  reduce 136


state 224
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'

	'('  shift 224
	')'  shift 296
	'*'  shift 2
	'['  shift 225
	ID  shift 3
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

	type_qualifier  goto 24
	parameter_list  goto 130
	enum_specifier  goto 28
	direct_abstract_declarator  goto 226
	parameter_declaration  goto 131
	declarator  goto 39
	parameter_type_list  goto 297
	abstract_declarator  goto 298
	direct_declarator  goto 30
	pointer  goto 229
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 133
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 225
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_expression ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	']'  shift 299
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 137
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	constant_expression  goto 300


state 226
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	abstract_declarator : direct_abstract_declarator .  (157)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'

	'('  shift 301
	'['  shift 302
	.  reduce 157


state 227
	parameter_declaration : declaration_specifiers declarator .  (149)

	.  reduce 149


state 228
	parameter_declaration : declaration_specifiers abstract_declarator .  (150)

	.  reduce 150


state 229
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 224
	'['  shift 225
	ID  shift 3
	.  reduce 156

	direct_abstract_declarator  goto 303
	direct_declarator  goto 54


state 230
	direct_declarator : direct_declarator '[' constant_expression ']' .  (134)

	.  reduce 134


state 231
	initializer : '{' . initializer_list ',' '}'
	initializer : '{' . initializer_list '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 231
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	initializer  goto 304
	initializer_list  goto 305
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 233
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 232
	init_declarator : declarator '=' initializer .  (86)

	.  reduce 86


state 233
	initializer : assignment_expression .  (168)

	.  reduce 168


state 234
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (209)

	.  reduce 209


state 235
	init_declarator_list : init_declarator_list ',' init_declarator .  (84)

	.  reduce 84


state 236
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (114)

	.  reduce 114


state 237
	struct_declarator : ':' . constant_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 137
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	constant_expression  goto 306


state 238
	struct_declaration : specifier_qualifier_list struct_declarator_list . ';'
	struct_declarator_list : struct_declarator_list . ',' struct_declarator

	','  shift 307
	';'  shift 308


state 239
	struct_declarator_list : struct_declarator .  (116)

	.  reduce 116


state 240
	struct_declarator : declarator . ':' constant_expression
	struct_declarator : declarator .  (118)

	':'  shift 309
	.  reduce 118


state 241
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (112)

	.  reduce 112


state 242
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}' .  (105)

	.  reduce 105


state 243
	struct_declaration_list : struct_declaration_list struct_declaration .  (110)

	.  reduce 110


state 244
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union ID '{' struct_declaration_list . '}'

	'}'  shift 310
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

	type_qualifier  goto 144
	specifier_qualifier_list  goto 145
	enum_specifier  goto 28
	struct_declaration  goto 243
	type_specifier  goto 147
	struct_or_union_specifier  goto 33
	struct_or_union  goto 35


state 245
	enumerator : ID '=' constant_expression .  (127)

	.  reduce 127


state 246
	enumerator_list : enumerator_list ',' enumerator .  (125)

	.  reduce 125


state 247
	enum_specifier : ENUM ID '{' enumerator_list '}' .  (122)

	.  reduce 122


state 248
	cast_expression : '(' type_name ')' . cast_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 311
	unary_expression  goto 136
	unary_operator  goto 102


state 249
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'

	'('  shift 249
	')'  shift 296
	'*'  shift 2
	'['  shift 225
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

	type_qualifier  goto 24
	parameter_list  goto 130
	enum_specifier  goto 28
	direct_abstract_declarator  goto 226
	parameter_declaration  goto 131
	parameter_type_list  goto 297
	abstract_declarator  goto 298
	pointer  goto 251
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 133
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 250
	type_name : specifier_qualifier_list abstract_declarator .  (155)

	.  reduce 155


state 251
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 249
	'['  shift 225
	.  reduce 156

	direct_abstract_declarator  goto 303


state 252
	primary_expression : '(' expression ')' .  (4)

	.  reduce 4


state 253
	labeled_statement : ID ':' statement .  (179)

	.  reduce 179


state 254
	unary_expression : SIZEOF '(' type_name . ')'

	')'  shift 312


state 255
	labeled_statement : CASE constant_expression ':' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 313
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 256
	labeled_statement : DEFAULT ':' statement .  (181)

	.  reduce 181


state 257
	expression : expression . ',' assignment_expression
	if_statement : IF '(' expression . ')' statement

	')'  shift 314
	','  shift 212


state 258
	expression : expression . ',' assignment_expression
	selection_statement : SWITCH '(' expression . ')' statement

	')'  shift 315
	','  shift 212


state 259
	expression : expression . ',' assignment_expression
	iteration_statement : WHILE '(' expression . ')' statement

	')'  shift 316
	','  shift 212


state 260
	iteration_statement : DO statement WHILE . '(' expression ')' ';'

	'('  shift 317


state 261
	iteration_statement : FOR '(' expression_statement . expression_statement ')' statement
	iteration_statement : FOR '(' expression_statement . expression_statement expression ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 318
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 262
	jump_statement : GOTO ID ';' .  (199)

	.  reduce 199


state 263
	jump_statement : RETURN expression ';' .  (203)

	.  reduce 203


state 264
	postfix_expression : postfix_expression '(' ')' .  (7)

	.  reduce 7


state 265
	postfix_expression : postfix_expression '(' argument_expression_list . ')'
	argument_expression_list : argument_expression_list . ',' assignment_expression

	')'  shift 319
	','  shift 320


state 266
	argument_expression_list : assignment_expression .  (13)

	.  reduce 13


state 267
	postfix_expression : postfix_expression '.' ID .  (9)

	.  reduce 9


state 268
	postfix_expression : postfix_expression '[' expression . ']'
	expression : expression . ',' assignment_expression

	','  shift 212
	']'  shift 321


state 269
	postfix_expression : postfix_expression PTR_OP ID .  (10)

	.  reduce 10


state 270
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	additive_expression : additive_expression '+' multiplicative_expression .  (34)

	'%'  shift 198
	'*'  shift 199
	'/'  shift 200
	.  reduce 34


state 271
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	additive_expression : additive_expression '-' multiplicative_expression .  (35)

	'%'  shift 198
	'*'  shift 199
	'/'  shift 200
	.  reduce 35


state 272
	additive_expression : additive_expression . '-' multiplicative_expression
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : shift_expression LEFT_OP additive_expression .  (37)

	'+'  shift 181
	'-'  shift 182
	.  reduce 37


state 273
	additive_expression : additive_expression . '-' multiplicative_expression
	shift_expression : shift_expression RIGHT_OP additive_expression .  (38)
	additive_expression : additive_expression . '+' multiplicative_expression

	'+'  shift 181
	'-'  shift 182
	.  reduce 38


state 274
	assignment_expression : unary_expression assignment_operator assignment_expression .  (60)

	.  reduce 60


state 275
	multiplicative_expression : multiplicative_expression '%' cast_expression .  (32)

	.  reduce 32


state 276
	multiplicative_expression : multiplicative_expression '*' cast_expression .  (30)

	.  reduce 30


state 277
	multiplicative_expression : multiplicative_expression '/' cast_expression .  (31)

	.  reduce 31


state 278
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '<' shift_expression .  (40)

	LEFT_OP  shift 183
	RIGHT_OP  shift 184
	.  reduce 40


state 279
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '>' shift_expression .  (41)

	LEFT_OP  shift 183
	RIGHT_OP  shift 184
	.  reduce 41


state 280
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression LE_OP shift_expression .  (42)

	LEFT_OP  shift 183
	RIGHT_OP  shift 184
	.  reduce 42


state 281
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (43)

	LEFT_OP  shift 183
	RIGHT_OP  shift 184
	.  reduce 43


state 282
	equality_expression : equality_expression EQ_OP relational_expression .  (45)
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . LE_OP shift_expression

	'<'  shift 201
	'>'  shift 202
	LE_OP  shift 203
	GE_OP  shift 204
	.  reduce 45


state 283
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	equality_expression : equality_expression NE_OP relational_expression .  (46)

	'<'  shift 201
	'>'  shift 202
	LE_OP  shift 203
	GE_OP  shift 204
	.  reduce 46


state 284
	equality_expression : equality_expression . EQ_OP relational_expression
	and_expression : and_expression '&' equality_expression .  (48)
	equality_expression : equality_expression . NE_OP relational_expression

	EQ_OP  shift 205
	NE_OP  shift 206
	.  reduce 48


state 285
	compound_statement : '{' declaration_list statement_list '}' .  (185)

	.  reduce 185


state 286
	expression : expression ',' assignment_expression .  (73)

	.  reduce 73


state 287
	exclusive_or_expression : exclusive_or_expression '^' and_expression .  (50)
	and_expression : and_expression . '&' equality_expression

	'&'  shift 207
	.  reduce 50


state 288
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (54)

	'|'  shift 216
	.  reduce 54


state 289
	inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression .  (52)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 214
	.  reduce 52


state 290
	conditional_expression : logical_or_expression '?' expression . ':' conditional_expression
	expression : expression . ',' assignment_expression

	','  shift 212
	':'  shift 322


state 291
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (56)

	AND_OP  shift 215
	.  reduce 56


state 292
	selection_statement : if_statement ELSE statement .  (193)

	.  reduce 193


state 293
	identifier_list : identifier_list ',' ID .  (153)

	.  reduce 153


state 294
	parameter_type_list : parameter_list ',' ELLIPSIS .  (146)

	.  reduce 146


state 295
	parameter_list : parameter_list ',' parameter_declaration .  (148)

	.  reduce 148


state 296
	direct_abstract_declarator : '(' ')' .  (164)

	.  reduce 164


state 297
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 323


state 298
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 324


state 299
	direct_abstract_declarator : '[' ']' .  (160)

	.  reduce 160


state 300
	direct_abstract_declarator : '[' constant_expression . ']'

	']'  shift 325


state 301
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'

	')'  shift 326
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

	type_qualifier  goto 24
	parameter_list  goto 130
	enum_specifier  goto 28
	parameter_declaration  goto 131
	parameter_type_list  goto 327
	type_specifier  goto 32
	struct_or_union_specifier  goto 33
	declaration_specifiers  goto 133
	struct_or_union  goto 35
	storage_class_specifier  goto 37


state 302
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_expression ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	']'  shift 328
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 137
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	constant_expression  goto 329


state 303
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	abstract_declarator : pointer direct_abstract_declarator .  (158)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'

	'('  shift 301
	'['  shift 302
	.  reduce 158


state 304
	initializer_list : initializer .  (171)

	.  reduce 171


state 305
	initializer : '{' initializer_list . ',' '}'
	initializer : '{' initializer_list . '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 330
	'}'  shift 331


state 306
	struct_declarator : ':' constant_expression .  (119)

	.  reduce 119


state 307
	struct_declarator_list : struct_declarator_list ',' . struct_declarator

	'('  shift 1
	'*'  shift 2
	':'  shift 237
	ID  shift 3

	struct_declarator  goto 332
	declarator  goto 240
	direct_declarator  goto 30
	pointer  goto 31


state 308
	struct_declaration : specifier_qualifier_list struct_declarator_list ';' .  (111)

	.  reduce 111


state 309
	struct_declarator : declarator ':' . constant_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 137
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	constant_expression  goto 333


state 310
	struct_or_union_specifier : struct_or_union ID '{' struct_declaration_list '}' .  (104)

	.  reduce 104


state 311
	cast_expression : '(' type_name ')' cast_expression .  (28)

	.  reduce 28


state 312
	unary_expression : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 313
	labeled_statement : CASE constant_expression ':' statement .  (180)

	.  reduce 180


state 314
	if_statement : IF '(' expression ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 334
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 315
	selection_statement : SWITCH '(' expression ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 335
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 316
	iteration_statement : WHILE '(' expression ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 336
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 317
	iteration_statement : DO statement WHILE '(' . expression ')' ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 337
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 318
	iteration_statement : FOR '(' expression_statement expression_statement . ')' statement
	iteration_statement : FOR '(' expression_statement expression_statement . expression ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	')'  shift 338
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression  goto 339
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 319
	postfix_expression : postfix_expression '(' argument_expression_list ')' .  (8)

	.  reduce 8


state 320
	argument_expression_list : argument_expression_list ',' . assignment_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 340
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 321
	postfix_expression : postfix_expression '[' expression ']' .  (6)

	.  reduce 6


state 322
	conditional_expression : logical_or_expression '?' expression ':' . conditional_expression

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 136
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	conditional_expression  goto 341
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 323
	direct_abstract_declarator : '(' parameter_type_list ')' .  (165)

	.  reduce 165


state 324
	direct_abstract_declarator : '(' abstract_declarator ')' .  (159)

	.  reduce 159


state 325
	direct_abstract_declarator : '[' constant_expression ']' .  (161)

	.  reduce 161


state 326
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (166)

	.  reduce 166


state 327
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 342


state 328
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (162)

	.  reduce 162


state 329
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression . ']'

	']'  shift 343


state 330
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 231
	'}'  shift 344
	'~'  shift 78
	ID  shift 135
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	initializer  goto 345
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 233
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121


state 331
	initializer : '{' initializer_list '}' .  (169)

	.  reduce 169


state 332
	struct_declarator_list : struct_declarator_list ',' struct_declarator .  (117)

	.  reduce 117


state 333
	struct_declarator : declarator ':' constant_expression .  (120)

	.  reduce 120


state 334
	if_statement : IF '(' expression ')' statement .  (192)

	.  reduce 192


state 335
	selection_statement : SWITCH '(' expression ')' statement .  (194)

	.  reduce 194


state 336
	iteration_statement : WHILE '(' expression ')' statement .  (195)

	.  reduce 195


state 337
	expression : expression . ',' assignment_expression
	iteration_statement : DO statement WHILE '(' expression . ')' ';'

	')'  shift 346
	','  shift 212


state 338
	iteration_statement : FOR '(' expression_statement expression_statement ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 347
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 339
	expression : expression . ',' assignment_expression
	iteration_statement : FOR '(' expression_statement expression_statement expression . ')' statement

	')'  shift 348
	','  shift 212


state 340
	argument_expression_list : argument_expression_list ',' assignment_expression .  (14)

	.  reduce 14


state 341
	conditional_expression : logical_or_expression '?' expression ':' conditional_expression .  (58)

	.  reduce 58


state 342
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (167)

	.  reduce 167


state 343
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']' .  (163)

	.  reduce 163


state 344
	initializer : '{' initializer_list ',' '}' .  (170)

	.  reduce 170


state 345
	initializer_list : initializer_list ',' initializer .  (172)

	.  reduce 172


state 346
	iteration_statement : DO statement WHILE '(' expression ')' . ';'

	';'  shift 349


state 347
	iteration_statement : FOR '(' expression_statement expression_statement ')' statement .  (197)

	.  reduce 197


state 348
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 47
	'~'  shift 78
	ID  shift 79
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84
	CASE  shift 85
	DEFAULT  shift 86
	IF  shift 87
	SWITCH  shift 88
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	primary_expression  goto 96
	postfix_expression  goto 97
	cast_expression  goto 98
	additive_expression  goto 99
	shift_expression  goto 100
	unary_expression  goto 101
	unary_operator  goto 102
	multiplicative_expression  goto 103
	relational_expression  goto 104
	equality_expression  goto 105
	and_expression  goto 106
	expression_statement  goto 108
	iteration_statement  goto 109
	jump_statement  goto 110
	statement  goto 350
	compound_statement  goto 112
	labeled_statement  goto 114
	expression  goto 115
	exclusive_or_expression  goto 116
	logical_and_expression  goto 117
	assignment_expression  goto 118
	conditional_expression  goto 119
	inclusive_or_expression  goto 120
	logical_or_expression  goto 121
	if_statement  goto 122
	selection_statement  goto 123


state 349
	iteration_statement : DO statement WHILE '(' expression ')' ';' .  (196)

	.  reduce 196


state 350
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement .  (198)

	.  reduce 198


##############################################################################
# Summary
##############################################################################

84 token(s), 66 nonterminal(s)
213 grammar rule(s), 351 state(s)


##############################################################################
# End of File
##############################################################################
