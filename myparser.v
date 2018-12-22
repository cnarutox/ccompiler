#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 74 of your 30 day trial period.
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
# Date: 12/23/18
# Time: 06:37:47
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

    5  postfix_pre_exp : postfix_exp '('

    6  postfix_exp : primary_exp
    7              | postfix_exp '[' exp ']'
    8              | postfix_pre_exp ')'
    9              | postfix_pre_exp argument_exp_list ')'
   10              | postfix_exp '.' ID
   11              | postfix_exp PTR_OP ID
   12              | postfix_exp INC_OP
   13              | postfix_exp DEC_OP

   14  argument_exp_list : assignment_exp
   15                    | argument_exp_list ',' assignment_exp

   16  unary_exp : postfix_exp
   17            | INC_OP unary_exp
   18            | DEC_OP unary_exp
   19            | unary_operator cast_exp
   20            | SIZEOF unary_exp
   21            | SIZEOF '(' type_name ')'

   22  unary_operator : '&'
   23                 | '*'
   24                 | '+'
   25                 | '-'
   26                 | '~'
   27                 | '!'

   28  cast_exp : unary_exp
   29           | '(' type_name ')' cast_exp

   30  multiplicative_exp : cast_exp
   31                     | multiplicative_exp '*' cast_exp
   32                     | multiplicative_exp '/' cast_exp
   33                     | multiplicative_exp '%' cast_exp

   34  additive_exp : multiplicative_exp
   35               | additive_exp '+' multiplicative_exp
   36               | additive_exp '-' multiplicative_exp

   37  shift_exp : additive_exp
   38            | shift_exp LEFT_OP additive_exp
   39            | shift_exp RIGHT_OP additive_exp

   40  relational_exp : shift_exp
   41                 | relational_exp '<' shift_exp
   42                 | relational_exp '>' shift_exp
   43                 | relational_exp LE_OP shift_exp
   44                 | relational_exp GE_OP shift_exp

   45  equality_exp : relational_exp
   46               | equality_exp EQ_OP relational_exp
   47               | equality_exp NE_OP relational_exp

   48  and_exp : equality_exp
   49          | and_exp '&' equality_exp

   50  exclusive_or_exp : and_exp
   51                   | exclusive_or_exp '^' and_exp

   52  inclusive_or_exp : exclusive_or_exp
   53                   | inclusive_or_exp '|' exclusive_or_exp

   54  logical_and_exp : inclusive_or_exp
   55                  | logical_and_exp AND_OP inclusive_or_exp

   56  logical_or_exp : logical_and_exp
   57                 | logical_or_exp OR_OP logical_and_exp

   58  conditional_exp : logical_or_exp
   59                  | logical_or_exp '?' exp ':' conditional_exp

   60  assignment_exp : conditional_exp
   61                 | unary_exp assignment_operator assignment_exp

   62  assignment_operator : '='
   63                      | MUL_ASSIGN
   64                      | DIV_ASSIGN
   65                      | MOD_ASSIGN
   66                      | ADD_ASSIGN
   67                      | SUB_ASSIGN
   68                      | LEFT_ASSIGN
   69                      | RIGHT_ASSIGN
   70                      | AND_ASSIGN
   71                      | XOR_ASSIGN
   72                      | OR_ASSIGN

   73  exp : assignment_exp
   74      | exp ',' assignment_exp

   75  constant_exp : conditional_exp

   76  declaration : declaration_specifiers ';'
   77              | declaration_specifiers init_declarator_list ';'

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
  105                 | type_specifier pointer

  106  struct_or_union_def : struct_or_union ID '{' declaration_list '}'
  107                      | struct_or_union '{' declaration_list '}'

  108  def_concat : ';'
  109             | init_declarator_list ';'

  110  struct_or_union_specifier : struct_or_union_def def_concat
  111                            | struct_or_union ID

  112  struct_or_union : STRUCT
  113                  | UNION

  114  struct_declaration_list : struct_declaration
  115                          | struct_declaration_list struct_declaration

  116  struct_declaration : specifier_qualifier_list struct_declarator_list ';'
  117                     | assignment_exp struct_declarator_list ';'

  118  specifier_qualifier_list : type_specifier specifier_qualifier_list
  119                           | type_specifier
  120                           | type_qualifier specifier_qualifier_list
  121                           | type_qualifier

  122  struct_declarator_list : struct_declarator
  123                         | struct_declarator_list ',' struct_declarator

  124  struct_declarator : declarator
  125                    | ':' constant_exp
  126                    | declarator ':' constant_exp

  127  enum_specifier : ENUM '{' enumerator_list '}'
  128                 | ENUM ID '{' enumerator_list '}'
  129                 | ENUM ID

  130  enumerator_list : enumerator
  131                  | enumerator_list ',' enumerator

  132  enumerator : ID
  133             | ID '=' constant_exp

  134  type_qualifier : CONST
  135                 | VOLATILE

  136  declarator : pointer direct_declarator
  137             | direct_declarator

  138  direct_pre_declarator : direct_declarator '('

  139  direct_declarator : ID
  140                    | '(' declarator ')'
  141                    | direct_declarator '[' constant_exp ']'
  142                    | direct_declarator '[' ']'
  143                    | direct_pre_declarator parameter_type_list ')'
  144                    | direct_pre_declarator identifier_list ')'
  145                    | direct_pre_declarator ')'

  146  pointer : '*'
  147          | '*' type_qualifier_list
  148          | '*' pointer
  149          | '*' type_qualifier_list pointer

  150  type_qualifier_list : type_qualifier
  151                      | type_qualifier_list type_qualifier

  152  parameter_type_list : parameter_list
  153                      | parameter_list ',' ELLIPSIS

  154  parameter_list : parameter_declaration
  155                 | parameter_list ',' parameter_declaration

  156  parameter_declaration : declaration_specifiers declarator
  157                        | declaration_specifiers abstract_declarator
  158                        | declaration_specifiers

  159  identifier_list : ID
  160                  | identifier_list ',' ID

  161  type_name : specifier_qualifier_list
  162            | specifier_qualifier_list abstract_declarator

  163  abstract_declarator : pointer
  164                      | direct_abstract_declarator
  165                      | pointer direct_abstract_declarator

  166  direct_abstract_declarator : '(' abstract_declarator ')'
  167                             | '[' ']'
  168                             | '[' constant_exp ']'
  169                             | direct_abstract_declarator '[' ']'
  170                             | direct_abstract_declarator '[' constant_exp ']'
  171                             | '(' ')'
  172                             | '(' parameter_type_list ')'
  173                             | direct_abstract_declarator '(' ')'
  174                             | direct_abstract_declarator '(' parameter_type_list ')'

  175  initializer : assignment_exp
  176              | '{' initializer_list '}'
  177              | '{' initializer_list ',' '}'

  178  initializer_list : initializer
  179                   | initializer_list ',' initializer

  180  other : labeled_statement
  181        | compound_statement
  182        | exp_statement
  183        | iteration_statement
  184        | jump_statement
  185        |

  186  statement : labeled_statement
  187            | compound_statement
  188            | exp_statement
  189            | selection_statement
  190            | iteration_statement
  191            | jump_statement

  192  labeled_statement : ID ':' statement
  193                    | CASE constant_exp ':' statement
  194                    | DEFAULT ':' statement

  195  compound_statement : '{' '}'
  196                     | '{' statement_list '}'
  197                     | '{' declaration_list '}'
  198                     | '{' declaration_list statement_list '}'

  199  declaration_list : declaration
  200                   | declaration_list declaration

  201  statement_list : statement
  202                 | statement_list statement

  203  exp_statement : ';'
  204                | exp ';'

  205  stmt : matched_statement
  206       | open_statement

  207  matched_statement : IF '(' exp ')' matched_statement ELSE matched_statement
  208                    | other

  209  open_statement : IF '(' exp ')' stmt
  210                 | IF '(' exp ')' matched_statement ELSE open_statement

  211  selection_statement : stmt
  212                      | SWITCH '(' exp ')' statement

  213  iteration_statement : WHILE '(' exp ')' statement
  214                      | DO statement WHILE '(' exp ')' ';'
  215                      | FOR '(' exp_statement exp_statement ')' statement
  216                      | FOR '(' exp_statement exp_statement exp ')' statement

  217  jump_statement : GOTO ID ';'
  218                 | CONTINUE ';'
  219                 | BREAK ';'
  220                 | RETURN ';'
  221                 | RETURN exp ';'

  222  translation_unit : external_declaration
  223                   | translation_unit external_declaration

  224  external_declaration : function_definition
  225                       | declaration

  226  function_definition : declaration_specifiers declarator declaration_list compound_statement
  227                      | declaration_specifiers declarator compound_statement
  228                      | declarator declaration_list compound_statement
  229                      | declarator compound_statement


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

	declaration  goto 24
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declarator  goto 28
	declaration_specifiers  goto 29
	direct_declarator  goto 30
	type_specifier  goto 31
	pointer  goto 32
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	direct_pre_declarator  goto 36
	translation_unit  goto 37
	external_declaration  goto 38
	function_definition  goto 39


state 1
	direct_declarator : '(' . declarator ')'

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 40
	direct_declarator  goto 30
	pointer  goto 32
	direct_pre_declarator  goto 36


2: shift-reduce conflict (shift 2, reduce 146) on '*'
2: shift-reduce conflict (shift 18, reduce 146) on CONST
2: shift-reduce conflict (shift 19, reduce 146) on VOLATILE
state 2
	pointer : '*' . pointer
	pointer : '*' . type_qualifier_list
	pointer : '*' .  (146)
	pointer : '*' . type_qualifier_list pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 146

	type_qualifier  goto 41
	pointer  goto 42
	type_qualifier_list  goto 43


state 3
	direct_declarator : ID .  (139)

	.  reduce 139


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
	type_qualifier : CONST .  (134)

	.  reduce 134


state 19
	type_qualifier : VOLATILE .  (135)

	.  reduce 135


state 20
	type_specifier : VOID .  (93)

	.  reduce 93


state 21
	struct_or_union : STRUCT .  (112)

	.  reduce 112


state 22
	struct_or_union : UNION .  (113)

	.  reduce 113


state 23
	enum_specifier : ENUM . ID
	enum_specifier : ENUM . '{' enumerator_list '}'
	enum_specifier : ENUM . ID '{' enumerator_list '}'

	'{'  shift 44
	ID  shift 45


state 24
	external_declaration : declaration .  (225)

	.  reduce 225


state 25
	struct_or_union_specifier : struct_or_union . ID
	struct_or_union_def : struct_or_union . ID '{' declaration_list '}'
	struct_or_union_def : struct_or_union . '{' declaration_list '}'

	'{'  shift 46
	ID  shift 47


state 26
	struct_or_union_specifier : struct_or_union_def . def_concat

	'('  shift 1
	'*'  shift 2
	';'  shift 48
	ID  shift 3

	declarator  goto 49
	direct_declarator  goto 30
	pointer  goto 32
	init_declarator_list  goto 50
	def_concat  goto 51
	init_declarator  goto 52
	direct_pre_declarator  goto 36


state 27
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

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 53
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35


state 28
	function_definition : declarator . compound_statement
	function_definition : declarator . declaration_list compound_statement

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

	declaration  goto 55
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	compound_statement  goto 57
	declaration_list  goto 58


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
	direct_declarator  goto 30
	pointer  goto 32
	init_declarator_list  goto 61
	init_declarator  goto 52
	direct_pre_declarator  goto 36


