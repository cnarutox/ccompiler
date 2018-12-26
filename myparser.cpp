/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 77 of your 30 day trial period.
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
* Date: 12/26/18
* Time: 13:49:38
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
		// vector<typenode*>::iterator iter;
		// for (iter=v.begin();iter!=v.end();iter++){
		// 	cout<<(*iter)->name<<' ';
		// }
		// cout<<endl;
	}

	void show_string(vector<string> &v) {
		// for (int i=0; i<v.size();i++) {
		// 	cout<<v[i]<<" ";
		// }
		// cout<<endl;
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
					cout<<"---------------------------\n";
					cout<<"|warning: lose precision!!|\n";
					cout<<"---------------------------\n";
					return true;
				}
				return false;
			}
		}
		return true;
	}

	void search_struct(typenode *root, string name, typenode &p, int &addr) {
		//cout << '~\n';
		if(root == NULL)
		{
			//cout << "root->left->name == name" << endl;
		}
		if(root->left != NULL)
		{
			//cout << "left " << root->left->name << endl;
			if (root->left->name == name)
			{
				//cout << "into left\n";
				p = *(root -> right);
				addr = root->left->addr;
			} 
			else search_struct(root->left, name, p, addr);
		}
		if(root->right != NULL)
		{
			//cout << "right " << root->right->name << endl;
			search_struct(root->right, name, p, addr);
		}
	}

	
#line 133 "myparser.cpp"
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
	
#line 157 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 156 ".\\myparser.y"

		// place any extra cleanup code here
	
