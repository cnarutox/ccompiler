#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 13 of your 30 day trial period.
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
# Date: 12/01/18
# Time: 21:58:15
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

	struct_or_union_specifier  goto 24
	pointer  goto 25
	type_specifier  goto 26
	direct_declarator  goto 27
	struct_or_union  goto 28
	type_qualifier  goto 29
	declarator  goto 30
	declaration  goto 31
	declaration_specifiers  goto 32
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	translation_unit  goto 35
	external_declaration  goto 36
	function_definition  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	pointer  goto 25
	direct_declarator  goto 27
	declarator  goto 38


state 2
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' .  (139)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 139

	pointer  goto 39
	type_qualifier_list  goto 40
	type_qualifier  goto 41


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
	enum_specifier : ENUM . IDENTIFIER '{' enumerator_list '}'
	enum_specifier : ENUM . IDENTIFIER
	enum_specifier : ENUM . '{' enumerator_list '}'

	'{'  shift 42
	IDENTIFIER  shift 43


state 24
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 25
	declarator : pointer . direct_declarator

	'('  shift 1
	IDENTIFIER  shift 3

	direct_declarator  goto 44


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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration_specifiers  goto 45
	enum_specifier  goto 33
	storage_class_specifier  goto 34


state 27
	declarator : direct_declarator .  (131)
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'

	'('  shift 46
	'['  shift 47
	.  reduce 131


state 28
	struct_or_union_specifier : struct_or_union . '{' struct_declaration_list '}'
	struct_or_union_specifier : struct_or_union . IDENTIFIER
	struct_or_union_specifier : struct_or_union . IDENTIFIER '{' struct_declaration_list '}'

	'{'  shift 48
	IDENTIFIER  shift 49


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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration_specifiers  goto 50
	enum_specifier  goto 33
	storage_class_specifier  goto 34


state 30
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration  goto 52
	declaration_specifiers  goto 53
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	compound_statement  goto 54
	declaration_list  goto 55


state 31
	external_declaration : declaration .  (207)

	.  reduce 207


state 32
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 56
	IDENTIFIER  shift 3

	pointer  goto 25
	direct_declarator  goto 27
	init_declarator  goto 57
	init_declarator_list  goto 58
	declarator  goto 59


state 33
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 34
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration_specifiers  goto 60
	enum_specifier  goto 33
	storage_class_specifier  goto 34


state 35
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

	struct_or_union_specifier  goto 24
	pointer  goto 25
	type_specifier  goto 26
	direct_declarator  goto 27
	struct_or_union  goto 28
	type_qualifier  goto 29
	declarator  goto 30
	declaration  goto 31
	declaration_specifiers  goto 32
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	external_declaration  goto 61
	function_definition  goto 37


state 36
	translation_unit : external_declaration .  (204)

	.  reduce 204


state 37
	external_declaration : function_definition .  (206)

	.  reduce 206


state 38
	direct_declarator : '(' declarator . ')'

	')'  shift 62


state 39
	pointer : '*' pointer .  (141)

	.  reduce 141


state 40
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (140)

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

	IDENTIFIER  shift 65

	enumerator_list  goto 66
	enumerator  goto 67


state 43
	enum_specifier : ENUM IDENTIFIER . '{' enumerator_list '}'
	enum_specifier : ENUM IDENTIFIER .  (123)

	'{'  shift 68
	.  reduce 123


state 44
	direct_declarator : direct_declarator . '[' constant_expression ']'
	direct_declarator : direct_declarator . '[' ']'
	declarator : pointer direct_declarator .  (130)
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'

	'('  shift 46
	'['  shift 47
	.  reduce 130


state 45
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 46
	direct_declarator : direct_declarator '(' . ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'
	direct_declarator : direct_declarator '(' . parameter_type_list ')'

	')'  shift 69
	IDENTIFIER  shift 70
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	parameter_type_list  goto 71
	parameter_list  goto 72
	declaration_specifiers  goto 73
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	identifier_list  goto 74
	parameter_declaration  goto 75


state 47
	direct_declarator : direct_declarator '[' . constant_expression ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	']'  shift 82
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	constant_expression  goto 102
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 48
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

	struct_or_union_specifier  goto 24
	struct_declaration_list  goto 107
	type_specifier  goto 108
	struct_declaration  goto 109
	struct_or_union  goto 28
	specifier_qualifier_list  goto 110
	type_qualifier  goto 111
	enum_specifier  goto 33


state 49
	struct_or_union_specifier : struct_or_union IDENTIFIER .  (106)
	struct_or_union_specifier : struct_or_union IDENTIFIER . '{' struct_declaration_list '}'

	'{'  shift 112
	.  reduce 106


state 50
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 51
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . '}'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'}'  shift 114
	'~'  shift 83
	IDENTIFIER  shift 115
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
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	struct_or_union_specifier  goto 24
	exclusive_or_expression  goto 101
	type_specifier  goto 26
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	struct_or_union  goto 28
	assignment_expression  goto 128
	expression  goto 129
	type_qualifier  goto 29
	conditional_expression  goto 130
	declaration  goto 52
	inclusive_or_expression  goto 106
	declaration_specifiers  goto 53
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	statement_list  goto 131
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 136
	iteration_statement  goto 137
	compound_statement  goto 138
	declaration_list  goto 139


