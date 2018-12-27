#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 78 of your 30 day trial period.
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
# Time: 17:23:47
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

	external_declaration  goto 24
	function_definition  goto 25
	direct_pre_declarator  goto 26
	translation_unit  goto 27
	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 32
	struct_or_union  goto 33
	declarator  goto 34
	direct_declarator  goto 35
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 38
	pointer  goto 39


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_pre_declarator  goto 26
	declarator  goto 40
	direct_declarator  goto 35
	pointer  goto 39


2: shift-reduce conflict (shift 2, reduce 150) on '*'
2: shift-reduce conflict (shift 18, reduce 150) on CONST
2: shift-reduce conflict (shift 19, reduce 150) on VOLATILE
state 2
	pointer : '*' .  (150)
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' . type_qualifier_list pointer

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
	enum_specifier : ENUM . ID
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'

	'{'  shift 44
	ID  shift 45


state 24
	translation_unit : external_declaration .  (223)

	.  reduce 223


state 25
	external_declaration : function_definition .  (225)

	.  reduce 225


state 26
	direct_declarator : direct_pre_declarator . ')'
	direct_declarator : direct_pre_declarator . identifier_list ')'
	direct_declarator : direct_pre_declarator . parameter_type_list ')'

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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 48
	parameter_type_list  goto 49
	parameter_declaration  goto 50
	identifier_list  goto 51
	parameter_list  goto 52


state 27
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

	external_declaration  goto 53
	function_definition  goto 25
	direct_pre_declarator  goto 26
	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 32
	struct_or_union  goto 33
	declarator  goto 34
	direct_declarator  goto 35
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 38
	pointer  goto 39


28: shift-reduce conflict (shift 2, reduce 84) on '*'
state 28
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 54
	pointer  goto 55


state 29
	type_specifier : enum_specifier .  (107)

	.  reduce 107


state 30
	declaration_specifiers : storage_class_specifier . declaration_specifiers
	declaration_specifiers : storage_class_specifier .  (82)

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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 56


state 31
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 57


state 32
	external_declaration : declaration .  (226)

	.  reduce 226


state 33
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'
	struct_or_union_def : struct_or_union . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID

	'{'  shift 58
	ID  shift 59


state 34
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

	'{'  shift 60
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 61
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 62
	declaration_list  goto 63
	compound_statement  goto 64


state 35
	direct_declarator : direct_declarator . '[' ']'
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'
	declarator : direct_declarator .  (141)

	'('  shift 65
	'['  shift 66
	.  reduce 141


state 36
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 67
	ID  shift 3

	direct_pre_declarator  goto 26
	init_declarator  goto 68
	declarator  goto 69
	direct_declarator  goto 35
	def_concat  goto 70
	init_declarator_list  goto 71
	pointer  goto 39


state 37
	type_specifier : struct_or_union_specifier .  (106)

	.  reduce 106


state 38
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 72
	ID  shift 3

	direct_pre_declarator  goto 26
	init_declarator  goto 68
	declarator  goto 73
	direct_declarator  goto 35
	init_declarator_list  goto 74
	pointer  goto 39


state 39
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_pre_declarator  goto 26
	direct_declarator  goto 75


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

	enumerator  goto 80
	enumerator_list  goto 81


state 45
	enum_specifier : ENUM ID .  (133)
	enum_specifier : ENUM ID . '{' enumerator_list '}'

	'{'  shift 82
	.  reduce 133


state 46
	direct_declarator : direct_pre_declarator ')' .  (149)

	.  reduce 149


state 47
	identifier_list : ID .  (163)

	.  reduce 163


state 48
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (162)

	'('  shift 83
	'*'  shift 2
	'['  shift 84
	ID  shift 3
	.  reduce 162

	direct_pre_declarator  goto 26
	declarator  goto 85
	direct_declarator  goto 35
	direct_abstract_declarator  goto 86
	abstract_declarator  goto 87
	pointer  goto 88


state 49
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 89


state 50
	parameter_list : parameter_declaration .  (158)

	.  reduce 158


state 51
	direct_declarator : direct_pre_declarator identifier_list . ')'
	identifier_list : identifier_list . ',' ID

	')'  shift 90
	','  shift 91


state 52
	parameter_type_list : parameter_list .  (156)
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 92
	.  reduce 156


state 53
	translation_unit : translation_unit external_declaration .  (224)

	.  reduce 224


state 54
	declaration_specifiers : type_specifier declaration_specifiers .  (85)

	.  reduce 85


state 55
	type_specifier : type_specifier pointer .  (109)

	.  reduce 109


state 56
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (83)

	.  reduce 83


state 57
	declaration_specifiers : type_qualifier declaration_specifiers .  (87)

	.  reduce 87


state 58
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 61
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 62
	declaration_list  goto 93


state 59
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union ID .  (115)

	'{'  shift 94
	.  reduce 115