#line 171 "myparser.cpp"
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
			//printf("108 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			
			traverse_vartable(s.size()-1);
			typenode* ptr = search(yyattribute(1 - 1).ntnode->name,s.size()-1);					
			if(ptr != NULL)
			{
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *ptr;
			}
			var_name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
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
#line 198 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("116 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *(new typenode("double", 8));
			offset += (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width;
		
#line 323 "myparser.cpp"
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
#line 210 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("123 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 343 "myparser.cpp"
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
#line 218 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("130 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";	
			s.pop_back();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = yyattribute(2 - 3).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist = yyattribute(2 - 3).ntnode->falselist;  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 365 "myparser.cpp"
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
#line 228 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("125 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();			
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 385 "myparser.cpp"
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
#line 236 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 405 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 248 ".\\myparser.y"

			fun_name = var_name;
		
#line 420 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 254 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("142 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 446 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 268 ".\\myparser.y"
	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("149 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *(yyattribute(1 - 4).ntnode->type.right);
		
#line 470 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 280 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("159 ");
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
		
#line 497 "myparser.cpp"
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
#line 295 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("168 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			s.pop_back();  
			vector<string> v_argument_list_temp; //??no value
			typenode* type_exp = (search(fun_name, s.size()-1));
			traverse(type_exp);//?
			cout<<"~~~~~";
			cout<<v_argument_list.size();
			for(int x=0;x<v_argument_list.size();x++){
				cout<<v_argument_list[x]<<" ";
			}
			if(type_exp->name == "fun"){
				int i=0;
				if (v_argument_list_temp.size()!=v_argument_list.size()){
					cout<<"Argument_list matching failed."<<endl;
				}
				else{
					while(i<v_argument_list_temp.size()&&v_argument_list[i]!=v_argument_list_temp[i]){
						i++;
						cout<<v_argument_list[i]<<" "<<v_argument_list_temp[i]<<endl;
					}
				// for(int i=0; i<v_argument_list_temp.size();i++){
				// 	if(v_argument_list[i]!=v_argument_list_temp[i])
				// 		cout<<"Argument_list matching failed."<<endl;			
				// }
				}
				if(i==v_argument_list_temp.size()){
				cout<<"i"<<i<<endl;//i=0;
				cout<<"-----------------------"<<endl;
				cout<<"|Argument_list matched!|"<<endl;
				cout<<"-----------------------"<<endl;
				}
				else{
					cout<<"Argument_list matching failed."<<endl;
				}
			}
			// cout<<"clear v_argument_list"<<endl;
			v_argument_list.clear();
		
#line 551 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 337 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("178 ");
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
				int temp_addr;
				search_struct(&(yyattribute(1 - 3).ntnode->type), yyattribute(3 - 3).ntnode->name, pointer, temp_addr);
				if (pointer.name == "###")
					cout << "struct doesn't have " << yyattribute(3 - 3).ntnode->name << endl;
				else{
					cout<<"struct has "<<yyattribute(3 - 3).ntnode->name<<endl;
				}
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = pointer;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = yyattribute(1 - 3).ntnode->type.addr+temp_addr;
				cout<<"struct has ";
			} 
			else if(yyattribute(1 - 3).ntnode->type.name == "array" && yyattribute(1 - 3).ntnode->type.right->name == "record"){
				typenode pointer;
				pointer.name = "#O#O#O";
				int temp_addr;
				search_struct(yyattribute(1 - 3).ntnode->type.right, yyattribute(3 - 3).ntnode->name, pointer, temp_addr);
				if (pointer.name == "#O#O#O")
					cout << "struct doesn't have " << yyattribute(3 - 3).ntnode->name << endl;
				else{
					cout<<"struct has "<<yyattribute(3 - 3).ntnode->name<<endl;
				}
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = pointer;
			}
			else cout << "struct doesn't exist!\n";

		
		
#line 604 "myparser.cpp"
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
#line 378 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("187 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 626 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 388 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("196 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
				cout<<"No additive calculation can be made for uncalculable types."<<endl;
		
#line 650 "myparser.cpp"
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
#line 400 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
				cout<<"Can't subtract from uncalculable types."<<endl;
		
#line 674 "myparser.cpp"
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
#line 415 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("215 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			v_argument_list.push_back(yyattribute(1 - 1).ntnode->type.name);

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;						
		
#line 697 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 426 ".\\myparser.y"

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
		
#line 722 "myparser.cpp"
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
#line 442 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("234 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 748 "myparser.cpp"
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
#line 456 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("241 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
				cout<<"No additive calculation can be made for uncalculable types."<<endl;
		
#line 772 "myparser.cpp"
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
#line 468 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("249 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
				cout<<"Can't subtract from uncalculable types ."<<endl;
		
#line 796 "myparser.cpp"
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
#line 480 ".\\myparser.y"

			//cast_exp:单目表达式/强制类型转换
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("257 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			if(yyattribute(1 - 2).ntnode->name=="!") {
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = yyattribute(2 - 2).ntnode->falselist;
			    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist = yyattribute(2 - 2).ntnode->truelist;
			}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(2 - 2).ntnode->type;				
		
#line 823 "myparser.cpp"
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
#line 495 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("265 ");
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
		
#line 850 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 510 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("273 ");
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
		
#line 877 "myparser.cpp"
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
#line 528 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("286 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&r";
		
#line 894 "myparser.cpp"
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
#line 533 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*";
		
#line 911 "myparser.cpp"
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
#line 538 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("301 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+";
		
#line 928 "myparser.cpp"
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
#line 543 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("308 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-";
		
#line 945 "myparser.cpp"
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
#line 548 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("315 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="~";
		
#line 962 "myparser.cpp"
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
#line 553 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("322 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="!";
		
#line 979 "myparser.cpp"
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
#line 561 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("332 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1005 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 575 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("339 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
			s.pop_back();  
		
#line 1029 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 590 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("352 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;	
		
#line 1055 "myparser.cpp"
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
#line 604 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("359 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Mismatch of Operator Types in Multiplication Operations."<<endl;
			gen(newlabel(), "*", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
												
		
#line 1085 "myparser.cpp"
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
#line 622 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("368 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Divisional Operator Type Mismatch."<<endl;
			gen(newlabel(), "/", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
		
#line 1114 "myparser.cpp"
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
#line 639 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("377 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Complementation Operator Type Mismatch."<<endl;
			gen(newlabel(), "%", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
		
#line 1143 "myparser.cpp"
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
#line 659 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("389 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1169 "myparser.cpp"
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
#line 673 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("396 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Operator type r,  $4->type.addrmismatch."<<endl;		
			gen(newlabel(), "+", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
		
#line 1193 "myparser.cpp"
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
#line 685 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("405 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Operator type mismatch."<<endl;	
			gen(newlabel(), "-", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
		
#line 1217 "myparser.cpp"
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
#line 700 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("417 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1243 "myparser.cpp"
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
#line 714 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("424 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Shift Operator Operator Mismatch ."<<endl;
		
#line 1268 "myparser.cpp"
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
#line 727 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("433 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Shift Operator Operator Mismatch ."<<endl;
		
#line 1293 "myparser.cpp"
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
#line 743 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("445 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1319 "myparser.cpp"
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
#line 757 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("452 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Relational expression type mismatch ."<<endl;
			gen(newlabel(), "j<", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());
			gen(nextinstr, "j");
		
#line 1348 "myparser.cpp"
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
#line 774 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("461 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Relational expression type mismatch ."<<endl;
			gen(newlabel(), "j>", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());
			gen(nextinstr, "j");
		
#line 1373 "myparser.cpp"
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
#line 787 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("470 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Relational expression type mismatch ."<<endl;

			gen(newlabel(), "j>", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(newlabel());
			gen(nextinstr, "j"); 
		
#line 1403 "myparser.cpp"
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
#line 805 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("479 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Relational expression type mismatch ."<<endl;

			gen(newlabel(), "j<", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(newlabel());
			gen(nextinstr, "j");
		
#line 1433 "myparser.cpp"
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
#line 826 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("491 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1459 "myparser.cpp"
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
#line 840 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("498 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Relational expression type mismatch ."<<endl;
			gen(newlabel(), "j=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr);  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());       
			gen(nextinstr, "j"); 
		
#line 1489 "myparser.cpp"
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
#line 858 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("507 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Relational expression type mismatch ."<<endl;
			
			int nextinstr = newlabel();
			gen(nextinstr, "j=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr);  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			nextinstr = newlabel();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr);    
			gen(nextinstr, "j"); 
		
#line 1522 "myparser.cpp"
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
#line 882 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("519 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1548 "myparser.cpp"
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
#line 896 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("526 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;

			if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Intersection Operator Type Mismatch ."<<endl;
		
#line 1574 "myparser.cpp"
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
#line 913 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("538 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1600 "myparser.cpp"
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
#line 927 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("545 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;

			if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Intersection Operator Type Mismatch ."<<endl;
		
#line 1626 "myparser.cpp"
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
#line 944 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("557 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1652 "myparser.cpp"
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
#line 958 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("564 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;

			if (!isInteger(yyattribute(1 - 3).ntnode->type.name) || !isInteger(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Or operation left-right operand type mismatch "<<endl;
		
#line 1678 "myparser.cpp"
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
#line 975 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("576 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1704 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 989 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("583 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;

			backpatch(yyattribute(1 - 4).ntnode->truelist, yyattribute(3 - 4).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = yyattribute(4 - 4).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist = merge(yyattribute(1 - 4).ntnode->falselist, yyattribute(4 - 4).ntnode->falselist); 		
		
#line 1731 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#line 1006 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("584 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="M";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->instr = nextinstr + 1;
		
#line 1744 "myparser.cpp"
		}
		break;
	case 58:
		{
#line 1015 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("585 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist->push_back(nextinstr + 1);
			gen(nextinstr+1, "j");
		
#line 1756 "myparser.cpp"
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1025 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("595 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1782 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1040 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("602 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;
			backpatch(yyattribute(1 - 4).ntnode->falselist, yyattribute(3 - 4).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = merge(yyattribute(1 - 4).ntnode->truelist, yyattribute(4 - 4).ntnode->truelist);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(4 - 4).ntnode->falselist;
		
#line 1804 "myparser.cpp"
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
#line 1053 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("614 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";		
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
			 
		
#line 1831 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1068 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("621 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 5).ntnode->type;

			vector<string> v1;
			vector<string> v2;
			compare_traverse(&yyattribute(3 - 5).ntnode->type, v1);
			compare_traverse(&yyattribute(5 - 5).ntnode->type, v2);
			if (v1 == v2){
				cout<<"------\n";
				cout<<"|match|\n";
				cout<<"------\n";
			}	
			else{
				cout<<"-------\n"<<endl;
				cout<<"mismatch!\n"<<endl;
				cout<<"-------\n"<<endl;
			}			
		
#line 1865 "myparser.cpp"
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
#line 1093 ".\\myparser.y"

			//(1)谓词表达式




			//(2)条件表达式 a<b?a:b
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("635 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1895 "myparser.cpp"
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
#line 1111 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("642 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
			  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(3 - 3).ntnode->type;
			if (check_type(&yyattribute(1 - 3).ntnode->type, &yyattribute(3 - 3).ntnode->type)){
				cout<<"----------------"<<endl;
				cout<<"|Two sides equal|"<<endl;
				cout<<"----------------"<<endl;
			}	
			else{
				cout<<"---------------------"<<endl;
				cout<<"|Two sides don't equal|"<<endl;
				cout<<"---------------------"<<endl;
			}
			gen(newlabel(), yyattribute(2 - 3).ntnode->name, yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, yyattribute(1 - 3).ntnode->type.addr);

			
#line 1927 "myparser.cpp"
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
#line 1134 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("654 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 1947 "myparser.cpp"
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
#line 1142 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("661 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 1967 "myparser.cpp"
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
#line 1150 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("668 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="/=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 1987 "myparser.cpp"
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
#line 1158 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("675 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="%=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2007 "myparser.cpp"
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
#line 1166 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("682 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2027 "myparser.cpp"
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
#line 1174 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2047 "myparser.cpp"
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
#line 1182 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("696 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="<<=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2067 "myparser.cpp"
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
#line 1190 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("703 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name=">>=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2087 "myparser.cpp"
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
#line 1198 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("710 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2107 "myparser.cpp"
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
#line 1206 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("717 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="^=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2127 "myparser.cpp"
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
#line 1214 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("724 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="|=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2147 "myparser.cpp"
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
#line 1225 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("740 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 2171 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1237 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("741 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;
			
			gen(newlabel(), ",", yyattribute(1 - 3).ntnode->instr, yyattribute(3 - 3).ntnode->instr, yyattribute(3 - 3).ntnode->type.addr);
		
#line 2196 "myparser.cpp"
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
#line 1253 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("753 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		
#line 2218 "myparser.cpp"
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
#line 1266 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("763 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
		
#line 2239 "myparser.cpp"
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
#line 1275 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("771 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;		
		
#line 2263 "myparser.cpp"
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
#line 1293 ".\\myparser.y"
 //static
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("783 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
#line 2284 "myparser.cpp"
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
#line 1303 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("791 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2306 "myparser.cpp"
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
#line 1313 ".\\myparser.y"
 // int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("799 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
#line 2327 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1322 ".\\myparser.y"
 // lont int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("806 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2349 "myparser.cpp"
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
#line 1332 ".\\myparser.y"
 //const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("814 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;	
		
#line 2370 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1341 ".\\myparser.y"
 //const int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("821 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2392 "myparser.cpp"
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
#line 1354 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("832 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		
#line 2414 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1364 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
		
#line 2436 "myparser.cpp"
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
#line 1377 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("851 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2456 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1385 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("858 ");
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
			show_string(v1);
			show_string(v2);
			if (check_type(&(yyattribute(1 - 3).ntnode->type), &(yyattribute(3 - 3).ntnode->type))){
				cout<<"-------"<<endl;
				cout<<"|match!|"<<endl;
				cout<<"-------"<<endl;
			}
			else{
				cout<<"----------"<<endl;
				cout<<"|!mismatch|"<<endl;
				cout<<"-----------"<<endl;
			}
			gen(newlabel(), "=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, yyattribute(1 - 3).ntnode->type.addr);
		
#line 2498 "myparser.cpp"
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
#line 1418 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("870 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;			
		
#line 2518 "myparser.cpp"
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
#line 1426 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("877 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2538 "myparser.cpp"
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
#line 1434 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("884 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2558 "myparser.cpp"
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
#line 1442 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2578 "myparser.cpp"
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
#line 1450 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("898 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 2598 "myparser.cpp"
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
#line 1461 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			wFlag(voidnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=voidnode;
		
#line 2620 "myparser.cpp"
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
#line 1471 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("915 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(charnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=charnode;
		
#line 2642 "myparser.cpp"
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
#line 1481 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("922 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(shortnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=shortnode;
		
#line 2664 "myparser.cpp"
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
#line 1491 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("929 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(intnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=intnode;
		
#line 2686 "myparser.cpp"
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
#line 1501 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("936 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(longnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=longnode;
		
#line 2708 "myparser.cpp"
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
#line 1511 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("943 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(floatnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=floatnode;
		
#line 2730 "myparser.cpp"
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
#line 1521 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("950 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(doublenode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=doublenode;
		
#line 2752 "myparser.cpp"
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
#line 1531 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("957 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(signednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=signednode;
		
#line 2774 "myparser.cpp"
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
#line 1541 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(unsignednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=unsignednode;
		
#line 2796 "myparser.cpp"
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
#line 1551 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			wFlag(yyattribute(1 - 1).ntnode->type);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = yyattribute(1 - 1).ntnode -> type;

		
#line 2820 "myparser.cpp"
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
#line 1563 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("978 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2840 "myparser.cpp"
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
#line 1571 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("985 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2860 "myparser.cpp"
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
#line 1579 ".\\myparser.y"

		
#line 2874 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1584 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("986 ");
			wFlag(*(create_struct(yyattribute(2 - 5).ntnode->name)));
		
#line 2891 "myparser.cpp"
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
#line 1590 ".\\myparser.y"

			static int i = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("987 ");
			wFlag(*(create_struct("struct" + to_string(i))));
			s.back()->vartable["struct" + to_string(i++)] = rFlag();
		
#line 2910 "myparser.cpp"
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
#line 1599 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("988 ");
		
#line 2926 "myparser.cpp"
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
#line 1603 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("989 ");
		
#line 2942 "myparser.cpp"
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
#line 1609 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("990 ");
		
#line 2958 "myparser.cpp"
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
#line 1613 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("991 ");
			
			map<string, typenode*>::iterator i;
			if ((i = auto_define_type.find(yyattribute(2 - 2).ntnode->name)) != auto_define_type.end())
			{
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *auto_define_type[yyattribute(2 - 2).ntnode->name];
			}
			else cout << "struct doesn't exist!\n";
		
#line 2981 "myparser.cpp"
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
#line 1702 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1027 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3001 "myparser.cpp"
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
#line 1710 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1034 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3021 "myparser.cpp"
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
#line 1721 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1044 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3041 "myparser.cpp"
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
#line 1729 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1051 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
		
#line 3062 "myparser.cpp"
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
#line 1741 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1062 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3084 "myparser.cpp"
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
#line 1751 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1062 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3106 "myparser.cpp"
			}
		}
		break;
	case 121:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1764 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1074 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3127 "myparser.cpp"
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
#line 1773 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1082 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3147 "myparser.cpp"
			}
		}
		break;
	case 123:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1781 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1089 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3168 "myparser.cpp"
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
#line 1790 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1097 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3188 "myparser.cpp"
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
#line 1801 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1107 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3208 "myparser.cpp"
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
#line 1809 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1114 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3230 "myparser.cpp"
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
#line 1822 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3250 "myparser.cpp"
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
#line 1830 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1133 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3271 "myparser.cpp"
			}
		}
		break;
	case 129:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1839 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1141 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3293 "myparser.cpp"
			}
		}
		break;
	case 130:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1852 ".\\myparser.y"
 //enum {a=1,b}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1153 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
		
#line 3316 "myparser.cpp"
			}
		}
		break;
	case 131:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1863 ".\\myparser.y"
 //enum q{a,b}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1163 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [5];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 5).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 5).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 5).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 5).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[4] = yyattribute(5 - 5).ntnode;
		
#line 3340 "myparser.cpp"
			}
		}
		break;
	case 132:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1875 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1174 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3361 "myparser.cpp"
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
#line 1887 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1185 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3381 "myparser.cpp"
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
#line 1895 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1192 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		
#line 3399 "myparser.cpp"
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
#line 1904 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3419 "myparser.cpp"
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
#line 1912 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1211 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3441 "myparser.cpp"
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
#line 1925 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1223 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3461 "myparser.cpp"
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
#line 1933 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1230 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3481 "myparser.cpp"
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
#line 1944 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1240 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3502 "myparser.cpp"
			}
		}
		break;
	case 140:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1953 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1248 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
#line 3523 "myparser.cpp"
			}
		}
		break;
	case 141:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1964 ".\\myparser.y"

			fun_name = var_name;
		
#line 3538 "myparser.cpp"
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
#line 1970 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1258 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			var_name = yyattribute(1 - 1).ntnode->name;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
			//cout << $1.ntnode->name << rFlag()->width << endl;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			offset += rFlag()->width;
		
#line 3563 "myparser.cpp"
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
#line 1983 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1265 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			s.pop_back();  
		
#line 3587 "myparser.cpp"
			}
		}
		break;
	case 144:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1995 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1274 ");
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
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			offset += rFlag()->width;
			traverse(root);
		
