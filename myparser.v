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
# Time: 17:07:15
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

  193  if_else_statement :
  194                    | ELSE statement

  195  selection_statement : if_statement if_else_statement
  196                      | SWITCH '(' expression ')' statement

  197  iteration_statement : WHILE '(' expression ')' statement
  198                      | DO statement WHILE '(' expression ')' ';'
  199                      | FOR '(' expression_statement expression_statement ')' statement
  200                      | FOR '(' expression_statement expression_statement expression ')' statement

  201  jump_statement : GOTO ID ';'
  202                 | CONTINUE ';'
  203                 | BREAK ';'
  204                 | RETURN ';'
  205                 | RETURN expression ';'

  206  translation_unit : external_declaration
  207                   | translation_unit external_declaration

  208  external_declaration : function_definition
  209                       | declaration

  210  function_definition : declaration_specifiers declarator declaration_list compound_statement
  211                      | declaration_specifiers declarator compound_statement
  212                      | declarator declaration_list compound_statement
  213                      | declarator compound_statement


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

	declaration  goto 24
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declarator  goto 29
	declaration_specifiers  goto 30
	direct_declarator  goto 31
	pointer  goto 32
	enum_specifier  goto 33
	type_specifier  goto 34
	translation_unit  goto 35
	external_declaration  goto 36
	function_definition  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 38
	direct_declarator  goto 31
	pointer  goto 32


state 2
	pointer : '*' . type_qualifier_list
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' .  (139)
	pointer : '*' . pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 139

	type_qualifier  goto 39
	pointer  goto 40
	type_qualifier_list  goto 41


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
	enum_specifier : ENUM . ID
	enum_specifier : ENUM . ID '{' enumerator_list '}'

	'{'  shift 42
	ID  shift 43


state 24
	external_declaration : declaration .  (209)

	.  reduce 209


state 25
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 26
	struct_or_union_specifier : struct_or_union . ID '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID

	'{'  shift 44
	ID  shift 45


state 27
	declaration_specifiers : storage_class_specifier . declaration_specifiers
	declaration_specifiers : storage_class_specifier .  (77)

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

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 46
	enum_specifier  goto 33
	type_specifier  goto 34


state 28
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

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 47
	enum_specifier  goto 33
	type_specifier  goto 34


state 29
	function_definition : declarator . compound_statement
	function_definition : declarator . declaration_list compound_statement

	'{'  shift 48
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

	declaration  goto 49
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 50
	enum_specifier  goto 33
	type_specifier  goto 34
	declaration_list  goto 51
	compound_statement  goto 52


state 30
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'
	function_definition : declaration_specifiers . declarator compound_statement
	function_definition : declaration_specifiers . declarator declaration_list compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 53
	ID  shift 3

	init_declarator  goto 54
	declarator  goto 55
	direct_declarator  goto 31
	pointer  goto 32
	init_declarator_list  goto 56


state 31
	declarator : direct_declarator .  (131)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'

	'('  shift 57
	'['  shift 58
	.  reduce 131


state 32
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 59


state 33
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 34
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

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 60
	enum_specifier  goto 33
	type_specifier  goto 34


state 35
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

	declaration  goto 24
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declarator  goto 29
	declaration_specifiers  goto 30
	direct_declarator  goto 31
	pointer  goto 32
	enum_specifier  goto 33
	type_specifier  goto 34
	external_declaration  goto 61
	function_definition  goto 37


state 36
	translation_unit : external_declaration .  (206)

	.  reduce 206


state 37
	external_declaration : function_definition .  (208)

	.  reduce 208


state 38
	direct_declarator : '(' declarator . ')'

	')'  shift 62


state 39
	type_qualifier_list : type_qualifier .  (143)

	.  reduce 143


state 40
	pointer : '*' pointer .  (141)

	.  reduce 141


state 41
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list .  (140)
	pointer : '*' type_qualifier_list . pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 140

	type_qualifier  goto 63
	pointer  goto 64


state 42
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 65

	enumerator_list  goto 66
	enumerator  goto 67


state 43
	enum_specifier : ENUM ID .  (123)
	enum_specifier : ENUM ID . '{' enumerator_list '}'

	'{'  shift 68
	.  reduce 123


state 44
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

	specifier_qualifier_list  goto 69
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	struct_declaration_list  goto 70
	type_qualifier  goto 71
	enum_specifier  goto 33
	type_specifier  goto 72
	struct_declaration  goto 73


state 45
	struct_or_union_specifier : struct_or_union ID . '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union ID .  (106)

	'{'  shift 74
	.  reduce 106


state 46
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 47
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 48
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list statement_list '}'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'}'  shift 82
	'~'  shift 83
	ID  shift 84
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
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	declaration  goto 49
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	logical_and_expression  goto 112
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 50
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	enum_specifier  goto 33
	type_specifier  goto 34
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 119
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	declaration_list  goto 123
	jump_statement  goto 124
	statement_list  goto 125
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 49
	declaration_list : declaration .  (186)

	.  reduce 186


state 50
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 53
	ID  shift 3

	init_declarator  goto 54
	declarator  goto 129
	direct_declarator  goto 31
	pointer  goto 32
	init_declarator_list  goto 56


