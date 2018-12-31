#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 83 of your 30 day trial period.
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
# Date: 12/31/18
# Time: 20:27:13
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

	direct_pre_declarator  goto 24
	translation_unit  goto 25
	external_declaration  goto 26
	function_definition  goto 27
	type_qualifier  goto 28
	direct_declarator  goto 29
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	declarator  goto 32
	struct_or_union  goto 33
	pointer  goto 34
	declaration_specifiers  goto 35
	declaration  goto 36
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_pre_declarator  goto 24
	direct_declarator  goto 29
	declarator  goto 40
	pointer  goto 34


2: shift-reduce conflict (shift 2, reduce 150) on '*'
2: shift-reduce conflict (shift 18, reduce 150) on CONST
2: shift-reduce conflict (shift 19, reduce 150) on VOLATILE
state 2
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' .  (150)
	pointer : '*' . pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 150

	type_qualifier  goto 41
	pointer  goto 42
	type_qualifier_list  goto 43


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
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . ID

	'{'  shift 44
	ID  shift 45


state 24
	direct_declarator : direct_pre_declarator . parameter_type_list ')'
	direct_declarator : direct_pre_declarator . ')'
	direct_declarator : direct_pre_declarator . identifier_list ')'

	')'  shift 46
	ID  shift 47
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	identifier_list  goto 48
	parameter_list  goto 49
	enum_specifier  goto 31
	struct_or_union  goto 33
	parameter_type_list  goto 50
	parameter_declaration  goto 51
	declaration_specifiers  goto 52
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


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

	direct_pre_declarator  goto 24
	external_declaration  goto 53
	function_definition  goto 27
	type_qualifier  goto 28
	direct_declarator  goto 29
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	declarator  goto 32
	struct_or_union  goto 33
	pointer  goto 34
	declaration_specifiers  goto 35
	declaration  goto 36
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 26
	translation_unit : external_declaration .  (223)

	.  reduce 223


state 27
	external_declaration : function_definition .  (225)

	.  reduce 225


state 28
	declaration_specifiers : type_qualifier .  (86)
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
	.  reduce 86

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	declaration_specifiers  goto 54
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 29
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'
	declarator : direct_declarator .  (141)
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 55
	'['  shift 56
	.  reduce 141


state 30
	type_specifier : struct_or_union_specifier .  (106)

	.  reduce 106


state 31
	type_specifier : enum_specifier .  (107)

	.  reduce 107


state 32
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

	'{'  shift 57
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	declaration_list  goto 58
	compound_statement  goto 59
	declaration_specifiers  goto 60
	declaration  goto 61
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 33
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'
	struct_or_union_def : struct_or_union . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID

	'{'  shift 62
	ID  shift 63


state 34
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_pre_declarator  goto 24
	direct_declarator  goto 64


state 35
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 65
	ID  shift 3

	direct_pre_declarator  goto 24
	direct_declarator  goto 29
	declarator  goto 66
	pointer  goto 34
	init_declarator_list  goto 67
	init_declarator  goto 68


state 36
	external_declaration : declaration .  (226)

	.  reduce 226


state 37
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	declaration_specifiers  goto 69
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 38
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 70
	ID  shift 3

	direct_pre_declarator  goto 24
	direct_declarator  goto 29
	declarator  goto 71
	pointer  goto 34
	init_declarator_list  goto 72
	init_declarator  goto 68
	def_concat  goto 73


39: shift-reduce conflict (shift 2, reduce 84) on '*'
state 39
	declaration_specifiers : type_specifier .  (84)
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
	.  reduce 84

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	pointer  goto 74
	declaration_specifiers  goto 75
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 40
	direct_declarator : '(' declarator . ')'

	')'  shift 76


state 41
	type_qualifier_list : type_qualifier .  (154)

	.  reduce 154


state 42
	pointer : '*' pointer .  (152)

	.  reduce 152


43: shift-reduce conflict (shift 2, reduce 151) on '*'
43: shift-reduce conflict (shift 18, reduce 151) on CONST
43: shift-reduce conflict (shift 19, reduce 151) on VOLATILE
state 43
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (151)
	type_qualifier_list : type_qualifier_list . type_qualifier

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 151

	type_qualifier  goto 77
	pointer  goto 78


state 44
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 79

	enumerator  goto 80
	enumerator_list  goto 81


state 45
	enum_specifier : ENUM ID . '{' enumerator_list '}'
	enum_specifier : ENUM ID .  (133)

	'{'  shift 82
	.  reduce 133


state 46
	direct_declarator : direct_pre_declarator ')' .  (149)

	.  reduce 149


state 47
	identifier_list : ID .  (163)

	.  reduce 163


state 48
	identifier_list : identifier_list . ',' ID
	direct_declarator : direct_pre_declarator identifier_list . ')'

	')'  shift 83
	','  shift 84


state 49
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_type_list : parameter_list .  (156)
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 85
	.  reduce 156


state 50
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 86


state 51
	parameter_list : parameter_declaration .  (158)

	.  reduce 158


