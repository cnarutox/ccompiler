#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 50 of your 30 day trial period.
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
# Date: 11/28/18
# Time: 20:36:14
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : translation_unit $end

    1  stmt : expr ';' expr
    2       | stmt ';' expr

    3  expr : NUMBER '+' NUMBER
    4       | expr '+' NUMBER

    5  primary_expression : IDENTIFIER
    6                     | CONSTANT
    7                     | STRING_LITERAL
    8                     | '(' expression ')'

    9  postfix_expression : primary_expression
   10                     | postfix_expression '[' expression ']'
   11                     | postfix_expression '(' ')'
   12                     | postfix_expression '(' argument_expression_list ')'
   13                     | postfix_expression '.' IDENTIFIER
   14                     | postfix_expression PTR_OP IDENTIFIER
   15                     | postfix_expression INC_OP
   16                     | postfix_expression DEC_OP

   17  argument_expression_list : assignment_expression
   18                           | argument_expression_list ',' assignment_expression

   19  unary_expression : postfix_expression
   20                   | INC_OP unary_expression
   21                   | DEC_OP unary_expression
   22                   | unary_operator cast_expression
   23                   | SIZEOF unary_expression
   24                   | SIZEOF '(' type_name ')'

   25  unary_operator : '&'
   26                 | '*'
   27                 | '+'
   28                 | '-'
   29                 | '~'
   30                 | '!'

   31  cast_expression : unary_expression
   32                  | '(' type_name ')' cast_expression

   33  multiplicative_expression : cast_expression
   34                            | multiplicative_expression '*' cast_expression
   35                            | multiplicative_expression '/' cast_expression
   36                            | multiplicative_expression '%' cast_expression

   37  additive_expression : multiplicative_expression
   38                      | additive_expression '+' multiplicative_expression
   39                      | additive_expression '-' multiplicative_expression

   40  shift_expression : additive_expression
   41                   | shift_expression LEFT_OP additive_expression
   42                   | shift_expression RIGHT_OP additive_expression

   43  relational_expression : shift_expression
   44                        | relational_expression '<' shift_expression
   45                        | relational_expression '>' shift_expression
   46                        | relational_expression LE_OP shift_expression
   47                        | relational_expression GE_OP shift_expression

   48  equality_expression : relational_expression
   49                      | equality_expression EQ_OP relational_expression
   50                      | equality_expression NE_OP relational_expression

   51  and_expression : equality_expression
   52                 | and_expression '&' equality_expression

   53  exclusive_or_expression : and_expression
   54                          | exclusive_or_expression '^' and_expression

   55  inclusive_or_expression : exclusive_or_expression
   56                          | inclusive_or_expression '|' exclusive_or_expression

   57  logical_and_expression : inclusive_or_expression
   58                         | logical_and_expression AND_OP inclusive_or_expression

   59  logical_or_expression : logical_and_expression
   60                        | logical_or_expression OR_OP logical_and_expression

   61  conditional_expression : logical_or_expression
   62                         | logical_or_expression '?' expression ':' conditional_expression

   63  assignment_expression : conditional_expression
   64                        | unary_expression assignment_operator assignment_expression

   65  assignment_operator : '='
   66                      | MUL_ASSIGN
   67                      | DIV_ASSIGN
   68                      | MOD_ASSIGN
   69                      | ADD_ASSIGN
   70                      | SUB_ASSIGN
   71                      | LEFT_ASSIGN
   72                      | RIGHT_ASSIGN
   73                      | AND_ASSIGN
   74                      | XOR_ASSIGN
   75                      | OR_ASSIGN

   76  expression : assignment_expression
   77             | expression ',' assignment_expression

   78  constant_expression : conditional_expression

   79  declaration : declaration_specifiers ';'
   80              | declaration_specifiers init_declarator_list ';'

   81  declaration_specifiers : storage_class_specifier
   82                         | storage_class_specifier declaration_specifiers
   83                         | type_specifier
   84                         | type_specifier declaration_specifiers
   85                         | type_qualifier
   86                         | type_qualifier declaration_specifiers

   87  init_declarator_list : init_declarator
   88                       | init_declarator_list ',' init_declarator

   89  init_declarator : declarator
   90                  | declarator '=' initializer

   91  storage_class_specifier : TYPEDEF
   92                          | EXTERN
   93                          | STATIC
   94                          | AUTO
   95                          | REGISTER

   96  type_specifier : VOID
   97                 | CHAR
   98                 | SHORT
   99                 | INT
  100                 | LONG
  101                 | FLOAT
  102                 | DOUBLE
  103                 | SIGNED
  104                 | UNSIGNED
  105                 | struct_or_union_specifier
  106                 | enum_specifier
  107                 | TYPE_NAME

  108  struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}'
  109                            | struct_or_union '{' struct_declaration_list '}'
  110                            | struct_or_union IDENTIFIER

  111  struct_or_union : STRUCT
  112                  | UNION

  113  struct_declaration_list : struct_declaration
  114                          | struct_declaration_list struct_declaration

  115  struct_declaration : specifier_qualifier_list struct_declarator_list ';'

  116  specifier_qualifier_list : type_specifier specifier_qualifier_list
  117                           | type_specifier
  118                           | type_qualifier specifier_qualifier_list
  119                           | type_qualifier

  120  struct_declarator_list : struct_declarator
  121                         | struct_declarator_list ',' struct_declarator

  122  struct_declarator : declarator
  123                    | ':' constant_expression
  124                    | declarator ':' constant_expression

  125  enum_specifier : ENUM '{' enumerator_list '}'
  126                 | ENUM IDENTIFIER '{' enumerator_list '}'
  127                 | ENUM IDENTIFIER

  128  enumerator_list : enumerator
  129                  | enumerator_list ',' enumerator

  130  enumerator : IDENTIFIER
  131             | IDENTIFIER '=' constant_expression

  132  type_qualifier : CONST
  133                 | VOLATILE

  134  declarator : pointer direct_declarator
  135             | direct_declarator

  136  direct_declarator : IDENTIFIER
  137                    | '(' declarator ')'
  138                    | direct_declarator '[' constant_expression ']'
  139                    | direct_declarator '[' ']'
  140                    | direct_declarator '(' parameter_type_list ')'
  141                    | direct_declarator '(' identifier_list ')'
  142                    | direct_declarator '(' ')'

  143  pointer : '*'
  144          | '*' type_qualifier_list
  145          | '*' pointer
  146          | '*' type_qualifier_list pointer

  147  type_qualifier_list : type_qualifier
  148                      | type_qualifier_list type_qualifier

  149  parameter_type_list : parameter_list
  150                      | parameter_list ',' ELLIPSIS

  151  parameter_list : parameter_declaration
  152                 | parameter_list ',' parameter_declaration

  153  parameter_declaration : declaration_specifiers declarator
  154                        | declaration_specifiers abstract_declarator
  155                        | declaration_specifiers

  156  identifier_list : IDENTIFIER
  157                  | identifier_list ',' IDENTIFIER

  158  type_name : specifier_qualifier_list
  159            | specifier_qualifier_list abstract_declarator

  160  abstract_declarator : pointer
  161                      | direct_abstract_declarator
  162                      | pointer direct_abstract_declarator

  163  direct_abstract_declarator : '(' abstract_declarator ')'
  164                             | '[' ']'
  165                             | '[' constant_expression ']'
  166                             | direct_abstract_declarator '[' ']'
  167                             | direct_abstract_declarator '[' constant_expression ']'
  168                             | '(' ')'
  169                             | '(' parameter_type_list ')'
  170                             | direct_abstract_declarator '(' ')'
  171                             | direct_abstract_declarator '(' parameter_type_list ')'

  172  initializer : assignment_expression
  173              | '{' initializer_list '}'
  174              | '{' initializer_list ',' '}'

  175  initializer_list : initializer
  176                   | initializer_list ',' initializer

  177  statement : labeled_statement
  178            | compound_statement
  179            | expression_statement
  180            | selection_statement
  181            | iteration_statement
  182            | jump_statement

  183  labeled_statement : IDENTIFIER ':' statement
  184                    | CASE constant_expression ':' statement
  185                    | DEFAULT ':' statement

  186  compound_statement : '{' '}'
  187                     | '{' statement_list '}'
  188                     | '{' declaration_list '}'
  189                     | '{' declaration_list statement_list '}'

  190  declaration_list : declaration
  191                   | declaration_list declaration

  192  statement_list : statement
  193                 | statement_list statement

  194  expression_statement : ';'
  195                       | expression ';'

  196  selection_statement : IF '(' expression ')' statement
  197                      | IF '(' expression ')' statement ELSE statement
  198                      | SWITCH '(' expression ')' statement

  199  iteration_statement : WHILE '(' expression ')' statement
  200                      | DO statement WHILE '(' expression ')' ';'
  201                      | FOR '(' expression_statement expression_statement ')' statement
  202                      | FOR '(' expression_statement expression_statement expression ')' statement

  203  jump_statement : GOTO IDENTIFIER ';'
  204                 | CONTINUE ';'
  205                 | BREAK ';'
  206                 | RETURN ';'
  207                 | RETURN expression ';'

  208  translation_unit : external_declaration
  209                   | translation_unit external_declaration

  210  external_declaration : function_definition
  211                       | declaration

  212  function_definition : declaration_specifiers declarator declaration_list compound_statement
  213                      | declaration_specifiers declarator compound_statement
  214                      | declarator declaration_list compound_statement
  215                      | declarator compound_statement


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
	declaration  goto 25
	declarator  goto 26
	declaration_specifiers  goto 27
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	external_declaration  goto 34
	direct_declarator  goto 35
	pointer  goto 36
	function_definition  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	declarator  goto 38
	direct_declarator  goto 35
	pointer  goto 36


