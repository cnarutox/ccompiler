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
# Time: 11:05:39
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 27
	struct_or_union_specifier  goto 28
	declaration  goto 29
	enum_specifier  goto 30
	type_qualifier  goto 31
	declarator  goto 32
	direct_declarator  goto 33
	pointer  goto 34
	external_declaration  goto 35
	translation_unit  goto 36
	function_definition  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	declarator  goto 38
	direct_declarator  goto 33
	pointer  goto 34


state 2
	pointer : '*' .  (139)
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' . pointer

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
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . IDENTIFIER
	enum_specifier : ENUM . IDENTIFIER '{' enumerator_list '}'

	'{'  shift 42
	IDENTIFIER  shift 43


state 24
	struct_or_union_specifier : struct_or_union . IDENTIFIER
	struct_or_union_specifier : struct_or_union . IDENTIFIER '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . '{' struct_declaration_list '}'

	'{'  shift 44
	IDENTIFIER  shift 45


state 25
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 46
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31


state 26
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 47
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31


state 27
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 48
	IDENTIFIER  shift 3

	init_declarator_list  goto 49
	init_declarator  goto 50
	declarator  goto 51
	direct_declarator  goto 33
	pointer  goto 34


state 28
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 29
	external_declaration : declaration .  (207)

	.  reduce 207


state 30
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 31
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 52
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31


state 32
	function_definition : declarator . compound_statement
	function_definition : declarator . declaration_list compound_statement

	'{'  shift 53
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 54
	struct_or_union_specifier  goto 28
	declaration  goto 55
	enum_specifier  goto 30
	type_qualifier  goto 31
	declaration_list  goto 56
	compound_statement  goto 57


state 33
	declarator : direct_declarator .  (131)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'

	'('  shift 58
	'['  shift 59
	.  reduce 131


state 34
	declarator : pointer . direct_declarator

	'('  shift 1
	IDENTIFIER  shift 3

	direct_declarator  goto 60


state 35
	translation_unit : external_declaration .  (204)

	.  reduce 204


state 36
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 27
	struct_or_union_specifier  goto 28
	declaration  goto 29
	enum_specifier  goto 30
	type_qualifier  goto 31
	declarator  goto 32
	direct_declarator  goto 33
	pointer  goto 34
	external_declaration  goto 61
	function_definition  goto 37


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

	enumerator_list  goto 66
	enumerator  goto 67


state 43
	enum_specifier : ENUM IDENTIFIER .  (123)
	enum_specifier : ENUM IDENTIFIER . '{' enumerator_list '}'

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
	struct_or_union  goto 24
	type_specifier  goto 70
	struct_declaration_list  goto 71
	struct_declaration  goto 72
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 73


state 45
	struct_or_union_specifier : struct_or_union IDENTIFIER .  (106)
	struct_or_union_specifier : struct_or_union IDENTIFIER . '{' struct_declaration_list '}'

	'{'  shift 74
	.  reduce 106


state 46
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 47
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 48
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 49
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 75
	';'  shift 76


state 50
	init_declarator_list : init_declarator .  (83)

	.  reduce 83


state 51
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 77
	'{'  shift 53
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 54
	struct_or_union_specifier  goto 28
	declaration  goto 55
	enum_specifier  goto 30
	type_qualifier  goto 31
	declaration_list  goto 78
	compound_statement  goto 79


state 52
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 53
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . statement_list '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'}'  shift 87
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	struct_or_union  goto 24
	expression  goto 118
	storage_class_specifier  goto 25
	type_specifier  goto 26
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	declaration_specifiers  goto 54
	struct_or_union_specifier  goto 28
	declaration  goto 55
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	enum_specifier  goto 30
	type_qualifier  goto 31
	labeled_statement  goto 124
	declaration_list  goto 125
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 129
	compound_statement  goto 130
	statement_list  goto 131
	iteration_statement  goto 132


state 54
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 48
	IDENTIFIER  shift 3

	init_declarator_list  goto 49
	init_declarator  goto 50
	declarator  goto 133
	direct_declarator  goto 33
	pointer  goto 34


state 55
	declaration_list : declaration .  (186)

	.  reduce 186


state 56
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

	'{'  shift 53
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 54
	struct_or_union_specifier  goto 28
	declaration  goto 134
	enum_specifier  goto 30
	type_qualifier  goto 31
	compound_statement  goto 135


state 57
	function_definition : declarator compound_statement .  (211)

	.  reduce 211


state 58
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'
	direct_declarator : direct_declarator '(' . ')'

	')'  shift 136
	IDENTIFIER  shift 137
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

	parameter_type_list  goto 138
	struct_or_union  goto 24
	parameter_list  goto 139
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 140
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31
	parameter_declaration  goto 141
	identifier_list  goto 142


