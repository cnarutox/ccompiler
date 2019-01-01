#pragma once
#ifndef DUP_H
#define DUP_H
#include <map>
#include <set>
#include <vector>7
#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <fstream>
using namespace std;
int offset = 1;
int struct_width;
int nextinstr = -1;
int switch_addr;
int fun_addr;
int default_label;
map<int, int> switch_map;
vector<int> nextlist;
string struct_name;
set<int> var_set;
fstream file("code.txt");
int call_fun_addr;
string fun_name2;
struct typenode
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

void traverse(typenode *root)
{
	// if (root != NULL)
	// 	cout << root->name << " " << root->addr << endl;
	// if (root->left != NULL)
	// {
	// 	cout << "left ";
	// 	traverse(root->left);
	// }
	// if (root->right != NULL)
	// {
	// 	cout << "right ";
	// 	traverse(root->right);
	// }
}
void traverse_list(typenode *root, vector<string> &v)
{
	if (root != NULL)
	{
		// cout<<"i am null!!"<<endl;
		//cout << root->name << " " << endl;
		if (root->right == NULL && root->left == NULL)
		{
			v.push_back(root->name);
		}
	}
	if (root->left != NULL)
	{
		//cout << "left ";
		traverse_list(root->left, v);
	}
	if (root->right != NULL)
	{
		//cout << "right ";
		traverse_list(root->right, v);
	}
}

void traverse_argument(typenode *root, vector<typenode *> &v)
{

	if (root->left && root->left->name == "X")
	{
		traverse_argument(root->left, v);
	}
	if (root->right && root->right->name == "X")
	{
		traverse_argument(root->right, v);
	}
	if (root != NULL && (root->left && root->left->name != "X" || root->right && root->right->name != "X"))
	{
		if (root->left->name != "X")
		{
			cout << "|||||||||||||||||||||||||||||" << endl;
			cout << "add left" << root->left->name << endl;
			v.push_back(root->left);
		}
		if (root->right->name != "X")
		{
			cout << "|||||||||||||||||||||||||||||" << endl;
			cout << "add right" << root->right->name << endl;
			v.push_back(root->right);
		}
	}
}
stack<typenode *> rtn_stmt;
typenode *type;
typenode *type2;
typenode *type3 = new typenode("fun");
typenode *type4 = new typenode("pointer");
string var_name;
string fun_name;
bool flag = false;

map<int, int> zhang_xing_own;

typenode unsignednode("unsigned", 4);
typenode shortnode("short", 2);
typenode intnode("int", 4);
typenode longnode("long", 8);
typenode floatnode("float", 4);
typenode doublenode("double", 8);
typenode charnode("char", 1);
typenode voidnode("void");
typenode signednode("signed", 4);
typenode boolnode("bool", 1);
map<string, typenode *> auto_define_type;
stack<typenode *> struct_stack;

vector<typenode *> v_argument_list;
map<int, vector<string>> code;

void show_code()
{
	for (int i = 0; i < code.size(); i++)
	{
		cout << i << ": (" << code[i][0] + ", " + code[i][1] + ", " + code[i][2] + ", " + code[i][3] + ")" << endl;
	}
}
void transcode()
{
	for (int i = 0; i < code.size(); i++)
	{
		file << i << ": (" << code[i][0] + ", " + code[i][1] + ", " + code[i][2] + ", " + code[i][3] + ")" << endl;
		// file << i << ":" << code[i][0] + "," + code[i][1] + "," + code[i][2] + "," + code[i][3] << "\n";
	}
}

struct varmap
{
	int name;
	varmap *parent;
	map<string, typenode *> vartable;
	varmap(int n = 0, varmap *p = NULL)
	{
		name = n;
		parent = p;
	}
};

varmap *varmap_temp;
vector<varmap *> s; //fuhao-table
					//
