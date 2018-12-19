#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 71 of your 30 day trial period.
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
# Time: 17:09:40
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
	translation_unit  goto 25
	external_declaration  goto 26
	type_qualifier  goto 27
	direct_declarator  goto 28
	declarator  goto 29
	pointer  goto 30
	enum_specifier  goto 31
	declaration_specifiers  goto 32
	type_specifier  goto 33
	declaration  goto 34
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_declarator  goto 28
	declarator  goto 38
	pointer  goto 30


2: shift-reduce conflict (shift 2, reduce 143) on '*'
2: shift-reduce conflict (shift 18, reduce 143) on CONST
2: shift-reduce conflict (shift 19, reduce 143) on VOLATILE
state 2
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . pointer
	pointer : '*' .  (143)
	pointer : '*' . type_qualifier_list

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 143

	type_qualifier_list  goto 39
	type_qualifier  goto 40
	pointer  goto 41


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
	enum_specifier : ENUM . ID
	enum_specifier : ENUM . ID '{' enumerator_list '}'

	'{'  shift 42
	ID  shift 43


state 24
	external_declaration : function_definition .  (220)

	.  reduce 220


state 25
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
	external_declaration  goto 44
	type_qualifier  goto 27
	direct_declarator  goto 28
	declarator  goto 29
	pointer  goto 30
	enum_specifier  goto 31
	declaration_specifiers  goto 32
	type_specifier  goto 33
	declaration  goto 34
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 26
	translation_unit : external_declaration .  (218)

	.  reduce 218


state 27
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

	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 45
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 28
	declarator : direct_declarator .  (135)
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 46
	'['  shift 47
	.  reduce 135


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

	compound_statement  goto 49
	declaration_list  goto 50
	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 52
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 30
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 53


state 31
	type_specifier : enum_specifier .  (102)

	.  reduce 102


state 32
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator compound_statement
	function_definition : declaration_specifiers . declarator declaration_list compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 54
	ID  shift 3

	direct_declarator  goto 28
	declarator  goto 55
	pointer  goto 30
	init_declarator_list  goto 56
	init_declarator  goto 57


33: shift-reduce conflict (shift 2, reduce 79) on '*'
state 33
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

	type_qualifier  goto 27
	pointer  goto 58
	enum_specifier  goto 31
	declaration_specifiers  goto 59
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 34
	external_declaration : declaration .  (221)

	.  reduce 221


state 35
	type_specifier : struct_or_union_specifier .  (101)

	.  reduce 101


state 36
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

	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 60
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 37
	struct_or_union_specifier : struct_or_union . ID '{' declaration_list '}' ';'
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_specifier : struct_or_union . '{' declaration_list '}' ';'
	struct_or_union_specifier : struct_or_union . ID '{' declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union . '{' declaration_list '}' init_declarator_list ';'

	'{'  shift 61
	ID  shift 62


state 38
	direct_declarator : '(' declarator . ')'

	')'  shift 63


39: shift-reduce conflict (shift 2, reduce 144) on '*'
39: shift-reduce conflict (shift 18, reduce 144) on CONST
39: shift-reduce conflict (shift 19, reduce 144) on VOLATILE
state 39
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (144)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 144

	type_qualifier  goto 64
	pointer  goto 65


state 40
	type_qualifier_list : type_qualifier .  (147)

	.  reduce 147


state 41
	pointer : '*' pointer .  (145)

	.  reduce 145


state 42
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 66

	enumerator  goto 67
	enumerator_list  goto 68


state 43
	enum_specifier : ENUM ID .  (127)
	enum_specifier : ENUM ID . '{' enumerator_list '}'

	'{'  shift 69
	.  reduce 127


state 44
	translation_unit : translation_unit external_declaration .  (219)

	.  reduce 219


state 45
	declaration_specifiers : type_qualifier declaration_specifiers .  (82)

	.  reduce 82


state 46
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'

	')'  shift 70
	ID  shift 71
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

	parameter_type_list  goto 72
	type_qualifier  goto 27
	parameter_declaration  goto 73
	identifier_list  goto 74
	parameter_list  goto 75
	enum_specifier  goto 31
	declaration_specifiers  goto 76
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 47
	direct_declarator : direct_declarator '[' . constant_exp ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	']'  shift 83
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 102
	and_exp  goto 103
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	constant_exp  goto 107


state 48
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . '}'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'}'  shift 109
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
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
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	declaration_list  goto 129
	exp_statement  goto 130
	statement_list  goto 131
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	type_qualifier  goto 27
	statement  goto 135
	enum_specifier  goto 31
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	declaration_specifiers  goto 51
	type_specifier  goto 33
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	declaration  goto 52
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 49
	function_definition : declarator compound_statement .  (225)

	.  reduce 225


state 50
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

	compound_statement  goto 139
	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 140
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 51
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 54
	ID  shift 3

	direct_declarator  goto 28
	declarator  goto 141
	pointer  goto 30
	init_declarator_list  goto 56
	init_declarator  goto 57


state 52
	declaration_list : declaration .  (195)

	.  reduce 195


state 53
	declarator : pointer direct_declarator .  (134)
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 46
	'['  shift 47
	.  reduce 134


state 54
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 55
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . compound_statement
	function_definition : declaration_specifiers declarator . declaration_list compound_statement

	'='  shift 142
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

	compound_statement  goto 143
	declaration_list  goto 144
	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 52
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
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
	type_specifier : type_specifier pointer .  (104)

	.  reduce 104


state 59
	declaration_specifiers : type_specifier declaration_specifiers .  (80)

	.  reduce 80


state 60
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (78)

	.  reduce 78


state 61
	struct_or_union_specifier : struct_or_union '{' . declaration_list '}' ';'
	struct_or_union_specifier : struct_or_union '{' . declaration_list '}' init_declarator_list ';'

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

	declaration_list  goto 147
	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 52
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 62
	struct_or_union_specifier : struct_or_union ID . '{' declaration_list '}' ';'
	struct_or_union_specifier : struct_or_union ID .  (109)
	struct_or_union_specifier : struct_or_union ID . '{' declaration_list '}' init_declarator_list ';'

	'{'  shift 148
	.  reduce 109


