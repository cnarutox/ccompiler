#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;
// #define ERROR 0
// #define VOID 1
// #define MAIN 2
// #define LP 3
// #define RP 4
// #define LBRACE 5
// #define RBRACE 6
// #define TYPE 7
// #define ID 8
// #define SEMICOL 9
// #define FOR 10
// #define ASSIGN 11
// #define NUMBER 12
// #define COMPARISON 13
// #define ADD 14
// #define MINUS 15
// #define IF 16
// #define ANNOTATION 17
// #define MUTIPLY 18
// #define DIVIDE 19
// #define THEN 20
// #define BREAK 21
// #define CASE 22
// #define CONST 23
// #define CONTINUE 24
// #define DEFAULT 25
// #define DO 26
// #define ELSE 27
// #define ENUM 28
// #define EXTERN 29
// #define GOTO 30
// #define RETURN 31
// #define REGISTER 32
// #define SIGNED 33
// #define SIZEOF 34
// #define STATIC 35
// #define STRUCT 36
// #define SWITCH 37
// #define TYPEDEF 38
// #define UNION 39
// #define UNSIGNED 40
// #define VOLATILE 41
// #define WHILE 42
// #define COLON 43
// #define LITERAL 44
// #define LOGIC 45
// #define BOOLOP 46
// #define LSQUBRAC 47
// #define RSQUBRAC 48
int Line = 1;
string Words[] = {
    "ERROR", "VOID", "MAIN", "LP", "RP", "LBRACE", "RBRACE", "TYPE", "ID",
    "SEMICOL", "FOR", "ASSIGN", "NUMBER", "COMPARISON", "ADD", "MINUS", "IF",
    "ANNOTATION", "MUTIPLY", "DIVIDE", "THEN", "BREAK", "CASE", "CONST",
    "CONTINUE", "DEFAULT", "DO", "ELSE", "ENUM", "EXTERN", "GOTO", "RETURN",
    "REGISTER", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDE",
    "UNION ", "UNSIGN", "VOLATI", "WHILE", "COLON", "LITERAL", "LOGIC",
    "BOOLOP", "LSQUBRAC", "RSQUBRAC"};
struct Symbol
{
    Symbol(int word, string element, int line, void *value = NULL) : word(word), element(element), value(value), line(line)
    {
        if (value)
            value = new string(element);
    }
    int word;
    string element;
    void *value;
    int line;
};
vector<Symbol> symbols;
void reserve(int word, string element, int line = Line)
{
    for (int i = 0; i < symbols.size(); i++)
        if (symbols[i].element == element)
        {
            
            return;
        }
    switch (word)
    {
    case ID:
        symbols.push_back(Symbol(word, element, line));
        symbols.back().value = &symbols.back().value;
        return;
    case NUMBER:
    case LITERAL:
        symbols.push_back(Symbol(word, element, line, &element));
        return;
    default:
        return;
    }
}
void comment(string val)
{
    for (int i = 0; i < val.length(); i++)
        if (val[i] == '\n')
            Line++;
    ////cout << val << endl;
}