state 30
	declarator : direct_declarator .  (137)
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 62
	'['  shift 63
	.  reduce 137


31: shift-reduce conflict (shift 2, reduce 80) on '*'
state 31
	declaration_specifiers : type_specifier .  (80)
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
	.  reduce 80

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 64
	type_specifier  goto 31
	pointer  goto 65
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35


state 32
	declarator : pointer . direct_declarator

	'('  shift 1
	ID  shift 3

	direct_declarator  goto 66
	direct_pre_declarator  goto 36


state 33
	declaration_specifiers : storage_class_specifier .  (78)
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
	.  reduce 78

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 67
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35


state 34
	type_specifier : struct_or_union_specifier .  (102)

	.  reduce 102


state 35
	type_specifier : enum_specifier .  (103)

	.  reduce 103


state 36
	direct_declarator : direct_pre_declarator . parameter_type_list ')'
	direct_declarator : direct_pre_declarator . identifier_list ')'
	direct_declarator : direct_pre_declarator . ')'

	')'  shift 68
	ID  shift 69
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

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 70
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	parameter_list  goto 71
	parameter_type_list  goto 72
	parameter_declaration  goto 73
	identifier_list  goto 74


state 37
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

	declaration  goto 24
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declarator  goto 28
	declaration_specifiers  goto 29
	direct_declarator  goto 30
	type_specifier  goto 31
	pointer  goto 32
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	direct_pre_declarator  goto 36
	external_declaration  goto 75
	function_definition  goto 39


state 38
	translation_unit : external_declaration .  (222)

	.  reduce 222


state 39
	external_declaration : function_definition .  (224)

	.  reduce 224


state 40
	direct_declarator : '(' declarator . ')'

	')'  shift 76


state 41
	type_qualifier_list : type_qualifier .  (150)

	.  reduce 150


state 42
	pointer : '*' pointer .  (148)

	.  reduce 148


43: shift-reduce conflict (shift 2, reduce 147) on '*'
43: shift-reduce conflict (shift 18, reduce 147) on CONST
43: shift-reduce conflict (shift 19, reduce 147) on VOLATILE
state 43
	type_qualifier_list : type_qualifier_list . type_qualifier
	pointer : '*' type_qualifier_list .  (147)
	pointer : '*' type_qualifier_list . pointer

	'*'  shift 2
	CONST  shift 18
	VOLATILE  shift 19
	.  reduce 147

	type_qualifier  goto 77
	pointer  goto 78


state 44
	enum_specifier : ENUM '{' . enumerator_list '}'

	ID  shift 79

	enumerator  goto 80
	enumerator_list  goto 81


state 45
	enum_specifier : ENUM ID .  (129)
	enum_specifier : ENUM ID . '{' enumerator_list '}'

	'{'  shift 82
	.  reduce 129


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

	declaration  goto 55
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	declaration_list  goto 83


state 47
	struct_or_union_specifier : struct_or_union ID .  (111)
	struct_or_union_def : struct_or_union ID . '{' declaration_list '}'

	'{'  shift 84
	.  reduce 111


state 48
	def_concat : ';' .  (108)

	.  reduce 108


state 49
	init_declarator : declarator .  (86)
	init_declarator : declarator . '=' initializer

	'='  shift 85
	.  reduce 86


state 50
	init_declarator_list : init_declarator_list . ',' init_declarator
	def_concat : init_declarator_list . ';'

	','  shift 86
	';'  shift 87


state 51
	struct_or_union_specifier : struct_or_union_def def_concat .  (110)

	.  reduce 110


state 52
	init_declarator_list : init_declarator .  (84)

	.  reduce 84


state 53
	declaration_specifiers : type_qualifier declaration_specifiers .  (83)

	.  reduce 83


54: shift-reduce conflict (shift 88, reduce 185) on '!'
54: shift-reduce conflict (shift 89, reduce 185) on '&'
54: shift-reduce conflict (shift 90, reduce 185) on '('
54: shift-reduce conflict (shift 91, reduce 185) on '*'
54: shift-reduce conflict (shift 92, reduce 185) on '+'
54: shift-reduce conflict (shift 93, reduce 185) on '-'
54: shift-reduce conflict (shift 94, reduce 185) on ';'
54: shift-reduce conflict (shift 54, reduce 185) on '{'
54: shift-reduce conflict (shift 95, reduce 185) on '}'
54: shift-reduce conflict (shift 96, reduce 185) on '~'
54: shift-reduce conflict (shift 97, reduce 185) on ID
54: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
54: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
54: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
54: shift-reduce conflict (shift 101, reduce 185) on INC_OP
54: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
54: shift-reduce conflict (shift 103, reduce 185) on CASE
54: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
54: shift-reduce conflict (shift 105, reduce 185) on IF
54: shift-reduce conflict (shift 106, reduce 185) on SWITCH
54: shift-reduce conflict (shift 107, reduce 185) on WHILE
54: shift-reduce conflict (shift 108, reduce 185) on DO
54: shift-reduce conflict (shift 109, reduce 185) on FOR
54: shift-reduce conflict (shift 110, reduce 185) on GOTO
54: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
54: shift-reduce conflict (shift 112, reduce 185) on BREAK
54: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 54
	compound_statement : '{' . declaration_list statement_list '}'
	compound_statement : '{' . statement_list '}'
	compound_statement : '{' . '}'
	compound_statement : '{' . declaration_list '}'
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'}'  shift 95
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
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
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	declaration  goto 55
	logical_and_exp  goto 124
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	exp  goto 125
	storage_class_specifier  goto 33
	logical_or_exp  goto 126
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	statement_list  goto 134
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 138
	declaration_list  goto 139
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 55
	declaration_list : declaration .  (199)

	.  reduce 199


state 56
	declaration : declaration_specifiers . init_declarator_list ';'
	declaration : declaration_specifiers . ';'

	'('  shift 1
	'*'  shift 2
	';'  shift 59
	ID  shift 3

	declarator  goto 49
	direct_declarator  goto 30
	pointer  goto 32
	init_declarator_list  goto 61
	init_declarator  goto 52
	direct_pre_declarator  goto 36


state 57
	function_definition : declarator compound_statement .  (229)

	.  reduce 229


state 58
	declaration_list : declaration_list . declaration
	function_definition : declarator declaration_list . compound_statement

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

	declaration  goto 146
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	compound_statement  goto 147


state 59
	declaration : declaration_specifiers ';' .  (76)

	.  reduce 76


state 60
	init_declarator : declarator .  (86)
	init_declarator : declarator . '=' initializer
	function_definition : declaration_specifiers declarator . compound_statement
	function_definition : declaration_specifiers declarator . declaration_list compound_statement

	'='  shift 85
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
	.  reduce 86

	declaration  goto 55
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	compound_statement  goto 148
	declaration_list  goto 149


state 61
	declaration : declaration_specifiers init_declarator_list . ';'
	init_declarator_list : init_declarator_list . ',' init_declarator

	','  shift 86
	';'  shift 150


state 62
	direct_pre_declarator : direct_declarator '(' .  (138)

	.  reduce 138


state 63
	direct_declarator : direct_declarator '[' . constant_exp ']'
	direct_declarator : direct_declarator '[' . ']'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	']'  shift 151
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	constant_exp  goto 154
	logical_or_exp  goto 126
	conditional_exp  goto 155
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 64
	declaration_specifiers : type_specifier declaration_specifiers .  (81)

	.  reduce 81


state 65
	type_specifier : type_specifier pointer .  (105)

	.  reduce 105


state 66
	declarator : pointer direct_declarator .  (136)
	direct_pre_declarator : direct_declarator . '('
	direct_declarator : direct_declarator . '[' constant_exp ']'
	direct_declarator : direct_declarator . '[' ']'

	'('  shift 62
	'['  shift 63
	.  reduce 136


state 67
	declaration_specifiers : storage_class_specifier declaration_specifiers .  (79)

	.  reduce 79


state 68
	direct_declarator : direct_pre_declarator ')' .  (145)

	.  reduce 145


state 69
	identifier_list : ID .  (159)

	.  reduce 159


state 70
	parameter_declaration : declaration_specifiers . abstract_declarator
	parameter_declaration : declaration_specifiers . declarator
	parameter_declaration : declaration_specifiers .  (158)

	'('  shift 156
	'*'  shift 2
	'['  shift 157
	ID  shift 3
	.  reduce 158

	declarator  goto 158
	direct_declarator  goto 30
	pointer  goto 159
	abstract_declarator  goto 160
	direct_abstract_declarator  goto 161
	direct_pre_declarator  goto 36


state 71
	parameter_type_list : parameter_list . ',' ELLIPSIS
	parameter_type_list : parameter_list .  (152)
	parameter_list : parameter_list . ',' parameter_declaration

	','  shift 162
	.  reduce 152


state 72
	direct_declarator : direct_pre_declarator parameter_type_list . ')'

	')'  shift 163


state 73
	parameter_list : parameter_declaration .  (154)

	.  reduce 154


state 74
	direct_declarator : direct_pre_declarator identifier_list . ')'
	identifier_list : identifier_list . ',' ID

	')'  shift 164
	','  shift 165


state 75
	translation_unit : translation_unit external_declaration .  (223)

	.  reduce 223


state 76
	direct_declarator : '(' declarator ')' .  (140)

	.  reduce 140


state 77
	type_qualifier_list : type_qualifier_list type_qualifier .  (151)

	.  reduce 151


state 78
	pointer : '*' type_qualifier_list pointer .  (149)

	.  reduce 149


state 79
	enumerator : ID .  (132)
	enumerator : ID . '=' constant_exp

	'='  shift 166
	.  reduce 132


state 80
	enumerator_list : enumerator .  (130)

	.  reduce 130


state 81
	enum_specifier : ENUM '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 167
	'}'  shift 168


state 82
	enum_specifier : ENUM ID '{' . enumerator_list '}'

	ID  shift 79

	enumerator  goto 80
	enumerator_list  goto 169


state 83
	struct_or_union_def : struct_or_union '{' declaration_list . '}'
	declaration_list : declaration_list . declaration

	'}'  shift 170
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

	declaration  goto 146
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35


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

	declaration  goto 55
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	declaration_list  goto 171


state 85
	init_declarator : declarator '=' . initializer

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'{'  shift 172
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 173
	inclusive_or_exp  goto 131
	initializer  goto 174
	postfix_pre_exp  goto 145


state 86
	init_declarator_list : init_declarator_list ',' . init_declarator

	'('  shift 1
	'*'  shift 2
	ID  shift 3

	declarator  goto 49
	direct_declarator  goto 30
	pointer  goto 32
	init_declarator  goto 175
	direct_pre_declarator  goto 36


state 87
	def_concat : init_declarator_list ';' .  (109)

	.  reduce 109


state 88
	unary_operator : '!' .  (27)

	.  reduce 27


state 89
	unary_operator : '&' .  (22)

	.  reduce 22


state 90
	primary_exp : '(' . exp ')'
	cast_exp : '(' . type_name ')' cast_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
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

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 176
	type_specifier  goto 177
	exp  goto 178
	logical_or_exp  goto 126
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	conditional_exp  goto 127
	specifier_qualifier_list  goto 179
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	type_name  goto 180
	postfix_pre_exp  goto 145


