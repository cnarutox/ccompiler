#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 63 of your 30 day trial period.
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
# Date: 12/11/18
# Time: 23:25:29
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
   77              | ID ID ';'

   78  declaration_specifiers : storage_class_specifier
   79                         | storage_class_specifier declaration_specifiers
   80                         | type_specifier
   81                         | type_specifier declaration_specifiers
   82                         | type_qualifier
   83                         | type_qualifier declaration_specifiers

   84  init_declarator_list : init_declarator
   85                       | init_declarator_list ',' init_declarator

   86  init_declarator : declarator
   87                  | declarator '=' initializer

   88  storage_class_specifier : TYPEDEF
   89                          | EXTERN
   90                          | STATIC
   91                          | AUTO
   92                          | REGISTER

   93  type_specifier : VOID
   94                 | CHAR
   95                 | SHORT
   96                 | INT
   97                 | LONG
   98                 | FLOAT
   99                 | DOUBLE
  100                 | SIGNED
  101                 | UNSIGNED
  102                 | struct_or_union_specifier
  103                 | enum_specifier
  104                 | TYPE_NAME

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
  175              |

  176  initializer_list : initializer
  177                   | initializer_list ',' initializer

  178  other : labeled_statement
  179        | compound_statement
  180        | exp_statement
  181        | iteration_statement
  182        | jump_statement

  183  statement : labeled_statement
  184            | compound_statement
  185            | exp_statement
  186            | selection_statement
  187            | iteration_statement
  188            | jump_statement

  189  labeled_statement : ID ':' statement
  190                    | CASE constant_exp ':' statement
  191                    | DEFAULT ':' statement

  192  compound_statement : '{' '}'
  193                     | '{' statement_list '}'
  194                     | '{' declaration_list '}'
  195                     | '{' declaration_list statement_list '}'

  196  declaration_list : declaration
  197                   | declaration_list declaration

  198  statement_list : statement
  199                 | statement_list statement

  200  exp_statement : ';'
  201                | exp ';'

  202  stmt : matched_statement
  203       | open_statement

  204  matched_statement : IF '(' exp ')' matched_statement ELSE matched_statement
  205                    | other

  206  open_statement : IF '(' exp ')' stmt
  207                 | IF '(' exp ')' matched_statement ELSE open_statement

  208  selection_statement : stmt
  209                      | SWITCH '(' exp ')' statement

  210  iteration_statement : WHILE '(' exp ')' statement
  211                      | DO statement WHILE '(' exp ')' ';'
  212                      | FOR '(' exp_statement exp_statement ')' statement
  213                      | FOR '(' exp_statement exp_statement exp ')' statement

  214  jump_statement : GOTO ID ';'
  215                 | CONTINUE ';'
  216                 | BREAK ';'
  217                 | RETURN ';'
  218                 | RETURN exp ';'

  219  translation_unit : external_declaration
  220                   | translation_unit external_declaration

  221  external_declaration : function_definition
  222                       | declaration

  223  function_definition : declaration_specifiers declarator declaration_list compound_statement
  224                      | declaration_specifiers declarator compound_statement
  225                      | declarator declaration_list compound_statement
  226                      | declarator compound_statement


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

	pointer  goto 24
	declaration  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 27
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declarator  goto 33
	direct_declarator  goto 34
	external_declaration  goto 35
	function_definition  goto 36
	translation_unit  goto 37


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 38

	pointer  goto 24
	declarator  goto 39
	direct_declarator  goto 34


state 2
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' .  (143)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 143

	pointer  goto 40
	type_qualifier  goto 41
	type_qualifier_list  goto 42


3: shift-reduce conflict (shift 43, reduce 136) on ID
state 3
	declaration : ID . ID ';'
	direct_declarator : ID .  (136)

	ID  shift 43
	.  reduce 136


state 4
	type_specifier : TYPE_NAME .  (104)

	.  reduce 104


state 5
	storage_class_specifier : TYPEDEF .  (88)

	.  reduce 88


state 6
	storage_class_specifier : EXTERN .  (89)

	.  reduce 89


state 7
	storage_class_specifier : STATIC .  (90)

	.  reduce 90


state 8
	storage_class_specifier : AUTO .  (91)

	.  reduce 91


state 9
	storage_class_specifier : REGISTER .  (92)

	.  reduce 92


state 10
	type_specifier : CHAR .  (94)

	.  reduce 94


state 11
	type_specifier : SHORT .  (95)

	.  reduce 95


state 12
	type_specifier : INT .  (96)

	.  reduce 96


state 13
	type_specifier : LONG .  (97)

	.  reduce 97


state 14
	type_specifier : SIGNED .  (100)

	.  reduce 100


state 15
	type_specifier : UNSIGNED .  (101)

	.  reduce 101


state 16
	type_specifier : FLOAT .  (98)

	.  reduce 98


state 17
	type_specifier : DOUBLE .  (99)

	.  reduce 99


state 18
	type_qualifier : CONST .  (132)

	.  reduce 132


state 19
	type_qualifier : VOLATILE .  (133)

	.  reduce 133


state 20
	type_specifier : VOID .  (93)

	.  reduce 93


state 21
	struct_or_union : STRUCT .  (110)

	.  reduce 110


state 22
	struct_or_union : UNION .  (111)

	.  reduce 111


state 23
	enum_specifier : ENUM . ID
	enum_specifier : ENUM . ID '{' enumerator_list '}'
	enum_specifier : ENUM . '{' enumerator_list '}'

	'{'  shift 44
	ID  shift 45


state 24
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 38

	direct_declarator  goto 46


state 25
	external_declaration : declaration .  (222)

	.  reduce 222


state 26
	declaration_specifiers : type_specifier .  (80)
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
	.  reduce 80

	type_specifier  goto 26
	declaration_specifiers  goto 47
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32


state 27
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'
	function_definition : declaration_specifiers . declarator declaration_list compound_statement
	function_definition : declaration_specifiers . declarator compound_statement

	'('  shift 1
	'*'  shift 2
	';'  shift 48
	ID  shift 38

	init_declarator  goto 49
	pointer  goto 24
	init_declarator_list  goto 50
	declarator  goto 51
	direct_declarator  goto 34


state 28
	struct_or_union_specifier : struct_or_union . '{' declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union . ID '{' declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_specifier : struct_or_union . '{' declaration_list '}' ';'
	struct_or_union_specifier : struct_or_union . ID '{' declaration_list '}' ';'

	'{'  shift 52
	ID  shift 53


state 29
	type_specifier : enum_specifier .  (103)

	.  reduce 103


state 30
	type_specifier : struct_or_union_specifier .  (102)

	.  reduce 102


state 31
	declaration_specifiers : storage_class_specifier . declaration_specifiers
	declaration_specifiers : storage_class_specifier .  (78)

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
	.  reduce 78

	type_specifier  goto 26
	declaration_specifiers  goto 54
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32


state 32
	declaration_specifiers : type_qualifier . declaration_specifiers
	declaration_specifiers : type_qualifier .  (82)

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

	type_specifier  goto 26
	declaration_specifiers  goto 55
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32


