#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 84 of your 30 day trial period.
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
# Date: 01/02/19
# Time: 01:23:47
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
    5              | TRUE
    6              | FALSE

    7  postfix_pre_exp : postfix_exp '('

    8  postfix_exp : primary_exp
    9              | postfix_exp '[' exp ']'
   10              | postfix_pre_exp ')'
   11              | postfix_pre_exp argument_exp_list ')'
   12              | postfix_exp '.' ID
   13              | postfix_exp PTR_OP ID
   14              | postfix_exp INC_OP
   15              | postfix_exp DEC_OP

   16  argument_exp_list : assignment_exp
   17                    | argument_exp_list ',' assignment_exp

   18  unary_exp : postfix_exp
   19            | INC_OP unary_exp
   20            | DEC_OP unary_exp
   21            | unary_operator cast_exp
   22            | SIZEOF unary_exp
   23            | SIZEOF '(' type_name ')'

   24  unary_operator : '&'
   25                 | '*'
   26                 | '+'
   27                 | '-'
   28                 | '~'
   29                 | '!'

   30  cast_exp : unary_exp
   31           | '(' type_name ')' cast_exp

   32  multiplicative_exp : cast_exp
   33                     | multiplicative_exp '^' cast_exp
   34                     | multiplicative_exp '*' cast_exp
   35                     | multiplicative_exp '/' cast_exp
   36                     | multiplicative_exp '%' cast_exp

   37  additive_exp : multiplicative_exp
   38               | additive_exp '+' multiplicative_exp
   39               | additive_exp '-' multiplicative_exp

   40  shift_exp : additive_exp
   41            | shift_exp LEFT_OP additive_exp
   42            | shift_exp RIGHT_OP additive_exp

   43  relational_exp : shift_exp
   44                 | relational_exp '<' shift_exp
   45                 | relational_exp '>' shift_exp
   46                 | relational_exp LE_OP shift_exp
   47                 | relational_exp GE_OP shift_exp

   48  equality_exp : relational_exp
   49               | equality_exp EQ_OP relational_exp
   50               | equality_exp NE_OP relational_exp

   51  and_exp : equality_exp
   52          | and_exp '&' equality_exp

   53  exclusive_or_exp : and_exp
   54                   | exclusive_or_exp '^' and_exp

   55  inclusive_or_exp : exclusive_or_exp
   56                   | inclusive_or_exp '|' exclusive_or_exp

   57  logical_and_exp : inclusive_or_exp
   58                  | logical_and_exp AND_OP M inclusive_or_exp

   59  M :

   60  N :

   61  P :

   62  logical_or_exp : logical_and_exp
   63                 | logical_or_exp OR_OP M logical_and_exp

   64  conditional_exp : logical_or_exp
   65                  | logical_or_exp '?' exp ':' conditional_exp

   66  assignment_exp : conditional_exp
   67                 | unary_exp assignment_operator assignment_exp

   68  assignment_operator : '='
   69                      | MUL_ASSIGN
   70                      | DIV_ASSIGN
   71                      | MOD_ASSIGN
   72                      | ADD_ASSIGN
   73                      | SUB_ASSIGN
   74                      | LEFT_ASSIGN
   75                      | RIGHT_ASSIGN
   76                      | AND_ASSIGN
   77                      | XOR_ASSIGN
   78                      | OR_ASSIGN

   79  exp : assignment_exp
   80      | exp ',' assignment_exp

   81  constant_exp : conditional_exp

   82  declaration : declaration_specifiers ';'
   83              | declaration_specifiers init_declarator_list ';'

   84  declaration_specifiers : storage_class_specifier
   85                         | storage_class_specifier declaration_specifiers
   86                         | type_specifier
   87                         | type_specifier declaration_specifiers
   88                         | type_qualifier
   89                         | type_qualifier declaration_specifiers

   90  init_declarator_list : init_declarator
   91                       | init_declarator_list ',' init_declarator

   92  init_declarator : declarator
   93                  | declarator '=' initializer

   94  storage_class_specifier : TYPEDEF
   95                          | EXTERN
   96                          | STATIC
   97                          | AUTO
   98                          | REGISTER

   99  type_specifier : VOID
  100                 | CHAR
  101                 | SHORT
  102                 | INT
  103                 | LONG
  104                 | FLOAT
  105                 | DOUBLE
  106                 | SIGNED
  107                 | UNSIGNED
  108                 | struct_or_union_specifier
  109                 | enum_specifier
  110                 | TYPE_NAME
  111                 | type_specifier pointer

  112  struct_or_union_def : struct_or_union ID '{' declaration_list '}'
  113                      | struct_or_union '{' declaration_list '}'

  114  def_concat : ';'
  115             | init_declarator_list ';'

  116  struct_or_union_specifier : struct_or_union_def def_concat
  117                            | struct_or_union ID

  118  struct_or_union : STRUCT
  119                  | UNION

  120  struct_declaration_list : struct_declaration
  121                          | struct_declaration_list struct_declaration

  122  struct_declaration : specifier_qualifier_list struct_declarator_list ';'
  123                     | assignment_exp struct_declarator_list ';'

  124  specifier_qualifier_list : type_specifier specifier_qualifier_list
  125                           | type_specifier
  126                           | type_qualifier specifier_qualifier_list
  127                           | type_qualifier

  128  struct_declarator_list : struct_declarator
  129                         | struct_declarator_list ',' struct_declarator

  130  struct_declarator : declarator
  131                    | ':' constant_exp
  132                    | declarator ':' constant_exp

  133  enum_specifier : ENUM '{' enumerator_list '}'
  134                 | ENUM ID '{' enumerator_list '}'
  135                 | ENUM ID

  136  enumerator_list : enumerator
  137                  | enumerator_list ',' enumerator

  138  enumerator : ID
  139             | ID '=' constant_exp

  140  type_qualifier : CONST
  141                 | VOLATILE

  142  declarator : pointer direct_declarator
  143             | direct_declarator

  144  direct_pre_declarator : direct_declarator '('

  145  direct_declarator : ID
  146                    | '(' declarator ')'
  147                    | direct_declarator '[' constant_exp ']'
  148                    | direct_declarator '[' ']'
  149                    | direct_pre_declarator parameter_type_list ')'
  150                    | direct_pre_declarator identifier_list ')'
  151                    | direct_pre_declarator ')'

  152  pointer : '*'
  153          | '*' type_qualifier_list
  154          | '*' pointer
  155          | '*' type_qualifier_list pointer

  156  type_qualifier_list : type_qualifier
  157                      | type_qualifier_list type_qualifier

  158  parameter_type_list : parameter_list
  159                      | parameter_list ',' ELLIPSIS

  160  parameter_list : parameter_declaration
  161                 | parameter_list ',' parameter_declaration

  162  parameter_declaration : declaration_specifiers declarator
  163                        | declaration_specifiers abstract_declarator
  164                        | declaration_specifiers

  165  identifier_list : ID
  166                  | identifier_list ',' ID

  167  type_name : specifier_qualifier_list
  168            | specifier_qualifier_list abstract_declarator

  169  abstract_declarator : pointer
  170                      | direct_abstract_declarator
  171                      | pointer direct_abstract_declarator

  172  direct_abstract_declarator : '(' abstract_declarator ')'
  173                             | '[' ']'
  174                             | '[' constant_exp ']'
  175                             | direct_abstract_declarator '[' ']'
  176                             | direct_abstract_declarator '[' constant_exp ']'
  177                             | '(' ')'
  178                             | '(' parameter_type_list ')'
  179                             | direct_abstract_declarator '(' ')'
  180                             | direct_abstract_declarator '(' parameter_type_list ')'

  181  initializer : assignment_exp
  182              | '{' initializer_list '}'
  183              | '{' initializer_list ',' '}'

  184  initializer_list : initializer
  185                   | initializer_list ',' initializer

  186  other : compound_statement
  187        | exp_statement
  188        | iteration_statement
  189        | jump_statement

  190  statement : labeled_statement
  191            | other
  192            | selection_statement

  193  default_pre : DEFAULT ':'

  194  labeled_statement : ID ':' statement
  195                    | CASE constant_exp ':' M statement
  196                    | default_pre statement

  197  compound_statement : '{' '}'
  198                     | '{' statement_list '}'
  199                     | '{' declaration_list '}'
  200                     | '{' declaration_list statement_list '}'

  201  declaration_list : declaration
  202                   | declaration_list M declaration

  203  statement_list : statement
  204                 | statement_list M statement

  205  exp_statement : ';'
  206                | exp ';'

  207  stmt : matched_statement
  208       | open_statement

  209  matched_statement : IF '(' exp ')' M matched_statement P ELSE M matched_statement
  210                    | other

  211  open_statement : IF '(' exp ')' M stmt
  212                 | IF '(' exp ')' M matched_statement P ELSE M open_statement

  213  selection_statement : stmt
  214                      | switch_pre statement

  215  switch_pre : SWITCH '(' exp ')'

  216  iteration_statement : WHILE M '(' exp ')' M statement
  217                      | DO M statement WHILE M '(' exp ')' ';'
  218                      | FOR '(' exp_statement M exp_statement ')' M statement
  219                      | FOR '(' exp_statement M exp_statement M exp P ')' M statement

  220  jump_statement : GOTO ID ';'
  221                 | CONTINUE ';'
  222                 | BREAK ';'
  223                 | RETURN ';'
  224                 | RETURN exp ';'

  225  translation_unit : external_declaration
  226                   | translation_unit external_declaration

  227  external_declaration : function_definition
  228                       | declaration

  229  function_definition : declaration_specifiers declarator declaration_list compound_statement
  230                      | declaration_specifiers declarator compound_statement
  231                      | declarator declaration_list compound_statement
  232                      | declarator compound_statement


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

	enum_specifier  goto 24
	declarator  goto 25
	direct_declarator  goto 26
	struct_or_union_def  goto 27
	pointer  goto 28
	declaration_specifiers  goto 29
	declaration  goto 30
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	translation_unit  goto 36
	function_definition  goto 37
	direct_pre_declarator  goto 38
	external_declaration  goto 39


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 40
	direct_declarator  goto 26
	pointer  goto 28
	direct_pre_declarator  goto 38


