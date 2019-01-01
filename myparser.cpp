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
* Date: 01/01/19
<<<<<<< HEAD
* Time: 11:52:34
=======
* Time: 11:12:28
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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

	Date: 2018??10??28??
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
			cout<<(*iter)->name<<' ';
		}
		cout<<endl;
	}

	void show_string(vector<string> &v) {
		for (int i=0; i<v.size();i++) {
			cout<<v[i]<<" ";
		}
		cout<<endl;
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
				//	cout<<"---------------------------\n";
					cout<<"|warning: lose precision!!|\n";
					cout<<"---------------------------\n";
				//	return true;
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
			printf("116 ");
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
		
#line 326 "myparser.cpp"
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
#line 213 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("123 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
#line 346 "myparser.cpp"
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
#line 221 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("130 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";	
			s.pop_back();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = yyattribute(2 - 3).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist = yyattribute(2 - 3).ntnode->falselist;  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
#line 368 "myparser.cpp"
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
#line 231 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("125 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();			
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 388 "myparser.cpp"
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
#line 239 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="primary_exp";
			int nextinstr = newlabel();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr);
            gen(nextinstr, "j");
		
#line 408 "myparser.cpp"
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
#line 251 ".\\myparser.y"

			fun_name = var_name;
		
#line 423 "myparser.cpp"
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
#line 257 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("142 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 449 "myparser.cpp"
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
#line 271 ".\\myparser.y"
	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("149 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[3] = yyattribute(4 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *(yyattribute(1 - 4).ntnode->type.right);
		
#line 473 "myparser.cpp"
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
#line 283 ".\\myparser.y"

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
			gen(newlabel(), "call", 0, 0, 0);
		
#line 501 "myparser.cpp"
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
#line 299 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("168 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			s.pop_back();  
			gen(newlabel(), "call", 0, 0, 0);
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
					//cout<<"-----------------------"<<endl;
					cout<<"|Argument_list matched!|"<<endl;
					//cout<<"-----------------------"<<endl;
				}
				else{
					// cout<<"Argument_list matching failed."<<endl;
				}
			}
			// cout<<"clear v_argument_list"<<endl;
			v_argument_list.clear();
		
#line 560 "myparser.cpp"
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
#line 346 ".\\myparser.y"

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

		
		
#line 613 "myparser.cpp"
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
#line 387 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("187 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
#line 635 "myparser.cpp"
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
#line 397 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("196 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
				cout<<"No additive calculation can be made for uncalculable types."<<endl;
		
#line 659 "myparser.cpp"
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
#line 409 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="postfix_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(1 - 2).ntnode->type.name))
				cout<<"Can't subtract from uncalculable types."<<endl;
		