state 51
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

	'{'  shift 48
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

	declaration  goto 130
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 50
	enum_specifier  goto 33
	type_specifier  goto 34
	compound_statement  goto 131


state 52
	function_definition : declarator compound_statement .  (213)

	.  reduce 213


state 53
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 54
	init_declarator_list : init_declarator .  (83)

	.  reduce 83


state 55
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (85)
	function_definition : declaration_specifiers declarator . compound_statement
	function_definition : declaration_specifiers declarator . declaration_list compound_statement

	'='  shift 132
	'{'  shift 48
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

	declaration  goto 49
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 50
	enum_specifier  goto 33
	type_specifier  goto 34
	declaration_list  goto 133
	compound_statement  goto 134


state 56
	init_declarator_list : init_declarator_list . ',' init_declarator
	declaration : declaration_specifiers init_declarator_list . ';'

	','  shift 135
	';'  shift 136


state 57
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'
	direct_declarator : direct_declarator '(' . ')'

	')'  shift 137
	ID  shift 138
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

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 139
	parameter_type_list  goto 140
	parameter_list  goto 141
	enum_specifier  goto 33
	type_specifier  goto 34
	parameter_declaration  goto 142
	identifier_list  goto 143


state 58
	direct_declarator : direct_declarator '[' . constant_expression ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	']'  shift 144
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	constant_expression  goto 147
	conditional_expression  goto 148
	logical_or_expression  goto 116


state 59
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	declarator : pointer direct_declarator .  (130)
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'

	'('  shift 57
	'['  shift 58
	.  reduce 130


state 60
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 61
	translation_unit : translation_unit external_declaration .  (207)

	.  reduce 207


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
	enumerator : ID .  (126)
	enumerator : ID . '=' constant_expression

	'='  shift 149
	.  reduce 126


state 66
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM '{' enumerator_list . '}'

	','  shift 150
	'}'  shift 151


state 67
	enumerator_list : enumerator .  (124)

	.  reduce 124


state 68
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 65

	enumerator_list  goto 152
	enumerator  goto 67


state 69
	struct_declaration : specifier_qualifier_list . struct_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	':'  shift 153
	ID  shift 3

	struct_declarator  goto 154
	struct_declarator_list  goto 155
	declarator  goto 156
	direct_declarator  goto 31
	pointer  goto 32


state 70
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list . '}'

	'}'  shift 157
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

	specifier_qualifier_list  goto 69
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	type_qualifier  goto 71
	enum_specifier  goto 33
	type_specifier  goto 72
	struct_declaration  goto 158


state 71
	specifier_qualifier_list : type_qualifier .  (115)
	specifier_qualifier_list : type_qualifier . specifier_qualifier_list

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

	specifier_qualifier_list  goto 159
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	type_qualifier  goto 71
	enum_specifier  goto 33
	type_specifier  goto 72


state 72
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

	specifier_qualifier_list  goto 160
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	type_qualifier  goto 71
	enum_specifier  goto 33
	type_specifier  goto 72


state 73
	struct_declaration_list : struct_declaration .  (109)

	.  reduce 109


state 74
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

	specifier_qualifier_list  goto 69
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	struct_declaration_list  goto 161
	type_qualifier  goto 71
	enum_specifier  goto 33
	type_specifier  goto 72
	struct_declaration  goto 73


state 75
	unary_operator : '!' .  (26)

	.  reduce 26


state 76
	unary_operator : '&' .  (21)

	.  reduce 21


state 77
	primary_expression : '(' . expression ')'
	cast_expression : '(' . type_name ')' cast_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
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

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	specifier_qualifier_list  goto 162
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	logical_and_expression  goto 112
	type_qualifier  goto 71
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	enum_specifier  goto 33
	type_specifier  goto 72
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 163
	type_name  goto 164


state 78
	unary_operator : '*' .  (22)

	.  reduce 22


state 79
	unary_operator : '+' .  (23)

	.  reduce 23


state 80
	unary_operator : '-' .  (24)

	.  reduce 24


state 81
	expression_statement : ';' .  (190)

	.  reduce 190


state 82
	compound_statement : '{' '}' .  (182)

	.  reduce 182


state 83
	unary_operator : '~' .  (25)

	.  reduce 25


state 84
	primary_expression : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 165
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

	'!'  shift 75
	'&'  shift 76
	'('  shift 166
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 167
	unary_operator  goto 109
	postfix_expression  goto 110


state 88
	unary_expression : INC_OP . unary_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 168
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 169
	unary_operator  goto 109
	postfix_expression  goto 110


state 89
	unary_expression : DEC_OP . unary_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 168
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 170
	unary_operator  goto 109
	postfix_expression  goto 110


state 90
	labeled_statement : CASE . constant_expression ':' statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	constant_expression  goto 171
	conditional_expression  goto 148
	logical_or_expression  goto 116


state 91
	labeled_statement : DEFAULT . ':' statement

	':'  shift 172


state 92
	if_statement : IF . '(' expression ')' statement

	'('  shift 173