state 52
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (162)

	'('  shift 87
	'*'  shift 2
	'['  shift 88
	ID  shift 3
	.  reduce 162

	direct_pre_declarator  goto 24
	direct_declarator  goto 29
	abstract_declarator  goto 89
	direct_abstract_declarator  goto 90
	declarator  goto 91
	pointer  goto 92


state 53
	translation_unit : translation_unit external_declaration .  (224)

	.  reduce 224


state 54
	declaration_specifiers : type_qualifier declaration_specifiers .  (87)

	.  reduce 87


state 55
	direct_pre_declarator : direct_declarator '(' .  (142)

	.  reduce 142


state 56
	direct_declarator : direct_declarator '[' . constant_exp ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	']'  shift 99
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	exclusive_or_exp  goto 122
	constant_exp  goto 123
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 126


state 57
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . '}'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'}'  shift 128
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TYPE_NAME  shift 4
	TRUE  shift 107
	FALSE  shift 108
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
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	statement  goto 149
	statement_list  goto 150
	exp_statement  goto 151
	iteration_statement  goto 152
	enum_specifier  goto 31
	struct_or_union  goto 33
	jump_statement  goto 153
	declaration_list  goto 154
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	declaration_specifiers  goto 60
	inclusive_or_exp  goto 121
	declaration  goto 61
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 58
	declaration_list : declaration_list . M declaration
	function_definition : declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 57
	.  reduce 58

	M  goto 160
	compound_statement  goto 161


state 59
	function_definition : declarator compound_statement .  (230)

	.  reduce 230


state 60
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 65
	ID  shift 3

	direct_pre_declarator  goto 24
	direct_declarator  goto 29
	declarator  goto 71
	pointer  goto 34
	init_declarator_list  goto 67
	init_declarator  goto 68


state 61
	declaration_list : declaration .  (199)

	.  reduce 199


state 62
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	declaration_list  goto 162
	declaration_specifiers  goto 60
	declaration  goto 61
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 63
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union ID .  (115)

	'{'  shift 163
	.  reduce 115


state 64
	direct_pre_declarator : direct_declarator . '('
	declarator : pointer direct_declarator .  (140)
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 55
	'['  shift 56
	.  reduce 140


state 65
	declaration : declaration_specifiers ';' .  (80)

	.  reduce 80


state 66
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 164
	'{'  shift 57
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	declaration_list  goto 165
	compound_statement  goto 166
	declaration_specifiers  goto 60
	declaration  goto 61
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 67
	init_declarator_list : init_declarator_list . ',' init_declarator
	declaration : declaration_specifiers init_declarator_list . ';'

	','  shift 167
	';'  shift 168


state 68
	init_declarator_list : init_declarator .  (88)

	.  reduce 88


state 69
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (83)

	.  reduce 83


state 70
	def_concat : ';' .  (112)

	.  reduce 112


state 71
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)

	'='  shift 164
	.  reduce 90


state 72
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 167
	';'  shift 169


state 73
	struct_or_union_specifier : struct_or_union_def def_concat .  (114)

	.  reduce 114


state 74
	type_specifier : type_specifier pointer .  (109)

	.  reduce 109


state 75
	declaration_specifiers : type_specifier declaration_specifiers .  (85)

	.  reduce 85


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
	enumerator : ID . '=' constant_exp
	enumerator : ID .  (136)

	'='  shift 170
	.  reduce 136


state 80
	enumerator_list : enumerator .  (134)

	.  reduce 134


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
	direct_declarator : direct_pre_declarator identifier_list ')' .  (148)

	.  reduce 148


state 84
	identifier_list : identifier_list ',' . ID

	ID  shift 174


state 85
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
	ELLIPSIS  shift 175

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	parameter_declaration  goto 176
	declaration_specifiers  goto 52
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 86
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (147)

	.  reduce 147


state 87
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 87
	')'  shift 177
	'*'  shift 2
	'['  shift 88
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

	direct_pre_declarator  goto 24
	type_qualifier  goto 28
	direct_declarator  goto 29
	struct_or_union_specifier  goto 30
	abstract_declarator  goto 178
	direct_abstract_declarator  goto 90
	parameter_list  goto 49
	enum_specifier  goto 31
	declarator  goto 40
	struct_or_union  goto 33
	pointer  goto 92
	parameter_type_list  goto 179
	parameter_declaration  goto 51
	declaration_specifiers  goto 52
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 88
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	']'  shift 180
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	exclusive_or_exp  goto 122
	constant_exp  goto 181
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 126


state 89
	parameter_declaration : declaration_specifiers abstract_declarator .  (161)

	.  reduce 161


state 90
	abstract_declarator : direct_abstract_declarator .  (168)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'

	'('  shift 182
	'['  shift 183
	.  reduce 168


state 91
	parameter_declaration : declaration_specifiers declarator .  (160)

	.  reduce 160


state 92
	declarator : pointer . direct_declarator
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (167)

	'('  shift 87
	'['  shift 88
	ID  shift 3
	.  reduce 167

	direct_pre_declarator  goto 24
	direct_declarator  goto 64
	direct_abstract_declarator  goto 184


state 93
	unary_operator : '!' .  (29)

	.  reduce 29


