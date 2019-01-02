%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date:2018??10??28??
****************************************************************************/
#include <map>
#include <vector>

#include "myparser.h"
#include "stdlib.h"
int Line = 1;
extern int offset;
extern struct typenode
{
    int addr;
    int width;
    string name;
    typenode *left;
    typenode *right;
    typenode(string n = "", int w = 0)
    {
        name = n;
        left = NULL;
        right = NULL;
        width = w;
        addr = offset;
        // cout << endl << "------------------offset:" << offset <<"-----------------"<<endl;
    }
    void copy(const typenode &type)
    {
        name = type.name;
        width = type.width;
        left = type.left;
        right = type.right;
    }
};
extern struct varmap
{
    int name;
    varmap *parent;
    map<string, typenode*> vartable;
    varmap(int n = 0, varmap *p = NULL)
    {
        name = n;
        parent = p;
    }
};
extern varmap *varmap_temp;
extern vector<varmap*> s;
extern struct node
{
    int id;
    string name;
    double dvalue;
    int length;
    node **children;
    typenode type;
    varmap *args;
    int instr;
    vector<int>* nextlist;
    vector<int>* falselist;
    vector<int>* truelist;
    node(string n = "")
    {
        length = 0;
        name = n;
        nextlist = new vector<int>();
        falselist = new vector<int>();
        truelist = new vector<int>();
    }
};


void comment(string val)
{
    for (int i = 0; i < val.length(); i++)
        if (val[i] == '\n')
            Line++;
    ////cout << val << endl;
}
int sign=0;
void push_into_s(varmap *args) {
    args = new varmap(sign++, s[s.size() - 1]);
    s.push_back(args);
}