#line 3634 "myparser.cpp"
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
#line 2030 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1284 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3656 "myparser.cpp"
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
#line 2040 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		
#line 3675 "myparser.cpp"
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
#line 2047 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1303 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}	
			s.pop_back();  
		
#line 3698 "myparser.cpp"
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
#line 2058 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1313 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			fun_name = var_name;
		
#line 3718 "myparser.cpp"
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
#line 2069 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1325 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			typenode* temp = new typenode("pointer");
			temp->left=rFlag();
			temp->width = 4;
			flag = !flag;
			wFlag(*temp);
			traverse(temp);
		
#line 3745 "myparser.cpp"
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
#line 2084 ".\\myparser.y"
 // *const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 3765 "myparser.cpp"
			}
		}
		break;
	case 151:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2092 ".\\myparser.y"
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
		
#line 3791 "myparser.cpp"
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
#line 2106 ".\\myparser.y"
 //*const*
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		
#line 3811 "myparser.cpp"
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
#line 2117 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1359 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 3831 "myparser.cpp"
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
#line 2125 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1366 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 3852 "myparser.cpp"
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
#line 2138 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1378 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			type3->left = rFlag();
		
#line 3874 "myparser.cpp"
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
#line 2148 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1385 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 3896 "myparser.cpp"
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
#line 2161 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1397 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 3916 "myparser.cpp"
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
#line 2169 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1404 ");
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
		
#line 3944 "myparser.cpp"
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
#line 2188 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1416 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 3965 "myparser.cpp"
			}
		}
		break;
	case 160:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2197 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1424 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 3985 "myparser.cpp"
			}
		}
		break;
	case 161:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2205 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1431 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4005 "myparser.cpp"
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
#line 2216 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1441 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
			offset += rFlag()->width;
		
#line 4027 "myparser.cpp"
			}
		}
		break;
	case 163:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2226 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1448 ");   
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.back()->vartable[yyattribute(3 - 3).ntnode->name] = rFlag();	
			offset += rFlag()->width;
		
#line 4051 "myparser.cpp"
			}
		}
		break;
	case 164:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2241 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1460 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4071 "myparser.cpp"
			}
		}
		break;
	case 165:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2249 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1467 ");  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4092 "myparser.cpp"
			}
		}
		break;
	case 166:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2261 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1478 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4112 "myparser.cpp"
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
#line 2269 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1485 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4132 "myparser.cpp"
			}
		}
		break;
	case 168:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2277 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1492 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4153 "myparser.cpp"
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
#line 2289 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1503 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4176 "myparser.cpp"
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
#line 2300 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1512 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4197 "myparser.cpp"
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
#line 2309 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1520 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4219 "myparser.cpp"
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
#line 2319 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1529 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4241 "myparser.cpp"
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
#line 2329 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1538 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
#line 4264 "myparser.cpp"
			}
		}
		break;
	case 174:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2340 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1548 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			s.pop_back();  
		
#line 4286 "myparser.cpp"
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
#line 2350 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1556 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4309 "myparser.cpp"
			}
		}
		break;
	case 176:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2361 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1565 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4332 "myparser.cpp"
			}
		}
		break;
	case 177:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2372 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1574 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
			s.pop_back();  
		
#line 4356 "myparser.cpp"
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
#line 2387 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1587 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
#line 4378 "myparser.cpp"
			}
		}
		break;
	case 179:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2397 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1594 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4400 "myparser.cpp"
			}
		}
		break;
	case 180:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2407 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1603 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
#line 4423 "myparser.cpp"
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
#line 2421 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1616 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4443 "myparser.cpp"
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
#line 2429 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1623 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4465 "myparser.cpp"
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
#line 2441 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1635 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4482 "myparser.cpp"
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
#line 2446 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1642 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4499 "myparser.cpp"
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
#line 2451 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1643 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4516 "myparser.cpp"
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
#line 2456 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1643 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4533 "myparser.cpp"
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
#line 2463 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1644 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
#line 4555 "myparser.cpp"
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
#line 2473 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1669 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "xx";
		
#line 4572 "myparser.cpp"
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
#line 2478 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1670 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4589 "myparser.cpp"
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
#line 2485 ".\\myparser.y"

		
	
#line 4604 "myparser.cpp"
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
#line 2489 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1680 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4626 "myparser.cpp"
			}
		}
		break;
	case 192:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2499 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
#line 4643 "myparser.cpp"
			}
		}
		break;
	case 193:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2504 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1699 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
#line 4660 "myparser.cpp"
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
#line 2512 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1711 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4681 "myparser.cpp"
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
#line 2521 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1719 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 4699 "myparser.cpp"
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
#line 2527 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1728 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 4717 "myparser.cpp"
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
#line 2533 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1737 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist= yyattribute(3 - 4).ntnode->nextlist ;
		
#line 4735 "myparser.cpp"
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
#line 2542 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1750 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
#line 4757 "myparser.cpp"
			}
		}
		break;
	case 199:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2552 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1757 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =yyattribute(3 - 3).ntnode->nextlist; 
		
#line 4776 "myparser.cpp"
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
#line 2562 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1768 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4796 "myparser.cpp"
			}
		}
		break;
	case 201:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2570 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//cout<<"$2->instr:"<<$2->instr<<endl;
			//printf("1775 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =yyattribute(3 - 3).ntnode->nextlist; 
		
#line 4816 "myparser.cpp"
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
#line 2581 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1786 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4836 "myparser.cpp"
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
#line 2589 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1793 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4857 "myparser.cpp"
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
#line 2600 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1794 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
#line 4878 "myparser.cpp"
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
#line 2609 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(); 
			//printf("1795 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4898 "myparser.cpp"
			}
		}
		break;
	case 206:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 2619 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1803 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
			s.pop_back();
			traverse_vartable(s.size() - 1);	 					
		
#line 4920 "myparser.cpp"
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
#line 2629 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1815 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			traverse_vartable(s.size() - 1);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type; 
		
#line 4942 "myparser.cpp"
			}
		}
		break;
	case 208:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 2641 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1816 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(6 - 6).ntnode->type;
			s.pop_back();
			traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 6).ntnode->truelist, yyattribute(5 - 6).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =merge(yyattribute(3 - 6).ntnode->falselist, yyattribute(6 - 6).ntnode->nextlist); 
			 
		
#line 4965 "myparser.cpp"
			}
		}
		break;
	case 209:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 2652 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1817 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			s.pop_back();
			traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
		
#line 4987 "myparser.cpp"
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
#line 2664 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1818 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5007 "myparser.cpp"
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
#line 2672 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1825 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			s.pop_back();  
		
#line 5025 "myparser.cpp"
			}
		}
		break;
	case 212:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2680 ".\\myparser.y"

		    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(3 - 4).ntnode->type;
			offset += (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width;
			switch_addr = (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr;			
			gen(newlabel(), "=", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr, 0, yyattribute(3 - 4).ntnode->type.addr);
			default_label=newlabel();
			gen(nextinstr,"j",0,0,default_label);
	
#line 5045 "myparser.cpp"
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
#line 2690 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(4 - 7).ntnode->truelist, yyattribute(6 - 7).ntnode->instr); 
			backpatch(yyattribute(7 - 7).ntnode->nextlist, yyattribute(2 - 7).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(4 - 7).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(2 - 7).ntnode->instr) ; 
			s.pop_back();
		
#line 5067 "myparser.cpp"
			}
		}
		break;
	case 214:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 2700 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1850 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(7 - 9).ntnode->truelist, yyattribute(2 - 9).ntnode->instr); 
			backpatch(yyattribute(3 - 9).ntnode->nextlist, yyattribute(5 - 9).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(7 - 9).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(5 - 9).ntnode->instr) ; 
			s.pop_back(); 
		
#line 5089 "myparser.cpp"
			}
		}
		break;
	case 215:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 2710 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1863 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}
			backpatch(yyattribute(5 - 8).ntnode->truelist, yyattribute(8 - 8).ntnode->instr);
			backpatch(yyattribute(8 - 8).ntnode->nextlist, yyattribute(5 - 8).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=yyattribute(5 - 8).ntnode->falselist;
			s.pop_back();		  
		
#line 5114 "myparser.cpp"
			}
		}
		break;
	case 216:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 2723 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1875 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(5 - 10).ntnode->truelist, yyattribute(9 - 10).ntnode->instr);
			backpatch(yyattribute(10 - 10).ntnode->nextlist, yyattribute(6 - 10).ntnode->instr);
			backpatch(yyattribute(7 - 10).ntnode->nextlist,yyattribute(4 - 10).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist= yyattribute(5 - 10).ntnode->falselist;
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++)
			{
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}
			
			s.pop_back();
		
#line 5142 "myparser.cpp"
			}
		}
		break;
	case 217:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2742 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 5164 "myparser.cpp"
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
#line 2752 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1900 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 5185 "myparser.cpp"
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
#line 2761 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 5206 "myparser.cpp"
			}
		}
		break;
	case 220:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2770 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1916 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			rtn_stmt.push(&voidnode);		
		
