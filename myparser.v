#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 77 of your 30 day trial period.
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
# Date: 12/26/18
# Time: 13:49:38
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
   33                     | multiplicative_exp '*' cast_exp
   34                     | multiplicative_exp '/' cast_exp
   35                     | multiplicative_exp '%' cast_exp

   36  additive_exp : multiplicative_exp
   37               | additive_exp '+' multiplicative_exp
   38               | additive_exp '-' multiplicative_exp

   39  shift_exp : additive_exp
   40            | shift_exp LEFT_OP additive_exp
   41            | shift_exp RIGHT_OP additive_exp

   42  relational_exp : shift_exp
   43                 | relational_exp '<' shift_exp
   44                 | relational_exp '>' shift_exp
   45                 | relational_exp LE_OP shift_exp
   46                 | relational_exp GE_OP shift_exp

   47  equality_exp : relational_exp
   48               | equality_exp EQ_OP relational_exp
   49               | equality_exp NE_OP relational_exp

   50  and_exp : equality_exp
   51          | and_exp '&' equality_exp

   52  exclusive_or_exp : and_exp
   53                   | exclusive_or_exp '^' and_exp

   54  inclusive_or_exp : exclusive_or_exp
   55                   | inclusive_or_exp '|' exclusive_or_exp

   56  logical_and_exp : inclusive_or_exp
   57                  | logical_and_exp AND_OP M inclusive_or_exp

   58  M :

   59  N :

   60  logical_or_exp : logical_and_exp
   61                 | logical_or_exp OR_OP M logical_and_exp

   62  conditional_exp : logical_or_exp
   63                  | logical_or_exp '?' exp ':' conditional_exp

   64  assignment_exp : conditional_exp
   65                 | unary_exp assignment_operator assignment_exp

   66  assignment_operator : '='
   67                      | MUL_ASSIGN
   68                      | DIV_ASSIGN
   69                      | MOD_ASSIGN
   70                      | ADD_ASSIGN
   71                      | SUB_ASSIGN
   72                      | LEFT_ASSIGN
   73                      | RIGHT_ASSIGN
   74                      | AND_ASSIGN
   75                      | XOR_ASSIGN
   76                      | OR_ASSIGN

   77  exp : assignment_exp
   78      | exp ',' assignment_exp

   79  constant_exp : conditional_exp

   80  declaration : declaration_specifiers ';'
   81              | declaration_specifiers init_declarator_list ';'

   82  declaration_specifiers : storage_class_specifier
   83                         | storage_class_specifier declaration_specifiers
   84                         | type_specifier
   85                         | type_specifier declaration_specifiers
   86                         | type_qualifier
   87                         | type_qualifier declaration_specifiers

   88  init_declarator_list : init_declarator
   89                       | init_declarator_list ',' init_declarator

   90  init_declarator : declarator
   91                  | declarator '=' initializer

   92  storage_class_specifier : TYPEDEF
   93                          | EXTERN
   94                          | STATIC
   95                          | AUTO
   96                          | REGISTER

   97  type_specifier : VOID
   98                 | CHAR
   99                 | SHORT
  100                 | INT
  101                 | LONG
  102                 | FLOAT
  103                 | DOUBLE
  104                 | SIGNED
  105                 | UNSIGNED
  106                 | struct_or_union_specifier
  107                 | enum_specifier
  108                 | TYPE_NAME
  109                 | type_specifier pointer

  110  struct_or_union_def : struct_or_union ID '{' declaration_list '}'
  111                      | struct_or_union '{' declaration_list '}'

  112  def_concat : ';'
  113             | init_declarator_list ';'

  114  struct_or_union_specifier : struct_or_union_def def_concat
  115                            | struct_or_union ID

  116  struct_or_union : STRUCT
  117                  | UNION

  118  struct_declaration_list : struct_declaration
  119                          | struct_declaration_list struct_declaration

  120  struct_declaration : specifier_qualifier_list struct_declarator_list ';'
  121                     | assignment_exp struct_declarator_list ';'

  122  specifier_qualifier_list : type_specifier specifier_qualifier_list
  123                           | type_specifier
  124                           | type_qualifier specifier_qualifier_list
  125                           | type_qualifier

  126  struct_declarator_list : struct_declarator
  127                         | struct_declarator_list ',' struct_declarator

  128  struct_declarator : declarator
  129                    | ':' constant_exp
  130                    | declarator ':' constant_exp

  131  enum_specifier : ENUM '{' enumerator_list '}'
  132                 | ENUM ID '{' enumerator_list '}'
  133                 | ENUM ID

  134  enumerator_list : enumerator
  135                  | enumerator_list ',' enumerator

  136  enumerator : ID
  137             | ID '=' constant_exp

  138  type_qualifier : CONST
  139                 | VOLATILE

  140  declarator : pointer direct_declarator
  141             | direct_declarator

  142  direct_pre_declarator : direct_declarator '('

  143  direct_declarator : ID
  144                    | '(' declarator ')'
  145                    | direct_declarator '[' constant_exp ']'
  146                    | direct_declarator '[' ']'
  147                    | direct_pre_declarator parameter_type_list ')'
  148                    | direct_pre_declarator identifier_list ')'
  149                    | direct_pre_declarator ')'

  150  pointer : '*'
  151          | '*' type_qualifier_list
  152          | '*' pointer
  153          | '*' type_qualifier_list pointer

  154  type_qualifier_list : type_qualifier
  155                      | type_qualifier_list type_qualifier

  156  parameter_type_list : parameter_list
  157                      | parameter_list ',' ELLIPSIS

  158  parameter_list : parameter_declaration
  159                 | parameter_list ',' parameter_declaration

  160  parameter_declaration : declaration_specifiers declarator
  161                        | declaration_specifiers abstract_declarator
  162                        | declaration_specifiers

  163  identifier_list : ID
  164                  | identifier_list ',' ID

  165  type_name : specifier_qualifier_list
  166            | specifier_qualifier_list abstract_declarator

  167  abstract_declarator : pointer
  168                      | direct_abstract_declarator
  169                      | pointer direct_abstract_declarator

  170  direct_abstract_declarator : '(' abstract_declarator ')'
  171                             | '[' ']'
  172                             | '[' constant_exp ']'
  173                             | direct_abstract_declarator '[' ']'
  174                             | direct_abstract_declarator '[' constant_exp ']'
  175                             | '(' ')'
  176                             | '(' parameter_type_list ')'
  177                             | direct_abstract_declarator '(' ')'
  178                             | direct_abstract_declarator '(' parameter_type_list ')'

  179  initializer : assignment_exp
  180              | '{' initializer_list '}'
  181              | '{' initializer_list ',' '}'

  182  initializer_list : initializer
  183                   | initializer_list ',' initializer

  184  other : compound_statement
  185        | exp_statement
  186        | iteration_statement
  187        | jump_statement

  188  statement : labeled_statement
  189            | other
  190            | selection_statement

  191  default_pre : DEFAULT ':'

  192  labeled_statement : ID ':' statement
  193                    | CASE constant_exp ':' M statement
  194                    | default_pre statement

  195  compound_statement : '{' '}'
  196                     | '{' statement_list '}'
  197                     | '{' declaration_list '}'
  198                     | '{' declaration_list statement_list '}'

  199  declaration_list : declaration
  200                   | declaration_list M declaration

  201  statement_list : statement
  202                 | statement_list M statement

  203  exp_statement : ';'
  204                | exp ';'

  205  stmt : matched_statement
  206       | open_statement

  207  matched_statement : IF '(' exp ')' M matched_statement N ELSE M matched_statement
  208                    | other

  209  open_statement : IF '(' exp ')' M stmt
  210                 | IF '(' exp ')' M matched_statement N ELSE M open_statement

  211  selection_statement : stmt
  212                      | switch_pre statement

  213  switch_pre : SWITCH '(' exp ')'

  214  iteration_statement : WHILE M '(' exp ')' M statement
  215                      | DO M statement WHILE M '(' exp ')' ';'
  216                      | FOR '(' exp_statement M exp_statement ')' M statement
  217                      | FOR '(' exp_statement M exp_statement M exp ')' M statement

  218  jump_statement : GOTO ID ';'
  219                 | CONTINUE ';'
  220                 | BREAK ';'
  221                 | RETURN ';'
  222                 | RETURN exp ';'

  223  translation_unit : external_declaration
  224                   | translation_unit external_declaration

  225  external_declaration : function_definition
  226                       | declaration

  227  function_definition : declaration_specifiers declarator declaration_list compound_statement
  228                      | declaration_specifiers declarator compound_statement
  229                      | declarator declaration_list compound_statement
  230                      | declarator compound_statement


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

	struct_or_union  goto 24
	type_qualifier  goto 25
	pointer  goto 26
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	declarator  goto 29
	enum_specifier  goto 30
	direct_declarator  goto 31
	struct_or_union_def  goto 32
	declaration_specifiers  goto 33
	storage_class_specifier  goto 34
	declaration  goto 35
	translation_unit  goto 36
	function_definition  goto 37
	direct_pre_declarator  goto 38
	external_declaration  goto 39


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	pointer  goto 26
	declarator  goto 40
	direct_declarator  goto 31
	direct_pre_declarator  goto 38