state 63
	direct_declarator : '(' declarator ')' .  (137)

	.  reduce 137


state 64
	type_qualifier_list : type_qualifier_list type_qualifier .  (148)

	.  reduce 148


state 65
	pointer : '*' type_qualifier_list pointer .  (146)

	.  reduce 146


state 66
	enumerator : ID .  (130)
	enumerator : ID . '=' constant_exp

	'='  shift 149
	.  reduce 130


state 67
	enumerator_list : enumerator .  (128)

	.  reduce 128


state 68
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 150
	'}'  shift 151


state 69
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 66

	enumerator  goto 67
	enumerator_list  goto 152


state 70
	direct_declarator : direct_declarator '(' ')' .  (142)

	.  reduce 142


state 71
	identifier_list : ID .  (156)

	.  reduce 156


state 72
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 153


state 73
	parameter_list : parameter_declaration .  (151)

	.  reduce 151


state 74
	identifier_list : identifier_list . ',' ID
	direct_declarator : direct_declarator '(' identifier_list . ')'

	')'  shift 154
	','  shift 155


state 75
	parameter_list : parameter_list . ',' parameter_declaration
	parameter_type_list : parameter_list .  (149)
	parameter_type_list : parameter_list . ',' ELLIPSIS

	','  shift 156
	.  reduce 149


state 76
	parameter_declaration : declaration_specifiers .  (155)
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator

	'('  shift 157
	'*'  shift 2
	'['  shift 158
	ID  shift 3
	.  reduce 155

	abstract_declarator  goto 159
	direct_abstract_declarator  goto 160
	direct_declarator  goto 28
	declarator  goto 161
	pointer  goto 162


state 77
	unary_operator : '!' .  (26)

	.  reduce 26


state 78
	unary_operator : '&' .  (21)

	.  reduce 21


state 79
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
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

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	type_qualifier  goto 163
	specifier_qualifier_list  goto 164
	type_name  goto 165
	enum_specifier  goto 31
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	type_specifier  goto 166
	and_exp  goto 103
	exp  goto 167
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	struct_or_union_specifier  goto 35
	struct_or_union  goto 37


state 80
	unary_operator : '*' .  (22)

	.  reduce 22


state 81
	unary_operator : '+' .  (23)

	.  reduce 23


state 82
	unary_operator : '-' .  (24)

	.  reduce 24


state 83
	direct_declarator : direct_declarator '[' ']' .  (139)

	.  reduce 139


state 84
	unary_operator : '~' .  (25)

	.  reduce 25


state 85
	primary_exp : ID .  (1)

	.  reduce 1


state 86
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 87
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 88
	unary_exp : SIZEOF . unary_exp
	unary_exp : SIZEOF . '(' type_name ')'

	'!'  shift 77
	'&'  shift 78
	'('  shift 168
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 169
	postfix_exp  goto 94
	unary_operator  goto 95
	primary_exp  goto 99


state 89
	unary_exp : INC_OP . unary_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 170
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 171
	postfix_exp  goto 94
	unary_operator  goto 95
	primary_exp  goto 99


state 90
	unary_exp : DEC_OP . unary_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 170
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 172
	postfix_exp  goto 94
	unary_operator  goto 95
	primary_exp  goto 99


state 91
	equality_exp : relational_exp .  (44)
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 173
	'>'  shift 174
	LE_OP  shift 175
	GE_OP  shift 176
	.  reduce 44


state 92
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : equality_exp .  (47)

	EQ_OP  shift 177
	NE_OP  shift 178
	.  reduce 47


state 93
	cast_exp : unary_exp .  (27)

	.  reduce 27


state 94
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '(' ')'
	postfix_exp : postfix_exp . '(' argument_exp_list ')'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (15)

	'('  shift 179
	'.'  shift 180
	'['  shift 181
	PTR_OP  shift 182
	INC_OP  shift 183
	DEC_OP  shift 184
	.  reduce 15


state 95
	unary_exp : unary_operator . cast_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 185
	primary_exp  goto 99


state 96
	multiplicative_exp : cast_exp .  (29)

	.  reduce 29


state 97
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : multiplicative_exp .  (33)
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 186
	'*'  shift 187
	'/'  shift 188
	.  reduce 33


state 98
	shift_exp : additive_exp .  (36)
	additive_exp : additive_exp . '+' multiplicative_exp
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 189
	'-'  shift 190
	.  reduce 36


state 99
	postfix_exp : primary_exp .  (5)

	.  reduce 5


state 100
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : shift_exp .  (39)

	LEFT_OP  shift 191
	RIGHT_OP  shift 192
	.  reduce 39


state 101
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : exclusive_or_exp .  (51)

	'^'  shift 193
	.  reduce 51


state 102
	constant_exp : conditional_exp .  (74)

	.  reduce 74


state 103
	exclusive_or_exp : and_exp .  (49)
	and_exp : and_exp . '&' equality_exp

	'&'  shift 194
	.  reduce 49


state 104
	logical_and_exp : inclusive_or_exp .  (53)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 195
	.  reduce 53


state 105
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp
	logical_or_exp : logical_and_exp .  (55)

	AND_OP  shift 196
	.  reduce 55


state 106
	logical_or_exp : logical_or_exp . OR_OP logical_and_exp
	conditional_exp : logical_or_exp .  (57)
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp

	'?'  shift 197
	OR_OP  shift 198
	.  reduce 57


state 107
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 199


state 108
	exp_statement : ';' .  (199)

	.  reduce 199


state 109
	compound_statement : '{' '}' .  (191)

	.  reduce 191


state 110
	labeled_statement : ID . ':' statement
	primary_exp : ID .  (1)

	':'  shift 200
	.  reduce 1


state 111
	labeled_statement : CASE . constant_exp ':' statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 102
	and_exp  goto 103
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	constant_exp  goto 201


state 112
	labeled_statement : DEFAULT . ':' statement

	':'  shift 202