#line 5228 "myparser.cpp"
			}
		}
		break;
	case 221:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2780 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1924 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;	
			rtn_stmt.push(&(yyattribute(2 - 3).ntnode->type));	
		
#line 5251 "myparser.cpp"
			}
		}
		break;
	case 222:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2794 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1946 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			show_code();
		
#line 5272 "myparser.cpp"
			}
		}
		break;
	case 223:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2803 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1953 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			show_code();
		
#line 5294 "myparser.cpp"
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
#line 2816 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5314 "myparser.cpp"
			}
		}
		break;
	case 225:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2824 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5334 "myparser.cpp"
			}
		}
		break;
	case 226:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2835 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1981 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
			type3->right = &(yyattribute(1 - 4).ntnode->type);
			s.back()->vartable[fun_name] = type3;
			if (rtn_stmt.size() == 0 && type3->right->name !="void" ){
				cout<<"type error in 1991!"<<endl;
			}
			while(rtn_stmt.size()>0){ 
			typenode *a = rtn_stmt.top();
			//cout<<"stack top"<<a->name<<endl;
			if(!check_type(a,&(yyattribute(1 - 4).ntnode->type)))
			{
						cout<<"type error in 1991!"<<endl;
			}
			rtn_stmt.pop();
			}	
			s.pop_back();
		
#line 5372 "myparser.cpp"
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
#line 2861 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1991 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;

			type3->right = &(yyattribute(1 - 3).ntnode->type);
			s[s.size()-2]->vartable[fun_name] = type3;
			if (rtn_stmt.size() == 0 && type3->right->name != "void"){
				cout<<"type error in 1991!"<<endl;
			}	
			while(rtn_stmt.size()>0){
				typenode *a = rtn_stmt.top();
				if(!check_type(a,&(yyattribute(1 - 3).ntnode->type)))
				{
						cout<<"type error in 1991!"<<endl;
				}
				rtn_stmt.pop();
			}	
			traverse_vartable(s.size()-1);	
			s.pop_back();
		
