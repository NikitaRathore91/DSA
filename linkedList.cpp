#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int x;
    node* next;

    node(int y){
        x=y;
        next=NULL;
    }
};

void insertathead(node* &head){
    int x;
    cout<<"Enter element to insert at head: ";
    cin>>x;
node* new_node=new node(x);
new_node->next=head;
head=new_node;
}

void insertatend(node* &head){
int x;
cout<<"Enter element to insert at end: ";
cin>>x;
node* new_node=new node(x);
node* temp=head;
while(temp->next!=NULL){
    temp=temp->next;}
temp->next=new_node;
}

void insertatanyposition(node* head){
    int n;
    cout<<"Enter element position to insert: ";
    cin>>n;

     int x;
    cout<<"enter elemnt to insert at any position: ";
    cin>>x;
    if(n==0){
        insertathead(head);
        return;
    }
    node* new_node=new node(x);
    node*temp=head;
    int current_position=0;
    while(current_position!=n-1){
temp=temp->next;
current_position++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void deleteathead(node* &head){
    node*temp=head;
    head=head->next;
    delete temp;
}

void deleteatend(node* &head){
    node*secondlast=head;
    while(secondlast->next->next!=NULL){
        secondlast=secondlast->next;
    }
    node*temp=secondlast->next;
    secondlast->next=NULL;
free(temp);
}

void deleteatanyposition(node*&head){
    int n;
    cout<<"enter position to delete: ";
    cin>>n;
    if(n==0){
        deleteathead(head);
        return;}
    node* prev=head;
    int current_position=0;
    while(current_position!=n-1){
        prev=prev->next;
        current_position++;
    }
    node* temp=prev->next;
prev->next=prev->next->next;
free(temp); 
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->x<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
  node* head=NULL;
  insertathead(head);
  display(head);
  insertatend(head);
  display(head);
  insertathead(head);
  display(head);
  insertatend(head);
  display(head);
  insertathead(head);
  display(head);
  insertatend(head);
  display(head);
  insertathead(head);
  display(head);


  
  
  

  insertatanyposition(head);
  display(head);
   insertatanyposition(head);
  display(head);


cout<<"After deletion at head: ";
deleteathead(head);
display(head);

cout<<"After deletion at end: ";
deleteatend(head);
display(head);


deleteatanyposition(head);
cout<<"After deletion at position: ";
display(head);


  return 0;}