state 59
	direct_declarator : direct_declarator '[' . constant_expression ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	']'  shift 143
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	constant_expression  goto 146
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 147


state 60
	declarator : pointer direct_declarator .  (130)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' ')'

	'('  shift 58
	'['  shift 59
	.  reduce 130


state 61
	translation_unit : translation_unit external_declaration .  (205)

	.  reduce 205


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
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 149
	'}'  shift 150


state 67
	enumerator_list : enumerator .  (124)

	.  reduce 124


state 68
	enum_specifier : ENUM IDENTIFIER '{' . enumerator_list '}'

	IDENTIFIER  shift 65

	enumerator_list  goto 151
	enumerator  goto 67


state 69
	struct_declaration : specifier_qualifier_list . struct_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	':'  shift 152
	IDENTIFIER  shift 3

	struct_declarator  goto 153
	struct_declarator_list  goto 154
	declarator  goto 155
	direct_declarator  goto 33
	pointer  goto 34


state 70
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

	specifier_qualifier_list  goto 156
	struct_or_union  goto 24
	type_specifier  goto 70
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 73


state 71
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
	struct_or_union  goto 24
	type_specifier  goto 70
	struct_declaration  goto 158
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 73


state 72
	struct_declaration_list : struct_declaration .  (109)

	.  reduce 109


state 73
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
	struct_or_union  goto 24
	type_specifier  goto 70
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 73


state 74
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

	specifier_qualifier_list  goto 69
	struct_or_union  goto 24
	type_specifier  goto 70
	struct_declaration_list  goto 160
	struct_declaration  goto 72
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 73


state 75
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	init_declarator  goto 161
	declarator  goto 133
	direct_declarator  goto 33
	pointer  goto 34


state 76
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 77
	init_declarator : declarator '=' . initializer

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'{'  shift 162
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 163
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	initializer  goto 164


state 78
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

	'{'  shift 53
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

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 54
	struct_or_union_specifier  goto 28
	declaration  goto 134
	enum_specifier  goto 30
	type_qualifier  goto 31
	compound_statement  goto 165


state 79
	function_definition : declaration_specifiers declarator compound_statement .  (209)

	.  reduce 209


state 80
	unary_operator : '!' .  (26)

	.  reduce 26


state 81
	unary_operator : '&' .  (21)

	.  reduce 21


state 82
	primary_expression : '(' . expression ')'
	cast_expression : '(' . type_name ')' cast_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	specifier_qualifier_list  goto 166
	struct_or_union  goto 24
	expression  goto 167
	type_specifier  goto 70
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	struct_or_union_specifier  goto 28
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	enum_specifier  goto 30
	type_qualifier  goto 73
	type_name  goto 168


state 83
	unary_operator : '*' .  (22)

	.  reduce 22


state 84
	unary_operator : '+' .  (23)

	.  reduce 23


state 85
	unary_operator : '-' .  (24)

	.  reduce 24


state 86
	expression_statement : ';' .  (190)

	.  reduce 190


state 87
	compound_statement : '{' '}' .  (182)

	.  reduce 182


state 88
	unary_operator : '~' .  (25)

	.  reduce 25


state 89
	primary_expression : IDENTIFIER .  (1)
	labeled_statement : IDENTIFIER . ':' statement

	':'  shift 169
	.  reduce 1


state 90
	primary_expression : CONSTANT .  (2)

	.  reduce 2


state 91
	primary_expression : STRING_LITERAL .  (3)

	.  reduce 3


state 92
	unary_expression : SIZEOF . '(' type_name ')'
	unary_expression : SIZEOF . unary_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 170
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 171


state 93
	unary_expression : INC_OP . unary_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 172
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 173


state 94
	unary_expression : DEC_OP . unary_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 172
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 174


state 95
	labeled_statement : CASE . constant_expression ':' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	constant_expression  goto 175
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 147


state 96
	labeled_statement : DEFAULT . ':' statement

	':'  shift 176


state 97
	selection_statement : IF . '(' expression ')' statement ELSE statement
	selection_statement : IF . '(' expression ')' statement

	'('  shift 177


state 98
	selection_statement : SWITCH . '(' expression ')' statement

	'('  shift 178


state 99
	iteration_statement : WHILE . '(' expression ')' statement

	'('  shift 179


state 100
	iteration_statement : DO . statement WHILE '(' expression ')' ';'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 180
	compound_statement  goto 130
	iteration_statement  goto 132


state 101
	iteration_statement : FOR . '(' expression_statement expression_statement ')' statement
	iteration_statement : FOR . '(' expression_statement expression_statement expression ')' statement

	'('  shift 181