state 60
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . statement_list '}'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'}'  shift 102
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TYPE_NAME  shift 4
	TRUE  shift 110
	FALSE  shift 111
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
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	type_specifier  goto 28
	enum_specifier  goto 29
	logical_and_exp  goto 143
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 61
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	declaration_specifiers  goto 62
	equality_exp  goto 149
	statement  goto 150
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	declaration_list  goto 154
	compound_statement  goto 155
	statement_list  goto 156


state 61
	declaration_list : declaration .  (199)

	.  reduce 199


state 62
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 72
	ID  shift 3

	direct_pre_declarator  goto 26
	init_declarator  goto 68
	declarator  goto 69
	direct_declarator  goto 35
	init_declarator_list  goto 74
	pointer  goto 39


state 63
	declaration_list : declaration_list . M declaration
	function_definition : declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 60
	.  reduce 58

	M  goto 157
	compound_statement  goto 158


state 64
	function_definition : declarator compound_statement .  (230)

	.  reduce 230


state 65
	direct_pre_declarator : direct_declarator '(' .  (142)

	.  reduce 142


state 66
	direct_declarator : direct_declarator '[' . ']'
	direct_declarator : direct_declarator '[' . constant_exp ']'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	']'  shift 159
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	constant_exp  goto 162
	logical_and_exp  goto 143
	conditional_exp  goto 163
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	equality_exp  goto 149


state 67
	def_concat : ';' .  (112)

	.  reduce 112


state 68
	init_declarator_list : init_declarator .  (88)

	.  reduce 88


state 69
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)

	'='  shift 164
	.  reduce 90


state 70
	struct_or_union_specifier : struct_or_union_def def_concat .  (114)

	.  reduce 114


state 71
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 165
	';'  shift 166


state 72
	declaration : declaration_specifiers ';' .  (80)

	.  reduce 80


state 73
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 164
	'{'  shift 60
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 61
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 62
	declaration_list  goto 167
	compound_statement  goto 168


state 74
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 165
	';'  shift 169


state 75
	direct_declarator : direct_declarator . '[' ']'
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'
	declarator : pointer direct_declarator .  (140)

	'('  shift 65
	'['  shift 66
	.  reduce 140


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
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 83
	')'  shift 174
	'*'  shift 2
	'['  shift 84
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

	direct_pre_declarator  goto 26
	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	declarator  goto 40
	direct_declarator  goto 35
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 48
	parameter_type_list  goto 175
	parameter_declaration  goto 50
	direct_abstract_declarator  goto 86
	abstract_declarator  goto 176
	parameter_list  goto 52
	pointer  goto 88


state 84
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	']'  shift 177
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	constant_exp  goto 178
	logical_and_exp  goto 143
	conditional_exp  goto 163
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	equality_exp  goto 149


state 85
	parameter_declaration : declaration_specifiers declarator .  (160)

	.  reduce 160


state 86
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	abstract_declarator : direct_abstract_declarator .  (168)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'

	'('  shift 179
	'['  shift 180
	.  reduce 168


state 87
	parameter_declaration : declaration_specifiers abstract_declarator .  (161)

	.  reduce 161


state 88
	abstract_declarator : pointer .  (167)
	abstract_declarator : pointer . direct_abstract_declarator
	declarator : pointer . direct_declarator

	'('  shift 83
	'['  shift 84
	ID  shift 3
	.  reduce 167

	direct_pre_declarator  goto 26
	direct_declarator  goto 75
	direct_abstract_declarator  goto 181


state 89
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (147)

	.  reduce 147


state 90
	direct_declarator : direct_pre_declarator identifier_list ')' .  (148)

	.  reduce 148


state 91
	identifier_list : identifier_list ',' . ID

	ID  shift 182


state 92
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
	ELLIPSIS  shift 183

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 48
	parameter_declaration  goto 184


state 93
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 185
	.  reduce 58

	M  goto 157


state 94
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 61
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 62
	declaration_list  goto 186


state 95
	unary_operator : '!' .  (29)

	.  reduce 29


state 96
	unary_operator : '&' .  (24)

	.  reduce 24


state 97
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TYPE_NAME  shift 4
	TRUE  shift 110
	FALSE  shift 111
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

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	type_specifier  goto 187
	enum_specifier  goto 29
	logical_and_exp  goto 143
	type_qualifier  goto 188
	specifier_qualifier_list  goto 189
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 190
	equality_exp  goto 149
	type_name  goto 191


state 98
	unary_operator : '*' .  (25)

	.  reduce 25


state 99
	unary_operator : '+' .  (26)

	.  reduce 26


state 100
	unary_operator : '-' .  (27)

	.  reduce 27


state 101
	exp_statement : ';' .  (203)

	.  reduce 203


state 102
	compound_statement : '{' '}' .  (195)

	.  reduce 195


