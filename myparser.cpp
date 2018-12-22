/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 74 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/23/18
* Time: 06:37:47
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018��10��28��
****************************************************************************/
#include "define.h"
#include "mylexer.h"
void compare_traverse(typenode *root, vector<string> &v) {
	if(root!=NULL)
		//cout << root->name << endl;
		v.push_back(root->name);
	if(root->left!=NULL)
	{
		traverse(root->left);
	}
	if(root->right!=NULL)
	{
		traverse(root->right);	
	}
}
void show_vector(vector<typenode*> &v){
	cout<<endl<<"&&&&&after_post_traverse&&&&&&&"<<endl;
	vector<typenode*>::iterator iter;
	for (iter=v.begin();iter!=v.end();iter++){
		cout<<(*iter)->name<<' ';
	}
	cout<<endl;
}

void show_string(vector<string> &v) {
	cout<<"''''''''''''''"<<endl;
	for (int i=0; i<v.size();i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"pppppppppppppppp"<<endl;
}

void post_traverse(typenode* root, vector<string> &v_temp)
{	
	if(root!=NULL){
		post_traverse(root->left, v_temp);
		post_traverse(root->right, v_temp);
		v_temp.push_back(root->name);
	}	
}

bool check_type(typenode* tp1, typenode* tp2){
	vector<string> temp1;
	vector<string> temp2;
	post_traverse(tp1, temp1);
	post_traverse(tp2, temp2);
	// show_string(temp1);
	// show_string(temp2);
	if (temp1.size() != temp2.size())
		return false;
	for(int i = 0; i < temp1.size(); i++) {
		if (temp1[i] != temp2[i]){
			if(temp2[i] == "double" && isComputable(temp1[i]))
			{
				cout<<"warning: lose precision!!\n";
				return true;
			}
			return false;
		}
	}
	return true;
}

void search_struct(typenode *root, string name, typenode &p) {
	cout << '~\n';
	if(root == NULL)
	{
		cout << "root->left->name == name" << endl;
	}
	if(root->left != NULL)
	{
		cout << "left " << root->left->name << endl;
		if (root->left->name == name)
		{
			cout << "into left\n";
			p = *(root -> right);
		} 
		else search_struct(root->left, name, p);
	}
	if(root->right != NULL)
	{
		cout << "right " << root->right->name << endl;
		search_struct(root->right, name, p);
	}
}


#line 134 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 151 ".\\myparser.y"

	// place any extra initialisation code here

#line 158 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 156 ".\\myparser.y"

	// place any extra cleanup code here

#line 172 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 179 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("108 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
		traverse_vartable(s.size()-1);
		typenode* ptr = search(yyattribute(1 - 1).ntnode->name,s.size()-1);						
		if(ptr != NULL)
		{
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *ptr;
			cout<<"****************"<<endl;
			cout<<yyattribute(1 - 1).ntnode->name<<":"<<(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.name<<endl;
		}
		var_name = yyattribute(1 - 1).ntnode->name;
	
#line 299 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 197 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("116 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = doublenode;
	
#line 322 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 208 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("123 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 342 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 216 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("130 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	
		s.pop_back();  
	
#line 365 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 231 ".\\myparser.y"

		fun_name = var_name;
	
#line 380 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 237 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("142 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;			
	
#line 403 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 248 ".\\myparser.y"
	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("149 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 4).ntnode->type;
	
#line 427 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 260 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("159 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		typenode* temp = search(fun_name, s.size()-1);
		if(temp->right != NULL)
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = *(temp->right);
		else{
			temp = new typenode();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *temp;
		}
		s.pop_back();  
	
#line 454 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 275 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("168 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		s.pop_back();  
		vector<string> v_argument_list_temp; 
		cout<<fun_name<<":fun_name"<<endl;
		typenode* type_exp = (search(fun_name, s.size()-1));
		traverse(type_exp);
		cout << "type_exp.name"<<type_exp->name << endl;
		if(type_exp->name == "fun"){
			cout<<"&&&&&&&It is a function!!!&&&&&&";
			if (v_argument_list_temp.size()!=v_argument_list.size()){
				cout<<"&&&&&&Argument_list matching failed."<<endl;
			}
			for(int i=0; i<v_argument_list_temp.size();i++){
				if(v_argument_list[i]!=v_argument_list_temp[i])
					cout<<"&&&&&&Argument_list matching failed."<<endl;				
			}
			cout<<"&&&&&&&Argument_list matched!!!&&&&&&&&"<<endl;
		}
		cout<<"&&&&&clear v_argument_list&&&"<<endl;
		v_argument_list.clear();
	
#line 491 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 300 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("178 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (yyattribute(1 - 3).ntnode->type.name == "record")
		{
			typenode pointer;
			pointer.name = "###";
			search_struct(&(yyattribute(1 - 3).ntnode->type), yyattribute(3 - 3).ntnode->name, pointer);
			cout<< pointer.name<<"////////"<<endl;
			if (pointer.name == "###")
				cout << "struct doesn't have " << yyattribute(3 - 3).ntnode->name << endl;
			else{
				cout<<"struct has "<<yyattribute(3 - 3).ntnode->name<<endl;
			}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = pointer;
		} 
		else if(yyattribute(1 - 3).ntnode->type.name == "array" && yyattribute(1 - 3).ntnode->type.right->name == "record"){
			typenode pointer;
			pointer.name = "#O#O#O";
			search_struct(yyattribute(1 - 3).ntnode->type.right, yyattribute(3 - 3).ntnode->name, pointer);
			cout<< pointer.name <<"////////"<<endl;
			if (pointer.name == "#O#O#O")
				cout << "struct doesn't have " << yyattribute(3 - 3).ntnode->name << endl;
			else{
				cout<<"struct has "<<yyattribute(3 - 3).ntnode->name<<endl;
			}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = pointer;
		}
		else cout << "struct doesn't exist!\n";

	
	
#line 542 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 339 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("187 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 564 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 349 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("196 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
			cout<<"No additive calculation can be made for uncalculable types."<<endl;
	
#line 588 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 361 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
			cout<<"Can't subtract from uncalculable types."<<endl;
	
#line 612 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 376 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("215 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;						
	
#line 634 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 386 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("222 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		v_argument_list.push_back(yyattribute(1 - 3).ntnode->type.name);
		v_argument_list.push_back(yyattribute(3 - 3).ntnode->type.name);
	
#line 659 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 402 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("234 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 682 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 413 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("241 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
			cout<<"No additive calculation can be made for uncalculable types."<<endl;
	
#line 706 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 425 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("249 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
			cout<<"Can't subtract from uncalculable types ."<<endl;
	
#line 730 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 437 ".\\myparser.y"

		//cast_exp:单目表达式/强制类型转换
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("257 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 752 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 447 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("265 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(yyattribute(2 - 2).ntnode->type.width!=0)
		{
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(2 - 2).ntnode->type.width; 
		}
		else cout<<"Unknown type, unable to perform sizeof operation."<<endl;
	
#line 779 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 462 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("273 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
		s.pop_back();  

		if(yyattribute(3 - 4).ntnode->type.width!=0)(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(3 - 4).ntnode->type.width;
		else cout<<"Unknown type, unable to perform sizeof operation."<<endl;
	
#line 806 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 480 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("286 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 826 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 488 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 846 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 496 ".\\myparser.y"

		printf("777");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("301 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 867 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 505 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("308 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 887 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 513 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("315 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 907 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 521 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("322 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 927 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 532 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("332 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 950 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 543 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("339 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
		s.pop_back();  
	
#line 974 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 558 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("352 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;			
	
#line 997 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 569 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("359 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
			cout<<"Mismatch of Operator Types in Multiplication Operations."<<endl;		
	
#line 1022 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 582 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("368 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
			cout<<"Divisional Operator Type Mismatch."<<endl;
	
#line 1047 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 595 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("377 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
			cout<<"Complementation Operator Type Mismatch."<<endl;
	
#line 1072 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 611 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("389 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1095 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 622 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("396 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
				
		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
			cout<<"Operator type mismatch."<<endl;		
	
#line 1120 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 635 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("405 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
			cout<<"Operator type mismatch."<<endl;	
	
#line 1145 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 651 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("417 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1168 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 662 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("424 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Shift Operator Operator Mismatch ."<<endl;
	
#line 1193 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 675 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("433 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Shift Operator Operator Mismatch ."<<endl;
	
#line 1218 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 691 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("445 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;		
	
#line 1241 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 702 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("452 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1266 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 715 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("461 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1291 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 728 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("470 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1316 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 741 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("479 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1341 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 757 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("491 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1364 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 768 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("498 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1390 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 782 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("507 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1416 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 799 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("519 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1439 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 810 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("526 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;

		if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Intersection Operator Type Mismatch ."<<endl;
	
#line 1465 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 827 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1488 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 838 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("545 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;

		if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Intersection Operator Type Mismatch ."<<endl;
	
#line 1514 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 855 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("557 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1537 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 866 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("564 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;

		if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Or operation left-right operand type mismatch "<<endl;
	
#line 1563 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 883 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("576 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1586 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 894 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("583 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;
	
#line 1609 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 908 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("595 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1632 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 919 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("602 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;
	
#line 1655 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 933 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("614 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1678 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 944 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("621 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 5).ntnode;	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 5).ntnode->type;

		vector<string> v1;
		vector<string> v2;
		compare_traverse(&yyattribute(3 - 5).ntnode->type, v1);
		compare_traverse(&yyattribute(5 - 5).ntnode->type, v2);
		if (v1 == v2){
			cout<<"match"<<endl;
		}	
		else{
			cout<<"mismatch!"<<endl;
		}			
	
#line 1714 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 971 ".\\myparser.y"

		//(1)谓词表达式




		//(2)条件表达式 a<b?a:b
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1741 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 986 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;   
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(3 - 3).ntnode->type;
		cout<<"############";traverse(&(yyattribute(1 - 3).ntnode->type));
		cout<<"^^^^^^^^^^^";traverse(&(yyattribute(3 - 3).ntnode->type));
		if (check_type(&yyattribute(1 - 3).ntnode->type, &yyattribute(3 - 3).ntnode->type)){
			cout<<"Two sides equal"<<endl;
		}	
		else{
			cout<<"Two sides don't equal"<<endl;
		}
	
#line 1772 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1008 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("654 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1792 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1016 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("661 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1812 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1024 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("668 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1832 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1032 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("675 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1852 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1040 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("682 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1872 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1048 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1892 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1056 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("696 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1912 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1064 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("703 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1932 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1072 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("710 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1952 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1080 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("717 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1972 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1088 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("724 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1992 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1099 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("123456 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;	
	
#line 2013 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1108 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("741 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;
	
#line 2036 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1122 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("753 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 2058 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1135 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("763 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2079 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1144 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("771 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;		
	
#line 2103 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1162 ".\\myparser.y"
 //static
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("783 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;	
	
#line 2124 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1172 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("791 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
	
#line 2146 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1182 ".\\myparser.y"
 // int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("799 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
	
#line 2167 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1191 ".\\myparser.y"
 // lont int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("806 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
	
#line 2189 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1201 ".\\myparser.y"
 //const
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("814 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;	
	
#line 2210 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1210 ".\\myparser.y"
 //const int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("821 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
	
#line 2232 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1223 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("832 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
	
#line 2254 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1233 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("839 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 2276 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1246 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("851 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2296 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1254 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("858 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	

		traverse_vartable(s.size()-1);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
		vector<string> v1;
		vector<string> v2;
		compare_traverse(&(yyattribute(1 - 3).ntnode->type), v1);
		compare_traverse(&(yyattribute(3 - 3).ntnode->type), v2);
		cout << "initializer.name " << yyattribute(3 - 3).ntnode->type.name << endl;
		cout << "declarator.name " << yyattribute(1 - 3).ntnode->type.name << endl;
		show_string(v1);
		show_string(v2);
		if (check_type(&(yyattribute(1 - 3).ntnode->type), &(yyattribute(3 - 3).ntnode->type))){
			cout<<"match!"<<endl;
		}
		else{
			cout<<"!mismatch "<<endl;
		}				
	
#line 2335 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1284 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("870 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;			
	
#line 2355 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1292 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("877 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2375 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1300 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("884 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2395 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1308 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2415 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1316 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("898 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2435 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1327 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		wFlag(voidnode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=voidnode;
	
#line 2457 "myparser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1337 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("915 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(charnode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=charnode;
	
#line 2479 "myparser.cpp"
			}
		}
		break;
	case 94:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1347 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("922 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(shortnode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=shortnode;
	
#line 2501 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1357 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("929 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(intnode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=intnode;
	
#line 2523 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1367 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("936 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(longnode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=longnode;
	
#line 2545 "myparser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1377 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("943 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(floatnode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=floatnode;
	
#line 2567 "myparser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1387 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("950 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(doublenode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=doublenode;
	
#line 2589 "myparser.cpp"
			}
		}
		break;
	case 99:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1397 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("957 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(signednode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=signednode;
	
#line 2611 "myparser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1407 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(unsignednode);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=unsignednode;
	
#line 2633 "myparser.cpp"
			}
		}
		break;
	case 101:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1417 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		wFlag(yyattribute(1 - 1).ntnode->type);
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = yyattribute(1 - 1).ntnode -> type;

	
#line 2657 "myparser.cpp"
			}
		}
		break;
	case 102:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1429 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("978 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2677 "myparser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1437 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("985 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2697 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1445 ".\\myparser.y"

	
#line 2711 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1450 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("986 ");
		wFlag(*(create_struct(yyattribute(2 - 5).ntnode->name)));
	
#line 2728 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1456 ".\\myparser.y"

		static int i = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("987 ");
		wFlag(*(create_struct("struct" + to_string(i))));
		s.back()->vartable["struct" + to_string(i++)] = rFlag();
	
#line 2747 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1465 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("988 ");
	
#line 2763 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1469 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("989 ");
		// s.back()->vartable[] = rFlag();
	
#line 2780 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1477 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("990 ");
	
#line 2796 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1481 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("991 ");
		
		map<string, typenode*>::iterator i;
		if ((i = auto_define_type.find(yyattribute(2 - 2).ntnode->name)) != auto_define_type.end())
		{
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *auto_define_type[yyattribute(2 - 2).ntnode->name];
		}
		else cout << "struct doesn't exist!\n";
	
#line 2819 "myparser.cpp"
			}
		}
		break;
	case 111:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1570 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1027 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2839 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1578 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1034 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2859 "myparser.cpp"
			}
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1589 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1044 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2879 "myparser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1597 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1051 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2900 "myparser.cpp"
			}
		}
		break;
	case 115:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1609 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1062 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2922 "myparser.cpp"
			}
		}
		break;
	case 116:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1619 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1062 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2944 "myparser.cpp"
			}
		}
		break;
	case 117:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1632 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1074 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2965 "myparser.cpp"
			}
		}
		break;
	case 118:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1641 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1082 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2985 "myparser.cpp"
			}
		}
		break;
	case 119:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1649 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1089 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3006 "myparser.cpp"
			}
		}
		break;
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1658 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1097 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3026 "myparser.cpp"
			}
		}
		break;
	case 121:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1669 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1107 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3046 "myparser.cpp"
			}
		}
		break;
	case 122:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1677 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1114 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3068 "myparser.cpp"
			}
		}
		break;
	case 123:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1690 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1126 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3088 "myparser.cpp"
			}
		}
		break;
	case 124:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1698 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1133 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3109 "myparser.cpp"
			}
		}
		break;
	case 125:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1707 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1141 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3131 "myparser.cpp"
			}
		}
		break;
	case 126:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1720 ".\\myparser.y"
 //enum {a=1,b}
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1153 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 3154 "myparser.cpp"
			}
		}
		break;
	case 127:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1731 ".\\myparser.y"
 //enum q{a,b}
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1163 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 5).ntnode;
	
