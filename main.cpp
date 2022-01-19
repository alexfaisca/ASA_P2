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
    int v1, v2, vertices, edges, target1, target2;
    scanf("%d %d\n", &target1, &target2);
    scanf("%d %d\n", &vertices, &edges);

    while(vertices-- > 0) {
        scanf("%d %d\n", &v1, &v2);
    }
    return 0;
    return 0;
}
