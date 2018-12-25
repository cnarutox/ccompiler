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
# Time: 07:08:52
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

  187  statement : labeled_statement
  188            | other
  189            | selection_statement
  190            | jump_statement

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

	translation_unit  goto 24
	direct_pre_declarator  goto 25
	external_declaration  goto 26
	function_definition  goto 27
	declarator  goto 28
	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 34
	declaration_specifiers  goto 35
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	direct_declarator  goto 38
	pointer  goto 39


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_pre_declarator  goto 25
	declarator  goto 40
	direct_declarator  goto 38
	pointer  goto 39


2: shift-reduce conflict (shift 2, reduce 150) on '*'
2: shift-reduce conflict (shift 18, reduce 150) on CONST
2: shift-reduce conflict (shift 19, reduce 150) on VOLATILE
state 2
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' . pointer
	pointer : '*' .  (150)

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
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . ID
	enum_specifier : ENUM . '{' enumerator_list '}'

	'{'  shift 44
	ID  shift 45


state 24
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

	direct_pre_declarator  goto 25
	external_declaration  goto 46
	function_definition  goto 27
	declarator  goto 28
	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 34
	declaration_specifiers  goto 35
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	direct_declarator  goto 38
	pointer  goto 39


state 25
	direct_declarator : direct_pre_declarator . ')'
	direct_declarator : direct_pre_declarator . identifier_list ')'
	direct_declarator : direct_pre_declarator . parameter_type_list ')'

	')'  shift 47
	ID  shift 48
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 49
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	parameter_type_list  goto 50
	parameter_list  goto 51
	identifier_list  goto 52
	parameter_declaration  goto 53


state 26
	translation_unit : external_declaration .  (223)

	.  reduce 223


state 27
	external_declaration : function_definition .  (225)

	.  reduce 225


state 28
	function_definition : declarator . declaration_list compound_statement
	function_definition : declarator . compound_statement

	'{'  shift 54
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 55
	declaration_specifiers  goto 56
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	compound_statement  goto 57
	declaration_list  goto 58


state 29
	struct_or_union_def : struct_or_union . '{' declaration_list '}'
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'

	'{'  shift 59
	ID  shift 60


30: shift-reduce conflict (shift 2, reduce 84) on '*'
state 30
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 61
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	pointer  goto 62


state 31
	type_specifier : enum_specifier .  (107)

	.  reduce 107


state 32
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 63
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37


state 33
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 64
	ID  shift 3

	direct_pre_declarator  goto 25
	declarator  goto 65
	init_declarator  goto 66
	init_declarator_list  goto 67
	def_concat  goto 68
	direct_declarator  goto 38
	pointer  goto 39


state 34
	external_declaration : declaration .  (226)

	.  reduce 226


state 35
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 69
	ID  shift 3

	direct_pre_declarator  goto 25
	declarator  goto 70
	init_declarator  goto 66
	init_declarator_list  goto 71
	direct_declarator  goto 38
	pointer  goto 39


state 36
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 72
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37


state 37
	type_specifier : struct_or_union_specifier .  (106)

	.  reduce 106


state 38
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '[' constant_exp ']'
	declarator : direct_declarator .  (141)
	direct_pre_declarator : direct_declarator . '('

	'('  shift 73
	'['  shift 74
	.  reduce 141


state 39
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_pre_declarator  goto 25
	direct_declarator  goto 75


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
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list .  (151)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 151

	type_qualifier  goto 77
	pointer  goto 78


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
	translation_unit : translation_unit external_declaration .  (224)

	.  reduce 224


state 47
	direct_declarator : direct_pre_declarator ')' .  (149)

	.  reduce 149


state 48
	identifier_list : ID .  (163)

	.  reduce 163


state 49
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (162)

	'('  shift 83
	'*'  shift 2
	'['  shift 84
	ID  shift 3
	.  reduce 162

	direct_pre_declarator  goto 25
	declarator  goto 85
	direct_declarator  goto 38
	abstract_declarator  goto 86
	direct_abstract_declarator  goto 87
	pointer  goto 88


state 50
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 89


state 51
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_list : parameter_list . ',' parameter_declaration
	parameter_type_list : parameter_list .  (156)

	','  shift 90
	.  reduce 156


state 52
	direct_declarator : direct_pre_declarator identifier_list . ')'
	identifier_list : identifier_list . ',' ID

	')'  shift 91
	','  shift 92


state 53
	parameter_list : parameter_declaration .  (158)

	.  reduce 158


