#include <iostream>
#include <vector>

using namespace std;

void mark_parent_nodes(vector< vector<int> > *graph_transpose, vector<int> *node_markings, int node, int mark, int max_mark){
    for(int parent : (*graph_transpose)[node-1]){
        if((*node_markings)[parent-1] == mark)
            (*node_markings)[parent-1] = max_mark;
        mark_parent_nodes(graph_transpose, node_markings, parent, mark, max_mark);
    }
}

int main() {
    int target1, target2, vertices, edges, v1, v2;
    scanf("%d %d\n", &target1, &target2);
    scanf("%d %d\n", &vertices, &edges);

    vector< vector<int> > graph_transpose(vertices);
    vector<int> node_markings(vertices,0);
    bool output = false, valid_graph = true;

    while(vertices-- > 0) {
        scanf("%d %d\n", &v1, &v2);
        graph_transpose[v2-1].push_back(v1);
        if(graph_transpose[v2-1].size() > 2) {
            valid_graph = false;
            break;
        }
    }

    if(!valid_graph) {
        cout << "0" << endl;
        return 0;
    }

    mark_parent_nodes(&graph_transpose, &node_markings, target1, 0, 1);
    mark_parent_nodes(&graph_transpose, &node_markings, target2, 1, 2);

    for(int i = 0; i < node_markings.size(); i++) {
        if(node_markings[i] > 1) {
            mark_parent_nodes(&graph_transpose, &node_markings, i+1, 2, 1);
        }
    }

    for(int i = 0; i < node_markings.size(); i++) {
        if(node_markings[i] == 2) {
            cout << i+1 << ' ';
            output = true;
        }
    }

    if(!output) cout << '-';

    return 0;
}
