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
	node** children;
	node(int v = 0, string n = '')
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
":"         {yylval.ntnode = new node(COLON); 	return COLON; }
"("			{yylval.ntnode = new node(LBRACE); 	return LBRACE; }
")"			{yylval.ntnode = new node(RBRACE); 	return RBRACE; }
"{"			{yylval.ntnode = new node(LP); 		return LP; }
"}"			{yylval.ntnode = new node(RP); 		return RP; }
"["			{yylval.ntnode = new node(LS); 		return LSQUBRAC; }
"]"			{yylval.ntnode = new node(RS); 		return RSQUBRAC; }
int 		{yylval.ntnode = new node(INT); 	return INT; }
float		{yylval.ntnode = new node(FLOAT); 	return FLOAT; }
char		{yylval.ntnode = new node(CHAR); 	return CHAR; }
double		{yylval.ntnode = new node(DOUBLE); 	return DOUBLE; }
short		{yylval.ntnode = new node(SHORT); 	return SHORT; }
;			{yylval.ntnode = new node(SEMICOL); return SHORT; }
for			{yylval.ntnode = new node(FOR); 	return FOR; }
"="			{yylval.ntnode = new node(FOR); 	return FOR; }
{number}+{id}	{retrun ERROR;}
{number}	{yylval.ntnode = new node(NUMBER);	return NUMBER; }
"<"
">"
"<="
">="
"!="
"==" 		{yylval.ntnode = new node(COMPARISON);	retrun COMPARISON; }
"+"			{yylval.ntnode = new node(ADD);		retrun ADD; return ADD; }
"-"			{yylval.ntnode = new node(MINUS);	retrun MINUS; }
"/"			{yylval.ntnode = new node(DIVIDE);	retrun DIVIDE; }
&|"|"|~|"^"	{yylval.ntnode = new node(LOGIC);	retrun LOGIC; }
&&|"||"|!	{yylval.ntnode = new node(BOOLOP);	retrun BOOLOP; }
if			{yylval.ntnode = new node(IF);		retrun IF; }
"*"			{yylval.ntnode = new node(MUTIPLY);	retrun MUTIPLY; }
then        {yylval.ntnode = new node(THEN);	retrun THEN;}     
break       {yylval.ntnode = new node(BREAK);	retrun BREAK;}
case        {yylval.ntnode = new node(CASE);	retrun CASE;}
const       {yylval.ntnode = new node(CONST);	retrun CONST;}
continue    {yylval.ntnode = new node(CONTINUE);retrun CONTINUE;}
default     {yylval.ntnode = new node(DEFAULT);	retrun DEFAULT;}
do          {yylval.ntnode = new node(DO);		retrun DO;}
else        {yylval.ntnode = new node(ELSE);	retrun ELSE;}
enum        {yylval.ntnode = new node(ENUM);	retrun ENUM;}
extern      {yylval.ntnode = new node(EXTERN);	retrun EXTERN;}
goto        {yylval.ntnode = new node(GOTO);	retrun GOTO;}
return      {yylval.ntnode = new node(RETURN);	retrun RETURN;}
register    {yylval.ntnode = new node(REGISTER);retrun REGISTER;}
signed      {yylval.ntnode = new node(SIGNED);	retrun SIGNED;}
unsigned    {yylval.ntnode = new node(UNSIGNED);retrun UNSIGNED;}
sizeof      {yylval.ntnode = new node(SIZEOF);	retrun SIZEOF;}
static      {yylval.ntnode = new node(STATIC);	retrun STATIC;}
struct      {yylval.ntnode = new node(STRUCT);	retrun STRUCT;}
switch      {yylval.ntnode = new node(SWITCH);	retrun SWITCH;}
typedef     {yylval.ntnode = new node(TYPEDEF);	retrun TYPEDEF;}
union       {yylval.ntnode = new node(UNION);	retrun UNION;}
volatile    {yylval.ntnode = new node(VOLATILE);retrun VOLATILE;}
while       {yylval.ntnode = new node(WHILE);	retrun WHILE;}
{id}		{reserve(ID, yytext); yylval.ntnode = new node(ID);	retrun ID;}
.			{retrun ERROR;}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section

