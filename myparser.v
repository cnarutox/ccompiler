#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 70 of your 30 day trial period.
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
# Date: 12/19/18
# Time: 10:56:12
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : translation_unit $end

    1  primary_exp : ID
    2              | CONSTANT
    3              | STRING_LITERAL
    4              | '(' exp ')'

    5  postfix_exp : primary_exp
    6              | postfix_exp '[' exp ']'
    7              | postfix_exp '(' ')'
    8              | postfix_exp '(' argument_exp_list ')'
    9              | postfix_exp '.' ID
   10              | postfix_exp PTR_OP ID
   11              | postfix_exp INC_OP
   12              | postfix_exp DEC_OP

   13  argument_exp_list : assignment_exp
   14                    | argument_exp_list ',' assignment_exp

   15  unary_exp : postfix_exp
   16            | INC_OP unary_exp
   17            | DEC_OP unary_exp
   18            | unary_operator cast_exp
   19            | SIZEOF unary_exp
   20            | SIZEOF '(' type_name ')'

   21  unary_operator : '&'
   22                 | '*'
   23                 | '+'
   24                 | '-'
   25                 | '~'
   26                 | '!'

   27  cast_exp : unary_exp
   28           | '(' type_name ')' cast_exp

   29  multiplicative_exp : cast_exp
   30                     | multiplicative_exp '*' cast_exp
   31                     | multiplicative_exp '/' cast_exp
   32                     | multiplicative_exp '%' cast_exp

   33  additive_exp : multiplicative_exp
   34               | additive_exp '+' multiplicative_exp
   35               | additive_exp '-' multiplicative_exp

   36  shift_exp : additive_exp
   37            | shift_exp LEFT_OP additive_exp
   38            | shift_exp RIGHT_OP additive_exp

   39  relational_exp : shift_exp
   40                 | relational_exp '<' shift_exp
   41                 | relational_exp '>' shift_exp
   42                 | relational_exp LE_OP shift_exp
   43                 | relational_exp GE_OP shift_exp

   44  equality_exp : relational_exp
   45               | equality_exp EQ_OP relational_exp
   46               | equality_exp NE_OP relational_exp

   47  and_exp : equality_exp
   48          | and_exp '&' equality_exp

   49  exclusive_or_exp : and_exp
   50                   | exclusive_or_exp '^' and_exp

   51  inclusive_or_exp : exclusive_or_exp
   52                   | inclusive_or_exp '|' exclusive_or_exp

   53  logical_and_exp : inclusive_or_exp
   54                  | logical_and_exp AND_OP inclusive_or_exp

   55  logical_or_exp : logical_and_exp
   56                 | logical_or_exp OR_OP logical_and_exp

   57  conditional_exp : logical_or_exp
   58                  | logical_or_exp '?' exp ':' conditional_exp

   59  assignment_exp : conditional_exp
   60                 | unary_exp assignment_operator assignment_exp

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

   72  exp : assignment_exp
   73      | exp ',' assignment_exp

   74  constant_exp : conditional_exp

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
  104                 | type_specifier pointer

  105  struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' ';'
  106                            | struct_or_union ID '{' declaration_list '}' init_declarator_list ';'
  107                            | struct_or_union '{' declaration_list '}' ';'
  108                            | struct_or_union '{' declaration_list '}' init_declarator_list ';'
  109                            | struct_or_union ID

  110  struct_or_union : STRUCT
  111                  | UNION

  112  struct_declaration_list : struct_declaration
  113                          | struct_declaration_list struct_declaration

  114  struct_declaration : specifier_qualifier_list struct_declarator_list ';'
  115                     | assignment_exp struct_declarator_list ';'

  116  specifier_qualifier_list : type_specifier specifier_qualifier_list
  117                           | type_specifier
  118                           | type_qualifier specifier_qualifier_list
  119                           | type_qualifier

  120  struct_declarator_list : struct_declarator
  121                         | struct_declarator_list ',' struct_declarator

  122  struct_declarator : declarator
  123                    | ':' constant_exp
  124                    | declarator ':' constant_exp

  125  enum_specifier : ENUM '{' enumerator_list '}'
  126                 | ENUM ID '{' enumerator_list '}'
  127                 | ENUM ID

  128  enumerator_list : enumerator
  129                  | enumerator_list ',' enumerator

  130  enumerator : ID
  131             | ID '=' constant_exp

  132  type_qualifier : CONST
  133                 | VOLATILE

  134  declarator : pointer direct_declarator
  135             | direct_declarator

  136  direct_declarator : ID
  137                    | '(' declarator ')'
  138                    | direct_declarator '[' constant_exp ']'
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

  156  identifier_list : ID
  157                  | identifier_list ',' ID

  158  type_name : specifier_qualifier_list
  159            | specifier_qualifier_list abstract_declarator

  160  abstract_declarator : pointer
  161                      | direct_abstract_declarator
  162                      | pointer direct_abstract_declarator

  163  direct_abstract_declarator : '(' abstract_declarator ')'
  164                             | '[' ']'
  165                             | '[' constant_exp ']'
  166                             | direct_abstract_declarator '[' ']'
  167                             | direct_abstract_declarator '[' constant_exp ']'
  168                             | '(' ')'
  169                             | '(' parameter_type_list ')'
  170                             | direct_abstract_declarator '(' ')'
  171                             | direct_abstract_declarator '(' parameter_type_list ')'

  172  initializer : assignment_exp
  173              | '{' initializer_list '}'
  174              | '{' initializer_list ',' '}'

  175  initializer_list : initializer
  176                   | initializer_list ',' initializer

  177  other : labeled_statement
  178        | compound_statement
  179        | exp_statement
  180        | iteration_statement
  181        | jump_statement

  182  statement : labeled_statement
  183            | compound_statement
  184            | exp_statement
  185            | selection_statement
  186            | iteration_statement
  187            | jump_statement

  188  labeled_statement : ID ':' statement
  189                    | CASE constant_exp ':' statement
  190                    | DEFAULT ':' statement

  191  compound_statement : '{' '}'
  192                     | '{' statement_list '}'
  193                     | '{' declaration_list '}'
  194                     | '{' declaration_list statement_list '}'

  195  declaration_list : declaration
  196                   | declaration_list declaration

  197  statement_list : statement
  198                 | statement_list statement

  199  exp_statement : ';'
  200                | exp ';'

  201  stmt : matched_statement
  202       | open_statement

  203  matched_statement : IF '(' exp ')' matched_statement ELSE matched_statement
  204                    | other

  205  open_statement : IF '(' exp ')' stmt
  206                 | IF '(' exp ')' matched_statement ELSE open_statement

  207  selection_statement : stmt
  208                      | SWITCH '(' exp ')' statement

  209  iteration_statement : WHILE '(' exp ')' statement
  210                      | DO statement WHILE '(' exp ')' ';'
  211                      | FOR '(' exp_statement exp_statement ')' statement
  212                      | FOR '(' exp_statement exp_statement exp ')' statement

  213  jump_statement : GOTO ID ';'
  214                 | CONTINUE ';'
  215                 | BREAK ';'
  216                 | RETURN ';'
  217                 | RETURN exp ';'

  218  translation_unit : external_declaration
  219                   | translation_unit external_declaration

  220  external_declaration : function_definition
  221                       | declaration

  222  function_definition : declaration_specifiers declarator declaration_list compound_statement
  223                      | declaration_specifiers declarator compound_statement
  224                      | declarator declaration_list compound_statement
  225                      | declarator compound_statement


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

	function_definition  goto 24
	declarator  goto 25
	enum_specifier  goto 26
	pointer  goto 27
	direct_declarator  goto 28
	translation_unit  goto 29
	external_declaration  goto 30
	type_qualifier  goto 31
	declaration  goto 32
	declaration_specifiers  goto 33
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 38
	pointer  goto 27
	direct_declarator  goto 28


