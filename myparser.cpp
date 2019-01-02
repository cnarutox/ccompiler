/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 85 of your 30 day trial period.
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
* Date: 01/02/19
* Time: 17:23:14
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
		vector<typenode*>::iterator iter;
		for (iter=v.begin();iter!=v.end();iter++){
			// cout<<(*iter)->name<<' ';
		}
		// cout<<endl;
	}

	void show_string(vector<string> &v) {
		// for(int i=0; i<v.size();i++) {
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
		show_string(temp1);
		show_string(temp2);
		if (temp1.size() != temp2.size())
			return false;
		for(int i = 0; i < temp1.size(); i++) {
			if (temp1[i] != temp2[i]){
				if(temp2[i] == "double" && isComputable(temp1[i])||temp1[i] == "double" && isComputable(temp2[i]))
				{
					cout<<endl<<"---------------------------\n";
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
			
			//traverse_vartable(s.size()-1);
			typenode* ptr = search(yyattribute(1 - 1).ntnode->name,s.size()-1);
			// cout<<"$1.ntnode->name:"<<$1.ntnode->name<<endl;
			// cout<<"---------"<<ptr->name<<endl;
			traverse(ptr);				
			if(ptr != NULL)
			{
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *ptr;
			}
			var_name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 302 "myparser.cpp"
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
#line 201 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("116 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *(new typenode("double", 8));
			// offset += $$->type.width;
			offset += 1;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "=#", yyattribute(1 - 1).ntnode->dvalue, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr);
		
#line 329 "myparser.cpp"
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
#line 216 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("123 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 349 "myparser.cpp"
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
#line 224 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("130 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";	
			s.pop_back();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = yyattribute(2 - 3).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist = yyattribute(2 - 3).ntnode->falselist;  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 371 "myparser.cpp"
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
#line 234 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("125 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();			
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 391 "myparser.cpp"
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
#line 242 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 411 "myparser.cpp"
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
#line 254 ".\\myparser.y"

			//printf("241");
			fun_name = var_name;
			// cout<<endl<<"-----------------"<<endl;
			// cout<<"241, fun_name:"<<fun_name<<endl;
		
#line 429 "myparser.cpp"
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
#line 263 ".\\myparser.y"

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
		
#line 455 "myparser.cpp"
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
#line 277 ".\\myparser.y"
	
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
			gen(newlabel(), "=#", 4, 0, offset);
			gen(newlabel(), "*", offset - 1, offset, offset + 1);
			offset++;
			gen(newlabel(), "array", 0, offset, offset + 1);
			// offset++;
		
#line 484 "myparser.cpp"
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
#line 294 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("159 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="call_fun";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			typenode* temp = search(fun_name, s.size()-1);
			if(temp->right != NULL)
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = *(temp->right);
			else{
				temp = new typenode();
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *temp;
			}
			s.pop_back();  
			if (temp->right->name != "void")
			{
				cout << "PRINTPRINT" + temp->right->name;
				gen(newlabel(), "call", -1, 0, 0);
			}
			else gen(newlabel(), "call", 0, 0, 0);
			call_fun_addr = nextinstr;
		
#line 518 "myparser.cpp"
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
#line 316 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("168 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="call_fun";
			s.pop_back();  
			call_fun_addr = nextinstr;
			vector<typenode*> v_argument_list_temp;
			typenode* type_exp = (search(fun_name, s.size()-1));
			cout<<"----------->type_exp.name"<<type_exp->name<<endl;
			cout<<"----------->type_exp->left.name"<<type_exp->left->name<<endl;
			traverse_argument(type_exp->left, v_argument_list_temp);
			for(int x=0;x<v_argument_list_temp.size();x++){
			}
			if (type_exp->right->name != "void")
			{
				cout << "PRINTPRINT" + type_exp->right->name;
				gen(newlabel(), "call", -1, 0, 0);}
			else gen(newlabel(), "call", 0, 0, 0);
			// cout<<endl;
			cout<<"parameter-------------------->"<<endl;
			for(int x=0;x<v_argument_list_temp.size();x++){
				cout<<v_argument_list_temp[x]->name<<" ";
			}
			cout<<endl;
			cout<<"argument-------------------->"<<endl;
			for(int x=0;x<v_argument_list.size();x++){
				cout<<v_argument_list[x]->name<<" ";
			}
			cout<<endl;
			int itm = 0;
			if(type_exp->name == "fun"){
				// cout<<"it is a function!!!"<<endl;
				if(v_argument_list.size()!=v_argument_list_temp.size()){
					cout<<endl<<"---------------------------------"<<endl;
					cout<<"|Argument_list doesn't matched!!|"<<endl;
					cout<<"--------------------------------"<<endl;
				}
				else{
					while(itm<v_argument_list.size()){
						if(check_type(v_argument_list[itm], v_argument_list_temp[itm]))
						{
							itm++;
						}
						else{
							cout<<endl<<"---------------------------------"<<endl;
							cout<<"|Argument_list doesn't matched!!|"<<endl;
							cout<<"----------------------------------"<<endl;
							break;
						}
					}
				}
				if(itm == v_argument_list.size()){
					// cout<<"-----------------------"<<endl;
					// cout<<"|Argument_list matched!|"<<endl;
					// cout<<"-----------------------"<<endl;
				}
				else{
					cout<<endl<<"----------------------------------"<<endl;
					cout<<"|Argument_list doesn't matched!!|"<<endl;
					cout<<"----------------------------------"<<endl;
				}
			}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *(type_exp->right);
			// cout<<"clear v_argument_list"<<endl;
			v_argument_list.clear();
		
#line 597 "myparser.cpp"
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
#line 383 ".\\myparser.y"

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
					// cout<<"struct has "<<$3.ntnode->name<<endl;
				}
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = pointer;
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = yyattribute(1 - 3).ntnode->type.addr + temp_addr;
				// cout<<"struct has ";
			} 
			else if(yyattribute(1 - 3).ntnode->type.name == "array" && yyattribute(1 - 3).ntnode->type.right->name == "record"){
				typenode pointer;
				pointer.name = "#O#O#O";
				int temp_addr;
				search_struct(yyattribute(1 - 3).ntnode->type.right, yyattribute(3 - 3).ntnode->name, pointer, temp_addr);
				if (pointer.name == "#O#O#O")
					cout << "struct doesn't have " << yyattribute(3 - 3).ntnode->name << endl;
				else{
					// cout<<"struct has "<<$3.ntnode->name<<endl;
				}
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = pointer;
			}
			else cout << "struct doesn't exist!\n";

		
		
#line 650 "myparser.cpp"
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
#line 424 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("187 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 672 "myparser.cpp"
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
#line 434 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("196 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name)){
				cout<<endl<<"--------------------------------------------------------------"<<endl;
				cout<<"|No additive calculation can be made for uncalculable types!!|"<<endl;
				cout<<"--------------------------------------------------------------"<<endl;
			}
		
#line 699 "myparser.cpp"
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
#line 449 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name)){
				cout<<endl<<"------------------------------------------"<<endl;
				cout<<"|Can't subtract from uncalculable types!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}
		
#line 726 "myparser.cpp"
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
#line 467 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("215 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			v_argument_list.push_back(&(yyattribute(1 - 1).ntnode->type));
			gen(newlabel(), "ARG", 0, 0, yyattribute(1 - 1).ntnode->type.addr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;						
		
#line 749 "myparser.cpp"
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
#line 478 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("222 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			// v_argument_list.push_back($1->type.name);
			v_argument_list.push_back(&(yyattribute(3 - 3).ntnode->type));
		
#line 774 "myparser.cpp"
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
#line 494 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("234 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 800 "myparser.cpp"
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
#line 508 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("241 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name)){
				cout<<endl<<"-------------------------------------------------------------"<<endl;
				cout<<"|No additive calculation can be made for uncalculable types!!|"<<endl;
				cout<<"--------------------------------------------------------------"<<endl;
			}															
		
#line 827 "myparser.cpp"
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
#line 523 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("249 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name)){
				cout<<endl<<"------------------------------------------"<<endl;
				cout<<"|Can't subtract from uncalculable types!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}
		
#line 854 "myparser.cpp"
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
#line 538 ".\\myparser.y"

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
				// offset += $$ -> type.width;
				offset += 1;
				//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
				if (yyattribute(1 - 2).ntnode->name == "&") {
					gen(newlabel(), "=&", yyattribute(2 - 2).ntnode->type.addr, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type.addr);
				}
				if (yyattribute(1 - 2).ntnode->name == "*") {
					gen(newlabel(), "=*", yyattribute(2 - 2).ntnode->type.addr, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type.addr);
				}
			}
		
#line 892 "myparser.cpp"
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
#line 564 ".\\myparser.y"

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
			else 
			{	
				cout<<endl<<"---------------------------------------------------"<<endl;
				cout<<"|Unknown type, unable to perform sizeof operation!!|"<<endl;
				cout<<"---------------------------------------------------"<<endl;
			}
		
#line 924 "myparser.cpp"
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
#line 584 ".\\myparser.y"

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
			else cout<<"!Unknown type, unable to perform sizeof operation!||"<<endl;
		
#line 951 "myparser.cpp"
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
#line 602 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("286 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&";
		
#line 968 "myparser.cpp"
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
#line 607 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*";
		
#line 985 "myparser.cpp"
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
#line 612 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("301 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+";
		
#line 1002 "myparser.cpp"
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
#line 617 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("308 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-";
		
#line 1019 "myparser.cpp"
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
#line 622 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("315 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="~";
		
#line 1036 "myparser.cpp"
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
#line 627 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("322 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="!";
		
#line 1053 "myparser.cpp"
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
#line 635 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("332 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1079 "myparser.cpp"
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
#line 649 ".\\myparser.y"

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
		
#line 1103 "myparser.cpp"
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
#line 664 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("352 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;	
		
#line 1125 "myparser.cpp"
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
#line 674 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("354 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name)){
				cout<<endl<<"--------------------------------------------------------"<<endl;
				cout<<"|Mismatch of Operator Types in Multiplication Operations!!|"<<endl;
				cout<<"----------------------------------------------------------"<<endl;
			}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "^", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
												
		
#line 1160 "myparser.cpp"
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
#line 697 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("359 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name)){
				cout<<endl<<"-----------------------------------------------------------"<<endl;
				cout<<"|Mismatch of Operator Types in Multiplication Operations!!|"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
			}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "*", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
												
		
#line 1195 "myparser.cpp"
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
#line 720 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("368 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{cout<<endl<<"------------------------------------------"<<endl;
				cout<<"|Divisional Operator Type Mismatch!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}				
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "/", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
			
		
#line 1230 "myparser.cpp"
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
#line 743 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("377 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
			{cout<<endl<<"------------------------------------------"<<endl;
				cout<<"|Complementation Operator Type Mismatch!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "%", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width); 
			offset += 1;
		
		
#line 1265 "myparser.cpp"
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
#line 769 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("389 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
            (*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1291 "myparser.cpp"
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
#line 783 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("396 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{cout<<endl<<"------------------------------------------"<<endl;
				cout<<"|Operator type r,  $4->type.addr>>mismatch!!|"<<endl;	
				cout<<"------------------------------------------"<<endl;}
				
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);	
			gen(newlabel(), "+", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
		
#line 1320 "myparser.cpp"
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
#line 800 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("405 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name)){
				cout<<endl<<"---------------------------"<<endl;			
				cout<<"|Operator type mismatch!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}
					
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "-", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
		
#line 1350 "myparser.cpp"
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
#line 821 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("417 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1376 "myparser.cpp"
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
#line 835 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("424 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{
				cout<<endl<<"-----------------------------------"<<endl;							
				cout<<"|Shift Operator Operator Mismatch!!|"<<endl;
				cout<<"-----------------------------------"<<endl;
			}
		