2: shift-reduce conflict (shift 2, reduce 150) on '*'
2: shift-reduce conflict (shift 18, reduce 150) on CONST
2: shift-reduce conflict (shift 19, reduce 150) on VOLATILE
state 2
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' .  (150)
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 150

	type_qualifier_list  goto 41
	type_qualifier  goto 42
	pointer  goto 43


state 3
	direct_declarator : ID .  (143)

	.  reduce 143


state 4
	type_specifier : TYPE_NAME .  (108)

	.  reduce 108


state 5
	storage_class_specifier : TYPEDEF .  (92)

	.  reduce 92


state 6
	storage_class_specifier : EXTERN .  (93)

	.  reduce 93


state 7
	storage_class_specifier : STATIC .  (94)

	.  reduce 94


state 8
	storage_class_specifier : AUTO .  (95)

	.  reduce 95


state 9
	storage_class_specifier : REGISTER .  (96)

	.  reduce 96


state 10
	type_specifier : CHAR .  (98)

	.  reduce 98


state 11
	type_specifier : SHORT .  (99)

	.  reduce 99


state 12
	type_specifier : INT .  (100)

	.  reduce 100


state 13
	type_specifier : LONG .  (101)

	.  reduce 101


state 14
	type_specifier : SIGNED .  (104)

	.  reduce 104


state 15
	type_specifier : UNSIGNED .  (105)

	.  reduce 105


state 16
	type_specifier : FLOAT .  (102)

	.  reduce 102


state 17
	type_specifier : DOUBLE .  (103)

	.  reduce 103


state 18
	type_qualifier : CONST .  (138)

	.  reduce 138


state 19
	type_qualifier : VOLATILE .  (139)

	.  reduce 139


state 20
	type_specifier : VOID .  (97)

	.  reduce 97


state 21
	struct_or_union : STRUCT .  (116)

	.  reduce 116


state 22
	struct_or_union : UNION .  (117)

	.  reduce 117


state 23
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID

	'{'  shift 44
	ID  shift 45


state 24
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'
	struct_or_union_def : struct_or_union . '{' declaration_list '}'

	'{'  shift 46
	ID  shift 47


state 25
	declaration_specifiers : type_qualifier . declaration_specifiers
	declaration_specifiers : type_qualifier .  (86)

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

	struct_or_union  goto 24
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 48
	storage_class_specifier  goto 34


state 26
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 49
	direct_pre_declarator  goto 38


27: shift-reduce conflict (shift 2, reduce 84) on '*'
state 27
	declaration_specifiers : type_specifier . declaration_specifiers
	declaration_specifiers : type_specifier .  (84)
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
	.  reduce 84

	struct_or_union  goto 24
	type_qualifier  goto 25
	pointer  goto 50
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 51
	storage_class_specifier  goto 34


state 28
	type_specifier : struct_or_union_specifier .  (106)

	.  reduce 106


state 29
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

	'{'  shift 52
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
	compound_statement  goto 53
	declaration_list  goto 54
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 55
	storage_class_specifier  goto 34
	declaration  goto 56


state 30
	type_specifier : enum_specifier .  (107)

	.  reduce 107


state 31
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '[' constant_exp ']'
	declarator : direct_declarator .  (141)
	direct_pre_declarator : direct_declarator . '('

	'('  shift 57
	'['  shift 58
	.  reduce 141


state 32
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 59
	ID  shift 3

	pointer  goto 26
	declarator  goto 60
	direct_declarator  goto 31
	init_declarator  goto 61
	init_declarator_list  goto 62
	def_concat  goto 63
	direct_pre_declarator  goto 38


state 33
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 64
	ID  shift 3

	pointer  goto 26
	declarator  goto 65
	direct_declarator  goto 31
	init_declarator  goto 61
	init_declarator_list  goto 66
	direct_pre_declarator  goto 38


state 34
	declaration_specifiers : storage_class_specifier .  (82)
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
	.  reduce 82

	struct_or_union  goto 24
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 67
	storage_class_specifier  goto 34


state 35
	external_declaration : declaration .  (226)

	.  reduce 226


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

	struct_or_union  goto 24
	type_qualifier  goto 25
	pointer  goto 26
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	declarator  goto 29
	enum_specifier  goto 30
	direct_declarator  goto 31
	struct_or_union_def  goto 32
	declaration_specifiers  goto 33
	storage_class_specifier  goto 34
	declaration  goto 35
	function_definition  goto 37
	direct_pre_declarator  goto 38
	external_declaration  goto 68


state 37
	external_declaration : function_definition .  (225)

	.  reduce 225


