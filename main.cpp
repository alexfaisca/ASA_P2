#include <iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};

struct geneologicalTree{
    Node *nodes;
};

Node* newNode(int key){
    Node *aux = new Node;
    aux->key = key;
    aux->left = aux->right = NULL;
    return aux;
}

Node *findNode(geneologicalTree *tree, int key){
    Node *source[];
}

Node *createNode(geneologicalTree *tree, int key){

}

geneologicalTree *addChild(Node *parent, Node *child){
    if(parent->left == NULL) {
        parent->left = child;
    } else{
        parent->right = child;
    }
}

int main() {
    int target1, target2, vertices, edges, v1, v2;
    scanf("%d %d\n", &target1, &target2);
    scanf("%d %d\n", &vertices, &edges);

    while(vertices-- > 0) {
        scanf("%d %d\n", &v1, &v2);
        if(findNode(v1) == NULL)
            struct Node* node = newNode(v1);
        addChild(findNode(v1), createNode(v2));
    }

    return 0;
}