state 94
	unary_operator : '&' .  (24)

	.  reduce 24


state 95
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TYPE_NAME  shift 4
	TRUE  shift 107
	FALSE  shift 108
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

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	type_qualifier  goto 185
	struct_or_union_specifier  goto 30
	type_name  goto 186
	enum_specifier  goto 31
	struct_or_union  goto 33
	specifier_qualifier_list  goto 187
	exp  goto 188
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	struct_or_union_def  goto 38
	type_specifier  goto 189
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 96
	unary_operator : '*' .  (25)

	.  reduce 25


state 97
	unary_operator : '+' .  (26)

	.  reduce 26


state 98
	unary_operator : '-' .  (27)

	.  reduce 27


state 99
	direct_declarator : direct_declarator '[' ']' .  (146)

	.  reduce 146


state 100
	unary_operator : '~' .  (28)

	.  reduce 28


state 101
	primary_exp : ID .  (1)

	.  reduce 1


state 102
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 103
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 104
	unary_exp : SIZEOF . unary_exp
	unary_exp : SIZEOF . '(' type_name ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 190
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 191
	unary_operator  goto 112
	primary_exp  goto 114


state 105
	unary_exp : INC_OP . unary_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 192
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 193
	unary_operator  goto 112
	primary_exp  goto 114


state 106
	unary_exp : DEC_OP . unary_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 192
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 194
	unary_operator  goto 112
	primary_exp  goto 114


state 107
	primary_exp : TRUE .  (5)

	.  reduce 5


state 108
	primary_exp : FALSE .  (6)

	.  reduce 6


state 109
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	')'  shift 195
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	argument_exp_list  goto 196
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 197
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 110
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (18)

	'('  shift 198
	'.'  shift 199
	'['  shift 200
	PTR_OP  shift 201
	INC_OP  shift 202
	DEC_OP  shift 203
	.  reduce 18


state 111
	cast_exp : unary_exp .  (30)

	.  reduce 30


state 112
	unary_exp : unary_operator . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 204
	primary_exp  goto 114


state 113
	multiplicative_exp : cast_exp .  (32)

	.  reduce 32


state 114
	postfix_exp : primary_exp .  (8)

	.  reduce 8


state 115
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : multiplicative_exp .  (36)

	'%'  shift 205
	'*'  shift 206
	'/'  shift 207
	.  reduce 36


state 116
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : additive_exp .  (39)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 208
	'-'  shift 209
	.  reduce 39


state 117
	relational_exp : shift_exp .  (42)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 210
	RIGHT_OP  shift 211
	.  reduce 42


state 118
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	equality_exp : relational_exp .  (47)
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 212
	'>'  shift 213
	LE_OP  shift 214
	GE_OP  shift 215
	.  reduce 47


state 119
	equality_exp : equality_exp . NE_OP relational_exp
	and_exp : equality_exp .  (50)
	equality_exp : equality_exp . EQ_OP relational_exp

	EQ_OP  shift 216
	NE_OP  shift 217
	.  reduce 50


state 120
	logical_or_exp : logical_or_exp . OR_OP M logical_and_exp
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp
	conditional_exp : logical_or_exp .  (62)

	'?'  shift 218
	OR_OP  shift 219
	.  reduce 62


state 121
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : inclusive_or_exp .  (56)

	'|'  shift 220
	.  reduce 56


state 122
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : exclusive_or_exp .  (54)

	'^'  shift 221
	.  reduce 54


state 123
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 222


state 124
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : and_exp .  (52)

	'&'  shift 223
	.  reduce 52


state 125
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_and_exp .  (60)

	AND_OP  shift 224
	.  reduce 60


state 126
	constant_exp : conditional_exp .  (79)

	.  reduce 79


state 127
	exp_statement : ';' .  (203)

	.  reduce 203


state 128
	compound_statement : '{' '}' .  (195)

	.  reduce 195


state 129
	labeled_statement : ID . ':' statement
	primary_exp : ID .  (1)

	':'  shift 225
	.  reduce 1


state 130
	labeled_statement : CASE . constant_exp ':' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	exclusive_or_exp  goto 122
	constant_exp  goto 226
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 126


state 131
	default_pre : DEFAULT . ':'

	':'  shift 227


state 132
	matched_statement : IF . '(' exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF . '(' exp ')' M stmt
	open_statement : IF . '(' exp ')' M matched_statement N ELSE M open_statement

	'('  shift 228


state 133
	switch_pre : SWITCH . '(' exp ')'

	'('  shift 229


state 134
	iteration_statement : WHILE . M '(' exp ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 230


state 135
	iteration_statement : DO . M statement WHILE M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 231


state 136
	iteration_statement : FOR . '(' exp_statement M exp_statement ')' M statement
	iteration_statement : FOR . '(' exp_statement M exp_statement M exp ')' M statement

	'('  shift 232


state 137
	jump_statement : GOTO . ID ';'

	ID  shift 233


state 138
	jump_statement : CONTINUE . ';'

	';'  shift 234


state 139
	jump_statement : BREAK . ';'

	';'  shift 235