state 2
	pointer : '*' .  (143)
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 143

	type_qualifier  goto 39
	pointer  goto 40
	type_qualifier_list  goto 41


state 3
	direct_declarator : IDENTIFIER .  (136)

	.  reduce 136


state 4
	type_specifier : TYPE_NAME .  (107)

	.  reduce 107


state 5
	storage_class_specifier : TYPEDEF .  (91)

	.  reduce 91


state 6
	storage_class_specifier : EXTERN .  (92)

	.  reduce 92


state 7
	storage_class_specifier : STATIC .  (93)

	.  reduce 93


state 8
	storage_class_specifier : AUTO .  (94)

	.  reduce 94


state 9
	storage_class_specifier : REGISTER .  (95)

	.  reduce 95


state 10
	type_specifier : CHAR .  (97)

	.  reduce 97


state 11
	type_specifier : SHORT .  (98)

	.  reduce 98


state 12
	type_specifier : INT .  (99)

	.  reduce 99


state 13
	type_specifier : LONG .  (100)

	.  reduce 100


state 14
	type_specifier : SIGNED .  (103)

	.  reduce 103


state 15
	type_specifier : UNSIGNED .  (104)

	.  reduce 104


state 16
	type_specifier : FLOAT .  (101)

	.  reduce 101


state 17
	type_specifier : DOUBLE .  (102)

	.  reduce 102


state 18
	type_qualifier : CONST .  (132)

	.  reduce 132


state 19
	type_qualifier : VOLATILE .  (133)

	.  reduce 133


state 20
	type_specifier : VOID .  (96)

	.  reduce 96


state 21
	struct_or_union : STRUCT .  (111)

	.  reduce 111


state 22
	struct_or_union : UNION .  (112)

	.  reduce 112


state 23
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . IDENTIFIER '{' enumerator_list '}'
	enum_specifier : ENUM . IDENTIFIER

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

	declaration  goto 25
	declarator  goto 26
	declaration_specifiers  goto 27
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	external_declaration  goto 44
	direct_declarator  goto 35
	pointer  goto 36
	function_definition  goto 37


state 25
	external_declaration : declaration .  (211)

	.  reduce 211


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

	declaration  goto 46
	declaration_specifiers  goto 47
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	compound_statement  goto 48
	declaration_list  goto 49


state 27
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 50
	IDENTIFIER  shift 3

	declarator  goto 51
	init_declarator_list  goto 52
	init_declarator  goto 53
	direct_declarator  goto 35
	pointer  goto 36


state 28
	declaration_specifiers : type_specifier .  (83)
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
	.  reduce 83

	declaration_specifiers  goto 54
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33


state 29
	declaration_specifiers : storage_class_specifier . declaration_specifiers
	declaration_specifiers : storage_class_specifier .  (81)

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

	declaration_specifiers  goto 55
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33


state 30
	declaration_specifiers : type_qualifier .  (85)
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
	.  reduce 85

	declaration_specifiers  goto 56
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33


state 31
	type_specifier : struct_or_union_specifier .  (105)

	.  reduce 105


state 32
	type_specifier : enum_specifier .  (106)

	.  reduce 106


state 33
	struct_or_union_specifier : struct_or_union . IDENTIFIER
	struct_or_union_specifier : struct_or_union . IDENTIFIER '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . '{' struct_declaration_list '}'

	'{'  shift 57
	IDENTIFIER  shift 58