2: shift-reduce conflict (shift 2, reduce 143) on '*'
2: shift-reduce conflict (shift 18, reduce 143) on CONST
2: shift-reduce conflict (shift 19, reduce 143) on VOLATILE
state 2
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' .  (143)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 143

	pointer  goto 39
	type_qualifier_list  goto 40
	type_qualifier  goto 41


state 3
	direct_declarator : ID .  (136)

	.  reduce 136


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
	type_qualifier : CONST .  (132)

	.  reduce 132


state 19
	type_qualifier : VOLATILE .  (133)

	.  reduce 133


state 20
	type_specifier : VOID .  (92)

	.  reduce 92


state 21
	struct_or_union : STRUCT .  (110)

	.  reduce 110


state 22
	struct_or_union : UNION .  (111)

	.  reduce 111


state 23
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . ID

	'{'  shift 42
	ID  shift 43


state 24
	external_declaration : function_definition .  (220)

	.  reduce 220


state 25
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

	'{'  shift 44
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

	enum_specifier  goto 26
	compound_statement  goto 45
	declaration_list  goto 46
	type_qualifier  goto 31
	declaration  goto 47
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 26
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 27
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 49


state 28
	declarator : direct_declarator .  (135)
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 50
	'['  shift 51
	.  reduce 135


state 29
	translation_unit : translation_unit . external_declaration
	$accept : translation_unit . $end  (0)

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

	function_definition  goto 24
	declarator  goto 25
	enum_specifier  goto 26
	pointer  goto 27
	direct_declarator  goto 28
	external_declaration  goto 52
	type_qualifier  goto 31
	declaration  goto 32
	declaration_specifiers  goto 33
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 30
	translation_unit : external_declaration .  (218)

	.  reduce 218


state 31
	declaration_specifiers : type_qualifier . declaration_specifiers
	declaration_specifiers : type_qualifier .  (81)

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

	enum_specifier  goto 26
	type_qualifier  goto 31
	declaration_specifiers  goto 53
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 32
	external_declaration : declaration .  (221)

	.  reduce 221


state 33
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'
	function_definition : declaration_specifiers . declarator compound_statement
	function_definition : declaration_specifiers . declarator declaration_list compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 54
	ID  shift 3

	declarator  goto 55
	pointer  goto 27
	direct_declarator  goto 28
	init_declarator_list  goto 56
	init_declarator  goto 57


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

	enum_specifier  goto 26
	type_qualifier  goto 31
	declaration_specifiers  goto 58
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


35: shift-reduce conflict (shift 2, reduce 79) on '*'
state 35
	declaration_specifiers : type_specifier .  (79)
	declaration_specifiers : type_specifier . declaration_specifiers
	type_specifier : type_specifier . pointer

	'*'  shift 2
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

	enum_specifier  goto 26
	pointer  goto 59
	type_qualifier  goto 31
	declaration_specifiers  goto 60
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 36
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 37
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_specifier : struct_or_union . ID '{' declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union . '{' declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union . ID '{' declaration_list '}' ';'
	struct_or_union_specifier : struct_or_union . '{' declaration_list '}' ';'

	'{'  shift 61
	ID  shift 62


state 38
	direct_declarator : '(' declarator . ')'

	')'  shift 63


state 39
	pointer : '*' pointer .  (145)

	.  reduce 145


40: shift-reduce conflict (shift 2, reduce 144) on '*'
40: shift-reduce conflict (shift 18, reduce 144) on CONST
40: shift-reduce conflict (shift 19, reduce 144) on VOLATILE
state 40
	pointer : '*' type_qualifier_list . pointer
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list .  (144)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 144

	pointer  goto 64
	type_qualifier  goto 65


state 41
	type_qualifier_list : type_qualifier .  (147)

	.  reduce 147


state 42
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 66

	enumerator_list  goto 67
	enumerator  goto 68


state 43
	enum_specifier : ENUM ID . '{' enumerator_list '}'
	enum_specifier : ENUM ID .  (127)

	'{'  shift 69
	.  reduce 127


state 44
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list statement_list '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	enum_specifier  goto 26
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	declaration_list  goto 114
	statement_list  goto 115
	jump_statement  goto 116
	statement  goto 117
	type_qualifier  goto 31
	labeled_statement  goto 118
	exp  goto 119
	declaration  goto 47
	and_exp  goto 120
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 45
	function_definition : declarator compound_statement .  (225)

	.  reduce 225


state 46
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

	'{'  shift 44
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

	enum_specifier  goto 26
	compound_statement  goto 127
	type_qualifier  goto 31
	declaration  goto 128
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 47
	declaration_list : declaration .  (195)

	.  reduce 195


state 48
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 54
	ID  shift 3

	declarator  goto 129
	pointer  goto 27
	direct_declarator  goto 28
	init_declarator_list  goto 56
	init_declarator  goto 57


state 49
	declarator : pointer direct_declarator .  (134)
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 50
	'['  shift 51
	.  reduce 134


state 50
	direct_declarator : direct_declarator '(' . ')'
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'

	')'  shift 130
	ID  shift 131
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

	parameter_list  goto 132
	parameter_declaration  goto 133
	enum_specifier  goto 26
	parameter_type_list  goto 134
	identifier_list  goto 135
	type_qualifier  goto 31
	declaration_specifiers  goto 136
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 51
	direct_declarator : direct_declarator '[' . constant_exp ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	']'  shift 137
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	constant_exp  goto 140
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 141


state 52
	translation_unit : translation_unit external_declaration .  (219)

	.  reduce 219


state 53
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 54
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 55
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . compound_statement
	function_definition : declaration_specifiers declarator . declaration_list compound_statement

	'='  shift 142
	'{'  shift 44
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

	enum_specifier  goto 26
	compound_statement  goto 143
	declaration_list  goto 144
	type_qualifier  goto 31
	declaration  goto 47
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 56
	init_declarator_list : init_declarator_list . ',' init_declarator
	declaration : declaration_specifiers init_declarator_list . ';'

	','  shift 145
	';'  shift 146


state 57
	init_declarator_list : init_declarator .  (83)

	.  reduce 83


state 58
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 59
	type_specifier : type_specifier pointer .  (104)

	.  reduce 104


state 60
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 61
	struct_or_union_specifier : struct_or_union '{' . declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union '{' . declaration_list '}' ';'

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

	enum_specifier  goto 26
	declaration_list  goto 147
	type_qualifier  goto 31
	declaration  goto 47
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 62
	struct_or_union_specifier : struct_or_union ID .  (109)
	struct_or_union_specifier : struct_or_union ID . '{' declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID . '{' declaration_list '}' ';'

	'{'  shift 148
	.  reduce 109


