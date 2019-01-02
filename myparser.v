#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 85 of your 30 day trial period.
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
# Time: 17:23:14
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

  211  open_statement : IF '(' exp ')' M stmt P
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	translation_unit  goto 26
	pointer  goto 27
	enum_specifier  goto 28
	direct_declarator  goto 29
	declarator  goto 30
	declaration_specifiers  goto 31
	declaration  goto 32
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36
	function_definition  goto 37
	direct_pre_declarator  goto 38
	external_declaration  goto 39


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	pointer  goto 27
	direct_declarator  goto 29
	declarator  goto 40
	direct_pre_declarator  goto 38


2: shift-reduce conflict (shift 2, reduce 152) on '*'
2: shift-reduce conflict (shift 18, reduce 152) on CONST
2: shift-reduce conflict (shift 19, reduce 152) on VOLATILE
state 2
	pointer : '*' .  (152)
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' . pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 152

	type_qualifier  goto 41
	type_qualifier_list  goto 42
	pointer  goto 43


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
	enum_specifier : ENUM . ID
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'

	'{'  shift 44
	ID  shift 45


state 24
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	enum_specifier  goto 28
	declaration_specifiers  goto 46
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 25
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_def : struct_or_union . '{' declaration_list '}'
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'

	'{'  shift 47
	ID  shift 48


state 26
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	pointer  goto 27
	enum_specifier  goto 28
	direct_declarator  goto 29
	declarator  goto 30
	declaration_specifiers  goto 31
	declaration  goto 32
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36
	function_definition  goto 37
	direct_pre_declarator  goto 38
	external_declaration  goto 49


state 27
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 50
	direct_pre_declarator  goto 38


state 28
	type_specifier : enum_specifier .  (109)

	.  reduce 109


state 29
	declarator : direct_declarator .  (143)
	direct_declarator : direct_declarator . '[' ']'
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'

	'('  shift 51
	'['  shift 52
	.  reduce 143


state 30
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

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

	type_qualifier  goto 24
	struct_or_union  goto 25
	declaration_list  goto 54
	enum_specifier  goto 28
	compound_statement  goto 55
	declaration_specifiers  goto 56
	declaration  goto 57
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 31
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator compound_statement
	function_definition : declaration_specifiers . declarator declaration_list compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 58
	ID  shift 3

	pointer  goto 27
	direct_declarator  goto 29
	declarator  goto 59
	init_declarator_list  goto 60
	init_declarator  goto 61
	direct_pre_declarator  goto 38


state 32
	external_declaration : declaration .  (228)

	.  reduce 228


state 33
	declaration_specifiers : storage_class_specifier . declaration_specifiers
	declaration_specifiers : storage_class_specifier .  (84)

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

	type_qualifier  goto 24
	struct_or_union  goto 25
	enum_specifier  goto 28
	declaration_specifiers  goto 62
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


34: shift-reduce conflict (shift 2, reduce 86) on '*'
state 34
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	pointer  goto 63
	enum_specifier  goto 28
	declaration_specifiers  goto 64
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 35
	type_specifier : struct_or_union_specifier .  (108)

	.  reduce 108


state 36
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 65
	ID  shift 3

	pointer  goto 27
	direct_declarator  goto 29
	declarator  goto 66
	def_concat  goto 67
	init_declarator_list  goto 68
	init_declarator  goto 61
	direct_pre_declarator  goto 38


state 37
	external_declaration : function_definition .  (227)

	.  reduce 227


state 38
	direct_declarator : direct_pre_declarator . parameter_type_list ')'
	direct_declarator : direct_pre_declarator . ')'
	direct_declarator : direct_pre_declarator . identifier_list ')'

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

	type_qualifier  goto 24
	identifier_list  goto 71
	struct_or_union  goto 25
	parameter_list  goto 72
	parameter_type_list  goto 73
	enum_specifier  goto 28
	parameter_declaration  goto 74
	declaration_specifiers  goto 75
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 39
	translation_unit : external_declaration .  (225)

	.  reduce 225


state 40
	direct_declarator : '(' declarator . ')'

	')'  shift 76


state 41
	type_qualifier_list : type_qualifier .  (156)

	.  reduce 156


42: shift-reduce conflict (shift 2, reduce 153) on '*'
42: shift-reduce conflict (shift 18, reduce 153) on CONST
42: shift-reduce conflict (shift 19, reduce 153) on VOLATILE
state 42
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (153)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 153

	type_qualifier  goto 77
	pointer  goto 78


state 43
	pointer : '*' pointer .  (154)

	.  reduce 154


state 44
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 79

	enumerator  goto 80
	enumerator_list  goto 81


state 45
	enum_specifier : ENUM ID .  (135)
	enum_specifier : ENUM ID . '{' enumerator_list '}'

	'{'  shift 82
	.  reduce 135


state 46
	declaration_specifiers : type_qualifier declaration_specifiers .  (89)

	.  reduce 89


state 47
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	declaration_list  goto 83
	enum_specifier  goto 28
	declaration_specifiers  goto 56
	declaration  goto 57
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 48
	struct_or_union_specifier : struct_or_union ID .  (117)
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'

	'{'  shift 84
	.  reduce 117


state 49
	translation_unit : translation_unit external_declaration .  (226)

	.  reduce 226


state 50
	direct_declarator : direct_declarator . '[' ']'
	declarator : pointer direct_declarator .  (142)
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'

	'('  shift 51
	'['  shift 52
	.  reduce 142


state 51
	direct_pre_declarator : direct_declarator '(' .  (144)

	.  reduce 144