state 34
	translation_unit : external_declaration .  (208)

	.  reduce 208


state 35
	declarator : direct_declarator .  (135)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'

	'('  shift 59
	'['  shift 60
	.  reduce 135


state 36
	declarator : pointer . direct_declarator

	'('  shift 1
	IDENTIFIER  shift 3

	direct_declarator  goto 61


state 37
	external_declaration : function_definition .  (210)

	.  reduce 210


state 38
	direct_declarator : '(' declarator . ')'

	')'  shift 62


state 39
	type_qualifier_list : type_qualifier .  (147)

	.  reduce 147


state 40
	pointer : '*' pointer .  (145)

	.  reduce 145


state 41
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (144)
	type_qualifier_list : type_qualifier_list . type_qualifier

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 144

	type_qualifier  goto 63
	pointer  goto 64


state 42
	enum_specifier : ENUM '{' . enumerator_list '}'

	IDENTIFIER  shift 65

	enumerator  goto 66
	enumerator_list  goto 67


state 43
	enum_specifier : ENUM IDENTIFIER . '{' enumerator_list '}'
	enum_specifier : ENUM IDENTIFIER .  (127)

	'{'  shift 68
	.  reduce 127


state 44
	translation_unit : translation_unit external_declaration .  (209)

	.  reduce 209


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	declaration  goto 46
	logical_or_expression  goto 109
	declaration_specifiers  goto 47
	inclusive_or_expression  goto 110
	type_specifier  goto 28
	conditional_expression  goto 111
	logical_and_expression  goto 112
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 115
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	declaration_list  goto 119
	expression_statement  goto 120
	statement_list  goto 121


state 46
	declaration_list : declaration .  (190)

	.  reduce 190


state 47
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 50
	IDENTIFIER  shift 3

	declarator  goto 122
	init_declarator_list  goto 52
	init_declarator  goto 53
	direct_declarator  goto 35
	pointer  goto 36


state 48
	function_definition : declarator compound_statement .  (215)

	.  reduce 215


state 49
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

	declaration  goto 123
	declaration_specifiers  goto 47
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	compound_statement  goto 124


state 50
	declaration : declaration_specifiers ';' .  (79)

	.  reduce 79


state 51
	init_declarator : declarator .  (89)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 125
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
	.  reduce 89

	declaration  goto 46
	declaration_specifiers  goto 47
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	compound_statement  goto 126
	declaration_list  goto 127


state 52
	init_declarator_list : init_declarator_list . ',' init_declarator
	declaration : declaration_specifiers init_declarator_list . ';'

	','  shift 128
	';'  shift 129


state 53
	init_declarator_list : init_declarator .  (87)

	.  reduce 87


state 54
	declaration_specifiers : type_specifier declaration_specifiers .  (84)

	.  reduce 84


state 55
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (82)

	.  reduce 82


state 56
	declaration_specifiers : type_qualifier declaration_specifiers .  (86)

	.  reduce 86


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

	type_specifier  goto 130
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	struct_declaration  goto 132
	enum_specifier  goto 32
	specifier_qualifier_list  goto 133
	struct_or_union  goto 33
	struct_declaration_list  goto 134


state 58
	struct_or_union_specifier : struct_or_union IDENTIFIER .  (110)
	struct_or_union_specifier : struct_or_union IDENTIFIER . '{' struct_declaration_list '}'

	'{'  shift 135
	.  reduce 110


state 59
	direct_declarator : direct_declarator '(' . ')'
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'

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

	declaration_specifiers  goto 138
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	parameter_declaration  goto 139
	parameter_list  goto 140
	parameter_type_list  goto 141
	identifier_list  goto 142


state 60
	direct_declarator : direct_declarator '[' . constant_expression ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	']'  shift 143
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	constant_expression  goto 146
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 147
	logical_and_expression  goto 112


state 61
	declarator : pointer direct_declarator .  (134)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'

	'('  shift 59
	'['  shift 60
	.  reduce 134


state 62
	direct_declarator : '(' declarator ')' .  (137)

	.  reduce 137


state 63
	type_qualifier_list : type_qualifier_list type_qualifier .  (148)

	.  reduce 148


state 64
	pointer : '*' type_qualifier_list pointer .  (146)

	.  reduce 146


state 65
	enumerator : IDENTIFIER .  (130)
	enumerator : IDENTIFIER . '=' constant_expression

	'='  shift 148
	.  reduce 130


state 66
	enumerator_list : enumerator .  (128)

	.  reduce 128


state 67
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 149
	'}'  shift 150


state 68
	enum_specifier : ENUM IDENTIFIER '{' . enumerator_list '}'

	IDENTIFIER  shift 65

	enumerator  goto 66
	enumerator_list  goto 151


state 69
	unary_operator : '!' .  (30)

	.  reduce 30


state 70
	unary_operator : '&' .  (25)

	.  reduce 25


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
	IDENTIFIER  shift 144
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

	additive_expression  goto 95
	type_name  goto 152
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 153
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	type_specifier  goto 130
	conditional_expression  goto 111
	logical_and_expression  goto 112
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	specifier_qualifier_list  goto 154
	struct_or_union  goto 33


state 72
	unary_operator : '*' .  (26)

	.  reduce 26


state 73
	unary_operator : '+' .  (27)

	.  reduce 27


state 74
	unary_operator : '-' .  (28)

	.  reduce 28


state 75
	expression_statement : ';' .  (194)

	.  reduce 194


state 76
	compound_statement : '{' '}' .  (186)

	.  reduce 186


state 77
	unary_operator : '~' .  (29)

	.  reduce 29


state 78
	primary_expression : IDENTIFIER .  (5)
	labeled_statement : IDENTIFIER . ':' statement

	':'  shift 155
	.  reduce 5


state 79
	primary_expression : CONSTANT .  (6)

	.  reduce 6


state 80
	primary_expression : STRING_LITERAL .  (7)

	.  reduce 7


state 81
	unary_expression : SIZEOF . '(' type_name ')'
	unary_expression : SIZEOF . unary_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 156
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 157
	unary_operator  goto 97
	primary_expression  goto 106
	postfix_expression  goto 107


state 82
	unary_expression : INC_OP . unary_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 158
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 159
	unary_operator  goto 97
	primary_expression  goto 106
	postfix_expression  goto 107


state 83
	unary_expression : DEC_OP . unary_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 158
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 160
	unary_operator  goto 97
	primary_expression  goto 106
	postfix_expression  goto 107


state 84
	labeled_statement : CASE . constant_expression ':' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	constant_expression  goto 161
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 147
	logical_and_expression  goto 112


