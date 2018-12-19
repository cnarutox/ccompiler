/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 71 of your 30 day trial period.
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
* Date: 12/19/18
* Time: 17:09:40
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

void traverse(typenode *root) {
	if(root!=NULL)
		cout << root->name << endl;
	if(root->left!=NULL)
	{
		cout << "left ";
		traverse(root->left);
	}
	if(root->right!=NULL)
	{
		cout << "right ";
		traverse(root->right);	
	}	
}
void compare_traverse(typenode *root, vector<string> &v) {
	if(root!=NULL)
		//cout << root->name << endl;
		v.push_back(root->name);
	if(root->left!=NULL)
	{
		//cout << "left ";
		traverse(root->left);
	}
	if(root->right!=NULL)
	{
		//cout << "right ";
		traverse(root->right);	
	}
}
typenode* search_struct(typenode *root, string name) {
	if(root == NULL)
		return false;
	if(root->left != NULL)
	{
		cout << "left " << root->left->name;
		if (root->left->name == name)
			return root->right;
		else return search_struct(root->left, name);
	}
	if(root->right != NULL)
	{
		cout << "right " << root->right->name;
		return search_struct(root->right, name);
	}
	return false;
}


#line 97 "myparser.cpp"
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
#line 114 ".\\myparser.y"

	// place any extra initialisation code here

#line 121 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 119 ".\\myparser.y"

	// place any extra cleanup code here

#line 135 "myparser.cpp"
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
#line 142 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("108 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		if(search(yyattribute(1 - 1).ntnode->name,s.size()-1)!=NULL)
		{
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *search(yyattribute(1 - 1).ntnode->name,s.size()-1);
		}
	
#line 257 "myparser.cpp"
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
#line 155 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("116 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = doublenode;
	
#line 280 "myparser.cpp"
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
#line 166 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("123 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 300 "myparser.cpp"
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
#line 174 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("130 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	
	
#line 322 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 188 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("142 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;			
	
#line 345 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 199 ".\\myparser.y"
	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("149 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 368 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 210 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("159 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 390 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 220 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("168 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 413 "myparser.cpp"
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
#line 231 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("178 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		map<string, typenode*>::iterator i;
		if ((i = auto_define_type.find(yyattribute(1 - 3).ntnode->type.name)) != auto_define_type.end())
		{
			cout << search_struct(i->second, yyattribute(3 - 3).ntnode->name);
		}
		else cout << "struct doesn't exist!\n";
	
#line 442 "myparser.cpp"
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
#line 248 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("187 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 464 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 258 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("196 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
			cout<<"No additive calculation can be made for uncalculable types."<<endl;
	
#line 488 "myparser.cpp"
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
#line 270 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
			cout<<"Can't subtract from uncalculable types."<<endl;
	
#line 512 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 285 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("215 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 532 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 293 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("222 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 554 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 306 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("234 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 577 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 317 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("241 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
			cout<<"No additive calculation can be made for uncalculable types."<<endl;
	
#line 601 "myparser.cpp"
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
#line 329 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("249 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

		if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
			cout<<"Can't subtract from uncalculable types ."<<endl;
	
#line 625 "myparser.cpp"
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
#line 341 ".\\myparser.y"

		//cast_exp:单目表达式/强制类型转换
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("257 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 647 "myparser.cpp"
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
#line 351 ".\\myparser.y"

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
	
#line 674 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 366 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("273 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;

		if(yyattribute(3 - 4).ntnode->type.width!=0)(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(3 - 4).ntnode->type.width;
		else cout<<"Unknown type, unable to perform sizeof operation."<<endl;
	
#line 700 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 383 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("286 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 720 "myparser.cpp"
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
#line 391 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 740 "myparser.cpp"
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
#line 399 ".\\myparser.y"

		printf("777");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("301 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 761 "myparser.cpp"
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
#line 408 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("308 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 781 "myparser.cpp"
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
#line 416 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("315 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 801 "myparser.cpp"
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
#line 424 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("322 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 821 "myparser.cpp"
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
#line 435 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("332 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 844 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 446 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("339 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 867 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 460 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("352 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;			
	
#line 890 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 471 ".\\myparser.y"

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
	
#line 915 "myparser.cpp"
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
#line 484 ".\\myparser.y"

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
	
#line 940 "myparser.cpp"
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
#line 497 ".\\myparser.y"

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
	
#line 965 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 513 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("389 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 988 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 524 ".\\myparser.y"

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
	
#line 1013 "myparser.cpp"
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
#line 537 ".\\myparser.y"

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
	
#line 1038 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 553 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("417 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1061 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 564 ".\\myparser.y"

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
	
#line 1086 "myparser.cpp"
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
#line 577 ".\\myparser.y"

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
	
#line 1111 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 593 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("445 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;		
	
#line 1134 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 604 ".\\myparser.y"

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
	
#line 1159 "myparser.cpp"
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
#line 617 ".\\myparser.y"

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
	
#line 1184 "myparser.cpp"
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
#line 630 ".\\myparser.y"

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
	
#line 1209 "myparser.cpp"
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
#line 643 ".\\myparser.y"

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
	
#line 1234 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 659 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("491 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1257 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 670 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("498 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1282 "myparser.cpp"
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
#line 683 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("507 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
	
#line 1307 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 699 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("519 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1330 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 710 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("526 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Intersection Operator Type Mismatch ."<<endl;
	
#line 1355 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 726 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1378 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 737 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("545 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Intersection Operator Type Mismatch ."<<endl;
	
#line 1403 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 753 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("557 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1426 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 764 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("564 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Or operation left-right operand type mismatch "<<endl;
	
#line 1451 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 780 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("576 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1474 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 791 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("583 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1496 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 804 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("595 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1519 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 815 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("602 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1541 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 828 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("614 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1564 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 839 ".\\myparser.y"

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

		vector<string> v1;
		vector<string> v2;
		compare_traverse(&yyattribute(3 - 5).ntnode->type, v1);
		compare_traverse(&yyattribute(5 - 5).ntnode->type, v2);
		if (v1==v2){
			cout<<"Two sides equal"<<endl;
		}	
		else{
			cout<<"Two sides don't equal"<<endl;
		}			
	
#line 1599 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 865 ".\\myparser.y"

		//(1)谓词表达式

		//(2)条件表达式 a<b?a:b
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
	
#line 1623 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 877 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		vector<string> v1;
		vector<string> v2;
		compare_traverse(&yyattribute(1 - 3).ntnode->type, v1);
		compare_traverse(&yyattribute(2 - 3).ntnode->type, v2);
		if (v1==v2){
			cout<<"Two sides equal"<<endl;
		}	
		else{
			cout<<"Two sides don't equal"<<endl;
		}
	
#line 1656 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 901 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("654 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1676 "myparser.cpp"
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
#line 909 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("661 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1696 "myparser.cpp"
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
#line 917 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("668 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1716 "myparser.cpp"
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
#line 925 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("675 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1736 "myparser.cpp"
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
#line 933 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("682 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1756 "myparser.cpp"
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
#line 941 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1776 "myparser.cpp"
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
#line 949 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("696 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1796 "myparser.cpp"
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
#line 957 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("703 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1816 "myparser.cpp"
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
#line 965 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("710 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1836 "myparser.cpp"
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
#line 973 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("717 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1856 "myparser.cpp"
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
#line 981 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("724 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1876 "myparser.cpp"
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
#line 992 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf(" ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1896 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1000 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("741 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1918 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1013 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("753 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1940 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1026 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("763 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1961 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1035 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("771 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		//$$->type = $1->type;		
	
#line 1985 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1053 ".\\myparser.y"
 //static
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("783 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2005 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1062 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("791 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2026 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1071 ".\\myparser.y"
 // int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("799 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		type3->right = rFlag();	
	
#line 2047 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1080 ".\\myparser.y"
 // lont int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("806 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2068 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1089 ".\\myparser.y"
 //const
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("814 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2088 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1097 ".\\myparser.y"
 //const int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("821 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2109 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1109 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("832 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

		//$$->type = $1->type;	
	
#line 2131 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1119 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("839 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 2153 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1132 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("851 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2173 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1140 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("858 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	

		
		//s.back()
		/* $$->type = $1->type;
		vector<string> v1;
		vector<string> v2;
		compare_traverse($$->type, v1);
		compare_traverse(type, v2);
		if (v1==v2){
			cout<<"Assignment matching of left and right values."<<endl;			
		}
		else{
			cout<<"Assignment left-right mismatch "<<endl;
		} */				
	
#line 2209 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1167 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("870 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2229 "myparser.cpp"
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
#line 1175 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("877 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2249 "myparser.cpp"
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
#line 1183 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("884 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2269 "myparser.cpp"
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
#line 1191 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2289 "myparser.cpp"
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
#line 1199 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("898 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2309 "myparser.cpp"
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
#line 1210 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		wFlag(voidnode);
	
#line 2330 "myparser.cpp"
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
#line 1219 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("915 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(charnode);
	
#line 2351 "myparser.cpp"
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
#line 1228 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("922 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(shortnode);
	
#line 2372 "myparser.cpp"
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
#line 1237 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("929 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(intnode);
	
#line 2393 "myparser.cpp"
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
#line 1246 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("936 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(longnode);
	
#line 2414 "myparser.cpp"
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
#line 1255 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("943 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(floatnode);
	
#line 2435 "myparser.cpp"
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
#line 1264 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("950 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(doublenode);
	
#line 2456 "myparser.cpp"
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
#line 1273 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("957 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(signednode);
	
#line 2477 "myparser.cpp"
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
#line 1282 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(unsignednode);
	
#line 2498 "myparser.cpp"
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
#line 1291 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2518 "myparser.cpp"
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
#line 1299 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("978 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2538 "myparser.cpp"
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
#line 1307 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("985 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2558 "myparser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1315 ".\\myparser.y"

	
#line 2572 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 1320 ".\\myparser.y"
  //struct a { int a = 0;};
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("995 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 6;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [6];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 6).ntnode;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[5] = yyattribute(6 - 6).ntnode;
		int width_sum = 0;

		map<string, typenode*>::iterator iter;
		typenode* temp_ptr;
		typenode* temp1;
		typenode* temp2;
		typenode* temp3=new typenode("?");
		for(iter = varmap_temp->vartable.begin(); iter!=varmap_temp->vartable.end(); ++iter){
				cout<<iter->first<<' '<<iter->second->name<<' ';
				temp_ptr = new typenode(string(iter->first));
				typenode* root = new typenode("X");
				root->left = temp_ptr;
				root->right = iter->second;
				width_sum += iter->second->width;
				struct_stack.push(root);
		}
		cout<<endl;
		while(struct_stack.size()>=1){
			cout<<struct_stack.size()<<endl;
			if(struct_stack.size() !=1){
				temp1 = struct_stack.top();struct_stack.pop();
				temp2 = struct_stack.top();struct_stack.pop();
				typenode* temp_ptr2 = new typenode("X");
				temp_ptr2->left = temp1;
				temp_ptr2->right = temp2;											
				struct_stack.push(temp_ptr2);				
			}
			else{
				temp3 = struct_stack.top();struct_stack.pop();
				break;
			}
		}
		typenode* temp = new typenode("record");
		temp->left = temp3;
		temp->width = width_sum;
		auto_define_type[yyattribute(2 - 6).ntnode->name] = temp;	
		traverse(temp);
		s.pop_back();
	
#line 2635 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1371 ".\\myparser.y"
 // struct a {int a = 0;} b[2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1006 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 7).ntnode;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[5] = yyattribute(6 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[6] = yyattribute(7 - 7).ntnode;
	
#line 2661 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1385 ".\\myparser.y"
 // struct a {int a = 0;};
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1007 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 5).ntnode;
	
#line 2685 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 1397 ".\\myparser.y"
 //struct {int a = 0;}a[2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1008 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 6;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [6];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[5] = yyattribute(6 - 6).ntnode;
	
#line 2710 "myparser.cpp"
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
#line 1410 ".\\myparser.y"
 // struct a
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1016 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	

		map<string, typenode*>::iterator i;
		cout << yyattribute(2 - 2).ntnode->type.name;
		if ((i = auto_define_type.find(yyattribute(2 - 2).ntnode->type.name)) != auto_define_type.end())
		{
			cout << search_struct(i->second, yyattribute(3 - 2).ntnode->name)->name;
		}
		else cout << "struct doesn't exist!\n";
	
#line 2739 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1430 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1027 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2759 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1438 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1034 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2779 "myparser.cpp"
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
#line 1449 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1044 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2799 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1457 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1051 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2820 "myparser.cpp"
			}
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1469 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1062 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2842 "myparser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1479 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1062 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2864 "myparser.cpp"
			}
		}
		break;
	case 115:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1492 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1074 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2885 "myparser.cpp"
			}
		}
		break;
	case 116:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1501 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1082 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2905 "myparser.cpp"
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
#line 1509 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1089 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2926 "myparser.cpp"
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
#line 1518 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1097 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2946 "myparser.cpp"
			}
		}
		break;
	case 119:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1529 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1107 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2966 "myparser.cpp"
			}
		}
		break;
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1537 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1114 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2988 "myparser.cpp"
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
#line 1550 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1126 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3008 "myparser.cpp"
			}
		}
		break;
	case 122:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1558 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1133 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3029 "myparser.cpp"
			}
		}
		break;
	case 123:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1567 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1141 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3051 "myparser.cpp"
			}
		}
		break;
	case 124:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1580 ".\\myparser.y"
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
	
