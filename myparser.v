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
# Date: 01/01/19
# Time: 11:12:28
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

	declaration_specifiers  goto 24
	struct_or_union  goto 25
	type_qualifier  goto 26
	declarator  goto 27
	direct_declarator  goto 28
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	declaration  goto 31
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	pointer  goto 35
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
	direct_declarator  goto 28
	pointer  goto 35
	direct_pre_declarator  goto 38


2: shift-reduce conflict (shift 2, reduce 150) on '*'
2: shift-reduce conflict (shift 18, reduce 150) on CONST
2: shift-reduce conflict (shift 19, reduce 150) on VOLATILE
state 2
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' .  (150)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 150

	type_qualifier  goto 41
	type_qualifier_list  goto 42
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
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . ID

	'{'  shift 44
	ID  shift 45


state 24
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 46
	ID  shift 3

	init_declarator_list  goto 47
	declarator  goto 48
	direct_declarator  goto 28
	init_declarator  goto 49
	pointer  goto 35
	direct_pre_declarator  goto 38


state 25
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'
	struct_or_union_def : struct_or_union . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID

	'{'  shift 50
	ID  shift 51


state 26
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

	declaration_specifiers  goto 52
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34


state 27
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

	declaration_specifiers  goto 54
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	declaration  goto 55
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	compound_statement  goto 56
	declaration_list  goto 57


state 28
	direct_declarator : direct_declarator . '[' ']'
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'
	declarator : direct_declarator .  (141)

	'('  shift 58
	'['  shift 59
	.  reduce 141


state 29
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 60
	ID  shift 3

	init_declarator_list  goto 61
	declarator  goto 62
	direct_declarator  goto 28
	def_concat  goto 63
	init_declarator  goto 49
	pointer  goto 35
	direct_pre_declarator  goto 38


state 30
	type_specifier : struct_or_union_specifier .  (106)

	.  reduce 106


state 31
	external_declaration : declaration .  (226)

	.  reduce 226


state 32
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

	declaration_specifiers  goto 64
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34


33: shift-reduce conflict (shift 2, reduce 84) on '*'
state 33
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

	declaration_specifiers  goto 65
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	pointer  goto 66


state 34
	type_specifier : enum_specifier .  (107)

	.  reduce 107


state 35
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 67
	direct_pre_declarator  goto 38


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

	declaration_specifiers  goto 24
	struct_or_union  goto 25
	type_qualifier  goto 26
	declarator  goto 27
	direct_declarator  goto 28
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	declaration  goto 31
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	pointer  goto 35
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

	declaration_specifiers  goto 71
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	parameter_list  goto 72
	identifier_list  goto 73
	parameter_declaration  goto 74
	parameter_type_list  goto 75


state 39
	translation_unit : external_declaration .  (223)

	.  reduce 223


state 40
	direct_declarator : '(' declarator . ')'

	')'  shift 76


state 41
	type_qualifier_list : type_qualifier .  (154)

	.  reduce 154


42: shift-reduce conflict (shift 2, reduce 151) on '*'
42: shift-reduce conflict (shift 18, reduce 151) on CONST
42: shift-reduce conflict (shift 19, reduce 151) on VOLATILE
state 42
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list .  (151)
	pointer : '*' type_qualifier_list . pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 151

	type_qualifier  goto 77
	pointer  goto 78


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
	declaration : declaration_specifiers ';' .  (80)

	.  reduce 80


state 47
	init_declarator_list : init_declarator_list . ',' init_declarator
	declaration : declaration_specifiers init_declarator_list . ';'

	','  shift 83
	';'  shift 84


state 48
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 85
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
	.  reduce 90

	declaration_specifiers  goto 54
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	declaration  goto 55
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	compound_statement  goto 86
	declaration_list  goto 87


state 49
	init_declarator_list : init_declarator .  (88)

	.  reduce 88


state 50
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

	declaration_specifiers  goto 54
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	declaration  goto 55
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	declaration_list  goto 88


state 51
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union ID .  (115)

	'{'  shift 89
	.  reduce 115


state 52
	declaration_specifiers : type_qualifier declaration_specifiers .  (87)

	.  reduce 87


state 53
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list statement_list '}'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'}'  shift 97
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TYPE_NAME  shift 4
	TRUE  shift 105
	FALSE  shift 106
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
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	declaration_specifiers  goto 54
	struct_or_union  goto 25
	type_qualifier  goto 26
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	struct_or_union_def  goto 29
	logical_or_exp  goto 132
	struct_or_union_specifier  goto 30
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	declaration  goto 55
	and_exp  goto 136
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	statement_list  goto 137
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 141
	compound_statement  goto 142
	declaration_list  goto 143
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 54
	declaration : declaration_specifiers . ';'
	declaration : declaration_specifiers . init_declarator_list ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 46
	ID  shift 3

	init_declarator_list  goto 47
	declarator  goto 62
	direct_declarator  goto 28
	init_declarator  goto 49
	pointer  goto 35
	direct_pre_declarator  goto 38