state 91
	unary_operator : '*' .  (23)

	.  reduce 23


state 92
	unary_operator : '+' .  (24)

	.  reduce 24


state 93
	unary_operator : '-' .  (25)

	.  reduce 25


state 94
	exp_statement : ';' .  (203)

	.  reduce 203


state 95
	compound_statement : '{' '}' .  (195)

	.  reduce 195


state 96
	unary_operator : '~' .  (26)

	.  reduce 26


state 97
	primary_exp : ID .  (1)
	labeled_statement : ID . ':' statement

	':'  shift 181
	.  reduce 1


state 98
	primary_exp : CONSTANT .  (2)

	.  reduce 2


state 99
	primary_exp : STRING_LITERAL .  (3)

	.  reduce 3


state 100
	unary_exp : SIZEOF . unary_exp
	unary_exp : SIZEOF . '(' type_name ')'

	'!'  shift 88
	'&'  shift 89
	'('  shift 182
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 183
	unary_operator  goto 121
	postfix_pre_exp  goto 145


state 101
	unary_exp : INC_OP . unary_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 184
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 185
	unary_operator  goto 121
	postfix_pre_exp  goto 145


state 102
	unary_exp : DEC_OP . unary_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 184
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 186
	unary_operator  goto 121
	postfix_pre_exp  goto 145


state 103
	labeled_statement : CASE . constant_exp ':' statement

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	constant_exp  goto 187
	logical_or_exp  goto 126
	conditional_exp  goto 155
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 104
	labeled_statement : DEFAULT . ':' statement

	':'  shift 188


state 105
	matched_statement : IF . '(' exp ')' matched_statement ELSE matched_statement
	open_statement : IF . '(' exp ')' matched_statement ELSE open_statement
	open_statement : IF . '(' exp ')' stmt

	'('  shift 189


state 106
	selection_statement : SWITCH . '(' exp ')' statement

	'('  shift 190


state 107
	iteration_statement : WHILE . '(' exp ')' statement

	'('  shift 191


108: shift-reduce conflict (shift 107, reduce 185) on WHILE
state 108
	iteration_statement : DO . statement WHILE '(' exp ')' ';'
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 192
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 109
	iteration_statement : FOR . '(' exp_statement exp_statement ')' statement
	iteration_statement : FOR . '(' exp_statement exp_statement exp ')' statement

	'('  shift 193


state 110
	jump_statement : GOTO . ID ';'

	ID  shift 194


state 111
	jump_statement : CONTINUE . ';'

	';'  shift 195


state 112
	jump_statement : BREAK . ';'

	';'  shift 196


state 113
	jump_statement : RETURN . exp ';'
	jump_statement : RETURN . ';'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 197
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 198
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 114
	postfix_exp : primary_exp .  (6)

	.  reduce 6


state 115
	additive_exp : additive_exp . '+' multiplicative_exp
	shift_exp : additive_exp .  (37)
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 199
	'-'  shift 200
	.  reduce 37


state 116
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : shift_exp .  (40)

	LEFT_OP  shift 201
	RIGHT_OP  shift 202
	.  reduce 40


state 117
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : relational_exp .  (45)
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 203
	'>'  shift 204
	LE_OP  shift 205
	GE_OP  shift 206
	.  reduce 45


state 118
	equality_exp : equality_exp . NE_OP relational_exp
	and_exp : equality_exp .  (48)
	equality_exp : equality_exp . EQ_OP relational_exp

	EQ_OP  shift 207
	NE_OP  shift 208
	.  reduce 48


state 119
	postfix_pre_exp : postfix_exp . '('
	postfix_exp : postfix_exp . '[' exp ']'
	postfix_exp : postfix_exp . '.' ID
	postfix_exp : postfix_exp . PTR_OP ID
	postfix_exp : postfix_exp . INC_OP
	postfix_exp : postfix_exp . DEC_OP
	unary_exp : postfix_exp .  (16)

	'('  shift 209
	'.'  shift 210
	'['  shift 211
	PTR_OP  shift 212
	INC_OP  shift 213
	DEC_OP  shift 214
	.  reduce 16


state 120
	cast_exp : unary_exp .  (28)
	assignment_exp : unary_exp . assignment_operator assignment_exp

	'='  shift 215
	MUL_ASSIGN  shift 216
	DIV_ASSIGN  shift 217
	MOD_ASSIGN  shift 218
	ADD_ASSIGN  shift 219
	SUB_ASSIGN  shift 220
	LEFT_ASSIGN  shift 221
	RIGHT_ASSIGN  shift 222
	AND_ASSIGN  shift 223
	XOR_ASSIGN  shift 224
	OR_ASSIGN  shift 225
	.  reduce 28

	assignment_operator  goto 226


state 121
	unary_exp : unary_operator . cast_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 227
	postfix_pre_exp  goto 145


state 122
	multiplicative_exp : cast_exp .  (30)

	.  reduce 30


state 123
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : multiplicative_exp .  (34)

	'%'  shift 228
	'*'  shift 229
	'/'  shift 230
	.  reduce 34


state 124
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp
	logical_or_exp : logical_and_exp .  (56)

	AND_OP  shift 231
	.  reduce 56


state 125
	exp : exp . ',' assignment_exp
	exp_statement : exp . ';'

	','  shift 232
	';'  shift 233


state 126
	logical_or_exp : logical_or_exp . OR_OP logical_and_exp
	conditional_exp : logical_or_exp . '?' exp ':' conditional_exp
	conditional_exp : logical_or_exp .  (58)

	'?'  shift 234
	OR_OP  shift 235
	.  reduce 58


state 127
	assignment_exp : conditional_exp .  (60)

	.  reduce 60


state 128
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : and_exp .  (50)

	'&'  shift 236
	.  reduce 50


state 129
	exclusive_or_exp : exclusive_or_exp . '^' and_exp
	inclusive_or_exp : exclusive_or_exp .  (52)

	'^'  shift 237
	.  reduce 52


state 130
	exp : assignment_exp .  (73)

	.  reduce 73


state 131
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : inclusive_or_exp .  (54)

	'|'  shift 238
	.  reduce 54


132: reduce-reduce conflict (reduce 180, reduce 186) on '!'
132: reduce-reduce conflict (reduce 180, reduce 186) on '&'
132: reduce-reduce conflict (reduce 180, reduce 186) on '('
132: reduce-reduce conflict (reduce 180, reduce 186) on '*'
132: reduce-reduce conflict (reduce 180, reduce 186) on '+'
132: reduce-reduce conflict (reduce 180, reduce 186) on '-'
132: reduce-reduce conflict (reduce 180, reduce 186) on ';'
132: reduce-reduce conflict (reduce 180, reduce 186) on '{'
132: reduce-reduce conflict (reduce 180, reduce 186) on '}'
132: reduce-reduce conflict (reduce 180, reduce 186) on '~'
132: reduce-reduce conflict (reduce 180, reduce 186) on ID
132: reduce-reduce conflict (reduce 180, reduce 186) on CONSTANT
132: reduce-reduce conflict (reduce 180, reduce 186) on STRING_LITERAL
132: reduce-reduce conflict (reduce 180, reduce 186) on SIZEOF
132: reduce-reduce conflict (reduce 180, reduce 186) on INC_OP
132: reduce-reduce conflict (reduce 180, reduce 186) on DEC_OP
132: reduce-reduce conflict (reduce 180, reduce 186) on CASE
132: reduce-reduce conflict (reduce 180, reduce 186) on DEFAULT
132: reduce-reduce conflict (reduce 180, reduce 186) on IF
132: reduce-reduce conflict (reduce 180, reduce 186) on ELSE
132: reduce-reduce conflict (reduce 180, reduce 186) on SWITCH
132: reduce-reduce conflict (reduce 180, reduce 186) on WHILE
132: reduce-reduce conflict (reduce 180, reduce 186) on DO
132: reduce-reduce conflict (reduce 180, reduce 186) on FOR
132: reduce-reduce conflict (reduce 180, reduce 186) on GOTO
132: reduce-reduce conflict (reduce 180, reduce 186) on CONTINUE
132: reduce-reduce conflict (reduce 180, reduce 186) on BREAK
132: reduce-reduce conflict (reduce 180, reduce 186) on RETURN
state 132
	other : labeled_statement .  (180)
	statement : labeled_statement .  (186)

	.  reduce 180


133: reduce-reduce conflict (reduce 181, reduce 187) on '!'
133: reduce-reduce conflict (reduce 181, reduce 187) on '&'
133: reduce-reduce conflict (reduce 181, reduce 187) on '('
133: reduce-reduce conflict (reduce 181, reduce 187) on '*'
133: reduce-reduce conflict (reduce 181, reduce 187) on '+'
133: reduce-reduce conflict (reduce 181, reduce 187) on '-'
133: reduce-reduce conflict (reduce 181, reduce 187) on ';'
133: reduce-reduce conflict (reduce 181, reduce 187) on '{'
133: reduce-reduce conflict (reduce 181, reduce 187) on '}'
133: reduce-reduce conflict (reduce 181, reduce 187) on '~'
133: reduce-reduce conflict (reduce 181, reduce 187) on ID
133: reduce-reduce conflict (reduce 181, reduce 187) on CONSTANT
133: reduce-reduce conflict (reduce 181, reduce 187) on STRING_LITERAL
133: reduce-reduce conflict (reduce 181, reduce 187) on SIZEOF
133: reduce-reduce conflict (reduce 181, reduce 187) on INC_OP
133: reduce-reduce conflict (reduce 181, reduce 187) on DEC_OP
133: reduce-reduce conflict (reduce 181, reduce 187) on CASE
133: reduce-reduce conflict (reduce 181, reduce 187) on DEFAULT
133: reduce-reduce conflict (reduce 181, reduce 187) on IF
133: reduce-reduce conflict (reduce 181, reduce 187) on ELSE
133: reduce-reduce conflict (reduce 181, reduce 187) on SWITCH
133: reduce-reduce conflict (reduce 181, reduce 187) on WHILE
133: reduce-reduce conflict (reduce 181, reduce 187) on DO
133: reduce-reduce conflict (reduce 181, reduce 187) on FOR
133: reduce-reduce conflict (reduce 181, reduce 187) on GOTO
133: reduce-reduce conflict (reduce 181, reduce 187) on CONTINUE
133: reduce-reduce conflict (reduce 181, reduce 187) on BREAK
133: reduce-reduce conflict (reduce 181, reduce 187) on RETURN
state 133
	other : compound_statement .  (181)
	statement : compound_statement .  (187)

	.  reduce 181


