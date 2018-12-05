#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 57 of your 30 day trial period.
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
# Time: 18:19:24
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : translation_unit $end

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
  171              |

  172  initializer_list : initializer
  173                   | initializer_list ',' initializer

  174  other : labeled_statement
  175        | compound_statement
  176        | expression_statement
  177        | iteration_statement
  178        | jump_statement

  179  statement : labeled_statement
  180            | compound_statement
  181            | expression_statement
  182            | selection_statement
  183            | iteration_statement
  184            | jump_statement

  185  labeled_statement : ID ':' statement
  186                    | CASE constant_expression ':' statement
  187                    | DEFAULT ':' statement

  188  compound_statement : '{' '}'
  189                     | '{' statement_list '}'
  190                     | '{' declaration_list '}'
  191                     | '{' declaration_list statement_list '}'

  192  declaration_list : declaration
  193                   | declaration_list declaration

  194  statement_list : statement
  195                 | statement_list statement

  196  expression_statement : ';'
  197                       | expression ';'

  198  stmt : matched_statement
  199       | open_statement

  200  matched_statement : IF '(' expression ')' matched_statement ELSE matched_statement
  201                    | other

  202  open_statement : IF '(' expression ')' stmt
  203                 | IF '(' expression ')' matched_statement ELSE open_statement

  204  selection_statement : stmt
  205                      | SWITCH '(' expression ')' statement

  206  iteration_statement : WHILE '(' expression ')' statement
  207                      | DO statement WHILE '(' expression ')' ';'
  208                      | FOR '(' expression_statement expression_statement ')' statement
  209                      | FOR '(' expression_statement expression_statement expression ')' statement

  210  jump_statement : GOTO ID ';'
  211                 | CONTINUE ';'
  212                 | BREAK ';'
  213                 | RETURN ';'
  214                 | RETURN expression ';'

  215  translation_unit : external_declaration
  216                   | translation_unit external_declaration

  217  external_declaration : function_definition
  218                       | declaration

  219  function_definition : declaration_specifiers declarator declaration_list compound_statement
  220                      | declaration_specifiers declarator compound_statement
  221                      | declarator declaration_list compound_statement
  222                      | declarator compound_statement


##############################################################################
# States
##############################################################################

state 0
	$accept : . translation_unit $end

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

	direct_declarator  goto 24
	pointer  goto 25
	declaration_specifiers  goto 26
	declarator  goto 27
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	declaration  goto 32
	enum_specifier  goto 33
	type_qualifier  goto 34
	function_definition  goto 35
	translation_unit  goto 36
	external_declaration  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_declarator  goto 24
	pointer  goto 25
	declarator  goto 38


state 2
	pointer : '*' . type_qualifier_list
	pointer : '*' .  (139)
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 139

	pointer  goto 39
	type_qualifier_list  goto 40
	type_qualifier  goto 41


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
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . ID

	'{'  shift 42
	ID  shift 43


state 24
	direct_declarator : direct_declarator . '[' ']'
	declarator : direct_declarator .  (131)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'

	'('  shift 44
	'['  shift 45
	.  reduce 131


state 25
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 46


state 26
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 47
	ID  shift 3

	direct_declarator  goto 24
	pointer  goto 25
	declarator  goto 48
	init_declarator  goto 49
	init_declarator_list  goto 50


state 27
	function_definition : declarator . compound_statement
	function_definition : declarator . declaration_list compound_statement

	'{'  shift 51
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

	declaration_specifiers  goto 52
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	declaration  goto 53
	enum_specifier  goto 33
	type_qualifier  goto 34
	declaration_list  goto 54
	compound_statement  goto 55


state 28
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 29
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

	declaration_specifiers  goto 56
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	type_qualifier  goto 34


state 30
	struct_or_union_specifier : struct_or_union . ID '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_specifier : struct_or_union . '{' struct_declaration_list '}'

	'{'  shift 57
	ID  shift 58


state 31
	declaration_specifiers : type_specifier . declaration_specifiers
	declaration_specifiers : type_specifier .  (79)

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

	declaration_specifiers  goto 59
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	type_qualifier  goto 34


state 32
	external_declaration : declaration .  (218)

	.  reduce 218


state 33
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 34
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

	declaration_specifiers  goto 60
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	type_qualifier  goto 34


state 35
	external_declaration : function_definition .  (217)

	.  reduce 217


state 36
	$accept : translation_unit . $end  (0)
	translation_unit : translation_unit . external_declaration

	$end  accept
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

	direct_declarator  goto 24
	pointer  goto 25
	declaration_specifiers  goto 26
	declarator  goto 27
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	declaration  goto 32
	enum_specifier  goto 33
	type_qualifier  goto 34
	function_definition  goto 35
	external_declaration  goto 61


state 37
	translation_unit : external_declaration .  (215)

	.  reduce 215


state 38
	direct_declarator : '(' declarator . ')'

	')'  shift 62


state 39
	pointer : '*' pointer .  (141)

	.  reduce 141


state 40
	pointer : '*' type_qualifier_list .  (140)
	pointer : '*' type_qualifier_list . pointer
	type_qualifier_list : type_qualifier_list . type_qualifier

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 140

	pointer  goto 63
	type_qualifier  goto 64


state 41
	type_qualifier_list : type_qualifier .  (143)

	.  reduce 143


state 42
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 65

	enumerator_list  goto 66
	enumerator  goto 67


state 43
	enum_specifier : ENUM ID . '{' enumerator_list '}'
	enum_specifier : ENUM ID .  (123)

	'{'  shift 68
	.  reduce 123


state 44
	direct_declarator : direct_declarator '(' . identifier_list ')'
	direct_declarator : direct_declarator '(' . ')'
	direct_declarator : direct_declarator '(' . parameter_type_list ')'

	')'  shift 69
	ID  shift 70
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

	declaration_specifiers  goto 71
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	parameter_list  goto 72
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	parameter_type_list  goto 73
	type_qualifier  goto 34
	identifier_list  goto 74
	parameter_declaration  goto 75


state 45
	direct_declarator : direct_declarator '[' . ']'
	direct_declarator : direct_declarator '[' . constant_expression ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	']'  shift 82
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	constant_expression  goto 102
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 46
	direct_declarator : direct_declarator . '[' ']'
	declarator : pointer direct_declarator .  (130)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'

	'('  shift 44
	'['  shift 45
	.  reduce 130


state 47
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 48
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (85)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 107
	'{'  shift 51
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

	declaration_specifiers  goto 52
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	declaration  goto 53
	enum_specifier  goto 33
	type_qualifier  goto 34
	declaration_list  goto 108
	compound_statement  goto 109


state 49
	init_declarator_list : init_declarator .  (83)

	.  reduce 83


state 50
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 110
	';'  shift 111


state 51
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list '}'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'}'  shift 113
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
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
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	declaration_specifiers  goto 52
	expression  goto 127
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	struct_or_union  goto 30
	type_specifier  goto 31
	conditional_expression  goto 128
	declaration  goto 53
	enum_specifier  goto 33
	type_qualifier  goto 34
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	declaration_list  goto 130
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 136
	statement_list  goto 137
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 52
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 47
	ID  shift 3

	direct_declarator  goto 24
	pointer  goto 25
	declarator  goto 143
	init_declarator  goto 49
	init_declarator_list  goto 50


