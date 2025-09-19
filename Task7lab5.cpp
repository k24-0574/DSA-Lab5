#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
	if(arr[x][y] && x<n &&y<n)
		return 1;
	
	return 0;
}

bool LionMaze(int** arr, int x, int y, int n, int** sol){
	if(x==n-1 && y==n-1 && arr[x][y]){
		sol[x][y]=1;
		return 1;
	}
	
	if(isSafe(arr, x, y, n)){
		sol[x][y]=1;
		if(LionMaze(arr, x+1, y, n, sol)) return 1;
		if(LionMaze(arr, x, y+1, n, sol)) return 1;
		sol[x][y]=0;
		return 0;
	}
	return 0;
}

int main(){
	
	int maze[5][5] = {1, 0, 1, 0, 1,
					  1, 1, 1, 1, 1,
					  0, 1, 0, 1, 1,
					  1, 0, 0, 1, 1, 
					  1, 1, 1, 0, 1	
					};
	int **arr = new int*[5];
	int **sol = new int*[5];
	for(int i=0;i<5;i++){
		sol[i] = new int[5];
		arr[i] = new int[5];
		for(int j=0;j<5;j++){
			arr[i][j]=maze[i][j];
			sol[i][j]=0;
		}
	} 
	 
	if(LionMaze(arr, 0, 0, 5, sol)) cout<<"Lion found a path"<<endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	} 
	for(int i=0;i<5;i++) delete[] sol[i];
	delete[] sol;
}