#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
};

void traversal(node* n)
{
	while(n!=NULL)
	{
		cout<<n->data<<"->";
		n=n->next;
	}
}

node* addnode(node** head, int data)
{
	node* p = new node();
	p->next = *head;
	p->data = data;
	*head = p;
}

node* insertatbetween(node** head, int data, int index)
{
	node* p = new node();
	node* ptr = *head;
	int i=0;
	while(i!= index-1)
	{
		ptr = ptr->next;
		i++;
	}
	p->data = data;
	p->next = ptr->next;
	ptr->next = p;
}

node* insertatend(node** head, int data)
{
	node* p = new node();
	node* ptr = *head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	p->next = NULL;
	p->data = data;
	ptr->next = p; 
}

void deletefirst(node* &head)
{
	node* ptr = head;
	head = head->next;
	delete ptr;
}

void deleteindex(node* &head, int index)
{
	node* p = head;
	int i=0;
	while(i != index-1)
	{
		p = p->next;
		i++;
	}
	node* q = p->next;
	p->next = q->next;
	delete q;
}

void deleteatend(node* &head)
{
	node* p = head;
	node* q = head->next;
	while(q->next != NULL)
	{
    p = p->next;
    q = q->next;
	}
	p->next = NULL;
	delete q;
}

int main()
{
	node* head = NULL;
	cout<<"THE LINKEDLIST IS EMPTY NOW."<<endl<<endl;
	while(true){
	cout<<"Do you want to insert elements in a present linked list: ";
	string s;
	cin>>s;
	cout<<endl;
	if(s == "yes")
	{
		int value;
		cout<<"enter the length of the linked list that you want to make: ";
		cin>>value;
		cout<<endl;
		cout<<"enter the elements which you want to be entered inside the linked list: "<<endl;
		for(int i=0 ;i<value; ++i)
		{
			int q;
			cin>>q;
			addnode(&head, q);
		}
		cout<<"The linked list that you have made is: ";
		traversal(head);
		cout<<endl<<endl;
		string ans;
		cout<<"DO YOU WANT TO MODIFY YOUR LINKED-LIST: ";
		cin>>ans;
		cout<<endl;
		if(ans == "yes")
		{
		int a;
		cout<<"enter 0 for inserting node at the beginning of the present linked-list."<<endl;
		cout<<"or"<<endl;
		cout<<"enter 1 for inserting node in between the present linked-list."<<endl;
		cout<<"or"<<endl;
		cout<<"enter 2 for inserting node at the end of the present linked-list"<<endl;
		cout<<"or"<<endl;
		cout<<"enter 3 for inserting node both in between and at the end of the linked-list simultaneously: "<<endl;
		cout<<"or"<<endl;
		cout<<"enter 4 for deleting the node at the beginning of the present linked-list: "<<endl;
		cout<<"or"<<endl;
		cout<<"enter 5 for deleting node in between the present linked-list: "<<endl;
		cout<<"or"<<endl;
		cout<<"enter 6 for deleting the node from the end of the present linked-list: "<<endl;
		cout<<"or"<<endl;
		cout<<"enter 7 for using all types of deleting functions simultaneously: "<<endl;
		cout<<endl;
		cin>>a;
		if(a == 0)
		{
			int x0;
			cout<<"enter data which you want to enter on the beginning of the present linked list: ";
			cin>>x0;
			cout<<"the linked list after inserting node on the beginning is: "<<endl;
			addnode(&head, x0); 
			traversal(head);
			cout<<endl;
      cout<<"insertion completed."<<endl;
			cout<<endl;
			cout<<"shifting to the next linked list."<<endl;
			cout<<endl<<endl;
		}
		else if(a == 1)
		{
			int x;
			int index1;
			cout<<"enter the data which you want to enter in the new node: ";
			cin>>x;
			cout<<endl;
			cout<<"enter the index where you want to insert the new node: ";
			cin>>index1;
			cout<<endl;
			cout<<"the linked list after inserting node in between is: "<<endl;	
			insertatbetween(&head, x, index1);
			traversal(head);
			cout<<endl;
      cout<<"insertion completed."<<endl;
			cout<<endl;
			cout<<"shifting to the next linked list."<<endl;
			cout<<endl<<endl;
		}
		else if(a == 2)
		{
			int  y;
			cout<<"enter the data which you want to enter: ";
			cin>>y;
			cout<<endl;
			cout<<"the linked list after inserting node at the end: "<<endl;
			insertatend(&head,y);
			traversal(head);
			cout<<endl;
			cout<<"insertion completed."<<endl;
			cout<<endl;
			cout<<"shifting to next linked list."<<endl;
			cout<<endl<<endl;
		}
		else if(a == 3)
		{
			int z0;
			int z1;
			int z2;
			cout<<"enter the number of times an element to be inserted on the beginning of the linkedlist: ";
			cin>>z0;
			cout<<endl;
			cout<<"enter data for elements to be inserted on the beginning: "<<endl;
			for(int i=0; i<z0; ++i)
			{
				int data7;
				cout<<"enter data: ";
				cin>>data7;
				cout<<endl;
				addnode(&head, data7);
			}
			
			cout<<"enter the number of times you want to insert an element in between the present linked-list: "; 
			cin>>z1;
			cout<<endl;
			cout<<"enter data and index for elements to be inserted in between: "<<endl;	
			for(int i=0; i<z1; ++i)
			{
				int data1;
				cout<<"enter data: ";
				cin>>data1;
				cout<<endl;
				int index2;
				cout<<"enter index: ";
				cin>>index2;
				cout<<endl;
				insertatbetween(&head, data1, index2);
			}
			cout<<"enter the number of times an element to be inserted at the end of the linkedlist: ";
			cin>>z2;
			cout<<endl;
			cout<<"enter data for elementsto be inserted at the end: "<<endl;
			for(int i=0; i<z2; ++i)
			{
				int data2;
				cout<<"enter data: ";
				cin>>data2;
				cout<<endl;
				insertatend(&head, data2);
			}
			cout<<"the linkedlist after inserting in between and at the end simultaneously: "<<endl;
			traversal(head);
			cout<<endl;
			cout<<"insertion completed.";
			cout<<endl;
			cout<<"shifting to next linked list."<<endl;
			cout<<endl<<endl;
		}
		else if(a == 4)
		{
			cout<<"after deleting the first node from the present linked list is: ";
			deletefirst(head);
			traversal(head);
			cout<<endl;
			cout<<"deletion completed.";
			cout<<endl;
			cout<<"shifting to next linked list."<<endl;
			cout<<endl<<endl;
		}
		else if(a == 5)
		{
			int index3;
			cout<<"enter the index which you want to delete: ";
			cin>>index3;
			cout<<endl;
			cout<<"the linked list after deleting node in between the present linked list: ";
			deleteindex(head, index3);
			traversal(head);
			cout<<endl;
			cout<<"deletion completed.";
			cout<<endl;
			cout<<"shifting to next linked list."<<endl;
			cout<<endl<<endl;
		}
		else if(a == 6)
		{
			cout<<"after deleting the last node from the present linked list is: ";
			deleteatend(head);
			traversal(head);
			cout<<endl;
			cout<<"deletion completed.";
			cout<<endl;
			cout<<"shifting to next linked list."<<endl;
			cout<<endl<<endl;
		}
		else if(a == 7)
		{
			int z3;
			int z4;
			int z5;
			cout<<"enter the number of times you want to delete the node from beginning of the linked list: ";
			cin>>z3;
			cout<<endl;
			for(int i=0; i<z3; ++i)
			{
				 deletefirst(head);
			}
			cout<<"enter the number of times you want to delete the node from the particular index of the linked list: ";
			cin>>z4;
			cout<<endl;
			for(int i=0; i<z4; ++i)
			{
				int index4;
				cout<<"enter index: ";
				cin>>index4;
				cout<<endl;
				deleteindex(head, index4);
			}
			cout<<"enter the number of times you want to delete the node from the end of the present linked list: ";
			cin>>z5;
			cout<<endl;
			for(int i=0; i<z5; ++i)
			{
				deleteatend(head);
			}
			cout<<"the linkedlist after deleting nodes at beginning, at index and at the end simultaneously: "<<endl;
			traversal(head);
			cout<<endl;
			cout<<"deletion completed.";
			cout<<endl;
			cout<<"shifting to next linked list."<<endl;
			cout<<endl<<endl;
		}
		else
		{
			cout<<"you entered the wrong key."<<endl;
		}
   }
   else if(ans == "no")
   {
   	cout<<"the final linked list that you have made is: ";
   	traversal(head);
   	cout<<endl<<endl;
		cout<<"shifting to next linked list."<<endl;
		cout<<endl<<endl;
	 }
	}
	else if(s == "no")
	{
		cout<<"No further linked list is made, thank you for your response."<<endl;
		break;
	}
	else
	{
		cout<<"sorry! invalid response..."<<endl;
		cout<<endl;
	}
}	
	return 0;
}