state 53
	declaration_list : declaration .  (192)

	.  reduce 192


state 54
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

	'{'  shift 51
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

	declaration_specifiers  goto 52
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	declaration  goto 144
	enum_specifier  goto 33
	type_qualifier  goto 34
	compound_statement  goto 145


state 55
	function_definition : declarator compound_statement .  (222)

	.  reduce 222


state 56
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 57
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

	struct_or_union_specifier  goto 28
	struct_declaration_list  goto 146
	specifier_qualifier_list  goto 147
	struct_or_union  goto 30
	type_specifier  goto 148
	enum_specifier  goto 33
	type_qualifier  goto 149
	struct_declaration  goto 150


state 58
	struct_or_union_specifier : struct_or_union ID . '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union ID .  (106)

	'{'  shift 151
	.  reduce 106


state 59
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 60
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 61
	translation_unit : translation_unit external_declaration .  (216)

	.  reduce 216


state 62
	direct_declarator : '(' declarator ')' .  (133)

	.  reduce 133


state 63
	pointer : '*' type_qualifier_list pointer .  (142)

	.  reduce 142


state 64
	type_qualifier_list : type_qualifier_list type_qualifier .  (144)

	.  reduce 144


state 65
	enumerator : ID .  (126)
	enumerator : ID . '=' constant_expression

	'='  shift 152
	.  reduce 126


state 66
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 153
	'}'  shift 154


state 67
	enumerator_list : enumerator .  (124)

	.  reduce 124


state 68
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 65

	enumerator_list  goto 155
	enumerator  goto 67


state 69
	direct_declarator : direct_declarator '(' ')' .  (138)

	.  reduce 138


state 70
	identifier_list : ID .  (152)

	.  reduce 152


state 71
	parameter_declaration : declaration_specifiers .  (151)
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers . declarator

	'('  shift 156
	'*'  shift 2
	'['  shift 157
	ID  shift 3
	.  reduce 151

	direct_declarator  goto 24
	pointer  goto 158
	declarator  goto 159
	direct_abstract_declarator  goto 160
	abstract_declarator  goto 161


state 72
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_list : parameter_list . ',' parameter_declaration
	parameter_type_list : parameter_list .  (145)

	','  shift 162
	.  reduce 145


state 73
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 163


state 74
	direct_declarator : direct_declarator '(' identifier_list . ')'
	identifier_list : identifier_list . ',' ID

	')'  shift 164
	','  shift 165


state 75
	parameter_list : parameter_declaration .  (147)

	.  reduce 147


state 76
	unary_operator : '!' .  (26)

	.  reduce 26


state 77
	unary_operator : '&' .  (21)

	.  reduce 21


state 78
	primary_expression : '(' . expression ')'
	cast_expression : '(' . type_name ')' cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
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

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 166
	struct_or_union_specifier  goto 28
	logical_and_expression  goto 103
	specifier_qualifier_list  goto 167
	exclusive_or_expression  goto 104
	struct_or_union  goto 30
	type_specifier  goto 148
	conditional_expression  goto 128
	enum_specifier  goto 33
	type_qualifier  goto 149
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	type_name  goto 168


state 79
	unary_operator : '*' .  (22)

	.  reduce 22


state 80
	unary_operator : '+' .  (23)

	.  reduce 23


state 81
	unary_operator : '-' .  (24)

	.  reduce 24


state 82
	direct_declarator : direct_declarator '[' ']' .  (135)

	.  reduce 135


state 83
	unary_operator : '~' .  (25)

	.  reduce 25


state 84
	primary_expression : ID .  (1)

	.  reduce 1


state 85
	primary_expression : CONSTANT .  (2)

	.  reduce 2


state 86
	primary_expression : STRING_LITERAL .  (3)

	.  reduce 3


state 87
	unary_expression : SIZEOF . unary_expression
	unary_expression : SIZEOF . '(' type_name ')'

	'!'  shift 76
	'&'  shift 77
	'('  shift 169
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	unary_operator  goto 93
	unary_expression  goto 170


state 88
	unary_expression : INC_OP . unary_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 171
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	unary_operator  goto 93
	unary_expression  goto 172


state 89
	unary_expression : DEC_OP . unary_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 171
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	unary_operator  goto 93
	unary_expression  goto 173


state 90
	postfix_expression : primary_expression .  (5)

	.  reduce 5


state 91
	postfix_expression : postfix_expression . '[' expression ']'
	postfix_expression : postfix_expression . '(' ')'
	postfix_expression : postfix_expression . '(' argument_expression_list ')'
	postfix_expression : postfix_expression . '.' ID
	postfix_expression : postfix_expression . PTR_OP ID
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (15)

	'('  shift 174
	'.'  shift 175
	'['  shift 176
	PTR_OP  shift 177
	INC_OP  shift 178
	DEC_OP  shift 179
	.  reduce 15


state 92
	multiplicative_expression : cast_expression .  (29)

	.  reduce 29


state 93
	unary_expression : unary_operator . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 180
	unary_operator  goto 93
	unary_expression  goto 95


state 94
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	additive_expression : multiplicative_expression .  (33)
	multiplicative_expression : multiplicative_expression . '*' cast_expression

	'%'  shift 181
	'*'  shift 182
	'/'  shift 183
	.  reduce 33


state 95
	cast_expression : unary_expression .  (27)

	.  reduce 27


state 96
	additive_expression : additive_expression . '-' multiplicative_expression
	shift_expression : additive_expression .  (36)
	additive_expression : additive_expression . '+' multiplicative_expression

	'+'  shift 184
	'-'  shift 185
	.  reduce 36


state 97
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : shift_expression .  (39)

	LEFT_OP  shift 186
	RIGHT_OP  shift 187
	.  reduce 39


state 98
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	equality_expression : relational_expression .  (44)
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 188
	'>'  shift 189
	LE_OP  shift 190
	GE_OP  shift 191
	.  reduce 44


state 99
	equality_expression : equality_expression . EQ_OP relational_expression
	and_expression : equality_expression .  (47)
	equality_expression : equality_expression . NE_OP relational_expression

	EQ_OP  shift 192
	NE_OP  shift 193
	.  reduce 47


state 100
	exclusive_or_expression : and_expression .  (49)
	and_expression : and_expression . '&' equality_expression

	'&'  shift 194
	.  reduce 49


state 101
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression
	conditional_expression : logical_or_expression .  (57)
	conditional_expression : logical_or_expression . '?' expression ':' conditional_expression

	'?'  shift 195
	OR_OP  shift 196
	.  reduce 57


state 102
	direct_declarator : direct_declarator '[' constant_expression . ']'

	']'  shift 197


state 103
	logical_or_expression : logical_and_expression .  (55)
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression

	AND_OP  shift 198
	.  reduce 55


