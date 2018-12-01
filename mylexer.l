%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018��10��28��
****************************************************************************/

#include "myparser.h"
#include "define.h"
extern struct node {
	string name;
	int value;
	int length;
	node** children;
	node(int v = 0, string n = "")
	{
		value = v;
		name = n;
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
{annotation}	{}
{single}	{}
{literal}   {}
\n			{Line++;}
void		{yylval.ntnode = new node(VOID); 	return VOID; }
main		{yylval.ntnode = new node(MAIN); 	return MAIN; }
":"         {yylval.ntnode = new node(':'); 	return ':'; }
"("			{yylval.ntnode = new node('('); 	return '('; }
")"			{yylval.ntnode = new node(')'); 	return ')'; }
"{"			{yylval.ntnode = new node('{'); 	return '{'; }
"}"			{yylval.ntnode = new node('}'); 	return '}'; }
"["			{yylval.ntnode = new node('['); 	return '['; }
"]"			{yylval.ntnode = new node(']'); 	return ']'; }
int 		{yylval.ntnode = new node(INT); 	return INT; }
float		{yylval.ntnode = new node(FLOAT); 	return FLOAT; }
char		{yylval.ntnode = new node(CHAR); 	return CHAR; }
double		{yylval.ntnode = new node(DOUBLE); 	return DOUBLE; }
short		{yylval.ntnode = new node(SHORT); 	return SHORT; }
;			{yylval.ntnode = new node(';'); 	return ';'; }
for			{yylval.ntnode = new node(FOR); 	return FOR; }
"="			{yylval.ntnode = new node(FOR); 	return FOR; }
{number}+{id}	{return -1;}
{number}	{yylval.ntnode = new node(NUMBER);	return NUMBER; }
"<"
">"
"<="
">="
"!="
// "==" 		{yylval.ntnode = new node(COMPARISON);	return COMPARISON; }
"+"			{yylval.ntnode = new node('+');		return '+'; }
"-"			{yylval.ntnode = new node('-');		return '-'; }
"/"			{yylval.ntnode = new node('/');		return '/'; }
"*"			{yylval.ntnode = new node('*');		return '*'; }
// &|"|"|~|"^"	{yylval.ntnode = new node(LOGIC);	return LOGIC; }
// &&|"||"|!	{yylval.ntnode = new node(BOOLOP);	return BOOLOP; }
if			{yylval.ntnode = new node(IF);		return IF; }
break       {yylval.ntnode = new node(BREAK);	return BREAK;}
case        {yylval.ntnode = new node(CASE);	return CASE;}
const       {yylval.ntnode = new node(CONST);	return CONST;}
continue    {yylval.ntnode = new node(CONTINUE);return CONTINUE;}
default     {yylval.ntnode = new node(DEFAULT);	return DEFAULT;}
do          {yylval.ntnode = new node(DO);		return DO;}
else        {yylval.ntnode = new node(ELSE);	return ELSE;}
enum        {yylval.ntnode = new node(ENUM);	return ENUM;}
extern      {yylval.ntnode = new node(EXTERN);	return EXTERN;}
goto        {yylval.ntnode = new node(GOTO);	return GOTO;}
return      {yylval.ntnode = new node(RETURN);	return RETURN;}
register    {yylval.ntnode = new node(REGISTER);return REGISTER;}
signed      {yylval.ntnode = new node(SIGNED);	return SIGNED;}
unsigned    {yylval.ntnode = new node(UNSIGNED);return UNSIGNED;}
sizeof      {yylval.ntnode = new node(SIZEOF);	return SIZEOF;}
static      {yylval.ntnode = new node(STATIC);	return STATIC;}
struct      {yylval.ntnode = new node(STRUCT);	return STRUCT;}
switch      {yylval.ntnode = new node(SWITCH);	return SWITCH;}
typedef     {yylval.ntnode = new node(TYPEDEF);	return TYPEDEF;}
union       {yylval.ntnode = new node(UNION);	return UNION;}
volatile    {yylval.ntnode = new node(VOLATILE);return VOLATILE;}
while       {yylval.ntnode = new node(WHILE);	return WHILE;}
// {id}		{reserve(ID, yytext); yylval.ntnode = new node(ID);	return ID;}
.			{return -1;}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section

