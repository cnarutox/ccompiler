%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018年10月28日
****************************************************************************/

#include "myparser.h"
#include <vector>
#include <string>
using namespace std;
#define END 0
#define VOID 1
#define MAIN 2
#define LP 3  
#define RP 4
#define LBRACE 5
#define RBRACE 6
#define TYPE 7
#define ID 8
#define SEMICOL 9
#define FOR 10
#define ASSIGN 11
#define NUMBER 12
#define LESS 13
#define ADD 14
#define MINUS 15
#define IF 16
#define MORE 17
#define MUTIPLY 18
#define DIVIDE 19
#define THEN 20
#define BREAK 21
#define CASE 22
#define CONST 23
#define CONTINUE 24
#define DEFAULT 25
#define DO 26
#define ELSE 27
#define ENUM 28
#define EXTERN 29
#define FOR 30
#define GOTO 31
#define RETURN 32
#define REGISTER 33
#define SIGNED 34
#define SIZEOF 35
#define STATIC 36
#define STRUCT 37
#define SWITCH 38
#define TYPEDEF 39
#define UNION 40
#define UNSIGNED 41
#define VOLATILE 42
#define WHILE 43
#define COLON 44
string Words[] = { "END", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID", "SEMICOL", "FOR", "ASSIGN", "NUMBER", "LESS", "ADD", "MINUS", "IF", "MORE", "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST", "CONTINUE", "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "FOR", "GOTO", "RETURN", "REGISTER", "COLON"};
struct Symbol
{
	Symbol(int word, string element, string value = "") :word(word), element(element), value(value) {}
	int word;
	string element;
	string value;
};
vector<Symbol> symbols;
void reserve(int word, string element)
{
	// 已存在符号表中
	for (int i = 0; i < symbols.size(); i++)
		if (symbols[i].element == element)
		{
			switch (word)
			{
				case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols[i] << endl; return;
				case NUMBER: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
				default:
					cout << Words[word] << "\t\t" << element << endl; return;
			}
		}
	//未存在符号表中
	symbols.push_back(Symbol(word, element));
	switch (word)
	{
		case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols.back() << endl; return;
		case NUMBER: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
		default:
			cout << Words[word] << "\t\t" << element << endl; return;
	}
}

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
delim	[ \t\n]
ws		{delim}+
letter	[A-Za-z]
digit	[0-9]
id		{letter}({letter}|{digit})*
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
%%
/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{ws}		{}
void		{reserve(VOID, yytext); }
main		{reserve(MAIN, yytext); }
":"         {reverve(COLON, yytext);}
"("			{reserve(LP, yytext); }
")"			{reserve(RP, yytext); }
"{"			{reserve(LBRACE, yytext); }
"}"			{reserve(RBRACE, yytext); }
int|float|char|double|float|short	{reserve(TYPE, yytext); }
;			{reserve(SEMICOL, yytext); }
for			{reserve(FOR, yytext); }
"="			{reserve(ASSIGN, yytext); }
{number}	{reserve(NUMBER, yytext); }
"<"			{reserve(LESS, yytext); }
"+"			{reserve(ADD, yytext); }
"-"			{reserve(MINUS, yytext); }
if			{reserve(IF, yytext); }
">"			{reserve(MORE, yytext); }
"*"			{reserve(MUTIPLY, yytext); }
"/"			{reserve(DIVIDE, yytext); }
then        {reverve(THEN, yytext);}     
break       {reverve(BREAK, yytext);}
case        {reverve(CASE, yytext);}
const       {reverve(CONST, yytext);}
continue    {reverve(CONTINUE, yytext);}
default     {reverve(DEFAULT, yytext);}
do          {reverve(DO, yytext);}
else        {reverve(DOUBLE, yytext);}
enum        {reverve(ENUM, yytextt);}
extern      {reverve(EXTERN, yytext);}
for         {reverve(FLOAT, yytext);}
goto        {reverve(GOTO, yytext);}
return      {reverve(RETURN, yytext);}
register    {reverve(REGISTER, yytext);}
signed      {reverve(SHORT, yytext);}
unsigned    {reverve(UNSIGNED, yytext);}
sizeof      {reverve(SIZEOF, yytext);}
static      {reverve(STATIC, yytext);}
struct      {reverve(STRUCT, yytext);}
switch      {reverve(SWITVH, yytext);}
typedef     {reverve(TYPEDEF, yytext);}
union       {reverve(TYPEDEF, yytext);}
volatile    {reverve(VOLATILE, yytext);}
while       {reverve(WHILE, yytext);}
{id}		{reserve(ID, yytext);}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section