state 55
	declaration_list : declaration .  (199)

	.  reduce 199


state 56
	function_definition : declarator compound_statement .  (230)

	.  reduce 230


state 57
	declaration_list : declaration_list . M declaration
	function_definition : declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 53
	.  reduce 58

	compound_statement  goto 152
	M  goto 153


state 58
	direct_pre_declarator : direct_declarator '(' .  (142)

	.  reduce 142


state 59
	direct_declarator : direct_declarator '[' . ']'
	direct_declarator : direct_declarator '[' . constant_exp ']'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	']'  shift 154
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 157
	and_exp  goto 136
	constant_exp  goto 158
	postfix_pre_exp  goto 151


state 60
	def_concat : ';' .  (112)

	.  reduce 112


state 61
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 83
	';'  shift 159


state 62
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)

	'='  shift 85
	.  reduce 90


state 63
	struct_or_union_specifier : struct_or_union_def def_concat .  (114)

	.  reduce 114


state 64
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (83)

	.  reduce 83


state 65
	declaration_specifiers : type_specifier declaration_specifiers .  (85)

	.  reduce 85


state 66
	type_specifier : type_specifier pointer .  (109)

	.  reduce 109


state 67
	direct_declarator : direct_declarator . '[' ']'
	declarator : pointer direct_declarator .  (140)
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'

	'('  shift 58
	'['  shift 59
	.  reduce 140


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
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (162)

	'('  shift 160
	'*'  shift 2
	'['  shift 161
	ID  shift 3
	.  reduce 162

	declarator  goto 162
	direct_declarator  goto 28
	abstract_declarator  goto 163
	direct_abstract_declarator  goto 164
	pointer  goto 165
	direct_pre_declarator  goto 38


state 72
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_type_list : parameter_list .  (156)
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 166
	.  reduce 156


state 73
	identifier_list : identifier_list . ',' ID
	direct_declarator : direct_pre_declarator identifier_list . ')'

	')'  shift 167
	','  shift 168


state 74
	parameter_list : parameter_declaration .  (158)

	.  reduce 158


state 75
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 169


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
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

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
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 62
	direct_declarator  goto 28
	init_declarator  goto 174
	pointer  goto 35
	direct_pre_declarator  goto 38


state 84
	declaration : declaration_specifiers init_declarator_list ';' .  (81)

	.  reduce 81


state 85
	init_declarator : declarator '=' . initializer

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'{'  shift 175
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 176
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	initializer  goto 177
	postfix_pre_exp  goto 151


state 86
	function_definition : declaration_specifiers declarator compound_statement .  (228)

	.  reduce 228


state 87
	declaration_list : declaration_list . M declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 53
	.  reduce 58

	compound_statement  goto 178
	M  goto 153


state 88
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 179
	.  reduce 58

	M  goto 153


state 89
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

	declaration_specifiers  goto 54
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	declaration  goto 55
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	declaration_list  goto 180


state 90
	unary_operator : '!' .  (29)

	.  reduce 29


state 91
	unary_operator : '&' .  (24)

	.  reduce 24


state 92
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TYPE_NAME  shift 4
	TRUE  shift 105
	FALSE  shift 106
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

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	struct_or_union  goto 25
	type_qualifier  goto 181
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 182
	logical_and_exp  goto 131
	struct_or_union_def  goto 29
	logical_or_exp  goto 132
	struct_or_union_specifier  goto 30
	specifier_qualifier_list  goto 183
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	type_specifier  goto 184
	enum_specifier  goto 34
	type_name  goto 185
	postfix_pre_exp  goto 151


state 93
	unary_operator : '*' .  (25)

	.  reduce 25


state 94
	unary_operator : '+' .  (26)

	.  reduce 26


state 95
	unary_operator : '-' .  (27)

	.  reduce 27


state 96
	exp_statement : ';' .  (203)

	.  reduce 203


state 97
	compound_statement : '{' '}' .  (195)

	.  reduce 195


state 98
	unary_operator : '~' .  (28)

	.  reduce 28


state 99
	primary_exp : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 186
	.  reduce 1


state 100
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 101
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 102
	unary_exp : SIZEOF . '(' type_name ')'
	unary_exp : SIZEOF . unary_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 187
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 188
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 103
	unary_exp : INC_OP . unary_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 189
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 190
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 104
	unary_exp : DEC_OP . unary_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 189
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 191
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 105
	primary_exp : TRUE .  (5)

	.  reduce 5


state 106
	primary_exp : FALSE .  (6)

	.  reduce 6


state 107
	labeled_statement : CASE . constant_exp ':' M statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 157
	and_exp  goto 136
	constant_exp  goto 192
	postfix_pre_exp  goto 151


state 108
	default_pre : DEFAULT . ':'

	':'  shift 193