state 103
	unary_operator : '~' .  (28)

	.  reduce 28


state 104
	labeled_statement : ID . ':' statement
	primary_exp : ID .  (1)

	':'  shift 192
	.  reduce 1


state 105
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 106
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 107
	unary_exp : SIZEOF . unary_exp
	unary_exp : SIZEOF . '(' type_name ')'

	'!'  shift 95
	'&'  shift 96
	'('  shift 193
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	unary_exp  goto 194
	postfix_exp  goto 138
	primary_exp  goto 139


state 108
	unary_exp : INC_OP . unary_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 195
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	unary_exp  goto 196
	postfix_exp  goto 138
	primary_exp  goto 139


state 109
	unary_exp : DEC_OP . unary_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 195
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	unary_exp  goto 197
	postfix_exp  goto 138
	primary_exp  goto 139


state 110
	primary_exp : TRUE .  (5)

	.  reduce 5


state 111
	primary_exp : FALSE .  (6)

	.  reduce 6


state 112
	labeled_statement : CASE . constant_exp ':' M statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	constant_exp  goto 198
	logical_and_exp  goto 143
	conditional_exp  goto 163
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	equality_exp  goto 149


state 113
	default_pre : DEFAULT . ':'

	':'  shift 199


state 114
	matched_statement : IF . '(' exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF . '(' exp ')' M matched_statement N ELSE M open_statement
	open_statement : IF . '(' exp ')' M stmt

	'('  shift 200


state 115
	switch_pre : SWITCH . '(' exp ')'

	'('  shift 201


state 116
	iteration_statement : WHILE . M '(' exp ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 202


state 117
	iteration_statement : DO . M statement WHILE M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 203


state 118
	iteration_statement : FOR . '(' exp_statement M exp_statement M exp ')' M statement
	iteration_statement : FOR . '(' exp_statement M exp_statement ')' M statement

	'('  shift 204


state 119
	jump_statement : GOTO . ID ';'

	ID  shift 205


state 120
	jump_statement : CONTINUE . ';'

	';'  shift 206


state 121
	jump_statement : BREAK . ';'

	';'  shift 207


state 122
	jump_statement : RETURN . exp ';'
	jump_statement : RETURN . ';'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 208
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 209
	equality_exp  goto 149


state 123
	selection_statement : stmt .  (211)

	.  reduce 211


124: reduce-reduce conflict (reduce 189, reduce 208) on '!'
124: reduce-reduce conflict (reduce 189, reduce 208) on '&'
124: reduce-reduce conflict (reduce 189, reduce 208) on '('
124: reduce-reduce conflict (reduce 189, reduce 208) on '*'
124: reduce-reduce conflict (reduce 189, reduce 208) on '+'
124: reduce-reduce conflict (reduce 189, reduce 208) on '-'
124: reduce-reduce conflict (reduce 189, reduce 208) on ';'
124: reduce-reduce conflict (reduce 189, reduce 208) on '{'
124: reduce-reduce conflict (reduce 189, reduce 208) on '}'
124: reduce-reduce conflict (reduce 189, reduce 208) on '~'
124: reduce-reduce conflict (reduce 189, reduce 208) on ID
124: reduce-reduce conflict (reduce 189, reduce 208) on CONSTANT
124: reduce-reduce conflict (reduce 189, reduce 208) on STRING_LITERAL
124: reduce-reduce conflict (reduce 189, reduce 208) on SIZEOF
124: reduce-reduce conflict (reduce 189, reduce 208) on INC_OP
124: reduce-reduce conflict (reduce 189, reduce 208) on DEC_OP
124: reduce-reduce conflict (reduce 189, reduce 208) on TRUE
124: reduce-reduce conflict (reduce 189, reduce 208) on FALSE
124: reduce-reduce conflict (reduce 189, reduce 208) on CASE
124: reduce-reduce conflict (reduce 189, reduce 208) on DEFAULT
124: reduce-reduce conflict (reduce 189, reduce 208) on IF
124: reduce-reduce conflict (reduce 189, reduce 208) on ELSE
124: reduce-reduce conflict (reduce 189, reduce 208) on SWITCH
124: reduce-reduce conflict (reduce 189, reduce 208) on WHILE
124: reduce-reduce conflict (reduce 189, reduce 208) on DO
124: reduce-reduce conflict (reduce 189, reduce 208) on FOR
124: reduce-reduce conflict (reduce 189, reduce 208) on GOTO
124: reduce-reduce conflict (reduce 189, reduce 208) on CONTINUE
124: reduce-reduce conflict (reduce 189, reduce 208) on BREAK
124: reduce-reduce conflict (reduce 189, reduce 208) on RETURN
state 124
	statement : other .  (189)
	matched_statement : other .  (208)

	.  reduce 189


state 125
	stmt : open_statement .  (206)

	.  reduce 206