state 63
	direct_declarator : '(' declarator ')' .  (137)

	.  reduce 137


state 64
	pointer : '*' type_qualifier_list pointer .  (146)

	.  reduce 146


state 65
	type_qualifier_list : type_qualifier_list type_qualifier .  (148)

	.  reduce 148


state 66
	enumerator : ID . '=' constant_exp
	enumerator : ID .  (130)

	'='  shift 149
	.  reduce 130


state 67
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 150
	'}'  shift 151


state 68
	enumerator_list : enumerator .  (128)

	.  reduce 128


state 69
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 66

	enumerator_list  goto 152
	enumerator  goto 68


state 70
	unary_operator : '!' .  (26)

	.  reduce 26


state 71
	unary_operator : '&' .  (21)

	.  reduce 21


state 72
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
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

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	enum_specifier  goto 26
	specifier_qualifier_list  goto 153
	type_name  goto 154
	type_qualifier  goto 155
	exp  goto 156
	and_exp  goto 120
	type_specifier  goto 157
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


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
	exp_statement : ';' .  (199)

	.  reduce 199


state 77
	compound_statement : '{' '}' .  (191)

	.  reduce 191


state 78
	unary_operator : '~' .  (25)

	.  reduce 25


state 79
	labeled_statement : ID . ':' statement
	primary_exp : ID .  (1)

	':'  shift 158
	.  reduce 1


state 80
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 81
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 82
	unary_exp : SIZEOF . '(' type_name ')'
	unary_exp : SIZEOF . unary_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 159
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 160


state 83
	unary_exp : INC_OP . unary_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 161
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 162


state 84
	unary_exp : DEC_OP . unary_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 161
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 163


state 85
	labeled_statement : CASE . constant_exp ':' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	constant_exp  goto 164
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 141


state 86
	labeled_statement : DEFAULT . ':' statement

	':'  shift 165


state 87
	open_statement : IF . '(' exp ')' stmt
	matched_statement : IF . '(' exp ')' matched_statement ELSE matched_statement
	open_statement : IF . '(' exp ')' matched_statement ELSE open_statement

	'('  shift 166


state 88
	selection_statement : SWITCH . '(' exp ')' statement

	'('  shift 167


state 89
	iteration_statement : WHILE . '(' exp ')' statement

	'('  shift 168


state 90
	iteration_statement : DO . statement WHILE '(' exp ')' ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 169
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 91
	iteration_statement : FOR . '(' exp_statement exp_statement ')' statement
	iteration_statement : FOR . '(' exp_statement exp_statement exp ')' statement

	'('  shift 170


state 92
	jump_statement : GOTO . ID ';'

	ID  shift 171


state 93
	jump_statement : CONTINUE . ';'

	';'  shift 172


state 94
	jump_statement : BREAK . ';'

	';'  shift 173


state 95
	jump_statement : RETURN . ';'
	jump_statement : RETURN . exp ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 174
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 175
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 96
	statement : selection_statement .  (185)

	.  reduce 185


state 97
	stmt : open_statement .  (202)

	.  reduce 202


state 98
	matched_statement : other .  (204)

	.  reduce 204


state 99
	stmt : matched_statement .  (201)

	.  reduce 201


state 100
	selection_statement : stmt .  (207)

	.  reduce 207


state 101
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	equality_exp : relational_exp .  (44)

	'<'  shift 176
	'>'  shift 177
	LE_OP  shift 178
	GE_OP  shift 179
	.  reduce 44


state 102
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : equality_exp .  (47)
	equality_exp : equality_exp . NE_OP relational_exp

	EQ_OP  shift 180
	NE_OP  shift 181
	.  reduce 47


state 103
	unary_exp : unary_operator . cast_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 182
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 104
	multiplicative_exp : cast_exp .  (29)

	.  reduce 29


state 105
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : multiplicative_exp .  (33)
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 183
	'*'  shift 184
	'/'  shift 185
	.  reduce 33


state 106
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : additive_exp .  (36)

	'+'  shift 186
	'-'  shift 187
	.  reduce 36


state 107
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '(' ')'
	postfix_exp : postfix_exp . '(' argument_exp_list ')'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (15)

	'('  shift 188
	'.'  shift 189
	'['  shift 190
	PTR_OP  shift 191
	INC_OP  shift 192
	DEC_OP  shift 193
	.  reduce 15


state 108
	postfix_exp : primary_exp .  (5)

	.  reduce 5


state 109
	cast_exp : unary_exp .  (27)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 194
	MUL_ASSIGN  shift 195
	DIV_ASSIGN  shift 196
	MOD_ASSIGN  shift 197
	ADD_ASSIGN  shift 198
	SUB_ASSIGN  shift 199
	LEFT_ASSIGN  shift 200
	RIGHT_ASSIGN  shift 201
	AND_ASSIGN  shift 202
	XOR_ASSIGN  shift 203
	OR_ASSIGN  shift 204
	.  reduce 27

	assignment_operator  goto 205


state 110
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : shift_exp .  (39)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 39


111: reduce-reduce conflict (reduce 179, reduce 184) on '!'
111: reduce-reduce conflict (reduce 179, reduce 184) on '&'
111: reduce-reduce conflict (reduce 179, reduce 184) on '('
111: reduce-reduce conflict (reduce 179, reduce 184) on '*'
111: reduce-reduce conflict (reduce 179, reduce 184) on '+'
111: reduce-reduce conflict (reduce 179, reduce 184) on '-'
111: reduce-reduce conflict (reduce 179, reduce 184) on ';'
111: reduce-reduce conflict (reduce 179, reduce 184) on '{'
111: reduce-reduce conflict (reduce 179, reduce 184) on '}'
111: reduce-reduce conflict (reduce 179, reduce 184) on '~'
111: reduce-reduce conflict (reduce 179, reduce 184) on ID
111: reduce-reduce conflict (reduce 179, reduce 184) on CONSTANT
111: reduce-reduce conflict (reduce 179, reduce 184) on STRING_LITERAL
111: reduce-reduce conflict (reduce 179, reduce 184) on SIZEOF
111: reduce-reduce conflict (reduce 179, reduce 184) on INC_OP
111: reduce-reduce conflict (reduce 179, reduce 184) on DEC_OP
111: reduce-reduce conflict (reduce 179, reduce 184) on CASE
111: reduce-reduce conflict (reduce 179, reduce 184) on DEFAULT
111: reduce-reduce conflict (reduce 179, reduce 184) on IF
111: reduce-reduce conflict (reduce 179, reduce 184) on ELSE
111: reduce-reduce conflict (reduce 179, reduce 184) on SWITCH
111: reduce-reduce conflict (reduce 179, reduce 184) on WHILE
111: reduce-reduce conflict (reduce 179, reduce 184) on DO
111: reduce-reduce conflict (reduce 179, reduce 184) on FOR
111: reduce-reduce conflict (reduce 179, reduce 184) on GOTO
111: reduce-reduce conflict (reduce 179, reduce 184) on CONTINUE
111: reduce-reduce conflict (reduce 179, reduce 184) on BREAK
111: reduce-reduce conflict (reduce 179, reduce 184) on RETURN
state 111
	other : exp_statement .  (179)
	statement : exp_statement .  (184)

	.  reduce 179