134: shift-reduce conflict (shift 88, reduce 185) on '!'
134: shift-reduce conflict (shift 89, reduce 185) on '&'
134: shift-reduce conflict (shift 90, reduce 185) on '('
134: shift-reduce conflict (shift 91, reduce 185) on '*'
134: shift-reduce conflict (shift 92, reduce 185) on '+'
134: shift-reduce conflict (shift 93, reduce 185) on '-'
134: shift-reduce conflict (shift 94, reduce 185) on ';'
134: shift-reduce conflict (shift 54, reduce 185) on '{'
134: shift-reduce conflict (shift 239, reduce 185) on '}'
134: shift-reduce conflict (shift 96, reduce 185) on '~'
134: shift-reduce conflict (shift 97, reduce 185) on ID
134: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
134: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
134: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
134: shift-reduce conflict (shift 101, reduce 185) on INC_OP
134: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
134: shift-reduce conflict (shift 103, reduce 185) on CASE
134: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
134: shift-reduce conflict (shift 105, reduce 185) on IF
134: shift-reduce conflict (shift 106, reduce 185) on SWITCH
134: shift-reduce conflict (shift 107, reduce 185) on WHILE
134: shift-reduce conflict (shift 108, reduce 185) on DO
134: shift-reduce conflict (shift 109, reduce 185) on FOR
134: shift-reduce conflict (shift 110, reduce 185) on GOTO
134: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
134: shift-reduce conflict (shift 112, reduce 185) on BREAK
134: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 134
	compound_statement : '{' statement_list . '}'
	statement_list : statement_list . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'}'  shift 239
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 240
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


135: reduce-reduce conflict (reduce 182, reduce 188) on '!'
135: reduce-reduce conflict (reduce 182, reduce 188) on '&'
135: reduce-reduce conflict (reduce 182, reduce 188) on '('
135: reduce-reduce conflict (reduce 182, reduce 188) on '*'
135: reduce-reduce conflict (reduce 182, reduce 188) on '+'
135: reduce-reduce conflict (reduce 182, reduce 188) on '-'
135: reduce-reduce conflict (reduce 182, reduce 188) on ';'
135: reduce-reduce conflict (reduce 182, reduce 188) on '{'
135: reduce-reduce conflict (reduce 182, reduce 188) on '}'
135: reduce-reduce conflict (reduce 182, reduce 188) on '~'
135: reduce-reduce conflict (reduce 182, reduce 188) on ID
135: reduce-reduce conflict (reduce 182, reduce 188) on CONSTANT
135: reduce-reduce conflict (reduce 182, reduce 188) on STRING_LITERAL
135: reduce-reduce conflict (reduce 182, reduce 188) on SIZEOF
135: reduce-reduce conflict (reduce 182, reduce 188) on INC_OP
135: reduce-reduce conflict (reduce 182, reduce 188) on DEC_OP
135: reduce-reduce conflict (reduce 182, reduce 188) on CASE
135: reduce-reduce conflict (reduce 182, reduce 188) on DEFAULT
135: reduce-reduce conflict (reduce 182, reduce 188) on IF
135: reduce-reduce conflict (reduce 182, reduce 188) on ELSE
135: reduce-reduce conflict (reduce 182, reduce 188) on SWITCH
135: reduce-reduce conflict (reduce 182, reduce 188) on WHILE
135: reduce-reduce conflict (reduce 182, reduce 188) on DO
135: reduce-reduce conflict (reduce 182, reduce 188) on FOR
135: reduce-reduce conflict (reduce 182, reduce 188) on GOTO
135: reduce-reduce conflict (reduce 182, reduce 188) on CONTINUE
135: reduce-reduce conflict (reduce 182, reduce 188) on BREAK
135: reduce-reduce conflict (reduce 182, reduce 188) on RETURN
state 135
	other : exp_statement .  (182)
	statement : exp_statement .  (188)

	.  reduce 182


136: reduce-reduce conflict (reduce 183, reduce 190) on '!'
136: reduce-reduce conflict (reduce 183, reduce 190) on '&'
136: reduce-reduce conflict (reduce 183, reduce 190) on '('
136: reduce-reduce conflict (reduce 183, reduce 190) on '*'
136: reduce-reduce conflict (reduce 183, reduce 190) on '+'
136: reduce-reduce conflict (reduce 183, reduce 190) on '-'
136: reduce-reduce conflict (reduce 183, reduce 190) on ';'
136: reduce-reduce conflict (reduce 183, reduce 190) on '{'
136: reduce-reduce conflict (reduce 183, reduce 190) on '}'
136: reduce-reduce conflict (reduce 183, reduce 190) on '~'
136: reduce-reduce conflict (reduce 183, reduce 190) on ID
136: reduce-reduce conflict (reduce 183, reduce 190) on CONSTANT
136: reduce-reduce conflict (reduce 183, reduce 190) on STRING_LITERAL
136: reduce-reduce conflict (reduce 183, reduce 190) on SIZEOF
136: reduce-reduce conflict (reduce 183, reduce 190) on INC_OP
136: reduce-reduce conflict (reduce 183, reduce 190) on DEC_OP
136: reduce-reduce conflict (reduce 183, reduce 190) on CASE
136: reduce-reduce conflict (reduce 183, reduce 190) on DEFAULT
136: reduce-reduce conflict (reduce 183, reduce 190) on IF
136: reduce-reduce conflict (reduce 183, reduce 190) on ELSE
136: reduce-reduce conflict (reduce 183, reduce 190) on SWITCH
136: reduce-reduce conflict (reduce 183, reduce 190) on WHILE
136: reduce-reduce conflict (reduce 183, reduce 190) on DO
136: reduce-reduce conflict (reduce 183, reduce 190) on FOR
136: reduce-reduce conflict (reduce 183, reduce 190) on GOTO
136: reduce-reduce conflict (reduce 183, reduce 190) on CONTINUE
136: reduce-reduce conflict (reduce 183, reduce 190) on BREAK
136: reduce-reduce conflict (reduce 183, reduce 190) on RETURN
state 136
	statement : iteration_statement .  (190)
	other : iteration_statement .  (183)

	.  reduce 183


137: reduce-reduce conflict (reduce 184, reduce 191) on '!'
137: reduce-reduce conflict (reduce 184, reduce 191) on '&'
137: reduce-reduce conflict (reduce 184, reduce 191) on '('
137: reduce-reduce conflict (reduce 184, reduce 191) on '*'
137: reduce-reduce conflict (reduce 184, reduce 191) on '+'
137: reduce-reduce conflict (reduce 184, reduce 191) on '-'
137: reduce-reduce conflict (reduce 184, reduce 191) on ';'
137: reduce-reduce conflict (reduce 184, reduce 191) on '{'
137: reduce-reduce conflict (reduce 184, reduce 191) on '}'
137: reduce-reduce conflict (reduce 184, reduce 191) on '~'
137: reduce-reduce conflict (reduce 184, reduce 191) on ID
137: reduce-reduce conflict (reduce 184, reduce 191) on CONSTANT
137: reduce-reduce conflict (reduce 184, reduce 191) on STRING_LITERAL
137: reduce-reduce conflict (reduce 184, reduce 191) on SIZEOF
137: reduce-reduce conflict (reduce 184, reduce 191) on INC_OP
137: reduce-reduce conflict (reduce 184, reduce 191) on DEC_OP
137: reduce-reduce conflict (reduce 184, reduce 191) on CASE
137: reduce-reduce conflict (reduce 184, reduce 191) on DEFAULT
137: reduce-reduce conflict (reduce 184, reduce 191) on IF
137: reduce-reduce conflict (reduce 184, reduce 191) on ELSE
137: reduce-reduce conflict (reduce 184, reduce 191) on SWITCH
137: reduce-reduce conflict (reduce 184, reduce 191) on WHILE
137: reduce-reduce conflict (reduce 184, reduce 191) on DO
137: reduce-reduce conflict (reduce 184, reduce 191) on FOR
137: reduce-reduce conflict (reduce 184, reduce 191) on GOTO
137: reduce-reduce conflict (reduce 184, reduce 191) on CONTINUE
137: reduce-reduce conflict (reduce 184, reduce 191) on BREAK
137: reduce-reduce conflict (reduce 184, reduce 191) on RETURN
state 137
	other : jump_statement .  (184)
	statement : jump_statement .  (191)

	.  reduce 184


state 138
	statement_list : statement .  (201)

	.  reduce 201


139: shift-reduce conflict (shift 88, reduce 185) on '!'
139: shift-reduce conflict (shift 89, reduce 185) on '&'
139: shift-reduce conflict (shift 90, reduce 185) on '('
139: shift-reduce conflict (shift 91, reduce 185) on '*'
139: shift-reduce conflict (shift 92, reduce 185) on '+'
139: shift-reduce conflict (shift 93, reduce 185) on '-'
139: shift-reduce conflict (shift 94, reduce 185) on ';'
139: shift-reduce conflict (shift 54, reduce 185) on '{'
139: shift-reduce conflict (shift 241, reduce 185) on '}'
139: shift-reduce conflict (shift 96, reduce 185) on '~'
139: shift-reduce conflict (shift 97, reduce 185) on ID
139: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
139: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
139: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
139: shift-reduce conflict (shift 101, reduce 185) on INC_OP
139: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
139: shift-reduce conflict (shift 103, reduce 185) on CASE
139: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
139: shift-reduce conflict (shift 105, reduce 185) on IF
139: shift-reduce conflict (shift 106, reduce 185) on SWITCH
139: shift-reduce conflict (shift 107, reduce 185) on WHILE
139: shift-reduce conflict (shift 108, reduce 185) on DO
139: shift-reduce conflict (shift 109, reduce 185) on FOR
139: shift-reduce conflict (shift 110, reduce 185) on GOTO
139: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
139: shift-reduce conflict (shift 112, reduce 185) on BREAK
139: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 139
	compound_statement : '{' declaration_list . statement_list '}'
	declaration_list : declaration_list . declaration
	compound_statement : '{' declaration_list . '}'
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'}'  shift 241
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
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
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	declaration  goto 146
	logical_and_exp  goto 124
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	exp  goto 125
	storage_class_specifier  goto 33
	logical_or_exp  goto 126
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	statement_list  goto 242
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 138
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 140
	selection_statement : stmt .  (211)

	.  reduce 211


state 141
	statement : selection_statement .  (189)

	.  reduce 189


state 142
	stmt : open_statement .  (206)

	.  reduce 206


state 143
	matched_statement : other .  (208)

	.  reduce 208


state 144
	stmt : matched_statement .  (205)

	.  reduce 205


state 145
	postfix_exp : postfix_pre_exp . ')'
	postfix_exp : postfix_pre_exp . argument_exp_list ')'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	')'  shift 243
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	argument_exp_list  goto 244
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 245
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 146
	declaration_list : declaration_list declaration .  (200)

	.  reduce 200


state 147
	function_definition : declarator declaration_list compound_statement .  (228)

	.  reduce 228


state 148
	function_definition : declaration_specifiers declarator compound_statement .  (227)

	.  reduce 227


state 149
	declaration_list : declaration_list . declaration
	function_definition : declaration_specifiers declarator declaration_list . compound_statement

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

	declaration  goto 146
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	compound_statement  goto 246


state 150
	declaration : declaration_specifiers init_declarator_list ';' .  (77)

	.  reduce 77


state 151
	direct_declarator : direct_declarator '[' ']' .  (142)

	.  reduce 142


state 152
	primary_exp : ID .  (1)

	.  reduce 1


state 153
	cast_exp : unary_exp .  (28)

	.  reduce 28


state 154
	direct_declarator : direct_declarator '[' constant_exp . ']'

	']'  shift 247


state 155
	constant_exp : conditional_exp .  (75)

	.  reduce 75


state 156
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_declarator : '(' . declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 156
	')'  shift 248
	'*'  shift 2
	'['  shift 157
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

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declarator  goto 40
	declaration_specifiers  goto 70
	direct_declarator  goto 30
	type_specifier  goto 31
	pointer  goto 159
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	parameter_list  goto 71
	parameter_type_list  goto 249
	abstract_declarator  goto 250
	parameter_declaration  goto 73
	direct_abstract_declarator  goto 161
	direct_pre_declarator  goto 36


