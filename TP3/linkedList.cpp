// http://stackoverflow.com/questions/22141477/simple-linked-list-c
#include <iostream>
using namespace std;

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
    };

    Node *head; // this is the private member variable. It is just a pointer to the first Node

public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
    }

    // This prepends a new value at the beginning of the list
    void inserirInicio(int val){
        Node *n = new Node();   // create new Node
        n->x = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
    }

    // returns the first element in the list and deletes the Node.
    int removerPrimeiro(){
        Node *n = head;
        if(n == nullptr) return -666;//ERRO, LISTA VAZIA
        int ret = n->x;//ret isn't destroyed when it goes out of scope

        head = head->next;
        delete n;
        return ret;
    }
};

int main() {
    LinkedList list;

    list.inserirInicio(5);
    list.inserirInicio(10);
    list.inserirInicio(20);

    cout << list.removerPrimeiro() << endl;
    cout << list.removerPrimeiro() << endl;
    cout << list.removerPrimeiro() << endl;
    cout << list.removerPrimeiro() << endl;

    return 0;
}