state 52
	direct_declarator : direct_declarator '[' . ']'
	direct_declarator : direct_declarator '[' . constant_exp ']'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	']'  shift 91
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	logical_and_exp  goto 114
	conditional_exp  goto 115
	constant_exp  goto 116
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 53
	compound_statement : '{' . '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . declaration_list '}'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'}'  shift 120
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TYPE_NAME  shift 4
	TRUE  shift 99
	FALSE  shift 100
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
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	type_qualifier  goto 24
	statement  goto 136
	struct_or_union  goto 25
	declaration_list  goto 137
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	enum_specifier  goto 28
	compound_statement  goto 141
	statement_list  goto 142
	inclusive_or_exp  goto 112
	declaration_specifiers  goto 56
	declaration  goto 57
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	struct_or_union_def  goto 36
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 54
	declaration_list : declaration_list . M declaration
	function_definition : declarator declaration_list . compound_statement
	M : .  (59)

	'{'  shift 53
	.  reduce 59

	compound_statement  goto 152
	M  goto 153


state 55
	function_definition : declarator compound_statement .  (232)

	.  reduce 232


state 56
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 58
	ID  shift 3

	pointer  goto 27
	direct_declarator  goto 29
	declarator  goto 66
	init_declarator_list  goto 60
	init_declarator  goto 61
	direct_pre_declarator  goto 38


state 57
	declaration_list : declaration .  (201)

	.  reduce 201


state 58
	declaration : declaration_specifiers ';' .  (82)

	.  reduce 82


state 59
	init_declarator : declarator .  (92)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . compound_statement
	function_definition : declaration_specifiers declarator . declaration_list compound_statement

	'='  shift 154
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
	.  reduce 92

	type_qualifier  goto 24
	struct_or_union  goto 25
	declaration_list  goto 155
	enum_specifier  goto 28
	compound_statement  goto 156
	declaration_specifiers  goto 56
	declaration  goto 57
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 60
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 157
	';'  shift 158


state 61
	init_declarator_list : init_declarator .  (90)

	.  reduce 90


state 62
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (85)

	.  reduce 85


state 63
	type_specifier : type_specifier pointer .  (111)

	.  reduce 111


state 64
	declaration_specifiers : type_specifier declaration_specifiers .  (87)

	.  reduce 87


state 65
	def_concat : ';' .  (114)

	.  reduce 114


state 66
	init_declarator : declarator .  (92)
	init_declarator : declarator . '=' initializer

	'='  shift 154
	.  reduce 92


state 67
	struct_or_union_specifier : struct_or_union_def def_concat .  (116)

	.  reduce 116


state 68
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 157
	';'  shift 159


state 69
	direct_declarator : direct_pre_declarator ')' .  (151)

	.  reduce 151


state 70
	identifier_list : ID .  (165)

	.  reduce 165


state 71
	identifier_list : identifier_list . ',' ID
	direct_declarator : direct_pre_declarator identifier_list . ')'

	')'  shift 160
	','  shift 161


state 72
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_type_list : parameter_list .  (158)
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 162
	.  reduce 158


state 73
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 163


state 74
	parameter_list : parameter_declaration .  (160)

	.  reduce 160


state 75
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (164)

	'('  shift 164
	'*'  shift 2
	'['  shift 165
	ID  shift 3
	.  reduce 164

	abstract_declarator  goto 166
	direct_abstract_declarator  goto 167
	pointer  goto 168
	direct_declarator  goto 29
	declarator  goto 169
	direct_pre_declarator  goto 38


state 76
	direct_declarator : '(' declarator ')' .  (146)

	.  reduce 146


state 77
	type_qualifier_list : type_qualifier_list type_qualifier .  (157)

	.  reduce 157


state 78
	pointer : '*' type_qualifier_list pointer .  (155)

	.  reduce 155


state 79
	enumerator : ID .  (138)
	enumerator : ID . '=' constant_exp

	'='  shift 170
	.  reduce 138


state 80
	enumerator_list : enumerator .  (136)

	.  reduce 136


state 81
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 171
	'}'  shift 172


state 82
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 79

	enumerator  goto 80
	enumerator_list  goto 173


state 83
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (59)

	'}'  shift 174
	.  reduce 59

	M  goto 153


state 84
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	declaration_list  goto 175
	enum_specifier  goto 28
	declaration_specifiers  goto 56
	declaration  goto 57
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 85
	unary_operator : '!' .  (29)

	.  reduce 29


state 86
	unary_operator : '&' .  (24)

	.  reduce 24


state 87
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TYPE_NAME  shift 4
	TRUE  shift 99
	FALSE  shift 100
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

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	type_qualifier  goto 176
	struct_or_union  goto 25
	type_name  goto 177
	enum_specifier  goto 28
	specifier_qualifier_list  goto 178
	inclusive_or_exp  goto 112
	type_specifier  goto 179
	struct_or_union_specifier  goto 35
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 180
	exclusive_or_exp  goto 117
	struct_or_union_def  goto 36
	postfix_pre_exp  goto 118


state 88
	unary_operator : '*' .  (25)

	.  reduce 25


state 89
	unary_operator : '+' .  (26)

	.  reduce 26


state 90
	unary_operator : '-' .  (27)

	.  reduce 27


state 91
	direct_declarator : direct_declarator '[' ']' .  (148)

	.  reduce 148


state 92
	unary_operator : '~' .  (28)

	.  reduce 28


state 93
	primary_exp : ID .  (1)

	.  reduce 1


state 94
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 95
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 96
	unary_exp : SIZEOF . '(' type_name ')'
	unary_exp : SIZEOF . unary_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 181
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 182
	postfix_exp  goto 104
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 97
	unary_exp : INC_OP . unary_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 183
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 184
	postfix_exp  goto 104
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 98
	unary_exp : DEC_OP . unary_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 183
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 185
	postfix_exp  goto 104
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 99
	primary_exp : TRUE .  (5)

	.  reduce 5


