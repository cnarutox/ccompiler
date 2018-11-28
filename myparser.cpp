/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 50 of your 30 day trial period.
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
* Date: 11/28/18
* Time: 20:36:14
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
	node(int v = 0)
	{
		value = v;
	}
	};

#line 60 "myparser.cpp"
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
#line 54 ".\\myparser.y"

	// place any extra initialisation code here

#line 84 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 59 ".\\myparser.y"

	// place any extra cleanup code here

#line 98 "myparser.cpp"
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
#line 81 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
			printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 215 "myparser.cpp"
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
#line 89 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
			printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 235 "myparser.cpp"
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
#line 98 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
			printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
				
			
#line 256 "myparser.cpp"
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
#line 107 ".\\myparser.y"

		        (*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(yyattribute(1 - 3).ntnode->value + yyattribute(3 - 3).ntnode->value);
				printf("%d\n", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->value) ;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 276 "myparser.cpp"
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
#line 221 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="conditional_expression";		
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 295 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 228 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="conditional_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[4] = yyattribute(5 - 5);				
	
#line 318 "myparser.cpp"
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
#line 242 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 337 "myparser.cpp"
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
#line 249 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="conditional_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);	
	
#line 358 "myparser.cpp"
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
#line 261 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_operator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1).ntnode;		
	
#line 377 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 268 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 396 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 275 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 415 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 282 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 434 "myparser.cpp"
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
#line 289 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 453 "myparser.cpp"
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
#line 296 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 472 "myparser.cpp"
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
#line 303 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 491 "myparser.cpp"
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
#line 310 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 510 "myparser.cpp"
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
#line 317 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 529 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 324 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 548 "myparser.cpp"
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
#line 331 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="assignment_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 567 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 341 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 586 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 348 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 607 "myparser.cpp"
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
#line 360 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="constant_expression";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 626 "myparser.cpp"
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
#line 370 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 646 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 378 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;		
	
#line 667 "myparser.cpp"
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
#line 390 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 686 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 398 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 706 "myparser.cpp"
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
#line 406 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 725 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 413 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 745 "myparser.cpp"
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
#line 421 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 764 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 428 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declaration_specifiers";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 784 "myparser.cpp"
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
#line 439 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 803 "myparser.cpp"
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
#line 446 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);		
	
#line 824 "myparser.cpp"
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
#line 458 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 843 "myparser.cpp"
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
#line 465 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="init_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);							
	
#line 864 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 477 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 883 "myparser.cpp"
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
#line 484 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 902 "myparser.cpp"
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
#line 491 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 921 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 498 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 940 "myparser.cpp"
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
#line 505 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="storage_class_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 959 "myparser.cpp"
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
#line 515 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 978 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 522 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 998 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 530 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1017 "myparser.cpp"
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
#line 537 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1036 "myparser.cpp"
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
#line 544 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1055 "myparser.cpp"
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
#line 551 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1074 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 558 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier"
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1093 "myparser.cpp"
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
#line 565 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1112 "myparser.cpp"
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
#line 572 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1131 "myparser.cpp"
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
#line 579 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1150 "myparser.cpp"
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
#line 586 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1169 "myparser.cpp"
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
#line 593 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);		
	
#line 1188 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 603 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[4] = yyattribute(5 - 5).ntnode;		
	
#line 1211 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 614 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;		
	
#line 1233 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 624 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 1253 "myparser.cpp"
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
#line 635 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 1272 "myparser.cpp"
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
#line 642 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_or_union";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 1291 "myparser.cpp"
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
#line 652 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);	
	
#line 1310 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 659 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);		
	
#line 1330 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 670 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1351 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 682 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 1371 "myparser.cpp"
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
#line 690 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1390 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 697 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 1410 "myparser.cpp"
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
#line 705 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="specifier_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1429 "myparser.cpp"
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
#line 715 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1448 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 722 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1469 "myparser.cpp"
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
#line 734 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1488 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 741 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 1508 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 749 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="struct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1529 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 761 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 1551 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 771 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 5).ntcode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[4] = yyattribute(5 - 5).ntcode;
	
#line 1574 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 782 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enum_specifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 1594 "myparser.cpp"
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
#line 793 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1613 "myparser.cpp"
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
#line 800 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator_list";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
	
#line 1634 "myparser.cpp"
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
#line 812 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1653 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 819 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="enumerator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3);
	
#line 1674 "myparser.cpp"
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
#line 831 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1693 "myparser.cpp"
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
#line 838 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="type_qualifier";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1712 "myparser.cpp"
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
#line 848 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 2);
	
#line 1732 "myparser.cpp"
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
#line 856 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1751 "myparser.cpp"
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
#line 866 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 1);
	
#line 1770 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 873 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1791 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 882 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 1813 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 892 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1834 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 901 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 1856 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 911 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[3] = yyattribute(4 - 4).ntnode;
	
#line 1878 "myparser.cpp"
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
#line 921 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr)->name="direct_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr)->children=new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr)->children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr)->children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr)->children[2] = yyattribute(3 - 3).ntnode;
	
#line 1899 "myparser.cpp"
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
#line 933 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 1918 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 940 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 1938 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 948 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 1958 "myparser.cpp"
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
#line 956 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node ();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "pointer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
	
#line 1978 "myparser.cpp"
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
#line 967 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 1997 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 974 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 2017 "myparser.cpp"
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
#line 986 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2036 "myparser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 993 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_type_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2057 "myparser.cpp"
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
#line 1005 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2076 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1012 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 2097 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1024 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 2117 "myparser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1032 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 2136 "myparser.cpp"
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
#line 1039 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "parameter_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2155 "myparser.cpp"
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
#line 1049 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2174 "myparser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1056 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_qualifier_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2195 "myparser.cpp"
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
#line 1068 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2214 "myparser.cpp"
			}
		}
		break;
	case 102:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1075 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "type_name";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 2234 "myparser.cpp"
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
#line 1086 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2253 "myparser.cpp"
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
#line 1093 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2272 "myparser.cpp"
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
#line 1100 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 2292 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1111 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2313 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1120 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;		
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 2333 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1128 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2354 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1137 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2375 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1146 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 2397 "myparser.cpp"
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
#line 1156 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 2417 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1164 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2438 "myparser.cpp"
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
#line 1173 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2459 "myparser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1182 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "direct_abstract_declarator";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 2481 "myparser.cpp"
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
#line 1195 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2500 "myparser.cpp"
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
#line 1202 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2521 "myparser.cpp"
			}
		}
		break;
	case 117:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1211 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 2543 "myparser.cpp"
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
#line 1224 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2562 "myparser.cpp"
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
#line 1231 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "initializer_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 2583 "myparser.cpp"
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
#line 1243 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2602 "myparser.cpp"
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
#line 1250 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2621 "myparser.cpp"
			}
		}
		break;
	case 122:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1257 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2640 "myparser.cpp"
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
#line 1264 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2659 "myparser.cpp"
			}
		}
		break;
	case 124:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1271 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2678 "myparser.cpp"
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
#line 1278 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2697 "myparser.cpp"
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
#line 1288 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 2718 "myparser.cpp"
			}
		}
		break;
	case 127:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1297 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4);
	