state 104
	exclusive_or_expression : exclusive_or_expression . '^' and_expression
	inclusive_or_expression : exclusive_or_expression .  (51)

	'^'  shift 199
	.  reduce 51


state 105
	constant_expression : conditional_expression .  (74)

	.  reduce 74


state 106
	logical_and_expression : inclusive_or_expression .  (53)
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression

	'|'  shift 200
	.  reduce 53


state 107
	init_declarator : declarator '=' . initializer
	initializer : .  (171)

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'{'  shift 201
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	.  reduce 171

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 202
	initializer  goto 203


state 108
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

	'{'  shift 51
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

	declaration_specifiers  goto 52
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	declaration  goto 144
	enum_specifier  goto 33
	type_qualifier  goto 34
	compound_statement  goto 204


state 109
	function_definition : declaration_specifiers declarator compound_statement .  (220)

	.  reduce 220


state 110
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_declarator  goto 24
	pointer  goto 25
	declarator  goto 143
	init_declarator  goto 205


state 111
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 112
	expression_statement : ';' .  (196)

	.  reduce 196


state 113
	compound_statement : '{' '}' .  (188)

	.  reduce 188


state 114
	primary_expression : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 206
	.  reduce 1


state 115
	labeled_statement : CASE . constant_expression ':' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	constant_expression  goto 207
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 116
	labeled_statement : DEFAULT . ':' statement

	':'  shift 208


state 117
	matched_statement : IF . '(' expression ')' matched_statement ELSE matched_statement
	open_statement : IF . '(' expression ')' matched_statement ELSE open_statement
	open_statement : IF . '(' expression ')' stmt

	'('  shift 209


state 118
	selection_statement : SWITCH . '(' expression ')' statement

	'('  shift 210


state 119
	iteration_statement : WHILE . '(' expression ')' statement

	'('  shift 211


state 120
	iteration_statement : DO . statement WHILE '(' expression ')' ';'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 212
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 121
	iteration_statement : FOR . '(' expression_statement expression_statement ')' statement
	iteration_statement : FOR . '(' expression_statement expression_statement expression ')' statement

	'('  shift 213


state 122
	jump_statement : GOTO . ID ';'

	ID  shift 214


state 123
	jump_statement : CONTINUE . ';'

	';'  shift 215


state 124
	jump_statement : BREAK . ';'

	';'  shift 216


state 125
	jump_statement : RETURN . ';'
	jump_statement : RETURN . expression ';'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 217
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 218
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 126
	cast_expression : unary_expression .  (27)
	assignment_expression : unary_expression . assignment_operator assignment_expression

	'='  shift 219
	MUL_ASSIGN  shift 220
	DIV_ASSIGN  shift 221
	MOD_ASSIGN  shift 222
	ADD_ASSIGN  shift 223
	SUB_ASSIGN  shift 224
	LEFT_ASSIGN  shift 225
	RIGHT_ASSIGN  shift 226
	AND_ASSIGN  shift 227
	XOR_ASSIGN  shift 228
	OR_ASSIGN  shift 229
	.  reduce 27

	assignment_operator  goto 230


state 127
	expression : expression . ',' assignment_expression
	expression_statement : expression . ';'

	','  shift 231
	';'  shift 232


state 128
	assignment_expression : conditional_expression .  (59)

	.  reduce 59


state 129
	expression : assignment_expression .  (72)

	.  reduce 72


state 130
	compound_statement : '{' declaration_list . statement_list '}'
	declaration_list : declaration_list . declaration
	compound_statement : '{' declaration_list . '}'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'}'  shift 233
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
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
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	declaration_specifiers  goto 52
	expression  goto 127
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	struct_or_union  goto 30
	type_specifier  goto 31
	conditional_expression  goto 128
	declaration  goto 144
	enum_specifier  goto 33
	type_qualifier  goto 34
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 136
	statement_list  goto 234
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


131: reduce-reduce conflict (reduce 174, reduce 179) on '!'
131: reduce-reduce conflict (reduce 174, reduce 179) on '&'
131: reduce-reduce conflict (reduce 174, reduce 179) on '('
131: reduce-reduce conflict (reduce 174, reduce 179) on '*'
131: reduce-reduce conflict (reduce 174, reduce 179) on '+'
131: reduce-reduce conflict (reduce 174, reduce 179) on '-'
131: reduce-reduce conflict (reduce 174, reduce 179) on ';'
131: reduce-reduce conflict (reduce 174, reduce 179) on '{'
131: reduce-reduce conflict (reduce 174, reduce 179) on '}'
131: reduce-reduce conflict (reduce 174, reduce 179) on '~'
131: reduce-reduce conflict (reduce 174, reduce 179) on ID
131: reduce-reduce conflict (reduce 174, reduce 179) on CONSTANT
131: reduce-reduce conflict (reduce 174, reduce 179) on STRING_LITERAL
131: reduce-reduce conflict (reduce 174, reduce 179) on SIZEOF
131: reduce-reduce conflict (reduce 174, reduce 179) on INC_OP
131: reduce-reduce conflict (reduce 174, reduce 179) on DEC_OP
131: reduce-reduce conflict (reduce 174, reduce 179) on CASE
131: reduce-reduce conflict (reduce 174, reduce 179) on DEFAULT
131: reduce-reduce conflict (reduce 174, reduce 179) on IF
131: reduce-reduce conflict (reduce 174, reduce 179) on ELSE
131: reduce-reduce conflict (reduce 174, reduce 179) on SWITCH
131: reduce-reduce conflict (reduce 174, reduce 179) on WHILE
131: reduce-reduce conflict (reduce 174, reduce 179) on DO
131: reduce-reduce conflict (reduce 174, reduce 179) on FOR
131: reduce-reduce conflict (reduce 174, reduce 179) on GOTO
131: reduce-reduce conflict (reduce 174, reduce 179) on CONTINUE
131: reduce-reduce conflict (reduce 174, reduce 179) on BREAK
131: reduce-reduce conflict (reduce 174, reduce 179) on RETURN
state 131
	other : labeled_statement .  (174)
	statement : labeled_statement .  (179)

	.  reduce 174