state 38
	direct_declarator : direct_pre_declarator . ')'
	direct_declarator : direct_pre_declarator . parameter_type_list ')'
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

	parameter_list  goto 71
	struct_or_union  goto 24
	type_qualifier  goto 25
	identifier_list  goto 72
	parameter_type_list  goto 73
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	parameter_declaration  goto 74
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 75
	storage_class_specifier  goto 34


state 39
	translation_unit : external_declaration .  (223)

	.  reduce 223


state 40
	direct_declarator : '(' declarator . ')'

	')'  shift 76


41: shift-reduce conflict (shift 2, reduce 151) on '*'
41: shift-reduce conflict (shift 18, reduce 151) on CONST
41: shift-reduce conflict (shift 19, reduce 151) on VOLATILE
state 41
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (151)
	type_qualifier_list : type_qualifier_list . type_qualifier

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 151

	type_qualifier  goto 77
	pointer  goto 78


state 42
	type_qualifier_list : type_qualifier .  (154)

	.  reduce 154


state 43
	pointer : '*' pointer .  (152)

	.  reduce 152


state 44
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 79

	enumerator_list  goto 80
	enumerator  goto 81


state 45
	enum_specifier : ENUM ID . '{' enumerator_list '}'
	enum_specifier : ENUM ID .  (133)

	'{'  shift 82
	.  reduce 133


state 46
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

	struct_or_union  goto 24
	declaration_list  goto 83
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 55
	storage_class_specifier  goto 34
	declaration  goto 56


state 47
	struct_or_union_specifier : struct_or_union ID .  (115)
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'

	'{'  shift 84
	.  reduce 115


state 48
	declaration_specifiers : type_qualifier declaration_specifiers .  (87)

	.  reduce 87


state 49
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '[' constant_exp ']'
	declarator : pointer direct_declarator .  (140)
	direct_pre_declarator : direct_declarator . '('

	'('  shift 57
	'['  shift 58
	.  reduce 140


state 50
	type_specifier : type_specifier pointer .  (109)

	.  reduce 109


state 51
	declaration_specifiers : type_specifier declaration_specifiers .  (85)

	.  reduce 85


state 52
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list statement_list '}'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'}'  shift 92
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TYPE_NAME  shift 4
	TRUE  shift 100
	FALSE  shift 101
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
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 123
	labeled_statement  goto 124
	struct_or_union  goto 24
	compound_statement  goto 125
	declaration_list  goto 126
	type_qualifier  goto 25
	statement_list  goto 127
	exp_statement  goto 128
	iteration_statement  goto 129
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	assignment_exp  goto 130
	struct_or_union_def  goto 32
	equality_exp  goto 131
	and_exp  goto 132
	declaration_specifiers  goto 55
	logical_and_exp  goto 133
	storage_class_specifier  goto 34
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	declaration  goto 56
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 53
	function_definition : declarator compound_statement .  (230)

	.  reduce 230


state 54
	declaration_list : declaration_list . M declaration
	function_definition : declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 52
	.  reduce 58

	compound_statement  goto 147
	M  goto 148


state 55
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 64
	ID  shift 3

	pointer  goto 26
	declarator  goto 60
	direct_declarator  goto 31
	init_declarator  goto 61
	init_declarator_list  goto 66
	direct_pre_declarator  goto 38


state 56
	declaration_list : declaration .  (199)

	.  reduce 199


state 57
	direct_pre_declarator : direct_declarator '(' .  (142)

	.  reduce 142


state 58
	direct_declarator : direct_declarator '[' . ']'
	direct_declarator : direct_declarator '[' . constant_exp ']'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	']'  shift 149
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	constant_exp  goto 152
	logical_or_exp  goto 137
	conditional_exp  goto 153
	postfix_pre_exp  goto 146


state 59
	def_concat : ';' .  (112)

	.  reduce 112


state 60
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)

	'='  shift 154
	.  reduce 90


state 61
	init_declarator_list : init_declarator .  (88)

	.  reduce 88


state 62
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 155
	';'  shift 156


state 63
	struct_or_union_specifier : struct_or_union_def def_concat .  (114)

	.  reduce 114


state 64
	declaration : declaration_specifiers ';' .  (80)

	.  reduce 80


state 65
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 154
	'{'  shift 52
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
	.  reduce 90

	struct_or_union  goto 24
	compound_statement  goto 157
	declaration_list  goto 158
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 55
	storage_class_specifier  goto 34
	declaration  goto 56


state 66
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 155
	';'  shift 159


state 67
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (83)

	.  reduce 83


state 68
	translation_unit : translation_unit external_declaration .  (224)

	.  reduce 224


state 69
	direct_declarator : direct_pre_declarator ')' .  (149)

	.  reduce 149


state 70
	identifier_list : ID .  (163)

	.  reduce 163


state 71
	parameter_type_list : parameter_list .  (156)
	parameter_list : parameter_list . ',' parameter_declaration
	parameter_type_list : parameter_list . ',' ELLIPSIS

	','  shift 160
	.  reduce 156


state 72
	identifier_list : identifier_list . ',' ID
	direct_declarator : direct_pre_declarator identifier_list . ')'

	')'  shift 161
	','  shift 162


state 73
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 163


state 74
	parameter_list : parameter_declaration .  (158)

	.  reduce 158


state 75
	parameter_declaration : declaration_specifiers .  (162)
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator

	'('  shift 164
	'*'  shift 2
	'['  shift 165
	ID  shift 3
	.  reduce 162

	abstract_declarator  goto 166
	pointer  goto 167
	declarator  goto 168
	direct_abstract_declarator  goto 169
	direct_declarator  goto 31
	direct_pre_declarator  goto 38


state 76
	direct_declarator : '(' declarator ')' .  (144)

	.  reduce 144


state 77
	type_qualifier_list : type_qualifier_list type_qualifier .  (155)

	.  reduce 155


state 78
	pointer : '*' type_qualifier_list pointer .  (153)

	.  reduce 153


state 79
	enumerator : ID .  (136)
	enumerator : ID . '=' constant_exp

	'='  shift 170
	.  reduce 136


state 80
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM '{' enumerator_list . '}'

	','  shift 171
	'}'  shift 172


state 81
	enumerator_list : enumerator .  (134)

	.  reduce 134


state 82
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 79

	enumerator_list  goto 173
	enumerator  goto 81


state 83
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 174
	.  reduce 58

	M  goto 148


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

	struct_or_union  goto 24
	declaration_list  goto 175
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 55
	storage_class_specifier  goto 34
	declaration  goto 56


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
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TYPE_NAME  shift 4
	TRUE  shift 100
	FALSE  shift 101
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

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	struct_or_union  goto 24
	type_qualifier  goto 176
	type_name  goto 177
	type_specifier  goto 178
	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 179
	enum_specifier  goto 30
	assignment_exp  goto 130
	struct_or_union_def  goto 32
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 180
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


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
	exp_statement : ';' .  (203)

	.  reduce 203


state 92
	compound_statement : '{' '}' .  (195)

	.  reduce 195


state 93
	unary_operator : '~' .  (28)

	.  reduce 28