#line 3074 "myparser.cpp"
			}
		}
		break;
	case 125:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1591 ".\\myparser.y"
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
	
#line 3098 "myparser.cpp"
			}
		}
		break;
	case 126:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1603 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1174 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3119 "myparser.cpp"
			}
		}
		break;
	case 127:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1615 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1185 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3139 "myparser.cpp"
			}
		}
		break;
	case 128:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1623 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1192 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3161 "myparser.cpp"
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
#line 1636 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3181 "myparser.cpp"
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
#line 1644 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1211 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3203 "myparser.cpp"
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
#line 1657 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1223 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3223 "myparser.cpp"
			}
		}
		break;
	case 132:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1665 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1230 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3243 "myparser.cpp"
			}
		}
		break;
	case 133:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1676 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1240 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3264 "myparser.cpp"
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
#line 1685 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1248 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3284 "myparser.cpp"
			}
		}
		break;
	case 135:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1697 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1258 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		var_name = yyattribute(1 - 1).ntnode->name;
		s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
	
#line 3307 "myparser.cpp"
			}
		}
		break;
	case 136:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1708 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1265 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3329 "myparser.cpp"
			}
		}
		break;
	case 137:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1718 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1274 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;

		typenode temp("array");
		char num[25];
		_itoa_s(int(yyattribute(3 - 4).ntnode->dvalue), num, 10);
		temp.left = new typenode(string(num));
		temp.right = rFlag();
		temp.width = rFlag()->width * yyattribute(3 - 4).ntnode->dvalue;
		type = &temp;
		traverse(type);
	
#line 3361 "myparser.cpp"
			}
		}
		break;
	case 138:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1738 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1284 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3383 "myparser.cpp"
			}
		}
		break;
	case 139:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1748 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 3406 "myparser.cpp"
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
#line 1759 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1303 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
		map<string, typenode*>::iterator iter;
		for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
			s[s.size()-2]->vartable[iter->first] = iter->second;
		}	
	
#line 3433 "myparser.cpp"
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
#line 1774 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1313 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode; 
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

		typenode* temp = new typenode("fun");
		temp->right = rFlag();	
		s.back()->vartable[var_name] = temp;			
	
#line 3459 "myparser.cpp"
			}
		}
		break;
	case 142:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1791 ".\\myparser.y"

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
	
#line 3486 "myparser.cpp"
			}
		}
		break;
	case 143:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1806 ".\\myparser.y"
 // *const
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3506 "myparser.cpp"
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
#line 1814 ".\\myparser.y"
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
	
#line 3532 "myparser.cpp"
			}
		}
		break;
	case 145:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1828 ".\\myparser.y"
 //*const*
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
	
#line 3552 "myparser.cpp"
			}
		}
		break;
	case 146:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1839 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1359 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3572 "myparser.cpp"
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
#line 1847 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1366 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3593 "myparser.cpp"
			}
		}
		break;
	case 148:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1860 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1378 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		type3->left = rFlag();
		s.back()->vartable[var_name] = type3;
		traverse(type3);
	
#line 3617 "myparser.cpp"
			}
		}
		break;
	case 149:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1872 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1385 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3639 "myparser.cpp"
			}
		}
		break;
	case 150:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1885 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1397 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3659 "myparser.cpp"
			}
		}
		break;
	case 151:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1893 ".\\myparser.y"

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
		cout<<"left"<<endl;
		traverse(rFlag());
		flag = !flag;
		temp->right = rFlag();
		cout<<"right"<<endl;
		traverse(rFlag());	
		wFlag(*temp);
	