struct node
{
	int id;
	string name;
	double dvalue;
	int length;
	node **children;
	typenode type;
	varmap *args;
	int instr;
	vector<int> *nextlist;
	vector<int> *falselist;
	vector<int> *truelist;
	node(string n = "")
	{
		length = 0;
		name = n;
		nextlist = new vector<int>();
		falselist = new vector<int>();
		truelist = new vector<int>();
	}
};

vector<int> *makelist(int i = -1)
{
	vector<int> list;
	if (i != -1)
	{
		list.push_back(i);
	}
	return &list;
}

int newlabel()
{
	static int label = -1;
	nextinstr = ++label;
	return label;
}

void backpatch(vector<int> *p, int index)
{
	cout << index << "@" << endl;
	char num[25];
	_itoa_s(index, num, 10);
	for (int i = 0; i < p->size(); i++)
	{
		cout << "\]\]\]\]" << endl;
		cout << (*p)[i] << endl;
		code[(*p)[i]][3] = string(num);
	}
}

void gen(int label, string op = "", int arg1 = 0, int arg2 = 0, int res = 0)
{
	char num1[25];
	_itoa_s(arg1, num1, 10);
	char num2[25];
	_itoa_s(arg2, num2, 10);
	char num3[25];
	_itoa_s(res, num3, 10);
	string a1, a2, a3;
	string info;

	if (arg1 > 0)
	{
		if (var_set.count(arg1) > 0)
		{
			a1 = "var" + string(num1);
		}
		else
		{
			a1 = "temp" + string(num1);
		}
	}
	else if (arg1 == 0)
	{
		a1 = string(num1);
	}
	if (arg2 != 0)
	{
		if (var_set.count(arg2) > 0)
		{
			a2 = "var" + string(num2);
		}
		else
		{
			a2 = "temp" + string(num2);
		}
	}
	else
	{
		a2 = string(num2);
	}
	if (res != 0 && op != "j" && op != "j=" && op != "j>" && op != "j<")
	{
		if (var_set.count(res) > 0)
		{
			a3 = "var" + string(num3);
		}
		else
		{
			a3 = "temp" + string(num3);
		}
	}
	else
	{
		a3 = string(num3);
	}
	if (op == "=#")
	{
		a1 = string(num1);
	}
	if (op == "fun" || op == "call")
	{
		if (op == "fun")
			a3 = fun_name2;
		else
		{
			if (arg1 == -1)
				a1 = "1";
			a3 = fun_name;
		}
	}
	if (op == "DEC")
	{
		a3 = "array" + string(num3);
	}
	code[label] = vector<string>();
	code[label].push_back(op);
	code[label].push_back(a1);
	code[label].push_back(a2);
	code[label].push_back(a3);
	//cout << label << ": (" << code[label][0] + ", " + code[label][1] + ", " + code[label][2] + ", " + code[label][3] + ")" << endl;
}

vector<int> *merge(vector<int> *p1, vector<int> *p2, vector<int> *p3 = new vector<int>())
{
	vector<int> *res = new vector<int>();
	for (int i = 0; i < p1->size(); i++)
	{
		res->push_back((*p1)[i]);
	}
	for (int i = 0; i < p2->size(); i++)
	{
		res->push_back((*p2)[i]);
	}
	if (p3->size() > 0)
	{
		for (int i = 0; i < p3->size(); i++)
		{
			res->push_back((*p3)[i]);
		}
	}
	return res;
}

bool isComputable(string s)
{
	if (s == "int" || s == "float" || s == "double" ||
		s == "unsigned" || s == "signed" || s == "short" || s == "char")
		return true;
	else
		return false;
}

bool compare_string(string s1, string s2)
{
	if (s1 == "double" && isComputable(s2) || s2 == "double" && isComputable(s1))
		return true;
	return false;
}

bool isInteger(string s)
{
	if (s == "int" || s == "unsigned" || s == "signed" || s == "short" || s == "char")
		return true;
	else
		return false;
}

