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
* Time: 18:19:24
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
#line 1792 ".\\myparser.y"

#line 3784 "myparser.cpp"
		}
		break;
	case 171:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1796 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1616 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3803 "myparser.cpp"
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
#line 1804 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1623 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3825 "myparser.cpp"
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
#line 1816 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3845 "myparser.cpp"
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
#line 1824 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3865 "myparser.cpp"
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
#line 1832 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3885 "myparser.cpp"
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
#line 1840 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3905 "myparser.cpp"
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
#line 1848 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3925 "myparser.cpp"
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
#line 1858 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3945 "myparser.cpp"
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
#line 1866 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3965 "myparser.cpp"
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
#line 1874 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3985 "myparser.cpp"
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
#line 1882 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1656 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4005 "myparser.cpp"
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
#line 1890 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4025 "myparser.cpp"
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
#line 1898 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4045 "myparser.cpp"
			}
		}
		break;
	case 184:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1909 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1680 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4067 "myparser.cpp"
			}
		}
		break;
	case 185:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1919 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4090 "myparser.cpp"
			}
		}
		break;
	case 186:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1930 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1699 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4112 "myparser.cpp"
			}
		}
		break;
	case 187:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1943 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1711 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4133 "myparser.cpp"
			}
		}
		break;
	case 188:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1952 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1719 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4155 "myparser.cpp"
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
#line 1962 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1728 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4177 "myparser.cpp"
			}
		}
		break;
	case 190:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1972 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1737 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4200 "myparser.cpp"
			}
		}
		break;
	case 191:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1986 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1750 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4220 "myparser.cpp"
			}
		}
		break;
	case 192:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1994 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1757 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4241 "myparser.cpp"
			}
		}
		break;
	case 193:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2006 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1768 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4261 "myparser.cpp"
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
#line 2014 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1775 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4282 "myparser.cpp"
			}
		}
		break;
	case 195:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2026 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1786 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4302 "myparser.cpp"
			}
		}
		break;
	case 196:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2034 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1793 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4323 "myparser.cpp"
			}
		}
		break;
	case 197:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2045 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1794 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4343 "myparser.cpp"
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
#line 2053 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1795 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4363 "myparser.cpp"
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
#line 2063 ".\\myparser.y"

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
	
#line 4389 "myparser.cpp"
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
#line 2077 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1815 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4409 "myparser.cpp"
			}
		}
		break;
	case 201:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2087 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1816@ ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[4] = yyattribute(5 - 5).ntnode;
	
#line 4433 "myparser.cpp"
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
#line 2099 ".\\myparser.y"

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
	
#line 4459 "myparser.cpp"
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
#line 2115 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1816 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4479 "myparser.cpp"
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
#line 2123 ".\\myparser.y"

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
	
#line 4503 "myparser.cpp"
			}
		}
		break;
	case 205:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2138 ".\\myparser.y"

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
	
#line 4527 "myparser.cpp"
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
#line 2150 ".\\myparser.y"

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
	
#line 4553 "myparser.cpp"
			}
		}
		break;
	case 207:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 2164 ".\\myparser.y"

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
	
#line 4578 "myparser.cpp"
			}
		}
		break;
	case 208:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2177 ".\\myparser.y"

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
	
#line 4604 "myparser.cpp"
			}
		}
		break;
	case 209:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2194 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4626 "myparser.cpp"
			}
		}
		break;
	case 210:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2204 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1900 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4647 "myparser.cpp"
			}
		}
		break;
	case 211:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2213 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4668 "myparser.cpp"
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
#line 2222 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1916 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4689 "myparser.cpp"
			}
		}
		break;
	case 213:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2231 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1924 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4711 "myparser.cpp"
			}
		}
		break;
	case 214:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2244 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1946 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		cout<<endl;
		traverse((*(YYSTYPE YYFAR*)yyvalptr).ntnode);
	
#line 4733 "myparser.cpp"
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
#line 2254 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1953 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		cout<<endl;
		traverse((*(YYSTYPE YYFAR*)yyvalptr).ntnode);
	
