#include <iostream>
#include <vector>

using namespace std;

int mark_parent_nodes(vector< vector<int> > *graph_transpose, vector<int> *node_markings, int node, int mark, int max_mark, int depth){
    if (depth == 0)
        return -1;
    for(int parent : (*graph_transpose)[node-1]){
        if((*node_markings)[parent-1] == mark) {
            (*node_markings)[parent - 1] = max_mark;
        }
        if(mark_parent_nodes(graph_transpose, node_markings, parent, mark, max_mark, depth-1) == -1)
            return -1;
    }
    return 0;
}

int main() {
    int target1, target2, vertices, edges, v1, v2;
    scanf("%d %d", &target1, &target2);
    scanf("%d %d", &vertices, &edges);

    vector< vector<int> > graph_transpose(vertices);
    vector<int> node_markings(vertices,0);
    bool output = false, valid_graph = true;
    int i;

    for(i = 0; i != edges && scanf("%d %d", &v1, &v2) != EOF; i++) {
        graph_transpose[v2-1].push_back(v1);
        if(graph_transpose[v2-1].size() > 2) {
            valid_graph = false;
            break;
        }
    }

    if(!valid_graph || i != edges || mark_parent_nodes(&graph_transpose, &node_markings, target1, 0, 1, edges) == -1 ||
            mark_parent_nodes(&graph_transpose, &node_markings, target2, 1, 2, edges) == -1) {
        cout << "0" << endl;
        return 0;
    }

    for(i = 0; i < static_cast<int>(node_markings.size()); i++) {
        if(node_markings[i] == 2) {
            mark_parent_nodes(&graph_transpose, &node_markings, i + 1, 2, 1, edges);
        }
    }

    for(i = 0; i < static_cast<int>(node_markings.size()); i++) {
        if(node_markings[i] == 2) {
            cout << i+1 << ' ';
            output = true;
        }
    }

    if(!output) cout << '-';
    cout << endl;
    return 0;
}




