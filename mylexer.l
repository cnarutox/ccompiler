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
string Words[] = { "END", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID", "SEMICOL", "FOR", "ASSIGN", "NUMBER", "LESS", "ADD", "MINUS", "IF", "MORE", "MUTIPLY", "DIVIDE" };
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
"("			{reserve(LP, yytext); }
")"			{reserve(RP, yytext); }
"{"			{reserve(LBRACE, yytext); }
"}"			{reserve(RBRACE, yytext); }
int|float	{reserve(TYPE, yytext); }
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
{id}		{reserve(ID, yytext);}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section