state 93
	selection_statement : SWITCH . '(' expression ')' statement

	'('  shift 174


state 94
	iteration_statement : WHILE . '(' expression ')' statement

	'('  shift 175


state 95
	iteration_statement : DO . statement WHILE '(' expression ')' ';'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 176
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 96
	iteration_statement : FOR . '(' expression_statement expression_statement expression ')' statement
	iteration_statement : FOR . '(' expression_statement expression_statement ')' statement

	'('  shift 177


state 97
	jump_statement : GOTO . ID ';'

	ID  shift 178


state 98
	jump_statement : CONTINUE . ';'

	';'  shift 179


state 99
	jump_statement : BREAK . ';'

	';'  shift 180


state 100
	jump_statement : RETURN . ';'
	jump_statement : RETURN . expression ';'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 181
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 182


state 101
	shift_expression : additive_expression .  (36)
	additive_expression : additive_expression . '-' multiplicative_expression
	additive_expression : additive_expression . '+' multiplicative_expression

	'+'  shift 183
	'-'  shift 184
	.  reduce 36


state 102
	postfix_expression : primary_expression .  (5)

	.  reduce 5


state 103
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	additive_expression : multiplicative_expression .  (33)

	'%'  shift 185
	'*'  shift 186
	'/'  shift 187
	.  reduce 33


state 104
	relational_expression : shift_expression .  (39)
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 39


state 105
	cast_expression : unary_expression .  (27)
	assignment_expression : unary_expression . assignment_operator assignment_expression

	'='  shift 190
	MUL_ASSIGN  shift 191
	DIV_ASSIGN  shift 192
	MOD_ASSIGN  shift 193
	ADD_ASSIGN  shift 194
	SUB_ASSIGN  shift 195
	LEFT_ASSIGN  shift 196
	RIGHT_ASSIGN  shift 197
	AND_ASSIGN  shift 198
	XOR_ASSIGN  shift 199
	OR_ASSIGN  shift 200
	.  reduce 27

	assignment_operator  goto 201


state 106
	multiplicative_expression : cast_expression .  (29)

	.  reduce 29


state 107
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	equality_expression : relational_expression .  (44)
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression

	'<'  shift 202
	'>'  shift 203
	LE_OP  shift 204
	GE_OP  shift 205
	.  reduce 44


state 108
	and_expression : equality_expression .  (47)
	equality_expression : equality_expression . EQ_OP relational_expression
	equality_expression : equality_expression . NE_OP relational_expression

	EQ_OP  shift 206
	NE_OP  shift 207
	.  reduce 47


state 109
	unary_expression : unary_operator . cast_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 146
	cast_expression  goto 208
	unary_operator  goto 109
	postfix_expression  goto 110


state 110
	postfix_expression : postfix_expression . '[' expression ']'
	postfix_expression : postfix_expression . '(' ')'
	postfix_expression : postfix_expression . '(' argument_expression_list ')'
	postfix_expression : postfix_expression . '.' ID
	postfix_expression : postfix_expression . PTR_OP ID
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (15)

	'('  shift 209
	'.'  shift 210
	'['  shift 211
	PTR_OP  shift 212
	INC_OP  shift 213
	DEC_OP  shift 214
	.  reduce 15


state 111
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : and_expression .  (49)

	'&'  shift 215
	.  reduce 49


state 112
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_and_expression .  (55)

	AND_OP  shift 216
	.  reduce 55


state 113
	inclusive_or_expression : exclusive_or_expression .  (51)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 217
	.  reduce 51


state 114
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : inclusive_or_expression .  (53)

	'|'  shift 218
	.  reduce 53


state 115
	assignment_expression : conditional_expression .  (59)

	.  reduce 59


state 116
	conditional_expression : logical_or_expression . '?' expression ':' conditional_expression
	conditional_expression : logical_or_expression .  (57)
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression

	'?'  shift 219
	OR_OP  shift 220
	.  reduce 57


state 117
	expression : assignment_expression .  (72)

	.  reduce 72


state 118
	expression : expression . ',' assignment_expression
	expression_statement : expression . ';'

	','  shift 221
	';'  shift 222


state 119
	statement_list : statement .  (188)

	.  reduce 188


state 120
	statement : expression_statement .  (175)

	.  reduce 175


state 121
	statement : iteration_statement .  (177)

	.  reduce 177


state 122
	statement : labeled_statement .  (173)

	.  reduce 173


state 123
	declaration_list : declaration_list . declaration
	compound_statement : '{' declaration_list . '}'
	compound_statement : '{' declaration_list . statement_list '}'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'}'  shift 223
	'~'  shift 83
	ID  shift 84
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
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	declaration  goto 130
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	logical_and_expression  goto 112
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 50
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	enum_specifier  goto 33
	type_specifier  goto 34
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 119
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	statement_list  goto 224
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 124
	statement : jump_statement .  (178)

	.  reduce 178


state 125
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'}'  shift 225
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 226
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 126
	statement : compound_statement .  (174)

	.  reduce 174


127: shift-reduce conflict (shift 227, reduce 193) on ELSE
state 127
	selection_statement : if_statement . if_else_statement
	if_else_statement : .  (193)

	ELSE  shift 227
	.  reduce 193

	if_else_statement  goto 228