state 109
	matched_statement : IF . '(' exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF . '(' exp ')' M matched_statement N ELSE M open_statement
	open_statement : IF . '(' exp ')' M stmt

	'('  shift 194


state 110
	switch_pre : SWITCH . '(' exp ')'

	'('  shift 195


state 111
	iteration_statement : WHILE . M '(' exp ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 196


state 112
	iteration_statement : DO . M statement WHILE M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 197


state 113
	iteration_statement : FOR . '(' exp_statement M exp_statement M exp ')' M statement
	iteration_statement : FOR . '(' exp_statement M exp_statement ')' M statement

	'('  shift 198


state 114
	jump_statement : GOTO . ID ';'

	ID  shift 199


state 115
	jump_statement : CONTINUE . ';'

	';'  shift 200


state 116
	jump_statement : BREAK . ';'

	';'  shift 201


state 117
	jump_statement : RETURN . exp ';'
	jump_statement : RETURN . ';'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 202
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 203
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 118
	postfix_exp : primary_exp .  (8)

	.  reduce 8


state 119
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . INC_OP
	unary_exp : postfix_exp .  (18)
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . DEC_OP

	'('  shift 204
	'.'  shift 205
	'['  shift 206
	PTR_OP  shift 207
	INC_OP  shift 208
	DEC_OP  shift 209
	.  reduce 18


state 120
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : multiplicative_exp .  (36)
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 210
	'*'  shift 211
	'/'  shift 212
	.  reduce 36


state 121
	cast_exp : unary_exp .  (30)
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
	.  reduce 30

	assignment_operator  goto 224


state 122
	shift_exp : additive_exp .  (39)
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp

	'+'  shift 225
	'-'  shift 226
	.  reduce 39


state 123
	relational_exp : shift_exp .  (42)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 227
	RIGHT_OP  shift 228
	.  reduce 42


state 124
	multiplicative_exp : cast_exp .  (32)

	.  reduce 32


state 125
	equality_exp : relational_exp .  (47)
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 229
	'>'  shift 230
	LE_OP  shift 231
	GE_OP  shift 232
	.  reduce 47


state 126
	labeled_statement : default_pre . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 233
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 127
	unary_exp : unary_operator . cast_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 156
	cast_exp  goto 234
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 128
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : equality_exp .  (50)
	equality_exp : equality_exp . NE_OP relational_exp

	EQ_OP  shift 235
	NE_OP  shift 236
	.  reduce 50


state 129
	exp : assignment_exp .  (77)

	.  reduce 77


state 130
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 237
	';'  shift 238


state 131
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_and_exp .  (60)

	AND_OP  shift 239
	.  reduce 60


state 132
	logical_or_exp : logical_or_exp . OR_OP M logical_and_exp
	conditional_exp : logical_or_exp .  (62)
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp

	'?'  shift 240
	OR_OP  shift 241
	.  reduce 62


state 133
	logical_and_exp : inclusive_or_exp .  (56)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 242
	.  reduce 56


state 134
	inclusive_or_exp : exclusive_or_exp .  (54)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 243
	.  reduce 54


state 135
	assignment_exp : conditional_exp .  (64)

	.  reduce 64


state 136
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : and_exp .  (52)

	'&'  shift 244
	.  reduce 52


state 137
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (58)

	'}'  shift 245
	.  reduce 58

	M  goto 246


state 138
	other : iteration_statement .  (186)

	.  reduce 186


state 139
	statement : labeled_statement .  (188)

	.  reduce 188


state 140
	other : exp_statement .  (185)

	.  reduce 185


state 141
	statement_list : statement .  (201)

	.  reduce 201


state 142
	other : compound_statement .  (184)

	.  reduce 184


state 143
	compound_statement : '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	compound_statement : '{' declaration_list . statement_list '}'
	M : .  (58)

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'}'  shift 247
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117
	.  reduce 58

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	statement_list  goto 248
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 141
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	M  goto 153
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 144
	selection_statement : switch_pre . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 249
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