state 126
	selection_statement : switch_pre . statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 210
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 127
	statement : selection_statement .  (190)

	.  reduce 190


state 128
	other : jump_statement .  (187)

	.  reduce 187


state 129
	stmt : matched_statement .  (205)

	.  reduce 205


state 130
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	')'  shift 211
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	argument_exp_list  goto 212
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 213
	equality_exp  goto 149


state 131
	unary_exp : unary_operator . cast_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 214
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 132
	multiplicative_exp : cast_exp .  (32)

	.  reduce 32


state 133
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : multiplicative_exp .  (36)
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 215
	'*'  shift 216
	'/'  shift 217
	.  reduce 36


state 134
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : additive_exp .  (39)

	'+'  shift 218
	'-'  shift 219
	.  reduce 39


state 135
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


state 136
	relational_exp : shift_exp .  (42)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 232
	RIGHT_OP  shift 233
	.  reduce 42


state 137
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : relational_exp .  (47)

	'<'  shift 234
	'>'  shift 235
	LE_OP  shift 236
	GE_OP  shift 237
	.  reduce 47


state 138
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (18)

	'('  shift 238
	'.'  shift 239
	'['  shift 240
	PTR_OP  shift 241
	INC_OP  shift 242
	DEC_OP  shift 243
	.  reduce 18


state 139
	postfix_exp : primary_exp .  (8)

	.  reduce 8


state 140
	labeled_statement : default_pre . statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 244
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 141
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : exclusive_or_exp .  (54)

	'^'  shift 245
	.  reduce 54


state 142
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : and_exp .  (52)

	'&'  shift 246
	.  reduce 52


state 143
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_and_exp .  (60)

	AND_OP  shift 247
	.  reduce 60


state 144
	assignment_exp : conditional_exp .  (64)

	.  reduce 64


state 145
	logical_or_exp : logical_or_exp . OR_OP M logical_and_exp
	conditional_exp : logical_or_exp .  (62)
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp

	'?'  shift 248
	OR_OP  shift 249
	.  reduce 62


state 146
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : inclusive_or_exp .  (56)

	'|'  shift 250
	.  reduce 56


state 147
	exp : assignment_exp .  (77)

	.  reduce 77


state 148
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 251
	';'  shift 252


state 149
	equality_exp : equality_exp . EQ_OP relational_exp
	equality_exp : equality_exp . NE_OP relational_exp
	and_exp : equality_exp .  (50)

	EQ_OP  shift 253
	NE_OP  shift 254
	.  reduce 50


state 150
	statement_list : statement .  (201)

	.  reduce 201


state 151
	statement : labeled_statement .  (188)

	.  reduce 188


state 152
	other : exp_statement .  (185)

	.  reduce 185


state 153
	other : iteration_statement .  (186)

	.  reduce 186


state 154
	compound_statement : '{' declaration_list . statement_list '}'
	compound_statement : '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'}'  shift 255
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122
	.  reduce 58

	M  goto 157
	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 150
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155
	statement_list  goto 256


state 155
	other : compound_statement .  (184)

	.  reduce 184


state 156
	statement_list : statement_list . M statement
	compound_statement : '{' statement_list . '}'
	M : .  (58)

	'}'  shift 257
	.  reduce 58

	M  goto 258


state 157
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	declaration  goto 259
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 62


state 158
	function_definition : declarator declaration_list compound_statement .  (229)

	.  reduce 229


state 159
	direct_declarator : direct_declarator '[' ']' .  (146)

	.  reduce 146


state 160
	primary_exp : ID .  (1)

	.  reduce 1


state 161
	cast_exp : unary_exp .  (30)

	.  reduce 30


state 162
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 260


state 163
	constant_exp : conditional_exp .  (79)

	.  reduce 79


state 164
	init_declarator : declarator '=' . initializer

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'{'  shift 261
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 262
	equality_exp  goto 149
	initializer  goto 263


state 165
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_pre_declarator  goto 26
	init_declarator  goto 264
	declarator  goto 69
	direct_declarator  goto 35
	pointer  goto 39


state 166
	def_concat : init_declarator_list ';' .  (113)

	.  reduce 113


state 167
	declaration_list : declaration_list . M declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 60
	.  reduce 58

	M  goto 157
	compound_statement  goto 265


state 168
	function_definition : declaration_specifiers declarator compound_statement .  (228)

	.  reduce 228


state 169
	declaration : declaration_specifiers init_declarator_list ';' .  (81)

	.  reduce 81


state 170
	enumerator : ID '=' . constant_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	constant_exp  goto 266
	logical_and_exp  goto 143
	conditional_exp  goto 163
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	equality_exp  goto 149


state 171
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 79

	enumerator  goto 267


state 172
	enum_specifier : ENUM '{' enumerator_list '}' .  (131)

	.  reduce 131


state 173
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM ID '{' enumerator_list . '}'

	','  shift 171
	'}'  shift 268