state 54
	compound_statement : '{' . '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . declaration_list statement_list '}'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'}'  shift 100
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TYPE_NAME  shift 4
	TRUE  shift 108
	FALSE  shift 109
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
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	struct_or_union  goto 29
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 55
	exclusive_or_exp  goto 146
	declaration_specifiers  goto 56
	and_exp  goto 147
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	labeled_statement  goto 148
	compound_statement  goto 149
	declaration_list  goto 150
	exp_statement  goto 151
	iteration_statement  goto 152
	statement_list  goto 153
	statement  goto 154


state 55
	declaration_list : declaration .  (199)

	.  reduce 199


state 56
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 69
	ID  shift 3

	direct_pre_declarator  goto 25
	declarator  goto 65
	init_declarator  goto 66
	init_declarator_list  goto 71
	direct_declarator  goto 38
	pointer  goto 39


state 57
	function_definition : declarator compound_statement .  (230)

	.  reduce 230


state 58
	declaration_list : declaration_list . M declaration
	function_definition : declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 54
	.  reduce 58

	M  goto 155
	compound_statement  goto 156


state 59
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 55
	declaration_specifiers  goto 56
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	declaration_list  goto 157


state 60
	struct_or_union_specifier : struct_or_union ID .  (115)
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'

	'{'  shift 158
	.  reduce 115


state 61
	declaration_specifiers : type_specifier declaration_specifiers .  (85)

	.  reduce 85


state 62
	type_specifier : type_specifier pointer .  (109)

	.  reduce 109


state 63
	declaration_specifiers : type_qualifier declaration_specifiers .  (87)

	.  reduce 87


state 64
	def_concat : ';' .  (112)

	.  reduce 112


state 65
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)

	'='  shift 159
	.  reduce 90


state 66
	init_declarator_list : init_declarator .  (88)

	.  reduce 88


state 67
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 160
	';'  shift 161


state 68
	struct_or_union_specifier : struct_or_union_def def_concat .  (114)

	.  reduce 114


state 69
	declaration : declaration_specifiers ';' .  (80)

	.  reduce 80


state 70
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (90)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 159
	'{'  shift 54
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 55
	declaration_specifiers  goto 56
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	compound_statement  goto 162
	declaration_list  goto 163


state 71
	init_declarator_list : init_declarator_list . ',' init_declarator
	declaration : declaration_specifiers init_declarator_list . ';'

	','  shift 160
	';'  shift 164


state 72
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (83)

	.  reduce 83


state 73
	direct_pre_declarator : direct_declarator '(' .  (142)

	.  reduce 142


state 74
	direct_declarator : direct_declarator '[' . ']'
	direct_declarator : direct_declarator '[' . constant_exp ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	']'  shift 165
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	conditional_exp  goto 168
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	constant_exp  goto 169
	and_exp  goto 147


state 75
	declarator : pointer direct_declarator .  (140)
	direct_declarator : direct_declarator . '[' ']'
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_pre_declarator : direct_declarator . '('

	'('  shift 73
	'['  shift 74
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
	enumerator : ID . '=' constant_exp
	enumerator : ID .  (136)

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
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

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

	direct_pre_declarator  goto 25
	declarator  goto 40
	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 49
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	direct_declarator  goto 38
	parameter_type_list  goto 175
	parameter_list  goto 51
	abstract_declarator  goto 176
	direct_abstract_declarator  goto 87
	pointer  goto 88
	parameter_declaration  goto 53


state 84
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	']'  shift 177
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	conditional_exp  goto 168
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	constant_exp  goto 178
	and_exp  goto 147


state 85
	parameter_declaration : declaration_specifiers declarator .  (160)

	.  reduce 160


state 86
	parameter_declaration : declaration_specifiers abstract_declarator .  (161)

	.  reduce 161


state 87
	abstract_declarator : direct_abstract_declarator .  (168)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 179
	'['  shift 180
	.  reduce 168


state 88
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (167)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 83
	'['  shift 84
	ID  shift 3
	.  reduce 167

	direct_pre_declarator  goto 25
	direct_declarator  goto 75
	direct_abstract_declarator  goto 181


state 89
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (147)

	.  reduce 147


state 90
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
	ELLIPSIS  shift 182

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 49
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	parameter_declaration  goto 183


state 91
	direct_declarator : direct_pre_declarator identifier_list ')' .  (148)

	.  reduce 148


state 92
	identifier_list : identifier_list ',' . ID

	ID  shift 184


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
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TYPE_NAME  shift 4
	TRUE  shift 108
	FALSE  shift 109
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

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 185
	struct_or_union  goto 29
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	type_specifier  goto 186
	enum_specifier  goto 31
	type_qualifier  goto 187
	struct_or_union_def  goto 33
	exclusive_or_exp  goto 146
	and_exp  goto 147
	struct_or_union_specifier  goto 37
	specifier_qualifier_list  goto 188
	type_name  goto 189


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
	exp_statement : ';' .  (203)

	.  reduce 203