#line 3178 "myparser.cpp"
			}
		}
		break;
	case 128:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1743 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1174 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3199 "myparser.cpp"
			}
		}
		break;
	case 129:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1755 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1185 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3219 "myparser.cpp"
			}
		}
		break;
	case 130:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1763 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1192 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3241 "myparser.cpp"
			}
		}
		break;
	case 131:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1776 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3261 "myparser.cpp"
			}
		}
		break;
	case 132:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1784 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1211 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3283 "myparser.cpp"
			}
		}
		break;
	case 133:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1797 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1223 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3303 "myparser.cpp"
			}
		}
		break;
	case 134:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1805 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1230 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3323 "myparser.cpp"
			}
		}
		break;
	case 135:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1816 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1240 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3344 "myparser.cpp"
			}
		}
		break;
	case 136:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1825 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1248 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 3365 "myparser.cpp"
			}
		}
		break;
	case 137:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1836 ".\\myparser.y"

		fun_name = var_name;
		cout<<"!!!!!!!!"<<endl;
	
#line 3381 "myparser.cpp"
			}
		}
		break;
	case 138:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1843 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1258 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		var_name = yyattribute(1 - 1).ntnode->name;
		s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
		offset += rFlag()->width;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
	
#line 3405 "myparser.cpp"
			}
		}
		break;
	case 139:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1855 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1265 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
		s.pop_back();  
	
#line 3429 "myparser.cpp"
			}
		}
		break;
	case 140:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1867 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1274 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;

		typenode* root = rFlag();
		typenode* basetype = root;
		typenode* parent = root;		
		while(basetype->right != NULL) {
			parent = basetype;						
			basetype = basetype->right;
		}
		typenode* temp = new typenode("array");	
		char num[25];
		_itoa_s(int(yyattribute(3 - 4).ntnode->dvalue), num, 10);
		root->width = root->width *= yyattribute(3 - 4).ntnode->dvalue;
		temp -> left = new typenode(string(num));
		temp -> right = basetype;
		if(root->right != NULL){
			parent -> right = temp;
		}
		else 
			root = temp;
        wFlag(*root);
		s.back()->vartable[var_name] = rFlag();
		offset += rFlag()->width;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
		traverse(root);
	
#line 3476 "myparser.cpp"
			}
		}
		break;
	case 141:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1902 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1284 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3498 "myparser.cpp"
			}
		}
		break;
	case 142:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1912 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
	
#line 3517 "myparser.cpp"
			}
		}
		break;
	case 143:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1919 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1303 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		map<string, typenode*>::iterator iter;
		for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
			s[s.size()-2]->vartable[iter->first] = iter->second;
		}	
		s.pop_back();  
	
#line 3540 "myparser.cpp"
			}
		}
		break;
	case 144:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1930 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1313 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		fun_name = var_name;
	
#line 3560 "myparser.cpp"
			}
		}
		break;
	case 145:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1941 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1325 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		typenode* temp = new typenode("pointer");
		temp->left=rFlag();
		temp->width = 4;
		flag = !flag;
		wFlag(*temp);
		//traverse(temp);
	
#line 3587 "myparser.cpp"
			}
		}
		break;
	case 146:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1956 ".\\myparser.y"
 // *const
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3607 "myparser.cpp"
			}
		}
		break;
	case 147:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1964 ".\\myparser.y"
 // **
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;

		typenode* temp = new typenode("pointer");
		temp->left = rFlag();
		temp->width = 4;
		flag = !flag;
		wFlag(*temp);
	
#line 3633 "myparser.cpp"
			}
		}
		break;
	case 148:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1978 ".\\myparser.y"
 //*const*
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
	
#line 3653 "myparser.cpp"
			}
		}
		break;
	case 149:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1989 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1359 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3673 "myparser.cpp"
			}
		}
		break;
	case 150:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1997 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1366 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3694 "myparser.cpp"
			}
		}
		break;
	case 151:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2010 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1378 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		type3->left = rFlag();
	
#line 3716 "myparser.cpp"
			}
		}
		break;
	case 152:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2020 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1385 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3738 "myparser.cpp"
			}
		}
		break;
	case 153:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2033 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1397 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3758 "myparser.cpp"
			}
		}
		break;
	case 154:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2041 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1404 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		typenode *temp = new typenode("X");
		flag = !flag;
		temp->left = rFlag();
		flag = !flag;
		temp->right = rFlag();
		wFlag(*temp);
	
#line 3786 "myparser.cpp"
			}
		}
		break;
	case 155:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2060 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1416 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3807 "myparser.cpp"
			}
		}
		break;
	case 156:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2069 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1424 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3827 "myparser.cpp"
			}
		}
		break;
	case 157:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2077 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1431 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3847 "myparser.cpp"
			}
		}
		break;
	case 158:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2088 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1441 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
		offset += rFlag()->width;
	
#line 3869 "myparser.cpp"
			}
		}
		break;
	case 159:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2098 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1448 ");   
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		s.back()->vartable[yyattribute(3 - 3).ntnode->name] = rFlag();	
		offset += rFlag()->width;
	
#line 3893 "myparser.cpp"
			}
		}
		break;
	case 160:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2113 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1460 ");
	  	(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3913 "myparser.cpp"
			}
		}
		break;
	case 161:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2121 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1467 ");  
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3934 "myparser.cpp"
			}
		}
		break;
	case 162:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2133 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1478 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3954 "myparser.cpp"
			}
		}
		break;
	case 163:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2141 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1485 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3974 "myparser.cpp"
			}
		}
		break;
	case 164:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2149 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1492 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3995 "myparser.cpp"
			}
		}
		break;
	case 165:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2161 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1503 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		s.pop_back();  
	
#line 4018 "myparser.cpp"
			}
		}
		break;
	case 166:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2172 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1512 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4039 "myparser.cpp"
			}
		}
		break;
	case 167:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2181 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1520 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4061 "myparser.cpp"
			}
		}
		break;
	case 168:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2191 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1529 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4083 "myparser.cpp"
			}
		}
		break;
	case 169:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2201 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4106 "myparser.cpp"
			}
		}
		break;
	case 170:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2212 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1548 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		s.pop_back();  
	
#line 4128 "myparser.cpp"
			}
		}
		break;
	case 171:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2222 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1556 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		s.pop_back();  
	
#line 4151 "myparser.cpp"
			}
		}
		break;
	case 172:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2233 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1565 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		s.pop_back();  
	
#line 4174 "myparser.cpp"
			}
		}
		break;
	case 173:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2244 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1574 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		s.pop_back();  
	
#line 4198 "myparser.cpp"
			}
		}
		break;
	case 174:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2259 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1587 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 4220 "myparser.cpp"
			}
		}
		break;
	case 175:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2269 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1594 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4242 "myparser.cpp"
			}
		}
		break;
	case 176:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2279 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1603 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4265 "myparser.cpp"
			}
		}
		break;
	case 177:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2293 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1616 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4285 "myparser.cpp"
			}
		}
		break;
	case 178:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2301 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1623 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4307 "myparser.cpp"
			}
		}
		break;
	case 179:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2313 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4327 "myparser.cpp"
			}
		}
		break;
	case 180:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2321 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4347 "myparser.cpp"
			}
		}
		break;
	case 181:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2329 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4367 "myparser.cpp"
			}
		}
		break;
	case 182:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2337 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4387 "myparser.cpp"
			}
		}
		break;
	case 183:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2345 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4407 "myparser.cpp"
			}
		}
		break;
	case 184:
		{
#line 2353 ".\\myparser.y"

		printf("other");
	
#line 4417 "myparser.cpp"
		}
		break;
	case 185:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2358 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		traverse_vartable(s.size() - 1);
	
#line 4438 "myparser.cpp"
			}
		}
		break;
	case 186:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2368 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		traverse_vartable(s.size() - 1);
	
#line 4459 "myparser.cpp"
			}
		}
		break;
	case 187:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2377 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		traverse_vartable(s.size() - 1);
	
#line 4480 "myparser.cpp"
			}
		}
		break;
	case 188:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2386 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1656 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		traverse_vartable(s.size() - 1);
	
#line 4502 "myparser.cpp"
			}
		}
		break;
	case 189:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2396 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		traverse_vartable(s.size() - 1);
	
#line 4523 "myparser.cpp"
			}
		}
		break;
	case 190:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2405 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "xx";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		traverse_vartable(s.size() - 1);
	
#line 4544 "myparser.cpp"
			}
		}
		break;
	case 191:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2417 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1680 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4566 "myparser.cpp"
			}
		}
		break;
	case 192:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2427 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4589 "myparser.cpp"
			}
		}
		break;
	case 193:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2438 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1699 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4611 "myparser.cpp"
			}
		}
		break;
	case 194:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2451 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1711 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4632 "myparser.cpp"
			}
		}
		break;
	case 195:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2460 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1719 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4654 "myparser.cpp"
			}
		}
		break;
	case 196:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2470 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1728 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;	
	
#line 4676 "myparser.cpp"
			}
		}
		break;
	case 197:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2480 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1737 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;	
	
#line 4699 "myparser.cpp"
			}
		}
		break;
	case 198:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2494 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1750 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		traverse_vartable(s.size() - 1);
	
#line 4721 "myparser.cpp"
			}
		}
		break;
	case 199:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2504 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1757 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4742 "myparser.cpp"
			}
		}
		break;
	case 200:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2516 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1768 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4762 "myparser.cpp"
			}
		}
		break;
	case 201:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2524 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1775 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4783 "myparser.cpp"
			}
		}
		break;
	case 202:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2536 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1786 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4803 "myparser.cpp"
			}
		}
		break;
	case 203:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2544 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1793 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4824 "myparser.cpp"
			}
		}
		break;
	case 204:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2555 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1794 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
	
#line 4845 "myparser.cpp"
			}
		}
		break;
	case 205:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2564 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(); 
		printf("1795 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4865 "myparser.cpp"
			}
		}
		break;
	case 206:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2574 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1803 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[5] = yyattribute(6 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[6] = yyattribute(7 - 7).ntnode;
		s.pop_back();
		traverse_vartable(s.size() - 1);		
	
#line 4893 "myparser.cpp"
			}
		}
		break;
	case 207:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2590 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1815 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		traverse_vartable(s.size() - 1);
		// s.pop_back();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
	
#line 4916 "myparser.cpp"
			}
		}
		break;
	case 208:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2603 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1816 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(5 - 5).ntnode->type;
		s.pop_back();
		traverse_vartable(s.size() - 1);
	
#line 4943 "myparser.cpp"
			}
		}
		break;
	case 209:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2618 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1817 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[5] = yyattribute(6 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[6] = yyattribute(7 - 7).ntnode;
		s.pop_back();
		traverse_vartable(s.size() - 1);
	
#line 4971 "myparser.cpp"
			}
		}
		break;
	case 210:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2636 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1818 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4991 "myparser.cpp"
			}
		}
		break;
	case 211:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2644 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1825 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 5).ntnode;
		s.pop_back();  
	