state 113
	matched_statement : IF . '(' exp ')' matched_statement ELSE matched_statement
	open_statement : IF . '(' exp ')' stmt
	open_statement : IF . '(' exp ')' matched_statement ELSE open_statement

	'('  shift 203


state 114
	selection_statement : SWITCH . '(' exp ')' statement

	'('  shift 204


state 115
	iteration_statement : WHILE . '(' exp ')' statement

	'('  shift 205


state 116
	iteration_statement : DO . statement WHILE '(' exp ')' ';'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 206
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 117
	iteration_statement : FOR . '(' exp_statement exp_statement exp ')' statement
	iteration_statement : FOR . '(' exp_statement exp_statement ')' statement

	'('  shift 207


state 118
	jump_statement : GOTO . ID ';'

	ID  shift 208


state 119
	jump_statement : CONTINUE . ';'

	';'  shift 209


state 120
	jump_statement : BREAK . ';'

	';'  shift 210


state 121
	jump_statement : RETURN . exp ';'
	jump_statement : RETURN . ';'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 211
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 212
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 122
	selection_statement : stmt .  (207)

	.  reduce 207


state 123
	matched_statement : other .  (204)

	.  reduce 204


state 124
	stmt : matched_statement .  (201)

	.  reduce 201


state 125
	statement : selection_statement .  (185)

	.  reduce 185


state 126
	stmt : open_statement .  (202)

	.  reduce 202


state 127
	cast_exp : unary_exp .  (27)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 213
	MUL_ASSIGN  shift 214
	DIV_ASSIGN  shift 215
	MOD_ASSIGN  shift 216
	ADD_ASSIGN  shift 217
	SUB_ASSIGN  shift 218
	LEFT_ASSIGN  shift 219
	RIGHT_ASSIGN  shift 220
	AND_ASSIGN  shift 221
	XOR_ASSIGN  shift 222
	OR_ASSIGN  shift 223
	.  reduce 27

	assignment_operator  goto 224


128: reduce-reduce conflict (reduce 178, reduce 183) on '!'
128: reduce-reduce conflict (reduce 178, reduce 183) on '&'
128: reduce-reduce conflict (reduce 178, reduce 183) on '('
128: reduce-reduce conflict (reduce 178, reduce 183) on '*'
128: reduce-reduce conflict (reduce 178, reduce 183) on '+'
128: reduce-reduce conflict (reduce 178, reduce 183) on '-'
128: reduce-reduce conflict (reduce 178, reduce 183) on ';'
128: reduce-reduce conflict (reduce 178, reduce 183) on '{'
128: reduce-reduce conflict (reduce 178, reduce 183) on '}'
128: reduce-reduce conflict (reduce 178, reduce 183) on '~'
128: reduce-reduce conflict (reduce 178, reduce 183) on ID
128: reduce-reduce conflict (reduce 178, reduce 183) on CONSTANT
128: reduce-reduce conflict (reduce 178, reduce 183) on STRING_LITERAL
128: reduce-reduce conflict (reduce 178, reduce 183) on SIZEOF
128: reduce-reduce conflict (reduce 178, reduce 183) on INC_OP
128: reduce-reduce conflict (reduce 178, reduce 183) on DEC_OP
128: reduce-reduce conflict (reduce 178, reduce 183) on CASE
128: reduce-reduce conflict (reduce 178, reduce 183) on DEFAULT
128: reduce-reduce conflict (reduce 178, reduce 183) on IF
128: reduce-reduce conflict (reduce 178, reduce 183) on ELSE
128: reduce-reduce conflict (reduce 178, reduce 183) on SWITCH
128: reduce-reduce conflict (reduce 178, reduce 183) on WHILE
128: reduce-reduce conflict (reduce 178, reduce 183) on DO
128: reduce-reduce conflict (reduce 178, reduce 183) on FOR
128: reduce-reduce conflict (reduce 178, reduce 183) on GOTO
128: reduce-reduce conflict (reduce 178, reduce 183) on CONTINUE
128: reduce-reduce conflict (reduce 178, reduce 183) on BREAK
128: reduce-reduce conflict (reduce 178, reduce 183) on RETURN
state 128
	other : compound_statement .  (178)
	statement : compound_statement .  (183)

	.  reduce 178


state 129
	compound_statement : '{' declaration_list . statement_list '}'
	declaration_list : declaration_list . declaration
	compound_statement : '{' declaration_list . '}'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'}'  shift 225
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
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
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	statement_list  goto 226
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	type_qualifier  goto 27
	statement  goto 135
	enum_specifier  goto 31
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	declaration_specifiers  goto 51
	type_specifier  goto 33
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	declaration  goto 140
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


130: reduce-reduce conflict (reduce 179, reduce 184) on '!'
130: reduce-reduce conflict (reduce 179, reduce 184) on '&'
130: reduce-reduce conflict (reduce 179, reduce 184) on '('
130: reduce-reduce conflict (reduce 179, reduce 184) on '*'
130: reduce-reduce conflict (reduce 179, reduce 184) on '+'
130: reduce-reduce conflict (reduce 179, reduce 184) on '-'
130: reduce-reduce conflict (reduce 179, reduce 184) on ';'
130: reduce-reduce conflict (reduce 179, reduce 184) on '{'
130: reduce-reduce conflict (reduce 179, reduce 184) on '}'
130: reduce-reduce conflict (reduce 179, reduce 184) on '~'
130: reduce-reduce conflict (reduce 179, reduce 184) on ID
130: reduce-reduce conflict (reduce 179, reduce 184) on CONSTANT
130: reduce-reduce conflict (reduce 179, reduce 184) on STRING_LITERAL
130: reduce-reduce conflict (reduce 179, reduce 184) on SIZEOF
130: reduce-reduce conflict (reduce 179, reduce 184) on INC_OP
130: reduce-reduce conflict (reduce 179, reduce 184) on DEC_OP
130: reduce-reduce conflict (reduce 179, reduce 184) on CASE
130: reduce-reduce conflict (reduce 179, reduce 184) on DEFAULT
130: reduce-reduce conflict (reduce 179, reduce 184) on IF
130: reduce-reduce conflict (reduce 179, reduce 184) on ELSE
130: reduce-reduce conflict (reduce 179, reduce 184) on SWITCH
130: reduce-reduce conflict (reduce 179, reduce 184) on WHILE
130: reduce-reduce conflict (reduce 179, reduce 184) on DO
130: reduce-reduce conflict (reduce 179, reduce 184) on FOR
130: reduce-reduce conflict (reduce 179, reduce 184) on GOTO
130: reduce-reduce conflict (reduce 179, reduce 184) on CONTINUE
130: reduce-reduce conflict (reduce 179, reduce 184) on BREAK
130: reduce-reduce conflict (reduce 179, reduce 184) on RETURN
state 130
	statement : exp_statement .  (184)
	other : exp_statement .  (179)

	.  reduce 179


