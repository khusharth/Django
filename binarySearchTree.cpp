#include<iostream>
#include<cstring>
using namespace std;
	struct node {
	
		char k[20],m[20];		
		node *lc,*rc;
	};


class BST{

	node *root;
	public:
		BST()	
		{
			root = 0;
		}//constructor

		void create(); 
		void display();
		void display(node *n);

	};//classBST


void BST :: create(){

		node *temp=0,*r=0;
		char ch='y';
		while(ch=='y')
		{
			temp=new node();
			cout<<"\n Enter the Keyword: ";
			cin>>temp->k;
			cout<<"\n Enter the Meaning: ";
			cin>>temp->m;
			temp->lc = temp->rc = 0;
			
			if(root == 0)
				root = temp; //Set new node as ROOT
			else{
				r = root;
					while(1)
					{
						if(strcmp(temp->k,r->k)<0)  //If the NEW key is less than ROOT //LeftChild
						{
							if(r->lc==0)
							{
								r->lc = temp;
								break;
							}
							else
							{
							 r=r->lc;
							}
						}//DoneWithLeft

						else if(strcmp(temp->k,r->k)>0)
						{
							if(r->rc==0)
							{
								r->rc = temp;
								break;
							}
							else
							{
							 r=r->rc;
							}
						}//DoneWithRight

	
					}//innerWhile

			} //else

				cout<<"DO you want to add more items?[y/n]: ";
				cin>>ch;
		

		}//while 	


	    }//create

void BST :: display()
{
	cout<<"\n Ascending order Display"<<endl;
	display(root);
//	cout<<"\n Descending order Display"<<endl;
//	display_rev(root);		
}

void BST :: display(node *n)
{
	if(n!=0)
	{
		display(n->lc);
		cout<< "Keyword is: "<<n->k;
		cout<< "\tMeaning is: "<<n->m<<endl;
		display(n->rc);		
	}
}
int main()
{
	int choice;
	BST b;
	do{
		cout<<"*+*+*+*+*+*+*DICTIONARY+*+*+*+*+*+*+*"<<endl<<endl;
		cout<<"Choose from the following: \n1) TO Create \n2) TO Display \n3) To Exit \nEnter your Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				b.create();
				cout<<endl;
				break;
			case 2:
				b.display();
				cout<<endl;
				break;
			case 3:
				cout<<"Thank you for using our application.... :-)"<<endl;
				cout<<endl;
				break;

			default:
				cout<<"Invalid choice Please try again :-)"<<endl;
				cout<<endl;
				break;
				
		}


	}while(choice != 3);

	return 0;
}