state 85
	labeled_statement : DEFAULT . ':' statement

	':'  shift 162


state 86
	selection_statement : IF . '(' expression ')' statement
	selection_statement : IF . '(' expression ')' statement ELSE statement

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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 166
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


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
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 172
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 95
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : additive_expression .  (40)
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 173
	'-'  shift 174
	.  reduce 40


state 96
	cast_expression : unary_expression .  (31)
	assignment_expression : unary_expression . assignment_operator assignment_expression

	'='  shift 175
	MUL_ASSIGN  shift 176
	DIV_ASSIGN  shift 177
	MOD_ASSIGN  shift 178
	ADD_ASSIGN  shift 179
	SUB_ASSIGN  shift 180
	LEFT_ASSIGN  shift 181
	RIGHT_ASSIGN  shift 182
	AND_ASSIGN  shift 183
	XOR_ASSIGN  shift 184
	OR_ASSIGN  shift 185
	.  reduce 31

	assignment_operator  goto 186


state 97
	unary_expression : unary_operator . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 145
	unary_operator  goto 97
	cast_expression  goto 187
	primary_expression  goto 106
	postfix_expression  goto 107


state 98
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : multiplicative_expression .  (37)

	'%'  shift 188
	'*'  shift 189
	'/'  shift 190
	.  reduce 37


state 99
	equality_expression : equality_expression . NE_OP relational_expression
	equality_expression : equality_expression . EQ_OP relational_expression
	and_expression : equality_expression .  (51)

	EQ_OP  shift 191
	NE_OP  shift 192
	.  reduce 51


state 100
	exclusive_or_expression : exclusive_or_expression . '^' and_expression
	inclusive_or_expression : exclusive_or_expression .  (55)

	'^'  shift 193
	.  reduce 55


state 101
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : and_expression .  (53)

	'&'  shift 194
	.  reduce 53


state 102
	relational_expression : relational_expression . GE_OP shift_expression
	equality_expression : relational_expression .  (48)
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression

	'<'  shift 195
	'>'  shift 196
	LE_OP  shift 197
	GE_OP  shift 198
	.  reduce 48


state 103
	expression : assignment_expression .  (76)

	.  reduce 76


state 104
	multiplicative_expression : cast_expression .  (33)

	.  reduce 33


state 105
	relational_expression : shift_expression .  (43)
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 199
	RIGHT_OP  shift 200
	.  reduce 43


state 106
	postfix_expression : primary_expression .  (9)

	.  reduce 9


state 107
	postfix_expression : postfix_expression . '[' expression ']'
	postfix_expression : postfix_expression . '(' ')'
	postfix_expression : postfix_expression . '(' argument_expression_list ')'
	postfix_expression : postfix_expression . '.' IDENTIFIER
	postfix_expression : postfix_expression . PTR_OP IDENTIFIER
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (19)

	'('  shift 201
	'.'  shift 202
	'['  shift 203
	PTR_OP  shift 204
	INC_OP  shift 205
	DEC_OP  shift 206
	.  reduce 19


state 108
	expression : expression . ',' assignment_expression
	expression_statement : expression . ';'

	','  shift 207
	';'  shift 208


state 109
	conditional_expression : logical_or_expression . '?' expression ':' conditional_expression
	conditional_expression : logical_or_expression .  (61)
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression

	'?'  shift 209
	OR_OP  shift 210
	.  reduce 61


state 110
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression
	logical_and_expression : inclusive_or_expression .  (57)

	'|'  shift 211
	.  reduce 57


state 111
	assignment_expression : conditional_expression .  (63)

	.  reduce 63


state 112
	logical_or_expression : logical_and_expression .  (59)
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression

	AND_OP  shift 212
	.  reduce 59


state 113
	statement : compound_statement .  (178)

	.  reduce 178


state 114
	statement : iteration_statement .  (181)

	.  reduce 181


state 115
	statement_list : statement .  (192)

	.  reduce 192


state 116
	statement : selection_statement .  (180)

	.  reduce 180


state 117
	statement : jump_statement .  (182)

	.  reduce 182


state 118
	statement : labeled_statement .  (177)

	.  reduce 177


state 119
	compound_statement : '{' declaration_list . statement_list '}'
	declaration_list : declaration_list . declaration
	compound_statement : '{' declaration_list . '}'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	';'  shift 75
	'{'  shift 45
	'}'  shift 213
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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	declaration  goto 123
	logical_or_expression  goto 109
	declaration_specifiers  goto 47
	inclusive_or_expression  goto 110
	type_specifier  goto 28
	conditional_expression  goto 111
	logical_and_expression  goto 112
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 115
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120
	statement_list  goto 214


state 120
	statement : expression_statement .  (179)

	.  reduce 179


state 121
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
	'}'  shift 215
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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 216
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 122
	init_declarator : declarator .  (89)
	init_declarator : declarator . '=' initializer

	'='  shift 125
	.  reduce 89


state 123
	declaration_list : declaration_list declaration .  (191)

	.  reduce 191


state 124
	function_definition : declarator declaration_list compound_statement .  (214)

	.  reduce 214


state 125
	init_declarator : declarator '=' . initializer

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'{'  shift 217
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 218
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	initializer  goto 219
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 126
	function_definition : declaration_specifiers declarator compound_statement .  (213)

	.  reduce 213


state 127
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

	declaration  goto 123
	declaration_specifiers  goto 47
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	compound_statement  goto 220


state 128
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	declarator  goto 122
	init_declarator  goto 221
	direct_declarator  goto 35
	pointer  goto 36


state 129
	declaration : declaration_specifiers init_declarator_list ';' .  (80)

	.  reduce 80


state 130
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	specifier_qualifier_list : type_specifier .  (117)

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
	.  reduce 117

	type_specifier  goto 130
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	specifier_qualifier_list  goto 222
	struct_or_union  goto 33


state 131
	specifier_qualifier_list : type_qualifier . specifier_qualifier_list
	specifier_qualifier_list : type_qualifier .  (119)

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
	.  reduce 119

	type_specifier  goto 130
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	specifier_qualifier_list  goto 223
	struct_or_union  goto 33


state 132
	struct_declaration_list : struct_declaration .  (113)

	.  reduce 113


state 133
	struct_declaration : specifier_qualifier_list . struct_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	':'  shift 224
	IDENTIFIER  shift 3

	declarator  goto 225
	struct_declarator_list  goto 226
	struct_declarator  goto 227
	direct_declarator  goto 35
	pointer  goto 36