2: shift-reduce conflict (shift 2, reduce 152) on '*'
2: shift-reduce conflict (shift 18, reduce 152) on CONST
2: shift-reduce conflict (shift 19, reduce 152) on VOLATILE
state 2
	pointer : '*' .  (152)
	pointer : '*' . type_qualifier_list
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 152

	pointer  goto 41
	type_qualifier_list  goto 42
	type_qualifier  goto 43


state 3
	direct_declarator : ID .  (145)

	.  reduce 145


state 4
	type_specifier : TYPE_NAME .  (110)

	.  reduce 110


state 5
	storage_class_specifier : TYPEDEF .  (94)

	.  reduce 94


state 6
	storage_class_specifier : EXTERN .  (95)

	.  reduce 95


state 7
	storage_class_specifier : STATIC .  (96)

	.  reduce 96


state 8
	storage_class_specifier : AUTO .  (97)

	.  reduce 97


state 9
	storage_class_specifier : REGISTER .  (98)

	.  reduce 98


state 10
	type_specifier : CHAR .  (100)

	.  reduce 100


state 11
	type_specifier : SHORT .  (101)

	.  reduce 101


state 12
	type_specifier : INT .  (102)

	.  reduce 102


state 13
	type_specifier : LONG .  (103)

	.  reduce 103


state 14
	type_specifier : SIGNED .  (106)

	.  reduce 106


state 15
	type_specifier : UNSIGNED .  (107)

	.  reduce 107


state 16
	type_specifier : FLOAT .  (104)

	.  reduce 104


state 17
	type_specifier : DOUBLE .  (105)

	.  reduce 105


state 18
	type_qualifier : CONST .  (140)

	.  reduce 140


state 19
	type_qualifier : VOLATILE .  (141)

	.  reduce 141


state 20
	type_specifier : VOID .  (99)

	.  reduce 99


state 21
	struct_or_union : STRUCT .  (118)

	.  reduce 118


state 22
	struct_or_union : UNION .  (119)

	.  reduce 119


state 23
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . ID

	'{'  shift 44
	ID  shift 45


state 24
	type_specifier : enum_specifier .  (109)

	.  reduce 109


state 25
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

	'{'  shift 46
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

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 47
	declaration  goto 48
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	declaration_list  goto 49
	compound_statement  goto 50


state 26
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '[' ']'
	direct_pre_declarator : direct_declarator . '('
	declarator : direct_declarator .  (143)

	'('  shift 51
	'['  shift 52
	.  reduce 143


state 27
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 53
	ID  shift 3

	declarator  goto 54
	direct_declarator  goto 26
	pointer  goto 28
	def_concat  goto 55
	init_declarator  goto 56
	init_declarator_list  goto 57
	direct_pre_declarator  goto 38


state 28
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 58
	direct_pre_declarator  goto 38


state 29
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator compound_statement
	function_definition : declaration_specifiers . declarator declaration_list compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 59
	ID  shift 3

	declarator  goto 60
	direct_declarator  goto 26
	pointer  goto 28
	init_declarator  goto 56
	init_declarator_list  goto 61
	direct_pre_declarator  goto 38


state 30
	external_declaration : declaration .  (228)

	.  reduce 228


31: shift-reduce conflict (shift 2, reduce 86) on '*'
state 31
	declaration_specifiers : type_specifier .  (86)
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
	.  reduce 86

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	pointer  goto 62
	declaration_specifiers  goto 63
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35


state 32
	type_specifier : struct_or_union_specifier .  (108)

	.  reduce 108


state 33
	struct_or_union_def : struct_or_union . '{' declaration_list '}'
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID

	'{'  shift 64
	ID  shift 65


state 34
	declaration_specifiers : type_qualifier .  (88)
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
	.  reduce 88

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 66
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35


state 35
	declaration_specifiers : storage_class_specifier .  (84)
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
	.  reduce 84

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 67
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35


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

	enum_specifier  goto 24
	declarator  goto 25
	direct_declarator  goto 26
	struct_or_union_def  goto 27
	pointer  goto 28
	declaration_specifiers  goto 29
	declaration  goto 30
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	function_definition  goto 37
	direct_pre_declarator  goto 38
	external_declaration  goto 68


state 37
	external_declaration : function_definition .  (227)

	.  reduce 227