145: reduce-reduce conflict (reduce 189, reduce 208) on '!'
145: reduce-reduce conflict (reduce 189, reduce 208) on '&'
145: reduce-reduce conflict (reduce 189, reduce 208) on '('
145: reduce-reduce conflict (reduce 189, reduce 208) on '*'
145: reduce-reduce conflict (reduce 189, reduce 208) on '+'
145: reduce-reduce conflict (reduce 189, reduce 208) on '-'
145: reduce-reduce conflict (reduce 189, reduce 208) on ';'
145: reduce-reduce conflict (reduce 189, reduce 208) on '{'
145: reduce-reduce conflict (reduce 189, reduce 208) on '}'
145: reduce-reduce conflict (reduce 189, reduce 208) on '~'
145: reduce-reduce conflict (reduce 189, reduce 208) on ID
145: reduce-reduce conflict (reduce 189, reduce 208) on CONSTANT
145: reduce-reduce conflict (reduce 189, reduce 208) on STRING_LITERAL
145: reduce-reduce conflict (reduce 189, reduce 208) on SIZEOF
145: reduce-reduce conflict (reduce 189, reduce 208) on INC_OP
145: reduce-reduce conflict (reduce 189, reduce 208) on DEC_OP
145: reduce-reduce conflict (reduce 189, reduce 208) on TRUE
145: reduce-reduce conflict (reduce 189, reduce 208) on FALSE
145: reduce-reduce conflict (reduce 189, reduce 208) on CASE
145: reduce-reduce conflict (reduce 189, reduce 208) on DEFAULT
145: reduce-reduce conflict (reduce 189, reduce 208) on IF
145: reduce-reduce conflict (reduce 189, reduce 208) on ELSE
145: reduce-reduce conflict (reduce 189, reduce 208) on SWITCH
145: reduce-reduce conflict (reduce 189, reduce 208) on WHILE
145: reduce-reduce conflict (reduce 189, reduce 208) on DO
145: reduce-reduce conflict (reduce 189, reduce 208) on FOR
145: reduce-reduce conflict (reduce 189, reduce 208) on GOTO
145: reduce-reduce conflict (reduce 189, reduce 208) on CONTINUE
145: reduce-reduce conflict (reduce 189, reduce 208) on BREAK
145: reduce-reduce conflict (reduce 189, reduce 208) on RETURN
state 145
	statement : other .  (189)
	matched_statement : other .  (208)

	.  reduce 189


state 146
	stmt : open_statement .  (206)

	.  reduce 206


state 147
	statement : selection_statement .  (190)

	.  reduce 190


state 148
	stmt : matched_statement .  (205)

	.  reduce 205


state 149
	other : jump_statement .  (187)

	.  reduce 187


state 150
	selection_statement : stmt .  (211)

	.  reduce 211


state 151
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	')'  shift 250
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	argument_exp_list  goto 251
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 252
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 152
	function_definition : declarator declaration_list compound_statement .  (229)

	.  reduce 229


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

	declaration_specifiers  goto 54
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	declaration  goto 253
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34


state 154
	direct_declarator : direct_declarator '[' ']' .  (146)

	.  reduce 146


state 155
	primary_exp : ID .  (1)

	.  reduce 1


state 156
	cast_exp : unary_exp .  (30)

	.  reduce 30


state 157
	constant_exp : conditional_exp .  (79)

	.  reduce 79


state 158
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 254


state 159
	def_concat : init_declarator_list ';' .  (113)

	.  reduce 113


state 160
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 160
	')'  shift 255
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

	declaration_specifiers  goto 71
	struct_or_union  goto 25
	type_qualifier  goto 26
	declarator  goto 40
	direct_declarator  goto 28
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	abstract_declarator  goto 256
	parameter_list  goto 72
	parameter_declaration  goto 74
	parameter_type_list  goto 257
	direct_abstract_declarator  goto 164
	pointer  goto 165
	direct_pre_declarator  goto 38


state 161
	direct_abstract_declarator : '[' . constant_exp ']'
	direct_abstract_declarator : '[' . ']'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	']'  shift 258
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 157
	and_exp  goto 136
	constant_exp  goto 259
	postfix_pre_exp  goto 151


state 162
	parameter_declaration : declaration_specifiers declarator .  (160)

	.  reduce 160


state 163
	parameter_declaration : declaration_specifiers abstract_declarator .  (161)

	.  reduce 161


state 164
	abstract_declarator : direct_abstract_declarator .  (168)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'

	'('  shift 260
	'['  shift 261
	.  reduce 168


state 165
	declarator : pointer . direct_declarator
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (167)

	'('  shift 160
	'['  shift 161
	ID  shift 3
	.  reduce 167

	direct_declarator  goto 67
	direct_abstract_declarator  goto 262
	direct_pre_declarator  goto 38


state 166
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
	ELLIPSIS  shift 263

	declaration_specifiers  goto 71
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	parameter_declaration  goto 264


state 167
	direct_declarator : direct_pre_declarator identifier_list ')' .  (148)

	.  reduce 148


state 168
	identifier_list : identifier_list ',' . ID

	ID  shift 265


state 169
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (147)

	.  reduce 147


state 170
	enumerator : ID '=' . constant_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 157
	and_exp  goto 136
	constant_exp  goto 266
	postfix_pre_exp  goto 151


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
	init_declarator_list : init_declarator_list ',' init_declarator .  (89)

	.  reduce 89


state 175
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'{'  shift 175
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 176
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	initializer  goto 269
	initializer_list  goto 270
	postfix_pre_exp  goto 151


state 176
	initializer : assignment_exp .  (179)

	.  reduce 179


state 177
	init_declarator : declarator '=' initializer .  (91)

	.  reduce 91


state 178
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (227)

	.  reduce 227


state 179
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (111)

	.  reduce 111