state 134
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list . '}'

	'}'  shift 228
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

	type_specifier  goto 130
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	struct_declaration  goto 229
	enum_specifier  goto 32
	specifier_qualifier_list  goto 133
	struct_or_union  goto 33


state 135
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

	type_specifier  goto 130
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	struct_declaration  goto 132
	enum_specifier  goto 32
	specifier_qualifier_list  goto 133
	struct_or_union  goto 33
	struct_declaration_list  goto 230


state 136
	direct_declarator : direct_declarator '(' ')' .  (142)

	.  reduce 142


state 137
	identifier_list : IDENTIFIER .  (156)

	.  reduce 156


state 138
	parameter_declaration : declaration_specifiers .  (155)
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers . declarator

	'('  shift 231
	'*'  shift 2
	'['  shift 232
	IDENTIFIER  shift 3
	.  reduce 155

	declarator  goto 233
	direct_abstract_declarator  goto 234
	abstract_declarator  goto 235
	direct_declarator  goto 35
	pointer  goto 236


state 139
	parameter_list : parameter_declaration .  (151)

	.  reduce 151


state 140
	parameter_type_list : parameter_list .  (149)
	parameter_list : parameter_list . ',' parameter_declaration
	parameter_type_list : parameter_list . ',' ELLIPSIS

	','  shift 237
	.  reduce 149


state 141
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 238


state 142
	identifier_list : identifier_list . ',' IDENTIFIER
	direct_declarator : direct_declarator '(' identifier_list . ')'

	')'  shift 239
	','  shift 240


state 143
	direct_declarator : direct_declarator '[' ']' .  (139)

	.  reduce 139


state 144
	primary_expression : IDENTIFIER .  (5)

	.  reduce 5


state 145
	cast_expression : unary_expression .  (31)

	.  reduce 31


state 146
	direct_declarator : direct_declarator '[' constant_expression . ']'

	']'  shift 241


state 147
	constant_expression : conditional_expression .  (78)

	.  reduce 78


state 148
	enumerator : IDENTIFIER '=' . constant_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	constant_expression  goto 242
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 147
	logical_and_expression  goto 112


state 149
	enumerator_list : enumerator_list ',' . enumerator

	IDENTIFIER  shift 65

	enumerator  goto 243


state 150
	enum_specifier : ENUM '{' enumerator_list '}' .  (125)

	.  reduce 125


state 151
	enum_specifier : ENUM IDENTIFIER '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 149
	'}'  shift 244


state 152
	cast_expression : '(' type_name . ')' cast_expression

	')'  shift 245


state 153
	primary_expression : '(' expression . ')'
	expression : expression . ',' assignment_expression

	')'  shift 246
	','  shift 207


state 154
	type_name : specifier_qualifier_list . abstract_declarator
	type_name : specifier_qualifier_list .  (158)

	'('  shift 247
	'*'  shift 2
	'['  shift 232
	.  reduce 158

	direct_abstract_declarator  goto 234
	abstract_declarator  goto 248
	pointer  goto 249


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 250
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


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
	IDENTIFIER  shift 144
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

	additive_expression  goto 95
	type_name  goto 251
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 153
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	type_specifier  goto 130
	conditional_expression  goto 111
	logical_and_expression  goto 112
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	specifier_qualifier_list  goto 154
	struct_or_union  goto 33


state 157
	unary_expression : SIZEOF unary_expression .  (23)

	.  reduce 23


state 158
	primary_expression : '(' . expression ')'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 153
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 159
	unary_expression : INC_OP unary_expression .  (20)

	.  reduce 20


state 160
	unary_expression : DEC_OP unary_expression .  (21)

	.  reduce 21


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 253
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 163
	selection_statement : IF '(' . expression ')' statement
	selection_statement : IF '(' . expression ')' statement ELSE statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 254
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 164
	selection_statement : SWITCH '(' . expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 255
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 165
	iteration_statement : WHILE '(' . expression ')' statement

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 256
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


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
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	expression_statement  goto 258


state 168
	jump_statement : GOTO IDENTIFIER . ';'

	';'  shift 259


state 169
	jump_statement : CONTINUE ';' .  (204)

	.  reduce 204


state 170
	jump_statement : BREAK ';' .  (205)

	.  reduce 205


state 171
	jump_statement : RETURN ';' .  (206)

	.  reduce 206


state 172
	expression : expression . ',' assignment_expression
	jump_statement : RETURN expression . ';'

	','  shift 207
	';'  shift 260


state 173
	additive_expression : additive_expression '+' . multiplicative_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 261
	cast_expression  goto 104
	primary_expression  goto 106
	postfix_expression  goto 107


state 174
	additive_expression : additive_expression '-' . multiplicative_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 262
	cast_expression  goto 104
	primary_expression  goto 106
	postfix_expression  goto 107


state 175
	assignment_operator : '=' .  (65)

	.  reduce 65


state 176
	assignment_operator : MUL_ASSIGN .  (66)

	.  reduce 66


state 177
	assignment_operator : DIV_ASSIGN .  (67)

	.  reduce 67


state 178
	assignment_operator : MOD_ASSIGN .  (68)

	.  reduce 68


state 179
	assignment_operator : ADD_ASSIGN .  (69)

	.  reduce 69


state 180
	assignment_operator : SUB_ASSIGN .  (70)

	.  reduce 70


state 181
	assignment_operator : LEFT_ASSIGN .  (71)

	.  reduce 71


state 182
	assignment_operator : RIGHT_ASSIGN .  (72)

	.  reduce 72


state 183
	assignment_operator : AND_ASSIGN .  (73)

	.  reduce 73


state 184
	assignment_operator : XOR_ASSIGN .  (74)

	.  reduce 74


state 185
	assignment_operator : OR_ASSIGN .  (75)

	.  reduce 75


state 186
	assignment_expression : unary_expression assignment_operator . assignment_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 263
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 187
	unary_expression : unary_operator cast_expression .  (22)

	.  reduce 22


state 188
	multiplicative_expression : multiplicative_expression '%' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 145
	unary_operator  goto 97
	cast_expression  goto 264
	primary_expression  goto 106
	postfix_expression  goto 107


state 189
	multiplicative_expression : multiplicative_expression '*' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 145
	unary_operator  goto 97
	cast_expression  goto 265
	primary_expression  goto 106
	postfix_expression  goto 107


state 190
	multiplicative_expression : multiplicative_expression '/' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 145
	unary_operator  goto 97
	cast_expression  goto 266
	primary_expression  goto 106
	postfix_expression  goto 107


state 191
	equality_expression : equality_expression EQ_OP . relational_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	relational_expression  goto 267
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107