state 131
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'}'  shift 227
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 228
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


132: reduce-reduce conflict (reduce 177, reduce 182) on '!'
132: reduce-reduce conflict (reduce 177, reduce 182) on '&'
132: reduce-reduce conflict (reduce 177, reduce 182) on '('
132: reduce-reduce conflict (reduce 177, reduce 182) on '*'
132: reduce-reduce conflict (reduce 177, reduce 182) on '+'
132: reduce-reduce conflict (reduce 177, reduce 182) on '-'
132: reduce-reduce conflict (reduce 177, reduce 182) on ';'
132: reduce-reduce conflict (reduce 177, reduce 182) on '{'
132: reduce-reduce conflict (reduce 177, reduce 182) on '}'
132: reduce-reduce conflict (reduce 177, reduce 182) on '~'
132: reduce-reduce conflict (reduce 177, reduce 182) on ID
132: reduce-reduce conflict (reduce 177, reduce 182) on CONSTANT
132: reduce-reduce conflict (reduce 177, reduce 182) on STRING_LITERAL
132: reduce-reduce conflict (reduce 177, reduce 182) on SIZEOF
132: reduce-reduce conflict (reduce 177, reduce 182) on INC_OP
132: reduce-reduce conflict (reduce 177, reduce 182) on DEC_OP
132: reduce-reduce conflict (reduce 177, reduce 182) on CASE
132: reduce-reduce conflict (reduce 177, reduce 182) on DEFAULT
132: reduce-reduce conflict (reduce 177, reduce 182) on IF
132: reduce-reduce conflict (reduce 177, reduce 182) on ELSE
132: reduce-reduce conflict (reduce 177, reduce 182) on SWITCH
132: reduce-reduce conflict (reduce 177, reduce 182) on WHILE
132: reduce-reduce conflict (reduce 177, reduce 182) on DO
132: reduce-reduce conflict (reduce 177, reduce 182) on FOR
132: reduce-reduce conflict (reduce 177, reduce 182) on GOTO
132: reduce-reduce conflict (reduce 177, reduce 182) on CONTINUE
132: reduce-reduce conflict (reduce 177, reduce 182) on BREAK
132: reduce-reduce conflict (reduce 177, reduce 182) on RETURN
state 132
	other : labeled_statement .  (177)
	statement : labeled_statement .  (182)

	.  reduce 177


133: reduce-reduce conflict (reduce 180, reduce 186) on '!'
133: reduce-reduce conflict (reduce 180, reduce 186) on '&'
133: reduce-reduce conflict (reduce 180, reduce 186) on '('
133: reduce-reduce conflict (reduce 180, reduce 186) on '*'
133: reduce-reduce conflict (reduce 180, reduce 186) on '+'
133: reduce-reduce conflict (reduce 180, reduce 186) on '-'
133: reduce-reduce conflict (reduce 180, reduce 186) on ';'
133: reduce-reduce conflict (reduce 180, reduce 186) on '{'
133: reduce-reduce conflict (reduce 180, reduce 186) on '}'
133: reduce-reduce conflict (reduce 180, reduce 186) on '~'
133: reduce-reduce conflict (reduce 180, reduce 186) on ID
133: reduce-reduce conflict (reduce 180, reduce 186) on CONSTANT
133: reduce-reduce conflict (reduce 180, reduce 186) on STRING_LITERAL
133: reduce-reduce conflict (reduce 180, reduce 186) on SIZEOF
133: reduce-reduce conflict (reduce 180, reduce 186) on INC_OP
133: reduce-reduce conflict (reduce 180, reduce 186) on DEC_OP
133: reduce-reduce conflict (reduce 180, reduce 186) on CASE
133: reduce-reduce conflict (reduce 180, reduce 186) on DEFAULT
133: reduce-reduce conflict (reduce 180, reduce 186) on IF
133: reduce-reduce conflict (reduce 180, reduce 186) on ELSE
133: reduce-reduce conflict (reduce 180, reduce 186) on SWITCH
133: reduce-reduce conflict (reduce 180, reduce 186) on WHILE
133: reduce-reduce conflict (reduce 180, reduce 186) on DO
133: reduce-reduce conflict (reduce 180, reduce 186) on FOR
133: reduce-reduce conflict (reduce 180, reduce 186) on GOTO
133: reduce-reduce conflict (reduce 180, reduce 186) on CONTINUE
133: reduce-reduce conflict (reduce 180, reduce 186) on BREAK
133: reduce-reduce conflict (reduce 180, reduce 186) on RETURN
state 133
	other : iteration_statement .  (180)
	statement : iteration_statement .  (186)

	.  reduce 180