state 157
	direct_abstract_declarator : '[' . ']'
	direct_abstract_declarator : '[' . constant_exp ']'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	']'  shift 251
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	constant_exp  goto 252
	logical_or_exp  goto 126
	conditional_exp  goto 155
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 158
	parameter_declaration : declaration_specifiers declarator .  (156)

	.  reduce 156


state 159
	declarator : pointer . direct_declarator
	abstract_declarator : pointer .  (163)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 156
	'['  shift 157
	ID  shift 3
	.  reduce 163

	direct_declarator  goto 66
	direct_abstract_declarator  goto 253
	direct_pre_declarator  goto 36


state 160
	parameter_declaration : declaration_specifiers abstract_declarator .  (157)

	.  reduce 157


state 161
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	abstract_declarator : direct_abstract_declarator .  (164)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 254
	'['  shift 255
	.  reduce 164


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
	ELLIPSIS  shift 256

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 70
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	parameter_declaration  goto 257


state 163
	direct_declarator : direct_pre_declarator parameter_type_list ')' .  (143)

	.  reduce 143


state 164
	direct_declarator : direct_pre_declarator identifier_list ')' .  (144)

	.  reduce 144


state 165
	identifier_list : identifier_list ',' . ID

	ID  shift 258


state 166
	enumerator : ID '=' . constant_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	constant_exp  goto 259
	logical_or_exp  goto 126
	conditional_exp  goto 155
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 167
	enumerator_list : enumerator_list ',' . enumerator

	ID  shift 79

	enumerator  goto 260


state 168
	enum_specifier : ENUM '{' enumerator_list '}' .  (127)

	.  reduce 127


state 169
	enum_specifier : ENUM ID '{' enumerator_list . '}'
	enumerator_list : enumerator_list . ',' enumerator

	','  shift 167
	'}'  shift 261


state 170
	struct_or_union_def : struct_or_union '{' declaration_list '}' .  (107)

	.  reduce 107


state 171
	struct_or_union_def : struct_or_union ID '{' declaration_list . '}'
	declaration_list : declaration_list . declaration

	'}'  shift 262
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

	declaration  goto 146
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 56
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35


state 172
	initializer : '{' . initializer_list ',' '}'
	initializer : '{' . initializer_list '}'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'{'  shift 172
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 173
	inclusive_or_exp  goto 131
	initializer  goto 263
	initializer_list  goto 264
	postfix_pre_exp  goto 145


state 173
	initializer : assignment_exp .  (175)

	.  reduce 175


state 174
	init_declarator : declarator '=' initializer .  (87)

	.  reduce 87


state 175
	init_declarator_list : init_declarator_list ',' init_declarator .  (85)

	.  reduce 85


state 176
	specifier_qualifier_list : type_qualifier . specifier_qualifier_list
	specifier_qualifier_list : type_qualifier .  (121)

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
	.  reduce 121

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 176
	type_specifier  goto 177
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	specifier_qualifier_list  goto 265


177: shift-reduce conflict (shift 2, reduce 119) on '*'
state 177
	specifier_qualifier_list : type_specifier . specifier_qualifier_list
	specifier_qualifier_list : type_specifier .  (119)
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
	.  reduce 119

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 176
	type_specifier  goto 177
	pointer  goto 65
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	specifier_qualifier_list  goto 266


state 178
	primary_exp : '(' exp . ')'
	exp : exp . ',' assignment_exp

	')'  shift 267
	','  shift 232


state 179
	type_name : specifier_qualifier_list . abstract_declarator
	type_name : specifier_qualifier_list .  (161)

	'('  shift 268
	'*'  shift 2
	'['  shift 157
	.  reduce 161

	pointer  goto 269
	abstract_declarator  goto 270
	direct_abstract_declarator  goto 161


state 180
	cast_exp : '(' type_name . ')' cast_exp

	')'  shift 271


181: shift-reduce conflict (shift 88, reduce 185) on '!'
181: shift-reduce conflict (shift 89, reduce 185) on '&'
181: shift-reduce conflict (shift 90, reduce 185) on '('
181: shift-reduce conflict (shift 91, reduce 185) on '*'
181: shift-reduce conflict (shift 92, reduce 185) on '+'
181: shift-reduce conflict (shift 93, reduce 185) on '-'
181: shift-reduce conflict (shift 94, reduce 185) on ';'
181: shift-reduce conflict (shift 54, reduce 185) on '{'
181: shift-reduce conflict (shift 96, reduce 185) on '~'
181: shift-reduce conflict (shift 97, reduce 185) on ID
181: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
181: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
181: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
181: shift-reduce conflict (shift 101, reduce 185) on INC_OP
181: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
181: shift-reduce conflict (shift 103, reduce 185) on CASE
181: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
181: shift-reduce conflict (shift 105, reduce 185) on IF
181: shift-reduce conflict (shift 106, reduce 185) on SWITCH
181: shift-reduce conflict (shift 107, reduce 185) on WHILE
181: shift-reduce conflict (shift 108, reduce 185) on DO
181: shift-reduce conflict (shift 109, reduce 185) on FOR
181: shift-reduce conflict (shift 110, reduce 185) on GOTO
181: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
181: shift-reduce conflict (shift 112, reduce 185) on BREAK
181: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 181
	labeled_statement : ID ':' . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 272
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 182
	primary_exp : '(' . exp ')'
	unary_exp : SIZEOF '(' . type_name ')'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
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

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 176
	type_specifier  goto 177
	exp  goto 178
	logical_or_exp  goto 126
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	conditional_exp  goto 127
	specifier_qualifier_list  goto 179
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	type_name  goto 273
	postfix_pre_exp  goto 145


state 183
	unary_exp : SIZEOF unary_exp .  (20)

	.  reduce 20


state 184
	primary_exp : '(' . exp ')'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 178
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 185
	unary_exp : INC_OP unary_exp .  (17)

	.  reduce 17


state 186
	unary_exp : DEC_OP unary_exp .  (18)

	.  reduce 18


state 187
	labeled_statement : CASE constant_exp . ':' statement

	':'  shift 274


188: shift-reduce conflict (shift 88, reduce 185) on '!'
188: shift-reduce conflict (shift 89, reduce 185) on '&'
188: shift-reduce conflict (shift 90, reduce 185) on '('
188: shift-reduce conflict (shift 91, reduce 185) on '*'
188: shift-reduce conflict (shift 92, reduce 185) on '+'
188: shift-reduce conflict (shift 93, reduce 185) on '-'
188: shift-reduce conflict (shift 94, reduce 185) on ';'
188: shift-reduce conflict (shift 54, reduce 185) on '{'
188: shift-reduce conflict (shift 96, reduce 185) on '~'
188: shift-reduce conflict (shift 97, reduce 185) on ID
188: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
188: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
188: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
188: shift-reduce conflict (shift 101, reduce 185) on INC_OP
188: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
188: shift-reduce conflict (shift 103, reduce 185) on CASE
188: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
188: shift-reduce conflict (shift 105, reduce 185) on IF
188: shift-reduce conflict (shift 106, reduce 185) on SWITCH
188: shift-reduce conflict (shift 107, reduce 185) on WHILE
188: shift-reduce conflict (shift 108, reduce 185) on DO
188: shift-reduce conflict (shift 109, reduce 185) on FOR
188: shift-reduce conflict (shift 110, reduce 185) on GOTO
188: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
188: shift-reduce conflict (shift 112, reduce 185) on BREAK
188: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 188
	labeled_statement : DEFAULT ':' . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 275
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 189
	matched_statement : IF '(' . exp ')' matched_statement ELSE matched_statement
	open_statement : IF '(' . exp ')' matched_statement ELSE open_statement
	open_statement : IF '(' . exp ')' stmt

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 276
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 190
	selection_statement : SWITCH '(' . exp ')' statement

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 277
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 191
	iteration_statement : WHILE '(' . exp ')' statement

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 278
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 192
	iteration_statement : DO statement . WHILE '(' exp ')' ';'

	WHILE  shift 279


state 193
	iteration_statement : FOR '(' . exp_statement exp_statement ')' statement
	iteration_statement : FOR '(' . exp_statement exp_statement exp ')' statement

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	exp_statement  goto 280
	postfix_pre_exp  goto 145


state 194
	jump_statement : GOTO ID . ';'

	';'  shift 281


state 195
	jump_statement : CONTINUE ';' .  (218)

	.  reduce 218


state 196
	jump_statement : BREAK ';' .  (219)

	.  reduce 219


state 197
	jump_statement : RETURN ';' .  (220)

	.  reduce 220


state 198
	exp : exp . ',' assignment_exp
	jump_statement : RETURN exp . ';'

	','  shift 232
	';'  shift 282


state 199
	additive_exp : additive_exp '+' . multiplicative_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 283
	postfix_pre_exp  goto 145


state 200
	additive_exp : additive_exp '-' . multiplicative_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 284
	postfix_pre_exp  goto 145


state 201
	shift_exp : shift_exp LEFT_OP . additive_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 285
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 202
	shift_exp : shift_exp RIGHT_OP . additive_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 286
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 203
	relational_exp : relational_exp '<' . shift_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 287
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 204
	relational_exp : relational_exp '>' . shift_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 288
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 205
	relational_exp : relational_exp LE_OP . shift_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 289
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 206
	relational_exp : relational_exp GE_OP . shift_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 290
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 207
	equality_exp : equality_exp EQ_OP . relational_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 291
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 208
	equality_exp : equality_exp NE_OP . relational_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 292
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 209
	postfix_pre_exp : postfix_exp '(' .  (5)

	.  reduce 5


state 210
	postfix_exp : postfix_exp '.' . ID

	ID  shift 293


state 211
	postfix_exp : postfix_exp '[' . exp ']'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 294
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 212
	postfix_exp : postfix_exp PTR_OP . ID

	ID  shift 295


state 213
	postfix_exp : postfix_exp INC_OP .  (12)

	.  reduce 12


state 214
	postfix_exp : postfix_exp DEC_OP .  (13)

	.  reduce 13


state 215
	assignment_operator : '=' .  (62)

	.  reduce 62


state 216
	assignment_operator : MUL_ASSIGN .  (63)

	.  reduce 63


state 217
	assignment_operator : DIV_ASSIGN .  (64)

	.  reduce 64


state 218
	assignment_operator : MOD_ASSIGN .  (65)

	.  reduce 65


state 219
	assignment_operator : ADD_ASSIGN .  (66)

	.  reduce 66


state 220
	assignment_operator : SUB_ASSIGN .  (67)

	.  reduce 67


state 221
	assignment_operator : LEFT_ASSIGN .  (68)

	.  reduce 68


state 222
	assignment_operator : RIGHT_ASSIGN .  (69)

	.  reduce 69


state 223
	assignment_operator : AND_ASSIGN .  (70)

	.  reduce 70


state 224
	assignment_operator : XOR_ASSIGN .  (71)

	.  reduce 71


state 225
	assignment_operator : OR_ASSIGN .  (72)

	.  reduce 72


state 226
	assignment_exp : unary_exp assignment_operator . assignment_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 296
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 227
	unary_exp : unary_operator cast_exp .  (19)

	.  reduce 19