state 102
	jump_statement : GOTO . IDENTIFIER ';'

	IDENTIFIER  shift 182


state 103
	jump_statement : CONTINUE . ';'

	';'  shift 183


state 104
	jump_statement : BREAK . ';'

	';'  shift 184


state 105
	jump_statement : RETURN . ';'
	jump_statement : RETURN . expression ';'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 185
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 186
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 106
	unary_expression : unary_operator . cast_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 187
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145


state 107
	multiplicative_expression : cast_expression .  (29)

	.  reduce 29


state 108
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	additive_expression : multiplicative_expression .  (33)

	'%'  shift 188
	'*'  shift 189
	'/'  shift 190
	.  reduce 33


state 109
	postfix_expression : postfix_expression . '[' expression ']'
	postfix_expression : postfix_expression . '(' ')'
	postfix_expression : postfix_expression . '(' argument_expression_list ')'
	postfix_expression : postfix_expression . '.' IDENTIFIER
	postfix_expression : postfix_expression . PTR_OP IDENTIFIER
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (15)

	'('  shift 191
	'.'  shift 192
	'['  shift 193
	PTR_OP  shift 194
	INC_OP  shift 195
	DEC_OP  shift 196
	.  reduce 15


state 110
	postfix_expression : primary_expression .  (5)

	.  reduce 5


state 111
	cast_expression : unary_expression .  (27)
	assignment_expression : unary_expression . assignment_operator assignment_expression

	'='  shift 197
	MUL_ASSIGN  shift 198
	DIV_ASSIGN  shift 199
	MOD_ASSIGN  shift 200
	ADD_ASSIGN  shift 201
	SUB_ASSIGN  shift 202
	LEFT_ASSIGN  shift 203
	RIGHT_ASSIGN  shift 204
	AND_ASSIGN  shift 205
	XOR_ASSIGN  shift 206
	OR_ASSIGN  shift 207
	.  reduce 27

	assignment_operator  goto 208


state 112
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression
	shift_expression : additive_expression .  (36)

	'+'  shift 209
	'-'  shift 210
	.  reduce 36


state 113
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : shift_expression .  (39)

	LEFT_OP  shift 211
	RIGHT_OP  shift 212
	.  reduce 39


state 114
	equality_expression : relational_expression .  (44)
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 213
	'>'  shift 214
	LE_OP  shift 215
	GE_OP  shift 216
	.  reduce 44


state 115
	and_expression : equality_expression .  (47)
	equality_expression : equality_expression . NE_OP relational_expression
	equality_expression : equality_expression . EQ_OP relational_expression

	EQ_OP  shift 217
	NE_OP  shift 218
	.  reduce 47


state 116
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : and_expression .  (49)

	'&'  shift 219
	.  reduce 49


state 117
	expression : assignment_expression .  (72)

	.  reduce 72


state 118
	expression : expression . ',' assignment_expression
	expression_statement : expression . ';'

	','  shift 220
	';'  shift 221


state 119
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : inclusive_or_expression .  (53)

	'|'  shift 222
	.  reduce 53


state 120
	conditional_expression : logical_or_expression .  (57)
	conditional_expression : logical_or_expression . '?' expression ':' conditional_expression
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression

	'?'  shift 223
	OR_OP  shift 224
	.  reduce 57


state 121
	logical_or_expression : logical_and_expression .  (55)
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression

	AND_OP  shift 225
	.  reduce 55


state 122
	exclusive_or_expression : exclusive_or_expression . '^' and_expression
	inclusive_or_expression : exclusive_or_expression .  (51)

	'^'  shift 226
	.  reduce 51


state 123
	assignment_expression : conditional_expression .  (59)

	.  reduce 59


state 124
	statement : labeled_statement .  (173)

	.  reduce 173


state 125
	declaration_list : declaration_list . declaration
	compound_statement : '{' declaration_list . statement_list '}'
	compound_statement : '{' declaration_list . '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'}'  shift 227
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	struct_or_union  goto 24
	expression  goto 118
	storage_class_specifier  goto 25
	type_specifier  goto 26
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	declaration_specifiers  goto 54
	struct_or_union_specifier  goto 28
	declaration  goto 134
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	enum_specifier  goto 30
	type_qualifier  goto 31
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 129
	compound_statement  goto 130
	statement_list  goto 228
	iteration_statement  goto 132


state 126
	statement : selection_statement .  (176)

	.  reduce 176


state 127
	statement : jump_statement .  (178)

	.  reduce 178


state 128
	statement : expression_statement .  (175)

	.  reduce 175


state 129
	statement_list : statement .  (188)

	.  reduce 188