state 180
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 271
	.  reduce 58

	M  goto 153


state 181
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

	struct_or_union  goto 25
	type_qualifier  goto 181
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	specifier_qualifier_list  goto 272
	type_specifier  goto 184
	enum_specifier  goto 34


state 182
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 273
	','  shift 237


state 183
	type_name : specifier_qualifier_list .  (165)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 274
	'*'  shift 2
	'['  shift 161
	.  reduce 165

	abstract_declarator  goto 275
	direct_abstract_declarator  goto 164
	pointer  goto 276


184: shift-reduce conflict (shift 2, reduce 123) on '*'
state 184
	type_specifier : type_specifier . pointer
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	specifier_qualifier_list : type_specifier .  (123)

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

	struct_or_union  goto 25
	type_qualifier  goto 181
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	specifier_qualifier_list  goto 277
	type_specifier  goto 184
	enum_specifier  goto 34
	pointer  goto 66


state 185
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 278


state 186
	labeled_statement : ID ':' . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 279
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 187
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TYPE_NAME  shift 4
	TRUE  shift 105
	FALSE  shift 106
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

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	struct_or_union  goto 25
	type_qualifier  goto 181
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 182
	logical_and_exp  goto 131
	struct_or_union_def  goto 29
	logical_or_exp  goto 132
	struct_or_union_specifier  goto 30
	specifier_qualifier_list  goto 183
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	type_specifier  goto 184
	enum_specifier  goto 34
	type_name  goto 280
	postfix_pre_exp  goto 151


state 188
	unary_exp : SIZEOF unary_exp .  (22)

	.  reduce 22


state 189
	primary_exp : '(' . exp ')'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 182
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 190
	unary_exp : INC_OP unary_exp .  (19)

	.  reduce 19


state 191
	unary_exp : DEC_OP unary_exp .  (20)

	.  reduce 20


state 192
	labeled_statement : CASE constant_exp . ':' M statement

	':'  shift 281


state 193
	default_pre : DEFAULT ':' .  (191)

	.  reduce 191


state 194
	matched_statement : IF '(' . exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' . exp ')' M matched_statement N ELSE M open_statement
	open_statement : IF '(' . exp ')' M stmt

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 282
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 195
	switch_pre : SWITCH '(' . exp ')'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 283
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 196
	iteration_statement : WHILE M . '(' exp ')' M statement

	'('  shift 284


state 197
	iteration_statement : DO M . statement WHILE M '(' exp ')' ';'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 285
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 198
	iteration_statement : FOR '(' . exp_statement M exp_statement M exp ')' M statement
	iteration_statement : FOR '(' . exp_statement M exp_statement ')' M statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	exp_statement  goto 286
	postfix_pre_exp  goto 151


state 199
	jump_statement : GOTO ID . ';'

	';'  shift 287


state 200
	jump_statement : CONTINUE ';' .  (219)

	.  reduce 219


state 201
	jump_statement : BREAK ';' .  (220)

	.  reduce 220


state 202
	jump_statement : RETURN ';' .  (221)

	.  reduce 221


state 203
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 237
	';'  shift 288


state 204
	postfix_pre_exp : postfix_exp '(' .  (7)

	.  reduce 7


state 205
	postfix_exp : postfix_exp '.' . ID

	ID  shift 289


state 206
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 290
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 207
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 291


state 208
	postfix_exp : postfix_exp INC_OP .  (14)

	.  reduce 14


state 209
	postfix_exp : postfix_exp DEC_OP .  (15)

	.  reduce 15


state 210
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 156
	cast_exp  goto 292
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 211
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 156
	cast_exp  goto 293
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 212
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 156
	cast_exp  goto 294
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 213
	assignment_operator : '=' .  (66)

	.  reduce 66


state 214
	assignment_operator : MUL_ASSIGN .  (67)

	.  reduce 67


state 215
	assignment_operator : DIV_ASSIGN .  (68)

	.  reduce 68


state 216
	assignment_operator : MOD_ASSIGN .  (69)

	.  reduce 69


state 217
	assignment_operator : ADD_ASSIGN .  (70)

	.  reduce 70


state 218
	assignment_operator : SUB_ASSIGN .  (71)

	.  reduce 71


state 219
	assignment_operator : LEFT_ASSIGN .  (72)

	.  reduce 72


state 220
	assignment_operator : RIGHT_ASSIGN .  (73)

	.  reduce 73


state 221
	assignment_operator : AND_ASSIGN .  (74)

	.  reduce 74


state 222
	assignment_operator : XOR_ASSIGN .  (75)

	.  reduce 75


state 223
	assignment_operator : OR_ASSIGN .  (76)

	.  reduce 76


state 224
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 295
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 225
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 296
	unary_exp  goto 156
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 226
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 297
	unary_exp  goto 156
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 227
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 298
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 228
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 299
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 229
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 300
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 230
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 301
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 231
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 302
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 232
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 303
	cast_exp  goto 124
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 233
	labeled_statement : default_pre statement .  (194)

	.  reduce 194


