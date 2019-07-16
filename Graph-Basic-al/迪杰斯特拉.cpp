#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dijkstra(vector<bool> &iv,vector<vector<int>> &matrix,int ver){
	iv[ver] = true;
	while(count(iv.begin(),iv.end(),false) > 0){
		int index = 0;
		int i = 0;
		for (; i < iv.size();i++){
			if (!iv[i]){
				index = i;
				break;
			}
		}
		for (i = index + 1; i < iv.size();i++){
			if (matrix[ver][i] < matrix[ver][index] && !iv[i]){
				index = i;
			}
		}
		iv[index] = true;
		for (i = 0; i < iv.size();i++){
			if (!iv[i] && matrix[index][i] < INT_MAX){
				matrix[ver][i] = matrix[ver][i] > (matrix[ver][index] + matrix[index][i]) ? matrix[ver][index] + matrix[index][i] : matrix[ver][i];
			}
			
		}
	}

}

int main(){
	int vex_num = 0; //顶点的个数
	int edge_num = 0;
	cin >> vex_num;
	cin >> edge_num;
	vector<bool> is_visited(vex_num,false);
	vector<vector<int>> vex_matrix(vex_num,vector<int>(vex_num,INT_MAX));
	for (int i = 0; i < edge_num;i++){
		int vertex1 = 0, vertex2 = 0;
		cin >> vertex1 >> vertex2;
		cin >> vex_matrix[vertex1][vertex2];
		//vex_matrix[vertex2][vertex1] = vex_matrix[vertex1][vertex2];
	}
	vector<int> ans; //存放结果
    dijkstra(is_visited,vex_matrix,0);
	for (int i = 0; i < vex_num;i++){
		cout << 0 << "-" << i << ":" <<vex_matrix[0][i] << endl;
	}


}