#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void flord(vector<vector<int>> &matrix,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k = 0;k<n;k++){
				if(matrix[i][k] < INT_MAX && matrix[k][j] < INT_MAX){
					matrix[i][j] = matrix[i][j]<(matrix[i][k]+matrix[k][j])?matrix[i][j]:matrix[i][k]+matrix[k][j];
				}
				
			}
			
		}
		
	}
}

int main(){
	int vex_num = 0; //顶点的个数
	int edge_num = 0;
	cin >> vex_num;
	cin >> edge_num;
	vector<vector<int>> vex_matrix(vex_num,vector<int>(vex_num,INT_MAX));
	for (int i = 0; i < edge_num;i++){
		int vertex1 = 0, vertex2 = 0;
		cin >> vertex1 >> vertex2;
		cin >> vex_matrix[vertex1][vertex2];
		//vex_matrix[vertex2][vertex1] = vex_matrix[vertex1][vertex2];
	}
    flord(vex_matrix);
	for (int i = 0; i < vex_num;i++){
		cout << 0 << "-" << i << ":" <<vex_matrix[0][i] << endl;
	}


}