state 33
	function_definition : declarator . compound_statement
	function_definition : declarator . declaration_list compound_statement

	'{'  shift 56
	ID  shift 57
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

	declaration  goto 58
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declaration_list  goto 60
	compound_statement  goto 61


state 34
	declarator : direct_declarator .  (135)
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 62
	'['  shift 63
	.  reduce 135


state 35
	translation_unit : external_declaration .  (219)

	.  reduce 219


state 36
	external_declaration : function_definition .  (221)

	.  reduce 221


state 37
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

	pointer  goto 24
	declaration  goto 25
	type_specifier  goto 26
	declaration_specifiers  goto 27
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declarator  goto 33
	direct_declarator  goto 34
	external_declaration  goto 64
	function_definition  goto 36


state 38
	direct_declarator : ID .  (136)

	.  reduce 136


state 39
	direct_declarator : '(' declarator . ')'

	')'  shift 65


state 40
	pointer : '*' pointer .  (145)

	.  reduce 145


state 41
	type_qualifier_list : type_qualifier .  (147)

	.  reduce 147


state 42
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list . pointer
	pointer : '*' type_qualifier_list .  (144)

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 144

	pointer  goto 66
	type_qualifier  goto 67


state 43
	declaration : ID ID . ';'

	';'  shift 68


state 44
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 69

	enumerator  goto 70
	enumerator_list  goto 71


state 45
	enum_specifier : ENUM ID .  (127)
	enum_specifier : ENUM ID . '{' enumerator_list '}'

	'{'  shift 72
	.  reduce 127


state 46
	declarator : pointer direct_declarator .  (134)
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '(' ')'
	direct_declarator : direct_declarator . '(' parameter_type_list ')'
	direct_declarator : direct_declarator . '(' identifier_list ')'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 62
	'['  shift 63
	.  reduce 134


state 47
	declaration_specifiers : type_specifier declaration_specifiers .  (81)

	.  reduce 81


state 48
	declaration : declaration_specifiers ';' .  (75)

	.  reduce 75


state 49
	init_declarator_list : init_declarator .  (84)

	.  reduce 84


state 50
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 73
	';'  shift 74


state 51
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (86)
	function_definition : declaration_specifiers declarator . declaration_list compound_statement
	function_definition : declaration_specifiers declarator . compound_statement

	'='  shift 75
	'{'  shift 56
	ID  shift 57
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

	declaration  goto 58
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declaration_list  goto 76
	compound_statement  goto 77


state 52
	struct_or_union_specifier : struct_or_union '{' . declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union '{' . declaration_list '}' ';'

	ID  shift 57
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

	declaration  goto 58
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declaration_list  goto 78


state 53
	struct_or_union_specifier : struct_or_union ID . '{' declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID .  (109)
	struct_or_union_specifier : struct_or_union ID . '{' declaration_list '}' ';'

	'{'  shift 79
	.  reduce 109


state 54
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (79)

	.  reduce 79


state 55
	declaration_specifiers : type_qualifier declaration_specifiers .  (83)

	.  reduce 83


state 56
	compound_statement : '{' . '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . declaration_list '}'
	compound_statement : '{' . declaration_list statement_list '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'}'  shift 87
	'~'  shift 88
	ID  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	declaration  goto 58
	conditional_exp  goto 123
	assignment_exp  goto 124
	type_specifier  goto 26
	inclusive_or_exp  goto 125
	declaration_specifiers  goto 59
	logical_and_exp  goto 126
	exp  goto 127
	struct_or_union  goto 28
	enum_specifier  goto 29
	logical_or_exp  goto 128
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declaration_list  goto 129
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	statement_list  goto 133
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 136


state 57
	declaration : ID . ID ';'

	ID  shift 43


state 58
	declaration_list : declaration .  (196)

	.  reduce 196


state 59
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 48
	ID  shift 38

	init_declarator  goto 49
	pointer  goto 24
	init_declarator_list  goto 50
	declarator  goto 137
	direct_declarator  goto 34


state 60
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

	'{'  shift 56
	ID  shift 57
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

	declaration  goto 138
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	compound_statement  goto 139


state 61
	function_definition : declarator compound_statement .  (226)

	.  reduce 226


state 62
	direct_declarator : direct_declarator '(' . ')'
	direct_declarator : direct_declarator '(' . parameter_type_list ')'
	direct_declarator : direct_declarator '(' . identifier_list ')'

	')'  shift 140
	ID  shift 141
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

	parameter_list  goto 142
	type_specifier  goto 26
	declaration_specifiers  goto 143
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	parameter_type_list  goto 144
	parameter_declaration  goto 145
	identifier_list  goto 146


state 63
	direct_declarator : direct_declarator '[' . constant_exp ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	']'  shift 147
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 150
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	constant_exp  goto 151
	logical_or_exp  goto 128


state 64
	translation_unit : translation_unit external_declaration .  (220)

	.  reduce 220


state 65
	direct_declarator : '(' declarator ')' .  (137)

	.  reduce 137


state 66
	pointer : '*' type_qualifier_list pointer .  (146)

	.  reduce 146


state 67
	type_qualifier_list : type_qualifier_list type_qualifier .  (148)

	.  reduce 148


state 68
	declaration : ID ID ';' .  (77)

	.  reduce 77


state 69
	enumerator : ID . '=' constant_exp
	enumerator : ID .  (130)

	'='  shift 152
	.  reduce 130


state 70
	enumerator_list : enumerator .  (128)

	.  reduce 128


state 71
	enumerator_list : enumerator_list . ',' enumerator
	enum_specifier : ENUM '{' enumerator_list . '}'

	','  shift 153
	'}'  shift 154


state 72
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 69

	enumerator  goto 70
	enumerator_list  goto 155


state 73
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 38

	init_declarator  goto 156
	pointer  goto 24
	declarator  goto 137
	direct_declarator  goto 34


state 74
	declaration : declaration_specifiers init_declarator_list ';' .  (76)

	.  reduce 76


state 75
	init_declarator : declarator '=' . initializer
	initializer : .  (175)

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'{'  shift 157
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	.  reduce 175

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 158
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128
	initializer  goto 159


state 76
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

	'{'  shift 56
	ID  shift 57
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

	declaration  goto 138
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	compound_statement  goto 160


state 77
	function_definition : declaration_specifiers declarator compound_statement .  (224)

	.  reduce 224


state 78
	struct_or_union_specifier : struct_or_union '{' declaration_list . '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union '{' declaration_list . '}' ';'
	declaration_list : declaration_list . declaration

	'}'  shift 161
	ID  shift 57
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

	declaration  goto 138
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32


state 79
	struct_or_union_specifier : struct_or_union ID '{' . declaration_list '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID '{' . declaration_list '}' ';'

	ID  shift 57
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

	declaration  goto 58
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declaration_list  goto 162


state 80
	unary_operator : '!' .  (26)

	.  reduce 26


state 81
	unary_operator : '&' .  (21)

	.  reduce 21