134: reduce-reduce conflict (reduce 181, reduce 187) on '!'
134: reduce-reduce conflict (reduce 181, reduce 187) on '&'
134: reduce-reduce conflict (reduce 181, reduce 187) on '('
134: reduce-reduce conflict (reduce 181, reduce 187) on '*'
134: reduce-reduce conflict (reduce 181, reduce 187) on '+'
134: reduce-reduce conflict (reduce 181, reduce 187) on '-'
134: reduce-reduce conflict (reduce 181, reduce 187) on ';'
134: reduce-reduce conflict (reduce 181, reduce 187) on '{'
134: reduce-reduce conflict (reduce 181, reduce 187) on '}'
134: reduce-reduce conflict (reduce 181, reduce 187) on '~'
134: reduce-reduce conflict (reduce 181, reduce 187) on ID
134: reduce-reduce conflict (reduce 181, reduce 187) on CONSTANT
134: reduce-reduce conflict (reduce 181, reduce 187) on STRING_LITERAL
134: reduce-reduce conflict (reduce 181, reduce 187) on SIZEOF
134: reduce-reduce conflict (reduce 181, reduce 187) on INC_OP
134: reduce-reduce conflict (reduce 181, reduce 187) on DEC_OP
134: reduce-reduce conflict (reduce 181, reduce 187) on CASE
134: reduce-reduce conflict (reduce 181, reduce 187) on DEFAULT
134: reduce-reduce conflict (reduce 181, reduce 187) on IF
134: reduce-reduce conflict (reduce 181, reduce 187) on ELSE
134: reduce-reduce conflict (reduce 181, reduce 187) on SWITCH
134: reduce-reduce conflict (reduce 181, reduce 187) on WHILE
134: reduce-reduce conflict (reduce 181, reduce 187) on DO
134: reduce-reduce conflict (reduce 181, reduce 187) on FOR
134: reduce-reduce conflict (reduce 181, reduce 187) on GOTO
134: reduce-reduce conflict (reduce 181, reduce 187) on CONTINUE
134: reduce-reduce conflict (reduce 181, reduce 187) on BREAK
134: reduce-reduce conflict (reduce 181, reduce 187) on RETURN
state 134
	other : jump_statement .  (181)
	statement : jump_statement .  (187)

	.  reduce 181


state 135
	statement_list : statement .  (197)

	.  reduce 197


state 136
	assignment_exp : conditional_exp .  (59)

	.  reduce 59


state 137
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 229
	';'  shift 230


state 138
	exp : assignment_exp .  (72)

	.  reduce 72


state 139
	function_definition : declarator declaration_list compound_statement .  (224)

	.  reduce 224


state 140
	declaration_list : declaration_list declaration .  (196)

	.  reduce 196


state 141
	init_declarator : declarator .  (85)
	init_declarator : declarator . '=' initializer

	'='  shift 142
	.  reduce 85


state 142
	init_declarator : declarator '=' . initializer

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'{'  shift 231
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	initializer  goto 232
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	assignment_exp  goto 233
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 143
	function_definition : declaration_specifiers declarator compound_statement .  (223)

	.  reduce 223


state 144
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

	compound_statement  goto 234
	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 140
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 145
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_declarator  goto 28
	declarator  goto 141
	pointer  goto 30
	init_declarator  goto 235


state 146
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 147
	struct_or_union_specifier : struct_or_union '{' declaration_list . '}' ';'
	struct_or_union_specifier : struct_or_union '{' declaration_list . '}' init_declarator_list ';'
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

	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 140
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 148
	struct_or_union_specifier : struct_or_union ID '{' . declaration_list '}' ';'
	struct_or_union_specifier : struct_or_union ID '{' . declaration_list '}' init_declarator_list ';'

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

	declaration_list  goto 237
	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 52
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 149
	enumerator : ID '=' . constant_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 102
	and_exp  goto 103
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	constant_exp  goto 238


state 150
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 66

	enumerator  goto 239


state 151
	enum_specifier : ENUM '{' enumerator_list '}' .  (125)

	.  reduce 125


state 152
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM ID '{' enumerator_list . '}'

	','  shift 150
	'}'  shift 240


state 153
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (140)

	.  reduce 140


state 154
	direct_declarator : direct_declarator '(' identifier_list ')' .  (141)

	.  reduce 141


state 155
	identifier_list : identifier_list ',' . ID

	ID  shift 241


state 156
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
	ELLIPSIS  shift 242

	type_qualifier  goto 27
	parameter_declaration  goto 243
	enum_specifier  goto 31
	declaration_specifiers  goto 76
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 157
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 157
	')'  shift 244
	'*'  shift 2
	'['  shift 158
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

	abstract_declarator  goto 245
	direct_abstract_declarator  goto 160
	parameter_type_list  goto 246
	type_qualifier  goto 27
	direct_declarator  goto 28
	parameter_declaration  goto 73
	declarator  goto 38
	pointer  goto 162
	parameter_list  goto 75
	enum_specifier  goto 31
	declaration_specifiers  goto 76
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 158
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	']'  shift 247
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 102
	and_exp  goto 103
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	constant_exp  goto 248


state 159
	parameter_declaration : declaration_specifiers abstract_declarator .  (154)

	.  reduce 154


state 160
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	abstract_declarator : direct_abstract_declarator .  (161)
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 249
	'['  shift 250
	.  reduce 161


state 161
	parameter_declaration : declaration_specifiers declarator .  (153)

	.  reduce 153


state 162
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (160)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 157
	'['  shift 158
	ID  shift 3
	.  reduce 160

	direct_abstract_declarator  goto 251
	direct_declarator  goto 53


state 163
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

	type_qualifier  goto 163
	specifier_qualifier_list  goto 252
	enum_specifier  goto 31
	type_specifier  goto 166
	struct_or_union_specifier  goto 35
	struct_or_union  goto 37


state 164
	type_name : specifier_qualifier_list .  (158)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 253
	'*'  shift 2
	'['  shift 158
	.  reduce 158

	abstract_declarator  goto 254
	direct_abstract_declarator  goto 160
	pointer  goto 255


state 165
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 256


166: shift-reduce conflict (shift 2, reduce 117) on '*'
state 166
	specifier_qualifier_list : type_specifier .  (117)
	type_specifier : type_specifier . pointer
	specifier_qualifier_list : type_specifier . specifier_qualifier_list

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

	type_qualifier  goto 163
	specifier_qualifier_list  goto 257
	pointer  goto 58
	enum_specifier  goto 31
	type_specifier  goto 166
	struct_or_union_specifier  goto 35
	struct_or_union  goto 37


state 167
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 258
	','  shift 229


state 168
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
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

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	type_qualifier  goto 163
	specifier_qualifier_list  goto 164
	type_name  goto 259
	enum_specifier  goto 31
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	type_specifier  goto 166
	and_exp  goto 103
	exp  goto 167
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	struct_or_union_specifier  goto 35
	struct_or_union  goto 37