state 94
	primary_exp : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 181
	.  reduce 1


state 95
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 96
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 97
	unary_exp : SIZEOF . unary_exp
	unary_exp : SIZEOF . '(' type_name ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 182
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	unary_exp  goto 183
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 98
	unary_exp : INC_OP . unary_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 184
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	unary_exp  goto 185
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 99
	unary_exp : DEC_OP . unary_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 184
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	unary_exp  goto 186
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 100
	primary_exp : TRUE .  (5)

	.  reduce 5


state 101
	primary_exp : FALSE .  (6)

	.  reduce 6


state 102
	labeled_statement : CASE . constant_exp ':' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	constant_exp  goto 187
	logical_or_exp  goto 137
	conditional_exp  goto 153
	postfix_pre_exp  goto 146


state 103
	default_pre : DEFAULT . ':'

	':'  shift 188


state 104
	matched_statement : IF . '(' exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF . '(' exp ')' M stmt
	open_statement : IF . '(' exp ')' M matched_statement N ELSE M open_statement

	'('  shift 189


state 105
	switch_pre : SWITCH . '(' exp ')'

	'('  shift 190


state 106
	iteration_statement : WHILE . M '(' exp ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 191


state 107
	iteration_statement : DO . M statement WHILE M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 192


state 108
	iteration_statement : FOR . '(' exp_statement M exp_statement ')' M statement
	iteration_statement : FOR . '(' exp_statement M exp_statement M exp ')' M statement

	'('  shift 193


state 109
	jump_statement : GOTO . ID ';'

	ID  shift 194


state 110
	jump_statement : CONTINUE . ';'

	';'  shift 195


state 111
	jump_statement : BREAK . ';'

	';'  shift 196


state 112
	jump_statement : RETURN . ';'
	jump_statement : RETURN . exp ';'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 197
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 198
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 113
	labeled_statement : default_pre . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 199
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 114
	multiplicative_exp : cast_exp .  (32)

	.  reduce 32


state 115
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : shift_exp .  (42)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 200
	RIGHT_OP  shift 201
	.  reduce 42


state 116
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : additive_exp .  (39)

	'+'  shift 202
	'-'  shift 203
	.  reduce 39


state 117
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : relational_exp .  (47)
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 204
	'>'  shift 205
	LE_OP  shift 206
	GE_OP  shift 207
	.  reduce 47


state 118
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : multiplicative_exp .  (36)
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 208
	'*'  shift 209
	'/'  shift 210
	.  reduce 36


state 119
	cast_exp : unary_exp .  (30)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 211
	MUL_ASSIGN  shift 212
	DIV_ASSIGN  shift 213
	MOD_ASSIGN  shift 214
	ADD_ASSIGN  shift 215
	SUB_ASSIGN  shift 216
	LEFT_ASSIGN  shift 217
	RIGHT_ASSIGN  shift 218
	AND_ASSIGN  shift 219
	XOR_ASSIGN  shift 220
	OR_ASSIGN  shift 221
	.  reduce 30

	assignment_operator  goto 222


state 120
	unary_exp : unary_operator . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 223
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 121
	postfix_exp : primary_exp .  (8)

	.  reduce 8


state 122
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (18)

	'('  shift 224
	'.'  shift 225
	'['  shift 226
	PTR_OP  shift 227
	INC_OP  shift 228
	DEC_OP  shift 229
	.  reduce 18


state 123
	statement_list : statement .  (201)

	.  reduce 201


state 124
	statement : labeled_statement .  (188)

	.  reduce 188


state 125
	other : compound_statement .  (184)

	.  reduce 184


state 126
	compound_statement : '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	compound_statement : '{' declaration_list . statement_list '}'
	M : .  (58)

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'}'  shift 230
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112
	.  reduce 58

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 123
	labeled_statement  goto 124
	compound_statement  goto 125
	statement_list  goto 231
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	M  goto 148
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 127
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (58)

	'}'  shift 232
	.  reduce 58

	M  goto 233


state 128
	other : exp_statement .  (185)

	.  reduce 185


state 129
	other : iteration_statement .  (186)

	.  reduce 186


state 130
	exp : assignment_exp .  (77)

	.  reduce 77


state 131
	equality_exp : equality_exp . NE_OP relational_exp
	and_exp : equality_exp .  (50)
	equality_exp : equality_exp . EQ_OP relational_exp

	EQ_OP  shift 234
	NE_OP  shift 235
	.  reduce 50


state 132
	exclusive_or_exp : and_exp .  (52)
	and_exp : and_exp . '&' equality_exp

	'&'  shift 236
	.  reduce 52


state 133
	logical_or_exp : logical_and_exp .  (60)
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp

	AND_OP  shift 237
	.  reduce 60


state 134
	logical_and_exp : inclusive_or_exp .  (56)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 238
	.  reduce 56


state 135
	inclusive_or_exp : exclusive_or_exp .  (54)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 239
	.  reduce 54


state 136
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 240
	';'  shift 241


state 137
	logical_or_exp : logical_or_exp . OR_OP M logical_and_exp
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp
	conditional_exp : logical_or_exp .  (62)

	'?'  shift 242
	OR_OP  shift 243
	.  reduce 62


state 138
	assignment_exp : conditional_exp .  (64)

	.  reduce 64


state 139
	other : jump_statement .  (187)

	.  reduce 187


state 140
	stmt : matched_statement .  (205)

	.  reduce 205


state 141
	stmt : open_statement .  (206)

	.  reduce 206


state 142
	statement : selection_statement .  (190)

	.  reduce 190


143: reduce-reduce conflict (reduce 189, reduce 208) on '!'
143: reduce-reduce conflict (reduce 189, reduce 208) on '&'
143: reduce-reduce conflict (reduce 189, reduce 208) on '('
143: reduce-reduce conflict (reduce 189, reduce 208) on '*'
143: reduce-reduce conflict (reduce 189, reduce 208) on '+'
143: reduce-reduce conflict (reduce 189, reduce 208) on '-'
143: reduce-reduce conflict (reduce 189, reduce 208) on ';'
143: reduce-reduce conflict (reduce 189, reduce 208) on '{'
143: reduce-reduce conflict (reduce 189, reduce 208) on '}'
143: reduce-reduce conflict (reduce 189, reduce 208) on '~'
143: reduce-reduce conflict (reduce 189, reduce 208) on ID
143: reduce-reduce conflict (reduce 189, reduce 208) on CONSTANT
143: reduce-reduce conflict (reduce 189, reduce 208) on STRING_LITERAL
143: reduce-reduce conflict (reduce 189, reduce 208) on SIZEOF
143: reduce-reduce conflict (reduce 189, reduce 208) on INC_OP
143: reduce-reduce conflict (reduce 189, reduce 208) on DEC_OP
143: reduce-reduce conflict (reduce 189, reduce 208) on TRUE
143: reduce-reduce conflict (reduce 189, reduce 208) on FALSE
143: reduce-reduce conflict (reduce 189, reduce 208) on CASE
143: reduce-reduce conflict (reduce 189, reduce 208) on DEFAULT
143: reduce-reduce conflict (reduce 189, reduce 208) on IF
143: reduce-reduce conflict (reduce 189, reduce 208) on ELSE
143: reduce-reduce conflict (reduce 189, reduce 208) on SWITCH
143: reduce-reduce conflict (reduce 189, reduce 208) on WHILE
143: reduce-reduce conflict (reduce 189, reduce 208) on DO
143: reduce-reduce conflict (reduce 189, reduce 208) on FOR
143: reduce-reduce conflict (reduce 189, reduce 208) on GOTO
143: reduce-reduce conflict (reduce 189, reduce 208) on CONTINUE
143: reduce-reduce conflict (reduce 189, reduce 208) on BREAK
143: reduce-reduce conflict (reduce 189, reduce 208) on RETURN
state 143
	statement : other .  (189)
	matched_statement : other .  (208)

	.  reduce 189