state 128
	statement : selection_statement .  (176)

	.  reduce 176


state 129
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (85)

	'='  shift 132
	.  reduce 85


state 130
	declaration_list : declaration_list declaration .  (187)

	.  reduce 187


state 131
	function_definition : declarator declaration_list compound_statement .  (212)

	.  reduce 212


state 132
	init_declarator : declarator '=' . initializer

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'{'  shift 229
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 230
	initializer  goto 231


state 133
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

	'{'  shift 48
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

	declaration  goto 130
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 50
	enum_specifier  goto 33
	type_specifier  goto 34
	compound_statement  goto 232


state 134
	function_definition : declaration_specifiers declarator compound_statement .  (211)

	.  reduce 211


state 135
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	init_declarator  goto 233
	declarator  goto 129
	direct_declarator  goto 31
	pointer  goto 32


state 136
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 137
	direct_declarator : direct_declarator '(' ')' .  (138)

	.  reduce 138


state 138
	identifier_list : ID .  (152)

	.  reduce 152


state 139
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (151)

	'('  shift 234
	'*'  shift 2
	'['  shift 235
	ID  shift 3
	.  reduce 151

	declarator  goto 236
	direct_declarator  goto 31
	pointer  goto 237
	abstract_declarator  goto 238
	direct_abstract_declarator  goto 239


state 140
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 240


state 141
	parameter_type_list : parameter_list .  (145)
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 241
	.  reduce 145


state 142
	parameter_list : parameter_declaration .  (147)

	.  reduce 147


state 143
	direct_declarator : direct_declarator '(' identifier_list . ')'
	identifier_list : identifier_list . ',' ID

	')'  shift 242
	','  shift 243


state 144
	direct_declarator : direct_declarator '[' ']' .  (135)

	.  reduce 135


state 145
	primary_expression : ID .  (1)

	.  reduce 1


state 146
	cast_expression : unary_expression .  (27)

	.  reduce 27


state 147
	direct_declarator : direct_declarator '[' constant_expression . ']'

	']'  shift 244


state 148
	constant_expression : conditional_expression .  (74)

	.  reduce 74


state 149
	enumerator : ID '=' . constant_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	constant_expression  goto 245
	conditional_expression  goto 148
	logical_or_expression  goto 116


state 150
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 65

	enumerator  goto 246


state 151
	enum_specifier : ENUM '{' enumerator_list '}' .  (121)

	.  reduce 121


state 152
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM ID '{' enumerator_list . '}'

	','  shift 150
	'}'  shift 247


state 153
	struct_declarator : ':' . constant_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	constant_expression  goto 248
	conditional_expression  goto 148
	logical_or_expression  goto 116


state 154
	struct_declarator_list : struct_declarator .  (116)

	.  reduce 116


state 155
	struct_declarator_list : struct_declarator_list . ',' struct_declarator
	struct_declaration : specifier_qualifier_list struct_declarator_list . ';'

	','  shift 249
	';'  shift 250


state 156
	struct_declarator : declarator .  (118)
	struct_declarator : declarator . ':' constant_expression

	':'  shift 251
	.  reduce 118


state 157
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}' .  (105)

	.  reduce 105


state 158
	struct_declaration_list : struct_declaration_list struct_declaration .  (110)

	.  reduce 110


state 159
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (114)

	.  reduce 114


state 160
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (112)

	.  reduce 112


state 161
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union ID '{' struct_declaration_list . '}'

	'}'  shift 252
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

	specifier_qualifier_list  goto 69
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	type_qualifier  goto 71
	enum_specifier  goto 33
	type_specifier  goto 72
	struct_declaration  goto 158


state 162
	type_name : specifier_qualifier_list . abstract_declarator
	type_name : specifier_qualifier_list .  (154)

	'('  shift 253
	'*'  shift 2
	'['  shift 235
	.  reduce 154

	pointer  goto 254
	abstract_declarator  goto 255
	direct_abstract_declarator  goto 239


state 163
	primary_expression : '(' expression . ')'
	expression : expression . ',' assignment_expression

	')'  shift 256
	','  shift 221


state 164
	cast_expression : '(' type_name . ')' cast_expression

	')'  shift 257


state 165
	labeled_statement : ID ':' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 258
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 166
	primary_expression : '(' . expression ')'
	unary_expression : SIZEOF '(' . type_name ')'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
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

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	specifier_qualifier_list  goto 162
	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	logical_and_expression  goto 112
	type_qualifier  goto 71
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	enum_specifier  goto 33
	type_specifier  goto 72
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 163
	type_name  goto 259


state 167
	unary_expression : SIZEOF unary_expression .  (19)

	.  reduce 19


state 168
	primary_expression : '(' . expression ')'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 163


state 169
	unary_expression : INC_OP unary_expression .  (16)

	.  reduce 16


state 170
	unary_expression : DEC_OP unary_expression .  (17)

	.  reduce 17


state 171
	labeled_statement : CASE constant_expression . ':' statement

	':'  shift 260


state 172
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 261
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 173
	if_statement : IF '(' . expression ')' statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 262


