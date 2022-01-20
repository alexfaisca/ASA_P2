#include <iostream>
#include <vector>

using namespace std;


void mark_parent_nodes(vector< vector<int> > graph_transpose, vector<int> node_markings, int mark, int max_mark);


int main() {
    int target1, target2, vertices, edges, v1, v2;
    scanf("%d %d\n", &target1, &target2);
    scanf("%d %d\n", &vertices, &edges);

    vector< vector<int> > graph_transpose(vertices);
    vector<int> node_markings(vertices,0);
    bool valid_graph = true;

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
    return 0;
}