state 100
	primary_exp : FALSE .  (6)

	.  reduce 6


state 101
	unary_exp : unary_operator . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 186
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 102
	relational_exp : shift_exp .  (43)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 187
	RIGHT_OP  shift 188
	.  reduce 43


state 103
	cast_exp : unary_exp .  (30)

	.  reduce 30


state 104
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (18)

	'('  shift 189
	'.'  shift 190
	'['  shift 191
	PTR_OP  shift 192
	INC_OP  shift 193
	DEC_OP  shift 194
	.  reduce 18


state 105
	multiplicative_exp : cast_exp .  (32)

	.  reduce 32


state 106
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : equality_exp .  (51)
	equality_exp : equality_exp . NE_OP relational_exp

	EQ_OP  shift 195
	NE_OP  shift 196
	.  reduce 51


107: shift-reduce conflict (shift 200, reduce 37) on '^'
state 107
	multiplicative_exp : multiplicative_exp . '^' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : multiplicative_exp .  (37)
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 197
	'*'  shift 198
	'/'  shift 199
	'^'  shift 200
	.  reduce 37


state 108
	additive_exp : additive_exp . '-' multiplicative_exp
	shift_exp : additive_exp .  (40)
	additive_exp : additive_exp . '+' multiplicative_exp

	'+'  shift 201
	'-'  shift 202
	.  reduce 40


state 109
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp
	equality_exp : relational_exp .  (48)

	'<'  shift 203
	'>'  shift 204
	LE_OP  shift 205
	GE_OP  shift 206
	.  reduce 48


state 110
	exclusive_or_exp : and_exp .  (53)
	and_exp : and_exp . '&' equality_exp

	'&'  shift 207
	.  reduce 53


state 111
	postfix_exp : primary_exp .  (8)

	.  reduce 8


state 112
	logical_and_exp : inclusive_or_exp .  (57)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 208
	.  reduce 57


state 113
	logical_or_exp : logical_or_exp . OR_OP M logical_and_exp
	conditional_exp : logical_or_exp .  (64)
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp

	'?'  shift 209
	OR_OP  shift 210
	.  reduce 64


state 114
	logical_or_exp : logical_and_exp .  (62)
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp

	AND_OP  shift 211
	.  reduce 62


state 115
	constant_exp : conditional_exp .  (81)

	.  reduce 81


state 116
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 212


state 117
	inclusive_or_exp : exclusive_or_exp .  (55)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 213
	.  reduce 55


state 118
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	')'  shift 214
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	argument_exp_list  goto 215
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 216
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 119
	exp_statement : ';' .  (205)

	.  reduce 205


state 120
	compound_statement : '{' '}' .  (197)

	.  reduce 197


state 121
	primary_exp : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 217
	.  reduce 1


state 122
	labeled_statement : CASE . constant_exp ':' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	logical_and_exp  goto 114
	conditional_exp  goto 115
	constant_exp  goto 218
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 123
	default_pre : DEFAULT . ':'

	':'  shift 219


state 124
	open_statement : IF . '(' exp ')' M matched_statement P ELSE M open_statement
	matched_statement : IF . '(' exp ')' M matched_statement P ELSE M matched_statement
	open_statement : IF . '(' exp ')' M stmt P

	'('  shift 220


state 125
	switch_pre : SWITCH . '(' exp ')'

	'('  shift 221


state 126
	iteration_statement : WHILE . M '(' exp ')' M statement
	M : .  (59)

	.  reduce 59

	M  goto 222


state 127
	iteration_statement : DO . M statement WHILE M '(' exp ')' ';'
	M : .  (59)

	.  reduce 59

	M  goto 223


state 128
	iteration_statement : FOR . '(' exp_statement M exp_statement ')' M statement
	iteration_statement : FOR . '(' exp_statement M exp_statement M exp P ')' M statement

	'('  shift 224


state 129
	jump_statement : GOTO . ID ';'

	ID  shift 225


state 130
	jump_statement : CONTINUE . ';'

	';'  shift 226


state 131
	jump_statement : BREAK . ';'

	';'  shift 227


state 132
	jump_statement : RETURN . ';'
	jump_statement : RETURN . exp ';'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 228
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 229
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 133
	labeled_statement : default_pre . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 230
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 134
	cast_exp : unary_exp .  (30)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 231
	MUL_ASSIGN  shift 232
	DIV_ASSIGN  shift 233
	MOD_ASSIGN  shift 234
	ADD_ASSIGN  shift 235
	SUB_ASSIGN  shift 236
	LEFT_ASSIGN  shift 237
	RIGHT_ASSIGN  shift 238
	AND_ASSIGN  shift 239
	XOR_ASSIGN  shift 240
	OR_ASSIGN  shift 241
	.  reduce 30

	assignment_operator  goto 242


state 135
	other : exp_statement .  (187)

	.  reduce 187


state 136
	statement_list : statement .  (203)

	.  reduce 203


state 137
	declaration_list : declaration_list . M declaration
	compound_statement : '{' declaration_list . statement_list '}'
	compound_statement : '{' declaration_list . '}'
	M : .  (59)

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'}'  shift 243
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132
	.  reduce 59

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 136
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	statement_list  goto 244
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	M  goto 153
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 138
	other : iteration_statement .  (188)

	.  reduce 188


state 139
	other : jump_statement .  (189)

	.  reduce 189


state 140
	statement : labeled_statement .  (190)

	.  reduce 190


state 141
	other : compound_statement .  (186)

	.  reduce 186


state 142
	statement_list : statement_list . M statement
	compound_statement : '{' statement_list . '}'
	M : .  (59)

	'}'  shift 245
	.  reduce 59

	M  goto 246


