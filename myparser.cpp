/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 57 of your 30 day trial period.
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
* Date: 12/05/18
* Time: 17:07:15
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
#include "mylexer.h"
#include <string>
int flag = 0;
struct node {
	int id;
	string name;
	string value;
	int length;
	node** children;
	node(string n = "", string v = "")
	{
		length = 0;
		id = flag++;
		name = n;
		value = v;
	}
};

void traverse(node* root) {
	cout<<root -> id<<":\t\t\t"<<root -> name<<"\t\t\t"<<root -> value<<"\t\t\tchildren:";
	if (root -> length != 0) {
		for (int i = 0; i < root -> length; i++) {
			cout<<root -> children[i] -> id<<" ";
		}
		cout<<endl;
		for (int i = 0; i < root -> length; i++) {
			traverse(root -> children[i]);
		}
	} else {
		cout<<endl;
	}
}

#line 79 "myparser.cpp"
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
#line 93 ".\\myparser.y"

	// place any extra initialisation code here

#line 103 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 98 ".\\myparser.y"

	// place any extra cleanup code here

#line 117 "myparser.cpp"
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
#line 121 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("108 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 234 "myparser.cpp"
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
#line 129 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("116 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 254 "myparser.cpp"
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
#line 137 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("123 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 274 "myparser.cpp"
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
#line 145 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("130 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	
	
#line 296 "myparser.cpp"
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
#line 158 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("142 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 316 "myparser.cpp"
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
#line 166 ".\\myparser.y"
	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("149 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 339 "myparser.cpp"
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
#line 177 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("159 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 361 "myparser.cpp"
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
#line 187 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("168 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 384 "myparser.cpp"
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
#line 198 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("178 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 406 "myparser.cpp"
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
#line 208 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("187 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 428 "myparser.cpp"
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
#line 218 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("196 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 449 "myparser.cpp"
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
#line 227 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 470 "myparser.cpp"
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
#line 239 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("215 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_expression_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 490 "myparser.cpp"
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
#line 247 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("222 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_expression_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 512 "myparser.cpp"
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
#line 260 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("234 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 532 "myparser.cpp"
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
#line 268 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("241 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 553 "myparser.cpp"
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
#line 277 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("249 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 574 "myparser.cpp"
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
#line 286 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("257 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 595 "myparser.cpp"
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
#line 295 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("265 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 616 "myparser.cpp"
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
#line 304 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("273 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 639 "myparser.cpp"
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
#line 318 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("286 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 659 "myparser.cpp"
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
#line 326 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 679 "myparser.cpp"
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
#line 334 ".\\myparser.y"

		printf("777");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("301 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 700 "myparser.cpp"
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
#line 343 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("308 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 720 "myparser.cpp"
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
#line 351 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("315 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 740 "myparser.cpp"
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
#line 359 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("322 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 760 "myparser.cpp"
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
#line 370 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("332 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 780 "myparser.cpp"
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
#line 378 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("339 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 803 "myparser.cpp"
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
#line 392 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("352 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 823 "myparser.cpp"
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
#line 400 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("359 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 845 "myparser.cpp"
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
#line 410 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("368 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 867 "myparser.cpp"
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
#line 420 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("377 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 889 "myparser.cpp"
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
#line 433 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("389 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 909 "myparser.cpp"
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
#line 441 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("396 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 931 "myparser.cpp"
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
#line 451 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("405 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 953 "myparser.cpp"
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
#line 464 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("417 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 973 "myparser.cpp"
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
#line 472 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("424 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 995 "myparser.cpp"
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
#line 482 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("433 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1017 "myparser.cpp"
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
#line 495 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("445 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 1037 "myparser.cpp"
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
#line 503 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("452 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1059 "myparser.cpp"
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
#line 513 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("461 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1081 "myparser.cpp"
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
#line 523 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("470 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1103 "myparser.cpp"
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
#line 533 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("479 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1125 "myparser.cpp"
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
#line 546 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("491 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 1145 "myparser.cpp"
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
#line 554 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("498 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1167 "myparser.cpp"
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
#line 564 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("507 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1189 "myparser.cpp"
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
#line 577 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("519 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 1209 "myparser.cpp"
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
#line 585 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("526 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1231 "myparser.cpp"
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
#line 598 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 1251 "myparser.cpp"
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
#line 606 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("545 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1273 "myparser.cpp"
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
#line 619 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("557 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 1293 "myparser.cpp"
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
#line 627 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("564 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1315 "myparser.cpp"
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
#line 640 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("576 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 1335 "myparser.cpp"
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
#line 648 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("583 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1357 "myparser.cpp"
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
#line 661 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("595 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 1377 "myparser.cpp"
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
#line 669 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("602 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1399 "myparser.cpp"
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
#line 682 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("614 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_expression";		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1419 "myparser.cpp"
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
#line 690 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("621 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 5).ntnode;				
	
#line 1443 "myparser.cpp"
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
#line 705 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1463 "myparser.cpp"
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
#line 713 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	
	
#line 1485 "myparser.cpp"
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
#line 726 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("654 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1505 "myparser.cpp"
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
#line 734 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("661 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1525 "myparser.cpp"
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
#line 742 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("668 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1545 "myparser.cpp"
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
#line 750 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("675 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1565 "myparser.cpp"
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
#line 758 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("682 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1585 "myparser.cpp"
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
#line 766 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1605 "myparser.cpp"
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
#line 774 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("696 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1625 "myparser.cpp"
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
#line 782 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("703 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1645 "myparser.cpp"
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
#line 790 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("710 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1665 "myparser.cpp"
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
#line 798 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("717 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1685 "myparser.cpp"
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
#line 806 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("724 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1705 "myparser.cpp"
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
#line 817 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("734 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1725 "myparser.cpp"
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
#line 825 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("741 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1747 "myparser.cpp"
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
#line 838 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("753 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_expression";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1767 "myparser.cpp"
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
#line 849 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("763 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1788 "myparser.cpp"
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
#line 858 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("771 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 1810 "myparser.cpp"
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
#line 871 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("783 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 1830 "myparser.cpp"
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
#line 880 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("791 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1851 "myparser.cpp"
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
#line 889 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("799 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 1871 "myparser.cpp"
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
#line 897 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("806 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1892 "myparser.cpp"
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
#line 906 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("814 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 1912 "myparser.cpp"
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
#line 914 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("821 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1933 "myparser.cpp"
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
#line 926 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("832 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1953 "myparser.cpp"
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
#line 934 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("839 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 1975 "myparser.cpp"
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
#line 947 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("851 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1995 "myparser.cpp"
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
#line 955 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("858 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;							
	
#line 2017 "myparser.cpp"
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
#line 968 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("870 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2037 "myparser.cpp"
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
#line 976 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("877 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2057 "myparser.cpp"
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
#line 984 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("884 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2077 "myparser.cpp"
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
#line 992 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2097 "myparser.cpp"
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
#line 1000 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("898 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2117 "myparser.cpp"
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
#line 1011 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2137 "myparser.cpp"
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
#line 1019 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("915 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2157 "myparser.cpp"
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
#line 1027 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("922 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2177 "myparser.cpp"
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
#line 1035 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("929 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2197 "myparser.cpp"
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
#line 1043 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("936 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2217 "myparser.cpp"
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
#line 1051 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("943 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2237 "myparser.cpp"
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
#line 1059 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("950 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2257 "myparser.cpp"
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
#line 1067 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("957 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2277 "myparser.cpp"
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
#line 1075 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2297 "myparser.cpp"
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
#line 1083 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2317 "myparser.cpp"
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
#line 1091 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("978 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2337 "myparser.cpp"
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
#line 1099 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("985 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2357 "myparser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1110 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("995 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 5).ntnode;		
	
#line 2381 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1122 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1006 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;		
	
#line 2404 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1133 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1016 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2425 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1145 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1027 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2445 "myparser.cpp"
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
#line 1153 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1034 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2465 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1164 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1044 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2485 "myparser.cpp"
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
#line 1172 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1051 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2506 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1184 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1062 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2528 "myparser.cpp"
			}
		}
		break;
	case 111:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1197 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1074 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2549 "myparser.cpp"
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
#line 1206 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1082 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2569 "myparser.cpp"
			}
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1214 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1089 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2590 "myparser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1223 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1097 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2610 "myparser.cpp"
			}
		}
		break;
	case 115:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1234 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1107 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2630 "myparser.cpp"
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
#line 1242 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1114 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2652 "myparser.cpp"
			}
		}
		break;
	case 117:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1255 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1126 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2672 "myparser.cpp"
			}
		}
		break;
	case 118:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1263 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1133 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2693 "myparser.cpp"
			}
		}
		break;
	case 119:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1272 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1141 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2715 "myparser.cpp"
			}
		}
		break;
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1285 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1153 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 2738 "myparser.cpp"
			}
		}
		break;
	case 121:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1296 ".\\myparser.y"

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
	
