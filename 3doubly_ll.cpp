#include<iostream>
using namespace std;
// creating a node
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this-> data = data;
        this-> next = NULL;
        this-> prev = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data "<<" "<<val<<endl;
    }
};

int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, int d){
    //empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}
// void insertAtHead(Node* &head,Node* &tail, int d){
//     //empty list
//     if(head == NULL){
//         Node* temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else{
//     Node* temp = new Node(d);
//     temp -> next = head;
//     head -> prev = temp;
//     head = temp;
//     }
// }

void insertAtTail(Node* &tail, int d){
    //empty list
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    tail -> next = temp;
    temp-> prev = tail;
    tail = temp;
    }
}
// void insertAtTail(Node* &tail,Node* head, int d){
//     //empty list
//     if(tail == NULL){
//         Node* temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else{
//     Node* temp = new Node(d);
//     tail -> next = temp;
//     temp-> prev = tail;
//     tail = temp;
//     }
// }

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    // insert at start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

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
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}


void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp-> next;
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
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}
int main(){

    // Node* node1 = new Node(10);
    // cout<< node1 -> data << endl;
    // cout<< node1 -> next << endl;
    // cout<< node1 -> prev << endl;
    // Node* head = node1;
    // Node* tail= node1;
    Node* head = NULL;
    Node* tail= NULL;
    print(head);
    cout<<getLength(head)<<endl;
    insertAtHead(head,5);
    print(head);
    insertAtHead(head,7);
    print(head);
    insertAtHead(head,9);
    print(head);
    insertAtTail(tail,20);
    print(head);
    insertAtPosition(head,tail,2, 100);
    print(head);
    insertAtPosition(head,tail,1, 101);
    print(head);
    insertAtPosition(head,tail,7, 109);
    print(head);

    deleteNode(1,head);
    print(head);
    return 0;
}