#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head,int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next= nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }else {
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

void display(Node*& head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main() {
    Node *head = nullptr;
    insert(head,5);
    insert(head,8);
    display(head);
}