state 140
	jump_statement : RETURN . ';'
	jump_statement : RETURN . exp ';'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 236
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 237
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 141
	selection_statement : switch_pre . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 238
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 142
	statement : selection_statement .  (190)

	.  reduce 190


state 143
	selection_statement : stmt .  (211)

	.  reduce 211


144: reduce-reduce conflict (reduce 189, reduce 208) on '!'
144: reduce-reduce conflict (reduce 189, reduce 208) on '&'
144: reduce-reduce conflict (reduce 189, reduce 208) on '('
144: reduce-reduce conflict (reduce 189, reduce 208) on '*'
144: reduce-reduce conflict (reduce 189, reduce 208) on '+'
144: reduce-reduce conflict (reduce 189, reduce 208) on '-'
144: reduce-reduce conflict (reduce 189, reduce 208) on ';'
144: reduce-reduce conflict (reduce 189, reduce 208) on '{'
144: reduce-reduce conflict (reduce 189, reduce 208) on '}'
144: reduce-reduce conflict (reduce 189, reduce 208) on '~'
144: reduce-reduce conflict (reduce 189, reduce 208) on ID
144: reduce-reduce conflict (reduce 189, reduce 208) on CONSTANT
144: reduce-reduce conflict (reduce 189, reduce 208) on STRING_LITERAL
144: reduce-reduce conflict (reduce 189, reduce 208) on SIZEOF
144: reduce-reduce conflict (reduce 189, reduce 208) on INC_OP
144: reduce-reduce conflict (reduce 189, reduce 208) on DEC_OP
144: reduce-reduce conflict (reduce 189, reduce 208) on TRUE
144: reduce-reduce conflict (reduce 189, reduce 208) on FALSE
144: reduce-reduce conflict (reduce 189, reduce 208) on CASE
144: reduce-reduce conflict (reduce 189, reduce 208) on DEFAULT
144: reduce-reduce conflict (reduce 189, reduce 208) on IF
144: reduce-reduce conflict (reduce 189, reduce 208) on ELSE
144: reduce-reduce conflict (reduce 189, reduce 208) on SWITCH
144: reduce-reduce conflict (reduce 189, reduce 208) on WHILE
144: reduce-reduce conflict (reduce 189, reduce 208) on DO
144: reduce-reduce conflict (reduce 189, reduce 208) on FOR
144: reduce-reduce conflict (reduce 189, reduce 208) on GOTO
144: reduce-reduce conflict (reduce 189, reduce 208) on CONTINUE
144: reduce-reduce conflict (reduce 189, reduce 208) on BREAK
144: reduce-reduce conflict (reduce 189, reduce 208) on RETURN
state 144
	statement : other .  (189)
	matched_statement : other .  (208)

	.  reduce 189


state 145
	stmt : open_statement .  (206)

	.  reduce 206


state 146
	stmt : matched_statement .  (205)

	.  reduce 205


state 147
	labeled_statement : default_pre . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 239
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 148
	cast_exp : unary_exp .  (30)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 240
	MUL_ASSIGN  shift 241
	DIV_ASSIGN  shift 242
	MOD_ASSIGN  shift 243
	ADD_ASSIGN  shift 244
	SUB_ASSIGN  shift 245
	LEFT_ASSIGN  shift 246
	RIGHT_ASSIGN  shift 247
	AND_ASSIGN  shift 248
	XOR_ASSIGN  shift 249
	OR_ASSIGN  shift 250
	.  reduce 30

	assignment_operator  goto 251


state 149
	statement_list : statement .  (201)

	.  reduce 201


state 150
	statement_list : statement_list . M statement
	compound_statement : '{' statement_list . '}'
	M : .  (58)

	'}'  shift 252
	.  reduce 58

	M  goto 253


state 151
	other : exp_statement .  (185)

	.  reduce 185


state 152
	other : iteration_statement .  (186)

	.  reduce 186


state 153
	other : jump_statement .  (187)

	.  reduce 187


state 154
	compound_statement : '{' declaration_list . '}'
	compound_statement : '{' declaration_list . statement_list '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'}'  shift 254
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140
	.  reduce 58

	M  goto 160
	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 149
	statement_list  goto 255
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 155
	statement : labeled_statement .  (188)

	.  reduce 188


state 156
	other : compound_statement .  (184)

	.  reduce 184


state 157
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 256
	';'  shift 257


state 158
	exp : assignment_exp .  (77)

	.  reduce 77


state 159
	assignment_exp : conditional_exp .  (64)

	.  reduce 64


state 160
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	declaration_specifiers  goto 60
	declaration  goto 258
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 161
	function_definition : declarator declaration_list compound_statement .  (229)

	.  reduce 229


state 162
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 259
	.  reduce 58

	M  goto 160


state 163
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	declaration_list  goto 260
	declaration_specifiers  goto 60
	declaration  goto 61
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 164
	init_declarator : declarator '=' . initializer

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'{'  shift 261
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	initializer  goto 262
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 263
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 165
	declaration_list : declaration_list . M declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 57
	.  reduce 58

	M  goto 160
	compound_statement  goto 264


state 166
	function_definition : declaration_specifiers declarator compound_statement .  (228)

	.  reduce 228