state 52
	declaration_list : declaration .  (186)

	.  reduce 186


state 53
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 56
	IDENTIFIER  shift 3

	pointer  goto 25
	direct_declarator  goto 27
	init_declarator  goto 57
	init_declarator_list  goto 58
	declarator  goto 140


state 54
	function_definition : declarator compound_statement .  (211)

	.  reduce 211


state 55
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration  goto 141
	declaration_specifiers  goto 53
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	compound_statement  goto 142


state 56
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 57
	init_declarator_list : init_declarator .  (83)

	.  reduce 83


state 58
	init_declarator_list : init_declarator_list . ',' init_declarator
	declaration : declaration_specifiers init_declarator_list . ';'

	','  shift 143
	';'  shift 144


state 59
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 145
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration  goto 52
	declaration_specifiers  goto 53
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	compound_statement  goto 146
	declaration_list  goto 147


state 60
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 61
	translation_unit : translation_unit external_declaration .  (205)

	.  reduce 205


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
	enumerator : IDENTIFIER .  (126)
	enumerator : IDENTIFIER . '=' constant_expression

	'='  shift 148
	.  reduce 126


state 66
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM '{' enumerator_list . '}'

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
	direct_declarator : direct_declarator '(' ')' .  (138)

	.  reduce 138


state 70
	identifier_list : IDENTIFIER .  (152)

	.  reduce 152


state 71
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 152


state 72
	parameter_list : parameter_list . ',' parameter_declaration
	parameter_type_list : parameter_list .  (145)
	parameter_type_list : parameter_list . ',' ELLIPSIS

	','  shift 153
	.  reduce 145


state 73
	parameter_declaration : declaration_specifiers .  (151)
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator

	'('  shift 154
	'*'  shift 2
	'['  shift 155
	IDENTIFIER  shift 3
	.  reduce 151

	pointer  goto 156
	direct_declarator  goto 27
	declarator  goto 157
	abstract_declarator  goto 158
	direct_abstract_declarator  goto 159


state 74
	direct_declarator : direct_declarator '(' identifier_list . ')'
	identifier_list : identifier_list . ',' IDENTIFIER

	')'  shift 160
	','  shift 161


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
	IDENTIFIER  shift 84
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

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	struct_or_union_specifier  goto 24
	exclusive_or_expression  goto 101
	type_specifier  goto 108
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	struct_or_union  goto 28
	assignment_expression  goto 128
	specifier_qualifier_list  goto 162
	expression  goto 163
	type_qualifier  goto 111
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	enum_specifier  goto 33
	type_name  goto 164


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
	primary_expression : IDENTIFIER .  (1)

	.  reduce 1


state 85
	primary_expression : CONSTANT .  (2)

	.  reduce 2


state 86
	primary_expression : STRING_LITERAL .  (3)

	.  reduce 3


state 87
	unary_expression : SIZEOF . '(' type_name ')'
	unary_expression : SIZEOF . unary_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 165
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 166


state 88
	unary_expression : INC_OP . unary_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 167
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 168


state 89
	unary_expression : DEC_OP . unary_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 167
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 169


state 90
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : shift_expression .  (39)

	LEFT_OP  shift 170
	RIGHT_OP  shift 171
	.  reduce 39


state 91
	multiplicative_expression : cast_expression .  (29)

	.  reduce 29


state 92
	equality_expression : equality_expression . EQ_OP relational_expression
	equality_expression : equality_expression . NE_OP relational_expression
	and_expression : equality_expression .  (47)

	EQ_OP  shift 172
	NE_OP  shift 173
	.  reduce 47


state 93
	postfix_expression : primary_expression .  (5)

	.  reduce 5


state 94
	exclusive_or_expression : and_expression .  (49)
	and_expression : and_expression . '&' equality_expression

	'&'  shift 174
	.  reduce 49


state 95
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression
	shift_expression : additive_expression .  (36)

	'+'  shift 175
	'-'  shift 176
	.  reduce 36


state 96
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	additive_expression : multiplicative_expression .  (33)
	multiplicative_expression : multiplicative_expression . '*' cast_expression

	'%'  shift 177
	'*'  shift 178
	'/'  shift 179
	.  reduce 33


state 97
	unary_expression : unary_operator . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 180
	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 98
	postfix_expression : postfix_expression . '[' expression ']'
	postfix_expression : postfix_expression . '(' ')'
	postfix_expression : postfix_expression . '(' argument_expression_list ')'
	postfix_expression : postfix_expression . '.' IDENTIFIER
	postfix_expression : postfix_expression . PTR_OP IDENTIFIER
	postfix_expression : postfix_expression . INC_OP
	postfix_expression : postfix_expression . DEC_OP
	unary_expression : postfix_expression .  (15)

	'('  shift 181
	'.'  shift 182
	'['  shift 183
	PTR_OP  shift 184
	INC_OP  shift 185
	DEC_OP  shift 186
	.  reduce 15


state 99
	cast_expression : unary_expression .  (27)

	.  reduce 27


state 100
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	equality_expression : relational_expression .  (44)
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . '<' shift_expression

	'<'  shift 187
	'>'  shift 188
	LE_OP  shift 189
	GE_OP  shift 190
	.  reduce 44