state 143
	exp : assignment_exp .  (79)

	.  reduce 79


state 144
	assignment_exp : conditional_exp .  (66)

	.  reduce 66


state 145
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 247
	';'  shift 248


146: reduce-reduce conflict (reduce 191, reduce 210) on '!'
146: reduce-reduce conflict (reduce 191, reduce 210) on '&'
146: reduce-reduce conflict (reduce 191, reduce 210) on '('
146: reduce-reduce conflict (reduce 191, reduce 210) on '*'
146: reduce-reduce conflict (reduce 191, reduce 210) on '+'
146: reduce-reduce conflict (reduce 191, reduce 210) on '-'
146: reduce-reduce conflict (reduce 191, reduce 210) on ';'
146: reduce-reduce conflict (reduce 191, reduce 210) on '{'
146: reduce-reduce conflict (reduce 191, reduce 210) on '}'
146: reduce-reduce conflict (reduce 191, reduce 210) on '~'
146: reduce-reduce conflict (reduce 191, reduce 210) on ID
146: reduce-reduce conflict (reduce 191, reduce 210) on CONSTANT
146: reduce-reduce conflict (reduce 191, reduce 210) on STRING_LITERAL
146: reduce-reduce conflict (reduce 191, reduce 210) on SIZEOF
146: reduce-reduce conflict (reduce 191, reduce 210) on INC_OP
146: reduce-reduce conflict (reduce 191, reduce 210) on DEC_OP
146: reduce-reduce conflict (reduce 191, reduce 210) on TRUE
146: reduce-reduce conflict (reduce 191, reduce 210) on FALSE
146: reduce-reduce conflict (reduce 191, reduce 210) on CASE
146: reduce-reduce conflict (reduce 191, reduce 210) on DEFAULT
146: reduce-reduce conflict (reduce 191, reduce 210) on IF
146: reduce-reduce conflict (reduce 191, reduce 210) on ELSE
146: reduce-reduce conflict (reduce 191, reduce 210) on SWITCH
146: reduce-reduce conflict (reduce 191, reduce 210) on WHILE
146: reduce-reduce conflict (reduce 191, reduce 210) on DO
146: reduce-reduce conflict (reduce 191, reduce 210) on FOR
146: reduce-reduce conflict (reduce 191, reduce 210) on GOTO
146: reduce-reduce conflict (reduce 191, reduce 210) on CONTINUE
146: reduce-reduce conflict (reduce 191, reduce 210) on BREAK
146: reduce-reduce conflict (reduce 191, reduce 210) on RETURN
state 146
	statement : other .  (191)
	matched_statement : other .  (210)

	.  reduce 191


state 147
	stmt : open_statement .  (208)

	.  reduce 208


state 148
	statement : selection_statement .  (192)

	.  reduce 192


state 149
	selection_statement : switch_pre . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 249
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 150
	selection_statement : stmt .  (213)

	.  reduce 213


state 151
	stmt : matched_statement .  (207)

	.  reduce 207


state 152
	function_definition : declarator declaration_list compound_statement .  (231)

	.  reduce 231


state 153
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	enum_specifier  goto 28
	declaration_specifiers  goto 56
	declaration  goto 250
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 154
	init_declarator : declarator '=' . initializer

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'{'  shift 251
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	initializer  goto 252
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 253
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 155
	declaration_list : declaration_list . M declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement
	M : .  (59)

	'{'  shift 53
	.  reduce 59

	compound_statement  goto 254
	M  goto 153


state 156
	function_definition : declaration_specifiers declarator compound_statement .  (230)

	.  reduce 230


state 157
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	pointer  goto 27
	direct_declarator  goto 29
	declarator  goto 66
	init_declarator  goto 255
	direct_pre_declarator  goto 38


state 158
	declaration : declaration_specifiers init_declarator_list ';' .  (83)

	.  reduce 83


state 159
	def_concat : init_declarator_list ';' .  (115)

	.  reduce 115


state 160
	direct_declarator : direct_pre_declarator identifier_list ')' .  (150)

	.  reduce 150


state 161
	identifier_list : identifier_list ',' . ID

	ID  shift 256


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

	type_qualifier  goto 24
	struct_or_union  goto 25
	enum_specifier  goto 28
	parameter_declaration  goto 258
	declaration_specifiers  goto 75
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 163
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (149)

	.  reduce 149


state 164
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 164
	')'  shift 259
	'*'  shift 2
	'['  shift 165
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

	abstract_declarator  goto 260
	type_qualifier  goto 24
	struct_or_union  goto 25
	parameter_list  goto 72
	direct_abstract_declarator  goto 167
	parameter_type_list  goto 261
	pointer  goto 168
	enum_specifier  goto 28
	direct_declarator  goto 29
	parameter_declaration  goto 74
	declarator  goto 40
	declaration_specifiers  goto 75
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36
	direct_pre_declarator  goto 38


state 165
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	']'  shift 262
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	logical_and_exp  goto 114
	conditional_exp  goto 115
	constant_exp  goto 263
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 166
	parameter_declaration : declaration_specifiers abstract_declarator .  (163)

	.  reduce 163


state 167
	abstract_declarator : direct_abstract_declarator .  (170)
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'

	'('  shift 264
	'['  shift 265
	.  reduce 170


state 168
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (169)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 164
	'['  shift 165
	ID  shift 3
	.  reduce 169

	direct_abstract_declarator  goto 266
	direct_declarator  goto 50
	direct_pre_declarator  goto 38


state 169
	parameter_declaration : declaration_specifiers declarator .  (162)

	.  reduce 162


state 170
	enumerator : ID '=' . constant_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	logical_and_exp  goto 114
	conditional_exp  goto 115
	constant_exp  goto 267
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


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
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (113)

	.  reduce 113