132: reduce-reduce conflict (reduce 176, reduce 181) on '!'
132: reduce-reduce conflict (reduce 176, reduce 181) on '&'
132: reduce-reduce conflict (reduce 176, reduce 181) on '('
132: reduce-reduce conflict (reduce 176, reduce 181) on '*'
132: reduce-reduce conflict (reduce 176, reduce 181) on '+'
132: reduce-reduce conflict (reduce 176, reduce 181) on '-'
132: reduce-reduce conflict (reduce 176, reduce 181) on ';'
132: reduce-reduce conflict (reduce 176, reduce 181) on '{'
132: reduce-reduce conflict (reduce 176, reduce 181) on '}'
132: reduce-reduce conflict (reduce 176, reduce 181) on '~'
132: reduce-reduce conflict (reduce 176, reduce 181) on ID
132: reduce-reduce conflict (reduce 176, reduce 181) on CONSTANT
132: reduce-reduce conflict (reduce 176, reduce 181) on STRING_LITERAL
132: reduce-reduce conflict (reduce 176, reduce 181) on SIZEOF
132: reduce-reduce conflict (reduce 176, reduce 181) on INC_OP
132: reduce-reduce conflict (reduce 176, reduce 181) on DEC_OP
132: reduce-reduce conflict (reduce 176, reduce 181) on CASE
132: reduce-reduce conflict (reduce 176, reduce 181) on DEFAULT
132: reduce-reduce conflict (reduce 176, reduce 181) on IF
132: reduce-reduce conflict (reduce 176, reduce 181) on ELSE
132: reduce-reduce conflict (reduce 176, reduce 181) on SWITCH
132: reduce-reduce conflict (reduce 176, reduce 181) on WHILE
132: reduce-reduce conflict (reduce 176, reduce 181) on DO
132: reduce-reduce conflict (reduce 176, reduce 181) on FOR
132: reduce-reduce conflict (reduce 176, reduce 181) on GOTO
132: reduce-reduce conflict (reduce 176, reduce 181) on CONTINUE
132: reduce-reduce conflict (reduce 176, reduce 181) on BREAK
132: reduce-reduce conflict (reduce 176, reduce 181) on RETURN
state 132
	other : expression_statement .  (176)
	statement : expression_statement .  (181)

	.  reduce 176


133: reduce-reduce conflict (reduce 177, reduce 183) on '!'
133: reduce-reduce conflict (reduce 177, reduce 183) on '&'
133: reduce-reduce conflict (reduce 177, reduce 183) on '('
133: reduce-reduce conflict (reduce 177, reduce 183) on '*'
133: reduce-reduce conflict (reduce 177, reduce 183) on '+'
133: reduce-reduce conflict (reduce 177, reduce 183) on '-'
133: reduce-reduce conflict (reduce 177, reduce 183) on ';'
133: reduce-reduce conflict (reduce 177, reduce 183) on '{'
133: reduce-reduce conflict (reduce 177, reduce 183) on '}'
133: reduce-reduce conflict (reduce 177, reduce 183) on '~'
133: reduce-reduce conflict (reduce 177, reduce 183) on ID
133: reduce-reduce conflict (reduce 177, reduce 183) on CONSTANT
133: reduce-reduce conflict (reduce 177, reduce 183) on STRING_LITERAL
133: reduce-reduce conflict (reduce 177, reduce 183) on SIZEOF
133: reduce-reduce conflict (reduce 177, reduce 183) on INC_OP
133: reduce-reduce conflict (reduce 177, reduce 183) on DEC_OP
133: reduce-reduce conflict (reduce 177, reduce 183) on CASE
133: reduce-reduce conflict (reduce 177, reduce 183) on DEFAULT
133: reduce-reduce conflict (reduce 177, reduce 183) on IF
133: reduce-reduce conflict (reduce 177, reduce 183) on ELSE
133: reduce-reduce conflict (reduce 177, reduce 183) on SWITCH
133: reduce-reduce conflict (reduce 177, reduce 183) on WHILE
133: reduce-reduce conflict (reduce 177, reduce 183) on DO
133: reduce-reduce conflict (reduce 177, reduce 183) on FOR
133: reduce-reduce conflict (reduce 177, reduce 183) on GOTO
133: reduce-reduce conflict (reduce 177, reduce 183) on CONTINUE
133: reduce-reduce conflict (reduce 177, reduce 183) on BREAK
133: reduce-reduce conflict (reduce 177, reduce 183) on RETURN
state 133
	other : iteration_statement .  (177)
	statement : iteration_statement .  (183)

	.  reduce 177


134: reduce-reduce conflict (reduce 178, reduce 184) on '!'
134: reduce-reduce conflict (reduce 178, reduce 184) on '&'
134: reduce-reduce conflict (reduce 178, reduce 184) on '('
134: reduce-reduce conflict (reduce 178, reduce 184) on '*'
134: reduce-reduce conflict (reduce 178, reduce 184) on '+'
134: reduce-reduce conflict (reduce 178, reduce 184) on '-'
134: reduce-reduce conflict (reduce 178, reduce 184) on ';'
134: reduce-reduce conflict (reduce 178, reduce 184) on '{'
134: reduce-reduce conflict (reduce 178, reduce 184) on '}'
134: reduce-reduce conflict (reduce 178, reduce 184) on '~'
134: reduce-reduce conflict (reduce 178, reduce 184) on ID
134: reduce-reduce conflict (reduce 178, reduce 184) on CONSTANT
134: reduce-reduce conflict (reduce 178, reduce 184) on STRING_LITERAL
134: reduce-reduce conflict (reduce 178, reduce 184) on SIZEOF
134: reduce-reduce conflict (reduce 178, reduce 184) on INC_OP
134: reduce-reduce conflict (reduce 178, reduce 184) on DEC_OP
134: reduce-reduce conflict (reduce 178, reduce 184) on CASE
134: reduce-reduce conflict (reduce 178, reduce 184) on DEFAULT
134: reduce-reduce conflict (reduce 178, reduce 184) on IF
134: reduce-reduce conflict (reduce 178, reduce 184) on ELSE
134: reduce-reduce conflict (reduce 178, reduce 184) on SWITCH
134: reduce-reduce conflict (reduce 178, reduce 184) on WHILE
134: reduce-reduce conflict (reduce 178, reduce 184) on DO
134: reduce-reduce conflict (reduce 178, reduce 184) on FOR
134: reduce-reduce conflict (reduce 178, reduce 184) on GOTO
134: reduce-reduce conflict (reduce 178, reduce 184) on CONTINUE
134: reduce-reduce conflict (reduce 178, reduce 184) on BREAK
134: reduce-reduce conflict (reduce 178, reduce 184) on RETURN
state 134
	other : jump_statement .  (178)
	statement : jump_statement .  (184)

	.  reduce 178


135: reduce-reduce conflict (reduce 175, reduce 180) on '!'
135: reduce-reduce conflict (reduce 175, reduce 180) on '&'
135: reduce-reduce conflict (reduce 175, reduce 180) on '('
135: reduce-reduce conflict (reduce 175, reduce 180) on '*'
135: reduce-reduce conflict (reduce 175, reduce 180) on '+'
135: reduce-reduce conflict (reduce 175, reduce 180) on '-'
135: reduce-reduce conflict (reduce 175, reduce 180) on ';'
135: reduce-reduce conflict (reduce 175, reduce 180) on '{'
135: reduce-reduce conflict (reduce 175, reduce 180) on '}'
135: reduce-reduce conflict (reduce 175, reduce 180) on '~'
135: reduce-reduce conflict (reduce 175, reduce 180) on ID
135: reduce-reduce conflict (reduce 175, reduce 180) on CONSTANT
135: reduce-reduce conflict (reduce 175, reduce 180) on STRING_LITERAL
135: reduce-reduce conflict (reduce 175, reduce 180) on SIZEOF
135: reduce-reduce conflict (reduce 175, reduce 180) on INC_OP
135: reduce-reduce conflict (reduce 175, reduce 180) on DEC_OP
135: reduce-reduce conflict (reduce 175, reduce 180) on CASE
135: reduce-reduce conflict (reduce 175, reduce 180) on DEFAULT
135: reduce-reduce conflict (reduce 175, reduce 180) on IF
135: reduce-reduce conflict (reduce 175, reduce 180) on ELSE
135: reduce-reduce conflict (reduce 175, reduce 180) on SWITCH
135: reduce-reduce conflict (reduce 175, reduce 180) on WHILE
135: reduce-reduce conflict (reduce 175, reduce 180) on DO
135: reduce-reduce conflict (reduce 175, reduce 180) on FOR
135: reduce-reduce conflict (reduce 175, reduce 180) on GOTO
135: reduce-reduce conflict (reduce 175, reduce 180) on CONTINUE
135: reduce-reduce conflict (reduce 175, reduce 180) on BREAK
135: reduce-reduce conflict (reduce 175, reduce 180) on RETURN
state 135
	other : compound_statement .  (175)
	statement : compound_statement .  (180)

	.  reduce 175