state 101
	inclusive_or_expression : exclusive_or_expression .  (51)
	exclusive_or_expression : exclusive_or_expression . '^' and_expression

	'^'  shift 191
	.  reduce 51


state 102
	direct_declarator : direct_declarator '[' constant_expression . ']'

	']'  shift 192


state 103
	conditional_expression : logical_or_expression .  (57)
	logical_or_expression : logical_or_expression . OR_OP logical_and_expression
	conditional_expression : logical_or_expression . '?' expression ':' conditional_expression

	'?'  shift 193
	OR_OP  shift 194
	.  reduce 57


state 104
	logical_or_expression : logical_and_expression .  (55)
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression

	AND_OP  shift 195
	.  reduce 55


state 105
	constant_expression : conditional_expression .  (74)

	.  reduce 74


state 106
	logical_and_expression : inclusive_or_expression .  (53)
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression

	'|'  shift 196
	.  reduce 53


state 107
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list . '}'

	'}'  shift 197
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 108
	struct_declaration  goto 198
	struct_or_union  goto 28
	specifier_qualifier_list  goto 110
	type_qualifier  goto 111
	enum_specifier  goto 33


state 108
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 108
	struct_or_union  goto 28
	specifier_qualifier_list  goto 199
	type_qualifier  goto 111
	enum_specifier  goto 33


state 109
	struct_declaration_list : struct_declaration .  (109)

	.  reduce 109


state 110
	struct_declaration : specifier_qualifier_list . struct_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	':'  shift 200
	IDENTIFIER  shift 3

	pointer  goto 25
	direct_declarator  goto 27
	struct_declarator_list  goto 201
	declarator  goto 202
	struct_declarator  goto 203


state 111
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 108
	struct_or_union  goto 28
	specifier_qualifier_list  goto 204
	type_qualifier  goto 111
	enum_specifier  goto 33


state 112
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

	struct_or_union_specifier  goto 24
	struct_declaration_list  goto 205
	type_specifier  goto 108
	struct_declaration  goto 109
	struct_or_union  goto 28
	specifier_qualifier_list  goto 110
	type_qualifier  goto 111
	enum_specifier  goto 33


state 113
	expression_statement : ';' .  (190)

	.  reduce 190


state 114
	compound_statement : '{' '}' .  (182)

	.  reduce 182


state 115
	primary_expression : IDENTIFIER .  (1)
	labeled_statement : IDENTIFIER . ':' statement

	':'  shift 206
	.  reduce 1


state 116
	labeled_statement : CASE . constant_expression ':' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	constant_expression  goto 207
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 117
	labeled_statement : DEFAULT . ':' statement

	':'  shift 208


state 118
	selection_statement : IF . '(' expression ')' statement ELSE statement
	selection_statement : IF . '(' expression ')' statement

	'('  shift 209


state 119
	selection_statement : SWITCH . '(' expression ')' statement

	'('  shift 210


state 120
	iteration_statement : WHILE . '(' expression ')' statement

	'('  shift 211


state 121
	iteration_statement : DO . statement WHILE '(' expression ')' ';'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 212
	iteration_statement  goto 137
	compound_statement  goto 138


state 122
	iteration_statement : FOR . '(' expression_statement expression_statement ')' statement
	iteration_statement : FOR . '(' expression_statement expression_statement expression ')' statement

	'('  shift 213


state 123
	jump_statement : GOTO . IDENTIFIER ';'

	IDENTIFIER  shift 214


state 124
	jump_statement : CONTINUE . ';'

	';'  shift 215


state 125
	jump_statement : BREAK . ';'

	';'  shift 216


state 126
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
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 218
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 127
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


state 128
	expression : assignment_expression .  (72)

	.  reduce 72


state 129
	expression : expression . ',' assignment_expression
	expression_statement : expression . ';'

	','  shift 231
	';'  shift 232


state 130
	assignment_expression : conditional_expression .  (59)

	.  reduce 59


state 131
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'}'  shift 233
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 234
	iteration_statement  goto 137
	compound_statement  goto 138


state 132
	statement : selection_statement .  (176)

	.  reduce 176


state 133
	statement : labeled_statement .  (173)

	.  reduce 173


state 134
	statement : jump_statement .  (178)

	.  reduce 178


state 135
	statement : expression_statement .  (175)

	.  reduce 175


state 136
	statement_list : statement .  (188)

	.  reduce 188


state 137
	statement : iteration_statement .  (177)

	.  reduce 177


state 138
	statement : compound_statement .  (174)

	.  reduce 174


state 139
	compound_statement : '{' declaration_list . '}'
	compound_statement : '{' declaration_list . statement_list '}'
	declaration_list : declaration_list . declaration

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'}'  shift 235
	'~'  shift 83
	IDENTIFIER  shift 115
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
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	struct_or_union_specifier  goto 24
	exclusive_or_expression  goto 101
	type_specifier  goto 26
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	struct_or_union  goto 28
	assignment_expression  goto 128
	expression  goto 129
	type_qualifier  goto 29
	conditional_expression  goto 130
	declaration  goto 141
	inclusive_or_expression  goto 106
	declaration_specifiers  goto 53
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	statement_list  goto 236
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 136
	iteration_statement  goto 137
	compound_statement  goto 138


