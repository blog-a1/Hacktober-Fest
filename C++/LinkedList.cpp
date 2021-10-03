#include <iostream>
using namespace std;

class Node
{
    public:
    int data; 
    Node *next;
};
Node *head=NULL;

void insert_beg()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    Node *ptr=new Node();
    ptr->data=n;
    ptr->next=head;
    head=ptr;
    cout<<"Node inserted in the beginning!!!"<<endl;
}

void insert_middle()
{
    int n,position;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the position: ";
    cin>>position;
    Node *ptr=new Node();
    ptr->data=n;
    ptr->next=NULL;
    if(position==1)
    {
        ptr->next=head;
        head=ptr;
        cout<<"Node inserted at position: "<<position<<endl;
        return;
    }
    Node *temp=head;
    for(int i=0;i<position-2;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;    
    cout<<"Node inserted at position: "<<position<<endl;
}

void insert_end()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    Node *ptr=new Node();
    ptr->data=n;
    ptr->next=NULL;
    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    cout<<"Node inserted at the end!!!"<<endl;
}

void delete_beg()
{
    if(head==NULL)
    {
        cout<<"List is empty!!!";
    }
    else
    {
        Node *temp=head;
        head=temp->next;
        free(temp);
        cout<<"Node deleted from the beginning!!!"<<endl;
    }
}

void delete_middle()
{
    if(head==NULL)
    {
        cout<<"List is empty!!!"<<endl;
    }
    else
    {
        int position;
        cout<<"Enter the position to be deleted: ";
        cin>>position;
        Node *temp=head,*next_node;
        for(int i=1;i<position-1;i++)
        {
            temp=temp->next;
        }
        next_node=temp->next;
        temp->next=next_node->next;
        free(next_node);
        cout<<"Node deleted from the given position!!!"<<endl;
    }
}

void delete_end()
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"List is empty!!!";
    }
    else if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
        cout<<"Node deleted!!!"<<endl;
    }
    else
    {
        Node *prev_node;
        while(temp->next!=NULL)
        {
            prev_node=temp;
            temp=temp->next;
        }
       prev_node->next=NULL;
       free(temp);
       cout<<"Node deleted from the end!!!"<<endl;
    }
}

void search()
{
    int n,position=1;
    cout<<"Enter the element to be searched: ";
    cin>>n;
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"List is empty!!!";
    }
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            cout<<"The element is found at position "<<position<<endl;
            return;
        }
        temp=temp->next;
        position++;
    }
    cout<<"The element was not found!!!"<<endl;
}

void display()
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"List is empty!!!"<<endl;
    }
    else
    {
        cout<<"List is: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    insert_beg();
    insert_middle();
    insert_end();
    delete_beg();
    delete_middle();
    delete_end();
    search();
    display();
    return 0;
}