#line 3691 "myparser.cpp"
			}
		}
		break;
	case 152:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1916 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1416 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3712 "myparser.cpp"
			}
		}
		break;
	case 153:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1925 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1424 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3732 "myparser.cpp"
			}
		}
		break;
	case 154:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1933 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1431 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3752 "myparser.cpp"
			}
		}
		break;
	case 155:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1944 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1441 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
	
#line 3773 "myparser.cpp"
			}
		}
		break;
	case 156:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1953 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1448 ");   
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		s.back()->vartable[yyattribute(3 - 3).ntnode->name] = rFlag();	
	
#line 3796 "myparser.cpp"
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
#line 1967 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1460 ");
	  	(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3816 "myparser.cpp"
			}
		}
		break;
	case 158:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1975 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1467 ");  
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3837 "myparser.cpp"
			}
		}
		break;
	case 159:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1987 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1478 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3857 "myparser.cpp"
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
#line 1995 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1485 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3877 "myparser.cpp"
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
#line 2003 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1492 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3898 "myparser.cpp"
			}
		}
		break;
	case 162:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2015 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1503 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3920 "myparser.cpp"
			}
		}
		break;
	case 163:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2025 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1512 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3941 "myparser.cpp"
			}
		}
		break;
	case 164:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2034 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1520 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3963 "myparser.cpp"
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
#line 2044 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1529 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3985 "myparser.cpp"
			}
		}
		break;
	case 166:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2054 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4008 "myparser.cpp"
			}
		}
		break;
	case 167:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2065 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1548 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4029 "myparser.cpp"
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
#line 2074 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1556 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4051 "myparser.cpp"
			}
		}
		break;
	case 169:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2084 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1565 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4073 "myparser.cpp"
			}
		}
		break;
	case 170:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2094 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1574 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4096 "myparser.cpp"
			}
		}
		break;
	case 171:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2108 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1587 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		//$$->type = $1->type;
	
#line 4118 "myparser.cpp"
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
#line 2118 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1594 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4140 "myparser.cpp"
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
#line 2128 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1603 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4163 "myparser.cpp"
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
#line 2142 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1616 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4183 "myparser.cpp"
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
#line 2150 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1623 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4205 "myparser.cpp"
			}
		}
		break;
	case 176:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2162 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4225 "myparser.cpp"
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
#line 2170 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4245 "myparser.cpp"
			}
		}
		break;
	case 178:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2178 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4265 "myparser.cpp"
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
#line 2186 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4285 "myparser.cpp"
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
#line 2194 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4305 "myparser.cpp"
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
#line 2204 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4325 "myparser.cpp"
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
#line 2212 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4345 "myparser.cpp"
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
#line 2220 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4365 "myparser.cpp"
			}
		}
		break;
	case 184:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2228 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1656 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4385 "myparser.cpp"
			}
		}
		break;
	case 185:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2236 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4405 "myparser.cpp"
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
#line 2244 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4425 "myparser.cpp"
			}
		}
		break;
	case 187:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2255 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1680 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4447 "myparser.cpp"
			}
		}
		break;
	case 188:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2265 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4470 "myparser.cpp"
			}
		}
		break;
	case 189:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2276 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1699 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4492 "myparser.cpp"
			}
		}
		break;
	case 190:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2289 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1711 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4513 "myparser.cpp"
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
#line 2298 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1719 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4535 "myparser.cpp"
			}
		}
		break;
	case 192:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2308 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1728 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4557 "myparser.cpp"
			}
		}
		break;
	case 193:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2318 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1737 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4580 "myparser.cpp"
			}
		}
		break;
	case 194:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2332 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1750 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4600 "myparser.cpp"
			}
		}
		break;
	case 195:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2340 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1757 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4621 "myparser.cpp"
			}
		}
		break;
	case 196:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2352 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1768 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4641 "myparser.cpp"
			}
		}
		break;
	case 197:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2360 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1775 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4662 "myparser.cpp"
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
#line 2372 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1786 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4682 "myparser.cpp"
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
#line 2380 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1793 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4703 "myparser.cpp"
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
#line 2391 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1794 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4723 "myparser.cpp"
			}
		}
		break;
	case 201:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2399 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(); 
		printf("1795 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4743 "myparser.cpp"
			}
		}
		break;
	case 202:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2409 ".\\myparser.y"

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
	
#line 4769 "myparser.cpp"
			}
		}
		break;
	case 203:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2423 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1815 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4789 "myparser.cpp"
			}
		}
		break;
	case 204:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2433 ".\\myparser.y"

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
	
#line 4813 "myparser.cpp"
			}
		}
		break;
	case 205:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2445 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1817@ ");
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
	
#line 4839 "myparser.cpp"
			}
		}
		break;
	case 206:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2461 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1816 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4859 "myparser.cpp"
			}
		}
		break;
	case 207:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2469 ".\\myparser.y"

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
	
#line 4883 "myparser.cpp"
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
#line 2484 ".\\myparser.y"

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
	
#line 4907 "myparser.cpp"
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
#line 2496 ".\\myparser.y"

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
	
#line 4933 "myparser.cpp"
			}
		}
		break;
	case 210:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 2510 ".\\myparser.y"

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
	
#line 4963 "myparser.cpp"
			}
		}
		break;
	case 211:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2528 ".\\myparser.y"

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
	
#line 4995 "myparser.cpp"
			}
		}
		break;
	case 212:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2551 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 5017 "myparser.cpp"
			}
		}
		break;
	case 213:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2561 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1900 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 5038 "myparser.cpp"
			}
		}
		break;
	case 214:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2570 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 5059 "myparser.cpp"
			}
		}
		break;
	case 215:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2579 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1916 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 5080 "myparser.cpp"
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
#line 2588 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1924 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 5102 "myparser.cpp"
			}
		}
		break;
	case 217:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2601 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1946 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		cout<<endl;
		// traverse($$);
	
#line 5124 "myparser.cpp"
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
#line 2611 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1953 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		cout<<endl;
		// traverse($$);
	