state 140
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer

	'='  shift 145
	.  reduce 85


state 141
	declaration_list : declaration_list declaration .  (187)

	.  reduce 187


state 142
	function_definition : declarator declaration_list compound_statement .  (210)

	.  reduce 210


state 143
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	IDENTIFIER  shift 3

	pointer  goto 25
	direct_declarator  goto 27
	init_declarator  goto 237
	declarator  goto 140


state 144
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 145
	init_declarator : declarator '=' . initializer

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'{'  shift 238
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 239
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	initializer  goto 240


state 146
	function_definition : declaration_specifiers declarator compound_statement .  (209)

	.  reduce 209


state 147
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration  goto 141
	declaration_specifiers  goto 53
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	compound_statement  goto 241


state 148
	enumerator : IDENTIFIER '=' . constant_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	constant_expression  goto 242
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 149
	enumerator_list : enumerator_list ',' . enumerator

	IDENTIFIER  shift 65

	enumerator  goto 243


state 150
	enum_specifier : ENUM '{' enumerator_list '}' .  (121)

	.  reduce 121


state 151
	enum_specifier : ENUM IDENTIFIER '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 149
	'}'  shift 244


state 152
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (136)

	.  reduce 136


state 153
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
	ELLIPSIS  shift 245

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	declaration_specifiers  goto 73
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	parameter_declaration  goto 246


state 154
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 154
	')'  shift 247
	'*'  shift 2
	'['  shift 155
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

	struct_or_union_specifier  goto 24
	pointer  goto 156
	type_specifier  goto 26
	direct_declarator  goto 27
	struct_or_union  goto 28
	type_qualifier  goto 29
	parameter_type_list  goto 248
	parameter_list  goto 72
	declarator  goto 38
	declaration_specifiers  goto 73
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	abstract_declarator  goto 249
	direct_abstract_declarator  goto 159
	parameter_declaration  goto 75


state 155
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_expression ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	']'  shift 250
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	constant_expression  goto 251
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 156
	declarator : pointer . direct_declarator
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (156)

	'('  shift 154
	'['  shift 155
	IDENTIFIER  shift 3
	.  reduce 156

	direct_declarator  goto 44
	direct_abstract_declarator  goto 252


state 157
	parameter_declaration : declaration_specifiers declarator .  (149)

	.  reduce 149


state 158
	parameter_declaration : declaration_specifiers abstract_declarator .  (150)

	.  reduce 150


state 159
	abstract_declarator : direct_abstract_declarator .  (157)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'

	'('  shift 253
	'['  shift 254
	.  reduce 157


state 160
	direct_declarator : direct_declarator '(' identifier_list ')' .  (137)

	.  reduce 137


state 161
	identifier_list : identifier_list ',' . IDENTIFIER

	IDENTIFIER  shift 255


state 162
	type_name : specifier_qualifier_list . abstract_declarator
	type_name : specifier_qualifier_list .  (154)

	'('  shift 256
	'*'  shift 2
	'['  shift 155
	.  reduce 154

	pointer  goto 257
	abstract_declarator  goto 258
	direct_abstract_declarator  goto 159


state 163
	primary_expression : '(' expression . ')'
	expression : expression . ',' assignment_expression

	')'  shift 259
	','  shift 231


state 164
	cast_expression : '(' type_name . ')' cast_expression

	')'  shift 260


state 165
	primary_expression : '(' . expression ')'
	unary_expression : SIZEOF '(' . type_name ')'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
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

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	struct_or_union_specifier  goto 24
	exclusive_or_expression  goto 101
	type_specifier  goto 108
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	struct_or_union  goto 28
	assignment_expression  goto 128
	specifier_qualifier_list  goto 162
	expression  goto 163
	type_qualifier  goto 111
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	enum_specifier  goto 33
	type_name  goto 261


state 166
	unary_expression : SIZEOF unary_expression .  (19)

	.  reduce 19


state 167
	primary_expression : '(' . expression ')'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 163
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 168
	unary_expression : INC_OP unary_expression .  (16)

	.  reduce 16


state 169
	unary_expression : DEC_OP unary_expression .  (17)

	.  reduce 17


state 170
	shift_expression : shift_expression LEFT_OP . additive_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 262
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 171
	shift_expression : shift_expression RIGHT_OP . additive_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 263
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 172
	equality_expression : equality_expression EQ_OP . relational_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 264


state 173
	equality_expression : equality_expression NE_OP . relational_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 265


state 174
	and_expression : and_expression '&' . equality_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 266
	primary_expression  goto 93
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100


state 175
	additive_expression : additive_expression '+' . multiplicative_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 91
	primary_expression  goto 93
	multiplicative_expression  goto 267
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 176
	additive_expression : additive_expression '-' . multiplicative_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 91
	primary_expression  goto 93
	multiplicative_expression  goto 268
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 177
	multiplicative_expression : multiplicative_expression '%' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 269
	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 178
	multiplicative_expression : multiplicative_expression '*' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 270
	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 179
	multiplicative_expression : multiplicative_expression '/' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 271
	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 180
	unary_expression : unary_operator cast_expression .  (18)

	.  reduce 18