state 144
	selection_statement : stmt .  (211)

	.  reduce 211


state 145
	selection_statement : switch_pre . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 244
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 146
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	')'  shift 245
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	argument_exp_list  goto 246
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 247
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 147
	function_definition : declarator declaration_list compound_statement .  (229)

	.  reduce 229


state 148
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

	struct_or_union  goto 24
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 55
	storage_class_specifier  goto 34
	declaration  goto 248


state 149
	direct_declarator : direct_declarator '[' ']' .  (146)

	.  reduce 146


state 150
	primary_exp : ID .  (1)

	.  reduce 1


state 151
	cast_exp : unary_exp .  (30)

	.  reduce 30


state 152
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 249


state 153
	constant_exp : conditional_exp .  (79)

	.  reduce 79


state 154
	init_declarator : declarator '=' . initializer

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'{'  shift 250
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	initializer  goto 251
	assignment_exp  goto 252
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 155
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	pointer  goto 26
	declarator  goto 60
	direct_declarator  goto 31
	init_declarator  goto 253
	direct_pre_declarator  goto 38


state 156
	def_concat : init_declarator_list ';' .  (113)

	.  reduce 113


state 157
	function_definition : declaration_specifiers declarator compound_statement .  (228)

	.  reduce 228


state 158
	declaration_list : declaration_list . M declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 52
	.  reduce 58

	compound_statement  goto 254
	M  goto 148


state 159
	declaration : declaration_specifiers init_declarator_list ';' .  (81)

	.  reduce 81


state 160
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
	ELLIPSIS  shift 255

	struct_or_union  goto 24
	type_qualifier  goto 25
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	parameter_declaration  goto 256
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 75
	storage_class_specifier  goto 34


state 161
	direct_declarator : direct_pre_declarator identifier_list ')' .  (148)

	.  reduce 148


state 162
	identifier_list : identifier_list ',' . ID

	ID  shift 257


state 163
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (147)

	.  reduce 147


state 164
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 164
	')'  shift 258
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

	parameter_list  goto 71
	struct_or_union  goto 24
	abstract_declarator  goto 259
	type_qualifier  goto 25
	pointer  goto 167
	parameter_type_list  goto 260
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	parameter_declaration  goto 74
	declarator  goto 40
	enum_specifier  goto 30
	direct_abstract_declarator  goto 169
	direct_declarator  goto 31
	struct_or_union_def  goto 32
	declaration_specifiers  goto 75
	storage_class_specifier  goto 34
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
	']'  shift 261
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	constant_exp  goto 262
	logical_or_exp  goto 137
	conditional_exp  goto 153
	postfix_pre_exp  goto 146


state 166
	parameter_declaration : declaration_specifiers abstract_declarator .  (161)

	.  reduce 161


state 167
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (167)
	declarator : pointer . direct_declarator

	'('  shift 164
	'['  shift 165
	ID  shift 3
	.  reduce 167

	direct_abstract_declarator  goto 263
	direct_declarator  goto 49
	direct_pre_declarator  goto 38


state 168
	parameter_declaration : declaration_specifiers declarator .  (160)

	.  reduce 160


state 169
	abstract_declarator : direct_abstract_declarator .  (168)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 264
	'['  shift 265
	.  reduce 168


state 170
	enumerator : ID '=' . constant_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	constant_exp  goto 266
	logical_or_exp  goto 137
	conditional_exp  goto 153
	postfix_pre_exp  goto 146


state 171
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 79

	enumerator  goto 267


state 172
	enum_specifier : ENUM '{' enumerator_list '}' .  (131)

	.  reduce 131


state 173
	enum_specifier : ENUM ID '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 171
	'}'  shift 268


state 174
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (111)

	.  reduce 111


state 175
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 269
	.  reduce 58

	M  goto 148


state 176
	specifier_qualifier_list : type_qualifier .  (125)
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
	.  reduce 125

	struct_or_union  goto 24
	type_qualifier  goto 176
	type_specifier  goto 178
	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 270
	enum_specifier  goto 30
	struct_or_union_def  goto 32


state 177
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 271


178: shift-reduce conflict (shift 2, reduce 123) on '*'
state 178
	specifier_qualifier_list : type_specifier .  (123)
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
	.  reduce 123

	struct_or_union  goto 24
	type_qualifier  goto 176
	pointer  goto 50
	type_specifier  goto 178
	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 272
	enum_specifier  goto 30
	struct_or_union_def  goto 32


state 179
	type_name : specifier_qualifier_list .  (165)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 273
	'*'  shift 2
	'['  shift 165
	.  reduce 165

	abstract_declarator  goto 274
	pointer  goto 275
	direct_abstract_declarator  goto 169


state 180
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 276
	','  shift 240


state 181
	labeled_statement : ID ':' . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 277
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 182
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TYPE_NAME  shift 4
	TRUE  shift 100
	FALSE  shift 101
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

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	struct_or_union  goto 24
	type_qualifier  goto 176
	type_name  goto 278
	type_specifier  goto 178
	struct_or_union_specifier  goto 28
	specifier_qualifier_list  goto 179
	enum_specifier  goto 30
	assignment_exp  goto 130
	struct_or_union_def  goto 32
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 180
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 183
	unary_exp : SIZEOF unary_exp .  (22)

	.  reduce 22


state 184
	primary_exp : '(' . exp ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 180
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 185
	unary_exp : INC_OP unary_exp .  (19)

	.  reduce 19


state 186
	unary_exp : DEC_OP unary_exp .  (20)

	.  reduce 20


state 187
	labeled_statement : CASE constant_exp . ':' M statement

	':'  shift 279


state 188
	default_pre : DEFAULT ':' .  (191)

	.  reduce 191


state 189
	matched_statement : IF '(' . exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' . exp ')' M stmt
	open_statement : IF '(' . exp ')' M matched_statement N ELSE M open_statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 280
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 190
	switch_pre : SWITCH '(' . exp ')'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 281
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 191
	iteration_statement : WHILE M . '(' exp ')' M statement

	'('  shift 282