state 228
	multiplicative_exp : multiplicative_exp '%' . cast_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 297
	postfix_pre_exp  goto 145


state 229
	multiplicative_exp : multiplicative_exp '*' . cast_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 298
	postfix_pre_exp  goto 145


state 230
	multiplicative_exp : multiplicative_exp '/' . cast_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 299
	postfix_pre_exp  goto 145


state 231
	logical_and_exp : logical_and_exp AND_OP . inclusive_or_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 300
	postfix_pre_exp  goto 145


state 232
	exp : exp ',' . assignment_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 301
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 233
	exp_statement : exp ';' .  (204)

	.  reduce 204


state 234
	conditional_exp : logical_or_exp '?' . exp ':' conditional_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 302
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 235
	logical_or_exp : logical_or_exp OR_OP . logical_and_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 303
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 236
	and_exp : and_exp '&' . equality_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 304
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	postfix_pre_exp  goto 145


state 237
	exclusive_or_exp : exclusive_or_exp '^' . and_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	and_exp  goto 305
	postfix_pre_exp  goto 145


state 238
	inclusive_or_exp : inclusive_or_exp '|' . exclusive_or_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	and_exp  goto 128
	exclusive_or_exp  goto 306
	postfix_pre_exp  goto 145


state 239
	compound_statement : '{' statement_list '}' .  (196)

	.  reduce 196


state 240
	statement_list : statement_list statement .  (202)

	.  reduce 202


state 241
	compound_statement : '{' declaration_list '}' .  (197)

	.  reduce 197


242: shift-reduce conflict (shift 88, reduce 185) on '!'
242: shift-reduce conflict (shift 89, reduce 185) on '&'
242: shift-reduce conflict (shift 90, reduce 185) on '('
242: shift-reduce conflict (shift 91, reduce 185) on '*'
242: shift-reduce conflict (shift 92, reduce 185) on '+'
242: shift-reduce conflict (shift 93, reduce 185) on '-'
242: shift-reduce conflict (shift 94, reduce 185) on ';'
242: shift-reduce conflict (shift 54, reduce 185) on '{'
242: shift-reduce conflict (shift 307, reduce 185) on '}'
242: shift-reduce conflict (shift 96, reduce 185) on '~'
242: shift-reduce conflict (shift 97, reduce 185) on ID
242: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
242: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
242: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
242: shift-reduce conflict (shift 101, reduce 185) on INC_OP
242: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
242: shift-reduce conflict (shift 103, reduce 185) on CASE
242: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
242: shift-reduce conflict (shift 105, reduce 185) on IF
242: shift-reduce conflict (shift 106, reduce 185) on SWITCH
242: shift-reduce conflict (shift 107, reduce 185) on WHILE
242: shift-reduce conflict (shift 108, reduce 185) on DO
242: shift-reduce conflict (shift 109, reduce 185) on FOR
242: shift-reduce conflict (shift 110, reduce 185) on GOTO
242: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
242: shift-reduce conflict (shift 112, reduce 185) on BREAK
242: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 242
	compound_statement : '{' declaration_list statement_list . '}'
	statement_list : statement_list . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'}'  shift 307
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 240
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 243
	postfix_exp : postfix_pre_exp ')' .  (8)

	.  reduce 8


state 244
	postfix_exp : postfix_pre_exp argument_exp_list . ')'
	argument_exp_list : argument_exp_list . ',' assignment_exp

	')'  shift 308
	','  shift 309


state 245
	argument_exp_list : assignment_exp .  (14)

	.  reduce 14


state 246
	function_definition : declaration_specifiers declarator declaration_list compound_statement .  (226)

	.  reduce 226


state 247
	direct_declarator : direct_declarator '[' constant_exp ']' .  (141)

	.  reduce 141


state 248
	direct_abstract_declarator : '(' ')' .  (171)

	.  reduce 171


state 249
	direct_abstract_declarator : '(' parameter_type_list . ')'

	')'  shift 310


state 250
	direct_abstract_declarator : '(' abstract_declarator . ')'

	')'  shift 311


state 251
	direct_abstract_declarator : '[' ']' .  (167)

	.  reduce 167


state 252
	direct_abstract_declarator : '[' constant_exp . ']'

	']'  shift 312


state 253
	direct_abstract_declarator : direct_abstract_declarator . '[' ']'
	direct_abstract_declarator : direct_abstract_declarator . '[' constant_exp ']'
	abstract_declarator : pointer direct_abstract_declarator .  (165)
	direct_abstract_declarator : direct_abstract_declarator . '(' ')'
	direct_abstract_declarator : direct_abstract_declarator . '(' parameter_type_list ')'

	'('  shift 254
	'['  shift 255
	.  reduce 165


state 254
	direct_abstract_declarator : direct_abstract_declarator '(' . ')'
	direct_abstract_declarator : direct_abstract_declarator '(' . parameter_type_list ')'

	')'  shift 313
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

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 70
	type_specifier  goto 31
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	parameter_list  goto 71
	parameter_type_list  goto 314
	parameter_declaration  goto 73


state 255
	direct_abstract_declarator : direct_abstract_declarator '[' . ']'
	direct_abstract_declarator : direct_abstract_declarator '[' . constant_exp ']'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	']'  shift 315
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	constant_exp  goto 316
	logical_or_exp  goto 126
	conditional_exp  goto 155
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 256
	parameter_type_list : parameter_list ',' ELLIPSIS .  (153)

	.  reduce 153


state 257
	parameter_list : parameter_list ',' parameter_declaration .  (155)

	.  reduce 155


state 258
	identifier_list : identifier_list ',' ID .  (160)

	.  reduce 160


state 259
	enumerator : ID '=' constant_exp .  (133)

	.  reduce 133


state 260
	enumerator_list : enumerator_list ',' enumerator .  (131)

	.  reduce 131


state 261
	enum_specifier : ENUM ID '{' enumerator_list '}' .  (128)

	.  reduce 128


state 262
	struct_or_union_def : struct_or_union ID '{' declaration_list '}' .  (106)

	.  reduce 106


state 263
	initializer_list : initializer .  (178)

	.  reduce 178


state 264
	initializer : '{' initializer_list . ',' '}'
	initializer_list : initializer_list . ',' initializer
	initializer : '{' initializer_list . '}'

	','  shift 317
	'}'  shift 318


state 265
	specifier_qualifier_list : type_qualifier specifier_qualifier_list .  (120)

	.  reduce 120


state 266
	specifier_qualifier_list : type_specifier specifier_qualifier_list .  (118)

	.  reduce 118


state 267
	primary_exp : '(' exp ')' .  (4)

	.  reduce 4


state 268
	direct_abstract_declarator : '(' . abstract_declarator ')'
	direct_abstract_declarator : '(' . parameter_type_list ')'
	direct_abstract_declarator : '(' . ')'

	'('  shift 268
	')'  shift 248
	'*'  shift 2
	'['  shift 157
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

	struct_or_union  goto 25
	struct_or_union_def  goto 26
	type_qualifier  goto 27
	declaration_specifiers  goto 70
	type_specifier  goto 31
	pointer  goto 269
	storage_class_specifier  goto 33
	struct_or_union_specifier  goto 34
	enum_specifier  goto 35
	parameter_list  goto 71
	parameter_type_list  goto 249
	abstract_declarator  goto 250
	parameter_declaration  goto 73
	direct_abstract_declarator  goto 161


state 269
	abstract_declarator : pointer .  (163)
	abstract_declarator : pointer . direct_abstract_declarator

	'('  shift 268
	'['  shift 157
	.  reduce 163

	direct_abstract_declarator  goto 253


state 270
	type_name : specifier_qualifier_list abstract_declarator .  (162)

	.  reduce 162


state 271
	cast_exp : '(' type_name ')' . cast_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 319
	postfix_pre_exp  goto 145


state 272
	labeled_statement : ID ':' statement .  (192)

	.  reduce 192


state 273
	unary_exp : SIZEOF '(' type_name . ')'

	')'  shift 320


274: shift-reduce conflict (shift 88, reduce 185) on '!'
274: shift-reduce conflict (shift 89, reduce 185) on '&'
274: shift-reduce conflict (shift 90, reduce 185) on '('
274: shift-reduce conflict (shift 91, reduce 185) on '*'
274: shift-reduce conflict (shift 92, reduce 185) on '+'
274: shift-reduce conflict (shift 93, reduce 185) on '-'
274: shift-reduce conflict (shift 94, reduce 185) on ';'
274: shift-reduce conflict (shift 54, reduce 185) on '{'
274: shift-reduce conflict (shift 96, reduce 185) on '~'
274: shift-reduce conflict (shift 97, reduce 185) on ID
274: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
274: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
274: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
274: shift-reduce conflict (shift 101, reduce 185) on INC_OP
274: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
274: shift-reduce conflict (shift 103, reduce 185) on CASE
274: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
274: shift-reduce conflict (shift 105, reduce 185) on IF
274: shift-reduce conflict (shift 106, reduce 185) on SWITCH
274: shift-reduce conflict (shift 107, reduce 185) on WHILE
274: shift-reduce conflict (shift 108, reduce 185) on DO
274: shift-reduce conflict (shift 109, reduce 185) on FOR
274: shift-reduce conflict (shift 110, reduce 185) on GOTO
274: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
274: shift-reduce conflict (shift 112, reduce 185) on BREAK
274: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 274
	labeled_statement : CASE constant_exp ':' . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 321
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 275
	labeled_statement : DEFAULT ':' statement .  (194)

	.  reduce 194


state 276
	exp : exp . ',' assignment_exp
	matched_statement : IF '(' exp . ')' matched_statement ELSE matched_statement
	open_statement : IF '(' exp . ')' matched_statement ELSE open_statement
	open_statement : IF '(' exp . ')' stmt

	')'  shift 322
	','  shift 232


state 277
	exp : exp . ',' assignment_exp
	selection_statement : SWITCH '(' exp . ')' statement

	')'  shift 323
	','  shift 232


state 278
	exp : exp . ',' assignment_exp
	iteration_statement : WHILE '(' exp . ')' statement

	')'  shift 324
	','  shift 232


state 279
	iteration_statement : DO statement WHILE . '(' exp ')' ';'

	'('  shift 325


state 280
	iteration_statement : FOR '(' exp_statement . exp_statement ')' statement
	iteration_statement : FOR '(' exp_statement . exp_statement exp ')' statement

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	exp_statement  goto 326
	postfix_pre_exp  goto 145


state 281
	jump_statement : GOTO ID ';' .  (217)

	.  reduce 217


state 282
	jump_statement : RETURN exp ';' .  (221)

	.  reduce 221


state 283
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '+' multiplicative_exp .  (35)

	'%'  shift 228
	'*'  shift 229
	'/'  shift 230
	.  reduce 35


state 284
	multiplicative_exp : multiplicative_exp . '*' cast_exp
	multiplicative_exp : multiplicative_exp . '%' cast_exp
	multiplicative_exp : multiplicative_exp . '/' cast_exp
	additive_exp : additive_exp '-' multiplicative_exp .  (36)

	'%'  shift 228
	'*'  shift 229
	'/'  shift 230
	.  reduce 36


state 285
	shift_exp : shift_exp LEFT_OP additive_exp .  (38)
	additive_exp : additive_exp . '+' multiplicative_exp
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 199
	'-'  shift 200
	.  reduce 38