state 181
	postfix_expression : postfix_expression '(' . ')'
	postfix_expression : postfix_expression '(' . argument_expression_list ')'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	')'  shift 272
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	argument_expression_list  goto 273
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 274
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 182
	postfix_expression : postfix_expression '.' . IDENTIFIER

	IDENTIFIER  shift 275


state 183
	postfix_expression : postfix_expression '[' . expression ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 276
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 184
	postfix_expression : postfix_expression PTR_OP . IDENTIFIER

	IDENTIFIER  shift 277


state 185
	postfix_expression : postfix_expression INC_OP .  (11)

	.  reduce 11


state 186
	postfix_expression : postfix_expression DEC_OP .  (12)

	.  reduce 12


state 187
	relational_expression : relational_expression '<' . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 278
	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 188
	relational_expression : relational_expression '>' . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 279
	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 189
	relational_expression : relational_expression LE_OP . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 280
	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 190
	relational_expression : relational_expression GE_OP . shift_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 281
	cast_expression  goto 91
	primary_expression  goto 93
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 191
	exclusive_or_expression : exclusive_or_expression '^' . and_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 282
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100


state 192
	direct_declarator : direct_declarator '[' constant_expression ']' .  (134)

	.  reduce 134


state 193
	conditional_expression : logical_or_expression '?' . expression ':' conditional_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 283
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 194
	logical_or_expression : logical_or_expression OR_OP . logical_and_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_and_expression  goto 284
	inclusive_or_expression  goto 106


state 195
	logical_and_expression : logical_and_expression AND_OP . inclusive_or_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	inclusive_or_expression  goto 285


state 196
	inclusive_or_expression : inclusive_or_expression '|' . exclusive_or_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 286


state 197
	struct_or_union_specifier : struct_or_union '{' struct_declaration_list '}' .  (105)

	.  reduce 105


state 198
	struct_declaration_list : struct_declaration_list struct_declaration .  (110)

	.  reduce 110


state 199
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (112)

	.  reduce 112


state 200
	struct_declarator : ':' . constant_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	constant_expression  goto 287
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 201
	struct_declaration : specifier_qualifier_list struct_declarator_list . ';'
	struct_declarator_list : struct_declarator_list . ',' struct_declarator

	','  shift 288
	';'  shift 289


state 202
	struct_declarator : declarator . ':' constant_expression
	struct_declarator : declarator .  (118)

	':'  shift 290
	.  reduce 118


state 203
	struct_declarator_list : struct_declarator .  (116)

	.  reduce 116


state 204
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (114)

	.  reduce 114


state 205
	struct_declaration_list : struct_declaration_list . struct_declaration
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list . '}'

	'}'  shift 291
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 108
	struct_declaration  goto 198
	struct_or_union  goto 28
	specifier_qualifier_list  goto 110
	type_qualifier  goto 111
	enum_specifier  goto 33


state 206
	labeled_statement : IDENTIFIER ':' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 292
	iteration_statement  goto 137
	compound_statement  goto 138


state 207
	labeled_statement : CASE constant_expression . ':' statement

	':'  shift 293


state 208
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 294
	iteration_statement  goto 137
	compound_statement  goto 138


state 209
	selection_statement : IF '(' . expression ')' statement ELSE statement
	selection_statement : IF '(' . expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 295
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 210
	selection_statement : SWITCH '(' . expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 296
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 211
	iteration_statement : WHILE '(' . expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 297
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 212
	iteration_statement : DO statement . WHILE '(' expression ')' ';'

	WHILE  shift 298


state 213
	iteration_statement : FOR '(' . expression_statement expression_statement ')' statement
	iteration_statement : FOR '(' . expression_statement expression_statement expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	expression_statement  goto 299


state 214
	jump_statement : GOTO IDENTIFIER . ';'

	';'  shift 300


state 215
	jump_statement : CONTINUE ';' .  (200)

	.  reduce 200


state 216
	jump_statement : BREAK ';' .  (201)

	.  reduce 201


state 217
	jump_statement : RETURN ';' .  (202)

	.  reduce 202


state 218
	expression : expression . ',' assignment_expression
	jump_statement : RETURN expression . ';'

	','  shift 231
	';'  shift 301


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
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 302
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 231
	expression : expression ',' . assignment_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 303
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 232
	expression_statement : expression ';' .  (191)

	.  reduce 191


state 233
	compound_statement : '{' statement_list '}' .  (183)

	.  reduce 183


state 234
	statement_list : statement_list statement .  (189)

	.  reduce 189


state 235
	compound_statement : '{' declaration_list '}' .  (184)

	.  reduce 184


state 236
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'}'  shift 304
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 234
	iteration_statement  goto 137
	compound_statement  goto 138


state 237
	init_declarator_list : init_declarator_list ',' init_declarator .  (84)

	.  reduce 84


state 238
	initializer : '{' . initializer_list ',' '}'
	initializer : '{' . initializer_list '}'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'{'  shift 238
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 239
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	initializer_list  goto 305
	initializer  goto 306


state 239
	initializer : assignment_expression .  (168)

	.  reduce 168


state 240
	init_declarator : declarator '=' initializer .  (86)

	.  reduce 86