state 82
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	type_specifier  goto 163
	inclusive_or_exp  goto 125
	specifier_qualifier_list  goto 164
	logical_and_exp  goto 126
	exp  goto 165
	struct_or_union  goto 28
	enum_specifier  goto 29
	logical_or_exp  goto 128
	struct_or_union_specifier  goto 30
	type_qualifier  goto 166
	type_name  goto 167


state 83
	unary_operator : '*' .  (22)

	.  reduce 22


state 84
	unary_operator : '+' .  (23)

	.  reduce 23


state 85
	unary_operator : '-' .  (24)

	.  reduce 24


state 86
	exp_statement : ';' .  (200)

	.  reduce 200


state 87
	compound_statement : '{' '}' .  (192)

	.  reduce 192


state 88
	unary_operator : '~' .  (25)

	.  reduce 25


state 89
	declaration : ID . ID ';'
	labeled_statement : ID . ':' statement
	primary_exp : ID .  (1)

	':'  shift 168
	ID  shift 43
	.  reduce 1


state 90
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 91
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 92
	unary_exp : SIZEOF . unary_exp
	unary_exp : SIZEOF . '(' type_name ')'

	'!'  shift 80
	'&'  shift 81
	'('  shift 169
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 170
	unary_operator  goto 112
	postfix_exp  goto 119
	primary_exp  goto 121


state 93
	unary_exp : INC_OP . unary_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 171
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 172
	unary_operator  goto 112
	postfix_exp  goto 119
	primary_exp  goto 121


state 94
	unary_exp : DEC_OP . unary_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 171
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 173
	unary_operator  goto 112
	postfix_exp  goto 119
	primary_exp  goto 121


state 95
	labeled_statement : CASE . constant_exp ':' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 150
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	constant_exp  goto 174
	logical_or_exp  goto 128


state 96
	labeled_statement : DEFAULT . ':' statement

	':'  shift 175


state 97
	matched_statement : IF . '(' exp ')' matched_statement ELSE matched_statement
	open_statement : IF . '(' exp ')' stmt
	open_statement : IF . '(' exp ')' matched_statement ELSE open_statement

	'('  shift 176


state 98
	selection_statement : SWITCH . '(' exp ')' statement

	'('  shift 177


state 99
	iteration_statement : WHILE . '(' exp ')' statement

	'('  shift 178


state 100
	iteration_statement : DO . statement WHILE '(' exp ')' ';'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 180


state 101
	iteration_statement : FOR . '(' exp_statement exp_statement ')' statement
	iteration_statement : FOR . '(' exp_statement exp_statement exp ')' statement

	'('  shift 181


state 102
	jump_statement : GOTO . ID ';'

	ID  shift 182


state 103
	jump_statement : CONTINUE . ';'

	';'  shift 183


state 104
	jump_statement : BREAK . ';'

	';'  shift 184


state 105
	jump_statement : RETURN . ';'
	jump_statement : RETURN . exp ';'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 185
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 186
	logical_or_exp  goto 128


state 106
	statement : selection_statement .  (186)

	.  reduce 186


state 107
	matched_statement : other .  (205)

	.  reduce 205


state 108
	stmt : matched_statement .  (202)

	.  reduce 202


state 109
	selection_statement : stmt .  (208)

	.  reduce 208


state 110
	stmt : open_statement .  (203)

	.  reduce 203


state 111
	cast_exp : unary_exp .  (27)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 187
	MUL_ASSIGN  shift 188
	DIV_ASSIGN  shift 189
	MOD_ASSIGN  shift 190
	ADD_ASSIGN  shift 191
	SUB_ASSIGN  shift 192
	LEFT_ASSIGN  shift 193
	RIGHT_ASSIGN  shift 194
	AND_ASSIGN  shift 195
	XOR_ASSIGN  shift 196
	OR_ASSIGN  shift 197
	.  reduce 27

	assignment_operator  goto 198


state 112
	unary_exp : unary_operator . cast_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 199
	postfix_exp  goto 119
	primary_exp  goto 121


state 113
	multiplicative_exp : cast_exp .  (29)

	.  reduce 29


state 114
	additive_exp : additive_exp . '+' multiplicative_exp
	additive_exp : additive_exp . '-' multiplicative_exp
	shift_exp : additive_exp .  (36)

	'+'  shift 200
	'-'  shift 201
	.  reduce 36


state 115
	relational_exp : shift_exp .  (39)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 202
	RIGHT_OP  shift 203
	.  reduce 39


state 116
	equality_exp : relational_exp .  (44)
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp

	'<'  shift 204
	'>'  shift 205
	LE_OP  shift 206
	GE_OP  shift 207
	.  reduce 44


state 117
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : equality_exp .  (47)

	EQ_OP  shift 208
	NE_OP  shift 209
	.  reduce 47


state 118
	exclusive_or_exp : and_exp .  (49)
	and_exp : and_exp . '&' equality_exp

	'&'  shift 210
	.  reduce 49


state 119
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '(' ')'
	postfix_exp : postfix_exp . '(' argument_exp_list ')'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (15)

	'('  shift 211
	'.'  shift 212
	'['  shift 213
	PTR_OP  shift 214
	INC_OP  shift 215
	DEC_OP  shift 216
	.  reduce 15


state 120
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : multiplicative_exp .  (33)

	'%'  shift 217
	'*'  shift 218
	'/'  shift 219
	.  reduce 33


state 121
	postfix_exp : primary_exp .  (5)

	.  reduce 5


state 122
	inclusive_or_exp : exclusive_or_exp .  (51)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 220
	.  reduce 51


state 123
	assignment_exp : conditional_exp .  (59)

	.  reduce 59


state 124
	exp : assignment_exp .  (72)

	.  reduce 72


state 125
	logical_and_exp : inclusive_or_exp .  (53)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 221
	.  reduce 53


state 126
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp
	logical_or_exp : logical_and_exp .  (55)

	AND_OP  shift 222
	.  reduce 55


state 127
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 223
	';'  shift 224


state 128
	conditional_exp : logical_or_exp .  (57)
	logical_or_exp : logical_or_exp . OR_OP logical_and_exp
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp

	'?'  shift 225
	OR_OP  shift 226
	.  reduce 57


state 129
	declaration_list : declaration_list . declaration
	compound_statement : '{' declaration_list . '}'
	compound_statement : '{' declaration_list . statement_list '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'}'  shift 227
	'~'  shift 88
	ID  shift 89
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	declaration  goto 138
	conditional_exp  goto 123
	assignment_exp  goto 124
	type_specifier  goto 26
	inclusive_or_exp  goto 125
	declaration_specifiers  goto 59
	logical_and_exp  goto 126
	exp  goto 127
	struct_or_union  goto 28
	enum_specifier  goto 29
	logical_or_exp  goto 128
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	statement_list  goto 228
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 136