state 167
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_pre_declarator  goto 24
	direct_declarator  goto 29
	declarator  goto 71
	pointer  goto 34
	init_declarator  goto 265


state 168
	declaration : declaration_specifiers init_declarator_list ';' .  (81)

	.  reduce 81


state 169
	def_concat : init_declarator_list ';' .  (113)

	.  reduce 113


state 170
	enumerator : ID '=' . constant_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	exclusive_or_exp  goto 122
	constant_exp  goto 266
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 126


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
	identifier_list : identifier_list ',' ID .  (164)

	.  reduce 164


state 175
	parameter_type_list : parameter_list ',' ELLIPSIS .  (157)

	.  reduce 157


state 176
	parameter_list : parameter_list ',' parameter_declaration .  (159)

	.  reduce 159


state 177
	direct_abstract_declarator : '(' ')' .  (175)

	.  reduce 175


state 178
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 269


state 179
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 270


state 180
	direct_abstract_declarator : '[' ']' .  (171)

	.  reduce 171


state 181
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 271


state 182
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'

	')'  shift 272
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	parameter_list  goto 49
	enum_specifier  goto 31
	struct_or_union  goto 33
	parameter_type_list  goto 273
	parameter_declaration  goto 51
	declaration_specifiers  goto 52
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 183
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	']'  shift 274
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	exclusive_or_exp  goto 122
	constant_exp  goto 275
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 126


state 184
	abstract_declarator : pointer direct_abstract_declarator .  (169)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'

	'('  shift 182
	'['  shift 183
	.  reduce 169


state 185
	specifier_qualifier_list : type_qualifier . specifier_qualifier_list
	specifier_qualifier_list : type_qualifier .  (125)

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

	type_qualifier  goto 185
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	specifier_qualifier_list  goto 276
	struct_or_union_def  goto 38
	type_specifier  goto 189


state 186
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 277


state 187
	type_name : specifier_qualifier_list .  (165)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 278
	'*'  shift 2
	'['  shift 88
	.  reduce 165

	abstract_declarator  goto 279
	direct_abstract_declarator  goto 90
	pointer  goto 280


state 188
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 281
	','  shift 256


189: shift-reduce conflict (shift 2, reduce 123) on '*'
state 189
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	specifier_qualifier_list : type_specifier .  (123)
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
	.  reduce 123

	type_qualifier  goto 185
	struct_or_union_specifier  goto 30
	enum_specifier  goto 31
	struct_or_union  goto 33
	pointer  goto 74
	specifier_qualifier_list  goto 282
	struct_or_union_def  goto 38
	type_specifier  goto 189


state 190
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TYPE_NAME  shift 4
	TRUE  shift 107
	FALSE  shift 108
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

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	type_qualifier  goto 185
	struct_or_union_specifier  goto 30
	type_name  goto 283
	enum_specifier  goto 31
	struct_or_union  goto 33
	specifier_qualifier_list  goto 187
	exp  goto 188
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	struct_or_union_def  goto 38
	type_specifier  goto 189
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 191
	unary_exp : SIZEOF unary_exp .  (22)

	.  reduce 22


state 192
	primary_exp : '(' . exp ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 188
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 193
	unary_exp : INC_OP unary_exp .  (19)

	.  reduce 19


state 194
	unary_exp : DEC_OP unary_exp .  (20)

	.  reduce 20


state 195
	postfix_exp : postfix_pre_exp ')' .  (10)

	.  reduce 10


state 196
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 284
	','  shift 285


state 197
	argument_exp_list : assignment_exp .  (16)

	.  reduce 16


state 198
	postfix_pre_exp : postfix_exp '(' .  (7)

	.  reduce 7


state 199
	postfix_exp : postfix_exp '.' . ID

	ID  shift 286


state 200
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 287
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 201
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 288


state 202
	postfix_exp : postfix_exp INC_OP .  (14)

	.  reduce 14


state 203
	postfix_exp : postfix_exp DEC_OP .  (15)

	.  reduce 15


state 204
	unary_exp : unary_operator cast_exp .  (21)

	.  reduce 21


state 205
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 289
	primary_exp  goto 114


state 206
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 290
	primary_exp  goto 114


state 207
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 291
	primary_exp  goto 114


state 208
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 292


state 209
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 293


state 210
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 294


state 211
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 295


state 212
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 296


state 213
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 297


state 214
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 298


state 215
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 299


state 216
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 300


state 217
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 301


state 218
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 302
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 219
	logical_or_exp : logical_or_exp OR_OP . M logical_and_exp
	M : .  (58)

	.  reduce 58

	M  goto 303


state 220
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exclusive_or_exp  goto 304
	and_exp  goto 124


state 221
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	and_exp  goto 305


state 222
	direct_declarator : direct_declarator '[' constant_exp ']' .  (145)

	.  reduce 145


state 223
	and_exp : and_exp '&' . equality_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 306


state 224
	logical_and_exp : logical_and_exp AND_OP . M inclusive_or_exp
	M : .  (58)

	.  reduce 58

	M  goto 307


state 225
	labeled_statement : ID ':' . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 308
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 226
	labeled_statement : CASE constant_exp . ':' M statement

	':'  shift 309