void Lex(YYSTYPE YYFAR& yylval, string s)
{
    yylval.ntnode = new node(s);
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
delim	[ \t]
ws		{delim}+
letter	[A-Za-z_]
digit	[0-9]
id		{letter}({letter}|{digit})*
number	(-)?{digit}+(\.{digit}+)?([Ee][+-]?{digit}+)?
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
// {literal}   {yylval.ntnode = new node(STRING_LITERAL); 	return STRING_LITERAL;}
\n			{Line++;}
void		{Lex(yylval, "VOID"); 			return VOID; }
":"         {Lex(yylval, ":"); 		        return ':'; }
"."			{Lex(yylval, ".");	            return '.';}
","         {Lex(yylval, ","); 		        return ','; }
"("			{Lex(yylval, "(");              push_into_s(yylval.ntnode->args);       return '('; }
")"			{Lex(yylval, ")"); 		        return ')'; }
"{"			{Lex(yylval, "{");              push_into_s(yylval.ntnode->args);       return '{'; }
"}"			{Lex(yylval, "}");              varmap_temp = s[s.size() - 1];     s.pop_back();   return '}'; }
"["			{Lex(yylval, "["); 		        return '['; }
"]"			{Lex(yylval, "]"); 		        return ']'; }
int 		{Lex(yylval, "INT"); 		    return INT; }
float		{Lex(yylval, "FLOAT"); 	        return FLOAT; }
char		{Lex(yylval, "CHAR"); 		    return CHAR; }
double		{Lex(yylval, "DOUBLE"); 	    return DOUBLE; }
short		{Lex(yylval, "SHORT"); 		    return SHORT; }
;			{Lex(yylval, ";"); 		        return ';'; }
for			{Lex(yylval, "FOR");            push_into_s(yylval.ntnode->args);       return FOR; }
"="			{Lex(yylval, "="); 		        return '='; }
{number}+{id}	{return -1;}
{number}	{Lex(yylval, yytext);           yylval.ntnode->dvalue = atof(yytext);   return CONSTANT; }
"<"			{Lex(yylval, "<");			    return '<'; }
">"			{Lex(yylval, ">");			    return '>'; }
"<="        {Lex(yylval, "LE_OP");			return LE_OP; }
">="        {Lex(yylval, "GE_OP");			return GE_OP; }
"&="        {Lex(yylval, "AND_ASSIGN");     return AND_ASSIGN; }
"|="        {Lex(yylval, "OR_ASSIGN");      return OR_ASSIGN; }
"^="        {Lex(yylval, "XOR_ASSIGN");     return XOR_ASSIGN; }
">>="       {Lex(yylval, "RIGHT_ASSIGN");   return RIGHT_ASSIGN; }
"<<="       {Lex(yylval, "LEFT_ASSIGN");	return LEFT_ASSIGN; }
"!="        {Lex(yylval, "NE_OP");			return NE_OP; }
"==" 		{Lex(yylval, "EQ_OP");			return EQ_OP; }
"+"			{Lex(yylval, "+");			    return '+'; }
"%"			{Lex(yylval, "%");			    return '%'; }
"-="		{Lex(yylval, "SUB_ASSIGN");	    return SUB_ASSIGN;}
"->"        {Lex(yylval, "PTR_OP"); 		return PTR_OP;}
"++"		{Lex(yylval, "INC_OP"); 		return INC_OP;}
"--"		{Lex(yylval, "DEC_OP"); 		return DEC_OP;}
"*="		{Lex(yylval, "MUL_ASSIGN");     return MUL_ASSIGN;}
"/="		{Lex(yylval, "DIV_ASSIGN");	    return DIV_ASSIGN;}
"%="		{Lex(yylval, "MOD_ASSIGN");	    return MOD_ASSIGN;}
"+="		{Lex(yylval, "ADD_ASSIGN");     return ADD_ASSIGN;}
"-"			{Lex(yylval, "-");			    return '-'; }
"/"			{Lex(yylval, "/");			    return '/'; }
"*"			{Lex(yylval, "*");			    return '*'; }
"&"			{Lex(yylval, "&");			    return '&'; }
"|"         {Lex(yylval, "|");			    return '|'; }
"~"			{Lex(yylval, "~");			    return '~'; }
"^"			{Lex(yylval, "^");			    return '^'; }
"&&"		{Lex(yylval, "AND_OP");	        return AND_OP; }
"||"		{Lex(yylval, "OR_OP");			return OR_OP; }
"!"     	{Lex(yylval, "!");			    return '!';}
if			{Lex(yylval, "IF");             return IF; }
break       {Lex(yylval, "BREAK");			return BREAK;}
case        {Lex(yylval, "CASE");			return CASE;}
const       {Lex(yylval, "CONST");			return CONST;}
continue    {Lex(yylval, "CONTINUE");		return CONTINUE;}
default     {Lex(yylval, "DEFAULT");		return DEFAULT;}
do          {Lex(yylval, "DO");			    return DO;}
else        {Lex(yylval, "ELSE");			return ELSE;}
// extern      {yyylval, ylval.ntnode = new node(EXTERN);	        printf("EXTERN");	return EXTERN;}
goto        {Lex(yylval, "GOTO");			return GOTO;}
return      {Lex(yylval, "RETURN");		    return RETURN;}
register    {Lex(yylval, "REGISTER");		return REGISTER;}
signed      {Lex(yylval, "SIGNED");		    return SIGNED;}
unsigned    {Lex(yylval, "UNSIGNED");	    return UNSIGNED;}
sizeof      {Lex(yylval, "SIZEOF");		    return SIZEOF;}
static      {Lex(yylval, "STATIC");		    return STATIC;}
struct      {Lex(yylval, "STRUCT");		    return STRUCT;}
switch      {Lex(yylval, "SWITCH");		    return SWITCH;}
typedef     {Lex(yylval, "TYPEDEF");		return TYPEDEF;}
union       {Lex(yylval, "UNION");			return UNION;}
volatile    {Lex(yylval, "VOLATILE"); 		return VOLATILE;}
while      	{Lex(yylval, "WHILE");          push_into_s(yylval.ntnode->args);  return WHILE;}
enum		{Lex(yylval, "ENUM"); 			return ENUM;}
ellipsis	{Lex(yylval, "ELLIPSIS");	    return ELLIPSIS;}
true	{Lex(yylval, "TRUE");	    return TRUE;}
false	{Lex(yylval, "FALSE");	    return FALSE;}
{id}		{Lex(yylval, yytext);	        return ID;}
.			{return -1;}
%%  
/////////////////////////////////////////////////////////////////////////////
// programs section