state 286
	shift_exp : shift_exp RIGHT_OP additive_exp .  (39)
	additive_exp : additive_exp . '+' multiplicative_exp
	additive_exp : additive_exp . '-' multiplicative_exp

	'+'  shift 199
	'-'  shift 200
	.  reduce 39


state 287
	relational_exp : relational_exp '<' shift_exp .  (41)
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp

	LEFT_OP  shift 201
	RIGHT_OP  shift 202
	.  reduce 41


state 288
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp '>' shift_exp .  (42)

	LEFT_OP  shift 201
	RIGHT_OP  shift 202
	.  reduce 42


state 289
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp LE_OP shift_exp .  (43)

	LEFT_OP  shift 201
	RIGHT_OP  shift 202
	.  reduce 43


state 290
	shift_exp : shift_exp . RIGHT_OP additive_exp
	shift_exp : shift_exp . LEFT_OP additive_exp
	relational_exp : relational_exp GE_OP shift_exp .  (44)

	LEFT_OP  shift 201
	RIGHT_OP  shift 202
	.  reduce 44


state 291
	relational_exp : relational_exp . '<' shift_exp
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	equality_exp : equality_exp EQ_OP relational_exp .  (46)
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 203
	'>'  shift 204
	LE_OP  shift 205
	GE_OP  shift 206
	.  reduce 46


state 292
	relational_exp : relational_exp . '<' shift_exp
	equality_exp : equality_exp NE_OP relational_exp .  (47)
	relational_exp : relational_exp . GE_OP shift_exp
	relational_exp : relational_exp . '>' shift_exp
	relational_exp : relational_exp . LE_OP shift_exp

	'<'  shift 203
	'>'  shift 204
	LE_OP  shift 205
	GE_OP  shift 206
	.  reduce 47


state 293
	postfix_exp : postfix_exp '.' ID .  (10)

	.  reduce 10


state 294
	postfix_exp : postfix_exp '[' exp . ']'
	exp : exp . ',' assignment_exp

	','  shift 232
	']'  shift 327


state 295
	postfix_exp : postfix_exp PTR_OP ID .  (11)

	.  reduce 11


state 296
	assignment_exp : unary_exp assignment_operator assignment_exp .  (61)

	.  reduce 61


state 297
	multiplicative_exp : multiplicative_exp '%' cast_exp .  (33)

	.  reduce 33


state 298
	multiplicative_exp : multiplicative_exp '*' cast_exp .  (31)

	.  reduce 31


state 299
	multiplicative_exp : multiplicative_exp '/' cast_exp .  (32)

	.  reduce 32


state 300
	inclusive_or_exp : inclusive_or_exp . '|' exclusive_or_exp
	logical_and_exp : logical_and_exp AND_OP inclusive_or_exp .  (55)

	'|'  shift 238
	.  reduce 55


state 301
	exp : exp ',' assignment_exp .  (74)

	.  reduce 74


state 302
	conditional_exp : logical_or_exp '?' exp . ':' conditional_exp
	exp : exp . ',' assignment_exp

	','  shift 232
	':'  shift 328


state 303
	logical_and_exp : logical_and_exp . AND_OP inclusive_or_exp
	logical_or_exp : logical_or_exp OR_OP logical_and_exp .  (57)

	AND_OP  shift 231
	.  reduce 57


state 304
	equality_exp : equality_exp . NE_OP relational_exp
	equality_exp : equality_exp . EQ_OP relational_exp
	and_exp : and_exp '&' equality_exp .  (49)

	EQ_OP  shift 207
	NE_OP  shift 208
	.  reduce 49


state 305
	and_exp : and_exp . '&' equality_exp
	exclusive_or_exp : exclusive_or_exp '^' and_exp .  (51)

	'&'  shift 236
	.  reduce 51


state 306
	inclusive_or_exp : inclusive_or_exp '|' exclusive_or_exp .  (53)
	exclusive_or_exp : exclusive_or_exp . '^' and_exp

	'^'  shift 237
	.  reduce 53


state 307
	compound_statement : '{' declaration_list statement_list '}' .  (198)

	.  reduce 198


state 308
	postfix_exp : postfix_pre_exp argument_exp_list ')' .  (9)

	.  reduce 9


state 309
	argument_exp_list : argument_exp_list ',' . assignment_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 329
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 310
	direct_abstract_declarator : '(' parameter_type_list ')' .  (172)

	.  reduce 172


state 311
	direct_abstract_declarator : '(' abstract_declarator ')' .  (166)

	.  reduce 166


state 312
	direct_abstract_declarator : '[' constant_exp ']' .  (168)

	.  reduce 168


state 313
	direct_abstract_declarator : direct_abstract_declarator '(' ')' .  (173)

	.  reduce 173


state 314
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list . ')'

	')'  shift 330


state 315
	direct_abstract_declarator : direct_abstract_declarator '[' ']' .  (169)

	.  reduce 169


state 316
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp . ']'

	']'  shift 331


state 317
	initializer : '{' initializer_list ',' . '}'
	initializer_list : initializer_list ',' . initializer

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'{'  shift 172
	'}'  shift 332
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 173
	inclusive_or_exp  goto 131
	initializer  goto 333
	postfix_pre_exp  goto 145


state 318
	initializer : '{' initializer_list '}' .  (176)

	.  reduce 176


state 319
	cast_exp : '(' type_name ')' cast_exp .  (29)

	.  reduce 29


state 320
	unary_exp : SIZEOF '(' type_name ')' .  (21)

	.  reduce 21


state 321
	labeled_statement : CASE constant_exp ':' statement .  (193)

	.  reduce 193


322: shift-reduce conflict (shift 88, reduce 185) on '!'
322: shift-reduce conflict (shift 89, reduce 185) on '&'
322: shift-reduce conflict (shift 90, reduce 185) on '('
322: shift-reduce conflict (shift 91, reduce 185) on '*'
322: shift-reduce conflict (shift 92, reduce 185) on '+'
322: shift-reduce conflict (shift 93, reduce 185) on '-'
322: shift-reduce conflict (shift 94, reduce 185) on ';'
322: shift-reduce conflict (shift 54, reduce 185) on '{'
322: shift-reduce conflict (shift 96, reduce 185) on '~'
322: shift-reduce conflict (shift 97, reduce 185) on ID
322: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
322: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
322: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
322: shift-reduce conflict (shift 101, reduce 185) on INC_OP
322: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
322: shift-reduce conflict (shift 103, reduce 185) on CASE
322: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
322: shift-reduce conflict (shift 105, reduce 185) on IF
322: shift-reduce conflict (shift 107, reduce 185) on WHILE
322: shift-reduce conflict (shift 108, reduce 185) on DO
322: shift-reduce conflict (shift 109, reduce 185) on FOR
322: shift-reduce conflict (shift 110, reduce 185) on GOTO
322: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
322: shift-reduce conflict (shift 112, reduce 185) on BREAK
322: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 322
	matched_statement : IF '(' exp ')' . matched_statement ELSE matched_statement
	open_statement : IF '(' exp ')' . matched_statement ELSE open_statement
	open_statement : IF '(' exp ')' . stmt
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 334
	compound_statement  goto 335
	exp_statement  goto 336
	iteration_statement  goto 337
	jump_statement  goto 338
	stmt  goto 339
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 340
	postfix_pre_exp  goto 145


323: shift-reduce conflict (shift 88, reduce 185) on '!'
323: shift-reduce conflict (shift 89, reduce 185) on '&'
323: shift-reduce conflict (shift 90, reduce 185) on '('
323: shift-reduce conflict (shift 91, reduce 185) on '*'
323: shift-reduce conflict (shift 92, reduce 185) on '+'
323: shift-reduce conflict (shift 93, reduce 185) on '-'
323: shift-reduce conflict (shift 94, reduce 185) on ';'
323: shift-reduce conflict (shift 54, reduce 185) on '{'
323: shift-reduce conflict (shift 96, reduce 185) on '~'
323: shift-reduce conflict (shift 97, reduce 185) on ID
323: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
323: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
323: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
323: shift-reduce conflict (shift 101, reduce 185) on INC_OP
323: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
323: shift-reduce conflict (shift 103, reduce 185) on CASE
323: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
323: shift-reduce conflict (shift 105, reduce 185) on IF
323: shift-reduce conflict (shift 106, reduce 185) on SWITCH
323: shift-reduce conflict (shift 107, reduce 185) on WHILE
323: shift-reduce conflict (shift 108, reduce 185) on DO
323: shift-reduce conflict (shift 109, reduce 185) on FOR
323: shift-reduce conflict (shift 110, reduce 185) on GOTO
323: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
323: shift-reduce conflict (shift 112, reduce 185) on BREAK
323: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 323
	selection_statement : SWITCH '(' exp ')' . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 341
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


324: shift-reduce conflict (shift 88, reduce 185) on '!'
324: shift-reduce conflict (shift 89, reduce 185) on '&'
324: shift-reduce conflict (shift 90, reduce 185) on '('
324: shift-reduce conflict (shift 91, reduce 185) on '*'
324: shift-reduce conflict (shift 92, reduce 185) on '+'
324: shift-reduce conflict (shift 93, reduce 185) on '-'
324: shift-reduce conflict (shift 94, reduce 185) on ';'
324: shift-reduce conflict (shift 54, reduce 185) on '{'
324: shift-reduce conflict (shift 96, reduce 185) on '~'
324: shift-reduce conflict (shift 97, reduce 185) on ID
324: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
324: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
324: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
324: shift-reduce conflict (shift 101, reduce 185) on INC_OP
324: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
324: shift-reduce conflict (shift 103, reduce 185) on CASE
324: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
324: shift-reduce conflict (shift 105, reduce 185) on IF
324: shift-reduce conflict (shift 106, reduce 185) on SWITCH
324: shift-reduce conflict (shift 107, reduce 185) on WHILE
324: shift-reduce conflict (shift 108, reduce 185) on DO
324: shift-reduce conflict (shift 109, reduce 185) on FOR
324: shift-reduce conflict (shift 110, reduce 185) on GOTO
324: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
324: shift-reduce conflict (shift 112, reduce 185) on BREAK
324: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 324
	iteration_statement : WHILE '(' exp ')' . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 342
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 325
	iteration_statement : DO statement WHILE '(' . exp ')' ';'

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 343
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 326
	iteration_statement : FOR '(' exp_statement exp_statement . ')' statement
	iteration_statement : FOR '(' exp_statement exp_statement . exp ')' statement

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	')'  shift 344
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 345
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 327
	postfix_exp : postfix_exp '[' exp ']' .  (7)

	.  reduce 7


state 328
	conditional_exp : logical_or_exp '?' exp ':' . conditional_exp

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	'~'  shift 96
	ID  shift 152
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 153
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	logical_or_exp  goto 126
	conditional_exp  goto 346
	and_exp  goto 128
	exclusive_or_exp  goto 129
	inclusive_or_exp  goto 131
	postfix_pre_exp  goto 145


state 329
	argument_exp_list : argument_exp_list ',' assignment_exp .  (15)

	.  reduce 15


state 330
	direct_abstract_declarator : direct_abstract_declarator '(' parameter_type_list ')' .  (174)

	.  reduce 174


state 331
	direct_abstract_declarator : direct_abstract_declarator '[' constant_exp ']' .  (170)

	.  reduce 170