state 175
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (59)

	'}'  shift 270
	.  reduce 59

	M  goto 153


state 176
	specifier_qualifier_list : type_qualifier .  (127)
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
	.  reduce 127

	type_qualifier  goto 176
	struct_or_union  goto 25
	enum_specifier  goto 28
	specifier_qualifier_list  goto 271
	type_specifier  goto 179
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 177
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 272


state 178
	type_name : specifier_qualifier_list .  (167)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 273
	'*'  shift 2
	'['  shift 165
	.  reduce 167

	abstract_declarator  goto 274
	direct_abstract_declarator  goto 167
	pointer  goto 275


179: shift-reduce conflict (shift 2, reduce 125) on '*'
state 179
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	specifier_qualifier_list : type_specifier .  (125)
	type_specifier : type_specifier . pointer

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

	type_qualifier  goto 176
	struct_or_union  goto 25
	pointer  goto 63
	enum_specifier  goto 28
	specifier_qualifier_list  goto 276
	type_specifier  goto 179
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 180
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 277
	','  shift 247


state 181
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TYPE_NAME  shift 4
	TRUE  shift 99
	FALSE  shift 100
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

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	type_qualifier  goto 176
	struct_or_union  goto 25
	type_name  goto 278
	enum_specifier  goto 28
	specifier_qualifier_list  goto 178
	inclusive_or_exp  goto 112
	type_specifier  goto 179
	struct_or_union_specifier  goto 35
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 180
	exclusive_or_exp  goto 117
	struct_or_union_def  goto 36
	postfix_pre_exp  goto 118


state 182
	unary_exp : SIZEOF unary_exp .  (22)

	.  reduce 22


state 183
	primary_exp : '(' . exp ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 180
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 184
	unary_exp : INC_OP unary_exp .  (19)

	.  reduce 19


state 185
	unary_exp : DEC_OP unary_exp .  (20)

	.  reduce 20


state 186
	unary_exp : unary_operator cast_exp .  (21)

	.  reduce 21


state 187
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 279
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 188
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 280
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 189
	postfix_pre_exp : postfix_exp '(' .  (7)

	.  reduce 7


state 190
	postfix_exp : postfix_exp '.' . ID

	ID  shift 281


state 191
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 282
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 192
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 283


state 193
	postfix_exp : postfix_exp INC_OP .  (14)

	.  reduce 14


state 194
	postfix_exp : postfix_exp DEC_OP .  (15)

	.  reduce 15


state 195
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 284
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 196
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 285
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 197
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 286
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 198
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 287
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 199
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 288
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 200
	multiplicative_exp : multiplicative_exp '^' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 289
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 201
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 290
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 202
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 291
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 203
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 292
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 108
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 204
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 293
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 108
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 205
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 294
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 108
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 206
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 295
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	multiplicative_exp  goto 107
	additive_exp  goto 108
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 207
	and_exp : and_exp '&' . equality_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 296
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 208
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exclusive_or_exp  goto 297
	postfix_pre_exp  goto 118


state 209
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 298
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 210
	logical_or_exp : logical_or_exp OR_OP . M logical_and_exp
	M : .  (59)

	.  reduce 59

	M  goto 299


state 211
	logical_and_exp : logical_and_exp AND_OP . M inclusive_or_exp
	M : .  (59)

	.  reduce 59

	M  goto 300


state 212
	direct_declarator : direct_declarator '[' constant_exp ']' .  (147)

	.  reduce 147


state 213
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 301
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 214
	postfix_exp : postfix_pre_exp ')' .  (10)

	.  reduce 10


state 215
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 302
	','  shift 303


state 216
	argument_exp_list : assignment_exp .  (16)

	.  reduce 16


state 217
	labeled_statement : ID ':' . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 304
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 218
	labeled_statement : CASE constant_exp . ':' M statement

	':'  shift 305


state 219
	default_pre : DEFAULT ':' .  (193)

	.  reduce 193


state 220
	open_statement : IF '(' . exp ')' M matched_statement P ELSE M open_statement
	matched_statement : IF '(' . exp ')' M matched_statement P ELSE M matched_statement
	open_statement : IF '(' . exp ')' M stmt P

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 306
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 221
	switch_pre : SWITCH '(' . exp ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 307
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 222
	iteration_statement : WHILE M . '(' exp ')' M statement

	'('  shift 308


state 223
	iteration_statement : DO M . statement WHILE M '(' exp ')' ';'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 309
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 224
	iteration_statement : FOR '(' . exp_statement M exp_statement ')' M statement
	iteration_statement : FOR '(' . exp_statement M exp_statement M exp P ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 310
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 225
	jump_statement : GOTO ID . ';'

	';'  shift 311


state 226
	jump_statement : CONTINUE ';' .  (221)

	.  reduce 221


state 227
	jump_statement : BREAK ';' .  (222)

	.  reduce 222


state 228
	jump_statement : RETURN ';' .  (223)

	.  reduce 223


state 229
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 247
	';'  shift 312


state 230
	labeled_statement : default_pre statement .  (196)

	.  reduce 196


state 231
	assignment_operator : '=' .  (68)

	.  reduce 68


state 232
	assignment_operator : MUL_ASSIGN .  (69)

	.  reduce 69


state 233
	assignment_operator : DIV_ASSIGN .  (70)

	.  reduce 70


state 234
	assignment_operator : MOD_ASSIGN .  (71)

	.  reduce 71


state 235
	assignment_operator : ADD_ASSIGN .  (72)

	.  reduce 72


state 236
	assignment_operator : SUB_ASSIGN .  (73)

	.  reduce 73


state 237
	assignment_operator : LEFT_ASSIGN .  (74)

	.  reduce 74