#line 2762 "myparser.cpp"
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
#line 1308 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1174 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2783 "myparser.cpp"
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
#line 1320 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1185 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2803 "myparser.cpp"
			}
		}
		break;
	case 124:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1328 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1192 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2825 "myparser.cpp"
			}
		}
		break;
	case 125:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1341 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2845 "myparser.cpp"
			}
		}
		break;
	case 126:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1349 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1211 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2867 "myparser.cpp"
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
#line 1362 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1223 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2887 "myparser.cpp"
			}
		}
		break;
	case 128:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1370 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1230 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2907 "myparser.cpp"
			}
		}
		break;
	case 129:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1381 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1240 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2928 "myparser.cpp"
			}
		}
		break;
	case 130:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1390 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1248 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2948 "myparser.cpp"
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
#line 1401 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1258 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2968 "myparser.cpp"
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
#line 1409 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1265 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2990 "myparser.cpp"
			}
		}
		break;
	case 133:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1419 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1274 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 3013 "myparser.cpp"
			}
		}
		break;
	case 134:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1430 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1284 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3035 "myparser.cpp"
			}
		}
		break;
	case 135:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1440 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 3058 "myparser.cpp"
			}
		}
		break;
	case 136:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1451 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1303 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 3081 "myparser.cpp"
			}
		}
		break;
	case 137:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1462 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1313 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3103 "myparser.cpp"
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
#line 1475 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1325 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3123 "myparser.cpp"
			}
		}
		break;
	case 139:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1483 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3143 "myparser.cpp"
			}
		}
		break;
	case 140:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1491 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3163 "myparser.cpp"
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
#line 1499 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
	
#line 3183 "myparser.cpp"
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
#line 1510 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1359 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3203 "myparser.cpp"
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
#line 1518 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1366 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3224 "myparser.cpp"
			}
		}
		break;
	case 144:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1531 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1378 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3244 "myparser.cpp"
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
#line 1539 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1385 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3266 "myparser.cpp"
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
#line 1552 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1397 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3286 "myparser.cpp"
			}
		}
		break;
	case 147:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1560 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1404 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3308 "myparser.cpp"
			}
		}
		break;
	case 148:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1573 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1416 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3329 "myparser.cpp"
			}
		}
		break;
	case 149:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1582 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1424 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3349 "myparser.cpp"
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
#line 1590 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1431 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3369 "myparser.cpp"
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
#line 1601 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1441 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3389 "myparser.cpp"
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
#line 1609 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1448 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3411 "myparser.cpp"
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
#line 1622 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1460 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3431 "myparser.cpp"
			}
		}
		break;
	case 154:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1630 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1467 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3452 "myparser.cpp"
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
#line 1642 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1478 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3472 "myparser.cpp"
			}
		}
		break;
	case 156:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1650 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1485 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3492 "myparser.cpp"
			}
		}
		break;
	case 157:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1658 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1492 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3513 "myparser.cpp"
			}
		}
		break;
	case 158:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1670 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1503 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3535 "myparser.cpp"
			}
		}
		break;
	case 159:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1680 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1512 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3556 "myparser.cpp"
			}
		}
		break;
	case 160:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1689 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1520 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3578 "myparser.cpp"
			}
		}
		break;
	case 161:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1699 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1529 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3600 "myparser.cpp"
			}
		}
		break;
	case 162:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1709 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3623 "myparser.cpp"
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
#line 1720 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1548 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3644 "myparser.cpp"
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
#line 1729 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1556 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3666 "myparser.cpp"
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
#line 1739 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1565 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3688 "myparser.cpp"
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
#line 1749 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1574 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3711 "myparser.cpp"
			}
		}
		break;
	case 167:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1763 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1587 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3731 "myparser.cpp"
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
#line 1771 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1594 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3753 "myparser.cpp"
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
#line 1781 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1603 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3776 "myparser.cpp"
			}
		}
		break;
	case 170:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1795 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1616 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3796 "myparser.cpp"
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
#line 1803 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1623 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3818 "myparser.cpp"
			}
		}
		break;
	case 172:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1816 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3838 "myparser.cpp"
			}
		}
		break;
	case 173:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1824 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3858 "myparser.cpp"
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
#line 1832 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3878 "myparser.cpp"
			}
		}
		break;
	case 175:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1840 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1656 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3898 "myparser.cpp"
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
#line 1848 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3918 "myparser.cpp"
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
#line 1856 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3938 "myparser.cpp"
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
#line 1867 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1680 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3960 "myparser.cpp"
			}
		}
		break;
	case 179:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1877 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3983 "myparser.cpp"
			}
		}
		break;
	case 180:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1888 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1699 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4005 "myparser.cpp"
			}
		}
		break;
	case 181:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1901 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1711 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4026 "myparser.cpp"
			}
		}
		break;
	case 182:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1910 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1719 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4048 "myparser.cpp"
			}
		}
		break;
	case 183:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1920 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1728 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4070 "myparser.cpp"
			}
		}
		break;
	case 184:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1930 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1737 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4093 "myparser.cpp"
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
#line 1944 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1750 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4113 "myparser.cpp"
			}
		}
		break;
	case 186:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1952 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1757 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4134 "myparser.cpp"
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
#line 1964 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1768 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4154 "myparser.cpp"
			}
		}
		break;
	case 188:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1972 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1775 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4175 "myparser.cpp"
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
#line 1984 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1786 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4195 "myparser.cpp"
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
#line 1992 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1793 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4216 "myparser.cpp"
			}
		}
		break;
	case 191:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2003 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1803 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "if_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 5).ntnode;
	
#line 4240 "myparser.cpp"
			}
		}
		break;
	case 192:
		{
#line 2017 ".\\myparser.y"

		// $$ = new node();
		// $$ -> name = "if_else_statement";
	
#line 4251 "myparser.cpp"
		}
		break;
	case 193:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2021 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1810 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "if_else_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4271 "myparser.cpp"
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
#line 2032 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1816 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4292 "myparser.cpp"
			}
		}
		break;
	case 195:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2041 ".\\myparser.y"

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
	
#line 4316 "myparser.cpp"
			}
		}
		break;
	case 196:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2056 ".\\myparser.y"

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
	
#line 4340 "myparser.cpp"
			}
		}
		break;
	case 197:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2068 ".\\myparser.y"

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
	
#line 4366 "myparser.cpp"
			}
		}
		break;
	case 198:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 2082 ".\\myparser.y"

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
	
#line 4391 "myparser.cpp"
			}
		}
		break;
	case 199:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2095 ".\\myparser.y"

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
	
#line 4417 "myparser.cpp"
			}
		}
		break;
	case 200:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2112 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4439 "myparser.cpp"
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
#line 2122 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1900 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4460 "myparser.cpp"
			}
		}
		break;
	case 202:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2131 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4481 "myparser.cpp"
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
#line 2140 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1916 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4502 "myparser.cpp"
			}
		}
		break;
	case 204:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2149 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1924 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4524 "myparser.cpp"
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
#line 2162 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1946 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		cout<<endl;
		traverse((*(YYSTYPE YYFAR*)yyvalptr).ntnode);
	