#line 1405 "myparser.cpp"
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
#line 852 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("433 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{
				cout<<endl<<"------------------------------------------"<<endl;
					cout<<"|Shift Operator Operator Mismatch!!|"<<endl;
					cout<<"------------------------------------------"<<endl;
			}
		
#line 1434 "myparser.cpp"
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
#line 872 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("445 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1460 "myparser.cpp"
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
#line 886 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("452 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{		cout<<endl<<"------------------------------------------"<<endl;
					cout<<"|Relational expression type mismatch!!|"<<endl;
					cout<<"------------------------------------------"<<endl;
					}
			gen(newlabel(), "j<", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());
			gen(nextinstr, "j");
		
#line 1492 "myparser.cpp"
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
#line 906 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("461 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{cout<<endl<<"------------------------------------------"<<endl;
					cout<<"|Relational expression type mismatch!!|"<<endl;
					cout<<"------------------------------------------"<<endl;
			}
			gen(newlabel(), "j>", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());
			gen(nextinstr, "j");
		
#line 1520 "myparser.cpp"
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
#line 922 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("470 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{		cout<<endl<<"------------------------------------------"<<endl;
					cout<<"|Relational expression type mismatch!!|"<<endl;
					cout<<"------------------------------------------"<<endl;
			}					

			gen(newlabel(), "j>", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(newlabel());
			gen(nextinstr, "j"); 
		
#line 1553 "myparser.cpp"
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
#line 943 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("479 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
			{
					cout<<"------------------------------------------"<<endl;			
					cout<<"|Relational expression type mismatch!!|"<<endl;
					cout<<"------------------------------------------"<<endl;
			}
			gen(newlabel(), "j<", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(newlabel());
			gen(nextinstr, "j");
		
#line 1586 "myparser.cpp"
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
#line 967 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("491 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1612 "myparser.cpp"
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
#line 981 ".\\myparser.y"

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
			{cout<<endl<<"------------------------------------------"<<endl;
					cout<<"|Relational expression type mismatch!!|"<<endl;
					cout<<"------------------------------------------"<<endl;
					}
			gen(newlabel(), "j=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr);  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());       
			gen(nextinstr, "j"); 
		
#line 1645 "myparser.cpp"
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
#line 1002 ".\\myparser.y"

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
			{cout<<"------------------------------------------"<<endl;
				cout<<"|Relational expression type mismatch!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}
			
			int nextinstr = newlabel();
			gen(nextinstr, "j=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr);  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			nextinstr = newlabel();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr);    
			gen(nextinstr, "j"); 
		
#line 1681 "myparser.cpp"
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
#line 1029 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("519 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1707 "myparser.cpp"
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
#line 1043 ".\\myparser.y"

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
{cout<<"------------------------------------------"<<endl;			
					cout<<"|Intersection Operator Type Mismatch!!|"<<endl;
cout<<"------------------------------------------"<<endl;}					
		
#line 1735 "myparser.cpp"
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
#line 1062 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("538 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1761 "myparser.cpp"
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
#line 1076 ".\\myparser.y"

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
			{cout<<"------------------------------------------"<<endl;
			cout<<"|Intersection Operator Type Mismatch!!|"<<endl;
			cout<<"------------------------------------------"<<endl;}
					
		
#line 1790 "myparser.cpp"
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
#line 1096 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("557 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1816 "myparser.cpp"
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
#line 1110 ".\\myparser.y"

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
			{cout<<"------------------------------------------"<<endl;
			cout<<"|Or operation left-right operand type mismatch!!| "<<endl;
			cout<<"------------------------------------------"<<endl;}
					
		
#line 1845 "myparser.cpp"
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
#line 1130 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("576 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1871 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1144 ".\\myparser.y"

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
		
#line 1898 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#line 1161 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("584 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="M";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->instr = nextinstr + 1;
		
#line 1911 "myparser.cpp"
		}
		break;
	case 59:
		{
#line 1170 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("585 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist->push_back(nextinstr + 1);
			gen(nextinstr+1, "j");
		
#line 1923 "myparser.cpp"
		}
		break;
	case 60:
		{
#line 1178 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("586 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist->push_back(newlabel());
			gen(nextinstr, "j");
		
#line 1935 "myparser.cpp"
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1188 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("595 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 1961 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1203 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("602 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;
			backpatch(yyattribute(1 - 4).ntnode->falselist, yyattribute(3 - 4).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = merge(yyattribute(1 - 4).ntnode->truelist, yyattribute(4 - 4).ntnode->truelist);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(4 - 4).ntnode->falselist;
		
#line 1983 "myparser.cpp"
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
#line 1216 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("614 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
			 
		
#line 2010 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1231 ".\\myparser.y"

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
				// cout<<"------\n";
				// cout<<"|match|\n";
				// cout<<"------\n";
			}	
			else{
				cout<<"-----------------"<<endl;
				cout<<"|type mismatch!!|"<<endl;
				cout<<"-----------------"<<endl;
			}			
		
#line 2044 "myparser.cpp"
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
#line 1256 ".\\myparser.y"

			//(1)谓词表达式
			//(2)条件表达式 a<b?a:b
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("635 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			//(1)???????
			//(2)???????? a<b?a:b
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 2069 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1269 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("642 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
			  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(3 - 3).ntnode->type;
			if (check_type(&yyattribute(1 - 3).ntnode->type, &yyattribute(3 - 3).ntnode->type)){
				// cout<<"----------------"<<endl;
				// cout<<"|Two sides equal|"<<endl;
				// cout<<"----------------"<<endl;
			}	
			else{
				cout<<"-------------------------"<<endl;
				cout<<"| two sides don't match!!|"<<endl;
				cout<<"-------------------------"<<endl;
			}
			gen(newlabel(), yyattribute(2 - 3).ntnode->name, yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, yyattribute(1 - 3).ntnode->type.addr);

			
#line 2101 "myparser.cpp"
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
#line 1292 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("654 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2121 "myparser.cpp"
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
#line 1300 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("661 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2141 "myparser.cpp"
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
#line 1308 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("668 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="/=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2161 "myparser.cpp"
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
#line 1316 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("675 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="%=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2181 "myparser.cpp"
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
#line 1324 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("682 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2201 "myparser.cpp"
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
#line 1332 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2221 "myparser.cpp"
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
#line 1340 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("696 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="<<=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2241 "myparser.cpp"
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
#line 1348 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("703 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name=">>=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2261 "myparser.cpp"
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
#line 1356 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("710 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2281 "myparser.cpp"
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
#line 1364 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("717 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="^=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2301 "myparser.cpp"
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
#line 1372 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("724 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="|=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2321 "myparser.cpp"
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
#line 1383 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("740 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 2345 "myparser.cpp"
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
#line 1395 ".\\myparser.y"

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
		
#line 2370 "myparser.cpp"
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
#line 1411 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("753 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		
#line 2392 "myparser.cpp"
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
#line 1424 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("763 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
		
#line 2413 "myparser.cpp"
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
#line 1433 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("771 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;		
		
#line 2437 "myparser.cpp"
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
#line 1451 ".\\myparser.y"
 //static
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("783 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
#line 2458 "myparser.cpp"
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
#line 1461 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("791 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2480 "myparser.cpp"
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
#line 1471 ".\\myparser.y"
 // int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("799 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=*rFlag();
			// cout<<"[799: $$->type:]"<<$$->type.name<<endl;
		
#line 2502 "myparser.cpp"
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
#line 1481 ".\\myparser.y"
 // lont int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("806 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2524 "myparser.cpp"
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
#line 1491 ".\\myparser.y"
 //const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("814 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;	
		
#line 2545 "myparser.cpp"
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
#line 1500 ".\\myparser.y"
 //const int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("821 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
#line 2567 "myparser.cpp"
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
#line 1513 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("832 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		
#line 2589 "myparser.cpp"
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
#line 1523 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
		
#line 2611 "myparser.cpp"
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
#line 1536 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("851 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 2631 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1544 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("858 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			if (yyattribute(3 - 3).ntnode -> name == "call_fun") {
				code[call_fun_addr][1] = "1"; 								
			}

			traverse_vartable(s.size()-1);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			vector<string> v1;
			vector<string> v2;
			compare_traverse(&(yyattribute(1 - 3).ntnode->type), v1);
			compare_traverse(&(yyattribute(3 - 3).ntnode->type), v2);
			show_string(v1);
			show_string(v2);
			// cout<<"*************858$3->type.name"<<$3->type.name<<endl;
			// cout<<"*************858$1->type.name"<<$1->type.name<<endl;
			if (check_type(&(yyattribute(1 - 3).ntnode->type), &(yyattribute(3 - 3).ntnode->type))){
				// cout<<"--------"<<endl;
				// cout<<"|match!|"<<endl;
				// cout<<"--------"<<endl;
			}
			else{
				// cout<<"-----"<<$1->type.name<<"------"<<endl;
				cout<<endl<<"-----------------"<<endl;
				cout<<"|" + yyattribute(1 - 3).ntnode->type.name + " cannot match " + yyattribute(3 - 3).ntnode->type.name + "!!|"<<endl;
				// cout<<"-----"<<$3->type.name<<"------"<<endl;
				cout<<"-----------------"<<endl;
			}
			gen(newlabel(), "=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, yyattribute(1 - 3).ntnode->type.addr);
		
#line 2681 "myparser.cpp"
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
#line 1585 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("870 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;			
		
#line 2701 "myparser.cpp"
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
#line 1593 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("877 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2721 "myparser.cpp"
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
#line 1601 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("884 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2741 "myparser.cpp"
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
#line 1609 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 2761 "myparser.cpp"
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
#line 1617 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("898 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 2781 "myparser.cpp"
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
#line 1628 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			wFlag(voidnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=voidnode;
		
#line 2803 "myparser.cpp"
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
#line 1638 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("915 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(charnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=charnode;
		
#line 2825 "myparser.cpp"
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
#line 1648 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("922 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(shortnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=shortnode;
		
#line 2847 "myparser.cpp"
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
#line 1658 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("929 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(intnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=intnode;
		
#line 2869 "myparser.cpp"
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
#line 1668 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("936 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(longnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=longnode;
		
#line 2891 "myparser.cpp"
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
#line 1678 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("943 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(floatnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=floatnode;
		
#line 2913 "myparser.cpp"
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
#line 1688 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("950 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(doublenode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=doublenode;
		
#line 2935 "myparser.cpp"
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
#line 1698 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("957 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(signednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=signednode;
		
#line 2957 "myparser.cpp"
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
#line 1708 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(unsignednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=unsignednode;
		
#line 2979 "myparser.cpp"
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
#line 1718 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			wFlag(yyattribute(1 - 1).ntnode->type);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = yyattribute(1 - 1).ntnode -> type;

		
#line 3003 "myparser.cpp"
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
#line 1730 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("978 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 3023 "myparser.cpp"
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
#line 1738 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("985 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
#line 3043 "myparser.cpp"
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
#line 1746 ".\\myparser.y"

		
#line 3057 "myparser.cpp"
			}
		}
		break;
	case 111:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 1751 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("986 ");
			wFlag(*(create_struct(yyattribute(2 - 5).ntnode->name)));
		
#line 3074 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 1757 ".\\myparser.y"

			static int i = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("987 ");
			wFlag(*(create_struct("struct" + to_string(i))));
			s.back()->vartable["struct" + to_string(i++)] = rFlag();
		
#line 3093 "myparser.cpp"
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
#line 1766 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("988 ");
		
#line 3109 "myparser.cpp"
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
#line 1770 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("989 ");
		
#line 3125 "myparser.cpp"
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
#line 1776 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("990 ");
		
#line 3141 "myparser.cpp"
			}
		}
		break;
	case 116:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1780 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("991 ");
			
			map<string, typenode*>::iterator i;
			if ((i = auto_define_type.find(yyattribute(2 - 2).ntnode->name)) != auto_define_type.end())
			{
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *auto_define_type[yyattribute(2 - 2).ntnode->name];
			}
			else cout << "struct doesn't exist!\n";
		
#line 3164 "myparser.cpp"
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
#line 1869 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1027 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3184 "myparser.cpp"
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
#line 1877 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1034 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3204 "myparser.cpp"
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
#line 1888 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1044 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 3224 "myparser.cpp"
			}
		}
		break;
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1896 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1051 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
		
#line 3245 "myparser.cpp"
			}
		}
		break;
	case 121:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 1908 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1062 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3267 "myparser.cpp"
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
#line 1918 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1062 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3289 "myparser.cpp"
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
#line 1931 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1074 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3310 "myparser.cpp"
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
#line 1940 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1082 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3330 "myparser.cpp"
			}
		}
		break;
	case 125:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1948 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1089 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3351 "myparser.cpp"
			}
		}
		break;
	case 126:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 1957 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1097 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3371 "myparser.cpp"
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
#line 1968 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1107 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3391 "myparser.cpp"
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
#line 1976 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1114 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3413 "myparser.cpp"
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
#line 1989 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3433 "myparser.cpp"
			}
		}
		break;
	case 130:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 1997 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1133 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3454 "myparser.cpp"
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
#line 2006 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1141 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3476 "myparser.cpp"
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
#line 2019 ".\\myparser.y"
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
		