state 100
	compound_statement : '{' '}' .  (195)

	.  reduce 195


state 101
	unary_operator : '~' .  (28)

	.  reduce 28


state 102
	labeled_statement : ID . ':' statement
	primary_exp : ID .  (1)

	':'  shift 190
	.  reduce 1


state 103
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 104
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 105
	unary_exp : SIZEOF . unary_exp
	unary_exp : SIZEOF . '(' type_name ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 191
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 192
	unary_operator  goto 136


state 106
	unary_exp : INC_OP . unary_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 193
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 194
	unary_operator  goto 136


state 107
	unary_exp : DEC_OP . unary_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 193
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 195
	unary_operator  goto 136


state 108
	primary_exp : TRUE .  (5)

	.  reduce 5


state 109
	primary_exp : FALSE .  (6)

	.  reduce 6


state 110
	labeled_statement : CASE . constant_exp ':' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	conditional_exp  goto 168
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	constant_exp  goto 196
	and_exp  goto 147


state 111
	default_pre : DEFAULT . ':'

	':'  shift 197


state 112
	matched_statement : IF . '(' exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF . '(' exp ')' M stmt
	open_statement : IF . '(' exp ')' M matched_statement N ELSE M open_statement

	'('  shift 198


state 113
	switch_pre : SWITCH . '(' exp ')'

	'('  shift 199


state 114
	iteration_statement : WHILE . M '(' exp ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 200


state 115
	iteration_statement : DO . M statement WHILE M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 201


state 116
	iteration_statement : FOR . '(' exp_statement M exp_statement M exp ')' M statement
	iteration_statement : FOR . '(' exp_statement M exp_statement ')' M statement

	'('  shift 202


state 117
	jump_statement : GOTO . ID ';'

	ID  shift 203


state 118
	jump_statement : CONTINUE . ';'

	';'  shift 204


state 119
	jump_statement : BREAK . ';'

	';'  shift 205


state 120
	jump_statement : RETURN . ';'
	jump_statement : RETURN . exp ';'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 206
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 207
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 121
	statement : selection_statement .  (189)

	.  reduce 189


122: reduce-reduce conflict (reduce 188, reduce 208) on '!'
122: reduce-reduce conflict (reduce 188, reduce 208) on '&'
122: reduce-reduce conflict (reduce 188, reduce 208) on '('
122: reduce-reduce conflict (reduce 188, reduce 208) on '*'
122: reduce-reduce conflict (reduce 188, reduce 208) on '+'
122: reduce-reduce conflict (reduce 188, reduce 208) on '-'
122: reduce-reduce conflict (reduce 188, reduce 208) on ';'
122: reduce-reduce conflict (reduce 188, reduce 208) on '{'
122: reduce-reduce conflict (reduce 188, reduce 208) on '}'
122: reduce-reduce conflict (reduce 188, reduce 208) on '~'
122: reduce-reduce conflict (reduce 188, reduce 208) on ID
122: reduce-reduce conflict (reduce 188, reduce 208) on CONSTANT
122: reduce-reduce conflict (reduce 188, reduce 208) on STRING_LITERAL
122: reduce-reduce conflict (reduce 188, reduce 208) on SIZEOF
122: reduce-reduce conflict (reduce 188, reduce 208) on INC_OP
122: reduce-reduce conflict (reduce 188, reduce 208) on DEC_OP
122: reduce-reduce conflict (reduce 188, reduce 208) on TRUE
122: reduce-reduce conflict (reduce 188, reduce 208) on FALSE
122: reduce-reduce conflict (reduce 188, reduce 208) on CASE
122: reduce-reduce conflict (reduce 188, reduce 208) on DEFAULT
122: reduce-reduce conflict (reduce 188, reduce 208) on IF
122: reduce-reduce conflict (reduce 188, reduce 208) on ELSE
122: reduce-reduce conflict (reduce 188, reduce 208) on SWITCH
122: reduce-reduce conflict (reduce 188, reduce 208) on WHILE
122: reduce-reduce conflict (reduce 188, reduce 208) on DO
122: reduce-reduce conflict (reduce 188, reduce 208) on FOR
122: reduce-reduce conflict (reduce 188, reduce 208) on GOTO
122: reduce-reduce conflict (reduce 188, reduce 208) on CONTINUE
122: reduce-reduce conflict (reduce 188, reduce 208) on BREAK
122: reduce-reduce conflict (reduce 188, reduce 208) on RETURN
state 122
	statement : other .  (188)
	matched_statement : other .  (208)

	.  reduce 188