typenode *create_struct(string name)
{
	int width_sum = 0;

	map<string, typenode *>::iterator iter;
	typenode *temp_ptr;
	typenode *temp1;
	typenode *temp2;
	typenode *temp3 = new typenode("?");
	for (iter = varmap_temp->vartable.begin(); iter != varmap_temp->vartable.end(); ++iter)
	{
		//cout << iter->first << ' ' << iter->second->name << ' ';
		temp_ptr = new typenode(string(iter->first));
		typenode *root = new typenode("X");
		root->left = temp_ptr;
		root->right = iter->second;
		root->left->addr = width_sum;
		//cout << iter->second->width << '%';
		width_sum += iter->second->width;
		struct_stack.push(root);
	}
	//cout<<endl;
	while (struct_stack.size() >= 1)
	{
		//cout<<struct_stack.size()<<endl;
		if (struct_stack.size() != 1)
		{
			temp1 = struct_stack.top();
			struct_stack.pop();
			temp2 = struct_stack.top();
			struct_stack.pop();
			typenode *temp_ptr2 = new typenode("X");
			temp_ptr2->left = temp1;
			temp_ptr2->right = temp2;
			struct_stack.push(temp_ptr2);
		}
		else
		{
			temp3 = struct_stack.top();
			struct_stack.pop();
			break;
		}
	}
	typenode *temp = new typenode("record");
	temp->left = temp3;
	struct_width = temp->width = width_sum;
	offset -= struct_width;
	//traverse(temp);
	return auto_define_type[name] = temp;
}

void traverse_vartable(int i, string tab = "**")
{
	cout << endl
		 << i << tab;
	map<string, typenode *>::iterator iter;
	for (iter = s[i]->vartable.begin(); iter != s[i]->vartable.end(); ++iter)
	{
		// cout << iter->first << ' ' << iter->second->name << ' ' << iter->second->addr << ' ' << iter->second->width << ';';
		cout << iter->first << ' ' << iter->second->name << ';';
	}
	if (i > 0)
	{
		i--;
		traverse_vartable(i, tab + "**");
	}
}

typenode *search(string myname, int i)
{
	if (s[i]->vartable.count(myname) > 0)
	{
		// cout<<"s[i]->vartable[myname]"<<s[i]->vartable[myname]->name<<endl;
		//cout<<myname<<" yes in "<<i<<endl;
		//traverse(s[i]->vartable[myname]);
		//traverse_vartable(i);
		//traverse(s[i]->vartable[myname]);
		return s[i]->vartable[myname];
	}
	else
	{
		if (s[i]->vartable.count(myname) == 0 && i > 0)
		{
			//cout<<endl<<"not bottom!!!"<<endl;
			i--;
			return search(myname, i);
		}
		else
		{
			cout << "Cannot find " << myname << "!" << endl;
			return NULL;
		}
	}
}

void wFlag(typenode &node)
{
	if (flag)
	{
		type2 = &node;
		flag = false;
	}
	else
	{
		type = &node;
		flag = true;
	}
}
typenode *rFlag()
{
	typenode *tmp = new typenode();
	if (flag == true)
	{
		(*tmp).copy(*type);
		//cout<<"tmp.name"<<tmp.name<<endl;
		//cout<<"tmp.left"<<tmp.left->name<<endl;
		return tmp;
	}
	else
	{
		(*tmp).copy(*type2);
		return tmp;
	}
}

// #define ERROR 0
// #define VOID 13
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
// #define NUMB 12
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
// void reserve(int word, string element, int line = Line)
// {
//     for (int i = 0; i < symbols.size(); i++)
//         if (symbols[i].element == element)
//         {

//             return;
//         }
//     switch (word)
//     {
//     case ID:
//         symbols.push_back(Symbol(word, element, line));
//         symbols.back().value = &symbols.back().value;
//         return;
//     case NUMBER:
//     case LITERAL:
//         symbols.push_back(Symbol(word, element, line, &element));
//         return;
//     default:
//         return;
//     }
// }
#endif
