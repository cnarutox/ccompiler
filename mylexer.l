%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018��10��28��
****************************************************************************/

#include "myparser.h"
#include "define.h"

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
{annotation}	{comment(yytext);}
{single}	{comment(yytext);}
{literal}   {reserve(LITERAL, yytext);}
\n			{Line++;}
void		{reserve(VOID, yytext); }
main		{reserve(MAIN, yytext); }
":"         {reserve(COLON, yytext);}
"("			{reserve(LP, yytext); }
")"			{reserve(RP, yytext); }
"{"			{reserve(LBRACE, yytext); }
"}"			{reserve(RBRACE, yytext); }
"["			{reserve(RBRACE, yytext); }
"]"			{reserve(RBRACE, yytext); }
int|float|char|double|short	{reserve(TYPE, yytext); }
;			{reserve(SEMICOL, yytext); }
for			{reserve(FOR, yytext); }
"="			{reserve(ASSIGN, yytext); }
{number}+{id}	{reserve(ERROR, yytext);}
{number}	{reserve(NUMBER, yytext); yylval = atoi(yytext); return NUMBER; }
"<"|">"|"<="|">="|"!="|"==" {reserve(COMPARISON, yytext);}
"+"			{reserve(ADD, yytext); yylval = yytext[0]; return yytext[0];}
"-"			{reserve(MINUS, yytext); }
"/"			{reserve(DIVIDE, yytext);}
&|"|"|~|"^"	{reserve(LOGIC, yytext);}
&&|"||"|!	{reserve(BOOLOP, yytext);}
if			{reserve(IF, yytext); }
"*"			{reserve(MUTIPLY, yytext); }
then        {reserve(THEN, yytext);}     
break       {reserve(BREAK, yytext);}
case        {reserve(CASE, yytext);}
const       {reserve(CONST, yytext);}
continue    {reserve(CONTINUE, yytext);}
default     {reserve(DEFAULT, yytext);}
do          {reserve(DO, yytext);}
else        {reserve(ELSE, yytext);}
enum        {reserve(ENUM, yytext);}
extern      {reserve(EXTERN, yytext);}
for         {reserve(FOR, yytext);}
goto        {reserve(GOTO, yytext);}
return      {reserve(RETURN, yytext);}
register    {reserve(REGISTER, yytext);}
signed      {reserve(SIGNED, yytext);}
unsigned    {reserve(UNSIGNED, yytext);}
sizeof      {reserve(SIZEOF, yytext);}
static      {reserve(STATIC, yytext);}
struct      {reserve(STRUCT, yytext);}
switch      {reserve(SWITCH, yytext);}
typedef     {reserve(TYPEDEF, yytext);}
union       {reserve(UNION, yytext);}
volatile    {reserve(VOLATILE, yytext);}
while       {reserve(WHILE, yytext);}
{id}		{reserve(ID, yytext);}
.			{reserve(ERROR, yytext);}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section