state 192
	iteration_statement : DO M . statement WHILE M '(' exp ')' ';'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 283
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 193
	iteration_statement : FOR '(' . exp_statement M exp_statement ')' M statement
	iteration_statement : FOR '(' . exp_statement M exp_statement M exp ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	exp_statement  goto 284
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 194
	jump_statement : GOTO ID . ';'

	';'  shift 285


state 195
	jump_statement : CONTINUE ';' .  (219)

	.  reduce 219


state 196
	jump_statement : BREAK ';' .  (220)

	.  reduce 220


state 197
	jump_statement : RETURN ';' .  (221)

	.  reduce 221


state 198
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 240
	';'  shift 286


state 199
	labeled_statement : default_pre statement .  (194)

	.  reduce 194


state 200
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	additive_exp  goto 287
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 201
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	additive_exp  goto 288
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 202
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	multiplicative_exp  goto 289
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 203
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	multiplicative_exp  goto 290
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 204
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 291
	additive_exp  goto 116
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 205
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 292
	additive_exp  goto 116
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 206
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 293
	additive_exp  goto 116
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 207
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 294
	additive_exp  goto 116
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 208
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 295
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 209
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 296
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 210
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 297
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 211
	assignment_operator : '=' .  (66)

	.  reduce 66


state 212
	assignment_operator : MUL_ASSIGN .  (67)

	.  reduce 67


state 213
	assignment_operator : DIV_ASSIGN .  (68)

	.  reduce 68


state 214
	assignment_operator : MOD_ASSIGN .  (69)

	.  reduce 69


state 215
	assignment_operator : ADD_ASSIGN .  (70)

	.  reduce 70


state 216
	assignment_operator : SUB_ASSIGN .  (71)

	.  reduce 71


state 217
	assignment_operator : LEFT_ASSIGN .  (72)

	.  reduce 72


state 218
	assignment_operator : RIGHT_ASSIGN .  (73)

	.  reduce 73


state 219
	assignment_operator : AND_ASSIGN .  (74)

	.  reduce 74


state 220
	assignment_operator : XOR_ASSIGN .  (75)

	.  reduce 75


state 221
	assignment_operator : OR_ASSIGN .  (76)

	.  reduce 76


state 222
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 298
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 223
	unary_exp : unary_operator cast_exp .  (21)

	.  reduce 21


state 224
	postfix_pre_exp : postfix_exp '(' .  (7)

	.  reduce 7


state 225
	postfix_exp : postfix_exp '.' . ID

	ID  shift 299


state 226
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 300
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 227
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 301


state 228
	postfix_exp : postfix_exp INC_OP .  (14)

	.  reduce 14


state 229
	postfix_exp : postfix_exp DEC_OP .  (15)

	.  reduce 15


state 230
	compound_statement : '{' declaration_list '}' .  (197)

	.  reduce 197


state 231
	statement_list : statement_list . M statement
	compound_statement : '{' declaration_list statement_list . '}'
	M : .  (58)

	'}'  shift 302
	.  reduce 58

	M  goto 233


state 232
	compound_statement : '{' statement_list '}' .  (196)

	.  reduce 196


state 233
	statement_list : statement_list M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 303
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 234
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 304
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 235
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 305
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 236
	and_exp : and_exp '&' . equality_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 306
	postfix_pre_exp  goto 146


state 237
	logical_and_exp : logical_and_exp AND_OP . M inclusive_or_exp
	M : .  (58)

	.  reduce 58

	M  goto 307


state 238
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	exclusive_or_exp  goto 308
	postfix_pre_exp  goto 146


state 239
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 309
	postfix_pre_exp  goto 146


state 240
	exp : exp ',' . assignment_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 310
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 241
	exp_statement : exp ';' .  (204)

	.  reduce 204


state 242
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 311
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 243
	logical_or_exp : logical_or_exp OR_OP . M logical_and_exp
	M : .  (58)

	.  reduce 58

	M  goto 312


state 244
	selection_statement : switch_pre statement .  (212)

	.  reduce 212


state 245
	postfix_exp : postfix_pre_exp ')' .  (10)

	.  reduce 10


state 246
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 313
	','  shift 314


state 247
	argument_exp_list : assignment_exp .  (16)

	.  reduce 16


state 248
	declaration_list : declaration_list M declaration .  (200)

	.  reduce 200


state 249
	direct_declarator : direct_declarator '[' constant_exp ']' .  (145)

	.  reduce 145


state 250
	initializer : '{' . initializer_list ',' '}'
	initializer : '{' . initializer_list '}'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'{'  shift 250
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	initializer  goto 315
	initializer_list  goto 316
	assignment_exp  goto 252
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 251
	init_declarator : declarator '=' initializer .  (91)

	.  reduce 91


state 252
	initializer : assignment_exp .  (179)

	.  reduce 179


state 253
	init_declarator_list : init_declarator_list ',' init_declarator .  (89)

	.  reduce 89


state 254
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (227)

	.  reduce 227


state 255
	parameter_type_list : parameter_list ',' ELLIPSIS .  (157)

	.  reduce 157


state 256
	parameter_list : parameter_list ',' parameter_declaration .  (159)

	.  reduce 159


state 257
	identifier_list : identifier_list ',' ID .  (164)

	.  reduce 164


state 258
	direct_abstract_declarator : '(' ')' .  (175)

	.  reduce 175


state 259
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 317


state 260
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 318


state 261
	direct_abstract_declarator : '[' ']' .  (171)

	.  reduce 171


state 262
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 319


state 263
	abstract_declarator : pointer direct_abstract_declarator .  (169)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 264
	'['  shift 265
	.  reduce 169


state 264
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

	')'  shift 320
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

	parameter_list  goto 71
	struct_or_union  goto 24
	type_qualifier  goto 25
	parameter_type_list  goto 321
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	parameter_declaration  goto 74
	enum_specifier  goto 30
	struct_or_union_def  goto 32
	declaration_specifiers  goto 75
	storage_class_specifier  goto 34


state 265
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	']'  shift 322
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	constant_exp  goto 323
	logical_or_exp  goto 137
	conditional_exp  goto 153
	postfix_pre_exp  goto 146


state 266
	enumerator : ID '=' constant_exp .  (137)

	.  reduce 137


state 267
	enumerator_list : enumerator_list ',' enumerator .  (135)

	.  reduce 135


state 268
	enum_specifier : ENUM ID '{' enumerator_list '}' .  (132)

	.  reduce 132


state 269
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (110)

	.  reduce 110


state 270
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (124)

	.  reduce 124


state 271
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 324
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	postfix_pre_exp  goto 146


state 272
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (122)

	.  reduce 122


state 273
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 273
	')'  shift 258
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

	parameter_list  goto 71
	struct_or_union  goto 24
	abstract_declarator  goto 259
	type_qualifier  goto 25
	pointer  goto 275
	parameter_type_list  goto 260
	type_specifier  goto 27
	struct_or_union_specifier  goto 28
	parameter_declaration  goto 74
	enum_specifier  goto 30
	direct_abstract_declarator  goto 169
	struct_or_union_def  goto 32
	declaration_specifiers  goto 75
	storage_class_specifier  goto 34


