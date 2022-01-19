#include <iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};

Node* newNode(int key){
    Node *aux = new Node;
    aux->key = key;
    aux->left = aux->right = NULL;
    return aux;
}

Node* genealogicalTree(){

}

int main() {
    string line;
    while(cin) {
        getline(cin, line);

    }
    return 0;
}