112: reduce-reduce conflict (reduce 178, reduce 183) on '!'
112: reduce-reduce conflict (reduce 178, reduce 183) on '&'
112: reduce-reduce conflict (reduce 178, reduce 183) on '('
112: reduce-reduce conflict (reduce 178, reduce 183) on '*'
112: reduce-reduce conflict (reduce 178, reduce 183) on '+'
112: reduce-reduce conflict (reduce 178, reduce 183) on '-'
112: reduce-reduce conflict (reduce 178, reduce 183) on ';'
112: reduce-reduce conflict (reduce 178, reduce 183) on '{'
112: reduce-reduce conflict (reduce 178, reduce 183) on '}'
112: reduce-reduce conflict (reduce 178, reduce 183) on '~'
112: reduce-reduce conflict (reduce 178, reduce 183) on ID
112: reduce-reduce conflict (reduce 178, reduce 183) on CONSTANT
112: reduce-reduce conflict (reduce 178, reduce 183) on STRING_LITERAL
112: reduce-reduce conflict (reduce 178, reduce 183) on SIZEOF
112: reduce-reduce conflict (reduce 178, reduce 183) on INC_OP
112: reduce-reduce conflict (reduce 178, reduce 183) on DEC_OP
112: reduce-reduce conflict (reduce 178, reduce 183) on CASE
112: reduce-reduce conflict (reduce 178, reduce 183) on DEFAULT
112: reduce-reduce conflict (reduce 178, reduce 183) on IF
112: reduce-reduce conflict (reduce 178, reduce 183) on ELSE
112: reduce-reduce conflict (reduce 178, reduce 183) on SWITCH
112: reduce-reduce conflict (reduce 178, reduce 183) on WHILE
112: reduce-reduce conflict (reduce 178, reduce 183) on DO
112: reduce-reduce conflict (reduce 178, reduce 183) on FOR
112: reduce-reduce conflict (reduce 178, reduce 183) on GOTO
112: reduce-reduce conflict (reduce 178, reduce 183) on CONTINUE
112: reduce-reduce conflict (reduce 178, reduce 183) on BREAK
112: reduce-reduce conflict (reduce 178, reduce 183) on RETURN
state 112
	statement : compound_statement .  (183)
	other : compound_statement .  (178)

	.  reduce 178


113: reduce-reduce conflict (reduce 180, reduce 186) on '!'
113: reduce-reduce conflict (reduce 180, reduce 186) on '&'
113: reduce-reduce conflict (reduce 180, reduce 186) on '('
113: reduce-reduce conflict (reduce 180, reduce 186) on '*'
113: reduce-reduce conflict (reduce 180, reduce 186) on '+'
113: reduce-reduce conflict (reduce 180, reduce 186) on '-'
113: reduce-reduce conflict (reduce 180, reduce 186) on ';'
113: reduce-reduce conflict (reduce 180, reduce 186) on '{'
113: reduce-reduce conflict (reduce 180, reduce 186) on '}'
113: reduce-reduce conflict (reduce 180, reduce 186) on '~'
113: reduce-reduce conflict (reduce 180, reduce 186) on ID
113: reduce-reduce conflict (reduce 180, reduce 186) on CONSTANT
113: reduce-reduce conflict (reduce 180, reduce 186) on STRING_LITERAL
113: reduce-reduce conflict (reduce 180, reduce 186) on SIZEOF
113: reduce-reduce conflict (reduce 180, reduce 186) on INC_OP
113: reduce-reduce conflict (reduce 180, reduce 186) on DEC_OP
113: reduce-reduce conflict (reduce 180, reduce 186) on CASE
113: reduce-reduce conflict (reduce 180, reduce 186) on DEFAULT
113: reduce-reduce conflict (reduce 180, reduce 186) on IF
113: reduce-reduce conflict (reduce 180, reduce 186) on ELSE
113: reduce-reduce conflict (reduce 180, reduce 186) on SWITCH
113: reduce-reduce conflict (reduce 180, reduce 186) on WHILE
113: reduce-reduce conflict (reduce 180, reduce 186) on DO
113: reduce-reduce conflict (reduce 180, reduce 186) on FOR
113: reduce-reduce conflict (reduce 180, reduce 186) on GOTO
113: reduce-reduce conflict (reduce 180, reduce 186) on CONTINUE
113: reduce-reduce conflict (reduce 180, reduce 186) on BREAK
113: reduce-reduce conflict (reduce 180, reduce 186) on RETURN
state 113
	statement : iteration_statement .  (186)
	other : iteration_statement .  (180)

	.  reduce 180


state 114
	compound_statement : '{' declaration_list . '}'
	compound_statement : '{' declaration_list . statement_list '}'
	declaration_list : declaration_list . declaration

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	enum_specifier  goto 26
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	statement_list  goto 209
	jump_statement  goto 116
	statement  goto 117
	type_qualifier  goto 31
	labeled_statement  goto 118
	exp  goto 119
	declaration  goto 128
	and_exp  goto 120
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 115
	statement_list : statement_list . statement
	compound_statement : '{' statement_list . '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 211
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


116: reduce-reduce conflict (reduce 181, reduce 187) on '!'
116: reduce-reduce conflict (reduce 181, reduce 187) on '&'
116: reduce-reduce conflict (reduce 181, reduce 187) on '('
116: reduce-reduce conflict (reduce 181, reduce 187) on '*'
116: reduce-reduce conflict (reduce 181, reduce 187) on '+'
116: reduce-reduce conflict (reduce 181, reduce 187) on '-'
116: reduce-reduce conflict (reduce 181, reduce 187) on ';'
116: reduce-reduce conflict (reduce 181, reduce 187) on '{'
116: reduce-reduce conflict (reduce 181, reduce 187) on '}'
116: reduce-reduce conflict (reduce 181, reduce 187) on '~'
116: reduce-reduce conflict (reduce 181, reduce 187) on ID
116: reduce-reduce conflict (reduce 181, reduce 187) on CONSTANT
116: reduce-reduce conflict (reduce 181, reduce 187) on STRING_LITERAL
116: reduce-reduce conflict (reduce 181, reduce 187) on SIZEOF
116: reduce-reduce conflict (reduce 181, reduce 187) on INC_OP
116: reduce-reduce conflict (reduce 181, reduce 187) on DEC_OP
116: reduce-reduce conflict (reduce 181, reduce 187) on CASE
116: reduce-reduce conflict (reduce 181, reduce 187) on DEFAULT
116: reduce-reduce conflict (reduce 181, reduce 187) on IF
116: reduce-reduce conflict (reduce 181, reduce 187) on ELSE
116: reduce-reduce conflict (reduce 181, reduce 187) on SWITCH
116: reduce-reduce conflict (reduce 181, reduce 187) on WHILE
116: reduce-reduce conflict (reduce 181, reduce 187) on DO
116: reduce-reduce conflict (reduce 181, reduce 187) on FOR
116: reduce-reduce conflict (reduce 181, reduce 187) on GOTO
116: reduce-reduce conflict (reduce 181, reduce 187) on CONTINUE
116: reduce-reduce conflict (reduce 181, reduce 187) on BREAK
116: reduce-reduce conflict (reduce 181, reduce 187) on RETURN
state 116
	statement : jump_statement .  (187)
	other : jump_statement .  (181)

	.  reduce 181