state 274
	type_name : specifier_qualifier_list abstract_declarator .  (166)

	.  reduce 166


state 275
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (167)

	'('  shift 273
	'['  shift 165
	.  reduce 167

	direct_abstract_declarator  goto 263


state 276
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 277
	labeled_statement : ID ':' statement .  (192)

	.  reduce 192


state 278
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 325


state 279
	labeled_statement : CASE constant_exp ':' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 326


state 280
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp . ')' M stmt
	open_statement : IF '(' exp . ')' M matched_statement N ELSE M open_statement

	')'  shift 327
	','  shift 240


state 281
	exp : exp . ',' assignment_exp
	switch_pre : SWITCH '(' exp . ')'

	')'  shift 328
	','  shift 240


state 282
	iteration_statement : WHILE M '(' . exp ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 329
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 283
	iteration_statement : DO M statement . WHILE M '(' exp ')' ';'

	WHILE  shift 330


state 284
	iteration_statement : FOR '(' exp_statement . M exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement . M exp_statement M exp ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 331


state 285
	jump_statement : GOTO ID ';' .  (218)

	.  reduce 218


state 286
	jump_statement : RETURN exp ';' .  (222)

	.  reduce 222


state 287
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (40)

	'+'  shift 202
	'-'  shift 203
	.  reduce 40


state 288
	shift_exp : shift_exp RIGHT_OP additive_exp .  (41)
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp

	'+'  shift 202
	'-'  shift 203
	.  reduce 41


state 289
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (37)

	'%'  shift 208
	'*'  shift 209
	'/'  shift 210
	.  reduce 37


state 290
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (38)

	'%'  shift 208
	'*'  shift 209
	'/'  shift 210
	.  reduce 38


state 291
	relational_exp : relational_exp '<' shift_exp .  (43)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 200
	RIGHT_OP  shift 201
	.  reduce 43


state 292
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '>' shift_exp .  (44)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 200
	RIGHT_OP  shift 201
	.  reduce 44


state 293
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (45)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 200
	RIGHT_OP  shift 201
	.  reduce 45


state 294
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp GE_OP shift_exp .  (46)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 200
	RIGHT_OP  shift 201
	.  reduce 46


state 295
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (35)

	.  reduce 35


state 296
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (33)

	.  reduce 33


state 297
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (34)

	.  reduce 34


state 298
	assignment_exp : unary_exp assignment_operator assignment_exp .  (65)

	.  reduce 65


state 299
	postfix_exp : postfix_exp '.' ID .  (12)

	.  reduce 12


state 300
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 240
	']'  shift 332


state 301
	postfix_exp : postfix_exp PTR_OP ID .  (13)

	.  reduce 13


state 302
	compound_statement : '{' declaration_list statement_list '}' .  (198)

	.  reduce 198


state 303
	statement_list : statement_list M statement .  (202)

	.  reduce 202


state 304
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (48)
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 204
	'>'  shift 205
	LE_OP  shift 206
	GE_OP  shift 207
	.  reduce 48


state 305
	relational_exp : relational_exp . '<' shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (49)
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 204
	'>'  shift 205
	LE_OP  shift 206
	GE_OP  shift 207
	.  reduce 49


state 306
	equality_exp : equality_exp . NE_OP relational_exp
	and_exp : and_exp '&' equality_exp .  (51)
	equality_exp : equality_exp . EQ_OP relational_exp

	EQ_OP  shift 234
	NE_OP  shift 235
	.  reduce 51


state 307
	logical_and_exp : logical_and_exp AND_OP M . inclusive_or_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	inclusive_or_exp  goto 333
	exclusive_or_exp  goto 135
	postfix_pre_exp  goto 146


state 308
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (55)

	'^'  shift 239
	.  reduce 55


state 309
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (53)

	'&'  shift 236
	.  reduce 53


state 310
	exp : exp ',' assignment_exp .  (78)

	.  reduce 78


state 311
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 240
	':'  shift 334


state 312
	logical_or_exp : logical_or_exp OR_OP M . logical_and_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 335
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	postfix_pre_exp  goto 146


state 313
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (11)

	.  reduce 11


state 314
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 336
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 315
	initializer_list : initializer .  (182)

	.  reduce 182


state 316
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . ',' '}'
	initializer : '{' initializer_list . '}'

	','  shift 337
	'}'  shift 338


state 317
	direct_abstract_declarator : '(' abstract_declarator ')' .  (170)

	.  reduce 170


state 318
	direct_abstract_declarator : '(' parameter_type_list ')' .  (176)

	.  reduce 176


state 319
	direct_abstract_declarator : '[' constant_exp ']' .  (172)

	.  reduce 172


state 320
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (177)

	.  reduce 177


state 321
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 339


state 322
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (173)

	.  reduce 173


state 323
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp . ']'

	']'  shift 340


state 324
	cast_exp : '(' type_name ')' cast_exp .  (31)

	.  reduce 31


state 325
	unary_exp : SIZEOF '(' type_name ')' .  (23)

	.  reduce 23


state 326
	labeled_statement : CASE constant_exp ':' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 341
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 327
	matched_statement : IF '(' exp ')' . M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' . M stmt
	open_statement : IF '(' exp ')' . M matched_statement N ELSE M open_statement
	M : .  (58)

	.  reduce 58

	M  goto 342


state 328
	switch_pre : SWITCH '(' exp ')' .  (213)

	.  reduce 213


state 329
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE M '(' exp . ')' M statement

	')'  shift 343
	','  shift 240


state 330
	iteration_statement : DO M statement WHILE . M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 344


state 331
	iteration_statement : FOR '(' exp_statement M . exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement M . exp_statement M exp ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	exp_statement  goto 345
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 332
	postfix_exp : postfix_exp '[' exp ']' .  (9)

	.  reduce 9


state 333
	logical_and_exp : logical_and_exp AND_OP M inclusive_or_exp .  (57)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 238
	.  reduce 57


state 334
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 151
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 346
	postfix_pre_exp  goto 146


state 335
	logical_or_exp : logical_or_exp OR_OP M logical_and_exp .  (61)
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp

	AND_OP  shift 237
	.  reduce 61


state 336
	argument_exp_list : argument_exp_list ',' assignment_exp .  (17)

	.  reduce 17


state 337
	initializer_list : initializer_list ',' . initializer
	initializer : '{' initializer_list ',' . '}'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'{'  shift 250
	'}'  shift 347
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	initializer  goto 348
	assignment_exp  goto 252
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 338
	initializer : '{' initializer_list '}' .  (180)

	.  reduce 180


state 339
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (178)

	.  reduce 178


state 340
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (174)

	.  reduce 174


state 341
	labeled_statement : CASE constant_exp ':' M statement .  (193)

	.  reduce 193


