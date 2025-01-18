#include <iostream>
#include <vector>
using namespace std;

long long N,B;
vector<vector<long long>>num(5,vector<long long>(5));


vector<vector<long long>> multi_matrix(vector<vector<long long>> matrix1, vector<vector<long long>> matrix2) {
	vector<vector<long long>> tmp(5,vector<long long>(5));


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			long long sum = 0;

			for (int i = 0; i < N; i++) {
				sum += ((matrix1[y][i] % 1000) * (matrix2[i][x] % 1000)) % 1000;
			}

			tmp[y][x] = sum % 1000;		
		}
	}

	return tmp;
}

vector<vector<long long>> recursion(vector<vector<long long>> matrix, long long depth) {
    if (depth == 1) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matrix[i][j] %= 1000;
        return matrix;
    }

   
    vector<vector<long long>> half_matrix = recursion(matrix, depth / 2);
    vector<vector<long long>> result = multi_matrix(half_matrix, half_matrix);

    if (depth % 2 == 1) {
        result = multi_matrix(num, result);
    }

    return result;
}

int main() {
    cin>>N>>B;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>> num[i][j];
        }
    }

    num = recursion(num,B);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<num[i][j]<<' ';
        }
        cout<<endl;
    }
   
    return 0;
}