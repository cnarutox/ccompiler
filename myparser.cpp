/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 53 of your 30 day trial period.
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
* Date: 12/01/18
* Time: 18:06:54
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
struct node {
	string name;
	int value;
	int length;
	node** children;
	node(int v = 0, string n = "")
	{
		value = v;
		name = n;
	}
	};

#line 61 "myparser.cpp"
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
#line 56 ".\\myparser.y"

	// place any extra initialisation code here

#line 85 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 61 ".\\myparser.y"

	// place any extra cleanup code here

#line 99 "myparser.cpp"
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
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 83 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
			printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 216 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 91 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
			printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 236 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 100 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
			printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
				
			
#line 257 "myparser.cpp"
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
#line 109 ".\\myparser.y"

		        (*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
				printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 277 "myparser.cpp"
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
#line 119 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 296 "myparser.cpp"
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
#line 126 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 315 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 133 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;	
	
#line 334 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 140 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="primary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;	
	
#line 355 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 152 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 374 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 159 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 396 "myparser.cpp"
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
#line 169 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 417 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 178 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 439 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 188 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 460 "myparser.cpp"
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
#line 197 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 481 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 206 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2).ntnode;
	
#line 501 "myparser.cpp"
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
#line 214 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="postfix_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2).ntnode;
	
#line 521 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 225 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="argument_expression_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 1);
	
#line 541 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 233 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="argument_expression_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 562 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 245 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 581 "myparser.cpp"
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
#line 252 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 601 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 260 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 621 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 268 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 641 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 276 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 661 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 284 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 683 "myparser.cpp"
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
#line 297 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 702 "myparser.cpp"
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
#line 304 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 721 "myparser.cpp"
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
#line 311 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 740 "myparser.cpp"
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
#line 318 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 759 "myparser.cpp"
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
#line 325 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 778 "myparser.cpp"
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
#line 332 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="unary_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;
	
#line 797 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 342 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="cast_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 816 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 349 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="cast_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4);
	
#line 838 "myparser.cpp"
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
#line 362 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 857 "myparser.cpp"
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
#line 369 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 878 "myparser.cpp"
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
#line 378 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 899 "myparser.cpp"
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
#line 387 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="multiplicative_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 920 "myparser.cpp"
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
#line 399 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="additive_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 939 "myparser.cpp"
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
#line 406 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="additive_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 960 "myparser.cpp"
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
#line 415 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="additive_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 981 "myparser.cpp"
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
#line 427 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="shift_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1000 "myparser.cpp"
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
#line 434 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="shift_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1021 "myparser.cpp"
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
#line 443 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="shift_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1042 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 455 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1061 "myparser.cpp"
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
#line 462 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1082 "myparser.cpp"
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
#line 471 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1103 "myparser.cpp"
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
#line 480 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1124 "myparser.cpp"
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
#line 489 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="relational_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];s
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1145 "myparser.cpp"
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
#line 501 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="equality_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1164 "myparser.cpp"
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
#line 508 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="equality_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1185 "myparser.cpp"
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
#line 517 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="equality_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1206 "myparser.cpp"
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
#line 529 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1225 "myparser.cpp"
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
#line 536 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1246 "myparser.cpp"
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
#line 548 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="exclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1265 "myparser.cpp"
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
#line 555 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="exclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1286 "myparser.cpp"
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
#line 567 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="inclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1305 "myparser.cpp"
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
#line 574 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="inclusive_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1326 "myparser.cpp"
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
#line 586 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="logical_and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1345 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 593 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="logical_and_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1366 "myparser.cpp"
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
#line 605 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="logical_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1385 "myparser.cpp"
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
#line 612 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="logical_or_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1406 "myparser.cpp"
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
#line 624 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="conditional_expression";		
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1425 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 631 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="conditional_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[4] = yyattribute(5 - 5);				
	
#line 1448 "myparser.cpp"
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
#line 645 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1467 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 652 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="conditional_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);	
	
#line 1488 "myparser.cpp"
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
#line 664 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 1507 "myparser.cpp"
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
#line 671 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1526 "myparser.cpp"
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
#line 678 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1545 "myparser.cpp"
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
#line 685 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1564 "myparser.cpp"
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
#line 692 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1583 "myparser.cpp"
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
#line 699 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1602 "myparser.cpp"
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
#line 706 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1621 "myparser.cpp"
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
#line 713 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1640 "myparser.cpp"
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
#line 720 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1659 "myparser.cpp"
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
#line 727 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1678 "myparser.cpp"
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
#line 734 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1697 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 744 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1716 "myparser.cpp"
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
#line 751 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1737 "myparser.cpp"
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
#line 763 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="constant_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1756 "myparser.cpp"
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
#line 773 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 1776 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 781 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 1797 "myparser.cpp"
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
#line 793 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 1816 "myparser.cpp"
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
#line 801 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 1836 "myparser.cpp"
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
#line 809 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 1855 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 816 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 1875 "myparser.cpp"
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
#line 824 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 1894 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 831 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 1914 "myparser.cpp"
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
#line 842 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1933 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 849 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);		
	
#line 1954 "myparser.cpp"
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
#line 861 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1973 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 868 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);							
	
#line 1994 "myparser.cpp"
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
#line 880 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2013 "myparser.cpp"
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
#line 887 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2032 "myparser.cpp"
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
#line 894 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2051 "myparser.cpp"
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
#line 901 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2070 "myparser.cpp"
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
#line 908 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2089 "myparser.cpp"
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
#line 918 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2108 "myparser.cpp"
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
#line 925 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2127 "myparser.cpp"
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
#line 932 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2146 "myparser.cpp"
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
#line 939 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2165 "myparser.cpp"
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
#line 946 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2184 "myparser.cpp"
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
#line 953 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2203 "myparser.cpp"
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
#line 960 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier"
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2222 "myparser.cpp"
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
#line 967 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2241 "myparser.cpp"
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
#line 974 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2260 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 981 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2279 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 988 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2298 "myparser.cpp"
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
#line 995 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 2317 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1005 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[4] = yyattribute(5 - 5).ntnode;		
	
#line 2340 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1016 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;		
	
#line 2362 "myparser.cpp"
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
#line 1026 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 2382 "myparser.cpp"
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
#line 1037 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 2401 "myparser.cpp"
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
#line 1044 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 2420 "myparser.cpp"
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
#line 1054 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 2439 "myparser.cpp"
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
#line 1061 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 2459 "myparser.cpp"
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
#line 1072 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2480 "myparser.cpp"
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
#line 1084 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 2500 "myparser.cpp"
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
#line 1092 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2519 "myparser.cpp"
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
#line 1099 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 2539 "myparser.cpp"
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
#line 1107 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2558 "myparser.cpp"
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
#line 1117 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2577 "myparser.cpp"
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
#line 1124 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 2598 "myparser.cpp"
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
#line 1136 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2617 "myparser.cpp"
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
#line 1143 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 2637 "myparser.cpp"
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
#line 1151 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 2658 "myparser.cpp"
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
#line 1163 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 2680 "myparser.cpp"
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
#line 1173 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 5).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[4] = yyattribute(5 - 5).ntcode;
	
#line 2703 "myparser.cpp"
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
#line 1184 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 2723 "myparser.cpp"
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
#line 1195 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2742 "myparser.cpp"
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
#line 1202 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
	
#line 2763 "myparser.cpp"
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
#line 1214 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2782 "myparser.cpp"
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
#line 1221 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 2803 "myparser.cpp"
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
#line 1233 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2822 "myparser.cpp"
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
#line 1240 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2841 "myparser.cpp"
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
#line 1250 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 2861 "myparser.cpp"
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
#line 1258 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2880 "myparser.cpp"
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
#line 1268 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 2899 "myparser.cpp"
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
#line 1275 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2920 "myparser.cpp"
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
#line 1284 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 2942 "myparser.cpp"
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
#line 1294 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 2963 "myparser.cpp"
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
#line 1303 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 2985 "myparser.cpp"
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
#line 1313 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 3007 "myparser.cpp"
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
#line 1323 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 3028 "myparser.cpp"
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
#line 1335 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 3047 "myparser.cpp"
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
#line 1342 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3067 "myparser.cpp"
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
#line 1350 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3087 "myparser.cpp"
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
#line 1358 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
	
#line 3107 "myparser.cpp"
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
#line 1369 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3126 "myparser.cpp"
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
#line 1376 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3146 "myparser.cpp"
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
#line 1388 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3165 "myparser.cpp"
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
#line 1395 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3186 "myparser.cpp"
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
#line 1407 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3205 "myparser.cpp"
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
#line 1414 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 3226 "myparser.cpp"
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
#line 1426 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3246 "myparser.cpp"
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
#line 1434 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3265 "myparser.cpp"
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
#line 1441 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3284 "myparser.cpp"
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
#line 1451 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3303 "myparser.cpp"
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
#line 1458 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3324 "myparser.cpp"
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
#line 1470 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3343 "myparser.cpp"
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
#line 1477 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3363 "myparser.cpp"
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
#line 1488 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3382 "myparser.cpp"
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
#line 1495 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3401 "myparser.cpp"
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
#line 1502 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3421 "myparser.cpp"
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
#line 1513 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3442 "myparser.cpp"
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
#line 1522 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;		
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3462 "myparser.cpp"
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
#line 1530 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3483 "myparser.cpp"
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
#line 1539 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3504 "myparser.cpp"
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
#line 1548 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3526 "myparser.cpp"
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
#line 1558 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3546 "myparser.cpp"
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
#line 1566 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3567 "myparser.cpp"
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
#line 1575 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3588 "myparser.cpp"
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
#line 1584 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3610 "myparser.cpp"
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
#line 1597 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3629 "myparser.cpp"
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
#line 1604 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3650 "myparser.cpp"
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
#line 1613 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3672 "myparser.cpp"
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
#line 1626 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3691 "myparser.cpp"
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
#line 1633 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 3712 "myparser.cpp"
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
#line 1645 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3731 "myparser.cpp"
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
#line 1652 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3750 "myparser.cpp"
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
#line 1659 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3769 "myparser.cpp"
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
#line 1666 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3788 "myparser.cpp"
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
#line 1673 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3807 "myparser.cpp"
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
#line 1680 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3826 "myparser.cpp"
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
#line 1690 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 3847 "myparser.cpp"
			}
		}
		break;
	case 183:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1699 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4);
	