state 130
	statement : compound_statement .  (174)

	.  reduce 174


state 131
	statement_list : statement_list . statement
	compound_statement : '{' statement_list . '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'}'  shift 229
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 230
	compound_statement  goto 130
	iteration_statement  goto 132


state 132
	statement : iteration_statement .  (177)

	.  reduce 177


state 133
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer

	'='  shift 77
	.  reduce 85


state 134
	declaration_list : declaration_list declaration .  (187)

	.  reduce 187


state 135
	function_definition : declarator declaration_list compound_statement .  (210)

	.  reduce 210


state 136
	direct_declarator : direct_declarator '(' ')' .  (138)

	.  reduce 138


state 137
	identifier_list : IDENTIFIER .  (152)

	.  reduce 152


state 138
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 231


state 139
	parameter_list : parameter_list . ',' parameter_declaration
	parameter_type_list : parameter_list .  (145)
	parameter_type_list : parameter_list . ',' ELLIPSIS

	','  shift 232
	.  reduce 145


state 140
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers .  (151)

	'('  shift 233
	'*'  shift 2
	'['  shift 234
	IDENTIFIER  shift 3
	.  reduce 151

	declarator  goto 235
	direct_declarator  goto 33
	pointer  goto 236
	direct_abstract_declarator  goto 237
	abstract_declarator  goto 238


state 141
	parameter_list : parameter_declaration .  (147)

	.  reduce 147


state 142
	direct_declarator : direct_declarator '(' identifier_list . ')'
	identifier_list : identifier_list . ',' IDENTIFIER

	')'  shift 239
	','  shift 240


state 143
	direct_declarator : direct_declarator '[' ']' .  (135)

	.  reduce 135


state 144
	primary_expression : IDENTIFIER .  (1)

	.  reduce 1


state 145
	cast_expression : unary_expression .  (27)

	.  reduce 27


state 146
	direct_declarator : direct_declarator '[' constant_expression . ']'

	']'  shift 241


state 147
	constant_expression : conditional_expression .  (74)

	.  reduce 74


state 148
	enumerator : IDENTIFIER '=' . constant_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	constant_expression  goto 242
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 147


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
	struct_declarator : ':' . constant_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	constant_expression  goto 245
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 147


state 153
	struct_declarator_list : struct_declarator .  (116)

	.  reduce 116


state 154
	struct_declaration : specifier_qualifier_list struct_declarator_list . ';'
	struct_declarator_list : struct_declarator_list . ',' struct_declarator

	','  shift 246
	';'  shift 247


state 155
	struct_declarator : declarator .  (118)
	struct_declarator : declarator . ':' constant_expression

	':'  shift 248
	.  reduce 118


state 156
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (112)

	.  reduce 112


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
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list . '}'

	'}'  shift 249
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
	struct_or_union  goto 24
	type_specifier  goto 70
	struct_declaration  goto 158
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 73


state 161
	init_declarator_list : init_declarator_list ',' init_declarator .  (84)

	.  reduce 84


state 162
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'{'  shift 162
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 163
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	initializer_list  goto 250
	initializer  goto 251


state 163
	initializer : assignment_expression .  (168)

	.  reduce 168


state 164
	init_declarator : declarator '=' initializer .  (86)

	.  reduce 86


state 165
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (208)

	.  reduce 208


state 166
	type_name : specifier_qualifier_list .  (154)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 252
	'*'  shift 2
	'['  shift 234
	.  reduce 154

	pointer  goto 253
	direct_abstract_declarator  goto 237
	abstract_declarator  goto 254


state 167
	primary_expression : '(' expression . ')'
	expression : expression . ',' assignment_expression

	')'  shift 255
	','  shift 220


state 168
	cast_expression : '(' type_name . ')' cast_expression

	')'  shift 256


state 169
	labeled_statement : IDENTIFIER ':' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 257
	compound_statement  goto 130
	iteration_statement  goto 132


state 170
	primary_expression : '(' . expression ')'
	unary_expression : SIZEOF '(' . type_name ')'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	specifier_qualifier_list  goto 166
	struct_or_union  goto 24
	expression  goto 167
	type_specifier  goto 70
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	struct_or_union_specifier  goto 28
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	enum_specifier  goto 30
	type_qualifier  goto 73
	type_name  goto 258


state 171
	unary_expression : SIZEOF unary_expression .  (19)

	.  reduce 19


state 172
	primary_expression : '(' . expression ')'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 167
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 173
	unary_expression : INC_OP unary_expression .  (16)

	.  reduce 16


state 174
	unary_expression : DEC_OP unary_expression .  (17)

	.  reduce 17