state 238
	assignment_operator : RIGHT_ASSIGN .  (75)

	.  reduce 75


state 239
	assignment_operator : AND_ASSIGN .  (76)

	.  reduce 76


state 240
	assignment_operator : XOR_ASSIGN .  (77)

	.  reduce 77


state 241
	assignment_operator : OR_ASSIGN .  (78)

	.  reduce 78


state 242
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 313
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 243
	compound_statement : '{' declaration_list '}' .  (199)

	.  reduce 199


state 244
	statement_list : statement_list . M statement
	compound_statement : '{' declaration_list statement_list . '}'
	M : .  (59)

	'}'  shift 314
	.  reduce 59

	M  goto 246


state 245
	compound_statement : '{' statement_list '}' .  (198)

	.  reduce 198


state 246
	statement_list : statement_list M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 315
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 247
	exp : exp ',' . assignment_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 316
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 248
	exp_statement : exp ';' .  (206)

	.  reduce 206


state 249
	selection_statement : switch_pre statement .  (214)

	.  reduce 214


state 250
	declaration_list : declaration_list M declaration .  (202)

	.  reduce 202


state 251
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'{'  shift 251
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	initializer  goto 317
	initializer_list  goto 318
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 253
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 252
	init_declarator : declarator '=' initializer .  (93)

	.  reduce 93


state 253
	initializer : assignment_exp .  (181)

	.  reduce 181


state 254
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (229)

	.  reduce 229


state 255
	init_declarator_list : init_declarator_list ',' init_declarator .  (91)

	.  reduce 91


state 256
	identifier_list : identifier_list ',' ID .  (166)

	.  reduce 166


state 257
	parameter_type_list : parameter_list ',' ELLIPSIS .  (159)

	.  reduce 159


state 258
	parameter_list : parameter_list ',' parameter_declaration .  (161)

	.  reduce 161


state 259
	direct_abstract_declarator : '(' ')' .  (177)

	.  reduce 177


state 260
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 319


state 261
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 320


state 262
	direct_abstract_declarator : '[' ']' .  (173)

	.  reduce 173


state 263
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 321


state 264
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

	type_qualifier  goto 24
	struct_or_union  goto 25
	parameter_list  goto 72
	parameter_type_list  goto 323
	enum_specifier  goto 28
	parameter_declaration  goto 74
	declaration_specifiers  goto 75
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 265
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	']'  shift 324
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	logical_and_exp  goto 114
	conditional_exp  goto 115
	constant_exp  goto 325
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 266
	abstract_declarator : pointer direct_abstract_declarator .  (171)
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'

	'('  shift 264
	'['  shift 265
	.  reduce 171


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
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (112)

	.  reduce 112


state 271
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (126)

	.  reduce 126


state 272
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 326
	primary_exp  goto 111
	postfix_pre_exp  goto 118


state 273
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 273
	')'  shift 259
	'*'  shift 2
	'['  shift 165
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

	abstract_declarator  goto 260
	type_qualifier  goto 24
	struct_or_union  goto 25
	parameter_list  goto 72
	direct_abstract_declarator  goto 167
	parameter_type_list  goto 261
	pointer  goto 275
	enum_specifier  goto 28
	parameter_declaration  goto 74
	declaration_specifiers  goto 75
	storage_class_specifier  goto 33
	type_specifier  goto 34
	struct_or_union_specifier  goto 35
	struct_or_union_def  goto 36


state 274
	type_name : specifier_qualifier_list abstract_declarator .  (168)

	.  reduce 168


state 275
	abstract_declarator : pointer .  (169)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 273
	'['  shift 165
	.  reduce 169

	direct_abstract_declarator  goto 266


state 276
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (124)

	.  reduce 124


state 277
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 278
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 327


state 279
	additive_exp : additive_exp . '-' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (41)
	additive_exp : additive_exp . '+' multiplicative_exp

	'+'  shift 201
	'-'  shift 202
	.  reduce 41


state 280
	additive_exp : additive_exp . '-' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (42)
	additive_exp : additive_exp . '+' multiplicative_exp

	'+'  shift 201
	'-'  shift 202
	.  reduce 42


state 281
	postfix_exp : postfix_exp '.' ID .  (12)

	.  reduce 12


state 282
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 247
	']'  shift 328


state 283
	postfix_exp : postfix_exp PTR_OP ID .  (13)

	.  reduce 13


state 284
	equality_exp : equality_exp EQ_OP relational_exp .  (49)
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp

	'<'  shift 203
	'>'  shift 204
	LE_OP  shift 205
	GE_OP  shift 206
	.  reduce 49


state 285
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (50)
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp

	'<'  shift 203
	'>'  shift 204
	LE_OP  shift 205
	GE_OP  shift 206
	.  reduce 50


state 286
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (36)

	.  reduce 36


state 287
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (34)

	.  reduce 34


state 288
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (35)

	.  reduce 35


state 289
	multiplicative_exp : multiplicative_exp '^' cast_exp .  (33)

	.  reduce 33


290: shift-reduce conflict (shift 200, reduce 38) on '^'
state 290
	multiplicative_exp : multiplicative_exp . '^' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (38)

	'%'  shift 197
	'*'  shift 198
	'/'  shift 199
	'^'  shift 200
	.  reduce 38


291: shift-reduce conflict (shift 200, reduce 39) on '^'
state 291
	multiplicative_exp : multiplicative_exp . '^' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (39)

	'%'  shift 197
	'*'  shift 198
	'/'  shift 199
	'^'  shift 200
	.  reduce 39


state 292
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '<' shift_exp .  (44)

	LEFT_OP  shift 187
	RIGHT_OP  shift 188
	.  reduce 44


state 293
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '>' shift_exp .  (45)

	LEFT_OP  shift 187
	RIGHT_OP  shift 188
	.  reduce 45