130: reduce-reduce conflict (reduce 182, reduce 188) on '!'
130: reduce-reduce conflict (reduce 182, reduce 188) on '&'
130: reduce-reduce conflict (reduce 182, reduce 188) on '('
130: reduce-reduce conflict (reduce 182, reduce 188) on '*'
130: reduce-reduce conflict (reduce 182, reduce 188) on '+'
130: reduce-reduce conflict (reduce 182, reduce 188) on '-'
130: reduce-reduce conflict (reduce 182, reduce 188) on ';'
130: reduce-reduce conflict (reduce 182, reduce 188) on '{'
130: reduce-reduce conflict (reduce 182, reduce 188) on '}'
130: reduce-reduce conflict (reduce 182, reduce 188) on '~'
130: reduce-reduce conflict (reduce 182, reduce 188) on ID
130: reduce-reduce conflict (reduce 182, reduce 188) on CONSTANT
130: reduce-reduce conflict (reduce 182, reduce 188) on STRING_LITERAL
130: reduce-reduce conflict (reduce 182, reduce 188) on SIZEOF
130: reduce-reduce conflict (reduce 182, reduce 188) on INC_OP
130: reduce-reduce conflict (reduce 182, reduce 188) on DEC_OP
130: reduce-reduce conflict (reduce 182, reduce 188) on CASE
130: reduce-reduce conflict (reduce 182, reduce 188) on DEFAULT
130: reduce-reduce conflict (reduce 182, reduce 188) on IF
130: reduce-reduce conflict (reduce 182, reduce 188) on ELSE
130: reduce-reduce conflict (reduce 182, reduce 188) on SWITCH
130: reduce-reduce conflict (reduce 182, reduce 188) on WHILE
130: reduce-reduce conflict (reduce 182, reduce 188) on DO
130: reduce-reduce conflict (reduce 182, reduce 188) on FOR
130: reduce-reduce conflict (reduce 182, reduce 188) on GOTO
130: reduce-reduce conflict (reduce 182, reduce 188) on CONTINUE
130: reduce-reduce conflict (reduce 182, reduce 188) on BREAK
130: reduce-reduce conflict (reduce 182, reduce 188) on RETURN
state 130
	other : jump_statement .  (182)
	statement : jump_statement .  (188)

	.  reduce 182


131: reduce-reduce conflict (reduce 179, reduce 184) on '!'
131: reduce-reduce conflict (reduce 179, reduce 184) on '&'
131: reduce-reduce conflict (reduce 179, reduce 184) on '('
131: reduce-reduce conflict (reduce 179, reduce 184) on '*'
131: reduce-reduce conflict (reduce 179, reduce 184) on '+'
131: reduce-reduce conflict (reduce 179, reduce 184) on '-'
131: reduce-reduce conflict (reduce 179, reduce 184) on ';'
131: reduce-reduce conflict (reduce 179, reduce 184) on '{'
131: reduce-reduce conflict (reduce 179, reduce 184) on '}'
131: reduce-reduce conflict (reduce 179, reduce 184) on '~'
131: reduce-reduce conflict (reduce 179, reduce 184) on ID
131: reduce-reduce conflict (reduce 179, reduce 184) on CONSTANT
131: reduce-reduce conflict (reduce 179, reduce 184) on STRING_LITERAL
131: reduce-reduce conflict (reduce 179, reduce 184) on SIZEOF
131: reduce-reduce conflict (reduce 179, reduce 184) on INC_OP
131: reduce-reduce conflict (reduce 179, reduce 184) on DEC_OP
131: reduce-reduce conflict (reduce 179, reduce 184) on CASE
131: reduce-reduce conflict (reduce 179, reduce 184) on DEFAULT
131: reduce-reduce conflict (reduce 179, reduce 184) on IF
131: reduce-reduce conflict (reduce 179, reduce 184) on ELSE
131: reduce-reduce conflict (reduce 179, reduce 184) on SWITCH
131: reduce-reduce conflict (reduce 179, reduce 184) on WHILE
131: reduce-reduce conflict (reduce 179, reduce 184) on DO
131: reduce-reduce conflict (reduce 179, reduce 184) on FOR
131: reduce-reduce conflict (reduce 179, reduce 184) on GOTO
131: reduce-reduce conflict (reduce 179, reduce 184) on CONTINUE
131: reduce-reduce conflict (reduce 179, reduce 184) on BREAK
131: reduce-reduce conflict (reduce 179, reduce 184) on RETURN
state 131
	statement : compound_statement .  (184)
	other : compound_statement .  (179)

	.  reduce 179


132: reduce-reduce conflict (reduce 180, reduce 185) on '!'
132: reduce-reduce conflict (reduce 180, reduce 185) on '&'
132: reduce-reduce conflict (reduce 180, reduce 185) on '('
132: reduce-reduce conflict (reduce 180, reduce 185) on '*'
132: reduce-reduce conflict (reduce 180, reduce 185) on '+'
132: reduce-reduce conflict (reduce 180, reduce 185) on '-'
132: reduce-reduce conflict (reduce 180, reduce 185) on ';'
132: reduce-reduce conflict (reduce 180, reduce 185) on '{'
132: reduce-reduce conflict (reduce 180, reduce 185) on '}'
132: reduce-reduce conflict (reduce 180, reduce 185) on '~'
132: reduce-reduce conflict (reduce 180, reduce 185) on ID
132: reduce-reduce conflict (reduce 180, reduce 185) on CONSTANT
132: reduce-reduce conflict (reduce 180, reduce 185) on STRING_LITERAL
132: reduce-reduce conflict (reduce 180, reduce 185) on SIZEOF
132: reduce-reduce conflict (reduce 180, reduce 185) on INC_OP
132: reduce-reduce conflict (reduce 180, reduce 185) on DEC_OP
132: reduce-reduce conflict (reduce 180, reduce 185) on CASE
132: reduce-reduce conflict (reduce 180, reduce 185) on DEFAULT
132: reduce-reduce conflict (reduce 180, reduce 185) on IF
132: reduce-reduce conflict (reduce 180, reduce 185) on ELSE
132: reduce-reduce conflict (reduce 180, reduce 185) on SWITCH
132: reduce-reduce conflict (reduce 180, reduce 185) on WHILE
132: reduce-reduce conflict (reduce 180, reduce 185) on DO
132: reduce-reduce conflict (reduce 180, reduce 185) on FOR
132: reduce-reduce conflict (reduce 180, reduce 185) on GOTO
132: reduce-reduce conflict (reduce 180, reduce 185) on CONTINUE
132: reduce-reduce conflict (reduce 180, reduce 185) on BREAK
132: reduce-reduce conflict (reduce 180, reduce 185) on RETURN
state 132
	statement : exp_statement .  (185)
	other : exp_statement .  (180)

	.  reduce 180


state 133
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'}'  shift 229
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 230


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
	other : iteration_statement .  (181)
	statement : iteration_statement .  (187)

	.  reduce 181