state 175
	labeled_statement : CASE constant_expression . ':' statement

	':'  shift 259


state 176
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 260
	compound_statement  goto 130
	iteration_statement  goto 132


state 177
	selection_statement : IF '(' . expression ')' statement ELSE statement
	selection_statement : IF '(' . expression ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 261
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 178
	selection_statement : SWITCH '(' . expression ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 262
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 179
	iteration_statement : WHILE '(' . expression ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 263
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 180
	iteration_statement : DO statement . WHILE '(' expression ')' ';'

	WHILE  shift 264


state 181
	iteration_statement : FOR '(' . expression_statement expression_statement ')' statement
	iteration_statement : FOR '(' . expression_statement expression_statement expression ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	expression_statement  goto 265


state 182
	jump_statement : GOTO IDENTIFIER . ';'

	';'  shift 266


state 183
	jump_statement : CONTINUE ';' .  (200)

	.  reduce 200


state 184
	jump_statement : BREAK ';' .  (201)

	.  reduce 201


state 185
	jump_statement : RETURN ';' .  (202)

	.  reduce 202


state 186
	expression : expression . ',' assignment_expression
	jump_statement : RETURN expression . ';'

	','  shift 220
	';'  shift 267


state 187
	unary_expression : unary_operator cast_expression .  (18)

	.  reduce 18


state 188
	multiplicative_expression : multiplicative_expression '%' . cast_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 268
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145


state 189
	multiplicative_expression : multiplicative_expression '*' . cast_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 269
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145


state 190
	multiplicative_expression : multiplicative_expression '/' . cast_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 270
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145


state 191
	postfix_expression : postfix_expression '(' . ')'
	postfix_expression : postfix_expression '(' . argument_expression_list ')'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	')'  shift 271
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	argument_expression_list  goto 272
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 273
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 192
	postfix_expression : postfix_expression '.' . IDENTIFIER

	IDENTIFIER  shift 274


state 193
	postfix_expression : postfix_expression '[' . expression ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 275
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 194
	postfix_expression : postfix_expression PTR_OP . IDENTIFIER

	IDENTIFIER  shift 276


state 195
	postfix_expression : postfix_expression INC_OP .  (11)

	.  reduce 11


state 196
	postfix_expression : postfix_expression DEC_OP .  (12)

	.  reduce 12


state 197
	assignment_operator : '=' .  (61)

	.  reduce 61


state 198
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 199
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 200
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 201
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 202
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 203
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 204
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 205
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 206
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 207
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 208
	assignment_expression : unary_expression assignment_operator . assignment_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 277
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 209
	additive_expression : additive_expression '+' . multiplicative_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 278
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145


state 210
	additive_expression : additive_expression '-' . multiplicative_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 279
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145


state 211
	shift_expression : shift_expression LEFT_OP . additive_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 280


state 212
	shift_expression : shift_expression RIGHT_OP . additive_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 281


state 213
	relational_expression : relational_expression '<' . shift_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 282


state 214
	relational_expression : relational_expression '>' . shift_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 283


state 215
	relational_expression : relational_expression LE_OP . shift_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 284


state 216
	relational_expression : relational_expression GE_OP . shift_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 285


state 217
	equality_expression : equality_expression EQ_OP . relational_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 286


state 218
	equality_expression : equality_expression NE_OP . relational_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 287


state 219
	and_expression : and_expression '&' . equality_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 288


state 220
	expression : expression ',' . assignment_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 289
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 221
	expression_statement : expression ';' .  (191)

	.  reduce 191


state 222
	inclusive_or_expression : inclusive_or_expression '|' . exclusive_or_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	exclusive_or_expression  goto 290


state 223
	conditional_expression : logical_or_expression '?' . expression ':' conditional_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 291
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 224
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_and_expression  goto 292
	exclusive_or_expression  goto 122


state 225
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 293
	exclusive_or_expression  goto 122


state 226
	exclusive_or_expression : exclusive_or_expression '^' . and_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 294


state 227
	compound_statement : '{' declaration_list '}' .  (184)

	.  reduce 184


state 228
	statement_list : statement_list . statement
	compound_statement : '{' declaration_list statement_list . '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'}'  shift 295
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 230
	compound_statement  goto 130
	iteration_statement  goto 132


state 229
	compound_statement : '{' statement_list '}' .  (183)

	.  reduce 183


state 230
	statement_list : statement_list statement .  (189)

	.  reduce 189


state 231
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (136)

	.  reduce 136


state 232
	parameter_list : parameter_list ',' . parameter_declaration
	parameter_type_list : parameter_list ',' . ELLIPSIS

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
	ELLIPSIS  shift 296

	struct_or_union  goto 24
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 140
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31
	parameter_declaration  goto 297


