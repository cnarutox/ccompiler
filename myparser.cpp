/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 70 of your 30 day trial period.
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
* Time: 10:56:12
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


#line 65 "myparser.cpp"
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
#line 82 ".\\myparser.y"

	// place any extra initialisation code here

#line 89 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 87 ".\\myparser.y"

	// place any extra cleanup code here

#line 103 "myparser.cpp"
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
#line 110 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("108 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

		//$$->type = $1.ntnode;
	
#line 222 "myparser.cpp"
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
#line 120 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("116 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 244 "myparser.cpp"
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
#line 130 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("123 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 264 "myparser.cpp"
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
#line 138 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("130 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	
	
#line 286 "myparser.cpp"
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
#line 152 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("142 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 308 "myparser.cpp"
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
#line 162 ".\\myparser.y"
	
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("149 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 331 "myparser.cpp"
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
#line 173 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("159 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 353 "myparser.cpp"
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
#line 183 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("168 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 376 "myparser.cpp"
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
#line 194 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("178 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 398 "myparser.cpp"
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
#line 204 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("187 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 420 "myparser.cpp"
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
#line 214 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("196 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 441 "myparser.cpp"
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
#line 223 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 462 "myparser.cpp"
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
#line 235 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("215 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 482 "myparser.cpp"
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
#line 243 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("222 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 504 "myparser.cpp"
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
#line 256 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("234 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 526 "myparser.cpp"
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
#line 266 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("241 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 547 "myparser.cpp"
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
#line 275 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("249 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 568 "myparser.cpp"
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
#line 284 ".\\myparser.y"

		//cast_exp:单目表达式/强制类型转换
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("257 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 590 "myparser.cpp"
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
#line 294 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("265 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 611 "myparser.cpp"
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
#line 303 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("273 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 634 "myparser.cpp"
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
#line 317 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("286 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 654 "myparser.cpp"
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
#line 325 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 674 "myparser.cpp"
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
#line 333 ".\\myparser.y"

		printf("777");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("301 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 695 "myparser.cpp"
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
#line 342 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("308 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 715 "myparser.cpp"
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
#line 350 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("315 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 735 "myparser.cpp"
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
#line 358 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("322 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 755 "myparser.cpp"
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
#line 369 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("332 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 777 "myparser.cpp"
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
#line 379 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("339 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 800 "myparser.cpp"
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
#line 393 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("352 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 822 "myparser.cpp"
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
#line 403 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("359 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 844 "myparser.cpp"
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
#line 413 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("368 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 866 "myparser.cpp"
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
#line 423 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("377 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 888 "myparser.cpp"
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
#line 436 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("389 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 910 "myparser.cpp"
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
#line 446 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("396 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 932 "myparser.cpp"
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
#line 456 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("405 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 954 "myparser.cpp"
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
#line 469 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("417 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 976 "myparser.cpp"
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
#line 479 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("424 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 998 "myparser.cpp"
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
#line 489 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("433 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1020 "myparser.cpp"
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
#line 502 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("445 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1042 "myparser.cpp"
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
#line 512 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("452 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1064 "myparser.cpp"
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
#line 522 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("461 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1086 "myparser.cpp"
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
#line 532 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("470 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1108 "myparser.cpp"
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
#line 542 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("479 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1130 "myparser.cpp"
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
#line 555 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("491 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1152 "myparser.cpp"
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
#line 565 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("498 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1174 "myparser.cpp"
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
#line 575 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("507 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1196 "myparser.cpp"
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
#line 588 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("519 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1218 "myparser.cpp"
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
#line 598 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("526 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1240 "myparser.cpp"
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
#line 611 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1262 "myparser.cpp"
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
#line 621 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("545 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1284 "myparser.cpp"
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
#line 634 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("557 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1306 "myparser.cpp"
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
#line 644 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("564 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1328 "myparser.cpp"
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
#line 657 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("576 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1350 "myparser.cpp"
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
#line 667 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("583 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1372 "myparser.cpp"
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
#line 680 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("595 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1394 "myparser.cpp"
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
#line 690 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("602 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1416 "myparser.cpp"
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
#line 703 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("614 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;	
	
#line 1438 "myparser.cpp"
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
#line 713 ".\\myparser.y"

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
	
#line 1462 "myparser.cpp"
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
#line 728 ".\\myparser.y"

		//(1)谓词表达式

		//(2)条件表达式 a<b?a:b
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1484 "myparser.cpp"
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
#line 738 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	
	
#line 1506 "myparser.cpp"
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
#line 751 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("654 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1526 "myparser.cpp"
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
#line 759 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("661 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1546 "myparser.cpp"
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
#line 767 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("668 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1566 "myparser.cpp"
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
#line 775 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("675 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1586 "myparser.cpp"
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
#line 783 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("682 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1606 "myparser.cpp"
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
#line 791 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1626 "myparser.cpp"
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
#line 799 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("696 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1646 "myparser.cpp"
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
#line 807 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("703 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1666 "myparser.cpp"
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
#line 815 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("710 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1686 "myparser.cpp"
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
#line 823 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("717 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1706 "myparser.cpp"
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
#line 831 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("724 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1726 "myparser.cpp"
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
#line 842 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf(" ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1746 "myparser.cpp"
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
#line 850 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("741 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1768 "myparser.cpp"
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
#line 863 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("753 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_exp";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
	
#line 1790 "myparser.cpp"
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
#line 876 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("763 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1811 "myparser.cpp"
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
#line 885 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("771 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 1833 "myparser.cpp"
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
#line 901 ".\\myparser.y"
 //static
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("783 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 1853 "myparser.cpp"
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
#line 910 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("791 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1874 "myparser.cpp"
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
#line 919 ".\\myparser.y"
 // int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("799 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		type3->right = rFlag();	
	
#line 1895 "myparser.cpp"
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
#line 928 ".\\myparser.y"
 // lont int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("806 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1916 "myparser.cpp"
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
#line 937 ".\\myparser.y"
 //const
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("814 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 1936 "myparser.cpp"
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
#line 945 ".\\myparser.y"
 //const int
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("821 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 1957 "myparser.cpp"
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
#line 957 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("832 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1977 "myparser.cpp"
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
#line 965 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("839 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 1999 "myparser.cpp"
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
#line 978 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("851 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2019 "myparser.cpp"
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
#line 986 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("858 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;	

		//s.back()
	
#line 2043 "myparser.cpp"
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
#line 1001 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("870 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2063 "myparser.cpp"
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
#line 1009 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("877 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2083 "myparser.cpp"
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
#line 1017 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("884 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2103 "myparser.cpp"
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
#line 1025 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2123 "myparser.cpp"
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
#line 1033 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("898 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2143 "myparser.cpp"
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
#line 1044 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		wFlag(voidnode);
	
#line 2164 "myparser.cpp"
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
#line 1053 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("915 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(charnode);
	
#line 2185 "myparser.cpp"
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
#line 1062 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("922 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(shortnode);
	
#line 2206 "myparser.cpp"
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
#line 1071 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("929 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(intnode);
	
#line 2227 "myparser.cpp"
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
#line 1080 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("936 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(longnode);
	
#line 2248 "myparser.cpp"
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
#line 1089 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("943 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(floatnode);
	
#line 2269 "myparser.cpp"
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
#line 1098 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("950 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		wFlag(doublenode);
	
#line 2290 "myparser.cpp"
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
#line 1107 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("957 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(signednode);
	
#line 2311 "myparser.cpp"
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
#line 1116 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		wFlag(unsignednode);
	
#line 2332 "myparser.cpp"
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
#line 1125 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2352 "myparser.cpp"
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
#line 1133 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("978 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2372 "myparser.cpp"
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
#line 1141 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("985 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 2392 "myparser.cpp"
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
#line 1149 ".\\myparser.y"

		printf("999");
	
#line 2407 "myparser.cpp"
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
#line 1155 ".\\myparser.y"
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
		auto_define_type[yyattribute(2 - 6).ntnode->name] = temp;	
		traverse(temp);
		s.pop_back();
	
#line 2467 "myparser.cpp"
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
#line 1203 ".\\myparser.y"
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
	
#line 2493 "myparser.cpp"
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
#line 1217 ".\\myparser.y"
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
	
#line 2517 "myparser.cpp"
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
#line 1229 ".\\myparser.y"
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
	
#line 2542 "myparser.cpp"
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
#line 1242 ".\\myparser.y"
 // struct a
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1016 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2563 "myparser.cpp"
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
#line 1254 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1027 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2583 "myparser.cpp"
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
#line 1262 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1034 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2603 "myparser.cpp"
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
#line 1273 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1044 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 2623 "myparser.cpp"
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
#line 1281 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1051 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
	
#line 2644 "myparser.cpp"
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
#line 1293 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1062 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2666 "myparser.cpp"
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
#line 1303 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1062 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2688 "myparser.cpp"
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
#line 1316 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1074 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2709 "myparser.cpp"
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
#line 1325 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1082 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2729 "myparser.cpp"
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
#line 1333 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1089 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2750 "myparser.cpp"
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
#line 1342 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1097 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2770 "myparser.cpp"
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
#line 1353 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1107 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2790 "myparser.cpp"
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
#line 1361 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1114 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2812 "myparser.cpp"
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
#line 1374 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1126 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2832 "myparser.cpp"
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
#line 1382 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1133 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2853 "myparser.cpp"
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
#line 1391 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1141 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2875 "myparser.cpp"
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
#line 1404 ".\\myparser.y"
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
	
#line 2898 "myparser.cpp"
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
#line 1415 ".\\myparser.y"
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
	
#line 2922 "myparser.cpp"
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
#line 1427 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1174 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 2943 "myparser.cpp"
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
#line 1439 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1185 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 2963 "myparser.cpp"
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
#line 1447 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1192 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2985 "myparser.cpp"
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
#line 1460 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1204 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3005 "myparser.cpp"
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
#line 1468 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1211 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3027 "myparser.cpp"
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
#line 1481 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1223 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3047 "myparser.cpp"
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
#line 1489 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1230 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3067 "myparser.cpp"
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
#line 1500 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1240 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
	
#line 3088 "myparser.cpp"
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
#line 1509 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1248 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
	
#line 3108 "myparser.cpp"
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
#line 1521 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1258 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

		var_name = yyattribute(1 - 1).ntnode->name;
		s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
	
#line 3131 "myparser.cpp"
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
#line 1532 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1265 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3153 "myparser.cpp"
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
#line 1542 ".\\myparser.y"

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
		type = &temp;
		cout<<"******"<<endl;
		traverse(type);
	
#line 3185 "myparser.cpp"
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
#line 1562 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1284 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3207 "myparser.cpp"
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
#line 1572 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1293 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
	
#line 3230 "myparser.cpp"
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
#line 1583 ".\\myparser.y"

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
	
#line 3257 "myparser.cpp"
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
#line 1598 ".\\myparser.y"

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
	
#line 3283 "myparser.cpp"
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
#line 1615 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1325 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		typenode* temp = new typenode("pointer");
		temp->left=rFlag();
		flag = !flag;
		wFlag(*temp);
		//traverse(temp);
	
#line 3309 "myparser.cpp"
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
#line 1629 ".\\myparser.y"
 // *const
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3329 "myparser.cpp"
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
#line 1637 ".\\myparser.y"
 // **
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;

		typenode* temp = new typenode("pointer");
		temp->left = rFlag();
		flag = !flag;
		wFlag(*temp);
	
#line 3354 "myparser.cpp"
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
#line 1650 ".\\myparser.y"
 //*const*
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
	
#line 3374 "myparser.cpp"
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
#line 1661 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1359 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3394 "myparser.cpp"
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
#line 1669 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1366 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3415 "myparser.cpp"
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
#line 1682 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1378 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

		type3->left = rFlag();
		s.back()->vartable[var_name] = type3;
		traverse(type3);
	
#line 3439 "myparser.cpp"
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
#line 1694 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1385 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3461 "myparser.cpp"
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
#line 1707 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1397 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3481 "myparser.cpp"
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
#line 1715 ".\\myparser.y"

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
	
#line 3513 "myparser.cpp"
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
#line 1738 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1416 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3534 "myparser.cpp"
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
#line 1747 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1424 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3554 "myparser.cpp"
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
#line 1755 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1431 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3574 "myparser.cpp"
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
#line 1766 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1441 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
	
#line 3595 "myparser.cpp"
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
#line 1775 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1448 ");   
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		s.back()->vartable[yyattribute(3 - 3).ntnode->name] = rFlag();	
	
#line 3618 "myparser.cpp"
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
#line 1789 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1460 ");
	  	(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3638 "myparser.cpp"
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
#line 1797 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1467 ");  
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3659 "myparser.cpp"
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
#line 1809 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1478 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3679 "myparser.cpp"
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
#line 1817 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1485 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3699 "myparser.cpp"
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
#line 1825 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1492 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3720 "myparser.cpp"
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
#line 1837 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1503 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3742 "myparser.cpp"
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
#line 1847 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1512 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3763 "myparser.cpp"
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
#line 1856 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1520 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3785 "myparser.cpp"
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
#line 1866 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1529 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3807 "myparser.cpp"
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
#line 1876 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1538 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3830 "myparser.cpp"
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
#line 1887 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1548 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3851 "myparser.cpp"
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
#line 1896 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1556 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3873 "myparser.cpp"
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
#line 1906 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1565 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3895 "myparser.cpp"
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
#line 1916 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1574 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3918 "myparser.cpp"
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
#line 1930 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1587 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3938 "myparser.cpp"
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
#line 1938 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1594 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3960 "myparser.cpp"
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
#line 1948 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1603 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
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
	case 174:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1962 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1616 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4003 "myparser.cpp"
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
#line 1970 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1623 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4025 "myparser.cpp"
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
#line 1982 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4045 "myparser.cpp"
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
#line 1990 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4065 "myparser.cpp"
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
#line 1998 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4085 "myparser.cpp"
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
#line 2006 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4105 "myparser.cpp"
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
#line 2014 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4125 "myparser.cpp"
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
#line 2024 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1635 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4145 "myparser.cpp"
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
#line 2032 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1642 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4165 "myparser.cpp"
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
#line 2040 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1649 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4185 "myparser.cpp"
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
#line 2048 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1656 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4205 "myparser.cpp"
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
#line 2056 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1663 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4225 "myparser.cpp"
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
#line 2064 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1670 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4245 "myparser.cpp"
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
#line 2075 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1680 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4267 "myparser.cpp"
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
#line 2085 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1689 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4290 "myparser.cpp"
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
#line 2096 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1699 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4312 "myparser.cpp"
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
#line 2109 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1711 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4333 "myparser.cpp"
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
#line 2118 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1719 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4355 "myparser.cpp"
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
#line 2128 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1728 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4377 "myparser.cpp"
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
#line 2138 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1737 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;		
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 4400 "myparser.cpp"
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
#line 2152 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1750 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4420 "myparser.cpp"
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
#line 2160 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1757 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4441 "myparser.cpp"
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
#line 2172 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1768 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4461 "myparser.cpp"
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
#line 2180 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1775 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4482 "myparser.cpp"
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
#line 2192 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1786 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4502 "myparser.cpp"
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
#line 2200 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1793 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4523 "myparser.cpp"
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
#line 2211 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1794 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4543 "myparser.cpp"
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
#line 2219 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1795 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4563 "myparser.cpp"
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
#line 2229 ".\\myparser.y"

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
	
#line 4589 "myparser.cpp"
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
#line 2243 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1815 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4609 "myparser.cpp"
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
#line 2253 ".\\myparser.y"

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
	
#line 4633 "myparser.cpp"
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
#line 2265 ".\\myparser.y"

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
	
#line 4659 "myparser.cpp"
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
#line 2281 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1816 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4679 "myparser.cpp"
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
#line 2289 ".\\myparser.y"

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
	
#line 4703 "myparser.cpp"
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
#line 2304 ".\\myparser.y"

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
	
#line 4727 "myparser.cpp"
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
#line 2316 ".\\myparser.y"

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
	
#line 4753 "myparser.cpp"
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
#line 2330 ".\\myparser.y"

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
	
#line 4783 "myparser.cpp"
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
#line 2348 ".\\myparser.y"

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
	
#line 4815 "myparser.cpp"
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
#line 2371 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1891 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4837 "myparser.cpp"
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
#line 2381 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1900 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4858 "myparser.cpp"
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
#line 2390 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1908 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4879 "myparser.cpp"
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
#line 2399 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1916 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4900 "myparser.cpp"
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
#line 2408 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1924 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4922 "myparser.cpp"
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
#line 2421 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1946 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		cout<<endl;
		// traverse($$);
	
#line 4944 "myparser.cpp"
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
#line 2431 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1953 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		cout<<endl;
		// traverse($$);
	
#line 4967 "myparser.cpp"
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
#line 2445 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1964 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4987 "myparser.cpp"
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
#line 2453 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1971 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 5007 "myparser.cpp"
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
#line 2464 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1981 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 5030 "myparser.cpp"
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
#line 2475 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("1991 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 5052 "myparser.cpp"
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
#line 2485 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2000 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 5074 "myparser.cpp"
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
#line 2495 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
		printf("2009 ");
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 5095 "myparser.cpp"
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

	yytokenaction_size = 408;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 349, YYAT_SHIFT, 70 },
		{ 109, YYAT_SHIFT, 194 },
		{ 264, YYAT_SHIFT, 176 },
		{ 124, YYAT_SHIFT, 218 },
		{ 264, YYAT_SHIFT, 177 },
		{ 349, YYAT_SHIFT, 71 },
		{ 228, YYAT_SHIFT, 224 },
		{ 349, YYAT_SHIFT, 72 },
		{ 322, YYAT_ERROR, 0 },
		{ 349, YYAT_SHIFT, 73 },
		{ 349, YYAT_SHIFT, 74 },
		{ 55, YYAT_SHIFT, 142 },
		{ 349, YYAT_SHIFT, 75 },
		{ 40, YYAT_SHIFT, 2 },
		{ 302, YYAT_SHIFT, 1 },
		{ 297, YYAT_SHIFT, 295 },
		{ 302, YYAT_SHIFT, 2 },
		{ 298, YYAT_SHIFT, 322 },
		{ 242, YYAT_SHIFT, 241 },
		{ 274, YYAT_SHIFT, 212 },
		{ 152, YYAT_SHIFT, 150 },
		{ 326, YYAT_SHIFT, 145 },
		{ 175, YYAT_SHIFT, 212 },
		{ 37, YYAT_SHIFT, 61 },
		{ 23, YYAT_SHIFT, 42 },
		{ 227, YYAT_SHIFT, 295 },
		{ 349, YYAT_SHIFT, 76 },
		{ 241, YYAT_SHIFT, 241 },
		{ 241, YYAT_SHIFT, 290 },
		{ 241, YYAT_SHIFT, 2 },
		{ 29, YYAT_ACCEPT, 0 },
		{ 49, YYAT_SHIFT, 50 },
		{ 153, YYAT_SHIFT, 241 },
		{ 302, YYAT_SHIFT, 325 },
		{ 153, YYAT_SHIFT, 2 },
		{ 28, YYAT_SHIFT, 50 },
		{ 326, YYAT_SHIFT, 345 },
		{ 175, YYAT_SHIFT, 258 },
		{ 136, YYAT_SHIFT, 224 },
		{ 224, YYAT_SHIFT, 224 },
		{ 136, YYAT_SHIFT, 2 },
		{ 285, YYAT_SHIFT, 212 },
		{ 35, YYAT_SHIFT, 2 },
		{ 278, YYAT_SHIFT, 186 },
		{ 338, YYAT_SHIFT, 349 },
		{ 278, YYAT_SHIFT, 187 },
		{ 269, YYAT_SHIFT, 183 },
		{ 338, YYAT_SHIFT, 212 },
		{ 50, YYAT_SHIFT, 130 },
		{ 2, YYAT_SHIFT, 2 },
		{ 277, YYAT_SHIFT, 186 },
		{ 269, YYAT_SHIFT, 184 },
		{ 277, YYAT_SHIFT, 187 },
		{ 268, YYAT_SHIFT, 183 },
		{ 347, YYAT_SHIFT, 352 },
		{ 285, YYAT_SHIFT, 314 },
		{ 269, YYAT_SHIFT, 185 },
		{ 228, YYAT_SHIFT, 225 },
		{ 268, YYAT_SHIFT, 184 },
		{ 263, YYAT_SHIFT, 176 },
		{ 346, YYAT_ERROR, 0 },
		{ 263, YYAT_SHIFT, 177 },
		{ 271, YYAT_SHIFT, 311 },
		{ 268, YYAT_SHIFT, 185 },
		{ 135, YYAT_SHIFT, 222 },
		{ 271, YYAT_SHIFT, 312 },
		{ 297, YYAT_SHIFT, 296 },
		{ 135, YYAT_SHIFT, 223 },
		{ 274, YYAT_SHIFT, 313 },
		{ 242, YYAT_SHIFT, 225 },
		{ 29, YYAT_SHIFT, 1 },
		{ 29, YYAT_ERROR, 0 },
		{ 322, YYAT_SHIFT, 231 },
		{ 55, YYAT_SHIFT, 44 },
		{ 322, YYAT_SHIFT, 343 },
		{ 106, YYAT_SHIFT, 186 },
		{ 227, YYAT_SHIFT, 296 },
		{ 106, YYAT_SHIFT, 187 },
		{ 241, YYAT_SHIFT, 225 },
		{ 281, YYAT_SHIFT, 180 },
		{ 281, YYAT_SHIFT, 181 },
		{ 336, YYAT_SHIFT, 347 },
		{ 49, YYAT_SHIFT, 51 },
		{ 153, YYAT_SHIFT, 225 },
		{ 327, YYAT_SHIFT, 346 },
		{ 107, YYAT_SHIFT, 188 },
		{ 28, YYAT_SHIFT, 51 },
		{ 295, YYAT_ERROR, 0 },
		{ 321, YYAT_SHIFT, 342 },
		{ 136, YYAT_SHIFT, 225 },
		{ 349, YYAT_SHIFT, 44 },
		{ 107, YYAT_SHIFT, 189 },
		{ 295, YYAT_ERROR, 0 },
		{ 349, YYAT_SHIFT, 78 },
		{ 295, YYAT_ERROR, 0 },
		{ 295, YYAT_SHIFT, 318 },
		{ 295, YYAT_ERROR, 0 },
		{ 295, YYAT_ERROR, 0 },
		{ 298, YYAT_SHIFT, 323 },
		{ 295, YYAT_ERROR, 0 },
		{ 159, YYAT_SHIFT, 4 },
		{ 152, YYAT_SHIFT, 240 },
		{ 319, YYAT_SHIFT, 341 },
		{ 101, YYAT_SHIFT, 176 },
		{ 114, YYAT_SHIFT, 76 },
		{ 101, YYAT_SHIFT, 177 },
		{ 159, YYAT_SHIFT, 10 },
		{ 159, YYAT_SHIFT, 11 },
		{ 159, YYAT_SHIFT, 12 },
		{ 159, YYAT_SHIFT, 13 },
		{ 159, YYAT_SHIFT, 14 },
		{ 159, YYAT_SHIFT, 15 },
		{ 159, YYAT_SHIFT, 16 },
		{ 159, YYAT_SHIFT, 17 },
		{ 159, YYAT_SHIFT, 18 },
		{ 159, YYAT_SHIFT, 19 },
		{ 159, YYAT_SHIFT, 20 },
		{ 159, YYAT_SHIFT, 21 },
		{ 159, YYAT_SHIFT, 22 },
		{ 159, YYAT_SHIFT, 23 },
		{ 157, YYAT_SHIFT, 2 },
		{ 29, YYAT_ERROR, 0 },
		{ 105, YYAT_SHIFT, 183 },
		{ 262, YYAT_SHIFT, 206 },
		{ 262, YYAT_SHIFT, 207 },
		{ 261, YYAT_SHIFT, 206 },
		{ 261, YYAT_SHIFT, 207 },
		{ 105, YYAT_SHIFT, 184 },
		{ 260, YYAT_SHIFT, 206 },
		{ 260, YYAT_SHIFT, 207 },
		{ 259, YYAT_SHIFT, 206 },
		{ 259, YYAT_SHIFT, 207 },
		{ 105, YYAT_SHIFT, 185 },
		{ 110, YYAT_SHIFT, 206 },
		{ 110, YYAT_SHIFT, 207 },
		{ 314, YYAT_ERROR, 0 },
		{ 107, YYAT_SHIFT, 190 },
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
		{ 37, YYAT_SHIFT, 62 },
		{ 23, YYAT_SHIFT, 43 },
		{ 102, YYAT_SHIFT, 180 },
		{ 102, YYAT_SHIFT, 181 },
		{ 310, YYAT_SHIFT, 337 },
		{ 301, YYAT_SHIFT, 324 },
		{ 296, YYAT_SHIFT, 320 },
		{ 294, YYAT_SHIFT, 317 },
		{ 292, YYAT_SHIFT, 316 },
		{ 291, YYAT_SHIFT, 315 },
		{ 286, YYAT_SHIFT, 216 },
		{ 114, YYAT_SHIFT, 44 },
		{ 284, YYAT_SHIFT, 215 },
		{ 114, YYAT_SHIFT, 208 },
		{ 283, YYAT_SHIFT, 217 },
		{ 282, YYAT_SHIFT, 214 },
		{ 256, YYAT_SHIFT, 76 },
		{ 255, YYAT_SHIFT, 309 },
		{ 254, YYAT_SHIFT, 308 },
		{ 253, YYAT_SHIFT, 307 },
		{ 252, YYAT_SHIFT, 306 },
		{ 249, YYAT_SHIFT, 304 },
		{ 237, YYAT_SHIFT, 302 },
		{ 295, YYAT_ERROR, 0 },
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
		{ 236, YYAT_SHIFT, 300 },
		{ 231, YYAT_ERROR, 0 },
		{ 225, YYAT_SHIFT, 293 },
		{ 223, YYAT_SHIFT, 289 },
		{ 220, YYAT_SHIFT, 287 },
		{ 322, YYAT_SHIFT, 138 },
		{ 209, YYAT_SHIFT, 279 },
		{ 264, YYAT_SHIFT, 178 },
		{ 264, YYAT_SHIFT, 179 },
		{ 191, YYAT_SHIFT, 275 },
		{ 124, YYAT_SHIFT, 219 },
		{ 109, YYAT_SHIFT, 195 },
		{ 109, YYAT_SHIFT, 196 },
		{ 109, YYAT_SHIFT, 197 },
		{ 109, YYAT_SHIFT, 198 },
		{ 109, YYAT_SHIFT, 199 },
		{ 109, YYAT_SHIFT, 200 },
		{ 109, YYAT_SHIFT, 201 },
		{ 109, YYAT_SHIFT, 202 },
		{ 109, YYAT_SHIFT, 203 },
		{ 109, YYAT_SHIFT, 204 },
		{ 189, YYAT_SHIFT, 273 },
		{ 228, YYAT_SHIFT, 3 },
		{ 349, YYAT_SHIFT, 79 },
		{ 349, YYAT_SHIFT, 80 },
		{ 349, YYAT_SHIFT, 81 },
		{ 349, YYAT_SHIFT, 82 },
		{ 188, YYAT_SHIFT, 270 },
		{ 349, YYAT_SHIFT, 83 },
		{ 349, YYAT_SHIFT, 84 },
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
		{ 136, YYAT_SHIFT, 3 },
		{ 224, YYAT_SHIFT, 3 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 322, YYAT_ERROR, 0 },
		{ 50, YYAT_SHIFT, 131 },
		{ 263, YYAT_SHIFT, 178 },
		{ 263, YYAT_SHIFT, 179 },
		{ 40, YYAT_SHIFT, 18 },
		{ 40, YYAT_SHIFT, 19 },
		{ 171, YYAT_SHIFT, 257 },
		{ 349, YYAT_SHIFT, 85 },
		{ 349, YYAT_SHIFT, 86 },
		{ 349, YYAT_SHIFT, 87 },
		{ 169, YYAT_SHIFT, 255 },
		{ 349, YYAT_SHIFT, 88 },
		{ 349, YYAT_SHIFT, 89 },
		{ 349, YYAT_SHIFT, 90 },
		{ 349, YYAT_SHIFT, 91 },
		{ 349, YYAT_SHIFT, 92 },
		{ 349, YYAT_SHIFT, 93 },
		{ 349, YYAT_SHIFT, 94 },
		{ 349, YYAT_SHIFT, 95 },
		{ 35, YYAT_SHIFT, 4 },
		{ 35, YYAT_SHIFT, 5 },
		{ 35, YYAT_SHIFT, 6 },
		{ 35, YYAT_SHIFT, 7 },
		{ 35, YYAT_SHIFT, 8 },
		{ 35, YYAT_SHIFT, 9 },
		{ 35, YYAT_SHIFT, 10 },
		{ 35, YYAT_SHIFT, 11 },
		{ 35, YYAT_SHIFT, 12 },
		{ 35, YYAT_SHIFT, 13 },
		{ 35, YYAT_SHIFT, 14 },
		{ 35, YYAT_SHIFT, 15 },
		{ 35, YYAT_SHIFT, 16 },
		{ 35, YYAT_SHIFT, 17 },
		{ 35, YYAT_SHIFT, 18 },
		{ 35, YYAT_SHIFT, 19 },
		{ 35, YYAT_SHIFT, 20 },
		{ 35, YYAT_SHIFT, 21 },
		{ 35, YYAT_SHIFT, 22 },
		{ 35, YYAT_SHIFT, 23 },
		{ 114, YYAT_SHIFT, 79 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 164, YYAT_SHIFT, 250 },
		{ 107, YYAT_SHIFT, 191 },
		{ 107, YYAT_SHIFT, 192 },
		{ 107, YYAT_SHIFT, 193 },
		{ 101, YYAT_SHIFT, 178 },
		{ 101, YYAT_SHIFT, 179 },
		{ 295, YYAT_ERROR, 0 },
		{ 295, YYAT_ERROR, 0 },
		{ 295, YYAT_ERROR, 0 },
		{ 295, YYAT_ERROR, 0 },
		{ 156, YYAT_SHIFT, 246 },
		{ 295, YYAT_ERROR, 0 },
		{ 295, YYAT_ERROR, 0 },
		{ 154, YYAT_SHIFT, 244 },
		{ 150, YYAT_SHIFT, 66 },
		{ 148, YYAT_ERROR, 0 },
		{ 147, YYAT_SHIFT, 236 },
		{ 145, YYAT_ERROR, 0 },
		{ 144, YYAT_SHIFT, 44 },
		{ 140, YYAT_SHIFT, 230 },
		{ 134, YYAT_SHIFT, 221 },
		{ 132, YYAT_SHIFT, 220 },
		{ 129, YYAT_SHIFT, 142 },
		{ 114, YYAT_SHIFT, 5 },
		{ 114, YYAT_SHIFT, 6 },
		{ 114, YYAT_SHIFT, 7 },
		{ 114, YYAT_SHIFT, 8 },
		{ 114, YYAT_SHIFT, 9 },
		{ 123, YYAT_SHIFT, 217 },
		{ 122, YYAT_SHIFT, 216 },
		{ 121, YYAT_SHIFT, 215 },
		{ 120, YYAT_SHIFT, 214 },
		{ 295, YYAT_SHIFT, 5 },
		{ 295, YYAT_SHIFT, 6 },
		{ 295, YYAT_SHIFT, 7 },
		{ 295, YYAT_SHIFT, 8 },
		{ 295, YYAT_SHIFT, 9 },
		{ 119, YYAT_SHIFT, 213 },
		{ 115, YYAT_SHIFT, 210 },
		{ 95, YYAT_SHIFT, 174 },
		{ 94, YYAT_SHIFT, 173 },
		{ 93, YYAT_SHIFT, 172 },
		{ 92, YYAT_SHIFT, 171 },
		{ 114, YYAT_SHIFT, 85 },
		{ 114, YYAT_SHIFT, 86 },
		{ 114, YYAT_SHIFT, 87 },
		{ 91, YYAT_SHIFT, 170 },
		{ 114, YYAT_SHIFT, 88 },
		{ 114, YYAT_SHIFT, 89 },
		{ 114, YYAT_SHIFT, 90 },
		{ 114, YYAT_SHIFT, 91 },
		{ 114, YYAT_SHIFT, 92 },
		{ 114, YYAT_SHIFT, 93 },
		{ 114, YYAT_SHIFT, 94 },
		{ 114, YYAT_SHIFT, 95 },
		{ 157, YYAT_SHIFT, 4 },
		{ 89, YYAT_SHIFT, 168 },
		{ 88, YYAT_SHIFT, 167 },
		{ 87, YYAT_SHIFT, 166 },
		{ 86, YYAT_SHIFT, 165 },
		{ 84, YYAT_SHIFT, 161 },
		{ 157, YYAT_SHIFT, 10 },
		{ 157, YYAT_SHIFT, 11 },
		{ 157, YYAT_SHIFT, 12 },
		{ 157, YYAT_SHIFT, 13 },
		{ 157, YYAT_SHIFT, 14 },
		{ 157, YYAT_SHIFT, 15 },
		{ 157, YYAT_SHIFT, 16 },
		{ 157, YYAT_SHIFT, 17 },
		{ 157, YYAT_SHIFT, 18 },
		{ 157, YYAT_SHIFT, 19 },
		{ 157, YYAT_SHIFT, 20 },
		{ 157, YYAT_SHIFT, 21 },
		{ 157, YYAT_SHIFT, 22 },
		{ 157, YYAT_SHIFT, 23 },
		{ 155, YYAT_SHIFT, 4 },
		{ 82, YYAT_SHIFT, 159 },
		{ 79, YYAT_SHIFT, 158 },
		{ 67, YYAT_SHIFT, 151 },
		{ 66, YYAT_SHIFT, 149 },
		{ 62, YYAT_SHIFT, 148 },
		{ 155, YYAT_SHIFT, 10 },
		{ 155, YYAT_SHIFT, 11 },
		{ 155, YYAT_SHIFT, 12 },
		{ 155, YYAT_SHIFT, 13 },
		{ 155, YYAT_SHIFT, 14 },
		{ 155, YYAT_SHIFT, 15 },
		{ 155, YYAT_SHIFT, 16 },
		{ 155, YYAT_SHIFT, 17 },
		{ 155, YYAT_SHIFT, 18 },
		{ 155, YYAT_SHIFT, 19 },
		{ 155, YYAT_SHIFT, 20 },
		{ 155, YYAT_SHIFT, 21 },
		{ 155, YYAT_SHIFT, 22 },
		{ 155, YYAT_SHIFT, 23 },
		{ 56, YYAT_SHIFT, 146 },
		{ 51, YYAT_SHIFT, 137 },
		{ 48, YYAT_SHIFT, 54 },
		{ 44, YYAT_SHIFT, 77 },
		{ 43, YYAT_SHIFT, 69 },
		{ 38, YYAT_SHIFT, 63 },
		{ 27, YYAT_ERROR, 0 },
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 407, 1, YYAT_DEFAULT, 29 },
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
		{ -99, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 364, 1, YYAT_DEFAULT, 145 },
		{ -5, 1, YYAT_REDUCE, 135 },
		{ 30, 1, YYAT_DEFAULT, 224 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ -101, 1, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ 0, 0, YYAT_DEFAULT, 48 },
		{ -145, 1, YYAT_REDUCE, 77 },
		{ 0, 1, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ -100, 1, YYAT_ERROR, 0 },
		{ 364, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ -29, 1, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ 281, 1, YYAT_REDUCE, 127 },
		{ 278, 1, YYAT_DEFAULT, 114 },
		{ 0, 0, YYAT_REDUCE, 225 },
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 343, 1, YYAT_DEFAULT, 302 },
		{ -9, 1, YYAT_REDUCE, 134 },
		{ 7, 1, YYAT_DEFAULT, 295 },
		{ 308, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 219 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ -50, 1, YYAT_REDUCE, 85 },
		{ 341, 1, YYAT_DEFAULT, 326 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_DEFAULT, 148 },
		{ 262, 1, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 323, 1, YYAT_REDUCE, 130 },
		{ 258, 1, YYAT_DEFAULT, 152 },
		{ 0, 0, YYAT_REDUCE, 128 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 159 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 324, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 341, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 84 },
		{ 325, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 306, 1, YYAT_ERROR, 0 },
		{ 323, 1, YYAT_ERROR, 0 },
		{ 322, 1, YYAT_ERROR, 0 },
		{ 321, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 311, 1, YYAT_ERROR, 0 },
		{ 90, 1, YYAT_ERROR, 0 },
		{ 287, 1, YYAT_ERROR, 0 },
		{ 286, 1, YYAT_ERROR, 0 },
		{ 285, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 43, 1, YYAT_REDUCE, 44 },
		{ -109, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 85, 1, YYAT_REDUCE, 33 },
		{ 32, 1, YYAT_REDUCE, 36 },
		{ 45, 1, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -60, 1, YYAT_REDUCE, 27 },
		{ -131, 1, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 45, 1, YYAT_DEFAULT, 159 },
		{ 218, 1, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 283, 1, YYAT_DEFAULT, 175 },
		{ 298, 1, YYAT_REDUCE, 49 },
		{ 241, 1, YYAT_REDUCE, 51 },
		{ 64, 1, YYAT_REDUCE, 55 },
		{ 209, 1, YYAT_REDUCE, 53 },
		{ -60, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 266, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 0, 0, YYAT_REDUCE, 156 },
		{ 282, 1, YYAT_REDUCE, 149 },
		{ 0, 0, YYAT_REDUCE, 151 },
		{ 284, 1, YYAT_ERROR, 0 },
		{ 23, 1, YYAT_ERROR, 0 },
		{ -2, 1, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 231, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_DEFAULT, 231 },
		{ 0, 0, YYAT_REDUCE, 223 },
		{ 200, 1, YYAT_DEFAULT, 148 },
		{ 263, 1, YYAT_DEFAULT, 302 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 196, 1, YYAT_DEFAULT, 237 },
		{ 279, 1, YYAT_DEFAULT, 295 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 62, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ -24, 1, YYAT_ERROR, 0 },
		{ -8, 1, YYAT_REDUCE, 158 },
		{ 277, 1, YYAT_ERROR, 0 },
		{ 98, 1, YYAT_REDUCE, 119 },
		{ 274, 1, YYAT_DEFAULT, 338 },
		{ 78, 1, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ -182, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 247, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ -35, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 256 },
		{ 210, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ 0, 0, YYAT_REDUCE, 216 },
		{ -22, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 187, 1, YYAT_DEFAULT, 314 },
		{ -35, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ -47, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
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
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 82, 1, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ -97, 1, YYAT_DEFAULT, 148 },
		{ 0, 0, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ -53, 1, YYAT_ERROR, 0 },
		{ -1, 1, YYAT_DEFAULT, 241 },
		{ 110, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ -15, 1, YYAT_REDUCE, 161 },
		{ -34, 1, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 77, 1, YYAT_DEFAULT, 322 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 142, 1, YYAT_DEFAULT, 302 },
		{ 54, 1, YYAT_DEFAULT, 148 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ 0, 0, YYAT_REDUCE, 129 },
		{ 0, 0, YYAT_REDUCE, 126 },
		{ -13, 1, YYAT_DEFAULT, 295 },
		{ -22, 1, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 137, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 136, 1, YYAT_DEFAULT, 338 },
		{ 135, 1, YYAT_DEFAULT, 338 },
		{ 134, 1, YYAT_DEFAULT, 338 },
		{ 134, 1, YYAT_ERROR, 0 },
		{ 114, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 0, 0, YYAT_REDUCE, 217 },
		{ -134, 1, YYAT_REDUCE, 40 },
		{ -136, 1, YYAT_REDUCE, 41 },
		{ -139, 1, YYAT_REDUCE, 42 },
		{ -141, 1, YYAT_REDUCE, 43 },
		{ -1, 1, YYAT_REDUCE, 45 },
		{ -58, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 16, 1, YYAT_REDUCE, 34 },
		{ 9, 1, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 21, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 7, 1, YYAT_REDUCE, 37 },
		{ 0, 1, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ -189, 1, YYAT_REDUCE, 48 },
		{ 134, 1, YYAT_REDUCE, 50 },
		{ 47, 1, YYAT_REDUCE, 54 },
		{ 75, 1, YYAT_REDUCE, 52 },
		{ -3, 1, YYAT_ERROR, 0 },
		{ -103, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ 125, 1, YYAT_ERROR, 0 },
		{ 124, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 71, 1, YYAT_ERROR, 0 },
		{ 54, 1, YYAT_DEFAULT, 159 },
		{ 70, 1, YYAT_DEFAULT, 314 },
		{ -25, 1, YYAT_REDUCE, 162 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 103, 1, YYAT_DEFAULT, 326 },
		{ -26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_DEFAULT, 346 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 120, 1, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 314 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 12, 1, YYAT_DEFAULT, 231 },
		{ 0, 0, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 0, 0, YYAT_REDUCE, 165 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 61, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ -5, 1, YYAT_ERROR, 0 },
		{ -51, 1, YYAT_DEFAULT, 346 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ -23, 1, YYAT_ERROR, 0 },
		{ -222, 1, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 40, 1, YYAT_DEFAULT, 338 },
		{ 0, 0, YYAT_DEFAULT, 349 },
		{ 3, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 0, 0, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ -247, 1, YYAT_DEFAULT, 349 },
		{ -5, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ -33, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 212 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 233;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 349, 109 },
		{ 322, 233 },
		{ 256, 119 },
		{ 322, -1 },
		{ 312, 339 },
		{ 349, 110 },
		{ 349, 101 },
		{ 349, 102 },
		{ 349, 120 },
		{ 349, 121 },
		{ 349, 123 },
		{ 349, 122 },
		{ 349, 124 },
		{ 349, 125 },
		{ 349, 126 },
		{ 188, 271 },
		{ 349, 119 },
		{ 346, -1 },
		{ 346, 333 },
		{ 346, 330 },
		{ 220, 136 },
		{ 337, 348 },
		{ 346, 329 },
		{ 346, -1 },
		{ 346, 351 },
		{ 346, 350 },
		{ 346, -1 },
		{ 346, 331 },
		{ 346, 332 },
		{ 44, 47 },
		{ 188, 272 },
		{ 1, -1 },
		{ 309, 336 },
		{ 322, 344 },
		{ 35, 60 },
		{ 322, -1 },
		{ 312, -1 },
		{ 322, -1 },
		{ 322, -1 },
		{ 148, 47 },
		{ 256, 310 },
		{ 322, -1 },
		{ 220, 288 },
		{ 322, -1 },
		{ 322, -1 },
		{ 1, 38 },
		{ 322, -1 },
		{ 322, -1 },
		{ 349, 98 },
		{ 349, 353 },
		{ 349, 118 },
		{ 349, 112 },
		{ 35, 59 },
		{ 308, 335 },
		{ 349, 111 },
		{ 349, 100 },
		{ 349, 99 },
		{ 349, 97 },
		{ 349, 96 },
		{ 349, 113 },
		{ 349, 116 },
		{ 114, 128 },
		{ 114, 48 },
		{ 44, 114 },
		{ 44, 115 },
		{ 114, 34 },
		{ 114, 35 },
		{ 114, 36 },
		{ 114, 37 },
		{ 29, 32 },
		{ 29, 33 },
		{ 296, 141 },
		{ 307, 334 },
		{ 148, 237 },
		{ 114, 26 },
		{ 296, 321 },
		{ 157, -1 },
		{ 114, 31 },
		{ 295, 136 },
		{ 157, -1 },
		{ 157, 157 },
		{ 295, 34 },
		{ 295, 35 },
		{ 295, 36 },
		{ 295, 37 },
		{ 157, 247 },
		{ 29, 25 },
		{ 29, 28 },
		{ 29, 27 },
		{ 250, 305 },
		{ 295, 26 },
		{ 157, 155 },
		{ 114, 117 },
		{ 295, 31 },
		{ 237, 128 },
		{ 237, 48 },
		{ 114, 209 },
		{ 314, 139 },
		{ 295, 319 },
		{ 295, 132 },
		{ 295, 133 },
		{ 159, 157 },
		{ 159, 36 },
		{ 159, 37 },
		{ 231, 299 },
		{ 231, 298 },
		{ 159, 153 },
		{ 302, 326 },
		{ 302, 57 },
		{ 159, 26 },
		{ 314, 340 },
		{ 314, -1 },
		{ 159, 155 },
		{ 29, 52 },
		{ 29, 24 },
		{ 237, -1 },
		{ 237, -1 },
		{ 237, -1 },
		{ 136, 226 },
		{ 136, 28 },
		{ 136, 228 },
		{ 159, 249 },
		{ 302, 129 },
		{ 302, 28 },
		{ 302, 27 },
		{ 244, 108 },
		{ 244, 107 },
		{ 136, 229 },
		{ 244, 139 },
		{ 244, 103 },
		{ 244, 303 },
		{ 241, 242 },
		{ 242, 297 },
		{ 241, 291 },
		{ 153, 242 },
		{ 155, 245 },
		{ 236, 301 },
		{ 50, 134 },
		{ 241, 292 },
		{ 241, 227 },
		{ 50, 135 },
		{ 153, 243 },
		{ 153, 227 },
		{ 2, 41 },
		{ 155, -1 },
		{ 228, 49 },
		{ 2, 39 },
		{ 2, 40 },
		{ 306, 328 },
		{ 306, 327 },
		{ 306, 97 },
		{ 224, 38 },
		{ 224, 28 },
		{ 224, 228 },
		{ 219, 286 },
		{ 219, -1 },
		{ 219, -1 },
		{ 40, 65 },
		{ 225, 294 },
		{ 310, 126 },
		{ 40, 64 },
		{ 310, 338 },
		{ 84, 163 },
		{ 218, 285 },
		{ 84, -1 },
		{ 217, 284 },
		{ 217, -1 },
		{ 216, 283 },
		{ 216, -1 },
		{ 215, 282 },
		{ 215, -1 },
		{ 214, 281 },
		{ 214, -1 },
		{ 207, 105 },
		{ 207, 278 },
		{ 187, 104 },
		{ 187, 269 },
		{ 181, 264 },
		{ 181, -1 },
		{ 179, 106 },
		{ 179, 262 },
		{ 145, -1 },
		{ 145, 235 },
		{ 69, 152 },
		{ 69, 68 },
		{ 55, 143 },
		{ 55, 144 },
		{ 34, -1 },
		{ 34, 58 },
		{ 25, 45 },
		{ 25, 46 },
		{ 0, 29 },
		{ 0, 30 },
		{ 212, 280 },
		{ 209, 211 },
		{ 206, 277 },
		{ 205, 276 },
		{ 190, 274 },
		{ 186, 268 },
		{ 185, 267 },
		{ 184, 266 },
		{ 183, 265 },
		{ 180, 263 },
		{ 178, 261 },
		{ 177, 260 },
		{ 176, 259 },
		{ 170, 256 },
		{ 168, 254 },
		{ 167, 253 },
		{ 166, 252 },
		{ 165, 251 },
		{ 161, 156 },
		{ 158, 248 },
		{ 150, 239 },
		{ 149, 238 },
		{ 144, 234 },
		{ 142, 232 },
		{ 109, 205 },
		{ 103, 182 },
		{ 95, 175 },
		{ 90, 169 },
		{ 85, 164 },
		{ 83, 162 },
		{ 82, 160 },
		{ 72, 154 },
		{ 61, 147 },
		{ 51, 140 },
		{ 48, 56 },
		{ 46, 127 },
		{ 42, 67 },
		{ 33, 55 },
		{ 31, 53 },
		{ 27, 49 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 126, 29 },
		{ 6, 145 },
		{ 105, -1 },
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
		{ 134, 148 },
		{ 0, -1 },
		{ 192, -1 },
		{ 0, -1 },
		{ 47, 237 },
		{ 0, -1 },
		{ 208, 34 },
		{ 0, -1 },
		{ 191, 48 },
		{ 165, 237 },
		{ 11, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 119, -1 },
		{ 0, -1 },
		{ 193, 69 },
		{ 0, -1 },
		{ 7, 114 },
		{ 0, -1 },
		{ 173, 237 },
		{ 0, -1 },
		{ 203, 302 },
		{ 0, -1 },
		{ 94, 295 },
		{ 205, 296 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 130, 148 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 169, 148 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 147, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 177, 159 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 219, 84 },
		{ 218, 84 },
		{ 158, 244 },
		{ 200, 296 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 167, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 199, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 212, 244 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 198, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 349 },
		{ 0, 209 },
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
		{ 79, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 166, 322 },
		{ 0, -1 },
		{ 160, 237 },
		{ 157, 302 },
		{ 0, -1 },
		{ 0, 237 },
		{ 17, 237 },
		{ 193, 296 },
		{ 176, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 93, -1 },
		{ 0, -1 },
		{ 103, 157 },
		{ 0, -1 },
		{ 53, 35 },
		{ 159, 349 },
		{ 74, 161 },
		{ 0, -1 },
		{ 191, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 157, 349 },
		{ 189, 310 },
		{ 188, 310 },
		{ 187, 310 },
		{ 0, -1 },
		{ 148, 256 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 196, 179 },
		{ 195, 179 },
		{ 194, 179 },
		{ 171, 207 },
		{ 192, 181 },
		{ 167, 214 },
		{ 0, -1 },
		{ 195, 244 },
		{ 194, 244 },
		{ 193, 244 },
		{ 191, 187 },
		{ 169, 244 },
		{ 12, 312 },
		{ 0, -1 },
		{ 177, 310 },
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
		{ 178, 312 },
		{ 187, 207 },
		{ 166, 187 },
		{ 0, -1 },
		{ 141, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 175, 312 },
		{ 0, -1 },
		{ 160, 215 },
		{ 157, 217 },
		{ 153, 219 },
		{ 152, 216 },
		{ 143, 310 },
		{ 139, 314 },
		{ -3, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 112, 241 },
		{ 137, 296 },
		{ 0, -1 },
		{ 0, -1 },
		{ 105, 242 },
		{ 0, -1 },
		{ 0, -1 },
		{ 54, 322 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 112, 302 },
		{ 72, 295 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 90, 295 },
		{ 83, -1 },
		{ 0, -1 },
		{ 124, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 36, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -18, 310 },
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
		{ 55, -1 },
		{ 54, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 83, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 89, 346 },
		{ 19, 349 },
		{ 0, 349 },
		{ 12, 310 },
		{ 141, 312 },
		{ 0, -1 },
		{ -14, 322 },
		{ 0, -1 },
		{ 93, 312 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
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
		{ -32, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -36, 349 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 179 },
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
#line 2508 ".\\myparser.y"


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