135: reduce-reduce conflict (reduce 178, reduce 183) on '!'
135: reduce-reduce conflict (reduce 178, reduce 183) on '&'
135: reduce-reduce conflict (reduce 178, reduce 183) on '('
135: reduce-reduce conflict (reduce 178, reduce 183) on '*'
135: reduce-reduce conflict (reduce 178, reduce 183) on '+'
135: reduce-reduce conflict (reduce 178, reduce 183) on '-'
135: reduce-reduce conflict (reduce 178, reduce 183) on ';'
135: reduce-reduce conflict (reduce 178, reduce 183) on '{'
135: reduce-reduce conflict (reduce 178, reduce 183) on '}'
135: reduce-reduce conflict (reduce 178, reduce 183) on '~'
135: reduce-reduce conflict (reduce 178, reduce 183) on ID
135: reduce-reduce conflict (reduce 178, reduce 183) on CONSTANT
135: reduce-reduce conflict (reduce 178, reduce 183) on STRING_LITERAL
135: reduce-reduce conflict (reduce 178, reduce 183) on SIZEOF
135: reduce-reduce conflict (reduce 178, reduce 183) on INC_OP
135: reduce-reduce conflict (reduce 178, reduce 183) on DEC_OP
135: reduce-reduce conflict (reduce 178, reduce 183) on CASE
135: reduce-reduce conflict (reduce 178, reduce 183) on DEFAULT
135: reduce-reduce conflict (reduce 178, reduce 183) on IF
135: reduce-reduce conflict (reduce 178, reduce 183) on ELSE
135: reduce-reduce conflict (reduce 178, reduce 183) on SWITCH
135: reduce-reduce conflict (reduce 178, reduce 183) on WHILE
135: reduce-reduce conflict (reduce 178, reduce 183) on DO
135: reduce-reduce conflict (reduce 178, reduce 183) on FOR
135: reduce-reduce conflict (reduce 178, reduce 183) on GOTO
135: reduce-reduce conflict (reduce 178, reduce 183) on CONTINUE
135: reduce-reduce conflict (reduce 178, reduce 183) on BREAK
135: reduce-reduce conflict (reduce 178, reduce 183) on RETURN
state 135
	statement : labeled_statement .  (183)
	other : labeled_statement .  (178)

	.  reduce 178


state 136
	statement_list : statement .  (198)

	.  reduce 198


state 137
	init_declarator : declarator . '=' initializer
	init_declarator : declarator .  (86)

	'='  shift 75
	.  reduce 86


state 138
	declaration_list : declaration_list declaration .  (197)

	.  reduce 197


state 139
	function_definition : declarator declaration_list compound_statement .  (225)

	.  reduce 225


state 140
	direct_declarator : direct_declarator '(' ')' .  (142)

	.  reduce 142


state 141
	identifier_list : ID .  (156)

	.  reduce 156


state 142
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_type_list : parameter_list .  (149)
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 231
	.  reduce 149


state 143
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers .  (155)

	'('  shift 232
	'*'  shift 2
	'['  shift 233
	ID  shift 38
	.  reduce 155

	pointer  goto 234
	declarator  goto 235
	direct_declarator  goto 34
	direct_abstract_declarator  goto 236
	abstract_declarator  goto 237


state 144
	direct_declarator : direct_declarator '(' parameter_type_list . ')'

	')'  shift 238


state 145
	parameter_list : parameter_declaration .  (151)

	.  reduce 151


state 146
	identifier_list : identifier_list . ',' ID
	direct_declarator : direct_declarator '(' identifier_list . ')'

	')'  shift 239
	','  shift 240


state 147
	direct_declarator : direct_declarator '[' ']' .  (139)

	.  reduce 139


state 148
	primary_exp : ID .  (1)

	.  reduce 1


state 149
	cast_exp : unary_exp .  (27)

	.  reduce 27


state 150
	constant_exp : conditional_exp .  (74)

	.  reduce 74


state 151
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 241


state 152
	enumerator : ID '=' . constant_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 150
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	constant_exp  goto 242
	logical_or_exp  goto 128


state 153
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 69

	enumerator  goto 243


state 154
	enum_specifier : ENUM '{' enumerator_list '}' .  (125)

	.  reduce 125


state 155
	enum_specifier : ENUM ID '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 153
	'}'  shift 244


state 156
	init_declarator_list : init_declarator_list ',' init_declarator .  (85)

	.  reduce 85


state 157
	initializer : '{' . initializer_list '}'
	initializer : '{' . initializer_list ',' '}'
	initializer : .  (175)

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'{'  shift 157
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	.  reduce 175

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 158
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128
	initializer  goto 245
	initializer_list  goto 246


state 158
	initializer : assignment_exp .  (172)

	.  reduce 172


state 159
	init_declarator : declarator '=' initializer .  (87)

	.  reduce 87


state 160
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (223)

	.  reduce 223


state 161
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' . init_declarator_list ';'
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 247
	ID  shift 38

	init_declarator  goto 49
	pointer  goto 24
	init_declarator_list  goto 248
	declarator  goto 137
	direct_declarator  goto 34


state 162
	struct_or_union_specifier : struct_or_union ID '{' declaration_list . '}' init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID '{' declaration_list . '}' ';'
	declaration_list : declaration_list . declaration

	'}'  shift 249
	ID  shift 57
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

	declaration  goto 138
	type_specifier  goto 26
	declaration_specifiers  goto 59
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32


state 163
	specifier_qualifier_list : type_specifier .  (117)
	specifier_qualifier_list : type_specifier . specifier_qualifier_list

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

	type_specifier  goto 163
	specifier_qualifier_list  goto 250
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	type_qualifier  goto 166


state 164
	type_name : specifier_qualifier_list .  (158)
	type_name : specifier_qualifier_list . abstract_declarator

	'('  shift 251
	'*'  shift 2
	'['  shift 233
	.  reduce 158

	pointer  goto 252
	direct_abstract_declarator  goto 236
	abstract_declarator  goto 253


state 165
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 254
	','  shift 223


state 166
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

	type_specifier  goto 163
	specifier_qualifier_list  goto 255
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	type_qualifier  goto 166


state 167
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 256


state 168
	labeled_statement : ID ':' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 257


state 169
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
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

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	type_specifier  goto 163
	inclusive_or_exp  goto 125
	specifier_qualifier_list  goto 164
	logical_and_exp  goto 126
	exp  goto 165
	struct_or_union  goto 28
	enum_specifier  goto 29
	logical_or_exp  goto 128
	struct_or_union_specifier  goto 30
	type_qualifier  goto 166
	type_name  goto 258


state 170
	unary_exp : SIZEOF unary_exp .  (19)

	.  reduce 19


state 171
	primary_exp : '(' . exp ')'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 165
	logical_or_exp  goto 128


state 172
	unary_exp : INC_OP unary_exp .  (16)

	.  reduce 16


state 173
	unary_exp : DEC_OP unary_exp .  (17)

	.  reduce 17


state 174
	labeled_statement : CASE constant_exp . ':' statement

	':'  shift 259


state 175
	labeled_statement : DEFAULT ':' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 260


state 176
	matched_statement : IF '(' . exp ')' matched_statement ELSE matched_statement
	open_statement : IF '(' . exp ')' stmt
	open_statement : IF '(' . exp ')' matched_statement ELSE open_statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 261
	logical_or_exp  goto 128


state 177
	selection_statement : SWITCH '(' . exp ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 262
	logical_or_exp  goto 128


state 178
	iteration_statement : WHILE '(' . exp ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 263
	logical_or_exp  goto 128


state 179
	labeled_statement : ID . ':' statement
	primary_exp : ID .  (1)

	':'  shift 168
	.  reduce 1