state 174
	direct_abstract_declarator : '(' ')' .  (175)

	.  reduce 175


state 175
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 269


state 176
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 270


state 177
	direct_abstract_declarator : '[' ']' .  (171)

	.  reduce 171


state 178
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 271


state 179
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 48
	parameter_type_list  goto 273
	parameter_declaration  goto 50
	parameter_list  goto 52


state 180
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	']'  shift 274
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	constant_exp  goto 275
	logical_and_exp  goto 143
	conditional_exp  goto 163
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	equality_exp  goto 149


state 181
	abstract_declarator : pointer direct_abstract_declarator .  (169)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'

	'('  shift 179
	'['  shift 180
	.  reduce 169


state 182
	identifier_list : identifier_list ',' ID .  (164)

	.  reduce 164


state 183
	parameter_type_list : parameter_list ',' ELLIPSIS .  (157)

	.  reduce 157


state 184
	parameter_list : parameter_list ',' parameter_declaration .  (159)

	.  reduce 159


state 185
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (111)

	.  reduce 111


state 186
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 276
	.  reduce 58

	M  goto 157


187: shift-reduce conflict (shift 2, reduce 123) on '*'
state 187
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	type_specifier : type_specifier . pointer
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

	type_specifier  goto 187
	enum_specifier  goto 29
	type_qualifier  goto 188
	specifier_qualifier_list  goto 277
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	pointer  goto 55


state 188
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

	type_specifier  goto 187
	enum_specifier  goto 29
	type_qualifier  goto 188
	specifier_qualifier_list  goto 278
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37


state 189
	type_name : specifier_qualifier_list .  (165)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 279
	'*'  shift 2
	'['  shift 84
	.  reduce 165

	direct_abstract_declarator  goto 86
	abstract_declarator  goto 280
	pointer  goto 281


state 190
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 282
	','  shift 251


state 191
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 283


state 192
	labeled_statement : ID ':' . statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 284
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 193
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TYPE_NAME  shift 4
	TRUE  shift 110
	FALSE  shift 111
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

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	type_specifier  goto 187
	enum_specifier  goto 29
	logical_and_exp  goto 143
	type_qualifier  goto 188
	specifier_qualifier_list  goto 189
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 190
	equality_exp  goto 149
	type_name  goto 285


state 194
	unary_exp : SIZEOF unary_exp .  (22)

	.  reduce 22


state 195
	primary_exp : '(' . exp ')'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 190
	equality_exp  goto 149


state 196
	unary_exp : INC_OP unary_exp .  (19)

	.  reduce 19


state 197
	unary_exp : DEC_OP unary_exp .  (20)

	.  reduce 20


state 198
	labeled_statement : CASE constant_exp . ':' M statement

	':'  shift 286


state 199
	default_pre : DEFAULT ':' .  (191)

	.  reduce 191


state 200
	matched_statement : IF '(' . exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' . exp ')' M matched_statement N ELSE M open_statement
	open_statement : IF '(' . exp ')' M stmt

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 287
	equality_exp  goto 149


state 201
	switch_pre : SWITCH '(' . exp ')'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 288
	equality_exp  goto 149


state 202
	iteration_statement : WHILE M . '(' exp ')' M statement

	'('  shift 289


state 203
	iteration_statement : DO M . statement WHILE M '(' exp ')' ';'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 290
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 204
	iteration_statement : FOR '(' . exp_statement M exp_statement M exp ')' M statement
	iteration_statement : FOR '(' . exp_statement M exp_statement ')' M statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	exp_statement  goto 291


state 205
	jump_statement : GOTO ID . ';'

	';'  shift 292


state 206
	jump_statement : CONTINUE ';' .  (219)

	.  reduce 219


state 207
	jump_statement : BREAK ';' .  (220)

	.  reduce 220


state 208
	jump_statement : RETURN ';' .  (221)

	.  reduce 221


state 209
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 251
	';'  shift 293


state 210
	selection_statement : switch_pre statement .  (212)

	.  reduce 212


state 211
	postfix_exp : postfix_pre_exp ')' .  (10)

	.  reduce 10


state 212
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 294
	','  shift 295


state 213
	argument_exp_list : assignment_exp .  (16)

	.  reduce 16


state 214
	unary_exp : unary_operator cast_exp .  (21)

	.  reduce 21


state 215
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 296
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 216
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 297
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 217
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 298
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 218
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 299
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 219
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 300
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 220
	assignment_operator : '=' .  (66)

	.  reduce 66


state 221
	assignment_operator : MUL_ASSIGN .  (67)

	.  reduce 67


state 222
	assignment_operator : DIV_ASSIGN .  (68)

	.  reduce 68


state 223
	assignment_operator : MOD_ASSIGN .  (69)

	.  reduce 69


state 224
	assignment_operator : ADD_ASSIGN .  (70)

	.  reduce 70