state 123
	stmt : matched_statement .  (205)

	.  reduce 205


state 124
	selection_statement : switch_pre . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 208


state 125
	stmt : open_statement .  (206)

	.  reduce 206


state 126
	selection_statement : stmt .  (211)

	.  reduce 211


state 127
	statement : jump_statement .  (190)

	.  reduce 190


state 128
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	')'  shift 209
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	argument_exp_list  goto 210
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 211
	conditional_exp  goto 141
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 129
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : relational_exp .  (47)
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 212
	'>'  shift 213
	LE_OP  shift 214
	GE_OP  shift 215
	.  reduce 47


state 130
	multiplicative_exp : cast_exp .  (32)

	.  reduce 32


state 131
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : additive_exp .  (39)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 216
	'-'  shift 217
	.  reduce 39


state 132
	postfix_exp : primary_exp .  (8)

	.  reduce 8


state 133
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (18)

	'('  shift 218
	'.'  shift 219
	'['  shift 220
	PTR_OP  shift 221
	INC_OP  shift 222
	DEC_OP  shift 223
	.  reduce 18


state 134
	labeled_statement : default_pre . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 224


state 135
	cast_exp : unary_exp .  (30)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 225
	MUL_ASSIGN  shift 226
	DIV_ASSIGN  shift 227
	MOD_ASSIGN  shift 228
	ADD_ASSIGN  shift 229
	SUB_ASSIGN  shift 230
	LEFT_ASSIGN  shift 231
	RIGHT_ASSIGN  shift 232
	AND_ASSIGN  shift 233
	XOR_ASSIGN  shift 234
	OR_ASSIGN  shift 235
	.  reduce 30

	assignment_operator  goto 236


state 136
	unary_exp : unary_operator . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 237
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136


state 137
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : multiplicative_exp .  (36)
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 238
	'*'  shift 239
	'/'  shift 240
	.  reduce 36


state 138
	relational_exp : shift_exp .  (42)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 241
	RIGHT_OP  shift 242
	.  reduce 42


state 139
	conditional_exp : logical_or_exp .  (62)
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp
	logical_or_exp : logical_or_exp . OR_OP M logical_and_exp

	'?'  shift 243
	OR_OP  shift 244
	.  reduce 62


state 140
	exp : assignment_exp .  (77)

	.  reduce 77


state 141
	assignment_exp : conditional_exp .  (64)

	.  reduce 64


state 142
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 245
	';'  shift 246


state 143
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : equality_exp .  (50)

	EQ_OP  shift 247
	NE_OP  shift 248
	.  reduce 50


state 144
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : inclusive_or_exp .  (56)

	'|'  shift 249
	.  reduce 56


state 145
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_and_exp .  (60)

	AND_OP  shift 250
	.  reduce 60


state 146
	inclusive_or_exp : exclusive_or_exp .  (54)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 251
	.  reduce 54


state 147
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : and_exp .  (52)

	'&'  shift 252
	.  reduce 52


state 148
	statement : labeled_statement .  (187)

	.  reduce 187


state 149
	other : compound_statement .  (184)

	.  reduce 184


state 150
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
	';'  shift 99
	'{'  shift 54
	'}'  shift 253
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120
	.  reduce 58

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	M  goto 155
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement_list  goto 254
	statement  goto 154


state 151
	other : exp_statement .  (185)

	.  reduce 185


state 152
	other : iteration_statement .  (186)

	.  reduce 186


state 153
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (58)

	'}'  shift 255
	.  reduce 58

	M  goto 256


state 154
	statement_list : statement .  (201)

	.  reduce 201


state 155
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 257
	declaration_specifiers  goto 56
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37


state 156
	function_definition : declarator declaration_list compound_statement .  (229)

	.  reduce 229


state 157
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 258
	.  reduce 58

	M  goto 155


state 158
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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration  goto 55
	declaration_specifiers  goto 56
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	declaration_list  goto 259


state 159
	init_declarator : declarator '=' . initializer

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'{'  shift 260
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 261
	conditional_exp  goto 141
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	initializer  goto 262


state 160
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	direct_pre_declarator  goto 25
	declarator  goto 65
	init_declarator  goto 263
	direct_declarator  goto 38
	pointer  goto 39


state 161
	def_concat : init_declarator_list ';' .  (113)

	.  reduce 113


state 162
	function_definition : declaration_specifiers declarator compound_statement .  (228)

	.  reduce 228


state 163
	declaration_list : declaration_list . M declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement
	M : .  (58)

	'{'  shift 54
	.  reduce 58

	M  goto 155
	compound_statement  goto 264


