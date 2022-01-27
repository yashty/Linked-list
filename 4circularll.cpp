
#include<iostream>
using namespace std;
// creating a node
class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }

    ~Node(){
      int val = this -> data;
      if(this -> next != NULL){
         delete next;
         next = NULL;
      }
      cout<<"Memory is free for node with data "<< val<<endl;
    }
};

void insertNode(Node* &tail, int element,int d){
   //assuming that the element is present in the list 
   // empty list 
   if(tail == NULL){
      Node* newnode = new Node(d);
      tail = newnode;
      newnode -> next = newnode;
   }
   else{
      Node* curr = tail;
      while(curr -> data != element){
         curr = curr -> next;
      }

      // element found -> curr is representing element wala node
      Node* temp = new Node(d);
      temp -> next = curr -> next;
      curr -> next = temp;
   }
}

void deleteNode(Node* &tail, int value){
   if(tail == NULL){
      cout<<"List is empty, plese check again"<<endl;
      return;
   }
   else{
      // non empty
      Node* prev = tail;
      Node* curr = prev -> next;

      while(curr -> data != value){
         prev = curr;
         curr = curr -> next;
      }

      prev -> next = curr -> next;
      // 1 node ll 
      if(curr == prev){
         tail = NULL;
      }
      if(tail == curr){
         tail = prev;
      }
      curr -> next = NULL;
      delete curr;
   }
}

void print(Node* tail){
   Node * temp = tail;

   if(tail == NULL){
      cout<<"List is Empty"<<endl;
      return;
   }
   do{
      cout<< tail -> data<<" ";
      tail = tail -> next;
   }
   while(tail != temp);
   cout<<endl;
}

int main(){

   Node* tail = NULL;
   insertNode(tail,5,3);
   print(tail);
   insertNode(tail,3,5);
   print(tail);
   insertNode(tail,5,7);
   print(tail);
   insertNode(tail,7,9);
   print(tail);
   insertNode(tail,5,6);
   print(tail);
   insertNode(tail,9,10);
   print(tail);
   insertNode(tail,3,4);
   print(tail);
   deleteNode(tail,3);
   print(tail);
   deleteNode(tail,10);
   print(tail);

   return 0;
}