state 227
	default_pre : DEFAULT ':' .  (191)

	.  reduce 191


state 228
	matched_statement : IF '(' . exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' . exp ')' M stmt
	open_statement : IF '(' . exp ')' M matched_statement N ELSE M open_statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 310
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 229
	switch_pre : SWITCH '(' . exp ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 311
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 230
	iteration_statement : WHILE M . '(' exp ')' M statement

	'('  shift 312


state 231
	iteration_statement : DO M . statement WHILE M '(' exp ')' ';'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 313
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 232
	iteration_statement : FOR '(' . exp_statement M exp_statement ')' M statement
	iteration_statement : FOR '(' . exp_statement M exp_statement M exp ')' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp_statement  goto 314
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 233
	jump_statement : GOTO ID . ';'

	';'  shift 315


state 234
	jump_statement : CONTINUE ';' .  (219)

	.  reduce 219


state 235
	jump_statement : BREAK ';' .  (220)

	.  reduce 220


state 236
	jump_statement : RETURN ';' .  (221)

	.  reduce 221


state 237
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 256
	';'  shift 316


state 238
	selection_statement : switch_pre statement .  (212)

	.  reduce 212


state 239
	labeled_statement : default_pre statement .  (194)

	.  reduce 194


state 240
	assignment_operator : '=' .  (66)

	.  reduce 66


state 241
	assignment_operator : MUL_ASSIGN .  (67)

	.  reduce 67


state 242
	assignment_operator : DIV_ASSIGN .  (68)

	.  reduce 68


state 243
	assignment_operator : MOD_ASSIGN .  (69)

	.  reduce 69


state 244
	assignment_operator : ADD_ASSIGN .  (70)

	.  reduce 70


state 245
	assignment_operator : SUB_ASSIGN .  (71)

	.  reduce 71


state 246
	assignment_operator : LEFT_ASSIGN .  (72)

	.  reduce 72


state 247
	assignment_operator : RIGHT_ASSIGN .  (73)

	.  reduce 73


state 248
	assignment_operator : AND_ASSIGN .  (74)

	.  reduce 74


state 249
	assignment_operator : XOR_ASSIGN .  (75)

	.  reduce 75


state 250
	assignment_operator : OR_ASSIGN .  (76)

	.  reduce 76


state 251
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 317
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 252
	compound_statement : '{' statement_list '}' .  (196)

	.  reduce 196


state 253
	statement_list : statement_list M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 318
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 254
	compound_statement : '{' declaration_list '}' .  (197)

	.  reduce 197


state 255
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (58)

	'}'  shift 319
	.  reduce 58

	M  goto 253


state 256
	exp : exp ',' . assignment_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 320
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 257
	exp_statement : exp ';' .  (204)

	.  reduce 204


state 258
	declaration_list : declaration_list M declaration .  (200)

	.  reduce 200


state 259
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (111)

	.  reduce 111


state 260
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 321
	.  reduce 58

	M  goto 160


state 261
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'{'  shift 261
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	initializer  goto 322
	initializer_list  goto 323
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 263
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 262
	init_declarator : declarator '=' initializer .  (91)

	.  reduce 91


state 263
	initializer : assignment_exp .  (179)

	.  reduce 179


state 264
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (227)

	.  reduce 227


state 265
	init_declarator_list : init_declarator_list ',' init_declarator .  (89)

	.  reduce 89


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
	direct_abstract_declarator : '(' abstract_declarator ')' .  (170)

	.  reduce 170


state 270
	direct_abstract_declarator : '(' parameter_type_list ')' .  (176)

	.  reduce 176


state 271
	direct_abstract_declarator : '[' constant_exp ']' .  (172)

	.  reduce 172


state 272
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (177)

	.  reduce 177


state 273
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 324


state 274
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (173)

	.  reduce 173


state 275
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp . ']'

	']'  shift 325


state 276
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (124)

	.  reduce 124


state 277
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 326
	primary_exp  goto 114


state 278
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 278
	')'  shift 177
	'*'  shift 2
	'['  shift 88
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

	type_qualifier  goto 28
	struct_or_union_specifier  goto 30
	abstract_declarator  goto 178
	direct_abstract_declarator  goto 90
	parameter_list  goto 49
	enum_specifier  goto 31
	struct_or_union  goto 33
	pointer  goto 280
	parameter_type_list  goto 179
	parameter_declaration  goto 51
	declaration_specifiers  goto 52
	storage_class_specifier  goto 37
	struct_or_union_def  goto 38
	type_specifier  goto 39


state 279
	type_name : specifier_qualifier_list abstract_declarator .  (166)

	.  reduce 166


state 280
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (167)

	'('  shift 278
	'['  shift 88
	.  reduce 167

	direct_abstract_declarator  goto 184


state 281
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 282
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (122)

	.  reduce 122


state 283
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 327


state 284
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (11)

	.  reduce 11


state 285
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 328
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 286
	postfix_exp : postfix_exp '.' ID .  (12)

	.  reduce 12


state 287
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 256
	']'  shift 329


