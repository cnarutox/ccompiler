/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 83 of your 30 day trial period.
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
* Date: 12/31/18
* Time: 20:27:13
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
				if(temp2[i] == "double" && isComputable(temp1[i])||temp1[i] == "double" && isComputable(temp2[i]))
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
			gen(newlabel(), "DEC", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr);
			gen(newlabel(), "=#", yyattribute(1 - 1).ntnode->dvalue, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr);
		
#line 325 "myparser.cpp"
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
#line 212 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("123 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 345 "myparser.cpp"
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
#line 220 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("130 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";	
			s.pop_back();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = yyattribute(2 - 3).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist = yyattribute(2 - 3).ntnode->falselist;  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 367 "myparser.cpp"
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
#line 230 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("125 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();			
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 387 "myparser.cpp"
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
#line 238 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 407 "myparser.cpp"
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
#line 250 ".\\myparser.y"

			fun_name = var_name;
		
#line 422 "myparser.cpp"
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
#line 256 ".\\myparser.y"

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
		
#line 448 "myparser.cpp"
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
#line 270 ".\\myparser.y"
	
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
		
#line 472 "myparser.cpp"
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
#line 282 ".\\myparser.y"

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
		
#line 499 "myparser.cpp"
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
#line 297 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("168 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			s.pop_back();  
			vector<string> v_argument_list_temp; //??no value
			typenode* type_exp = (search(fun_name, s.size()-1));
			traverse_list(type_exp->left, v_argument_list_temp);//?
			//for(int x=0;x<v_argument_list_temp.size();x++){
				//cout<<v_argument_list_temp[x]<<" ";
			//}
			//for(int x=0;x<v_argument_list.size();x++){
				//cout<<v_argument_list[x]<<" ";
			//}
			if(type_exp->name == "fun"){
				int i=0;
				if (v_argument_list_temp.size()!=v_argument_list.size()){
					// cout<<"Argument_list matching failed."<<endl;
				}
				else{
					// while(i<v_argument_list_temp.size()&&v_argument_list[i]!=v_argument_list_temp[i]){
					// 	i++;
					// 	cout<<v_argument_list[i]<<" "<<v_argument_list_temp[i]<<endl;
						// }
					for(i=0; i<v_argument_list_temp.size();i++){
						if(v_argument_list[i]!=v_argument_list_temp[i])
						{
							//cout<<"Argument_list matching failed."<<endl;
							break;
						}			
					}
				}
				if(i==v_argument_list_temp.size()){
					//cout<<"i"<<i<<endl;//i=0;
					cout<<"-----------------------"<<endl;
					cout<<"|Argument_list matched!|"<<endl;
					cout<<"-----------------------"<<endl;
				}
				else{
					// cout<<"Argument_list matching failed."<<endl;
				}
			}
			// cout<<"clear v_argument_list"<<endl;
			v_argument_list.clear();
		
#line 557 "myparser.cpp"
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
#line 343 ".\\myparser.y"

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
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = yyattribute(1 - 3).ntnode->type.addr + temp_addr;
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

		
		
#line 610 "myparser.cpp"
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
#line 384 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("187 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 632 "myparser.cpp"
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
#line 394 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("196 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
				cout<<"No additive calculation can be made for uncalculable types."<<endl;
		
#line 656 "myparser.cpp"
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
#line 406 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
				cout<<"Can't subtract from uncalculable types."<<endl;
		
#line 680 "myparser.cpp"
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
#line 421 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("215 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			v_argument_list.push_back(yyattribute(1 - 1).ntnode->type.name);

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;						
		
#line 703 "myparser.cpp"
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
#line 432 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("222 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			// v_argument_list.push_back($1->type.name);
			v_argument_list.push_back(yyattribute(3 - 3).ntnode->type.name);
		
#line 728 "myparser.cpp"
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
#line 448 ".\\myparser.y"

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
		
#line 754 "myparser.cpp"
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
#line 462 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("241 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
				cout<<"No additive calculation can be made for uncalculable types."<<endl;
		
#line 778 "myparser.cpp"
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
#line 474 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("249 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
				cout<<"Can't subtract from uncalculable types ."<<endl;
		