state 136
	statement_list : statement .  (194)

	.  reduce 194


state 137
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'}'  shift 235
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 236
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 138
	selection_statement : stmt .  (204)

	.  reduce 204


state 139
	matched_statement : other .  (201)

	.  reduce 201


state 140
	statement : selection_statement .  (182)

	.  reduce 182


state 141
	stmt : matched_statement .  (198)

	.  reduce 198


state 142
	stmt : open_statement .  (199)

	.  reduce 199


state 143
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (85)

	'='  shift 107
	.  reduce 85


state 144
	declaration_list : declaration_list declaration .  (193)

	.  reduce 193


state 145
	function_definition : declarator declaration_list compound_statement .  (221)

	.  reduce 221


state 146
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list . '}'

	'}'  shift 237
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

	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 147
	struct_or_union  goto 30
	type_specifier  goto 148
	enum_specifier  goto 33
	type_qualifier  goto 149
	struct_declaration  goto 238


state 147
	struct_declaration : specifier_qualifier_list . struct_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	':'  shift 239
	ID  shift 3

	direct_declarator  goto 24
	pointer  goto 25
	declarator  goto 240
	struct_declarator  goto 241
	struct_declarator_list  goto 242


state 148
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	specifier_qualifier_list : type_specifier .  (113)

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

	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 243
	struct_or_union  goto 30
	type_specifier  goto 148
	enum_specifier  goto 33
	type_qualifier  goto 149


state 149
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

	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 244
	struct_or_union  goto 30
	type_specifier  goto 148
	enum_specifier  goto 33
	type_qualifier  goto 149


state 150
	struct_declaration_list : struct_declaration .  (109)

	.  reduce 109


state 151
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

	struct_or_union_specifier  goto 28
	struct_declaration_list  goto 245
	specifier_qualifier_list  goto 147
	struct_or_union  goto 30
	type_specifier  goto 148
	enum_specifier  goto 33
	type_qualifier  goto 149
	struct_declaration  goto 150


state 152
	enumerator : ID '=' . constant_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	constant_expression  goto 246
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 153
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 65

	enumerator  goto 247


state 154
	enum_specifier : ENUM '{' enumerator_list '}' .  (121)

	.  reduce 121


state 155
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM ID '{' enumerator_list . '}'

	','  shift 153
	'}'  shift 248


state 156
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 156
	')'  shift 249
	'*'  shift 2
	'['  shift 157
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

	direct_declarator  goto 24
	pointer  goto 158
	declaration_specifiers  goto 71
	declarator  goto 38
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	parameter_list  goto 72
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	parameter_type_list  goto 250
	type_qualifier  goto 34
	direct_abstract_declarator  goto 160
	abstract_declarator  goto 251
	parameter_declaration  goto 75


state 157
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_expression ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	']'  shift 252
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	constant_expression  goto 253
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 158
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 156
	'['  shift 157
	ID  shift 3
	.  reduce 156

	direct_declarator  goto 46
	direct_abstract_declarator  goto 254


state 159
	parameter_declaration : declaration_specifiers declarator .  (149)

	.  reduce 149


state 160
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	abstract_declarator : direct_abstract_declarator .  (157)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'

	'('  shift 255
	'['  shift 256
	.  reduce 157


state 161
	parameter_declaration : declaration_specifiers abstract_declarator .  (150)

	.  reduce 150


state 162
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
	ELLIPSIS  shift 257

	declaration_specifiers  goto 71
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	type_qualifier  goto 34
	parameter_declaration  goto 258


state 163
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (136)

	.  reduce 136


state 164
	direct_declarator : direct_declarator '(' identifier_list ')' .  (137)

	.  reduce 137


state 165
	identifier_list : identifier_list ',' . ID

	ID  shift 259


state 166
	primary_expression : '(' expression . ')'
	expression : expression . ',' assignment_expression

	')'  shift 260
	','  shift 231


state 167
	type_name : specifier_qualifier_list .  (154)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 261
	'*'  shift 2
	'['  shift 157
	.  reduce 154

	pointer  goto 262
	direct_abstract_declarator  goto 160
	abstract_declarator  goto 263


state 168
	cast_expression : '(' type_name . ')' cast_expression

	')'  shift 264


state 169
	primary_expression : '(' . expression ')'
	unary_expression : SIZEOF '(' . type_name ')'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
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

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 166
	struct_or_union_specifier  goto 28
	logical_and_expression  goto 103
	specifier_qualifier_list  goto 167
	exclusive_or_expression  goto 104
	struct_or_union  goto 30
	type_specifier  goto 148
	conditional_expression  goto 128
	enum_specifier  goto 33
	type_qualifier  goto 149
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	type_name  goto 265


state 170
	unary_expression : SIZEOF unary_expression .  (19)

	.  reduce 19


state 171
	primary_expression : '(' . expression ')'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 166
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 172
	unary_expression : INC_OP unary_expression .  (16)

	.  reduce 16


state 173
	unary_expression : DEC_OP unary_expression .  (17)

	.  reduce 17


state 174
	postfix_expression : postfix_expression '(' . ')'
	postfix_expression : postfix_expression '(' . argument_expression_list ')'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	')'  shift 266
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	argument_expression_list  goto 267
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 268


state 175
	postfix_expression : postfix_expression '.' . ID

	ID  shift 269


state 176
	postfix_expression : postfix_expression '[' . expression ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 270
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 177
	postfix_expression : postfix_expression PTR_OP . ID

	ID  shift 271


state 178
	postfix_expression : postfix_expression INC_OP .  (11)

	.  reduce 11


state 179
	postfix_expression : postfix_expression DEC_OP .  (12)

	.  reduce 12


state 180
	unary_expression : unary_operator cast_expression .  (18)

	.  reduce 18


state 181
	multiplicative_expression : multiplicative_expression '%' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 272
	unary_operator  goto 93
	unary_expression  goto 95


state 182
	multiplicative_expression : multiplicative_expression '*' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 273
	unary_operator  goto 93
	unary_expression  goto 95