#line 5016 "myparser.cpp"
			}
		}
		break;
	case 212:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2660 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1839 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 5).ntnode;
		s.pop_back();
	
#line 5041 "myparser.cpp"
			}
		}
		break;
	case 213:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2673 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1850 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[5] = yyattribute(6 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[6] = yyattribute(7 - 7).ntnode;
		s.pop_back();  
	
#line 5068 "myparser.cpp"
			}
		}
		break;
	case 214:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 2688 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1863 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 6;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [6];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[5] = yyattribute(6 - 6).ntnode;
		map<string, typenode*>::iterator iter;
		for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
			s[s.size()-2]->vartable[iter->first] = iter->second;
		}
		s.pop_back();		
	
#line 5098 "myparser.cpp"
			}
		}
		break;
	case 215:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2706 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1875 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[5] = yyattribute(6 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[6] = yyattribute(7 - 7).ntnode;
		map<string, typenode*>::iterator iter;
		for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++)
		{
			s[s.size()-2]->vartable[iter->first] = iter->second;
		}
		s.pop_back();
	
#line 5130 "myparser.cpp"
			}
		}
		break;
	case 216:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2729 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 5152 "myparser.cpp"
			}
		}
		break;
	case 217:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2739 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1900 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 5173 "myparser.cpp"
			}
		}
		break;
	case 218:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2748 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 5194 "myparser.cpp"
			}
		}
		break;
	case 219:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2757 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1916 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		rtn_stmt.push(&voidnode);		
	
#line 5216 "myparser.cpp"
			}
		}
		break;
	case 220:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2767 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1924 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;	
		rtn_stmt.push(&(yyattribute(2 - 3).ntnode->type));	
		cout<<yyattribute(2 - 3).ntnode->name<<": "<<yyattribute(2 - 3).ntnode->type.name<<endl;		
	
#line 5240 "myparser.cpp"
			}
		}
		break;
	case 221:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2782 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1946 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		cout<<endl;
		// traverse($$);
	
#line 5262 "myparser.cpp"
			}
		}
		break;
	case 222:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2792 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1953 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		cout<<endl;
		// traverse($$);
	
#line 5285 "myparser.cpp"
			}
		}
		break;
	case 223:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2806 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 5305 "myparser.cpp"
			}
		}
		break;
	case 224:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2814 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 5325 "myparser.cpp"
			}
		}
		break;
	case 225:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2825 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1981 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		type3->right = &(yyattribute(1 - 4).ntnode->type);
		s.back()->vartable[fun_name] = type3;
		traverse(type3);
		cout<<"_______________________"<<endl;
		cout<<"stack size"<<rtn_stmt.size()<<endl;		
		if (rtn_stmt.size() == 0 && type3->right != NULL){
			cout<<"type error in 1991!"<<endl;
		}
		while(rtn_stmt.size()>0){ 
		typenode *a = rtn_stmt.top();
		cout<<"stack top"<<a->name<<endl;
		if(!check_type(a,&(yyattribute(1 - 4).ntnode->type)))
		{
					cout<<"type error in 1991!"<<endl;
					cout<<"left"<<yyattribute(1 - 4).ntnode->type.name<<"right"<<a->name<<endl;					
		}
		rtn_stmt.pop();
		}	
		cout<<"+++++++++++++++++++++"<<endl;
		s.pop_back();
	
#line 5368 "myparser.cpp"
			}
		}
		break;
	case 226:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2856 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1991 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;

		type3->right = &(yyattribute(1 - 3).ntnode->type);
		cout<<"fun_name:"<<fun_name<<endl;
		s[s.size()-2]->vartable[fun_name] = type3;
		traverse(type3);
		cout<<"_______________________"<<endl;
		cout<<"stack size"<<rtn_stmt.size()<<endl;	
		if (rtn_stmt.size() == 0 && type3->right != NULL){
			cout<<"type error in 1991!"<<endl;
		}	
		while(rtn_stmt.size()>0){
			typenode *a = rtn_stmt.top();
			cout<<"stack top"<<a->name<<endl;
			if(!check_type(a,&(yyattribute(1 - 3).ntnode->type)))
			{
					cout<<"type error in 1991!"<<endl;
					cout<<"left"<<yyattribute(1 - 3).ntnode->type.name<<"right"<<a->name<<endl;					 							
			}
			rtn_stmt.pop();
		}	
		cout<<"+++++++++++++++++++++"<<endl;
		traverse_vartable(s.size()-1);	
		s.pop_back();
	
#line 5413 "myparser.cpp"
			}
		}
		break;
	case 227:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2889 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2000 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		type3->right = &(yyattribute(1 - 3).ntnode->type);
		s.back()->vartable[fun_name] = type3;
		traverse(type3);
		cout<<"_______________________"<<endl;
		cout<<"stack size"<<rtn_stmt.size()<<endl;
		if (rtn_stmt.size() == 0 && type3->right != NULL){
			cout<<"type error in 1991!"<<endl;
		}		
		while(rtn_stmt.size()>0){
		typenode *a = rtn_stmt.top();
		cout<<"stack top"<<a->name<<endl;
		if(!check_type(a,&(yyattribute(1 - 3).ntnode->type)))
		{
					cout<<"type error in 1991!"<<endl;
					cout<<"left"<<yyattribute(1 - 3).ntnode->type.name<<"right"<<a->name<<endl;					 							
		}
		rtn_stmt.pop();
		}	
		cout<<"+++++++++++++++++++++"<<endl;
		s.pop_back();
	
#line 5455 "myparser.cpp"
			}
		}
		break;
	case 228:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2919 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2009 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		type3->right = &(yyattribute(1 - 2).ntnode->type);
		s.back()->vartable[fun_name] = type3;
		traverse(type3);
		cout<<"_______________________"<<endl;
		cout<<"stack size"<<rtn_stmt.size()<<endl;	
		if (rtn_stmt.size() == 0 && type3->right != NULL){
			cout<<"type error in 1991!"<<endl;
		}	
		while(rtn_stmt.size()>0){
		typenode *a = rtn_stmt.top();
		cout<<"stack top"<<a->name<<endl;
		if(!check_type(a,&(yyattribute(1 - 2).ntnode->type)))
		{
					cout<<"type error in 1991!"<<endl;
					cout<<"left"<<yyattribute(1 - 2).ntnode->type.name<<"right"<<a->name<<endl;					 							
		}
		rtn_stmt.pop();
		}	
		cout<<"+++++++++++++++++++++"<<endl;
		s.pop_back();
	