state 164
	declaration : declaration_specifiers init_declarator_list ';' .  (81)

	.  reduce 81


state 165
	direct_declarator : direct_declarator '[' ']' .  (146)

	.  reduce 146


state 166
	primary_exp : ID .  (1)

	.  reduce 1


state 167
	cast_exp : unary_exp .  (30)

	.  reduce 30


state 168
	constant_exp : conditional_exp .  (79)

	.  reduce 79


state 169
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 265


state 170
	enumerator : ID '=' . constant_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	conditional_exp  goto 168
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	constant_exp  goto 266
	and_exp  goto 147


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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 49
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	parameter_type_list  goto 273
	parameter_list  goto 51
	parameter_declaration  goto 53


state 180
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	']'  shift 274
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	conditional_exp  goto 168
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	constant_exp  goto 275
	and_exp  goto 147


state 181
	abstract_declarator : pointer direct_abstract_declarator .  (169)
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 179
	'['  shift 180
	.  reduce 169


state 182
	parameter_type_list : parameter_list ',' ELLIPSIS .  (157)

	.  reduce 157


state 183
	parameter_list : parameter_list ',' parameter_declaration .  (159)

	.  reduce 159


state 184
	identifier_list : identifier_list ',' ID .  (164)

	.  reduce 164


state 185
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 276
	','  shift 245


186: shift-reduce conflict (shift 2, reduce 123) on '*'
state 186
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

	struct_or_union  goto 29
	type_specifier  goto 186
	enum_specifier  goto 31
	type_qualifier  goto 187
	struct_or_union_def  goto 33
	struct_or_union_specifier  goto 37
	specifier_qualifier_list  goto 277
	pointer  goto 62


state 187
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

	struct_or_union  goto 29
	type_specifier  goto 186
	enum_specifier  goto 31
	type_qualifier  goto 187
	struct_or_union_def  goto 33
	struct_or_union_specifier  goto 37
	specifier_qualifier_list  goto 278


state 188
	type_name : specifier_qualifier_list .  (165)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 279
	'*'  shift 2
	'['  shift 84
	.  reduce 165

	abstract_declarator  goto 280
	direct_abstract_declarator  goto 87
	pointer  goto 281


state 189
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 282


state 190
	labeled_statement : ID ':' . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 283


state 191
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TYPE_NAME  shift 4
	TRUE  shift 108
	FALSE  shift 109
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

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 185
	struct_or_union  goto 29
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	type_specifier  goto 186
	enum_specifier  goto 31
	type_qualifier  goto 187
	struct_or_union_def  goto 33
	exclusive_or_exp  goto 146
	and_exp  goto 147
	struct_or_union_specifier  goto 37
	specifier_qualifier_list  goto 188
	type_name  goto 284


state 192
	unary_exp : SIZEOF unary_exp .  (22)

	.  reduce 22


state 193
	primary_exp : '(' . exp ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 185
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 194
	unary_exp : INC_OP unary_exp .  (19)

	.  reduce 19


state 195
	unary_exp : DEC_OP unary_exp .  (20)

	.  reduce 20


state 196
	labeled_statement : CASE constant_exp . ':' M statement

	':'  shift 285


state 197
	default_pre : DEFAULT ':' .  (191)

	.  reduce 191


state 198
	matched_statement : IF '(' . exp ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' . exp ')' M stmt
	open_statement : IF '(' . exp ')' M matched_statement N ELSE M open_statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 286
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 199
	switch_pre : SWITCH '(' . exp ')'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 287
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 200
	iteration_statement : WHILE M . '(' exp ')' M statement

	'('  shift 288


state 201
	iteration_statement : DO M . statement WHILE M '(' exp ')' ';'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 289


state 202
	iteration_statement : FOR '(' . exp_statement M exp_statement M exp ')' M statement
	iteration_statement : FOR '(' . exp_statement M exp_statement ')' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	exp_statement  goto 290


state 203
	jump_statement : GOTO ID . ';'

	';'  shift 291


state 204
	jump_statement : CONTINUE ';' .  (219)

	.  reduce 219


state 205
	jump_statement : BREAK ';' .  (220)

	.  reduce 220


state 206
	jump_statement : RETURN ';' .  (221)

	.  reduce 221


state 207
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 245
	';'  shift 292


state 208
	selection_statement : switch_pre statement .  (212)

	.  reduce 212


state 209
	postfix_exp : postfix_pre_exp ')' .  (10)

	.  reduce 10


state 210
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 293
	','  shift 294


state 211
	argument_exp_list : assignment_exp .  (16)

	.  reduce 16