state 38
	direct_declarator : direct_pre_declarator . identifier_list ')'
	direct_declarator : direct_pre_declarator . ')'
	direct_declarator : direct_pre_declarator . parameter_type_list ')'

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

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 71
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	parameter_type_list  goto 72
	parameter_list  goto 73
	parameter_declaration  goto 74
	identifier_list  goto 75


state 39
	translation_unit : external_declaration .  (225)

	.  reduce 225


state 40
	direct_declarator : '(' declarator . ')'

	')'  shift 76


state 41
	pointer : '*' pointer .  (154)

	.  reduce 154


42: shift-reduce conflict (shift 2, reduce 153) on '*'
42: shift-reduce conflict (shift 18, reduce 153) on CONST
42: shift-reduce conflict (shift 19, reduce 153) on VOLATILE
state 42
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list .  (153)
	pointer : '*' type_qualifier_list . pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 153

	pointer  goto 77
	type_qualifier  goto 78


state 43
	type_qualifier_list : type_qualifier .  (156)

	.  reduce 156


state 44
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 79

	enumerator_list  goto 80
	enumerator  goto 81


state 45
	enum_specifier : ENUM ID . '{' enumerator_list '}'
	enum_specifier : ENUM ID .  (135)

	'{'  shift 82
	.  reduce 135


state 46
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . declaration_list statement_list '}'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'}'  shift 90
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TYPE_NAME  shift 4
	TRUE  shift 98
	FALSE  shift 99
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
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	enum_specifier  goto 24
	struct_or_union_def  goto 27
	exp  goto 123
	declaration_specifiers  goto 47
	declaration  goto 48
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	jump_statement  goto 130
	declaration_list  goto 131
	labeled_statement  goto 132
	statement_list  goto 133
	compound_statement  goto 134
	statement  goto 135
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 47
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 59
	ID  shift 3

	declarator  goto 54
	direct_declarator  goto 26
	pointer  goto 28
	init_declarator  goto 56
	init_declarator_list  goto 61
	direct_pre_declarator  goto 38


state 48
	declaration_list : declaration .  (201)

	.  reduce 201


state 49
	declaration_list : declaration_list . M declaration
	function_definition : declarator declaration_list . compound_statement
	M : .  (59)

	'{'  shift 46
	.  reduce 59

	compound_statement  goto 145
	M  goto 146


state 50
	function_definition : declarator compound_statement .  (232)

	.  reduce 232


state 51
	direct_pre_declarator : direct_declarator '(' .  (144)

	.  reduce 144


state 52
	direct_declarator : direct_declarator '[' . constant_exp ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	']'  shift 147
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	inclusive_or_exp  goto 127
	conditional_exp  goto 150
	exclusive_or_exp  goto 129
	constant_exp  goto 151
	postfix_pre_exp  goto 144


state 53
	def_concat : ';' .  (114)

	.  reduce 114


state 54
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (92)

	'='  shift 152
	.  reduce 92


state 55
	struct_or_union_specifier : struct_or_union_def def_concat .  (116)

	.  reduce 116


state 56
	init_declarator_list : init_declarator .  (90)

	.  reduce 90


state 57
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 153
	';'  shift 154


state 58
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '[' ']'
	declarator : pointer direct_declarator .  (142)
	direct_pre_declarator : direct_declarator . '('

	'('  shift 51
	'['  shift 52
	.  reduce 142


state 59
	declaration : declaration_specifiers ';' .  (82)

	.  reduce 82


state 60
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (92)
	function_definition : declaration_specifiers declarator . compound_statement
	function_definition : declaration_specifiers declarator . declaration_list compound_statement

	'='  shift 152
	'{'  shift 46
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
	.  reduce 92

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 47
	declaration  goto 48
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	declaration_list  goto 155
	compound_statement  goto 156


state 61
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 153
	';'  shift 157


state 62
	type_specifier : type_specifier pointer .  (111)

	.  reduce 111


state 63
	declaration_specifiers : type_specifier declaration_specifiers .  (87)

	.  reduce 87


state 64
	struct_or_union_def : struct_or_union '{' . declaration_list '}'

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

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 47
	declaration  goto 48
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	declaration_list  goto 158


state 65
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union ID .  (117)

	'{'  shift 159
	.  reduce 117


state 66
	declaration_specifiers : type_qualifier declaration_specifiers .  (89)

	.  reduce 89


state 67
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (85)

	.  reduce 85


state 68
	translation_unit : translation_unit external_declaration .  (226)

	.  reduce 226


state 69
	direct_declarator : direct_pre_declarator ')' .  (151)

	.  reduce 151


state 70
	identifier_list : ID .  (165)

	.  reduce 165


state 71
	parameter_declaration : declaration_specifiers .  (164)
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator

	'('  shift 160
	'*'  shift 2
	'['  shift 161
	ID  shift 3
	.  reduce 164

	declarator  goto 162
	direct_declarator  goto 26
	pointer  goto 163
	abstract_declarator  goto 164
	direct_abstract_declarator  goto 165
	direct_pre_declarator  goto 38


state 72
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 166


state 73
	parameter_type_list : parameter_list .  (158)
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 167
	.  reduce 158


state 74
	parameter_list : parameter_declaration .  (160)

	.  reduce 160


state 75
	direct_declarator : direct_pre_declarator identifier_list . ')'
	identifier_list : identifier_list . ',' ID

	')'  shift 168
	','  shift 169


state 76
	direct_declarator : '(' declarator ')' .  (146)

	.  reduce 146


state 77
	pointer : '*' type_qualifier_list pointer .  (155)

	.  reduce 155


state 78
	type_qualifier_list : type_qualifier_list type_qualifier .  (157)

	.  reduce 157


state 79
	enumerator : ID .  (138)
	enumerator : ID . '=' constant_exp

	'='  shift 170
	.  reduce 138


state 80
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 171
	'}'  shift 172


state 81
	enumerator_list : enumerator .  (136)

	.  reduce 136


state 82
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 79

	enumerator_list  goto 173
	enumerator  goto 81


state 83
	unary_operator : '!' .  (29)

	.  reduce 29


state 84
	unary_operator : '&' .  (24)

	.  reduce 24


state 85
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TYPE_NAME  shift 4
	TRUE  shift 98
	FALSE  shift 99
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

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	enum_specifier  goto 24
	struct_or_union_def  goto 27
	exp  goto 174
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	specifier_qualifier_list  goto 175
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	type_specifier  goto 176
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 177
	type_name  goto 178
	postfix_pre_exp  goto 144


state 86
	unary_operator : '*' .  (25)

	.  reduce 25


state 87
	unary_operator : '+' .  (26)

	.  reduce 26


state 88
	unary_operator : '-' .  (27)

	.  reduce 27


state 89
	exp_statement : ';' .  (205)

	.  reduce 205


state 90
	compound_statement : '{' '}' .  (197)

	.  reduce 197


state 91
	unary_operator : '~' .  (28)

	.  reduce 28


state 92
	primary_exp : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 179
	.  reduce 1


state 93
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 94
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 95
	unary_exp : SIZEOF . '(' type_name ')'
	unary_exp : SIZEOF . unary_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 180
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	postfix_exp  goto 120
	unary_exp  goto 181
	postfix_pre_exp  goto 144