state 174
	selection_statement : SWITCH '(' . expression ')' statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 263


state 175
	iteration_statement : WHILE '(' . expression ')' statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 264


state 176
	iteration_statement : DO statement . WHILE '(' expression ')' ';'

	WHILE  shift 265


state 177
	iteration_statement : FOR '(' . expression_statement expression_statement expression ')' statement
	iteration_statement : FOR '(' . expression_statement expression_statement ')' statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	expression_statement  goto 266


state 178
	jump_statement : GOTO ID . ';'

	';'  shift 267


state 179
	jump_statement : CONTINUE ';' .  (202)

	.  reduce 202


state 180
	jump_statement : BREAK ';' .  (203)

	.  reduce 203


state 181
	jump_statement : RETURN ';' .  (204)

	.  reduce 204


state 182
	expression : expression . ',' assignment_expression
	jump_statement : RETURN expression . ';'

	','  shift 221
	';'  shift 268


state 183
	additive_expression : additive_expression '+' . multiplicative_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	multiplicative_expression  goto 269
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 184
	additive_expression : additive_expression '-' . multiplicative_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	multiplicative_expression  goto 270
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 185
	multiplicative_expression : multiplicative_expression '%' . cast_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 146
	cast_expression  goto 271
	unary_operator  goto 109
	postfix_expression  goto 110


state 186
	multiplicative_expression : multiplicative_expression '*' . cast_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 146
	cast_expression  goto 272
	unary_operator  goto 109
	postfix_expression  goto 110


state 187
	multiplicative_expression : multiplicative_expression '/' . cast_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 146
	cast_expression  goto 273
	unary_operator  goto 109
	postfix_expression  goto 110


state 188
	shift_expression : shift_expression LEFT_OP . additive_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 274
	primary_expression  goto 102
	multiplicative_expression  goto 103
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 189
	shift_expression : shift_expression RIGHT_OP . additive_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 275
	primary_expression  goto 102
	multiplicative_expression  goto 103
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 190
	assignment_operator : '=' .  (61)

	.  reduce 61


state 191
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 192
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 193
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 194
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 195
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 196
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 197
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 198
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 199
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 200
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 201
	assignment_expression : unary_expression assignment_operator . assignment_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 276


state 202
	relational_expression : relational_expression '<' . shift_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 277
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 203
	relational_expression : relational_expression '>' . shift_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 278
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 204
	relational_expression : relational_expression LE_OP . shift_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 279
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 205
	relational_expression : relational_expression GE_OP . shift_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 280
	unary_expression  goto 146
	cast_expression  goto 106
	unary_operator  goto 109
	postfix_expression  goto 110


state 206
	equality_expression : equality_expression EQ_OP . relational_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 281
	unary_operator  goto 109
	postfix_expression  goto 110


state 207
	equality_expression : equality_expression NE_OP . relational_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 282
	unary_operator  goto 109
	postfix_expression  goto 110


state 208
	unary_expression : unary_operator cast_expression .  (18)

	.  reduce 18


state 209
	postfix_expression : postfix_expression '(' . ')'
	postfix_expression : postfix_expression '(' . argument_expression_list ')'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	')'  shift 283
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	argument_expression_list  goto 284
	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 285


state 210
	postfix_expression : postfix_expression '.' . ID

	ID  shift 286


state 211
	postfix_expression : postfix_expression '[' . expression ']'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 287


state 212
	postfix_expression : postfix_expression PTR_OP . ID

	ID  shift 288


state 213
	postfix_expression : postfix_expression INC_OP .  (11)

	.  reduce 11


state 214
	postfix_expression : postfix_expression DEC_OP .  (12)

	.  reduce 12


state 215
	and_expression : and_expression '&' . equality_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 289
	unary_operator  goto 109
	postfix_expression  goto 110


state 216
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 290


state 217
	exclusive_or_expression : exclusive_or_expression '^' . and_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 291


state 218
	inclusive_or_expression : inclusive_or_expression '|' . exclusive_or_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	exclusive_or_expression  goto 292


state 219
	conditional_expression : logical_or_expression '?' . expression ':' conditional_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 293


state 220
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 294
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114


state 221
	expression : expression ',' . assignment_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 295


state 222
	expression_statement : expression ';' .  (191)

	.  reduce 191


state 223
	compound_statement : '{' declaration_list '}' .  (184)

	.  reduce 184


state 224
	statement_list : statement_list . statement
	compound_statement : '{' declaration_list statement_list . '}'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'}'  shift 296
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 226
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 225
	compound_statement : '{' statement_list '}' .  (183)

	.  reduce 183


state 226
	statement_list : statement_list statement .  (189)

	.  reduce 189


state 227
	if_else_statement : ELSE . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 297
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 228
	selection_statement : if_statement if_else_statement .  (195)

	.  reduce 195


state 229
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'{'  shift 229
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 230
	initializer  goto 298
	initializer_list  goto 299


state 230
	initializer : assignment_expression .  (168)

	.  reduce 168


state 231
	init_declarator : declarator '=' initializer .  (86)

	.  reduce 86