state 180
	iteration_statement : DO statement . WHILE '(' exp ')' ';'

	WHILE  shift 264


state 181
	iteration_statement : FOR '(' . exp_statement exp_statement ')' statement
	iteration_statement : FOR '(' . exp_statement exp_statement exp ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	exp_statement  goto 265


state 182
	jump_statement : GOTO ID . ';'

	';'  shift 266


state 183
	jump_statement : CONTINUE ';' .  (215)

	.  reduce 215


state 184
	jump_statement : BREAK ';' .  (216)

	.  reduce 216


state 185
	jump_statement : RETURN ';' .  (217)

	.  reduce 217


state 186
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 223
	';'  shift 267


state 187
	assignment_operator : '=' .  (61)

	.  reduce 61


state 188
	assignment_operator : MUL_ASSIGN .  (62)

	.  reduce 62


state 189
	assignment_operator : DIV_ASSIGN .  (63)

	.  reduce 63


state 190
	assignment_operator : MOD_ASSIGN .  (64)

	.  reduce 64


state 191
	assignment_operator : ADD_ASSIGN .  (65)

	.  reduce 65


state 192
	assignment_operator : SUB_ASSIGN .  (66)

	.  reduce 66


state 193
	assignment_operator : LEFT_ASSIGN .  (67)

	.  reduce 67


state 194
	assignment_operator : RIGHT_ASSIGN .  (68)

	.  reduce 68


state 195
	assignment_operator : AND_ASSIGN .  (69)

	.  reduce 69


state 196
	assignment_operator : XOR_ASSIGN .  (70)

	.  reduce 70


state 197
	assignment_operator : OR_ASSIGN .  (71)

	.  reduce 71


state 198
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 268
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128


state 199
	unary_exp : unary_operator cast_exp .  (18)

	.  reduce 18


state 200
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	postfix_exp  goto 119
	multiplicative_exp  goto 269
	primary_exp  goto 121


state 201
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	postfix_exp  goto 119
	multiplicative_exp  goto 270
	primary_exp  goto 121


state 202
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 271
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 203
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 272
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 204
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 273
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 205
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 274
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 206
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 275
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 207
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 276
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 208
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 277
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 209
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 278
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 210
	and_exp : and_exp '&' . equality_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 279
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 211
	postfix_exp : postfix_exp '(' . ')'
	postfix_exp : postfix_exp '(' . argument_exp_list ')'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	')'  shift 280
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	argument_exp_list  goto 281
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 282
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128


state 212
	postfix_exp : postfix_exp '.' . ID

	ID  shift 283


state 213
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 284
	logical_or_exp  goto 128


state 214
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 285


state 215
	postfix_exp : postfix_exp INC_OP .  (11)

	.  reduce 11


state 216
	postfix_exp : postfix_exp DEC_OP .  (12)

	.  reduce 12


state 217
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 286
	postfix_exp  goto 119
	primary_exp  goto 121


state 218
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 287
	postfix_exp  goto 119
	primary_exp  goto 121


state 219
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 288
	postfix_exp  goto 119
	primary_exp  goto 121


state 220
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 289
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121


state 221
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 290


state 222
	logical_and_exp : logical_and_exp AND_OP . inclusive_or_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	inclusive_or_exp  goto 291


state 223
	exp : exp ',' . assignment_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 292
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128


state 224
	exp_statement : exp ';' .  (201)

	.  reduce 201


state 225
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 293
	logical_or_exp  goto 128


state 226
	logical_or_exp : logical_or_exp OR_OP . logical_and_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	inclusive_or_exp  goto 125
	logical_and_exp  goto 294


state 227
	compound_statement : '{' declaration_list '}' .  (194)

	.  reduce 194


state 228
	statement_list : statement_list . statement
	compound_statement : '{' declaration_list statement_list . '}'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'}'  shift 295
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 230


state 229
	compound_statement : '{' statement_list '}' .  (193)

	.  reduce 193


state 230
	statement_list : statement_list statement .  (199)

	.  reduce 199


state 231
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
	ELLIPSIS  shift 296

	type_specifier  goto 26
	declaration_specifiers  goto 143
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	parameter_declaration  goto 297


state 232
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 232
	')'  shift 298
	'*'  shift 2
	'['  shift 233
	ID  shift 38
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

	parameter_list  goto 142
	pointer  goto 234
	type_specifier  goto 26
	declaration_specifiers  goto 143
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	declarator  goto 39
	direct_declarator  goto 34
	parameter_type_list  goto 299
	direct_abstract_declarator  goto 236
	parameter_declaration  goto 145
	abstract_declarator  goto 300


state 233
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	']'  shift 301
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 150
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	constant_exp  goto 302
	logical_or_exp  goto 128


state 234
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (160)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 232
	'['  shift 233
	ID  shift 38
	.  reduce 160

	direct_declarator  goto 46
	direct_abstract_declarator  goto 303


state 235
	parameter_declaration : declaration_specifiers declarator .  (153)

	.  reduce 153


state 236
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	abstract_declarator : direct_abstract_declarator .  (161)
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'

	'('  shift 304
	'['  shift 305
	.  reduce 161


state 237
	parameter_declaration : declaration_specifiers abstract_declarator .  (154)

	.  reduce 154


state 238
	direct_declarator : direct_declarator '(' parameter_type_list ')' .  (140)

	.  reduce 140


state 239
	direct_declarator : direct_declarator '(' identifier_list ')' .  (141)

	.  reduce 141


state 240
	identifier_list : identifier_list ',' . ID

	ID  shift 306


state 241
	direct_declarator : direct_declarator '[' constant_exp ']' .  (138)

	.  reduce 138


state 242
	enumerator : ID '=' constant_exp .  (131)

	.  reduce 131


state 243
	enumerator_list : enumerator_list ',' enumerator .  (129)

	.  reduce 129


state 244
	enum_specifier : ENUM ID '{' enumerator_list '}' .  (126)

	.  reduce 126


state 245
	initializer_list : initializer .  (176)

	.  reduce 176


state 246
	initializer : '{' initializer_list . '}'
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . ',' '}'

	','  shift 307
	'}'  shift 308


state 247
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' ';' .  (107)

	.  reduce 107


state 248
	init_declarator_list : init_declarator_list . ',' init_declarator
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' init_declarator_list . ';'

	','  shift 73
	';'  shift 309


state 249
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' . init_declarator_list ';'
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 310
	ID  shift 38

	init_declarator  goto 49
	pointer  goto 24
	init_declarator_list  goto 311
	declarator  goto 137
	direct_declarator  goto 34


state 250
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (116)

	.  reduce 116


state 251
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'

	'('  shift 251
	')'  shift 298
	'*'  shift 2
	'['  shift 233
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

	parameter_list  goto 142
	pointer  goto 252
	type_specifier  goto 26
	declaration_specifiers  goto 143
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	parameter_type_list  goto 299
	direct_abstract_declarator  goto 236
	parameter_declaration  goto 145
	abstract_declarator  goto 300


state 252
	abstract_declarator : pointer .  (160)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 251
	'['  shift 233
	.  reduce 160

	direct_abstract_declarator  goto 303