state 288
	postfix_exp : postfix_exp PTR_OP ID .  (13)

	.  reduce 13


state 289
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (35)

	.  reduce 35


state 290
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (33)

	.  reduce 33


state 291
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (34)

	.  reduce 34


state 292
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (37)
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 205
	'*'  shift 206
	'/'  shift 207
	.  reduce 37


state 293
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (38)

	'%'  shift 205
	'*'  shift 206
	'/'  shift 207
	.  reduce 38


state 294
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (40)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 208
	'-'  shift 209
	.  reduce 40


state 295
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (41)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 208
	'-'  shift 209
	.  reduce 41


state 296
	relational_exp : relational_exp '<' shift_exp .  (43)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 210
	RIGHT_OP  shift 211
	.  reduce 43


state 297
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp '>' shift_exp .  (44)

	LEFT_OP  shift 210
	RIGHT_OP  shift 211
	.  reduce 44


state 298
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (45)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 210
	RIGHT_OP  shift 211
	.  reduce 45


state 299
	relational_exp : relational_exp GE_OP shift_exp .  (46)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 210
	RIGHT_OP  shift 211
	.  reduce 46


state 300
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (48)
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 212
	'>'  shift 213
	LE_OP  shift 214
	GE_OP  shift 215
	.  reduce 48


state 301
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (49)
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 212
	'>'  shift 213
	LE_OP  shift 214
	GE_OP  shift 215
	.  reduce 49


state 302
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 256
	':'  shift 330


state 303
	logical_or_exp : logical_or_exp OR_OP M . logical_and_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	inclusive_or_exp  goto 121
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 331


state 304
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (55)

	'^'  shift 221
	.  reduce 55


state 305
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (53)

	'&'  shift 223
	.  reduce 53


state 306
	and_exp : and_exp '&' equality_exp .  (51)
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp

	EQ_OP  shift 216
	NE_OP  shift 217
	.  reduce 51


state 307
	logical_and_exp : logical_and_exp AND_OP M . inclusive_or_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	inclusive_or_exp  goto 332
	exclusive_or_exp  goto 122
	and_exp  goto 124


state 308
	labeled_statement : ID ':' statement .  (192)

	.  reduce 192


state 309
	labeled_statement : CASE constant_exp ':' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 333


state 310
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp . ')' M stmt
	open_statement : IF '(' exp . ')' M matched_statement N ELSE M open_statement

	')'  shift 334
	','  shift 256


state 311
	exp : exp . ',' assignment_exp
	switch_pre : SWITCH '(' exp . ')'

	')'  shift 335
	','  shift 256


state 312
	iteration_statement : WHILE M '(' . exp ')' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 336
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 313
	iteration_statement : DO M statement . WHILE M '(' exp ')' ';'

	WHILE  shift 337


state 314
	iteration_statement : FOR '(' exp_statement . M exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement . M exp_statement M exp ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 338


state 315
	jump_statement : GOTO ID ';' .  (218)

	.  reduce 218


state 316
	jump_statement : RETURN exp ';' .  (222)

	.  reduce 222


state 317
	assignment_exp : unary_exp assignment_operator assignment_exp .  (65)

	.  reduce 65


state 318
	statement_list : statement_list M statement .  (202)

	.  reduce 202


state 319
	compound_statement : '{' declaration_list statement_list '}' .  (198)

	.  reduce 198


state 320
	exp : exp ',' assignment_exp .  (78)

	.  reduce 78


state 321
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (110)

	.  reduce 110


state 322
	initializer_list : initializer .  (182)

	.  reduce 182


state 323
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'

	','  shift 339
	'}'  shift 340


state 324
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (178)

	.  reduce 178


state 325
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (174)

	.  reduce 174


state 326
	cast_exp : '(' type_name ')' cast_exp .  (31)

	.  reduce 31


state 327
	unary_exp : SIZEOF '(' type_name ')' .  (23)

	.  reduce 23


state 328
	argument_exp_list : argument_exp_list ',' assignment_exp .  (17)

	.  reduce 17


state 329
	postfix_exp : postfix_exp '[' exp ']' .  (9)

	.  reduce 9


state 330
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 341


state 331
	logical_or_exp : logical_or_exp OR_OP M logical_and_exp .  (61)
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp

	AND_OP  shift 224
	.  reduce 61


state 332
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : logical_and_exp AND_OP M inclusive_or_exp .  (57)

	'|'  shift 220
	.  reduce 57


state 333
	labeled_statement : CASE constant_exp ':' M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 342
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 334
	matched_statement : IF '(' exp ')' . M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' . M stmt
	open_statement : IF '(' exp ')' . M matched_statement N ELSE M open_statement
	M : .  (58)

	.  reduce 58

	M  goto 343


state 335
	switch_pre : SWITCH '(' exp ')' .  (213)

	.  reduce 213


state 336
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE M '(' exp . ')' M statement

	')'  shift 344
	','  shift 256


state 337
	iteration_statement : DO M statement WHILE . M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 345