state 117
	statement_list : statement .  (197)

	.  reduce 197


118: reduce-reduce conflict (reduce 177, reduce 182) on '!'
118: reduce-reduce conflict (reduce 177, reduce 182) on '&'
118: reduce-reduce conflict (reduce 177, reduce 182) on '('
118: reduce-reduce conflict (reduce 177, reduce 182) on '*'
118: reduce-reduce conflict (reduce 177, reduce 182) on '+'
118: reduce-reduce conflict (reduce 177, reduce 182) on '-'
118: reduce-reduce conflict (reduce 177, reduce 182) on ';'
118: reduce-reduce conflict (reduce 177, reduce 182) on '{'
118: reduce-reduce conflict (reduce 177, reduce 182) on '}'
118: reduce-reduce conflict (reduce 177, reduce 182) on '~'
118: reduce-reduce conflict (reduce 177, reduce 182) on ID
118: reduce-reduce conflict (reduce 177, reduce 182) on CONSTANT
118: reduce-reduce conflict (reduce 177, reduce 182) on STRING_LITERAL
118: reduce-reduce conflict (reduce 177, reduce 182) on SIZEOF
118: reduce-reduce conflict (reduce 177, reduce 182) on INC_OP
118: reduce-reduce conflict (reduce 177, reduce 182) on DEC_OP
118: reduce-reduce conflict (reduce 177, reduce 182) on CASE
118: reduce-reduce conflict (reduce 177, reduce 182) on DEFAULT
118: reduce-reduce conflict (reduce 177, reduce 182) on IF
118: reduce-reduce conflict (reduce 177, reduce 182) on ELSE
118: reduce-reduce conflict (reduce 177, reduce 182) on SWITCH
118: reduce-reduce conflict (reduce 177, reduce 182) on WHILE
118: reduce-reduce conflict (reduce 177, reduce 182) on DO
118: reduce-reduce conflict (reduce 177, reduce 182) on FOR
118: reduce-reduce conflict (reduce 177, reduce 182) on GOTO
118: reduce-reduce conflict (reduce 177, reduce 182) on CONTINUE
118: reduce-reduce conflict (reduce 177, reduce 182) on BREAK
118: reduce-reduce conflict (reduce 177, reduce 182) on RETURN
state 118
	other : labeled_statement .  (177)
	statement : labeled_statement .  (182)

	.  reduce 177


state 119
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 212
	';'  shift 213


state 120
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : and_exp .  (49)

	'&'  shift 214
	.  reduce 49


state 121
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : exclusive_or_exp .  (51)

	'^'  shift 215
	.  reduce 51


state 122
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp
	logical_or_exp : logical_and_exp .  (55)

	AND_OP  shift 216
	.  reduce 55


state 123
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : inclusive_or_exp .  (53)

	'|'  shift 217
	.  reduce 53


state 124
	conditional_exp : logical_or_exp .  (57)
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp
	logical_or_exp : logical_or_exp . OR_OP logical_and_exp

	'?'  shift 218
	OR_OP  shift 219
	.  reduce 57


state 125
	assignment_exp : conditional_exp .  (59)

	.  reduce 59


state 126
	exp : assignment_exp .  (72)

	.  reduce 72


state 127
	function_definition : declarator declaration_list compound_statement .  (224)

	.  reduce 224


state 128
	declaration_list : declaration_list declaration .  (196)

	.  reduce 196


state 129
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer

	'='  shift 142
	.  reduce 85


state 130
	direct_declarator : direct_declarator '(' ')' .  (142)

	.  reduce 142


state 131
	identifier_list : ID .  (156)

	.  reduce 156


state 132
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_type_list : parameter_list .  (149)
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 220
	.  reduce 149


state 133
	parameter_list : parameter_declaration .  (151)

	.  reduce 151


state 134
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 221


state 135
	identifier_list : identifier_list . ',' ID
	direct_declarator : direct_declarator '(' identifier_list . ')'

	')'  shift 222
	','  shift 223


state 136
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers .  (155)
	parameter_declaration : declaration_specifiers . abstract_declarator

	'('  shift 224
	'*'  shift 2
	'['  shift 225
	ID  shift 3
	.  reduce 155

	declarator  goto 226
	direct_abstract_declarator  goto 227
	pointer  goto 228
	direct_declarator  goto 28
	abstract_declarator  goto 229


state 137
	direct_declarator : direct_declarator '[' ']' .  (139)

	.  reduce 139


state 138
	primary_exp : ID .  (1)

	.  reduce 1


state 139
	cast_exp : unary_exp .  (27)

	.  reduce 27


state 140
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 230


state 141
	constant_exp : conditional_exp .  (74)

	.  reduce 74


state 142
	init_declarator : declarator '=' . initializer

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 231
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	initializer  goto 232
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 233


state 143
	function_definition : declaration_specifiers declarator compound_statement .  (223)

	.  reduce 223


state 144
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

	'{'  shift 44
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

	enum_specifier  goto 26
	compound_statement  goto 234
	type_qualifier  goto 31
	declaration  goto 128
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 145
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 129
	pointer  goto 27
	direct_declarator  goto 28
	init_declarator  goto 235


state 146
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 147
	struct_or_union_specifier : struct_or_union '{' declaration_list . '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union '{' declaration_list . '}' ';'
	declaration_list : declaration_list . declaration

	'}'  shift 236
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

	enum_specifier  goto 26
	type_qualifier  goto 31
	declaration  goto 128
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 148
	struct_or_union_specifier : struct_or_union ID '{' . declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID '{' . declaration_list '}' ';'

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

	enum_specifier  goto 26
	declaration_list  goto 237
	type_qualifier  goto 31
	declaration  goto 47
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 149
	enumerator : ID '=' . constant_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	constant_exp  goto 238
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 141


state 150
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 66

	enumerator  goto 239


state 151
	enum_specifier : ENUM '{' enumerator_list '}' .  (125)

	.  reduce 125


state 152
	enum_specifier : ENUM ID '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 150
	'}'  shift 240


state 153
	type_name : specifier_qualifier_list . abstract_declarator
	type_name : specifier_qualifier_list .  (158)

	'('  shift 241
	'*'  shift 2
	'['  shift 225
	.  reduce 158

	direct_abstract_declarator  goto 227
	pointer  goto 242
	abstract_declarator  goto 243


state 154
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 244


state 155
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

	enum_specifier  goto 26
	specifier_qualifier_list  goto 245
	type_qualifier  goto 155
	type_specifier  goto 157
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 156
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 246
	','  shift 212