#line 5496 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "\'!\'", 33 },
		{ "\'%\'", 37 },
		{ "\'&\'", 38 },
		{ "\'(\'", 40 },
		{ "\')\'", 41 },
		{ "\'*\'", 42 },
		{ "\'+\'", 43 },
		{ "\',\'", 44 },
		{ "\'-\'", 45 },
		{ "\'.\'", 46 },
		{ "\'/\'", 47 },
		{ "\':\'", 58 },
		{ "\';\'", 59 },
		{ "\'<\'", 60 },
		{ "\'=\'", 61 },
		{ "\'>\'", 62 },
		{ "\'\?\'", 63 },
		{ "\'[\'", 91 },
		{ "\']\'", 93 },
		{ "\'^\'", 94 },
		{ "\'{\'", 123 },
		{ "\'|\'", 124 },
		{ "\'}\'", 125 },
		{ "\'~\'", 126 },
		{ "error", 256 },
		{ "ID", 257 },
		{ "CONSTANT", 258 },
		{ "STRING_LITERAL", 259 },
		{ "SIZEOF", 260 },
		{ "PTR_OP", 261 },
		{ "INC_OP", 262 },
		{ "DEC_OP", 263 },
		{ "LEFT_OP", 264 },
		{ "RIGHT_OP", 265 },
		{ "LE_OP", 266 },
		{ "GE_OP", 267 },
		{ "EQ_OP", 268 },
		{ "NE_OP", 269 },
		{ "AND_OP", 270 },
		{ "OR_OP", 271 },
		{ "MUL_ASSIGN", 272 },
		{ "DIV_ASSIGN", 273 },
		{ "MOD_ASSIGN", 274 },
		{ "ADD_ASSIGN", 275 },
		{ "SUB_ASSIGN", 276 },
		{ "LEFT_ASSIGN", 277 },
		{ "RIGHT_ASSIGN", 278 },
		{ "AND_ASSIGN", 279 },
		{ "XOR_ASSIGN", 280 },
		{ "OR_ASSIGN", 281 },
		{ "TYPE_NAME", 282 },
		{ "TYPEDEF", 283 },
		{ "EXTERN", 284 },
		{ "STATIC", 285 },
		{ "AUTO", 286 },
		{ "REGISTER", 287 },
		{ "CHAR", 288 },
		{ "SHORT", 289 },
		{ "INT", 290 },
		{ "LONG", 291 },
		{ "SIGNED", 292 },
		{ "UNSIGNED", 293 },
		{ "FLOAT", 294 },
		{ "DOUBLE", 295 },
		{ "CONST", 296 },
		{ "VOLATILE", 297 },
		{ "VOID", 298 },
		{ "STRUCT", 299 },
		{ "UNION", 300 },
		{ "ENUM", 301 },
		{ "ELLIPSIS", 302 },
		{ "CASE", 303 },
		{ "DEFAULT", 304 },
		{ "IF", 305 },
		{ "ELSE", 306 },
		{ "SWITCH", 307 },
		{ "WHILE", 308 },
		{ "DO", 309 },
		{ "FOR", 310 },
		{ "GOTO", 311 },
		{ "CONTINUE", 312 },
		{ "BREAK", 313 },
		{ "RETURN", 314 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: translation_unit",
		"primary_exp: ID",
		"primary_exp: CONSTANT",
		"primary_exp: STRING_LITERAL",
		"primary_exp: \'(\' exp \')\'",
		"postfix_pre_exp: postfix_exp \'(\'",
		"postfix_exp: primary_exp",
		"postfix_exp: postfix_exp \'[\' exp \']\'",
		"postfix_exp: postfix_pre_exp \')\'",
		"postfix_exp: postfix_pre_exp argument_exp_list \')\'",
		"postfix_exp: postfix_exp \'.\' ID",
		"postfix_exp: postfix_exp PTR_OP ID",
		"postfix_exp: postfix_exp INC_OP",
		"postfix_exp: postfix_exp DEC_OP",
		"argument_exp_list: assignment_exp",
		"argument_exp_list: argument_exp_list \',\' assignment_exp",
		"unary_exp: postfix_exp",
		"unary_exp: INC_OP unary_exp",
		"unary_exp: DEC_OP unary_exp",
		"unary_exp: unary_operator cast_exp",
		"unary_exp: SIZEOF unary_exp",
		"unary_exp: SIZEOF \'(\' type_name \')\'",
		"unary_operator: \'&\'",
		"unary_operator: \'*\'",
		"unary_operator: \'+\'",
		"unary_operator: \'-\'",
		"unary_operator: \'~\'",
		"unary_operator: \'!\'",
		"cast_exp: unary_exp",
		"cast_exp: \'(\' type_name \')\' cast_exp",
		"multiplicative_exp: cast_exp",
		"multiplicative_exp: multiplicative_exp \'*\' cast_exp",
		"multiplicative_exp: multiplicative_exp \'/\' cast_exp",
		"multiplicative_exp: multiplicative_exp \'%\' cast_exp",
		"additive_exp: multiplicative_exp",
		"additive_exp: additive_exp \'+\' multiplicative_exp",
		"additive_exp: additive_exp \'-\' multiplicative_exp",
		"shift_exp: additive_exp",
		"shift_exp: shift_exp LEFT_OP additive_exp",
		"shift_exp: shift_exp RIGHT_OP additive_exp",
		"relational_exp: shift_exp",
		"relational_exp: relational_exp \'<\' shift_exp",
		"relational_exp: relational_exp \'>\' shift_exp",
		"relational_exp: relational_exp LE_OP shift_exp",
		"relational_exp: relational_exp GE_OP shift_exp",
		"equality_exp: relational_exp",
		"equality_exp: equality_exp EQ_OP relational_exp",
		"equality_exp: equality_exp NE_OP relational_exp",
		"and_exp: equality_exp",
		"and_exp: and_exp \'&\' equality_exp",
		"exclusive_or_exp: and_exp",
		"exclusive_or_exp: exclusive_or_exp \'^\' and_exp",
		"inclusive_or_exp: exclusive_or_exp",
		"inclusive_or_exp: inclusive_or_exp \'|\' exclusive_or_exp",
		"logical_and_exp: inclusive_or_exp",
		"logical_and_exp: logical_and_exp AND_OP inclusive_or_exp",
		"logical_or_exp: logical_and_exp",
		"logical_or_exp: logical_or_exp OR_OP logical_and_exp",
		"conditional_exp: logical_or_exp",
		"conditional_exp: logical_or_exp \'\?\' exp \':\' conditional_exp",
		"assignment_exp: conditional_exp",
		"assignment_exp: unary_exp assignment_operator assignment_exp",
		"assignment_operator: \'=\'",
		"assignment_operator: MUL_ASSIGN",
		"assignment_operator: DIV_ASSIGN",
		"assignment_operator: MOD_ASSIGN",
		"assignment_operator: ADD_ASSIGN",
		"assignment_operator: SUB_ASSIGN",
		"assignment_operator: LEFT_ASSIGN",
		"assignment_operator: RIGHT_ASSIGN",
		"assignment_operator: AND_ASSIGN",
		"assignment_operator: XOR_ASSIGN",
		"assignment_operator: OR_ASSIGN",
		"exp: assignment_exp",
		"exp: exp \',\' assignment_exp",
		"constant_exp: conditional_exp",
		"declaration: declaration_specifiers \';\'",
		"declaration: declaration_specifiers init_declarator_list \';\'",
		"declaration_specifiers: storage_class_specifier",
		"declaration_specifiers: storage_class_specifier declaration_specifiers",
		"declaration_specifiers: type_specifier",
		"declaration_specifiers: type_specifier declaration_specifiers",
		"declaration_specifiers: type_qualifier",
		"declaration_specifiers: type_qualifier declaration_specifiers",
		"init_declarator_list: init_declarator",
		"init_declarator_list: init_declarator_list \',\' init_declarator",
		"init_declarator: declarator",
		"init_declarator: declarator \'=\' initializer",
		"storage_class_specifier: TYPEDEF",
		"storage_class_specifier: EXTERN",
		"storage_class_specifier: STATIC",
		"storage_class_specifier: AUTO",
		"storage_class_specifier: REGISTER",
		"type_specifier: VOID",
		"type_specifier: CHAR",
		"type_specifier: SHORT",
		"type_specifier: INT",
		"type_specifier: LONG",
		"type_specifier: FLOAT",
		"type_specifier: DOUBLE",
		"type_specifier: SIGNED",
		"type_specifier: UNSIGNED",
		"type_specifier: struct_or_union_specifier",
		"type_specifier: enum_specifier",
		"type_specifier: TYPE_NAME",
		"type_specifier: type_specifier pointer",
		"struct_or_union_def: struct_or_union ID \'{\' declaration_list \'}\'",
		"struct_or_union_def: struct_or_union \'{\' declaration_list \'}\'",
		"def_concat: \';\'",
		"def_concat: init_declarator_list \';\'",
		"struct_or_union_specifier: struct_or_union_def def_concat",
		"struct_or_union_specifier: struct_or_union ID",
		"struct_or_union: STRUCT",
		"struct_or_union: UNION",
		"struct_declaration_list: struct_declaration",
		"struct_declaration_list: struct_declaration_list struct_declaration",
		"struct_declaration: specifier_qualifier_list struct_declarator_list \';\'",
		"struct_declaration: assignment_exp struct_declarator_list \';\'",
		"specifier_qualifier_list: type_specifier specifier_qualifier_list",
		"specifier_qualifier_list: type_specifier",
		"specifier_qualifier_list: type_qualifier specifier_qualifier_list",
		"specifier_qualifier_list: type_qualifier",
		"struct_declarator_list: struct_declarator",
		"struct_declarator_list: struct_declarator_list \',\' struct_declarator",
		"struct_declarator: declarator",
		"struct_declarator: \':\' constant_exp",
		"struct_declarator: declarator \':\' constant_exp",
		"enum_specifier: ENUM \'{\' enumerator_list \'}\'",
		"enum_specifier: ENUM ID \'{\' enumerator_list \'}\'",
		"enum_specifier: ENUM ID",
		"enumerator_list: enumerator",
		"enumerator_list: enumerator_list \',\' enumerator",
		"enumerator: ID",
		"enumerator: ID \'=\' constant_exp",
		"type_qualifier: CONST",
		"type_qualifier: VOLATILE",
		"declarator: pointer direct_declarator",
		"declarator: direct_declarator",
		"direct_pre_declarator: direct_declarator \'(\'",
		"direct_declarator: ID",
		"direct_declarator: \'(\' declarator \')\'",
		"direct_declarator: direct_declarator \'[\' constant_exp \']\'",
		"direct_declarator: direct_declarator \'[\' \']\'",
		"direct_declarator: direct_pre_declarator parameter_type_list \')\'",
		"direct_declarator: direct_pre_declarator identifier_list \')\'",
		"direct_declarator: direct_pre_declarator \')\'",
		"pointer: \'*\'",
		"pointer: \'*\' type_qualifier_list",
		"pointer: \'*\' pointer",
		"pointer: \'*\' type_qualifier_list pointer",
		"type_qualifier_list: type_qualifier",
		"type_qualifier_list: type_qualifier_list type_qualifier",
		"parameter_type_list: parameter_list",
		"parameter_type_list: parameter_list \',\' ELLIPSIS",
		"parameter_list: parameter_declaration",
		"parameter_list: parameter_list \',\' parameter_declaration",
		"parameter_declaration: declaration_specifiers declarator",
		"parameter_declaration: declaration_specifiers abstract_declarator",
		"parameter_declaration: declaration_specifiers",
		"identifier_list: ID",
		"identifier_list: identifier_list \',\' ID",
		"type_name: specifier_qualifier_list",
		"type_name: specifier_qualifier_list abstract_declarator",
		"abstract_declarator: pointer",
		"abstract_declarator: direct_abstract_declarator",
		"abstract_declarator: pointer direct_abstract_declarator",
		"direct_abstract_declarator: \'(\' abstract_declarator \')\'",
		"direct_abstract_declarator: \'[\' \']\'",
		"direct_abstract_declarator: \'[\' constant_exp \']\'",
		"direct_abstract_declarator: direct_abstract_declarator \'[\' \']\'",
		"direct_abstract_declarator: direct_abstract_declarator \'[\' constant_exp \']\'",
		"direct_abstract_declarator: \'(\' \')\'",
		"direct_abstract_declarator: \'(\' parameter_type_list \')\'",
		"direct_abstract_declarator: direct_abstract_declarator \'(\' \')\'",
		"direct_abstract_declarator: direct_abstract_declarator \'(\' parameter_type_list \')\'",
		"initializer: assignment_exp",
		"initializer: \'{\' initializer_list \'}\'",
		"initializer: \'{\' initializer_list \',\' \'}\'",
		"initializer_list: initializer",
		"initializer_list: initializer_list \',\' initializer",
		"other: labeled_statement",
		"other: compound_statement",
		"other: exp_statement",
		"other: iteration_statement",
		"other: jump_statement",
		"other:",
		"statement: labeled_statement",
		"statement: compound_statement",
		"statement: exp_statement",
		"statement: selection_statement",
		"statement: iteration_statement",
		"statement: jump_statement",
		"labeled_statement: ID \':\' statement",
		"labeled_statement: CASE constant_exp \':\' statement",
		"labeled_statement: DEFAULT \':\' statement",
		"compound_statement: \'{\' \'}\'",
		"compound_statement: \'{\' statement_list \'}\'",
		"compound_statement: \'{\' declaration_list \'}\'",
		"compound_statement: \'{\' declaration_list statement_list \'}\'",
		"declaration_list: declaration",
		"declaration_list: declaration_list declaration",
		"statement_list: statement",
		"statement_list: statement_list statement",
		"exp_statement: \';\'",
		"exp_statement: exp \';\'",
		"stmt: matched_statement",
		"stmt: open_statement",
		"matched_statement: IF \'(\' exp \')\' matched_statement ELSE matched_statement",
		"matched_statement: other",
		"open_statement: IF \'(\' exp \')\' stmt",
		"open_statement: IF \'(\' exp \')\' matched_statement ELSE open_statement",
		"selection_statement: stmt",
		"selection_statement: SWITCH \'(\' exp \')\' statement",
		"iteration_statement: WHILE \'(\' exp \')\' statement",
		"iteration_statement: DO statement WHILE \'(\' exp \')\' \';\'",
		"iteration_statement: FOR \'(\' exp_statement exp_statement \')\' statement",
		"iteration_statement: FOR \'(\' exp_statement exp_statement exp \')\' statement",
		"jump_statement: GOTO ID \';\'",
		"jump_statement: CONTINUE \';\'",
		"jump_statement: BREAK \';\'",
		"jump_statement: RETURN \';\'",
		"jump_statement: RETURN exp \';\'",
		"translation_unit: external_declaration",
		"translation_unit: translation_unit external_declaration",
		"external_declaration: function_definition",
		"external_declaration: declaration",
		"function_definition: declaration_specifiers declarator declaration_list compound_statement",
		"function_definition: declaration_specifiers declarator compound_statement",
		"function_definition: declarator declaration_list compound_statement",
		"function_definition: declarator compound_statement"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 1, 1, 1 },
		{ 1, 1, 2 },
		{ 1, 3, 3 },
		{ 2, 2, 4 },
		{ 3, 1, 5 },
		{ 3, 4, 6 },
		{ 3, 2, 7 },
		{ 3, 3, 8 },
		{ 3, 3, 9 },
		{ 3, 3, 10 },
		{ 3, 2, 11 },
		{ 3, 2, 12 },
		{ 4, 1, 13 },
		{ 4, 3, 14 },
		{ 5, 1, 15 },
		{ 5, 2, 16 },
		{ 5, 2, 17 },
		{ 5, 2, 18 },
		{ 5, 2, 19 },
		{ 5, 4, 20 },
		{ 6, 1, 21 },
		{ 6, 1, 22 },
		{ 6, 1, 23 },
		{ 6, 1, 24 },
		{ 6, 1, 25 },
		{ 6, 1, 26 },
		{ 7, 1, 27 },
		{ 7, 4, 28 },
		{ 8, 1, 29 },
		{ 8, 3, 30 },
		{ 8, 3, 31 },
		{ 8, 3, 32 },
		{ 9, 1, 33 },
		{ 9, 3, 34 },
		{ 9, 3, 35 },
		{ 10, 1, 36 },
		{ 10, 3, 37 },
		{ 10, 3, 38 },
		{ 11, 1, 39 },
		{ 11, 3, 40 },
		{ 11, 3, 41 },
		{ 11, 3, 42 },
		{ 11, 3, 43 },
		{ 12, 1, 44 },
		{ 12, 3, 45 },
		{ 12, 3, 46 },
		{ 13, 1, 47 },
		{ 13, 3, 48 },
		{ 14, 1, 49 },
		{ 14, 3, 50 },
		{ 15, 1, 51 },
		{ 15, 3, 52 },
		{ 16, 1, 53 },
		{ 16, 3, 54 },
		{ 17, 1, 55 },
		{ 17, 3, 56 },
		{ 18, 1, 57 },
		{ 18, 5, 58 },
		{ 19, 1, 59 },
		{ 19, 3, 60 },
		{ 20, 1, 61 },
		{ 20, 1, 62 },
		{ 20, 1, 63 },
		{ 20, 1, 64 },
		{ 20, 1, 65 },
		{ 20, 1, 66 },
		{ 20, 1, 67 },
		{ 20, 1, 68 },
		{ 20, 1, 69 },
		{ 20, 1, 70 },
		{ 20, 1, 71 },
		{ 21, 1, 72 },
		{ 21, 3, 73 },
		{ 22, 1, 74 },
		{ 23, 2, 75 },
		{ 23, 3, 76 },
		{ 24, 1, 77 },
		{ 24, 2, 78 },
		{ 24, 1, 79 },
		{ 24, 2, 80 },
		{ 24, 1, 81 },
		{ 24, 2, 82 },
		{ 25, 1, 83 },
		{ 25, 3, 84 },
		{ 26, 1, 85 },
		{ 26, 3, 86 },
		{ 27, 1, 87 },
		{ 27, 1, 88 },
		{ 27, 1, 89 },
		{ 27, 1, 90 },
		{ 27, 1, 91 },
		{ 28, 1, 92 },
		{ 28, 1, 93 },
		{ 28, 1, 94 },
		{ 28, 1, 95 },
		{ 28, 1, 96 },
		{ 28, 1, 97 },
		{ 28, 1, 98 },
		{ 28, 1, 99 },
		{ 28, 1, 100 },
		{ 28, 1, 101 },
		{ 28, 1, 102 },
		{ 28, 1, 103 },
		{ 28, 2, 104 },
		{ 29, 5, 105 },
		{ 29, 4, 106 },
		{ 30, 1, 107 },
		{ 30, 2, 108 },
		{ 31, 2, 109 },
		{ 31, 2, 110 },
		{ 32, 1, 111 },
		{ 32, 1, 112 },
		{ 33, 1, 113 },
		{ 33, 2, 114 },
		{ 34, 3, 115 },
		{ 34, 3, 116 },
		{ 35, 2, 117 },
		{ 35, 1, 118 },
		{ 35, 2, 119 },
		{ 35, 1, 120 },
		{ 36, 1, 121 },
		{ 36, 3, 122 },
		{ 37, 1, 123 },
		{ 37, 2, 124 },
		{ 37, 3, 125 },
		{ 38, 4, 126 },
		{ 38, 5, 127 },
		{ 38, 2, 128 },
		{ 39, 1, 129 },
		{ 39, 3, 130 },
		{ 40, 1, 131 },
		{ 40, 3, 132 },
		{ 41, 1, 133 },
		{ 41, 1, 134 },
		{ 42, 2, 135 },
		{ 42, 1, 136 },
		{ 43, 2, 137 },
		{ 44, 1, 138 },
		{ 44, 3, 139 },
		{ 44, 4, 140 },
		{ 44, 3, 141 },
		{ 44, 3, 142 },
		{ 44, 3, 143 },
		{ 44, 2, 144 },
		{ 45, 1, 145 },
		{ 45, 2, 146 },
		{ 45, 2, 147 },
		{ 45, 3, 148 },
		{ 46, 1, 149 },
		{ 46, 2, 150 },
		{ 47, 1, 151 },
		{ 47, 3, 152 },
		{ 48, 1, 153 },
		{ 48, 3, 154 },
		{ 49, 2, 155 },
		{ 49, 2, 156 },
		{ 49, 1, 157 },
		{ 50, 1, 158 },
		{ 50, 3, 159 },
		{ 51, 1, 160 },
		{ 51, 2, 161 },
		{ 52, 1, 162 },
		{ 52, 1, 163 },
		{ 52, 2, 164 },
		{ 53, 3, 165 },
		{ 53, 2, 166 },
		{ 53, 3, 167 },
		{ 53, 3, 168 },
		{ 53, 4, 169 },
		{ 53, 2, 170 },
		{ 53, 3, 171 },
		{ 53, 3, 172 },
		{ 53, 4, 173 },
		{ 54, 1, 174 },
		{ 54, 3, 175 },
		{ 54, 4, 176 },
		{ 55, 1, 177 },
		{ 55, 3, 178 },
		{ 56, 1, 179 },
		{ 56, 1, 180 },
		{ 56, 1, 181 },
		{ 56, 1, 182 },
		{ 56, 1, 183 },
		{ 56, 0, 184 },
		{ 57, 1, 185 },
		{ 57, 1, 186 },
		{ 57, 1, 187 },
		{ 57, 1, 188 },
		{ 57, 1, 189 },
		{ 57, 1, 190 },
		{ 58, 3, 191 },
		{ 58, 4, 192 },
		{ 58, 3, 193 },
		{ 59, 2, 194 },
		{ 59, 3, 195 },
		{ 59, 3, 196 },
		{ 59, 4, 197 },
		{ 60, 1, 198 },
		{ 60, 2, 199 },
		{ 61, 1, 200 },
		{ 61, 2, 201 },
		{ 62, 1, 202 },
		{ 62, 2, 203 },
		{ 63, 1, 204 },
		{ 63, 1, 205 },
		{ 64, 7, 206 },
		{ 64, 1, 207 },
		{ 65, 5, 208 },
		{ 65, 7, 209 },
		{ 66, 1, 210 },
		{ 66, 5, 211 },
		{ 67, 5, 212 },
		{ 67, 7, 213 },
		{ 67, 6, 214 },
		{ 67, 7, 215 },
		{ 68, 3, 216 },
		{ 68, 2, 217 },
		{ 68, 2, 218 },
		{ 68, 2, 219 },
		{ 68, 3, 220 },
		{ 69, 1, 221 },
		{ 69, 2, 222 },
		{ 70, 1, 223 },
		{ 70, 1, 224 },
		{ 71, 4, 225 },
		{ 71, 3, 226 },
		{ 71, 3, 227 },
		{ 71, 2, 228 }
	};
	yyreduction = reduction;

	yytokenaction_size = 770;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 350, YYAT_SHIFT, 88 },
		{ 70, YYAT_SHIFT, 156 },
		{ 159, YYAT_SHIFT, 156 },
		{ 70, YYAT_SHIFT, 2 },
		{ 86, YYAT_SHIFT, 1 },
		{ 350, YYAT_SHIFT, 89 },
		{ 86, YYAT_SHIFT, 2 },
		{ 350, YYAT_SHIFT, 90 },
		{ 264, YYAT_SHIFT, 317 },
		{ 350, YYAT_SHIFT, 91 },
		{ 350, YYAT_SHIFT, 92 },
		{ 119, YYAT_SHIFT, 209 },
		{ 350, YYAT_SHIFT, 93 },
		{ 344, YYAT_SHIFT, 88 },
		{ 156, YYAT_SHIFT, 156 },
		{ 126, YYAT_SHIFT, 234 },
		{ 198, YYAT_SHIFT, 232 },
		{ 119, YYAT_SHIFT, 210 },
		{ 344, YYAT_SHIFT, 89 },
		{ 36, YYAT_SHIFT, 68 },
		{ 344, YYAT_SHIFT, 90 },
		{ 169, YYAT_SHIFT, 167 },
		{ 344, YYAT_SHIFT, 91 },
		{ 344, YYAT_SHIFT, 92 },
		{ 345, YYAT_SHIFT, 350 },
		{ 344, YYAT_SHIFT, 93 },
		{ 350, YYAT_SHIFT, 94 },
		{ 345, YYAT_SHIFT, 232 },
		{ 324, YYAT_SHIFT, 88 },
		{ 25, YYAT_SHIFT, 46 },
		{ 23, YYAT_SHIFT, 44 },
		{ 198, YYAT_SHIFT, 282 },
		{ 286, YYAT_SHIFT, 199 },
		{ 324, YYAT_SHIFT, 89 },
		{ 286, YYAT_SHIFT, 200 },
		{ 324, YYAT_SHIFT, 90 },
		{ 61, YYAT_SHIFT, 86 },
		{ 324, YYAT_SHIFT, 91 },
		{ 324, YYAT_SHIFT, 92 },
		{ 344, YYAT_SHIFT, 94 },
		{ 324, YYAT_SHIFT, 93 },
		{ 43, YYAT_SHIFT, 2 },
		{ 292, YYAT_SHIFT, 203 },
		{ 348, YYAT_SHIFT, 353 },
		{ 292, YYAT_SHIFT, 204 },
		{ 37, YYAT_ACCEPT, 0 },
		{ 294, YYAT_SHIFT, 232 },
		{ 254, YYAT_ERROR, 0 },
		{ 254, YYAT_SHIFT, 313 },
		{ 254, YYAT_ERROR, 0 },
		{ 269, YYAT_SHIFT, 268 },
		{ 61, YYAT_SHIFT, 150 },
		{ 70, YYAT_SHIFT, 157 },
		{ 159, YYAT_SHIFT, 157 },
		{ 324, YYAT_SHIFT, 94 },
		{ 244, YYAT_SHIFT, 308 },
		{ 343, YYAT_SHIFT, 348 },
		{ 179, YYAT_SHIFT, 268 },
		{ 244, YYAT_SHIFT, 309 },
		{ 179, YYAT_SHIFT, 2 },
		{ 253, YYAT_SHIFT, 254 },
		{ 285, YYAT_SHIFT, 199 },
		{ 119, YYAT_SHIFT, 211 },
		{ 285, YYAT_SHIFT, 200 },
		{ 2, YYAT_SHIFT, 2 },
		{ 33, YYAT_SHIFT, 4 },
		{ 33, YYAT_SHIFT, 5 },
		{ 33, YYAT_SHIFT, 6 },
		{ 33, YYAT_SHIFT, 7 },
		{ 33, YYAT_SHIFT, 8 },
		{ 33, YYAT_SHIFT, 9 },
		{ 33, YYAT_SHIFT, 10 },
		{ 33, YYAT_SHIFT, 11 },
		{ 33, YYAT_SHIFT, 12 },
		{ 33, YYAT_SHIFT, 13 },
		{ 33, YYAT_SHIFT, 14 },
		{ 33, YYAT_SHIFT, 15 },
		{ 33, YYAT_SHIFT, 16 },
		{ 33, YYAT_SHIFT, 17 },
		{ 33, YYAT_SHIFT, 18 },
		{ 33, YYAT_SHIFT, 19 },
		{ 33, YYAT_SHIFT, 20 },
		{ 33, YYAT_SHIFT, 21 },
		{ 33, YYAT_SHIFT, 22 },
		{ 33, YYAT_SHIFT, 23 },
		{ 37, YYAT_SHIFT, 1 },
		{ 37, YYAT_ERROR, 0 },
		{ 323, YYAT_SHIFT, 88 },
		{ 161, YYAT_SHIFT, 254 },
		{ 264, YYAT_SHIFT, 318 },
		{ 350, YYAT_SHIFT, 54 },
		{ 340, YYAT_SHIFT, 347 },
		{ 323, YYAT_SHIFT, 89 },
		{ 350, YYAT_SHIFT, 96 },
		{ 323, YYAT_SHIFT, 90 },
		{ 294, YYAT_SHIFT, 327 },
		{ 323, YYAT_SHIFT, 91 },
		{ 323, YYAT_SHIFT, 92 },
		{ 254, YYAT_ERROR, 0 },
		{ 323, YYAT_SHIFT, 93 },
		{ 274, YYAT_SHIFT, 88 },
		{ 269, YYAT_SHIFT, 157 },
		{ 169, YYAT_SHIFT, 261 },
		{ 344, YYAT_SHIFT, 54 },
		{ 326, YYAT_SHIFT, 344 },
		{ 274, YYAT_SHIFT, 89 },
		{ 344, YYAT_SHIFT, 96 },
		{ 274, YYAT_SHIFT, 90 },
		{ 179, YYAT_SHIFT, 157 },
		{ 274, YYAT_SHIFT, 91 },
		{ 274, YYAT_SHIFT, 92 },
		{ 253, YYAT_SHIFT, 255 },
		{ 274, YYAT_SHIFT, 93 },
		{ 323, YYAT_SHIFT, 94 },
		{ 291, YYAT_SHIFT, 203 },
		{ 188, YYAT_SHIFT, 88 },
		{ 291, YYAT_SHIFT, 204 },
		{ 66, YYAT_SHIFT, 62 },
		{ 324, YYAT_SHIFT, 54 },
		{ 30, YYAT_SHIFT, 62 },
		{ 188, YYAT_SHIFT, 89 },
		{ 324, YYAT_SHIFT, 96 },
		{ 188, YYAT_SHIFT, 90 },
		{ 302, YYAT_SHIFT, 232 },
		{ 188, YYAT_SHIFT, 91 },
		{ 188, YYAT_SHIFT, 92 },
		{ 274, YYAT_SHIFT, 94 },
		{ 188, YYAT_SHIFT, 93 },
		{ 117, YYAT_SHIFT, 203 },
		{ 74, YYAT_SHIFT, 164 },
		{ 117, YYAT_SHIFT, 204 },
		{ 115, YYAT_SHIFT, 199 },
		{ 74, YYAT_SHIFT, 165 },
		{ 115, YYAT_SHIFT, 200 },
		{ 304, YYAT_SHIFT, 207 },
		{ 304, YYAT_SHIFT, 208 },
		{ 37, YYAT_ERROR, 0 },
		{ 302, YYAT_SHIFT, 328 },
		{ 317, YYAT_SHIFT, 332 },
		{ 161, YYAT_SHIFT, 255 },
		{ 316, YYAT_SHIFT, 331 },
		{ 188, YYAT_SHIFT, 94 },
		{ 27, YYAT_SHIFT, 4 },
		{ 27, YYAT_SHIFT, 5 },
		{ 27, YYAT_SHIFT, 6 },
		{ 27, YYAT_SHIFT, 7 },
		{ 27, YYAT_SHIFT, 8 },
		{ 27, YYAT_SHIFT, 9 },
		{ 27, YYAT_SHIFT, 10 },
		{ 27, YYAT_SHIFT, 11 },
		{ 27, YYAT_SHIFT, 12 },
		{ 27, YYAT_SHIFT, 13 },
		{ 27, YYAT_SHIFT, 14 },
		{ 27, YYAT_SHIFT, 15 },
		{ 27, YYAT_SHIFT, 16 },
		{ 27, YYAT_SHIFT, 17 },
		{ 27, YYAT_SHIFT, 18 },
		{ 27, YYAT_SHIFT, 19 },
		{ 27, YYAT_SHIFT, 20 },
		{ 27, YYAT_SHIFT, 21 },
		{ 27, YYAT_SHIFT, 22 },
		{ 27, YYAT_SHIFT, 23 },
		{ 284, YYAT_SHIFT, 228 },
		{ 25, YYAT_SHIFT, 47 },
		{ 23, YYAT_SHIFT, 45 },
		{ 314, YYAT_SHIFT, 330 },
		{ 283, YYAT_SHIFT, 228 },
		{ 284, YYAT_SHIFT, 229 },
		{ 66, YYAT_SHIFT, 63 },
		{ 306, YYAT_SHIFT, 237 },
		{ 30, YYAT_SHIFT, 63 },
		{ 283, YYAT_SHIFT, 229 },
		{ 284, YYAT_SHIFT, 230 },
		{ 305, YYAT_SHIFT, 236 },
		{ 181, YYAT_SHIFT, 88 },
		{ 303, YYAT_SHIFT, 231 },
		{ 283, YYAT_SHIFT, 230 },
		{ 323, YYAT_SHIFT, 54 },
		{ 300, YYAT_SHIFT, 238 },
		{ 181, YYAT_SHIFT, 89 },
		{ 323, YYAT_SHIFT, 96 },
		{ 181, YYAT_SHIFT, 90 },
		{ 123, YYAT_SHIFT, 228 },
		{ 181, YYAT_SHIFT, 91 },
		{ 181, YYAT_SHIFT, 92 },
		{ 60, YYAT_SHIFT, 85 },
		{ 181, YYAT_SHIFT, 93 },
		{ 123, YYAT_SHIFT, 229 },
		{ 290, YYAT_SHIFT, 201 },
		{ 290, YYAT_SHIFT, 202 },
		{ 274, YYAT_SHIFT, 54 },
		{ 280, YYAT_SHIFT, 94 },
		{ 123, YYAT_SHIFT, 230 },
		{ 274, YYAT_SHIFT, 96 },
		{ 289, YYAT_SHIFT, 201 },
		{ 289, YYAT_SHIFT, 202 },
		{ 288, YYAT_SHIFT, 201 },
		{ 288, YYAT_SHIFT, 202 },
		{ 287, YYAT_SHIFT, 201 },
		{ 287, YYAT_SHIFT, 202 },
		{ 181, YYAT_SHIFT, 94 },
		{ 118, YYAT_SHIFT, 207 },
		{ 118, YYAT_SHIFT, 208 },
		{ 116, YYAT_SHIFT, 201 },
		{ 116, YYAT_SHIFT, 202 },
		{ 188, YYAT_SHIFT, 54 },
		{ 279, YYAT_SHIFT, 325 },
		{ 278, YYAT_SHIFT, 324 },
		{ 188, YYAT_SHIFT, 96 },
		{ 277, YYAT_SHIFT, 323 },
		{ 276, YYAT_SHIFT, 322 },
		{ 273, YYAT_SHIFT, 320 },
		{ 255, YYAT_SHIFT, 315 },
		{ 252, YYAT_SHIFT, 312 },
		{ 250, YYAT_SHIFT, 311 },
		{ 249, YYAT_SHIFT, 310 },
		{ 31, YYAT_SHIFT, 2 },
		{ 212, YYAT_SHIFT, 295 },
		{ 70, YYAT_SHIFT, 3 },
		{ 159, YYAT_SHIFT, 3 },
		{ 210, YYAT_SHIFT, 293 },
		{ 86, YYAT_SHIFT, 3 },
		{ 194, YYAT_SHIFT, 281 },
		{ 126, YYAT_SHIFT, 235 },
		{ 350, YYAT_SHIFT, 97 },
		{ 350, YYAT_SHIFT, 98 },
		{ 350, YYAT_SHIFT, 99 },
		{ 350, YYAT_SHIFT, 100 },
		{ 192, YYAT_SHIFT, 279 },
		{ 350, YYAT_SHIFT, 101 },
		{ 350, YYAT_SHIFT, 102 },
		{ 156, YYAT_SHIFT, 3 },
		{ 119, YYAT_SHIFT, 212 },
		{ 119, YYAT_SHIFT, 213 },
		{ 119, YYAT_SHIFT, 214 },
		{ 36, YYAT_SHIFT, 69 },
		{ 187, YYAT_SHIFT, 274 },
		{ 344, YYAT_SHIFT, 97 },
		{ 344, YYAT_SHIFT, 98 },
		{ 344, YYAT_SHIFT, 99 },
		{ 344, YYAT_SHIFT, 100 },
		{ 180, YYAT_SHIFT, 271 },
		{ 344, YYAT_SHIFT, 101 },
		{ 344, YYAT_SHIFT, 102 },
		{ 178, YYAT_SHIFT, 267 },
		{ 172, YYAT_SHIFT, 172 },
		{ 171, YYAT_SHIFT, 262 },
		{ 60, YYAT_SHIFT, 54 },
		{ 292, YYAT_SHIFT, 205 },
		{ 292, YYAT_SHIFT, 206 },
		{ 167, YYAT_SHIFT, 79 },
		{ 165, YYAT_SHIFT, 258 },
		{ 324, YYAT_SHIFT, 97 },
		{ 324, YYAT_SHIFT, 98 },
		{ 324, YYAT_SHIFT, 99 },
		{ 324, YYAT_SHIFT, 100 },
		{ 347, YYAT_SHIFT, 88 },
		{ 324, YYAT_SHIFT, 101 },
		{ 324, YYAT_SHIFT, 102 },
		{ 162, YYAT_SHIFT, 256 },
		{ 177, YYAT_SHIFT, 2 },
		{ 347, YYAT_SHIFT, 89 },
		{ 157, YYAT_SHIFT, 251 },
		{ 347, YYAT_SHIFT, 90 },
		{ 181, YYAT_SHIFT, 54 },
		{ 347, YYAT_SHIFT, 91 },
		{ 347, YYAT_SHIFT, 92 },
		{ 181, YYAT_SHIFT, 96 },
		{ 347, YYAT_SHIFT, 93 },
		{ 154, YYAT_SHIFT, 247 },
		{ 350, YYAT_SHIFT, 103 },
		{ 350, YYAT_SHIFT, 104 },
		{ 350, YYAT_SHIFT, 105 },
		{ 149, YYAT_SHIFT, 54 },
		{ 350, YYAT_SHIFT, 106 },
		{ 350, YYAT_SHIFT, 107 },
		{ 350, YYAT_SHIFT, 108 },
		{ 350, YYAT_SHIFT, 109 },
		{ 350, YYAT_SHIFT, 110 },
		{ 350, YYAT_SHIFT, 111 },
		{ 350, YYAT_SHIFT, 112 },
		{ 350, YYAT_SHIFT, 113 },
		{ 347, YYAT_SHIFT, 94 },
		{ 344, YYAT_SHIFT, 103 },
		{ 344, YYAT_SHIFT, 104 },
		{ 344, YYAT_SHIFT, 105 },
		{ 145, YYAT_SHIFT, 243 },
		{ 344, YYAT_SHIFT, 106 },
		{ 344, YYAT_SHIFT, 107 },
		{ 344, YYAT_SHIFT, 108 },
		{ 344, YYAT_SHIFT, 109 },
		{ 344, YYAT_SHIFT, 110 },
		{ 344, YYAT_SHIFT, 111 },
		{ 344, YYAT_SHIFT, 112 },
		{ 344, YYAT_SHIFT, 113 },
		{ 43, YYAT_SHIFT, 18 },
		{ 43, YYAT_SHIFT, 19 },
		{ 134, YYAT_SHIFT, 239 },
		{ 324, YYAT_SHIFT, 103 },
		{ 324, YYAT_SHIFT, 104 },
		{ 324, YYAT_SHIFT, 105 },
		{ 131, YYAT_SHIFT, 238 },
		{ 324, YYAT_SHIFT, 106 },
		{ 324, YYAT_SHIFT, 107 },
		{ 324, YYAT_SHIFT, 108 },
		{ 324, YYAT_SHIFT, 109 },
		{ 324, YYAT_SHIFT, 110 },
		{ 324, YYAT_SHIFT, 111 },
		{ 324, YYAT_SHIFT, 112 },
		{ 324, YYAT_SHIFT, 113 },
		{ 129, YYAT_SHIFT, 237 },
		{ 323, YYAT_SHIFT, 97 },
		{ 323, YYAT_SHIFT, 98 },
		{ 323, YYAT_SHIFT, 99 },
		{ 323, YYAT_SHIFT, 100 },
		{ 128, YYAT_SHIFT, 236 },
		{ 323, YYAT_SHIFT, 101 },
		{ 323, YYAT_SHIFT, 102 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 291, YYAT_SHIFT, 205 },
		{ 291, YYAT_SHIFT, 206 },
		{ 125, YYAT_SHIFT, 233 },
		{ 124, YYAT_SHIFT, 231 },
		{ 274, YYAT_SHIFT, 97 },
		{ 274, YYAT_SHIFT, 98 },
		{ 274, YYAT_SHIFT, 99 },
		{ 274, YYAT_SHIFT, 100 },
		{ 113, YYAT_SHIFT, 197 },
		{ 274, YYAT_SHIFT, 101 },
		{ 274, YYAT_SHIFT, 102 },
		{ 112, YYAT_SHIFT, 196 },
		{ 111, YYAT_SHIFT, 195 },
		{ 110, YYAT_SHIFT, 194 },
		{ 117, YYAT_SHIFT, 205 },
		{ 117, YYAT_SHIFT, 206 },
		{ 109, YYAT_SHIFT, 193 },
		{ 108, YYAT_ERROR, 0 },
		{ 107, YYAT_SHIFT, 191 },
		{ 188, YYAT_SHIFT, 97 },
		{ 188, YYAT_SHIFT, 98 },
		{ 188, YYAT_SHIFT, 99 },
		{ 188, YYAT_SHIFT, 100 },
		{ 322, YYAT_SHIFT, 88 },
		{ 188, YYAT_SHIFT, 101 },
		{ 188, YYAT_SHIFT, 102 },
		{ 347, YYAT_SHIFT, 54 },
		{ 106, YYAT_SHIFT, 190 },
		{ 322, YYAT_SHIFT, 89 },
		{ 347, YYAT_SHIFT, 96 },
		{ 322, YYAT_SHIFT, 90 },
		{ 105, YYAT_SHIFT, 189 },
		{ 322, YYAT_SHIFT, 91 },
		{ 322, YYAT_SHIFT, 92 },
		{ 104, YYAT_SHIFT, 188 },
		{ 322, YYAT_SHIFT, 93 },
		{ 102, YYAT_SHIFT, 184 },
		{ 323, YYAT_SHIFT, 103 },
		{ 323, YYAT_SHIFT, 104 },
		{ 323, YYAT_SHIFT, 105 },
		{ 100, YYAT_SHIFT, 182 },
		{ 323, YYAT_SHIFT, 106 },
		{ 323, YYAT_SHIFT, 107 },
		{ 323, YYAT_SHIFT, 108 },
		{ 323, YYAT_SHIFT, 109 },
		{ 323, YYAT_SHIFT, 110 },
		{ 323, YYAT_SHIFT, 111 },
		{ 323, YYAT_SHIFT, 112 },
		{ 323, YYAT_SHIFT, 113 },
		{ 322, YYAT_SHIFT, 94 },
		{ 274, YYAT_SHIFT, 103 },
		{ 274, YYAT_SHIFT, 104 },
		{ 274, YYAT_SHIFT, 105 },
		{ 120, YYAT_SHIFT, 215 },
		{ 274, YYAT_SHIFT, 106 },
		{ 274, YYAT_SHIFT, 107 },
		{ 274, YYAT_SHIFT, 108 },
		{ 274, YYAT_SHIFT, 109 },
		{ 274, YYAT_SHIFT, 110 },
		{ 274, YYAT_SHIFT, 111 },
		{ 274, YYAT_SHIFT, 112 },
		{ 274, YYAT_SHIFT, 113 },
		{ 97, YYAT_SHIFT, 181 },
		{ 84, YYAT_ERROR, 0 },
		{ 83, YYAT_SHIFT, 170 },
		{ 188, YYAT_SHIFT, 103 },
		{ 188, YYAT_SHIFT, 104 },
		{ 188, YYAT_SHIFT, 105 },
		{ 81, YYAT_SHIFT, 168 },
		{ 188, YYAT_SHIFT, 106 },
		{ 188, YYAT_SHIFT, 107 },
		{ 188, YYAT_SHIFT, 108 },
		{ 188, YYAT_SHIFT, 109 },
		{ 188, YYAT_SHIFT, 110 },
		{ 188, YYAT_SHIFT, 111 },
		{ 188, YYAT_SHIFT, 112 },
		{ 188, YYAT_SHIFT, 113 },
		{ 79, YYAT_SHIFT, 166 },
		{ 181, YYAT_SHIFT, 97 },
		{ 181, YYAT_SHIFT, 98 },
		{ 181, YYAT_SHIFT, 99 },
		{ 181, YYAT_SHIFT, 100 },
		{ 72, YYAT_SHIFT, 163 },
		{ 181, YYAT_SHIFT, 101 },
		{ 181, YYAT_SHIFT, 102 },
		{ 71, YYAT_SHIFT, 162 },
		{ 60, YYAT_SHIFT, 4 },
		{ 60, YYAT_SHIFT, 5 },
		{ 60, YYAT_SHIFT, 6 },
		{ 60, YYAT_SHIFT, 7 },
		{ 60, YYAT_SHIFT, 8 },
		{ 60, YYAT_SHIFT, 9 },
		{ 60, YYAT_SHIFT, 10 },
		{ 60, YYAT_SHIFT, 11 },
		{ 60, YYAT_SHIFT, 12 },
		{ 60, YYAT_SHIFT, 13 },
		{ 60, YYAT_SHIFT, 14 },
		{ 60, YYAT_SHIFT, 15 },
		{ 60, YYAT_SHIFT, 16 },
		{ 60, YYAT_SHIFT, 17 },
		{ 60, YYAT_SHIFT, 18 },
		{ 60, YYAT_SHIFT, 19 },
		{ 60, YYAT_SHIFT, 20 },
		{ 60, YYAT_SHIFT, 21 },
		{ 60, YYAT_SHIFT, 22 },
		{ 60, YYAT_SHIFT, 23 },
		{ 63, YYAT_SHIFT, 151 },
		{ 139, YYAT_SHIFT, 94 },
		{ 56, YYAT_SHIFT, 59 },
		{ 54, YYAT_SHIFT, 95 },
		{ 50, YYAT_SHIFT, 87 },
		{ 49, YYAT_SHIFT, 85 },
		{ 47, YYAT_SHIFT, 84 },
		{ 322, YYAT_SHIFT, 54 },
		{ 45, YYAT_SHIFT, 82 },
		{ 40, YYAT_SHIFT, 76 },
		{ 322, YYAT_SHIFT, 96 },
		{ 32, YYAT_ERROR, 0 },
		{ 26, YYAT_SHIFT, 48 },
		{ 0, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 181, YYAT_SHIFT, 103 },
		{ 181, YYAT_SHIFT, 104 },
		{ 181, YYAT_SHIFT, 105 },
		{ -1, YYAT_ERROR, 0 },
		{ 181, YYAT_SHIFT, 106 },
		{ 181, YYAT_SHIFT, 107 },
		{ 181, YYAT_SHIFT, 108 },
		{ 181, YYAT_SHIFT, 109 },
		{ 181, YYAT_SHIFT, 110 },
		{ 181, YYAT_SHIFT, 111 },
		{ 181, YYAT_SHIFT, 112 },
		{ 181, YYAT_SHIFT, 113 },
		{ 31, YYAT_SHIFT, 4 },
		{ 31, YYAT_SHIFT, 5 },
		{ 31, YYAT_SHIFT, 6 },
		{ 31, YYAT_SHIFT, 7 },
		{ 31, YYAT_SHIFT, 8 },
		{ 31, YYAT_SHIFT, 9 },
		{ 31, YYAT_SHIFT, 10 },
		{ 31, YYAT_SHIFT, 11 },
		{ 31, YYAT_SHIFT, 12 },
		{ 31, YYAT_SHIFT, 13 },
		{ 31, YYAT_SHIFT, 14 },
		{ 31, YYAT_SHIFT, 15 },
		{ 31, YYAT_SHIFT, 16 },
		{ 31, YYAT_SHIFT, 17 },
		{ 31, YYAT_SHIFT, 18 },
		{ 31, YYAT_SHIFT, 19 },
		{ 31, YYAT_SHIFT, 20 },
		{ 31, YYAT_SHIFT, 21 },
		{ 31, YYAT_SHIFT, 22 },
		{ 31, YYAT_SHIFT, 23 },
		{ 242, YYAT_SHIFT, 54 },
		{ -1, YYAT_ERROR, 0 },
		{ 242, YYAT_SHIFT, 307 },
		{ -1, YYAT_ERROR, 0 },
		{ 347, YYAT_SHIFT, 97 },
		{ 347, YYAT_SHIFT, 98 },
		{ 347, YYAT_SHIFT, 99 },
		{ 347, YYAT_SHIFT, 100 },
		{ -1, YYAT_ERROR, 0 },
		{ 347, YYAT_SHIFT, 101 },
		{ 347, YYAT_SHIFT, 102 },
		{ 268, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 139, YYAT_SHIFT, 54 },
		{ 268, YYAT_ERROR, 0 },
		{ 139, YYAT_SHIFT, 241 },
		{ 268, YYAT_SHIFT, 268 },
		{ 268, YYAT_SHIFT, 248 },
		{ 268, YYAT_SHIFT, 2 },
		{ 268, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ 177, YYAT_SHIFT, 4 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 177, YYAT_SHIFT, 10 },
		{ 177, YYAT_SHIFT, 11 },
		{ 177, YYAT_SHIFT, 12 },
		{ 177, YYAT_SHIFT, 13 },
		{ 177, YYAT_SHIFT, 14 },
		{ 177, YYAT_SHIFT, 15 },
		{ 177, YYAT_SHIFT, 16 },
		{ 177, YYAT_SHIFT, 17 },
		{ 177, YYAT_SHIFT, 18 },
		{ 177, YYAT_SHIFT, 19 },
		{ 177, YYAT_SHIFT, 20 },
		{ 177, YYAT_SHIFT, 21 },
		{ 177, YYAT_SHIFT, 22 },
		{ 177, YYAT_SHIFT, 23 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 347, YYAT_SHIFT, 103 },
		{ 347, YYAT_SHIFT, 104 },
		{ 347, YYAT_SHIFT, 105 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 347, YYAT_SHIFT, 107 },
		{ 347, YYAT_SHIFT, 108 },
		{ 347, YYAT_SHIFT, 109 },
		{ 347, YYAT_SHIFT, 110 },
		{ 347, YYAT_SHIFT, 111 },
		{ 347, YYAT_SHIFT, 112 },
		{ 347, YYAT_SHIFT, 113 },
		{ -1, YYAT_ERROR, 0 },
		{ 328, YYAT_SHIFT, 88 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 328, YYAT_SHIFT, 89 },
		{ 268, YYAT_SHIFT, 157 },
		{ 328, YYAT_SHIFT, 90 },
		{ 182, YYAT_SHIFT, 4 },
		{ 328, YYAT_SHIFT, 91 },
		{ 328, YYAT_SHIFT, 92 },
		{ -1, YYAT_ERROR, 0 },
		{ 328, YYAT_SHIFT, 93 },
		{ -1, YYAT_ERROR, 0 },
		{ 182, YYAT_SHIFT, 10 },
		{ 182, YYAT_SHIFT, 11 },
		{ 182, YYAT_SHIFT, 12 },
		{ 182, YYAT_SHIFT, 13 },
		{ 182, YYAT_SHIFT, 14 },
		{ 182, YYAT_SHIFT, 15 },
		{ 182, YYAT_SHIFT, 16 },
		{ 182, YYAT_SHIFT, 17 },
		{ 182, YYAT_SHIFT, 18 },
		{ 182, YYAT_SHIFT, 19 },
		{ 182, YYAT_SHIFT, 20 },
		{ 182, YYAT_SHIFT, 21 },
		{ 182, YYAT_SHIFT, 22 },
		{ 182, YYAT_SHIFT, 23 },
		{ 322, YYAT_SHIFT, 97 },
		{ 322, YYAT_SHIFT, 98 },
		{ 322, YYAT_SHIFT, 99 },
		{ 322, YYAT_SHIFT, 100 },
		{ -1, YYAT_ERROR, 0 },
		{ 322, YYAT_SHIFT, 101 },
		{ 322, YYAT_SHIFT, 102 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 120, YYAT_SHIFT, 216 },
		{ 120, YYAT_SHIFT, 217 },
		{ 120, YYAT_SHIFT, 218 },
		{ 120, YYAT_SHIFT, 219 },
		{ 120, YYAT_SHIFT, 220 },
		{ 120, YYAT_SHIFT, 221 },
		{ 120, YYAT_SHIFT, 222 },
		{ 120, YYAT_SHIFT, 223 },
		{ 120, YYAT_SHIFT, 224 },
		{ 120, YYAT_SHIFT, 225 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 242, YYAT_SHIFT, 97 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 322, YYAT_SHIFT, 103 },
		{ 322, YYAT_SHIFT, 104 },
		{ 322, YYAT_SHIFT, 105 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 322, YYAT_SHIFT, 107 },
		{ 322, YYAT_SHIFT, 108 },
		{ 322, YYAT_SHIFT, 109 },
		{ 322, YYAT_SHIFT, 110 },
		{ 322, YYAT_SHIFT, 111 },
		{ 322, YYAT_SHIFT, 112 },
		{ 322, YYAT_SHIFT, 113 },
		{ 139, YYAT_SHIFT, 97 },
		{ -1, YYAT_ERROR, 0 },
		{ 176, YYAT_SHIFT, 4 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 328, YYAT_SHIFT, 96 },
		{ 176, YYAT_SHIFT, 10 },
		{ 176, YYAT_SHIFT, 11 },
		{ 176, YYAT_SHIFT, 12 },
		{ 176, YYAT_SHIFT, 13 },
		{ 176, YYAT_SHIFT, 14 },
		{ 176, YYAT_SHIFT, 15 },
		{ 176, YYAT_SHIFT, 16 },
		{ 176, YYAT_SHIFT, 17 },
		{ 176, YYAT_SHIFT, 18 },
		{ 176, YYAT_SHIFT, 19 },
		{ 176, YYAT_SHIFT, 20 },
		{ 176, YYAT_SHIFT, 21 },
		{ 176, YYAT_SHIFT, 22 },
		{ 176, YYAT_SHIFT, 23 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 139, YYAT_SHIFT, 5 },
		{ 139, YYAT_SHIFT, 6 },
		{ 139, YYAT_SHIFT, 7 },
		{ 139, YYAT_SHIFT, 8 },
		{ 139, YYAT_SHIFT, 9 },
		{ 242, YYAT_SHIFT, 103 },
		{ 242, YYAT_SHIFT, 104 },
		{ 242, YYAT_SHIFT, 105 },
		{ -1, YYAT_ERROR, 0 },
		{ 242, YYAT_SHIFT, 106 },
		{ 242, YYAT_SHIFT, 107 },
		{ 242, YYAT_SHIFT, 108 },
		{ 242, YYAT_SHIFT, 109 },
		{ 242, YYAT_SHIFT, 110 },
		{ 242, YYAT_SHIFT, 111 },
		{ 242, YYAT_SHIFT, 112 },
		{ 242, YYAT_SHIFT, 113 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 139, YYAT_SHIFT, 103 },
		{ 139, YYAT_SHIFT, 104 },
		{ 139, YYAT_SHIFT, 105 },
		{ -1, YYAT_ERROR, 0 },
		{ 139, YYAT_SHIFT, 106 },
		{ 139, YYAT_SHIFT, 107 },
		{ 139, YYAT_SHIFT, 108 },
		{ 139, YYAT_SHIFT, 109 },
		{ 139, YYAT_SHIFT, 110 },
		{ 139, YYAT_SHIFT, 111 },
		{ 139, YYAT_SHIFT, 112 },
		{ 139, YYAT_SHIFT, 113 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ 268, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 268, YYAT_SHIFT, 5 },
		{ 268, YYAT_SHIFT, 6 },
		{ 268, YYAT_SHIFT, 7 },
		{ 268, YYAT_SHIFT, 8 },
		{ 268, YYAT_SHIFT, 9 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 328, YYAT_SHIFT, 152 },
		{ 328, YYAT_SHIFT, 98 },
		{ 328, YYAT_SHIFT, 99 },
		{ 328, YYAT_SHIFT, 100 },
		{ -1, YYAT_ERROR, 0 },
		{ 328, YYAT_SHIFT, 101 },
		{ 328, YYAT_SHIFT, 102 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 439, 1, YYAT_DEFAULT, 37 },
		{ 0, 0, YYAT_DEFAULT, 86 },
		{ 22, 1, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ -93, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 225 },
		{ -94, 1, YYAT_ERROR, 0 },
		{ 379, 1, YYAT_DEFAULT, 86 },
		{ -140, 1, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_DEFAULT, 149 },
		{ 0, 0, YYAT_DEFAULT, 56 },
		{ 79, 1, YYAT_REDUCE, 137 },
		{ 174, 1, YYAT_REDUCE, 80 },
		{ 395, 1, YYAT_DEFAULT, 86 },
		{ -217, 1, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ -22, 1, YYAT_DEFAULT, 254 },
		{ 45, 1, YYAT_DEFAULT, 156 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 394, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ -1, 1, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_DEFAULT, 167 },
		{ 311, 1, YYAT_REDUCE, 129 },
		{ 0, 0, YYAT_DEFAULT, 84 },
		{ 309, 1, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 370, 1, YYAT_REDUCE, 86 },
		{ 371, 1, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 304, 1, YYAT_DEFAULT, 139 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 369, 1, YYAT_DEFAULT, 86 },
		{ 0, 0, YYAT_REDUCE, 229 },
		{ 0, 0, YYAT_DEFAULT, 149 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 124, 1, YYAT_REDUCE, 86 },
		{ -8, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 333, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ 77, 1, YYAT_REDUCE, 136 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ -39, 1, YYAT_REDUCE, 158 },
		{ 361, 1, YYAT_REDUCE, 152 },
		{ 361, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ 88, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 223 },
		{ 0, 0, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 151 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ 336, 1, YYAT_REDUCE, 132 },
		{ 0, 0, YYAT_REDUCE, 130 },
		{ 263, 1, YYAT_DEFAULT, 169 },
		{ 0, 0, YYAT_DEFAULT, 167 },
		{ 259, 1, YYAT_DEFAULT, 171 },
		{ 342, 1, YYAT_DEFAULT, 254 },
		{ 0, 0, YYAT_DEFAULT, 172 },
		{ -36, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 182 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 324, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 320, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 102 },
		{ 316, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 296, 1, YYAT_ERROR, 0 },
		{ 311, 1, YYAT_ERROR, 0 },
		{ 307, 1, YYAT_ERROR, 0 },
		{ 298, 1, YYAT_ERROR, 0 },
		{ 212, 1, YYAT_DEFAULT, 242 },
		{ 296, 1, YYAT_ERROR, 0 },
		{ 76, 1, YYAT_ERROR, 0 },
		{ 273, 1, YYAT_ERROR, 0 },
		{ 272, 1, YYAT_ERROR, 0 },
		{ 269, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 88, 1, YYAT_REDUCE, 37 },
		{ -61, 1, YYAT_REDUCE, 40 },
		{ 68, 1, YYAT_REDUCE, 45 },
		{ -67, 1, YYAT_REDUCE, 48 },
		{ -29, 1, YYAT_REDUCE, 16 },
		{ 312, 1, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 145, 1, YYAT_REDUCE, 34 },
		{ 53, 1, YYAT_REDUCE, 56 },
		{ 263, 1, YYAT_DEFAULT, 198 },
		{ -48, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 277, 1, YYAT_REDUCE, 50 },
		{ 216, 1, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 177, 1, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 172, 1, YYAT_DEFAULT, 242 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 368, 1, YYAT_DEFAULT, 182 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 245, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 0, 0, YYAT_REDUCE, 228 },
		{ 0, 0, YYAT_REDUCE, 227 },
		{ 150, 1, YYAT_DEFAULT, 84 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 176, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ -26, 1, YYAT_DEFAULT, 268 },
		{ 169, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 156 },
		{ -38, 1, YYAT_REDUCE, 163 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 48, 1, YYAT_REDUCE, 164 },
		{ -43, 1, YYAT_DEFAULT, 84 },
		{ 0, 0, YYAT_REDUCE, 143 },
		{ 0, 0, YYAT_REDUCE, 144 },
		{ -6, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ -7, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 127 },
		{ -23, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 121, 1, YYAT_DEFAULT, 84 },
		{ 122, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 345, 1, YYAT_REDUCE, 121 },
		{ 218, 1, YYAT_REDUCE, 119 },
		{ 203, 1, YYAT_DEFAULT, 345 },
		{ 17, 1, YYAT_REDUCE, 161 },
		{ 200, 1, YYAT_ERROR, 0 },
		{ 141, 1, YYAT_REDUCE, 185 },
		{ 265, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 178, 1, YYAT_ERROR, 0 },
		{ 82, 1, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ -80, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 280 },
		{ 163, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ 0, 0, YYAT_REDUCE, 219 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ -40, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 353, 1, YYAT_DEFAULT, 280 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 14, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 226 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 174, 1, YYAT_ERROR, 0 },
		{ 173, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 167 },
		{ 120, 1, YYAT_ERROR, 0 },
		{ 20, 1, YYAT_REDUCE, 165 },
		{ 7, 1, YYAT_DEFAULT, 268 },
		{ 119, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ 0, 0, YYAT_REDUCE, 128 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ -36, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 120 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 454, 1, YYAT_DEFAULT, 182 },
		{ 10, 1, YYAT_REDUCE, 163 },
		{ 0, 0, YYAT_REDUCE, 162 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 170, 1, YYAT_ERROR, 0 },
		{ 67, 1, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 169, 1, YYAT_DEFAULT, 345 },
		{ 168, 1, YYAT_DEFAULT, 345 },
		{ 166, 1, YYAT_DEFAULT, 345 },
		{ 166, 1, YYAT_ERROR, 0 },
		{ 132, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 217 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ 129, 1, YYAT_REDUCE, 35 },
		{ 125, 1, YYAT_REDUCE, 36 },
		{ 18, 1, YYAT_REDUCE, 38 },
		{ -11, 1, YYAT_REDUCE, 39 },
		{ -66, 1, YYAT_REDUCE, 41 },
		{ -68, 1, YYAT_REDUCE, 42 },
		{ -70, 1, YYAT_REDUCE, 43 },
		{ -76, 1, YYAT_REDUCE, 44 },
		{ 54, 1, YYAT_REDUCE, 46 },
		{ -18, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 2, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 54, 1, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 79, 1, YYAT_ERROR, 0 },
		{ -95, 1, YYAT_REDUCE, 57 },
		{ -134, 1, YYAT_REDUCE, 49 },
		{ 135, 1, YYAT_REDUCE, 51 },
		{ 75, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 124, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 169 },
		{ 47, 1, YYAT_ERROR, 0 },
		{ 13, 1, YYAT_DEFAULT, 172 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 310, 1, YYAT_REDUCE, 185 },
		{ 54, 1, YYAT_REDUCE, 185 },
		{ -5, 1, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_DEFAULT, 328 },
		{ 63, 1, YYAT_DEFAULT, 328 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 506, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ -215, 1, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 15, 1, YYAT_DEFAULT, 345 },
		{ -20, 1, YYAT_REDUCE, 185 },
		{ -17, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 223, 1, YYAT_REDUCE, 185 },
		{ -16, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ -33, 1, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 0, 0, YYAT_REDUCE, 216 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 248;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 350, 114 },
		{ 350, 145 },
		{ 350, 119 },
		{ 280, 125 },
		{ 350, 120 },
		{ 350, 121 },
		{ 350, 122 },
		{ 350, 123 },
		{ 350, 115 },
		{ 350, 116 },
		{ 350, 117 },
		{ 350, 118 },
		{ 350, 128 },
		{ 350, 129 },
		{ 350, 131 },
		{ 350, 124 },
		{ 350, 126 },
		{ 350, 127 },
		{ 350, 130 },
		{ 328, 153 },
		{ 350, 125 },
		{ 31, 64 },
		{ 268, 70 },
		{ 84, 55 },
		{ 317, 173 },
		{ 268, 33 },
		{ 268, 31 },
		{ 268, 26 },
		{ 162, 70 },
		{ 268, 34 },
		{ 268, 25 },
		{ 54, 55 },
		{ 328, 346 },
		{ 328, -1 },
		{ 145, 244 },
		{ 328, -1 },
		{ 268, 35 },
		{ 177, -1 },
		{ 26, 50 },
		{ 268, 27 },
		{ 177, -1 },
		{ 177, 177 },
		{ 31, 65 },
		{ 26, 51 },
		{ 280, 326 },
		{ 268, 249 },
		{ 268, 71 },
		{ 268, 73 },
		{ 177, 266 },
		{ 145, 245 },
		{ 268, 250 },
		{ 237, 305 },
		{ 237, -1 },
		{ 162, 257 },
		{ 177, 176 },
		{ 350, 143 },
		{ 350, 354 },
		{ 350, 132 },
		{ 350, 133 },
		{ 317, 333 },
		{ 84, 171 },
		{ 350, 135 },
		{ 350, 140 },
		{ 350, 144 },
		{ 350, 142 },
		{ 350, 141 },
		{ 350, 136 },
		{ 350, 137 },
		{ 54, 139 },
		{ 54, 134 },
		{ 328, -1 },
		{ 255, 155 },
		{ 328, -1 },
		{ 328, -1 },
		{ 1, -1 },
		{ 255, 316 },
		{ 328, -1 },
		{ 86, 175 },
		{ 328, -1 },
		{ 328, -1 },
		{ 344, 349 },
		{ 328, -1 },
		{ 328, -1 },
		{ 139, 146 },
		{ 139, 56 },
		{ 37, 24 },
		{ 37, 29 },
		{ 139, 33 },
		{ 139, 31 },
		{ 139, 26 },
		{ 1, 40 },
		{ 139, 34 },
		{ 139, 25 },
		{ 86, 49 },
		{ 325, 343 },
		{ 86, 30 },
		{ 86, 32 },
		{ 326, 120 },
		{ 139, 35 },
		{ 176, 265 },
		{ 36, 72 },
		{ 139, 27 },
		{ 324, 342 },
		{ 36, 74 },
		{ 37, 28 },
		{ 37, 36 },
		{ 37, 30 },
		{ 37, 32 },
		{ 179, 269 },
		{ 176, -1 },
		{ 326, 127 },
		{ 326, 130 },
		{ 309, 329 },
		{ 326, 345 },
		{ 309, -1 },
		{ 179, 270 },
		{ 179, 161 },
		{ 139, 138 },
		{ 347, -1 },
		{ 347, 334 },
		{ 347, 335 },
		{ 139, 242 },
		{ 323, 341 },
		{ 347, 336 },
		{ 347, -1 },
		{ 347, 352 },
		{ 347, 351 },
		{ 347, -1 },
		{ 347, 337 },
		{ 347, 338 },
		{ 171, 146 },
		{ 171, 56 },
		{ 37, 75 },
		{ 37, 39 },
		{ 182, 177 },
		{ 182, 26 },
		{ 43, 77 },
		{ 182, 34 },
		{ 182, 25 },
		{ 70, 158 },
		{ 43, 78 },
		{ 182, 179 },
		{ 70, 159 },
		{ 102, 186 },
		{ 182, 35 },
		{ 102, -1 },
		{ 274, 321 },
		{ 182, 176 },
		{ 2, 41 },
		{ 70, 160 },
		{ 70, 161 },
		{ 269, 253 },
		{ 2, 42 },
		{ 2, 43 },
		{ 171, -1 },
		{ 171, -1 },
		{ 171, -1 },
		{ 182, 273 },
		{ 238, 306 },
		{ 238, -1 },
		{ 238, -1 },
		{ 238, -1 },
		{ 238, -1 },
		{ 254, -1 },
		{ 242, 240 },
		{ 254, 314 },
		{ 156, 40 },
		{ 156, 36 },
		{ 156, 30 },
		{ 156, 159 },
		{ 254, -1 },
		{ 254, -1 },
		{ 322, 339 },
		{ 322, 340 },
		{ 322, 142 },
		{ 271, 319 },
		{ 271, -1 },
		{ 271, -1 },
		{ 236, 304 },
		{ 236, -1 },
		{ 235, 131 },
		{ 235, 303 },
		{ 231, 129 },
		{ 231, 300 },
		{ 208, 292 },
		{ 208, -1 },
		{ 206, 290 },
		{ 206, -1 },
		{ 202, 286 },
		{ 202, -1 },
		{ 200, 122 },
		{ 200, 284 },
		{ 172, 263 },
		{ 172, 264 },
		{ 159, 36 },
		{ 159, 66 },
		{ 82, 169 },
		{ 82, 80 },
		{ 60, 148 },
		{ 60, 149 },
		{ 56, 61 },
		{ 56, 52 },
		{ 33, -1 },
		{ 33, 67 },
		{ 28, 57 },
		{ 28, 58 },
		{ 0, 37 },
		{ 0, 38 },
		{ 234, 302 },
		{ 232, 301 },
		{ 230, 299 },
		{ 229, 298 },
		{ 228, 297 },
		{ 226, 296 },
		{ 211, 294 },
		{ 207, 291 },
		{ 205, 289 },
		{ 204, 288 },
		{ 203, 287 },
		{ 201, 285 },
		{ 199, 283 },
		{ 193, 280 },
		{ 191, 278 },
		{ 190, 277 },
		{ 189, 276 },
		{ 188, 275 },
		{ 184, 178 },
		{ 181, 272 },
		{ 167, 260 },
		{ 166, 259 },
		{ 157, 252 },
		{ 149, 246 },
		{ 121, 227 },
		{ 120, 226 },
		{ 113, 198 },
		{ 108, 192 },
		{ 103, 187 },
		{ 101, 185 },
		{ 100, 183 },
		{ 90, 180 },
		{ 85, 174 },
		{ 63, 154 },
		{ 58, 147 },
		{ 46, 83 },
		{ 44, 81 },
		{ 32, -1 },
		{ 29, 60 },
		{ 27, 53 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 137, 37 },
		{ 48, 86 },
		{ 107, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 13, 56 },
		{ 223, 33 },
		{ 145, 84 },
		{ 204, 56 },
		{ 0, -1 },
		{ -3, 33 },
		{ 192, 159 },
		{ 179, 171 },
		{ 0, -1 },
		{ 0, -1 },
		{ 53, 254 },
		{ 62, 171 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 95, -1 },
		{ 205, 82 },
		{ 0, -1 },
		{ 183, 84 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 8, 139 },
		{ 0, -1 },
		{ 175, 86 },
		{ 0, -1 },
		{ 183, 171 },
		{ 0, -1 },
		{ 139, 84 },
		{ 0, -1 },
		{ 0, -1 },
		{ 219, 255 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 97, 1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 157, -1 },
		{ 0, 171 },
		{ 0, 171 },
		{ 186, 317 },
		{ 51, 32 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 188, 182 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 233, 102 },
		{ 232, 102 },
		{ 138, 271 },
		{ 214, 255 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 178, 350 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 213, 326 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 213, -1 },
		{ 225, 271 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 242 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 60, 350 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 30, 309 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 172, 171 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 124, 268 },
		{ 208, 255 },
		{ 0, -1 },
		{ 151, 269 },
		{ 0, -1 },
		{ 0, -1 },
		{ 4, 33 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 207, 255 },
		{ 188, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 107, 254 },
		{ 138, 317 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 64, 177 },
		{ 13, 31 },
		{ 0, -1 },
		{ 63, -1 },
		{ 0, -1 },
		{ 170, 350 },
		{ 106, 184 },
		{ 0, -1 },
		{ 205, 326 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 168, 350 },
		{ 203, 326 },
		{ 202, 326 },
		{ 201, 326 },
		{ 0, -1 },
		{ 159, 280 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 212, 200 },
		{ 183, 271 },
		{ 210, 202 },
		{ 179, 206 },
		{ 208, 206 },
		{ 207, 206 },
		{ 206, 206 },
		{ 176, 208 },
		{ 204, 208 },
		{ 173, 236 },
		{ 0, -1 },
		{ 0, -1 },
		{ 193, 326 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 194, 309 },
		{ 0, -1 },
		{ 205, 271 },
		{ 204, 271 },
		{ 203, 271 },
		{ 168, 238 },
		{ 190, 309 },
		{ 0, -1 },
		{ 187, 326 },
		{ 165, 231 },
		{ 166, 237 },
		{ 38, 238 },
		{ 144, 328 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 107, 350 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 118, 268 },
		{ 53, 328 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 179 },
		{ 98, -1 },
		{ 0, -1 },
		{ 168, 202 },
		{ 0, -1 },
		{ 0, -1 },
		{ 89, 350 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -18, 326 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 93, 326 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 5, 309 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 109, 347 },
		{ 65, 350 },
		{ 45, 350 },
		{ 73, 326 },
		{ 92, 328 },
		{ 0, -1 },
		{ 14, 347 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, 350 },
		{ 0, -1 },
		{ 0, -1 },
		{ 61, 350 },
		{ 0, -1 },
		{ 0, -1 },
		{ -1, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 2952 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	s.push_back(new varmap());
//  FILE *stream;
//	freopen_s(&stream, "in.txt", "r", stdin);
//	freopen_s(&stream, "out.txt", "w", stdout);
	cout << "Name\t\tElement\t\tValue\t\tLine" << endl;
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	getchar();
	return 0;
}