state 169
	unary_exp : SIZEOF unary_exp .  (19)

	.  reduce 19


state 170
	primary_exp : '(' . exp ')'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 167
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 171
	unary_exp : INC_OP unary_exp .  (16)

	.  reduce 16


state 172
	unary_exp : DEC_OP unary_exp .  (17)

	.  reduce 17


state 173
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 260


state 174
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 261


state 175
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 262


state 176
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 263


state 177
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 264
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100


state 178
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 265
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100


state 179
	postfix_exp : postfix_exp '(' . ')'
	postfix_exp : postfix_exp '(' . argument_exp_list ')'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	')'  shift 266
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	argument_exp_list  goto 267
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	assignment_exp  goto 268
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 180
	postfix_exp : postfix_exp '.' . ID

	ID  shift 269


state 181
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 270
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 182
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 271


state 183
	postfix_exp : postfix_exp INC_OP .  (11)

	.  reduce 11


state 184
	postfix_exp : postfix_exp DEC_OP .  (12)

	.  reduce 12


state 185
	unary_exp : unary_operator cast_exp .  (18)

	.  reduce 18


state 186
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 272
	primary_exp  goto 99


state 187
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 273
	primary_exp  goto 99


state 188
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 274
	primary_exp  goto 99


state 189
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 275
	primary_exp  goto 99


state 190
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 276
	primary_exp  goto 99


state 191
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 277
	primary_exp  goto 99


state 192
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 278
	primary_exp  goto 99


state 193
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	and_exp  goto 279


state 194
	and_exp : and_exp '&' . equality_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 280
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100


state 195
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 281
	and_exp  goto 103


state 196
	logical_and_exp : logical_and_exp AND_OP . inclusive_or_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	and_exp  goto 103
	inclusive_or_exp  goto 282


state 197
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 283
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 198
	logical_or_exp : logical_or_exp OR_OP . logical_and_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	and_exp  goto 103
	inclusive_or_exp  goto 104
	logical_and_exp  goto 284


state 199
	direct_declarator : direct_declarator '[' constant_exp ']' .  (138)

	.  reduce 138


state 200
	labeled_statement : ID ':' . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 285
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 201
	labeled_statement : CASE constant_exp . ':' statement

	':'  shift 286


state 202
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 287
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 203
	matched_statement : IF '(' . exp ')' matched_statement ELSE matched_statement
	open_statement : IF '(' . exp ')' stmt
	open_statement : IF '(' . exp ')' matched_statement ELSE open_statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 288
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 204
	selection_statement : SWITCH '(' . exp ')' statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 289
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 205
	iteration_statement : WHILE '(' . exp ')' statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 290
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 206
	iteration_statement : DO statement . WHILE '(' exp ')' ';'

	WHILE  shift 291


state 207
	iteration_statement : FOR '(' . exp_statement exp_statement exp ')' statement
	iteration_statement : FOR '(' . exp_statement exp_statement ')' statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exp_statement  goto 292
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 208
	jump_statement : GOTO ID . ';'

	';'  shift 293


state 209
	jump_statement : CONTINUE ';' .  (214)

	.  reduce 214


state 210
	jump_statement : BREAK ';' .  (215)

	.  reduce 215


state 211
	jump_statement : RETURN ';' .  (216)

	.  reduce 216


state 212
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 229
	';'  shift 294


state 213
	assignment_operator : '=' .  (61)

	.  reduce 61


state 214
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 215
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 216
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 217
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 218
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 219
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 220
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 221
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 222
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 223
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 224
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	assignment_exp  goto 295
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 225
	compound_statement : '{' declaration_list '}' .  (193)

	.  reduce 193


state 226
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'}'  shift 296
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 228
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 227
	compound_statement : '{' statement_list '}' .  (192)

	.  reduce 192


state 228
	statement_list : statement_list statement .  (198)

	.  reduce 198


state 229
	exp : exp ',' . assignment_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	assignment_exp  goto 297
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 230
	exp_statement : exp ';' .  (200)

	.  reduce 200


state 231
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'{'  shift 231
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	initializer  goto 298
	initializer_list  goto 299
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	assignment_exp  goto 233
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


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
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' . ';'
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 300
	ID  shift 3

	direct_declarator  goto 28
	declarator  goto 141
	pointer  goto 30
	init_declarator_list  goto 301
	init_declarator  goto 57


state 237
	struct_or_union_specifier : struct_or_union ID '{' declaration_list . '}' ';'
	struct_or_union_specifier : struct_or_union ID '{' declaration_list . '}' init_declarator_list ';'
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

	type_qualifier  goto 27
	enum_specifier  goto 31
	declaration_specifiers  goto 51
	type_specifier  goto 33
	declaration  goto 140
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
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
	identifier_list : identifier_list ',' ID .  (157)

	.  reduce 157


state 242
	parameter_type_list : parameter_list ',' ELLIPSIS .  (150)

	.  reduce 150


state 243
	parameter_list : parameter_list ',' parameter_declaration .  (152)

	.  reduce 152


state 244
	direct_abstract_declarator : '(' ')' .  (168)

	.  reduce 168


state 245
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 303


state 246
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 304


state 247
	direct_abstract_declarator : '[' ']' .  (164)

	.  reduce 164


state 248
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 305


state 249
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

	')'  shift 306
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

	parameter_type_list  goto 307
	type_qualifier  goto 27
	parameter_declaration  goto 73
	parameter_list  goto 75
	enum_specifier  goto 31
	declaration_specifiers  goto 76
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 250
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	']'  shift 308
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 102
	and_exp  goto 103
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106
	constant_exp  goto 309


state 251
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	abstract_declarator : pointer direct_abstract_declarator .  (162)
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 249
	'['  shift 250
	.  reduce 162


state 252
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (118)

	.  reduce 118