state 253
	type_name : specifier_qualifier_list abstract_declarator .  (159)

	.  reduce 159


state 254
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 255
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (118)

	.  reduce 118


state 256
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 312
	postfix_exp  goto 119
	primary_exp  goto 121


state 257
	labeled_statement : ID ':' statement .  (189)

	.  reduce 189


state 258
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 313


state 259
	labeled_statement : CASE constant_exp ':' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 314


state 260
	labeled_statement : DEFAULT ':' statement .  (191)

	.  reduce 191


state 261
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' matched_statement ELSE matched_statement
	open_statement : IF '(' exp . ')' stmt
	open_statement : IF '(' exp . ')' matched_statement ELSE open_statement

	')'  shift 315
	','  shift 223


state 262
	exp : exp . ',' assignment_exp
	selection_statement : SWITCH '(' exp . ')' statement

	')'  shift 316
	','  shift 223


state 263
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE '(' exp . ')' statement

	')'  shift 317
	','  shift 223


state 264
	iteration_statement : DO statement WHILE . '(' exp ')' ';'

	'('  shift 318


state 265
	iteration_statement : FOR '(' exp_statement . exp_statement ')' statement
	iteration_statement : FOR '(' exp_statement . exp_statement exp ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	exp_statement  goto 319


state 266
	jump_statement : GOTO ID ';' .  (214)

	.  reduce 214


state 267
	jump_statement : RETURN exp ';' .  (218)

	.  reduce 218


state 268
	assignment_exp : unary_exp assignment_operator assignment_exp .  (60)

	.  reduce 60


state 269
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (34)

	'%'  shift 217
	'*'  shift 218
	'/'  shift 219
	.  reduce 34


state 270
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (35)

	'%'  shift 217
	'*'  shift 218
	'/'  shift 219
	.  reduce 35


state 271
	shift_exp : shift_exp LEFT_OP additive_exp .  (37)
	additive_exp : additive_exp . '+' multiplicative_exp
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 200
	'-'  shift 201
	.  reduce 37


state 272
	shift_exp : shift_exp RIGHT_OP additive_exp .  (38)
	additive_exp : additive_exp . '+' multiplicative_exp
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 200
	'-'  shift 201
	.  reduce 38


state 273
	relational_exp : relational_exp '<' shift_exp .  (40)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 202
	RIGHT_OP  shift 203
	.  reduce 40


state 274
	relational_exp : relational_exp '>' shift_exp .  (41)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 202
	RIGHT_OP  shift 203
	.  reduce 41


state 275
	relational_exp : relational_exp LE_OP shift_exp .  (42)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 202
	RIGHT_OP  shift 203
	.  reduce 42


state 276
	relational_exp : relational_exp GE_OP shift_exp .  (43)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 202
	RIGHT_OP  shift 203
	.  reduce 43


state 277
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (45)

	'<'  shift 204
	'>'  shift 205
	LE_OP  shift 206
	GE_OP  shift 207
	.  reduce 45


state 278
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (46)

	'<'  shift 204
	'>'  shift 205
	LE_OP  shift 206
	GE_OP  shift 207
	.  reduce 46


state 279
	and_exp : and_exp '&' equality_exp .  (48)
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp

	EQ_OP  shift 208
	NE_OP  shift 209
	.  reduce 48


state 280
	postfix_exp : postfix_exp '(' ')' .  (7)

	.  reduce 7


state 281
	postfix_exp : postfix_exp '(' argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 320
	','  shift 321


state 282
	argument_exp_list : assignment_exp .  (13)

	.  reduce 13


state 283
	postfix_exp : postfix_exp '.' ID .  (9)

	.  reduce 9


state 284
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 223
	']'  shift 322


state 285
	postfix_exp : postfix_exp PTR_OP ID .  (10)

	.  reduce 10


state 286
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (32)

	.  reduce 32


state 287
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (30)

	.  reduce 30


state 288
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (31)

	.  reduce 31


state 289
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (50)

	'&'  shift 210
	.  reduce 50


state 290
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (52)

	'^'  shift 220
	.  reduce 52


state 291
	logical_and_exp : logical_and_exp AND_OP inclusive_or_exp .  (54)
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp

	'|'  shift 221
	.  reduce 54


state 292
	exp : exp ',' assignment_exp .  (73)

	.  reduce 73


state 293
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 223
	':'  shift 323


state 294
	logical_or_exp : logical_or_exp OR_OP logical_and_exp .  (56)
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp

	AND_OP  shift 222
	.  reduce 56


state 295
	compound_statement : '{' declaration_list statement_list '}' .  (195)

	.  reduce 195


state 296
	parameter_type_list : parameter_list ',' ELLIPSIS .  (150)

	.  reduce 150


state 297
	parameter_list : parameter_list ',' parameter_declaration .  (152)

	.  reduce 152


state 298
	direct_abstract_declarator : '(' ')' .  (168)

	.  reduce 168


state 299
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 324


state 300
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 325


state 301
	direct_abstract_declarator : '[' ']' .  (164)

	.  reduce 164


state 302
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 326


state 303
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	abstract_declarator : pointer direct_abstract_declarator .  (162)

	'('  shift 304
	'['  shift 305
	.  reduce 162


state 304
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'

	')'  shift 327
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

	parameter_list  goto 142
	type_specifier  goto 26
	declaration_specifiers  goto 143
	struct_or_union  goto 28
	enum_specifier  goto 29
	struct_or_union_specifier  goto 30
	storage_class_specifier  goto 31
	type_qualifier  goto 32
	parameter_type_list  goto 328
	parameter_declaration  goto 145


state 305
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	']'  shift 329
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 150
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	constant_exp  goto 330
	logical_or_exp  goto 128


state 306
	identifier_list : identifier_list ',' ID .  (157)

	.  reduce 157


307: shift-reduce conflict (shift 331, reduce 175) on '}'
state 307
	initializer_list : initializer_list ',' . initializer
	initializer : '{' initializer_list ',' . '}'
	initializer : .  (175)

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'{'  shift 157
	'}'  shift 331
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	.  reduce 175

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 158
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128
	initializer  goto 332


state 308
	initializer : '{' initializer_list '}' .  (173)

	.  reduce 173


state 309
	struct_or_union_specifier : struct_or_union '{' declaration_list '}' init_declarator_list ';' .  (108)

	.  reduce 108


state 310
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' ';' .  (105)

	.  reduce 105


state 311
	init_declarator_list : init_declarator_list . ',' init_declarator
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' init_declarator_list . ';'

	','  shift 73
	';'  shift 333


state 312
	cast_exp : '(' type_name ')' cast_exp .  (28)

	.  reduce 28


state 313
	unary_exp : SIZEOF '(' type_name ')' .  (20)

	.  reduce 20


state 314
	labeled_statement : CASE constant_exp ':' statement .  (190)

	.  reduce 190