#line 5147 "myparser.cpp"
			}
		}
		break;
	case 219:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2625 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 5167 "myparser.cpp"
			}
		}
		break;
	case 220:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2633 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 5187 "myparser.cpp"
			}
		}
		break;
	case 221:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2644 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1981 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 5210 "myparser.cpp"
			}
		}
		break;
	case 222:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2655 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1991 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 5232 "myparser.cpp"
			}
		}
		break;
	case 223:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2665 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2000 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 5254 "myparser.cpp"
			}
		}
		break;
	case 224:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2675 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2009 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 5275 "myparser.cpp"
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
		"postfix_exp: primary_exp",
		"postfix_exp: postfix_exp \'[\' exp \']\'",
		"postfix_exp: postfix_exp \'(\' \')\'",
		"postfix_exp: postfix_exp \'(\' argument_exp_list \')\'",
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
		"struct_or_union_specifier: struct_or_union ID \'{\' declaration_list \'}\' \';\'",
		"struct_or_union_specifier: struct_or_union ID \'{\' declaration_list \'}\' init_declarator_list \';\'",
		"struct_or_union_specifier: struct_or_union \'{\' declaration_list \'}\' \';\'",
		"struct_or_union_specifier: struct_or_union \'{\' declaration_list \'}\' init_declarator_list \';\'",
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
		"direct_declarator: ID",
		"direct_declarator: \'(\' declarator \')\'",
		"direct_declarator: direct_declarator \'[\' constant_exp \']\'",
		"direct_declarator: direct_declarator \'[\' \']\'",
		"direct_declarator: direct_declarator \'(\' parameter_type_list \')\'",
		"direct_declarator: direct_declarator \'(\' identifier_list \')\'",
		"direct_declarator: direct_declarator \'(\' \')\'",
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
		{ 2, 1, 4 },
		{ 2, 4, 5 },
		{ 2, 3, 6 },
		{ 2, 4, 7 },
		{ 2, 3, 8 },
		{ 2, 3, 9 },
		{ 2, 2, 10 },
		{ 2, 2, 11 },
		{ 3, 1, 12 },
		{ 3, 3, 13 },
		{ 4, 1, 14 },
		{ 4, 2, 15 },
		{ 4, 2, 16 },
		{ 4, 2, 17 },
		{ 4, 2, 18 },
		{ 4, 4, 19 },
		{ 5, 1, 20 },
		{ 5, 1, 21 },
		{ 5, 1, 22 },
		{ 5, 1, 23 },
		{ 5, 1, 24 },
		{ 5, 1, 25 },
		{ 6, 1, 26 },
		{ 6, 4, 27 },
		{ 7, 1, 28 },
		{ 7, 3, 29 },
		{ 7, 3, 30 },
		{ 7, 3, 31 },
		{ 8, 1, 32 },
		{ 8, 3, 33 },
		{ 8, 3, 34 },
		{ 9, 1, 35 },
		{ 9, 3, 36 },
		{ 9, 3, 37 },
		{ 10, 1, 38 },
		{ 10, 3, 39 },
		{ 10, 3, 40 },
		{ 10, 3, 41 },
		{ 10, 3, 42 },
		{ 11, 1, 43 },
		{ 11, 3, 44 },
		{ 11, 3, 45 },
		{ 12, 1, 46 },
		{ 12, 3, 47 },
		{ 13, 1, 48 },
		{ 13, 3, 49 },
		{ 14, 1, 50 },
		{ 14, 3, 51 },
		{ 15, 1, 52 },
		{ 15, 3, 53 },
		{ 16, 1, 54 },
		{ 16, 3, 55 },
		{ 17, 1, 56 },
		{ 17, 5, 57 },
		{ 18, 1, 58 },
		{ 18, 3, 59 },
		{ 19, 1, 60 },
		{ 19, 1, 61 },
		{ 19, 1, 62 },
		{ 19, 1, 63 },
		{ 19, 1, 64 },
		{ 19, 1, 65 },
		{ 19, 1, 66 },
		{ 19, 1, 67 },
		{ 19, 1, 68 },
		{ 19, 1, 69 },
		{ 19, 1, 70 },
		{ 20, 1, 71 },
		{ 20, 3, 72 },
		{ 21, 1, 73 },
		{ 22, 2, 74 },
		{ 22, 3, 75 },
		{ 23, 1, 76 },
		{ 23, 2, 77 },
		{ 23, 1, 78 },
		{ 23, 2, 79 },
		{ 23, 1, 80 },
		{ 23, 2, 81 },
		{ 24, 1, 82 },
		{ 24, 3, 83 },
		{ 25, 1, 84 },
		{ 25, 3, 85 },
		{ 26, 1, 86 },
		{ 26, 1, 87 },
		{ 26, 1, 88 },
		{ 26, 1, 89 },
		{ 26, 1, 90 },
		{ 27, 1, 91 },
		{ 27, 1, 92 },
		{ 27, 1, 93 },
		{ 27, 1, 94 },
		{ 27, 1, 95 },
		{ 27, 1, 96 },
		{ 27, 1, 97 },
		{ 27, 1, 98 },
		{ 27, 1, 99 },
		{ 27, 1, 100 },
		{ 27, 1, 101 },
		{ 27, 1, 102 },
		{ 27, 2, 103 },
		{ 28, 6, 104 },
		{ 28, 7, 105 },
		{ 28, 5, 106 },
		{ 28, 6, 107 },
		{ 28, 2, 108 },
		{ 29, 1, 109 },
		{ 29, 1, 110 },
		{ 30, 1, 111 },
		{ 30, 2, 112 },
		{ 31, 3, 113 },
		{ 31, 3, 114 },
		{ 32, 2, 115 },
		{ 32, 1, 116 },
		{ 32, 2, 117 },
		{ 32, 1, 118 },
		{ 33, 1, 119 },
		{ 33, 3, 120 },
		{ 34, 1, 121 },
		{ 34, 2, 122 },
		{ 34, 3, 123 },
		{ 35, 4, 124 },
		{ 35, 5, 125 },
		{ 35, 2, 126 },
		{ 36, 1, 127 },
		{ 36, 3, 128 },
		{ 37, 1, 129 },
		{ 37, 3, 130 },
		{ 38, 1, 131 },
		{ 38, 1, 132 },
		{ 39, 2, 133 },
		{ 39, 1, 134 },
		{ 40, 1, 135 },
		{ 40, 3, 136 },
		{ 40, 4, 137 },
		{ 40, 3, 138 },
		{ 40, 4, 139 },
		{ 40, 4, 140 },
		{ 40, 3, 141 },
		{ 41, 1, 142 },
		{ 41, 2, 143 },
		{ 41, 2, 144 },
		{ 41, 3, 145 },
		{ 42, 1, 146 },
		{ 42, 2, 147 },
		{ 43, 1, 148 },
		{ 43, 3, 149 },
		{ 44, 1, 150 },
		{ 44, 3, 151 },
		{ 45, 2, 152 },
		{ 45, 2, 153 },
		{ 45, 1, 154 },
		{ 46, 1, 155 },
		{ 46, 3, 156 },
		{ 47, 1, 157 },
		{ 47, 2, 158 },
		{ 48, 1, 159 },
		{ 48, 1, 160 },
		{ 48, 2, 161 },
		{ 49, 3, 162 },
		{ 49, 2, 163 },
		{ 49, 3, 164 },
		{ 49, 3, 165 },
		{ 49, 4, 166 },
		{ 49, 2, 167 },
		{ 49, 3, 168 },
		{ 49, 3, 169 },
		{ 49, 4, 170 },
		{ 50, 1, 171 },
		{ 50, 3, 172 },
		{ 50, 4, 173 },
		{ 51, 1, 174 },
		{ 51, 3, 175 },
		{ 52, 1, 176 },
		{ 52, 1, 177 },
		{ 52, 1, 178 },
		{ 52, 1, 179 },
		{ 52, 1, 180 },
		{ 53, 1, 181 },
		{ 53, 1, 182 },
		{ 53, 1, 183 },
		{ 53, 1, 184 },
		{ 53, 1, 185 },
		{ 53, 1, 186 },
		{ 54, 3, 187 },
		{ 54, 4, 188 },
		{ 54, 3, 189 },
		{ 55, 2, 190 },
		{ 55, 3, 191 },
		{ 55, 3, 192 },
		{ 55, 4, 193 },
		{ 56, 1, 194 },
		{ 56, 2, 195 },
		{ 57, 1, 196 },
		{ 57, 2, 197 },
		{ 58, 1, 198 },
		{ 58, 2, 199 },
		{ 59, 1, 200 },
		{ 59, 1, 201 },
		{ 60, 7, 202 },
		{ 60, 1, 203 },
		{ 61, 5, 204 },
		{ 61, 7, 205 },
		{ 62, 1, 206 },
		{ 62, 5, 207 },
		{ 63, 5, 208 },
		{ 63, 7, 209 },
		{ 63, 6, 210 },
		{ 63, 7, 211 },
		{ 64, 3, 212 },
		{ 64, 2, 213 },
		{ 64, 2, 214 },
		{ 64, 2, 215 },
		{ 64, 3, 216 },
		{ 65, 1, 217 },
		{ 65, 2, 218 },
		{ 66, 1, 219 },
		{ 66, 1, 220 },
		{ 67, 4, 221 },
		{ 67, 3, 222 },
		{ 67, 3, 223 },
		{ 67, 2, 224 }
	};
	yyreduction = reduction;

	yytokenaction_size = 410;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 349, YYAT_SHIFT, 77 },
		{ 127, YYAT_SHIFT, 213 },
		{ 265, YYAT_SHIFT, 173 },
		{ 106, YYAT_SHIFT, 197 },
		{ 265, YYAT_SHIFT, 174 },
		{ 349, YYAT_SHIFT, 78 },
		{ 162, YYAT_SHIFT, 157 },
		{ 349, YYAT_SHIFT, 79 },
		{ 322, YYAT_ERROR, 0 },
		{ 349, YYAT_SHIFT, 80 },
		{ 349, YYAT_SHIFT, 81 },
		{ 55, YYAT_SHIFT, 142 },
		{ 349, YYAT_SHIFT, 82 },
		{ 39, YYAT_SHIFT, 2 },
		{ 302, YYAT_SHIFT, 1 },
		{ 255, YYAT_SHIFT, 253 },
		{ 302, YYAT_SHIFT, 2 },
		{ 299, YYAT_SHIFT, 322 },
		{ 164, YYAT_SHIFT, 253 },
		{ 321, YYAT_SHIFT, 341 },
		{ 164, YYAT_SHIFT, 2 },
		{ 152, YYAT_SHIFT, 150 },
		{ 280, YYAT_SHIFT, 177 },
		{ 280, YYAT_SHIFT, 178 },
		{ 251, YYAT_SHIFT, 249 },
		{ 160, YYAT_SHIFT, 249 },
		{ 349, YYAT_SHIFT, 108 },
		{ 249, YYAT_ERROR, 0 },
		{ 249, YYAT_SHIFT, 306 },
		{ 249, YYAT_ERROR, 0 },
		{ 25, YYAT_ACCEPT, 0 },
		{ 53, YYAT_SHIFT, 46 },
		{ 37, YYAT_SHIFT, 61 },
		{ 302, YYAT_SHIFT, 325 },
		{ 270, YYAT_SHIFT, 229 },
		{ 23, YYAT_SHIFT, 42 },
		{ 326, YYAT_SHIFT, 145 },
		{ 28, YYAT_SHIFT, 46 },
		{ 76, YYAT_SHIFT, 157 },
		{ 157, YYAT_SHIFT, 157 },
		{ 76, YYAT_SHIFT, 2 },
		{ 212, YYAT_SHIFT, 229 },
		{ 33, YYAT_SHIFT, 2 },
		{ 342, YYAT_SHIFT, 349 },
		{ 283, YYAT_SHIFT, 229 },
		{ 276, YYAT_SHIFT, 186 },
		{ 342, YYAT_SHIFT, 229 },
		{ 347, YYAT_SHIFT, 352 },
		{ 46, YYAT_SHIFT, 70 },
		{ 2, YYAT_SHIFT, 2 },
		{ 276, YYAT_SHIFT, 187 },
		{ 326, YYAT_SHIFT, 345 },
		{ 278, YYAT_SHIFT, 189 },
		{ 346, YYAT_ERROR, 0 },
		{ 278, YYAT_SHIFT, 190 },
		{ 276, YYAT_SHIFT, 188 },
		{ 212, YYAT_SHIFT, 294 },
		{ 162, YYAT_SHIFT, 158 },
		{ 283, YYAT_SHIFT, 315 },
		{ 264, YYAT_SHIFT, 173 },
		{ 267, YYAT_SHIFT, 312 },
		{ 264, YYAT_SHIFT, 174 },
		{ 74, YYAT_SHIFT, 154 },
		{ 267, YYAT_SHIFT, 313 },
		{ 340, YYAT_SHIFT, 347 },
		{ 74, YYAT_SHIFT, 155 },
		{ 255, YYAT_SHIFT, 158 },
		{ 263, YYAT_SHIFT, 191 },
		{ 263, YYAT_SHIFT, 192 },
		{ 164, YYAT_SHIFT, 158 },
		{ 25, YYAT_SHIFT, 1 },
		{ 25, YYAT_ERROR, 0 },
		{ 322, YYAT_SHIFT, 231 },
		{ 55, YYAT_SHIFT, 48 },
		{ 322, YYAT_SHIFT, 343 },
		{ 251, YYAT_SHIFT, 250 },
		{ 160, YYAT_SHIFT, 250 },
		{ 277, YYAT_SHIFT, 189 },
		{ 249, YYAT_ERROR, 0 },
		{ 277, YYAT_SHIFT, 190 },
		{ 262, YYAT_SHIFT, 191 },
		{ 262, YYAT_SHIFT, 192 },
		{ 53, YYAT_SHIFT, 47 },
		{ 270, YYAT_SHIFT, 314 },
		{ 98, YYAT_SHIFT, 189 },
		{ 94, YYAT_SHIFT, 179 },
		{ 98, YYAT_SHIFT, 190 },
		{ 253, YYAT_ERROR, 0 },
		{ 28, YYAT_SHIFT, 47 },
		{ 76, YYAT_SHIFT, 158 },
		{ 349, YYAT_SHIFT, 48 },
		{ 94, YYAT_SHIFT, 180 },
		{ 253, YYAT_ERROR, 0 },
		{ 349, YYAT_SHIFT, 84 },
		{ 253, YYAT_SHIFT, 253 },
		{ 253, YYAT_SHIFT, 244 },
		{ 253, YYAT_SHIFT, 2 },
		{ 253, YYAT_ERROR, 0 },
		{ 299, YYAT_SHIFT, 323 },
		{ 253, YYAT_ERROR, 0 },
		{ 168, YYAT_SHIFT, 4 },
		{ 321, YYAT_ERROR, 0 },
		{ 152, YYAT_SHIFT, 240 },
		{ 91, YYAT_SHIFT, 173 },
		{ 129, YYAT_SHIFT, 108 },
		{ 91, YYAT_SHIFT, 174 },
		{ 168, YYAT_SHIFT, 10 },
		{ 168, YYAT_SHIFT, 11 },
		{ 168, YYAT_SHIFT, 12 },
		{ 168, YYAT_SHIFT, 13 },
		{ 168, YYAT_SHIFT, 14 },
		{ 168, YYAT_SHIFT, 15 },
		{ 168, YYAT_SHIFT, 16 },
		{ 168, YYAT_SHIFT, 17 },
		{ 168, YYAT_SHIFT, 18 },
		{ 168, YYAT_SHIFT, 19 },
		{ 168, YYAT_SHIFT, 20 },
		{ 168, YYAT_SHIFT, 21 },
		{ 168, YYAT_SHIFT, 22 },
		{ 168, YYAT_SHIFT, 23 },
		{ 166, YYAT_SHIFT, 2 },
		{ 25, YYAT_ERROR, 0 },
		{ 275, YYAT_SHIFT, 186 },
		{ 97, YYAT_SHIFT, 186 },
		{ 261, YYAT_SHIFT, 191 },
		{ 261, YYAT_SHIFT, 192 },
		{ 332, YYAT_SHIFT, 346 },
		{ 275, YYAT_SHIFT, 187 },
		{ 97, YYAT_SHIFT, 187 },
		{ 260, YYAT_SHIFT, 191 },
		{ 260, YYAT_SHIFT, 192 },
		{ 320, YYAT_ERROR, 0 },
		{ 275, YYAT_SHIFT, 188 },
		{ 97, YYAT_SHIFT, 188 },
		{ 100, YYAT_SHIFT, 191 },
		{ 100, YYAT_SHIFT, 192 },
		{ 94, YYAT_SHIFT, 181 },
		{ 92, YYAT_SHIFT, 177 },
		{ 92, YYAT_SHIFT, 178 },
		{ 309, YYAT_SHIFT, 328 },
		{ 307, YYAT_SHIFT, 327 },
		{ 301, YYAT_SHIFT, 324 },
		{ 292, YYAT_SHIFT, 108 },
		{ 291, YYAT_SHIFT, 320 },
		{ 290, YYAT_SHIFT, 319 },
		{ 253, YYAT_SHIFT, 158 },
		{ 36, YYAT_SHIFT, 4 },
		{ 36, YYAT_SHIFT, 5 },
		{ 36, YYAT_SHIFT, 6 },
		{ 36, YYAT_SHIFT, 7 },
		{ 36, YYAT_SHIFT, 8 },
		{ 36, YYAT_SHIFT, 9 },
		{ 36, YYAT_SHIFT, 10 },
		{ 36, YYAT_SHIFT, 11 },
		{ 36, YYAT_SHIFT, 12 },
		{ 36, YYAT_SHIFT, 13 },
		{ 36, YYAT_SHIFT, 14 },
		{ 36, YYAT_SHIFT, 15 },
		{ 36, YYAT_SHIFT, 16 },
		{ 36, YYAT_SHIFT, 17 },
		{ 36, YYAT_SHIFT, 18 },
		{ 36, YYAT_SHIFT, 19 },
		{ 36, YYAT_SHIFT, 20 },
		{ 36, YYAT_SHIFT, 21 },
		{ 36, YYAT_SHIFT, 22 },
		{ 36, YYAT_SHIFT, 23 },
		{ 37, YYAT_SHIFT, 62 },
		{ 289, YYAT_SHIFT, 318 },
		{ 129, YYAT_SHIFT, 48 },
		{ 23, YYAT_SHIFT, 43 },
		{ 129, YYAT_SHIFT, 225 },
		{ 288, YYAT_SHIFT, 317 },
		{ 284, YYAT_SHIFT, 196 },
		{ 282, YYAT_SHIFT, 195 },
		{ 281, YYAT_SHIFT, 193 },
		{ 279, YYAT_SHIFT, 194 },
		{ 259, YYAT_SHIFT, 311 },
		{ 250, YYAT_SHIFT, 308 },
		{ 248, YYAT_SHIFT, 305 },
		{ 246, YYAT_SHIFT, 304 },
		{ 253, YYAT_ERROR, 0 },
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
		{ 245, YYAT_SHIFT, 303 },
		{ 237, YYAT_SHIFT, 302 },
		{ 236, YYAT_SHIFT, 300 },
		{ 231, YYAT_ERROR, 0 },
		{ 226, YYAT_SHIFT, 296 },
		{ 322, YYAT_SHIFT, 85 },
		{ 208, YYAT_SHIFT, 293 },
		{ 265, YYAT_SHIFT, 175 },
		{ 265, YYAT_SHIFT, 176 },
		{ 206, YYAT_SHIFT, 291 },
		{ 106, YYAT_SHIFT, 198 },
		{ 127, YYAT_SHIFT, 214 },
		{ 127, YYAT_SHIFT, 215 },
		{ 127, YYAT_SHIFT, 216 },
		{ 127, YYAT_SHIFT, 217 },
		{ 127, YYAT_SHIFT, 218 },
		{ 127, YYAT_SHIFT, 219 },
		{ 127, YYAT_SHIFT, 220 },
		{ 127, YYAT_SHIFT, 221 },
		{ 127, YYAT_SHIFT, 222 },
		{ 127, YYAT_SHIFT, 223 },
		{ 201, YYAT_SHIFT, 286 },
		{ 162, YYAT_SHIFT, 3 },
		{ 349, YYAT_SHIFT, 110 },
		{ 349, YYAT_SHIFT, 86 },
		{ 349, YYAT_SHIFT, 87 },
		{ 349, YYAT_SHIFT, 88 },
		{ 182, YYAT_SHIFT, 271 },
		{ 349, YYAT_SHIFT, 89 },
		{ 349, YYAT_SHIFT, 90 },
		{ 302, YYAT_SHIFT, 3 },
		{ 55, YYAT_SHIFT, 4 },
		{ 55, YYAT_SHIFT, 5 },
		{ 55, YYAT_SHIFT, 6 },
		{ 55, YYAT_SHIFT, 7 },
		{ 55, YYAT_SHIFT, 8 },
		{ 55, YYAT_SHIFT, 9 },
		{ 55, YYAT_SHIFT, 10 },
		{ 55, YYAT_SHIFT, 11 },
		{ 55, YYAT_SHIFT, 12 },
		{ 55, YYAT_SHIFT, 13 },
		{ 55, YYAT_SHIFT, 14 },
		{ 55, YYAT_SHIFT, 15 },
		{ 55, YYAT_SHIFT, 16 },
		{ 55, YYAT_SHIFT, 17 },
		{ 55, YYAT_SHIFT, 18 },
		{ 55, YYAT_SHIFT, 19 },
		{ 55, YYAT_SHIFT, 20 },
		{ 55, YYAT_SHIFT, 21 },
		{ 55, YYAT_SHIFT, 22 },
		{ 55, YYAT_SHIFT, 23 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 76, YYAT_SHIFT, 3 },
		{ 157, YYAT_SHIFT, 3 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 46, YYAT_SHIFT, 71 },
		{ 264, YYAT_SHIFT, 175 },
		{ 264, YYAT_SHIFT, 176 },
		{ 39, YYAT_SHIFT, 18 },
		{ 39, YYAT_SHIFT, 19 },
		{ 180, YYAT_SHIFT, 269 },
		{ 349, YYAT_SHIFT, 111 },
		{ 349, YYAT_SHIFT, 112 },
		{ 349, YYAT_SHIFT, 113 },
		{ 179, YYAT_SHIFT, 266 },
		{ 349, YYAT_SHIFT, 114 },
		{ 349, YYAT_SHIFT, 115 },
		{ 349, YYAT_SHIFT, 116 },
		{ 349, YYAT_SHIFT, 117 },
		{ 349, YYAT_SHIFT, 118 },
		{ 349, YYAT_SHIFT, 119 },
		{ 349, YYAT_SHIFT, 120 },
		{ 349, YYAT_SHIFT, 121 },
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
		{ 129, YYAT_SHIFT, 110 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 167, YYAT_SHIFT, 258 },
		{ 94, YYAT_SHIFT, 182 },
		{ 94, YYAT_SHIFT, 183 },
		{ 94, YYAT_SHIFT, 184 },
		{ 91, YYAT_SHIFT, 175 },
		{ 91, YYAT_SHIFT, 176 },
		{ 253, YYAT_ERROR, 0 },
		{ 253, YYAT_ERROR, 0 },
		{ 253, YYAT_ERROR, 0 },
		{ 253, YYAT_ERROR, 0 },
		{ 165, YYAT_SHIFT, 256 },
		{ 253, YYAT_ERROR, 0 },
		{ 253, YYAT_ERROR, 0 },
		{ 158, YYAT_SHIFT, 247 },
		{ 156, YYAT_SHIFT, 242 },
		{ 155, YYAT_SHIFT, 241 },
		{ 150, YYAT_SHIFT, 66 },
		{ 148, YYAT_ERROR, 0 },
		{ 147, YYAT_SHIFT, 236 },
		{ 145, YYAT_ERROR, 0 },
		{ 144, YYAT_SHIFT, 48 },
		{ 141, YYAT_SHIFT, 142 },
		{ 137, YYAT_SHIFT, 230 },
		{ 129, YYAT_SHIFT, 5 },
		{ 129, YYAT_SHIFT, 6 },
		{ 129, YYAT_SHIFT, 7 },
		{ 129, YYAT_SHIFT, 8 },
		{ 129, YYAT_SHIFT, 9 },
		{ 131, YYAT_SHIFT, 227 },
		{ 121, YYAT_SHIFT, 211 },
		{ 120, YYAT_SHIFT, 210 },
		{ 119, YYAT_SHIFT, 209 },
		{ 253, YYAT_SHIFT, 5 },
		{ 253, YYAT_SHIFT, 6 },
		{ 253, YYAT_SHIFT, 7 },
		{ 253, YYAT_SHIFT, 8 },
		{ 253, YYAT_SHIFT, 9 },
		{ 118, YYAT_SHIFT, 208 },
		{ 117, YYAT_SHIFT, 207 },
		{ 115, YYAT_SHIFT, 205 },
		{ 114, YYAT_SHIFT, 204 },
		{ 113, YYAT_SHIFT, 203 },
		{ 112, YYAT_SHIFT, 202 },
		{ 129, YYAT_SHIFT, 111 },
		{ 129, YYAT_SHIFT, 112 },
		{ 129, YYAT_SHIFT, 113 },
		{ 110, YYAT_SHIFT, 200 },
		{ 129, YYAT_SHIFT, 114 },
		{ 129, YYAT_SHIFT, 115 },
		{ 129, YYAT_SHIFT, 116 },
		{ 129, YYAT_SHIFT, 117 },
		{ 129, YYAT_SHIFT, 118 },
		{ 129, YYAT_SHIFT, 119 },
		{ 129, YYAT_SHIFT, 120 },
		{ 129, YYAT_SHIFT, 121 },
		{ 166, YYAT_SHIFT, 4 },
		{ 107, YYAT_SHIFT, 199 },
		{ 105, YYAT_SHIFT, 196 },
		{ 104, YYAT_SHIFT, 195 },
		{ 103, YYAT_SHIFT, 194 },
		{ 101, YYAT_SHIFT, 193 },
		{ 166, YYAT_SHIFT, 10 },
		{ 166, YYAT_SHIFT, 11 },
		{ 166, YYAT_SHIFT, 12 },
		{ 166, YYAT_SHIFT, 13 },
		{ 166, YYAT_SHIFT, 14 },
		{ 166, YYAT_SHIFT, 15 },
		{ 166, YYAT_SHIFT, 16 },
		{ 166, YYAT_SHIFT, 17 },
		{ 166, YYAT_SHIFT, 18 },
		{ 166, YYAT_SHIFT, 19 },
		{ 166, YYAT_SHIFT, 20 },
		{ 166, YYAT_SHIFT, 21 },
		{ 166, YYAT_SHIFT, 22 },
		{ 166, YYAT_SHIFT, 23 },
		{ 163, YYAT_SHIFT, 4 },
		{ 90, YYAT_SHIFT, 170 },
		{ 88, YYAT_SHIFT, 168 },
		{ 75, YYAT_SHIFT, 156 },
		{ 72, YYAT_SHIFT, 153 },
		{ 68, YYAT_SHIFT, 151 },
		{ 163, YYAT_SHIFT, 10 },
		{ 163, YYAT_SHIFT, 11 },
		{ 163, YYAT_SHIFT, 12 },
		{ 163, YYAT_SHIFT, 13 },
		{ 163, YYAT_SHIFT, 14 },
		{ 163, YYAT_SHIFT, 15 },
		{ 163, YYAT_SHIFT, 16 },
		{ 163, YYAT_SHIFT, 17 },
		{ 163, YYAT_SHIFT, 18 },
		{ 163, YYAT_SHIFT, 19 },
		{ 163, YYAT_SHIFT, 20 },
		{ 163, YYAT_SHIFT, 21 },
		{ 163, YYAT_SHIFT, 22 },
		{ 163, YYAT_SHIFT, 23 },
		{ 66, YYAT_SHIFT, 149 },
		{ 62, YYAT_SHIFT, 148 },
		{ 56, YYAT_SHIFT, 146 },
		{ 51, YYAT_SHIFT, 54 },
		{ 48, YYAT_SHIFT, 109 },
		{ 47, YYAT_SHIFT, 83 },
		{ 43, YYAT_SHIFT, 69 },
		{ 38, YYAT_SHIFT, 63 },
		{ 30, YYAT_ERROR, 0 },
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 409, 1, YYAT_DEFAULT, 25 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 7, 1, YYAT_REDUCE, 143 },
		{ 0, 0, YYAT_REDUCE, 136 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ 0, 0, YYAT_REDUCE, 132 },
		{ 0, 0, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ -88, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ 30, 1, YYAT_DEFAULT, 157 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ -101, 1, YYAT_REDUCE, 81 },
		{ -3, 1, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ 366, 1, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 0, 0, YYAT_DEFAULT, 51 },
		{ 0, 1, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ -136, 1, YYAT_REDUCE, 77 },
		{ -91, 1, YYAT_ERROR, 0 },
		{ 366, 1, YYAT_ERROR, 0 },
		{ -29, 1, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ 283, 1, YYAT_REDUCE, 127 },
		{ 0, 0, YYAT_REDUCE, 219 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 7, 1, YYAT_DEFAULT, 249 },
		{ 312, 1, YYAT_DEFAULT, 320 },
		{ 279, 1, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_REDUCE, 225 },
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ 344, 1, YYAT_DEFAULT, 302 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ -9, 1, YYAT_REDUCE, 134 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ -50, 1, YYAT_REDUCE, 85 },
		{ 343, 1, YYAT_DEFAULT, 326 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_DEFAULT, 148 },
		{ 278, 1, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 339, 1, YYAT_REDUCE, 130 },
		{ 0, 0, YYAT_REDUCE, 128 },
		{ 260, 1, YYAT_DEFAULT, 152 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 0, 0, YYAT_REDUCE, 156 },
		{ 343, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 151 },
		{ 21, 1, YYAT_ERROR, 0 },
		{ 339, 1, YYAT_REDUCE, 149 },
		{ -2, 1, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 342, 1, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 90 },
		{ 341, 1, YYAT_DEFAULT, 320 },
		{ 43, 1, YYAT_REDUCE, 44 },
		{ -131, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 45, 1, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 86, 1, YYAT_REDUCE, 33 },
		{ 41, 1, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -130, 1, YYAT_REDUCE, 39 },
		{ 271, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 326, 1, YYAT_REDUCE, 49 },
		{ 239, 1, YYAT_REDUCE, 53 },
		{ 92, 1, YYAT_REDUCE, 55 },
		{ -60, 1, YYAT_REDUCE, 57 },
		{ 268, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 293, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 289, 1, YYAT_ERROR, 0 },
		{ 306, 1, YYAT_ERROR, 0 },
		{ 305, 1, YYAT_ERROR, 0 },
		{ 304, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 303, 1, YYAT_ERROR, 0 },
		{ 85, 1, YYAT_ERROR, 0 },
		{ 277, 1, YYAT_ERROR, 0 },
		{ 276, 1, YYAT_ERROR, 0 },
		{ 275, 1, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ -60, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 45, 1, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 208, 1, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 268, 1, YYAT_DEFAULT, 212 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 265, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_DEFAULT, 231 },
		{ 0, 0, YYAT_REDUCE, 223 },
		{ 202, 1, YYAT_DEFAULT, 148 },
		{ 265, 1, YYAT_DEFAULT, 302 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 198, 1, YYAT_DEFAULT, 237 },
		{ 281, 1, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 64, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ -23, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ 63, 1, YYAT_ERROR, 0 },
		{ 17, 1, YYAT_DEFAULT, 148 },
		{ -1, 1, YYAT_DEFAULT, 253 },
		{ 225, 1, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ -15, 1, YYAT_REDUCE, 161 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ -34, 1, YYAT_REDUCE, 160 },
		{ 98, 1, YYAT_REDUCE, 119 },
		{ -22, 1, YYAT_REDUCE, 158 },
		{ 274, 1, YYAT_ERROR, 0 },
		{ 78, 1, YYAT_REDUCE, 117 },
		{ 264, 1, YYAT_DEFAULT, 342 },
		{ -182, 1, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 232, 1, YYAT_DEFAULT, 321 },
		{ 12, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ -29, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 164, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ -98, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 292 },
		{ 148, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ 0, 0, YYAT_REDUCE, 216 },
		{ -3, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 61 },
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
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 80, 1, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 79, 1, YYAT_DEFAULT, 322 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 144, 1, YYAT_DEFAULT, 302 },
		{ 77, 1, YYAT_DEFAULT, 148 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ 0, 0, YYAT_REDUCE, 129 },
		{ 0, 0, YYAT_REDUCE, 126 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ 160, 1, YYAT_ERROR, 0 },
		{ 138, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 85, 1, YYAT_ERROR, 0 },
		{ -13, 1, YYAT_DEFAULT, 253 },
		{ 84, 1, YYAT_DEFAULT, 320 },
		{ -16, 1, YYAT_REDUCE, 162 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ 54, 1, YYAT_DEFAULT, 168 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ -25, 1, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 135, 1, YYAT_ERROR, 0 },
		{ -135, 1, YYAT_REDUCE, 40 },
		{ -140, 1, YYAT_REDUCE, 41 },
		{ -184, 1, YYAT_REDUCE, 42 },
		{ -197, 1, YYAT_REDUCE, 43 },
		{ -1, 1, YYAT_REDUCE, 45 },
		{ -58, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 19, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ -10, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 85, 1, YYAT_REDUCE, 34 },
		{ 8, 1, YYAT_REDUCE, 35 },
		{ 34, 1, YYAT_REDUCE, 37 },
		{ 9, 1, YYAT_REDUCE, 38 },
		{ 137, 1, YYAT_REDUCE, 50 },
		{ -246, 1, YYAT_REDUCE, 48 },
		{ 80, 1, YYAT_REDUCE, 52 },
		{ 49, 1, YYAT_REDUCE, 54 },
		{ 0, 1, YYAT_ERROR, 0 },
		{ -98, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 130, 1, YYAT_DEFAULT, 342 },
		{ 126, 1, YYAT_DEFAULT, 342 },
		{ 103, 1, YYAT_DEFAULT, 342 },
		{ 103, 1, YYAT_ERROR, 0 },
		{ 83, 1, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 0, 0, YYAT_REDUCE, 217 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 82, 1, YYAT_DEFAULT, 326 },
		{ -26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 0, 0, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 165 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 99, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ 46, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 320 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_DEFAULT, 346 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 90, 1, YYAT_DEFAULT, 321 },
		{ -22, 1, YYAT_DEFAULT, 231 },
		{ -51, 1, YYAT_DEFAULT, 346 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ -8, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 0, 0, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ -180, 1, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 23, 1, YYAT_DEFAULT, 342 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 2, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ -254, 1, YYAT_DEFAULT, 349 },
		{ -12, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ -33, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 212 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 234;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 349, 127 },
		{ 322, 233 },
		{ 292, 137 },
		{ 322, -1 },
		{ 313, 329 },
		{ 349, 100 },
		{ 349, 91 },
		{ 349, 92 },
		{ 349, 103 },
		{ 349, 101 },
		{ 349, 104 },
		{ 349, 105 },
		{ 349, 106 },
		{ 349, 136 },
		{ 349, 138 },
		{ 179, 267 },
		{ 349, 137 },
		{ 346, -1 },
		{ 346, 335 },
		{ 346, 333 },
		{ 156, 76 },
		{ 33, 59 },
		{ 346, 334 },
		{ 346, -1 },
		{ 346, 350 },
		{ 346, 351 },
		{ 346, -1 },
		{ 346, 336 },
		{ 346, 337 },
		{ 148, 52 },
		{ 179, 268 },
		{ 1, -1 },
		{ 341, 348 },
		{ 322, 344 },
		{ 48, 52 },
		{ 322, -1 },
		{ 313, -1 },
		{ 322, -1 },
		{ 322, -1 },
		{ 33, 58 },
		{ 292, 321 },
		{ 322, -1 },
		{ 156, 243 },
		{ 322, -1 },
		{ 322, -1 },
		{ 1, 38 },
		{ 322, -1 },
		{ 322, -1 },
		{ 349, 123 },
		{ 349, 353 },
		{ 349, 132 },
		{ 349, 128 },
		{ 320, 340 },
		{ 163, 252 },
		{ 349, 130 },
		{ 349, 122 },
		{ 349, 124 },
		{ 349, 126 },
		{ 349, 125 },
		{ 349, 133 },
		{ 349, 134 },
		{ 253, 76 },
		{ 163, -1 },
		{ 148, 237 },
		{ 253, 36 },
		{ 253, 33 },
		{ 253, 35 },
		{ 253, 37 },
		{ 48, 129 },
		{ 48, 131 },
		{ 321, 138 },
		{ 2, 40 },
		{ 321, 342 },
		{ 253, 31 },
		{ 2, 41 },
		{ 2, 39 },
		{ 253, 27 },
		{ 25, 34 },
		{ 25, 32 },
		{ 315, 93 },
		{ 319, 339 },
		{ 253, 246 },
		{ 253, 75 },
		{ 253, 73 },
		{ 129, 140 },
		{ 129, 51 },
		{ 253, 245 },
		{ 318, 338 },
		{ 129, 36 },
		{ 129, 33 },
		{ 129, 35 },
		{ 129, 37 },
		{ 315, 330 },
		{ 315, -1 },
		{ 25, 29 },
		{ 25, 28 },
		{ 25, 30 },
		{ 129, 31 },
		{ 231, 298 },
		{ 231, 299 },
		{ 129, 27 },
		{ 302, 326 },
		{ 302, 57 },
		{ 168, 166 },
		{ 168, 35 },
		{ 168, 37 },
		{ 237, 140 },
		{ 237, 51 },
		{ 168, 164 },
		{ 250, 102 },
		{ 90, 172 },
		{ 168, 31 },
		{ 90, -1 },
		{ 250, 309 },
		{ 168, 163 },
		{ 129, 135 },
		{ 302, 141 },
		{ 302, 28 },
		{ 302, 30 },
		{ 129, 226 },
		{ 286, 316 },
		{ 25, 44 },
		{ 25, 24 },
		{ 168, 259 },
		{ 249, -1 },
		{ 255, 251 },
		{ 249, 307 },
		{ 237, -1 },
		{ 237, -1 },
		{ 237, -1 },
		{ 166, -1 },
		{ 249, -1 },
		{ 249, -1 },
		{ 166, -1 },
		{ 166, 166 },
		{ 236, 301 },
		{ 164, 255 },
		{ 256, 99 },
		{ 256, 94 },
		{ 166, 257 },
		{ 256, 93 },
		{ 256, 95 },
		{ 256, 310 },
		{ 164, 254 },
		{ 164, 160 },
		{ 166, 163 },
		{ 76, 161 },
		{ 76, 28 },
		{ 76, 162 },
		{ 317, 331 },
		{ 317, 332 },
		{ 317, 126 },
		{ 198, 284 },
		{ 198, -1 },
		{ 198, -1 },
		{ 76, 159 },
		{ 157, 38 },
		{ 157, 28 },
		{ 157, 162 },
		{ 46, 72 },
		{ 39, 64 },
		{ 229, 297 },
		{ 46, 74 },
		{ 39, 65 },
		{ 196, 282 },
		{ 196, -1 },
		{ 195, 281 },
		{ 195, -1 },
		{ 194, 280 },
		{ 194, -1 },
		{ 193, 279 },
		{ 193, -1 },
		{ 192, 97 },
		{ 192, 278 },
		{ 190, 96 },
		{ 190, 276 },
		{ 178, 265 },
		{ 178, -1 },
		{ 176, 98 },
		{ 176, 263 },
		{ 145, -1 },
		{ 145, 235 },
		{ 69, 152 },
		{ 69, 67 },
		{ 55, 143 },
		{ 55, 144 },
		{ 36, -1 },
		{ 36, 60 },
		{ 29, 49 },
		{ 29, 50 },
		{ 0, 25 },
		{ 0, 26 },
		{ 226, 228 },
		{ 224, 295 },
		{ 207, 292 },
		{ 205, 290 },
		{ 204, 289 },
		{ 203, 288 },
		{ 202, 287 },
		{ 200, 285 },
		{ 197, 283 },
		{ 191, 277 },
		{ 189, 275 },
		{ 188, 274 },
		{ 187, 273 },
		{ 186, 272 },
		{ 181, 270 },
		{ 177, 264 },
		{ 175, 262 },
		{ 174, 261 },
		{ 173, 260 },
		{ 170, 167 },
		{ 162, 53 },
		{ 158, 248 },
		{ 150, 239 },
		{ 149, 238 },
		{ 144, 234 },
		{ 142, 232 },
		{ 127, 224 },
		{ 121, 212 },
		{ 116, 206 },
		{ 111, 201 },
		{ 95, 185 },
		{ 89, 171 },
		{ 88, 169 },
		{ 79, 165 },
		{ 61, 147 },
		{ 51, 56 },
		{ 50, 139 },
		{ 47, 107 },
		{ 42, 68 },
		{ 32, 55 },
		{ 30, 53 },
		{ 27, 45 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 125, 25 },
		{ 6, 145 },
		{ 33, -1 },
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
		{ 55, 237 },
		{ 0, -1 },
		{ 210, 36 },
		{ 0, -1 },
		{ 133, 148 },
		{ 192, -1 },
		{ 0, -1 },
		{ 192, 51 },
		{ -2, 36 },
		{ 0, -1 },
		{ 0, -1 },
		{ 164, 237 },
		{ 0, -1 },
		{ 0, -1 },
		{ 122, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 194, 69 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 116, 249 },
		{ 208, 250 },
		{ 12, 129 },
		{ 0, -1 },
		{ 173, 237 },
		{ 203, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 129, 148 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 170, 148 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 146, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 107, 164 },
		{ 0, -1 },
		{ 0, -1 },
		{ 178, 168 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 220, 90 },
		{ 219, 90 },
		{ 106, 256 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 216, 256 },
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
		{ 200, 250 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 167, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 199, 321 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 199, -1 },
		{ 0, -1 },
		{ 62, 349 },
		{ 0, -1 },
		{ 0, 226 },
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
		{ 167, 322 },
		{ 0, -1 },
		{ 161, 237 },
		{ 156, 302 },
		{ 0, -1 },
		{ 0, 237 },
		{ 7, 237 },
		{ 194, 250 },
		{ 177, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, 36 },
		{ 117, 253 },
		{ 192, 250 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 172, 255 },
		{ 21, 166 },
		{ 95, -1 },
		{ 0, -1 },
		{ 107, 33 },
		{ 0, -1 },
		{ 76, 170 },
		{ 0, -1 },
		{ 191, 321 },
		{ 0, -1 },
		{ 0, -1 },
		{ 201, 176 },
		{ 200, 176 },
		{ 199, 176 },
		{ 170, 192 },
		{ 197, 178 },
		{ 166, 194 },
		{ 12, 313 },
		{ 0, -1 },
		{ 186, 321 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 199, 256 },
		{ 198, 256 },
		{ 197, 256 },
		{ 195, 190 },
		{ 168, 256 },
		{ 193, 192 },
		{ 165, 190 },
		{ 158, 195 },
		{ 157, 193 },
		{ 153, 196 },
		{ 150, 198 },
		{ 180, 321 },
		{ 137, 315 },
		{ 0, -1 },
		{ 146, 349 },
		{ 0, -1 },
		{ 145, 349 },
		{ 177, 321 },
		{ 176, 321 },
		{ 175, 321 },
		{ 0, -1 },
		{ 136, 292 },
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
		{ 175, 313 },
		{ 0, -1 },
		{ 139, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 143, 313 },
		{ 0, -1 },
		{ 48, 322 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 111, 302 },
		{ 84, 249 },
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
		{ 83, 253 },
		{ 92, 315 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, 164 },
		{ 0, -1 },
		{ 76, -1 },
		{ 136, -1 },
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
		{ 0, -1 },
		{ 67, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -18, 321 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, -1 },
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
		{ -14, 322 },
		{ 0, -1 },
		{ 75, 313 },
		{ 0, -1 },
		{ 90, 346 },
		{ 34, 349 },
		{ 27, 349 },
		{ 32, 321 },
		{ 52, 313 },
		{ -17, 346 },
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
		{ -21, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -36, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 176 },
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
#line 2688 ".\\myparser.y"


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