state 212
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 295


state 213
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 296


state 214
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 297


state 215
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 298


state 216
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 299


state 217
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 300


state 218
	postfix_pre_exp : postfix_exp '(' .  (7)

	.  reduce 7


state 219
	postfix_exp : postfix_exp '.' . ID

	ID  shift 301


state 220
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 302
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 221
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 303


state 222
	postfix_exp : postfix_exp INC_OP .  (14)

	.  reduce 14


state 223
	postfix_exp : postfix_exp DEC_OP .  (15)

	.  reduce 15


state 224
	labeled_statement : default_pre statement .  (194)

	.  reduce 194


state 225
	assignment_operator : '=' .  (66)

	.  reduce 66


state 226
	assignment_operator : MUL_ASSIGN .  (67)

	.  reduce 67


state 227
	assignment_operator : DIV_ASSIGN .  (68)

	.  reduce 68


state 228
	assignment_operator : MOD_ASSIGN .  (69)

	.  reduce 69


state 229
	assignment_operator : ADD_ASSIGN .  (70)

	.  reduce 70


state 230
	assignment_operator : SUB_ASSIGN .  (71)

	.  reduce 71


state 231
	assignment_operator : LEFT_ASSIGN .  (72)

	.  reduce 72


state 232
	assignment_operator : RIGHT_ASSIGN .  (73)

	.  reduce 73


state 233
	assignment_operator : AND_ASSIGN .  (74)

	.  reduce 74


state 234
	assignment_operator : XOR_ASSIGN .  (75)

	.  reduce 75


state 235
	assignment_operator : OR_ASSIGN .  (76)

	.  reduce 76


state 236
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 304
	conditional_exp  goto 141
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 237
	unary_exp : unary_operator cast_exp .  (21)

	.  reduce 21


state 238
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 305
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136


state 239
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 306
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136


state 240
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 307
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136


state 241
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	additive_exp  goto 308
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137


state 242
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 130
	additive_exp  goto 309
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137


state 243
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 310
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 244
	logical_or_exp : logical_or_exp OR_OP . M logical_and_exp
	M : .  (58)

	.  reduce 58

	M  goto 311


state 245
	exp : exp ',' . assignment_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 312
	conditional_exp  goto 141
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 246
	exp_statement : exp ';' .  (204)

	.  reduce 204


state 247
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 313
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138


state 248
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 314
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138


state 249
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	equality_exp  goto 143
	exclusive_or_exp  goto 315
	and_exp  goto 147


state 250
	logical_and_exp : logical_and_exp AND_OP . M inclusive_or_exp
	M : .  (58)

	.  reduce 58

	M  goto 316


state 251
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	equality_exp  goto 143
	and_exp  goto 317


state 252
	and_exp : and_exp '&' . equality_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	equality_exp  goto 318


state 253
	compound_statement : '{' declaration_list '}' .  (197)

	.  reduce 197


state 254
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . M statement
	M : .  (58)

	'}'  shift 319
	.  reduce 58

	M  goto 256


state 255
	compound_statement : '{' statement_list '}' .  (196)

	.  reduce 196


state 256
	statement_list : statement_list M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 320


state 257
	declaration_list : declaration_list M declaration .  (200)

	.  reduce 200


state 258
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (111)

	.  reduce 111


state 259
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . M declaration
	M : .  (58)

	'}'  shift 321
	.  reduce 58

	M  goto 155


state 260
	initializer : '{' . initializer_list ',' '}'
	initializer : '{' . initializer_list '}'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'{'  shift 260
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 261
	conditional_exp  goto 141
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	initializer  goto 322
	initializer_list  goto 323


state 261
	initializer : assignment_exp .  (179)

	.  reduce 179


state 262
	init_declarator : declarator '=' initializer .  (91)

	.  reduce 91


state 263
	init_declarator_list : init_declarator_list ',' init_declarator .  (89)

	.  reduce 89


state 264
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (227)

	.  reduce 227


state 265
	direct_declarator : direct_declarator '[' constant_exp ']' .  (145)

	.  reduce 145


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
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 277
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (122)

	.  reduce 122


state 278
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (124)

	.  reduce 124


state 279
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

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

	struct_or_union  goto 29
	type_specifier  goto 30
	enum_specifier  goto 31
	type_qualifier  goto 32
	struct_or_union_def  goto 33
	declaration_specifiers  goto 49
	storage_class_specifier  goto 36
	struct_or_union_specifier  goto 37
	parameter_type_list  goto 175
	parameter_list  goto 51
	abstract_declarator  goto 176
	direct_abstract_declarator  goto 87
	pointer  goto 281
	parameter_declaration  goto 53


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
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	cast_exp  goto 326
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136