state 96
	unary_exp : INC_OP . unary_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 182
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	postfix_exp  goto 120
	unary_exp  goto 183
	postfix_pre_exp  goto 144


state 97
	unary_exp : DEC_OP . unary_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 182
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	postfix_exp  goto 120
	unary_exp  goto 184
	postfix_pre_exp  goto 144


state 98
	primary_exp : TRUE .  (5)

	.  reduce 5


state 99
	primary_exp : FALSE .  (6)

	.  reduce 6


state 100
	labeled_statement : CASE . constant_exp ':' M statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	inclusive_or_exp  goto 127
	conditional_exp  goto 150
	exclusive_or_exp  goto 129
	constant_exp  goto 185
	postfix_pre_exp  goto 144


state 101
	default_pre : DEFAULT . ':'

	':'  shift 186


state 102
	open_statement : IF . '(' exp ')' M stmt
	open_statement : IF . '(' exp ')' M matched_statement P ELSE M open_statement
	matched_statement : IF . '(' exp ')' M matched_statement P ELSE M matched_statement

	'('  shift 187


state 103
	switch_pre : SWITCH . '(' exp ')'

	'('  shift 188


state 104
	iteration_statement : WHILE . M '(' exp ')' M statement
	M : .  (59)

	.  reduce 59

	M  goto 189


state 105
	iteration_statement : DO . M statement WHILE M '(' exp ')' ';'
	M : .  (59)

	.  reduce 59

	M  goto 190


state 106
	iteration_statement : FOR . '(' exp_statement M exp_statement ')' M statement
	iteration_statement : FOR . '(' exp_statement M exp_statement M exp P ')' M statement

	'('  shift 191


state 107
	jump_statement : GOTO . ID ';'

	ID  shift 192


state 108
	jump_statement : CONTINUE . ';'

	';'  shift 193


state 109
	jump_statement : BREAK . ';'

	';'  shift 194


state 110
	jump_statement : RETURN . exp ';'
	jump_statement : RETURN . ';'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 195
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 196
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 111
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : additive_exp .  (40)

	'+'  shift 197
	'-'  shift 198
	.  reduce 40


state 112
	and_exp : equality_exp .  (51)
	equality_exp : equality_exp . EQ_OP relational_exp
	equality_exp : equality_exp . NE_OP relational_exp

	EQ_OP  shift 199
	NE_OP  shift 200
	.  reduce 51


state 113
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : and_exp .  (53)

	'&'  shift 201
	.  reduce 53


state 114
	postfix_exp : primary_exp .  (8)

	.  reduce 8


115: shift-reduce conflict (shift 205, reduce 37) on '^'
state 115
	multiplicative_exp : multiplicative_exp . '^' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : multiplicative_exp .  (37)
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 202
	'*'  shift 203
	'/'  shift 204
	'^'  shift 205
	.  reduce 37


state 116
	relational_exp : shift_exp .  (43)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 43


state 117
	unary_exp : unary_operator . cast_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	cast_exp  goto 208
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 118
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : relational_exp .  (48)
	relational_exp : relational_exp . '<' shift_exp

	'<'  shift 209
	'>'  shift 210
	LE_OP  shift 211
	GE_OP  shift 212
	.  reduce 48


state 119
	multiplicative_exp : cast_exp .  (32)

	.  reduce 32


state 120
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (18)

	'('  shift 213
	'.'  shift 214
	'['  shift 215
	PTR_OP  shift 216
	INC_OP  shift 217
	DEC_OP  shift 218
	.  reduce 18


state 121
	labeled_statement : default_pre . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 219
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 122
	cast_exp : unary_exp .  (30)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 220
	MUL_ASSIGN  shift 221
	DIV_ASSIGN  shift 222
	MOD_ASSIGN  shift 223
	ADD_ASSIGN  shift 224
	SUB_ASSIGN  shift 225
	LEFT_ASSIGN  shift 226
	RIGHT_ASSIGN  shift 227
	AND_ASSIGN  shift 228
	XOR_ASSIGN  shift 229
	OR_ASSIGN  shift 230
	.  reduce 30

	assignment_operator  goto 231


state 123
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 232
	';'  shift 233


state 124
	logical_or_exp : logical_or_exp . OR_OP M logical_and_exp
	conditional_exp : logical_or_exp .  (64)
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp

	'?'  shift 234
	OR_OP  shift 235
	.  reduce 64


state 125
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_and_exp .  (62)

	AND_OP  shift 236
	.  reduce 62


state 126
	exp : assignment_exp .  (79)

	.  reduce 79


state 127
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : inclusive_or_exp .  (57)

	'|'  shift 237
	.  reduce 57


state 128
	assignment_exp : conditional_exp .  (66)

	.  reduce 66


state 129
	inclusive_or_exp : exclusive_or_exp .  (55)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 238
	.  reduce 55


state 130
	other : jump_statement .  (189)

	.  reduce 189


state 131
	declaration_list : declaration_list . M declaration
	compound_statement : '{' declaration_list . '}'
	compound_statement : '{' declaration_list . statement_list '}'
	M : .  (59)

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'}'  shift 239
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110
	.  reduce 59

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	statement_list  goto 240
	compound_statement  goto 134
	statement  goto 135
	exp_statement  goto 136
	iteration_statement  goto 137
	M  goto 146
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 132
	statement : labeled_statement .  (190)

	.  reduce 190


state 133
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (59)

	'}'  shift 241
	.  reduce 59

	M  goto 242


state 134
	other : compound_statement .  (186)

	.  reduce 186


state 135
	statement_list : statement .  (203)

	.  reduce 203


state 136
	other : exp_statement .  (187)

	.  reduce 187


state 137
	other : iteration_statement .  (188)

	.  reduce 188


state 138
	stmt : matched_statement .  (207)

	.  reduce 207


state 139
	stmt : open_statement .  (208)

	.  reduce 208


state 140
	selection_statement : stmt .  (213)

	.  reduce 213


state 141
	selection_statement : switch_pre . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 243
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


142: reduce-reduce conflict (reduce 191, reduce 210) on '!'
142: reduce-reduce conflict (reduce 191, reduce 210) on '&'
142: reduce-reduce conflict (reduce 191, reduce 210) on '('
142: reduce-reduce conflict (reduce 191, reduce 210) on '*'
142: reduce-reduce conflict (reduce 191, reduce 210) on '+'
142: reduce-reduce conflict (reduce 191, reduce 210) on '-'
142: reduce-reduce conflict (reduce 191, reduce 210) on ';'
142: reduce-reduce conflict (reduce 191, reduce 210) on '{'
142: reduce-reduce conflict (reduce 191, reduce 210) on '}'
142: reduce-reduce conflict (reduce 191, reduce 210) on '~'
142: reduce-reduce conflict (reduce 191, reduce 210) on ID
142: reduce-reduce conflict (reduce 191, reduce 210) on CONSTANT
142: reduce-reduce conflict (reduce 191, reduce 210) on STRING_LITERAL
142: reduce-reduce conflict (reduce 191, reduce 210) on SIZEOF
142: reduce-reduce conflict (reduce 191, reduce 210) on INC_OP
142: reduce-reduce conflict (reduce 191, reduce 210) on DEC_OP
142: reduce-reduce conflict (reduce 191, reduce 210) on TRUE
142: reduce-reduce conflict (reduce 191, reduce 210) on FALSE
142: reduce-reduce conflict (reduce 191, reduce 210) on CASE
142: reduce-reduce conflict (reduce 191, reduce 210) on DEFAULT
142: reduce-reduce conflict (reduce 191, reduce 210) on IF
142: reduce-reduce conflict (reduce 191, reduce 210) on ELSE
142: reduce-reduce conflict (reduce 191, reduce 210) on SWITCH
142: reduce-reduce conflict (reduce 191, reduce 210) on WHILE
142: reduce-reduce conflict (reduce 191, reduce 210) on DO
142: reduce-reduce conflict (reduce 191, reduce 210) on FOR
142: reduce-reduce conflict (reduce 191, reduce 210) on GOTO
142: reduce-reduce conflict (reduce 191, reduce 210) on CONTINUE
142: reduce-reduce conflict (reduce 191, reduce 210) on BREAK
142: reduce-reduce conflict (reduce 191, reduce 210) on RETURN
state 142
	statement : other .  (191)
	matched_statement : other .  (210)

	.  reduce 191