#line 683 "myparser.cpp"
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
#line 424 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("215 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			v_argument_list.push_back(yyattribute(1 - 1).ntnode->type.name);
			gen(newlabel(), "ARG", 0, 0, yyattribute(1 - 1).ntnode->type.addr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;						
		
#line 706 "myparser.cpp"
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
#line 435 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("222 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="argument_exp_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			// v_argument_list.push_back($1->type.name);
			v_argument_list.push_back(yyattribute(3 - 3).ntnode->type.name);
		
#line 731 "myparser.cpp"
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
#line 451 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("234 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
#line 757 "myparser.cpp"
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
#line 465 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("241 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
				cout<<"No additive calculation can be made for uncalculable types."<<endl;
		
#line 781 "myparser.cpp"
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
#line 477 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("249 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="unary_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;

			if(!isComputable(yyattribute(2 - 2).ntnode->type.name))
				cout<<"Can't subtract from uncalculable types ."<<endl;
		
#line 805 "myparser.cpp"
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
#line 489 ".\\myparser.y"

			//cast_exp:��Ŀ���ʽ/ǿ������ת��
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("257 ");
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
					typenode* temp = new typenode("pointer");
					temp->left=&(yyattribute(2 - 2).ntnode->type);
					temp->width = 4;
					traverse(temp);
					(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=*temp;
				}
				if (yyattribute(1 - 2).ntnode->name == "*") {
					gen(newlabel(), "=*", yyattribute(2 - 2).ntnode->type.addr, 0, (*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type.addr);
					(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=*(yyattribute(2 - 2).ntnode->type.left);
				}
			}
		
<<<<<<< HEAD
#line 843 "myparser.cpp"
=======
#line 845 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 515 ".\\myparser.y"
=======
#line 517 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 870 "myparser.cpp"
=======
#line 872 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 530 ".\\myparser.y"
=======
#line 532 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 897 "myparser.cpp"
=======
#line 899 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 548 ".\\myparser.y"
=======
#line 550 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("286 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&";
		
<<<<<<< HEAD
#line 914 "myparser.cpp"
=======
#line 916 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 553 ".\\myparser.y"
=======
#line 555 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*";
		
<<<<<<< HEAD
#line 931 "myparser.cpp"
=======
#line 933 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 558 ".\\myparser.y"
=======
#line 560 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("301 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+";
		
<<<<<<< HEAD
#line 948 "myparser.cpp"
=======
#line 950 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 563 ".\\myparser.y"
=======
#line 565 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("308 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-";
		
<<<<<<< HEAD
#line 965 "myparser.cpp"
=======
#line 967 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 568 ".\\myparser.y"
=======
#line 570 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("315 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="~";
		
<<<<<<< HEAD
#line 982 "myparser.cpp"
=======
#line 984 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 573 ".\\myparser.y"
=======
#line 575 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("322 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="!";
		
<<<<<<< HEAD
#line 999 "myparser.cpp"
=======
#line 1001 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 581 ".\\myparser.y"
=======
#line 583 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("332 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="cast_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1025 "myparser.cpp"
=======
#line 1027 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 595 ".\\myparser.y"
=======
#line 597 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 1049 "myparser.cpp"
=======
#line 1051 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 610 ".\\myparser.y"
=======
#line 612 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("352 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="multiplicative_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;	
		
<<<<<<< HEAD
#line 1075 "myparser.cpp"
=======
#line 1077 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 624 ".\\myparser.y"
=======
#line 626 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("359 ");
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
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "*", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
												
		
<<<<<<< HEAD
#line 1107 "myparser.cpp"
=======
#line 1108 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 644 ".\\myparser.y"
=======
#line 645 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("368 ");
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
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "/", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
			
		
<<<<<<< HEAD
#line 1139 "myparser.cpp"
=======
#line 1138 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 664 ".\\myparser.y"
=======
#line 663 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "%", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width); 
			offset += 1;
		
		
<<<<<<< HEAD
#line 1171 "myparser.cpp"
=======
#line 1168 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 687 ".\\myparser.y"
=======
#line 684 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("389 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1197 "myparser.cpp"
=======
#line 1194 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 701 ".\\myparser.y"
=======
#line 698 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("396 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Operator type r,  $4->type.addrmismatch."<<endl;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);	
			gen(newlabel(), "+", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
		
<<<<<<< HEAD
#line 1223 "myparser.cpp"
=======
#line 1219 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 715 ".\\myparser.y"
=======
#line 711 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("405 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="additive_exp";
			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || isComputable(yyattribute(3 - 3).ntnode->type.name))
				cout<<"Operator type mismatch."<<endl;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type.addr = offset;
			//gen(newlabel(), "DEC", $$->type.width, 0, $$->type.addr);
			gen(newlabel(), "-", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, offset);
			// offset += max($1->type.width, $3->type.width);
			offset += 1;
		
<<<<<<< HEAD
#line 1249 "myparser.cpp"
=======
#line 1244 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 732 ".\\myparser.y"
=======
#line 727 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("417 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="shift_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1275 "myparser.cpp"
=======
#line 1270 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 746 ".\\myparser.y"
=======
#line 741 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 1300 "myparser.cpp"
=======
#line 1295 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 759 ".\\myparser.y"
=======
#line 754 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 1325 "myparser.cpp"
=======
#line 1320 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 775 ".\\myparser.y"
=======
#line 770 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("445 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		    (*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1351 "myparser.cpp"
=======
#line 1346 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 789 ".\\myparser.y"
=======
#line 784 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			gen(newlabel(), "j<", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());
			gen(nextinstr, "j");
		
<<<<<<< HEAD
#line 1380 "myparser.cpp"
=======
#line 1375 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 806 ".\\myparser.y"
=======
#line 801 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("461 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="relational_exp";

			if (!isComputable(yyattribute(1 - 3).ntnode->type.name) || !isComputable(yyattribute(3 - 3).ntnode->type.name))
					cout<<"Relational expression type mismatch ."<<endl;
			gen(newlabel(), "j>", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());
			gen(nextinstr, "j");
		
<<<<<<< HEAD
#line 1405 "myparser.cpp"
=======
#line 1400 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 819 ".\\myparser.y"
=======
#line 814 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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

			gen(newlabel(), "j>", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(newlabel());
			gen(nextinstr, "j"); 
		
<<<<<<< HEAD
#line 1435 "myparser.cpp"
=======
#line 1430 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 837 ".\\myparser.y"
=======
#line 832 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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

			gen(newlabel(), "j<", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(newlabel());
			gen(nextinstr, "j");
		
<<<<<<< HEAD
#line 1465 "myparser.cpp"
=======
#line 1460 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 858 ".\\myparser.y"
=======
#line 853 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("491 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="equality_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1491 "myparser.cpp"
=======
#line 1486 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 872 ".\\myparser.y"
=======
#line 867 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			gen(newlabel(), "j=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr);  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(newlabel());       
			gen(nextinstr, "j"); 
		
<<<<<<< HEAD
#line 1521 "myparser.cpp"
=======
#line 1516 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 890 ".\\myparser.y"
=======
#line 885 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			
			int nextinstr = newlabel();
			gen(nextinstr, "j=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr);  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist->push_back(nextinstr); 
			nextinstr = newlabel();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist->push_back(nextinstr);    
			gen(nextinstr, "j"); 
		
<<<<<<< HEAD
#line 1554 "myparser.cpp"
=======
#line 1549 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 914 ".\\myparser.y"
=======
#line 909 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("519 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="and_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1580 "myparser.cpp"
=======
#line 1575 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 928 ".\\myparser.y"
=======
#line 923 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 1606 "myparser.cpp"
=======
#line 1601 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 945 ".\\myparser.y"
=======
#line 940 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("538 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exclusive_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1632 "myparser.cpp"
=======
#line 1627 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 959 ".\\myparser.y"
=======
#line 954 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 1658 "myparser.cpp"
=======
#line 1653 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 976 ".\\myparser.y"
=======
#line 971 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("557 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="inclusive_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1684 "myparser.cpp"
=======
#line 1679 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 990 ".\\myparser.y"
=======
#line 985 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 1710 "myparser.cpp"
=======
#line 1705 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1007 ".\\myparser.y"
=======
#line 1002 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("576 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_and_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1736 "myparser.cpp"
=======
#line 1731 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1021 ".\\myparser.y"
=======
#line 1016 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("583 ");
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
		
<<<<<<< HEAD
#line 1763 "myparser.cpp"
=======
#line 1758 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
			}
		}
		break;
	case 57:
		{
<<<<<<< HEAD
#line 1038 ".\\myparser.y"
=======
#line 1033 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("584 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="M";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->instr = nextinstr + 1;
		
<<<<<<< HEAD
#line 1776 "myparser.cpp"
=======
#line 1771 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		}
		break;
	case 58:
		{
<<<<<<< HEAD
#line 1047 ".\\myparser.y"
=======
#line 1042 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("585 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist->push_back(nextinstr + 1);
			gen(nextinstr+1, "j");
		
<<<<<<< HEAD
#line 1788 "myparser.cpp"
=======
#line 1783 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
<<<<<<< HEAD
#line 1057 ".\\myparser.y"
=======
#line 1052 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("595 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1814 "myparser.cpp"
=======
#line 1809 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1072 ".\\myparser.y"
=======
#line 1067 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("602 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="logical_or_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=boolnode;
			backpatch(yyattribute(1 - 4).ntnode->falselist, yyattribute(3 - 4).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist = merge(yyattribute(1 - 4).ntnode->truelist, yyattribute(4 - 4).ntnode->truelist);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(4 - 4).ntnode->falselist;
		
<<<<<<< HEAD
#line 1836 "myparser.cpp"
=======
#line 1831 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1085 ".\\myparser.y"
=======
#line 1080 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("614 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";		
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
			 
		
<<<<<<< HEAD
#line 1863 "myparser.cpp"
=======
#line 1858 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1100 ".\\myparser.y"
=======
#line 1095 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("621 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 5;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="conditional_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 5).ntnode->type;

			vector<string> v1;
			vector<string> v2;
			compare_traverse(&yyattribute(3 - 5).ntnode->type, v1);
			compare_traverse(&yyattribute(5 - 5).ntnode->type, v2);
			if (v1 == v2){
			//	cout<<"------\n";
				cout<<"|match|\n";
			//	cout<<"------\n";
			}	
			else{
			//	cout<<"-------\n"<<endl;
				cout<<"mismatch!\n"<<endl;
			//	cout<<"-------\n"<<endl;
			}			
		
<<<<<<< HEAD
#line 1897 "myparser.cpp"
=======
#line 1892 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1125 ".\\myparser.y"

			//(1)谓词表达式
			//(2)条件表达式 a<b?a:b
=======
#line 1120 ".\\myparser.y"

			//(1)???????
			//(2)???????? a<b?a:b
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("635 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 1923 "myparser.cpp"
=======
#line 1919 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1139 ".\\myparser.y"
=======
#line 1135 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("642 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="assignment_exp";
			  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(3 - 3).ntnode->type;
			if (check_type(&yyattribute(1 - 3).ntnode->type, &yyattribute(3 - 3).ntnode->type)){
			//	cout<<"----------------"<<endl;
				cout<<"|Two sides equal|"<<endl;
			//	cout<<"----------------"<<endl;
			}	
			else{
			//	cout<<"---------------------"<<endl;
				cout<<"|Two sides don't equal|"<<endl;
			//	cout<<"---------------------"<<endl;
			}
			gen(newlabel(), yyattribute(2 - 3).ntnode->name, yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, yyattribute(1 - 3).ntnode->type.addr);
			
<<<<<<< HEAD
#line 1955 "myparser.cpp"
=======
#line 1950 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1162 ".\\myparser.y"
=======
#line 1157 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("654 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 1975 "myparser.cpp"
=======
#line 1970 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1170 ".\\myparser.y"
=======
#line 1165 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("661 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="*=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 1995 "myparser.cpp"
=======
#line 1990 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1178 ".\\myparser.y"
=======
#line 1173 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("668 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="/=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2015 "myparser.cpp"
=======
#line 2010 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1186 ".\\myparser.y"
=======
#line 1181 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("675 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="%=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2035 "myparser.cpp"
=======
#line 2030 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1194 ".\\myparser.y"
=======
#line 1189 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("682 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="+=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2055 "myparser.cpp"
=======
#line 2050 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1202 ".\\myparser.y"
=======
#line 1197 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="-=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2075 "myparser.cpp"
=======
#line 2070 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1210 ".\\myparser.y"
=======
#line 1205 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("696 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="<<=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2095 "myparser.cpp"
=======
#line 2090 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1218 ".\\myparser.y"
=======
#line 1213 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("703 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name=">>=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2115 "myparser.cpp"
=======
#line 2110 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1226 ".\\myparser.y"
=======
#line 1221 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("710 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="&=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2135 "myparser.cpp"
=======
#line 2130 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1234 ".\\myparser.y"
=======
#line 1229 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("717 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="^=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2155 "myparser.cpp"
=======
#line 2150 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1242 ".\\myparser.y"
=======
#line 1237 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("724 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="|=";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2175 "myparser.cpp"
=======
#line 2170 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1253 ".\\myparser.y"
=======
#line 1248 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("740 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->truelist= yyattribute(1 - 1).ntnode->truelist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->falselist= yyattribute(1 - 1).ntnode->falselist;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(1 - 1).ntnode->nextlist;
		
<<<<<<< HEAD
#line 2199 "myparser.cpp"
=======
#line 2194 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1265 ".\\myparser.y"
=======
#line 1260 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("741 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(3 - 3).ntnode->type;
			
			gen(newlabel(), ",", yyattribute(1 - 3).ntnode->instr, yyattribute(3 - 3).ntnode->instr, yyattribute(3 - 3).ntnode->type.addr);
		
<<<<<<< HEAD
#line 2224 "myparser.cpp"
=======
#line 2219 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1281 ".\\myparser.y"
=======
#line 1276 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("753 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="constant_exp";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->dvalue = yyattribute(1 - 1).ntnode->dvalue;
		
<<<<<<< HEAD
#line 2246 "myparser.cpp"
=======
#line 2241 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1294 ".\\myparser.y"
=======
#line 1289 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("763 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
		
<<<<<<< HEAD
#line 2267 "myparser.cpp"
=======
#line 2262 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1303 ".\\myparser.y"
=======
#line 1298 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("771 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 3).ntnode->type;		
		
<<<<<<< HEAD
#line 2291 "myparser.cpp"
=======
#line 2286 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1321 ".\\myparser.y"
=======
#line 1316 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
 //static
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("783 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
<<<<<<< HEAD
#line 2312 "myparser.cpp"
=======
#line 2307 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1331 ".\\myparser.y"
=======
#line 1326 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("791 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
<<<<<<< HEAD
#line 2334 "myparser.cpp"
=======
#line 2329 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1341 ".\\myparser.y"
 // int
=======
#line 1336 ".\\myparser.y"
 // int int*
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("799 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
<<<<<<< HEAD
#line 2355 "myparser.cpp"
=======
#line 2350 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1350 ".\\myparser.y"
=======
#line 1345 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
 // lont int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("806 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
<<<<<<< HEAD
#line 2377 "myparser.cpp"
=======
#line 2372 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1360 ".\\myparser.y"
=======
#line 1355 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
 //const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("814 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;	
		
<<<<<<< HEAD
#line 2398 "myparser.cpp"
=======
#line 2393 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1369 ".\\myparser.y"
=======
#line 1364 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
 //const int
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("821 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declaration_specifiers";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 2).ntnode->type;	
		
<<<<<<< HEAD
#line 2420 "myparser.cpp"
=======
#line 2415 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1382 ".\\myparser.y"
=======
#line 1377 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("832 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;	
		
<<<<<<< HEAD
#line 2442 "myparser.cpp"
=======
#line 2437 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1392 ".\\myparser.y"
=======
#line 1387 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;		
		
<<<<<<< HEAD
#line 2464 "myparser.cpp"
=======
#line 2459 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1405 ".\\myparser.y"
=======
#line 1400 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("851 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="init_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2484 "myparser.cpp"
=======
#line 2479 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1413 ".\\myparser.y"
=======
#line 1408 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			show_string(v1);
			show_string(v2);
			if (check_type(&(yyattribute(1 - 3).ntnode->type), &(yyattribute(3 - 3).ntnode->type))){
			//	cout<<"-------"<<endl;
				cout<<"|match!|"<<endl;
			//	cout<<"-------"<<endl;
			}
			else{
			//	cout<<"----------"<<endl;
				cout<<"|!mismatch|"<<endl;
			//	cout<<"-----------"<<endl;
			}
			gen(newlabel(), "=", yyattribute(1 - 3).ntnode->type.addr, yyattribute(3 - 3).ntnode->type.addr, yyattribute(1 - 3).ntnode->type.addr);
		
<<<<<<< HEAD
#line 2526 "myparser.cpp"
=======
#line 2521 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1446 ".\\myparser.y"
=======
#line 1441 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("870 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;			
		
<<<<<<< HEAD
#line 2546 "myparser.cpp"
=======
#line 2541 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1454 ".\\myparser.y"
=======
#line 1449 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("877 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 2566 "myparser.cpp"
=======
#line 2561 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1462 ".\\myparser.y"
=======
#line 1457 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("884 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 2586 "myparser.cpp"
=======
#line 2581 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1470 ".\\myparser.y"
=======
#line 1465 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 2606 "myparser.cpp"
=======
#line 2601 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1478 ".\\myparser.y"
=======
#line 1473 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("898 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="storage_class_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
<<<<<<< HEAD
#line 2626 "myparser.cpp"
=======
#line 2621 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1489 ".\\myparser.y"
=======
#line 1484 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			wFlag(voidnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=voidnode;
		
<<<<<<< HEAD
#line 2648 "myparser.cpp"
=======
#line 2643 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1499 ".\\myparser.y"
=======
#line 1494 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("915 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(charnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=charnode;
		
<<<<<<< HEAD
#line 2670 "myparser.cpp"
=======
#line 2665 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1509 ".\\myparser.y"
=======
#line 1504 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("922 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(shortnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=shortnode;
		
<<<<<<< HEAD
#line 2692 "myparser.cpp"
=======
#line 2687 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1519 ".\\myparser.y"
=======
#line 1514 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("929 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(intnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=intnode;
		
<<<<<<< HEAD
#line 2714 "myparser.cpp"
=======
#line 2709 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1529 ".\\myparser.y"
=======
#line 1524 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("936 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(longnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=longnode;
		
<<<<<<< HEAD
#line 2736 "myparser.cpp"
=======
#line 2731 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1539 ".\\myparser.y"
=======
#line 1534 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("943 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(floatnode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=floatnode;
		
<<<<<<< HEAD
#line 2758 "myparser.cpp"
=======
#line 2753 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1549 ".\\myparser.y"
=======
#line 1544 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("950 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
			wFlag(doublenode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=doublenode;
		
<<<<<<< HEAD
#line 2780 "myparser.cpp"
=======
#line 2775 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1559 ".\\myparser.y"
=======
#line 1554 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("957 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(signednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=signednode;
		
<<<<<<< HEAD
#line 2802 "myparser.cpp"
=======
#line 2797 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1569 ".\\myparser.y"
=======
#line 1564 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
			wFlag(unsignednode);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=unsignednode;
		
<<<<<<< HEAD
#line 2824 "myparser.cpp"
=======
#line 2819 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1579 ".\\myparser.y"
=======
#line 1574 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;

			wFlag(yyattribute(1 - 1).ntnode->type);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> type = yyattribute(1 - 1).ntnode -> type;

		
<<<<<<< HEAD
#line 2848 "myparser.cpp"
=======
#line 2843 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1591 ".\\myparser.y"
=======
#line 1586 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("978 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2868 "myparser.cpp"
=======
#line 2863 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1599 ".\\myparser.y"
=======
#line 1594 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("985 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;		
		
<<<<<<< HEAD
#line 2888 "myparser.cpp"
=======
#line 2883 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1607 ".\\myparser.y"
=======
#line 1602 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode=new node();
			printf("999 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_specifier";
		
<<<<<<< HEAD
#line 2902 "myparser.cpp"
=======
#line 2901 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1612 ".\\myparser.y"
=======
#line 1611 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("986 ");
			wFlag(*(create_struct(yyattribute(2 - 5).ntnode->name)));
		
<<<<<<< HEAD
#line 2919 "myparser.cpp"
=======
#line 2918 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1618 ".\\myparser.y"
=======
#line 1617 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			static int i = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("987 ");
			wFlag(*(create_struct("struct" + to_string(i))));
			s.back()->vartable["struct" + to_string(i++)] = rFlag();
		
<<<<<<< HEAD
#line 2938 "myparser.cpp"
=======
#line 2937 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1627 ".\\myparser.y"
=======
#line 1626 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("988 ");
		
<<<<<<< HEAD
#line 2954 "myparser.cpp"
=======
#line 2953 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1631 ".\\myparser.y"
=======
#line 1630 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("989 ");
		
<<<<<<< HEAD
#line 2970 "myparser.cpp"
=======
#line 2969 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1637 ".\\myparser.y"
=======
#line 1636 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("990 ");
		
<<<<<<< HEAD
#line 2986 "myparser.cpp"
=======
#line 2985 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1641 ".\\myparser.y"
=======
#line 1640 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("991 ");
			
			map<string, typenode*>::iterator i;
			if ((i = auto_define_type.find(yyattribute(2 - 2).ntnode->name)) != auto_define_type.end())
			{
				(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *auto_define_type[yyattribute(2 - 2).ntnode->name];
			}
			else cout << "struct doesn't exist!\n";
		
<<<<<<< HEAD
#line 3009 "myparser.cpp"
=======
#line 3008 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1730 ".\\myparser.y"
=======
#line 1729 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1027 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
<<<<<<< HEAD
#line 3029 "myparser.cpp"
=======
#line 3028 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1738 ".\\myparser.y"
=======
#line 1737 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1034 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_or_union";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
<<<<<<< HEAD
#line 3049 "myparser.cpp"
=======
#line 3048 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1749 ".\\myparser.y"
=======
#line 1748 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1044 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;	
		
<<<<<<< HEAD
#line 3069 "myparser.cpp"
=======
#line 3068 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1757 ".\\myparser.y"
=======
#line 1756 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1051 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;		
		
<<<<<<< HEAD
#line 3090 "myparser.cpp"
=======
#line 3089 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1769 ".\\myparser.y"
=======
#line 1768 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1062 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 3112 "myparser.cpp"
=======
#line 3111 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1779 ".\\myparser.y"
=======
#line 1778 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1062 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 3134 "myparser.cpp"
=======
#line 3133 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1792 ".\\myparser.y"
=======
#line 1791 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1074 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 3155 "myparser.cpp"
=======
#line 3154 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1801 ".\\myparser.y"
=======
#line 1800 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1082 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3175 "myparser.cpp"
=======
#line 3174 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1809 ".\\myparser.y"
=======
#line 1808 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1089 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 3196 "myparser.cpp"
=======
#line 3195 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1818 ".\\myparser.y"
=======
#line 1817 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1097 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="specifier_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3216 "myparser.cpp"
=======
#line 3215 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1829 ".\\myparser.y"
=======
#line 1828 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1107 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3236 "myparser.cpp"
=======
#line 3235 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1837 ".\\myparser.y"
=======
#line 1836 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1114 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 3258 "myparser.cpp"
=======
#line 3257 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1850 ".\\myparser.y"
=======
#line 1849 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1126 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3278 "myparser.cpp"
=======
#line 3277 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1858 ".\\myparser.y"
=======
#line 1857 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1133 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 3299 "myparser.cpp"
=======
#line 3298 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1867 ".\\myparser.y"
=======
#line 1866 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1141 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="struct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 3321 "myparser.cpp"
=======
#line 3320 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1880 ".\\myparser.y"
=======
#line 1879 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
		
<<<<<<< HEAD
#line 3344 "myparser.cpp"
=======
#line 3343 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1891 ".\\myparser.y"
=======
#line 1890 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
		
<<<<<<< HEAD
#line 3368 "myparser.cpp"
=======
#line 3367 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1903 ".\\myparser.y"
=======
#line 1902 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1174 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enum_specifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 3389 "myparser.cpp"
=======
#line 3388 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1915 ".\\myparser.y"
=======
#line 1914 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1185 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3409 "myparser.cpp"
=======
#line 3408 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1923 ".\\myparser.y"
=======
#line 1922 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1192 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator_list";
		
<<<<<<< HEAD
#line 3427 "myparser.cpp"
=======
#line 3426 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1932 ".\\myparser.y"
=======
#line 1931 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1204 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3447 "myparser.cpp"
=======
#line 3446 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1940 ".\\myparser.y"
=======
#line 1939 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1211 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="enumerator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 3469 "myparser.cpp"
=======
#line 3468 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1953 ".\\myparser.y"
=======
#line 1952 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1223 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3489 "myparser.cpp"
=======
#line 3488 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1961 ".\\myparser.y"
=======
#line 1960 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1230 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="type_qualifier";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3509 "myparser.cpp"
=======
#line 3508 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1972 ".\\myparser.y"
=======
#line 1971 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1240 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
		
<<<<<<< HEAD
#line 3527 "myparser.cpp"
=======
#line 3526 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1978 ".\\myparser.y"
=======
#line 1977 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1248 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
<<<<<<< HEAD
#line 3548 "myparser.cpp"
=======
#line 3547 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1989 ".\\myparser.y"
=======
#line 1988 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			fun_name = var_name;
			fun_addr = yyattribute(1 - 2).ntnode->type.addr;
		
<<<<<<< HEAD
#line 3564 "myparser.cpp"
=======
#line 3563 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 1996 ".\\myparser.y"
=======
#line 1995 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1258 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			var_name = yyattribute(1 - 1).ntnode->name;
			////gen(newlabel(), "DEC", $1.ntnode->type.width, 0, $1.ntnode->type.addr);
			//cout << $1.ntnode->name << rFlag()->width << endl;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			int temp = yyattribute(1 - 1).ntnode->type.addr;
			yyattribute(1 - 1).ntnode->type = *rFlag();
			yyattribute(1 - 1).ntnode->type.addr = temp;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
			// offset += rFlag()->width;
			offset += 1;
			//gen(newlabel(), "DEC", $1.ntnode->type.width, 0, $1.ntnode->type.addr);
		
<<<<<<< HEAD
#line 3593 "myparser.cpp"
=======
#line 3591 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2013 ".\\myparser.y"
=======
#line 2011 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 3617 "myparser.cpp"
=======
#line 3615 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2025 ".\\myparser.y"
=======
#line 2023 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			int tmp = yyattribute(1 - 4).ntnode->type.addr;
			rFlag()->addr = tmp;
			s.back()->vartable[var_name] = rFlag();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = *rFlag();
			yyattribute(1 - 4).ntnode->type = *rFlag();
			// offset += rFlag()->width;
			offset += 1;
			//gen(newlabel(), "DEC", $1->type.width, 0, $1->type.addr);
			//traverse(root);
		
<<<<<<< HEAD
#line 3669 "myparser.cpp"
=======
#line 3666 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2065 ".\\myparser.y"
=======
#line 2062 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1284 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 3691 "myparser.cpp"
=======
#line 3688 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2075 ".\\myparser.y"
=======
#line 2072 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1293 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [4];
		
<<<<<<< HEAD
#line 3710 "myparser.cpp"
=======
#line 3707 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2082 ".\\myparser.y"
=======
#line 2079 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1303 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}	
			s.pop_back();  
		
<<<<<<< HEAD
#line 3733 "myparser.cpp"
=======
#line 3730 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2093 ".\\myparser.y"
=======
#line 2090 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1313 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->name="direct_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->children=new node* [3];
			fun_name = var_name;

			gen(newlabel(), "fun", 0, 0, 0);
		
<<<<<<< HEAD
#line 3755 "myparser.cpp"
=======
#line 3752 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2106 ".\\myparser.y"
=======
#line 2103 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			traverse(temp);
		
<<<<<<< HEAD
#line 3782 "myparser.cpp"
=======
#line 3779 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2121 ".\\myparser.y"
=======
#line 2118 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
 // *const
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 3802 "myparser.cpp"
=======
#line 3799 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2129 ".\\myparser.y"
=======
#line 2126 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
		
<<<<<<< HEAD
#line 3828 "myparser.cpp"
=======
#line 3825 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2143 ".\\myparser.y"
=======
#line 2140 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
 //*const*
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node ();
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "pointer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
		
<<<<<<< HEAD
#line 3848 "myparser.cpp"
=======
#line 3845 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2154 ".\\myparser.y"
=======
#line 2151 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1359 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3868 "myparser.cpp"
=======
#line 3865 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2162 ".\\myparser.y"
=======
#line 2159 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1366 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_qualifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 3889 "myparser.cpp"
=======
#line 3886 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2175 ".\\myparser.y"
=======
#line 2172 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1378 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			type3->left = rFlag();

			gen(newlabel(), "fun", 0, 0, 0);
		
<<<<<<< HEAD
#line 3913 "myparser.cpp"
=======
#line 3910 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2187 ".\\myparser.y"
=======
#line 2184 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1385 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_type_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 3935 "myparser.cpp"
=======
#line 3932 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2200 ".\\myparser.y"
=======
#line 2197 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1397 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 3955 "myparser.cpp"
=======
#line 3952 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2208 ".\\myparser.y"
=======
#line 2205 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 3983 "myparser.cpp"
=======
#line 3980 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2227 ".\\myparser.y"
=======
#line 2224 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1416 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			gen(newlabel(), "param", 0, 0, yyattribute(2 - 2).ntnode -> type.addr);
		
<<<<<<< HEAD
#line 4005 "myparser.cpp"
=======
#line 4002 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2237 ".\\myparser.y"
=======
#line 2234 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1424 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 4025 "myparser.cpp"
=======
#line 4022 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2245 ".\\myparser.y"
=======
#line 2242 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1431 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "parameter_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4045 "myparser.cpp"
=======
#line 4042 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2256 ".\\myparser.y"
=======
#line 2253 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1441 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			int tmp = yyattribute(1 - 1).ntnode->type.addr;
			rFlag()->addr = tmp;
			s.back()->vartable[yyattribute(1 - 1).ntnode->name] = rFlag();
			// offset += rFlag()->width;
			offset += 1;
			yyattribute(1 - 1).ntnode->type = *rFlag();
			//gen(newlabel(), "DEC", $1.ntnode->type.width, 0, $1.ntnode->type.addr);
		
<<<<<<< HEAD
#line 4072 "myparser.cpp"
=======
#line 4068 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2271 ".\\myparser.y"
=======
#line 2267 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1448 ");   
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "identifier_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			int tmp = yyattribute(3 - 3).ntnode->type.addr;
			rFlag()->addr = tmp;
			s.back()->vartable[yyattribute(3 - 3).ntnode->name] = rFlag();	
			// offset += rFlag()->width;
			offset += 1;
			yyattribute(3 - 3).ntnode->type = *rFlag();
			//gen(newlabel(), "DEC", $3.ntnode->type.width, 0, $3.ntnode->type.addr);
		
<<<<<<< HEAD
#line 4101 "myparser.cpp"
=======
#line 4096 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2291 ".\\myparser.y"
=======
#line 2286 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1460 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4121 "myparser.cpp"
=======
#line 4116 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2299 ".\\myparser.y"
=======
#line 2294 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1467 ");  
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "type_name";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 4142 "myparser.cpp"
=======
#line 4137 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2311 ".\\myparser.y"
=======
#line 2306 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1478 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4162 "myparser.cpp"
=======
#line 4157 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2319 ".\\myparser.y"
=======
#line 2314 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1485 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4182 "myparser.cpp"
=======
#line 4177 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2327 ".\\myparser.y"
=======
#line 2322 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1492 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 4203 "myparser.cpp"
=======
#line 4198 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2339 ".\\myparser.y"
=======
#line 2334 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1503 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
<<<<<<< HEAD
#line 4226 "myparser.cpp"
=======
#line 4221 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2350 ".\\myparser.y"
=======
#line 2345 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1512 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;		
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 4247 "myparser.cpp"
=======
#line 4242 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2359 ".\\myparser.y"
=======
#line 2354 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1520 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 4269 "myparser.cpp"
=======
#line 4264 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2369 ".\\myparser.y"
=======
#line 2364 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1529 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 4291 "myparser.cpp"
=======
#line 4286 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2379 ".\\myparser.y"
=======
#line 2374 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1538 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
<<<<<<< HEAD
#line 4314 "myparser.cpp"
=======
#line 4309 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2390 ".\\myparser.y"
=======
#line 2385 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1548 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			s.pop_back();  
		
<<<<<<< HEAD
#line 4336 "myparser.cpp"
=======
#line 4331 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2400 ".\\myparser.y"
=======
#line 2395 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1556 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
<<<<<<< HEAD
#line 4359 "myparser.cpp"
=======
#line 4354 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2411 ".\\myparser.y"
=======
#line 2406 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1565 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "direct_abstract_declarator";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
			s.pop_back();  
		
<<<<<<< HEAD
#line 4382 "myparser.cpp"
=======
#line 4377 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2422 ".\\myparser.y"
=======
#line 2417 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
		
<<<<<<< HEAD
#line 4406 "myparser.cpp"
=======
#line 4401 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2437 ".\\myparser.y"
=======
#line 2432 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1587 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type = yyattribute(1 - 1).ntnode->type;
		
<<<<<<< HEAD
#line 4428 "myparser.cpp"
=======
#line 4423 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2447 ".\\myparser.y"
=======
#line 2442 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1594 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 4450 "myparser.cpp"
=======
#line 4445 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2457 ".\\myparser.y"
=======
#line 2452 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1603 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 4;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [4];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 4).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[3] = yyattribute(4 - 4).ntnode;
		
<<<<<<< HEAD
#line 4473 "myparser.cpp"
=======
#line 4468 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2471 ".\\myparser.y"
=======
#line 2466 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1616 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4493 "myparser.cpp"
=======
#line 4488 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2479 ".\\myparser.y"
=======
#line 2474 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1623 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "initializer_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 4515 "myparser.cpp"
=======
#line 4510 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2491 ".\\myparser.y"
=======
#line 2486 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1635 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
<<<<<<< HEAD
#line 4532 "myparser.cpp"
=======
#line 4527 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2496 ".\\myparser.y"
=======
#line 2491 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1642 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
<<<<<<< HEAD
#line 4549 "myparser.cpp"
=======
#line 4544 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2501 ".\\myparser.y"
=======
#line 2496 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1643 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
<<<<<<< HEAD
#line 4566 "myparser.cpp"
=======
#line 4561 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2506 ".\\myparser.y"
=======
#line 2501 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1643 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
<<<<<<< HEAD
#line 4583 "myparser.cpp"
=======
#line 4578 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2513 ".\\myparser.y"
=======
#line 2508 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1644 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
<<<<<<< HEAD
#line 4605 "myparser.cpp"
=======
#line 4600 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2523 ".\\myparser.y"
=======
#line 2518 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1669 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "xx";
		
<<<<<<< HEAD
#line 4622 "myparser.cpp"
=======
#line 4617 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2528 ".\\myparser.y"
=======
#line 2523 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1670 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "other";
		
<<<<<<< HEAD
#line 4639 "myparser.cpp"
=======
#line 4634 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2535 ".\\myparser.y"

		
	
#line 4654 "myparser.cpp"
=======
#line 2530 ".\\myparser.y"

		
	
#line 4649 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2539 ".\\myparser.y"
=======
#line 2534 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1680 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 4676 "myparser.cpp"
=======
#line 4671 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2549 ".\\myparser.y"
=======
#line 2544 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1689 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
<<<<<<< HEAD
#line 4693 "myparser.cpp"
=======
#line 4688 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2554 ".\\myparser.y"
=======
#line 2549 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1699 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "labeled_statement";
		
<<<<<<< HEAD
#line 4710 "myparser.cpp"
=======
#line 4705 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2562 ".\\myparser.y"
=======
#line 2557 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1711 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 4731 "myparser.cpp"
=======
#line 4726 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2571 ".\\myparser.y"
=======
#line 2566 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1719 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
<<<<<<< HEAD
#line 4749 "myparser.cpp"
=======
#line 4744 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2577 ".\\myparser.y"
=======
#line 2572 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1728 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";	
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(2 - 3).ntnode->nextlist;
		
<<<<<<< HEAD
#line 4767 "myparser.cpp"
=======
#line 4764 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2583 ".\\myparser.y"
=======
#line 2580 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1737 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "compound_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist= yyattribute(3 - 4).ntnode->nextlist ;
		
<<<<<<< HEAD
#line 4785 "myparser.cpp"
=======
#line 4782 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2592 ".\\myparser.y"
=======
#line 2589 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1750 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;

			traverse_vartable(s.size() - 1);
		
<<<<<<< HEAD
#line 4807 "myparser.cpp"
=======
#line 4804 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2602 ".\\myparser.y"
=======
#line 2599 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1757 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "declaration_list";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =yyattribute(3 - 3).ntnode->nextlist; 
		
<<<<<<< HEAD
#line 4826 "myparser.cpp"
=======
#line 4823 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2612 ".\\myparser.y"
=======
#line 2609 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1768 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4846 "myparser.cpp"
=======
#line 4843 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2620 ".\\myparser.y"
=======
#line 2617 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			//cout<<"$2->instr:"<<$2->instr<<endl;
			printf("1775 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "statement_list";
			backpatch(yyattribute(1 - 3).ntnode->nextlist , yyattribute(2 - 3).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =yyattribute(3 - 3).ntnode->nextlist; 
		
<<<<<<< HEAD
#line 4866 "myparser.cpp"
=======
#line 4863 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2631 ".\\myparser.y"
=======
#line 2628 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1786 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4886 "myparser.cpp"
=======
#line 4883 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2639 ".\\myparser.y"
=======
#line 2636 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1793 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "exp_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 4907 "myparser.cpp"
=======
#line 4904 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2650 ".\\myparser.y"
=======
#line 2647 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1794 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type;
		
<<<<<<< HEAD
#line 4928 "myparser.cpp"
=======
#line 4925 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2659 ".\\myparser.y"
=======
#line 2656 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node(); 
			printf("1795 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "stmt";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 4948 "myparser.cpp"
=======
#line 4945 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2669 ".\\myparser.y"
=======
#line 2666 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1803 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
			s.pop_back();
			traverse_vartable(s.size() - 1);	 					
		
<<<<<<< HEAD
#line 4970 "myparser.cpp"
=======
#line 4967 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2679 ".\\myparser.y"
=======
#line 2676 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1815 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "matched_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
			traverse_vartable(s.size() - 1);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(1 - 1).ntnode->type; 
		
<<<<<<< HEAD
#line 4992 "myparser.cpp"
=======
#line 4989 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2691 ".\\myparser.y"
=======
#line 2688 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1816 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->type=yyattribute(6 - 6).ntnode->type;
			s.pop_back();
			traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 6).ntnode->truelist, yyattribute(5 - 6).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist =merge(yyattribute(3 - 6).ntnode->falselist, yyattribute(6 - 6).ntnode->nextlist); 
			 
		
<<<<<<< HEAD
#line 5015 "myparser.cpp"
=======
#line 5012 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2702 ".\\myparser.y"
=======
#line 2699 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1817 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "open_statement";
			s.pop_back();
			traverse_vartable(s.size() - 1);
			backpatch(yyattribute(3 - 10).ntnode->truelist, yyattribute(5 - 10).ntnode->instr);  
			backpatch(yyattribute(3 - 10).ntnode->falselist, yyattribute(9 - 10).ntnode->instr);    
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=merge(yyattribute(6 - 10).ntnode->nextlist, yyattribute(7 - 10).ntnode->nextlist, yyattribute(10 - 10).ntnode->nextlist); 	
		
<<<<<<< HEAD
#line 5037 "myparser.cpp"
=======
#line 5034 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2714 ".\\myparser.y"
=======
#line 2711 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1818 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 5057 "myparser.cpp"
=======
#line 5054 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2722 ".\\myparser.y"
=======
#line 2719 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1825 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "selection_statement";
			s.pop_back();  
		
<<<<<<< HEAD
#line 5075 "myparser.cpp"
=======
#line 5072 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2730 ".\\myparser.y"
=======
#line 2727 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

		    // $$->type = $3->type;
			// offset += $$->type.width;
			// switch_addr = $$->type.addr;			
			// gen(newlabel(), "=", $$->type.addr, 0, $3->type.addr);
			// default_label=newlabel();
			// gen(nextinstr,"j",0,0,default_label);
	
<<<<<<< HEAD
#line 5095 "myparser.cpp"
=======
#line 5092 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2740 ".\\myparser.y"
=======
#line 2737 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1839 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(4 - 7).ntnode->truelist, yyattribute(6 - 7).ntnode->instr); 
			backpatch(yyattribute(7 - 7).ntnode->nextlist, yyattribute(2 - 7).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(4 - 7).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(2 - 7).ntnode->instr) ; 
			s.pop_back();
		
<<<<<<< HEAD
#line 5117 "myparser.cpp"
=======
#line 5114 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2750 ".\\myparser.y"
=======
#line 2747 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1850 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			backpatch(yyattribute(7 - 9).ntnode->truelist, yyattribute(2 - 9).ntnode->instr); 
			backpatch(yyattribute(3 - 9).ntnode->nextlist, yyattribute(5 - 9).ntnode->instr); 
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist = yyattribute(7 - 9).ntnode->falselist;
			gen(newlabel(), "j", 0, 0, yyattribute(5 - 9).ntnode->instr) ; 
			s.pop_back(); 
		
<<<<<<< HEAD
#line 5139 "myparser.cpp"
=======
#line 5136 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2760 ".\\myparser.y"
=======
#line 2757 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1863 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "iteration_statement";
			map<string, typenode*>::iterator iter;
			for(iter = s.back()->vartable.begin();iter!=s.back()->vartable.end();iter++){
				s[s.size()-2]->vartable[iter->first] = iter->second;
			}
			backpatch(yyattribute(5 - 8).ntnode->truelist, yyattribute(8 - 8).ntnode->instr);
			backpatch(yyattribute(8 - 8).ntnode->nextlist, yyattribute(5 - 8).ntnode->instr);
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode->nextlist=yyattribute(5 - 8).ntnode->falselist;
			s.pop_back();		  
		
<<<<<<< HEAD
#line 5164 "myparser.cpp"
=======
#line 5161 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2773 ".\\myparser.y"
=======
#line 2770 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1875 ");
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
		
<<<<<<< HEAD
#line 5192 "myparser.cpp"
=======
#line 5189 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2792 ".\\myparser.y"
=======
#line 2789 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1891 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;
		
<<<<<<< HEAD
#line 5214 "myparser.cpp"
=======
#line 5211 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2802 ".\\myparser.y"
=======
#line 2799 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1900 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 5235 "myparser.cpp"
=======
#line 5232 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2811 ".\\myparser.y"
=======
#line 2808 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1908 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 5256 "myparser.cpp"
=======
#line 5253 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2820 ".\\myparser.y"
=======
#line 2817 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1916 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			rtn_stmt.push(&voidnode);		
		
<<<<<<< HEAD
#line 5278 "myparser.cpp"
=======
#line 5275 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2830 ".\\myparser.y"
=======
#line 2827 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1924 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "jump_statement";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;	
			rtn_stmt.push(&(yyattribute(2 - 3).ntnode->type));	
		
<<<<<<< HEAD
#line 5301 "myparser.cpp"
=======
#line 5298 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2844 ".\\myparser.y"
=======
#line 2841 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1946 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 5321 "myparser.cpp"
=======
#line 5319 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2852 ".\\myparser.y"
=======
#line 2850 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1953 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "translation_unit";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
		
<<<<<<< HEAD
#line 5342 "myparser.cpp"
=======
#line 5341 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2864 ".\\myparser.y"
=======
#line 2863 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1964 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 1;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [1];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 5362 "myparser.cpp"
=======
#line 5361 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2872 ".\\myparser.y"
=======
#line 2871 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1971 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "external_declaration";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 1).ntnode;
		
<<<<<<< HEAD
#line 5382 "myparser.cpp"
=======
#line 5381 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2883 ".\\myparser.y"
=======
#line 2882 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1981 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			type3->right = &(yyattribute(1 - 4).ntnode->type);
			s.back()->vartable[fun_name] = type3;
			//gen(newlabel(), "DEC", -1, 0, fun_addr);
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
		
<<<<<<< HEAD
#line 5415 "myparser.cpp"
=======
#line 5414 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2904 ".\\myparser.y"
=======
#line 2903 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("1991 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 3;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [3];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 3).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[2] = yyattribute(3 - 3).ntnode;

			type3->right = &(yyattribute(1 - 3).ntnode->type);
			s[s.size()-2]->vartable[fun_name] = type3;
			cout<<"/./././././././"<<fun_addr<<endl;
			//gen(newlabel(), "DEC", -1, 0, fun_addr);

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
		
<<<<<<< HEAD
#line 5456 "myparser.cpp"
=======
#line 5455 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2933 ".\\myparser.y"
=======
#line 2932 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

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
			cout<<"/./././././././"<<fun_addr<<endl;
			//gen(newlabel(), "DEC", -1, 0, fun_addr);
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
		
<<<<<<< HEAD
#line 5494 "myparser.cpp"
=======
#line 5493 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2959 ".\\myparser.y"
=======
#line 2958 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a

			(*(YYSTYPE YYFAR*)yyvalptr).ntnode = new node();
			printf("2009 ");
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> name = "function_definition";
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> length = 2;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children = new node* [2];
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[0] = yyattribute(1 - 2).ntnode;
			(*(YYSTYPE YYFAR*)yyvalptr).ntnode -> children[1] = yyattribute(2 - 2).ntnode;
			type3->right = &(yyattribute(1 - 2).ntnode->type);
			s.back()->vartable[fun_name] = type3;
			cout<<"/./././././././"<<fun_addr<<endl;
			//gen(newlabel(), "DEC", -1, 0, fun_addr);
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
		
<<<<<<< HEAD
#line 5531 "myparser.cpp"
=======
#line 5530 "myparser.cpp"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
		{ 136, YYAT_SHIFT, 83 },
		{ 355, YYAT_ERROR, 0 },
		{ 134, YYAT_SHIFT, 230 },
		{ 43, YYAT_SHIFT, 2 },
		{ 113, YYAT_SHIFT, 207 },
		{ 136, YYAT_SHIFT, 84 },
		{ 75, YYAT_SHIFT, 164 },
		{ 136, YYAT_SHIFT, 85 },
		{ 75, YYAT_SHIFT, 2 },
		{ 136, YYAT_SHIFT, 86 },
		{ 136, YYAT_SHIFT, 87 },
		{ 2, YYAT_SHIFT, 2 },
		{ 136, YYAT_SHIFT, 88 },
		{ 367, YYAT_SHIFT, 83 },
		{ 155, YYAT_SHIFT, 1 },
		{ 166, YYAT_SHIFT, 164 },
		{ 155, YYAT_SHIFT, 2 },
		{ 164, YYAT_SHIFT, 164 },
		{ 367, YYAT_SHIFT, 84 },
		{ 39, YYAT_SHIFT, 69 },
		{ 367, YYAT_SHIFT, 85 },
		{ 29, YYAT_SHIFT, 51 },
		{ 367, YYAT_SHIFT, 86 },
		{ 367, YYAT_SHIFT, 87 },
		{ 99, YYAT_SHIFT, 184 },
		{ 367, YYAT_SHIFT, 88 },
		{ 136, YYAT_SHIFT, 119 },
		{ 23, YYAT_SHIFT, 44 },
		{ 25, YYAT_ACCEPT, 0 },
		{ 316, YYAT_SHIFT, 337 },
		{ 99, YYAT_SHIFT, 185 },
		{ 173, YYAT_SHIFT, 171 },
		{ 179, YYAT_SHIFT, 4 },
		{ 264, YYAT_ERROR, 0 },
		{ 264, YYAT_SHIFT, 320 },
		{ 264, YYAT_ERROR, 0 },
		{ 175, YYAT_SHIFT, 270 },
		{ 271, YYAT_SHIFT, 270 },
		{ 175, YYAT_SHIFT, 2 },
		{ 367, YYAT_SHIFT, 119 },
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
		{ 362, YYAT_SHIFT, 366 },
		{ 228, YYAT_SHIFT, 246 },
		{ 365, YYAT_SHIFT, 91 },
		{ 75, YYAT_SHIFT, 165 },
		{ 278, YYAT_SHIFT, 246 },
		{ 67, YYAT_SHIFT, 155 },
		{ 263, YYAT_SHIFT, 264 },
		{ 32, YYAT_SHIFT, 2 },
		{ 167, YYAT_SHIFT, 264 },
		{ 49, YYAT_SHIFT, 46 },
		{ 24, YYAT_SHIFT, 46 },
		{ 355, YYAT_ERROR, 0 },
		{ 166, YYAT_SHIFT, 165 },
=======
		{ 143, YYAT_SHIFT, 90 },
		{ 355, YYAT_ERROR, 0 },
		{ 121, YYAT_SHIFT, 213 },
		{ 42, YYAT_SHIFT, 2 },
		{ 132, YYAT_SHIFT, 240 },
		{ 143, YYAT_SHIFT, 91 },
		{ 71, YYAT_SHIFT, 160 },
		{ 143, YYAT_SHIFT, 92 },
		{ 71, YYAT_SHIFT, 2 },
		{ 143, YYAT_SHIFT, 93 },
		{ 143, YYAT_SHIFT, 94 },
		{ 2, YYAT_SHIFT, 2 },
		{ 143, YYAT_SHIFT, 95 },
		{ 367, YYAT_SHIFT, 90 },
		{ 83, YYAT_SHIFT, 1 },
		{ 165, YYAT_SHIFT, 160 },
		{ 83, YYAT_SHIFT, 2 },
		{ 160, YYAT_SHIFT, 160 },
		{ 367, YYAT_SHIFT, 91 },
		{ 38, YYAT_SHIFT, 69 },
		{ 367, YYAT_SHIFT, 92 },
		{ 25, YYAT_SHIFT, 50 },
		{ 367, YYAT_SHIFT, 93 },
		{ 367, YYAT_SHIFT, 94 },
		{ 119, YYAT_SHIFT, 204 },
		{ 367, YYAT_SHIFT, 95 },
		{ 143, YYAT_SHIFT, 96 },
		{ 23, YYAT_SHIFT, 44 },
		{ 36, YYAT_ACCEPT, 0 },
		{ 270, YYAT_SHIFT, 324 },
		{ 119, YYAT_SHIFT, 205 },
		{ 173, YYAT_SHIFT, 171 },
		{ 187, YYAT_SHIFT, 4 },
		{ 260, YYAT_ERROR, 0 },
		{ 260, YYAT_SHIFT, 320 },
		{ 260, YYAT_ERROR, 0 },
		{ 183, YYAT_SHIFT, 274 },
		{ 276, YYAT_SHIFT, 274 },
		{ 183, YYAT_SHIFT, 2 },
		{ 367, YYAT_SHIFT, 96 },
		{ 187, YYAT_SHIFT, 10 },
		{ 187, YYAT_SHIFT, 11 },
		{ 187, YYAT_SHIFT, 12 },
		{ 187, YYAT_SHIFT, 13 },
		{ 187, YYAT_SHIFT, 14 },
		{ 187, YYAT_SHIFT, 15 },
		{ 187, YYAT_SHIFT, 16 },
		{ 187, YYAT_SHIFT, 17 },
		{ 187, YYAT_SHIFT, 18 },
		{ 187, YYAT_SHIFT, 19 },
		{ 187, YYAT_SHIFT, 20 },
		{ 187, YYAT_SHIFT, 21 },
		{ 187, YYAT_SHIFT, 22 },
		{ 187, YYAT_SHIFT, 23 },
		{ 362, YYAT_SHIFT, 366 },
		{ 203, YYAT_SHIFT, 237 },
		{ 365, YYAT_SHIFT, 155 },
		{ 71, YYAT_SHIFT, 161 },
		{ 290, YYAT_SHIFT, 237 },
		{ 61, YYAT_SHIFT, 83 },
		{ 262, YYAT_SHIFT, 260 },
		{ 33, YYAT_SHIFT, 2 },
		{ 164, YYAT_SHIFT, 260 },
		{ 67, YYAT_SHIFT, 58 },
		{ 28, YYAT_SHIFT, 58 },
		{ 355, YYAT_ERROR, 0 },
		{ 165, YYAT_SHIFT, 161 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 358, YYAT_SHIFT, 362 },
		{ 25, YYAT_SHIFT, 1 },
		{ 25, YYAT_ERROR, 0 },
		{ 228, YYAT_SHIFT, 310 },
		{ 356, YYAT_SHIFT, 361 },
<<<<<<< HEAD
		{ 296, YYAT_SHIFT, 246 },
		{ 270, YYAT_ERROR, 0 },
		{ 67, YYAT_SHIFT, 159 },
		{ 99, YYAT_SHIFT, 186 },
		{ 360, YYAT_SHIFT, 364 },
		{ 349, YYAT_REDUCE, 59 },
		{ 270, YYAT_ERROR, 0 },
		{ 360, YYAT_SHIFT, 246 },
		{ 270, YYAT_SHIFT, 270 },
		{ 270, YYAT_SHIFT, 258 },
		{ 270, YYAT_SHIFT, 2 },
		{ 270, YYAT_ERROR, 0 },
		{ 264, YYAT_ERROR, 0 },
		{ 270, YYAT_ERROR, 0 },
		{ 296, YYAT_SHIFT, 328 },
		{ 175, YYAT_SHIFT, 165 },
		{ 271, YYAT_SHIFT, 165 },
		{ 284, YYAT_SHIFT, 190 },
		{ 136, YYAT_SHIFT, 53 },
		{ 283, YYAT_SHIFT, 190 },
		{ 136, YYAT_SHIFT, 242 },
		{ 136, YYAT_SHIFT, 90 },
		{ 284, YYAT_SHIFT, 191 },
		{ 212, YYAT_SHIFT, 299 },
		{ 283, YYAT_SHIFT, 191 },
		{ 71, YYAT_SHIFT, 160 },
		{ 212, YYAT_SHIFT, 300 },
		{ 284, YYAT_SHIFT, 192 },
		{ 71, YYAT_SHIFT, 161 },
		{ 283, YYAT_SHIFT, 192 },
		{ 346, YYAT_SHIFT, 354 },
=======
		{ 308, YYAT_SHIFT, 237 },
		{ 274, YYAT_ERROR, 0 },
		{ 61, YYAT_SHIFT, 159 },
		{ 119, YYAT_SHIFT, 206 },
		{ 360, YYAT_SHIFT, 364 },
		{ 350, YYAT_REDUCE, 59 },
		{ 274, YYAT_ERROR, 0 },
		{ 360, YYAT_SHIFT, 237 },
		{ 274, YYAT_SHIFT, 274 },
		{ 274, YYAT_SHIFT, 255 },
		{ 274, YYAT_SHIFT, 2 },
		{ 274, YYAT_ERROR, 0 },
		{ 260, YYAT_ERROR, 0 },
		{ 274, YYAT_ERROR, 0 },
		{ 308, YYAT_SHIFT, 336 },
		{ 183, YYAT_SHIFT, 161 },
		{ 276, YYAT_SHIFT, 161 },
		{ 297, YYAT_SHIFT, 210 },
		{ 143, YYAT_SHIFT, 53 },
		{ 296, YYAT_SHIFT, 210 },
		{ 143, YYAT_SHIFT, 247 },
		{ 143, YYAT_SHIFT, 98 },
		{ 297, YYAT_SHIFT, 211 },
		{ 251, YYAT_SHIFT, 315 },
		{ 296, YYAT_SHIFT, 211 },
		{ 73, YYAT_SHIFT, 167 },
		{ 251, YYAT_SHIFT, 316 },
		{ 297, YYAT_SHIFT, 212 },
		{ 73, YYAT_SHIFT, 168 },
		{ 296, YYAT_SHIFT, 212 },
		{ 347, YYAT_SHIFT, 354 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 367, YYAT_SHIFT, 53 },
		{ 365, YYAT_ERROR, 0 },
		{ 365, YYAT_ERROR, 0 },
		{ 367, YYAT_SHIFT, 90 },
		{ 278, YYAT_SHIFT, 326 },
		{ 365, YYAT_ERROR, 0 },
<<<<<<< HEAD
		{ 66, YYAT_SHIFT, 154 },
		{ 316, YYAT_SHIFT, 338 },
		{ 263, YYAT_SHIFT, 265 },
		{ 173, YYAT_SHIFT, 268 },
		{ 167, YYAT_SHIFT, 265 },
		{ 49, YYAT_SHIFT, 47 },
		{ 24, YYAT_SHIFT, 47 },
		{ 177, YYAT_SHIFT, 2 },
		{ 100, YYAT_SHIFT, 190 },
		{ 286, YYAT_SHIFT, 193 },
		{ 25, YYAT_ERROR, 0 },
		{ 286, YYAT_SHIFT, 194 },
		{ 285, YYAT_SHIFT, 193 },
		{ 100, YYAT_SHIFT, 191 },
		{ 285, YYAT_SHIFT, 194 },
		{ 103, YYAT_SHIFT, 193 },
		{ 345, YYAT_SHIFT, 353 },
		{ 103, YYAT_SHIFT, 194 },
		{ 100, YYAT_SHIFT, 192 },
		{ 293, YYAT_SHIFT, 202 },
		{ 293, YYAT_SHIFT, 203 },
		{ 337, YYAT_SHIFT, 347 },
		{ 270, YYAT_SHIFT, 165 },
		{ 35, YYAT_SHIFT, 4 },
		{ 53, YYAT_SHIFT, 119 },
		{ 336, YYAT_SHIFT, 119 },
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
		{ 334, YYAT_SHIFT, 344 },
		{ 29, YYAT_SHIFT, 52 },
		{ 290, YYAT_SHIFT, 195 },
		{ 290, YYAT_SHIFT, 196 },
		{ 289, YYAT_SHIFT, 195 },
		{ 289, YYAT_SHIFT, 196 },
		{ 329, YYAT_SHIFT, 206 },
		{ 23, YYAT_SHIFT, 45 },
		{ 288, YYAT_SHIFT, 195 },
		{ 288, YYAT_SHIFT, 196 },
		{ 287, YYAT_SHIFT, 195 },
		{ 287, YYAT_SHIFT, 196 },
		{ 270, YYAT_ERROR, 0 },
		{ 107, YYAT_SHIFT, 202 },
		{ 107, YYAT_SHIFT, 203 },
		{ 28, YYAT_SHIFT, 4 },
		{ 327, YYAT_SHIFT, 209 },
		{ 66, YYAT_SHIFT, 53 },
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
		{ 292, YYAT_SHIFT, 197 },
		{ 323, YYAT_SHIFT, 340 },
		{ 292, YYAT_SHIFT, 198 },
		{ 291, YYAT_SHIFT, 197 },
		{ 321, YYAT_SHIFT, 339 },
		{ 291, YYAT_SHIFT, 198 },
		{ 53, YYAT_SHIFT, 53 },
		{ 105, YYAT_SHIFT, 197 },
		{ 53, YYAT_SHIFT, 120 },
		{ 105, YYAT_SHIFT, 198 },
		{ 104, YYAT_SHIFT, 195 },
		{ 104, YYAT_SHIFT, 196 },
		{ 307, YYAT_SHIFT, 335 },
		{ 305, YYAT_SHIFT, 333 },
		{ 304, YYAT_SHIFT, 332 },
		{ 298, YYAT_SHIFT, 205 },
		{ 294, YYAT_SHIFT, 204 },
		{ 276, YYAT_SHIFT, 325 },
		{ 265, YYAT_SHIFT, 322 },
		{ 262, YYAT_SHIFT, 319 },
		{ 260, YYAT_SHIFT, 318 },
		{ 113, YYAT_SHIFT, 208 },
		{ 134, YYAT_SHIFT, 231 },
		{ 134, YYAT_SHIFT, 232 },
		{ 134, YYAT_SHIFT, 233 },
		{ 134, YYAT_SHIFT, 234 },
		{ 134, YYAT_SHIFT, 235 },
		{ 134, YYAT_SHIFT, 236 },
		{ 134, YYAT_SHIFT, 237 },
		{ 134, YYAT_SHIFT, 238 },
		{ 134, YYAT_SHIFT, 239 },
		{ 134, YYAT_SHIFT, 240 },
		{ 75, YYAT_SHIFT, 3 },
		{ 136, YYAT_SHIFT, 121 },
		{ 136, YYAT_SHIFT, 92 },
		{ 136, YYAT_SHIFT, 93 },
		{ 136, YYAT_SHIFT, 94 },
		{ 259, YYAT_SHIFT, 317 },
		{ 136, YYAT_SHIFT, 95 },
		{ 136, YYAT_SHIFT, 96 },
		{ 155, YYAT_SHIFT, 3 },
		{ 166, YYAT_SHIFT, 3 },
		{ 250, YYAT_SHIFT, 250 },
		{ 164, YYAT_SHIFT, 3 },
		{ 39, YYAT_SHIFT, 70 },
		{ 243, YYAT_SHIFT, 312 },
		{ 367, YYAT_SHIFT, 121 },
		{ 367, YYAT_SHIFT, 92 },
		{ 367, YYAT_SHIFT, 93 },
		{ 367, YYAT_SHIFT, 94 },
		{ 224, YYAT_SHIFT, 309 },
		{ 367, YYAT_SHIFT, 95 },
		{ 367, YYAT_SHIFT, 96 },
		{ 221, YYAT_SHIFT, 306 },
		{ 99, YYAT_SHIFT, 187 },
		{ 99, YYAT_SHIFT, 188 },
		{ 99, YYAT_SHIFT, 189 },
		{ 217, YYAT_SHIFT, 303 },
		{ 355, YYAT_ERROR, 0 },
		{ 136, YYAT_SHIFT, 97 },
		{ 136, YYAT_SHIFT, 98 },
=======
		{ 48, YYAT_SHIFT, 85 },
		{ 270, YYAT_SHIFT, 325 },
		{ 262, YYAT_SHIFT, 261 },
		{ 173, YYAT_SHIFT, 268 },
		{ 164, YYAT_SHIFT, 261 },
		{ 67, YYAT_SHIFT, 59 },
		{ 28, YYAT_SHIFT, 59 },
		{ 184, YYAT_SHIFT, 2 },
		{ 120, YYAT_SHIFT, 210 },
		{ 299, YYAT_SHIFT, 225 },
		{ 36, YYAT_ERROR, 0 },
		{ 299, YYAT_SHIFT, 226 },
		{ 298, YYAT_SHIFT, 225 },
		{ 120, YYAT_SHIFT, 211 },
		{ 298, YYAT_SHIFT, 226 },
		{ 122, YYAT_SHIFT, 225 },
		{ 346, YYAT_SHIFT, 353 },
		{ 122, YYAT_SHIFT, 226 },
		{ 120, YYAT_SHIFT, 212 },
		{ 312, YYAT_SHIFT, 235 },
		{ 312, YYAT_SHIFT, 236 },
		{ 337, YYAT_SHIFT, 239 },
		{ 274, YYAT_SHIFT, 161 },
		{ 32, YYAT_SHIFT, 4 },
		{ 53, YYAT_SHIFT, 96 },
		{ 335, YYAT_SHIFT, 242 },
		{ 32, YYAT_SHIFT, 5 },
		{ 32, YYAT_SHIFT, 6 },
		{ 32, YYAT_SHIFT, 7 },
		{ 32, YYAT_SHIFT, 8 },
		{ 32, YYAT_SHIFT, 9 },
		{ 32, YYAT_SHIFT, 10 },
		{ 32, YYAT_SHIFT, 11 },
		{ 32, YYAT_SHIFT, 12 },
		{ 32, YYAT_SHIFT, 13 },
		{ 32, YYAT_SHIFT, 14 },
		{ 32, YYAT_SHIFT, 15 },
		{ 32, YYAT_SHIFT, 16 },
		{ 32, YYAT_SHIFT, 17 },
		{ 32, YYAT_SHIFT, 18 },
		{ 32, YYAT_SHIFT, 19 },
		{ 32, YYAT_SHIFT, 20 },
		{ 32, YYAT_SHIFT, 21 },
		{ 32, YYAT_SHIFT, 22 },
		{ 32, YYAT_SHIFT, 23 },
		{ 333, YYAT_SHIFT, 96 },
		{ 25, YYAT_SHIFT, 51 },
		{ 303, YYAT_SHIFT, 227 },
		{ 303, YYAT_SHIFT, 228 },
		{ 302, YYAT_SHIFT, 227 },
		{ 302, YYAT_SHIFT, 228 },
		{ 331, YYAT_SHIFT, 345 },
		{ 23, YYAT_SHIFT, 45 },
		{ 301, YYAT_SHIFT, 227 },
		{ 301, YYAT_SHIFT, 228 },
		{ 300, YYAT_SHIFT, 227 },
		{ 300, YYAT_SHIFT, 228 },
		{ 274, YYAT_ERROR, 0 },
		{ 128, YYAT_SHIFT, 235 },
		{ 128, YYAT_SHIFT, 236 },
		{ 26, YYAT_SHIFT, 4 },
		{ 324, YYAT_SHIFT, 341 },
		{ 48, YYAT_SHIFT, 53 },
		{ 26, YYAT_SHIFT, 5 },
		{ 26, YYAT_SHIFT, 6 },
		{ 26, YYAT_SHIFT, 7 },
		{ 26, YYAT_SHIFT, 8 },
		{ 26, YYAT_SHIFT, 9 },
		{ 26, YYAT_SHIFT, 10 },
		{ 26, YYAT_SHIFT, 11 },
		{ 26, YYAT_SHIFT, 12 },
		{ 26, YYAT_SHIFT, 13 },
		{ 26, YYAT_SHIFT, 14 },
		{ 26, YYAT_SHIFT, 15 },
		{ 26, YYAT_SHIFT, 16 },
		{ 26, YYAT_SHIFT, 17 },
		{ 26, YYAT_SHIFT, 18 },
		{ 26, YYAT_SHIFT, 19 },
		{ 26, YYAT_SHIFT, 20 },
		{ 26, YYAT_SHIFT, 21 },
		{ 26, YYAT_SHIFT, 22 },
		{ 26, YYAT_SHIFT, 23 },
		{ 305, YYAT_SHIFT, 229 },
		{ 323, YYAT_SHIFT, 340 },
		{ 305, YYAT_SHIFT, 230 },
		{ 304, YYAT_SHIFT, 229 },
		{ 321, YYAT_SHIFT, 339 },
		{ 304, YYAT_SHIFT, 230 },
		{ 53, YYAT_SHIFT, 53 },
		{ 125, YYAT_SHIFT, 229 },
		{ 53, YYAT_SHIFT, 97 },
		{ 125, YYAT_SHIFT, 230 },
		{ 123, YYAT_SHIFT, 227 },
		{ 123, YYAT_SHIFT, 228 },
		{ 311, YYAT_SHIFT, 244 },
		{ 310, YYAT_SHIFT, 243 },
		{ 285, YYAT_SHIFT, 332 },
		{ 283, YYAT_SHIFT, 330 },
		{ 282, YYAT_SHIFT, 329 },
		{ 280, YYAT_SHIFT, 327 },
		{ 261, YYAT_SHIFT, 322 },
		{ 259, YYAT_SHIFT, 319 },
		{ 257, YYAT_SHIFT, 318 },
		{ 132, YYAT_SHIFT, 241 },
		{ 121, YYAT_SHIFT, 214 },
		{ 121, YYAT_SHIFT, 215 },
		{ 121, YYAT_SHIFT, 216 },
		{ 121, YYAT_SHIFT, 217 },
		{ 121, YYAT_SHIFT, 218 },
		{ 121, YYAT_SHIFT, 219 },
		{ 121, YYAT_SHIFT, 220 },
		{ 121, YYAT_SHIFT, 221 },
		{ 121, YYAT_SHIFT, 222 },
		{ 121, YYAT_SHIFT, 223 },
		{ 71, YYAT_SHIFT, 3 },
		{ 143, YYAT_SHIFT, 99 },
		{ 143, YYAT_SHIFT, 100 },
		{ 143, YYAT_SHIFT, 101 },
		{ 143, YYAT_SHIFT, 102 },
		{ 256, YYAT_SHIFT, 317 },
		{ 143, YYAT_SHIFT, 103 },
		{ 143, YYAT_SHIFT, 104 },
		{ 83, YYAT_SHIFT, 3 },
		{ 165, YYAT_SHIFT, 3 },
		{ 248, YYAT_SHIFT, 314 },
		{ 160, YYAT_SHIFT, 3 },
		{ 38, YYAT_SHIFT, 70 },
		{ 207, YYAT_SHIFT, 291 },
		{ 367, YYAT_SHIFT, 99 },
		{ 367, YYAT_SHIFT, 100 },
		{ 367, YYAT_SHIFT, 101 },
		{ 367, YYAT_SHIFT, 102 },
		{ 205, YYAT_SHIFT, 289 },
		{ 367, YYAT_SHIFT, 103 },
		{ 367, YYAT_SHIFT, 104 },
		{ 199, YYAT_SHIFT, 287 },
		{ 119, YYAT_SHIFT, 207 },
		{ 119, YYAT_SHIFT, 208 },
		{ 119, YYAT_SHIFT, 209 },
		{ 196, YYAT_SHIFT, 284 },
		{ 355, YYAT_ERROR, 0 },
		{ 143, YYAT_SHIFT, 105 },
		{ 143, YYAT_SHIFT, 106 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
		{ 355, YYAT_ERROR, 0 },
<<<<<<< HEAD
		{ 43, YYAT_SHIFT, 18 },
		{ 43, YYAT_SHIFT, 19 },
		{ 215, YYAT_SHIFT, 301 },
		{ 187, YYAT_SHIFT, 279 },
		{ 367, YYAT_SHIFT, 97 },
		{ 367, YYAT_SHIFT, 98 },
		{ 185, YYAT_SHIFT, 277 },
		{ 178, YYAT_SHIFT, 275 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 176, YYAT_SHIFT, 273 },
		{ 171, YYAT_SHIFT, 79 },
		{ 165, YYAT_SHIFT, 261 },
		{ 136, YYAT_SHIFT, 122 },
		{ 136, YYAT_SHIFT, 123 },
		{ 136, YYAT_SHIFT, 124 },
		{ 163, YYAT_SHIFT, 256 },
		{ 136, YYAT_SHIFT, 125 },
		{ 136, YYAT_SHIFT, 126 },
		{ 136, YYAT_SHIFT, 127 },
		{ 136, YYAT_SHIFT, 128 },
		{ 136, YYAT_SHIFT, 129 },
		{ 136, YYAT_SHIFT, 130 },
		{ 136, YYAT_SHIFT, 131 },
		{ 136, YYAT_SHIFT, 132 },
		{ 161, YYAT_SHIFT, 255 },
		{ 367, YYAT_SHIFT, 122 },
		{ 367, YYAT_SHIFT, 123 },
		{ 367, YYAT_SHIFT, 124 },
		{ 158, YYAT_SHIFT, 53 },
		{ 367, YYAT_SHIFT, 125 },
		{ 367, YYAT_SHIFT, 126 },
		{ 367, YYAT_SHIFT, 127 },
		{ 367, YYAT_SHIFT, 128 },
		{ 367, YYAT_SHIFT, 129 },
		{ 367, YYAT_SHIFT, 130 },
		{ 367, YYAT_SHIFT, 131 },
		{ 367, YYAT_SHIFT, 132 },
		{ 270, YYAT_ERROR, 0 },
		{ 270, YYAT_ERROR, 0 },
		{ 270, YYAT_ERROR, 0 },
		{ 270, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 4 },
		{ 270, YYAT_ERROR, 0 },
		{ 270, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 5 },
		{ 32, YYAT_SHIFT, 6 },
		{ 32, YYAT_SHIFT, 7 },
		{ 32, YYAT_SHIFT, 8 },
		{ 32, YYAT_SHIFT, 9 },
		{ 32, YYAT_SHIFT, 10 },
		{ 32, YYAT_SHIFT, 11 },
		{ 32, YYAT_SHIFT, 12 },
		{ 32, YYAT_SHIFT, 13 },
		{ 32, YYAT_SHIFT, 14 },
		{ 32, YYAT_SHIFT, 15 },
		{ 32, YYAT_SHIFT, 16 },
		{ 32, YYAT_SHIFT, 17 },
		{ 32, YYAT_SHIFT, 18 },
		{ 32, YYAT_SHIFT, 19 },
		{ 32, YYAT_SHIFT, 20 },
		{ 32, YYAT_SHIFT, 21 },
		{ 32, YYAT_SHIFT, 22 },
		{ 32, YYAT_SHIFT, 23 },
		{ 270, YYAT_ERROR, 0 },
		{ 270, YYAT_ERROR, 0 },
		{ 270, YYAT_SHIFT, 5 },
		{ 270, YYAT_SHIFT, 6 },
		{ 270, YYAT_SHIFT, 7 },
		{ 270, YYAT_SHIFT, 8 },
		{ 270, YYAT_SHIFT, 9 },
		{ 66, YYAT_SHIFT, 4 },
		{ 53, YYAT_SHIFT, 121 },
		{ 153, YYAT_ERROR, 0 },
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
		{ 144, YYAT_SHIFT, 247 },
		{ 137, YYAT_SHIFT, 244 },
		{ 132, YYAT_SHIFT, 227 },
		{ 131, YYAT_SHIFT, 226 },
		{ 177, YYAT_SHIFT, 4 },
		{ 130, YYAT_SHIFT, 225 },
		{ 129, YYAT_SHIFT, 224 },
=======
		{ 42, YYAT_SHIFT, 18 },
		{ 42, YYAT_SHIFT, 19 },
		{ 192, YYAT_SHIFT, 281 },
		{ 185, YYAT_SHIFT, 278 },
		{ 367, YYAT_SHIFT, 105 },
		{ 367, YYAT_SHIFT, 106 },
		{ 182, YYAT_SHIFT, 273 },
		{ 180, YYAT_SHIFT, 271 },
		{ 2, YYAT_SHIFT, 18 },
		{ 2, YYAT_SHIFT, 19 },
		{ 175, YYAT_SHIFT, 175 },
		{ 171, YYAT_SHIFT, 79 },
		{ 168, YYAT_SHIFT, 265 },
		{ 143, YYAT_SHIFT, 107 },
		{ 143, YYAT_SHIFT, 108 },
		{ 143, YYAT_SHIFT, 109 },
		{ 166, YYAT_SHIFT, 263 },
		{ 143, YYAT_SHIFT, 110 },
		{ 143, YYAT_SHIFT, 111 },
		{ 143, YYAT_SHIFT, 112 },
		{ 143, YYAT_SHIFT, 113 },
		{ 143, YYAT_SHIFT, 114 },
		{ 143, YYAT_SHIFT, 115 },
		{ 143, YYAT_SHIFT, 116 },
		{ 143, YYAT_SHIFT, 117 },
		{ 161, YYAT_SHIFT, 258 },
		{ 367, YYAT_SHIFT, 107 },
		{ 367, YYAT_SHIFT, 108 },
		{ 367, YYAT_SHIFT, 109 },
		{ 158, YYAT_SHIFT, 254 },
		{ 367, YYAT_SHIFT, 110 },
		{ 367, YYAT_SHIFT, 111 },
		{ 367, YYAT_SHIFT, 112 },
		{ 367, YYAT_SHIFT, 113 },
		{ 367, YYAT_SHIFT, 114 },
		{ 367, YYAT_SHIFT, 115 },
		{ 367, YYAT_SHIFT, 116 },
		{ 367, YYAT_SHIFT, 117 },
		{ 274, YYAT_ERROR, 0 },
		{ 274, YYAT_ERROR, 0 },
		{ 274, YYAT_ERROR, 0 },
		{ 274, YYAT_ERROR, 0 },
		{ 33, YYAT_SHIFT, 4 },
		{ 274, YYAT_ERROR, 0 },
		{ 274, YYAT_ERROR, 0 },
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
		{ 274, YYAT_ERROR, 0 },
		{ 274, YYAT_ERROR, 0 },
		{ 274, YYAT_SHIFT, 5 },
		{ 274, YYAT_SHIFT, 6 },
		{ 274, YYAT_SHIFT, 7 },
		{ 274, YYAT_SHIFT, 8 },
		{ 274, YYAT_SHIFT, 9 },
		{ 48, YYAT_SHIFT, 4 },
		{ 53, YYAT_SHIFT, 99 },
		{ 153, YYAT_ERROR, 0 },
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
		{ 151, YYAT_SHIFT, 250 },
		{ 137, YYAT_SHIFT, 245 },
		{ 136, YYAT_SHIFT, 244 },
		{ 134, YYAT_SHIFT, 243 },
		{ 184, YYAT_SHIFT, 4 },
		{ 133, YYAT_SHIFT, 242 },
		{ 131, YYAT_SHIFT, 239 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 53, YYAT_SHIFT, 5 },
		{ 53, YYAT_SHIFT, 6 },
		{ 53, YYAT_SHIFT, 7 },
		{ 53, YYAT_SHIFT, 8 },
		{ 53, YYAT_SHIFT, 9 },
<<<<<<< HEAD
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
		{ 128, YYAT_SHIFT, 223 },
		{ 53, YYAT_SHIFT, 122 },
		{ 53, YYAT_SHIFT, 123 },
		{ 53, YYAT_SHIFT, 124 },
		{ 125, YYAT_SHIFT, 220 },
		{ 53, YYAT_SHIFT, 125 },
		{ 53, YYAT_SHIFT, 126 },
		{ 53, YYAT_SHIFT, 127 },
		{ 53, YYAT_SHIFT, 128 },
		{ 53, YYAT_SHIFT, 129 },
		{ 53, YYAT_SHIFT, 130 },
		{ 53, YYAT_SHIFT, 131 },
		{ 53, YYAT_SHIFT, 132 },
		{ 124, YYAT_SHIFT, 219 },
		{ 123, YYAT_SHIFT, 218 },
		{ 121, YYAT_SHIFT, 216 },
		{ 117, YYAT_SHIFT, 214 },
		{ 116, YYAT_SHIFT, 211 },
		{ 115, YYAT_SHIFT, 210 },
		{ 292, YYAT_SHIFT, 199 },
		{ 292, YYAT_SHIFT, 200 },
		{ 174, YYAT_SHIFT, 4 },
		{ 291, YYAT_SHIFT, 199 },
		{ 291, YYAT_SHIFT, 200 },
		{ 114, YYAT_SHIFT, 209 },
		{ 111, YYAT_SHIFT, 206 },
		{ 105, YYAT_SHIFT, 199 },
		{ 105, YYAT_SHIFT, 200 },
		{ 110, YYAT_SHIFT, 205 },
		{ 174, YYAT_SHIFT, 10 },
		{ 174, YYAT_SHIFT, 11 },
		{ 174, YYAT_SHIFT, 12 },
		{ 174, YYAT_SHIFT, 13 },
		{ 174, YYAT_SHIFT, 14 },
		{ 174, YYAT_SHIFT, 15 },
		{ 174, YYAT_SHIFT, 16 },
		{ 174, YYAT_SHIFT, 17 },
		{ 174, YYAT_SHIFT, 18 },
		{ 174, YYAT_SHIFT, 19 },
		{ 174, YYAT_SHIFT, 20 },
		{ 174, YYAT_SHIFT, 21 },
		{ 174, YYAT_SHIFT, 22 },
		{ 174, YYAT_SHIFT, 23 },
		{ 109, YYAT_SHIFT, 204 },
		{ 96, YYAT_SHIFT, 181 },
		{ 94, YYAT_SHIFT, 179 },
		{ 81, YYAT_SHIFT, 172 },
		{ 79, YYAT_SHIFT, 170 },
		{ 74, YYAT_SHIFT, 163 },
		{ 73, YYAT_SHIFT, 162 },
		{ 60, YYAT_SHIFT, 156 },
		{ 59, YYAT_SHIFT, 154 },
		{ 57, YYAT_SHIFT, 65 },
		{ 55, YYAT_SHIFT, 53 },
		{ 52, YYAT_SHIFT, 118 },
		{ 47, YYAT_SHIFT, 89 },
		{ 45, YYAT_SHIFT, 82 },
		{ 40, YYAT_SHIFT, 76 },
		{ 31, YYAT_SHIFT, 58 },
		{ 30, YYAT_SHIFT, 53 },
		{ 26, YYAT_ERROR, 0 },
=======
		{ 184, YYAT_SHIFT, 10 },
		{ 184, YYAT_SHIFT, 11 },
		{ 184, YYAT_SHIFT, 12 },
		{ 184, YYAT_SHIFT, 13 },
		{ 184, YYAT_SHIFT, 14 },
		{ 184, YYAT_SHIFT, 15 },
		{ 184, YYAT_SHIFT, 16 },
		{ 184, YYAT_SHIFT, 17 },
		{ 184, YYAT_SHIFT, 18 },
		{ 184, YYAT_SHIFT, 19 },
		{ 184, YYAT_SHIFT, 20 },
		{ 184, YYAT_SHIFT, 21 },
		{ 184, YYAT_SHIFT, 22 },
		{ 184, YYAT_SHIFT, 23 },
		{ 130, YYAT_SHIFT, 238 },
		{ 53, YYAT_SHIFT, 107 },
		{ 53, YYAT_SHIFT, 108 },
		{ 53, YYAT_SHIFT, 109 },
		{ 117, YYAT_SHIFT, 202 },
		{ 53, YYAT_SHIFT, 110 },
		{ 53, YYAT_SHIFT, 111 },
		{ 53, YYAT_SHIFT, 112 },
		{ 53, YYAT_SHIFT, 113 },
		{ 53, YYAT_SHIFT, 114 },
		{ 53, YYAT_SHIFT, 115 },
		{ 53, YYAT_SHIFT, 116 },
		{ 53, YYAT_SHIFT, 117 },
		{ 116, YYAT_SHIFT, 201 },
		{ 115, YYAT_SHIFT, 200 },
		{ 114, YYAT_SHIFT, 199 },
		{ 113, YYAT_SHIFT, 198 },
		{ 110, YYAT_SHIFT, 195 },
		{ 109, YYAT_SHIFT, 194 },
		{ 305, YYAT_SHIFT, 231 },
		{ 305, YYAT_SHIFT, 232 },
		{ 181, YYAT_SHIFT, 4 },
		{ 304, YYAT_SHIFT, 231 },
		{ 304, YYAT_SHIFT, 232 },
		{ 108, YYAT_SHIFT, 193 },
		{ 104, YYAT_SHIFT, 189 },
		{ 125, YYAT_SHIFT, 231 },
		{ 125, YYAT_SHIFT, 232 },
		{ 102, YYAT_SHIFT, 187 },
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
		{ 99, YYAT_SHIFT, 186 },
		{ 88, YYAT_SHIFT, 179 },
		{ 87, YYAT_SHIFT, 53 },
		{ 80, YYAT_SHIFT, 172 },
		{ 79, YYAT_SHIFT, 170 },
		{ 75, YYAT_SHIFT, 169 },
		{ 72, YYAT_SHIFT, 166 },
		{ 62, YYAT_SHIFT, 85 },
		{ 59, YYAT_SHIFT, 154 },
		{ 57, YYAT_SHIFT, 53 },
		{ 54, YYAT_SHIFT, 46 },
		{ 51, YYAT_SHIFT, 89 },
		{ 47, YYAT_SHIFT, 84 },
		{ 45, YYAT_SHIFT, 82 },
		{ 40, YYAT_SHIFT, 76 },
		{ 35, YYAT_ERROR, 0 },
		{ 29, YYAT_SHIFT, 60 },
		{ 27, YYAT_SHIFT, 53 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, YYAT_ERROR, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
<<<<<<< HEAD
		{ 439, 1, YYAT_DEFAULT, 25 },
		{ 0, 0, YYAT_DEFAULT, 155 },
=======
		{ 439, 1, YYAT_DEFAULT, 36 },
		{ 0, 0, YYAT_DEFAULT, 83 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
		{ 24, 1, YYAT_REDUCE, 141 },
		{ 28, 1, YYAT_DEFAULT, 164 },
		{ 396, 1, YYAT_DEFAULT, 155 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ -113, 1, YYAT_REDUCE, 86 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ 314, 1, YYAT_DEFAULT, 153 },
		{ 377, 1, YYAT_DEFAULT, 155 },
		{ 19, 1, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 226 },
		{ 0, 0, YYAT_DEFAULT, 57 },
		{ -150, 1, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 106 },
=======
		{ 0, 0, YYAT_DEFAULT, 54 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ -113, 1, YYAT_REDUCE, 86 },
		{ 315, 1, YYAT_DEFAULT, 153 },
		{ 24, 1, YYAT_REDUCE, 141 },
		{ 378, 1, YYAT_DEFAULT, 83 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 226 },
		{ -150, 1, YYAT_REDUCE, 82 },
		{ 19, 1, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 394, 1, YYAT_DEFAULT, 83 },
		{ 28, 1, YYAT_DEFAULT, 160 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 225 },
		{ -22, 1, YYAT_DEFAULT, 260 },
		{ 0, 0, YYAT_REDUCE, 223 },
<<<<<<< HEAD
		{ -22, 1, YYAT_DEFAULT, 264 },
		{ 394, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ -39, 1, YYAT_REDUCE, 151 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 311, 1, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 340, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 23, 1, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_DEFAULT, 153 },
		{ 309, 1, YYAT_REDUCE, 115 },
		{ 74, 1, YYAT_DEFAULT, 179 },
		{ 0, 0, YYAT_REDUCE, 230 },
		{ 308, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 371, 1, YYAT_DEFAULT, 155 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 368, 1, YYAT_REDUCE, 90 },
		{ 369, 1, YYAT_DEFAULT, 67 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 48, 1, YYAT_REDUCE, 90 },
		{ 15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 56, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 158 },
		{ 386, 1, YYAT_ERROR, 0 },
		{ 382, 1, YYAT_REDUCE, 156 },
		{ -34, 1, YYAT_REDUCE, 162 },
=======
		{ 394, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ -39, 1, YYAT_REDUCE, 151 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_DEFAULT, 171 },
		{ 311, 1, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 374, 1, YYAT_DEFAULT, 61 },
		{ 48, 1, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_DEFAULT, 153 },
		{ 309, 1, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 74, 1, YYAT_DEFAULT, 187 },
		{ 372, 1, YYAT_DEFAULT, 83 },
		{ 0, 0, YYAT_REDUCE, 199 },
		{ 0, 0, YYAT_REDUCE, 230 },
		{ 307, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 336, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 15, 1, YYAT_ERROR, 0 },
		{ 367, 1, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 23, 1, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 224 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ -34, 1, YYAT_REDUCE, 162 },
		{ 383, 1, YYAT_REDUCE, 156 },
		{ 56, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 158 },
		{ 385, 1, YYAT_ERROR, 0 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 364, 1, YYAT_REDUCE, 136 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 299, 1, YYAT_DEFAULT, 173 },
		{ 0, 0, YYAT_DEFAULT, 171 },
<<<<<<< HEAD
=======
		{ -26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_DEFAULT, 175 },
		{ 0, 0, YYAT_REDUCE, 228 },
		{ 300, 1, YYAT_REDUCE, 58 },
		{ 297, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 153 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_DEFAULT, 179 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 383, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 382, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 6 },
<<<<<<< HEAD
		{ -16, 1, YYAT_REDUCE, 18 },
		{ 80, 1, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 30 },
=======
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 344, 1, YYAT_ERROR, 0 },
		{ 356, 1, YYAT_ERROR, 0 },
		{ 355, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 354, 1, YYAT_ERROR, 0 },
		{ 136, 1, YYAT_ERROR, 0 },
		{ 333, 1, YYAT_ERROR, 0 },
		{ 332, 1, YYAT_ERROR, 0 },
		{ 323, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -16, 1, YYAT_REDUCE, 18 },
		{ 80, 1, YYAT_REDUCE, 36 },
		{ -59, 1, YYAT_REDUCE, 30 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 81, 1, YYAT_REDUCE, 39 },
		{ -63, 1, YYAT_REDUCE, 42 },
		{ 138, 1, YYAT_REDUCE, 47 },
<<<<<<< HEAD
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -101, 1, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 383, 1, YYAT_REDUCE, 52 },
		{ 312, 1, YYAT_REDUCE, 54 },
		{ 133, 1, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ -59, 1, YYAT_REDUCE, 62 },
		{ 278, 1, YYAT_REDUCE, 56 },
		{ 303, 1, YYAT_ERROR, 0 },
		{ 354, 1, YYAT_DEFAULT, 355 },
		{ 269, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 153 },
		{ 0, 0, YYAT_REDUCE, 203 },
		{ 0, 0, YYAT_REDUCE, 195 },
		{ 335, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 334, 1, YYAT_ERROR, 0 },
		{ 351, 1, YYAT_ERROR, 0 },
		{ 342, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 338, 1, YYAT_ERROR, 0 },
		{ 101, 1, YYAT_ERROR, 0 },
		{ 298, 1, YYAT_ERROR, 0 },
		{ 296, 1, YYAT_ERROR, 0 },
		{ 295, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ -59, 1, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ -33, 1, YYAT_REDUCE, 58 },
		{ 228, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 293, 1, YYAT_DEFAULT, 228 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 0, 0, YYAT_REDUCE, 229 },
		{ 291, 1, YYAT_DEFAULT, 264 },
		{ 0, 0, YYAT_DEFAULT, 250 },
		{ -26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ 0, 0, YYAT_REDUCE, 228 },
		{ 165, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ -29, 1, YYAT_DEFAULT, 153 },
		{ -23, 1, YYAT_DEFAULT, 270 },
		{ 178, 1, YYAT_DEFAULT, 355 },
		{ -25, 1, YYAT_REDUCE, 167 },
		{ 22, 1, YYAT_REDUCE, 168 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_REDUCE, 161 },
=======
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -101, 1, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 319, 1, YYAT_DEFAULT, 203 },
		{ 88, 1, YYAT_REDUCE, 60 },
		{ -59, 1, YYAT_REDUCE, 62 },
		{ 233, 1, YYAT_REDUCE, 56 },
		{ 261, 1, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 316, 1, YYAT_REDUCE, 52 },
		{ 228, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 186 },
		{ 0, 0, YYAT_REDUCE, 188 },
		{ 0, 0, YYAT_REDUCE, 185 },
		{ 0, 0, YYAT_REDUCE, 201 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ -33, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 189 },
		{ 0, 0, YYAT_REDUCE, 206 },
		{ 0, 0, YYAT_REDUCE, 190 },
		{ 0, 0, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 187 },
		{ 0, 0, YYAT_REDUCE, 211 },
		{ 311, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 229 },
		{ 291, 1, YYAT_DEFAULT, 260 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 195, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ -23, 1, YYAT_DEFAULT, 274 },
		{ 191, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_REDUCE, 161 },
		{ 22, 1, YYAT_REDUCE, 168 },
		{ -25, 1, YYAT_REDUCE, 167 },
		{ -29, 1, YYAT_DEFAULT, 153 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 14, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 147 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ -13, 1, YYAT_ERROR, 0 },
<<<<<<< HEAD
		{ 117, 1, YYAT_REDUCE, 125 },
=======
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 146, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 227 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 141, 1, YYAT_REDUCE, 58 },
		{ 117, 1, YYAT_REDUCE, 125 },
		{ 224, 1, YYAT_DEFAULT, 360 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ -4, 1, YYAT_REDUCE, 165 },
		{ 228, 1, YYAT_ERROR, 0 },
		{ 74, 1, YYAT_REDUCE, 123 },
<<<<<<< HEAD
		{ 225, 1, YYAT_DEFAULT, 360 },
=======
		{ 221, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 367 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ -250, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 8, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 5, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 15 },
<<<<<<< HEAD
=======
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
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 194 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 355 },
<<<<<<< HEAD
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
=======
		{ 0, 0, YYAT_REDUCE, 204 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 54, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 136, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 190, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 191 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_DEFAULT, 355 },
<<<<<<< HEAD
		{ 204, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 336 },
		{ 182, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 219 },
		{ 0, 0, YYAT_REDUCE, 220 },
		{ 0, 0, YYAT_REDUCE, 221 },
		{ 11, 1, YYAT_ERROR, 0 },
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
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 111, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 204 },
=======
		{ 0, 0, YYAT_REDUCE, 196 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 197 },
		{ 108, 1, YYAT_REDUCE, 58 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 212 },
		{ 0, 0, YYAT_REDUCE, 200 },
		{ 110, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 227 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 187, 1, YYAT_ERROR, 0 },
		{ 170, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 117, 1, YYAT_ERROR, 0 },
<<<<<<< HEAD
		{ 20, 1, YYAT_REDUCE, 169 },
		{ -7, 1, YYAT_DEFAULT, 270 },
		{ 116, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 132 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 40, 1, YYAT_DEFAULT, 179 },
		{ -3, 1, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 166 },
=======
		{ -7, 1, YYAT_DEFAULT, 274 },
		{ 116, 1, YYAT_DEFAULT, 355 },
		{ 20, 1, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 132 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ -15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 40, 1, YYAT_DEFAULT, 187 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ -3, 1, YYAT_REDUCE, 167 },
		{ 0, 0, YYAT_REDUCE, 122 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 167, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 14, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 54, 1, YYAT_REDUCE, 37 },
		{ 52, 1, YYAT_REDUCE, 38 },
		{ 78, 1, YYAT_REDUCE, 40 },
		{ 75, 1, YYAT_REDUCE, 41 },
		{ -100, 1, YYAT_REDUCE, 43 },
		{ -102, 1, YYAT_REDUCE, 44 },
		{ -106, 1, YYAT_REDUCE, 45 },
		{ -108, 1, YYAT_REDUCE, 46 },
		{ 134, 1, YYAT_REDUCE, 48 },
		{ 131, 1, YYAT_REDUCE, 49 },
<<<<<<< HEAD
		{ -140, 1, YYAT_REDUCE, 51 },
		{ 169, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 28, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 112, 1, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 192 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 164, 1, YYAT_DEFAULT, 360 },
		{ 163, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -107, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 218 },
		{ 0, 0, YYAT_REDUCE, 222 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ -15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 176 },
=======
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 28, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ 110, 1, YYAT_REDUCE, 55 },
		{ 165, 1, YYAT_REDUCE, 53 },
		{ -140, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 202 },
		{ 0, 0, YYAT_REDUCE, 198 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 355 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 154, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 99, 1, YYAT_ERROR, 0 },
<<<<<<< HEAD
=======
		{ 45, 1, YYAT_DEFAULT, 175 },
		{ 0, 0, YYAT_REDUCE, 180 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 46, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -110, 1, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_DEFAULT, 367 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 213 },
		{ 113, 1, YYAT_DEFAULT, 360 },
		{ 0, 0, YYAT_REDUCE, 58 },
<<<<<<< HEAD
		{ 75, 1, YYAT_DEFAULT, 355 },
		{ 5, 1, YYAT_DEFAULT, 250 },
		{ 0, 0, YYAT_REDUCE, 180 },
=======
		{ 95, 1, YYAT_DEFAULT, 355 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 10, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_DEFAULT, 355 },
		{ -140, 1, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 17 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, 0, YYAT_REDUCE, 178 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 193 },
		{ 0, 0, YYAT_DEFAULT, 365 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 85, 1, YYAT_ERROR, 0 },
		{ 61, 1, YYAT_REDUCE, 58 },
<<<<<<< HEAD
		{ 0, 0, YYAT_REDUCE, 181 },
		{ 0, 0, YYAT_REDUCE, 183 },
=======
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 208 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ -231, 1, YYAT_REDUCE, 205 },
		{ 0, 0, YYAT_REDUCE, 209 },
		{ 0, 0, YYAT_REDUCE, 208 },
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
		{ 0, 0, YYAT_REDUCE, 210 },
		{ 0, 0, YYAT_REDUCE, 207 },
		{ 0, 0, YYAT_REDUCE, 217 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 257;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
<<<<<<< HEAD
		{ 367, 101 },
		{ 367, 116 },
		{ 367, 99 },
		{ 336, 144 },
		{ 367, 134 },
		{ 367, 106 },
		{ 367, 108 },
		{ 367, 100 },
		{ 367, 103 },
		{ 367, 104 },
		{ 367, 105 },
		{ 367, 107 },
		{ 367, 109 },
		{ 367, 110 },
		{ 367, 114 },
		{ 367, 111 },
		{ 118, 56 },
		{ 337, 252 },
		{ 367, 113 },
		{ 367, 143 },
		{ 367, 145 },
		{ 300, 330 },
		{ 367, 144 },
		{ 300, -1 },
		{ 35, 68 },
		{ 175, 271 },
		{ 174, 269 },
		{ 179, 177 },
		{ 179, 31 },
		{ 364, 367 },
		{ 179, 36 },
		{ 179, 29 },
		{ 175, 272 },
		{ 175, 167 },
		{ 179, 175 },
		{ 1, -1 },
		{ 174, -1 },
		{ 179, 27 },
		{ 53, 56 },
		{ 53, 57 },
		{ 179, 174 },
		{ 32, 64 },
		{ 53, 35 },
		{ 53, 32 },
		{ 53, 31 },
		{ 336, 346 },
		{ 53, 36 },
		{ 53, 29 },
		{ 136, 153 },
		{ 35, -1 },
		{ 179, 276 },
		{ 1, 40 },
		{ 337, 348 },
		{ 53, 27 },
		{ 118, 215 },
		{ 361, 365 },
		{ 53, 28 },
		{ 367, 150 },
		{ 367, 370 },
		{ 367, 133 },
		{ 367, 142 },
		{ 367, 135 },
		{ 32, 63 },
		{ 359, 363 },
		{ 367, 138 },
		{ 367, 149 },
=======
		{ 367, 118 },
		{ 367, 151 },
		{ 367, 119 },
		{ 333, 130 },
		{ 367, 121 },
		{ 367, 127 },
		{ 367, 124 },
		{ 367, 120 },
		{ 367, 122 },
		{ 367, 123 },
		{ 367, 125 },
		{ 367, 128 },
		{ 367, 136 },
		{ 367, 134 },
		{ 367, 133 },
		{ 367, 131 },
		{ 89, 55 },
		{ 324, 176 },
		{ 367, 132 },
		{ 367, 135 },
		{ 367, 129 },
		{ 316, 338 },
		{ 367, 130 },
		{ 316, -1 },
		{ 32, 64 },
		{ 183, 276 },
		{ 181, 272 },
		{ 187, 184 },
		{ 187, 29 },
		{ 364, 367 },
		{ 187, 30 },
		{ 187, 25 },
		{ 183, 275 },
		{ 183, 164 },
		{ 187, 183 },
		{ 1, -1 },
		{ 181, -1 },
		{ 187, 34 },
		{ 53, 55 },
		{ 53, 54 },
		{ 187, 181 },
		{ 33, 65 },
		{ 53, 32 },
		{ 53, 33 },
		{ 53, 29 },
		{ 333, 347 },
		{ 53, 30 },
		{ 53, 25 },
		{ 143, 153 },
		{ 32, -1 },
		{ 187, 280 },
		{ 1, 40 },
		{ 324, 342 },
		{ 53, 34 },
		{ 89, 180 },
		{ 361, 365 },
		{ 53, 26 },
		{ 367, 145 },
		{ 367, 370 },
		{ 367, 126 },
		{ 367, 139 },
		{ 367, 142 },
		{ 33, 66 },
		{ 359, 363 },
		{ 367, 140 },
		{ 367, 150 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 367, 148 },
		{ 367, 146 },
		{ 367, 147 },
<<<<<<< HEAD
		{ 367, 151 },
		{ 367, 146 },
		{ 367, 139 },
		{ 367, 140 },
		{ 53, 141 },
		{ 355, 360 },
		{ 116, 212 },
		{ 270, 75 },
		{ 53, 136 },
		{ 53, 137 },
		{ 270, 35 },
		{ 270, 32 },
		{ 270, 31 },
		{ 328, 102 },
		{ 270, 36 },
		{ 270, 29 },
		{ 297, 329 },
		{ 25, 33 },
		{ 25, 34 },
		{ 297, -1 },
		{ 297, -1 },
		{ 270, 27 },
		{ 136, 141 },
		{ 116, 213 },
		{ 270, 28 },
		{ 295, 327 },
		{ 295, -1 },
		{ 136, 243 },
		{ 328, 341 },
		{ 328, -1 },
		{ 270, 259 },
		{ 270, 74 },
		{ 270, 72 },
		{ 250, 315 },
		{ 250, 316 },
		{ 270, 260 },
		{ 25, 30 },
		{ 25, 39 },
		{ 25, 24 },
		{ 25, 26 },
		{ 355, -1 },
		{ 2, 42 },
		{ 209, 298 },
		{ 209, -1 },
		{ 355, -1 },
		{ 2, 41 },
		{ 2, 43 },
=======
		{ 367, 144 },
		{ 367, 138 },
		{ 367, 149 },
		{ 53, 141 },
		{ 355, 360 },
		{ 151, 251 },
		{ 274, 71 },
		{ 53, 143 },
		{ 53, 137 },
		{ 274, 32 },
		{ 274, 33 },
		{ 274, 29 },
		{ 336, 156 },
		{ 274, 30 },
		{ 274, 25 },
		{ 309, 337 },
		{ 36, 31 },
		{ 36, 24 },
		{ 309, -1 },
		{ 309, -1 },
		{ 274, 34 },
		{ 143, 141 },
		{ 151, 252 },
		{ 274, 26 },
		{ 307, 335 },
		{ 307, -1 },
		{ 143, 248 },
		{ 336, 348 },
		{ 336, -1 },
		{ 274, 257 },
		{ 274, 72 },
		{ 274, 74 },
		{ 243, 128 },
		{ 243, 311 },
		{ 274, 256 },
		{ 36, 27 },
		{ 36, 38 },
		{ 36, 28 },
		{ 36, 35 },
		{ 355, -1 },
		{ 2, 41 },
		{ 242, 310 },
		{ 242, -1 },
		{ 355, -1 },
		{ 2, 43 },
		{ 2, 42 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 355, -1 },
		{ 177, -1 },
		{ 355, -1 },
		{ 355, -1 },
<<<<<<< HEAD
		{ 177, -1 },
		{ 177, 177 },
		{ 355, -1 },
		{ 355, -1 },
		{ 39, 73 },
		{ 354, 359 },
		{ 155, 253 },
		{ 39, 71 },
		{ 177, 274 },
		{ 365, 351 },
=======
		{ 184, -1 },
		{ 184, 184 },
		{ 355, -1 },
		{ 355, -1 },
		{ 38, 75 },
		{ 354, 359 },
		{ 83, 174 },
		{ 38, 73 },
		{ 184, 277 },
		{ 365, 349 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 365, -1 },
		{ 365, -1 },
		{ 365, -1 },
		{ 353, 358 },
<<<<<<< HEAD
		{ 177, 174 },
		{ 25, 48 },
		{ 25, 37 },
=======
		{ 184, 181 },
		{ 36, 68 },
		{ 36, 37 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 365, -1 },
		{ 365, 369 },
		{ 365, 368 },
		{ 365, -1 },
		{ 365, -1 },
<<<<<<< HEAD
		{ 155, 59 },
		{ 75, 168 },
		{ 155, 24 },
		{ 155, 26 },
		{ 75, 166 },
		{ 31, 60 },
		{ 264, -1 },
		{ 96, 183 },
		{ 264, 321 },
		{ 96, -1 },
		{ 31, 61 },
		{ 75, 169 },
		{ 75, 167 },
		{ 264, -1 },
		{ 264, -1 },
		{ 164, 40 },
		{ 164, 39 },
		{ 164, 24 },
		{ 164, 166 },
		{ 343, 350 },
		{ 343, 349 },
		{ 343, 147 },
		{ 273, 324 },
		{ 273, -1 },
		{ 273, -1 },
		{ 163, -1 },
		{ 163, -1 },
		{ 163, 257 },
		{ 265, 112 },
		{ 43, 78 },
		{ 205, 294 },
		{ 205, -1 },
		{ 265, 323 },
		{ 43, 77 },
		{ 204, 293 },
		{ 204, -1 },
		{ 203, 292 },
		{ 203, -1 },
		{ 200, 290 },
		{ 200, -1 },
		{ 196, 286 },
		{ 196, -1 },
		{ 194, 108 },
		{ 194, 284 },
		{ 166, 39 },
		{ 166, 49 },
		{ 153, 249 },
		{ 153, 57 },
		{ 82, 173 },
		{ 82, 80 },
		{ 66, 157 },
		{ 66, 158 },
		{ 57, 67 },
		{ 57, 62 },
		{ 30, 54 },
		{ 30, 55 },
		{ 0, 25 },
		{ 0, 38 },
		{ 352, 357 },
		{ 349, 356 },
		{ 346, 355 },
		{ 344, 352 },
		{ 335, 345 },
		{ 332, 343 },
		{ 331, 342 },
		{ 308, 336 },
		{ 306, 334 },
		{ 303, 331 },
		{ 271, 263 },
		{ 246, 314 },
		{ 245, 313 },
		{ 243, 245 },
		{ 241, 311 },
		{ 223, 308 },
		{ 222, 307 },
		{ 220, 305 },
		{ 219, 304 },
		{ 216, 302 },
		{ 215, 153 },
		{ 208, 297 },
		{ 207, 296 },
		{ 206, 295 },
		{ 202, 291 },
		{ 199, 289 },
		{ 198, 288 },
		{ 197, 287 },
		{ 195, 285 },
		{ 193, 283 },
		{ 192, 282 },
		{ 191, 281 },
		{ 190, 280 },
		{ 186, 278 },
		{ 181, 178 },
		{ 171, 267 },
		{ 170, 266 },
		{ 165, 262 },
		{ 158, 254 },
		{ 154, 251 },
		{ 146, 248 },
		{ 134, 241 },
		{ 133, 229 },
		{ 132, 228 },
		{ 127, 222 },
		{ 126, 221 },
		{ 122, 217 },
		{ 106, 201 },
		{ 95, 182 },
		{ 94, 180 },
		{ 85, 176 },
		{ 55, 152 },
		{ 51, 117 },
		{ 47, 115 },
		{ 44, 81 },
		{ 34, 66 },
		{ 28, 50 },
		{ 26, -1 }
=======
		{ 83, 62 },
		{ 71, 162 },
		{ 83, 28 },
		{ 83, 35 },
		{ 71, 165 },
		{ 29, 61 },
		{ 260, -1 },
		{ 104, 191 },
		{ 260, 321 },
		{ 104, -1 },
		{ 29, 63 },
		{ 71, 163 },
		{ 71, 164 },
		{ 260, -1 },
		{ 260, -1 },
		{ 160, 40 },
		{ 160, 38 },
		{ 160, 28 },
		{ 160, 165 },
		{ 344, 351 },
		{ 344, 350 },
		{ 344, 146 },
		{ 278, 326 },
		{ 278, -1 },
		{ 278, -1 },
		{ 244, 312 },
		{ 244, -1 },
		{ 244, -1 },
		{ 166, -1 },
		{ 166, -1 },
		{ 166, 264 },
		{ 261, 157 },
		{ 42, 77 },
		{ 236, 305 },
		{ 236, -1 },
		{ 261, 323 },
		{ 42, 78 },
		{ 232, 303 },
		{ 232, -1 },
		{ 228, 299 },
		{ 228, -1 },
		{ 226, 124 },
		{ 226, 297 },
		{ 175, 269 },
		{ 175, 270 },
		{ 165, 38 },
		{ 165, 67 },
		{ 153, 253 },
		{ 153, 54 },
		{ 82, 173 },
		{ 82, 81 },
		{ 54, 47 },
		{ 54, 49 },
		{ 48, 86 },
		{ 48, 87 },
		{ 27, 56 },
		{ 27, 57 },
		{ 0, 36 },
		{ 0, 39 },
		{ 352, 357 },
		{ 350, 356 },
		{ 347, 355 },
		{ 345, 352 },
		{ 332, 346 },
		{ 329, 344 },
		{ 328, 343 },
		{ 286, 333 },
		{ 284, 331 },
		{ 281, 328 },
		{ 276, 262 },
		{ 248, 246 },
		{ 246, 313 },
		{ 241, 309 },
		{ 240, 308 },
		{ 239, 307 },
		{ 237, 306 },
		{ 235, 304 },
		{ 231, 302 },
		{ 230, 301 },
		{ 229, 300 },
		{ 227, 298 },
		{ 225, 296 },
		{ 224, 295 },
		{ 212, 294 },
		{ 211, 293 },
		{ 210, 292 },
		{ 206, 290 },
		{ 198, 286 },
		{ 197, 285 },
		{ 195, 283 },
		{ 194, 282 },
		{ 189, 182 },
		{ 186, 279 },
		{ 180, 153 },
		{ 171, 267 },
		{ 170, 266 },
		{ 161, 259 },
		{ 144, 249 },
		{ 127, 234 },
		{ 126, 233 },
		{ 121, 224 },
		{ 117, 203 },
		{ 112, 197 },
		{ 111, 196 },
		{ 107, 192 },
		{ 103, 190 },
		{ 102, 188 },
		{ 92, 185 },
		{ 87, 178 },
		{ 85, 177 },
		{ 59, 158 },
		{ 57, 152 },
		{ 50, 88 },
		{ 44, 80 },
		{ 35, -1 },
		{ 26, 52 },
		{ 24, 48 }
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
<<<<<<< HEAD
		{ 124, 25 },
		{ 7, 155 },
		{ 66, -1 },
		{ 0, -1 },
=======
		{ 125, 36 },
		{ 7, 83 },
		{ 66, -1 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 60, 153 },
		{ 201, 166 },
		{ 0, -1 },
		{ 229, 35 },
		{ 0, -1 },
		{ 133, 118 },
		{ 119, 57 },
		{ 15, 35 },
		{ 0, -1 },
		{ 210, 57 },
		{ -2, 163 },
		{ 0, -1 },
=======
		{ 213, 54 },
		{ 0, -1 },
		{ 230, 32 },
		{ 134, 89 },
		{ 0, -1 },
		{ 119, 54 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 166 },
		{ 15, 32 },
		{ 0, -1 },
		{ 200, 165 },
		{ 60, 153 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 74, 260 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 74, 264 },
		{ 0, -1 },
		{ 0, -1 },
=======
		{ 0, -1 },
		{ 0, -1 },
		{ 130, -1 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 127, -1 },
		{ 212, 82 },
		{ 0, -1 },
		{ 0, -1 },
		{ 228, 265 },
		{ 0, -1 },
		{ 132, 89 },
		{ 0, -1 },
<<<<<<< HEAD
=======
		{ 190, 89 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 188, 118 },
		{ 0, -1 },
		{ 13, 367 },
<<<<<<< HEAD
=======
		{ 165, 83 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 188, 215 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 166, 155 },
=======
		{ 190, 180 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 227, 261 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 129, 118 },
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
<<<<<<< HEAD
		{ 148, -1 },
=======
		{ 149, -1 },
		{ 97, 35 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 196, 179 },
=======
		{ 187, 180 },
		{ 0, 180 },
		{ -9, 153 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 243, 96 },
		{ 242, 96 },
		{ 143, 273 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 0, -1 },
		{ 0, -1 },
=======
		{ 242, 104 },
		{ 241, 104 },
		{ 143, 278 },
		{ 0, -1 },
		{ 0, -1 },
		{ 221, 261 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 239, 273 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
=======
		{ 219, 355 },
		{ 0, -1 },
		{ 0, -1 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 219, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 181, 367 },
		{ 232, 278 },
		{ 0, -1 },
		{ 70, 300 },
		{ 0, 215 },
		{ -9, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 221, 265 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 227, -1 },
		{ 226, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 248 },
		{ 0, -1 },
		{ 0, -1 },
		{ 219, 355 },
		{ 182, 367 },
		{ 218, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 31, 367 },
		{ 0, 243 },
		{ 0, -1 },
=======
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 31, 367 },
		{ 179, 367 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 180, 367 },
=======
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
=======
		{ 163, 32 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 162, 35 },
		{ 182, 337 },
		{ 97, 26 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 175, 215 },
=======
		{ 112, 274 },
		{ 213, 261 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 141, 276 },
		{ 120, 260 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 117, 264 },
		{ 112, 270 },
		{ 212, 265 },
		{ 140, 271 },
		{ 0, -1 },
		{ 0, -1 },
=======
		{ 0, -1 },
		{ 0, -1 },
		{ 212, 261 },
		{ 193, -1 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 211, 265 },
		{ 192, -1 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ -11, 177 },
		{ -22, -1 },
		{ 0, -1 },
		{ 90, 32 },
=======
		{ 128, 324 },
		{ 0, -1 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ -3, 181 },
		{ 0, -1 },
		{ 210, 355 },
		{ 0, -1 },
		{ 217, -1 },
		{ -11, 184 },
		{ 0, -1 },
<<<<<<< HEAD
=======
		{ -22, -1 },
		{ 90, 33 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 209, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 224, 273 },
		{ 223, 273 },
		{ 222, 273 },
		{ 220, 194 },
		{ 176, 273 },
		{ 218, 196 },
		{ 172, 200 },
		{ 216, 200 },
		{ 215, 200 },
		{ 214, 200 },
		{ 169, 203 },
		{ 0, -1 },
		{ 212, 203 },
		{ 166, 204 },
		{ 163, 205 },
		{ 158, 209 },
		{ 205, -1 },
		{ 198, 355 },
		{ 203, -1 },
		{ 96, 295 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 202, -1 },
		{ 159, 367 },
		{ 0, -1 },
		{ 0, -1 },
		{ 194, 355 },
		{ 193, 355 },
		{ 0, -1 },
		{ 156, 367 },
		{ 149, 336 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 219, 278 },
		{ 218, 278 },
		{ 217, 278 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 192, 300 },
=======
		{ 202, 316 },
		{ 214, 226 },
		{ 175, 278 },
		{ 212, 228 },
		{ 171, 232 },
		{ 210, 232 },
		{ 209, 232 },
		{ 208, 232 },
		{ 168, 236 },
		{ 0, -1 },
		{ 0, -1 },
		{ 206, 236 },
		{ 163, 244 },
		{ 195, 316 },
		{ 0, -1 },
		{ 198, -1 },
		{ 191, 355 },
		{ 196, -1 },
		{ 96, 307 },
		{ 89, 244 },
		{ 154, 242 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 153, 367 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 152, 367 },
		{ 189, 300 },
=======
		{ 194, -1 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
		{ 100, 274 },
		{ 152, 336 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 100, 270 },
		{ 149, 328 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 175 },
		{ 154, -1 },
		{ 0, -1 },
		{ 156, 196 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 183 },
		{ 0, -1 },
		{ 155, -1 },
		{ 0, -1 },
<<<<<<< HEAD
=======
		{ 156, 228 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 78, 297 },
		{ 0, -1 },
		{ 68, 328 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 355 },
		{ 0, -1 },
		{ 0, -1 },
		{ 191, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 184, 355 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 189, -1 },
=======
		{ 78, 309 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 68, 336 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 76, 300 },
		{ 0, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 146, 367 },
		{ 187, -1 },
=======
		{ 76, 316 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 0, -1 },
		{ 186, -1 },
		{ -20, 355 },
		{ -4, 300 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 94, 365 },
		{ 185, -1 },
		{ 0, -1 },
		{ 184, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 0, -1 },
		{ 182, -1 },
=======
		{ 185, -1 },
		{ 0, -1 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		{ 0, -1 },
		{ 183, -1 },
		{ 0, -1 },
<<<<<<< HEAD
		{ 140, 367 },
=======
		{ 141, 367 },
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
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
<<<<<<< HEAD
#line 2988 ".\\myparser.y"
=======
#line 2987 ".\\myparser.y"
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a


	/////////////////////////////////////////////////////////////////////////////
	// programs section

	int main(void)
	{
		files.open("D:\\code.txt");
		s.push_back(new varmap());
	//print-function
		type3->right = &voidnode;
		type3->left=&intnode;
		s[s.size()-1]->vartable["print"] = type3;
		s.push_back(new varmap());

	//  FILE *stream;
	// 	freopen_s(&stream, "in.txt", "r", stdin);
	// 	freopen_s(&stream, "out.txt", "w", stdout);
	// 	cout << "Name\t\tElement\t\tValue\t\tLine" << endl;
		int n = 1;
		mylexer lexer;
		myparser parser;
		if (parser.yycreate(&lexer)) {
			if (lexer.yycreate(&parser)) {
				n = parser.yyparse();
				show_code();
			}
		}
<<<<<<< HEAD
=======
		transcode();
		files.close();
>>>>>>> e149ef266ca1f9fbea04360d87d292f867b2005a
		getchar();

		return 0;
	}