157: shift-reduce conflict (shift 2, reduce 117) on '*'
state 157
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	type_specifier : type_specifier . pointer
	specifier_qualifier_list : type_specifier .  (117)

	'*'  shift 2
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

	enum_specifier  goto 26
	specifier_qualifier_list  goto 247
	pointer  goto 59
	type_qualifier  goto 155
	type_specifier  goto 157
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 158
	labeled_statement : ID ':' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 248
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 159
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
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

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	enum_specifier  goto 26
	specifier_qualifier_list  goto 153
	type_name  goto 249
	type_qualifier  goto 155
	exp  goto 156
	and_exp  goto 120
	type_specifier  goto 157
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 160
	unary_exp : SIZEOF unary_exp .  (19)

	.  reduce 19


state 161
	primary_exp : '(' . exp ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 156
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 162
	unary_exp : INC_OP unary_exp .  (16)

	.  reduce 16


state 163
	unary_exp : DEC_OP unary_exp .  (17)

	.  reduce 17


state 164
	labeled_statement : CASE constant_exp . ':' statement

	':'  shift 250


state 165
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 251
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 166
	open_statement : IF '(' . exp ')' stmt
	matched_statement : IF '(' . exp ')' matched_statement ELSE matched_statement
	open_statement : IF '(' . exp ')' matched_statement ELSE open_statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 252
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 167
	selection_statement : SWITCH '(' . exp ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 253
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 168
	iteration_statement : WHILE '(' . exp ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 254
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 169
	iteration_statement : DO statement . WHILE '(' exp ')' ';'

	WHILE  shift 255


state 170
	iteration_statement : FOR '(' . exp_statement exp_statement ')' statement
	iteration_statement : FOR '(' . exp_statement exp_statement exp ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 256
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 171
	jump_statement : GOTO ID . ';'

	';'  shift 257


state 172
	jump_statement : CONTINUE ';' .  (214)

	.  reduce 214


state 173
	jump_statement : BREAK ';' .  (215)

	.  reduce 215


state 174
	jump_statement : RETURN ';' .  (216)

	.  reduce 216


state 175
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 212
	';'  shift 258


state 176
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 259


state 177
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 260


state 178
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 261


state 179
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 262


state 180
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 263
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110


state 181
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 264
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110


state 182
	unary_exp : unary_operator cast_exp .  (18)

	.  reduce 18


state 183
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 265
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 184
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 266
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 185
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 267
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 186
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 268
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 187
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 269
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 188
	postfix_exp : postfix_exp '(' . ')'
	postfix_exp : postfix_exp '(' . argument_exp_list ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	')'  shift 270
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	argument_exp_list  goto 271
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 272


state 189
	postfix_exp : postfix_exp '.' . ID

	ID  shift 273


state 190
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 274
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 191
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 275


state 192
	postfix_exp : postfix_exp INC_OP .  (11)

	.  reduce 11


state 193
	postfix_exp : postfix_exp DEC_OP .  (12)

	.  reduce 12


state 194
	assignment_operator : '=' .  (61)

	.  reduce 61


state 195
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 196
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 197
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 198
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 199
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 200
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 201
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 202
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 203
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 204
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 205
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 276


state 206
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 277
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 207
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 278
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 208
	compound_statement : '{' declaration_list '}' .  (193)

	.  reduce 193


state 209
	statement_list : statement_list . statement
	compound_statement : '{' declaration_list statement_list . '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'}'  shift 279
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 211
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 210
	compound_statement : '{' statement_list '}' .  (192)

	.  reduce 192


state 211
	statement_list : statement_list statement .  (198)

	.  reduce 198


state 212
	exp : exp ',' . assignment_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 280


state 213
	exp_statement : exp ';' .  (200)

	.  reduce 200


state 214
	and_exp : and_exp '&' . equality_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 281
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110


state 215
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 282


state 216
	logical_and_exp : logical_and_exp AND_OP . inclusive_or_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 121
	inclusive_or_exp  goto 283


state 217
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 284


state 218
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 285
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 219
	logical_or_exp : logical_or_exp OR_OP . logical_and_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 286
	inclusive_or_exp  goto 123


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
	ELLIPSIS  shift 287

	parameter_declaration  goto 288
	enum_specifier  goto 26
	type_qualifier  goto 31
	declaration_specifiers  goto 136
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 221
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (140)

	.  reduce 140


state 222
	direct_declarator : direct_declarator '(' identifier_list ')' .  (141)

	.  reduce 141


state 223
	identifier_list : identifier_list ',' . ID

	ID  shift 289


state 224
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 224
	')'  shift 290
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

	declarator  goto 38
	parameter_list  goto 132
	parameter_declaration  goto 133
	direct_abstract_declarator  goto 227
	enum_specifier  goto 26
	parameter_type_list  goto 291
	pointer  goto 228
	direct_declarator  goto 28
	abstract_declarator  goto 292
	type_qualifier  goto 31
	declaration_specifiers  goto 136
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 225
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	']'  shift 293
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	constant_exp  goto 294
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 141


state 226
	parameter_declaration : declaration_specifiers declarator .  (153)

	.  reduce 153


state 227
	abstract_declarator : direct_abstract_declarator .  (161)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 295
	'['  shift 296
	.  reduce 161


state 228
	declarator : pointer . direct_declarator
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (160)

	'('  shift 224
	'['  shift 225
	ID  shift 3
	.  reduce 160

	direct_abstract_declarator  goto 297
	direct_declarator  goto 49


state 229
	parameter_declaration : declaration_specifiers abstract_declarator .  (154)

	.  reduce 154


state 230
	direct_declarator : direct_declarator '[' constant_exp ']' .  (138)

	.  reduce 138


state 231
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 231
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	initializer_list  goto 298
	initializer  goto 299
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 233


state 232
	init_declarator : declarator '=' initializer .  (86)

	.  reduce 86


state 233
	initializer : assignment_exp .  (172)

	.  reduce 172


state 234
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (222)

	.  reduce 222


state 235
	init_declarator_list : init_declarator_list ',' init_declarator .  (84)

	.  reduce 84


state 236
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' . init_declarator_list ';'
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 300
	ID  shift 3

	declarator  goto 129
	pointer  goto 27
	direct_declarator  goto 28
	init_declarator_list  goto 301
	init_declarator  goto 57


state 237
	struct_or_union_specifier : struct_or_union ID '{' declaration_list . '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID '{' declaration_list . '}' ';'
	declaration_list : declaration_list . declaration

	'}'  shift 302
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

	enum_specifier  goto 26
	type_qualifier  goto 31
	declaration  goto 128
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 238
	enumerator : ID '=' constant_exp .  (131)

	.  reduce 131


state 239
	enumerator_list : enumerator_list ',' enumerator .  (129)

	.  reduce 129


state 240
	enum_specifier : ENUM ID '{' enumerator_list '}' .  (126)

	.  reduce 126


state 241
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 241
	')'  shift 290
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

	parameter_list  goto 132
	parameter_declaration  goto 133
	direct_abstract_declarator  goto 227
	enum_specifier  goto 26
	parameter_type_list  goto 291
	pointer  goto 242
	abstract_declarator  goto 292
	type_qualifier  goto 31
	declaration_specifiers  goto 136
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 242
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (160)

	'('  shift 241
	'['  shift 225
	.  reduce 160

	direct_abstract_declarator  goto 297