state 233
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 233
	')'  shift 298
	'*'  shift 2
	'['  shift 234
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

	parameter_type_list  goto 299
	struct_or_union  goto 24
	parameter_list  goto 139
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 140
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31
	declarator  goto 38
	direct_declarator  goto 33
	pointer  goto 236
	direct_abstract_declarator  goto 237
	parameter_declaration  goto 141
	abstract_declarator  goto 300


state 234
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_expression ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	']'  shift 301
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	constant_expression  goto 302
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 147


state 235
	parameter_declaration : declaration_specifiers declarator .  (149)

	.  reduce 149


state 236
	declarator : pointer . direct_declarator
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (156)

	'('  shift 233
	'['  shift 234
	IDENTIFIER  shift 3
	.  reduce 156

	direct_declarator  goto 60
	direct_abstract_declarator  goto 303


state 237
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	abstract_declarator : direct_abstract_declarator .  (157)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'

	'('  shift 304
	'['  shift 305
	.  reduce 157


state 238
	parameter_declaration : declaration_specifiers abstract_declarator .  (150)

	.  reduce 150


state 239
	direct_declarator : direct_declarator '(' identifier_list ')' .  (137)

	.  reduce 137


state 240
	identifier_list : identifier_list ',' . IDENTIFIER

	IDENTIFIER  shift 306


state 241
	direct_declarator : direct_declarator '[' constant_expression ']' .  (134)

	.  reduce 134


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
	struct_declarator : ':' constant_expression .  (119)

	.  reduce 119


state 246
	struct_declarator_list : struct_declarator_list ',' . struct_declarator

	'('  shift 1
	'*'  shift 2
	':'  shift 152
	IDENTIFIER  shift 3

	struct_declarator  goto 307
	declarator  goto 155
	direct_declarator  goto 33
	pointer  goto 34


state 247
	struct_declaration : specifier_qualifier_list struct_declarator_list ';' .  (111)

	.  reduce 111


state 248
	struct_declarator : declarator ':' . constant_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	constant_expression  goto 308
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 147


state 249
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}' .  (104)

	.  reduce 104


state 250
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 309
	'}'  shift 310


state 251
	initializer_list : initializer .  (171)

	.  reduce 171


state 252
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 252
	')'  shift 298
	'*'  shift 2
	'['  shift 234
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

	parameter_type_list  goto 299
	struct_or_union  goto 24
	parameter_list  goto 139
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 140
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31
	pointer  goto 253
	direct_abstract_declarator  goto 237
	parameter_declaration  goto 141
	abstract_declarator  goto 300


state 253
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (156)

	'('  shift 252
	'['  shift 234
	.  reduce 156

	direct_abstract_declarator  goto 303


state 254
	type_name : specifier_qualifier_list abstract_declarator .  (155)

	.  reduce 155


state 255
	primary_expression : '(' expression ')' .  (4)

	.  reduce 4


state 256
	cast_expression : '(' type_name ')' . cast_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 311
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145


state 257
	labeled_statement : IDENTIFIER ':' statement .  (179)

	.  reduce 179


state 258
	unary_expression : SIZEOF '(' type_name . ')'

	')'  shift 312


state 259
	labeled_statement : CASE constant_expression ':' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 313
	compound_statement  goto 130
	iteration_statement  goto 132


state 260
	labeled_statement : DEFAULT ':' statement .  (181)

	.  reduce 181


state 261
	expression : expression . ',' assignment_expression
	selection_statement : IF '(' expression . ')' statement ELSE statement
	selection_statement : IF '(' expression . ')' statement

	')'  shift 314
	','  shift 220


state 262
	expression : expression . ',' assignment_expression
	selection_statement : SWITCH '(' expression . ')' statement

	')'  shift 315
	','  shift 220


state 263
	expression : expression . ',' assignment_expression
	iteration_statement : WHILE '(' expression . ')' statement

	')'  shift 316
	','  shift 220


state 264
	iteration_statement : DO statement WHILE . '(' expression ')' ';'

	'('  shift 317


state 265
	iteration_statement : FOR '(' expression_statement . expression_statement ')' statement
	iteration_statement : FOR '(' expression_statement . expression_statement expression ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	expression_statement  goto 318


state 266
	jump_statement : GOTO IDENTIFIER ';' .  (199)

	.  reduce 199


state 267
	jump_statement : RETURN expression ';' .  (203)

	.  reduce 203


state 268
	multiplicative_expression : multiplicative_expression '%' cast_expression .  (32)

	.  reduce 32


state 269
	multiplicative_expression : multiplicative_expression '*' cast_expression .  (30)

	.  reduce 30