#line 4546 "myparser.cpp"
			}
		}
		break;
	case 206:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2172 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1953 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		cout<<endl;
		traverse((*(YYSTYPE YYFAR*)yyvalptr).ntnode);
	
#line 4569 "myparser.cpp"
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
#line 2186 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4589 "myparser.cpp"
			}
		}
		break;
	case 208:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2194 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4609 "myparser.cpp"
			}
		}
		break;
	case 209:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2205 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1981 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4632 "myparser.cpp"
			}
		}
		break;
	case 210:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2216 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1991 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4654 "myparser.cpp"
			}
		}
		break;
	case 211:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2226 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2000 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4676 "myparser.cpp"
			}
		}
		break;
	case 212:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2236 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2009 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4697 "myparser.cpp"
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
		"primary_expression: ID",
		"primary_expression: CONSTANT",
		"primary_expression: STRING_LITERAL",
		"primary_expression: \'(\' expression \')\'",
		"postfix_expression: primary_expression",
		"postfix_expression: postfix_expression \'[\' expression \']\'",
		"postfix_expression: postfix_expression \'(\' \')\'",
		"postfix_expression: postfix_expression \'(\' argument_expression_list \')\'",
		"postfix_expression: postfix_expression \'.\' ID",
		"postfix_expression: postfix_expression PTR_OP ID",
		"postfix_expression: postfix_expression INC_OP",
		"postfix_expression: postfix_expression DEC_OP",
		"argument_expression_list: assignment_expression",
		"argument_expression_list: argument_expression_list \',\' assignment_expression",
		"unary_expression: postfix_expression",
		"unary_expression: INC_OP unary_expression",
		"unary_expression: DEC_OP unary_expression",
		"unary_expression: unary_operator cast_expression",
		"unary_expression: SIZEOF unary_expression",
		"unary_expression: SIZEOF \'(\' type_name \')\'",
		"unary_operator: \'&\'",
		"unary_operator: \'*\'",
		"unary_operator: \'+\'",
		"unary_operator: \'-\'",
		"unary_operator: \'~\'",
		"unary_operator: \'!\'",
		"cast_expression: unary_expression",
		"cast_expression: \'(\' type_name \')\' cast_expression",
		"multiplicative_expression: cast_expression",
		"multiplicative_expression: multiplicative_expression \'*\' cast_expression",
		"multiplicative_expression: multiplicative_expression \'/\' cast_expression",
		"multiplicative_expression: multiplicative_expression \'%\' cast_expression",
		"additive_expression: multiplicative_expression",
		"additive_expression: additive_expression \'+\' multiplicative_expression",
		"additive_expression: additive_expression \'-\' multiplicative_expression",
		"shift_expression: additive_expression",
		"shift_expression: shift_expression LEFT_OP additive_expression",
		"shift_expression: shift_expression RIGHT_OP additive_expression",
		"relational_expression: shift_expression",
		"relational_expression: relational_expression \'<\' shift_expression",
		"relational_expression: relational_expression \'>\' shift_expression",
		"relational_expression: relational_expression LE_OP shift_expression",
		"relational_expression: relational_expression GE_OP shift_expression",
		"equality_expression: relational_expression",
		"equality_expression: equality_expression EQ_OP relational_expression",
		"equality_expression: equality_expression NE_OP relational_expression",
		"and_expression: equality_expression",
		"and_expression: and_expression \'&\' equality_expression",
		"exclusive_or_expression: and_expression",
		"exclusive_or_expression: exclusive_or_expression \'^\' and_expression",
		"inclusive_or_expression: exclusive_or_expression",
		"inclusive_or_expression: inclusive_or_expression \'|\' exclusive_or_expression",
		"logical_and_expression: inclusive_or_expression",
		"logical_and_expression: logical_and_expression AND_OP inclusive_or_expression",
		"logical_or_expression: logical_and_expression",
		"logical_or_expression: logical_or_expression OR_OP logical_and_expression",
		"conditional_expression: logical_or_expression",
		"conditional_expression: logical_or_expression \'\?\' expression \':\' conditional_expression",
		"assignment_expression: conditional_expression",
		"assignment_expression: unary_expression assignment_operator assignment_expression",
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
		"expression: assignment_expression",
		"expression: expression \',\' assignment_expression",
		"constant_expression: conditional_expression",
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
		"struct_or_union_specifier: struct_or_union ID \'{\' struct_declaration_list \'}\'",
		"struct_or_union_specifier: struct_or_union \'{\' struct_declaration_list \'}\'",
		"struct_or_union_specifier: struct_or_union ID",
		"struct_or_union: STRUCT",
		"struct_or_union: UNION",
		"struct_declaration_list: struct_declaration",
		"struct_declaration_list: struct_declaration_list struct_declaration",
		"struct_declaration: specifier_qualifier_list struct_declarator_list \';\'",
		"specifier_qualifier_list: type_specifier specifier_qualifier_list",
		"specifier_qualifier_list: type_specifier",
		"specifier_qualifier_list: type_qualifier specifier_qualifier_list",
		"specifier_qualifier_list: type_qualifier",
		"struct_declarator_list: struct_declarator",
		"struct_declarator_list: struct_declarator_list \',\' struct_declarator",
		"struct_declarator: declarator",
		"struct_declarator: \':\' constant_expression",
		"struct_declarator: declarator \':\' constant_expression",
		"enum_specifier: ENUM \'{\' enumerator_list \'}\'",
		"enum_specifier: ENUM ID \'{\' enumerator_list \'}\'",
		"enum_specifier: ENUM ID",
		"enumerator_list: enumerator",
		"enumerator_list: enumerator_list \',\' enumerator",
		"enumerator: ID",
		"enumerator: ID \'=\' constant_expression",
		"type_qualifier: CONST",
		"type_qualifier: VOLATILE",
		"declarator: pointer direct_declarator",
		"declarator: direct_declarator",
		"direct_declarator: ID",
		"direct_declarator: \'(\' declarator \')\'",
		"direct_declarator: direct_declarator \'[\' constant_expression \']\'",
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
		"direct_abstract_declarator: \'[\' constant_expression \']\'",
		"direct_abstract_declarator: direct_abstract_declarator \'[\' \']\'",
		"direct_abstract_declarator: direct_abstract_declarator \'[\' constant_expression \']\'",
		"direct_abstract_declarator: \'(\' \')\'",
		"direct_abstract_declarator: \'(\' parameter_type_list \')\'",
		"direct_abstract_declarator: direct_abstract_declarator \'(\' \')\'",
		"direct_abstract_declarator: direct_abstract_declarator \'(\' parameter_type_list \')\'",
		"initializer: assignment_expression",
		"initializer: \'{\' initializer_list \'}\'",
		"initializer: \'{\' initializer_list \',\' \'}\'",
		"initializer_list: initializer",
		"initializer_list: initializer_list \',\' initializer",
		"statement: labeled_statement",
		"statement: compound_statement",
		"statement: expression_statement",
		"statement: selection_statement",
		"statement: iteration_statement",
		"statement: jump_statement",
		"labeled_statement: ID \':\' statement",
		"labeled_statement: CASE constant_expression \':\' statement",
		"labeled_statement: DEFAULT \':\' statement",
		"compound_statement: \'{\' \'}\'",
		"compound_statement: \'{\' statement_list \'}\'",
		"compound_statement: \'{\' declaration_list \'}\'",
		"compound_statement: \'{\' declaration_list statement_list \'}\'",
		"declaration_list: declaration",
		"declaration_list: declaration_list declaration",
		"statement_list: statement",
		"statement_list: statement_list statement",
		"expression_statement: \';\'",
		"expression_statement: expression \';\'",
		"if_statement: IF \'(\' expression \')\' statement",
		"if_else_statement:",
		"if_else_statement: ELSE statement",
		"selection_statement: if_statement if_else_statement",
		"selection_statement: SWITCH \'(\' expression \')\' statement",
		"iteration_statement: WHILE \'(\' expression \')\' statement",
		"iteration_statement: DO statement WHILE \'(\' expression \')\' \';\'",
		"iteration_statement: FOR \'(\' expression_statement expression_statement \')\' statement",
		"iteration_statement: FOR \'(\' expression_statement expression_statement expression \')\' statement",
		"jump_statement: GOTO ID \';\'",
		"jump_statement: CONTINUE \';\'",
		"jump_statement: BREAK \';\'",
		"jump_statement: RETURN \';\'",
		"jump_statement: RETURN expression \';\'",
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
		{ 28, 5, 103 },
		{ 28, 4, 104 },
		{ 28, 2, 105 },
		{ 29, 1, 106 },
		{ 29, 1, 107 },
		{ 30, 1, 108 },
		{ 30, 2, 109 },
		{ 31, 3, 110 },
		{ 32, 2, 111 },
		{ 32, 1, 112 },
		{ 32, 2, 113 },
		{ 32, 1, 114 },
		{ 33, 1, 115 },
		{ 33, 3, 116 },
		{ 34, 1, 117 },
		{ 34, 2, 118 },
		{ 34, 3, 119 },
		{ 35, 4, 120 },
		{ 35, 5, 121 },
		{ 35, 2, 122 },
		{ 36, 1, 123 },
		{ 36, 3, 124 },
		{ 37, 1, 125 },
		{ 37, 3, 126 },
		{ 38, 1, 127 },
		{ 38, 1, 128 },
		{ 39, 2, 129 },
		{ 39, 1, 130 },
		{ 40, 1, 131 },
		{ 40, 3, 132 },
		{ 40, 4, 133 },
		{ 40, 3, 134 },
		{ 40, 4, 135 },
		{ 40, 4, 136 },
		{ 40, 3, 137 },
		{ 41, 1, 138 },
		{ 41, 2, 139 },
		{ 41, 2, 140 },
		{ 41, 3, 141 },
		{ 42, 1, 142 },
		{ 42, 2, 143 },
		{ 43, 1, 144 },
		{ 43, 3, 145 },
		{ 44, 1, 146 },
		{ 44, 3, 147 },
		{ 45, 2, 148 },
		{ 45, 2, 149 },
		{ 45, 1, 150 },
		{ 46, 1, 151 },
		{ 46, 3, 152 },
		{ 47, 1, 153 },
		{ 47, 2, 154 },
		{ 48, 1, 155 },
		{ 48, 1, 156 },
		{ 48, 2, 157 },
		{ 49, 3, 158 },
		{ 49, 2, 159 },
		{ 49, 3, 160 },
		{ 49, 3, 161 },
		{ 49, 4, 162 },
		{ 49, 2, 163 },
		{ 49, 3, 164 },
		{ 49, 3, 165 },
		{ 49, 4, 166 },
		{ 50, 1, 167 },
		{ 50, 3, 168 },
		{ 50, 4, 169 },
		{ 51, 1, 170 },
		{ 51, 3, 171 },
		{ 52, 1, 172 },
		{ 52, 1, 173 },
		{ 52, 1, 174 },
		{ 52, 1, 175 },
		{ 52, 1, 176 },
		{ 52, 1, 177 },
		{ 53, 3, 178 },
		{ 53, 4, 179 },
		{ 53, 3, 180 },
		{ 54, 2, 181 },
		{ 54, 3, 182 },
		{ 54, 3, 183 },
		{ 54, 4, 184 },
		{ 55, 1, 185 },
		{ 55, 2, 186 },
		{ 56, 1, 187 },
		{ 56, 2, 188 },
		{ 57, 1, 189 },
		{ 57, 2, 190 },
		{ 58, 5, 191 },
		{ 59, 0, 192 },
		{ 59, 2, 193 },
		{ 60, 2, 194 },
		{ 60, 5, 195 },
		{ 61, 5, 196 },
		{ 61, 7, 197 },
		{ 61, 6, 198 },
		{ 61, 7, 199 },
		{ 62, 3, 200 },
		{ 62, 2, 201 },
		{ 62, 2, 202 },
		{ 62, 2, 203 },
		{ 62, 3, 204 },
		{ 63, 1, 205 },
		{ 63, 2, 206 },
		{ 64, 1, 207 },
		{ 64, 1, 208 },
		{ 65, 4, 209 },
		{ 65, 3, 210 },
		{ 65, 3, 211 },
		{ 65, 2, 212 }
	};
	yyreduction = reduction;

	yytokenaction_size = 401;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 55, YYAT_SHIFT, 132 },
		{ 306, YYAT_SHIFT, 330 },
		{ 348, YYAT_SHIFT, 48 },
		{ 249, YYAT_SHIFT, 1 },
		{ 133, YYAT_ERROR, 0 },
		{ 249, YYAT_SHIFT, 2 },
		{ 35, YYAT_ACCEPT, 0 },
		{ 346, YYAT_SHIFT, 349 },
		{ 282, YYAT_SHIFT, 202 },
		{ 26, YYAT_SHIFT, 44 },
		{ 282, YYAT_SHIFT, 203 },
		{ 281, YYAT_SHIFT, 202 },
		{ 23, YYAT_SHIFT, 42 },
		{ 281, YYAT_SHIFT, 203 },
		{ 275, YYAT_SHIFT, 183 },
		{ 241, YYAT_ERROR, 0 },
		{ 275, YYAT_SHIFT, 184 },
		{ 299, YYAT_SHIFT, 325 },
		{ 152, YYAT_SHIFT, 150 },
		{ 305, YYAT_SHIFT, 306 },
		{ 161, YYAT_ERROR, 0 },
		{ 249, YYAT_SHIFT, 153 },
		{ 34, YYAT_SHIFT, 4 },
		{ 34, YYAT_SHIFT, 5 },
		{ 34, YYAT_SHIFT, 6 },
		{ 34, YYAT_SHIFT, 7 },
		{ 34, YYAT_SHIFT, 8 },
		{ 34, YYAT_SHIFT, 9 },
		{ 34, YYAT_SHIFT, 10 },
		{ 34, YYAT_SHIFT, 11 },
		{ 34, YYAT_SHIFT, 12 },
		{ 34, YYAT_SHIFT, 13 },
		{ 34, YYAT_SHIFT, 14 },
		{ 34, YYAT_SHIFT, 15 },
		{ 34, YYAT_SHIFT, 16 },
		{ 34, YYAT_SHIFT, 17 },
		{ 34, YYAT_SHIFT, 18 },
		{ 34, YYAT_SHIFT, 19 },
		{ 34, YYAT_SHIFT, 20 },
		{ 34, YYAT_SHIFT, 21 },
		{ 34, YYAT_SHIFT, 22 },
		{ 34, YYAT_SHIFT, 23 },
		{ 162, YYAT_SHIFT, 253 },
		{ 123, YYAT_SHIFT, 81 },
		{ 162, YYAT_SHIFT, 2 },
		{ 254, YYAT_SHIFT, 253 },
		{ 35, YYAT_SHIFT, 1 },
		{ 35, YYAT_ERROR, 0 },
		{ 325, YYAT_SHIFT, 75 },
		{ 337, YYAT_SHIFT, 346 },
		{ 253, YYAT_SHIFT, 253 },
		{ 253, YYAT_SHIFT, 300 },
		{ 253, YYAT_SHIFT, 2 },
		{ 325, YYAT_SHIFT, 76 },
		{ 239, YYAT_SHIFT, 306 },
		{ 325, YYAT_SHIFT, 77 },
		{ 166, YYAT_SHIFT, 75 },
		{ 325, YYAT_SHIFT, 78 },
		{ 325, YYAT_SHIFT, 79 },
		{ 41, YYAT_SHIFT, 2 },
		{ 325, YYAT_SHIFT, 80 },
		{ 166, YYAT_SHIFT, 76 },
		{ 55, YYAT_SHIFT, 48 },
		{ 166, YYAT_SHIFT, 77 },
		{ 2, YYAT_SHIFT, 2 },
		{ 166, YYAT_SHIFT, 78 },
		{ 166, YYAT_SHIFT, 79 },
		{ 139, YYAT_SHIFT, 234 },
		{ 166, YYAT_SHIFT, 80 },
		{ 139, YYAT_SHIFT, 2 },
		{ 305, YYAT_SHIFT, 307 },
		{ 116, YYAT_SHIFT, 219 },
		{ 59, YYAT_SHIFT, 57 },
		{ 237, YYAT_SHIFT, 234 },
		{ 31, YYAT_SHIFT, 57 },
		{ 182, YYAT_SHIFT, 221 },
		{ 155, YYAT_SHIFT, 249 },
		{ 287, YYAT_SHIFT, 221 },
		{ 339, YYAT_SHIFT, 348 },
		{ 284, YYAT_SHIFT, 321 },
		{ 143, YYAT_SHIFT, 242 },
		{ 339, YYAT_SHIFT, 221 },
		{ 284, YYAT_SHIFT, 322 },
		{ 143, YYAT_SHIFT, 243 },
		{ 289, YYAT_SHIFT, 206 },
		{ 289, YYAT_SHIFT, 207 },
		{ 133, YYAT_SHIFT, 48 },
		{ 56, YYAT_SHIFT, 135 },
		{ 105, YYAT_SHIFT, 190 },
		{ 293, YYAT_SHIFT, 221 },
		{ 182, YYAT_SHIFT, 268 },
		{ 155, YYAT_SHIFT, 250 },
		{ 234, YYAT_SHIFT, 234 },
		{ 162, YYAT_SHIFT, 235 },
		{ 110, YYAT_SHIFT, 209 },
		{ 57, YYAT_SHIFT, 137 },
		{ 254, YYAT_SHIFT, 235 },
		{ 35, YYAT_ERROR, 0 },
		{ 299, YYAT_SHIFT, 326 },
		{ 152, YYAT_SHIFT, 247 },
		{ 110, YYAT_SHIFT, 210 },
		{ 253, YYAT_SHIFT, 235 },
		{ 56, YYAT_SHIFT, 136 },
		{ 293, YYAT_SHIFT, 324 },
		{ 161, YYAT_SHIFT, 252 },
		{ 239, YYAT_SHIFT, 307 },
		{ 274, YYAT_SHIFT, 183 },
		{ 123, YYAT_SHIFT, 48 },
		{ 274, YYAT_SHIFT, 184 },
		{ 123, YYAT_SHIFT, 223 },
		{ 270, YYAT_SHIFT, 185 },
		{ 101, YYAT_SHIFT, 183 },
		{ 269, YYAT_SHIFT, 185 },
		{ 101, YYAT_SHIFT, 184 },
		{ 107, YYAT_SHIFT, 202 },
		{ 270, YYAT_SHIFT, 186 },
		{ 107, YYAT_SHIFT, 203 },
		{ 269, YYAT_SHIFT, 186 },
		{ 139, YYAT_SHIFT, 235 },
		{ 333, YYAT_SHIFT, 345 },
		{ 270, YYAT_SHIFT, 187 },
		{ 331, YYAT_SHIFT, 344 },
		{ 269, YYAT_SHIFT, 187 },
		{ 59, YYAT_SHIFT, 58 },
		{ 237, YYAT_SHIFT, 235 },
		{ 31, YYAT_SHIFT, 58 },
		{ 287, YYAT_SHIFT, 323 },
		{ 103, YYAT_SHIFT, 185 },
		{ 280, YYAT_SHIFT, 188 },
		{ 280, YYAT_SHIFT, 189 },
		{ 279, YYAT_SHIFT, 188 },
		{ 279, YYAT_SHIFT, 189 },
		{ 103, YYAT_SHIFT, 186 },
		{ 278, YYAT_SHIFT, 188 },
		{ 278, YYAT_SHIFT, 189 },
		{ 324, YYAT_ERROR, 0 },
		{ 348, YYAT_SHIFT, 84 },
		{ 103, YYAT_SHIFT, 187 },
		{ 325, YYAT_SHIFT, 229 },
		{ 320, YYAT_SHIFT, 338 },
		{ 325, YYAT_SHIFT, 342 },
		{ 325, YYAT_SHIFT, 83 },
		{ 307, YYAT_SHIFT, 332 },
		{ 26, YYAT_SHIFT, 45 },
		{ 304, YYAT_SHIFT, 329 },
		{ 110, YYAT_SHIFT, 211 },
		{ 23, YYAT_SHIFT, 43 },
		{ 277, YYAT_SHIFT, 188 },
		{ 277, YYAT_SHIFT, 189 },
		{ 166, YYAT_SHIFT, 83 },
		{ 28, YYAT_SHIFT, 4 },
		{ 28, YYAT_SHIFT, 5 },
		{ 28, YYAT_SHIFT, 6 },
		{ 28, YYAT_SHIFT, 7 },
		{ 28, YYAT_SHIFT, 8 },
		{ 28, YYAT_SHIFT, 9 },
		{ 28, YYAT_SHIFT, 10 },
		{ 28, YYAT_SHIFT, 11 },
		{ 28, YYAT_SHIFT, 12 },
		{ 28, YYAT_SHIFT, 13 },
		{ 28, YYAT_SHIFT, 14 },
		{ 28, YYAT_SHIFT, 15 },
		{ 28, YYAT_SHIFT, 16 },
		{ 28, YYAT_SHIFT, 17 },
		{ 28, YYAT_SHIFT, 18 },
		{ 28, YYAT_SHIFT, 19 },
		{ 28, YYAT_SHIFT, 20 },
		{ 28, YYAT_SHIFT, 21 },
		{ 28, YYAT_SHIFT, 22 },
		{ 28, YYAT_SHIFT, 23 },
		{ 108, YYAT_SHIFT, 206 },
		{ 108, YYAT_SHIFT, 207 },
		{ 104, YYAT_SHIFT, 188 },
		{ 104, YYAT_SHIFT, 189 },
		{ 302, YYAT_SHIFT, 328 },
		{ 301, YYAT_SHIFT, 327 },
		{ 294, YYAT_SHIFT, 216 },
		{ 292, YYAT_SHIFT, 217 },
		{ 291, YYAT_SHIFT, 215 },
		{ 290, YYAT_SHIFT, 218 },
		{ 266, YYAT_SHIFT, 81 },
		{ 265, YYAT_SHIFT, 319 },
		{ 348, YYAT_SHIFT, 90 },
		{ 348, YYAT_SHIFT, 91 },
		{ 348, YYAT_SHIFT, 92 },
		{ 264, YYAT_SHIFT, 318 },
		{ 348, YYAT_SHIFT, 93 },
		{ 348, YYAT_SHIFT, 94 },
		{ 348, YYAT_SHIFT, 95 },
		{ 348, YYAT_SHIFT, 96 },
		{ 348, YYAT_SHIFT, 97 },
		{ 348, YYAT_SHIFT, 98 },
		{ 348, YYAT_SHIFT, 99 },
		{ 348, YYAT_SHIFT, 100 },
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
		{ 282, YYAT_SHIFT, 204 },
		{ 282, YYAT_SHIFT, 205 },
		{ 263, YYAT_SHIFT, 317 },
		{ 281, YYAT_SHIFT, 204 },
		{ 281, YYAT_SHIFT, 205 },
		{ 262, YYAT_SHIFT, 316 },
		{ 249, YYAT_SHIFT, 3 },
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
		{ 123, YYAT_SHIFT, 84 },
		{ 306, YYAT_SHIFT, 4 },
		{ 306, YYAT_SHIFT, 5 },
		{ 306, YYAT_SHIFT, 6 },
		{ 306, YYAT_SHIFT, 7 },
		{ 306, YYAT_SHIFT, 8 },
		{ 306, YYAT_SHIFT, 9 },
		{ 306, YYAT_SHIFT, 10 },
		{ 306, YYAT_SHIFT, 11 },
		{ 306, YYAT_SHIFT, 12 },
		{ 306, YYAT_SHIFT, 13 },
		{ 306, YYAT_SHIFT, 14 },
		{ 306, YYAT_SHIFT, 15 },
		{ 306, YYAT_SHIFT, 16 },
		{ 306, YYAT_SHIFT, 17 },
		{ 306, YYAT_SHIFT, 18 },
		{ 306, YYAT_SHIFT, 19 },
		{ 306, YYAT_SHIFT, 20 },
		{ 306, YYAT_SHIFT, 21 },
		{ 306, YYAT_SHIFT, 22 },
		{ 306, YYAT_SHIFT, 23 },
		{ 161, YYAT_ERROR, 0 },
		{ 161, YYAT_ERROR, 0 },
		{ 161, YYAT_ERROR, 0 },
		{ 161, YYAT_ERROR, 0 },
		{ 161, YYAT_ERROR, 0 },
		{ 123, YYAT_SHIFT, 5 },
		{ 123, YYAT_SHIFT, 6 },
		{ 123, YYAT_SHIFT, 7 },
		{ 123, YYAT_SHIFT, 8 },
		{ 123, YYAT_SHIFT, 9 },
		{ 325, YYAT_SHIFT, 145 },
		{ 325, YYAT_SHIFT, 85 },
		{ 325, YYAT_SHIFT, 86 },
		{ 325, YYAT_SHIFT, 87 },
		{ 241, YYAT_SHIFT, 308 },
		{ 325, YYAT_SHIFT, 88 },
		{ 325, YYAT_SHIFT, 89 },
		{ 116, YYAT_SHIFT, 220 },
		{ 166, YYAT_SHIFT, 145 },
		{ 166, YYAT_SHIFT, 85 },
		{ 166, YYAT_SHIFT, 86 },
		{ 166, YYAT_SHIFT, 87 },
		{ 139, YYAT_SHIFT, 3 },
		{ 166, YYAT_SHIFT, 88 },
		{ 166, YYAT_SHIFT, 89 },
		{ 123, YYAT_SHIFT, 90 },
		{ 123, YYAT_SHIFT, 91 },
		{ 123, YYAT_SHIFT, 92 },
		{ 237, YYAT_SHIFT, 3 },
		{ 123, YYAT_SHIFT, 93 },
		{ 123, YYAT_SHIFT, 94 },
		{ 123, YYAT_SHIFT, 95 },
		{ 123, YYAT_SHIFT, 96 },
		{ 123, YYAT_SHIFT, 97 },
		{ 123, YYAT_SHIFT, 98 },
		{ 123, YYAT_SHIFT, 99 },
		{ 123, YYAT_SHIFT, 100 },
		{ 105, YYAT_SHIFT, 191 },
		{ 105, YYAT_SHIFT, 192 },
		{ 105, YYAT_SHIFT, 193 },
		{ 105, YYAT_SHIFT, 194 },
		{ 105, YYAT_SHIFT, 195 },
		{ 105, YYAT_SHIFT, 196 },
		{ 105, YYAT_SHIFT, 197 },
		{ 105, YYAT_SHIFT, 198 },
		{ 105, YYAT_SHIFT, 199 },
		{ 105, YYAT_SHIFT, 200 },
		{ 234, YYAT_SHIFT, 3 },
		{ 259, YYAT_SHIFT, 314 },
		{ 57, YYAT_SHIFT, 138 },
		{ 243, YYAT_SHIFT, 310 },
		{ 41, YYAT_SHIFT, 18 },
		{ 41, YYAT_SHIFT, 19 },
		{ 110, YYAT_SHIFT, 212 },
		{ 110, YYAT_SHIFT, 213 },
		{ 110, YYAT_SHIFT, 214 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 107, YYAT_SHIFT, 204 },
		{ 107, YYAT_SHIFT, 205 },
		{ 72, YYAT_SHIFT, 4 },
		{ 235, YYAT_SHIFT, 303 },
		{ 229, YYAT_ERROR, 0 },
		{ 224, YYAT_SHIFT, 296 },
		{ 212, YYAT_SHIFT, 288 },
		{ 210, YYAT_SHIFT, 286 },
		{ 72, YYAT_SHIFT, 10 },
		{ 72, YYAT_SHIFT, 11 },
		{ 72, YYAT_SHIFT, 12 },
		{ 72, YYAT_SHIFT, 13 },
		{ 72, YYAT_SHIFT, 14 },
		{ 72, YYAT_SHIFT, 15 },
		{ 72, YYAT_SHIFT, 16 },
		{ 72, YYAT_SHIFT, 17 },
		{ 72, YYAT_SHIFT, 18 },
		{ 72, YYAT_SHIFT, 19 },
		{ 72, YYAT_SHIFT, 20 },
		{ 72, YYAT_SHIFT, 21 },
		{ 72, YYAT_SHIFT, 22 },
		{ 72, YYAT_SHIFT, 23 },
		{ 71, YYAT_SHIFT, 4 },
		{ 209, YYAT_SHIFT, 283 },
		{ 178, YYAT_SHIFT, 267 },
		{ 176, YYAT_SHIFT, 265 },
		{ 171, YYAT_SHIFT, 260 },
		{ 164, YYAT_SHIFT, 257 },
		{ 71, YYAT_SHIFT, 10 },
		{ 71, YYAT_SHIFT, 11 },
		{ 71, YYAT_SHIFT, 12 },
		{ 71, YYAT_SHIFT, 13 },
		{ 71, YYAT_SHIFT, 14 },
		{ 71, YYAT_SHIFT, 15 },
		{ 71, YYAT_SHIFT, 16 },
		{ 71, YYAT_SHIFT, 17 },
		{ 71, YYAT_SHIFT, 18 },
		{ 71, YYAT_SHIFT, 19 },
		{ 71, YYAT_SHIFT, 20 },
		{ 71, YYAT_SHIFT, 21 },
		{ 71, YYAT_SHIFT, 22 },
		{ 71, YYAT_SHIFT, 23 },
		{ 163, YYAT_SHIFT, 256 },
		{ 156, YYAT_SHIFT, 251 },
		{ 150, YYAT_SHIFT, 65 },
		{ 147, YYAT_SHIFT, 244 },
		{ 141, YYAT_SHIFT, 241 },
		{ 140, YYAT_SHIFT, 240 },
		{ 135, YYAT_ERROR, 0 },
		{ 129, YYAT_SHIFT, 132 },
		{ 127, YYAT_SHIFT, 227 },
		{ 125, YYAT_SHIFT, 225 },
		{ 118, YYAT_SHIFT, 222 },
		{ 114, YYAT_SHIFT, 218 },
		{ 113, YYAT_SHIFT, 217 },
		{ 112, YYAT_SHIFT, 216 },
		{ 111, YYAT_SHIFT, 215 },
		{ 100, YYAT_SHIFT, 181 },
		{ 99, YYAT_SHIFT, 180 },
		{ 98, YYAT_SHIFT, 179 },
		{ 97, YYAT_SHIFT, 178 },
		{ 96, YYAT_SHIFT, 177 },
		{ 94, YYAT_SHIFT, 175 },
		{ 93, YYAT_SHIFT, 174 },
		{ 92, YYAT_SHIFT, 173 },
		{ 91, YYAT_SHIFT, 172 },
		{ 89, YYAT_SHIFT, 168 },
		{ 87, YYAT_SHIFT, 166 },
		{ 84, YYAT_SHIFT, 165 },
		{ 74, YYAT_ERROR, 0 },
		{ 70, YYAT_SHIFT, 157 },
		{ 66, YYAT_SHIFT, 151 },
		{ 65, YYAT_SHIFT, 149 },
		{ 58, YYAT_SHIFT, 144 },
		{ 50, YYAT_SHIFT, 53 },
		{ 48, YYAT_SHIFT, 82 },
		{ 45, YYAT_SHIFT, 74 },
		{ 43, YYAT_SHIFT, 68 },
		{ 38, YYAT_SHIFT, 62 },
		{ 32, YYAT_ERROR, 0 },
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 400, 1, YYAT_DEFAULT, 35 },
		{ 0, 0, YYAT_DEFAULT, 135 },
		{ 22, 1, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 132 },
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
		{ 0, 0, YYAT_REDUCE, 128 },
		{ 0, 0, YYAT_REDUCE, 129 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ -111, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ -114, 1, YYAT_ERROR, 0 },
		{ -88, 1, YYAT_REDUCE, 77 },
		{ -132, 1, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 50 },
		{ 34, 1, YYAT_REDUCE, 131 },
		{ 357, 1, YYAT_DEFAULT, 135 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ -260, 1, YYAT_REDUCE, 79 },
		{ 6, 1, YYAT_DEFAULT, 234 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 357, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 143 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ 17, 1, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ 274, 1, YYAT_REDUCE, 123 },
		{ 0, 0, YYAT_DEFAULT, 74 },
		{ 273, 1, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 270, 1, YYAT_DEFAULT, 123 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 335, 1, YYAT_DEFAULT, 135 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ -61, 1, YYAT_REDUCE, 85 },
		{ 43, 1, YYAT_ERROR, 0 },
		{ 54, 1, YYAT_DEFAULT, 306 },
		{ 300, 1, YYAT_DEFAULT, 324 },
		{ 32, 1, YYAT_REDUCE, 130 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 331, 1, YYAT_REDUCE, 126 },
		{ 266, 1, YYAT_DEFAULT, 152 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ 0, 0, YYAT_DEFAULT, 249 },
		{ 265, 1, YYAT_DEFAULT, 161 },
		{ 60, 1, YYAT_REDUCE, 115 },
		{ 40, 1, YYAT_REDUCE, 113 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 264, 1, YYAT_DEFAULT, 161 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 330, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 347, 1, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 89 },
		{ 346, 1, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 327, 1, YYAT_ERROR, 0 },
		{ 344, 1, YYAT_ERROR, 0 },
		{ 343, 1, YYAT_ERROR, 0 },
		{ 342, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 341, 1, YYAT_ERROR, 0 },
		{ 123, 1, YYAT_ERROR, 0 },
		{ 320, 1, YYAT_ERROR, 0 },
		{ 319, 1, YYAT_ERROR, 0 },
		{ 318, 1, YYAT_DEFAULT, 324 },
		{ 68, 1, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 90, 1, YYAT_REDUCE, 33 },
		{ -92, 1, YYAT_REDUCE, 39 },
		{ 27, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 54, 1, YYAT_REDUCE, 44 },
		{ -98, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 54, 1, YYAT_REDUCE, 15 },
		{ 338, 1, YYAT_REDUCE, 49 },
		{ 105, 1, YYAT_REDUCE, 55 },
		{ 280, 1, YYAT_REDUCE, 51 },
		{ 249, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 8, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 313, 1, YYAT_DEFAULT, 182 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ -16, 1, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 246, 1, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 64, 1, YYAT_REDUCE, 193 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 308, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_DEFAULT, 229 },
		{ -37, 1, YYAT_DEFAULT, 306 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 310, 1, YYAT_DEFAULT, 249 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 27, 1, YYAT_REDUCE, 151 },
		{ 326, 1, YYAT_ERROR, 0 },
		{ 322, 1, YYAT_REDUCE, 145 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 39, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 272, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 107, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 121 },
		{ -26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 32, 1, YYAT_ERROR, 0 },
		{ 305, 1, YYAT_REDUCE, 118 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ -21, 1, YYAT_DEFAULT, 306 },
		{ 2, 1, YYAT_REDUCE, 154 },
		{ 321, 1, YYAT_DEFAULT, 339 },
		{ 306, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 23, 1, YYAT_DEFAULT, 74 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 288, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 266 },
		{ 285, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 31, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
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
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 302, 1, YYAT_DEFAULT, 324 },
		{ 70, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 69, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ 200, 1, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 199, 1, YYAT_DEFAULT, 325 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 52, 1, YYAT_DEFAULT, 253 },
		{ 230, 1, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ 33, 1, YYAT_REDUCE, 156 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ 14, 1, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 136 },
		{ -26, 1, YYAT_DEFAULT, 306 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 55, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 0, 0, YYAT_REDUCE, 127 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 0, 0, YYAT_REDUCE, 119 },
		{ -37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 10, 1, YYAT_DEFAULT, 306 },
		{ 5, 1, YYAT_REDUCE, 156 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 269, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 178, 1, YYAT_DEFAULT, 339 },
		{ 175, 1, YYAT_DEFAULT, 339 },
		{ 144, 1, YYAT_DEFAULT, 339 },
		{ 141, 1, YYAT_ERROR, 0 },
		{ 121, 1, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 75, 1, YYAT_REDUCE, 34 },
		{ 73, 1, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 63, 1, YYAT_REDUCE, 37 },
		{ -29, 1, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ -117, 1, YYAT_REDUCE, 40 },
		{ -131, 1, YYAT_REDUCE, 41 },
		{ -134, 1, YYAT_REDUCE, 42 },
		{ -136, 1, YYAT_REDUCE, 43 },
		{ -49, 1, YYAT_REDUCE, 45 },
		{ -52, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 33, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -184, 1, YYAT_REDUCE, 48 },
		{ 55, 1, YYAT_REDUCE, 54 },
		{ 140, 1, YYAT_REDUCE, 50 },
		{ 83, 1, YYAT_REDUCE, 52 },
		{ 45, 1, YYAT_ERROR, 0 },
		{ -94, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 134, 1, YYAT_ERROR, 0 },
		{ 133, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ 51, 1, YYAT_ERROR, 0 },
		{ -21, 1, YYAT_REDUCE, 158 },
		{ -40, 1, YYAT_ERROR, 0 },
		{ 49, 1, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 0, 0, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_REDUCE, 120 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 98, 1, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 324 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 12, 1, YYAT_DEFAULT, 229 },
		{ 15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 165 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 161 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ 80, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 162 },
		{ 26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 8, 1, YYAT_DEFAULT, 339 },
		{ 0, 0, YYAT_DEFAULT, 348 },
		{ 37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ -52, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ -121, 1, YYAT_DEFAULT, 266 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 200 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 227;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 348, 102 },
		{ 348, 110 },
		{ 55, 49 },
		{ 348, 105 },
		{ 348, 109 },
		{ 348, 106 },
		{ 348, 103 },
		{ 348, 101 },
		{ 348, 104 },
		{ 348, 107 },
		{ 348, 108 },
		{ 348, 111 },
		{ 348, 113 },
		{ 348, 114 },
		{ 348, 112 },
		{ 348, 116 },
		{ 348, 115 },
		{ 348, 117 },
		{ 266, 118 },
		{ 348, 118 },
		{ 123, 130 },
		{ 123, 50 },
		{ 209, 284 },
		{ 338, 347 },
		{ 123, 27 },
		{ 123, 34 },
		{ 123, 25 },
		{ 123, 26 },
		{ 324, 146 },
		{ 319, 337 },
		{ 325, 230 },
		{ 322, 340 },
		{ 325, -1 },
		{ 123, 33 },
		{ 55, 134 },
		{ 55, 133 },
		{ 123, 28 },
		{ 209, 285 },
		{ 166, 72 },
		{ 166, 25 },
		{ 166, 26 },
		{ 324, 341 },
		{ 324, -1 },
		{ 166, 162 },
		{ 133, 130 },
		{ 133, 50 },
		{ 166, 33 },
		{ 229, 298 },
		{ 229, 299 },
		{ 166, 71 },
		{ 123, 119 },
		{ 348, 350 },
		{ 348, 122 },
		{ 348, 126 },
		{ 123, 224 },
		{ 266, 320 },
		{ 348, 120 },
		{ 348, 127 },
		{ 166, 259 },
		{ 348, 128 },
		{ 348, 121 },
		{ 348, 124 },
		{ 325, 343 },
		{ 322, -1 },
		{ 325, -1 },
		{ 325, -1 },
		{ 325, -1 },
		{ 35, 24 },
		{ 35, 30 },
		{ 325, -1 },
		{ 325, -1 },
		{ 48, 49 },
		{ 325, -1 },
		{ 325, -1 },
		{ 325, -1 },
		{ 306, 139 },
		{ 133, 232 },
		{ 34, 60 },
		{ 306, 27 },
		{ 306, 34 },
		{ 306, 25 },
		{ 306, 26 },
		{ 318, 336 },
		{ 1, -1 },
		{ 35, 29 },
		{ 35, 31 },
		{ 35, 32 },
		{ 306, 33 },
		{ 1, 38 },
		{ 135, 233 },
		{ 306, 28 },
		{ 139, 236 },
		{ 139, 31 },
		{ 139, 237 },
		{ 317, 335 },
		{ 306, 331 },
		{ 306, 141 },
		{ 306, 142 },
		{ 161, -1 },
		{ 34, -1 },
		{ 139, 238 },
		{ 161, -1 },
		{ 161, 72 },
		{ 135, 129 },
		{ 48, 123 },
		{ 48, 125 },
		{ 161, 158 },
		{ 161, 69 },
		{ 316, 334 },
		{ 35, 61 },
		{ 35, 37 },
		{ 249, 311 },
		{ 253, 254 },
		{ 161, 71 },
		{ 253, 301 },
		{ 162, 254 },
		{ 249, 156 },
		{ 249, 31 },
		{ 249, 32 },
		{ 253, 302 },
		{ 253, 239 },
		{ 2, 39 },
		{ 162, 255 },
		{ 162, 239 },
		{ 2, 40 },
		{ 2, 41 },
		{ 257, 313 },
		{ 257, -1 },
		{ 257, -1 },
		{ 241, -1 },
		{ 241, -1 },
		{ 241, 309 },
		{ 234, 38 },
		{ 234, 31 },
		{ 234, 237 },
		{ 220, 294 },
		{ 220, -1 },
		{ 220, -1 },
		{ 307, 148 },
		{ 260, 315 },
		{ 57, 140 },
		{ 41, 63 },
		{ 307, 333 },
		{ 57, 143 },
		{ 41, 64 },
		{ 320, 117 },
		{ 89, 170 },
		{ 320, 339 },
		{ 89, -1 },
		{ 218, 292 },
		{ 218, -1 },
		{ 217, 291 },
		{ 217, -1 },
		{ 216, 290 },
		{ 216, -1 },
		{ 215, 289 },
		{ 215, -1 },
		{ 207, 282 },
		{ 207, -1 },
		{ 205, 280 },
		{ 205, -1 },
		{ 189, 275 },
		{ 189, -1 },
		{ 184, 106 },
		{ 184, 270 },
		{ 74, 161 },
		{ 74, 73 },
		{ 72, -1 },
		{ 72, 160 },
		{ 69, 155 },
		{ 69, 154 },
		{ 68, 152 },
		{ 68, 67 },
		{ 50, 56 },
		{ 50, 54 },
		{ 29, 52 },
		{ 29, 51 },
		{ 0, 35 },
		{ 0, 36 },
		{ 254, 305 },
		{ 251, 312 },
		{ 237, 59 },
		{ 235, 304 },
		{ 227, 297 },
		{ 224, 226 },
		{ 221, 295 },
		{ 219, 293 },
		{ 211, 287 },
		{ 206, 281 },
		{ 204, 279 },
		{ 203, 278 },
		{ 202, 277 },
		{ 201, 276 },
		{ 188, 274 },
		{ 187, 273 },
		{ 186, 272 },
		{ 185, 271 },
		{ 183, 269 },
		{ 177, 266 },
		{ 175, 264 },
		{ 174, 263 },
		{ 173, 262 },
		{ 172, 261 },
		{ 168, 163 },
		{ 165, 258 },
		{ 153, 248 },
		{ 150, 246 },
		{ 149, 245 },
		{ 132, 231 },
		{ 127, 228 },
		{ 109, 208 },
		{ 105, 201 },
		{ 100, 182 },
		{ 95, 176 },
		{ 90, 171 },
		{ 88, 169 },
		{ 87, 167 },
		{ 77, 164 },
		{ 71, 159 },
		{ 58, 147 },
		{ 51, 131 },
		{ 44, 70 },
		{ 42, 66 },
		{ 32, 59 },
		{ 30, 55 },
		{ 28, 47 },
		{ 27, 46 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 114, 35 },
		{ 49, 249 },
		{ 83, -1 },
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
		{ 203, 34 },
		{ 202, 34 },
		{ 121, 55 },
		{ 185, 50 },
		{ 0, -1 },
		{ 183, -1 },
		{ 0, -1 },
		{ 54, 241 },
		{ 45, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 103, -1 },
		{ 186, 68 },
		{ 0, -1 },
		{ 191, 74 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 123 },
		{ 0, -1 },
		{ 149, 135 },
		{ 166, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -20, 133 },
		{ 0, -1 },
		{ 97, 306 },
		{ 198, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 135, -1 },
		{ 136, 249 },
		{ 0, 161 },
		{ 186, 72 },
		{ 136, 161 },
		{ 0, -1 },
		{ 135, 161 },
		{ 0, -1 },
		{ 0, -1 },
		{ 170, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 212, 89 },
		{ 211, 89 },
		{ 142, 257 },
		{ 193, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 161, 348 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 192, 320 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 192, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 204, 257 },
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
		{ -2, 348 },
		{ 0, -1 },
		{ 0, 224 },
		{ 0, -1 },
		{ 150, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 158, 325 },
		{ 22, 34 },
		{ 0, -1 },
		{ 64, 1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 52, 162 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 186, 307 },
		{ 169, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 184, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, 34 },
		{ 74, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 152, 348 },
		{ 11, 168 },
		{ 0, -1 },
		{ 183, 320 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 150, 348 },
		{ 181, 320 },
		{ 180, 320 },
		{ 179, 320 },
		{ 0, -1 },
		{ 141, 266 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 190, 184 },
		{ 157, 257 },
		{ 190, 257 },
		{ 189, 257 },
		{ 188, 257 },
		{ 185, 189 },
		{ 153, 205 },
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
		{ 174, 322 },
		{ 182, 205 },
		{ 181, 205 },
		{ 180, 205 },
		{ 150, 207 },
		{ 178, 207 },
		{ 147, 215 },
		{ 0, -1 },
		{ 19, 322 },
		{ 0, -1 },
		{ 167, 320 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 144, 217 },
		{ 139, 220 },
		{ 139, 218 },
		{ 136, 216 },
		{ 166, 320 },
		{ 120, 324 },
		{ 167, 322 },
		{ 0, -1 },
		{ 0, -1 },
		{ 132, 348 },
		{ 0, -1 },
		{ 0, -1 },
		{ 131, 348 },
		{ 0, -1 },
		{ -3, 325 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 93, 253 },
		{ 161, 307 },
		{ 0, -1 },
		{ 141, 254 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 86, 306 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, -1 },
		{ 0, -1 },
		{ 159, 307 },
		{ 0, -1 },
		{ 71, 306 },
		{ 130, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 120, 189 },
		{ 0, -1 },
		{ 0, -1 },
		{ 87, 348 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 320 },
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
		{ 52, -1 },
		{ 121, 324 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 56, 348 },
		{ 42, 348 },
		{ 30, 348 },
		{ 9, 320 },
		{ 127, 322 },
		{ 0, -1 },
		{ 13, 325 },
		{ 0, -1 },
		{ 24, 322 },
		{ 12, 348 },
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
		{ -29, 348 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -1, -1 },
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
#line 2249 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	
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