state 283
	labeled_statement : ID ':' statement .  (192)

	.  reduce 192


state 284
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 327


state 285
	labeled_statement : CASE constant_exp ':' . M statement
	M : .  (58)

	.  reduce 58

	M  goto 328


state 286
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp . ')' M stmt
	open_statement : IF '(' exp . ')' M matched_statement N ELSE M open_statement

	')'  shift 329
	','  shift 245


state 287
	exp : exp . ',' assignment_exp
	switch_pre : SWITCH '(' exp . ')'

	')'  shift 330
	','  shift 245


state 288
	iteration_statement : WHILE M '(' . exp ')' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 331
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 289
	iteration_statement : DO M statement . WHILE M '(' exp ')' ';'

	WHILE  shift 332


state 290
	iteration_statement : FOR '(' exp_statement . M exp_statement M exp ')' M statement
	iteration_statement : FOR '(' exp_statement . M exp_statement ')' M statement
	M : .  (58)

	.  reduce 58

	M  goto 333


state 291
	jump_statement : GOTO ID ';' .  (218)

	.  reduce 218


state 292
	jump_statement : RETURN exp ';' .  (222)

	.  reduce 222


state 293
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (11)

	.  reduce 11


state 294
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 334
	conditional_exp  goto 141
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 295
	relational_exp : relational_exp '<' shift_exp .  (43)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 241
	RIGHT_OP  shift 242
	.  reduce 43


state 296
	relational_exp : relational_exp '>' shift_exp .  (44)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 241
	RIGHT_OP  shift 242
	.  reduce 44


state 297
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (45)
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 241
	RIGHT_OP  shift 242
	.  reduce 45


state 298
	relational_exp : relational_exp GE_OP shift_exp .  (46)
	shift_exp : shift_exp . LEFT_OP additive_exp
	shift_exp : shift_exp . RIGHT_OP additive_exp

	LEFT_OP  shift 241
	RIGHT_OP  shift 242
	.  reduce 46


state 299
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (37)
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 238
	'*'  shift 239
	'/'  shift 240
	.  reduce 37


state 300
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (38)
	multiplicative_exp : multiplicative_exp . '/' cast_exp

	'%'  shift 238
	'*'  shift 239
	'/'  shift 240
	.  reduce 38


state 301
	postfix_exp : postfix_exp '.' ID .  (12)

	.  reduce 12


state 302
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 245
	']'  shift 335


state 303
	postfix_exp : postfix_exp PTR_OP ID .  (13)

	.  reduce 13


state 304
	assignment_exp : unary_exp assignment_operator assignment_exp .  (65)

	.  reduce 65


state 305
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (35)

	.  reduce 35


state 306
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (33)

	.  reduce 33


state 307
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (34)

	.  reduce 34


state 308
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp LEFT_OP additive_exp .  (40)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 216
	'-'  shift 217
	.  reduce 40


state 309
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : shift_exp RIGHT_OP additive_exp .  (41)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 216
	'-'  shift 217
	.  reduce 41


state 310
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 245
	':'  shift 336


state 311
	logical_or_exp : logical_or_exp OR_OP M . logical_and_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 337
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 312
	exp : exp ',' assignment_exp .  (78)

	.  reduce 78


state 313
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (48)

	'<'  shift 212
	'>'  shift 213
	LE_OP  shift 214
	GE_OP  shift 215
	.  reduce 48


state 314
	relational_exp : relational_exp . GE_OP shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (49)
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 212
	'>'  shift 213
	LE_OP  shift 214
	GE_OP  shift 215
	.  reduce 49


state 315
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (55)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 251
	.  reduce 55


state 316
	logical_and_exp : logical_and_exp AND_OP M . inclusive_or_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	equality_exp  goto 143
	inclusive_or_exp  goto 338
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 317
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (53)

	'&'  shift 252
	.  reduce 53


state 318
	and_exp : and_exp '&' equality_exp .  (51)
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp

	EQ_OP  shift 247
	NE_OP  shift 248
	.  reduce 51


state 319
	compound_statement : '{' declaration_list statement_list '}' .  (198)

	.  reduce 198


state 320
	statement_list : statement_list M statement .  (202)

	.  reduce 202


state 321
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (110)

	.  reduce 110


state 322
	initializer_list : initializer .  (182)

	.  reduce 182


state 323
	initializer : '{' initializer_list . ',' '}'
	initializer : '{' initializer_list . '}'
	initializer_list : initializer_list . ',' initializer

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
	labeled_statement : CASE constant_exp ':' M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 341