state 192
	equality_expression : equality_expression NE_OP . relational_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	relational_expression  goto 268
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107


state 193
	exclusive_or_expression : exclusive_or_expression '^' . and_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	and_expression  goto 269
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107


state 194
	and_expression : and_expression '&' . equality_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 270
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107


state 195
	relational_expression : relational_expression '<' . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	cast_expression  goto 104
	shift_expression  goto 271
	primary_expression  goto 106
	postfix_expression  goto 107


state 196
	relational_expression : relational_expression '>' . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	cast_expression  goto 104
	shift_expression  goto 272
	primary_expression  goto 106
	postfix_expression  goto 107


state 197
	relational_expression : relational_expression LE_OP . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	cast_expression  goto 104
	shift_expression  goto 273
	primary_expression  goto 106
	postfix_expression  goto 107


state 198
	relational_expression : relational_expression GE_OP . shift_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	cast_expression  goto 104
	shift_expression  goto 274
	primary_expression  goto 106
	postfix_expression  goto 107


state 199
	shift_expression : shift_expression LEFT_OP . additive_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 275
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	cast_expression  goto 104
	primary_expression  goto 106
	postfix_expression  goto 107


state 200
	shift_expression : shift_expression RIGHT_OP . additive_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 276
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	cast_expression  goto 104
	primary_expression  goto 106
	postfix_expression  goto 107


state 201
	postfix_expression : postfix_expression '(' . ')'
	postfix_expression : postfix_expression '(' . argument_expression_list ')'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	')'  shift 277
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 278
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	argument_expression_list  goto 279
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 202
	postfix_expression : postfix_expression '.' . IDENTIFIER

	IDENTIFIER  shift 280


state 203
	postfix_expression : postfix_expression '[' . expression ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 281
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 204
	postfix_expression : postfix_expression PTR_OP . IDENTIFIER

	IDENTIFIER  shift 282


state 205
	postfix_expression : postfix_expression INC_OP .  (15)

	.  reduce 15


state 206
	postfix_expression : postfix_expression DEC_OP .  (16)

	.  reduce 16


state 207
	expression : expression ',' . assignment_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 283
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 208
	expression_statement : expression ';' .  (195)

	.  reduce 195


state 209
	conditional_expression : logical_or_expression '?' . expression ':' conditional_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 284
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 210
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	inclusive_or_expression  goto 110
	logical_and_expression  goto 285


state 211
	inclusive_or_expression : inclusive_or_expression '|' . exclusive_or_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 286
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107


state 212
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	inclusive_or_expression  goto 287


state 213
	compound_statement : '{' declaration_list '}' .  (188)

	.  reduce 188


state 214
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
	'}'  shift 288
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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 216
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 215
	compound_statement : '{' statement_list '}' .  (187)

	.  reduce 187


state 216
	statement_list : statement_list statement .  (193)

	.  reduce 193


state 217
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'{'  shift 217
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 218
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	initializer  goto 289
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	initializer_list  goto 290


state 218
	initializer : assignment_expression .  (172)

	.  reduce 172


state 219
	init_declarator : declarator '=' initializer .  (90)

	.  reduce 90


state 220
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (212)

	.  reduce 212


state 221
	init_declarator_list : init_declarator_list ',' init_declarator .  (88)

	.  reduce 88


state 222
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (116)

	.  reduce 116


state 223
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (118)

	.  reduce 118


state 224
	struct_declarator : ':' . constant_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	constant_expression  goto 291
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 147
	logical_and_expression  goto 112


state 225
	struct_declarator : declarator . ':' constant_expression
	struct_declarator : declarator .  (122)

	':'  shift 292
	.  reduce 122


state 226
	struct_declarator_list : struct_declarator_list . ',' struct_declarator
	struct_declaration : specifier_qualifier_list struct_declarator_list . ';'

	','  shift 293
	';'  shift 294


state 227
	struct_declarator_list : struct_declarator .  (120)

	.  reduce 120


state 228
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}' .  (109)

	.  reduce 109


state 229
	struct_declaration_list : struct_declaration_list struct_declaration .  (114)

	.  reduce 114


state 230
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list . '}'
	struct_declaration_list : struct_declaration_list . struct_declaration

	'}'  shift 295
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

	type_specifier  goto 130
	type_qualifier  goto 131
	struct_or_union_specifier  goto 31
	struct_declaration  goto 229
	enum_specifier  goto 32
	specifier_qualifier_list  goto 133
	struct_or_union  goto 33


state 231
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 231
	')'  shift 296
	'*'  shift 2
	'['  shift 232
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

	declarator  goto 38
	declaration_specifiers  goto 138
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	direct_abstract_declarator  goto 234
	parameter_declaration  goto 139
	abstract_declarator  goto 297
	parameter_list  goto 140
	direct_declarator  goto 35
	pointer  goto 236
	parameter_type_list  goto 298


state 232
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_expression ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	']'  shift 299
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	constant_expression  goto 300
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 147
	logical_and_expression  goto 112


state 233
	parameter_declaration : declaration_specifiers declarator .  (153)

	.  reduce 153


state 234
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	abstract_declarator : direct_abstract_declarator .  (161)
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 301
	'['  shift 302
	.  reduce 161


state 235
	parameter_declaration : declaration_specifiers abstract_declarator .  (154)

	.  reduce 154


state 236
	declarator : pointer . direct_declarator
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (160)

	'('  shift 231
	'['  shift 232
	IDENTIFIER  shift 3
	.  reduce 160

	direct_abstract_declarator  goto 303
	direct_declarator  goto 61


state 237
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
	ELLIPSIS  shift 304

	declaration_specifiers  goto 138
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	parameter_declaration  goto 305


state 238
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (140)

	.  reduce 140


state 239
	direct_declarator : direct_declarator '(' identifier_list ')' .  (141)

	.  reduce 141


state 240
	identifier_list : identifier_list ',' . IDENTIFIER

	IDENTIFIER  shift 306


state 241
	direct_declarator : direct_declarator '[' constant_expression ']' .  (138)

	.  reduce 138


state 242
	enumerator : IDENTIFIER '=' constant_expression .  (131)

	.  reduce 131


state 243
	enumerator_list : enumerator_list ',' enumerator .  (129)

	.  reduce 129


state 244
	enum_specifier : ENUM IDENTIFIER '{' enumerator_list '}' .  (126)

	.  reduce 126


state 245
	cast_expression : '(' type_name ')' . cast_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	unary_expression  goto 145
	unary_operator  goto 97
	cast_expression  goto 307
	primary_expression  goto 106
	postfix_expression  goto 107


state 246
	primary_expression : '(' expression ')' .  (8)

	.  reduce 8