state 270
	multiplicative_expression : multiplicative_expression '/' cast_expression .  (31)

	.  reduce 31


state 271
	postfix_expression : postfix_expression '(' ')' .  (7)

	.  reduce 7


state 272
	postfix_expression : postfix_expression '(' argument_expression_list . ')'
	argument_expression_list : argument_expression_list . ',' assignment_expression

	')'  shift 319
	','  shift 320


state 273
	argument_expression_list : assignment_expression .  (13)

	.  reduce 13


state 274
	postfix_expression : postfix_expression '.' IDENTIFIER .  (9)

	.  reduce 9


state 275
	postfix_expression : postfix_expression '[' expression . ']'
	expression : expression . ',' assignment_expression

	','  shift 220
	']'  shift 321


state 276
	postfix_expression : postfix_expression PTR_OP IDENTIFIER .  (10)

	.  reduce 10


state 277
	assignment_expression : unary_expression assignment_operator assignment_expression .  (60)

	.  reduce 60


state 278
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	additive_expression : additive_expression '+' multiplicative_expression .  (34)

	'%'  shift 188
	'*'  shift 189
	'/'  shift 190
	.  reduce 34


state 279
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	additive_expression : additive_expression '-' multiplicative_expression .  (35)

	'%'  shift 188
	'*'  shift 189
	'/'  shift 190
	.  reduce 35


state 280
	shift_expression : shift_expression LEFT_OP additive_expression .  (37)
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 209
	'-'  shift 210
	.  reduce 37


state 281
	shift_expression : shift_expression RIGHT_OP additive_expression .  (38)
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 209
	'-'  shift 210
	.  reduce 38


state 282
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '<' shift_expression .  (40)

	LEFT_OP  shift 211
	RIGHT_OP  shift 212
	.  reduce 40


state 283
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '>' shift_expression .  (41)

	LEFT_OP  shift 211
	RIGHT_OP  shift 212
	.  reduce 41


state 284
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression LE_OP shift_expression .  (42)

	LEFT_OP  shift 211
	RIGHT_OP  shift 212
	.  reduce 42


state 285
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (43)

	LEFT_OP  shift 211
	RIGHT_OP  shift 212
	.  reduce 43


state 286
	equality_expression : equality_expression EQ_OP relational_expression .  (45)
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 213
	'>'  shift 214
	LE_OP  shift 215
	GE_OP  shift 216
	.  reduce 45


state 287
	equality_expression : equality_expression NE_OP relational_expression .  (46)
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression

	'<'  shift 213
	'>'  shift 214
	LE_OP  shift 215
	GE_OP  shift 216
	.  reduce 46


state 288
	equality_expression : equality_expression . NE_OP relational_expression
	and_expression : and_expression '&' equality_expression .  (48)
	equality_expression : equality_expression . EQ_OP relational_expression

	EQ_OP  shift 217
	NE_OP  shift 218
	.  reduce 48


state 289
	expression : expression ',' assignment_expression .  (73)

	.  reduce 73


state 290
	inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression .  (52)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 226
	.  reduce 52


state 291
	conditional_expression : logical_or_expression '?' expression . ':' conditional_expression
	expression : expression . ',' assignment_expression

	','  shift 220
	':'  shift 322


state 292
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (56)

	AND_OP  shift 225
	.  reduce 56


state 293
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (54)
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression

	'|'  shift 222
	.  reduce 54


state 294
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : exclusive_or_expression '^' and_expression .  (50)

	'&'  shift 219
	.  reduce 50


state 295
	compound_statement : '{' declaration_list statement_list '}' .  (185)

	.  reduce 185


state 296
	parameter_type_list : parameter_list ',' ELLIPSIS .  (146)

	.  reduce 146


state 297
	parameter_list : parameter_list ',' parameter_declaration .  (148)

	.  reduce 148


state 298
	direct_abstract_declarator : '(' ')' .  (164)

	.  reduce 164


state 299
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 323


state 300
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 324


state 301
	direct_abstract_declarator : '[' ']' .  (160)

	.  reduce 160


state 302
	direct_abstract_declarator : '[' constant_expression . ']'

	']'  shift 325


state 303
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	abstract_declarator : pointer direct_abstract_declarator .  (158)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'

	'('  shift 304
	'['  shift 305
	.  reduce 158


state 304
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

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

	parameter_type_list  goto 327
	struct_or_union  goto 24
	parameter_list  goto 139
	storage_class_specifier  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 140
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	type_qualifier  goto 31
	parameter_declaration  goto 141


state 305
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_expression ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	']'  shift 328
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	constant_expression  goto 329
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 147


state 306
	identifier_list : identifier_list ',' IDENTIFIER .  (153)

	.  reduce 153