state 234
	unary_exp : unary_operator cast_exp .  (21)

	.  reduce 21


state 235
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 304
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 236
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 305
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 237
	exp : exp ',' . assignment_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 306
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 238
	exp_statement : exp ';' .  (204)

	.  reduce 204


state 239
	logical_and_exp : logical_and_exp AND_OP . M inclusive_or_exp
	M : .  (58)

	.  reduce 58

	M  goto 307


state 240
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 308
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 241
	logical_or_exp : logical_or_exp OR_OP . M logical_and_exp
	M : .  (58)

	.  reduce 58

	M  goto 309


state 242
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	exclusive_or_exp  goto 310
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 243
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	and_exp  goto 311
	postfix_pre_exp  goto 151


state 244
	and_exp : and_exp '&' . equality_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 312
	postfix_pre_exp  goto 151


state 245
	compound_statement : '{' statement_list '}' .  (196)

	.  reduce 196


state 246
	statement_list : statement_list M . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 313
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 247
	compound_statement : '{' declaration_list '}' .  (197)

	.  reduce 197


state 248
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (58)

	'}'  shift 314
	.  reduce 58

	M  goto 246


state 249
	selection_statement : switch_pre statement .  (212)

	.  reduce 212


state 250
	postfix_exp : postfix_pre_exp ')' .  (10)

	.  reduce 10


state 251
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 315
	','  shift 316


state 252
	argument_exp_list : assignment_exp .  (16)

	.  reduce 16


state 253
	declaration_list : declaration_list M declaration .  (200)

	.  reduce 200


state 254
	direct_declarator : direct_declarator '[' constant_exp ']' .  (145)

	.  reduce 145


state 255
	direct_abstract_declarator : '(' ')' .  (175)

	.  reduce 175


state 256
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 317


state 257
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 318


state 258
	direct_abstract_declarator : '[' ']' .  (171)

	.  reduce 171


state 259
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 319


state 260
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

	declaration_specifiers  goto 71
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	parameter_list  goto 72
	parameter_declaration  goto 74
	parameter_type_list  goto 321


state 261
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	']'  shift 322
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 157
	and_exp  goto 136
	constant_exp  goto 323
	postfix_pre_exp  goto 151


state 262
	abstract_declarator : pointer direct_abstract_declarator .  (169)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'

	'('  shift 260
	'['  shift 261
	.  reduce 169


state 263
	parameter_type_list : parameter_list ',' ELLIPSIS .  (157)

	.  reduce 157


state 264
	parameter_list : parameter_list ',' parameter_declaration .  (159)

	.  reduce 159


state 265
	identifier_list : identifier_list ',' ID .  (164)

	.  reduce 164


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
	initializer_list : initializer .  (182)

	.  reduce 182


state 270
	initializer : '{' initializer_list . '}'
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer

	','  shift 324
	'}'  shift 325


state 271
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (110)

	.  reduce 110


state 272
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (124)

	.  reduce 124


state 273
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 274
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 274
	')'  shift 255
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

	declaration_specifiers  goto 71
	struct_or_union  goto 25
	type_qualifier  goto 26
	struct_or_union_def  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 32
	type_specifier  goto 33
	enum_specifier  goto 34
	abstract_declarator  goto 256
	parameter_list  goto 72
	parameter_declaration  goto 74
	parameter_type_list  goto 257
	direct_abstract_declarator  goto 164
	pointer  goto 276


state 275
	type_name : specifier_qualifier_list abstract_declarator .  (166)

	.  reduce 166


state 276
	abstract_declarator : pointer . direct_abstract_declarator
	abstract_declarator : pointer .  (167)

	'('  shift 274
	'['  shift 161
	.  reduce 167

	direct_abstract_declarator  goto 262


state 277
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (122)

	.  reduce 122


state 278
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 156
	cast_exp  goto 326
	unary_operator  goto 127
	postfix_pre_exp  goto 151


state 279
	labeled_statement : ID ':' statement .  (192)

	.  reduce 192


state 280
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 327


state 281
	labeled_statement : CASE constant_exp ':' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 328


state 282
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp . ')' M matched_statement N ELSE M open_statement
	open_statement : IF '(' exp . ')' M stmt

	')'  shift 329
	','  shift 237


state 283
	exp : exp . ',' assignment_exp
	switch_pre : SWITCH '(' exp . ')'

	')'  shift 330
	','  shift 237


state 284
	iteration_statement : WHILE M '(' . exp ')' M statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 331
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 285
	iteration_statement : DO M statement . WHILE M '(' exp ')' ';'

	WHILE  shift 332


state 286
	iteration_statement : FOR '(' exp_statement . M exp_statement M exp ')' M statement
	iteration_statement : FOR '(' exp_statement . M exp_statement ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 333