#line 3869 "myparser.cpp"
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
#line 1709 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 3890 "myparser.cpp"
			}
		}
		break;
	case 185:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1721 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3910 "myparser.cpp"
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
#line 1729 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3931 "myparser.cpp"
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
#line 1738 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3952 "myparser.cpp"
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
#line 1747 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;		
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 3974 "myparser.cpp"
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
#line 1760 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3993 "myparser.cpp"
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
#line 1767 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 4013 "myparser.cpp"
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
#line 1778 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 4032 "myparser.cpp"
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
#line 1785 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 4052 "myparser.cpp"
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
#line 1796 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 4071 "myparser.cpp"
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
#line 1803 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4091 "myparser.cpp"
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
#line 1814 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(4 - 5);
	
#line 4114 "myparser.cpp"
			}
		}
		break;
	case 196:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1825 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[5] = yyattribute(6 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[6] = yyattribute(7 - 7);
	
#line 4139 "myparser.cpp"
			}
		}
		break;
	case 197:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1838 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 5);
	
#line 4162 "myparser.cpp"
			}
		}
		break;
	case 198:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1852 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 5);
	
#line 4185 "myparser.cpp"
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
#line 1863 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[5] = yyattribute(6 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[6] = yyattribute(7 - 7).ntnode;
	
#line 4210 "myparser.cpp"
			}
		}
		break;
	case 200:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 1876 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 6;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [6];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 6);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 6);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 6).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[5] = yyattribute(6 - 6);
	
#line 4234 "myparser.cpp"
			}
		}
		break;
	case 201:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1888 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 7;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [7];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 7);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[5] = yyattribute(6 - 7).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[6] = yyattribute(7 - 7);
	
#line 4259 "myparser.cpp"
			}
		}
		break;
	case 202:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1904 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4280 "myparser.cpp"
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
#line 1913 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4300 "myparser.cpp"
			}
		}
		break;
	case 204:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1921 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4320 "myparser.cpp"
			}
		}
		break;
	case 205:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1929 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 4340 "myparser.cpp"
			}
		}
		break;
	case 206:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1937 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 4361 "myparser.cpp"
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
#line 1949 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 4380 "myparser.cpp"
			}
		}
		break;
	case 208:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1956 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 4400 "myparser.cpp"
			}
		}
		break;
	case 209:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1967 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 4419 "myparser.cpp"
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
#line 1974 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 4438 "myparser.cpp"
			}
		}
		break;
	case 211:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1984 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4);
	