state 183
	multiplicative_expression : multiplicative_expression '/' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 274
	unary_operator  goto 93
	unary_expression  goto 95


state 184
	additive_expression : additive_expression '+' . multiplicative_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 275
	unary_expression  goto 95


state 185
	additive_expression : additive_expression '-' . multiplicative_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 276
	unary_expression  goto 95


state 186
	shift_expression : shift_expression LEFT_OP . additive_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 277


state 187
	shift_expression : shift_expression RIGHT_OP . additive_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 278


state 188
	relational_expression : relational_expression '<' . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 279


state 189
	relational_expression : relational_expression '>' . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 280


state 190
	relational_expression : relational_expression LE_OP . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 281


state 191
	relational_expression : relational_expression GE_OP . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 282


state 192
	equality_expression : equality_expression EQ_OP . relational_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 283


state 193
	equality_expression : equality_expression NE_OP . relational_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 284


state 194
	and_expression : and_expression '&' . equality_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 285


state 195
	conditional_expression : logical_or_expression '?' . expression ':' conditional_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 286
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 196
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_and_expression  goto 287
	exclusive_or_expression  goto 104
	inclusive_or_expression  goto 106


state 197
	direct_declarator : direct_declarator '[' constant_expression ']' .  (134)

	.  reduce 134


state 198
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	exclusive_or_expression  goto 104
	inclusive_or_expression  goto 288


state 199
	exclusive_or_expression : exclusive_or_expression '^' . and_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 289


state 200
	inclusive_or_expression : inclusive_or_expression '|' . exclusive_or_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	exclusive_or_expression  goto 290


state 201
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'
	initializer : .  (171)

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'{'  shift 201
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	.  reduce 171

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 202
	initializer  goto 291
	initializer_list  goto 292


state 202
	initializer : assignment_expression .  (168)

	.  reduce 168


state 203
	init_declarator : declarator '=' initializer .  (86)

	.  reduce 86


state 204
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (219)

	.  reduce 219


state 205
	init_declarator_list : init_declarator_list ',' init_declarator .  (84)

	.  reduce 84


state 206
	labeled_statement : ID ':' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 293
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 207
	labeled_statement : CASE constant_expression . ':' statement

	':'  shift 294


state 208
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 295
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 209
	matched_statement : IF '(' . expression ')' matched_statement ELSE matched_statement
	open_statement : IF '(' . expression ')' matched_statement ELSE open_statement
	open_statement : IF '(' . expression ')' stmt

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 296
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 210
	selection_statement : SWITCH '(' . expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 297
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 211
	iteration_statement : WHILE '(' . expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 298
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 212
	iteration_statement : DO statement . WHILE '(' expression ')' ';'

	WHILE  shift 299


state 213
	iteration_statement : FOR '(' . expression_statement expression_statement ')' statement
	iteration_statement : FOR '(' . expression_statement expression_statement expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	expression_statement  goto 300


state 214
	jump_statement : GOTO ID . ';'

	';'  shift 301


state 215
	jump_statement : CONTINUE ';' .  (211)

	.  reduce 211


state 216
	jump_statement : BREAK ';' .  (212)

	.  reduce 212


state 217
	jump_statement : RETURN ';' .  (213)

	.  reduce 213


state 218
	expression : expression . ',' assignment_expression
	jump_statement : RETURN expression . ';'

	','  shift 231
	';'  shift 302


state 219
	assignment_operator : '=' .  (61)

	.  reduce 61


state 220
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 221
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 222
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 223
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 224
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 225
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 226
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 227
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 228
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 229
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 230
	assignment_expression : unary_expression assignment_operator . assignment_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 303


state 231
	expression : expression ',' . assignment_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 304


state 232
	expression_statement : expression ';' .  (197)

	.  reduce 197


state 233
	compound_statement : '{' declaration_list '}' .  (190)

	.  reduce 190


state 234
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'}'  shift 305
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 236
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 235
	compound_statement : '{' statement_list '}' .  (189)

	.  reduce 189


state 236
	statement_list : statement_list statement .  (195)

	.  reduce 195


state 237
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}' .  (105)

	.  reduce 105


state 238
	struct_declaration_list : struct_declaration_list struct_declaration .  (110)

	.  reduce 110


state 239
	struct_declarator : ':' . constant_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	constant_expression  goto 306
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 240
	struct_declarator : declarator . ':' constant_expression
	struct_declarator : declarator .  (118)

	':'  shift 307
	.  reduce 118


state 241
	struct_declarator_list : struct_declarator .  (116)

	.  reduce 116


state 242
	struct_declaration : specifier_qualifier_list struct_declarator_list . ';'
	struct_declarator_list : struct_declarator_list . ',' struct_declarator

	','  shift 308
	';'  shift 309


state 243
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (112)

	.  reduce 112


state 244
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (114)

	.  reduce 114


state 245
	struct_or_union_specifier : struct_or_union ID '{' struct_declaration_list . '}'
	struct_declaration_list : struct_declaration_list . struct_declaration

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

	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 147
	struct_or_union  goto 30
	type_specifier  goto 148
	enum_specifier  goto 33
	type_qualifier  goto 149
	struct_declaration  goto 238


state 246
	enumerator : ID '=' constant_expression .  (127)

	.  reduce 127


state 247
	enumerator_list : enumerator_list ',' enumerator .  (125)

	.  reduce 125


state 248
	enum_specifier : ENUM ID '{' enumerator_list '}' .  (122)

	.  reduce 122


state 249
	direct_abstract_declarator : '(' ')' .  (164)

	.  reduce 164


state 250
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 311


state 251
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 312


state 252
	direct_abstract_declarator : '[' ']' .  (160)

	.  reduce 160


state 253
	direct_abstract_declarator : '[' constant_expression . ']'

	']'  shift 313


state 254
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	abstract_declarator : pointer direct_abstract_declarator .  (158)
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'

	'('  shift 255
	'['  shift 256
	.  reduce 158


state 255
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

	')'  shift 314
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

	declaration_specifiers  goto 71
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	parameter_list  goto 72
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	parameter_type_list  goto 315
	type_qualifier  goto 34
	parameter_declaration  goto 75


state 256
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_expression ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	']'  shift 316
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	constant_expression  goto 317
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 257
	parameter_type_list : parameter_list ',' ELLIPSIS .  (146)

	.  reduce 146


state 258
	parameter_list : parameter_list ',' parameter_declaration .  (148)

	.  reduce 148


state 259
	identifier_list : identifier_list ',' ID .  (153)

	.  reduce 153


state 260
	primary_expression : '(' expression ')' .  (4)

	.  reduce 4


state 261
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 261
	')'  shift 249
	'*'  shift 2
	'['  shift 157
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

	pointer  goto 262
	declaration_specifiers  goto 71
	struct_or_union_specifier  goto 28
	storage_class_specifier  goto 29
	parameter_list  goto 72
	struct_or_union  goto 30
	type_specifier  goto 31
	enum_specifier  goto 33
	parameter_type_list  goto 250
	type_qualifier  goto 34
	direct_abstract_declarator  goto 160
	abstract_declarator  goto 251
	parameter_declaration  goto 75