state 143
	statement : selection_statement .  (192)

	.  reduce 192


state 144
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	')'  shift 244
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	argument_exp_list  goto 245
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 246
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 145
	function_definition : declarator declaration_list compound_statement .  (231)

	.  reduce 231


state 146
	declaration_list : declaration_list M . declaration

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

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 47
	declaration  goto 247
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35


state 147
	direct_declarator : direct_declarator '[' ']' .  (148)

	.  reduce 148


state 148
	primary_exp : ID .  (1)

	.  reduce 1


state 149
	cast_exp : unary_exp .  (30)

	.  reduce 30


state 150
	constant_exp : conditional_exp .  (81)

	.  reduce 81


state 151
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 248


state 152
	init_declarator : declarator '=' . initializer

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'{'  shift 249
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 250
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	initializer  goto 251
	postfix_pre_exp  goto 144


state 153
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 54
	direct_declarator  goto 26
	pointer  goto 28
	init_declarator  goto 252
	direct_pre_declarator  goto 38


state 154
	def_concat : init_declarator_list ';' .  (115)

	.  reduce 115


state 155
	declaration_list : declaration_list . M declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement
	M : .  (59)

	'{'  shift 46
	.  reduce 59

	compound_statement  goto 253
	M  goto 146


state 156
	function_definition : declaration_specifiers declarator compound_statement .  (230)

	.  reduce 230


state 157
	declaration : declaration_specifiers init_declarator_list ';' .  (83)

	.  reduce 83


state 158
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (59)

	'}'  shift 254
	.  reduce 59

	M  goto 146


state 159
	struct_or_union_def : struct_or_union ID '{' . declaration_list '}'

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

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 47
	declaration  goto 48
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	declaration_list  goto 255


state 160
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 160
	')'  shift 256
	'*'  shift 2
	'['  shift 161
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

	enum_specifier  goto 24
	declarator  goto 40
	direct_declarator  goto 26
	struct_or_union_def  goto 27
	pointer  goto 163
	declaration_specifiers  goto 71
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	parameter_type_list  goto 257
	parameter_list  goto 73
	abstract_declarator  goto 258
	parameter_declaration  goto 74
	direct_abstract_declarator  goto 165
	direct_pre_declarator  goto 38


state 161
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	']'  shift 259
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	inclusive_or_exp  goto 127
	conditional_exp  goto 150
	exclusive_or_exp  goto 129
	constant_exp  goto 260
	postfix_pre_exp  goto 144


state 162
	parameter_declaration : declaration_specifiers declarator .  (162)

	.  reduce 162


state 163
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (169)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 160
	'['  shift 161
	ID  shift 3
	.  reduce 169

	direct_declarator  goto 58
	direct_abstract_declarator  goto 261
	direct_pre_declarator  goto 38


state 164
	parameter_declaration : declaration_specifiers abstract_declarator .  (163)

	.  reduce 163


state 165
	abstract_declarator : direct_abstract_declarator .  (170)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 262
	'['  shift 263
	.  reduce 170


state 166
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (149)

	.  reduce 149


state 167
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
	ELLIPSIS  shift 264

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 71
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	parameter_declaration  goto 265


state 168
	direct_declarator : direct_pre_declarator identifier_list ')' .  (150)

	.  reduce 150


state 169
	identifier_list : identifier_list ',' . ID

	ID  shift 266


state 170
	enumerator : ID '=' . constant_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	inclusive_or_exp  goto 127
	conditional_exp  goto 150
	exclusive_or_exp  goto 129
	constant_exp  goto 267
	postfix_pre_exp  goto 144


state 171
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 79

	enumerator  goto 268


state 172
	enum_specifier : ENUM '{' enumerator_list '}' .  (133)

	.  reduce 133


state 173
	enum_specifier : ENUM ID '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 171
	'}'  shift 269


state 174
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 270
	','  shift 232


state 175
	type_name : specifier_qualifier_list . abstract_declarator
	type_name : specifier_qualifier_list .  (167)

	'('  shift 271
	'*'  shift 2
	'['  shift 161
	.  reduce 167

	pointer  goto 272
	abstract_declarator  goto 273
	direct_abstract_declarator  goto 165


176: shift-reduce conflict (shift 2, reduce 125) on '*'
state 176
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	type_specifier : type_specifier . pointer
	specifier_qualifier_list : type_specifier .  (125)

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
	.  reduce 125

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	pointer  goto 62
	specifier_qualifier_list  goto 274
	type_specifier  goto 176
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 177


state 177
	specifier_qualifier_list : type_qualifier . specifier_qualifier_list
	specifier_qualifier_list : type_qualifier .  (127)

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
	.  reduce 127

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	specifier_qualifier_list  goto 275
	type_specifier  goto 176
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 177


state 178
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 276


state 179
	labeled_statement : ID ':' . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 277
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 180
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TYPE_NAME  shift 4
	TRUE  shift 98
	FALSE  shift 99
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

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	enum_specifier  goto 24
	struct_or_union_def  goto 27
	exp  goto 174
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	specifier_qualifier_list  goto 175
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	type_specifier  goto 176
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 177
	type_name  goto 278
	postfix_pre_exp  goto 144


state 181
	unary_exp : SIZEOF unary_exp .  (22)

	.  reduce 22


state 182
	primary_exp : '(' . exp ')'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 174
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 183
	unary_exp : INC_OP unary_exp .  (19)

	.  reduce 19


state 184
	unary_exp : DEC_OP unary_exp .  (20)

	.  reduce 20


state 185
	labeled_statement : CASE constant_exp . ':' M statement

	':'  shift 279


state 186
	default_pre : DEFAULT ':' .  (193)

	.  reduce 193


state 187
	open_statement : IF '(' . exp ')' M stmt
	open_statement : IF '(' . exp ')' M matched_statement P ELSE M open_statement
	matched_statement : IF '(' . exp ')' M matched_statement P ELSE M matched_statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 280
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 188
	switch_pre : SWITCH '(' . exp ')'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 281
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 189
	iteration_statement : WHILE M . '(' exp ')' M statement

	'('  shift 282