state 294
	relational_exp : relational_exp LE_OP shift_exp .  (46)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 187
	RIGHT_OP  shift 188
	.  reduce 46


state 295
	relational_exp : relational_exp GE_OP shift_exp .  (47)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 187
	RIGHT_OP  shift 188
	.  reduce 47


state 296
	equality_exp : equality_exp . EQ_OP relational_exp
	equality_exp : equality_exp . NE_OP relational_exp
	and_exp : and_exp '&' equality_exp .  (52)

	EQ_OP  shift 195
	NE_OP  shift 196
	.  reduce 52


state 297
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (56)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 213
	.  reduce 56


state 298
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 247
	':'  shift 329


state 299
	logical_or_exp : logical_or_exp OR_OP M . logical_and_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_and_exp  goto 330
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 300
	logical_and_exp : logical_and_exp AND_OP M . inclusive_or_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 331
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 301
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (54)

	'&'  shift 207
	.  reduce 54


state 302
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (11)

	.  reduce 11


state 303
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 332
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 304
	labeled_statement : ID ':' statement .  (194)

	.  reduce 194


state 305
	labeled_statement : CASE constant_exp ':' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 333


state 306
	exp : exp . ',' assignment_exp
	open_statement : IF '(' exp . ')' M matched_statement P ELSE M open_statement
	matched_statement : IF '(' exp . ')' M matched_statement P ELSE M matched_statement
	open_statement : IF '(' exp . ')' M stmt P

	')'  shift 334
	','  shift 247


state 307
	exp : exp . ',' assignment_exp
	switch_pre : SWITCH '(' exp . ')'

	')'  shift 335
	','  shift 247


state 308
	iteration_statement : WHILE M '(' . exp ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 336
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 309
	iteration_statement : DO M statement . WHILE M '(' exp ')' ';'

	WHILE  shift 337


state 310
	iteration_statement : FOR '(' exp_statement . M exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement . M exp_statement M exp P ')' M statement
	M : .  (59)

	.  reduce 59

	M  goto 338


state 311
	jump_statement : GOTO ID ';' .  (220)

	.  reduce 220


state 312
	jump_statement : RETURN exp ';' .  (224)

	.  reduce 224


state 313
	assignment_exp : unary_exp assignment_operator assignment_exp .  (67)

	.  reduce 67


state 314
	compound_statement : '{' declaration_list statement_list '}' .  (200)

	.  reduce 200


state 315
	statement_list : statement_list M statement .  (204)

	.  reduce 204


state 316
	exp : exp ',' assignment_exp .  (80)

	.  reduce 80


state 317
	initializer_list : initializer .  (184)

	.  reduce 184


state 318
	initializer : '{' initializer_list . '}'
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . ',' '}'

	','  shift 339
	'}'  shift 340


state 319
	direct_abstract_declarator : '(' abstract_declarator ')' .  (172)

	.  reduce 172


state 320
	direct_abstract_declarator : '(' parameter_type_list ')' .  (178)

	.  reduce 178


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
	postfix_exp : postfix_exp '[' exp ']' .  (9)

	.  reduce 9


state 329
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 103
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	logical_and_exp  goto 114
	conditional_exp  goto 343
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 330
	logical_or_exp : logical_or_exp OR_OP M logical_and_exp .  (63)
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp

	AND_OP  shift 211
	.  reduce 63


state 331
	logical_and_exp : logical_and_exp AND_OP M inclusive_or_exp .  (58)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 208
	.  reduce 58


state 332
	argument_exp_list : argument_exp_list ',' assignment_exp .  (17)

	.  reduce 17


state 333
	labeled_statement : CASE constant_exp ':' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 344
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 334
	open_statement : IF '(' exp ')' . M matched_statement P ELSE M open_statement
	matched_statement : IF '(' exp ')' . M matched_statement P ELSE M matched_statement
	open_statement : IF '(' exp ')' . M stmt P
	M : .  (59)

	.  reduce 59

	M  goto 345


state 335
	switch_pre : SWITCH '(' exp ')' .  (215)

	.  reduce 215


state 336
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE M '(' exp . ')' M statement

	')'  shift 346
	','  shift 247


state 337
	iteration_statement : DO M statement WHILE . M '(' exp ')' ';'
	M : .  (59)

	.  reduce 59

	M  goto 347


state 338
	iteration_statement : FOR '(' exp_statement M . exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement M . exp_statement M exp P ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 348
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 339
	initializer_list : initializer_list ',' . initializer
	initializer : '{' initializer_list ',' . '}'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'{'  shift 251
	'}'  shift 349
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	initializer  goto 350
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 253
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


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
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (65)

	.  reduce 65


state 344
	labeled_statement : CASE constant_exp ':' M statement .  (195)

	.  reduce 195


state 345
	open_statement : IF '(' exp ')' M . matched_statement P ELSE M open_statement
	matched_statement : IF '(' exp ')' M . matched_statement P ELSE M matched_statement
	open_statement : IF '(' exp ')' M . stmt P

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	IF  shift 124
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	iteration_statement  goto 138
	jump_statement  goto 139
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 351
	open_statement  goto 147
	stmt  goto 352
	matched_statement  goto 353
	postfix_pre_exp  goto 118


state 346
	iteration_statement : WHILE M '(' exp ')' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 354


state 347
	iteration_statement : DO M statement WHILE M . '(' exp ')' ';'

	'('  shift 355


state 348
	iteration_statement : FOR '(' exp_statement M exp_statement . ')' M statement
	iteration_statement : FOR '(' exp_statement M exp_statement . M exp P ')' M statement
	M : .  (59)

	')'  shift 356
	.  reduce 59

	M  goto 357