state 253
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 253
	')'  shift 244
	'*'  shift 2
	'['  shift 158
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

	abstract_declarator  goto 245
	direct_abstract_declarator  goto 160
	parameter_type_list  goto 246
	type_qualifier  goto 27
	parameter_declaration  goto 73
	pointer  goto 255
	parameter_list  goto 75
	enum_specifier  goto 31
	declaration_specifiers  goto 76
	type_specifier  goto 33
	struct_or_union_specifier  goto 35
	storage_class_specifier  goto 36
	struct_or_union  goto 37


state 254
	type_name : specifier_qualifier_list abstract_declarator .  (159)

	.  reduce 159


state 255
	abstract_declarator : pointer .  (160)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 253
	'['  shift 158
	.  reduce 160

	direct_abstract_declarator  goto 251


state 256
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 310
	primary_exp  goto 99


state 257
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (116)

	.  reduce 116


state 258
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 259
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 311


state 260
	relational_exp : relational_exp '<' shift_exp .  (40)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 191
	RIGHT_OP  shift 192
	.  reduce 40


state 261
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '>' shift_exp .  (41)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 191
	RIGHT_OP  shift 192
	.  reduce 41


state 262
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (42)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 191
	RIGHT_OP  shift 192
	.  reduce 42


state 263
	relational_exp : relational_exp GE_OP shift_exp .  (43)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 191
	RIGHT_OP  shift 192
	.  reduce 43


state 264
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (45)
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 173
	'>'  shift 174
	LE_OP  shift 175
	GE_OP  shift 176
	.  reduce 45


state 265
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (46)
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 173
	'>'  shift 174
	LE_OP  shift 175
	GE_OP  shift 176
	.  reduce 46


state 266
	postfix_exp : postfix_exp '(' ')' .  (7)

	.  reduce 7


state 267
	postfix_exp : postfix_exp '(' argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 312
	','  shift 313


state 268
	argument_exp_list : assignment_exp .  (13)

	.  reduce 13


state 269
	postfix_exp : postfix_exp '.' ID .  (9)

	.  reduce 9


state 270
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 229
	']'  shift 314


state 271
	postfix_exp : postfix_exp PTR_OP ID .  (10)

	.  reduce 10


state 272
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (32)

	.  reduce 32


state 273
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (30)

	.  reduce 30


state 274
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (31)

	.  reduce 31


state 275
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (34)

	'%'  shift 186
	'*'  shift 187
	'/'  shift 188
	.  reduce 34


state 276
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (35)

	'%'  shift 186
	'*'  shift 187
	'/'  shift 188
	.  reduce 35


state 277
	additive_exp : additive_exp . '+' multiplicative_exp
	additive_exp : additive_exp . '-' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (37)

	'+'  shift 189
	'-'  shift 190
	.  reduce 37


state 278
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (38)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 189
	'-'  shift 190
	.  reduce 38


state 279
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (50)
	and_exp : and_exp . '&' equality_exp

	'&'  shift 194
	.  reduce 50


state 280
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : and_exp '&' equality_exp .  (48)

	EQ_OP  shift 177
	NE_OP  shift 178
	.  reduce 48


state 281
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (52)

	'^'  shift 193
	.  reduce 52


state 282
	logical_and_exp : logical_and_exp AND_OP inclusive_or_exp .  (54)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 195
	.  reduce 54


state 283
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 229
	':'  shift 315


state 284
	logical_or_exp : logical_or_exp OR_OP logical_and_exp .  (56)
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp

	AND_OP  shift 196
	.  reduce 56


state 285
	labeled_statement : ID ':' statement .  (188)

	.  reduce 188


state 286
	labeled_statement : CASE constant_exp ':' . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 316
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 287
	labeled_statement : DEFAULT ':' statement .  (190)

	.  reduce 190


state 288
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' matched_statement ELSE matched_statement
	open_statement : IF '(' exp . ')' stmt
	open_statement : IF '(' exp . ')' matched_statement ELSE open_statement

	')'  shift 317
	','  shift 229


state 289
	exp : exp . ',' assignment_exp
	selection_statement : SWITCH '(' exp . ')' statement

	')'  shift 318
	','  shift 229


state 290
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE '(' exp . ')' statement

	')'  shift 319
	','  shift 229


state 291
	iteration_statement : DO statement WHILE . '(' exp ')' ';'

	'('  shift 320


state 292
	iteration_statement : FOR '(' exp_statement . exp_statement exp ')' statement
	iteration_statement : FOR '(' exp_statement . exp_statement ')' statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exp_statement  goto 321
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 293
	jump_statement : GOTO ID ';' .  (213)

	.  reduce 213


state 294
	jump_statement : RETURN exp ';' .  (217)

	.  reduce 217


state 295
	assignment_exp : unary_exp assignment_operator assignment_exp .  (60)

	.  reduce 60


state 296
	compound_statement : '{' declaration_list statement_list '}' .  (194)

	.  reduce 194


state 297
	exp : exp ',' assignment_exp .  (73)

	.  reduce 73


state 298
	initializer_list : initializer .  (175)

	.  reduce 175


state 299
	initializer : '{' initializer_list . '}'
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . ',' '}'

	','  shift 322
	'}'  shift 323


state 300
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' ';' .  (107)

	.  reduce 107


state 301
	init_declarator_list : init_declarator_list . ',' init_declarator
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' init_declarator_list . ';'

	','  shift 145
	';'  shift 324


state 302
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' . ';'
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 325
	ID  shift 3

	direct_declarator  goto 28
	declarator  goto 141
	pointer  goto 30
	init_declarator_list  goto 326
	init_declarator  goto 57


state 303
	direct_abstract_declarator : '(' abstract_declarator ')' .  (163)

	.  reduce 163


state 304
	direct_abstract_declarator : '(' parameter_type_list ')' .  (169)

	.  reduce 169


state 305
	direct_abstract_declarator : '[' constant_exp ']' .  (165)

	.  reduce 165


state 306
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (170)

	.  reduce 170


state 307
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 327


state 308
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (166)

	.  reduce 166


state 309
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp . ']'

	']'  shift 328


state 310
	cast_exp : '(' type_name ')' cast_exp .  (28)

	.  reduce 28


state 311
	unary_exp : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 312
	postfix_exp : postfix_exp '(' argument_exp_list ')' .  (8)

	.  reduce 8