state 232
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (210)

	.  reduce 210


state 233
	init_declarator_list : init_declarator_list ',' init_declarator .  (84)

	.  reduce 84


state 234
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 234
	')'  shift 300
	'*'  shift 2
	'['  shift 235
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

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declarator  goto 38
	declaration_specifiers  goto 139
	direct_declarator  goto 31
	pointer  goto 237
	parameter_type_list  goto 301
	parameter_list  goto 141
	enum_specifier  goto 33
	type_specifier  goto 34
	parameter_declaration  goto 142
	abstract_declarator  goto 302
	direct_abstract_declarator  goto 239


state 235
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_expression ']'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	']'  shift 303
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	constant_expression  goto 304
	conditional_expression  goto 148
	logical_or_expression  goto 116


state 236
	parameter_declaration : declaration_specifiers declarator .  (149)

	.  reduce 149


state 237
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 234
	'['  shift 235
	ID  shift 3
	.  reduce 156

	direct_declarator  goto 59
	direct_abstract_declarator  goto 305


state 238
	parameter_declaration : declaration_specifiers abstract_declarator .  (150)

	.  reduce 150


state 239
	abstract_declarator : direct_abstract_declarator .  (157)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'

	'('  shift 306
	'['  shift 307
	.  reduce 157


state 240
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (136)

	.  reduce 136


state 241
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
	ELLIPSIS  shift 308

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 139
	enum_specifier  goto 33
	type_specifier  goto 34
	parameter_declaration  goto 309


state 242
	direct_declarator : direct_declarator '(' identifier_list ')' .  (137)

	.  reduce 137


state 243
	identifier_list : identifier_list ',' . ID

	ID  shift 310


state 244
	direct_declarator : direct_declarator '[' constant_expression ']' .  (134)

	.  reduce 134


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
	struct_declarator : ':' constant_expression .  (119)

	.  reduce 119


state 249
	struct_declarator_list : struct_declarator_list ',' . struct_declarator

	'('  shift 1
	'*'  shift 2
	':'  shift 153
	ID  shift 3

	struct_declarator  goto 311
	declarator  goto 156
	direct_declarator  goto 31
	pointer  goto 32


state 250
	struct_declaration : specifier_qualifier_list struct_declarator_list ';' .  (111)

	.  reduce 111


state 251
	struct_declarator : declarator ':' . constant_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	constant_expression  goto 312
	conditional_expression  goto 148
	logical_or_expression  goto 116


state 252
	struct_or_union_specifier : struct_or_union ID '{' struct_declaration_list '}' .  (104)

	.  reduce 104


state 253
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 253
	')'  shift 300
	'*'  shift 2
	'['  shift 235
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

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 139
	pointer  goto 254
	parameter_type_list  goto 301
	parameter_list  goto 141
	enum_specifier  goto 33
	type_specifier  goto 34
	parameter_declaration  goto 142
	abstract_declarator  goto 302
	direct_abstract_declarator  goto 239


state 254
	abstract_declarator : pointer .  (156)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 253
	'['  shift 235
	.  reduce 156

	direct_abstract_declarator  goto 305


state 255
	type_name : specifier_qualifier_list abstract_declarator .  (155)

	.  reduce 155


state 256
	primary_expression : '(' expression ')' .  (4)

	.  reduce 4


state 257
	cast_expression : '(' type_name ')' . cast_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 102
	unary_expression  goto 146
	cast_expression  goto 313
	unary_operator  goto 109
	postfix_expression  goto 110


state 258
	labeled_statement : ID ':' statement .  (179)

	.  reduce 179


state 259
	unary_expression : SIZEOF '(' type_name . ')'

	')'  shift 314


state 260
	labeled_statement : CASE constant_expression ':' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 315
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 261
	labeled_statement : DEFAULT ':' statement .  (181)

	.  reduce 181


state 262
	expression : expression . ',' assignment_expression
	if_statement : IF '(' expression . ')' statement

	')'  shift 316
	','  shift 221


state 263
	expression : expression . ',' assignment_expression
	selection_statement : SWITCH '(' expression . ')' statement

	')'  shift 317
	','  shift 221


state 264
	expression : expression . ',' assignment_expression
	iteration_statement : WHILE '(' expression . ')' statement

	')'  shift 318
	','  shift 221


state 265
	iteration_statement : DO statement WHILE . '(' expression ')' ';'

	'('  shift 319


state 266
	iteration_statement : FOR '(' expression_statement . expression_statement expression ')' statement
	iteration_statement : FOR '(' expression_statement . expression_statement ')' statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	expression_statement  goto 320


state 267
	jump_statement : GOTO ID ';' .  (201)

	.  reduce 201


state 268
	jump_statement : RETURN expression ';' .  (205)

	.  reduce 205


state 269
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	additive_expression : additive_expression '+' multiplicative_expression .  (34)

	'%'  shift 185
	'*'  shift 186
	'/'  shift 187
	.  reduce 34


state 270
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	additive_expression : additive_expression '-' multiplicative_expression .  (35)

	'%'  shift 185
	'*'  shift 186
	'/'  shift 187
	.  reduce 35