#line 4756 "myparser.cpp"
			}
		}
		break;
	case 216:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2268 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4776 "myparser.cpp"
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
#line 2276 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4796 "myparser.cpp"
			}
		}
		break;
	case 218:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2287 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1981 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4819 "myparser.cpp"
			}
		}
		break;
	case 219:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2298 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1991 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4841 "myparser.cpp"
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
#line 2308 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2000 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4863 "myparser.cpp"
			}
		}
		break;
	case 221:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2318 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2009 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4884 "myparser.cpp"
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
		"initializer:",
		"initializer_list: initializer",
		"initializer_list: initializer_list \',\' initializer",
		"other: labeled_statement",
		"other: compound_statement",
		"other: expression_statement",
		"other: iteration_statement",
		"other: jump_statement",
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
		"stmt: matched_statement",
		"stmt: open_statement",
		"matched_statement: IF \'(\' expression \')\' matched_statement ELSE matched_statement",
		"matched_statement: other",
		"open_statement: IF \'(\' expression \')\' stmt",
		"open_statement: IF \'(\' expression \')\' matched_statement ELSE open_statement",
		"selection_statement: stmt",
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
		{ 50, 0, 170 },
		{ 51, 1, 171 },
		{ 51, 3, 172 },
		{ 52, 1, 173 },
		{ 52, 1, 174 },
		{ 52, 1, 175 },
		{ 52, 1, 176 },
		{ 52, 1, 177 },
		{ 53, 1, 178 },
		{ 53, 1, 179 },
		{ 53, 1, 180 },
		{ 53, 1, 181 },
		{ 53, 1, 182 },
		{ 53, 1, 183 },
		{ 54, 3, 184 },
		{ 54, 4, 185 },
		{ 54, 3, 186 },
		{ 55, 2, 187 },
		{ 55, 3, 188 },
		{ 55, 3, 189 },
		{ 55, 4, 190 },
		{ 56, 1, 191 },
		{ 56, 2, 192 },
		{ 57, 1, 193 },
		{ 57, 2, 194 },
		{ 58, 1, 195 },
		{ 58, 2, 196 },
		{ 59, 1, 197 },
		{ 59, 1, 198 },
		{ 60, 7, 199 },
		{ 60, 1, 200 },
		{ 61, 5, 201 },
		{ 61, 7, 202 },
		{ 62, 1, 203 },
		{ 62, 5, 204 },
		{ 63, 5, 205 },
		{ 63, 7, 206 },
		{ 63, 6, 207 },
		{ 63, 7, 208 },
		{ 64, 3, 209 },
		{ 64, 2, 210 },
		{ 64, 2, 211 },
		{ 64, 2, 212 },
		{ 64, 3, 213 },
		{ 65, 1, 214 },
		{ 65, 2, 215 },
		{ 66, 1, 216 },
		{ 66, 1, 217 },
		{ 67, 4, 218 },
		{ 67, 3, 219 },
		{ 67, 3, 220 },
		{ 67, 2, 221 }
	};
	yyreduction = reduction;

	yytokenaction_size = 445;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 261, YYAT_SHIFT, 261 },
		{ 261, YYAT_SHIFT, 249 },
		{ 261, YYAT_SHIFT, 2 },
		{ 324, YYAT_SHIFT, 76 },
		{ 126, YYAT_SHIFT, 219 },
		{ 355, YYAT_SHIFT, 51 },
		{ 101, YYAT_SHIFT, 195 },
		{ 30, YYAT_SHIFT, 57 },
		{ 324, YYAT_SHIFT, 77 },
		{ 158, YYAT_SHIFT, 156 },
		{ 324, YYAT_SHIFT, 78 },
		{ 331, YYAT_SHIFT, 76 },
		{ 324, YYAT_SHIFT, 79 },
		{ 324, YYAT_SHIFT, 80 },
		{ 156, YYAT_SHIFT, 156 },
		{ 324, YYAT_SHIFT, 81 },
		{ 331, YYAT_SHIFT, 77 },
		{ 23, YYAT_SHIFT, 42 },
		{ 331, YYAT_SHIFT, 78 },
		{ 331, YYAT_SHIFT, 350 },
		{ 331, YYAT_SHIFT, 79 },
		{ 331, YYAT_SHIFT, 80 },
		{ 308, YYAT_SHIFT, 1 },
		{ 331, YYAT_SHIFT, 81 },
		{ 308, YYAT_SHIFT, 2 },
		{ 108, YYAT_ERROR, 0 },
		{ 162, YYAT_ERROR, 0 },
		{ 292, YYAT_SHIFT, 324 },
		{ 155, YYAT_SHIFT, 153 },
		{ 255, YYAT_ERROR, 0 },
		{ 255, YYAT_SHIFT, 314 },
		{ 255, YYAT_ERROR, 0 },
		{ 270, YYAT_SHIFT, 231 },
		{ 242, YYAT_SHIFT, 308 },
		{ 167, YYAT_SHIFT, 261 },
		{ 262, YYAT_SHIFT, 261 },
		{ 167, YYAT_SHIFT, 2 },
		{ 254, YYAT_SHIFT, 255 },
		{ 218, YYAT_SHIFT, 231 },
		{ 160, YYAT_SHIFT, 255 },
		{ 308, YYAT_SHIFT, 239 },
		{ 48, YYAT_SHIFT, 107 },
		{ 36, YYAT_ACCEPT, 0 },
		{ 46, YYAT_SHIFT, 44 },
		{ 286, YYAT_SHIFT, 231 },
		{ 276, YYAT_SHIFT, 181 },
		{ 24, YYAT_SHIFT, 44 },
		{ 50, YYAT_SHIFT, 110 },
		{ 242, YYAT_SHIFT, 309 },
		{ 40, YYAT_SHIFT, 2 },
		{ 276, YYAT_SHIFT, 182 },
		{ 261, YYAT_SHIFT, 157 },
		{ 2, YYAT_SHIFT, 2 },
		{ 218, YYAT_SHIFT, 302 },
		{ 351, YYAT_SHIFT, 355 },
		{ 276, YYAT_SHIFT, 183 },
		{ 245, YYAT_ERROR, 0 },
		{ 351, YYAT_SHIFT, 231 },
		{ 286, YYAT_SHIFT, 323 },
		{ 201, YYAT_SHIFT, 76 },
		{ 158, YYAT_SHIFT, 157 },
		{ 278, YYAT_SHIFT, 184 },
		{ 50, YYAT_SHIFT, 111 },
		{ 278, YYAT_SHIFT, 185 },
		{ 201, YYAT_SHIFT, 77 },
		{ 353, YYAT_SHIFT, 358 },
		{ 201, YYAT_SHIFT, 78 },
		{ 107, YYAT_SHIFT, 76 },
		{ 201, YYAT_SHIFT, 79 },
		{ 201, YYAT_SHIFT, 80 },
		{ 352, YYAT_ERROR, 0 },
		{ 201, YYAT_SHIFT, 81 },
		{ 107, YYAT_SHIFT, 77 },
		{ 71, YYAT_SHIFT, 156 },
		{ 107, YYAT_SHIFT, 78 },
		{ 71, YYAT_SHIFT, 2 },
		{ 107, YYAT_SHIFT, 79 },
		{ 107, YYAT_SHIFT, 80 },
		{ 349, YYAT_SHIFT, 353 },
		{ 107, YYAT_SHIFT, 81 },
		{ 255, YYAT_ERROR, 0 },
		{ 270, YYAT_SHIFT, 322 },
		{ 36, YYAT_SHIFT, 1 },
		{ 36, YYAT_ERROR, 0 },
		{ 130, YYAT_SHIFT, 112 },
		{ 167, YYAT_SHIFT, 157 },
		{ 262, YYAT_SHIFT, 157 },
		{ 346, YYAT_SHIFT, 352 },
		{ 254, YYAT_SHIFT, 256 },
		{ 44, YYAT_SHIFT, 69 },
		{ 160, YYAT_SHIFT, 256 },
		{ 330, YYAT_ERROR, 0 },
		{ 91, YYAT_SHIFT, 174 },
		{ 324, YYAT_SHIFT, 201 },
		{ 46, YYAT_SHIFT, 45 },
		{ 324, YYAT_SHIFT, 338 },
		{ 324, YYAT_SHIFT, 83 },
		{ 24, YYAT_SHIFT, 45 },
		{ 91, YYAT_SHIFT, 175 },
		{ 267, YYAT_SHIFT, 320 },
		{ 317, YYAT_SHIFT, 335 },
		{ 275, YYAT_SHIFT, 181 },
		{ 267, YYAT_SHIFT, 321 },
		{ 48, YYAT_SHIFT, 51 },
		{ 331, YYAT_SHIFT, 83 },
		{ 315, YYAT_SHIFT, 334 },
		{ 275, YYAT_SHIFT, 182 },
		{ 108, YYAT_SHIFT, 51 },
		{ 292, YYAT_SHIFT, 325 },
		{ 155, YYAT_SHIFT, 248 },
		{ 284, YYAT_SHIFT, 188 },
		{ 275, YYAT_SHIFT, 183 },
		{ 284, YYAT_SHIFT, 189 },
		{ 283, YYAT_SHIFT, 188 },
		{ 300, YYAT_SHIFT, 112 },
		{ 283, YYAT_SHIFT, 189 },
		{ 169, YYAT_SHIFT, 76 },
		{ 98, YYAT_SHIFT, 188 },
		{ 277, YYAT_SHIFT, 184 },
		{ 98, YYAT_SHIFT, 189 },
		{ 277, YYAT_SHIFT, 185 },
		{ 169, YYAT_SHIFT, 77 },
		{ 94, YYAT_SHIFT, 181 },
		{ 169, YYAT_SHIFT, 78 },
		{ 71, YYAT_SHIFT, 157 },
		{ 169, YYAT_SHIFT, 79 },
		{ 169, YYAT_SHIFT, 80 },
		{ 94, YYAT_SHIFT, 182 },
		{ 169, YYAT_SHIFT, 81 },
		{ 285, YYAT_SHIFT, 192 },
		{ 285, YYAT_SHIFT, 193 },
		{ 74, YYAT_SHIFT, 164 },
		{ 94, YYAT_SHIFT, 183 },
		{ 36, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 165 },
		{ 96, YYAT_SHIFT, 184 },
		{ 299, YYAT_SHIFT, 330 },
		{ 96, YYAT_SHIFT, 185 },
		{ 298, YYAT_SHIFT, 329 },
		{ 355, YYAT_SHIFT, 114 },
		{ 245, YYAT_SHIFT, 310 },
		{ 30, YYAT_SHIFT, 58 },
		{ 297, YYAT_SHIFT, 328 },
		{ 91, YYAT_SHIFT, 176 },
		{ 282, YYAT_SHIFT, 186 },
		{ 282, YYAT_SHIFT, 187 },
		{ 281, YYAT_SHIFT, 186 },
		{ 281, YYAT_SHIFT, 187 },
		{ 130, YYAT_SHIFT, 51 },
		{ 201, YYAT_SHIFT, 201 },
		{ 130, YYAT_SHIFT, 233 },
		{ 23, YYAT_SHIFT, 43 },
		{ 201, YYAT_SHIFT, 83 },
		{ 280, YYAT_SHIFT, 186 },
		{ 280, YYAT_SHIFT, 187 },
		{ 279, YYAT_SHIFT, 186 },
		{ 279, YYAT_SHIFT, 187 },
		{ 107, YYAT_SHIFT, 201 },
		{ 99, YYAT_SHIFT, 192 },
		{ 99, YYAT_SHIFT, 193 },
		{ 107, YYAT_SHIFT, 83 },
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
		{ 97, YYAT_SHIFT, 186 },
		{ 97, YYAT_SHIFT, 187 },
		{ 296, YYAT_SHIFT, 327 },
		{ 290, YYAT_SHIFT, 199 },
		{ 355, YYAT_SHIFT, 115 },
		{ 355, YYAT_SHIFT, 116 },
		{ 355, YYAT_SHIFT, 117 },
		{ 289, YYAT_SHIFT, 194 },
		{ 355, YYAT_SHIFT, 118 },
		{ 355, YYAT_SHIFT, 119 },
		{ 355, YYAT_SHIFT, 120 },
		{ 355, YYAT_SHIFT, 121 },
		{ 355, YYAT_SHIFT, 122 },
		{ 355, YYAT_SHIFT, 123 },
		{ 355, YYAT_SHIFT, 124 },
		{ 355, YYAT_SHIFT, 125 },
		{ 288, YYAT_SHIFT, 200 },
		{ 287, YYAT_SHIFT, 198 },
		{ 265, YYAT_SHIFT, 319 },
		{ 256, YYAT_SHIFT, 316 },
		{ 253, YYAT_SHIFT, 313 },
		{ 251, YYAT_SHIFT, 312 },
		{ 250, YYAT_SHIFT, 311 },
		{ 240, YYAT_SHIFT, 307 },
		{ 234, YYAT_SHIFT, 305 },
		{ 214, YYAT_SHIFT, 301 },
		{ 212, YYAT_SHIFT, 299 },
		{ 207, YYAT_SHIFT, 294 },
		{ 169, YYAT_SHIFT, 83 },
		{ 177, YYAT_SHIFT, 271 },
		{ 175, YYAT_SHIFT, 269 },
		{ 174, YYAT_SHIFT, 266 },
		{ 168, YYAT_SHIFT, 264 },
		{ 101, YYAT_SHIFT, 196 },
		{ 126, YYAT_SHIFT, 220 },
		{ 126, YYAT_SHIFT, 221 },
		{ 126, YYAT_SHIFT, 222 },
		{ 126, YYAT_SHIFT, 223 },
		{ 126, YYAT_SHIFT, 224 },
		{ 126, YYAT_SHIFT, 225 },
		{ 126, YYAT_SHIFT, 226 },
		{ 126, YYAT_SHIFT, 227 },
		{ 126, YYAT_SHIFT, 228 },
		{ 126, YYAT_SHIFT, 229 },
		{ 166, YYAT_SHIFT, 260 },
		{ 158, YYAT_SHIFT, 3 },
		{ 324, YYAT_SHIFT, 84 },
		{ 324, YYAT_SHIFT, 85 },
		{ 324, YYAT_SHIFT, 86 },
		{ 324, YYAT_SHIFT, 87 },
		{ 156, YYAT_SHIFT, 3 },
		{ 324, YYAT_SHIFT, 88 },
		{ 324, YYAT_SHIFT, 89 },
		{ 165, YYAT_SHIFT, 259 },
		{ 331, YYAT_SHIFT, 84 },
		{ 331, YYAT_SHIFT, 85 },
		{ 331, YYAT_SHIFT, 86 },
		{ 331, YYAT_SHIFT, 87 },
		{ 308, YYAT_SHIFT, 3 },
		{ 331, YYAT_SHIFT, 88 },
		{ 331, YYAT_SHIFT, 89 },
		{ 261, YYAT_SHIFT, 4 },
		{ 261, YYAT_SHIFT, 5 },
		{ 261, YYAT_SHIFT, 6 },
		{ 261, YYAT_SHIFT, 7 },
		{ 261, YYAT_SHIFT, 8 },
		{ 261, YYAT_SHIFT, 9 },
		{ 261, YYAT_SHIFT, 10 },
		{ 261, YYAT_SHIFT, 11 },
		{ 261, YYAT_SHIFT, 12 },
		{ 261, YYAT_SHIFT, 13 },
		{ 261, YYAT_SHIFT, 14 },
		{ 261, YYAT_SHIFT, 15 },
		{ 261, YYAT_SHIFT, 16 },
		{ 261, YYAT_SHIFT, 17 },
		{ 261, YYAT_SHIFT, 18 },
		{ 261, YYAT_SHIFT, 19 },
		{ 261, YYAT_SHIFT, 20 },
		{ 261, YYAT_SHIFT, 21 },
		{ 261, YYAT_SHIFT, 22 },
		{ 261, YYAT_SHIFT, 23 },
		{ 48, YYAT_SHIFT, 4 },
		{ 48, YYAT_SHIFT, 5 },
		{ 48, YYAT_SHIFT, 6 },
		{ 48, YYAT_SHIFT, 7 },
		{ 48, YYAT_SHIFT, 8 },
		{ 48, YYAT_SHIFT, 9 },
		{ 48, YYAT_SHIFT, 10 },
		{ 48, YYAT_SHIFT, 11 },
		{ 48, YYAT_SHIFT, 12 },
		{ 48, YYAT_SHIFT, 13 },
		{ 48, YYAT_SHIFT, 14 },
		{ 48, YYAT_SHIFT, 15 },
		{ 48, YYAT_SHIFT, 16 },
		{ 48, YYAT_SHIFT, 17 },
		{ 48, YYAT_SHIFT, 18 },
		{ 48, YYAT_SHIFT, 19 },
		{ 48, YYAT_SHIFT, 20 },
		{ 48, YYAT_SHIFT, 21 },
		{ 48, YYAT_SHIFT, 22 },
		{ 48, YYAT_SHIFT, 23 },
		{ 130, YYAT_SHIFT, 114 },
		{ 201, YYAT_SHIFT, 84 },
		{ 201, YYAT_SHIFT, 85 },
		{ 201, YYAT_SHIFT, 86 },
		{ 201, YYAT_SHIFT, 87 },
		{ 162, YYAT_SHIFT, 257 },
		{ 201, YYAT_SHIFT, 88 },
		{ 201, YYAT_SHIFT, 89 },
		{ 71, YYAT_SHIFT, 3 },
		{ 107, YYAT_SHIFT, 84 },
		{ 107, YYAT_SHIFT, 85 },
		{ 107, YYAT_SHIFT, 86 },
		{ 107, YYAT_SHIFT, 87 },
		{ 157, YYAT_SHIFT, 252 },
		{ 107, YYAT_SHIFT, 88 },
		{ 107, YYAT_SHIFT, 89 },
		{ 245, YYAT_ERROR, 0 },
		{ 245, YYAT_ERROR, 0 },
		{ 245, YYAT_ERROR, 0 },
		{ 245, YYAT_ERROR, 0 },
		{ 245, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 18 },
		{ 40, YYAT_SHIFT, 19 },
		{ 44, YYAT_SHIFT, 70 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 130, YYAT_SHIFT, 5 },
		{ 130, YYAT_SHIFT, 6 },
		{ 130, YYAT_SHIFT, 7 },
		{ 130, YYAT_SHIFT, 8 },
		{ 130, YYAT_SHIFT, 9 },
		{ 91, YYAT_SHIFT, 177 },
		{ 91, YYAT_SHIFT, 178 },
		{ 91, YYAT_SHIFT, 179 },
		{ 284, YYAT_SHIFT, 190 },
		{ 284, YYAT_SHIFT, 191 },
		{ 153, YYAT_SHIFT, 65 },
		{ 283, YYAT_SHIFT, 190 },
		{ 283, YYAT_SHIFT, 191 },
		{ 151, YYAT_ERROR, 0 },
		{ 146, YYAT_SHIFT, 237 },
		{ 98, YYAT_SHIFT, 190 },
		{ 98, YYAT_SHIFT, 191 },
		{ 143, YYAT_SHIFT, 107 },
		{ 137, YYAT_SHIFT, 235 },
		{ 127, YYAT_SHIFT, 232 },
		{ 130, YYAT_SHIFT, 115 },
		{ 130, YYAT_SHIFT, 116 },
		{ 130, YYAT_SHIFT, 117 },
		{ 125, YYAT_SHIFT, 217 },
		{ 130, YYAT_SHIFT, 118 },
		{ 130, YYAT_SHIFT, 119 },
		{ 130, YYAT_SHIFT, 120 },
		{ 130, YYAT_SHIFT, 121 },
		{ 130, YYAT_SHIFT, 122 },
		{ 130, YYAT_SHIFT, 123 },
		{ 130, YYAT_SHIFT, 124 },
		{ 130, YYAT_SHIFT, 125 },
		{ 169, YYAT_SHIFT, 84 },
		{ 169, YYAT_SHIFT, 85 },
		{ 169, YYAT_SHIFT, 86 },
		{ 169, YYAT_SHIFT, 87 },
		{ 124, YYAT_SHIFT, 216 },
		{ 169, YYAT_SHIFT, 88 },
		{ 169, YYAT_SHIFT, 89 },
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
		{ 29, YYAT_SHIFT, 4 },
		{ 29, YYAT_SHIFT, 5 },
		{ 29, YYAT_SHIFT, 6 },
		{ 29, YYAT_SHIFT, 7 },
		{ 29, YYAT_SHIFT, 8 },
		{ 29, YYAT_SHIFT, 9 },
		{ 29, YYAT_SHIFT, 10 },
		{ 29, YYAT_SHIFT, 11 },
		{ 29, YYAT_SHIFT, 12 },
		{ 29, YYAT_SHIFT, 13 },
		{ 29, YYAT_SHIFT, 14 },
		{ 29, YYAT_SHIFT, 15 },
		{ 29, YYAT_SHIFT, 16 },
		{ 29, YYAT_SHIFT, 17 },
		{ 29, YYAT_SHIFT, 18 },
		{ 29, YYAT_SHIFT, 19 },
		{ 29, YYAT_SHIFT, 20 },
		{ 29, YYAT_SHIFT, 21 },
		{ 29, YYAT_SHIFT, 22 },
		{ 29, YYAT_SHIFT, 23 },
		{ 149, YYAT_SHIFT, 4 },
		{ 123, YYAT_SHIFT, 215 },
		{ 122, YYAT_SHIFT, 214 },
		{ 121, YYAT_SHIFT, 213 },
		{ 119, YYAT_SHIFT, 211 },
		{ 118, YYAT_SHIFT, 210 },
		{ 149, YYAT_SHIFT, 10 },
		{ 149, YYAT_SHIFT, 11 },
		{ 149, YYAT_SHIFT, 12 },
		{ 149, YYAT_SHIFT, 13 },
		{ 149, YYAT_SHIFT, 14 },
		{ 149, YYAT_SHIFT, 15 },
		{ 149, YYAT_SHIFT, 16 },
		{ 149, YYAT_SHIFT, 17 },
		{ 149, YYAT_SHIFT, 18 },
		{ 149, YYAT_SHIFT, 19 },
		{ 149, YYAT_SHIFT, 20 },
		{ 149, YYAT_SHIFT, 21 },
		{ 149, YYAT_SHIFT, 22 },
		{ 149, YYAT_SHIFT, 23 },
		{ 148, YYAT_SHIFT, 4 },
		{ 117, YYAT_SHIFT, 209 },
		{ 116, YYAT_SHIFT, 208 },
		{ 114, YYAT_SHIFT, 206 },
		{ 110, YYAT_ERROR, 0 },
		{ 106, YYAT_SHIFT, 200 },
		{ 148, YYAT_SHIFT, 10 },
		{ 148, YYAT_SHIFT, 11 },
		{ 148, YYAT_SHIFT, 12 },
		{ 148, YYAT_SHIFT, 13 },
		{ 148, YYAT_SHIFT, 14 },
		{ 148, YYAT_SHIFT, 15 },
		{ 148, YYAT_SHIFT, 16 },
		{ 148, YYAT_SHIFT, 17 },
		{ 148, YYAT_SHIFT, 18 },
		{ 148, YYAT_SHIFT, 19 },
		{ 148, YYAT_SHIFT, 20 },
		{ 148, YYAT_SHIFT, 21 },
		{ 148, YYAT_SHIFT, 22 },
		{ 148, YYAT_SHIFT, 23 },
		{ 104, YYAT_SHIFT, 199 },
		{ 103, YYAT_SHIFT, 198 },
		{ 102, YYAT_SHIFT, 197 },
		{ 100, YYAT_SHIFT, 194 },
		{ 89, YYAT_SHIFT, 171 },
		{ 87, YYAT_SHIFT, 169 },
		{ 73, YYAT_SHIFT, 163 },
		{ 72, YYAT_SHIFT, 162 },
		{ 66, YYAT_SHIFT, 154 },
		{ 65, YYAT_SHIFT, 152 },
		{ 58, YYAT_SHIFT, 151 },
		{ 52, YYAT_SHIFT, 47 },
		{ 51, YYAT_SHIFT, 113 },
		{ 45, YYAT_SHIFT, 82 },
		{ 43, YYAT_SHIFT, 68 },
		{ 38, YYAT_SHIFT, 62 },
		{ 25, YYAT_ERROR, 0 },
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 444, 1, YYAT_DEFAULT, 36 },
		{ 0, 0, YYAT_DEFAULT, 110 },
		{ 10, 1, YYAT_REDUCE, 139 },
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
		{ -106, 1, YYAT_ERROR, 0 },
		{ 6, 1, YYAT_REDUCE, 131 },
		{ 401, 1, YYAT_DEFAULT, 110 },
		{ 0, 0, YYAT_DEFAULT, 52 },
		{ 0, 0, YYAT_DEFAULT, 108 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 85, 1, YYAT_REDUCE, 77 },
		{ -116, 1, YYAT_ERROR, 0 },
		{ 65, 1, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ -121, 1, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 217 },
		{ 42, 1, YYAT_DEFAULT, 156 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ 401, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ 7, 1, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 143 },
		{ 0, 0, YYAT_DEFAULT, 153 },
		{ 318, 1, YYAT_REDUCE, 123 },
		{ 48, 1, YYAT_DEFAULT, 255 },
		{ 347, 1, YYAT_DEFAULT, 330 },
		{ 3, 1, YYAT_REDUCE, 130 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ -20, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 3, 1, YYAT_ERROR, 0 },
		{ 314, 1, YYAT_DEFAULT, 130 },
		{ 379, 1, YYAT_DEFAULT, 110 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_DEFAULT, 108 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_DEFAULT, 151 },
		{ 314, 1, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 216 },
		{ 0, 0, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 0, 0, YYAT_REDUCE, 144 },
		{ 375, 1, YYAT_REDUCE, 126 },
		{ 310, 1, YYAT_DEFAULT, 155 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_DEFAULT, 153 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 33, 1, YYAT_REDUCE, 151 },
		{ 390, 1, YYAT_REDUCE, 145 },
		{ 392, 1, YYAT_ERROR, 0 },
		{ 90, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 169 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 392, 1, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 89 },
		{ 391, 1, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 52, 1, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 85, 1, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 92, 1, YYAT_REDUCE, 36 },
		{ -83, 1, YYAT_REDUCE, 39 },
		{ 57, 1, YYAT_REDUCE, 44 },
		{ -110, 1, YYAT_REDUCE, 47 },
		{ 392, 1, YYAT_REDUCE, 49 },
		{ -57, 1, YYAT_REDUCE, 57 },
		{ 336, 1, YYAT_ERROR, 0 },
		{ 158, 1, YYAT_REDUCE, 55 },
		{ 333, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 288, 1, YYAT_REDUCE, 53 },
		{ 34, 1, YYAT_REDUCE, 171 },
		{ -16, 1, YYAT_DEFAULT, 255 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ 353, 1, YYAT_DEFAULT, 308 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 352, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 351, 1, YYAT_ERROR, 0 },
		{ 368, 1, YYAT_ERROR, 0 },
		{ 352, 1, YYAT_ERROR, 0 },
		{ 351, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 350, 1, YYAT_ERROR, 0 },
		{ 132, 1, YYAT_ERROR, 0 },
		{ 329, 1, YYAT_ERROR, 0 },
		{ 285, 1, YYAT_ERROR, 0 },
		{ 272, 1, YYAT_DEFAULT, 330 },
		{ -57, 1, YYAT_REDUCE, 27 },
		{ 268, 1, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 25, 1, YYAT_DEFAULT, 169 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 201, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 264, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ 197, 1, YYAT_DEFAULT, 245 },
		{ 0, 0, YYAT_DEFAULT, 308 },
		{ 125, 1, YYAT_REDUCE, 113 },
		{ 105, 1, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 196, 1, YYAT_DEFAULT, 245 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 61, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 121 },
		{ -16, 1, YYAT_ERROR, 0 },
		{ -26, 1, YYAT_DEFAULT, 261 },
		{ 202, 1, YYAT_DEFAULT, 330 },
		{ -31, 1, YYAT_REDUCE, 156 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ -1, 1, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ -15, 1, YYAT_DEFAULT, 255 },
		{ 0, 0, YYAT_REDUCE, 136 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ -23, 1, YYAT_ERROR, 0 },
		{ 184, 1, YYAT_DEFAULT, 351 },
		{ -6, 1, YYAT_REDUCE, 154 },
		{ 172, 1, YYAT_ERROR, 0 },
		{ 83, 1, YYAT_DEFAULT, 151 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 171, 1, YYAT_DEFAULT, 331 },
		{ -46, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ -47, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 26, 1, YYAT_REDUCE, 171 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 219 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 150, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ -101, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 300 },
		{ 147, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ -6, 1, YYAT_ERROR, 0 },
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
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 80, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 146, 1, YYAT_REDUCE, 118 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ -11, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 15, 1, YYAT_DEFAULT, 255 },
		{ 0, 0, YYAT_REDUCE, 127 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 162, 1, YYAT_ERROR, 0 },
		{ 161, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ 108, 1, YYAT_ERROR, 0 },
		{ -3, 1, YYAT_REDUCE, 158 },
		{ -11, 1, YYAT_DEFAULT, 261 },
		{ 107, 1, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -40, 1, YYAT_ERROR, 0 },
		{ -5, 1, YYAT_REDUCE, 156 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 158, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 58, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ -12, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 64, 1, YYAT_REDUCE, 34 },
		{ 8, 1, YYAT_REDUCE, 35 },
		{ 75, 1, YYAT_REDUCE, 37 },
		{ 18, 1, YYAT_REDUCE, 38 },
		{ -109, 1, YYAT_REDUCE, 40 },
		{ -111, 1, YYAT_REDUCE, 41 },
		{ -118, 1, YYAT_REDUCE, 42 },
		{ -120, 1, YYAT_REDUCE, 43 },
		{ 53, 1, YYAT_REDUCE, 45 },
		{ 50, 1, YYAT_REDUCE, 46 },
		{ -139, 1, YYAT_REDUCE, 48 },
		{ 0, 1, YYAT_ERROR, 0 },
		{ -72, 1, YYAT_REDUCE, 56 },
		{ 73, 1, YYAT_REDUCE, 54 },
		{ 150, 1, YYAT_REDUCE, 50 },
		{ 90, 1, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ -17, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 142, 1, YYAT_DEFAULT, 351 },
		{ 101, 1, YYAT_DEFAULT, 351 },
		{ 97, 1, YYAT_DEFAULT, 351 },
		{ 96, 1, YYAT_ERROR, 0 },
		{ 55, 1, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_REDUCE, 119 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ -18, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 165 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 161 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ 64, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 162 },
		{ 7, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 330 },
		{ -30, 1, YYAT_REDUCE, 171 },
		{ 0, 0, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 0, 0, YYAT_DEFAULT, 352 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 50, 1, YYAT_DEFAULT, 331 },
		{ -22, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 120 },
		{ 0, 0, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ -219, 1, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 37, 1, YYAT_DEFAULT, 351 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 13, 1, YYAT_ERROR, 0 },
		{ -237, 1, YYAT_DEFAULT, 355 },
		{ 6, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ -118, 1, YYAT_DEFAULT, 300 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 209 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 241;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 355, 90 },
		{ 355, 91 },
		{ 48, 53 },
		{ 355, 126 },
		{ 355, 93 },
		{ 355, 92 },
		{ 355, 94 },
		{ 355, 96 },
		{ 355, 97 },
		{ 355, 98 },
		{ 355, 99 },
		{ 355, 100 },
		{ 355, 104 },
		{ 355, 106 },
		{ 355, 103 },
		{ 355, 101 },
		{ 355, 128 },
		{ 355, 129 },
		{ 261, 71 },
		{ 355, 127 },
		{ 350, 354 },
		{ 261, 29 },
		{ 261, 31 },
		{ 261, 28 },
		{ 261, 30 },
		{ 34, 60 },
		{ 169, 148 },
		{ 169, 28 },
		{ 169, 30 },
		{ 300, 127 },
		{ 261, 33 },
		{ 169, 167 },
		{ 330, 349 },
		{ 261, 34 },
		{ 169, 33 },
		{ 48, 109 },
		{ 48, 108 },
		{ 169, 149 },
		{ 261, 250 },
		{ 261, 72 },
		{ 261, 75 },
		{ 331, 351 },
		{ 324, 202 },
		{ 261, 251 },
		{ 329, 348 },
		{ 2, 41 },
		{ 169, 265 },
		{ 34, -1 },
		{ 2, 39 },
		{ 2, 40 },
		{ 328, 347 },
		{ 355, 139 },
		{ 355, 359 },
		{ 355, 131 },
		{ 355, 135 },
		{ 51, 53 },
		{ 294, 326 },
		{ 355, 132 },
		{ 355, 138 },
		{ 355, 141 },
		{ 355, 142 },
		{ 355, 140 },
		{ 355, 133 },
		{ 355, 134 },
		{ 130, 144 },
		{ 130, 52 },
		{ 262, 254 },
		{ 300, 331 },
		{ 130, 29 },
		{ 130, 31 },
		{ 130, 28 },
		{ 130, 30 },
		{ 256, 317 },
		{ 331, -1 },
		{ 324, 339 },
		{ 331, -1 },
		{ 331, -1 },
		{ 130, 33 },
		{ 174, 267 },
		{ 331, -1 },
		{ 130, 34 },
		{ 331, -1 },
		{ 331, -1 },
		{ 323, 95 },
		{ 331, -1 },
		{ 331, -1 },
		{ 36, 32 },
		{ 36, 26 },
		{ 239, 306 },
		{ 51, 130 },
		{ 51, 137 },
		{ 108, 144 },
		{ 108, 52 },
		{ 174, 268 },
		{ 307, 105 },
		{ 130, 136 },
		{ 323, 337 },
		{ 323, -1 },
		{ 307, 332 },
		{ 130, 234 },
		{ 71, 159 },
		{ 71, 24 },
		{ 71, 158 },
		{ 36, 27 },
		{ 36, 24 },
		{ 36, 25 },
		{ 352, -1 },
		{ 352, 340 },
		{ 352, 344 },
		{ 71, 161 },
		{ 234, 236 },
		{ 352, 341 },
		{ 352, -1 },
		{ 352, 356 },
		{ 352, 357 },
		{ 352, -1 },
		{ 352, 342 },
		{ 352, 343 },
		{ 245, -1 },
		{ 231, 304 },
		{ 1, -1 },
		{ 245, -1 },
		{ 245, 148 },
		{ 230, 303 },
		{ 108, 204 },
		{ 1, 38 },
		{ 245, 238 },
		{ 245, 147 },
		{ 110, 205 },
		{ 44, 73 },
		{ 36, 61 },
		{ 36, 35 },
		{ 44, 74 },
		{ 245, 149 },
		{ 200, 290 },
		{ 200, -1 },
		{ 200, -1 },
		{ 200, -1 },
		{ 200, -1 },
		{ 255, -1 },
		{ 213, 300 },
		{ 255, 315 },
		{ 110, 143 },
		{ 308, 333 },
		{ 167, 262 },
		{ 211, 298 },
		{ 255, -1 },
		{ 255, -1 },
		{ 308, 240 },
		{ 308, 24 },
		{ 308, 25 },
		{ 167, 263 },
		{ 167, 160 },
		{ 327, 345 },
		{ 327, 346 },
		{ 327, 142 },
		{ 264, 318 },
		{ 264, -1 },
		{ 264, -1 },
		{ 162, -1 },
		{ 162, -1 },
		{ 162, 258 },
		{ 156, 38 },
		{ 156, 24 },
		{ 156, 158 },
		{ 40, 64 },
		{ 210, 297 },
		{ 321, 336 },
		{ 40, 63 },
		{ 321, -1 },
		{ 89, 173 },
		{ 209, 296 },
		{ 89, -1 },
		{ 201, 291 },
		{ 201, 292 },
		{ 199, 289 },
		{ 199, -1 },
		{ 198, 104 },
		{ 198, 288 },
		{ 196, 106 },
		{ 196, 287 },
		{ 194, 285 },
		{ 194, -1 },
		{ 193, 284 },
		{ 193, -1 },
		{ 191, 282 },
		{ 191, -1 },
		{ 187, 278 },
		{ 187, -1 },
		{ 185, 92 },
		{ 185, 276 },
		{ 151, 245 },
		{ 151, 150 },
		{ 149, -1 },
		{ 149, 244 },
		{ 147, 242 },
		{ 147, 241 },
		{ 68, 155 },
		{ 68, 67 },
		{ 52, 50 },
		{ 52, 49 },
		{ 27, 55 },
		{ 27, 54 },
		{ 0, 36 },
		{ 0, 37 },
		{ 208, 295 },
		{ 206, 293 },
		{ 195, 286 },
		{ 192, 283 },
		{ 190, 281 },
		{ 189, 280 },
		{ 188, 279 },
		{ 186, 277 },
		{ 184, 275 },
		{ 183, 274 },
		{ 182, 273 },
		{ 181, 272 },
		{ 176, 270 },
		{ 171, 166 },
		{ 158, 46 },
		{ 157, 253 },
		{ 153, 247 },
		{ 152, 246 },
		{ 148, 243 },
		{ 126, 230 },
		{ 125, 218 },
		{ 120, 212 },
		{ 115, 207 },
		{ 107, 203 },
		{ 93, 180 },
		{ 88, 172 },
		{ 87, 170 },
		{ 78, 168 },
		{ 57, 146 },
		{ 54, 145 },
		{ 45, 102 },
		{ 42, 66 },
		{ 31, 59 },
		{ 29, 56 },
		{ 26, 48 },
		{ 25, 46 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 138, 36 },
		{ 86, 308 },
		{ 7, -1 },
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
		{ 200, -1 },
		{ 200, 52 },
		{ 146, 48 },
		{ 0, -1 },
		{ 215, 34 },
		{ 0, -1 },
		{ 214, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 2, 162 },
		{ 0, -1 },
		{ 64, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 127, -1 },
		{ 0, -1 },
		{ 200, 68 },
		{ 0, -1 },
		{ 86, 255 },
		{ 214, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ -20, 108 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 130 },
		{ 175, 110 },
		{ 0, -1 },
		{ 179, 108 },
		{ 0, -1 },
		{ 0, -1 },
		{ 203, 151 },
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
		{ 161, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 61, 167 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 185, 169 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 227, 89 },
		{ 226, 89 },
		{ 166, 264 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 223, 264 },
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
		{ 178, 324 },
		{ 69, 34 },
		{ 0, -1 },
		{ 103, 1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 206, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 173, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 205, 331 },
		{ 205, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 42, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 234 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 245 },
		{ 162, 308 },
		{ 191, 149 },
		{ 162, 245 },
		{ 0, -1 },
		{ 161, 245 },
		{ 201, 307 },
		{ 184, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 123, 261 },
		{ 199, 307 },
		{ 179, 262 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 116, 255 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 103, -1 },
		{ 0, -1 },
		{ -1, 171 },
		{ 0, -1 },
		{ 198, 331 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, 321 },
		{ 0, -1 },
		{ 197, 331 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 210, 264 },
		{ 209, 264 },
		{ 208, 264 },
		{ 206, 185 },
		{ 183, 264 },
		{ 204, 187 },
		{ 179, 191 },
		{ 202, 191 },
		{ 201, 191 },
		{ 200, 191 },
		{ 176, 193 },
		{ 198, 193 },
		{ 173, 194 },
		{ 170, 199 },
		{ 187, 331 },
		{ 165, 198 },
		{ 0, -1 },
		{ 164, 200 },
		{ 163, 200 },
		{ 121, 323 },
		{ 123, 324 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 153, 355 },
		{ 0, -1 },
		{ 152, 355 },
		{ 151, 331 },
		{ 146, 331 },
		{ 125, 331 },
		{ 0, -1 },
		{ 82, 300 },
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
		{ 105, 321 },
		{ 101, 321 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 67, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 95, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 98, 261 },
		{ 51, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -5, 167 },
		{ 17, -1 },
		{ 0, -1 },
		{ 150, 187 },
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
		{ 3, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 9, 331 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, 323 },
		{ 109, -1 },
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
		{ 149, 331 },
		{ 0, -1 },
		{ 79, 321 },
		{ 24, 321 },
		{ 0, -1 },
		{ 0, -1 },
		{ 94, 352 },
		{ -3, 355 },
		{ -9, 355 },
		{ 12, 331 },
		{ 21, 352 },
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
		{ -33, 355 },
		{ 0, -1 },
		{ 53, 355 },
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
#line 2331 ".\\myparser.y"


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