state 241
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (208)

	.  reduce 208


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
	parameter_type_list : parameter_list ',' ELLIPSIS .  (146)

	.  reduce 146


state 246
	parameter_list : parameter_list ',' parameter_declaration .  (148)

	.  reduce 148


state 247
	direct_abstract_declarator : '(' ')' .  (164)

	.  reduce 164


state 248
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 307


state 249
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 308


state 250
	direct_abstract_declarator : '[' ']' .  (160)

	.  reduce 160


state 251
	direct_abstract_declarator : '[' constant_expression . ']'

	']'  shift 309


state 252
	abstract_declarator : pointer direct_abstract_declarator .  (158)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_expression ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'

	'('  shift 253
	'['  shift 254
	.  reduce 158


state 253
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'

	')'  shift 310
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

	struct_or_union_specifier  goto 24
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	parameter_type_list  goto 311
	parameter_list  goto 72
	declaration_specifiers  goto 73
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	parameter_declaration  goto 75


state 254
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_expression ']'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	']'  shift 312
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	constant_expression  goto 313
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 255
	identifier_list : identifier_list ',' IDENTIFIER .  (153)

	.  reduce 153


state 256
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 256
	')'  shift 247
	'*'  shift 2
	'['  shift 155
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

	struct_or_union_specifier  goto 24
	pointer  goto 257
	type_specifier  goto 26
	struct_or_union  goto 28
	type_qualifier  goto 29
	parameter_type_list  goto 248
	parameter_list  goto 72
	declaration_specifiers  goto 73
	enum_specifier  goto 33
	storage_class_specifier  goto 34
	abstract_declarator  goto 249
	direct_abstract_declarator  goto 159
	parameter_declaration  goto 75


state 257
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (156)

	'('  shift 256
	'['  shift 155
	.  reduce 156

	direct_abstract_declarator  goto 252


state 258
	type_name : specifier_qualifier_list abstract_declarator .  (155)

	.  reduce 155


state 259
	primary_expression : '(' expression ')' .  (4)

	.  reduce 4


state 260
	cast_expression : '(' type_name ')' . cast_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	cast_expression  goto 314
	primary_expression  goto 93
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99


state 261
	unary_expression : SIZEOF '(' type_name . ')'

	')'  shift 315


state 262
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression
	shift_expression : shift_expression LEFT_OP additive_expression .  (37)

	'+'  shift 175
	'-'  shift 176
	.  reduce 37


state 263
	additive_expression : additive_expression . '+' multiplicative_expression
	additive_expression : additive_expression . '-' multiplicative_expression
	shift_expression : shift_expression RIGHT_OP additive_expression .  (38)

	'+'  shift 175
	'-'  shift 176
	.  reduce 38


state 264
	equality_expression : equality_expression EQ_OP relational_expression .  (45)
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . '<' shift_expression

	'<'  shift 187
	'>'  shift 188
	LE_OP  shift 189
	GE_OP  shift 190
	.  reduce 45


state 265
	equality_expression : equality_expression NE_OP relational_expression .  (46)
	relational_expression : relational_expression . LE_OP shift_expression
	relational_expression : relational_expression . GE_OP shift_expression
	relational_expression : relational_expression . '>' shift_expression
	relational_expression : relational_expression . '<' shift_expression

	'<'  shift 187
	'>'  shift 188
	LE_OP  shift 189
	GE_OP  shift 190
	.  reduce 46


state 266
	equality_expression : equality_expression . EQ_OP relational_expression
	equality_expression : equality_expression . NE_OP relational_expression
	and_expression : and_expression '&' equality_expression .  (48)

	EQ_OP  shift 172
	NE_OP  shift 173
	.  reduce 48


state 267
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : additive_expression '+' multiplicative_expression .  (34)

	'%'  shift 177
	'*'  shift 178
	'/'  shift 179
	.  reduce 34


state 268
	multiplicative_expression : multiplicative_expression . '/' cast_expression
	multiplicative_expression : multiplicative_expression . '%' cast_expression
	multiplicative_expression : multiplicative_expression . '*' cast_expression
	additive_expression : additive_expression '-' multiplicative_expression .  (35)

	'%'  shift 177
	'*'  shift 178
	'/'  shift 179
	.  reduce 35


state 269
	multiplicative_expression : multiplicative_expression '%' cast_expression .  (32)

	.  reduce 32


state 270
	multiplicative_expression : multiplicative_expression '*' cast_expression .  (30)

	.  reduce 30


state 271
	multiplicative_expression : multiplicative_expression '/' cast_expression .  (31)

	.  reduce 31


state 272
	postfix_expression : postfix_expression '(' ')' .  (7)

	.  reduce 7


state 273
	postfix_expression : postfix_expression '(' argument_expression_list . ')'
	argument_expression_list : argument_expression_list . ',' assignment_expression

	')'  shift 316
	','  shift 317


state 274
	argument_expression_list : assignment_expression .  (13)

	.  reduce 13


state 275
	postfix_expression : postfix_expression '.' IDENTIFIER .  (9)

	.  reduce 9


state 276
	postfix_expression : postfix_expression '[' expression . ']'
	expression : expression . ',' assignment_expression

	','  shift 231
	']'  shift 318