state 271
	multiplicative_expression : multiplicative_expression '%' cast_expression .  (32)

	.  reduce 32


state 272
	multiplicative_expression : multiplicative_expression '*' cast_expression .  (30)

	.  reduce 30


state 273
	multiplicative_expression : multiplicative_expression '/' cast_expression .  (31)

	.  reduce 31


state 274
	additive_expression : additive_expression . '-' multiplicative_expression
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : shift_expression LEFT_OP additive_expression .  (37)

	'+'  shift 183
	'-'  shift 184
	.  reduce 37


state 275
	additive_expression : additive_expression . '-' multiplicative_expression
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : shift_expression RIGHT_OP additive_expression .  (38)

	'+'  shift 183
	'-'  shift 184
	.  reduce 38


state 276
	assignment_expression : unary_expression assignment_operator assignment_expression .  (60)

	.  reduce 60


state 277
	relational_expression : relational_expression '<' shift_expression .  (40)
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 40


state 278
	relational_expression : relational_expression '>' shift_expression .  (41)
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 41


state 279
	relational_expression : relational_expression LE_OP shift_expression .  (42)
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 42


state 280
	shift_expression : shift_expression . LEFT_OP additive_expression
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (43)

	LEFT_OP  shift 188
	RIGHT_OP  shift 189
	.  reduce 43


state 281
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	equality_expression : equality_expression EQ_OP relational_expression .  (45)
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression

	'<'  shift 202
	'>'  shift 203
	LE_OP  shift 204
	GE_OP  shift 205
	.  reduce 45


state 282
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression
	equality_expression : equality_expression NE_OP relational_expression .  (46)
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression

	'<'  shift 202
	'>'  shift 203
	LE_OP  shift 204
	GE_OP  shift 205
	.  reduce 46


state 283
	postfix_expression : postfix_expression '(' ')' .  (7)

	.  reduce 7


state 284
	postfix_expression : postfix_expression '(' argument_expression_list . ')'
	argument_expression_list : argument_expression_list . ',' assignment_expression

	')'  shift 321
	','  shift 322


state 285
	argument_expression_list : assignment_expression .  (13)

	.  reduce 13


state 286
	postfix_expression : postfix_expression '.' ID .  (9)

	.  reduce 9


state 287
	postfix_expression : postfix_expression '[' expression . ']'
	expression : expression . ',' assignment_expression

	','  shift 221
	']'  shift 323


state 288
	postfix_expression : postfix_expression PTR_OP ID .  (10)

	.  reduce 10


state 289
	and_expression : and_expression '&' equality_expression .  (48)
	equality_expression : equality_expression . EQ_OP relational_expression
	equality_expression : equality_expression . NE_OP relational_expression

	EQ_OP  shift 206
	NE_OP  shift 207
	.  reduce 48


state 290
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (54)

	'|'  shift 218
	.  reduce 54


state 291
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : exclusive_or_expression '^' and_expression .  (50)

	'&'  shift 215
	.  reduce 50


state 292
	inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression .  (52)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 217
	.  reduce 52


state 293
	conditional_expression : logical_or_expression '?' expression . ':' conditional_expression
	expression : expression . ',' assignment_expression

	','  shift 221
	':'  shift 324


state 294
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (56)

	AND_OP  shift 216
	.  reduce 56


state 295
	expression : expression ',' assignment_expression .  (73)

	.  reduce 73


state 296
	compound_statement : '{' declaration_list statement_list '}' .  (185)

	.  reduce 185


state 297
	if_else_statement : ELSE statement .  (194)

	.  reduce 194


state 298
	initializer_list : initializer .  (171)

	.  reduce 171


state 299
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 325
	'}'  shift 326


state 300
	direct_abstract_declarator : '(' ')' .  (164)

	.  reduce 164


state 301
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 327


state 302
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 328


state 303
	direct_abstract_declarator : '[' ']' .  (160)

	.  reduce 160


state 304
	direct_abstract_declarator : '[' constant_expression . ']'

	']'  shift 329


state 305
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'
	abstract_declarator : pointer direct_abstract_declarator .  (158)

	'('  shift 306
	'['  shift 307
	.  reduce 158


state 306
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

	')'  shift 330
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

	struct_or_union_specifier  goto 25
	struct_or_union  goto 26
	storage_class_specifier  goto 27
	type_qualifier  goto 28
	declaration_specifiers  goto 139
	parameter_type_list  goto 331
	parameter_list  goto 141
	enum_specifier  goto 33
	type_specifier  goto 34
	parameter_declaration  goto 142


state 307
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_expression ']'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	']'  shift 332
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	constant_expression  goto 333
	conditional_expression  goto 148
	logical_or_expression  goto 116


state 308
	parameter_type_list : parameter_list ',' ELLIPSIS .  (146)

	.  reduce 146


state 309
	parameter_list : parameter_list ',' parameter_declaration .  (148)

	.  reduce 148


state 310
	identifier_list : identifier_list ',' ID .  (153)

	.  reduce 153


state 311
	struct_declarator_list : struct_declarator_list ',' struct_declarator .  (117)

	.  reduce 117