#line 4460 "myparser.cpp"
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
#line 1994 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 4481 "myparser.cpp"
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
#line 2003 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 4502 "myparser.cpp"
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
#line 2012 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 4522 "myparser.cpp"
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
		{ "NUMBER", 257 },
		{ "IDENTIFIER", 258 },
		{ "CONSTANT", 259 },
		{ "STRING_LITERAL", 260 },
		{ "SIZEOF", 261 },
		{ "PTR_OP", 262 },
		{ "INC_OP", 263 },
		{ "DEC_OP", 264 },
		{ "LEFT_OP", 265 },
		{ "RIGHT_OP", 266 },
		{ "LE_OP", 267 },
		{ "GE_OP", 268 },
		{ "EQ_OP", 269 },
		{ "NE_OP", 270 },
		{ "AND_OP", 271 },
		{ "OR_OP", 272 },
		{ "MUL_ASSIGN", 273 },
		{ "DIV_ASSIGN", 274 },
		{ "MOD_ASSIGN", 275 },
		{ "ADD_ASSIGN", 276 },
		{ "SUB_ASSIGN", 277 },
		{ "LEFT_ASSIGN", 278 },
		{ "RIGHT_ASSIGN", 279 },
		{ "AND_ASSIGN", 280 },
		{ "XOR_ASSIGN", 281 },
		{ "OR_ASSIGN", 282 },
		{ "TYPE_NAME", 283 },
		{ "TYPEDEF", 284 },
		{ "EXTERN", 285 },
		{ "STATIC", 286 },
		{ "AUTO", 287 },
		{ "REGISTER", 288 },
		{ "CHAR", 289 },
		{ "SHORT", 290 },
		{ "INT", 291 },
		{ "LONG", 292 },
		{ "SIGNED", 293 },
		{ "UNSIGNED", 294 },
		{ "FLOAT", 295 },
		{ "DOUBLE", 296 },
		{ "CONST", 297 },
		{ "VOLATILE", 298 },
		{ "VOID", 299 },
		{ "STRUCT", 300 },
		{ "UNION", 301 },
		{ "ENUM", 302 },
		{ "ELLIPSIS", 303 },
		{ "CASE", 304 },
		{ "DEFAULT", 305 },
		{ "IF", 306 },
		{ "ELSE", 307 },
		{ "SWITCH", 308 },
		{ "WHILE", 309 },
		{ "DO", 310 },
		{ "FOR", 311 },
		{ "GOTO", 312 },
		{ "CONTINUE", 313 },
		{ "BREAK", 314 },
		{ "RETURN", 315 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: translation_unit",
		"stmt: expr \';\' expr",
		"stmt: stmt \';\' expr",
		"expr: NUMBER \'+\' NUMBER",
		"expr: expr \'+\' NUMBER",
		"primary_expression: IDENTIFIER",
		"primary_expression: CONSTANT",
		"primary_expression: STRING_LITERAL",
		"primary_expression: \'(\' expression \')\'",
		"postfix_expression: primary_expression",
		"postfix_expression: postfix_expression \'[\' expression \']\'",
		"postfix_expression: postfix_expression \'(\' \')\'",
		"postfix_expression: postfix_expression \'(\' argument_expression_list \')\'",
		"postfix_expression: postfix_expression \'.\' IDENTIFIER",
		"postfix_expression: postfix_expression PTR_OP IDENTIFIER",
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
		"struct_or_union_specifier: struct_or_union IDENTIFIER \'{\' struct_declaration_list \'}\'",
		"struct_or_union_specifier: struct_or_union \'{\' struct_declaration_list \'}\'",
		"struct_or_union_specifier: struct_or_union IDENTIFIER",
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
		"enum_specifier: ENUM IDENTIFIER \'{\' enumerator_list \'}\'",
		"enum_specifier: ENUM IDENTIFIER",
		"enumerator_list: enumerator",
		"enumerator_list: enumerator_list \',\' enumerator",
		"enumerator: IDENTIFIER",
		"enumerator: IDENTIFIER \'=\' constant_expression",
		"type_qualifier: CONST",
		"type_qualifier: VOLATILE",
		"declarator: pointer direct_declarator",
		"declarator: direct_declarator",
		"direct_declarator: IDENTIFIER",
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
		"identifier_list: IDENTIFIER",
		"identifier_list: identifier_list \',\' IDENTIFIER",
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
		"labeled_statement: IDENTIFIER \':\' statement",
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
		"selection_statement: IF \'(\' expression \')\' statement",
		"selection_statement: IF \'(\' expression \')\' statement ELSE statement",
		"selection_statement: SWITCH \'(\' expression \')\' statement",
		"iteration_statement: WHILE \'(\' expression \')\' statement",
		"iteration_statement: DO statement WHILE \'(\' expression \')\' \';\'",
		"iteration_statement: FOR \'(\' expression_statement expression_statement \')\' statement",
		"iteration_statement: FOR \'(\' expression_statement expression_statement expression \')\' statement",
		"jump_statement: GOTO IDENTIFIER \';\'",
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
		{ 1, 3, 0 },
		{ 1, 3, 1 },
		{ 2, 3, 2 },
		{ 2, 3, 3 },
		{ 3, 1, 4 },
		{ 3, 1, 5 },
		{ 3, 1, 6 },
		{ 3, 3, 7 },
		{ 4, 1, 8 },
		{ 4, 4, 9 },
		{ 4, 3, 10 },
		{ 4, 4, 11 },
		{ 4, 3, 12 },
		{ 4, 3, 13 },
		{ 4, 2, 14 },
		{ 4, 2, 15 },
		{ 5, 1, 16 },
		{ 5, 3, 17 },
		{ 6, 1, 18 },
		{ 6, 2, 19 },
		{ 6, 2, 20 },
		{ 6, 2, 21 },
		{ 6, 2, 22 },
		{ 6, 4, 23 },
		{ 7, 1, 24 },
		{ 7, 1, 25 },
		{ 7, 1, 26 },
		{ 7, 1, 27 },
		{ 7, 1, 28 },
		{ 7, 1, 29 },
		{ 8, 1, 30 },
		{ 8, 4, 31 },
		{ 9, 1, 32 },
		{ 9, 3, 33 },
		{ 9, 3, 34 },
		{ 9, 3, 35 },
		{ 10, 1, 36 },
		{ 10, 3, 37 },
		{ 10, 3, 38 },
		{ 11, 1, 39 },
		{ 11, 3, 40 },
		{ 11, 3, 41 },
		{ 12, 1, 42 },
		{ 12, 3, 43 },
		{ 12, 3, 44 },
		{ 12, 3, 45 },
		{ 12, 3, 46 },
		{ 13, 1, 47 },
		{ 13, 3, 48 },
		{ 13, 3, 49 },
		{ 14, 1, 50 },
		{ 14, 3, 51 },
		{ 15, 1, 52 },
		{ 15, 3, 53 },
		{ 16, 1, 54 },
		{ 16, 3, 55 },
		{ 17, 1, 56 },
		{ 17, 3, 57 },
		{ 18, 1, 58 },
		{ 18, 3, 59 },
		{ 19, 1, 60 },
		{ 19, 5, 61 },
		{ 20, 1, 62 },
		{ 20, 3, 63 },
		{ 21, 1, 64 },
		{ 21, 1, 65 },
		{ 21, 1, 66 },
		{ 21, 1, 67 },
		{ 21, 1, 68 },
		{ 21, 1, 69 },
		{ 21, 1, 70 },
		{ 21, 1, 71 },
		{ 21, 1, 72 },
		{ 21, 1, 73 },
		{ 21, 1, 74 },
		{ 22, 1, 75 },
		{ 22, 3, 76 },
		{ 23, 1, 77 },
		{ 24, 2, 78 },
		{ 24, 3, 79 },
		{ 25, 1, 80 },
		{ 25, 2, 81 },
		{ 25, 1, 82 },
		{ 25, 2, 83 },
		{ 25, 1, 84 },
		{ 25, 2, 85 },
		{ 26, 1, 86 },
		{ 26, 3, 87 },
		{ 27, 1, 88 },
		{ 27, 3, 89 },
		{ 28, 1, 90 },
		{ 28, 1, 91 },
		{ 28, 1, 92 },
		{ 28, 1, 93 },
		{ 28, 1, 94 },
		{ 29, 1, 95 },
		{ 29, 1, 96 },
		{ 29, 1, 97 },
		{ 29, 1, 98 },
		{ 29, 1, 99 },
		{ 29, 1, 100 },
		{ 29, 1, 101 },
		{ 29, 1, 102 },
		{ 29, 1, 103 },
		{ 29, 1, 104 },
		{ 29, 1, 105 },
		{ 29, 1, 106 },
		{ 30, 5, 107 },
		{ 30, 4, 108 },
		{ 30, 2, 109 },
		{ 31, 1, 110 },
		{ 31, 1, 111 },
		{ 32, 1, 112 },
		{ 32, 2, 113 },
		{ 33, 3, 114 },
		{ 34, 2, 115 },
		{ 34, 1, 116 },
		{ 34, 2, 117 },
		{ 34, 1, 118 },
		{ 35, 1, 119 },
		{ 35, 3, 120 },
		{ 36, 1, 121 },
		{ 36, 2, 122 },
		{ 36, 3, 123 },
		{ 37, 4, 124 },
		{ 37, 5, 125 },
		{ 37, 2, 126 },
		{ 38, 1, 127 },
		{ 38, 3, 128 },
		{ 39, 1, 129 },
		{ 39, 3, 130 },
		{ 40, 1, 131 },
		{ 40, 1, 132 },
		{ 41, 2, 133 },
		{ 41, 1, 134 },
		{ 42, 1, 135 },
		{ 42, 3, 136 },
		{ 42, 4, 137 },
		{ 42, 3, 138 },
		{ 42, 4, 139 },
		{ 42, 4, 140 },
		{ 42, 3, 141 },
		{ 43, 1, 142 },
		{ 43, 2, 143 },
		{ 43, 2, 144 },
		{ 43, 3, 145 },
		{ 44, 1, 146 },
		{ 44, 2, 147 },
		{ 45, 1, 148 },
		{ 45, 3, 149 },
		{ 46, 1, 150 },
		{ 46, 3, 151 },
		{ 47, 2, 152 },
		{ 47, 2, 153 },
		{ 47, 1, 154 },
		{ 48, 1, 155 },
		{ 48, 3, 156 },
		{ 49, 1, 157 },
		{ 49, 2, 158 },
		{ 50, 1, 159 },
		{ 50, 1, 160 },
		{ 50, 2, 161 },
		{ 51, 3, 162 },
		{ 51, 2, 163 },
		{ 51, 3, 164 },
		{ 51, 3, 165 },
		{ 51, 4, 166 },
		{ 51, 2, 167 },
		{ 51, 3, 168 },
		{ 51, 3, 169 },
		{ 51, 4, 170 },
		{ 52, 1, 171 },
		{ 52, 3, 172 },
		{ 52, 4, 173 },
		{ 53, 1, 174 },
		{ 53, 3, 175 },
		{ 54, 1, 176 },
		{ 54, 1, 177 },
		{ 54, 1, 178 },
		{ 54, 1, 179 },
		{ 54, 1, 180 },
		{ 54, 1, 181 },
		{ 55, 3, 182 },
		{ 55, 4, 183 },
		{ 55, 3, 184 },
		{ 56, 2, 185 },
		{ 56, 3, 186 },
		{ 56, 3, 187 },
		{ 56, 4, 188 },
		{ 57, 1, 189 },
		{ 57, 2, 190 },
		{ 58, 1, 191 },
		{ 58, 2, 192 },
		{ 59, 1, 193 },
		{ 59, 2, 194 },
		{ 60, 5, 195 },
		{ 60, 7, 196 },
		{ 60, 5, 197 },
		{ 61, 5, 198 },
		{ 61, 7, 199 },
		{ 61, 6, 200 },
		{ 61, 7, 201 },
		{ 62, 3, 202 },
		{ 62, 2, 203 },
		{ 62, 2, 204 },
		{ 62, 2, 205 },
		{ 62, 3, 206 },
		{ 63, 1, 207 },
		{ 63, 2, 208 },
		{ 64, 1, 209 },
		{ 64, 1, 210 },
		{ 65, 4, 211 },
		{ 65, 3, 212 },
		{ 65, 3, 213 },
		{ 65, 2, 214 }
	};
	yyreduction = reduction;

	yytokenaction_size = 401;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 51, YYAT_SHIFT, 125 },
		{ 301, YYAT_SHIFT, 326 },
		{ 345, YYAT_SHIFT, 45 },
		{ 293, YYAT_SHIFT, 1 },
		{ 33, YYAT_SHIFT, 57 },
		{ 293, YYAT_SHIFT, 2 },
		{ 24, YYAT_ACCEPT, 0 },
		{ 23, YYAT_SHIFT, 42 },
		{ 283, YYAT_SHIFT, 197 },
		{ 126, YYAT_ERROR, 0 },
		{ 283, YYAT_SHIFT, 198 },
		{ 282, YYAT_SHIFT, 197 },
		{ 290, YYAT_SHIFT, 319 },
		{ 282, YYAT_SHIFT, 198 },
		{ 343, YYAT_SHIFT, 347 },
		{ 237, YYAT_ERROR, 0 },
		{ 335, YYAT_SHIFT, 345 },
		{ 151, YYAT_SHIFT, 149 },
		{ 333, YYAT_SHIFT, 343 },
		{ 335, YYAT_SHIFT, 173 },
		{ 230, YYAT_ERROR, 0 },
		{ 293, YYAT_SHIFT, 224 },
		{ 30, YYAT_SHIFT, 4 },
		{ 30, YYAT_SHIFT, 5 },
		{ 30, YYAT_SHIFT, 6 },
		{ 30, YYAT_SHIFT, 7 },
		{ 30, YYAT_SHIFT, 8 },
		{ 30, YYAT_SHIFT, 9 },
		{ 30, YYAT_SHIFT, 10 },
		{ 30, YYAT_SHIFT, 11 },
		{ 30, YYAT_SHIFT, 12 },
		{ 30, YYAT_SHIFT, 13 },
		{ 30, YYAT_SHIFT, 14 },
		{ 30, YYAT_SHIFT, 15 },
		{ 30, YYAT_SHIFT, 16 },
		{ 30, YYAT_SHIFT, 17 },
		{ 30, YYAT_SHIFT, 18 },
		{ 30, YYAT_SHIFT, 19 },
		{ 30, YYAT_SHIFT, 20 },
		{ 30, YYAT_SHIFT, 21 },
		{ 30, YYAT_SHIFT, 22 },
		{ 30, YYAT_SHIFT, 23 },
		{ 281, YYAT_SHIFT, 195 },
		{ 117, YYAT_SHIFT, 75 },
		{ 281, YYAT_SHIFT, 196 },
		{ 303, YYAT_SHIFT, 301 },
		{ 24, YYAT_SHIFT, 1 },
		{ 24, YYAT_ERROR, 0 },
		{ 319, YYAT_SHIFT, 69 },
		{ 330, YYAT_SHIFT, 342 },
		{ 247, YYAT_SHIFT, 247 },
		{ 247, YYAT_SHIFT, 296 },
		{ 247, YYAT_SHIFT, 2 },
		{ 319, YYAT_SHIFT, 70 },
		{ 249, YYAT_SHIFT, 247 },
		{ 319, YYAT_SHIFT, 71 },
		{ 156, YYAT_SHIFT, 69 },
		{ 319, YYAT_SHIFT, 72 },
		{ 319, YYAT_SHIFT, 73 },
		{ 41, YYAT_SHIFT, 2 },
		{ 319, YYAT_SHIFT, 74 },
		{ 156, YYAT_SHIFT, 70 },
		{ 51, YYAT_SHIFT, 45 },
		{ 156, YYAT_SHIFT, 71 },
		{ 2, YYAT_SHIFT, 2 },
		{ 156, YYAT_SHIFT, 72 },
		{ 156, YYAT_SHIFT, 73 },
		{ 138, YYAT_SHIFT, 231 },
		{ 156, YYAT_SHIFT, 74 },
		{ 138, YYAT_SHIFT, 2 },
		{ 154, YYAT_SHIFT, 247 },
		{ 110, YYAT_SHIFT, 210 },
		{ 154, YYAT_SHIFT, 2 },
		{ 236, YYAT_SHIFT, 231 },
		{ 234, YYAT_SHIFT, 301 },
		{ 59, YYAT_SHIFT, 60 },
		{ 35, YYAT_SHIFT, 60 },
		{ 329, YYAT_SHIFT, 341 },
		{ 264, YYAT_SHIFT, 315 },
		{ 267, YYAT_SHIFT, 173 },
		{ 271, YYAT_SHIFT, 201 },
		{ 264, YYAT_SHIFT, 316 },
		{ 327, YYAT_SHIFT, 340 },
		{ 142, YYAT_SHIFT, 239 },
		{ 226, YYAT_SHIFT, 293 },
		{ 271, YYAT_SHIFT, 202 },
		{ 142, YYAT_SHIFT, 240 },
		{ 172, YYAT_SHIFT, 173 },
		{ 96, YYAT_SHIFT, 175 },
		{ 285, YYAT_SHIFT, 173 },
		{ 271, YYAT_SHIFT, 203 },
		{ 126, YYAT_SHIFT, 45 },
		{ 231, YYAT_SHIFT, 231 },
		{ 290, YYAT_SHIFT, 320 },
		{ 98, YYAT_SHIFT, 187 },
		{ 60, YYAT_SHIFT, 136 },
		{ 303, YYAT_SHIFT, 302 },
		{ 24, YYAT_ERROR, 0 },
		{ 151, YYAT_SHIFT, 244 },
		{ 226, YYAT_SHIFT, 294 },
		{ 98, YYAT_SHIFT, 188 },
		{ 247, YYAT_SHIFT, 232 },
		{ 172, YYAT_SHIFT, 260 },
		{ 285, YYAT_SHIFT, 318 },
		{ 230, YYAT_SHIFT, 295 },
		{ 249, YYAT_SHIFT, 232 },
		{ 318, YYAT_ERROR, 0 },
		{ 117, YYAT_SHIFT, 45 },
		{ 52, YYAT_SHIFT, 128 },
		{ 117, YYAT_SHIFT, 215 },
		{ 270, YYAT_SHIFT, 201 },
		{ 280, YYAT_SHIFT, 195 },
		{ 105, YYAT_SHIFT, 201 },
		{ 280, YYAT_SHIFT, 196 },
		{ 104, YYAT_SHIFT, 197 },
		{ 270, YYAT_SHIFT, 202 },
		{ 104, YYAT_SHIFT, 198 },
		{ 105, YYAT_SHIFT, 202 },
		{ 138, YYAT_SHIFT, 232 },
		{ 314, YYAT_SHIFT, 334 },
		{ 270, YYAT_SHIFT, 203 },
		{ 154, YYAT_SHIFT, 232 },
		{ 105, YYAT_SHIFT, 203 },
		{ 52, YYAT_SHIFT, 129 },
		{ 236, YYAT_SHIFT, 232 },
		{ 234, YYAT_SHIFT, 302 },
		{ 59, YYAT_SHIFT, 61 },
		{ 35, YYAT_SHIFT, 61 },
		{ 267, YYAT_SHIFT, 317 },
		{ 103, YYAT_SHIFT, 195 },
		{ 302, YYAT_SHIFT, 328 },
		{ 103, YYAT_SHIFT, 196 },
		{ 279, YYAT_SHIFT, 207 },
		{ 279, YYAT_SHIFT, 208 },
		{ 275, YYAT_SHIFT, 205 },
		{ 275, YYAT_SHIFT, 206 },
		{ 300, YYAT_SHIFT, 325 },
		{ 345, YYAT_SHIFT, 78 },
		{ 319, YYAT_SHIFT, 217 },
		{ 33, YYAT_SHIFT, 58 },
		{ 319, YYAT_SHIFT, 338 },
		{ 319, YYAT_SHIFT, 77 },
		{ 23, YYAT_SHIFT, 43 },
		{ 274, YYAT_SHIFT, 205 },
		{ 274, YYAT_SHIFT, 206 },
		{ 98, YYAT_SHIFT, 189 },
		{ 273, YYAT_SHIFT, 205 },
		{ 273, YYAT_SHIFT, 206 },
		{ 298, YYAT_SHIFT, 324 },
		{ 156, YYAT_SHIFT, 77 },
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
		{ 272, YYAT_SHIFT, 205 },
		{ 272, YYAT_SHIFT, 206 },
		{ 108, YYAT_SHIFT, 207 },
		{ 108, YYAT_SHIFT, 208 },
		{ 107, YYAT_SHIFT, 205 },
		{ 107, YYAT_SHIFT, 206 },
		{ 297, YYAT_SHIFT, 323 },
		{ 287, YYAT_SHIFT, 194 },
		{ 286, YYAT_SHIFT, 209 },
		{ 284, YYAT_SHIFT, 212 },
		{ 269, YYAT_SHIFT, 204 },
		{ 258, YYAT_SHIFT, 75 },
		{ 257, YYAT_SHIFT, 313 },
		{ 345, YYAT_SHIFT, 84 },
		{ 345, YYAT_SHIFT, 85 },
		{ 345, YYAT_SHIFT, 86 },
		{ 256, YYAT_SHIFT, 312 },
		{ 345, YYAT_SHIFT, 87 },
		{ 345, YYAT_SHIFT, 88 },
		{ 345, YYAT_SHIFT, 89 },
		{ 345, YYAT_SHIFT, 90 },
		{ 345, YYAT_SHIFT, 91 },
		{ 345, YYAT_SHIFT, 92 },
		{ 345, YYAT_SHIFT, 93 },
		{ 345, YYAT_SHIFT, 94 },
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
		{ 283, YYAT_SHIFT, 199 },
		{ 283, YYAT_SHIFT, 200 },
		{ 255, YYAT_SHIFT, 311 },
		{ 282, YYAT_SHIFT, 199 },
		{ 282, YYAT_SHIFT, 200 },
		{ 254, YYAT_SHIFT, 310 },
		{ 293, YYAT_SHIFT, 3 },
		{ 51, YYAT_SHIFT, 4 },
		{ 51, YYAT_SHIFT, 5 },
		{ 51, YYAT_SHIFT, 6 },
		{ 51, YYAT_SHIFT, 7 },
		{ 51, YYAT_SHIFT, 8 },
		{ 51, YYAT_SHIFT, 9 },
		{ 51, YYAT_SHIFT, 10 },
		{ 51, YYAT_SHIFT, 11 },
		{ 51, YYAT_SHIFT, 12 },
		{ 51, YYAT_SHIFT, 13 },
		{ 51, YYAT_SHIFT, 14 },
		{ 51, YYAT_SHIFT, 15 },
		{ 51, YYAT_SHIFT, 16 },
		{ 51, YYAT_SHIFT, 17 },
		{ 51, YYAT_SHIFT, 18 },
		{ 51, YYAT_SHIFT, 19 },
		{ 51, YYAT_SHIFT, 20 },
		{ 51, YYAT_SHIFT, 21 },
		{ 51, YYAT_SHIFT, 22 },
		{ 51, YYAT_SHIFT, 23 },
		{ 117, YYAT_SHIFT, 78 },
		{ 301, YYAT_SHIFT, 4 },
		{ 301, YYAT_SHIFT, 5 },
		{ 301, YYAT_SHIFT, 6 },
		{ 301, YYAT_SHIFT, 7 },
		{ 301, YYAT_SHIFT, 8 },
		{ 301, YYAT_SHIFT, 9 },
		{ 301, YYAT_SHIFT, 10 },
		{ 301, YYAT_SHIFT, 11 },
		{ 301, YYAT_SHIFT, 12 },
		{ 301, YYAT_SHIFT, 13 },
		{ 301, YYAT_SHIFT, 14 },
		{ 301, YYAT_SHIFT, 15 },
		{ 301, YYAT_SHIFT, 16 },
		{ 301, YYAT_SHIFT, 17 },
		{ 301, YYAT_SHIFT, 18 },
		{ 301, YYAT_SHIFT, 19 },
		{ 301, YYAT_SHIFT, 20 },
		{ 301, YYAT_SHIFT, 21 },
		{ 301, YYAT_SHIFT, 22 },
		{ 301, YYAT_SHIFT, 23 },
		{ 230, YYAT_ERROR, 0 },
		{ 230, YYAT_ERROR, 0 },
		{ 230, YYAT_ERROR, 0 },
		{ 230, YYAT_ERROR, 0 },
		{ 230, YYAT_ERROR, 0 },
		{ 117, YYAT_SHIFT, 5 },
		{ 117, YYAT_SHIFT, 6 },
		{ 117, YYAT_SHIFT, 7 },
		{ 117, YYAT_SHIFT, 8 },
		{ 117, YYAT_SHIFT, 9 },
		{ 319, YYAT_SHIFT, 144 },
		{ 319, YYAT_SHIFT, 79 },
		{ 319, YYAT_SHIFT, 80 },
		{ 319, YYAT_SHIFT, 81 },
		{ 237, YYAT_SHIFT, 304 },
		{ 319, YYAT_SHIFT, 82 },
		{ 319, YYAT_SHIFT, 83 },
		{ 110, YYAT_SHIFT, 211 },
		{ 156, YYAT_SHIFT, 144 },
		{ 156, YYAT_SHIFT, 79 },
		{ 156, YYAT_SHIFT, 80 },
		{ 156, YYAT_SHIFT, 81 },
		{ 138, YYAT_SHIFT, 3 },
		{ 156, YYAT_SHIFT, 82 },
		{ 156, YYAT_SHIFT, 83 },
		{ 117, YYAT_SHIFT, 84 },
		{ 117, YYAT_SHIFT, 85 },
		{ 117, YYAT_SHIFT, 86 },
		{ 236, YYAT_SHIFT, 3 },
		{ 117, YYAT_SHIFT, 87 },
		{ 117, YYAT_SHIFT, 88 },
		{ 117, YYAT_SHIFT, 89 },
		{ 117, YYAT_SHIFT, 90 },
		{ 117, YYAT_SHIFT, 91 },
		{ 117, YYAT_SHIFT, 92 },
		{ 117, YYAT_SHIFT, 93 },
		{ 117, YYAT_SHIFT, 94 },
		{ 96, YYAT_SHIFT, 176 },
		{ 96, YYAT_SHIFT, 177 },
		{ 96, YYAT_SHIFT, 178 },
		{ 96, YYAT_SHIFT, 179 },
		{ 96, YYAT_SHIFT, 180 },
		{ 96, YYAT_SHIFT, 181 },
		{ 96, YYAT_SHIFT, 182 },
		{ 96, YYAT_SHIFT, 183 },
		{ 96, YYAT_SHIFT, 184 },
		{ 96, YYAT_SHIFT, 185 },
		{ 231, YYAT_SHIFT, 3 },
		{ 251, YYAT_SHIFT, 308 },
		{ 60, YYAT_SHIFT, 137 },
		{ 240, YYAT_SHIFT, 306 },
		{ 41, YYAT_SHIFT, 18 },
		{ 41, YYAT_SHIFT, 19 },
		{ 98, YYAT_SHIFT, 190 },
		{ 98, YYAT_SHIFT, 191 },
		{ 98, YYAT_SHIFT, 192 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 104, YYAT_SHIFT, 199 },
		{ 104, YYAT_SHIFT, 200 },
		{ 131, YYAT_SHIFT, 4 },
		{ 232, YYAT_SHIFT, 299 },
		{ 225, YYAT_SHIFT, 292 },
		{ 217, YYAT_ERROR, 0 },
		{ 216, YYAT_SHIFT, 288 },
		{ 190, YYAT_SHIFT, 268 },
		{ 131, YYAT_SHIFT, 10 },
		{ 131, YYAT_SHIFT, 11 },
		{ 131, YYAT_SHIFT, 12 },
		{ 131, YYAT_SHIFT, 13 },
		{ 131, YYAT_SHIFT, 14 },
		{ 131, YYAT_SHIFT, 15 },
		{ 131, YYAT_SHIFT, 16 },
		{ 131, YYAT_SHIFT, 17 },
		{ 131, YYAT_SHIFT, 18 },
		{ 131, YYAT_SHIFT, 19 },
		{ 131, YYAT_SHIFT, 20 },
		{ 131, YYAT_SHIFT, 21 },
		{ 131, YYAT_SHIFT, 22 },
		{ 131, YYAT_SHIFT, 23 },
		{ 130, YYAT_SHIFT, 4 },
		{ 188, YYAT_SHIFT, 266 },
		{ 187, YYAT_SHIFT, 263 },
		{ 168, YYAT_SHIFT, 259 },
		{ 166, YYAT_SHIFT, 257 },
		{ 161, YYAT_SHIFT, 252 },
		{ 130, YYAT_SHIFT, 10 },
		{ 130, YYAT_SHIFT, 11 },
		{ 130, YYAT_SHIFT, 12 },
		{ 130, YYAT_SHIFT, 13 },
		{ 130, YYAT_SHIFT, 14 },
		{ 130, YYAT_SHIFT, 15 },
		{ 130, YYAT_SHIFT, 16 },
		{ 130, YYAT_SHIFT, 17 },
		{ 130, YYAT_SHIFT, 18 },
		{ 130, YYAT_SHIFT, 19 },
		{ 130, YYAT_SHIFT, 20 },
		{ 130, YYAT_SHIFT, 21 },
		{ 130, YYAT_SHIFT, 22 },
		{ 130, YYAT_SHIFT, 23 },
		{ 153, YYAT_SHIFT, 246 },
		{ 152, YYAT_SHIFT, 245 },
		{ 149, YYAT_SHIFT, 65 },
		{ 147, YYAT_SHIFT, 241 },
		{ 141, YYAT_SHIFT, 238 },
		{ 139, YYAT_SHIFT, 237 },
		{ 135, YYAT_ERROR, 0 },
		{ 134, YYAT_SHIFT, 228 },
		{ 128, YYAT_ERROR, 0 },
		{ 122, YYAT_SHIFT, 125 },
		{ 116, YYAT_SHIFT, 213 },
		{ 112, YYAT_SHIFT, 212 },
		{ 109, YYAT_SHIFT, 209 },
		{ 106, YYAT_SHIFT, 204 },
		{ 102, YYAT_SHIFT, 194 },
		{ 95, YYAT_SHIFT, 174 },
		{ 94, YYAT_SHIFT, 171 },
		{ 93, YYAT_SHIFT, 170 },
		{ 92, YYAT_SHIFT, 169 },
		{ 91, YYAT_SHIFT, 168 },
		{ 90, YYAT_SHIFT, 167 },
		{ 88, YYAT_SHIFT, 165 },
		{ 87, YYAT_SHIFT, 164 },
		{ 86, YYAT_SHIFT, 163 },
		{ 85, YYAT_SHIFT, 162 },
		{ 83, YYAT_SHIFT, 158 },
		{ 81, YYAT_SHIFT, 156 },
		{ 78, YYAT_SHIFT, 155 },
		{ 67, YYAT_SHIFT, 150 },
		{ 65, YYAT_SHIFT, 148 },
		{ 61, YYAT_SHIFT, 143 },
		{ 58, YYAT_SHIFT, 135 },
		{ 47, YYAT_SHIFT, 50 },
		{ 45, YYAT_SHIFT, 76 },
		{ 43, YYAT_SHIFT, 68 },
		{ 38, YYAT_SHIFT, 62 },
		{ 34, YYAT_ERROR, 0 },
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 400, 1, YYAT_DEFAULT, 24 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 22, 1, YYAT_REDUCE, 143 },
		{ 0, 0, YYAT_REDUCE, 136 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 0, 0, YYAT_REDUCE, 132 },
		{ 0, 0, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ -116, 1, YYAT_ERROR, 0 },
		{ 6, 1, YYAT_DEFAULT, 231 },
		{ 0, 0, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 0, 0, YYAT_DEFAULT, 47 },
		{ -88, 1, YYAT_REDUCE, 83 },
		{ -133, 1, YYAT_REDUCE, 85 },
		{ -261, 1, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ -119, 1, YYAT_ERROR, 0 },
		{ 357, 1, YYAT_DEFAULT, 128 },
		{ 36, 1, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 357, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 17, 1, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_DEFAULT, 149 },
		{ 274, 1, YYAT_REDUCE, 127 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 271, 1, YYAT_DEFAULT, 117 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 336, 1, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ -61, 1, YYAT_REDUCE, 89 },
		{ 64, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_DEFAULT, 135 },
		{ 271, 1, YYAT_REDUCE, 110 },
		{ 35, 1, YYAT_REDUCE, 134 },
		{ 54, 1, YYAT_DEFAULT, 301 },
		{ 300, 1, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 331, 1, YYAT_REDUCE, 130 },
		{ 0, 0, YYAT_REDUCE, 128 },
		{ 266, 1, YYAT_DEFAULT, 151 },
		{ 0, 0, YYAT_DEFAULT, 149 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_DEFAULT, 156 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 332, 1, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 349, 1, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 83 },
		{ 348, 1, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 329, 1, YYAT_ERROR, 0 },
		{ 346, 1, YYAT_ERROR, 0 },
		{ 345, 1, YYAT_ERROR, 0 },
		{ 344, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ 343, 1, YYAT_ERROR, 0 },
		{ 124, 1, YYAT_ERROR, 0 },
		{ 322, 1, YYAT_ERROR, 0 },
		{ 321, 1, YYAT_ERROR, 0 },
		{ 320, 1, YYAT_DEFAULT, 318 },
		{ 319, 1, YYAT_DEFAULT, 172 },
		{ 27, 1, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 54, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 283, 1, YYAT_REDUCE, 55 },
		{ 86, 1, YYAT_REDUCE, 40 },
		{ 54, 1, YYAT_REDUCE, 48 },
		{ 75, 1, YYAT_REDUCE, 37 },
		{ 338, 1, YYAT_REDUCE, 53 },
		{ -91, 1, YYAT_REDUCE, 43 },
		{ -97, 1, YYAT_REDUCE, 51 },
		{ 104, 1, YYAT_REDUCE, 59 },
		{ 8, 1, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 250, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 248, 1, YYAT_DEFAULT, 345 },
		{ -16, 1, YYAT_DEFAULT, 156 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 311, 1, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 0, 0, YYAT_DEFAULT, 217 },
		{ -32, 1, YYAT_DEFAULT, 301 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 313, 1, YYAT_DEFAULT, 293 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 60, 1, YYAT_REDUCE, 117 },
		{ 40, 1, YYAT_REDUCE, 119 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ 0, 0, YYAT_DEFAULT, 293 },
		{ 245, 1, YYAT_DEFAULT, 230 },
		{ 244, 1, YYAT_DEFAULT, 230 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 0, 0, YYAT_REDUCE, 156 },
		{ 27, 1, YYAT_REDUCE, 155 },
		{ 324, 1, YYAT_REDUCE, 149 },
		{ 0, 0, YYAT_REDUCE, 151 },
		{ 326, 1, YYAT_ERROR, 0 },
		{ 42, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 273, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 107, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 323, 1, YYAT_DEFAULT, 335 },
		{ 322, 1, YYAT_ERROR, 0 },
		{ 30, 1, YYAT_REDUCE, 158 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ 23, 1, YYAT_DEFAULT, 135 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 290, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 258 },
		{ 287, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 43, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 304, 1, YYAT_DEFAULT, 318 },
		{ 86, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 70, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 202, 1, YYAT_DEFAULT, 345 },
		{ 201, 1, YYAT_DEFAULT, 319 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 267, 1, YYAT_REDUCE, 122 },
		{ 40, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 120 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ -21, 1, YYAT_DEFAULT, 301 },
		{ 52, 1, YYAT_DEFAULT, 247 },
		{ 231, 1, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 34, 1, YYAT_REDUCE, 161 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ 33, 1, YYAT_REDUCE, 160 },
		{ -26, 1, YYAT_DEFAULT, 301 },
		{ 0, 0, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ 55, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ 0, 0, YYAT_REDUCE, 129 },
		{ 0, 0, YYAT_REDUCE, 126 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 10, 1, YYAT_DEFAULT, 301 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 14, 1, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ 270, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 179, 1, YYAT_DEFAULT, 335 },
		{ 176, 1, YYAT_DEFAULT, 335 },
		{ 145, 1, YYAT_DEFAULT, 335 },
		{ 142, 1, YYAT_ERROR, 0 },
		{ 122, 1, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 35, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 142, 1, YYAT_REDUCE, 54 },
		{ 73, 1, YYAT_REDUCE, 38 },
		{ 43, 1, YYAT_REDUCE, 39 },
		{ -95, 1, YYAT_REDUCE, 44 },
		{ -119, 1, YYAT_REDUCE, 45 },
		{ -122, 1, YYAT_REDUCE, 46 },
		{ -131, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ -137, 1, YYAT_REDUCE, 52 },
		{ 68, 1, YYAT_REDUCE, 41 },
		{ -1, 1, YYAT_REDUCE, 42 },
		{ -49, 1, YYAT_REDUCE, 49 },
		{ -52, 1, YYAT_REDUCE, 50 },
		{ 55, 1, YYAT_REDUCE, 58 },
		{ 45, 1, YYAT_ERROR, 0 },
		{ -93, 1, YYAT_REDUCE, 60 },
		{ 83, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ -32, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 123 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ -37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ 135, 1, YYAT_ERROR, 0 },
		{ 107, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 43, 1, YYAT_ERROR, 0 },
		{ -40, 1, YYAT_ERROR, 0 },
		{ 37, 1, YYAT_DEFAULT, 318 },
		{ 5, 1, YYAT_REDUCE, 162 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 78, 1, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -17, 1, YYAT_DEFAULT, 217 },
		{ 15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_REDUCE, 121 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 0, 0, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 165 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 41, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ -16, 1, YYAT_ERROR, 0 },
		{ -258, 1, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ -23, 1, YYAT_DEFAULT, 335 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 0, 0, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_DEFAULT, 345 },
		{ -45, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ -121, 1, YYAT_DEFAULT, 258 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 0, 0, YYAT_REDUCE, 202 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 227;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 345, 101 },
		{ 345, 98 },
		{ 258, 95 },
		{ 345, 96 },
		{ 345, 99 },
		{ 345, 100 },
		{ 345, 105 },
		{ 345, 103 },
		{ 345, 107 },
		{ 345, 104 },
		{ 345, 108 },
		{ 345, 106 },
		{ 345, 102 },
		{ 345, 112 },
		{ 345, 109 },
		{ 345, 110 },
		{ 345, 111 },
		{ 345, 97 },
		{ 342, 346 },
		{ 345, 95 },
		{ 117, 123 },
		{ 117, 47 },
		{ 30, 56 },
		{ 316, 336 },
		{ 117, 30 },
		{ 117, 28 },
		{ 117, 32 },
		{ 117, 33 },
		{ 319, 218 },
		{ 318, 145 },
		{ 319, -1 },
		{ 187, 264 },
		{ 45, 46 },
		{ 117, 31 },
		{ 2, 39 },
		{ 334, 344 },
		{ 117, 29 },
		{ 2, 40 },
		{ 2, 41 },
		{ 258, 314 },
		{ 51, 46 },
		{ 302, 146 },
		{ 318, 337 },
		{ 318, -1 },
		{ 30, -1 },
		{ 302, 329 },
		{ 187, 265 },
		{ 128, 221 },
		{ 126, 123 },
		{ 126, 47 },
		{ 117, 119 },
		{ 345, 348 },
		{ 345, 115 },
		{ 345, 120 },
		{ 117, 216 },
		{ 316, -1 },
		{ 345, 113 },
		{ 345, 118 },
		{ 345, 121 },
		{ 345, 114 },
		{ 319, 339 },
		{ 128, 122 },
		{ 319, -1 },
		{ 319, -1 },
		{ 319, -1 },
		{ 45, 117 },
		{ 45, 116 },
		{ 319, -1 },
		{ 319, -1 },
		{ 319, -1 },
		{ 319, -1 },
		{ 301, 138 },
		{ 51, 127 },
		{ 51, 126 },
		{ 301, 30 },
		{ 301, 28 },
		{ 301, 32 },
		{ 301, 33 },
		{ 24, 26 },
		{ 24, 27 },
		{ 126, 220 },
		{ 313, 333 },
		{ 247, 249 },
		{ 301, 31 },
		{ 247, 298 },
		{ 60, 141 },
		{ 301, 29 },
		{ 312, 332 },
		{ 60, 142 },
		{ 247, 297 },
		{ 247, 234 },
		{ 301, 327 },
		{ 301, 139 },
		{ 301, 140 },
		{ 1, -1 },
		{ 24, 25 },
		{ 24, 35 },
		{ 24, 34 },
		{ 311, 331 },
		{ 1, 38 },
		{ 156, 130 },
		{ 156, 32 },
		{ 156, 33 },
		{ 310, 330 },
		{ 41, 63 },
		{ 156, 154 },
		{ 230, -1 },
		{ 41, 64 },
		{ 156, 31 },
		{ 230, -1 },
		{ 230, 130 },
		{ 156, 131 },
		{ 217, 289 },
		{ 217, 290 },
		{ 230, 229 },
		{ 230, 133 },
		{ 211, 112 },
		{ 211, 286 },
		{ 24, 44 },
		{ 24, 36 },
		{ 156, 251 },
		{ 230, 131 },
		{ 138, 233 },
		{ 138, 35 },
		{ 138, 236 },
		{ 212, 287 },
		{ 212, -1 },
		{ 212, -1 },
		{ 212, -1 },
		{ 212, -1 },
		{ 293, 322 },
		{ 138, 235 },
		{ 154, 249 },
		{ 209, 102 },
		{ 209, 284 },
		{ 293, 225 },
		{ 293, 35 },
		{ 293, 34 },
		{ 292, 321 },
		{ 154, 248 },
		{ 154, 234 },
		{ 246, 307 },
		{ 246, -1 },
		{ 246, -1 },
		{ 237, -1 },
		{ 237, -1 },
		{ 237, 305 },
		{ 231, 38 },
		{ 231, 35 },
		{ 231, 236 },
		{ 208, 283 },
		{ 208, -1 },
		{ 208, -1 },
		{ 314, 97 },
		{ 83, 160 },
		{ 314, 335 },
		{ 83, -1 },
		{ 206, 281 },
		{ 206, -1 },
		{ 204, 104 },
		{ 204, 279 },
		{ 200, 275 },
		{ 200, -1 },
		{ 196, 100 },
		{ 196, 271 },
		{ 194, 269 },
		{ 194, -1 },
		{ 135, 230 },
		{ 135, 132 },
		{ 133, 226 },
		{ 133, 227 },
		{ 131, -1 },
		{ 131, 223 },
		{ 68, 151 },
		{ 68, 66 },
		{ 47, 52 },
		{ 47, 53 },
		{ 25, 49 },
		{ 25, 48 },
		{ 0, 24 },
		{ 0, 37 },
		{ 252, 309 },
		{ 249, 303 },
		{ 236, 59 },
		{ 232, 300 },
		{ 224, 291 },
		{ 216, 214 },
		{ 210, 285 },
		{ 207, 282 },
		{ 205, 280 },
		{ 203, 278 },
		{ 202, 277 },
		{ 201, 276 },
		{ 199, 274 },
		{ 198, 273 },
		{ 197, 272 },
		{ 195, 270 },
		{ 189, 267 },
		{ 186, 262 },
		{ 173, 261 },
		{ 167, 258 },
		{ 165, 256 },
		{ 164, 255 },
		{ 163, 254 },
		{ 162, 253 },
		{ 158, 152 },
		{ 155, 250 },
		{ 149, 243 },
		{ 148, 242 },
		{ 130, 222 },
		{ 125, 219 },
		{ 99, 193 },
		{ 96, 186 },
		{ 94, 172 },
		{ 89, 166 },
		{ 84, 161 },
		{ 82, 159 },
		{ 81, 157 },
		{ 71, 153 },
		{ 61, 147 },
		{ 57, 134 },
		{ 48, 124 },
		{ 42, 67 },
		{ 34, 59 },
		{ 29, 55 },
		{ 28, 54 },
		{ 27, 51 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 116, 24 },
		{ 58, 293 },
		{ -6, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 54, 30 },
		{ 121, 51 },
		{ 0, -1 },
		{ 185, 47 },
		{ 200, 30 },
		{ 199, 30 },
		{ -3, 237 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 181, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 64, -1 },
		{ 184, 68 },
		{ 0, -1 },
		{ 0, -1 },
		{ 8, 117 },
		{ 0, -1 },
		{ 149, 128 },
		{ 165, 126 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, 126 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 188, 135 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, 301 },
		{ 196, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 135, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 169, 156 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 211, 83 },
		{ 210, 83 },
		{ 148, 246 },
		{ 192, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 160, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 191, 314 },
		{ 0, -1 },
		{ 191, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 203, 246 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 216 },
		{ -4, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 158, 319 },
		{ 24, 30 },
		{ 0, -1 },
		{ 20, 1 },
		{ 0, -1 },
		{ 175, 131 },
		{ 138, 230 },
		{ 0, -1 },
		{ 134, 293 },
		{ 0, 230 },
		{ 135, 230 },
		{ 0, -1 },
		{ 0, -1 },
		{ 81, 154 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 185, 302 },
		{ 168, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 89, -1 },
		{ 152, 345 },
		{ 71, 158 },
		{ 0, -1 },
		{ 183, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 150, 345 },
		{ 181, 314 },
		{ 180, 314 },
		{ 179, 314 },
		{ 0, -1 },
		{ 141, 258 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 179, 316 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 178, 316 },
		{ 26, 316 },
		{ 0, -1 },
		{ 175, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 151, 212 },
		{ 187, 196 },
		{ 155, 246 },
		{ 184, 200 },
		{ 183, 200 },
		{ 182, 200 },
		{ 150, 208 },
		{ 184, 246 },
		{ 183, 246 },
		{ 182, 246 },
		{ 147, 208 },
		{ 179, 206 },
		{ 147, 200 },
		{ 176, 208 },
		{ 138, 194 },
		{ 118, 212 },
		{ 165, 314 },
		{ 100, 209 },
		{ 110, 318 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 132, 345 },
		{ 60, 319 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 162, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 81, 30 },
		{ 106, 247 },
		{ 161, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 141, 249 },
		{ 99, 301 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 133, 206 },
		{ 39, 301 },
		{ 0, -1 },
		{ 131, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 127, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -20, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 115, 302 },
		{ 94, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 46, -1 },
		{ 22, 318 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 345 },
		{ 44, 345 },
		{ 33, 345 },
		{ 59, 314 },
		{ 133, 316 },
		{ 0, -1 },
		{ 3, 319 },
		{ 0, -1 },
		{ 23, 316 },
		{ 8, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -19, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -36, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, -1 },
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
#line 2024 ".\\myparser.y"


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