state 349
	initializer : '{' initializer_list ',' '}' .  (183)

	.  reduce 183


state 350
	initializer_list : initializer_list ',' initializer .  (185)

	.  reduce 185


state 351
	matched_statement : other .  (210)

	.  reduce 210


state 352
	open_statement : IF '(' exp ')' M stmt . P
	P : .  (61)

	.  reduce 61

	P  goto 358


353: reduce-reduce conflict (reduce 61, reduce 207) on ELSE
state 353
	stmt : matched_statement .  (207)
	open_statement : IF '(' exp ')' M matched_statement . P ELSE M open_statement
	matched_statement : IF '(' exp ')' M matched_statement . P ELSE M matched_statement
	P : .  (61)

	ELSE  reduce 61
	.  reduce 207

	P  goto 359


state 354
	iteration_statement : WHILE M '(' exp ')' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 360
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 355
	iteration_statement : DO M statement WHILE M '(' . exp ')' ';'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 361
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 356
	iteration_statement : FOR '(' exp_statement M exp_statement ')' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 362


state 357
	iteration_statement : FOR '(' exp_statement M exp_statement M . exp P ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 363
	exclusive_or_exp  goto 117
	postfix_pre_exp  goto 118


state 358
	open_statement : IF '(' exp ')' M stmt P .  (211)

	.  reduce 211


state 359
	open_statement : IF '(' exp ')' M matched_statement P . ELSE M open_statement
	matched_statement : IF '(' exp ')' M matched_statement P . ELSE M matched_statement

	ELSE  shift 364


state 360
	iteration_statement : WHILE M '(' exp ')' M statement .  (216)

	.  reduce 216


state 361
	exp : exp . ',' assignment_exp
	iteration_statement : DO M statement WHILE M '(' exp . ')' ';'

	')'  shift 365
	','  shift 247


state 362
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 366
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 363
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement M exp_statement M exp . P ')' M statement
	P : .  (61)

	','  shift 247
	.  reduce 61

	P  goto 367


state 364
	open_statement : IF '(' exp ')' M matched_statement P ELSE . M open_statement
	matched_statement : IF '(' exp ')' M matched_statement P ELSE . M matched_statement
	M : .  (59)

	.  reduce 59

	M  goto 368


state 365
	iteration_statement : DO M statement WHILE M '(' exp ')' . ';'

	';'  shift 369


state 366
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M statement .  (218)

	.  reduce 218


state 367
	iteration_statement : FOR '(' exp_statement M exp_statement M exp P . ')' M statement

	')'  shift 370


state 368
	open_statement : IF '(' exp ')' M matched_statement P ELSE M . open_statement
	matched_statement : IF '(' exp ')' M matched_statement P ELSE M . matched_statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 93
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	IF  shift 124
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	iteration_statement  goto 138
	jump_statement  goto 139
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 351
	open_statement  goto 371
	matched_statement  goto 372
	postfix_pre_exp  goto 118


state 369
	iteration_statement : DO M statement WHILE M '(' exp ')' ';' .  (217)

	.  reduce 217


state 370
	iteration_statement : FOR '(' exp_statement M exp_statement M exp P ')' . M statement
	M : .  (59)

	.  reduce 59

	M  goto 373


state 371
	open_statement : IF '(' exp ')' M matched_statement P ELSE M open_statement .  (212)

	.  reduce 212


state 372
	matched_statement : IF '(' exp ')' M matched_statement P ELSE M matched_statement .  (209)

	.  reduce 209


state 373
	iteration_statement : FOR '(' exp_statement M exp_statement M exp P ')' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 119
	'{'  shift 53
	'~'  shift 92
	ID  shift 121
	CONSTANT  shift 94
	STRING_LITERAL  shift 95
	SIZEOF  shift 96
	INC_OP  shift 97
	DEC_OP  shift 98
	TRUE  shift 99
	FALSE  shift 100
	CASE  shift 122
	DEFAULT  shift 123
	IF  shift 124
	SWITCH  shift 125
	WHILE  shift 126
	DO  shift 127
	FOR  shift 128
	GOTO  shift 129
	CONTINUE  shift 130
	BREAK  shift 131
	RETURN  shift 132

	default_pre  goto 133
	unary_operator  goto 101
	shift_exp  goto 102
	unary_exp  goto 134
	postfix_exp  goto 104
	cast_exp  goto 105
	equality_exp  goto 106
	multiplicative_exp  goto 107
	additive_exp  goto 108
	relational_exp  goto 109
	and_exp  goto 110
	primary_exp  goto 111
	exp_statement  goto 135
	statement  goto 374
	iteration_statement  goto 138
	jump_statement  goto 139
	labeled_statement  goto 140
	compound_statement  goto 141
	inclusive_or_exp  goto 112
	logical_or_exp  goto 113
	assignment_exp  goto 143
	logical_and_exp  goto 114
	conditional_exp  goto 144
	exp  goto 145
	exclusive_or_exp  goto 117
	other  goto 146
	open_statement  goto 147
	selection_statement  goto 148
	switch_pre  goto 149
	stmt  goto 150
	matched_statement  goto 151
	postfix_pre_exp  goto 118


state 374
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
State 34 contains 1 shift-reduce conflict(s)
State 42 contains 3 shift-reduce conflict(s)
State 107 contains 1 shift-reduce conflict(s)
State 146 contains 30 reduce-reduce conflict(s)
State 179 contains 1 shift-reduce conflict(s)
State 290 contains 1 shift-reduce conflict(s)
State 291 contains 1 shift-reduce conflict(s)
State 353 contains 1 reduce-reduce conflict(s)


86 token(s), 77 nonterminal(s)
233 grammar rule(s), 375 state(s)


##############################################################################
# End of File
##############################################################################