#line 3499 "myparser.cpp"
			}
		}
		break;
	case 133:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2030 ".\\myparser.y"
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
		
#line 3523 "myparser.cpp"
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
#line 2042 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1174 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
#line 3544 "myparser.cpp"
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
#line 2054 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1185 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3564 "myparser.cpp"
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
#line 2062 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1192 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		
#line 3582 "myparser.cpp"
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
#line 2071 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3602 "myparser.cpp"
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
#line 2079 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1211 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3624 "myparser.cpp"
			}
		}
		break;
	case 139:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2092 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1223 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3644 "myparser.cpp"
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
#line 2100 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1230 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
#line 3664 "myparser.cpp"
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
#line 2111 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1240 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		
#line 3682 "myparser.cpp"
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
#line 2117 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1248 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
#line 3703 "myparser.cpp"
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
#line 2128 ".\\myparser.y"

			//printf("8521");
			fun_name2 = var_name;
			// cout<<endl<<"-------------------"<<endl;
			// cout<<"8521 fun_name2:"<<fun_name2<<endl;
			fun_addr = yyattribute(1 - 2).ntnode->type.addr;
		
#line 3722 "myparser.cpp"
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
#line 2138 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1258 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			var_name = yyattribute(1 - 1).ntnode->name;
			//gen(newlabel(), "DEC", $1.ntnode->type.width, 0, $1.ntnode->type.addr);
			//cout << $1.ntnode->name << rFlag()->width << endl;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			int temp = yyattribute(1 - 1).ntnode->type.addr;
			yyattribute(1 - 1).ntnode->type = *rFlag();
			yyattribute(1 - 1).ntnode->type.addr = temp;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
		    var_set.insert(yyattribute(1 - 1).ntnode->type.addr);
			// offset += rFlag()->width;
			offset += 1;
			//gen(newlabel(), "DEC", $1.ntnode->type.width, 0, $1.ntnode->type.addr);
		
#line 3752 "myparser.cpp"
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
#line 2156 ".\\myparser.y"

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
		
#line 3776 "myparser.cpp"
			}
		}
		break;
	case 146:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2168 ".\\myparser.y"

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
			int tmp = yyattribute(1 - 4).ntnode->type.addr;
			rFlag()->addr = tmp;
			s.back()->vartable[var_name] = rFlag();
			// var_set.insert(var_name);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			yyattribute(1 - 4).ntnode->type = *rFlag();
			// offset += rFlag()->width;
			offset += 1;
			gen(newlabel(), "=#", 4, 0, offset - 1);
			gen(newlabel(), "*", offset - 1, offset - 2, offset);
			offset++;
			gen(newlabel(), "DEC", offset - 1, 0, offset);
			offset++;
			//traverse(root);
		
#line 3833 "myparser.cpp"
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
#line 2213 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1284 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 3855 "myparser.cpp"
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
#line 2223 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		
#line 3874 "myparser.cpp"
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
#line 2230 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1303 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}	
			s.pop_back();  
		
#line 3897 "myparser.cpp"
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
#line 2241 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1313 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			fun_name2 = var_name;
			// cout<<endl<<"----------------------"<<endl;
			// cout<<"1313->fun_name2:"<<fun_name2<<endl;
			gen(newlabel(), "fun", 0, 0, 0);
		
#line 3920 "myparser.cpp"
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
#line 2255 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1325 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			typenode* temp = new typenode("pointer");
			temp->left=rFlag();
			temp->width = 4;
			// cout<<"1325: temp->name:"<<temp->name<<endl;
			flag = !flag;
			wFlag(*temp);
			// cout<<"1325-->"<<endl;						
			// traverse(temp);
		
#line 3949 "myparser.cpp"
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
#line 2272 ".\\myparser.y"
 // *const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 3969 "myparser.cpp"
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
#line 2280 ".\\myparser.y"
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
		
#line 3995 "myparser.cpp"
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
#line 2294 ".\\myparser.y"
 //*const*
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		
#line 4015 "myparser.cpp"
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
#line 2305 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1359 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4035 "myparser.cpp"
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
#line 2313 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1366 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4056 "myparser.cpp"
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
#line 2326 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1378 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			type3->left = rFlag();
			// cout<<"[1378:type3->left]"<<type3->left->name<<endl;
			// traverse(type3->left);

			gen(newlabel(), "fun", 0, 0, 0);
		
#line 4082 "myparser.cpp"
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
#line 2340 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1385 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4104 "myparser.cpp"
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
#line 2353 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1397 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4124 "myparser.cpp"
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
#line 2361 ".\\myparser.y"

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
			// cout<<"1404"<<endl<<"rFlag()"<<temp->left->name<<endl;
			flag = !flag;
			temp->right = rFlag();
			wFlag(*temp);
		
#line 4153 "myparser.cpp"
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
#line 2381 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1416 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			gen(newlabel(), "param", 0, 0, yyattribute(2 - 2).ntnode -> type.addr);
		
#line 4175 "myparser.cpp"
			}
		}
		break;
	case 162:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2391 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1424 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4195 "myparser.cpp"
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
#line 2399 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1431 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4215 "myparser.cpp"
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
#line 2410 ".\\myparser.y"
	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1441 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			int tmp = yyattribute(1 - 1).ntnode->type.addr;
			rFlag()->addr = tmp;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
            var_set.insert(yyattribute(1 - 1).ntnode->type.addr);
			// offset += rFlag()->width;
			offset += 1;
			yyattribute(1 - 1).ntnode->type = *rFlag();
			//gen(newlabel(), "DEC", $1.ntnode->type.width, 0, $1.ntnode->type.addr);
		
#line 4243 "myparser.cpp"
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
#line 2426 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1448 ");   
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			int tmp = yyattribute(3 - 3).ntnode->type.addr;
			rFlag()->addr = tmp;
			s.back()->vartable[yyattribute(3 - 3).ntnode->name] = rFlag();	
			var_set.insert(yyattribute(3 - 3).ntnode->type.addr);
			// offset += rFlag()->width;
			offset += 1;
			yyattribute(3 - 3).ntnode->type = *rFlag();
			//gen(newlabel(), "DEC", $3.ntnode->type.width, 0, $3.ntnode->type.addr);
		
#line 4273 "myparser.cpp"
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
#line 2447 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1460 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4293 "myparser.cpp"
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
#line 2455 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1467 ");  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4314 "myparser.cpp"
			}
		}
		break;
	case 168:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2467 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1478 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4334 "myparser.cpp"
			}
		}
		break;
	case 169:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2475 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1485 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4354 "myparser.cpp"
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
#line 2483 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1492 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4375 "myparser.cpp"
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
#line 2495 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1503 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4398 "myparser.cpp"
			}
		}
		break;
	case 172:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2506 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1512 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4419 "myparser.cpp"
			}
		}
		break;
	case 173:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2515 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1520 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4441 "myparser.cpp"
			}
		}
		break;
	case 174:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2525 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1529 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4463 "myparser.cpp"
			}
		}
		break;
	case 175:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2535 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1538 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
#line 4486 "myparser.cpp"
			}
		}
		break;
	case 176:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 2546 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1548 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			s.pop_back();  
		
#line 4508 "myparser.cpp"
			}
		}
		break;
	case 177:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2556 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1556 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4531 "myparser.cpp"
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
#line 2567 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1565 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
#line 4554 "myparser.cpp"
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
#line 2578 ".\\myparser.y"

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
		
#line 4578 "myparser.cpp"
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
#line 2593 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1587 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
#line 4600 "myparser.cpp"
			}
		}
		break;
	case 181:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2603 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1594 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4622 "myparser.cpp"
			}
		}
		break;
	case 182:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2613 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1603 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
#line 4645 "myparser.cpp"
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
#line 2627 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1616 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 4665 "myparser.cpp"
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
#line 2635 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1623 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4687 "myparser.cpp"
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
#line 2647 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1635 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(1 - 1).ntnode->nextlist;
			// cout << $1->nextlist->size() << "???????????????" << endl;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> truelist = yyattribute(1 - 1).ntnode -> truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> falselist = yyattribute(1 - 1).ntnode -> falselist;
			traverse_vartable(s.size()-1);
		
#line 4709 "myparser.cpp"
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
#line 2657 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1636 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 1).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 4727 "myparser.cpp"
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
#line 2663 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1637 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 4745 "myparser.cpp"
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
#line 2669 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1638 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 4763 "myparser.cpp"
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
#line 2677 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1644 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
#line 4785 "myparser.cpp"
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
#line 2687 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1669 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "xx";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(1 - 1).ntnode->nextlist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> truelist = yyattribute(1 - 1).ntnode -> truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> falselist = yyattribute(1 - 1).ntnode -> falselist;
		
#line 4805 "myparser.cpp"
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
#line 2695 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1670 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 4823 "myparser.cpp"
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
#line 2703 ".\\myparser.y"

		
	
#line 4838 "myparser.cpp"
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
#line 2707 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1680 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 4860 "myparser.cpp"
			}
		}
		break;
	case 194:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 2717 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
#line 4877 "myparser.cpp"
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
#line 2722 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1699 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
#line 4894 "myparser.cpp"
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
#line 2730 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1711 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 4915 "myparser.cpp"
			}
		}
		break;
	case 197:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2739 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1719 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> truelist = yyattribute(2 - 3).ntnode -> truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> falselist = yyattribute(2 - 3).ntnode -> falselist;
		
#line 4935 "myparser.cpp"
			}
		}
		break;
	case 198:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2747 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1728 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 4953 "myparser.cpp"
			}
		}
		break;
	case 199:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2753 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1737 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist= yyattribute(3 - 4).ntnode->nextlist ;
		
