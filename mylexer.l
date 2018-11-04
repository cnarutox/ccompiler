%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018��10��28��
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
#define COMPARISON 13
#define ADD 14
#define MINUS 15
#define IF 16
#define ANNOTATION 17
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
#define GOTO 30
#define RETURN 31
#define REGISTER 32
#define SIGNED 33
#define SIZEOF 34
#define STATIC 35
#define STRUCT 36
#define SWITCH 37
#define TYPEDEF 38
#define UNION 39
#define UNSIGNED 40
#define VOLATILE 41
#define WHILE 42
#define COLON 43
#define LITERAL 44
string Words[] = {
    "END", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID",
    "SEMICOL", "FOR", "ASSIGN", "NUMBER", "COMPARISON", "ADD", "MINUS", "IF", "ANNOTATION",
    "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST", "CONTINUE",
    "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "GOTO", "RETURN", "REGISTER",
    "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDE", "UNION ",
    "UNSIGN", "VOLATI", "WHILE", "COLON", "LITERAL"
};
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
	// �Ѵ��ڷ��ű���
	for (int i = 0; i < symbols.size(); i++)
		if (symbols[i].element == element)
		{
			switch (word)
			{
				case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols[i] << endl; return;
				case NUMBER: 
				case LITERAL: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
				default:
					cout << Words[word] << "\t\t" << element << endl; return;
			}
		}
	//δ���ڷ��ű���
	symbols.push_back(Symbol(word, element));
	switch (word)
	{
		case ID: cout << Words[word] << "\t\t" << element << "\t\t" << &symbols.back() << endl; return;
		case NUMBER: 
		case LITERAL: cout << Words[word] << "\t\t" << element << "\t\t" << element << endl; return;
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
letter	[A-Za-z_]
digit	[0-9]
id		{letter}({letter}|{digit})*
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
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
{annotation}	{printf("%s\n", yytext);}
{single}	{printf("%s\n", yytext);}
{literal}   {reserve(LITERAL, yytext);}
void		{reserve(VOID, yytext); }
main		{reserve(MAIN, yytext); }
":"         {reserve(COLON, yytext);}
"("			{reserve(LP, yytext); }
")"			{reserve(RP, yytext); }
"{"			{reserve(LBRACE, yytext); }
"}"			{reserve(RBRACE, yytext); }
int|float|char|double|short	{reserve(TYPE, yytext); }
;			{reserve(SEMICOL, yytext); }
for			{reserve(FOR, yytext); }
"="			{reserve(ASSIGN, yytext); }
{number}+{id}	{reserve(END, yytext);}
{number}	{reserve(NUMBER, yytext); }
"<"|">"|"<="|">="|"!="|"==" {reserve(COMPARISON, yytext);}
"+"			{reserve(ADD, yytext); }
"-"			{reserve(MINUS, yytext); }
"/"			{reserve(DIVIDE, yytext);}
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
.			{reserve(END, yytext);}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section

