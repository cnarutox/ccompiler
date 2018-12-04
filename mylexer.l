%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018��10��28��
****************************************************************************/

#include "myparser.h"
#include "define.h"
extern int flag;
extern struct node {
	int id;
	string name;
	string value;
	int length;
	node** children;
	node(string n = "", string v = "")
	{
		length = 0;
		id = flag++;
		name = n;
		value = v;
	}
};
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
delim	[ \t]
ws		{delim}+
letter	[A-Za-z_]
digit	[0-9]
id		{letter}({letter}|{digit})*
number	{digit}+(\.{digit}+)?([Ee][+-]?{digit}+)?
literal \"(\\.|[^"\\])*\"
annotation "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"
single \/\/[^\n]*
%%
/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{ws}		{}
// {annotation}	{}
// {single}	{}
// {literal}   {yylval.ntnode = new(STRING_LITERAL); 	return STRING_LITERAL;}
\n			{Line++;}
void		{yylval.ntnode = new node("VOID"); 			return VOID; }
":"         {yylval.ntnode = new node(":"); 		return ':'; }
","         {yylval.ntnode = new node(","); 		return ','; }
"("			{yylval.ntnode = new node("("); 		return '('; }
")"			{yylval.ntnode = new node(")"); 		return ')'; }
"{"			{yylval.ntnode = new node("{"); 		return '{'; }
"}"			{yylval.ntnode = new node("}"); 		return '}'; }
"["			{yylval.ntnode = new node("["); 		return '['; }
"]"			{yylval.ntnode = new node("]"); 		return ']'; }
int 		{yylval.ntnode = new node("INT"); 			return INT; }
float		{yylval.ntnode = new node("FLOAT"); 		return FLOAT; }
char		{yylval.ntnode = new node("CHAR"); 		return CHAR; }
double		{yylval.ntnode = new node("DOUBLE"); 		return DOUBLE; }
short		{yylval.ntnode = new node("SHORT"); 		return SHORT; }
;			{yylval.ntnode = new node(";"); 		return ';'; }
for			{yylval.ntnode = new node("FOR"); 			return FOR; }
"="			{yylval.ntnode = new node("="); 		return '='; }
{number}+{id}	{return -1;}
{number}	{yylval.ntnode = new node("CONSTANT", yytext);	return CONSTANT; }
"<"			{yylval.ntnode = new node("<");			return '<'; }
">"			{yylval.ntnode = new node(">");			return '>'; }
"<="        {yylval.ntnode = new node("LE_OP");			return LE_OP; }
">="        {yylval.ntnode = new node("GE_OP");			return GE_OP; }
">>="       {yylval.ntnode = new node("RIGHT_ASSIGN");return RIGHT_ASSIGN; }
"<<="       {yylval.ntnode = new node("LEFT_ASSIGN");		return LEFT_ASSIGN; }
"!="        {yylval.ntnode = new node("NE_OP");			return NE_OP; }
"==" 		{yylval.ntnode = new node("EQ_OP");			return EQ_OP; }
"+"			{yylval.ntnode = new node("+");			return '+'; }
"-="		{yylval.ntnode = new node("SUB_ASSIGN");	return SUB_ASSIGN;}
"->"        {yylval.ntnode = new node("PTR_OP"); 		return PTR_OP;}
"++"		{yylval.ntnode = new node("INC_OP"); 		return INC_OP;}
"--"		{yylval.ntnode = new node("DEC_OP"); 		return DEC_OP;}
"*="		{yylval.ntnode = new node("MUL_ASSIGN");	return MUL_ASSIGN;}
"/="		{yylval.ntnode = new node("DIV_ASSIGN");	return DIV_ASSIGN;}
"%="		{yylval.ntnode = new node("MOD_ASSIGN");	return MOD_ASSIGN;}
"+="		{yylval.ntnode = new node("ADD_ASSIGN");    return ADD_ASSIGN;}
"-"			{yylval.ntnode = new node("-");			return '-'; }
"/"			{yylval.ntnode = new node("/");			return '/'; }
"*"			{yylval.ntnode = new node("*");			return '*'; }
"&"			{yylval.ntnode = new node("&");			return '&'; }
"|"         {yylval.ntnode = new node("|");			return '|'; }
"~"			{yylval.ntnode = new node("~");			return '~'; }
"^"			{yylval.ntnode = new node("^");			return '^'; }
"&&"			{yylval.ntnode = new node("AND_OP");	return AND_OP; }
"||"		{yylval.ntnode = new node("OR_OP");			return OR_OP; }
// !			{yylval.ntnode = new node(BOOLOP);	printf("BOOLOP");	return BOOLOP; }
if			{yylval.ntnode = new node("IF");			return IF; }
break       {yylval.ntnode = new node("BREAK");			return BREAK;}
case        {yylval.ntnode = new node("CASE");			return CASE;}
const       {yylval.ntnode = new node("CONST");			return CONST;}
continue    {yylval.ntnode = new node("CONTINUE");		return CONTINUE;}
default     {yylval.ntnode = new node("DEFAULT");		return DEFAULT;}
do          {yylval.ntnode = new node("DO");			return DO;}
else        {yylval.ntnode = new node("ELSE");			return ELSE;}
// extern      {yylval.ntnode = new node(EXTERN);	printf("EXTERN");	return EXTERN;}
goto        {yylval.ntnode = new node("GOTO");			return GOTO;}
return      {yylval.ntnode = new node("RETURN");		return RETURN;}
register    {yylval.ntnode = new node("REGISTER");		return REGISTER;}
signed      {yylval.ntnode = new node("SIGNED");		return SIGNED;}
unsigned    {yylval.ntnode = new node("UNSIGNED");	return UNSIGNED;}
sizeof      {yylval.ntnode = new node("SIZEOF");		return SIZEOF;}
static      {yylval.ntnode = new node("STATIC");		return STATIC;}
struct      {yylval.ntnode = new node("STRUCT");		return STRUCT;}
switch      {yylval.ntnode = new node("SWITCH");		return SWITCH;}
typedef     {yylval.ntnode = new node("TYPEDEF");		return TYPEDEF;}
union       {yylval.ntnode = new node("UNION");			return UNION;}
volatile    {yylval.ntnode = new node("VOLATILE"); 		return VOLATILE;}
while      	{yylval.ntnode = new node("WHILE");			return WHILE;}
enum		{yylval.ntnode = new node("ENUM"); 			return ENUM;}
ellipsis	{yylval.ntnode = new node("ELLIPSIS");	    return ELLIPSIS;}
{id}		{yylval.ntnode = new node("ID", yytext);	return ID;}
.			{return -1;}
%%  
/////////////////////////////////////////////////////////////////////////////
// programs section
 