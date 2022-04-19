#include <bits/stdc++.h>
#define isz(x) (int)x.size()
#define fr first
#define sc second

using namespace std;

const int INF = 1e9;
int main(){
    system("chcp 1251");
    int count_vertex,number_of_edges;
    std::cin >> count_vertex >> number_of_edges;
    vector < vector <int> > edges(count_vertex + 1);
    vector < vector <int> > bandwidth(count_vertex + 1, vector <int> (count_vertex + 1,0));
    for (int i = 0;i < number_of_edges;i++){
        int u,v,cur_bandwidth_first,cur_bandwidth_second;
        std::cin >> u >> v >> cur_bandwidth_first >> cur_bandwidth_second;
        edges[u].push_back(v);
        edges[v].push_back(u);
        bandwidth[u][v] = cur_bandwidth_first;
        bandwidth[v][u] = cur_bandwidth_second;
    }
    /*
    for (int i = 1;i <= count_vertex;i++){
        std::cout << "cur_vertex = " << i << ":\n";
        for (auto edge : edges[i]){
            std::cout << edge << ' ' << bandwidth[i][edge] << " ---> ";
        }
        std::cout << "\n----->\n";
    }
    */
    int start_vertex,finish_vertex;
    std::cin >> start_vertex >> finish_vertex;
    vector <int> all_mins;
    while(true){
        set < pair <int,int> > bfs;
        bfs.insert({-INF,start_vertex});
        vector <bool> used_vertex(count_vertex + 1,false);
        vector <int> pred(count_vertex + 1);
        int pred_vertex = -1;
        used_vertex[start_vertex] = true;
        bool correct = true;
        int cur_min = 1e9;
        while(isz(bfs) > 0){
            auto [cur_bandwidth,cur_vertex] = *bfs.begin();
            bfs.erase({cur_bandwidth,cur_vertex});
            cur_min = min(cur_min,-cur_bandwidth);
            pred[cur_vertex] = pred_vertex;
            if (cur_vertex == finish_vertex){
                break;
            }
            for (auto adjacent_vertex : edges[cur_vertex]){
                if (!used_vertex[adjacent_vertex] && bandwidth[cur_vertex][adjacent_vertex] > 0){
                    bfs.insert({-bandwidth[cur_vertex][adjacent_vertex],adjacent_vertex});
                }
            }
            if (isz(bfs) == 0){
                int pred_for_cur = pred[cur_vertex];
                if (pred_for_cur == -1){
                    correct = false;
                    break;
                }
                int pred_for_pred = pred[pred[cur_vertex]];
                used_vertex[cur_vertex] = true;
                bfs.insert({-bandwidth[pred_for_pred][pred_for_cur],pred_for_cur});
                pred_vertex = pred_for_pred;
                continue;
            }
            /*
            for (auto cur : bfs){
                std::cout << cur.fr << ' ' << cur.sc << "\n";
            }
            */
            auto [up_bandwidth,up_vertex] = *bfs.begin();
            bfs.clear();
            bfs.insert({up_bandwidth,up_vertex});
            used_vertex[up_vertex] = true;
            /*
            for (auto cur : bfs){
                std::cout << cur.fr << ' ' << cur.sc << "\n";
            }
            */
            pred_vertex = cur_vertex;
        }
        if (!correct){
            break;
        }
        std::cout << "Сквозной путь - ";
        int cur = finish_vertex;
        std::cout << cur << ' ';
        while(pred[cur] != -1){
            std::cout << pred[cur] << ' ';
            bandwidth[cur][pred[cur]] += cur_min;
            bandwidth[pred[cur]][cur] -= cur_min;
            cur = pred[cur];
        }
        std::cout << "\n";
        for (int i = 1;i <= count_vertex;i++){
            std::cout << "cur_vertex = " << i << ":\n";
            for (auto edge : edges[i]){
                std::cout << edge << ' ' << bandwidth[i][edge] << " ----> ";
            }
            std::cout << "\n---->\n";
        }
        std::cout << "cur_min = " << cur_min << "\n";
        all_mins.push_back(cur_min);
    }
    /*
    std::cout << "after\n";
    for (int i = 1;i <= count_vertex;i++){
        std::cout << "cur_vertex = " << i << ":\n";
        for (auto edge : edges[i]){
            std::cout << edge << ' ' << bandwidth[i][edge] << " ----> ";
        }
        std::cout << "\n---->\n";
    }
    */
    int maximum_flow = 0;
    for (int i = 0;i < isz(all_mins);i++){
        maximum_flow += all_mins[i];
    }
    std::cout << "максимальный поток = " << maximum_flow;
}
