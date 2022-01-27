#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
//constructor
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }

//destructor
    ~Node(){
        int val = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

        cout<<"Memory is free for node with data"<< " " <<val <<endl;
    }
};

void insertAtHead(Node* &head, int d){

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;   //(tail -> next)
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    // insert at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    // if we know length of ll
    // if(len == position -1){
    //     insertAtTail(tail, d);
    //     return;
    // }

    // inset at position
    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }

// insert at last 
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head-> next;
        // memory free start node 
        temp -> next = NULL;
        delete temp;
    }

    else{
        //deleting middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

// traversing a linked list
void print(Node* &head ){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<< endl;
}

int main(){

    // created a new node
    Node* node1 = new Node(10);
    // cout<< node1 -> data << endl;
    // cout<< node1 -> next << endl;
// head pointed node1
    Node* head = node1;
    // tail pointed node1
    Node* tail = node1;
// head pointed
    // print(head);
    // insertAtHead(head, 12);
    // print(head);
    // insertAtHead(head, 15);
    // print(head);

// tail pointed
    print(head);
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head,tail, 3, 22);
    print(head);

    deleteNode(2,head);
    print(head);
    return 0;
}