state 338
	iteration_statement : FOR '(' exp_statement M . exp_statement ')' M statement
	iteration_statement : FOR '(' exp_statement M . exp_statement M exp ')' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp_statement  goto 346
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 339
	initializer_list : initializer_list ',' . initializer
	initializer : '{' initializer_list ',' . '}'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'{'  shift 261
	'}'  shift 347
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	initializer  goto 348
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 263
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 340
	initializer : '{' initializer_list '}' .  (180)

	.  reduce 180


state 341
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (63)

	.  reduce 63


state 342
	labeled_statement : CASE constant_exp ':' M statement .  (193)

	.  reduce 193


state 343
	matched_statement : IF '(' exp ')' M . matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' M . stmt
	open_statement : IF '(' exp ')' M . matched_statement N ELSE M open_statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	IF  shift 132
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	stmt  goto 349
	other  goto 350
	open_statement  goto 145
	matched_statement  goto 351
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 344
	iteration_statement : WHILE M '(' exp ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 352


state 345
	iteration_statement : DO M statement WHILE M . '(' exp ')' ';'

	'('  shift 353


state 346
	iteration_statement : FOR '(' exp_statement M exp_statement . ')' M statement
	iteration_statement : FOR '(' exp_statement M exp_statement . M exp ')' M statement
	M : .  (58)

	')'  shift 354
	.  reduce 58

	M  goto 355


state 347
	initializer : '{' initializer_list ',' '}' .  (181)

	.  reduce 181


state 348
	initializer_list : initializer_list ',' initializer .  (183)

	.  reduce 183


state 349
	open_statement : IF '(' exp ')' M stmt .  (209)

	.  reduce 209


state 350
	matched_statement : other .  (208)

	.  reduce 208


351: reduce-reduce conflict (reduce 59, reduce 205) on ELSE
state 351
	stmt : matched_statement .  (205)
	matched_statement : IF '(' exp ')' M matched_statement . N ELSE M matched_statement
	open_statement : IF '(' exp ')' M matched_statement . N ELSE M open_statement
	N : .  (59)

	ELSE  reduce 59
	.  reduce 205

	N  goto 356


state 352
	iteration_statement : WHILE M '(' exp ')' M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 357
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 353
	iteration_statement : DO M statement WHILE M '(' . exp ')' ';'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 358
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 354
	iteration_statement : FOR '(' exp_statement M exp_statement ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 359


state 355
	iteration_statement : FOR '(' exp_statement M exp_statement M . exp ')' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108

	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp  goto 360
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


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
	','  shift 256


state 359
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 363
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 360
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement M exp_statement M exp . ')' M statement

	')'  shift 364
	','  shift 256


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

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 101
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	IF  shift 132
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	other  goto 350
	open_statement  goto 368
	matched_statement  goto 369
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 366
	iteration_statement : DO M statement WHILE M '(' exp ')' ';' .  (215)

	.  reduce 215


state 367
	iteration_statement : FOR '(' exp_statement M exp_statement M exp ')' M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 127
	'{'  shift 57
	'~'  shift 100
	ID  shift 129
	CONSTANT  shift 102
	STRING_LITERAL  shift 103
	SIZEOF  shift 104
	INC_OP  shift 105
	DEC_OP  shift 106
	TRUE  shift 107
	FALSE  shift 108
	CASE  shift 130
	DEFAULT  shift 131
	IF  shift 132
	SWITCH  shift 133
	WHILE  shift 134
	DO  shift 135
	FOR  shift 136
	GOTO  shift 137
	CONTINUE  shift 138
	BREAK  shift 139
	RETURN  shift 140

	switch_pre  goto 141
	selection_statement  goto 142
	stmt  goto 143
	other  goto 144
	open_statement  goto 145
	matched_statement  goto 146
	postfix_pre_exp  goto 109
	postfix_exp  goto 110
	default_pre  goto 147
	unary_exp  goto 148
	unary_operator  goto 112
	cast_exp  goto 113
	primary_exp  goto 114
	multiplicative_exp  goto 115
	additive_exp  goto 116
	shift_exp  goto 117
	relational_exp  goto 118
	equality_exp  goto 119
	statement  goto 370
	exp_statement  goto 151
	iteration_statement  goto 152
	jump_statement  goto 153
	labeled_statement  goto 155
	compound_statement  goto 156
	exp  goto 157
	logical_or_exp  goto 120
	inclusive_or_exp  goto 121
	assignment_exp  goto 158
	exclusive_or_exp  goto 122
	and_exp  goto 124
	logical_and_exp  goto 125
	conditional_exp  goto 159


state 368
	open_statement : IF '(' exp ')' M matched_statement N ELSE M open_statement .  (210)

	.  reduce 210


state 369
	matched_statement : IF '(' exp ')' M matched_statement N ELSE M matched_statement .  (207)

	.  reduce 207


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
State 39 contains 1 shift-reduce conflict(s)
State 43 contains 3 shift-reduce conflict(s)
State 144 contains 30 reduce-reduce conflict(s)
State 189 contains 1 shift-reduce conflict(s)
State 351 contains 1 reduce-reduce conflict(s)


86 token(s), 76 nonterminal(s)
231 grammar rule(s), 371 state(s)


##############################################################################
# End of File
##############################################################################