state 307
	struct_declarator_list : struct_declarator_list ',' struct_declarator .  (117)

	.  reduce 117


state 308
	struct_declarator : declarator ':' constant_expression .  (120)

	.  reduce 120


state 309
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'{'  shift 162
	'}'  shift 330
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 163
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	initializer  goto 331


state 310
	initializer : '{' initializer_list '}' .  (169)

	.  reduce 169


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
	selection_statement : IF '(' expression ')' . statement ELSE statement
	selection_statement : IF '(' expression ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 332
	compound_statement  goto 130
	iteration_statement  goto 132


state 315
	selection_statement : SWITCH '(' expression ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 333
	compound_statement  goto 130
	iteration_statement  goto 132


state 316
	iteration_statement : WHILE '(' expression ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 334
	compound_statement  goto 130
	iteration_statement  goto 132


state 317
	iteration_statement : DO statement WHILE '(' . expression ')' ';'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 335
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 318
	iteration_statement : FOR '(' expression_statement expression_statement . ')' statement
	iteration_statement : FOR '(' expression_statement expression_statement . expression ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	')'  shift 336
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 337
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 319
	postfix_expression : postfix_expression '(' argument_expression_list ')' .  (8)

	.  reduce 8


state 320
	argument_expression_list : argument_expression_list ',' . assignment_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 338
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123


state 321
	postfix_expression : postfix_expression '[' expression ']' .  (6)

	.  reduce 6


state 322
	conditional_expression : logical_or_expression '?' expression ':' . conditional_expression

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	IDENTIFIER  shift 144
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 145
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 339


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

	')'  shift 340


state 328
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (162)

	.  reduce 162


state 329
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression . ']'

	']'  shift 341


state 330
	initializer : '{' initializer_list ',' '}' .  (170)

	.  reduce 170


state 331
	initializer_list : initializer_list ',' initializer .  (172)

	.  reduce 172


332: shift-reduce conflict (shift 342, reduce 192) on ELSE
state 332
	selection_statement : IF '(' expression ')' statement . ELSE statement
	selection_statement : IF '(' expression ')' statement .  (192)

	ELSE  shift 342
	.  reduce 192


state 333
	selection_statement : SWITCH '(' expression ')' statement .  (194)

	.  reduce 194


state 334
	iteration_statement : WHILE '(' expression ')' statement .  (195)

	.  reduce 195


state 335
	expression : expression . ',' assignment_expression
	iteration_statement : DO statement WHILE '(' expression . ')' ';'

	')'  shift 343
	','  shift 220


state 336
	iteration_statement : FOR '(' expression_statement expression_statement ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 344
	compound_statement  goto 130
	iteration_statement  goto 132


state 337
	expression : expression . ',' assignment_expression
	iteration_statement : FOR '(' expression_statement expression_statement expression . ')' statement

	')'  shift 345
	','  shift 220


state 338
	argument_expression_list : argument_expression_list ',' assignment_expression .  (14)

	.  reduce 14


state 339
	conditional_expression : logical_or_expression '?' expression ':' conditional_expression .  (58)

	.  reduce 58


state 340
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (167)

	.  reduce 167


state 341
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']' .  (163)

	.  reduce 163


state 342
	selection_statement : IF '(' expression ')' statement ELSE . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 346
	compound_statement  goto 130
	iteration_statement  goto 132


state 343
	iteration_statement : DO statement WHILE '(' expression ')' . ';'

	';'  shift 347


state 344
	iteration_statement : FOR '(' expression_statement expression_statement ')' statement .  (197)

	.  reduce 197


state 345
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 53
	'~'  shift 88
	IDENTIFIER  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	unary_operator  goto 106
	cast_expression  goto 107
	multiplicative_expression  goto 108
	postfix_expression  goto 109
	primary_expression  goto 110
	unary_expression  goto 111
	additive_expression  goto 112
	shift_expression  goto 113
	relational_expression  goto 114
	equality_expression  goto 115
	and_expression  goto 116
	assignment_expression  goto 117
	expression  goto 118
	inclusive_or_expression  goto 119
	logical_or_expression  goto 120
	logical_and_expression  goto 121
	exclusive_or_expression  goto 122
	conditional_expression  goto 123
	labeled_statement  goto 124
	selection_statement  goto 126
	jump_statement  goto 127
	expression_statement  goto 128
	statement  goto 348
	compound_statement  goto 130
	iteration_statement  goto 132


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

State 332 contains 1 shift-reduce conflict(s)


84 token(s), 64 nonterminal(s)
212 grammar rule(s), 349 state(s)


##############################################################################
# End of File
##############################################################################