state 247
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 247
	')'  shift 296
	'*'  shift 2
	'['  shift 232
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

	declaration_specifiers  goto 138
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	direct_abstract_declarator  goto 234
	parameter_declaration  goto 139
	abstract_declarator  goto 297
	parameter_list  goto 140
	pointer  goto 249
	parameter_type_list  goto 298


state 248
	type_name : specifier_qualifier_list abstract_declarator .  (159)

	.  reduce 159


state 249
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (160)

	'('  shift 247
	'['  shift 232
	.  reduce 160

	direct_abstract_declarator  goto 303


state 250
	labeled_statement : IDENTIFIER ':' statement .  (183)

	.  reduce 183


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 309
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 253
	labeled_statement : DEFAULT ':' statement .  (185)

	.  reduce 185


state 254
	expression : expression . ',' assignment_expression
	selection_statement : IF '(' expression . ')' statement
	selection_statement : IF '(' expression . ')' statement ELSE statement

	')'  shift 310
	','  shift 207


state 255
	expression : expression . ',' assignment_expression
	selection_statement : SWITCH '(' expression . ')' statement

	')'  shift 311
	','  shift 207


state 256
	expression : expression . ',' assignment_expression
	iteration_statement : WHILE '(' expression . ')' statement

	')'  shift 312
	','  shift 207


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
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	expression_statement  goto 314


state 259
	jump_statement : GOTO IDENTIFIER ';' .  (203)

	.  reduce 203


state 260
	jump_statement : RETURN expression ';' .  (207)

	.  reduce 207


state 261
	additive_expression : additive_expression '+' multiplicative_expression .  (38)
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression

	'%'  shift 188
	'*'  shift 189
	'/'  shift 190
	.  reduce 38


state 262
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : additive_expression '-' multiplicative_expression .  (39)

	'%'  shift 188
	'*'  shift 189
	'/'  shift 190
	.  reduce 39


state 263
	assignment_expression : unary_expression assignment_operator assignment_expression .  (64)

	.  reduce 64


state 264
	multiplicative_expression : multiplicative_expression '%' cast_expression .  (36)

	.  reduce 36


state 265
	multiplicative_expression : multiplicative_expression '*' cast_expression .  (34)

	.  reduce 34


state 266
	multiplicative_expression : multiplicative_expression '/' cast_expression .  (35)

	.  reduce 35


state 267
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression
	equality_expression : equality_expression EQ_OP relational_expression .  (49)
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression

	'<'  shift 195
	'>'  shift 196
	LE_OP  shift 197
	GE_OP  shift 198
	.  reduce 49


state 268
	equality_expression : equality_expression NE_OP relational_expression .  (50)
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . '<' shift_expression
	relational_expression : relational_expression . LE_OP shift_expression

	'<'  shift 195
	'>'  shift 196
	LE_OP  shift 197
	GE_OP  shift 198
	.  reduce 50


state 269
	and_expression : and_expression . '&' equality_expression
	exclusive_or_expression : exclusive_or_expression '^' and_expression .  (54)

	'&'  shift 194
	.  reduce 54


state 270
	and_expression : and_expression '&' equality_expression .  (52)
	equality_expression : equality_expression . NE_OP relational_expression
	equality_expression : equality_expression . EQ_OP relational_expression

	EQ_OP  shift 191
	NE_OP  shift 192
	.  reduce 52


state 271
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '<' shift_expression .  (44)

	LEFT_OP  shift 199
	RIGHT_OP  shift 200
	.  reduce 44


state 272
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '>' shift_expression .  (45)

	LEFT_OP  shift 199
	RIGHT_OP  shift 200
	.  reduce 45


state 273
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression LE_OP shift_expression .  (46)

	LEFT_OP  shift 199
	RIGHT_OP  shift 200
	.  reduce 46


state 274
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (47)
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 199
	RIGHT_OP  shift 200
	.  reduce 47


state 275
	additive_expression : additive_expression . '+' multiplicative_expression
	shift_expression : shift_expression LEFT_OP additive_expression .  (41)
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 173
	'-'  shift 174
	.  reduce 41


state 276
	shift_expression : shift_expression RIGHT_OP additive_expression .  (42)
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression

	'+'  shift 173
	'-'  shift 174
	.  reduce 42


state 277
	postfix_expression : postfix_expression '(' ')' .  (11)

	.  reduce 11


state 278
	argument_expression_list : assignment_expression .  (17)

	.  reduce 17


state 279
	postfix_expression : postfix_expression '(' argument_expression_list . ')'
	argument_expression_list : argument_expression_list . ',' assignment_expression

	')'  shift 315
	','  shift 316


state 280
	postfix_expression : postfix_expression '.' IDENTIFIER .  (13)

	.  reduce 13


state 281
	postfix_expression : postfix_expression '[' expression . ']'
	expression : expression . ',' assignment_expression

	','  shift 207
	']'  shift 317


state 282
	postfix_expression : postfix_expression PTR_OP IDENTIFIER .  (14)

	.  reduce 14


state 283
	expression : expression ',' assignment_expression .  (77)

	.  reduce 77


state 284
	conditional_expression : logical_or_expression '?' expression . ':' conditional_expression
	expression : expression . ',' assignment_expression

	','  shift 207
	':'  shift 318


state 285
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (60)

	AND_OP  shift 212
	.  reduce 60


state 286
	exclusive_or_expression : exclusive_or_expression . '^' and_expression
	inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression .  (56)

	'^'  shift 193
	.  reduce 56


state 287
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (58)
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression

	'|'  shift 211
	.  reduce 58


state 288
	compound_statement : '{' declaration_list statement_list '}' .  (189)

	.  reduce 189


state 289
	initializer_list : initializer .  (175)

	.  reduce 175


state 290
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 319
	'}'  shift 320


state 291
	struct_declarator : ':' constant_expression .  (123)

	.  reduce 123


state 292
	struct_declarator : declarator ':' . constant_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	constant_expression  goto 321
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 147
	logical_and_expression  goto 112


state 293
	struct_declarator_list : struct_declarator_list ',' . struct_declarator

	'('  shift 1
	'*'  shift 2
	':'  shift 224
	IDENTIFIER  shift 3

	declarator  goto 225
	struct_declarator  goto 322
	direct_declarator  goto 35
	pointer  goto 36


state 294
	struct_declaration : specifier_qualifier_list struct_declarator_list ';' .  (115)

	.  reduce 115


state 295
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}' .  (108)

	.  reduce 108


state 296
	direct_abstract_declarator : '(' ')' .  (168)

	.  reduce 168