#line 4971 "myparser.cpp"
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
#line 2762 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1750 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
#line 4993 "myparser.cpp"
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
#line 2772 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1757 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =yyattribute(3 - 3).ntnode->nextlist; 
		
#line 5012 "myparser.cpp"
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
#line 2782 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1768 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 5033 "myparser.cpp"
			}
		}
		break;
	case 203:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 2791 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			// cout<<"$2->instr:"<<$2->instr<<endl;
			//printf("1775 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			cout << "--------------============";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(3 - 3).ntnode->nextlist; 
		
#line 5054 "myparser.cpp"
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
#line 2803 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1786 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5074 "myparser.cpp"
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
#line 2811 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1793 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name = yyattribute(1 - 2).ntnode->name;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(1 - 2).ntnode->nextlist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> falselist = yyattribute(1 - 2).ntnode -> falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> truelist = yyattribute(1 - 2).ntnode -> truelist; 
		
#line 5098 "myparser.cpp"
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
#line 2825 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1794 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 5120 "myparser.cpp"
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
#line 2835 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(); 
			//printf("1795 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 5141 "myparser.cpp"
			}
		}
		break;
	case 208:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 2846 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1803 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
			s.pop_back();
			traverse_vartable(s.size() - 1);	 					
		
#line 5163 "myparser.cpp"
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
#line 2856 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1815 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			traverse_vartable(s.size() - 1);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type; 
		
#line 5185 "myparser.cpp"
			}
		}
		break;
	case 210:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 2868 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1816 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(6 - 7).ntnode->type;
			s.pop_back();
			//traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 7).ntnode->truelist, yyattribute(5 - 7).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =merge(yyattribute(3 - 7).ntnode->falselist, yyattribute(7 - 7).ntnode->nextlist); 
		
#line 5207 "myparser.cpp"
			}
		}
		break;
	case 211:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 2878 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1817 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			s.pop_back();
			traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
		
#line 5229 "myparser.cpp"
			}
		}
		break;
	case 212:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 2890 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1818 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 5250 "myparser.cpp"
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
#line 2899 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1825 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			s.pop_back();  
		
#line 5268 "myparser.cpp"
			}
		}
		break;
	case 214:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 2907 ".\\myparser.y"

		    // $$->type = $3->type;
			// offset += $$->type.width;
			// switch_addr = $$->type.addr;			
			// gen(newlabel(), "=", $$->type.addr, 0, $3->type.addr);
			// default_label=newlabel();
			// gen(nextinstr,"j",0,0,default_label);
	
#line 5288 "myparser.cpp"
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
#line 2917 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(4 - 7).ntnode->truelist, yyattribute(6 - 7).ntnode->instr); 
			backpatch(yyattribute(7 - 7).ntnode->nextlist, yyattribute(2 - 7).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(4 - 7).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(2 - 7).ntnode->instr) ; 
			cout << yyattribute(2 - 7).ntnode->instr << "@";
			// s.pop_back();
			traverse_vartable(s.size()-1);
			s.pop_back(); 
			s.pop_back();
			traverse_vartable(s.size()-1);
		
#line 5315 "myparser.cpp"
			}
		}
		break;
	case 216:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 2932 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1850 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(7 - 9).ntnode->truelist, yyattribute(2 - 9).ntnode->instr); 
			backpatch(yyattribute(3 - 9).ntnode->nextlist, yyattribute(5 - 9).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(7 - 9).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(5 - 9).ntnode->instr) ; 
			cout<<"WHILE"<<endl;
			traverse_vartable(s.size()-1);
			s.pop_back(); 
			s.pop_back();
			traverse_vartable(s.size()-1);
		
#line 5341 "myparser.cpp"
			}
		}
		break;
	case 217:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 2946 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1863 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}
			backpatch(yyattribute(5 - 8).ntnode->truelist, yyattribute(8 - 8).ntnode->instr);
			// backpatch($8->nextlist, $5->instr);
			gen(newlabel(), "j", 0, 0, yyattribute(4 - 8).ntnode->instr);
			yyattribute(8 - 8).ntnode->nextlist = makelist(yyattribute(5 - 8).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=yyattribute(5 - 8).ntnode->falselist;
			s.pop_back();		  
		
#line 5368 "myparser.cpp"
			}
		}
		break;
	case 218:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[12];
			yyinitdebug((void YYFAR**)yya, 12);
#endif
			{
#line 2961 ".\\myparser.y"

			
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1875 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(5 - 11).ntnode->truelist, yyattribute(10 - 11).ntnode->instr);
			// backpatch($10->nextlist, $6->instr);
			gen(newlabel(), "j", 0, 0, yyattribute(6 - 11).ntnode->instr);
			yyattribute(10 - 11).ntnode->nextlist = makelist(yyattribute(6 - 11).ntnode->instr);
			backpatch(yyattribute(8 - 11).ntnode->nextlist, yyattribute(4 - 11).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist= yyattribute(5 - 11).ntnode->falselist;
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++)
			{
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}
			cout<<"FOR"<<endl;
			traverse_vartable(s.size()-1);
			s.pop_back();
			s.pop_back();
			traverse_vartable(s.size()-1);
		
#line 5402 "myparser.cpp"
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
#line 2987 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
#line 5424 "myparser.cpp"
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
#line 2997 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1900 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 5445 "myparser.cpp"
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
#line 3006 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 5466 "myparser.cpp"
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
#line 3015 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1916 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			rtn_stmt.push(&voidnode);		
		
#line 5488 "myparser.cpp"
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
#line 3025 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1924 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;	
			rtn_stmt.push(&(yyattribute(2 - 3).ntnode->type));
			gen(newlabel(), "RETURN", 0, 0, yyattribute(2 - 3).ntnode->type.addr);
		
#line 5512 "myparser.cpp"
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
#line 3040 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1946 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5532 "myparser.cpp"
			}
		}
		break;
	case 225:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 3048 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1953 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
#line 5553 "myparser.cpp"
			}
		}
		break;
	case 226:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 3060 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5573 "myparser.cpp"
			}
		}
		break;
	case 227:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 3068 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
#line 5593 "myparser.cpp"
			}
		}
		break;
	case 228:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 3079 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1981 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			type3->right = &(yyattribute(1 - 4).ntnode->type);
			//cout<<"$$$$$$$$$$$$$$$$$$$type3:"<<type3<<endl;
			s.back()->vartable[fun_name2] = type3;
			// var_set.insert(fun_name);
			//gen(newlabel(), "DEC", -1, 0, fun_addr);
			if (rtn_stmt.size() == 0 && type3->right->name !="void" ){
				cout<<endl<<"-----------------------"<<endl;
				cout<<"|must return a value!!|"<<endl;
				cout<<"-----------------------"<<endl;
			}
			while(rtn_stmt.size()>0){ 
			typenode *a = rtn_stmt.top();
			//cout<<"stack top"<<a->name<<endl;
			if(!check_type(a,&(yyattribute(1 - 4).ntnode->type)))
			{
				cout<<a->name+"mismatches with "
				+yyattribute(1 - 4).ntnode->type.name<<endl;
			}
			rtn_stmt.pop();
			}	
			s.pop_back();
		
#line 5631 "myparser.cpp"
			}
		}
		break;
	case 229:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 3105 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("1991 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> nextlist = yyattribute(3 - 3).ntnode -> nextlist;

			
			type3->right = &(yyattribute(1 - 3).ntnode->type);
			// cout<<"[1991:type3->right]:"<<$1->type.name<<endl;
			// cout<<"fun_name------------>"<<fun_name<<endl;
			
			// var_set.insert(fun_name);
			// cout<<endl<<"---------------type3"<<type3->name<<endl;
			// cout<<"----------------fun_name2"<<fun_name2<<endl;
			// cout<<"6666666666666"<<endl;
			s[s.size()-2]->vartable[fun_name2] = type3;
			//s.back()->vartable[fun_name] = type3;
			
			//cout<<"/./././././././"<<fun_addr<<endl;
			//gen(newlabel(), "DEC", -1, 0, fun_addr);

			if (rtn_stmt.size() == 0 && type3->right->name != "void"){
				cout<<endl<<"-----------------------"<<endl;
				cout<<"|must return a value!!|"<<endl;
				cout<<"-----------------------"<<endl;
			}
			while(rtn_stmt.size()>0){
				typenode *a = rtn_stmt.top();
				if(!check_type(a,&(yyattribute(1 - 3).ntnode->type)))
				{
					if(yyattribute(1 - 3).ntnode->type.name == "void"){
						cout<<endl<<"-------------------------------"<<endl;
						cout<<"|cannot return " + a->name + " to void!!|"<<endl;
						cout<<"-------------------------------"<<endl;
					}
					else{
						cout<<endl<<"-------------------------------"<<endl;						
						cout<<"|must return " + yyattribute(1 - 3).ntnode->type.name + ", not " + a->name + "!!|"<<endl;
						cout<<"-------------------------------"<<endl;						
					}
				}
				rtn_stmt.pop();
			}
			s.pop_back();	
			traverse_vartable(s.size()-1);	
		
#line 5689 "myparser.cpp"
			}
		}
		break;
	case 230:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 3151 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("2000 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			type3->right = &(yyattribute(1 - 3).ntnode->type);
			s.back()->vartable[fun_name2] = type3;
			// var_set.insert(fun_name);
			// cout<<"/./././././././"<<fun_addr<<endl;
			//gen(newlabel(), "DEC", -1, 0, fun_addr);
			if (rtn_stmt.size() == 0 && type3->right->name != "void"){
				cout<<endl<<"------------------------------------------"<<endl;
				cout<<"|must return a value " + type3->right->name+"!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}		
			while(rtn_stmt.size()>0){
			typenode *a = rtn_stmt.top();
			if(!check_type(a,&(yyattribute(1 - 3).ntnode->type)))
			{cout<<"------------------"<<endl;
				cout<<"|type error!!|"<<endl;
				cout<<"--------------"<<endl;
			}
			rtn_stmt.pop();
			}	
			s.pop_back();
		
#line 5731 "myparser.cpp"
			}
		}
		break;
	case 231:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 3181 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//printf("2009 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			type3->right = &(yyattribute(1 - 2).ntnode->type);
			s.back()->vartable[fun_name2] = type3;
			// var_set.insert(fun_name);
			//gen(newlabel(), "DEC", -1, 0, fun_addr);
			if (rtn_stmt.size() == 0 && type3->right->name != "void"){
				cout<<endl<<"------------------------------------------"<<endl;
				cout<<"|must return a value " + type3->right->name+"!!|"<<endl;
				cout<<"------------------------------------------"<<endl;
			}	
			while(rtn_stmt.size()>0){
			typenode *a = rtn_stmt.top();
			if(!check_type(a,&(yyattribute(1 - 2).ntnode->type)))
			{
				cout<<"--------------"<<endl;
				cout<<"|type error!!|"<<endl;
				cout<<"--------------"<<endl;
			}
			rtn_stmt.pop();
			}	
			s.pop_back();
		