state 287
	jump_statement : GOTO ID ';' .  (218)

	.  reduce 218


state 288
	jump_statement : RETURN exp ';' .  (222)

	.  reduce 222


state 289
	postfix_exp : postfix_exp '.' ID .  (12)

	.  reduce 12


state 290
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 237
	']'  shift 334


state 291
	postfix_exp : postfix_exp PTR_OP ID .  (13)

	.  reduce 13


state 292
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (35)

	.  reduce 35


state 293
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (33)

	.  reduce 33


state 294
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (34)

	.  reduce 34


state 295
	assignment_exp : unary_exp assignment_operator assignment_exp .  (65)

	.  reduce 65


state 296
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (37)
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 210
	'*'  shift 211
	'/'  shift 212
	.  reduce 37


state 297
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (38)
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp

	'%'  shift 210
	'*'  shift 211
	'/'  shift 212
	.  reduce 38


state 298
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (40)

	'+'  shift 225
	'-'  shift 226
	.  reduce 40


state 299
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (41)

	'+'  shift 225
	'-'  shift 226
	.  reduce 41


state 300
	relational_exp : relational_exp '<' shift_exp .  (43)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 227
	RIGHT_OP  shift 228
	.  reduce 43


state 301
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '>' shift_exp .  (44)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 227
	RIGHT_OP  shift 228
	.  reduce 44


state 302
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (45)

	LEFT_OP  shift 227
	RIGHT_OP  shift 228
	.  reduce 45


state 303
	relational_exp : relational_exp GE_OP shift_exp .  (46)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 227
	RIGHT_OP  shift 228
	.  reduce 46


state 304
	equality_exp : equality_exp EQ_OP relational_exp .  (48)
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 229
	'>'  shift 230
	LE_OP  shift 231
	GE_OP  shift 232
	.  reduce 48


state 305
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (49)

	'<'  shift 229
	'>'  shift 230
	LE_OP  shift 231
	GE_OP  shift 232
	.  reduce 49


state 306
	exp : exp ',' assignment_exp .  (78)

	.  reduce 78


state 307
	logical_and_exp : logical_and_exp AND_OP M . inclusive_or_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	inclusive_or_exp  goto 335
	exclusive_or_exp  goto 134
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 308
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 237
	':'  shift 336


state 309
	logical_or_exp : logical_or_exp OR_OP M . logical_and_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	logical_and_exp  goto 337
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 310
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (55)

	'^'  shift 243
	.  reduce 55


state 311
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (53)

	'&'  shift 244
	.  reduce 53


state 312
	equality_exp : equality_exp . EQ_OP relational_exp
	equality_exp : equality_exp . NE_OP relational_exp
	and_exp : and_exp '&' equality_exp .  (51)

	EQ_OP  shift 235
	NE_OP  shift 236
	.  reduce 51


state 313
	statement_list : statement_list M statement .  (202)

	.  reduce 202


state 314
	compound_statement : '{' declaration_list statement_list '}' .  (198)

	.  reduce 198


state 315
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (11)

	.  reduce 11


state 316
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 338
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


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
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'{'  shift 175
	'}'  shift 341
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 176
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	initializer  goto 342
	postfix_pre_exp  goto 151


state 325
	initializer : '{' initializer_list '}' .  (180)

	.  reduce 180


state 326
	cast_exp : '(' type_name ')' cast_exp .  (31)

	.  reduce 31


state 327
	unary_exp : SIZEOF '(' type_name ')' .  (23)

	.  reduce 23


state 328
	labeled_statement : CASE constant_exp ':' M . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 343
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 329
	matched_statement : IF '(' exp ')' . M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' . M matched_statement N ELSE M open_statement
	open_statement : IF '(' exp ')' . M stmt
	M : .  (58)

	.  reduce 58

	M  goto 344


state 330
	switch_pre : SWITCH '(' exp ')' .  (213)

	.  reduce 213


state 331
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE M '(' exp . ')' M statement

	')'  shift 345
	','  shift 237


state 332
	iteration_statement : DO M statement WHILE . M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 346


state 333
	iteration_statement : FOR '(' exp_statement M . exp_statement M exp ')' M statement
	iteration_statement : FOR '(' exp_statement M . exp_statement ')' M statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	exp_statement  goto 347
	postfix_pre_exp  goto 151


state 334
	postfix_exp : postfix_exp '[' exp ']' .  (9)

	.  reduce 9


state 335
	logical_and_exp : logical_and_exp AND_OP M inclusive_or_exp .  (57)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 242
	.  reduce 57


state 336
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 156
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 348
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 337
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_or_exp OR_OP M logical_and_exp .  (61)

	AND_OP  shift 239
	.  reduce 61


state 338
	argument_exp_list : argument_exp_list ',' assignment_exp .  (17)

	.  reduce 17


state 339
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (178)

	.  reduce 178


state 340
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (174)

	.  reduce 174