state 297
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 323


state 298
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 324


state 299
	direct_abstract_declarator : '[' ']' .  (164)

	.  reduce 164


state 300
	direct_abstract_declarator : '[' constant_expression . ']'

	']'  shift 325


state 301
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

	declaration_specifiers  goto 138
	type_specifier  goto 28
	storage_class_specifier  goto 29
	type_qualifier  goto 30
	struct_or_union_specifier  goto 31
	enum_specifier  goto 32
	struct_or_union  goto 33
	parameter_declaration  goto 139
	parameter_list  goto 140
	parameter_type_list  goto 327


state 302
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_expression ']'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	']'  shift 328
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	constant_expression  goto 329
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 147
	logical_and_expression  goto 112


state 303
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	abstract_declarator : pointer direct_abstract_declarator .  (162)
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 301
	'['  shift 302
	.  reduce 162


state 304
	parameter_type_list : parameter_list ',' ELLIPSIS .  (150)

	.  reduce 150


state 305
	parameter_list : parameter_list ',' parameter_declaration .  (152)

	.  reduce 152


state 306
	identifier_list : identifier_list ',' IDENTIFIER .  (157)

	.  reduce 157


state 307
	cast_expression : '(' type_name ')' cast_expression .  (32)

	.  reduce 32


state 308
	unary_expression : SIZEOF '(' type_name ')' .  (24)

	.  reduce 24


state 309
	labeled_statement : CASE constant_expression ':' statement .  (184)

	.  reduce 184


state 310
	selection_statement : IF '(' expression ')' . statement
	selection_statement : IF '(' expression ')' . statement ELSE statement

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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 330
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 331
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 332
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 313
	iteration_statement : DO statement WHILE '(' . expression ')' ';'

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 333
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


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
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 335
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 315
	postfix_expression : postfix_expression '(' argument_expression_list ')' .  (12)

	.  reduce 12


state 316
	argument_expression_list : argument_expression_list ',' . assignment_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 336
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 317
	postfix_expression : postfix_expression '[' expression ']' .  (10)

	.  reduce 10


state 318
	conditional_expression : logical_or_expression '?' expression ':' . conditional_expression

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 145
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 337
	logical_and_expression  goto 112


state 319
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 69
	'&'  shift 70
	'('  shift 71
	'*'  shift 72
	'+'  shift 73
	'-'  shift 74
	'{'  shift 217
	'}'  shift 338
	'~'  shift 77
	IDENTIFIER  shift 144
	CONSTANT  shift 79
	STRING_LITERAL  shift 80
	SIZEOF  shift 81
	INC_OP  shift 82
	DEC_OP  shift 83

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 218
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	initializer  goto 339
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112


state 320
	initializer : '{' initializer_list '}' .  (173)

	.  reduce 173


state 321
	struct_declarator : declarator ':' constant_expression .  (124)

	.  reduce 124


state 322
	struct_declarator_list : struct_declarator_list ',' struct_declarator .  (121)

	.  reduce 121


state 323
	direct_abstract_declarator : '(' abstract_declarator ')' .  (163)

	.  reduce 163


state 324
	direct_abstract_declarator : '(' parameter_type_list ')' .  (169)

	.  reduce 169


state 325
	direct_abstract_declarator : '[' constant_expression ']' .  (165)

	.  reduce 165


state 326
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (170)

	.  reduce 170


state 327
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 340


state 328
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (166)

	.  reduce 166


state 329
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression . ']'

	']'  shift 341


330: shift-reduce conflict (shift 342, reduce 196) on ELSE
state 330
	selection_statement : IF '(' expression ')' statement .  (196)
	selection_statement : IF '(' expression ')' statement . ELSE statement

	ELSE  shift 342
	.  reduce 196


state 331
	selection_statement : SWITCH '(' expression ')' statement .  (198)

	.  reduce 198


state 332
	iteration_statement : WHILE '(' expression ')' statement .  (199)

	.  reduce 199


state 333
	expression : expression . ',' assignment_expression
	iteration_statement : DO statement WHILE '(' expression . ')' ';'

	')'  shift 343
	','  shift 207


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 344
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 335
	expression : expression . ',' assignment_expression
	iteration_statement : FOR '(' expression_statement expression_statement expression . ')' statement

	')'  shift 345
	','  shift 207


state 336
	argument_expression_list : argument_expression_list ',' assignment_expression .  (18)

	.  reduce 18


state 337
	conditional_expression : logical_or_expression '?' expression ':' conditional_expression .  (62)

	.  reduce 62


state 338
	initializer : '{' initializer_list ',' '}' .  (174)

	.  reduce 174


state 339
	initializer_list : initializer_list ',' initializer .  (176)

	.  reduce 176


state 340
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (171)

	.  reduce 171


state 341
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']' .  (167)

	.  reduce 167


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 346
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 343
	iteration_statement : DO statement WHILE '(' expression ')' . ';'

	';'  shift 347


state 344
	iteration_statement : FOR '(' expression_statement expression_statement ')' statement .  (201)

	.  reduce 201


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

	additive_expression  goto 95
	unary_expression  goto 96
	unary_operator  goto 97
	multiplicative_expression  goto 98
	equality_expression  goto 99
	exclusive_or_expression  goto 100
	and_expression  goto 101
	relational_expression  goto 102
	assignment_expression  goto 103
	cast_expression  goto 104
	shift_expression  goto 105
	primary_expression  goto 106
	postfix_expression  goto 107
	expression  goto 108
	logical_or_expression  goto 109
	inclusive_or_expression  goto 110
	conditional_expression  goto 111
	logical_and_expression  goto 112
	compound_statement  goto 113
	iteration_statement  goto 114
	statement  goto 348
	selection_statement  goto 116
	jump_statement  goto 117
	labeled_statement  goto 118
	expression_statement  goto 120


state 346
	selection_statement : IF '(' expression ')' statement ELSE statement .  (197)

	.  reduce 197


state 347
	iteration_statement : DO statement WHILE '(' expression ')' ';' .  (200)

	.  reduce 200


state 348
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement .  (202)

	.  reduce 202


Tokens never shifted
	NUMBER  (257)


Rules never reduced
	stmt : expr ';' expr  (1)
	stmt : stmt ';' expr  (2)
	expr : NUMBER '+' NUMBER  (3)
	expr : expr '+' NUMBER  (4)


##############################################################################
# Summary
##############################################################################

State 330 contains 1 shift-reduce conflict(s)


85 token(s), 66 nonterminal(s)
216 grammar rule(s), 349 state(s)


##############################################################################
# End of File
##############################################################################