#line 5772 "myparser.cpp"
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
		"multiplicative_exp: multiplicative_exp \'^\' cast_exp",
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
		"P:",
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
		"matched_statement: IF \'(\' exp \')\' M matched_statement P ELSE M matched_statement",
		"matched_statement: other",
		"open_statement: IF \'(\' exp \')\' M stmt P",
		"open_statement: IF \'(\' exp \')\' M matched_statement P ELSE M open_statement",
		"selection_statement: stmt",
		"selection_statement: switch_pre statement",
		"switch_pre: SWITCH \'(\' exp \')\'",
		"iteration_statement: WHILE M \'(\' exp \')\' M statement",
		"iteration_statement: DO M statement WHILE M \'(\' exp \')\' \';\'",
		"iteration_statement: FOR \'(\' exp_statement M exp_statement \')\' M statement",
		"iteration_statement: FOR \'(\' exp_statement M exp_statement M exp P \')\' M statement",
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
		{ 8, 3, 35 },
		{ 9, 1, 36 },
		{ 9, 3, 37 },
		{ 9, 3, 38 },
		{ 10, 1, 39 },
		{ 10, 3, 40 },
		{ 10, 3, 41 },
		{ 11, 1, 42 },
		{ 11, 3, 43 },
		{ 11, 3, 44 },
		{ 11, 3, 45 },
		{ 11, 3, 46 },
		{ 12, 1, 47 },
		{ 12, 3, 48 },
		{ 12, 3, 49 },
		{ 13, 1, 50 },
		{ 13, 3, 51 },
		{ 14, 1, 52 },
		{ 14, 3, 53 },
		{ 15, 1, 54 },
		{ 15, 3, 55 },
		{ 16, 1, 56 },
		{ 16, 4, 57 },
		{ 17, 0, 58 },
		{ 18, 0, 59 },
		{ 19, 0, 60 },
		{ 20, 1, 61 },
		{ 20, 4, 62 },
		{ 21, 1, 63 },
		{ 21, 5, 64 },
		{ 22, 1, 65 },
		{ 22, 3, 66 },
		{ 23, 1, 67 },
		{ 23, 1, 68 },
		{ 23, 1, 69 },
		{ 23, 1, 70 },
		{ 23, 1, 71 },
		{ 23, 1, 72 },
		{ 23, 1, 73 },
		{ 23, 1, 74 },
		{ 23, 1, 75 },
		{ 23, 1, 76 },
		{ 23, 1, 77 },
		{ 24, 1, 78 },
		{ 24, 3, 79 },
		{ 25, 1, 80 },
		{ 26, 2, 81 },
		{ 26, 3, 82 },
		{ 27, 1, 83 },
		{ 27, 2, 84 },
		{ 27, 1, 85 },
		{ 27, 2, 86 },
		{ 27, 1, 87 },
		{ 27, 2, 88 },
		{ 28, 1, 89 },
		{ 28, 3, 90 },
		{ 29, 1, 91 },
		{ 29, 3, 92 },
		{ 30, 1, 93 },
		{ 30, 1, 94 },
		{ 30, 1, 95 },
		{ 30, 1, 96 },
		{ 30, 1, 97 },
		{ 31, 1, 98 },
		{ 31, 1, 99 },
		{ 31, 1, 100 },
		{ 31, 1, 101 },
		{ 31, 1, 102 },
		{ 31, 1, 103 },
		{ 31, 1, 104 },
		{ 31, 1, 105 },
		{ 31, 1, 106 },
		{ 31, 1, 107 },
		{ 31, 1, 108 },
		{ 31, 1, 109 },
		{ 31, 2, 110 },
		{ 32, 5, 111 },
		{ 32, 4, 112 },
		{ 33, 1, 113 },
		{ 33, 2, 114 },
		{ 34, 2, 115 },
		{ 34, 2, 116 },
		{ 35, 1, 117 },
		{ 35, 1, 118 },
		{ 36, 1, 119 },
		{ 36, 2, 120 },
		{ 37, 3, 121 },
		{ 37, 3, 122 },
		{ 38, 2, 123 },
		{ 38, 1, 124 },
		{ 38, 2, 125 },
		{ 38, 1, 126 },
		{ 39, 1, 127 },
		{ 39, 3, 128 },
		{ 40, 1, 129 },
		{ 40, 2, 130 },
		{ 40, 3, 131 },
		{ 41, 4, 132 },
		{ 41, 5, 133 },
		{ 41, 2, 134 },
		{ 42, 1, 135 },
		{ 42, 3, 136 },
		{ 43, 1, 137 },
		{ 43, 3, 138 },
		{ 44, 1, 139 },
		{ 44, 1, 140 },
		{ 45, 2, 141 },
		{ 45, 1, 142 },
		{ 46, 2, 143 },
		{ 47, 1, 144 },
		{ 47, 3, 145 },
		{ 47, 4, 146 },
		{ 47, 3, 147 },
		{ 47, 3, 148 },
		{ 47, 3, 149 },
		{ 47, 2, 150 },
		{ 48, 1, 151 },
		{ 48, 2, 152 },
		{ 48, 2, 153 },
		{ 48, 3, 154 },
		{ 49, 1, 155 },
		{ 49, 2, 156 },
		{ 50, 1, 157 },
		{ 50, 3, 158 },
		{ 51, 1, 159 },
		{ 51, 3, 160 },
		{ 52, 2, 161 },
		{ 52, 2, 162 },
		{ 52, 1, 163 },
		{ 53, 1, 164 },
		{ 53, 3, 165 },
		{ 54, 1, 166 },
		{ 54, 2, 167 },
		{ 55, 1, 168 },
		{ 55, 1, 169 },
		{ 55, 2, 170 },
		{ 56, 3, 171 },
		{ 56, 2, 172 },
		{ 56, 3, 173 },
		{ 56, 3, 174 },
		{ 56, 4, 175 },
		{ 56, 2, 176 },
		{ 56, 3, 177 },
		{ 56, 3, 178 },
		{ 56, 4, 179 },
		{ 57, 1, 180 },
		{ 57, 3, 181 },
		{ 57, 4, 182 },
		{ 58, 1, 183 },
		{ 58, 3, 184 },
		{ 59, 1, 185 },
		{ 59, 1, 186 },
		{ 59, 1, 187 },
		{ 59, 1, 188 },
		{ 60, 1, 189 },
		{ 60, 1, 190 },
		{ 60, 1, 191 },
		{ 61, 2, 192 },
		{ 62, 3, 193 },
		{ 62, 5, 194 },
		{ 62, 2, 195 },
		{ 63, 2, 196 },
		{ 63, 3, 197 },
		{ 63, 3, 198 },
		{ 63, 4, 199 },
		{ 64, 1, 200 },
		{ 64, 3, 201 },
		{ 65, 1, 202 },
		{ 65, 3, 203 },
		{ 66, 1, 204 },
		{ 66, 2, 205 },
		{ 67, 1, 206 },
		{ 67, 1, 207 },
		{ 68, 10, 208 },
		{ 68, 1, 209 },
		{ 69, 7, 210 },
		{ 69, 10, 211 },
		{ 70, 1, 212 },
		{ 70, 2, 213 },
		{ 71, 4, 214 },
		{ 72, 7, 215 },
		{ 72, 9, 216 },
		{ 72, 8, 217 },
		{ 72, 11, 218 },
		{ 73, 3, 219 },
		{ 73, 2, 220 },
		{ 73, 2, 221 },
		{ 73, 2, 222 },
		{ 73, 3, 223 },
		{ 74, 1, 224 },
		{ 74, 2, 225 },
		{ 75, 1, 226 },
		{ 75, 1, 227 },
		{ 76, 4, 228 },
		{ 76, 3, 229 },
		{ 76, 3, 230 },
		{ 76, 2, 231 }
	};
	yyreduction = reduction;

	yytokenaction_size = 444;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 137, YYAT_SHIFT, 85 },
		{ 357, YYAT_ERROR, 0 },
		{ 134, YYAT_SHIFT, 231 },
		{ 42, YYAT_SHIFT, 2 },
		{ 113, YYAT_SHIFT, 209 },
		{ 137, YYAT_SHIFT, 86 },
		{ 75, YYAT_SHIFT, 164 },
		{ 137, YYAT_SHIFT, 87 },
		{ 75, YYAT_SHIFT, 2 },
		{ 137, YYAT_SHIFT, 88 },
		{ 137, YYAT_SHIFT, 89 },
		{ 2, YYAT_SHIFT, 2 },
		{ 137, YYAT_SHIFT, 90 },
		{ 373, YYAT_SHIFT, 85 },
		{ 157, YYAT_SHIFT, 1 },
		{ 168, YYAT_SHIFT, 164 },
		{ 157, YYAT_SHIFT, 2 },
		{ 164, YYAT_SHIFT, 164 },
		{ 373, YYAT_SHIFT, 86 },
		{ 38, YYAT_SHIFT, 69 },
		{ 373, YYAT_SHIFT, 87 },
		{ 25, YYAT_SHIFT, 47 },
		{ 373, YYAT_SHIFT, 88 },
		{ 373, YYAT_SHIFT, 89 },
		{ 104, YYAT_SHIFT, 189 },
		{ 373, YYAT_SHIFT, 90 },
		{ 137, YYAT_SHIFT, 119 },
		{ 23, YYAT_SHIFT, 44 },
		{ 26, YYAT_ACCEPT, 0 },
		{ 318, YYAT_SHIFT, 339 },
		{ 104, YYAT_SHIFT, 190 },
		{ 173, YYAT_SHIFT, 171 },
		{ 181, YYAT_SHIFT, 4 },
		{ 264, YYAT_ERROR, 0 },
		{ 264, YYAT_SHIFT, 322 },
		{ 264, YYAT_ERROR, 0 },
		{ 178, YYAT_SHIFT, 273 },
		{ 275, YYAT_SHIFT, 273 },
		{ 178, YYAT_SHIFT, 2 },
		{ 373, YYAT_SHIFT, 119 },
		{ 181, YYAT_SHIFT, 10 },
		{ 181, YYAT_SHIFT, 11 },
		{ 181, YYAT_SHIFT, 12 },
		{ 181, YYAT_SHIFT, 13 },
		{ 181, YYAT_SHIFT, 14 },
		{ 181, YYAT_SHIFT, 15 },
		{ 181, YYAT_SHIFT, 16 },
		{ 181, YYAT_SHIFT, 17 },
		{ 181, YYAT_SHIFT, 18 },
		{ 181, YYAT_SHIFT, 19 },
		{ 181, YYAT_SHIFT, 20 },
		{ 181, YYAT_SHIFT, 21 },
		{ 181, YYAT_SHIFT, 22 },
		{ 181, YYAT_SHIFT, 23 },
		{ 291, YYAT_SHIFT, 197 },
		{ 361, YYAT_SHIFT, 365 },
		{ 368, YYAT_SHIFT, 93 },
		{ 75, YYAT_SHIFT, 165 },
		{ 361, YYAT_SHIFT, 247 },
		{ 291, YYAT_SHIFT, 198 },
		{ 367, YYAT_SHIFT, 370 },
		{ 34, YYAT_SHIFT, 2 },
		{ 266, YYAT_SHIFT, 264 },
		{ 167, YYAT_SHIFT, 264 },
		{ 291, YYAT_SHIFT, 199 },
		{ 357, YYAT_ERROR, 0 },
		{ 168, YYAT_SHIFT, 165 },
		{ 290, YYAT_SHIFT, 197 },
		{ 26, YYAT_SHIFT, 1 },
		{ 26, YYAT_ERROR, 0 },
		{ 50, YYAT_SHIFT, 51 },
		{ 29, YYAT_SHIFT, 51 },
		{ 290, YYAT_SHIFT, 198 },
		{ 273, YYAT_ERROR, 0 },
		{ 282, YYAT_SHIFT, 247 },
		{ 104, YYAT_SHIFT, 191 },
		{ 229, YYAT_SHIFT, 247 },
		{ 290, YYAT_SHIFT, 199 },
		{ 273, YYAT_ERROR, 0 },
		{ 68, YYAT_SHIFT, 157 },
		{ 273, YYAT_SHIFT, 273 },
		{ 273, YYAT_SHIFT, 259 },
		{ 273, YYAT_SHIFT, 2 },
		{ 273, YYAT_ERROR, 0 },
		{ 264, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 298, YYAT_SHIFT, 247 },
		{ 178, YYAT_SHIFT, 165 },
		{ 275, YYAT_SHIFT, 165 },
		{ 365, YYAT_SHIFT, 369 },
		{ 137, YYAT_SHIFT, 53 },
		{ 229, YYAT_SHIFT, 312 },
		{ 137, YYAT_SHIFT, 243 },
		{ 137, YYAT_SHIFT, 92 },
		{ 68, YYAT_SHIFT, 159 },
		{ 215, YYAT_SHIFT, 302 },
		{ 71, YYAT_SHIFT, 160 },
		{ 107, YYAT_SHIFT, 197 },
		{ 215, YYAT_SHIFT, 303 },
		{ 71, YYAT_SHIFT, 161 },
		{ 298, YYAT_SHIFT, 329 },
		{ 363, YYAT_SHIFT, 247 },
		{ 107, YYAT_SHIFT, 198 },
		{ 373, YYAT_SHIFT, 53 },
		{ 368, YYAT_ERROR, 0 },
		{ 368, YYAT_ERROR, 0 },
		{ 373, YYAT_SHIFT, 92 },
		{ 107, YYAT_SHIFT, 199 },
		{ 368, YYAT_ERROR, 0 },
		{ 59, YYAT_SHIFT, 154 },
		{ 318, YYAT_SHIFT, 340 },
		{ 291, YYAT_SHIFT, 200 },
		{ 173, YYAT_SHIFT, 269 },
		{ 266, YYAT_SHIFT, 265 },
		{ 167, YYAT_SHIFT, 265 },
		{ 280, YYAT_SHIFT, 201 },
		{ 179, YYAT_SHIFT, 2 },
		{ 280, YYAT_SHIFT, 202 },
		{ 279, YYAT_SHIFT, 201 },
		{ 26, YYAT_ERROR, 0 },
		{ 279, YYAT_SHIFT, 202 },
		{ 50, YYAT_SHIFT, 52 },
		{ 29, YYAT_SHIFT, 52 },
		{ 282, YYAT_SHIFT, 328 },
		{ 290, YYAT_SHIFT, 200 },
		{ 108, YYAT_SHIFT, 201 },
		{ 359, YYAT_SHIFT, 364 },
		{ 108, YYAT_SHIFT, 202 },
		{ 296, YYAT_SHIFT, 195 },
		{ 296, YYAT_SHIFT, 196 },
		{ 353, YYAT_REDUCE, 61 },
		{ 273, YYAT_SHIFT, 165 },
		{ 33, YYAT_SHIFT, 4 },
		{ 53, YYAT_SHIFT, 119 },
		{ 348, YYAT_SHIFT, 356 },
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
		{ 107, YYAT_SHIFT, 200 },
		{ 25, YYAT_SHIFT, 48 },
		{ 295, YYAT_SHIFT, 187 },
		{ 295, YYAT_SHIFT, 188 },
		{ 294, YYAT_SHIFT, 187 },
		{ 294, YYAT_SHIFT, 188 },
		{ 347, YYAT_SHIFT, 355 },
		{ 23, YYAT_SHIFT, 45 },
		{ 293, YYAT_SHIFT, 187 },
		{ 293, YYAT_SHIFT, 188 },
		{ 292, YYAT_SHIFT, 187 },
		{ 292, YYAT_SHIFT, 188 },
		{ 273, YYAT_ERROR, 0 },
		{ 106, YYAT_SHIFT, 195 },
		{ 106, YYAT_SHIFT, 196 },
		{ 24, YYAT_SHIFT, 4 },
		{ 339, YYAT_SHIFT, 349 },
		{ 59, YYAT_SHIFT, 53 },
		{ 24, YYAT_SHIFT, 5 },
		{ 24, YYAT_SHIFT, 6 },
		{ 24, YYAT_SHIFT, 7 },
		{ 24, YYAT_SHIFT, 8 },
		{ 24, YYAT_SHIFT, 9 },
		{ 24, YYAT_SHIFT, 10 },
		{ 24, YYAT_SHIFT, 11 },
		{ 24, YYAT_SHIFT, 12 },
		{ 24, YYAT_SHIFT, 13 },
		{ 24, YYAT_SHIFT, 14 },
		{ 24, YYAT_SHIFT, 15 },
		{ 24, YYAT_SHIFT, 16 },
		{ 24, YYAT_SHIFT, 17 },
		{ 24, YYAT_SHIFT, 18 },
		{ 24, YYAT_SHIFT, 19 },
		{ 24, YYAT_SHIFT, 20 },
		{ 24, YYAT_SHIFT, 21 },
		{ 24, YYAT_SHIFT, 22 },
		{ 24, YYAT_SHIFT, 23 },
		{ 285, YYAT_SHIFT, 203 },
		{ 338, YYAT_SHIFT, 119 },
		{ 285, YYAT_SHIFT, 204 },
		{ 284, YYAT_SHIFT, 203 },
		{ 336, YYAT_SHIFT, 346 },
		{ 284, YYAT_SHIFT, 204 },
		{ 53, YYAT_SHIFT, 53 },
		{ 109, YYAT_SHIFT, 203 },
		{ 53, YYAT_SHIFT, 120 },
		{ 109, YYAT_SHIFT, 204 },
		{ 102, YYAT_SHIFT, 187 },
		{ 102, YYAT_SHIFT, 188 },
		{ 331, YYAT_SHIFT, 208 },
		{ 330, YYAT_SHIFT, 211 },
		{ 325, YYAT_SHIFT, 342 },
		{ 323, YYAT_SHIFT, 341 },
		{ 309, YYAT_SHIFT, 337 },
		{ 307, YYAT_SHIFT, 335 },
		{ 306, YYAT_SHIFT, 334 },
		{ 301, YYAT_SHIFT, 207 },
		{ 297, YYAT_SHIFT, 213 },
		{ 113, YYAT_SHIFT, 210 },
		{ 134, YYAT_SHIFT, 232 },
		{ 134, YYAT_SHIFT, 233 },
		{ 134, YYAT_SHIFT, 234 },
		{ 134, YYAT_SHIFT, 235 },
		{ 134, YYAT_SHIFT, 236 },
		{ 134, YYAT_SHIFT, 237 },
		{ 134, YYAT_SHIFT, 238 },
		{ 134, YYAT_SHIFT, 239 },
		{ 134, YYAT_SHIFT, 240 },
		{ 134, YYAT_SHIFT, 241 },
		{ 75, YYAT_SHIFT, 3 },
		{ 137, YYAT_SHIFT, 121 },
		{ 137, YYAT_SHIFT, 94 },
		{ 137, YYAT_SHIFT, 95 },
		{ 137, YYAT_SHIFT, 96 },
		{ 278, YYAT_SHIFT, 327 },
		{ 137, YYAT_SHIFT, 97 },
		{ 137, YYAT_SHIFT, 98 },
		{ 157, YYAT_SHIFT, 3 },
		{ 168, YYAT_SHIFT, 3 },
		{ 265, YYAT_SHIFT, 324 },
		{ 164, YYAT_SHIFT, 3 },
		{ 38, YYAT_SHIFT, 70 },
		{ 263, YYAT_SHIFT, 321 },
		{ 373, YYAT_SHIFT, 121 },
		{ 373, YYAT_SHIFT, 94 },
		{ 373, YYAT_SHIFT, 95 },
		{ 373, YYAT_SHIFT, 96 },
		{ 261, YYAT_SHIFT, 320 },
		{ 373, YYAT_SHIFT, 97 },
		{ 373, YYAT_SHIFT, 98 },
		{ 260, YYAT_SHIFT, 319 },
		{ 104, YYAT_SHIFT, 192 },
		{ 104, YYAT_SHIFT, 193 },
		{ 104, YYAT_SHIFT, 194 },
		{ 251, YYAT_SHIFT, 251 },
		{ 357, YYAT_ERROR, 0 },
		{ 137, YYAT_SHIFT, 99 },
		{ 137, YYAT_SHIFT, 100 },
		{ 357, YYAT_ERROR, 0 },
		{ 357, YYAT_ERROR, 0 },
		{ 357, YYAT_ERROR, 0 },
		{ 357, YYAT_ERROR, 0 },
		{ 357, YYAT_ERROR, 0 },
		{ 357, YYAT_ERROR, 0 },
		{ 357, YYAT_ERROR, 0 },
		{ 42, YYAT_SHIFT, 18 },
		{ 42, YYAT_SHIFT, 19 },
		{ 244, YYAT_SHIFT, 314 },
		{ 225, YYAT_SHIFT, 311 },
		{ 373, YYAT_SHIFT, 99 },
		{ 373, YYAT_SHIFT, 100 },
		{ 222, YYAT_SHIFT, 308 },
		{ 218, YYAT_SHIFT, 305 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 192, YYAT_SHIFT, 283 },
		{ 190, YYAT_SHIFT, 281 },
		{ 180, YYAT_SHIFT, 277 },
		{ 137, YYAT_SHIFT, 122 },
		{ 137, YYAT_SHIFT, 123 },
		{ 137, YYAT_SHIFT, 124 },
		{ 177, YYAT_SHIFT, 272 },
		{ 137, YYAT_SHIFT, 125 },
		{ 137, YYAT_SHIFT, 126 },
		{ 137, YYAT_SHIFT, 127 },
		{ 137, YYAT_SHIFT, 128 },
		{ 137, YYAT_SHIFT, 129 },
		{ 137, YYAT_SHIFT, 130 },
		{ 137, YYAT_SHIFT, 131 },
		{ 137, YYAT_SHIFT, 132 },
		{ 175, YYAT_SHIFT, 270 },
		{ 373, YYAT_SHIFT, 122 },
		{ 373, YYAT_SHIFT, 123 },
		{ 373, YYAT_SHIFT, 124 },
		{ 171, YYAT_SHIFT, 79 },
		{ 373, YYAT_SHIFT, 125 },
		{ 373, YYAT_SHIFT, 126 },
		{ 373, YYAT_SHIFT, 127 },
		{ 373, YYAT_SHIFT, 128 },
		{ 373, YYAT_SHIFT, 129 },
		{ 373, YYAT_SHIFT, 130 },
		{ 373, YYAT_SHIFT, 131 },
		{ 373, YYAT_SHIFT, 132 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 34, YYAT_SHIFT, 4 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
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
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_ERROR, 0 },
		{ 273, YYAT_SHIFT, 5 },
		{ 273, YYAT_SHIFT, 6 },
		{ 273, YYAT_SHIFT, 7 },
		{ 273, YYAT_SHIFT, 8 },
		{ 273, YYAT_SHIFT, 9 },
		{ 59, YYAT_SHIFT, 4 },
		{ 53, YYAT_SHIFT, 121 },
		{ 165, YYAT_SHIFT, 262 },
		{ 59, YYAT_SHIFT, 5 },
		{ 59, YYAT_SHIFT, 6 },
		{ 59, YYAT_SHIFT, 7 },
		{ 59, YYAT_SHIFT, 8 },
		{ 59, YYAT_SHIFT, 9 },
		{ 59, YYAT_SHIFT, 10 },
		{ 59, YYAT_SHIFT, 11 },
		{ 59, YYAT_SHIFT, 12 },
		{ 59, YYAT_SHIFT, 13 },
		{ 59, YYAT_SHIFT, 14 },
		{ 59, YYAT_SHIFT, 15 },
		{ 59, YYAT_SHIFT, 16 },
		{ 59, YYAT_SHIFT, 17 },
		{ 59, YYAT_SHIFT, 18 },
		{ 59, YYAT_SHIFT, 19 },
		{ 59, YYAT_SHIFT, 20 },
		{ 59, YYAT_SHIFT, 21 },
		{ 59, YYAT_SHIFT, 22 },
		{ 59, YYAT_SHIFT, 23 },
		{ 162, YYAT_SHIFT, 257 },
		{ 161, YYAT_SHIFT, 256 },
		{ 155, YYAT_SHIFT, 53 },
		{ 153, YYAT_ERROR, 0 },
		{ 179, YYAT_SHIFT, 4 },
		{ 145, YYAT_SHIFT, 248 },
		{ 142, YYAT_SHIFT, 245 },
		{ 53, YYAT_SHIFT, 5 },
		{ 53, YYAT_SHIFT, 6 },
		{ 53, YYAT_SHIFT, 7 },
		{ 53, YYAT_SHIFT, 8 },
		{ 53, YYAT_SHIFT, 9 },
		{ 179, YYAT_SHIFT, 10 },
		{ 179, YYAT_SHIFT, 11 },
		{ 179, YYAT_SHIFT, 12 },
		{ 179, YYAT_SHIFT, 13 },
		{ 179, YYAT_SHIFT, 14 },
		{ 179, YYAT_SHIFT, 15 },
		{ 179, YYAT_SHIFT, 16 },
		{ 179, YYAT_SHIFT, 17 },
		{ 179, YYAT_SHIFT, 18 },
		{ 179, YYAT_SHIFT, 19 },
		{ 179, YYAT_SHIFT, 20 },
		{ 179, YYAT_SHIFT, 21 },
		{ 179, YYAT_SHIFT, 22 },
		{ 179, YYAT_SHIFT, 23 },
		{ 132, YYAT_SHIFT, 228 },
		{ 53, YYAT_SHIFT, 122 },
		{ 53, YYAT_SHIFT, 123 },
		{ 53, YYAT_SHIFT, 124 },
		{ 131, YYAT_SHIFT, 227 },
		{ 53, YYAT_SHIFT, 125 },
		{ 53, YYAT_SHIFT, 126 },
		{ 53, YYAT_SHIFT, 127 },
		{ 53, YYAT_SHIFT, 128 },
		{ 53, YYAT_SHIFT, 129 },
		{ 53, YYAT_SHIFT, 130 },
		{ 53, YYAT_SHIFT, 131 },
		{ 53, YYAT_SHIFT, 132 },
		{ 130, YYAT_SHIFT, 226 },
		{ 129, YYAT_SHIFT, 225 },
		{ 128, YYAT_SHIFT, 224 },
		{ 125, YYAT_SHIFT, 221 },
		{ 124, YYAT_SHIFT, 220 },
		{ 123, YYAT_SHIFT, 219 },
		{ 285, YYAT_SHIFT, 205 },
		{ 285, YYAT_SHIFT, 206 },
		{ 176, YYAT_SHIFT, 4 },
		{ 284, YYAT_SHIFT, 205 },
		{ 284, YYAT_SHIFT, 206 },
		{ 121, YYAT_SHIFT, 217 },
		{ 118, YYAT_SHIFT, 214 },
		{ 109, YYAT_SHIFT, 205 },
		{ 109, YYAT_SHIFT, 206 },
		{ 117, YYAT_SHIFT, 213 },
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
		{ 116, YYAT_SHIFT, 212 },
		{ 114, YYAT_SHIFT, 211 },
		{ 112, YYAT_SHIFT, 208 },
		{ 110, YYAT_SHIFT, 207 },
		{ 98, YYAT_SHIFT, 183 },
		{ 96, YYAT_SHIFT, 181 },
		{ 83, YYAT_SHIFT, 174 },
		{ 81, YYAT_SHIFT, 172 },
		{ 79, YYAT_SHIFT, 170 },
		{ 73, YYAT_SHIFT, 163 },
		{ 72, YYAT_SHIFT, 162 },
		{ 66, YYAT_SHIFT, 154 },
		{ 60, YYAT_SHIFT, 158 },
		{ 56, YYAT_SHIFT, 58 },
		{ 54, YYAT_SHIFT, 53 },
		{ 52, YYAT_SHIFT, 91 },
		{ 48, YYAT_SHIFT, 84 },
		{ 45, YYAT_SHIFT, 82 },
		{ 40, YYAT_SHIFT, 76 },
		{ 36, YYAT_SHIFT, 65 },
		{ 30, YYAT_SHIFT, 53 },
		{ 27, YYAT_ERROR, 0 },
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 443, 1, YYAT_DEFAULT, 26 },
		{ 0, 0, YYAT_DEFAULT, 157 },
		{ -31, 1, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ 0, 0, YYAT_REDUCE, 119 },
		{ -96, 1, YYAT_ERROR, 0 },
		{ -113, 1, YYAT_REDUCE, 88 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ 28, 1, YYAT_DEFAULT, 164 },
		{ 400, 1, YYAT_DEFAULT, 157 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 31, 1, YYAT_REDUCE, 143 },
		{ 318, 1, YYAT_DEFAULT, 153 },
		{ 0, 0, YYAT_DEFAULT, 56 },
		{ 0, 0, YYAT_REDUCE, 228 },
		{ -150, 1, YYAT_REDUCE, 84 },
		{ 19, 1, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 381, 1, YYAT_DEFAULT, 157 },
		{ 0, 0, YYAT_REDUCE, 227 },
		{ -22, 1, YYAT_DEFAULT, 264 },
		{ 0, 0, YYAT_REDUCE, 225 },
		{ 398, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 156 },
		{ -39, 1, YYAT_REDUCE, 153 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 315, 1, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_DEFAULT, 153 },
		{ 314, 1, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_REDUCE, 226 },
		{ 30, 1, YYAT_REDUCE, 142 },
		{ 0, 0, YYAT_REDUCE, 144 },
		{ 343, 1, YYAT_DEFAULT, 357 },
		{ 74, 1, YYAT_DEFAULT, 181 },
		{ 312, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 232 },
		{ 375, 1, YYAT_DEFAULT, 157 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 48, 1, YYAT_REDUCE, 92 },
		{ 374, 1, YYAT_DEFAULT, 68 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 371, 1, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 35, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 151 },
		{ 0, 0, YYAT_REDUCE, 165 },
		{ 55, 1, YYAT_ERROR, 0 },
		{ 387, 1, YYAT_REDUCE, 158 },
		{ 389, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ -34, 1, YYAT_REDUCE, 164 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 368, 1, YYAT_REDUCE, 138 },
		{ 0, 0, YYAT_REDUCE, 136 },
		{ 303, 1, YYAT_DEFAULT, 173 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 302, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 153 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 386, 1, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 98 },
		{ 385, 1, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ -63, 1, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ -16, 1, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ -101, 1, YYAT_REDUCE, 51 },
		{ 60, 1, YYAT_REDUCE, 37 },
		{ 82, 1, YYAT_REDUCE, 40 },
		{ 138, 1, YYAT_REDUCE, 48 },
		{ 386, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 299, 1, YYAT_REDUCE, 57 },
		{ -59, 1, YYAT_REDUCE, 64 },
		{ 152, 1, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 328, 1, YYAT_ERROR, 0 },
		{ 312, 1, YYAT_REDUCE, 55 },
		{ 362, 1, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 344, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 338, 1, YYAT_ERROR, 0 },
		{ 355, 1, YYAT_ERROR, 0 },
		{ 354, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 353, 1, YYAT_ERROR, 0 },
		{ 135, 1, YYAT_ERROR, 0 },
		{ 332, 1, YYAT_ERROR, 0 },
		{ 323, 1, YYAT_ERROR, 0 },
		{ 319, 1, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ -59, 1, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ -33, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 233, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 298, 1, YYAT_DEFAULT, 229 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_REDUCE, 208 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 231 },
		{ 314, 1, YYAT_DEFAULT, 264 },
		{ 0, 0, YYAT_DEFAULT, 251 },
		{ 231, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 230 },
		{ -26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ 96, 1, YYAT_ERROR, 0 },
		{ 48, 1, YYAT_DEFAULT, 153 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ -23, 1, YYAT_DEFAULT, 273 },
		{ 239, 1, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 23, 1, YYAT_REDUCE, 170 },
		{ -25, 1, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 162 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 31, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 133 },
		{ -13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ 159, 1, YYAT_REDUCE, 59 },
		{ 117, 1, YYAT_REDUCE, 127 },
		{ 234, 1, YYAT_ERROR, 0 },
		{ -4, 1, YYAT_REDUCE, 167 },
		{ 74, 1, YYAT_REDUCE, 125 },
		{ 230, 1, YYAT_DEFAULT, 361 },
		{ -250, 1, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 12, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 54, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ 208, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 225, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ 0, 0, YYAT_DEFAULT, 338 },
		{ 203, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 0, 0, YYAT_REDUCE, 223 },
		{ 32, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 136, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 214 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 125, 1, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 229 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 161 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 203, 1, YYAT_ERROR, 0 },
		{ 200, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 143, 1, YYAT_ERROR, 0 },
		{ -7, 1, YYAT_DEFAULT, 273 },
		{ 140, 1, YYAT_DEFAULT, 357 },
		{ 22, 1, YYAT_REDUCE, 171 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 0, 0, YYAT_REDUCE, 126 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 40, 1, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ -3, 1, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 187, 1, YYAT_ERROR, 0 },
		{ 75, 1, YYAT_REDUCE, 41 },
		{ 72, 1, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 30, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 134, 1, YYAT_REDUCE, 49 },
		{ 131, 1, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 30, 1, YYAT_REDUCE, 38 },
		{ 17, 1, YYAT_REDUCE, 39 },
		{ -100, 1, YYAT_REDUCE, 44 },
		{ -102, 1, YYAT_REDUCE, 45 },
		{ -106, 1, YYAT_REDUCE, 46 },
		{ -108, 1, YYAT_REDUCE, 47 },
		{ -140, 1, YYAT_REDUCE, 52 },
		{ 117, 1, YYAT_REDUCE, 56 },
		{ 42, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 172, 1, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 168, 1, YYAT_DEFAULT, 361 },
		{ 167, 1, YYAT_DEFAULT, 361 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ -103, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 0, 0, YYAT_REDUCE, 204 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ -15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 165, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 112, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ -66, 1, YYAT_REDUCE, 63 },
		{ 79, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 215 },
		{ 154, 1, YYAT_DEFAULT, 361 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 133, 1, YYAT_DEFAULT, 357 },
		{ 45, 1, YYAT_DEFAULT, 251 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 0, 0, YYAT_DEFAULT, 368 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 120, 1, YYAT_ERROR, 0 },
		{ 93, 1, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ -178, 1, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ 0, 0, YYAT_DEFAULT, 357 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ -58, 1, YYAT_DEFAULT, 368 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 216 },
		{ 14, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 373 },
		{ 57, 1, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 30, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ 19, 1, YYAT_ERROR, 0 },
		{ -201, 1, YYAT_DEFAULT, 373 },
		{ 0, 0, YYAT_REDUCE, 217 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ -20, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 219 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 261;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 373, 111 },
		{ 373, 118 },
		{ 373, 104 },
		{ 370, 373 },
		{ 373, 134 },
		{ 373, 101 },
		{ 373, 105 },
		{ 373, 107 },
		{ 373, 108 },
		{ 373, 102 },
		{ 373, 109 },
		{ 373, 106 },
		{ 373, 110 },
		{ 373, 117 },
		{ 373, 112 },
		{ 373, 114 },
		{ 34, 64 },
		{ 84, 57 },
		{ 339, 253 },
		{ 373, 113 },
		{ 373, 144 },
		{ 373, 143 },
		{ 338, 145 },
		{ 373, 145 },
		{ 33, 62 },
		{ 36, 68 },
		{ 1, -1 },
		{ 364, 368 },
		{ 181, 179 },
		{ 181, 36 },
		{ 36, 67 },
		{ 181, 35 },
		{ 181, 25 },
		{ 38, 73 },
		{ 118, 215 },
		{ 181, 178 },
		{ 38, 71 },
		{ 34, 63 },
		{ 181, 28 },
		{ 53, 57 },
		{ 53, 56 },
		{ 181, 176 },
		{ 1, 40 },
		{ 53, 33 },
		{ 53, 34 },
		{ 53, 36 },
		{ 137, 153 },
		{ 53, 35 },
		{ 53, 25 },
		{ 33, -1 },
		{ 363, 367 },
		{ 181, 278 },
		{ 118, 216 },
		{ 339, 350 },
		{ 53, 28 },
		{ 84, 175 },
		{ 362, 366 },
		{ 53, 24 },
		{ 373, 146 },
		{ 373, 374 },
		{ 373, 133 },
		{ 373, 140 },
		{ 373, 141 },
		{ 356, 362 },
		{ 338, 348 },
		{ 373, 135 },
		{ 373, 150 },
		{ 373, 151 },
		{ 373, 147 },
		{ 373, 148 },
		{ 373, 149 },
		{ 373, 138 },
		{ 373, 139 },
		{ 53, 136 },
		{ 357, 363 },
		{ 329, 103 },
		{ 273, 75 },
		{ 53, 137 },
		{ 53, 142 },
		{ 273, 33 },
		{ 273, 34 },
		{ 273, 36 },
		{ 355, 361 },
		{ 273, 35 },
		{ 273, 25 },
		{ 354, 360 },
		{ 26, 32 },
		{ 26, 31 },
		{ 176, 271 },
		{ 137, 136 },
		{ 273, 28 },
		{ 329, 343 },
		{ 329, -1 },
		{ 273, 24 },
		{ 137, 244 },
		{ 264, -1 },
		{ 157, 255 },
		{ 264, 323 },
		{ 176, -1 },
		{ 273, 261 },
		{ 273, 72 },
		{ 273, 74 },
		{ 264, -1 },
		{ 264, -1 },
		{ 273, 260 },
		{ 26, 30 },
		{ 26, 38 },
		{ 26, 29 },
		{ 26, 27 },
		{ 357, -1 },
		{ 299, 112 },
		{ 299, 330 },
		{ 157, 66 },
		{ 357, -1 },
		{ 157, 29 },
		{ 157, 27 },
		{ 357, -1 },
		{ 179, -1 },
		{ 357, -1 },
		{ 357, -1 },
		{ 179, -1 },
		{ 179, 179 },
		{ 357, -1 },
		{ 357, -1 },
		{ 164, 40 },
		{ 164, 38 },
		{ 164, 29 },
		{ 164, 168 },
		{ 179, 276 },
		{ 368, 351 },
		{ 368, -1 },
		{ 368, -1 },
		{ 368, -1 },
		{ 353, 359 },
		{ 179, 176 },
		{ 26, 49 },
		{ 26, 37 },
		{ 368, -1 },
		{ 368, 372 },
		{ 368, 371 },
		{ 368, -1 },
		{ 368, -1 },
		{ 75, 169 },
		{ 300, 331 },
		{ 300, -1 },
		{ 75, 168 },
		{ 2, 41 },
		{ 178, 275 },
		{ 300, -1 },
		{ 300, -1 },
		{ 2, 43 },
		{ 2, 42 },
		{ 75, 166 },
		{ 75, 167 },
		{ 178, 274 },
		{ 178, 167 },
		{ 345, 352 },
		{ 345, 353 },
		{ 345, 147 },
		{ 272, 326 },
		{ 272, -1 },
		{ 272, -1 },
		{ 162, -1 },
		{ 162, -1 },
		{ 162, 258 },
		{ 265, 115 },
		{ 42, 77 },
		{ 251, 317 },
		{ 251, 318 },
		{ 265, 325 },
		{ 42, 78 },
		{ 303, 332 },
		{ 98, 185 },
		{ 303, -1 },
		{ 98, -1 },
		{ 213, 301 },
		{ 213, -1 },
		{ 208, 297 },
		{ 208, -1 },
		{ 207, 296 },
		{ 207, -1 },
		{ 206, 295 },
		{ 206, -1 },
		{ 202, 105 },
		{ 202, 291 },
		{ 196, 285 },
		{ 196, -1 },
		{ 188, 280 },
		{ 188, -1 },
		{ 168, 38 },
		{ 168, 50 },
		{ 153, 250 },
		{ 153, 56 },
		{ 82, 173 },
		{ 82, 80 },
		{ 59, 156 },
		{ 59, 155 },
		{ 56, 60 },
		{ 56, 61 },
		{ 30, 55 },
		{ 30, 54 },
		{ 0, 26 },
		{ 0, 39 },
		{ 352, 358 },
		{ 348, 357 },
		{ 346, 354 },
		{ 337, 347 },
		{ 334, 345 },
		{ 333, 344 },
		{ 310, 338 },
		{ 308, 336 },
		{ 305, 333 },
		{ 275, 266 },
		{ 247, 316 },
		{ 246, 315 },
		{ 244, 246 },
		{ 242, 313 },
		{ 224, 310 },
		{ 223, 309 },
		{ 221, 307 },
		{ 220, 306 },
		{ 217, 304 },
		{ 211, 300 },
		{ 210, 299 },
		{ 209, 298 },
		{ 205, 294 },
		{ 204, 293 },
		{ 203, 292 },
		{ 201, 290 },
		{ 200, 289 },
		{ 199, 288 },
		{ 198, 287 },
		{ 197, 286 },
		{ 195, 284 },
		{ 191, 282 },
		{ 187, 279 },
		{ 183, 180 },
		{ 175, 153 },
		{ 171, 268 },
		{ 170, 267 },
		{ 165, 263 },
		{ 155, 254 },
		{ 154, 252 },
		{ 149, 249 },
		{ 134, 242 },
		{ 133, 230 },
		{ 132, 229 },
		{ 127, 223 },
		{ 126, 222 },
		{ 122, 218 },
		{ 101, 186 },
		{ 97, 184 },
		{ 96, 182 },
		{ 87, 177 },
		{ 54, 152 },
		{ 52, 116 },
		{ 47, 83 },
		{ 44, 81 },
		{ 31, 59 },
		{ 27, -1 },
		{ 24, 46 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 127, 26 },
		{ -3, 157 },
		{ 102, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 233, 33 },
		{ 0, -1 },
		{ 60, 153 },
		{ 203, 168 },
		{ 0, -1 },
		{ 0, -1 },
		{ 136, 84 },
		{ 213, 56 },
		{ 0, -1 },
		{ -3, 162 },
		{ -11, 33 },
		{ 0, -1 },
		{ -3, 56 },
		{ 0, -1 },
		{ -17, 264 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 122, -1 },
		{ 0, -1 },
		{ 215, 82 },
		{ 0, -1 },
		{ 0, -1 },
		{ 192, 84 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 230, 265 },
		{ 13, 373 },
		{ 191, 175 },
		{ 0, -1 },
		{ 169, 157 },
		{ 0, -1 },
		{ 0, -1 },
		{ 132, 84 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
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
		{ 151, -1 },
		{ 0, 175 },
		{ -9, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 199, 181 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 247, 98 },
		{ 246, 98 },
		{ 167, 272 },
		{ 0, -1 },
		{ 0, -1 },
		{ 243, 272 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 30, 303 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 224, 265 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 231, -1 },
		{ 230, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 222, 357 },
		{ 185, 373 },
		{ 221, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 373 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 244 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 183, 373 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 165, 33 },
		{ 185, 339 },
		{ 178, 175 },
		{ 0, -1 },
		{ 67, 27 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 112, 264 },
		{ 0, -1 },
		{ 79, 273 },
		{ 215, 265 },
		{ 0, -1 },
		{ 0, -1 },
		{ 143, 275 },
		{ 0, -1 },
		{ 214, 265 },
		{ 195, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 220, -1 },
		{ 50, 179 },
		{ 0, -1 },
		{ 99, -1 },
		{ 90, 34 },
		{ 0, -1 },
		{ -3, 183 },
		{ 0, -1 },
		{ 212, 357 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 226, 188 },
		{ 178, 206 },
		{ 0, -1 },
		{ 0, -1 },
		{ 210, 357 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 222, 196 },
		{ 174, 207 },
		{ 225, 272 },
		{ 224, 272 },
		{ 223, 272 },
		{ 222, 272 },
		{ 220, 202 },
		{ 176, 272 },
		{ 217, 206 },
		{ 216, 206 },
		{ 215, 206 },
		{ 171, 196 },
		{ 167, 213 },
		{ 163, 300 },
		{ 200, 357 },
		{ 206, -1 },
		{ 205, -1 },
		{ 0, -1 },
		{ 162, 208 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 161, 373 },
		{ 0, -1 },
		{ 0, -1 },
		{ 196, 357 },
		{ 195, 357 },
		{ 0, -1 },
		{ 158, 373 },
		{ 151, 338 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 194, 303 },
		{ 0, -1 },
		{ 198, -1 },
		{ 0, -1 },
		{ 154, 373 },
		{ 191, 303 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 110, 339 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 47, 273 },
		{ 144, 329 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 152, 188 },
		{ 49, 178 },
		{ 0, -1 },
		{ 156, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 95, 300 },
		{ 128, 329 },
		{ 0, -1 },
		{ 0, -1 },
		{ 149, 357 },
		{ 0, -1 },
		{ 194, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 186, 357 },
		{ 0, -1 },
		{ 192, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 70, 303 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 148, 373 },
		{ 190, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 189, -1 },
		{ -2, 357 },
		{ -4, 303 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 89, 368 },
		{ 188, -1 },
		{ 0, -1 },
		{ 187, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 184, -1 },
		{ 114, -1 },
		{ 25, 373 },
		{ 58, 357 },
		{ 46, -1 },
		{ 50, 368 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 373 },
		{ 31, -1 },
		{ 10, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 70, 373 },
		{ 0, -1 },
		{ -14, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -1, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 3214 ".\\myparser.y"


	/////////////////////////////////////////////////////////////////////////////
	// programs section

	int main(void)
	{
		s.push_back(new varmap());
	//print-function
		typenode *type5 = new typenode("fun");
		type5->right = &voidnode;
		type5->left = &intnode;
		s[s.size()-1]->vartable["print"] = type5;
		s.push_back(new varmap());

	//print-function
		type5->right = &voidnode;
		type5->left = &intnode;
		s[s.size()-1]->vartable["read"] = type5;
		s.push_back(new varmap());

	//  	FILE *stream;
	//	freopen_s(&stream, "test.c", "r", stdin);
	//	freopen_s(&stream, "out.txt", "w", stdout);
		// cout << "Name\t\tElement\t\tValue\t\tLine" << endl;
		int n = 1;
		mylexer lexer;
		myparser parser;
		if (parser.yycreate(&lexer)) {
			if (lexer.yycreate(&parser)) {
				n = parser.yyparse();
				show_code();
				transcode();
			}
		}
		file.close();
		getchar();
		return 0;
	}