state 315
	matched_statement : IF '(' exp ')' . matched_statement ELSE matched_statement
	open_statement : IF '(' exp ')' . stmt
	open_statement : IF '(' exp ')' . matched_statement ELSE open_statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	other  goto 107
	matched_statement  goto 334
	stmt  goto 335
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 336
	compound_statement  goto 337
	exp_statement  goto 338
	iteration_statement  goto 339
	labeled_statement  goto 340


state 316
	selection_statement : SWITCH '(' exp ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 341


state 317
	iteration_statement : WHILE '(' exp ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 342


state 318
	iteration_statement : DO statement WHILE '(' . exp ')' ';'

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 343
	logical_or_exp  goto 128


state 319
	iteration_statement : FOR '(' exp_statement exp_statement . ')' statement
	iteration_statement : FOR '(' exp_statement exp_statement . exp ')' statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	')'  shift 344
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 345
	logical_or_exp  goto 128


state 320
	postfix_exp : postfix_exp '(' argument_exp_list ')' .  (8)

	.  reduce 8


state 321
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 346
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128


state 322
	postfix_exp : postfix_exp '[' exp ']' .  (6)

	.  reduce 6


state 323
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	'~'  shift 88
	ID  shift 148
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94

	unary_exp  goto 149
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 347
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	logical_or_exp  goto 128


state 324
	direct_abstract_declarator : '(' parameter_type_list ')' .  (169)

	.  reduce 169


state 325
	direct_abstract_declarator : '(' abstract_declarator ')' .  (163)

	.  reduce 163


state 326
	direct_abstract_declarator : '[' constant_exp ']' .  (165)

	.  reduce 165


state 327
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (170)

	.  reduce 170


state 328
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 348


state 329
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (166)

	.  reduce 166


state 330
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp . ']'

	']'  shift 349


state 331
	initializer : '{' initializer_list ',' '}' .  (174)

	.  reduce 174


state 332
	initializer_list : initializer_list ',' initializer .  (177)

	.  reduce 177


state 333
	struct_or_union_specifier : struct_or_union ID '{' declaration_list '}' init_declarator_list ';' .  (106)

	.  reduce 106


334: shift-reduce conflict (shift 350, reduce 202) on ELSE
state 334
	stmt : matched_statement .  (202)
	matched_statement : IF '(' exp ')' matched_statement . ELSE matched_statement
	open_statement : IF '(' exp ')' matched_statement . ELSE open_statement

	ELSE  shift 350
	.  reduce 202


state 335
	open_statement : IF '(' exp ')' stmt .  (206)

	.  reduce 206


state 336
	other : jump_statement .  (182)

	.  reduce 182


state 337
	other : compound_statement .  (179)

	.  reduce 179


state 338
	other : exp_statement .  (180)

	.  reduce 180


state 339
	other : iteration_statement .  (181)

	.  reduce 181


state 340
	other : labeled_statement .  (178)

	.  reduce 178


state 341
	selection_statement : SWITCH '(' exp ')' statement .  (209)

	.  reduce 209


state 342
	iteration_statement : WHILE '(' exp ')' statement .  (210)

	.  reduce 210


state 343
	exp : exp . ',' assignment_exp
	iteration_statement : DO statement WHILE '(' exp . ')' ';'

	')'  shift 351
	','  shift 223


state 344
	iteration_statement : FOR '(' exp_statement exp_statement ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 352


state 345
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement exp_statement exp . ')' statement

	')'  shift 353
	','  shift 223


state 346
	argument_exp_list : argument_exp_list ',' assignment_exp .  (14)

	.  reduce 14


state 347
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (58)

	.  reduce 58


state 348
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (171)

	.  reduce 171


state 349
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (167)

	.  reduce 167


state 350
	matched_statement : IF '(' exp ')' matched_statement ELSE . matched_statement
	open_statement : IF '(' exp ')' matched_statement ELSE . open_statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	other  goto 107
	matched_statement  goto 354
	open_statement  goto 355
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 336
	compound_statement  goto 337
	exp_statement  goto 338
	iteration_statement  goto 339
	labeled_statement  goto 340


state 351
	iteration_statement : DO statement WHILE '(' exp ')' . ';'

	';'  shift 356


state 352
	iteration_statement : FOR '(' exp_statement exp_statement ')' statement .  (212)

	.  reduce 212


state 353
	iteration_statement : FOR '(' exp_statement exp_statement exp ')' . statement

	'!'  shift 80
	'&'  shift 81
	'('  shift 82
	'*'  shift 83
	'+'  shift 84
	'-'  shift 85
	';'  shift 86
	'{'  shift 56
	'~'  shift 88
	ID  shift 179
	CONSTANT  shift 90
	STRING_LITERAL  shift 91
	SIZEOF  shift 92
	INC_OP  shift 93
	DEC_OP  shift 94
	CASE  shift 95
	DEFAULT  shift 96
	IF  shift 97
	SWITCH  shift 98
	WHILE  shift 99
	DO  shift 100
	FOR  shift 101
	GOTO  shift 102
	CONTINUE  shift 103
	BREAK  shift 104
	RETURN  shift 105

	selection_statement  goto 106
	other  goto 107
	matched_statement  goto 108
	stmt  goto 109
	open_statement  goto 110
	unary_exp  goto 111
	unary_operator  goto 112
	cast_exp  goto 113
	additive_exp  goto 114
	shift_exp  goto 115
	relational_exp  goto 116
	equality_exp  goto 117
	and_exp  goto 118
	postfix_exp  goto 119
	multiplicative_exp  goto 120
	primary_exp  goto 121
	exclusive_or_exp  goto 122
	conditional_exp  goto 123
	assignment_exp  goto 124
	inclusive_or_exp  goto 125
	logical_and_exp  goto 126
	exp  goto 127
	logical_or_exp  goto 128
	jump_statement  goto 130
	compound_statement  goto 131
	exp_statement  goto 132
	iteration_statement  goto 134
	labeled_statement  goto 135
	statement  goto 357


state 354
	matched_statement : IF '(' exp ')' matched_statement ELSE matched_statement .  (204)

	.  reduce 204


state 355
	open_statement : IF '(' exp ')' matched_statement ELSE open_statement .  (207)

	.  reduce 207


state 356
	iteration_statement : DO statement WHILE '(' exp ')' ';' .  (211)

	.  reduce 211


state 357
	iteration_statement : FOR '(' exp_statement exp_statement exp ')' statement .  (213)

	.  reduce 213


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
	statement : labeled_statement  (183)
	statement : compound_statement  (184)
	statement : exp_statement  (185)
	statement : iteration_statement  (187)
	statement : jump_statement  (188)


##############################################################################
# Summary
##############################################################################

State 3 contains 1 shift-reduce conflict(s)
State 130 contains 28 reduce-reduce conflict(s)
State 131 contains 28 reduce-reduce conflict(s)
State 132 contains 28 reduce-reduce conflict(s)
State 134 contains 28 reduce-reduce conflict(s)
State 135 contains 28 reduce-reduce conflict(s)
State 307 contains 1 shift-reduce conflict(s)
State 334 contains 1 shift-reduce conflict(s)


84 token(s), 68 nonterminal(s)
227 grammar rule(s), 358 state(s)


##############################################################################
# End of File
##############################################################################