state 277
	postfix_expression : postfix_expression PTR_OP IDENTIFIER .  (10)

	.  reduce 10


state 278
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '<' shift_expression .  (40)

	LEFT_OP  shift 170
	RIGHT_OP  shift 171
	.  reduce 40


state 279
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression
	relational_expression : relational_expression '>' shift_expression .  (41)

	LEFT_OP  shift 170
	RIGHT_OP  shift 171
	.  reduce 41


state 280
	relational_expression : relational_expression LE_OP shift_expression .  (42)
	shift_expression : shift_expression . RIGHT_OP additive_expression
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 170
	RIGHT_OP  shift 171
	.  reduce 42


state 281
	shift_expression : shift_expression . RIGHT_OP additive_expression
	relational_expression : relational_expression GE_OP shift_expression .  (43)
	shift_expression : shift_expression . LEFT_OP additive_expression

	LEFT_OP  shift 170
	RIGHT_OP  shift 171
	.  reduce 43


state 282
	exclusive_or_expression : exclusive_or_expression '^' and_expression .  (50)
	and_expression : and_expression . '&' equality_expression

	'&'  shift 174
	.  reduce 50


state 283
	conditional_expression : logical_or_expression '?' expression . ':' conditional_expression
	expression : expression . ',' assignment_expression

	','  shift 231
	':'  shift 319


state 284
	logical_or_expression : logical_or_expression OR_OP logical_and_expression .  (56)
	logical_and_expression : logical_and_expression . AND_OP inclusive_or_expression

	AND_OP  shift 195
	.  reduce 56


state 285
	logical_and_expression : logical_and_expression AND_OP inclusive_or_expression .  (54)
	inclusive_or_expression : inclusive_or_expression . '|' exclusive_or_expression

	'|'  shift 196
	.  reduce 54


state 286
	exclusive_or_expression : exclusive_or_expression . '^' and_expression
	inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression .  (52)

	'^'  shift 191
	.  reduce 52


state 287
	struct_declarator : ':' constant_expression .  (119)

	.  reduce 119


state 288
	struct_declarator_list : struct_declarator_list ',' . struct_declarator

	'('  shift 1
	'*'  shift 2
	':'  shift 200
	IDENTIFIER  shift 3

	pointer  goto 25
	direct_declarator  goto 27
	declarator  goto 202
	struct_declarator  goto 320


state 289
	struct_declaration : specifier_qualifier_list struct_declarator_list ';' .  (111)

	.  reduce 111


state 290
	struct_declarator : declarator ':' . constant_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	constant_expression  goto 321
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 105
	inclusive_or_expression  goto 106


state 291
	struct_or_union_specifier : struct_or_union IDENTIFIER '{' struct_declaration_list '}' .  (104)

	.  reduce 104


state 292
	labeled_statement : IDENTIFIER ':' statement .  (179)

	.  reduce 179


state 293
	labeled_statement : CASE constant_expression ':' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 322
	iteration_statement  goto 137
	compound_statement  goto 138


state 294
	labeled_statement : DEFAULT ':' statement .  (181)

	.  reduce 181


state 295
	expression : expression . ',' assignment_expression
	selection_statement : IF '(' expression . ')' statement ELSE statement
	selection_statement : IF '(' expression . ')' statement

	')'  shift 323
	','  shift 231


state 296
	expression : expression . ',' assignment_expression
	selection_statement : SWITCH '(' expression . ')' statement

	')'  shift 324
	','  shift 231


state 297
	expression : expression . ',' assignment_expression
	iteration_statement : WHILE '(' expression . ')' statement

	')'  shift 325
	','  shift 231


state 298
	iteration_statement : DO statement WHILE . '(' expression ')' ';'

	'('  shift 326


state 299
	iteration_statement : FOR '(' expression_statement . expression_statement ')' statement
	iteration_statement : FOR '(' expression_statement . expression_statement expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	expression_statement  goto 327


state 300
	jump_statement : GOTO IDENTIFIER ';' .  (199)

	.  reduce 199


state 301
	jump_statement : RETURN expression ';' .  (203)

	.  reduce 203


state 302
	assignment_expression : unary_expression assignment_operator assignment_expression .  (60)

	.  reduce 60


state 303
	expression : expression ',' assignment_expression .  (73)

	.  reduce 73


state 304
	compound_statement : '{' declaration_list statement_list '}' .  (185)

	.  reduce 185


state 305
	initializer : '{' initializer_list . ',' '}'
	initializer : '{' initializer_list . '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 328
	'}'  shift 329


state 306
	initializer_list : initializer .  (171)

	.  reduce 171


state 307
	direct_abstract_declarator : '(' parameter_type_list ')' .  (165)

	.  reduce 165


state 308
	direct_abstract_declarator : '(' abstract_declarator ')' .  (159)

	.  reduce 159


state 309
	direct_abstract_declarator : '[' constant_expression ']' .  (161)

	.  reduce 161


state 310
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (166)

	.  reduce 166


state 311
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 330


state 312
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (162)

	.  reduce 162


state 313
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression . ']'

	']'  shift 331


state 314
	cast_expression : '(' type_name ')' cast_expression .  (28)

	.  reduce 28