state 262
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 261
	'['  shift 157
	.  reduce 156

	direct_abstract_declarator  goto 254


state 263
	type_name : specifier_qualifier_list abstract_declarator .  (155)

	.  reduce 155


state 264
	cast_expression : '(' type_name ')' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 318
	unary_operator  goto 93
	unary_expression  goto 95


state 265
	unary_expression : SIZEOF '(' type_name . ')'

	')'  shift 319


state 266
	postfix_expression : postfix_expression '(' ')' .  (7)

	.  reduce 7


state 267
	postfix_expression : postfix_expression '(' argument_expression_list . ')'
	argument_expression_list : argument_expression_list . ',' assignment_expression

	')'  shift 320
	','  shift 321


state 268
	argument_expression_list : assignment_expression .  (13)

	.  reduce 13


state 269
	postfix_expression : postfix_expression '.' ID .  (9)

	.  reduce 9


state 270
	postfix_expression : postfix_expression '[' expression . ']'
	expression : expression . ',' assignment_expression

	','  shift 231
	']'  shift 322


state 271
	postfix_expression : postfix_expression PTR_OP ID .  (10)

	.  reduce 10


state 272
	multiplicative_expression : multiplicative_expression '%' cast_expression .  (32)

	.  reduce 32


state 273
	multiplicative_expression : multiplicative_expression '*' cast_expression .  (30)

	.  reduce 30


state 274
	multiplicative_expression : multiplicative_expression '/' cast_expression .  (31)

	.  reduce 31


state 275
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : additive_expression '+' multiplicative_expression .  (34)

	'%'  shift 181
	'*'  shift 182
	'/'  shift 183
	.  reduce 34


state 276
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : additive_expression '-' multiplicative_expression .  (35)

	'%'  shift 181
	'*'  shift 182
	'/'  shift 183
	.  reduce 35


state 277
	additive_expression : additive_expression . '-' multiplicative_expression
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : shift_expression LEFT_OP additive_expression .  (37)

	'+'  shift 184
	'-'  shift 185
	.  reduce 37


state 278
	additive_expression : additive_expression . '-' multiplicative_expression
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : shift_expression RIGHT_OP additive_expression .  (38)

	'+'  shift 184
	'-'  shift 185
	.  reduce 38


state 279
	relational_expression : relational_expression '<' shift_expression .  (40)
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 186
	RIGHT_OP  shift 187
	.  reduce 40


state 280
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '>' shift_expression .  (41)
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 186
	RIGHT_OP  shift 187
	.  reduce 41


state 281
	relational_expression : relational_expression LE_OP shift_expression .  (42)
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 186
	RIGHT_OP  shift 187
	.  reduce 42


state 282
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (43)
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 186
	RIGHT_OP  shift 187
	.  reduce 43


state 283
	equality_expression : equality_expression EQ_OP relational_expression .  (45)
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 188
	'>'  shift 189
	LE_OP  shift 190
	GE_OP  shift 191
	.  reduce 45


state 284
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	equality_expression : equality_expression NE_OP relational_expression .  (46)
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 188
	'>'  shift 189
	LE_OP  shift 190
	GE_OP  shift 191
	.  reduce 46


state 285
	equality_expression : equality_expression . EQ_OP relational_expression
	equality_expression : equality_expression . NE_OP relational_expression
	and_expression : and_expression '&' equality_expression .  (48)

	EQ_OP  shift 192
	NE_OP  shift 193
	.  reduce 48


state 286
	conditional_expression : logical_or_expression '?' expression . ':' conditional_expression
	expression : expression . ',' assignment_expression

	','  shift 231
	':'  shift 323


state 287
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (56)
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression

	AND_OP  shift 198
	.  reduce 56


state 288
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (54)

	'|'  shift 200
	.  reduce 54


state 289
	exclusive_or_expression : exclusive_or_expression '^' and_expression .  (50)
	and_expression : and_expression . '&' equality_expression

	'&'  shift 194
	.  reduce 50


state 290
	exclusive_or_expression : exclusive_or_expression . '^' and_expression
	inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression .  (52)

	'^'  shift 199
	.  reduce 52


state 291
	initializer_list : initializer .  (172)

	.  reduce 172


state 292
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 324
	'}'  shift 325


state 293
	labeled_statement : ID ':' statement .  (185)

	.  reduce 185


state 294
	labeled_statement : CASE constant_expression ':' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 326
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 295
	labeled_statement : DEFAULT ':' statement .  (187)

	.  reduce 187


state 296
	expression : expression . ',' assignment_expression
	matched_statement : IF '(' expression . ')' matched_statement ELSE matched_statement
	open_statement : IF '(' expression . ')' matched_statement ELSE open_statement
	open_statement : IF '(' expression . ')' stmt

	')'  shift 327
	','  shift 231


state 297
	expression : expression . ',' assignment_expression
	selection_statement : SWITCH '(' expression . ')' statement

	')'  shift 328
	','  shift 231


state 298
	expression : expression . ',' assignment_expression
	iteration_statement : WHILE '(' expression . ')' statement

	')'  shift 329
	','  shift 231


state 299
	iteration_statement : DO statement WHILE . '(' expression ')' ';'

	'('  shift 330


state 300
	iteration_statement : FOR '(' expression_statement . expression_statement ')' statement
	iteration_statement : FOR '(' expression_statement . expression_statement expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	expression_statement  goto 331


state 301
	jump_statement : GOTO ID ';' .  (210)

	.  reduce 210


state 302
	jump_statement : RETURN expression ';' .  (214)

	.  reduce 214


state 303
	assignment_expression : unary_expression assignment_operator assignment_expression .  (60)

	.  reduce 60


state 304
	expression : expression ',' assignment_expression .  (73)

	.  reduce 73


state 305
	compound_statement : '{' declaration_list statement_list '}' .  (191)

	.  reduce 191


state 306
	struct_declarator : ':' constant_expression .  (119)

	.  reduce 119


state 307
	struct_declarator : declarator ':' . constant_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	constant_expression  goto 332
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 308
	struct_declarator_list : struct_declarator_list ',' . struct_declarator

	'('  shift 1
	'*'  shift 2
	':'  shift 239
	ID  shift 3

	direct_declarator  goto 24
	pointer  goto 25
	declarator  goto 240
	struct_declarator  goto 333


state 309
	struct_declaration : specifier_qualifier_list struct_declarator_list ';' .  (111)

	.  reduce 111


state 310
	struct_or_union_specifier : struct_or_union ID '{' struct_declaration_list '}' .  (104)

	.  reduce 104


state 311
	direct_abstract_declarator : '(' parameter_type_list ')' .  (165)

	.  reduce 165


state 312
	direct_abstract_declarator : '(' abstract_declarator ')' .  (159)

	.  reduce 159


state 313
	direct_abstract_declarator : '[' constant_expression ']' .  (161)

	.  reduce 161