#line 2740 "myparser.cpp"
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
#line 1307 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "labeled_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 2761 "myparser.cpp"
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
#line 1319 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 2781 "myparser.cpp"
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
#line 1327 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2802 "myparser.cpp"
			}
		}
		break;
	case 131:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1336 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 2823 "myparser.cpp"
			}
		}
		break;
	case 132:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1345 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "compound_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;		
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4).ntnode;
	
#line 2845 "myparser.cpp"
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
#line 1358 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2864 "myparser.cpp"
			}
		}
		break;
	case 134:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1365 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "declaration_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 2884 "myparser.cpp"
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
#line 1376 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 2903 "myparser.cpp"
			}
		}
		break;
	case 136:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1383 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "statement_list";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 2923 "myparser.cpp"
			}
		}
		break;
	case 137:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1394 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1).ntnode;
	
#line 2942 "myparser.cpp"
			}
		}
		break;
	case 138:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1401 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "expression_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 2962 "myparser.cpp"
			}
		}
		break;
	case 139:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1412 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(4 - 5);
	
#line 2985 "myparser.cpp"
			}
		}
		break;
	case 140:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1423 ".\\myparser.y"

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
	
#line 3010 "myparser.cpp"
			}
		}
		break;
	case 141:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1436 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "selection_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 5);
	
#line 3033 "myparser.cpp"
			}
		}
		break;
	case 142:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1450 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "iteration_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 5;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [5];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 5);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 5).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[4] = yyattribute(5 - 5);
	
#line 3056 "myparser.cpp"
			}
		}
		break;
	case 143:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1461 ".\\myparser.y"

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
	
#line 3081 "myparser.cpp"
			}
		}
		break;
	case 144:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 1474 ".\\myparser.y"

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
	
#line 3105 "myparser.cpp"
			}
		}
		break;
	case 145:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 1486 ".\\myparser.y"

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
	
#line 3130 "myparser.cpp"
			}
		}
		break;
	case 146:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1502 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3151 "myparser.cpp"
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
#line 1511 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3171 "myparser.cpp"
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
#line 1519 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3191 "myparser.cpp"
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
#line 1527 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2).ntnode;
	
#line 3211 "myparser.cpp"
			}
		}
		break;
	case 150:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1535 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "jump_statement";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3).ntnode;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3).ntnode;
	
#line 3232 "myparser.cpp"
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
#line 1547 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3251 "myparser.cpp"
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
#line 1554 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "translation_unit";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3271 "myparser.cpp"
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
#line 1565 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 1;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [1];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3290 "myparser.cpp"
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
#line 1572 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "external_declaration";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 1);
	
#line 3309 "myparser.cpp"
			}
		}
		break;
	case 155:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1582 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 4;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [4];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 4);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[3] = yyattribute(4 - 4);
	
#line 3331 "myparser.cpp"
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
#line 1592 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 3352 "myparser.cpp"
			}
		}
		break;
	case 157:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1601 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 3;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [3];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 3);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[2] = yyattribute(3 - 3);
	