#line 5410 "myparser.cpp"
			}
		}
		break;
	case 228:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2887 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("2000 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			type3->right = &(yyattribute(1 - 3).ntnode->type);
			s.back()->vartable[fun_name] = type3;
			if (rtn_stmt.size() == 0 && type3->right->name != "void"){
				cout<<"type error in 1991!"<<endl;
			}		
			while(rtn_stmt.size()>0){
			typenode *a = rtn_stmt.top();
			if(!check_type(a,&(yyattribute(1 - 3).ntnode->type)))
			{
						cout<<"type error in 1991!"<<endl;
			}
			rtn_stmt.pop();
			}	
			s.pop_back();
		
#line 5446 "myparser.cpp"
			}
		}
		break;
	case 229:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2911 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("2009 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			type3->right = &(yyattribute(1 - 2).ntnode->type);
			s.back()->vartable[fun_name] = type3;
			if (rtn_stmt.size() == 0 && type3->right->name != "void"){
				cout<<"type error in 1991!"<<endl;
			}	
			while(rtn_stmt.size()>0){
			typenode *a = rtn_stmt.top();
			if(!check_type(a,&(yyattribute(1 - 2).ntnode->type)))
			{
						cout<<"type error in 1991!"<<endl;
			}
			rtn_stmt.pop();
			}	
			s.pop_back();
		
#line 5481 "myparser.cpp"
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
		{ "TRUE", 283 },
		{ "FALSE", 284 },
		{ "TYPEDEF", 285 },
		{ "EXTERN", 286 },
		{ "STATIC", 287 },
		{ "AUTO", 288 },
		{ "REGISTER", 289 },
		{ "CHAR", 290 },
		{ "SHORT", 291 },
		{ "INT", 292 },
		{ "LONG", 293 },
		{ "SIGNED", 294 },
		{ "UNSIGNED", 295 },
		{ "FLOAT", 296 },
		{ "DOUBLE", 297 },
		{ "CONST", 298 },
		{ "VOLATILE", 299 },
		{ "VOID", 300 },
		{ "STRUCT", 301 },
		{ "UNION", 302 },
		{ "ENUM", 303 },
		{ "ELLIPSIS", 304 },
		{ "CASE", 305 },
		{ "DEFAULT", 306 },
		{ "IF", 307 },
		{ "ELSE", 308 },
		{ "SWITCH", 309 },
		{ "WHILE", 310 },
		{ "DO", 311 },
		{ "FOR", 312 },
		{ "GOTO", 313 },
		{ "CONTINUE", 314 },
		{ "BREAK", 315 },
		{ "RETURN", 316 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: translation_unit",
		"primary_exp: ID",
		"primary_exp: CONSTANT",
		"primary_exp: STRING_LITERAL",
		"primary_exp: \'(\' exp \')\'",
		"primary_exp: TRUE",
		"primary_exp: FALSE",
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
		"logical_and_exp: logical_and_exp AND_OP M inclusive_or_exp",
		"M:",
		"N:",
		"logical_or_exp: logical_and_exp",
		"logical_or_exp: logical_or_exp OR_OP M logical_and_exp",
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
		"other: compound_statement",
		"other: exp_statement",
		"other: iteration_statement",
		"other: jump_statement",
		"statement: labeled_statement",
		"statement: other",
		"statement: selection_statement",
		"default_pre: DEFAULT \':\'",
		"labeled_statement: ID \':\' statement",
		"labeled_statement: CASE constant_exp \':\' M statement",
		"labeled_statement: default_pre statement",
		"compound_statement: \'{\' \'}\'",
		"compound_statement: \'{\' statement_list \'}\'",
		"compound_statement: \'{\' declaration_list \'}\'",
		"compound_statement: \'{\' declaration_list statement_list \'}\'",
		"declaration_list: declaration",
		"declaration_list: declaration_list M declaration",
		"statement_list: statement",
		"statement_list: statement_list M statement",
		"exp_statement: \';\'",
		"exp_statement: exp \';\'",
		"stmt: matched_statement",
		"stmt: open_statement",
		"matched_statement: IF \'(\' exp \')\' M matched_statement N ELSE M matched_statement",
		"matched_statement: other",
		"open_statement: IF \'(\' exp \')\' M stmt",
		"open_statement: IF \'(\' exp \')\' M matched_statement N ELSE M open_statement",
		"selection_statement: stmt",
		"selection_statement: switch_pre statement",
		"switch_pre: SWITCH \'(\' exp \')\'",
		"iteration_statement: WHILE M \'(\' exp \')\' M statement",
		"iteration_statement: DO M statement WHILE M \'(\' exp \')\' \';\'",
		"iteration_statement: FOR \'(\' exp_statement M exp_statement \')\' M statement",
		"iteration_statement: FOR \'(\' exp_statement M exp_statement M exp \')\' M statement",
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
		{ 1, 1, 4 },
		{ 1, 1, 5 },
		{ 2, 2, 6 },
		{ 3, 1, 7 },
		{ 3, 4, 8 },
		{ 3, 2, 9 },
		{ 3, 3, 10 },
		{ 3, 3, 11 },
		{ 3, 3, 12 },
		{ 3, 2, 13 },
		{ 3, 2, 14 },
		{ 4, 1, 15 },
		{ 4, 3, 16 },
		{ 5, 1, 17 },
		{ 5, 2, 18 },
		{ 5, 2, 19 },
		{ 5, 2, 20 },
		{ 5, 2, 21 },
		{ 5, 4, 22 },
		{ 6, 1, 23 },
		{ 6, 1, 24 },
		{ 6, 1, 25 },
		{ 6, 1, 26 },
		{ 6, 1, 27 },
		{ 6, 1, 28 },
		{ 7, 1, 29 },
		{ 7, 4, 30 },
		{ 8, 1, 31 },
		{ 8, 3, 32 },
		{ 8, 3, 33 },
		{ 8, 3, 34 },
		{ 9, 1, 35 },
		{ 9, 3, 36 },
		{ 9, 3, 37 },
		{ 10, 1, 38 },
		{ 10, 3, 39 },
		{ 10, 3, 40 },
		{ 11, 1, 41 },
		{ 11, 3, 42 },
		{ 11, 3, 43 },
		{ 11, 3, 44 },
		{ 11, 3, 45 },
		{ 12, 1, 46 },
		{ 12, 3, 47 },
		{ 12, 3, 48 },
		{ 13, 1, 49 },
		{ 13, 3, 50 },
		{ 14, 1, 51 },
		{ 14, 3, 52 },
		{ 15, 1, 53 },
		{ 15, 3, 54 },
		{ 16, 1, 55 },
		{ 16, 4, 56 },
		{ 17, 0, 57 },
		{ 18, 0, 58 },
		{ 19, 1, 59 },
		{ 19, 4, 60 },
		{ 20, 1, 61 },
		{ 20, 5, 62 },
		{ 21, 1, 63 },
		{ 21, 3, 64 },
		{ 22, 1, 65 },
		{ 22, 1, 66 },
		{ 22, 1, 67 },
		{ 22, 1, 68 },
		{ 22, 1, 69 },
		{ 22, 1, 70 },
		{ 22, 1, 71 },
		{ 22, 1, 72 },
		{ 22, 1, 73 },
		{ 22, 1, 74 },
		{ 22, 1, 75 },
		{ 23, 1, 76 },
		{ 23, 3, 77 },
		{ 24, 1, 78 },
		{ 25, 2, 79 },
		{ 25, 3, 80 },
		{ 26, 1, 81 },
		{ 26, 2, 82 },
		{ 26, 1, 83 },
		{ 26, 2, 84 },
		{ 26, 1, 85 },
		{ 26, 2, 86 },
		{ 27, 1, 87 },
		{ 27, 3, 88 },
		{ 28, 1, 89 },
		{ 28, 3, 90 },
		{ 29, 1, 91 },
		{ 29, 1, 92 },
		{ 29, 1, 93 },
		{ 29, 1, 94 },
		{ 29, 1, 95 },
		{ 30, 1, 96 },
		{ 30, 1, 97 },
		{ 30, 1, 98 },
		{ 30, 1, 99 },
		{ 30, 1, 100 },
		{ 30, 1, 101 },
		{ 30, 1, 102 },
		{ 30, 1, 103 },
		{ 30, 1, 104 },
		{ 30, 1, 105 },
		{ 30, 1, 106 },
		{ 30, 1, 107 },
		{ 30, 2, 108 },
		{ 31, 5, 109 },
		{ 31, 4, 110 },
		{ 32, 1, 111 },
		{ 32, 2, 112 },
		{ 33, 2, 113 },
		{ 33, 2, 114 },
		{ 34, 1, 115 },
		{ 34, 1, 116 },
		{ 35, 1, 117 },
		{ 35, 2, 118 },
		{ 36, 3, 119 },
		{ 36, 3, 120 },
		{ 37, 2, 121 },
		{ 37, 1, 122 },
		{ 37, 2, 123 },
		{ 37, 1, 124 },
		{ 38, 1, 125 },
		{ 38, 3, 126 },
		{ 39, 1, 127 },
		{ 39, 2, 128 },
		{ 39, 3, 129 },
		{ 40, 4, 130 },
		{ 40, 5, 131 },
		{ 40, 2, 132 },
		{ 41, 1, 133 },
		{ 41, 3, 134 },
		{ 42, 1, 135 },
		{ 42, 3, 136 },
		{ 43, 1, 137 },
		{ 43, 1, 138 },
		{ 44, 2, 139 },
		{ 44, 1, 140 },
		{ 45, 2, 141 },
		{ 46, 1, 142 },
		{ 46, 3, 143 },
		{ 46, 4, 144 },
		{ 46, 3, 145 },
		{ 46, 3, 146 },
		{ 46, 3, 147 },
		{ 46, 2, 148 },
		{ 47, 1, 149 },
		{ 47, 2, 150 },
		{ 47, 2, 151 },
		{ 47, 3, 152 },
		{ 48, 1, 153 },
		{ 48, 2, 154 },
		{ 49, 1, 155 },
		{ 49, 3, 156 },
		{ 50, 1, 157 },
		{ 50, 3, 158 },
		{ 51, 2, 159 },
		{ 51, 2, 160 },
		{ 51, 1, 161 },
		{ 52, 1, 162 },
		{ 52, 3, 163 },
		{ 53, 1, 164 },
		{ 53, 2, 165 },
		{ 54, 1, 166 },
		{ 54, 1, 167 },
		{ 54, 2, 168 },
		{ 55, 3, 169 },
		{ 55, 2, 170 },
		{ 55, 3, 171 },
		{ 55, 3, 172 },
		{ 55, 4, 173 },
		{ 55, 2, 174 },
		{ 55, 3, 175 },
		{ 55, 3, 176 },
		{ 55, 4, 177 },
		{ 56, 1, 178 },
		{ 56, 3, 179 },
		{ 56, 4, 180 },
		{ 57, 1, 181 },
		{ 57, 3, 182 },
		{ 58, 1, 183 },
		{ 58, 1, 184 },
		{ 58, 1, 185 },
		{ 58, 1, 186 },
		{ 59, 1, 187 },
		{ 59, 1, 188 },
		{ 59, 1, 189 },
		{ 60, 2, 190 },
		{ 61, 3, 191 },
		{ 61, 5, 192 },
		{ 61, 2, 193 },
		{ 62, 2, 194 },
		{ 62, 3, 195 },
		{ 62, 3, 196 },
		{ 62, 4, 197 },
		{ 63, 1, 198 },
		{ 63, 3, 199 },
		{ 64, 1, 200 },
		{ 64, 3, 201 },
		{ 65, 1, 202 },
		{ 65, 2, 203 },
		{ 66, 1, 204 },
		{ 66, 1, 205 },
		{ 67, 10, 206 },
		{ 67, 1, 207 },
		{ 68, 6, 208 },
		{ 68, 10, 209 },
		{ 69, 1, 210 },
		{ 69, 2, 211 },
		{ 70, 4, 212 },
		{ 71, 7, 213 },
		{ 71, 9, 214 },
		{ 71, 8, 215 },
		{ 71, 10, 216 },
		{ 72, 3, 217 },
		{ 72, 2, 218 },
		{ 72, 2, 219 },
		{ 72, 2, 220 },
		{ 72, 3, 221 },
		{ 73, 1, 222 },
		{ 73, 2, 223 },
		{ 74, 1, 224 },
		{ 74, 1, 225 },
		{ 75, 4, 226 },
		{ 75, 3, 227 },
		{ 75, 3, 228 },
		{ 75, 2, 229 }
	};
	yyreduction = reduction;

	yytokenaction_size = 440;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 126, YYAT_SHIFT, 85 },
		{ 355, YYAT_ERROR, 0 },
		{ 119, YYAT_SHIFT, 211 },
		{ 41, YYAT_SHIFT, 2 },
		{ 137, YYAT_SHIFT, 242 },
		{ 126, YYAT_SHIFT, 86 },
		{ 75, YYAT_SHIFT, 164 },
		{ 126, YYAT_SHIFT, 87 },
		{ 75, YYAT_SHIFT, 2 },
		{ 126, YYAT_SHIFT, 88 },
		{ 126, YYAT_SHIFT, 89 },
		{ 2, YYAT_SHIFT, 2 },
		{ 126, YYAT_SHIFT, 90 },
		{ 367, YYAT_SHIFT, 85 },
		{ 155, YYAT_SHIFT, 1 },
		{ 167, YYAT_SHIFT, 164 },
		{ 155, YYAT_SHIFT, 2 },
		{ 164, YYAT_SHIFT, 164 },
		{ 367, YYAT_SHIFT, 86 },
		{ 38, YYAT_SHIFT, 69 },
		{ 367, YYAT_SHIFT, 87 },
		{ 24, YYAT_SHIFT, 46 },
		{ 367, YYAT_SHIFT, 88 },
		{ 367, YYAT_SHIFT, 89 },
		{ 122, YYAT_SHIFT, 224 },
		{ 367, YYAT_SHIFT, 90 },
		{ 126, YYAT_SHIFT, 91 },
		{ 23, YYAT_SHIFT, 44 },
		{ 36, YYAT_ACCEPT, 0 },
		{ 316, YYAT_SHIFT, 337 },
		{ 122, YYAT_SHIFT, 225 },
		{ 173, YYAT_SHIFT, 171 },
		{ 182, YYAT_SHIFT, 4 },
		{ 264, YYAT_ERROR, 0 },
		{ 264, YYAT_SHIFT, 320 },
		{ 264, YYAT_ERROR, 0 },
		{ 179, YYAT_SHIFT, 273 },
		{ 275, YYAT_SHIFT, 273 },
		{ 179, YYAT_SHIFT, 2 },
		{ 367, YYAT_SHIFT, 91 },
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
		{ 362, YYAT_SHIFT, 366 },
		{ 198, YYAT_SHIFT, 240 },
		{ 365, YYAT_SHIFT, 150 },
		{ 75, YYAT_SHIFT, 165 },
		{ 300, YYAT_SHIFT, 240 },
		{ 66, YYAT_SHIFT, 155 },
		{ 263, YYAT_SHIFT, 264 },
		{ 27, YYAT_SHIFT, 2 },
		{ 169, YYAT_SHIFT, 264 },
		{ 49, YYAT_SHIFT, 57 },
		{ 31, YYAT_SHIFT, 57 },
		{ 355, YYAT_ERROR, 0 },
		{ 167, YYAT_SHIFT, 165 },
		{ 358, YYAT_SHIFT, 362 },
		{ 36, YYAT_SHIFT, 1 },
		{ 36, YYAT_ERROR, 0 },
		{ 198, YYAT_SHIFT, 286 },
		{ 356, YYAT_SHIFT, 361 },
		{ 311, YYAT_SHIFT, 240 },
		{ 273, YYAT_ERROR, 0 },
		{ 66, YYAT_SHIFT, 159 },
		{ 122, YYAT_SHIFT, 226 },
		{ 360, YYAT_SHIFT, 364 },
		{ 349, YYAT_REDUCE, 59 },
		{ 273, YYAT_ERROR, 0 },
		{ 360, YYAT_SHIFT, 240 },
		{ 273, YYAT_SHIFT, 273 },
		{ 273, YYAT_SHIFT, 258 },
		{ 273, YYAT_SHIFT, 2 },
		{ 273, YYAT_ERROR, 0 },
		{ 264, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 311, YYAT_SHIFT, 334 },
		{ 179, YYAT_SHIFT, 165 },
		{ 275, YYAT_SHIFT, 165 },
		{ 290, YYAT_SHIFT, 208 },
		{ 126, YYAT_SHIFT, 52 },
		{ 289, YYAT_SHIFT, 208 },
		{ 126, YYAT_SHIFT, 230 },
		{ 126, YYAT_SHIFT, 93 },
		{ 290, YYAT_SHIFT, 209 },
		{ 246, YYAT_SHIFT, 313 },
		{ 289, YYAT_SHIFT, 209 },
		{ 72, YYAT_SHIFT, 161 },
		{ 246, YYAT_SHIFT, 314 },
		{ 290, YYAT_SHIFT, 210 },
		{ 72, YYAT_SHIFT, 162 },
		{ 289, YYAT_SHIFT, 210 },
		{ 345, YYAT_SHIFT, 354 },
		{ 367, YYAT_SHIFT, 52 },
		{ 365, YYAT_ERROR, 0 },
		{ 365, YYAT_ERROR, 0 },
		{ 367, YYAT_SHIFT, 93 },
		{ 300, YYAT_SHIFT, 332 },
		{ 365, YYAT_ERROR, 0 },
		{ 65, YYAT_SHIFT, 154 },
		{ 316, YYAT_SHIFT, 338 },
		{ 263, YYAT_SHIFT, 265 },
		{ 173, YYAT_SHIFT, 268 },
		{ 169, YYAT_SHIFT, 265 },
		{ 49, YYAT_SHIFT, 58 },
		{ 31, YYAT_SHIFT, 58 },
		{ 178, YYAT_SHIFT, 2 },
		{ 118, YYAT_SHIFT, 208 },
		{ 288, YYAT_SHIFT, 202 },
		{ 36, YYAT_ERROR, 0 },
		{ 288, YYAT_SHIFT, 203 },
		{ 287, YYAT_SHIFT, 202 },
		{ 118, YYAT_SHIFT, 209 },
		{ 287, YYAT_SHIFT, 203 },
		{ 116, YYAT_SHIFT, 202 },
		{ 344, YYAT_SHIFT, 353 },
		{ 116, YYAT_SHIFT, 203 },
		{ 118, YYAT_SHIFT, 210 },
		{ 306, YYAT_SHIFT, 234 },
		{ 306, YYAT_SHIFT, 235 },
		{ 337, YYAT_SHIFT, 347 },
		{ 273, YYAT_SHIFT, 165 },
		{ 34, YYAT_SHIFT, 4 },
		{ 52, YYAT_SHIFT, 91 },
		{ 335, YYAT_SHIFT, 237 },
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
		{ 333, YYAT_SHIFT, 238 },
		{ 24, YYAT_SHIFT, 47 },
		{ 294, YYAT_SHIFT, 200 },
		{ 294, YYAT_SHIFT, 201 },
		{ 293, YYAT_SHIFT, 200 },
		{ 293, YYAT_SHIFT, 201 },
		{ 331, YYAT_SHIFT, 91 },
		{ 23, YYAT_SHIFT, 45 },
		{ 292, YYAT_SHIFT, 200 },
		{ 292, YYAT_SHIFT, 201 },
		{ 291, YYAT_SHIFT, 200 },
		{ 291, YYAT_SHIFT, 201 },
		{ 273, YYAT_ERROR, 0 },
		{ 131, YYAT_SHIFT, 234 },
		{ 131, YYAT_SHIFT, 235 },
		{ 25, YYAT_SHIFT, 4 },
		{ 329, YYAT_SHIFT, 343 },
		{ 65, YYAT_SHIFT, 52 },
		{ 25, YYAT_SHIFT, 5 },
		{ 25, YYAT_SHIFT, 6 },
		{ 25, YYAT_SHIFT, 7 },
		{ 25, YYAT_SHIFT, 8 },
		{ 25, YYAT_SHIFT, 9 },
		{ 25, YYAT_SHIFT, 10 },
		{ 25, YYAT_SHIFT, 11 },
		{ 25, YYAT_SHIFT, 12 },
		{ 25, YYAT_SHIFT, 13 },
		{ 25, YYAT_SHIFT, 14 },
		{ 25, YYAT_SHIFT, 15 },
		{ 25, YYAT_SHIFT, 16 },
		{ 25, YYAT_SHIFT, 17 },
		{ 25, YYAT_SHIFT, 18 },
		{ 25, YYAT_SHIFT, 19 },
		{ 25, YYAT_SHIFT, 20 },
		{ 25, YYAT_SHIFT, 21 },
		{ 25, YYAT_SHIFT, 22 },
		{ 25, YYAT_SHIFT, 23 },
		{ 305, YYAT_SHIFT, 204 },
		{ 323, YYAT_SHIFT, 340 },
		{ 305, YYAT_SHIFT, 205 },
		{ 304, YYAT_SHIFT, 204 },
		{ 321, YYAT_SHIFT, 339 },
		{ 304, YYAT_SHIFT, 205 },
		{ 52, YYAT_SHIFT, 52 },
		{ 117, YYAT_SHIFT, 204 },
		{ 52, YYAT_SHIFT, 92 },
		{ 117, YYAT_SHIFT, 205 },
		{ 115, YYAT_SHIFT, 200 },
		{ 115, YYAT_SHIFT, 201 },
		{ 309, YYAT_SHIFT, 236 },
		{ 308, YYAT_SHIFT, 239 },
		{ 283, YYAT_SHIFT, 330 },
		{ 281, YYAT_SHIFT, 328 },
		{ 280, YYAT_SHIFT, 327 },
		{ 278, YYAT_SHIFT, 325 },
		{ 265, YYAT_SHIFT, 322 },
		{ 262, YYAT_SHIFT, 319 },
		{ 260, YYAT_SHIFT, 318 },
		{ 137, YYAT_SHIFT, 243 },
		{ 119, YYAT_SHIFT, 212 },
		{ 119, YYAT_SHIFT, 213 },
		{ 119, YYAT_SHIFT, 214 },
		{ 119, YYAT_SHIFT, 215 },
		{ 119, YYAT_SHIFT, 216 },
		{ 119, YYAT_SHIFT, 217 },
		{ 119, YYAT_SHIFT, 218 },
		{ 119, YYAT_SHIFT, 219 },
		{ 119, YYAT_SHIFT, 220 },
		{ 119, YYAT_SHIFT, 221 },
		{ 75, YYAT_SHIFT, 3 },
		{ 126, YYAT_SHIFT, 94 },
		{ 126, YYAT_SHIFT, 95 },
		{ 126, YYAT_SHIFT, 96 },
		{ 126, YYAT_SHIFT, 97 },
		{ 259, YYAT_SHIFT, 317 },
		{ 126, YYAT_SHIFT, 98 },
		{ 126, YYAT_SHIFT, 99 },
		{ 155, YYAT_SHIFT, 3 },
		{ 167, YYAT_SHIFT, 3 },
		{ 250, YYAT_SHIFT, 250 },
		{ 164, YYAT_SHIFT, 3 },
		{ 38, YYAT_SHIFT, 70 },
		{ 231, YYAT_SHIFT, 302 },
		{ 367, YYAT_SHIFT, 94 },
		{ 367, YYAT_SHIFT, 95 },
		{ 367, YYAT_SHIFT, 96 },
		{ 367, YYAT_SHIFT, 97 },
		{ 227, YYAT_SHIFT, 301 },
		{ 367, YYAT_SHIFT, 98 },
		{ 367, YYAT_SHIFT, 99 },
		{ 225, YYAT_SHIFT, 299 },
		{ 122, YYAT_SHIFT, 227 },
		{ 122, YYAT_SHIFT, 228 },
		{ 122, YYAT_SHIFT, 229 },
		{ 194, YYAT_SHIFT, 285 },
		{ 355, YYAT_ERROR, 0 },
		{ 126, YYAT_SHIFT, 100 },
		{ 126, YYAT_SHIFT, 101 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 41, YYAT_SHIFT, 18 },
		{ 41, YYAT_SHIFT, 19 },
		{ 191, YYAT_SHIFT, 282 },
		{ 187, YYAT_SHIFT, 279 },
		{ 367, YYAT_SHIFT, 100 },
		{ 367, YYAT_SHIFT, 101 },
		{ 180, YYAT_SHIFT, 276 },
		{ 177, YYAT_SHIFT, 271 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 175, YYAT_SHIFT, 269 },
		{ 171, YYAT_SHIFT, 79 },
		{ 165, YYAT_SHIFT, 261 },
		{ 126, YYAT_SHIFT, 102 },
		{ 126, YYAT_SHIFT, 103 },
		{ 126, YYAT_SHIFT, 104 },
		{ 162, YYAT_SHIFT, 257 },
		{ 126, YYAT_SHIFT, 105 },
		{ 126, YYAT_SHIFT, 106 },
		{ 126, YYAT_SHIFT, 107 },
		{ 126, YYAT_SHIFT, 108 },
		{ 126, YYAT_SHIFT, 109 },
		{ 126, YYAT_SHIFT, 110 },
		{ 126, YYAT_SHIFT, 111 },
		{ 126, YYAT_SHIFT, 112 },
		{ 160, YYAT_SHIFT, 255 },
		{ 367, YYAT_SHIFT, 102 },
		{ 367, YYAT_SHIFT, 103 },
		{ 367, YYAT_SHIFT, 104 },
		{ 158, YYAT_SHIFT, 52 },
		{ 367, YYAT_SHIFT, 105 },
		{ 367, YYAT_SHIFT, 106 },
		{ 367, YYAT_SHIFT, 107 },
		{ 367, YYAT_SHIFT, 108 },
		{ 367, YYAT_SHIFT, 109 },
		{ 367, YYAT_SHIFT, 110 },
		{ 367, YYAT_SHIFT, 111 },
		{ 367, YYAT_SHIFT, 112 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 27, YYAT_SHIFT, 4 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
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
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_SHIFT, 5 },
		{ 273, YYAT_SHIFT, 6 },
		{ 273, YYAT_SHIFT, 7 },
		{ 273, YYAT_SHIFT, 8 },
		{ 273, YYAT_SHIFT, 9 },
		{ 65, YYAT_SHIFT, 4 },
		{ 52, YYAT_SHIFT, 94 },
		{ 152, YYAT_SHIFT, 249 },
		{ 65, YYAT_SHIFT, 5 },
		{ 65, YYAT_SHIFT, 6 },
		{ 65, YYAT_SHIFT, 7 },
		{ 65, YYAT_SHIFT, 8 },
		{ 65, YYAT_SHIFT, 9 },
		{ 65, YYAT_SHIFT, 10 },
		{ 65, YYAT_SHIFT, 11 },
		{ 65, YYAT_SHIFT, 12 },
		{ 65, YYAT_SHIFT, 13 },
		{ 65, YYAT_SHIFT, 14 },
		{ 65, YYAT_SHIFT, 15 },
		{ 65, YYAT_SHIFT, 16 },
		{ 65, YYAT_SHIFT, 17 },
		{ 65, YYAT_SHIFT, 18 },
		{ 65, YYAT_SHIFT, 19 },
		{ 65, YYAT_SHIFT, 20 },
		{ 65, YYAT_SHIFT, 21 },
		{ 65, YYAT_SHIFT, 22 },
		{ 65, YYAT_SHIFT, 23 },
		{ 148, YYAT_ERROR, 0 },
		{ 146, YYAT_SHIFT, 245 },
		{ 136, YYAT_SHIFT, 241 },
		{ 135, YYAT_SHIFT, 239 },
		{ 178, YYAT_SHIFT, 4 },
		{ 134, YYAT_SHIFT, 238 },
		{ 133, YYAT_SHIFT, 237 },
		{ 52, YYAT_SHIFT, 5 },
		{ 52, YYAT_SHIFT, 6 },
		{ 52, YYAT_SHIFT, 7 },
		{ 52, YYAT_SHIFT, 8 },
		{ 52, YYAT_SHIFT, 9 },
		{ 178, YYAT_SHIFT, 10 },
		{ 178, YYAT_SHIFT, 11 },
		{ 178, YYAT_SHIFT, 12 },
		{ 178, YYAT_SHIFT, 13 },
		{ 178, YYAT_SHIFT, 14 },
		{ 178, YYAT_SHIFT, 15 },
		{ 178, YYAT_SHIFT, 16 },
		{ 178, YYAT_SHIFT, 17 },
		{ 178, YYAT_SHIFT, 18 },
		{ 178, YYAT_SHIFT, 19 },
		{ 178, YYAT_SHIFT, 20 },
		{ 178, YYAT_SHIFT, 21 },
		{ 178, YYAT_SHIFT, 22 },
		{ 178, YYAT_SHIFT, 23 },
		{ 132, YYAT_SHIFT, 236 },
		{ 52, YYAT_SHIFT, 102 },
		{ 52, YYAT_SHIFT, 103 },
		{ 52, YYAT_SHIFT, 104 },
		{ 127, YYAT_SHIFT, 232 },
		{ 52, YYAT_SHIFT, 105 },
		{ 52, YYAT_SHIFT, 106 },
		{ 52, YYAT_SHIFT, 107 },
		{ 52, YYAT_SHIFT, 108 },
		{ 52, YYAT_SHIFT, 109 },
		{ 52, YYAT_SHIFT, 110 },
		{ 52, YYAT_SHIFT, 111 },
		{ 52, YYAT_SHIFT, 112 },
		{ 112, YYAT_SHIFT, 197 },
		{ 111, YYAT_SHIFT, 196 },
		{ 110, YYAT_SHIFT, 195 },
		{ 109, YYAT_SHIFT, 194 },
		{ 108, YYAT_SHIFT, 193 },
		{ 105, YYAT_SHIFT, 190 },
		{ 305, YYAT_SHIFT, 206 },
		{ 305, YYAT_SHIFT, 207 },
		{ 176, YYAT_SHIFT, 4 },
		{ 304, YYAT_SHIFT, 206 },
		{ 304, YYAT_SHIFT, 207 },
		{ 104, YYAT_SHIFT, 189 },
		{ 103, YYAT_SHIFT, 188 },
		{ 117, YYAT_SHIFT, 206 },
		{ 117, YYAT_SHIFT, 207 },
		{ 99, YYAT_SHIFT, 184 },
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
		{ 97, YYAT_SHIFT, 182 },
		{ 94, YYAT_SHIFT, 181 },
		{ 83, YYAT_SHIFT, 174 },
		{ 80, YYAT_SHIFT, 172 },
		{ 79, YYAT_SHIFT, 170 },
		{ 73, YYAT_SHIFT, 163 },
		{ 71, YYAT_SHIFT, 160 },
		{ 62, YYAT_SHIFT, 156 },
		{ 60, YYAT_SHIFT, 154 },
		{ 58, YYAT_SHIFT, 149 },
		{ 55, YYAT_SHIFT, 64 },
		{ 54, YYAT_SHIFT, 52 },
		{ 47, YYAT_SHIFT, 84 },
		{ 45, YYAT_SHIFT, 82 },
		{ 40, YYAT_SHIFT, 76 },
		{ 32, YYAT_SHIFT, 59 },
		{ 29, YYAT_SHIFT, 52 },
		{ 26, YYAT_ERROR, 0 },
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 439, 1, YYAT_DEFAULT, 36 },
		{ 0, 0, YYAT_DEFAULT, 155 },
		{ -31, 1, YYAT_REDUCE, 150 },
		{ 0, 0, YYAT_REDUCE, 143 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_REDUCE, 117 },
		{ -96, 1, YYAT_ERROR, 0 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ -113, 1, YYAT_REDUCE, 86 },
		{ 396, 1, YYAT_DEFAULT, 155 },
		{ 19, 1, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 314, 1, YYAT_DEFAULT, 148 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 24, 1, YYAT_REDUCE, 141 },
		{ 377, 1, YYAT_DEFAULT, 155 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ -150, 1, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 226 },
		{ 28, 1, YYAT_DEFAULT, 164 },
		{ 0, 0, YYAT_REDUCE, 225 },
		{ -22, 1, YYAT_DEFAULT, 264 },
		{ 0, 0, YYAT_REDUCE, 223 },
		{ 394, 1, YYAT_ERROR, 0 },
		{ -39, 1, YYAT_REDUCE, 151 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 311, 1, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_DEFAULT, 148 },
		{ 310, 1, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 23, 1, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 74, 1, YYAT_DEFAULT, 182 },
		{ 0, 0, YYAT_REDUCE, 230 },
		{ 309, 1, YYAT_REDUCE, 58 },
		{ 372, 1, YYAT_DEFAULT, 155 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 337, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 368, 1, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 369, 1, YYAT_DEFAULT, 66 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 48, 1, YYAT_REDUCE, 90 },
		{ 15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 383, 1, YYAT_REDUCE, 156 },
		{ 56, 1, YYAT_ERROR, 0 },
		{ 385, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 158 },
		{ -34, 1, YYAT_REDUCE, 162 },
		{ 0, 0, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 364, 1, YYAT_REDUCE, 136 },
		{ 299, 1, YYAT_DEFAULT, 173 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 298, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 148 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_DEFAULT, 182 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 364, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 381, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 99 },
		{ 366, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 345, 1, YYAT_ERROR, 0 },
		{ 362, 1, YYAT_ERROR, 0 },
		{ 356, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 355, 1, YYAT_ERROR, 0 },
		{ 137, 1, YYAT_ERROR, 0 },
		{ 334, 1, YYAT_ERROR, 0 },
		{ 333, 1, YYAT_ERROR, 0 },
		{ 332, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ -63, 1, YYAT_REDUCE, 42 },
		{ 81, 1, YYAT_REDUCE, 39 },
		{ 138, 1, YYAT_REDUCE, 47 },
		{ 80, 1, YYAT_REDUCE, 36 },
		{ -59, 1, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -16, 1, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ -33, 1, YYAT_REDUCE, 58 },
		{ 257, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ -101, 1, YYAT_REDUCE, 50 },
		{ 340, 1, YYAT_REDUCE, 52 },
		{ 88, 1, YYAT_REDUCE, 60 },
		{ 233, 1, YYAT_REDUCE, 56 },
		{ 261, 1, YYAT_REDUCE, 54 },
		{ 295, 1, YYAT_DEFAULT, 198 },
		{ -59, 1, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 312, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 229 },
		{ 311, 1, YYAT_DEFAULT, 264 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 239, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_DEFAULT, 250 },
		{ -26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ 0, 0, YYAT_REDUCE, 228 },
		{ 165, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ -20, 1, YYAT_DEFAULT, 148 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 18, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ -23, 1, YYAT_DEFAULT, 273 },
		{ 178, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 161 },
		{ -25, 1, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ 22, 1, YYAT_REDUCE, 168 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ -13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 144, 1, YYAT_REDUCE, 58 },
		{ 117, 1, YYAT_REDUCE, 125 },
		{ 225, 1, YYAT_ERROR, 0 },
		{ 74, 1, YYAT_REDUCE, 123 },
		{ -4, 1, YYAT_REDUCE, 165 },
		{ 224, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ -250, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 204, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 221, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 331 },
		{ 189, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 219 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ 11, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
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
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -16, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 111, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 54, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 110, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 227 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 187, 1, YYAT_ERROR, 0 },
		{ 170, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 117, 1, YYAT_ERROR, 0 },
		{ 20, 1, YYAT_REDUCE, 169 },
		{ -7, 1, YYAT_DEFAULT, 273 },
		{ 116, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 132 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 40, 1, YYAT_DEFAULT, 182 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ -3, 1, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 167, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 166, 1, YYAT_DEFAULT, 360 },
		{ 165, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -105, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 78, 1, YYAT_REDUCE, 40 },
		{ 75, 1, YYAT_REDUCE, 41 },
		{ 54, 1, YYAT_REDUCE, 37 },
		{ 52, 1, YYAT_REDUCE, 38 },
		{ -100, 1, YYAT_REDUCE, 43 },
		{ -102, 1, YYAT_REDUCE, 44 },
		{ -106, 1, YYAT_REDUCE, 45 },
		{ -108, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 14, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 134, 1, YYAT_REDUCE, 48 },
		{ 131, 1, YYAT_REDUCE, 49 },
		{ -140, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 110, 1, YYAT_REDUCE, 55 },
		{ 165, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 28, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ -15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 154, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 99, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 129, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 101, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 30, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -136, 1, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 5, 1, YYAT_DEFAULT, 250 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 0, 0, YYAT_DEFAULT, 365 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 85, 1, YYAT_ERROR, 0 },
		{ 61, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ -231, 1, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -58, 1, YYAT_DEFAULT, 365 },
		{ -237, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 26, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 35, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -5, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 216 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -201, 1, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ -20, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 217 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 257;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 367, 121 },
		{ 367, 146 },
		{ 367, 122 },
		{ 331, 136 },
		{ 367, 119 },
		{ 367, 120 },
		{ 367, 114 },
		{ 367, 118 },
		{ 367, 116 },
		{ 367, 115 },
		{ 367, 117 },
		{ 367, 131 },
		{ 367, 132 },
		{ 367, 135 },
		{ 367, 134 },
		{ 367, 133 },
		{ 84, 56 },
		{ 337, 252 },
		{ 367, 137 },
		{ 367, 138 },
		{ 367, 130 },
		{ 314, 336 },
		{ 367, 136 },
		{ 314, -1 },
		{ 34, 67 },
		{ 179, 275 },
		{ 176, 270 },
		{ 182, 178 },
		{ 182, 32 },
		{ 364, 367 },
		{ 182, 28 },
		{ 182, 24 },
		{ 179, 274 },
		{ 179, 169 },
		{ 182, 179 },
		{ 1, -1 },
		{ 176, -1 },
		{ 182, 30 },
		{ 52, 56 },
		{ 52, 55 },
		{ 182, 176 },
		{ 27, 51 },
		{ 52, 34 },
		{ 52, 27 },
		{ 52, 32 },
		{ 331, 345 },
		{ 52, 28 },
		{ 52, 24 },
		{ 126, 148 },
		{ 34, -1 },
		{ 182, 278 },
		{ 1, 40 },
		{ 337, 348 },
		{ 52, 30 },
		{ 84, 175 },
		{ 361, 365 },
		{ 52, 25 },
		{ 367, 143 },
		{ 367, 370 },
		{ 367, 113 },
		{ 367, 124 },
		{ 367, 125 },
		{ 27, 50 },
		{ 359, 363 },
		{ 367, 128 },
		{ 367, 144 },
		{ 367, 140 },
		{ 367, 141 },
		{ 367, 142 },
		{ 367, 145 },
		{ 367, 129 },
		{ 367, 139 },
		{ 52, 123 },
		{ 355, 360 },
		{ 146, 246 },
		{ 273, 75 },
		{ 52, 126 },
		{ 52, 127 },
		{ 273, 34 },
		{ 273, 27 },
		{ 273, 32 },
		{ 334, 151 },
		{ 273, 28 },
		{ 273, 24 },
		{ 312, 335 },
		{ 36, 35 },
		{ 36, 33 },
		{ 312, -1 },
		{ 312, -1 },
		{ 273, 30 },
		{ 126, 123 },
		{ 146, 247 },
		{ 273, 25 },
		{ 307, 333 },
		{ 307, -1 },
		{ 126, 231 },
		{ 334, 346 },
		{ 334, -1 },
		{ 273, 260 },
		{ 273, 71 },
		{ 273, 74 },
		{ 250, 315 },
		{ 250, 316 },
		{ 273, 259 },
		{ 36, 29 },
		{ 36, 38 },
		{ 36, 31 },
		{ 36, 26 },
		{ 355, -1 },
		{ 2, 42 },
		{ 239, 309 },
		{ 239, -1 },
		{ 355, -1 },
		{ 2, 43 },
		{ 2, 41 },
		{ 355, -1 },
		{ 178, -1 },
		{ 355, -1 },
		{ 355, -1 },
		{ 178, -1 },
		{ 178, 178 },
		{ 355, -1 },
		{ 355, -1 },
		{ 38, 73 },
		{ 354, 359 },
		{ 155, 253 },
		{ 38, 72 },
		{ 178, 272 },
		{ 365, 350 },
		{ 365, -1 },
		{ 365, -1 },
		{ 365, -1 },
		{ 353, 358 },
		{ 178, 176 },
		{ 36, 68 },
		{ 36, 37 },
		{ 365, -1 },
		{ 365, 368 },
		{ 365, 369 },
		{ 365, -1 },
		{ 365, -1 },
		{ 155, 60 },
		{ 75, 168 },
		{ 155, 31 },
		{ 155, 26 },
		{ 75, 167 },
		{ 32, 62 },
		{ 264, -1 },
		{ 99, 186 },
		{ 264, 321 },
		{ 99, -1 },
		{ 32, 63 },
		{ 75, 166 },
		{ 75, 169 },
		{ 264, -1 },
		{ 264, -1 },
		{ 164, 40 },
		{ 164, 38 },
		{ 164, 31 },
		{ 164, 167 },
		{ 342, 351 },
		{ 342, 349 },
		{ 342, 141 },
		{ 271, 324 },
		{ 271, -1 },
		{ 271, -1 },
		{ 160, -1 },
		{ 160, -1 },
		{ 160, 256 },
		{ 265, 153 },
		{ 41, 77 },
		{ 238, 308 },
		{ 238, -1 },
		{ 265, 323 },
		{ 41, 78 },
		{ 236, 306 },
		{ 236, -1 },
		{ 235, 305 },
		{ 235, -1 },
		{ 207, 294 },
		{ 207, -1 },
		{ 203, 114 },
		{ 203, 290 },
		{ 201, 288 },
		{ 201, -1 },
		{ 167, 38 },
		{ 167, 49 },
		{ 148, 248 },
		{ 148, 55 },
		{ 82, 173 },
		{ 82, 81 },
		{ 65, 157 },
		{ 65, 158 },
		{ 55, 66 },
		{ 55, 61 },
		{ 29, 53 },
		{ 29, 54 },
		{ 0, 36 },
		{ 0, 39 },
		{ 352, 357 },
		{ 349, 356 },
		{ 345, 355 },
		{ 343, 352 },
		{ 330, 344 },
		{ 327, 342 },
		{ 326, 341 },
		{ 284, 331 },
		{ 282, 329 },
		{ 279, 326 },
		{ 275, 263 },
		{ 243, 312 },
		{ 242, 311 },
		{ 240, 310 },
		{ 237, 307 },
		{ 234, 304 },
		{ 233, 303 },
		{ 231, 233 },
		{ 226, 300 },
		{ 222, 298 },
		{ 210, 297 },
		{ 209, 296 },
		{ 208, 295 },
		{ 206, 293 },
		{ 205, 292 },
		{ 204, 291 },
		{ 202, 289 },
		{ 200, 287 },
		{ 193, 284 },
		{ 192, 283 },
		{ 190, 281 },
		{ 189, 280 },
		{ 184, 180 },
		{ 181, 277 },
		{ 175, 148 },
		{ 171, 267 },
		{ 170, 266 },
		{ 165, 262 },
		{ 158, 254 },
		{ 154, 251 },
		{ 145, 244 },
		{ 120, 223 },
		{ 119, 222 },
		{ 113, 199 },
		{ 112, 198 },
		{ 107, 192 },
		{ 106, 191 },
		{ 102, 187 },
		{ 98, 185 },
		{ 97, 183 },
		{ 87, 177 },
		{ 58, 152 },
		{ 54, 147 },
		{ 46, 83 },
		{ 44, 80 },
		{ 33, 65 },
		{ 26, -1 },
		{ 25, 48 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 124, 36 },
		{ 7, 155 },
		{ 66, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 230, 34 },
		{ 200, 167 },
		{ 15, 34 },
		{ 0, -1 },
		{ 133, 84 },
		{ 0, -1 },
		{ 0, -1 },
		{ 119, 55 },
		{ 210, 55 },
		{ -2, 160 },
		{ 0, -1 },
		{ 60, 148 },
		{ 0, -1 },
		{ 74, 264 },
		{ 0, -1 },
		{ 0, -1 },
		{ 127, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 212, 82 },
		{ 0, -1 },
		{ 189, 84 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 13, 367 },
		{ 0, -1 },
		{ 189, 175 },
		{ 166, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 226, 265 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 129, 84 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 98, 1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 148, -1 },
		{ 0, 175 },
		{ -9, 148 },
		{ 0, -1 },
		{ 0, -1 },
		{ 196, 182 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 243, 99 },
		{ 242, 99 },
		{ 143, 271 },
		{ 0, -1 },
		{ 0, -1 },
		{ 222, 265 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 228, -1 },
		{ 227, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 220, 355 },
		{ 183, 367 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 219, -1 },
		{ 233, 271 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 31, 367 },
		{ 0, 231 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 180, 367 },
		{ 70, 314 },
		{ 0, -1 },
		{ 162, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 182, 337 },
		{ 97, 26 },
		{ 0, -1 },
		{ 0, -1 },
		{ 175, 175 },
		{ 0, -1 },
		{ 117, 264 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 112, 273 },
		{ 212, 265 },
		{ 0, -1 },
		{ 140, 275 },
		{ 0, -1 },
		{ 0, -1 },
		{ 211, 265 },
		{ 192, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 216, -1 },
		{ -11, 178 },
		{ 0, -1 },
		{ 90, 27 },
		{ -22, -1 },
		{ 0, -1 },
		{ 173, 367 },
		{ -3, 184 },
		{ 0, -1 },
		{ 208, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 207, 355 },
		{ 206, 355 },
		{ 0, -1 },
		{ 169, 367 },
		{ 162, 331 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 217, 201 },
		{ 174, 207 },
		{ 217, 203 },
		{ 174, 271 },
		{ 214, 207 },
		{ 213, 207 },
		{ 212, 207 },
		{ 169, 235 },
		{ 214, 271 },
		{ 213, 271 },
		{ 212, 271 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 197, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 194, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 199, -1 },
		{ 0, -1 },
		{ 156, 367 },
		{ 203, 235 },
		{ 166, 236 },
		{ 163, 239 },
		{ 196, -1 },
		{ 157, 307 },
		{ 97, 238 },
		{ 191, 314 },
		{ 0, -1 },
		{ 188, 355 },
		{ 193, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, 337 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 100, 273 },
		{ 149, 334 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 156, 201 },
		{ 0, -1 },
		{ 49, 179 },
		{ 0, -1 },
		{ 154, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 191, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 184, 355 },
		{ 0, -1 },
		{ 189, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 78, 312 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 68, 334 },
		{ 0, -1 },
		{ 0, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 146, 367 },
		{ 187, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 186, -1 },
		{ -20, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 76, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 314 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 94, 365 },
		{ 185, -1 },
		{ 0, -1 },
		{ 184, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 182, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 140, 367 },
		{ 109, 355 },
		{ 107, -1 },
		{ 50, 365 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 4, 367 },
		{ 0, -1 },
		{ 38, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 12, -1 },
		{ 70, 367 },
		{ 0, -1 },
		{ -1, -1 },
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
#line 2938 ".\\myparser.y"


	/////////////////////////////////////////////////////////////////////////////
	// programs section

	int main(void)
	{
		s.push_back(new varmap());
	//print-function
		type3->right = &voidnode;
		type3->left=&intnode;
		s[s.size()-1]->vartable["print"] = type3;
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