state 225
	assignment_operator : SUB_ASSIGN .  (71)

	.  reduce 71


state 226
	assignment_operator : LEFT_ASSIGN .  (72)

	.  reduce 72


state 227
	assignment_operator : RIGHT_ASSIGN .  (73)

	.  reduce 73


state 228
	assignment_operator : AND_ASSIGN .  (74)

	.  reduce 74


state 229
	assignment_operator : XOR_ASSIGN .  (75)

	.  reduce 75


state 230
	assignment_operator : OR_ASSIGN .  (76)

	.  reduce 76


state 231
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 301
	equality_exp  goto 149


state 232
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 302
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 233
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 303
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 234
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 304
	postfix_exp  goto 138
	primary_exp  goto 139


state 235
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 305
	postfix_exp  goto 138
	primary_exp  goto 139


state 236
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 306
	postfix_exp  goto 138
	primary_exp  goto 139


state 237
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 307
	postfix_exp  goto 138
	primary_exp  goto 139


state 238
	postfix_pre_exp : postfix_exp '(' .  (7)

	.  reduce 7


state 239
	postfix_exp : postfix_exp '.' . ID

	ID  shift 308


state 240
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 309
	equality_exp  goto 149


state 241
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 310


state 242
	postfix_exp : postfix_exp INC_OP .  (14)

	.  reduce 14


state 243
	postfix_exp : postfix_exp DEC_OP .  (15)

	.  reduce 15


state 244
	labeled_statement : default_pre statement .  (194)

	.  reduce 194


state 245
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	and_exp  goto 311
	equality_exp  goto 149


state 246
	and_exp : and_exp '&' . equality_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	equality_exp  goto 312


state 247
	logical_and_exp : logical_and_exp AND_OP . M inclusive_or_exp
	M : .  (58)

	.  reduce 58

	M  goto 313


state 248
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 314
	equality_exp  goto 149


state 249
	logical_or_exp : logical_or_exp OR_OP . M logical_and_exp
	M : .  (58)

	.  reduce 58

	M  goto 315


state 250
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 316
	and_exp  goto 142
	equality_exp  goto 149


state 251
	exp : exp ',' . assignment_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 317
	equality_exp  goto 149


state 252
	exp_statement : exp ';' .  (204)

	.  reduce 204


state 253
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 318
	postfix_exp  goto 138
	primary_exp  goto 139


state 254
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 319
	postfix_exp  goto 138
	primary_exp  goto 139


state 255
	compound_statement : '{' declaration_list '}' .  (197)

	.  reduce 197


state 256
	statement_list : statement_list . M statement
	compound_statement : '{' declaration_list statement_list . '}'
	M : .  (58)

	'}'  shift 320
	.  reduce 58

	M  goto 258


state 257
	compound_statement : '{' statement_list '}' .  (196)

	.  reduce 196


state 258
	statement_list : statement_list M . statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 321
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 259
	declaration_list : declaration_list M declaration .  (200)

	.  reduce 200


state 260
	direct_declarator : direct_declarator '[' constant_exp ']' .  (145)

	.  reduce 145


state 261
	initializer : '{' . initializer_list ',' '}'
	initializer : '{' . initializer_list '}'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'{'  shift 261
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 262
	equality_exp  goto 149
	initializer_list  goto 322
	initializer  goto 323


state 262
	initializer : assignment_exp .  (179)

	.  reduce 179


state 263
	init_declarator : declarator '=' initializer .  (91)

	.  reduce 91


state 264
	init_declarator_list : init_declarator_list ',' init_declarator .  (89)

	.  reduce 89


state 265
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (227)

	.  reduce 227


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
	direct_abstract_declarator : '(' parameter_type_list ')' .  (176)

	.  reduce 176


state 270
	direct_abstract_declarator : '(' abstract_declarator ')' .  (170)

	.  reduce 170


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
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (110)

	.  reduce 110


state 277
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (122)

	.  reduce 122


state 278
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (124)

	.  reduce 124


state 279
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 279
	')'  shift 174
	'*'  shift 2
	'['  shift 84
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

	type_specifier  goto 28
	enum_specifier  goto 29
	storage_class_specifier  goto 30
	type_qualifier  goto 31
	struct_or_union  goto 33
	struct_or_union_def  goto 36
	struct_or_union_specifier  goto 37
	declaration_specifiers  goto 48
	parameter_type_list  goto 175
	parameter_declaration  goto 50
	direct_abstract_declarator  goto 86
	abstract_declarator  goto 176
	parameter_list  goto 52
	pointer  goto 281


state 280
	type_name : specifier_qualifier_list abstract_declarator .  (166)

	.  reduce 166


state 281
	abstract_declarator : pointer .  (167)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 279
	'['  shift 84
	.  reduce 167

	direct_abstract_declarator  goto 181