#line 802 "myparser.cpp"
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
#line 486 ".\\myparser.y"

			//cast_exp:单目表达式/强制类型转换
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("257 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			if(yyattribute(1 - 2).ntnode->name == "!") {
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = yyattribute(2 - 2).ntnode->falselist;
			    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist = yyattribute(2 - 2).ntnode->truelist;
			}
			if(yyattribute(1 - 2).ntnode->name != "*" && yyattribute(1 - 2).ntnode->name != "&"){
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = yyattribute(2 - 2).ntnode->type;
			}
			else{
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type.addr = offset;
				offset += (*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type.width;
				gen(newlabel(), "DEC", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr);
				if (yyattribute(1 - 2).ntnode->name == "&") {
					gen(newlabel(), "=&", yyattribute(2 - 2).ntnode->type.addr, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type.addr);
				}
				if (yyattribute(1 - 2).ntnode->name == "*") {
					gen(newlabel(), "=*", yyattribute(2 - 2).ntnode->type.addr, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type.addr);
				}
			}
		
#line 839 "myparser.cpp"
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
#line 511 ".\\myparser.y"

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
		
#line 866 "myparser.cpp"
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
#line 526 ".\\myparser.y"

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
		
#line 893 "myparser.cpp"
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
#line 544 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("286 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&";
		
#line 910 "myparser.cpp"
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
#line 549 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*";
		
#line 927 "myparser.cpp"
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
#line 554 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("301 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+";
		
#line 944 "myparser.cpp"
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
#line 559 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("308 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-";
		
#line 961 "myparser.cpp"
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
#line 564 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("315 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="~";
		
#line 978 "myparser.cpp"
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
#line 569 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("322 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="!";
		
#line 995 "myparser.cpp"
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
#line 577 ".\\myparser.y"

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
		
#line 1021 "myparser.cpp"
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
#line 591 ".\\myparser.y"

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
		
#line 1045 "myparser.cpp"
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
#line 606 ".\\myparser.y"

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
		
#line 1071 "myparser.cpp"
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
#line 620 ".\\myparser.y"

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
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			gen(newlabel(), "DEC", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width);
			gen(newlabel(), "*", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
												
		
#line 1102 "myparser.cpp"
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
#line 639 ".\\myparser.y"

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
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			gen(newlabel(), "DEC", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width);
			gen(newlabel(), "/", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
		
#line 1132 "myparser.cpp"
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
#line 657 ".\\myparser.y"

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
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			gen(newlabel(), "DEC", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr);
			gen(newlabel(), "%", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
		
#line 1162 "myparser.cpp"
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
#line 678 ".\\myparser.y"

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
		
#line 1188 "myparser.cpp"
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
#line 692 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("396 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Operator type r,  $4->type.addrmismatch."<<endl;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			gen(newlabel(), "DEC", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr);	
			gen(newlabel(), "+", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
		
#line 1213 "myparser.cpp"
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
#line 705 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("405 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Operator type mismatch."<<endl;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			gen(newlabel(), "DEC", (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.width, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr);
			gen(newlabel(), "-", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			offset += max(yyattribute(1 - 3).ntnode->type.width, yyattribute(3 - 3).ntnode->type.width);
		
#line 1238 "myparser.cpp"
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
#line 721 ".\\myparser.y"

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
		
#line 1264 "myparser.cpp"
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
#line 735 ".\\myparser.y"

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
		
#line 1289 "myparser.cpp"
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
#line 748 ".\\myparser.y"

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
		
#line 1314 "myparser.cpp"
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
#line 764 ".\\myparser.y"

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
		
#line 1340 "myparser.cpp"
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
#line 778 ".\\myparser.y"

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
		
#line 1369 "myparser.cpp"
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
#line 795 ".\\myparser.y"

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
		
#line 1394 "myparser.cpp"
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
#line 808 ".\\myparser.y"

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
		
#line 1424 "myparser.cpp"
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
#line 826 ".\\myparser.y"

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
		
#line 1454 "myparser.cpp"
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
#line 847 ".\\myparser.y"

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
		
#line 1480 "myparser.cpp"
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
#line 861 ".\\myparser.y"

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
		
#line 1510 "myparser.cpp"
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
#line 879 ".\\myparser.y"

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
		
#line 1543 "myparser.cpp"
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
#line 903 ".\\myparser.y"

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
		
#line 1569 "myparser.cpp"
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
#line 917 ".\\myparser.y"

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
		
#line 1595 "myparser.cpp"
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
#line 934 ".\\myparser.y"

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
		
#line 1621 "myparser.cpp"
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
#line 948 ".\\myparser.y"

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
		
#line 1647 "myparser.cpp"
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
#line 965 ".\\myparser.y"

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
		
#line 1673 "myparser.cpp"
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
#line 979 ".\\myparser.y"

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
		
#line 1699 "myparser.cpp"
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
#line 996 ".\\myparser.y"

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
		
#line 1725 "myparser.cpp"
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
#line 1010 ".\\myparser.y"

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
		
#line 1752 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#line 1027 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("584 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="M";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->instr = nextinstr + 1;
		
#line 1765 "myparser.cpp"
		}
		break;
	case 58:
		{
#line 1036 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("585 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist->push_back(nextinstr + 1);
			gen(nextinstr+1, "j");
		
#line 1777 "myparser.cpp"
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1046 ".\\myparser.y"

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
		
#line 1803 "myparser.cpp"
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
#line 1061 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("602 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;
			backpatch(yyattribute(1 - 4).ntnode->falselist, yyattribute(3 - 4).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = merge(yyattribute(1 - 4).ntnode->truelist, yyattribute(4 - 4).ntnode->truelist);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(4 - 4).ntnode->falselist;
		
#line 1825 "myparser.cpp"
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
#line 1074 ".\\myparser.y"

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
			 
		
#line 1852 "myparser.cpp"
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
#line 1089 ".\\myparser.y"

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
		
#line 1886 "myparser.cpp"
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
#line 1114 ".\\myparser.y"

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
		
#line 1917 "myparser.cpp"
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
#line 1133 ".\\myparser.y"

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

			
#line 1949 "myparser.cpp"
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
#line 1156 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("654 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 1969 "myparser.cpp"
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
#line 1164 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("661 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 1989 "myparser.cpp"
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
#line 1172 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("668 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="/=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2009 "myparser.cpp"
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
#line 1180 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("675 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="%=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2029 "myparser.cpp"
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
#line 1188 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("682 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2049 "myparser.cpp"
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
#line 1196 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2069 "myparser.cpp"
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
#line 1204 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("696 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="<<=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2089 "myparser.cpp"
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
#line 1212 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("703 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name=">>=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2109 "myparser.cpp"
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
#line 1220 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("710 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2129 "myparser.cpp"
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
#line 1228 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("717 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="^=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2149 "myparser.cpp"
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
#line 1236 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("724 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="|=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2169 "myparser.cpp"
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
#line 1247 ".\\myparser.y"

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
		
#line 2193 "myparser.cpp"
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
#line 1259 ".\\myparser.y"

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
		
#line 2218 "myparser.cpp"
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
#line 1275 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("753 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		
#line 2240 "myparser.cpp"
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
#line 1288 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("763 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
		
#line 2261 "myparser.cpp"
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
#line 1297 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("771 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;		
		
#line 2285 "myparser.cpp"
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
#line 1315 ".\\myparser.y"
 //static
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("783 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
#line 2306 "myparser.cpp"
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
#line 1325 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("791 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2328 "myparser.cpp"
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
#line 1335 ".\\myparser.y"
 // int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("799 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
#line 2349 "myparser.cpp"
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
#line 1344 ".\\myparser.y"
 // lont int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("806 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2371 "myparser.cpp"
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
#line 1354 ".\\myparser.y"
 //const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("814 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;	
		
#line 2392 "myparser.cpp"
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
#line 1363 ".\\myparser.y"
 //const int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("821 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2414 "myparser.cpp"
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
#line 1376 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("832 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		
#line 2436 "myparser.cpp"
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
#line 1386 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
		
#line 2458 "myparser.cpp"
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
#line 1399 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("851 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2478 "myparser.cpp"
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
#line 1407 ".\\myparser.y"

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
		
#line 2520 "myparser.cpp"
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
#line 1440 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("870 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;			
		
#line 2540 "myparser.cpp"
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
#line 1448 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("877 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2560 "myparser.cpp"
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
#line 1456 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("884 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2580 "myparser.cpp"
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
#line 1464 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2600 "myparser.cpp"
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
#line 1472 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("898 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 2620 "myparser.cpp"
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
#line 1483 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			wFlag(voidnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=voidnode;
		
#line 2642 "myparser.cpp"
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
#line 1493 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("915 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(charnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=charnode;
		
#line 2664 "myparser.cpp"
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
#line 1503 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("922 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(shortnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=shortnode;
		
#line 2686 "myparser.cpp"
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
#line 1513 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("929 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(intnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=intnode;
		
#line 2708 "myparser.cpp"
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
#line 1523 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("936 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(longnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=longnode;
		
#line 2730 "myparser.cpp"
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
#line 1533 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("943 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(floatnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=floatnode;
		
#line 2752 "myparser.cpp"
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
#line 1543 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("950 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(doublenode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=doublenode;
		
#line 2774 "myparser.cpp"
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
#line 1553 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("957 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(signednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=signednode;
		
#line 2796 "myparser.cpp"
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
#line 1563 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(unsignednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=unsignednode;
		
#line 2818 "myparser.cpp"
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
#line 1573 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			wFlag(yyattribute(1 - 1).ntnode->type);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = yyattribute(1 - 1).ntnode -> type;

		
#line 2842 "myparser.cpp"
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
#line 1585 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("978 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2862 "myparser.cpp"
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
#line 1593 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("985 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2882 "myparser.cpp"
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
#line 1601 ".\\myparser.y"

		
#line 2896 "myparser.cpp"
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
#line 1606 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("986 ");
			wFlag(*(create_struct(yyattribute(2 - 5).ntnode->name)));
		
#line 2913 "myparser.cpp"
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
#line 1612 ".\\myparser.y"

			static int i = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("987 ");
			wFlag(*(create_struct("struct" + to_string(i))));
			s.back()->vartable["struct" + to_string(i++)] = rFlag();
		
#line 2932 "myparser.cpp"
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
#line 1621 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("988 ");
		
#line 2948 "myparser.cpp"
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
#line 1625 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("989 ");
		
#line 2964 "myparser.cpp"
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
#line 1631 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("990 ");
		
#line 2980 "myparser.cpp"
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
#line 1635 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("991 ");
			
			map<string, typenode*>::iterator i;
			if ((i = auto_define_type.find(yyattribute(2 - 2).ntnode->name)) != auto_define_type.end())
			{
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *auto_define_type[yyattribute(2 - 2).ntnode->name];
			}
			else cout << "struct doesn't exist!\n";
		
#line 3003 "myparser.cpp"
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
#line 1724 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1027 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3023 "myparser.cpp"
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
#line 1732 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1034 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3043 "myparser.cpp"
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
#line 1743 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1044 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3063 "myparser.cpp"
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
#line 1751 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1051 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
		
#line 3084 "myparser.cpp"
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
#line 1763 ".\\myparser.y"

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
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1773 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1062 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3128 "myparser.cpp"
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
#line 1786 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1074 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3149 "myparser.cpp"
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
#line 1795 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1082 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3169 "myparser.cpp"
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
#line 1803 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1089 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3190 "myparser.cpp"
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
#line 1812 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1097 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3210 "myparser.cpp"
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
#line 1823 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1107 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3230 "myparser.cpp"
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
#line 1831 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1114 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3252 "myparser.cpp"
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
#line 1844 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3272 "myparser.cpp"
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
#line 1852 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1133 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3293 "myparser.cpp"
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
#line 1861 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1141 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3315 "myparser.cpp"
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
#line 1874 ".\\myparser.y"
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
		
#line 3338 "myparser.cpp"
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
#line 1885 ".\\myparser.y"
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
		
#line 3362 "myparser.cpp"
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
#line 1897 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1174 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3383 "myparser.cpp"
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
#line 1909 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1185 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3403 "myparser.cpp"
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
#line 1917 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1192 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		
#line 3421 "myparser.cpp"
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
#line 1926 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3441 "myparser.cpp"
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
#line 1934 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1211 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3463 "myparser.cpp"
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
#line 1947 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1223 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3483 "myparser.cpp"
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
#line 1955 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1230 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3503 "myparser.cpp"
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
#line 1966 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1240 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		
#line 3521 "myparser.cpp"
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
#line 1972 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1248 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
#line 3542 "myparser.cpp"
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
#line 1983 ".\\myparser.y"

			fun_name = var_name;
		
#line 3557 "myparser.cpp"
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
#line 1989 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1258 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			var_name = yyattribute(1 - 1).ntnode->name;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
			//gen(newlabel(), "DEC", $1.ntnode->type.width, 0, $1.ntnode->type.addr);
			//cout << $1.ntnode->name << rFlag()->width << endl;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			offset += rFlag()->width;
			gen(newlabel(), "DEC", yyattribute(1 - 1).ntnode->type.width, 0, yyattribute(1 - 1).ntnode->type.addr);
		
#line 3584 "myparser.cpp"
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
#line 2004 ".\\myparser.y"

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
		
#line 3608 "myparser.cpp"
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
#line 2016 ".\\myparser.y"

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
			gen(newlabel(), "DEC", yyattribute(1 - 4).ntnode->type.width, 0, yyattribute(1 - 4).ntnode->type.addr);
			//traverse(root);
		
#line 3656 "myparser.cpp"
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
#line 2052 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1284 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3678 "myparser.cpp"
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
#line 2062 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		
#line 3697 "myparser.cpp"
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
#line 2069 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1303 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}	
			s.pop_back();  
		
#line 3720 "myparser.cpp"
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
#line 2080 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1313 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			fun_name = var_name;
		
#line 3740 "myparser.cpp"
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
#line 2091 ".\\myparser.y"

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
		
#line 3767 "myparser.cpp"
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
#line 2106 ".\\myparser.y"
 // *const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 3787 "myparser.cpp"
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
#line 2114 ".\\myparser.y"
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
		
#line 3813 "myparser.cpp"
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
#line 2128 ".\\myparser.y"
 //*const*
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		
#line 3833 "myparser.cpp"
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
#line 2139 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1359 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 3853 "myparser.cpp"
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
#line 2147 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1366 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 3874 "myparser.cpp"
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
#line 2160 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1378 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			type3->left = rFlag();

			gen(newlabel(), "fun", 0, 0, 0);
		
#line 3898 "myparser.cpp"
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
#line 2172 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1385 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 3920 "myparser.cpp"
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
#line 2185 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1397 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 3940 "myparser.cpp"
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
#line 2193 ".\\myparser.y"

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
		
#line 3968 "myparser.cpp"
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
#line 2212 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1416 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			gen(newlabel(), "param", 0, 0, yyattribute(2 - 2).ntnode -> type.addr);
		
#line 3990 "myparser.cpp"
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
#line 2222 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1424 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4010 "myparser.cpp"
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
#line 2230 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1431 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4030 "myparser.cpp"
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
#line 2241 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1441 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
			offset += rFlag()->width;
			gen(newlabel(), "DEC", yyattribute(1 - 1).ntnode->type.width, 0, yyattribute(1 - 1).ntnode->type.addr);
		
#line 4053 "myparser.cpp"
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
#line 2252 ".\\myparser.y"

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

			gen(newlabel(), "DEC", yyattribute(3 - 3).ntnode->type.width, 0, yyattribute(3 - 3).ntnode->type.addr);
		
#line 4079 "myparser.cpp"
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
#line 2269 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1460 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4099 "myparser.cpp"
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
#line 2277 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1467 ");  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4120 "myparser.cpp"
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
#line 2289 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1478 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4140 "myparser.cpp"
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
#line 2297 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1485 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4160 "myparser.cpp"
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
#line 2305 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1492 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4181 "myparser.cpp"
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
#line 2317 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1503 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4204 "myparser.cpp"
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
#line 2328 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1512 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4225 "myparser.cpp"
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
#line 2337 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1520 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4247 "myparser.cpp"
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
#line 2347 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1529 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4269 "myparser.cpp"
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
#line 2357 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1538 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
#line 4292 "myparser.cpp"
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
#line 2368 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1548 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			s.pop_back();  
		
#line 4314 "myparser.cpp"
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
#line 2378 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1556 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4337 "myparser.cpp"
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
#line 2389 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1565 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4360 "myparser.cpp"
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
#line 2400 ".\\myparser.y"

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
		
#line 4384 "myparser.cpp"
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
#line 2415 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1587 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
#line 4406 "myparser.cpp"
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
#line 2425 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1594 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4428 "myparser.cpp"
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
#line 2435 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1603 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
#line 4451 "myparser.cpp"
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
#line 2449 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1616 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4471 "myparser.cpp"
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
#line 2457 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1623 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4493 "myparser.cpp"
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
#line 2469 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1635 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4510 "myparser.cpp"
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
#line 2474 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1642 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4527 "myparser.cpp"
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
#line 2479 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1643 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4544 "myparser.cpp"
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
#line 2484 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1643 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4561 "myparser.cpp"
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
#line 2491 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1644 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
#line 4583 "myparser.cpp"
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
#line 2501 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1669 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "xx";
		
#line 4600 "myparser.cpp"
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
#line 2506 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1670 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
#line 4617 "myparser.cpp"
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
#line 2513 ".\\myparser.y"

		
	
#line 4632 "myparser.cpp"
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
#line 2517 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1680 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4654 "myparser.cpp"
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
#line 2527 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
#line 4671 "myparser.cpp"
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
#line 2532 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1699 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
#line 4688 "myparser.cpp"
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
#line 2540 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1711 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4709 "myparser.cpp"
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
#line 2549 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1719 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 4727 "myparser.cpp"
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
#line 2555 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1728 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 4745 "myparser.cpp"
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
#line 2561 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1737 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist= yyattribute(3 - 4).ntnode->nextlist ;
		
#line 4763 "myparser.cpp"
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
#line 2570 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1750 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
#line 4785 "myparser.cpp"
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
#line 2580 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1757 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =yyattribute(3 - 3).ntnode->nextlist; 
		
#line 4804 "myparser.cpp"
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
#line 2590 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1768 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4824 "myparser.cpp"
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
#line 2598 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//cout<<"$2->instr:"<<$2->instr<<endl;
			//printf("1775 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =yyattribute(3 - 3).ntnode->nextlist; 
		
#line 4844 "myparser.cpp"
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
#line 2609 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1786 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4864 "myparser.cpp"
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
#line 2617 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1793 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4885 "myparser.cpp"
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
#line 2628 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1794 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
#line 4906 "myparser.cpp"
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
#line 2637 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(); 
			//printf("1795 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4926 "myparser.cpp"
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
#line 2647 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1803 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
			s.pop_back();
			traverse_vartable(s.size() - 1);	 					
		
#line 4948 "myparser.cpp"
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
#line 2657 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1815 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			traverse_vartable(s.size() - 1);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type; 
		
#line 4970 "myparser.cpp"
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
#line 2669 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1816 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(6 - 6).ntnode->type;
			s.pop_back();
			traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 6).ntnode->truelist, yyattribute(5 - 6).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =merge(yyattribute(3 - 6).ntnode->falselist, yyattribute(6 - 6).ntnode->nextlist); 
			 
		
#line 4993 "myparser.cpp"
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
#line 2680 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1817 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			s.pop_back();
			traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
		
#line 5015 "myparser.cpp"
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
#line 2692 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1818 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5035 "myparser.cpp"
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
#line 2700 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1825 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			s.pop_back();  
		
#line 5053 "myparser.cpp"
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
#line 2708 ".\\myparser.y"

		    // $$->type = $3->type;
			// offset += $$->type.width;
			// switch_addr = $$->type.addr;			
			// gen(newlabel(), "=", $$->type.addr, 0, $3->type.addr);
			// default_label=newlabel();
			// gen(nextinstr,"j",0,0,default_label);
	
#line 5073 "myparser.cpp"
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
#line 2718 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(4 - 7).ntnode->truelist, yyattribute(6 - 7).ntnode->instr); 
			backpatch(yyattribute(7 - 7).ntnode->nextlist, yyattribute(2 - 7).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(4 - 7).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(2 - 7).ntnode->instr) ; 
			s.pop_back();
		
#line 5095 "myparser.cpp"
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
#line 2728 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1850 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(7 - 9).ntnode->truelist, yyattribute(2 - 9).ntnode->instr); 
			backpatch(yyattribute(3 - 9).ntnode->nextlist, yyattribute(5 - 9).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(7 - 9).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(5 - 9).ntnode->instr) ; 
			s.pop_back(); 
		
#line 5117 "myparser.cpp"
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
#line 2738 ".\\myparser.y"

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
		
#line 5142 "myparser.cpp"
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
#line 2751 ".\\myparser.y"

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
		
#line 5170 "myparser.cpp"
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
#line 2770 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 5192 "myparser.cpp"
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
#line 2780 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1900 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 5213 "myparser.cpp"
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
#line 2789 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 5234 "myparser.cpp"
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
#line 2798 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1916 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			rtn_stmt.push(&voidnode);		
		
#line 5256 "myparser.cpp"
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
#line 2808 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1924 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;	
			rtn_stmt.push(&(yyattribute(2 - 3).ntnode->type));	
		
#line 5279 "myparser.cpp"
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
#line 2822 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1946 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			show_code();
		
#line 5300 "myparser.cpp"
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
#line 2831 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1953 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			show_code();
		
#line 5322 "myparser.cpp"
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
#line 2844 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5342 "myparser.cpp"
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
#line 2852 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5362 "myparser.cpp"
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
#line 2863 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1981 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
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
		
#line 5394 "myparser.cpp"
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
#line 2883 ".\\myparser.y"

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
		
#line 5432 "myparser.cpp"
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
#line 2909 ".\\myparser.y"

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
		
#line 5468 "myparser.cpp"
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
#line 2933 ".\\myparser.y"

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
		
#line 5503 "myparser.cpp"
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

	yytokenaction_size = 443;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 154, YYAT_SHIFT, 93 },
		{ 355, YYAT_ERROR, 0 },
		{ 148, YYAT_SHIFT, 240 },
		{ 25, YYAT_ACCEPT, 0 },
		{ 120, YYAT_SHIFT, 218 },
		{ 154, YYAT_SHIFT, 94 },
		{ 52, YYAT_SHIFT, 87 },
		{ 154, YYAT_SHIFT, 95 },
		{ 52, YYAT_SHIFT, 2 },
		{ 154, YYAT_SHIFT, 96 },
		{ 154, YYAT_SHIFT, 97 },
		{ 43, YYAT_SHIFT, 2 },
		{ 154, YYAT_SHIFT, 98 },
		{ 367, YYAT_SHIFT, 93 },
		{ 2, YYAT_SHIFT, 2 },
		{ 167, YYAT_SHIFT, 1 },
		{ 92, YYAT_SHIFT, 87 },
		{ 167, YYAT_SHIFT, 2 },
		{ 367, YYAT_SHIFT, 94 },
		{ 87, YYAT_SHIFT, 87 },
		{ 367, YYAT_SHIFT, 95 },
		{ 33, YYAT_SHIFT, 62 },
		{ 367, YYAT_SHIFT, 96 },
		{ 367, YYAT_SHIFT, 97 },
		{ 110, YYAT_SHIFT, 198 },
		{ 367, YYAT_SHIFT, 98 },
		{ 154, YYAT_SHIFT, 127 },
		{ 23, YYAT_SHIFT, 44 },
		{ 24, YYAT_SHIFT, 46 },
		{ 323, YYAT_SHIFT, 339 },
		{ 110, YYAT_SHIFT, 199 },
		{ 173, YYAT_SHIFT, 171 },
		{ 362, YYAT_SHIFT, 366 },
		{ 182, YYAT_ERROR, 0 },
		{ 182, YYAT_SHIFT, 272 },
		{ 182, YYAT_ERROR, 0 },
		{ 187, YYAT_SHIFT, 278 },
		{ 280, YYAT_SHIFT, 278 },
		{ 187, YYAT_SHIFT, 2 },
		{ 367, YYAT_SHIFT, 127 },
		{ 184, YYAT_SHIFT, 182 },
		{ 237, YYAT_SHIFT, 256 },
		{ 358, YYAT_SHIFT, 362 },
		{ 25, YYAT_SHIFT, 1 },
		{ 72, YYAT_SHIFT, 167 },
		{ 25, YYAT_SHIFT, 2 },
		{ 365, YYAT_SHIFT, 101 },
		{ 287, YYAT_SHIFT, 256 },
		{ 90, YYAT_SHIFT, 182 },
		{ 64, YYAT_SHIFT, 55 },
		{ 29, YYAT_SHIFT, 55 },
		{ 360, YYAT_SHIFT, 364 },
		{ 302, YYAT_SHIFT, 256 },
		{ 293, YYAT_SHIFT, 205 },
		{ 360, YYAT_SHIFT, 256 },
		{ 356, YYAT_SHIFT, 361 },
		{ 237, YYAT_SHIFT, 316 },
		{ 52, YYAT_SHIFT, 88 },
		{ 293, YYAT_SHIFT, 206 },
		{ 72, YYAT_SHIFT, 169 },
		{ 295, YYAT_SHIFT, 208 },
		{ 39, YYAT_SHIFT, 2 },
		{ 295, YYAT_SHIFT, 209 },
		{ 293, YYAT_SHIFT, 207 },
		{ 292, YYAT_SHIFT, 205 },
		{ 355, YYAT_ERROR, 0 },
		{ 302, YYAT_SHIFT, 330 },
		{ 92, YYAT_SHIFT, 88 },
		{ 196, YYAT_SHIFT, 284 },
		{ 292, YYAT_SHIFT, 206 },
		{ 294, YYAT_SHIFT, 208 },
		{ 196, YYAT_SHIFT, 285 },
		{ 294, YYAT_SHIFT, 209 },
		{ 278, YYAT_ERROR, 0 },
		{ 292, YYAT_SHIFT, 207 },
		{ 110, YYAT_SHIFT, 200 },
		{ 48, YYAT_SHIFT, 83 },
		{ 351, YYAT_REDUCE, 59 },
		{ 278, YYAT_ERROR, 0 },
		{ 48, YYAT_SHIFT, 84 },
		{ 278, YYAT_SHIFT, 278 },
		{ 278, YYAT_SHIFT, 177 },
		{ 278, YYAT_SHIFT, 2 },
		{ 278, YYAT_ERROR, 0 },
		{ 182, YYAT_ERROR, 0 },
		{ 278, YYAT_ERROR, 0 },
		{ 346, YYAT_SHIFT, 354 },
		{ 187, YYAT_SHIFT, 88 },
		{ 280, YYAT_SHIFT, 88 },
		{ 345, YYAT_SHIFT, 353 },
		{ 154, YYAT_SHIFT, 57 },
		{ 184, YYAT_SHIFT, 183 },
		{ 154, YYAT_SHIFT, 254 },
		{ 154, YYAT_SHIFT, 100 },
		{ 365, YYAT_ERROR, 0 },
		{ 365, YYAT_ERROR, 0 },
		{ 287, YYAT_SHIFT, 329 },
		{ 115, YYAT_SHIFT, 205 },
		{ 365, YYAT_ERROR, 0 },
		{ 90, YYAT_SHIFT, 183 },
		{ 64, YYAT_SHIFT, 56 },
		{ 29, YYAT_SHIFT, 56 },
		{ 115, YYAT_SHIFT, 206 },
		{ 367, YYAT_SHIFT, 57 },
		{ 306, YYAT_SHIFT, 216 },
		{ 306, YYAT_SHIFT, 217 },
		{ 367, YYAT_SHIFT, 100 },
		{ 115, YYAT_SHIFT, 207 },
		{ 339, YYAT_SHIFT, 347 },
		{ 66, YYAT_SHIFT, 164 },
		{ 323, YYAT_SHIFT, 340 },
		{ 116, YYAT_SHIFT, 208 },
		{ 173, YYAT_SHIFT, 268 },
		{ 116, YYAT_SHIFT, 209 },
		{ 299, YYAT_SHIFT, 210 },
		{ 299, YYAT_SHIFT, 211 },
		{ 189, YYAT_SHIFT, 2 },
		{ 298, YYAT_SHIFT, 210 },
		{ 298, YYAT_SHIFT, 211 },
		{ 297, YYAT_SHIFT, 210 },
		{ 297, YYAT_SHIFT, 211 },
		{ 296, YYAT_SHIFT, 210 },
		{ 296, YYAT_SHIFT, 211 },
		{ 119, YYAT_SHIFT, 216 },
		{ 119, YYAT_SHIFT, 217 },
		{ 117, YYAT_SHIFT, 210 },
		{ 117, YYAT_SHIFT, 211 },
		{ 338, YYAT_SHIFT, 127 },
		{ 336, YYAT_SHIFT, 344 },
		{ 332, YYAT_SHIFT, 220 },
		{ 331, YYAT_SHIFT, 224 },
		{ 278, YYAT_SHIFT, 88 },
		{ 37, YYAT_SHIFT, 4 },
		{ 57, YYAT_SHIFT, 127 },
		{ 313, YYAT_SHIFT, 337 },
		{ 37, YYAT_SHIFT, 5 },
		{ 37, YYAT_SHIFT, 6 },
		{ 37, YYAT_SHIFT, 7 },
		{ 37, YYAT_SHIFT, 8 },
		{ 37, YYAT_SHIFT, 9 },
		{ 37, YYAT_SHIFT, 10 },
		{ 37, YYAT_SHIFT, 11 },
		{ 37, YYAT_SHIFT, 12 },
		{ 37, YYAT_SHIFT, 13 },
		{ 37, YYAT_SHIFT, 14 },
		{ 37, YYAT_SHIFT, 15 },
		{ 37, YYAT_SHIFT, 16 },
		{ 37, YYAT_SHIFT, 17 },
		{ 37, YYAT_SHIFT, 18 },
		{ 37, YYAT_SHIFT, 19 },
		{ 37, YYAT_SHIFT, 20 },
		{ 37, YYAT_SHIFT, 21 },
		{ 37, YYAT_SHIFT, 22 },
		{ 37, YYAT_SHIFT, 23 },
		{ 311, YYAT_SHIFT, 335 },
		{ 33, YYAT_SHIFT, 63 },
		{ 310, YYAT_SHIFT, 334 },
		{ 305, YYAT_SHIFT, 223 },
		{ 304, YYAT_SHIFT, 221 },
		{ 283, YYAT_SHIFT, 327 },
		{ 275, YYAT_SHIFT, 325 },
		{ 23, YYAT_SHIFT, 45 },
		{ 273, YYAT_SHIFT, 324 },
		{ 261, YYAT_SHIFT, 261 },
		{ 260, YYAT_SHIFT, 321 },
		{ 255, YYAT_SHIFT, 319 },
		{ 278, YYAT_ERROR, 0 },
		{ 233, YYAT_SHIFT, 315 },
		{ 230, YYAT_SHIFT, 312 },
		{ 28, YYAT_SHIFT, 4 },
		{ 226, YYAT_SHIFT, 309 },
		{ 66, YYAT_SHIFT, 57 },
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
		{ 301, YYAT_SHIFT, 212 },
		{ 201, YYAT_SHIFT, 288 },
		{ 301, YYAT_SHIFT, 213 },
		{ 300, YYAT_SHIFT, 212 },
		{ 199, YYAT_SHIFT, 286 },
		{ 300, YYAT_SHIFT, 213 },
		{ 57, YYAT_SHIFT, 57 },
		{ 118, YYAT_SHIFT, 212 },
		{ 57, YYAT_SHIFT, 128 },
		{ 118, YYAT_SHIFT, 213 },
		{ 188, YYAT_SHIFT, 281 },
		{ 186, YYAT_SHIFT, 277 },
		{ 183, YYAT_SHIFT, 274 },
		{ 181, YYAT_SHIFT, 271 },
		{ 179, YYAT_SHIFT, 270 },
		{ 178, YYAT_SHIFT, 269 },
		{ 171, YYAT_SHIFT, 79 },
		{ 165, YYAT_SHIFT, 57 },
		{ 163, YYAT_ERROR, 0 },
		{ 162, YYAT_SHIFT, 259 },
		{ 157, YYAT_SHIFT, 257 },
		{ 120, YYAT_SHIFT, 219 },
		{ 148, YYAT_SHIFT, 241 },
		{ 148, YYAT_SHIFT, 242 },
		{ 148, YYAT_SHIFT, 243 },
		{ 148, YYAT_SHIFT, 244 },
		{ 148, YYAT_SHIFT, 245 },
		{ 148, YYAT_SHIFT, 246 },
		{ 148, YYAT_SHIFT, 247 },
		{ 148, YYAT_SHIFT, 248 },
		{ 148, YYAT_SHIFT, 249 },
		{ 148, YYAT_SHIFT, 250 },
		{ 52, YYAT_SHIFT, 3 },
		{ 154, YYAT_SHIFT, 129 },
		{ 154, YYAT_SHIFT, 102 },
		{ 154, YYAT_SHIFT, 103 },
		{ 154, YYAT_SHIFT, 104 },
		{ 150, YYAT_SHIFT, 252 },
		{ 154, YYAT_SHIFT, 105 },
		{ 154, YYAT_SHIFT, 106 },
		{ 140, YYAT_SHIFT, 236 },
		{ 167, YYAT_SHIFT, 3 },
		{ 92, YYAT_SHIFT, 3 },
		{ 139, YYAT_SHIFT, 235 },
		{ 138, YYAT_SHIFT, 234 },
		{ 87, YYAT_SHIFT, 3 },
		{ 367, YYAT_SHIFT, 129 },
		{ 367, YYAT_SHIFT, 102 },
		{ 367, YYAT_SHIFT, 103 },
		{ 367, YYAT_SHIFT, 104 },
		{ 137, YYAT_SHIFT, 233 },
		{ 367, YYAT_SHIFT, 105 },
		{ 367, YYAT_SHIFT, 106 },
		{ 24, YYAT_SHIFT, 47 },
		{ 110, YYAT_SHIFT, 201 },
		{ 110, YYAT_SHIFT, 202 },
		{ 110, YYAT_SHIFT, 203 },
		{ 136, YYAT_SHIFT, 232 },
		{ 355, YYAT_ERROR, 0 },
		{ 154, YYAT_SHIFT, 107 },
		{ 154, YYAT_SHIFT, 108 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 133, YYAT_SHIFT, 229 },
		{ 25, YYAT_SHIFT, 3 },
		{ 132, YYAT_SHIFT, 228 },
		{ 131, YYAT_SHIFT, 227 },
		{ 367, YYAT_SHIFT, 107 },
		{ 367, YYAT_SHIFT, 108 },
		{ 129, YYAT_SHIFT, 225 },
		{ 125, YYAT_SHIFT, 224 },
		{ 43, YYAT_SHIFT, 18 },
		{ 43, YYAT_SHIFT, 19 },
		{ 124, YYAT_SHIFT, 223 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 154, YYAT_SHIFT, 130 },
		{ 154, YYAT_SHIFT, 131 },
		{ 154, YYAT_SHIFT, 132 },
		{ 123, YYAT_SHIFT, 222 },
		{ 154, YYAT_SHIFT, 133 },
		{ 154, YYAT_SHIFT, 134 },
		{ 154, YYAT_SHIFT, 135 },
		{ 154, YYAT_SHIFT, 136 },
		{ 154, YYAT_SHIFT, 137 },
		{ 154, YYAT_SHIFT, 138 },
		{ 154, YYAT_SHIFT, 139 },
		{ 154, YYAT_SHIFT, 140 },
		{ 122, YYAT_SHIFT, 221 },
		{ 367, YYAT_SHIFT, 130 },
		{ 367, YYAT_SHIFT, 131 },
		{ 367, YYAT_SHIFT, 132 },
		{ 121, YYAT_SHIFT, 220 },
		{ 367, YYAT_SHIFT, 133 },
		{ 367, YYAT_SHIFT, 134 },
		{ 367, YYAT_SHIFT, 135 },
		{ 367, YYAT_SHIFT, 136 },
		{ 367, YYAT_SHIFT, 137 },
		{ 367, YYAT_SHIFT, 138 },
		{ 367, YYAT_SHIFT, 139 },
		{ 367, YYAT_SHIFT, 140 },
		{ 278, YYAT_ERROR, 0 },
		{ 278, YYAT_ERROR, 0 },
		{ 278, YYAT_ERROR, 0 },
		{ 278, YYAT_ERROR, 0 },
		{ 39, YYAT_SHIFT, 4 },
		{ 278, YYAT_ERROR, 0 },
		{ 278, YYAT_ERROR, 0 },
		{ 39, YYAT_SHIFT, 5 },
		{ 39, YYAT_SHIFT, 6 },
		{ 39, YYAT_SHIFT, 7 },
		{ 39, YYAT_SHIFT, 8 },
		{ 39, YYAT_SHIFT, 9 },
		{ 39, YYAT_SHIFT, 10 },
		{ 39, YYAT_SHIFT, 11 },
		{ 39, YYAT_SHIFT, 12 },
		{ 39, YYAT_SHIFT, 13 },
		{ 39, YYAT_SHIFT, 14 },
		{ 39, YYAT_SHIFT, 15 },
		{ 39, YYAT_SHIFT, 16 },
		{ 39, YYAT_SHIFT, 17 },
		{ 39, YYAT_SHIFT, 18 },
		{ 39, YYAT_SHIFT, 19 },
		{ 39, YYAT_SHIFT, 20 },
		{ 39, YYAT_SHIFT, 21 },
		{ 39, YYAT_SHIFT, 22 },
		{ 39, YYAT_SHIFT, 23 },
		{ 278, YYAT_ERROR, 0 },
		{ 278, YYAT_ERROR, 0 },
		{ 278, YYAT_SHIFT, 5 },
		{ 278, YYAT_SHIFT, 6 },
		{ 278, YYAT_SHIFT, 7 },
		{ 278, YYAT_SHIFT, 8 },
		{ 278, YYAT_SHIFT, 9 },
		{ 66, YYAT_SHIFT, 4 },
		{ 57, YYAT_SHIFT, 129 },
		{ 109, YYAT_SHIFT, 195 },
		{ 66, YYAT_SHIFT, 5 },
		{ 66, YYAT_SHIFT, 6 },
		{ 66, YYAT_SHIFT, 7 },
		{ 66, YYAT_SHIFT, 8 },
		{ 66, YYAT_SHIFT, 9 },
		{ 66, YYAT_SHIFT, 10 },
		{ 66, YYAT_SHIFT, 11 },
		{ 66, YYAT_SHIFT, 12 },
		{ 66, YYAT_SHIFT, 13 },
		{ 66, YYAT_SHIFT, 14 },
		{ 66, YYAT_SHIFT, 15 },
		{ 66, YYAT_SHIFT, 16 },
		{ 66, YYAT_SHIFT, 17 },
		{ 66, YYAT_SHIFT, 18 },
		{ 66, YYAT_SHIFT, 19 },
		{ 66, YYAT_SHIFT, 20 },
		{ 66, YYAT_SHIFT, 21 },
		{ 66, YYAT_SHIFT, 22 },
		{ 66, YYAT_SHIFT, 23 },
		{ 106, YYAT_SHIFT, 192 },
		{ 104, YYAT_SHIFT, 190 },
		{ 88, YYAT_SHIFT, 180 },
		{ 85, YYAT_SHIFT, 175 },
		{ 189, YYAT_SHIFT, 4 },
		{ 84, YYAT_SHIFT, 174 },
		{ 81, YYAT_SHIFT, 172 },
		{ 57, YYAT_SHIFT, 5 },
		{ 57, YYAT_SHIFT, 6 },
		{ 57, YYAT_SHIFT, 7 },
		{ 57, YYAT_SHIFT, 8 },
		{ 57, YYAT_SHIFT, 9 },
		{ 189, YYAT_SHIFT, 10 },
		{ 189, YYAT_SHIFT, 11 },
		{ 189, YYAT_SHIFT, 12 },
		{ 189, YYAT_SHIFT, 13 },
		{ 189, YYAT_SHIFT, 14 },
		{ 189, YYAT_SHIFT, 15 },
		{ 189, YYAT_SHIFT, 16 },
		{ 189, YYAT_SHIFT, 17 },
		{ 189, YYAT_SHIFT, 18 },
		{ 189, YYAT_SHIFT, 19 },
		{ 189, YYAT_SHIFT, 20 },
		{ 189, YYAT_SHIFT, 21 },
		{ 189, YYAT_SHIFT, 22 },
		{ 189, YYAT_SHIFT, 23 },
		{ 79, YYAT_SHIFT, 170 },
		{ 57, YYAT_SHIFT, 130 },
		{ 57, YYAT_SHIFT, 131 },
		{ 57, YYAT_SHIFT, 132 },
		{ 71, YYAT_SHIFT, 164 },
		{ 57, YYAT_SHIFT, 133 },
		{ 57, YYAT_SHIFT, 134 },
		{ 57, YYAT_SHIFT, 135 },
		{ 57, YYAT_SHIFT, 136 },
		{ 57, YYAT_SHIFT, 137 },
		{ 57, YYAT_SHIFT, 138 },
		{ 57, YYAT_SHIFT, 139 },
		{ 57, YYAT_SHIFT, 140 },
		{ 67, YYAT_SHIFT, 168 },
		{ 63, YYAT_SHIFT, 163 },
		{ 60, YYAT_SHIFT, 65 },
		{ 58, YYAT_SHIFT, 57 },
		{ 56, YYAT_SHIFT, 99 },
		{ 50, YYAT_SHIFT, 86 },
		{ 301, YYAT_SHIFT, 214 },
		{ 301, YYAT_SHIFT, 215 },
		{ 190, YYAT_SHIFT, 4 },
		{ 300, YYAT_SHIFT, 214 },
		{ 300, YYAT_SHIFT, 215 },
		{ 49, YYAT_SHIFT, 85 },
		{ 45, YYAT_SHIFT, 82 },
		{ 118, YYAT_SHIFT, 214 },
		{ 118, YYAT_SHIFT, 215 },
		{ 40, YYAT_SHIFT, 76 },
		{ 190, YYAT_SHIFT, 10 },
		{ 190, YYAT_SHIFT, 11 },
		{ 190, YYAT_SHIFT, 12 },
		{ 190, YYAT_SHIFT, 13 },
		{ 190, YYAT_SHIFT, 14 },
		{ 190, YYAT_SHIFT, 15 },
		{ 190, YYAT_SHIFT, 16 },
		{ 190, YYAT_SHIFT, 17 },
		{ 190, YYAT_SHIFT, 18 },
		{ 190, YYAT_SHIFT, 19 },
		{ 190, YYAT_SHIFT, 20 },
		{ 190, YYAT_SHIFT, 21 },
		{ 190, YYAT_SHIFT, 22 },
		{ 190, YYAT_SHIFT, 23 },
		{ 185, YYAT_SHIFT, 4 },
		{ 38, YYAT_SHIFT, 70 },
		{ 34, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 57 },
		{ 0, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 185, YYAT_SHIFT, 10 },
		{ 185, YYAT_SHIFT, 11 },
		{ 185, YYAT_SHIFT, 12 },
		{ 185, YYAT_SHIFT, 13 },
		{ 185, YYAT_SHIFT, 14 },
		{ 185, YYAT_SHIFT, 15 },
		{ 185, YYAT_SHIFT, 16 },
		{ 185, YYAT_SHIFT, 17 },
		{ 185, YYAT_SHIFT, 18 },
		{ 185, YYAT_SHIFT, 19 },
		{ 185, YYAT_SHIFT, 20 },
		{ 185, YYAT_SHIFT, 21 },
		{ 185, YYAT_SHIFT, 22 },
		{ 185, YYAT_SHIFT, 23 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 425, 1, YYAT_DEFAULT, 25 },
		{ 0, 0, YYAT_DEFAULT, 167 },
		{ -28, 1, YYAT_REDUCE, 150 },
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
		{ -13, 1, YYAT_DEFAULT, 182 },
		{ 3, 1, YYAT_DEFAULT, 163 },
		{ 0, 0, YYAT_REDUCE, 223 },
		{ 0, 0, YYAT_REDUCE, 225 },
		{ -113, 1, YYAT_REDUCE, 86 },
		{ 10, 1, YYAT_REDUCE, 141 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 301, 1, YYAT_DEFAULT, 163 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ 381, 1, YYAT_DEFAULT, 167 },
		{ 0, 0, YYAT_DEFAULT, 60 },
		{ 0, 0, YYAT_REDUCE, 226 },
		{ -150, 1, YYAT_REDUCE, 82 },
		{ 363, 1, YYAT_DEFAULT, 167 },
		{ 19, 1, YYAT_REDUCE, 84 },
		{ 365, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ -31, 1, YYAT_REDUCE, 151 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 280, 1, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 35, 1, YYAT_ERROR, 0 },
		{ 358, 1, YYAT_REDUCE, 156 },
		{ 355, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 158 },
		{ -34, 1, YYAT_REDUCE, 162 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 302, 1, YYAT_DEFAULT, 355 },
		{ 74, 1, YYAT_DEFAULT, 190 },
		{ 271, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 230 },
		{ 334, 1, YYAT_DEFAULT, 167 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 0, 0, YYAT_DEFAULT, 163 },
		{ 269, 1, YYAT_REDUCE, 115 },
		{ 9, 1, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 48, 1, YYAT_REDUCE, 90 },
		{ 332, 1, YYAT_DEFAULT, 72 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 321, 1, YYAT_REDUCE, 90 },
		{ 0, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 317, 1, YYAT_REDUCE, 136 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 233, 1, YYAT_DEFAULT, 173 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 100, 1, YYAT_ERROR, 0 },
		{ 51, 1, YYAT_DEFAULT, 163 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ -21, 1, YYAT_DEFAULT, 278 },
		{ 261, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 161 },
		{ 8, 1, YYAT_REDUCE, 168 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ -24, 1, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 313, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 106 },
		{ 312, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 291, 1, YYAT_DEFAULT, 355 },
		{ -16, 1, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 60, 1, YYAT_REDUCE, 36 },
		{ 68, 1, YYAT_REDUCE, 39 },
		{ -139, 1, YYAT_REDUCE, 42 },
		{ 138, 1, YYAT_REDUCE, 47 },
		{ -145, 1, YYAT_REDUCE, 50 },
		{ -59, 1, YYAT_REDUCE, 62 },
		{ 164, 1, YYAT_REDUCE, 56 },
		{ 190, 1, YYAT_REDUCE, 54 },
		{ 182, 1, YYAT_ERROR, 0 },
		{ 231, 1, YYAT_REDUCE, 52 },
		{ -4, 1, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 207, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 204, 1, YYAT_ERROR, 0 },
		{ 221, 1, YYAT_ERROR, 0 },
		{ 219, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 208, 1, YYAT_ERROR, 0 },
		{ -16, 1, YYAT_ERROR, 0 },
		{ 176, 1, YYAT_ERROR, 0 },
		{ 175, 1, YYAT_ERROR, 0 },
		{ 172, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ -59, 1, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 103, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ -33, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ 152, 1, YYAT_DEFAULT, 237 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_DEFAULT, 163 },
		{ 0, 0, YYAT_REDUCE, 229 },
		{ 85, 1, YYAT_REDUCE, 58 },
		{ 168, 1, YYAT_DEFAULT, 182 },
		{ 0, 0, YYAT_DEFAULT, 261 },
		{ 85, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 228 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -50, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ -13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 165, 1, YYAT_ERROR, 0 },
		{ 164, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 111, 1, YYAT_ERROR, 0 },
		{ -7, 1, YYAT_DEFAULT, 278 },
		{ 110, 1, YYAT_DEFAULT, 355 },
		{ 0, 1, YYAT_REDUCE, 169 },
		{ 139, 1, YYAT_REDUCE, 125 },
		{ 161, 1, YYAT_ERROR, 0 },
		{ -4, 1, YYAT_REDUCE, 165 },
		{ 160, 1, YYAT_DEFAULT, 360 },
		{ 74, 1, YYAT_REDUCE, 123 },
		{ 117, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -62, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -65, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 21 },
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
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 112, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 128, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 338 },
		{ 108, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 219 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ -3, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_REDUCE, 194 },
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
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 40, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 39, 1, YYAT_REDUCE, 58 },
		{ 40, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 227 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 132 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 121, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 67, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 40, 1, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ -3, 1, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 118, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 3, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 27, 1, YYAT_REDUCE, 37 },
		{ 16, 1, YYAT_REDUCE, 38 },
		{ 27, 1, YYAT_REDUCE, 40 },
		{ 17, 1, YYAT_REDUCE, 41 },
		{ -143, 1, YYAT_REDUCE, 43 },
		{ -145, 1, YYAT_REDUCE, 44 },
		{ -147, 1, YYAT_REDUCE, 45 },
		{ -150, 1, YYAT_REDUCE, 46 },
		{ 134, 1, YYAT_REDUCE, 48 },
		{ 131, 1, YYAT_REDUCE, 49 },
		{ 8, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 64, 1, YYAT_REDUCE, 55 },
		{ 119, 1, YYAT_REDUCE, 53 },
		{ -164, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 115, 1, YYAT_DEFAULT, 360 },
		{ 113, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -176, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ -15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -140, 1, YYAT_REDUCE, 61 },
		{ 5, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 87, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 68, 1, YYAT_DEFAULT, 355 },
		{ -17, 1, YYAT_DEFAULT, 261 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 0, 0, YYAT_DEFAULT, 365 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 49, 1, YYAT_ERROR, 0 },
		{ 45, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ -231, 1, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -58, 1, YYAT_DEFAULT, 365 },
		{ -253, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 1, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 10, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 216 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -211, 1, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ -20, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 217 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 262;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 367, 114 },
		{ 367, 109 },
		{ 367, 110 },
		{ 338, 157 },
		{ 367, 148 },
		{ 367, 112 },
		{ 367, 113 },
		{ 367, 115 },
		{ 367, 116 },
		{ 367, 117 },
		{ 367, 118 },
		{ 367, 119 },
		{ 367, 124 },
		{ 367, 122 },
		{ 367, 121 },
		{ 367, 125 },
		{ 339, 263 },
		{ 160, 258 },
		{ 367, 120 },
		{ 367, 159 },
		{ 367, 158 },
		{ 330, 111 },
		{ 367, 157 },
		{ 189, -1 },
		{ 163, 61 },
		{ 163, 60 },
		{ 189, -1 },
		{ 189, 189 },
		{ 307, 332 },
		{ 307, -1 },
		{ 38, 72 },
		{ 39, 75 },
		{ 307, -1 },
		{ 307, -1 },
		{ 189, 282 },
		{ 38, 73 },
		{ 330, 341 },
		{ 330, -1 },
		{ 57, 61 },
		{ 57, 60 },
		{ 189, 185 },
		{ 364, 367 },
		{ 57, 37 },
		{ 57, 39 },
		{ 57, 38 },
		{ 338, 346 },
		{ 57, 30 },
		{ 57, 33 },
		{ 163, -1 },
		{ 163, -1 },
		{ 163, -1 },
		{ 339, 348 },
		{ 39, 74 },
		{ 57, 31 },
		{ 154, 160 },
		{ 160, -1 },
		{ 57, 28 },
		{ 367, 144 },
		{ 367, 370 },
		{ 367, 147 },
		{ 367, 155 },
		{ 367, 156 },
		{ 163, 260 },
		{ 85, 52 },
		{ 367, 151 },
		{ 367, 143 },
		{ 367, 146 },
		{ 367, 145 },
		{ 367, 142 },
		{ 367, 141 },
		{ 367, 152 },
		{ 367, 153 },
		{ 57, 149 },
		{ 355, 360 },
		{ 109, 196 },
		{ 278, 52 },
		{ 57, 154 },
		{ 57, 150 },
		{ 278, 37 },
		{ 278, 39 },
		{ 278, 38 },
		{ 1, -1 },
		{ 278, 30 },
		{ 278, 33 },
		{ 185, 276 },
		{ 25, 36 },
		{ 25, 35 },
		{ 24, 50 },
		{ 85, 176 },
		{ 278, 31 },
		{ 24, 48 },
		{ 109, 197 },
		{ 278, 28 },
		{ 361, 365 },
		{ 185, -1 },
		{ 167, 265 },
		{ 154, 149 },
		{ 1, 40 },
		{ 278, 179 },
		{ 278, 49 },
		{ 278, 51 },
		{ 154, 255 },
		{ 187, 280 },
		{ 278, 178 },
		{ 25, 32 },
		{ 25, 24 },
		{ 25, 29 },
		{ 25, 34 },
		{ 355, -1 },
		{ 187, 279 },
		{ 187, 90 },
		{ 167, 71 },
		{ 355, -1 },
		{ 167, 29 },
		{ 167, 34 },
		{ 355, -1 },
		{ 183, 126 },
		{ 355, -1 },
		{ 355, -1 },
		{ 359, 363 },
		{ 183, 275 },
		{ 355, -1 },
		{ 355, -1 },
		{ 190, 189 },
		{ 190, 38 },
		{ 43, 77 },
		{ 190, 30 },
		{ 190, 33 },
		{ 354, 359 },
		{ 43, 78 },
		{ 190, 187 },
		{ 303, 121 },
		{ 303, 331 },
		{ 190, 31 },
		{ 25, 53 },
		{ 25, 27 },
		{ 190, 185 },
		{ 261, 322 },
		{ 261, 323 },
		{ 365, 350 },
		{ 365, -1 },
		{ 365, -1 },
		{ 365, -1 },
		{ 343, 349 },
		{ 343, 351 },
		{ 343, 145 },
		{ 190, 283 },
		{ 365, -1 },
		{ 365, 369 },
		{ 365, 368 },
		{ 365, -1 },
		{ 365, -1 },
		{ 52, 91 },
		{ 221, 119 },
		{ 221, 305 },
		{ 52, 92 },
		{ 2, 41 },
		{ 182, -1 },
		{ 353, 358 },
		{ 182, 273 },
		{ 2, 42 },
		{ 2, 43 },
		{ 52, 89 },
		{ 52, 90 },
		{ 182, -1 },
		{ 182, -1 },
		{ 87, 40 },
		{ 87, 24 },
		{ 87, 29 },
		{ 87, 92 },
		{ 277, 326 },
		{ 277, -1 },
		{ 277, -1 },
		{ 223, 306 },
		{ 223, -1 },
		{ 223, -1 },
		{ 285, 328 },
		{ 106, 194 },
		{ 285, -1 },
		{ 106, -1 },
		{ 220, 304 },
		{ 220, -1 },
		{ 217, 301 },
		{ 217, -1 },
		{ 215, 299 },
		{ 215, -1 },
		{ 211, 295 },
		{ 211, -1 },
		{ 209, 113 },
		{ 209, 293 },
		{ 92, 24 },
		{ 92, 64 },
		{ 82, 173 },
		{ 82, 80 },
		{ 66, 166 },
		{ 66, 165 },
		{ 60, 67 },
		{ 60, 68 },
		{ 37, -1 },
		{ 37, 69 },
		{ 32, 59 },
		{ 32, 58 },
		{ 0, 25 },
		{ 0, 26 },
		{ 352, 357 },
		{ 351, 356 },
		{ 346, 355 },
		{ 344, 352 },
		{ 337, 345 },
		{ 334, 343 },
		{ 333, 342 },
		{ 314, 338 },
		{ 312, 336 },
		{ 309, 333 },
		{ 280, 184 },
		{ 260, 160 },
		{ 256, 320 },
		{ 255, 253 },
		{ 253, 318 },
		{ 251, 317 },
		{ 232, 314 },
		{ 231, 313 },
		{ 229, 311 },
		{ 228, 310 },
		{ 225, 308 },
		{ 224, 307 },
		{ 219, 303 },
		{ 218, 302 },
		{ 216, 300 },
		{ 214, 298 },
		{ 213, 297 },
		{ 212, 296 },
		{ 210, 294 },
		{ 208, 292 },
		{ 207, 291 },
		{ 206, 290 },
		{ 205, 289 },
		{ 200, 287 },
		{ 192, 188 },
		{ 171, 267 },
		{ 170, 266 },
		{ 165, 264 },
		{ 164, 262 },
		{ 148, 251 },
		{ 147, 239 },
		{ 141, 238 },
		{ 140, 237 },
		{ 135, 231 },
		{ 134, 230 },
		{ 130, 226 },
		{ 112, 204 },
		{ 105, 193 },
		{ 104, 191 },
		{ 95, 186 },
		{ 88, 181 },
		{ 62, 162 },
		{ 58, 161 },
		{ 56, 123 },
		{ 44, 81 },
		{ 35, 66 },
		{ 34, -1 },
		{ 28, 54 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 129, 25 },
		{ 53, 167 },
		{ 113, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, 182 },
		{ 60, 160 },
		{ 0, -1 },
		{ 0, -1 },
		{ 235, 37 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 138, 163 },
		{ 0, -1 },
		{ 205, 92 },
		{ 215, 60 },
		{ 0, -1 },
		{ 173, 160 },
		{ 3, 60 },
		{ 5, 37 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 82, -1 },
		{ 217, 82 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 108, 1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 233, 183 },
		{ 13, 367 },
		{ 194, 260 },
		{ 0, -1 },
		{ 169, 167 },
		{ 0, -1 },
		{ 192, 163 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 132, 163 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 151, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 37 },
		{ 0, -1 },
		{ 122, 278 },
		{ 230, 183 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 145, 280 },
		{ 0, -1 },
		{ 0, -1 },
		{ 200, 190 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 247, 106 },
		{ 246, 106 },
		{ 172, 277 },
		{ 0, -1 },
		{ 0, -1 },
		{ 70, 285 },
		{ 0, -1 },
		{ 0, -1 },
		{ 243, 277 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 225, 183 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 231, -1 },
		{ 230, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 223, 355 },
		{ 186, 367 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 185, 367 },
		{ 221, -1 },
		{ 0, -1 },
		{ 0, 255 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 367 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -8, 163 },
		{ 0, -1 },
		{ 0, 260 },
		{ -1, 182 },
		{ 186, 339 },
		{ 179, 260 },
		{ 0, -1 },
		{ 67, 34 },
		{ 0, -1 },
		{ 0, -1 },
		{ 216, 183 },
		{ 197, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 110, 278 },
		{ 96, 330 },
		{ 0, -1 },
		{ 47, 189 },
		{ 0, -1 },
		{ 55, -1 },
		{ 0, -1 },
		{ -3, 39 },
		{ 93, 192 },
		{ 0, -1 },
		{ 215, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 214, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 229, 277 },
		{ 228, 277 },
		{ 227, 277 },
		{ 225, 209 },
		{ 181, 277 },
		{ 223, 211 },
		{ 177, 215 },
		{ 221, 215 },
		{ 220, 215 },
		{ 219, 215 },
		{ 174, 217 },
		{ 217, 217 },
		{ 171, 223 },
		{ 204, 355 },
		{ 209, -1 },
		{ 166, 307 },
		{ 141, 223 },
		{ 0, -1 },
		{ 161, 220 },
		{ 208, -1 },
		{ 165, 367 },
		{ 0, -1 },
		{ 0, -1 },
		{ 200, 355 },
		{ 199, 355 },
		{ 0, -1 },
		{ 162, 367 },
		{ 155, 338 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 198, 285 },
		{ 0, -1 },
		{ 159, 367 },
		{ 0, -1 },
		{ 200, -1 },
		{ 195, 285 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 198, -1 },
		{ 81, 339 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 163, 211 },
		{ 49, 187 },
		{ 0, -1 },
		{ 159, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 155, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 116, 307 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 13, 330 },
		{ 0, -1 },
		{ 196, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 189, 355 },
		{ 0, -1 },
		{ 194, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, 285 },
		{ 0, -1 },
		{ 0, -1 },
		{ 151, 367 },
		{ 192, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 191, -1 },
		{ -20, 355 },
		{ -5, 285 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, 365 },
		{ 190, -1 },
		{ 0, -1 },
		{ 189, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 187, -1 },
		{ 145, 367 },
		{ 135, 355 },
		{ 111, -1 },
		{ 50, 365 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 60, 367 },
		{ 0, -1 },
		{ 76, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, -1 },
		{ 81, 367 },
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
#line 2960 ".\\myparser.y"


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