state 313
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	assignment_exp  goto 329
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 314
	postfix_exp : postfix_exp '[' exp ']' .  (6)

	.  reduce 6


state 315
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 93
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 330
	and_exp  goto 103
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 316
	labeled_statement : CASE constant_exp ':' statement .  (189)

	.  reduce 189


state 317
	matched_statement : IF '(' exp ')' . matched_statement ELSE matched_statement
	open_statement : IF '(' exp ')' . stmt
	open_statement : IF '(' exp ')' . matched_statement ELSE open_statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 331
	other  goto 123
	matched_statement  goto 332
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 333
	exp_statement  goto 334
	labeled_statement  goto 335
	iteration_statement  goto 336
	jump_statement  goto 337
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 318
	selection_statement : SWITCH '(' exp ')' . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 338
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 319
	iteration_statement : WHILE '(' exp ')' . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 339
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 320
	iteration_statement : DO statement WHILE '(' . exp ')' ';'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 340
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 321
	iteration_statement : FOR '(' exp_statement exp_statement . exp ')' statement
	iteration_statement : FOR '(' exp_statement exp_statement . ')' statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	')'  shift 341
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 342
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 322
	initializer_list : initializer_list ',' . initializer
	initializer : '{' initializer_list ',' . '}'

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	'{'  shift 231
	'}'  shift 343
	'~'  shift 84
	ID  shift 85
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90

	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	initializer  goto 344
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	assignment_exp  goto 233
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


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


state 327
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (171)

	.  reduce 171


state 328
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (167)

	.  reduce 167


state 329
	argument_exp_list : argument_exp_list ',' assignment_exp .  (14)

	.  reduce 14


state 330
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (58)

	.  reduce 58


state 331
	open_statement : IF '(' exp ')' stmt .  (205)

	.  reduce 205


332: shift-reduce conflict (shift 346, reduce 201) on ELSE
state 332
	stmt : matched_statement .  (201)
	matched_statement : IF '(' exp ')' matched_statement . ELSE matched_statement
	open_statement : IF '(' exp ')' matched_statement . ELSE open_statement

	ELSE  shift 346
	.  reduce 201


state 333
	other : compound_statement .  (178)

	.  reduce 178


state 334
	other : exp_statement .  (179)

	.  reduce 179


state 335
	other : labeled_statement .  (177)

	.  reduce 177


state 336
	other : iteration_statement .  (180)

	.  reduce 180


state 337
	other : jump_statement .  (181)

	.  reduce 181


state 338
	selection_statement : SWITCH '(' exp ')' statement .  (208)

	.  reduce 208


state 339
	iteration_statement : WHILE '(' exp ')' statement .  (209)

	.  reduce 209


state 340
	exp : exp . ',' assignment_exp
	iteration_statement : DO statement WHILE '(' exp . ')' ';'

	')'  shift 347
	','  shift 229


state 341
	iteration_statement : FOR '(' exp_statement exp_statement ')' . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 348
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 342
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement exp_statement exp . ')' statement

	')'  shift 349
	','  shift 229


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

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	other  goto 123
	matched_statement  goto 350
	open_statement  goto 351
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 333
	exp_statement  goto 334
	labeled_statement  goto 335
	iteration_statement  goto 336
	jump_statement  goto 337
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 347
	iteration_statement : DO statement WHILE '(' exp ')' . ';'

	';'  shift 352


state 348
	iteration_statement : FOR '(' exp_statement exp_statement ')' statement .  (211)

	.  reduce 211


state 349
	iteration_statement : FOR '(' exp_statement exp_statement exp ')' . statement

	'!'  shift 77
	'&'  shift 78
	'('  shift 79
	'*'  shift 80
	'+'  shift 81
	'-'  shift 82
	';'  shift 108
	'{'  shift 48
	'~'  shift 84
	ID  shift 110
	CONSTANT  shift 86
	STRING_LITERAL  shift 87
	SIZEOF  shift 88
	INC_OP  shift 89
	DEC_OP  shift 90
	CASE  shift 111
	DEFAULT  shift 112
	IF  shift 113
	SWITCH  shift 114
	WHILE  shift 115
	DO  shift 116
	FOR  shift 117
	GOTO  shift 118
	CONTINUE  shift 119
	BREAK  shift 120
	RETURN  shift 121

	stmt  goto 122
	other  goto 123
	matched_statement  goto 124
	selection_statement  goto 125
	open_statement  goto 126
	relational_exp  goto 91
	equality_exp  goto 92
	unary_exp  goto 127
	postfix_exp  goto 94
	unary_operator  goto 95
	cast_exp  goto 96
	multiplicative_exp  goto 97
	additive_exp  goto 98
	primary_exp  goto 99
	shift_exp  goto 100
	compound_statement  goto 128
	exp_statement  goto 130
	labeled_statement  goto 132
	iteration_statement  goto 133
	jump_statement  goto 134
	statement  goto 353
	exclusive_or_exp  goto 101
	conditional_exp  goto 136
	and_exp  goto 103
	exp  goto 137
	assignment_exp  goto 138
	inclusive_or_exp  goto 104
	logical_and_exp  goto 105
	logical_or_exp  goto 106


state 350
	matched_statement : IF '(' exp ')' matched_statement ELSE matched_statement .  (203)

	.  reduce 203


state 351
	open_statement : IF '(' exp ')' matched_statement ELSE open_statement .  (206)

	.  reduce 206


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
State 33 contains 1 shift-reduce conflict(s)
State 39 contains 3 shift-reduce conflict(s)
State 128 contains 28 reduce-reduce conflict(s)
State 130 contains 28 reduce-reduce conflict(s)
State 132 contains 28 reduce-reduce conflict(s)
State 133 contains 28 reduce-reduce conflict(s)
State 134 contains 28 reduce-reduce conflict(s)
State 166 contains 1 shift-reduce conflict(s)
State 332 contains 1 shift-reduce conflict(s)


84 token(s), 68 nonterminal(s)
226 grammar rule(s), 354 state(s)


##############################################################################
# End of File
##############################################################################