state 282
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 283
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 326
	unary_exp  goto 161
	postfix_exp  goto 138
	primary_exp  goto 139


state 284
	labeled_statement : ID ':' statement .  (192)

	.  reduce 192


state 285
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 327


state 286
	labeled_statement : CASE constant_exp ':' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 328


state 287
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp . ')' M matched_statement N ELSE M open_statement
	open_statement : IF '(' exp . ')' M stmt

	')'  shift 329
	','  shift 251


state 288
	exp : exp . ',' assignment_exp
	switch_pre : SWITCH '(' exp . ')'

	')'  shift 330
	','  shift 251


state 289
	iteration_statement : WHILE M '(' . exp ')' M statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 331
	equality_exp  goto 149


state 290
	iteration_statement : DO M statement . WHILE M '(' exp ')' ';'

	WHILE  shift 332


state 291
	iteration_statement : FOR '(' exp_statement . M exp_statement M exp ')' M statement
	iteration_statement : FOR '(' exp_statement . M exp_statement ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 333


state 292
	jump_statement : GOTO ID ';' .  (218)

	.  reduce 218


state 293
	jump_statement : RETURN exp ';' .  (222)

	.  reduce 222


state 294
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (11)

	.  reduce 11


state 295
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 334
	equality_exp  goto 149


state 296
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (35)

	.  reduce 35


state 297
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (33)

	.  reduce 33


state 298
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (34)

	.  reduce 34


state 299
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (37)
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 215
	'*'  shift 216
	'/'  shift 217
	.  reduce 37


state 300
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (38)
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 215
	'*'  shift 216
	'/'  shift 217
	.  reduce 38


state 301
	assignment_exp : unary_exp assignment_operator assignment_exp .  (65)

	.  reduce 65


state 302
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (40)

	'+'  shift 218
	'-'  shift 219
	.  reduce 40


state 303
	additive_exp : additive_exp . '-' multiplicative_exp
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (41)

	'+'  shift 218
	'-'  shift 219
	.  reduce 41


state 304
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp '<' shift_exp .  (43)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 232
	RIGHT_OP  shift 233
	.  reduce 43


state 305
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp '>' shift_exp .  (44)

	LEFT_OP  shift 232
	RIGHT_OP  shift 233
	.  reduce 44


state 306
	shift_exp : shift_exp . RIGHT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (45)
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 232
	RIGHT_OP  shift 233
	.  reduce 45


state 307
	relational_exp : relational_exp GE_OP shift_exp .  (46)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 232
	RIGHT_OP  shift 233
	.  reduce 46


state 308
	postfix_exp : postfix_exp '.' ID .  (12)

	.  reduce 12


state 309
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 251
	']'  shift 335


state 310
	postfix_exp : postfix_exp PTR_OP ID .  (13)

	.  reduce 13


state 311
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (53)

	'&'  shift 246
	.  reduce 53


state 312
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : and_exp '&' equality_exp .  (51)
	equality_exp : equality_exp . NE_OP relational_exp

	EQ_OP  shift 253
	NE_OP  shift 254
	.  reduce 51


state 313
	logical_and_exp : logical_and_exp AND_OP M . inclusive_or_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	inclusive_or_exp  goto 336
	equality_exp  goto 149


state 314
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 251
	':'  shift 337


state 315
	logical_or_exp : logical_or_exp OR_OP M . logical_and_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 338
	inclusive_or_exp  goto 146
	equality_exp  goto 149


state 316
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (55)

	'^'  shift 245
	.  reduce 55


state 317
	exp : exp ',' assignment_exp .  (78)

	.  reduce 78


state 318
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (48)
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 234
	'>'  shift 235
	LE_OP  shift 236
	GE_OP  shift 237
	.  reduce 48


state 319
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (49)

	'<'  shift 234
	'>'  shift 235
	LE_OP  shift 236
	GE_OP  shift 237
	.  reduce 49


state 320
	compound_statement : '{' declaration_list statement_list '}' .  (198)

	.  reduce 198


state 321
	statement_list : statement_list M statement .  (202)

	.  reduce 202


state 322
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . ',' '}'
	initializer : '{' initializer_list . '}'

	','  shift 339
	'}'  shift 340


state 323
	initializer_list : initializer .  (182)

	.  reduce 182


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
	labeled_statement : CASE constant_exp ':' M . statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 341
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 329
	matched_statement : IF '(' exp ')' . M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' . M matched_statement N ELSE M open_statement
	open_statement : IF '(' exp ')' . M stmt
	M : .  (58)

	.  reduce 58

	M  goto 342


state 330
	switch_pre : SWITCH '(' exp ')' .  (213)

	.  reduce 213


state 331
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE M '(' exp . ')' M statement

	')'  shift 343
	','  shift 251


state 332
	iteration_statement : DO M statement WHILE . M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 344