state 190
	iteration_statement : DO M . statement WHILE M '(' exp ')' ';'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 283
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 191
	iteration_statement : FOR '(' . exp_statement M exp_statement ')' M statement
	iteration_statement : FOR '(' . exp_statement M exp_statement M exp P ')' M statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	exp_statement  goto 284
	postfix_pre_exp  goto 144


state 192
	jump_statement : GOTO ID . ';'

	';'  shift 285


state 193
	jump_statement : CONTINUE ';' .  (221)

	.  reduce 221


state 194
	jump_statement : BREAK ';' .  (222)

	.  reduce 222


state 195
	jump_statement : RETURN ';' .  (223)

	.  reduce 223


state 196
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 232
	';'  shift 286


state 197
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	multiplicative_exp  goto 287
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 198
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	multiplicative_exp  goto 288
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 199
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 289
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 200
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 290
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 201
	and_exp : and_exp '&' . equality_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 291
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 202
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	cast_exp  goto 292
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 203
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	cast_exp  goto 293
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 204
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	cast_exp  goto 294
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 205
	multiplicative_exp : multiplicative_exp '^' . cast_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	cast_exp  goto 295
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 206
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 296
	primary_exp  goto 114
	multiplicative_exp  goto 115
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 207
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 297
	primary_exp  goto 114
	multiplicative_exp  goto 115
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 208
	unary_exp : unary_operator cast_exp .  (21)

	.  reduce 21


state 209
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 298
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 210
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 299
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 211
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 300
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 212
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 301
	unary_operator  goto 117
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 213
	postfix_pre_exp : postfix_exp '(' .  (7)

	.  reduce 7


state 214
	postfix_exp : postfix_exp '.' . ID

	ID  shift 302


state 215
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 303
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 216
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 304


state 217
	postfix_exp : postfix_exp INC_OP .  (14)

	.  reduce 14


state 218
	postfix_exp : postfix_exp DEC_OP .  (15)

	.  reduce 15


state 219
	labeled_statement : default_pre statement .  (196)

	.  reduce 196


state 220
	assignment_operator : '=' .  (68)

	.  reduce 68


state 221
	assignment_operator : MUL_ASSIGN .  (69)

	.  reduce 69


state 222
	assignment_operator : DIV_ASSIGN .  (70)

	.  reduce 70


state 223
	assignment_operator : MOD_ASSIGN .  (71)

	.  reduce 71


state 224
	assignment_operator : ADD_ASSIGN .  (72)

	.  reduce 72


state 225
	assignment_operator : SUB_ASSIGN .  (73)

	.  reduce 73


state 226
	assignment_operator : LEFT_ASSIGN .  (74)

	.  reduce 74


state 227
	assignment_operator : RIGHT_ASSIGN .  (75)

	.  reduce 75


state 228
	assignment_operator : AND_ASSIGN .  (76)

	.  reduce 76


state 229
	assignment_operator : XOR_ASSIGN .  (77)

	.  reduce 77


state 230
	assignment_operator : OR_ASSIGN .  (78)

	.  reduce 78


state 231
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 305
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 232
	exp : exp ',' . assignment_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 306
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 233
	exp_statement : exp ';' .  (206)

	.  reduce 206


state 234
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 307
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 235
	logical_or_exp : logical_or_exp OR_OP . M logical_and_exp
	M : .  (59)

	.  reduce 59

	M  goto 308


state 236
	logical_and_exp : logical_and_exp AND_OP . M inclusive_or_exp
	M : .  (59)

	.  reduce 59

	M  goto 309


state 237
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	exclusive_or_exp  goto 310
	postfix_pre_exp  goto 144


state 238
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 311
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 239
	compound_statement : '{' declaration_list '}' .  (199)

	.  reduce 199


state 240
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (59)

	'}'  shift 312
	.  reduce 59

	M  goto 242


state 241
	compound_statement : '{' statement_list '}' .  (198)

	.  reduce 198


state 242
	statement_list : statement_list M . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 313
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 243
	selection_statement : switch_pre statement .  (214)

	.  reduce 214


state 244
	postfix_exp : postfix_pre_exp ')' .  (10)

	.  reduce 10


state 245
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 314
	','  shift 315


state 246
	argument_exp_list : assignment_exp .  (16)

	.  reduce 16


state 247
	declaration_list : declaration_list M declaration .  (202)

	.  reduce 202


state 248
	direct_declarator : direct_declarator '[' constant_exp ']' .  (147)

	.  reduce 147


state 249
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'{'  shift 249
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 250
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	initializer  goto 316
	initializer_list  goto 317
	postfix_pre_exp  goto 144


state 250
	initializer : assignment_exp .  (181)

	.  reduce 181


state 251
	init_declarator : declarator '=' initializer .  (93)

	.  reduce 93


state 252
	init_declarator_list : init_declarator_list ',' init_declarator .  (91)

	.  reduce 91


state 253
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (229)

	.  reduce 229


state 254
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (113)

	.  reduce 113


state 255
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (59)

	'}'  shift 318
	.  reduce 59

	M  goto 146


state 256
	direct_abstract_declarator : '(' ')' .  (177)

	.  reduce 177


state 257
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 319


state 258
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 320


state 259
	direct_abstract_declarator : '[' ']' .  (173)

	.  reduce 173


state 260
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 321


state 261
	abstract_declarator : pointer direct_abstract_declarator .  (171)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 262
	'['  shift 263
	.  reduce 171


state 262
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

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	declaration_specifiers  goto 71
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	parameter_type_list  goto 323
	parameter_list  goto 73
	parameter_declaration  goto 74


state 263
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	']'  shift 324
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	inclusive_or_exp  goto 127
	conditional_exp  goto 150
	exclusive_or_exp  goto 129
	constant_exp  goto 325
	postfix_pre_exp  goto 144


state 264
	parameter_type_list : parameter_list ',' ELLIPSIS .  (159)

	.  reduce 159


state 265
	parameter_list : parameter_list ',' parameter_declaration .  (161)

	.  reduce 161


state 266
	identifier_list : identifier_list ',' ID .  (166)

	.  reduce 166


state 267
	enumerator : ID '=' constant_exp .  (139)

	.  reduce 139


state 268
	enumerator_list : enumerator_list ',' enumerator .  (137)

	.  reduce 137


state 269
	enum_specifier : ENUM ID '{' enumerator_list '}' .  (134)

	.  reduce 134


state 270
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 271
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 271
	')'  shift 256
	'*'  shift 2
	'['  shift 161
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

	enum_specifier  goto 24
	struct_or_union_def  goto 27
	pointer  goto 272
	declaration_specifiers  goto 71
	type_specifier  goto 31
	struct_or_union_specifier  goto 32
	struct_or_union  goto 33
	type_qualifier  goto 34
	storage_class_specifier  goto 35
	parameter_type_list  goto 257
	parameter_list  goto 73
	abstract_declarator  goto 258
	parameter_declaration  goto 74
	direct_abstract_declarator  goto 165


state 272
	abstract_declarator : pointer .  (169)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 271
	'['  shift 161
	.  reduce 169

	direct_abstract_declarator  goto 261


state 273
	type_name : specifier_qualifier_list abstract_declarator .  (168)

	.  reduce 168


state 274
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (124)

	.  reduce 124


state 275
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (126)

	.  reduce 126