state 315
	unary_expression : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 316
	postfix_expression : postfix_expression '(' argument_expression_list ')' .  (8)

	.  reduce 8


state 317
	argument_expression_list : argument_expression_list ',' . assignment_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 332
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 318
	postfix_expression : postfix_expression '[' expression ']' .  (6)

	.  reduce 6


state 319
	conditional_expression : logical_or_expression '?' expression ':' . conditional_expression

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 99
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	conditional_expression  goto 333
	inclusive_or_expression  goto 106


state 320
	struct_declarator_list : struct_declarator_list ',' struct_declarator .  (117)

	.  reduce 117


state 321
	struct_declarator : declarator ':' constant_expression .  (120)

	.  reduce 120


state 322
	labeled_statement : CASE constant_expression ':' statement .  (180)

	.  reduce 180


state 323
	selection_statement : IF '(' expression ')' . statement ELSE statement
	selection_statement : IF '(' expression ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 334
	iteration_statement  goto 137
	compound_statement  goto 138


state 324
	selection_statement : SWITCH '(' expression ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 335
	iteration_statement  goto 137
	compound_statement  goto 138


state 325
	iteration_statement : WHILE '(' expression ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 336
	iteration_statement  goto 137
	compound_statement  goto 138


state 326
	iteration_statement : DO statement WHILE '(' . expression ')' ';'

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 337
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 327
	iteration_statement : FOR '(' expression_statement expression_statement . ')' statement
	iteration_statement : FOR '(' expression_statement expression_statement . expression ')' statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	')'  shift 338
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 339
	conditional_expression  goto 130
	inclusive_or_expression  goto 106


state 328
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	'{'  shift 238
	'}'  shift 340
	'~'  shift 83
	IDENTIFIER  shift 84
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 239
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	initializer  goto 341


state 329
	initializer : '{' initializer_list '}' .  (169)

	.  reduce 169


state 330
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (167)

	.  reduce 167


state 331
	direct_abstract_declarator : direct_abstract_declarator '[' constant_expression ']' .  (163)

	.  reduce 163


state 332
	argument_expression_list : argument_expression_list ',' assignment_expression .  (14)

	.  reduce 14


state 333
	conditional_expression : logical_or_expression '?' expression ':' conditional_expression .  (58)

	.  reduce 58


334: shift-reduce conflict (shift 342, reduce 192) on ELSE
state 334
	selection_statement : IF '(' expression ')' statement . ELSE statement
	selection_statement : IF '(' expression ')' statement .  (192)

	ELSE  shift 342
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

	')'  shift 343
	','  shift 231


state 338
	iteration_statement : FOR '(' expression_statement expression_statement ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 344
	iteration_statement  goto 137
	compound_statement  goto 138


state 339
	expression : expression . ',' assignment_expression
	iteration_statement : FOR '(' expression_statement expression_statement expression . ')' statement

	')'  shift 345
	','  shift 231


state 340
	initializer : '{' initializer_list ',' '}' .  (170)

	.  reduce 170


state 341
	initializer_list : initializer_list ',' initializer .  (172)

	.  reduce 172


state 342
	selection_statement : IF '(' expression ')' statement ELSE . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 346
	iteration_statement  goto 137
	compound_statement  goto 138


state 343
	iteration_statement : DO statement WHILE '(' expression ')' . ';'

	';'  shift 347


state 344
	iteration_statement : FOR '(' expression_statement expression_statement ')' statement .  (197)

	.  reduce 197


state 345
	iteration_statement : FOR '(' expression_statement expression_statement expression ')' . statement

	'!'  shift 76
	'&'  shift 77
	'('  shift 78
	'*'  shift 79
	'+'  shift 80
	'-'  shift 81
	';'  shift 113
	'{'  shift 51
	'~'  shift 83
	IDENTIFIER  shift 115
	CONSTANT  shift 85
	STRING_LITERAL  shift 86
	SIZEOF  shift 87
	INC_OP  shift 88
	DEC_OP  shift 89
	CASE  shift 116
	DEFAULT  shift 117
	IF  shift 118
	SWITCH  shift 119
	WHILE  shift 120
	DO  shift 121
	FOR  shift 122
	GOTO  shift 123
	CONTINUE  shift 124
	BREAK  shift 125
	RETURN  shift 126

	shift_expression  goto 90
	cast_expression  goto 91
	equality_expression  goto 92
	primary_expression  goto 93
	and_expression  goto 94
	additive_expression  goto 95
	multiplicative_expression  goto 96
	unary_operator  goto 97
	postfix_expression  goto 98
	unary_expression  goto 127
	relational_expression  goto 100
	exclusive_or_expression  goto 101
	logical_or_expression  goto 103
	logical_and_expression  goto 104
	assignment_expression  goto 128
	expression  goto 129
	conditional_expression  goto 130
	inclusive_or_expression  goto 106
	selection_statement  goto 132
	labeled_statement  goto 133
	jump_statement  goto 134
	expression_statement  goto 135
	statement  goto 348
	iteration_statement  goto 137
	compound_statement  goto 138


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

State 334 contains 1 shift-reduce conflict(s)


84 token(s), 64 nonterminal(s)
212 grammar rule(s), 349 state(s)


##############################################################################
# End of File
##############################################################################