state 329
	matched_statement : IF '(' exp ')' . M matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' . M stmt
	open_statement : IF '(' exp ')' . M matched_statement N ELSE M open_statement
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
	','  shift 245


state 332
	iteration_statement : DO M statement WHILE . M '(' exp ')' ';'
	M : .  (58)

	.  reduce 58

	M  goto 344


state 333
	iteration_statement : FOR '(' exp_statement M . exp_statement M exp ')' M statement
	iteration_statement : FOR '(' exp_statement M . exp_statement ')' M statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	exp_statement  goto 345


state 334
	argument_exp_list : argument_exp_list ',' assignment_exp .  (17)

	.  reduce 17


state 335
	postfix_exp : postfix_exp '[' exp ']' .  (9)

	.  reduce 9


state 336
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 167
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	conditional_exp  goto 346
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


state 337
	logical_and_exp : logical_and_exp . AND_OP M inclusive_or_exp
	logical_or_exp : logical_or_exp OR_OP M logical_and_exp .  (61)

	AND_OP  shift 250
	.  reduce 61


state 338
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : logical_and_exp AND_OP M inclusive_or_exp .  (57)

	'|'  shift 249
	.  reduce 57


state 339
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'{'  shift 260
	'}'  shift 347
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 261
	conditional_exp  goto 141
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	initializer  goto 348


state 340
	initializer : '{' initializer_list '}' .  (180)

	.  reduce 180


state 341
	labeled_statement : CASE constant_exp ':' M statement .  (193)

	.  reduce 193


state 342
	matched_statement : IF '(' exp ')' M . matched_statement N ELSE M matched_statement
	open_statement : IF '(' exp ')' M . stmt
	open_statement : IF '(' exp ')' M . matched_statement N ELSE M open_statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	IF  shift 112
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116

	other  goto 349
	matched_statement  goto 350
	open_statement  goto 125
	stmt  goto 351
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152


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

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 357


state 353
	iteration_statement : DO M statement WHILE M '(' . exp ')' ';'

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 358
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


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
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109

	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 360
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147


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
	','  shift 245


state 359
	iteration_statement : FOR '(' exp_statement M exp_statement ')' M . statement

	'!'  shift 93
	'&'  shift 94
	'('  shift 95
	'*'  shift 96
	'+'  shift 97
	'-'  shift 98
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 363


state 360
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement M exp_statement M exp . ')' M statement

	')'  shift 364
	','  shift 245


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
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 166
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	IF  shift 112
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116

	other  goto 349
	matched_statement  goto 368
	open_statement  goto 369
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152


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
	';'  shift 99
	'{'  shift 54
	'~'  shift 101
	ID  shift 102
	CONSTANT  shift 103
	STRING_LITERAL  shift 104
	SIZEOF  shift 105
	INC_OP  shift 106
	DEC_OP  shift 107
	TRUE  shift 108
	FALSE  shift 109
	CASE  shift 110
	DEFAULT  shift 111
	IF  shift 112
	SWITCH  shift 113
	WHILE  shift 114
	DO  shift 115
	FOR  shift 116
	GOTO  shift 117
	CONTINUE  shift 118
	BREAK  shift 119
	RETURN  shift 120

	selection_statement  goto 121
	other  goto 122
	matched_statement  goto 123
	switch_pre  goto 124
	open_statement  goto 125
	stmt  goto 126
	jump_statement  goto 127
	postfix_pre_exp  goto 128
	relational_exp  goto 129
	cast_exp  goto 130
	additive_exp  goto 131
	primary_exp  goto 132
	postfix_exp  goto 133
	default_pre  goto 134
	unary_exp  goto 135
	unary_operator  goto 136
	multiplicative_exp  goto 137
	shift_exp  goto 138
	logical_or_exp  goto 139
	assignment_exp  goto 140
	conditional_exp  goto 141
	exp  goto 142
	equality_exp  goto 143
	inclusive_or_exp  goto 144
	logical_and_exp  goto 145
	exclusive_or_exp  goto 146
	and_exp  goto 147
	labeled_statement  goto 148
	compound_statement  goto 149
	exp_statement  goto 151
	iteration_statement  goto 152
	statement  goto 370


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
State 30 contains 1 shift-reduce conflict(s)
State 43 contains 3 shift-reduce conflict(s)
State 122 contains 30 reduce-reduce conflict(s)
State 186 contains 1 shift-reduce conflict(s)
State 350 contains 1 reduce-reduce conflict(s)


86 token(s), 76 nonterminal(s)
231 grammar rule(s), 371 state(s)


##############################################################################
# End of File
##############################################################################