#line 3373 "myparser.cpp"
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
#line 1610 ".\\myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = new node();
		(*(YYSTYPE YYFAR*)yyvalptr) -> name = "function_definition";
		(*(YYSTYPE YYFAR*)yyvalptr) -> length = 2;
		(*(YYSTYPE YYFAR*)yyvalptr) -> children = new node* [2];
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[0] = yyattribute(1 - 2);
		(*(YYSTYPE YYFAR*)yyvalptr) -> children[1] = yyattribute(2 - 2);
	
#line 3393 "myparser.cpp"
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
		{ 3, 1, -1 },
		{ 3, 1, -1 },
		{ 3, 1, -1 },
		{ 3, 3, -1 },
		{ 4, 1, -1 },
		{ 4, 4, -1 },
		{ 4, 3, -1 },
		{ 4, 4, -1 },
		{ 4, 3, -1 },
		{ 4, 3, -1 },
		{ 4, 2, -1 },
		{ 4, 2, -1 },
		{ 5, 1, -1 },
		{ 5, 3, -1 },
		{ 6, 1, -1 },
		{ 6, 2, -1 },
		{ 6, 2, -1 },
		{ 6, 2, -1 },
		{ 6, 2, -1 },
		{ 6, 4, -1 },
		{ 7, 1, -1 },
		{ 7, 1, -1 },
		{ 7, 1, -1 },
		{ 7, 1, -1 },
		{ 7, 1, -1 },
		{ 7, 1, -1 },
		{ 8, 1, -1 },
		{ 8, 4, -1 },
		{ 9, 1, -1 },
		{ 9, 3, -1 },
		{ 9, 3, -1 },
		{ 9, 3, -1 },
		{ 10, 1, -1 },
		{ 10, 3, -1 },
		{ 10, 3, -1 },
		{ 11, 1, -1 },
		{ 11, 3, -1 },
		{ 11, 3, -1 },
		{ 12, 1, -1 },
		{ 12, 3, -1 },
		{ 12, 3, -1 },
		{ 12, 3, -1 },
		{ 12, 3, -1 },
		{ 13, 1, -1 },
		{ 13, 3, -1 },
		{ 13, 3, -1 },
		{ 14, 1, -1 },
		{ 14, 3, -1 },
		{ 15, 1, -1 },
		{ 15, 3, -1 },
		{ 16, 1, -1 },
		{ 16, 3, -1 },
		{ 17, 1, -1 },
		{ 17, 3, -1 },
		{ 18, 1, -1 },
		{ 18, 3, -1 },
		{ 19, 1, 4 },
		{ 19, 5, 5 },
		{ 20, 1, 6 },
		{ 20, 3, 7 },
		{ 21, 1, 8 },
		{ 21, 1, 9 },
		{ 21, 1, 10 },
		{ 21, 1, 11 },
		{ 21, 1, 12 },
		{ 21, 1, 13 },
		{ 21, 1, 14 },
		{ 21, 1, 15 },
		{ 21, 1, 16 },
		{ 21, 1, 17 },
		{ 21, 1, 18 },
		{ 22, 1, 19 },
		{ 22, 3, 20 },
		{ 23, 1, 21 },
		{ 24, 2, 22 },
		{ 24, 3, 23 },
		{ 25, 1, 24 },
		{ 25, 2, 25 },
		{ 25, 1, 26 },
		{ 25, 2, 27 },
		{ 25, 1, 28 },
		{ 25, 2, 29 },
		{ 26, 1, 30 },
		{ 26, 3, 31 },
		{ 27, 1, 32 },
		{ 27, 3, 33 },
		{ 28, 1, 34 },
		{ 28, 1, 35 },
		{ 28, 1, 36 },
		{ 28, 1, 37 },
		{ 28, 1, 38 },
		{ 29, 1, 39 },
		{ 29, 1, 40 },
		{ 29, 1, 41 },
		{ 29, 1, 42 },
		{ 29, 1, 43 },
		{ 29, 1, 44 },
		{ 29, 1, 45 },
		{ 29, 1, 46 },
		{ 29, 1, 47 },
		{ 29, 1, 48 },
		{ 29, 1, 49 },
		{ 29, 1, 50 },
		{ 30, 5, 51 },
		{ 30, 4, 52 },
		{ 30, 2, 53 },
		{ 31, 1, 54 },
		{ 31, 1, 55 },
		{ 32, 1, 56 },
		{ 32, 2, 57 },
		{ 33, 3, 58 },
		{ 34, 2, 59 },
		{ 34, 1, 60 },
		{ 34, 2, 61 },
		{ 34, 1, 62 },
		{ 35, 1, 63 },
		{ 35, 3, 64 },
		{ 36, 1, 65 },
		{ 36, 2, 66 },
		{ 36, 3, 67 },
		{ 37, 4, 68 },
		{ 37, 5, 69 },
		{ 37, 2, 70 },
		{ 38, 1, 71 },
		{ 38, 3, 72 },
		{ 39, 1, 73 },
		{ 39, 3, 74 },
		{ 40, 1, 75 },
		{ 40, 1, 76 },
		{ 41, 2, 77 },
		{ 41, 1, 78 },
		{ 42, 1, 79 },
		{ 42, 3, 80 },
		{ 42, 4, 81 },
		{ 42, 3, 82 },
		{ 42, 4, 83 },
		{ 42, 4, 84 },
		{ 42, 3, 85 },
		{ 43, 1, 86 },
		{ 43, 2, 87 },
		{ 43, 2, 88 },
		{ 43, 3, 89 },
		{ 44, 1, 90 },
		{ 44, 2, 91 },
		{ 45, 1, 92 },
		{ 45, 3, 93 },
		{ 46, 1, 94 },
		{ 46, 3, 95 },
		{ 47, 2, 96 },
		{ 47, 2, 97 },
		{ 47, 1, 98 },
		{ 48, 1, 99 },
		{ 48, 3, 100 },
		{ 49, 1, 101 },
		{ 49, 2, 102 },
		{ 50, 1, 103 },
		{ 50, 1, 104 },
		{ 50, 2, 105 },
		{ 51, 3, 106 },
		{ 51, 2, 107 },
		{ 51, 3, 108 },
		{ 51, 3, 109 },
		{ 51, 4, 110 },
		{ 51, 2, 111 },
		{ 51, 3, 112 },
		{ 51, 3, 113 },
		{ 51, 4, 114 },
		{ 52, 1, 115 },
		{ 52, 3, 116 },
		{ 52, 4, 117 },
		{ 53, 1, 118 },
		{ 53, 3, 119 },
		{ 54, 1, 120 },
		{ 54, 1, 121 },
		{ 54, 1, 122 },
		{ 54, 1, 123 },
		{ 54, 1, 124 },
		{ 54, 1, 125 },
		{ 55, 3, 126 },
		{ 55, 4, 127 },
		{ 55, 3, 128 },
		{ 56, 2, 129 },
		{ 56, 3, 130 },
		{ 56, 3, 131 },
		{ 56, 4, 132 },
		{ 57, 1, 133 },
		{ 57, 2, 134 },
		{ 58, 1, 135 },
		{ 58, 2, 136 },
		{ 59, 1, 137 },
		{ 59, 2, 138 },
		{ 60, 5, 139 },
		{ 60, 7, 140 },
		{ 60, 5, 141 },
		{ 61, 5, 142 },
		{ 61, 7, 143 },
		{ 61, 6, 144 },
		{ 61, 7, 145 },
		{ 62, 3, 146 },
		{ 62, 2, 147 },
		{ 62, 2, 148 },
		{ 62, 2, 149 },
		{ 62, 3, 150 },
		{ 63, 1, 151 },
		{ 63, 2, 152 },
		{ 64, 1, 153 },
		{ 64, 1, 154 },
		{ 65, 4, 155 },
		{ 65, 3, 156 },
		{ 65, 3, 157 },
		{ 65, 2, 158 }
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
		{ 268, YYAT_SHIFT, 195 },
		{ 127, YYAT_ERROR, 0 },
		{ 268, YYAT_SHIFT, 196 },
		{ 267, YYAT_SHIFT, 195 },
		{ 290, YYAT_SHIFT, 319 },
		{ 267, YYAT_SHIFT, 196 },
		{ 343, YYAT_SHIFT, 347 },
		{ 237, YYAT_ERROR, 0 },
		{ 335, YYAT_SHIFT, 345 },
		{ 151, YYAT_SHIFT, 149 },
		{ 333, YYAT_SHIFT, 343 },
		{ 335, YYAT_SHIFT, 207 },
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
		{ 276, YYAT_SHIFT, 173 },
		{ 119, YYAT_SHIFT, 75 },
		{ 276, YYAT_SHIFT, 174 },
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
		{ 109, YYAT_SHIFT, 209 },
		{ 154, YYAT_SHIFT, 2 },
		{ 236, YYAT_SHIFT, 231 },
		{ 234, YYAT_SHIFT, 301 },
		{ 61, YYAT_SHIFT, 59 },
		{ 35, YYAT_SHIFT, 59 },
		{ 329, YYAT_SHIFT, 341 },
		{ 279, YYAT_SHIFT, 315 },
		{ 281, YYAT_SHIFT, 207 },
		{ 262, YYAT_SHIFT, 188 },
		{ 279, YYAT_SHIFT, 316 },
		{ 327, YYAT_SHIFT, 340 },
		{ 142, YYAT_SHIFT, 239 },
		{ 226, YYAT_SHIFT, 293 },
		{ 262, YYAT_SHIFT, 189 },
		{ 142, YYAT_SHIFT, 240 },
		{ 172, YYAT_SHIFT, 207 },
		{ 96, YYAT_SHIFT, 175 },
		{ 284, YYAT_SHIFT, 207 },
		{ 262, YYAT_SHIFT, 190 },
		{ 127, YYAT_SHIFT, 45 },
		{ 231, YYAT_SHIFT, 231 },
		{ 290, YYAT_SHIFT, 320 },
		{ 107, YYAT_SHIFT, 201 },
		{ 59, YYAT_SHIFT, 136 },
		{ 303, YYAT_SHIFT, 302 },
		{ 24, YYAT_ERROR, 0 },
		{ 151, YYAT_SHIFT, 244 },
		{ 226, YYAT_SHIFT, 294 },
		{ 107, YYAT_SHIFT, 202 },
		{ 247, YYAT_SHIFT, 232 },
		{ 172, YYAT_SHIFT, 260 },
		{ 284, YYAT_SHIFT, 318 },
		{ 230, YYAT_SHIFT, 295 },
		{ 249, YYAT_SHIFT, 232 },
		{ 318, YYAT_ERROR, 0 },
		{ 119, YYAT_SHIFT, 45 },
		{ 52, YYAT_SHIFT, 128 },
		{ 119, YYAT_SHIFT, 213 },
		{ 261, YYAT_SHIFT, 188 },
		{ 275, YYAT_SHIFT, 173 },
		{ 98, YYAT_SHIFT, 188 },
		{ 275, YYAT_SHIFT, 174 },
		{ 102, YYAT_SHIFT, 195 },
		{ 261, YYAT_SHIFT, 189 },
		{ 102, YYAT_SHIFT, 196 },
		{ 98, YYAT_SHIFT, 189 },
		{ 138, YYAT_SHIFT, 232 },
		{ 314, YYAT_SHIFT, 334 },
		{ 261, YYAT_SHIFT, 190 },
		{ 154, YYAT_SHIFT, 232 },
		{ 98, YYAT_SHIFT, 190 },
		{ 52, YYAT_SHIFT, 129 },
		{ 236, YYAT_SHIFT, 232 },
		{ 234, YYAT_SHIFT, 302 },
		{ 61, YYAT_SHIFT, 60 },
		{ 35, YYAT_SHIFT, 60 },
		{ 281, YYAT_SHIFT, 317 },
		{ 95, YYAT_SHIFT, 173 },
		{ 302, YYAT_SHIFT, 328 },
		{ 95, YYAT_SHIFT, 174 },
		{ 274, YYAT_SHIFT, 199 },
		{ 274, YYAT_SHIFT, 200 },
		{ 273, YYAT_SHIFT, 199 },
		{ 273, YYAT_SHIFT, 200 },
		{ 300, YYAT_SHIFT, 325 },
		{ 345, YYAT_SHIFT, 78 },
		{ 319, YYAT_SHIFT, 217 },
		{ 33, YYAT_SHIFT, 58 },
		{ 319, YYAT_SHIFT, 338 },
		{ 319, YYAT_SHIFT, 77 },
		{ 23, YYAT_SHIFT, 43 },
		{ 272, YYAT_SHIFT, 199 },
		{ 272, YYAT_SHIFT, 200 },
		{ 107, YYAT_SHIFT, 203 },
		{ 271, YYAT_SHIFT, 199 },
		{ 271, YYAT_SHIFT, 200 },
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
		{ 270, YYAT_SHIFT, 191 },
		{ 270, YYAT_SHIFT, 192 },
		{ 105, YYAT_SHIFT, 199 },
		{ 105, YYAT_SHIFT, 200 },
		{ 99, YYAT_SHIFT, 191 },
		{ 99, YYAT_SHIFT, 192 },
		{ 297, YYAT_SHIFT, 323 },
		{ 287, YYAT_SHIFT, 211 },
		{ 286, YYAT_SHIFT, 193 },
		{ 285, YYAT_SHIFT, 212 },
		{ 269, YYAT_SHIFT, 194 },
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
		{ 268, YYAT_SHIFT, 197 },
		{ 268, YYAT_SHIFT, 198 },
		{ 255, YYAT_SHIFT, 311 },
		{ 267, YYAT_SHIFT, 197 },
		{ 267, YYAT_SHIFT, 198 },
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
		{ 119, YYAT_SHIFT, 78 },
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
		{ 119, YYAT_SHIFT, 5 },
		{ 119, YYAT_SHIFT, 6 },
		{ 119, YYAT_SHIFT, 7 },
		{ 119, YYAT_SHIFT, 8 },
		{ 119, YYAT_SHIFT, 9 },
		{ 319, YYAT_SHIFT, 144 },
		{ 319, YYAT_SHIFT, 79 },
		{ 319, YYAT_SHIFT, 80 },
		{ 319, YYAT_SHIFT, 81 },
		{ 237, YYAT_SHIFT, 304 },
		{ 319, YYAT_SHIFT, 82 },
		{ 319, YYAT_SHIFT, 83 },
		{ 109, YYAT_SHIFT, 210 },
		{ 156, YYAT_SHIFT, 144 },
		{ 156, YYAT_SHIFT, 79 },
		{ 156, YYAT_SHIFT, 80 },
		{ 156, YYAT_SHIFT, 81 },
		{ 138, YYAT_SHIFT, 3 },
		{ 156, YYAT_SHIFT, 82 },
		{ 156, YYAT_SHIFT, 83 },
		{ 119, YYAT_SHIFT, 84 },
		{ 119, YYAT_SHIFT, 85 },
		{ 119, YYAT_SHIFT, 86 },
		{ 236, YYAT_SHIFT, 3 },
		{ 119, YYAT_SHIFT, 87 },
		{ 119, YYAT_SHIFT, 88 },
		{ 119, YYAT_SHIFT, 89 },
		{ 119, YYAT_SHIFT, 90 },
		{ 119, YYAT_SHIFT, 91 },
		{ 119, YYAT_SHIFT, 92 },
		{ 119, YYAT_SHIFT, 93 },
		{ 119, YYAT_SHIFT, 94 },
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
		{ 59, YYAT_SHIFT, 137 },
		{ 240, YYAT_SHIFT, 306 },
		{ 41, YYAT_SHIFT, 18 },
		{ 41, YYAT_SHIFT, 19 },
		{ 107, YYAT_SHIFT, 204 },
		{ 107, YYAT_SHIFT, 205 },
		{ 107, YYAT_SHIFT, 206 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 102, YYAT_SHIFT, 197 },
		{ 102, YYAT_SHIFT, 198 },
		{ 131, YYAT_SHIFT, 4 },
		{ 232, YYAT_SHIFT, 299 },
		{ 225, YYAT_SHIFT, 292 },
		{ 217, YYAT_ERROR, 0 },
		{ 214, YYAT_SHIFT, 288 },
		{ 204, YYAT_SHIFT, 282 },
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
		{ 202, YYAT_SHIFT, 280 },
		{ 201, YYAT_SHIFT, 277 },
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
		{ 146, YYAT_SHIFT, 241 },
		{ 141, YYAT_SHIFT, 238 },
		{ 140, YYAT_SHIFT, 237 },
		{ 135, YYAT_ERROR, 0 },
		{ 134, YYAT_SHIFT, 228 },
		{ 128, YYAT_ERROR, 0 },
		{ 122, YYAT_SHIFT, 125 },
		{ 121, YYAT_SHIFT, 215 },
		{ 112, YYAT_SHIFT, 212 },
		{ 110, YYAT_SHIFT, 211 },
		{ 108, YYAT_SHIFT, 208 },
		{ 101, YYAT_SHIFT, 194 },
		{ 100, YYAT_SHIFT, 193 },
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
		{ 60, YYAT_SHIFT, 143 },
		{ 58, YYAT_SHIFT, 135 },
		{ 47, YYAT_SHIFT, 50 },
		{ 45, YYAT_SHIFT, 76 },
		{ 43, YYAT_SHIFT, 68 },
		{ 38, YYAT_SHIFT, 62 },
		{ 36, YYAT_ERROR, 0 },
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
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 0, 0, YYAT_DEFAULT, 127 },
		{ 0, 0, YYAT_DEFAULT, 47 },
		{ -88, 1, YYAT_REDUCE, 83 },
		{ -133, 1, YYAT_REDUCE, 81 },
		{ -261, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ -119, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 36, 1, YYAT_REDUCE, 135 },
		{ 357, 1, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 357, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 17, 1, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_DEFAULT, 149 },
		{ 274, 1, YYAT_REDUCE, 127 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 271, 1, YYAT_DEFAULT, 119 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 336, 1, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ 0, 0, YYAT_DEFAULT, 127 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ -61, 1, YYAT_REDUCE, 89 },
		{ 64, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_DEFAULT, 135 },
		{ 271, 1, YYAT_REDUCE, 110 },
		{ 54, 1, YYAT_DEFAULT, 301 },
		{ 300, 1, YYAT_DEFAULT, 318 },
		{ 35, 1, YYAT_REDUCE, 134 },
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
		{ 86, 1, YYAT_REDUCE, 40 },
		{ 27, 1, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 75, 1, YYAT_REDUCE, 37 },
		{ -95, 1, YYAT_REDUCE, 51 },
		{ 284, 1, YYAT_REDUCE, 55 },
		{ 339, 1, YYAT_REDUCE, 53 },
		{ 54, 1, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ -93, 1, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 54, 1, YYAT_REDUCE, 19 },
		{ 317, 1, YYAT_DEFAULT, 172 },
		{ 8, 1, YYAT_REDUCE, 61 },
		{ 251, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 103, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ -16, 1, YYAT_DEFAULT, 156 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 248, 1, YYAT_DEFAULT, 345 },
		{ 311, 1, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 0, 0, YYAT_DEFAULT, 217 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ -32, 1, YYAT_DEFAULT, 301 },
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
		{ 0, 0, YYAT_REDUCE, 151 },
		{ 324, 1, YYAT_REDUCE, 149 },
		{ 326, 1, YYAT_ERROR, 0 },
		{ 42, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 273, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 107, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 323, 1, YYAT_ERROR, 0 },
		{ 322, 1, YYAT_DEFAULT, 335 },
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
		{ 0, 0, YYAT_DEFAULT, 318 },
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
		{ 304, 1, YYAT_DEFAULT, 318 },
		{ 86, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 70, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 202, 1, YYAT_DEFAULT, 345 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 0, 0, YYAT_REDUCE, 193 },
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
		{ 0, 0, YYAT_DEFAULT, 318 },
		{ 0, 0, YYAT_REDUCE, 8 },
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
		{ 73, 1, YYAT_REDUCE, 38 },
		{ 43, 1, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ -49, 1, YYAT_REDUCE, 49 },
		{ -52, 1, YYAT_REDUCE, 50 },
		{ 142, 1, YYAT_REDUCE, 54 },
		{ -99, 1, YYAT_REDUCE, 52 },
		{ -119, 1, YYAT_REDUCE, 44 },
		{ -122, 1, YYAT_REDUCE, 45 },
		{ -131, 1, YYAT_REDUCE, 46 },
		{ -133, 1, YYAT_REDUCE, 47 },
		{ 68, 1, YYAT_REDUCE, 41 },
		{ -1, 1, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 35, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 45, 1, YYAT_ERROR, 0 },
		{ -92, 1, YYAT_REDUCE, 60 },
		{ 84, 1, YYAT_REDUCE, 56 },
		{ 53, 1, YYAT_REDUCE, 58 },
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

	yynontermgoto_size = 220;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 345, 96 },
		{ 319, 218 },
		{ 258, 108 },
		{ 319, -1 },
		{ 24, 25 },
		{ 24, 27 },
		{ 345, 102 },
		{ 345, 99 },
		{ 345, 101 },
		{ 345, 100 },
		{ 345, 110 },
		{ 345, 112 },
		{ 345, 109 },
		{ 345, 111 },
		{ 345, 103 },
		{ 316, 336 },
		{ 345, 108 },
		{ 318, 145 },
		{ 45, 46 },
		{ 201, 279 },
		{ 342, 346 },
		{ 24, 26 },
		{ 24, 35 },
		{ 24, 36 },
		{ 30, 56 },
		{ 2, 39 },
		{ 334, 344 },
		{ 51, 46 },
		{ 2, 40 },
		{ 2, 41 },
		{ 318, 337 },
		{ 318, -1 },
		{ 313, 333 },
		{ 319, 339 },
		{ 201, 278 },
		{ 319, -1 },
		{ 319, -1 },
		{ 319, -1 },
		{ 312, 332 },
		{ 258, 314 },
		{ 319, -1 },
		{ 319, -1 },
		{ 319, -1 },
		{ 319, -1 },
		{ 24, 44 },
		{ 24, 37 },
		{ 30, -1 },
		{ 316, -1 },
		{ 345, 348 },
		{ 345, 118 },
		{ 345, 113 },
		{ 45, 119 },
		{ 45, 121 },
		{ 345, 120 },
		{ 345, 116 },
		{ 345, 114 },
		{ 345, 117 },
		{ 119, 123 },
		{ 119, 47 },
		{ 51, 126 },
		{ 51, 127 },
		{ 119, 29 },
		{ 119, 28 },
		{ 119, 31 },
		{ 119, 33 },
		{ 217, 289 },
		{ 217, 290 },
		{ 1, -1 },
		{ 127, 123 },
		{ 127, 47 },
		{ 119, 32 },
		{ 128, 221 },
		{ 1, 38 },
		{ 119, 30 },
		{ 301, 138 },
		{ 211, 286 },
		{ 211, -1 },
		{ 301, 29 },
		{ 301, 28 },
		{ 301, 31 },
		{ 301, 33 },
		{ 138, 233 },
		{ 138, 35 },
		{ 138, 236 },
		{ 302, 147 },
		{ 128, 122 },
		{ 301, 32 },
		{ 119, 115 },
		{ 302, 329 },
		{ 301, 30 },
		{ 138, 235 },
		{ 119, 214 },
		{ 210, 110 },
		{ 210, 285 },
		{ 301, 327 },
		{ 301, 140 },
		{ 301, 139 },
		{ 156, 130 },
		{ 156, 31 },
		{ 156, 33 },
		{ 127, 220 },
		{ 59, 141 },
		{ 156, 154 },
		{ 230, -1 },
		{ 59, 142 },
		{ 156, 32 },
		{ 230, -1 },
		{ 230, 130 },
		{ 156, 131 },
		{ 293, 322 },
		{ 41, 63 },
		{ 230, 229 },
		{ 230, 133 },
		{ 41, 64 },
		{ 293, 225 },
		{ 293, 35 },
		{ 293, 36 },
		{ 156, 251 },
		{ 230, 131 },
		{ 245, 106 },
		{ 245, 107 },
		{ 154, 249 },
		{ 245, 145 },
		{ 245, 97 },
		{ 245, 307 },
		{ 247, 249 },
		{ 311, 331 },
		{ 247, 298 },
		{ 154, 248 },
		{ 154, 234 },
		{ 200, 98 },
		{ 200, 276 },
		{ 247, 297 },
		{ 247, 234 },
		{ 212, 287 },
		{ 212, -1 },
		{ 212, -1 },
		{ 212, -1 },
		{ 237, -1 },
		{ 237, -1 },
		{ 237, 305 },
		{ 231, 38 },
		{ 231, 35 },
		{ 231, 236 },
		{ 314, 103 },
		{ 83, 160 },
		{ 314, 335 },
		{ 83, -1 },
		{ 198, 95 },
		{ 198, 274 },
		{ 194, 270 },
		{ 194, -1 },
		{ 193, 269 },
		{ 193, -1 },
		{ 192, 105 },
		{ 192, 268 },
		{ 174, 104 },
		{ 174, 262 },
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
		{ 26, 48 },
		{ 26, 49 },
		{ 0, 24 },
		{ 0, 34 },
		{ 310, 330 },
		{ 292, 321 },
		{ 252, 309 },
		{ 249, 303 },
		{ 236, 61 },
		{ 232, 300 },
		{ 224, 291 },
		{ 214, 216 },
		{ 209, 284 },
		{ 207, 283 },
		{ 203, 281 },
		{ 199, 275 },
		{ 197, 273 },
		{ 196, 272 },
		{ 195, 271 },
		{ 191, 267 },
		{ 190, 266 },
		{ 189, 265 },
		{ 188, 264 },
		{ 186, 263 },
		{ 173, 261 },
		{ 167, 258 },
		{ 165, 256 },
		{ 164, 255 },
		{ 163, 254 },
		{ 162, 253 },
		{ 158, 153 },
		{ 155, 250 },
		{ 149, 243 },
		{ 148, 242 },
		{ 130, 222 },
		{ 125, 219 },
		{ 97, 187 },
		{ 96, 186 },
		{ 94, 172 },
		{ 89, 166 },
		{ 84, 161 },
		{ 82, 159 },
		{ 81, 157 },
		{ 71, 152 },
		{ 60, 146 },
		{ 57, 134 },
		{ 49, 124 },
		{ 42, 67 },
		{ 36, 61 },
		{ 29, 55 },
		{ 28, 54 },
		{ 27, 51 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 107, 24 },
		{ 31, 293 },
		{ -15, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -20, 30 },
		{ 0, -1 },
		{ 112, 51 },
		{ 178, 47 },
		{ 193, 30 },
		{ 192, 30 },
		{ -1, 237 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 174, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 70, -1 },
		{ 177, 68 },
		{ 0, -1 },
		{ 0, -1 },
		{ -6, 119 },
		{ 0, -1 },
		{ 140, 128 },
		{ 0, -1 },
		{ 158, 127 },
		{ 0, -1 },
		{ 3, 127 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 181, 135 },
		{ 0, -1 },
		{ 56, 301 },
		{ 189, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 126, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 162, 156 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 204, 83 },
		{ 203, 83 },
		{ 139, 245 },
		{ 185, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 153, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 184, 314 },
		{ 0, -1 },
		{ 184, -1 },
		{ 196, 245 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 345 },
		{ 0, -1 },
		{ 0, 214 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 151, 319 },
		{ 0, -1 },
		{ 44, 30 },
		{ 44, 1 },
		{ 0, -1 },
		{ 168, 131 },
		{ 129, 230 },
		{ 0, -1 },
		{ 125, 293 },
		{ 0, 230 },
		{ 126, 230 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, 154 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 178, 302 },
		{ 161, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 78, -1 },
		{ 145, 345 },
		{ 68, 158 },
		{ 0, -1 },
		{ 176, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 143, 345 },
		{ 174, 314 },
		{ 173, 314 },
		{ 172, 314 },
		{ 0, -1 },
		{ 134, 258 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 183, 174 },
		{ 148, 245 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 171, 316 },
		{ 0, -1 },
		{ 182, 245 },
		{ 181, 245 },
		{ 180, 245 },
		{ 175, 192 },
		{ 143, 198 },
		{ 138, 211 },
		{ 137, 193 },
		{ 175, 198 },
		{ 174, 198 },
		{ 173, 198 },
		{ 138, 200 },
		{ 173, 200 },
		{ 121, 174 },
		{ 14, 316 },
		{ 0, -1 },
		{ 160, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 161, 316 },
		{ 0, -1 },
		{ 158, 314 },
		{ 76, 212 },
		{ 60, 212 },
		{ 118, 318 },
		{ 0, -1 },
		{ 125, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 13, 319 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 155, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 78, 30 },
		{ 100, 247 },
		{ 154, 302 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 134, 249 },
		{ 93, 301 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 116, -1 },
		{ 0, -1 },
		{ 82, 301 },
		{ 0, -1 },
		{ 124, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 120, 345 },
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
		{ 150, 302 },
		{ 73, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, -1 },
		{ 65, 318 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 118, 345 },
		{ 72, 345 },
		{ -16, 345 },
		{ 10, 314 },
		{ 124, 316 },
		{ 0, -1 },
		{ -5, 319 },
		{ 0, -1 },
		{ 11, 316 },
		{ -19, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -28, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -34, 345 },
		{ 0, -1 },
		{ 0, -1 },
		{ -6, 192 },
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
#line 1622 ".\\myparser.y"


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