state 314
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (166)

	.  reduce 166


state 315
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 334


state 316
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (162)

	.  reduce 162


state 317
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression . ']'

	']'  shift 335


state 318
	cast_expression : '(' type_name ')' cast_expression .  (28)

	.  reduce 28


state 319
	unary_expression : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 320
	postfix_expression : postfix_expression '(' argument_expression_list ')' .  (8)

	.  reduce 8


state 321
	argument_expression_list : argument_expression_list ',' . assignment_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 336


state 322
	postfix_expression : postfix_expression '[' expression ']' .  (6)

	.  reduce 6


state 323
	conditional_expression : logical_or_expression '?' expression ':' . conditional_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 95
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 337
	inclusive_or_expression  goto 106


324: shift-reduce conflict (shift 338, reduce 171) on '}'
state 324
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer
	initializer : .  (171)

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'{'  shift 201
	'}'  shift 338
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	.  reduce 171

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 202
	initializer  goto 339


state 325
	initializer : '{' initializer_list '}' .  (169)

	.  reduce 169


state 326
	labeled_statement : CASE constant_expression ':' statement .  (186)

	.  reduce 186


state 327
	matched_statement : IF '(' expression ')' . matched_statement ELSE matched_statement
	open_statement : IF '(' expression ')' . matched_statement ELSE open_statement
	open_statement : IF '(' expression ')' . stmt

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 340
	expression_statement  goto 341
	iteration_statement  goto 342
	jump_statement  goto 343
	compound_statement  goto 344
	stmt  goto 345
	other  goto 139
	matched_statement  goto 346
	open_statement  goto 142


state 328
	selection_statement : SWITCH '(' expression ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 347
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 329
	iteration_statement : WHILE '(' expression ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 348
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 330
	iteration_statement : DO statement WHILE '(' . expression ')' ';'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 349
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 331
	iteration_statement : FOR '(' expression_statement expression_statement . ')' statement
	iteration_statement : FOR '(' expression_statement expression_statement . expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	')'  shift 350
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 351
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129


state 332
	struct_declarator : declarator ':' constant_expression .  (120)

	.  reduce 120


state 333
	struct_declarator_list : struct_declarator_list ',' struct_declarator .  (117)

	.  reduce 117


state 334
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (167)

	.  reduce 167


state 335
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']' .  (163)

	.  reduce 163


state 336
	argument_expression_list : argument_expression_list ',' assignment_expression .  (14)

	.  reduce 14


state 337
	conditional_expression : logical_or_expression '?' expression ':' conditional_expression .  (58)

	.  reduce 58


state 338
	initializer : '{' initializer_list ',' '}' .  (170)

	.  reduce 170


state 339
	initializer_list : initializer_list ',' initializer .  (173)

	.  reduce 173


state 340
	other : labeled_statement .  (174)

	.  reduce 174


state 341
	other : expression_statement .  (176)

	.  reduce 176


state 342
	other : iteration_statement .  (177)

	.  reduce 177


state 343
	other : jump_statement .  (178)

	.  reduce 178


state 344
	other : compound_statement .  (175)

	.  reduce 175


state 345
	open_statement : IF '(' expression ')' stmt .  (202)

	.  reduce 202


346: shift-reduce conflict (shift 352, reduce 198) on ELSE
state 346
	matched_statement : IF '(' expression ')' matched_statement . ELSE matched_statement
	open_statement : IF '(' expression ')' matched_statement . ELSE open_statement
	stmt : matched_statement .  (198)

	ELSE  shift 352
	.  reduce 198


state 347
	selection_statement : SWITCH '(' expression ')' statement .  (205)

	.  reduce 205


state 348
	iteration_statement : WHILE '(' expression ')' statement .  (206)

	.  reduce 206


state 349
	expression : expression . ',' assignment_expression
	iteration_statement : DO statement WHILE '(' expression . ')' ';'

	')'  shift 353
	','  shift 231


state 350
	iteration_statement : FOR '(' expression_statement expression_statement ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 354
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 351
	expression : expression . ',' assignment_expression
	iteration_statement : FOR '(' expression_statement expression_statement expression . ')' statement

	')'  shift 355
	','  shift 231


state 352
	matched_statement : IF '(' expression ')' matched_statement ELSE . matched_statement
	open_statement : IF '(' expression ')' matched_statement ELSE . open_statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 340
	expression_statement  goto 341
	iteration_statement  goto 342
	jump_statement  goto 343
	compound_statement  goto 344
	other  goto 139
	matched_statement  goto 356
	open_statement  goto 357


state 353
	iteration_statement : DO statement WHILE '(' expression ')' . ';'

	';'  shift 358


state 354
	iteration_statement : FOR '(' expression_statement expression_statement ')' statement .  (208)

	.  reduce 208


state 355
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 112
	'{'  shift 51
	'~'  shift 83
	ID  shift 114
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 115
	DEFAULT  shift 116
	IF  shift 117
	SWITCH  shift 118
	WHILE  shift 119
	DO  shift 120
	FOR  shift 121
	GOTO  shift 122
	CONTINUE  shift 123
	BREAK  shift 124
	RETURN  shift 125

	primary_expression  goto 90
	postfix_expression  goto 91
	cast_expression  goto 92
	unary_operator  goto 93
	multiplicative_expression  goto 94
	unary_expression  goto 126
	additive_expression  goto 96
	shift_expression  goto 97
	relational_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 100
	logical_or_expression  goto 101
	expression  goto 127
	logical_and_expression  goto 103
	exclusive_or_expression  goto 104
	conditional_expression  goto 128
	inclusive_or_expression  goto 106
	assignment_expression  goto 129
	labeled_statement  goto 131
	expression_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	compound_statement  goto 135
	statement  goto 359
	stmt  goto 138
	other  goto 139
	selection_statement  goto 140
	matched_statement  goto 141
	open_statement  goto 142


state 356
	matched_statement : IF '(' expression ')' matched_statement ELSE matched_statement .  (200)

	.  reduce 200


state 357
	open_statement : IF '(' expression ')' matched_statement ELSE open_statement .  (203)

	.  reduce 203


state 358
	iteration_statement : DO statement WHILE '(' expression ')' ';' .  (207)

	.  reduce 207


state 359
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement .  (209)

	.  reduce 209


Rules never reduced
	statement : labeled_statement  (179)
	statement : compound_statement  (180)
	statement : expression_statement  (181)
	statement : iteration_statement  (183)
	statement : jump_statement  (184)


##############################################################################
# Summary
##############################################################################

State 131 contains 28 reduce-reduce conflict(s)
State 132 contains 28 reduce-reduce conflict(s)
State 133 contains 28 reduce-reduce conflict(s)
State 134 contains 28 reduce-reduce conflict(s)
State 135 contains 28 reduce-reduce conflict(s)
State 324 contains 1 shift-reduce conflict(s)
State 346 contains 1 shift-reduce conflict(s)


84 token(s), 68 nonterminal(s)
223 grammar rule(s), 360 state(s)


##############################################################################
# End of File
##############################################################################