state 312
	struct_declarator : declarator ':' constant_expression .  (120)

	.  reduce 120


state 313
	cast_expression : '(' type_name ')' cast_expression .  (28)

	.  reduce 28


state 314
	unary_expression : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 315
	labeled_statement : CASE constant_expression ':' statement .  (180)

	.  reduce 180


state 316
	if_statement : IF '(' expression ')' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 334
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 317
	selection_statement : SWITCH '(' expression ')' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 335
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 318
	iteration_statement : WHILE '(' expression ')' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 336
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 319
	iteration_statement : DO statement WHILE '(' . expression ')' ';'

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 337


state 320
	iteration_statement : FOR '(' expression_statement expression_statement . expression ')' statement
	iteration_statement : FOR '(' expression_statement expression_statement . ')' statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	')'  shift 338
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 339


state 321
	postfix_expression : postfix_expression '(' argument_expression_list ')' .  (8)

	.  reduce 8


state 322
	argument_expression_list : argument_expression_list ',' . assignment_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 340


state 323
	postfix_expression : postfix_expression '[' expression ']' .  (6)

	.  reduce 6


state 324
	conditional_expression : logical_or_expression '?' expression ':' . conditional_expression

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 146
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 341
	logical_or_expression  goto 116


state 325
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	'{'  shift 229
	'}'  shift 342
	'~'  shift 83
	ID  shift 145
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 230
	initializer  goto 343


state 326
	initializer : '{' initializer_list '}' .  (169)

	.  reduce 169


state 327
	direct_abstract_declarator : '(' parameter_type_list ')' .  (165)

	.  reduce 165


state 328
	direct_abstract_declarator : '(' abstract_declarator ')' .  (159)

	.  reduce 159


state 329
	direct_abstract_declarator : '[' constant_expression ']' .  (161)

	.  reduce 161


state 330
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (166)

	.  reduce 166


state 331
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 344


state 332
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (162)

	.  reduce 162


state 333
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression . ']'

	']'  shift 345


state 334
	if_statement : IF '(' expression ')' statement .  (192)

	.  reduce 192


state 335
	selection_statement : SWITCH '(' expression ')' statement .  (196)

	.  reduce 196


state 336
	iteration_statement : WHILE '(' expression ')' statement .  (197)

	.  reduce 197


state 337
	expression : expression . ',' assignment_expression
	iteration_statement : DO statement WHILE '(' expression . ')' ';'

	')'  shift 346
	','  shift 221


state 338
	iteration_statement : FOR '(' expression_statement expression_statement ')' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 347
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 339
	expression : expression . ',' assignment_expression
	iteration_statement : FOR '(' expression_statement expression_statement expression . ')' statement

	')'  shift 348
	','  shift 221


state 340
	argument_expression_list : argument_expression_list ',' assignment_expression .  (14)

	.  reduce 14


state 341
	conditional_expression : logical_or_expression '?' expression ':' conditional_expression .  (58)

	.  reduce 58


state 342
	initializer : '{' initializer_list ',' '}' .  (170)

	.  reduce 170


state 343
	initializer_list : initializer_list ',' initializer .  (172)

	.  reduce 172


state 344
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (167)

	.  reduce 167


state 345
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']' .  (163)

	.  reduce 163


state 346
	iteration_statement : DO statement WHILE '(' expression ')' . ';'

	';'  shift 349


state 347
	iteration_statement : FOR '(' expression_statement expression_statement ')' statement .  (199)

	.  reduce 199


state 348
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' . statement

	'!'  shift 75
	'&'  shift 76
	'('  shift 77
	'*'  shift 78
	'+'  shift 79
	'-'  shift 80
	';'  shift 81
	'{'  shift 48
	'~'  shift 83
	ID  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 90
	DEFAULT  shift 91
	IF  shift 92
	SWITCH  shift 93
	WHILE  shift 94
	DO  shift 95
	FOR  shift 96
	GOTO  shift 97
	CONTINUE  shift 98
	BREAK  shift 99
	RETURN  shift 100

	additive_expression  goto 101
	primary_expression  goto 102
	multiplicative_expression  goto 103
	shift_expression  goto 104
	unary_expression  goto 105
	cast_expression  goto 106
	relational_expression  goto 107
	equality_expression  goto 108
	unary_operator  goto 109
	postfix_expression  goto 110
	and_expression  goto 111
	logical_and_expression  goto 112
	exclusive_or_expression  goto 113
	inclusive_or_expression  goto 114
	conditional_expression  goto 115
	logical_or_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	statement  goto 350
	expression_statement  goto 120
	iteration_statement  goto 121
	labeled_statement  goto 122
	jump_statement  goto 124
	compound_statement  goto 126
	if_statement  goto 127
	selection_statement  goto 128


state 349
	iteration_statement : DO statement WHILE '(' expression ')' ';' .  (198)

	.  reduce 198


state 350
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement .  (200)

	.  reduce 200


##############################################################################
# Summary
##############################################################################

State 127 contains 1 shift-reduce conflict(s)


84 token(s), 66 nonterminal(s)
214 grammar rule(s), 351 state(s)


##############################################################################
# End of File
##############################################################################