state 332
	initializer : '{' initializer_list ',' '}' .  (177)

	.  reduce 177


state 333
	initializer_list : initializer_list ',' initializer .  (179)

	.  reduce 179


state 334
	other : labeled_statement .  (180)

	.  reduce 180


state 335
	other : compound_statement .  (181)

	.  reduce 181


state 336
	other : exp_statement .  (182)

	.  reduce 182


state 337
	other : iteration_statement .  (183)

	.  reduce 183


state 338
	other : jump_statement .  (184)

	.  reduce 184


state 339
	open_statement : IF '(' exp ')' stmt .  (209)

	.  reduce 209


340: shift-reduce conflict (shift 347, reduce 205) on ELSE
state 340
	stmt : matched_statement .  (205)
	matched_statement : IF '(' exp ')' matched_statement . ELSE matched_statement
	open_statement : IF '(' exp ')' matched_statement . ELSE open_statement

	ELSE  shift 347
	.  reduce 205


state 341
	selection_statement : SWITCH '(' exp ')' statement .  (212)

	.  reduce 212


state 342
	iteration_statement : WHILE '(' exp ')' statement .  (213)

	.  reduce 213


state 343
	exp : exp . ',' assignment_exp
	iteration_statement : DO statement WHILE '(' exp . ')' ';'

	')'  shift 348
	','  shift 232


344: shift-reduce conflict (shift 88, reduce 185) on '!'
344: shift-reduce conflict (shift 89, reduce 185) on '&'
344: shift-reduce conflict (shift 90, reduce 185) on '('
344: shift-reduce conflict (shift 91, reduce 185) on '*'
344: shift-reduce conflict (shift 92, reduce 185) on '+'
344: shift-reduce conflict (shift 93, reduce 185) on '-'
344: shift-reduce conflict (shift 94, reduce 185) on ';'
344: shift-reduce conflict (shift 54, reduce 185) on '{'
344: shift-reduce conflict (shift 96, reduce 185) on '~'
344: shift-reduce conflict (shift 97, reduce 185) on ID
344: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
344: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
344: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
344: shift-reduce conflict (shift 101, reduce 185) on INC_OP
344: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
344: shift-reduce conflict (shift 103, reduce 185) on CASE
344: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
344: shift-reduce conflict (shift 105, reduce 185) on IF
344: shift-reduce conflict (shift 106, reduce 185) on SWITCH
344: shift-reduce conflict (shift 107, reduce 185) on WHILE
344: shift-reduce conflict (shift 108, reduce 185) on DO
344: shift-reduce conflict (shift 109, reduce 185) on FOR
344: shift-reduce conflict (shift 110, reduce 185) on GOTO
344: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
344: shift-reduce conflict (shift 112, reduce 185) on BREAK
344: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 344
	iteration_statement : FOR '(' exp_statement exp_statement ')' . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 349
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 345
	exp : exp . ',' assignment_exp
	iteration_statement : FOR '(' exp_statement exp_statement exp . ')' statement

	')'  shift 350
	','  shift 232


state 346
	conditional_exp : logical_or_exp '?' exp ':' conditional_exp .  (59)

	.  reduce 59


347: shift-reduce conflict (shift 88, reduce 185) on '!'
347: shift-reduce conflict (shift 89, reduce 185) on '&'
347: shift-reduce conflict (shift 90, reduce 185) on '('
347: shift-reduce conflict (shift 91, reduce 185) on '*'
347: shift-reduce conflict (shift 92, reduce 185) on '+'
347: shift-reduce conflict (shift 93, reduce 185) on '-'
347: shift-reduce conflict (shift 94, reduce 185) on ';'
347: shift-reduce conflict (shift 54, reduce 185) on '{'
347: shift-reduce conflict (shift 96, reduce 185) on '~'
347: shift-reduce conflict (shift 97, reduce 185) on ID
347: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
347: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
347: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
347: shift-reduce conflict (shift 101, reduce 185) on INC_OP
347: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
347: shift-reduce conflict (shift 103, reduce 185) on CASE
347: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
347: shift-reduce conflict (shift 105, reduce 185) on IF
347: shift-reduce conflict (shift 107, reduce 185) on WHILE
347: shift-reduce conflict (shift 108, reduce 185) on DO
347: shift-reduce conflict (shift 109, reduce 185) on FOR
347: shift-reduce conflict (shift 110, reduce 185) on GOTO
347: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
347: shift-reduce conflict (shift 112, reduce 185) on BREAK
347: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 347
	matched_statement : IF '(' exp ')' matched_statement ELSE . matched_statement
	open_statement : IF '(' exp ')' matched_statement ELSE . open_statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 334
	compound_statement  goto 335
	exp_statement  goto 336
	iteration_statement  goto 337
	jump_statement  goto 338
	open_statement  goto 351
	other  goto 143
	matched_statement  goto 352
	postfix_pre_exp  goto 145


state 348
	iteration_statement : DO statement WHILE '(' exp ')' . ';'

	';'  shift 353


state 349
	iteration_statement : FOR '(' exp_statement exp_statement ')' statement .  (215)

	.  reduce 215


350: shift-reduce conflict (shift 88, reduce 185) on '!'
350: shift-reduce conflict (shift 89, reduce 185) on '&'
350: shift-reduce conflict (shift 90, reduce 185) on '('
350: shift-reduce conflict (shift 91, reduce 185) on '*'
350: shift-reduce conflict (shift 92, reduce 185) on '+'
350: shift-reduce conflict (shift 93, reduce 185) on '-'
350: shift-reduce conflict (shift 94, reduce 185) on ';'
350: shift-reduce conflict (shift 54, reduce 185) on '{'
350: shift-reduce conflict (shift 96, reduce 185) on '~'
350: shift-reduce conflict (shift 97, reduce 185) on ID
350: shift-reduce conflict (shift 98, reduce 185) on CONSTANT
350: shift-reduce conflict (shift 99, reduce 185) on STRING_LITERAL
350: shift-reduce conflict (shift 100, reduce 185) on SIZEOF
350: shift-reduce conflict (shift 101, reduce 185) on INC_OP
350: shift-reduce conflict (shift 102, reduce 185) on DEC_OP
350: shift-reduce conflict (shift 103, reduce 185) on CASE
350: shift-reduce conflict (shift 104, reduce 185) on DEFAULT
350: shift-reduce conflict (shift 105, reduce 185) on IF
350: shift-reduce conflict (shift 106, reduce 185) on SWITCH
350: shift-reduce conflict (shift 107, reduce 185) on WHILE
350: shift-reduce conflict (shift 108, reduce 185) on DO
350: shift-reduce conflict (shift 109, reduce 185) on FOR
350: shift-reduce conflict (shift 110, reduce 185) on GOTO
350: shift-reduce conflict (shift 111, reduce 185) on CONTINUE
350: shift-reduce conflict (shift 112, reduce 185) on BREAK
350: shift-reduce conflict (shift 113, reduce 185) on RETURN
state 350
	iteration_statement : FOR '(' exp_statement exp_statement exp ')' . statement
	other : .  (185)

	'!'  shift 88
	'&'  shift 89
	'('  shift 90
	'*'  shift 91
	'+'  shift 92
	'-'  shift 93
	';'  shift 94
	'{'  shift 54
	'~'  shift 96
	ID  shift 97
	CONSTANT  shift 98
	STRING_LITERAL  shift 99
	SIZEOF  shift 100
	INC_OP  shift 101
	DEC_OP  shift 102
	CASE  shift 103
	DEFAULT  shift 104
	IF  shift 105
	SWITCH  shift 106
	WHILE  shift 107
	DO  shift 108
	FOR  shift 109
	GOTO  shift 110
	CONTINUE  shift 111
	BREAK  shift 112
	RETURN  shift 113
	.  reduce 185

	primary_exp  goto 114
	additive_exp  goto 115
	shift_exp  goto 116
	relational_exp  goto 117
	equality_exp  goto 118
	postfix_exp  goto 119
	unary_exp  goto 120
	unary_operator  goto 121
	cast_exp  goto 122
	multiplicative_exp  goto 123
	logical_and_exp  goto 124
	exp  goto 125
	logical_or_exp  goto 126
	conditional_exp  goto 127
	and_exp  goto 128
	exclusive_or_exp  goto 129
	assignment_exp  goto 130
	inclusive_or_exp  goto 131
	labeled_statement  goto 132
	compound_statement  goto 133
	exp_statement  goto 135
	iteration_statement  goto 136
	jump_statement  goto 137
	statement  goto 354
	stmt  goto 140
	selection_statement  goto 141
	open_statement  goto 142
	other  goto 143
	matched_statement  goto 144
	postfix_pre_exp  goto 145


state 351
	open_statement : IF '(' exp ')' matched_statement ELSE open_statement .  (210)

	.  reduce 210


state 352
	matched_statement : IF '(' exp ')' matched_statement ELSE matched_statement .  (207)

	.  reduce 207


state 353
	iteration_statement : DO statement WHILE '(' exp ')' ';' .  (214)

	.  reduce 214


state 354
	iteration_statement : FOR '(' exp_statement exp_statement exp ')' statement .  (216)

	.  reduce 216


Rules never reduced
	struct_declaration_list : struct_declaration  (114)
	struct_declaration_list : struct_declaration_list struct_declaration  (115)
	struct_declaration : specifier_qualifier_list struct_declarator_list ';'  (116)
	struct_declaration : assignment_exp struct_declarator_list ';'  (117)
	struct_declarator_list : struct_declarator  (122)
	struct_declarator_list : struct_declarator_list ',' struct_declarator  (123)
	struct_declarator : declarator  (124)
	struct_declarator : ':' constant_exp  (125)
	struct_declarator : declarator ':' constant_exp  (126)
	statement : labeled_statement  (186)
	statement : compound_statement  (187)
	statement : exp_statement  (188)
	statement : iteration_statement  (190)
	statement : jump_statement  (191)


##############################################################################
# Summary
##############################################################################

State 2 contains 3 shift-reduce conflict(s)
State 31 contains 1 shift-reduce conflict(s)
State 43 contains 3 shift-reduce conflict(s)
State 54 contains 27 shift-reduce conflict(s)
State 108 contains 1 shift-reduce conflict(s)
State 132 contains 28 reduce-reduce conflict(s)
State 133 contains 28 reduce-reduce conflict(s)
State 134 contains 27 shift-reduce conflict(s)
State 135 contains 28 reduce-reduce conflict(s)
State 136 contains 28 reduce-reduce conflict(s)
State 137 contains 28 reduce-reduce conflict(s)
State 139 contains 27 shift-reduce conflict(s)
State 177 contains 1 shift-reduce conflict(s)
State 181 contains 26 shift-reduce conflict(s)
State 188 contains 26 shift-reduce conflict(s)
State 242 contains 27 shift-reduce conflict(s)
State 274 contains 26 shift-reduce conflict(s)
State 322 contains 25 shift-reduce conflict(s)
State 323 contains 26 shift-reduce conflict(s)
State 324 contains 26 shift-reduce conflict(s)
State 340 contains 1 shift-reduce conflict(s)
State 344 contains 26 shift-reduce conflict(s)
State 347 contains 25 shift-reduce conflict(s)
State 350 contains 26 shift-reduce conflict(s)


84 token(s), 72 nonterminal(s)
230 grammar rule(s), 355 state(s)


##############################################################################
# End of File
##############################################################################