state 342
	matched_statement : IF '(' exp ')' M . matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' M . stmt
	open_statement : IF '(' exp ')' M . matched_statement N ELSE M open_statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	IF  shift 104
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 349
	open_statement  goto 141
	other  goto 350
	stmt  goto 351
	postfix_pre_exp  goto 146


state 343
	iteration_statement : WHILE M '(' exp ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 352


state 344
	iteration_statement : DO M statement WHILE M . '(' exp ')' ';'

	'('  shift 353


state 345
	iteration_statement : FOR '(' exp_statement M exp_statement . ')' M statement
	iteration_statement : FOR '(' exp_statement M exp_statement . M exp ')' M statement
	M : .  (58)

	')'  shift 354
	.  reduce 58

	M  goto 355


state 346
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (63)

	.  reduce 63


state 347
	initializer : '{' initializer_list ',' '}' .  (181)

	.  reduce 181


state 348
	initializer_list : initializer_list ',' initializer .  (183)

	.  reduce 183


349: reduce-reduce conflict (reduce 59, reduce 205) on ELSE
state 349
	stmt : matched_statement .  (205)
	matched_statement : IF '(' exp ')' M matched_statement . N ELSE M matched_statement
	open_statement : IF '(' exp ')' M matched_statement . N ELSE M open_statement
	N : .  (59)

	ELSE  reduce 59
	.  reduce 205

	N  goto 356


state 350
	matched_statement : other .  (208)

	.  reduce 208


state 351
	open_statement : IF '(' exp ')' M stmt .  (209)

	.  reduce 209


state 352
	iteration_statement : WHILE M '(' exp ')' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 357
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 353
	iteration_statement : DO M statement WHILE M '(' . exp ')' ';'

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 358
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 354
	iteration_statement : FOR '(' exp_statement M exp_statement ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 359


state 355
	iteration_statement : FOR '(' exp_statement M exp_statement M . exp ')' M statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 360
	logical_or_exp  goto 137
	conditional_exp  goto 138
	postfix_pre_exp  goto 146


state 356
	matched_statement : IF '(' exp ')' M matched_statement N . ELSE M matched_statement
	open_statement : IF '(' exp ')' M matched_statement N . ELSE M open_statement

	ELSE  shift 361


state 357
	iteration_statement : WHILE M '(' exp ')' M statement .  (214)

	.  reduce 214


state 358
	exp : exp . ',' assignment_exp
	iteration_statement : DO M statement WHILE M '(' exp . ')' ';'

	')'  shift 362
	','  shift 240


state 359
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 363
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 360
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement M exp_statement M exp . ')' M statement

	')'  shift 364
	','  shift 240


state 361
	matched_statement : IF '(' exp ')' M matched_statement N ELSE . M matched_statement
	open_statement : IF '(' exp ')' M matched_statement N ELSE . M open_statement
	M : .  (58)

	.  reduce 58

	M  goto 365


state 362
	iteration_statement : DO M statement WHILE M '(' exp ')' . ';'

	';'  shift 366


state 363
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M statement .  (216)

	.  reduce 216


state 364
	iteration_statement : FOR '(' exp_statement M exp_statement M exp ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 367


state 365
	matched_statement : IF '(' exp ')' M matched_statement N ELSE M . matched_statement
	open_statement : IF '(' exp ')' M matched_statement N ELSE M . open_statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 150
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	IF  shift 104
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 368
	open_statement  goto 369
	other  goto 350
	postfix_pre_exp  goto 146


state 366
	iteration_statement : DO M statement WHILE M '(' exp ')' ';' .  (215)

	.  reduce 215


state 367
	iteration_statement : FOR '(' exp_statement M exp_statement M exp ')' M . statement

	'!'  shift 85
	'&'  shift 86
	'('  shift 87
	'*'  shift 88
	'+'  shift 89
	'-'  shift 90
	';'  shift 91
	'{'  shift 52
	'~'  shift 93
	ID  shift 94
	CONSTANT  shift 95
	STRING_LITERAL  shift 96
	SIZEOF  shift 97
	INC_OP  shift 98
	DEC_OP  shift 99
	TRUE  shift 100
	FALSE  shift 101
	CASE  shift 102
	DEFAULT  shift 103
	IF  shift 104
	SWITCH  shift 105
	WHILE  shift 106
	DO  shift 107
	FOR  shift 108
	GOTO  shift 109
	CONTINUE  shift 110
	BREAK  shift 111
	RETURN  shift 112

	default_pre  goto 113
	cast_exp  goto 114
	shift_exp  goto 115
	additive_exp  goto 116
	relational_exp  goto 117
	multiplicative_exp  goto 118
	unary_exp  goto 119
	unary_operator  goto 120
	primary_exp  goto 121
	postfix_exp  goto 122
	statement  goto 370
	labeled_statement  goto 124
	compound_statement  goto 125
	exp_statement  goto 128
	iteration_statement  goto 129
	assignment_exp  goto 130
	equality_exp  goto 131
	and_exp  goto 132
	logical_and_exp  goto 133
	inclusive_or_exp  goto 134
	exclusive_or_exp  goto 135
	exp  goto 136
	logical_or_exp  goto 137
	conditional_exp  goto 138
	jump_statement  goto 139
	matched_statement  goto 140
	open_statement  goto 141
	selection_statement  goto 142
	other  goto 143
	stmt  goto 144
	switch_pre  goto 145
	postfix_pre_exp  goto 146


state 368
	matched_statement : IF '(' exp ')' M matched_statement N ELSE M matched_statement .  (207)

	.  reduce 207


state 369
	open_statement : IF '(' exp ')' M matched_statement N ELSE M open_statement .  (210)

	.  reduce 210


state 370
	iteration_statement : FOR '(' exp_statement M exp_statement M exp ')' M statement .  (217)

	.  reduce 217


Rules never reduced
	struct_declaration_list : struct_declaration  (118)
	struct_declaration_list : struct_declaration_list struct_declaration  (119)
	struct_declaration : specifier_qualifier_list struct_declarator_list ';'  (120)
	struct_declaration : assignment_exp struct_declarator_list ';'  (121)
	struct_declarator_list : struct_declarator  (126)
	struct_declarator_list : struct_declarator_list ',' struct_declarator  (127)
	struct_declarator : declarator  (128)
	struct_declarator : ':' constant_exp  (129)
	struct_declarator : declarator ':' constant_exp  (130)


##############################################################################
# Summary
##############################################################################

State 2 contains 3 shift-reduce conflict(s)
State 27 contains 1 shift-reduce conflict(s)
State 41 contains 3 shift-reduce conflict(s)
State 143 contains 30 reduce-reduce conflict(s)
State 178 contains 1 shift-reduce conflict(s)
State 349 contains 1 reduce-reduce conflict(s)


86 token(s), 76 nonterminal(s)
231 grammar rule(s), 371 state(s)


##############################################################################
# End of File
##############################################################################