state 276
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	primary_exp  goto 114
	unary_operator  goto 117
	cast_exp  goto 326
	postfix_exp  goto 120
	unary_exp  goto 149
	postfix_pre_exp  goto 144


state 277
	labeled_statement : ID ':' statement .  (194)

	.  reduce 194


state 278
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 327


state 279
	labeled_statement : CASE constant_exp ':' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 328


state 280
	exp : exp . ',' assignment_exp
	open_statement : IF '(' exp . ')' M stmt
	open_statement : IF '(' exp . ')' M matched_statement P ELSE M open_statement
	matched_statement : IF '(' exp . ')' M matched_statement P ELSE M matched_statement

	')'  shift 329
	','  shift 232


state 281
	exp : exp . ',' assignment_exp
	switch_pre : SWITCH '(' exp . ')'

	')'  shift 330
	','  shift 232


state 282
	iteration_statement : WHILE M '(' . exp ')' M statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 331
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 283
	iteration_statement : DO M statement . WHILE M '(' exp ')' ';'

	WHILE  shift 332


state 284
	iteration_statement : FOR '(' exp_statement . M exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement . M exp_statement M exp P ')' M statement
	M : .  (59)

	.  reduce 59

	M  goto 333


state 285
	jump_statement : GOTO ID ';' .  (220)

	.  reduce 220


state 286
	jump_statement : RETURN exp ';' .  (224)

	.  reduce 224


287: shift-reduce conflict (shift 205, reduce 38) on '^'
state 287
	multiplicative_exp : multiplicative_exp . '^' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (38)
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 202
	'*'  shift 203
	'/'  shift 204
	'^'  shift 205
	.  reduce 38


288: shift-reduce conflict (shift 205, reduce 39) on '^'
state 288
	multiplicative_exp : multiplicative_exp . '^' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (39)
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 202
	'*'  shift 203
	'/'  shift 204
	'^'  shift 205
	.  reduce 39


state 289
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (49)
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp

	'<'  shift 209
	'>'  shift 210
	LE_OP  shift 211
	GE_OP  shift 212
	.  reduce 49


state 290
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (50)
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp

	'<'  shift 209
	'>'  shift 210
	LE_OP  shift 211
	GE_OP  shift 212
	.  reduce 50


state 291
	and_exp : and_exp '&' equality_exp .  (52)
	equality_exp : equality_exp . EQ_OP relational_exp
	equality_exp : equality_exp . NE_OP relational_exp

	EQ_OP  shift 199
	NE_OP  shift 200
	.  reduce 52


state 292
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (36)

	.  reduce 36


state 293
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (34)

	.  reduce 34


state 294
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (35)

	.  reduce 35


state 295
	multiplicative_exp : multiplicative_exp '^' cast_exp .  (33)

	.  reduce 33


state 296
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (41)

	'+'  shift 197
	'-'  shift 198
	.  reduce 41


state 297
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (42)

	'+'  shift 197
	'-'  shift 198
	.  reduce 42


state 298
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '<' shift_exp .  (44)

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 44


state 299
	relational_exp : relational_exp '>' shift_exp .  (45)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 45


state 300
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (46)
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 46


state 301
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp GE_OP shift_exp .  (47)
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 206
	RIGHT_OP  shift 207
	.  reduce 47


state 302
	postfix_exp : postfix_exp '.' ID .  (12)

	.  reduce 12


state 303
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 232
	']'  shift 334


state 304
	postfix_exp : postfix_exp PTR_OP ID .  (13)

	.  reduce 13


state 305
	assignment_exp : unary_exp assignment_operator assignment_exp .  (67)

	.  reduce 67


state 306
	exp : exp ',' assignment_exp .  (80)

	.  reduce 80


state 307
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 232
	':'  shift 335


state 308
	logical_or_exp : logical_or_exp OR_OP M . logical_and_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	logical_and_exp  goto 336
	inclusive_or_exp  goto 127
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 309
	logical_and_exp : logical_and_exp AND_OP M . inclusive_or_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	inclusive_or_exp  goto 337
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 310
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (56)

	'^'  shift 238
	.  reduce 56


state 311
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (54)

	'&'  shift 201
	.  reduce 54


state 312
	compound_statement : '{' declaration_list statement_list '}' .  (200)

	.  reduce 200


state 313
	statement_list : statement_list M statement .  (204)

	.  reduce 204


state 314
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (11)

	.  reduce 11


state 315
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 338
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 316
	initializer_list : initializer .  (184)

	.  reduce 184


state 317
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'

	','  shift 339
	'}'  shift 340


state 318
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (112)

	.  reduce 112


state 319
	direct_abstract_declarator : '(' parameter_type_list ')' .  (178)

	.  reduce 178


state 320
	direct_abstract_declarator : '(' abstract_declarator ')' .  (172)

	.  reduce 172


state 321
	direct_abstract_declarator : '[' constant_exp ']' .  (174)

	.  reduce 174


state 322
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (179)

	.  reduce 179


state 323
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 341


state 324
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (175)

	.  reduce 175


state 325
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp . ']'

	']'  shift 342


state 326
	cast_exp : '(' type_name ')' cast_exp .  (31)

	.  reduce 31


state 327
	unary_exp : SIZEOF '(' type_name ')' .  (23)

	.  reduce 23


state 328
	labeled_statement : CASE constant_exp ':' M . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 343
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 329
	open_statement : IF '(' exp ')' . M stmt
	open_statement : IF '(' exp ')' . M matched_statement P ELSE M open_statement
	matched_statement : IF '(' exp ')' . M matched_statement P ELSE M matched_statement
	M : .  (59)

	.  reduce 59

	M  goto 344


state 330
	switch_pre : SWITCH '(' exp ')' .  (215)

	.  reduce 215


state 331
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE M '(' exp . ')' M statement

	')'  shift 345
	','  shift 232


state 332
	iteration_statement : DO M statement WHILE . M '(' exp ')' ';'
	M : .  (59)

	.  reduce 59

	M  goto 346


state 333
	iteration_statement : FOR '(' exp_statement M . exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement M . exp_statement M exp P ')' M statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	exp_statement  goto 347
	postfix_pre_exp  goto 144


state 334
	postfix_exp : postfix_exp '[' exp ']' .  (9)

	.  reduce 9


state 335
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 149
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	inclusive_or_exp  goto 127
	conditional_exp  goto 348
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 336
	logical_or_exp : logical_or_exp OR_OP M logical_and_exp .  (63)
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp

	AND_OP  shift 236
	.  reduce 63


state 337
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : logical_and_exp AND_OP M inclusive_or_exp .  (58)

	'|'  shift 237
	.  reduce 58


state 338
	argument_exp_list : argument_exp_list ',' assignment_exp .  (17)

	.  reduce 17


state 339
	initializer_list : initializer_list ',' . initializer
	initializer : '{' initializer_list ',' . '}'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'{'  shift 249
	'}'  shift 349
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 250
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	initializer  goto 350
	postfix_pre_exp  goto 144


state 340
	initializer : '{' initializer_list '}' .  (182)

	.  reduce 182


state 341
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (180)

	.  reduce 180


state 342
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (176)

	.  reduce 176


state 343
	labeled_statement : CASE constant_exp ':' M statement .  (195)

	.  reduce 195