state 243
	type_name : specifier_qualifier_list abstract_declarator .  (159)

	.  reduce 159


state 244
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	unary_operator  goto 103
	cast_exp  goto 303
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139


state 245
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (118)

	.  reduce 118


state 246
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 247
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (116)

	.  reduce 116


state 248
	labeled_statement : ID ':' statement .  (188)

	.  reduce 188


state 249
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 304


state 250
	labeled_statement : CASE constant_exp ':' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 305
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 251
	labeled_statement : DEFAULT ':' statement .  (190)

	.  reduce 190


state 252
	exp : exp . ',' assignment_exp
	open_statement : IF '(' exp . ')' stmt
	matched_statement : IF '(' exp . ')' matched_statement ELSE matched_statement
	open_statement : IF '(' exp . ')' matched_statement ELSE open_statement

	')'  shift 306
	','  shift 212


state 253
	exp : exp . ',' assignment_exp
	selection_statement : SWITCH '(' exp . ')' statement

	')'  shift 307
	','  shift 212


state 254
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE '(' exp . ')' statement

	')'  shift 308
	','  shift 212


state 255
	iteration_statement : DO statement WHILE . '(' exp ')' ';'

	'('  shift 309


state 256
	iteration_statement : FOR '(' exp_statement . exp_statement ')' statement
	iteration_statement : FOR '(' exp_statement . exp_statement exp ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 310
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 257
	jump_statement : GOTO ID ';' .  (213)

	.  reduce 213


state 258
	jump_statement : RETURN exp ';' .  (217)

	.  reduce 217


state 259
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '<' shift_exp .  (40)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 40


state 260
	relational_exp : relational_exp '>' shift_exp .  (41)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 41


state 261
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (42)

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 42


state 262
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp GE_OP shift_exp .  (43)

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 43


state 263
	equality_exp : equality_exp EQ_OP relational_exp .  (45)
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 176
	'>'  shift 177
	LE_OP  shift 178
	GE_OP  shift 179
	.  reduce 45


state 264
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (46)

	'<'  shift 176
	'>'  shift 177
	LE_OP  shift 178
	GE_OP  shift 179
	.  reduce 46


state 265
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (32)

	.  reduce 32


state 266
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (30)

	.  reduce 30


state 267
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (31)

	.  reduce 31


state 268
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (34)

	'%'  shift 183
	'*'  shift 184
	'/'  shift 185
	.  reduce 34


state 269
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (35)

	'%'  shift 183
	'*'  shift 184
	'/'  shift 185
	.  reduce 35


state 270
	postfix_exp : postfix_exp '(' ')' .  (7)

	.  reduce 7


state 271
	postfix_exp : postfix_exp '(' argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 311
	','  shift 312


state 272
	argument_exp_list : assignment_exp .  (13)

	.  reduce 13


state 273
	postfix_exp : postfix_exp '.' ID .  (9)

	.  reduce 9


state 274
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 212
	']'  shift 313


state 275
	postfix_exp : postfix_exp PTR_OP ID .  (10)

	.  reduce 10


state 276
	assignment_exp : unary_exp assignment_operator assignment_exp .  (60)

	.  reduce 60


state 277
	additive_exp : additive_exp . '-' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (37)
	additive_exp : additive_exp . '+' multiplicative_exp

	'+'  shift 186
	'-'  shift 187
	.  reduce 37


state 278
	additive_exp : additive_exp . '-' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (38)
	additive_exp : additive_exp . '+' multiplicative_exp

	'+'  shift 186
	'-'  shift 187
	.  reduce 38


state 279
	compound_statement : '{' declaration_list statement_list '}' .  (194)

	.  reduce 194


state 280
	exp : exp ',' assignment_exp .  (73)

	.  reduce 73


state 281
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : and_exp '&' equality_exp .  (48)
	equality_exp : equality_exp . NE_OP relational_exp

	EQ_OP  shift 180
	NE_OP  shift 181
	.  reduce 48


state 282
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (50)
	and_exp : and_exp . '&' equality_exp

	'&'  shift 214
	.  reduce 50


state 283
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : logical_and_exp AND_OP inclusive_or_exp .  (54)

	'|'  shift 217
	.  reduce 54


state 284
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (52)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 215
	.  reduce 52


state 285
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 212
	':'  shift 314


state 286
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp
	logical_or_exp : logical_or_exp OR_OP logical_and_exp .  (56)

	AND_OP  shift 216
	.  reduce 56


state 287
	parameter_type_list : parameter_list ',' ELLIPSIS .  (150)

	.  reduce 150


state 288
	parameter_list : parameter_list ',' parameter_declaration .  (152)

	.  reduce 152


state 289
	identifier_list : identifier_list ',' ID .  (157)

	.  reduce 157


state 290
	direct_abstract_declarator : '(' ')' .  (168)

	.  reduce 168


state 291
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 315


state 292
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 316


state 293
	direct_abstract_declarator : '[' ']' .  (164)

	.  reduce 164


state 294
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 317


state 295
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

	')'  shift 318
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

	parameter_list  goto 132
	parameter_declaration  goto 133
	enum_specifier  goto 26
	parameter_type_list  goto 319
	type_qualifier  goto 31
	declaration_specifiers  goto 136
	storage_class_specifier  goto 34
	type_specifier  goto 35
	struct_or_union_specifier  goto 36
	struct_or_union  goto 37


state 296
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	']'  shift 320
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	constant_exp  goto 321
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 141


state 297
	abstract_declarator : pointer direct_abstract_declarator .  (162)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 295
	'['  shift 296
	.  reduce 162


state 298
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 322
	'}'  shift 323


state 299
	initializer_list : initializer .  (175)

	.  reduce 175


state 300
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' ';' .  (107)

	.  reduce 107


state 301
	init_declarator_list : init_declarator_list . ',' init_declarator
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' init_declarator_list . ';'

	','  shift 145
	';'  shift 324


state 302
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' . init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 325
	ID  shift 3

	declarator  goto 129
	pointer  goto 27
	direct_declarator  goto 28
	init_declarator_list  goto 326
	init_declarator  goto 57


state 303
	cast_exp : '(' type_name ')' cast_exp .  (28)

	.  reduce 28


state 304
	unary_exp : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 305
	labeled_statement : CASE constant_exp ':' statement .  (189)

	.  reduce 189


state 306
	open_statement : IF '(' exp ')' . stmt
	matched_statement : IF '(' exp ')' . matched_statement ELSE matched_statement
	open_statement : IF '(' exp ')' . matched_statement ELSE open_statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	open_statement  goto 97
	other  goto 98
	matched_statement  goto 327
	stmt  goto 328
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 329
	compound_statement  goto 330
	iteration_statement  goto 331
	jump_statement  goto 332
	labeled_statement  goto 333
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 307
	selection_statement : SWITCH '(' exp ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 334
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 308
	iteration_statement : WHILE '(' exp ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 335
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 309
	iteration_statement : DO statement WHILE '(' . exp ')' ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 336
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 310
	iteration_statement : FOR '(' exp_statement exp_statement . ')' statement
	iteration_statement : FOR '(' exp_statement exp_statement . exp ')' statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	')'  shift 337
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp  goto 338
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 311
	postfix_exp : postfix_exp '(' argument_exp_list ')' .  (8)

	.  reduce 8