state 333
	iteration_statement : FOR '(' exp_statement M . exp_statement M exp ')' M statement
	iteration_statement : FOR '(' exp_statement M . exp_statement ')' M statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	exp_statement  goto 345


state 334
	argument_exp_list : argument_exp_list ',' assignment_exp .  (17)

	.  reduce 17


state 335
	postfix_exp : postfix_exp '[' exp ']' .  (9)

	.  reduce 9


state 336
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : logical_and_exp AND_OP M inclusive_or_exp .  (57)

	'|'  shift 250
	.  reduce 57


state 337
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 161
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 346
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	equality_exp  goto 149


state 338
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_or_exp OR_OP M logical_and_exp .  (61)

	AND_OP  shift 247
	.  reduce 61


state 339
	initializer_list : initializer_list ',' . initializer
	initializer : '{' initializer_list ',' . '}'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'{'  shift 261
	'}'  shift 347
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 262
	equality_exp  goto 149
	initializer  goto 348


state 340
	initializer : '{' initializer_list '}' .  (180)

	.  reduce 180


state 341
	labeled_statement : CASE constant_exp ':' M statement .  (193)

	.  reduce 193


state 342
	matched_statement : IF '(' exp ')' M . matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' M . matched_statement N ELSE M open_statement
	open_statement : IF '(' exp ')' M . stmt

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	IF  shift 114
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 349
	other  goto 350
	open_statement  goto 125
	jump_statement  goto 128
	matched_statement  goto 351
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 343
	iteration_statement : WHILE M '(' exp ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 352


state 344
	iteration_statement : DO M statement WHILE M . '(' exp ')' ';'

	'('  shift 353


state 345
	iteration_statement : FOR '(' exp_statement M exp_statement . M exp ')' M statement
	iteration_statement : FOR '(' exp_statement M exp_statement . ')' M statement
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

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 357
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 353
	iteration_statement : DO M statement WHILE M '(' . exp ')' ';'

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 358
	equality_exp  goto 149


state 354
	iteration_statement : FOR '(' exp_statement M exp_statement ')' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 359


state 355
	iteration_statement : FOR '(' exp_statement M exp_statement M . exp ')' M statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111

	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 360
	equality_exp  goto 149


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
	','  shift 251


state 359
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M . statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 363
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 360
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement M exp_statement M exp . ')' M statement

	')'  shift 364
	','  shift 251


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

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 160
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	IF  shift 114
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	other  goto 350
	open_statement  goto 368
	jump_statement  goto 128
	matched_statement  goto 369
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


state 366
	iteration_statement : DO M statement WHILE M '(' exp ')' ';' .  (215)

	.  reduce 215


state 367
	iteration_statement : FOR '(' exp_statement M exp_statement M exp ')' M . statement

	'!'  shift 95
	'&'  shift 96
	'('  shift 97
	'*'  shift 98
	'+'  shift 99
	'-'  shift 100
	';'  shift 101
	'{'  shift 60
	'~'  shift 103
	ID  shift 104
	CONSTANT  shift 105
	STRING_LITERAL  shift 106
	SIZEOF  shift 107
	INC_OP  shift 108
	DEC_OP  shift 109
	TRUE  shift 110
	FALSE  shift 111
	CASE  shift 112
	DEFAULT  shift 113
	IF  shift 114
	SWITCH  shift 115
	WHILE  shift 116
	DO  shift 117
	FOR  shift 118
	GOTO  shift 119
	CONTINUE  shift 120
	BREAK  shift 121
	RETURN  shift 122

	stmt  goto 123
	other  goto 124
	open_statement  goto 125
	switch_pre  goto 126
	selection_statement  goto 127
	jump_statement  goto 128
	matched_statement  goto 129
	postfix_pre_exp  goto 130
	unary_operator  goto 131
	cast_exp  goto 132
	multiplicative_exp  goto 133
	additive_exp  goto 134
	unary_exp  goto 135
	shift_exp  goto 136
	relational_exp  goto 137
	postfix_exp  goto 138
	primary_exp  goto 139
	default_pre  goto 140
	exclusive_or_exp  goto 141
	and_exp  goto 142
	logical_and_exp  goto 143
	conditional_exp  goto 144
	logical_or_exp  goto 145
	inclusive_or_exp  goto 146
	assignment_exp  goto 147
	exp  goto 148
	equality_exp  goto 149
	statement  goto 370
	labeled_statement  goto 151
	exp_statement  goto 152
	iteration_statement  goto 153
	compound_statement  goto 155


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
State 28 contains 1 shift-reduce conflict(s)
State 42 contains 3 shift-reduce conflict(s)
State 124 contains 30 reduce-reduce conflict(s)
State 187 contains 1 shift-reduce conflict(s)
State 351 contains 1 reduce-reduce conflict(s)


86 token(s), 76 nonterminal(s)
231 grammar rule(s), 371 state(s)


##############################################################################
# End of File
##############################################################################