state 344
	open_statement : IF '(' exp ')' M . stmt
	open_statement : IF '(' exp ')' M . matched_statement P ELSE M open_statement
	matched_statement : IF '(' exp ')' M . matched_statement P ELSE M matched_statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	IF  shift 102
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	compound_statement  goto 134
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 351
	open_statement  goto 139
	stmt  goto 352
	other  goto 353
	postfix_pre_exp  goto 144


state 345
	iteration_statement : WHILE M '(' exp ')' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 354


state 346
	iteration_statement : DO M statement WHILE M . '(' exp ')' ';'

	'('  shift 355


state 347
	iteration_statement : FOR '(' exp_statement M exp_statement . ')' M statement
	iteration_statement : FOR '(' exp_statement M exp_statement . M exp P ')' M statement
	M : .  (59)

	')'  shift 356
	.  reduce 59

	M  goto 357


state 348
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (65)

	.  reduce 65


state 349
	initializer : '{' initializer_list ',' '}' .  (183)

	.  reduce 183


state 350
	initializer_list : initializer_list ',' initializer .  (185)

	.  reduce 185


351: reduce-reduce conflict (reduce 61, reduce 207) on ELSE
state 351
	stmt : matched_statement .  (207)
	open_statement : IF '(' exp ')' M matched_statement . P ELSE M open_statement
	matched_statement : IF '(' exp ')' M matched_statement . P ELSE M matched_statement
	P : .  (61)

	ELSE  reduce 61
	.  reduce 207

	P  goto 358


state 352
	open_statement : IF '(' exp ')' M stmt .  (211)

	.  reduce 211


state 353
	matched_statement : other .  (210)

	.  reduce 210


state 354
	iteration_statement : WHILE M '(' exp ')' M . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 359
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 355
	iteration_statement : DO M statement WHILE M '(' . exp ')' ';'

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 360
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 356
	iteration_statement : FOR '(' exp_statement M exp_statement ')' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 361


state 357
	iteration_statement : FOR '(' exp_statement M exp_statement M . exp P ')' M statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 362
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	postfix_pre_exp  goto 144


state 358
	open_statement : IF '(' exp ')' M matched_statement P . ELSE M open_statement
	matched_statement : IF '(' exp ')' M matched_statement P . ELSE M matched_statement

	ELSE  shift 363


state 359
	iteration_statement : WHILE M '(' exp ')' M statement .  (216)

	.  reduce 216


state 360
	exp : exp . ',' assignment_exp
	iteration_statement : DO M statement WHILE M '(' exp . ')' ';'

	')'  shift 364
	','  shift 232


state 361
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 365
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 362
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement M exp_statement M exp . P ')' M statement
	P : .  (61)

	','  shift 232
	.  reduce 61

	P  goto 366


state 363
	open_statement : IF '(' exp ')' M matched_statement P ELSE . M open_statement
	matched_statement : IF '(' exp ')' M matched_statement P ELSE . M matched_statement
	M : .  (59)

	.  reduce 59

	M  goto 367


state 364
	iteration_statement : DO M statement WHILE M '(' exp ')' . ';'

	';'  shift 368


state 365
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M statement .  (218)

	.  reduce 218


state 366
	iteration_statement : FOR '(' exp_statement M exp_statement M exp P . ')' M statement

	')'  shift 369


state 367
	open_statement : IF '(' exp ')' M matched_statement P ELSE M . open_statement
	matched_statement : IF '(' exp ')' M matched_statement P ELSE M . matched_statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 148
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	IF  shift 102
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	compound_statement  goto 134
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 370
	open_statement  goto 371
	other  goto 353
	postfix_pre_exp  goto 144


state 368
	iteration_statement : DO M statement WHILE M '(' exp ')' ';' .  (217)

	.  reduce 217


state 369
	iteration_statement : FOR '(' exp_statement M exp_statement M exp P ')' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 372


state 370
	matched_statement : IF '(' exp ')' M matched_statement P ELSE M matched_statement .  (209)

	.  reduce 209


state 371
	open_statement : IF '(' exp ')' M matched_statement P ELSE M open_statement .  (212)

	.  reduce 212


state 372
	iteration_statement : FOR '(' exp_statement M exp_statement M exp P ')' M . statement

	'!'  shift 83
	'&'  shift 84
	'('  shift 85
	'*'  shift 86
	'+'  shift 87
	'-'  shift 88
	';'  shift 89
	'{'  shift 46
	'~'  shift 91
	ID  shift 92
	CONSTANT  shift 93
	STRING_LITERAL  shift 94
	SIZEOF  shift 95
	INC_OP  shift 96
	DEC_OP  shift 97
	TRUE  shift 98
	FALSE  shift 99
	CASE  shift 100
	DEFAULT  shift 101
	IF  shift 102
	SWITCH  shift 103
	WHILE  shift 104
	DO  shift 105
	FOR  shift 106
	GOTO  shift 107
	CONTINUE  shift 108
	BREAK  shift 109
	RETURN  shift 110

	additive_exp  goto 111
	equality_exp  goto 112
	and_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	shift_exp  goto 116
	unary_operator  goto 117
	relational_exp  goto 118
	cast_exp  goto 119
	postfix_exp  goto 120
	default_pre  goto 121
	unary_exp  goto 122
	exp  goto 123
	logical_or_exp  goto 124
	logical_and_exp  goto 125
	assignment_exp  goto 126
	inclusive_or_exp  goto 127
	conditional_exp  goto 128
	exclusive_or_exp  goto 129
	jump_statement  goto 130
	labeled_statement  goto 132
	compound_statement  goto 134
	statement  goto 373
	exp_statement  goto 136
	iteration_statement  goto 137
	matched_statement  goto 138
	open_statement  goto 139
	stmt  goto 140
	switch_pre  goto 141
	other  goto 142
	selection_statement  goto 143
	postfix_pre_exp  goto 144


state 373
	iteration_statement : FOR '(' exp_statement M exp_statement M exp P ')' M statement .  (219)

	.  reduce 219


Rules never reduced
	N :  (60)
	struct_declaration_list : struct_declaration  (120)
	struct_declaration_list : struct_declaration_list struct_declaration  (121)
	struct_declaration : specifier_qualifier_list struct_declarator_list ';'  (122)
	struct_declaration : assignment_exp struct_declarator_list ';'  (123)
	struct_declarator_list : struct_declarator  (128)
	struct_declarator_list : struct_declarator_list ',' struct_declarator  (129)
	struct_declarator : declarator  (130)
	struct_declarator : ':' constant_exp  (131)
	struct_declarator : declarator ':' constant_exp  (132)


##############################################################################
# Summary
##############################################################################

State 2 contains 3 shift-reduce conflict(s)
State 31 contains 1 shift-reduce conflict(s)
State 42 contains 3 shift-reduce conflict(s)
State 115 contains 1 shift-reduce conflict(s)
State 142 contains 30 reduce-reduce conflict(s)
State 176 contains 1 shift-reduce conflict(s)
State 287 contains 1 shift-reduce conflict(s)
State 288 contains 1 shift-reduce conflict(s)
State 351 contains 1 reduce-reduce conflict(s)


86 token(s), 77 nonterminal(s)
233 grammar rule(s), 374 state(s)


##############################################################################
# End of File
##############################################################################