state 341
	initializer : '{' initializer_list ',' '}' .  (181)

	.  reduce 181


state 342
	initializer_list : initializer_list ',' initializer .  (183)

	.  reduce 183


state 343
	labeled_statement : CASE constant_exp ':' M statement .  (193)

	.  reduce 193


state 344
	matched_statement : IF '(' exp ')' M . matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' M . matched_statement N ELSE M open_statement
	open_statement : IF '(' exp ')' M . stmt

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	IF  shift 109
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	exp_statement  goto 140
	compound_statement  goto 142
	other  goto 349
	open_statement  goto 146
	matched_statement  goto 350
	jump_statement  goto 149
	stmt  goto 351
	postfix_pre_exp  goto 151


state 345
	iteration_statement : WHILE M '(' exp ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 352


state 346
	iteration_statement : DO M statement WHILE M . '(' exp ')' ';'

	'('  shift 353


state 347
	iteration_statement : FOR '(' exp_statement M exp_statement . M exp ')' M statement
	iteration_statement : FOR '(' exp_statement M exp_statement . ')' M statement
	M : .  (58)

	')'  shift 354
	.  reduce 58

	M  goto 355


state 348
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (63)

	.  reduce 63


state 349
	matched_statement : other .  (208)

	.  reduce 208


350: reduce-reduce conflict (reduce 59, reduce 205) on ELSE
state 350
	stmt : matched_statement .  (205)
	matched_statement : IF '(' exp ')' M matched_statement . N ELSE M matched_statement
	open_statement : IF '(' exp ')' M matched_statement . N ELSE M open_statement
	N : .  (59)

	ELSE  reduce 59
	.  reduce 205

	N  goto 356


state 351
	open_statement : IF '(' exp ')' M stmt .  (209)

	.  reduce 209


state 352
	iteration_statement : WHILE M '(' exp ')' M . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 357
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 353
	iteration_statement : DO M statement WHILE M '(' . exp ')' ';'

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 358
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


state 354
	iteration_statement : FOR '(' exp_statement M exp_statement ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 359


state 355
	iteration_statement : FOR '(' exp_statement M exp_statement M . exp ')' M statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 360
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	postfix_pre_exp  goto 151


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
	','  shift 237


state 359
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 363
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


state 360
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement M exp_statement M exp . ')' M statement

	')'  shift 364
	','  shift 237


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

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 155
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	IF  shift 109
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	exp_statement  goto 140
	compound_statement  goto 142
	other  goto 349
	open_statement  goto 368
	matched_statement  goto 369
	jump_statement  goto 149
	postfix_pre_exp  goto 151


state 366
	iteration_statement : DO M statement WHILE M '(' exp ')' ';' .  (215)

	.  reduce 215


state 367
	iteration_statement : FOR '(' exp_statement M exp_statement M exp ')' M . statement

	'!'  shift 90
	'&'  shift 91
	'('  shift 92
	'*'  shift 93
	'+'  shift 94
	'-'  shift 95
	';'  shift 96
	'{'  shift 53
	'~'  shift 98
	ID  shift 99
	CONSTANT  shift 100
	STRING_LITERAL  shift 101
	SIZEOF  shift 102
	INC_OP  shift 103
	DEC_OP  shift 104
	TRUE  shift 105
	FALSE  shift 106
	CASE  shift 107
	DEFAULT  shift 108
	IF  shift 109
	SWITCH  shift 110
	WHILE  shift 111
	DO  shift 112
	FOR  shift 113
	GOTO  shift 114
	CONTINUE  shift 115
	BREAK  shift 116
	RETURN  shift 117

	primary_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	unary_exp  goto 121
	additive_exp  goto 122
	shift_exp  goto 123
	cast_exp  goto 124
	relational_exp  goto 125
	default_pre  goto 126
	unary_operator  goto 127
	equality_exp  goto 128
	assignment_exp  goto 129
	exp  goto 130
	logical_and_exp  goto 131
	logical_or_exp  goto 132
	inclusive_or_exp  goto 133
	exclusive_or_exp  goto 134
	conditional_exp  goto 135
	and_exp  goto 136
	iteration_statement  goto 138
	labeled_statement  goto 139
	exp_statement  goto 140
	statement  goto 370
	compound_statement  goto 142
	switch_pre  goto 144
	other  goto 145
	open_statement  goto 146
	selection_statement  goto 147
	matched_statement  goto 148
	jump_statement  goto 149
	stmt  goto 150
	postfix_pre_exp  goto 151


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
State 33 contains 1 shift-reduce conflict(s)
State 42 contains 3 shift-reduce conflict(s)
State 145 contains 30 reduce-reduce conflict(s)
State 184 contains 1 shift-reduce conflict(s)
State 350 contains 1 reduce-reduce conflict(s)


86 token(s), 76 nonterminal(s)
231 grammar rule(s), 371 state(s)


##############################################################################
# End of File
##############################################################################