state 312
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 339


state 313
	postfix_exp : postfix_exp '[' exp ']' .  (6)

	.  reduce 6


state 314
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 139
	shift_exp  goto 110
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 340


state 315
	direct_abstract_declarator : '(' parameter_type_list ')' .  (169)

	.  reduce 169


state 316
	direct_abstract_declarator : '(' abstract_declarator ')' .  (163)

	.  reduce 163


state 317
	direct_abstract_declarator : '[' constant_exp ']' .  (165)

	.  reduce 165


state 318
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (170)

	.  reduce 170


state 319
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 341


state 320
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (166)

	.  reduce 166


state 321
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp . ']'

	']'  shift 342


state 322
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 231
	'}'  shift 343
	'~'  shift 78
	ID  shift 138
	CONSTANT  shift 80
	STRING_LITERAL  shift 81
	SIZEOF  shift 82
	INC_OP  shift 83
	DEC_OP  shift 84

	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	initializer  goto 344
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 233


state 323
	initializer : '{' initializer_list '}' .  (173)

	.  reduce 173


state 324
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' init_declarator_list ';' .  (108)

	.  reduce 108


state 325
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' ';' .  (105)

	.  reduce 105


state 326
	init_declarator_list : init_declarator_list . ',' init_declarator
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' init_declarator_list . ';'

	','  shift 145
	';'  shift 345


327: shift-reduce conflict (shift 346, reduce 201) on ELSE
state 327
	stmt : matched_statement .  (201)
	matched_statement : IF '(' exp ')' matched_statement . ELSE matched_statement
	open_statement : IF '(' exp ')' matched_statement . ELSE open_statement

	ELSE  shift 346
	.  reduce 201


state 328
	open_statement : IF '(' exp ')' stmt .  (205)

	.  reduce 205


state 329
	other : exp_statement .  (179)

	.  reduce 179


state 330
	other : compound_statement .  (178)

	.  reduce 178


state 331
	other : iteration_statement .  (180)

	.  reduce 180


state 332
	other : jump_statement .  (181)

	.  reduce 181


state 333
	other : labeled_statement .  (177)

	.  reduce 177


state 334
	selection_statement : SWITCH '(' exp ')' statement .  (208)

	.  reduce 208


state 335
	iteration_statement : WHILE '(' exp ')' statement .  (209)

	.  reduce 209


state 336
	exp : exp . ',' assignment_exp
	iteration_statement : DO statement WHILE '(' exp . ')' ';'

	')'  shift 347
	','  shift 212


state 337
	iteration_statement : FOR '(' exp_statement exp_statement ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 348
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 338
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement exp_statement exp . ')' statement

	')'  shift 349
	','  shift 212


state 339
	argument_exp_list : argument_exp_list ',' assignment_exp .  (14)

	.  reduce 14


state 340
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (58)

	.  reduce 58


state 341
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (171)

	.  reduce 171


state 342
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (167)

	.  reduce 167


state 343
	initializer : '{' initializer_list ',' '}' .  (174)

	.  reduce 174


state 344
	initializer_list : initializer_list ',' initializer .  (176)

	.  reduce 176


state 345
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' init_declarator_list ';' .  (106)

	.  reduce 106


state 346
	matched_statement : IF '(' exp ')' matched_statement ELSE . matched_statement
	open_statement : IF '(' exp ')' matched_statement ELSE . open_statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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
	WHILE  shift 89
	DO  shift 90
	FOR  shift 91
	GOTO  shift 92
	CONTINUE  shift 93
	BREAK  shift 94
	RETURN  shift 95

	open_statement  goto 350
	other  goto 98
	matched_statement  goto 351
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 329
	compound_statement  goto 330
	iteration_statement  goto 331
	jump_statement  goto 332
	labeled_statement  goto 333
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 347
	iteration_statement : DO statement WHILE '(' exp ')' . ';'

	';'  shift 352


state 348
	iteration_statement : FOR '(' exp_statement exp_statement ')' statement .  (211)

	.  reduce 211


state 349
	iteration_statement : FOR '(' exp_statement exp_statement exp ')' . statement

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
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

	selection_statement  goto 96
	open_statement  goto 97
	other  goto 98
	matched_statement  goto 99
	stmt  goto 100
	relational_exp  goto 101
	equality_exp  goto 102
	unary_operator  goto 103
	cast_exp  goto 104
	multiplicative_exp  goto 105
	additive_exp  goto 106
	postfix_exp  goto 107
	primary_exp  goto 108
	unary_exp  goto 109
	shift_exp  goto 110
	exp_statement  goto 111
	compound_statement  goto 112
	iteration_statement  goto 113
	jump_statement  goto 116
	statement  goto 353
	labeled_statement  goto 118
	exp  goto 119
	and_exp  goto 120
	exclusive_or_exp  goto 121
	logical_and_exp  goto 122
	inclusive_or_exp  goto 123
	logical_or_exp  goto 124
	conditional_exp  goto 125
	assignment_exp  goto 126


state 350
	open_statement : IF '(' exp ')' matched_statement ELSE open_statement .  (206)

	.  reduce 206


state 351
	matched_statement : IF '(' exp ')' matched_statement ELSE matched_statement .  (203)

	.  reduce 203


state 352
	iteration_statement : DO statement WHILE '(' exp ')' ';' .  (210)

	.  reduce 210


state 353
	iteration_statement : FOR '(' exp_statement exp_statement exp ')' statement .  (212)

	.  reduce 212


Rules never reduced
	struct_declaration_list : struct_declaration  (112)
	struct_declaration_list : struct_declaration_list struct_declaration  (113)
	struct_declaration : specifier_qualifier_list struct_declarator_list ';'  (114)
	struct_declaration : assignment_exp struct_declarator_list ';'  (115)
	struct_declarator_list : struct_declarator  (120)
	struct_declarator_list : struct_declarator_list ',' struct_declarator  (121)
	struct_declarator : declarator  (122)
	struct_declarator : ':' constant_exp  (123)
	struct_declarator : declarator ':' constant_exp  (124)
	statement : labeled_statement  (182)
	statement : compound_statement  (183)
	statement : exp_statement  (184)
	statement : iteration_statement  (186)
	statement : jump_statement  (187)


##############################################################################
# Summary
##############################################################################

State 2 contains 3 shift-reduce conflict(s)
State 35 contains 1 shift-reduce conflict(s)
State 40 contains 3 shift-reduce conflict(s)
State 111 contains 28 reduce-reduce conflict(s)
State 112 contains 28 reduce-reduce conflict(s)
State 113 contains 28 reduce-reduce conflict(s)
State 116 contains 28 reduce-reduce conflict(s)
State 118 contains 28 reduce-reduce conflict(s)
State 157 contains 1 shift-reduce conflict(s)
State 327 contains 1 shift-reduce conflict(s)


84 token(s), 68 nonterminal(s)
226 grammar rule(s), 354 state(s)


##############################################################################
# End of File
##############################################################################
