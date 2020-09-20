#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    queue<pair<int, int> > myqueue;

    int numberOfIslands = 0;

	Solution(){

	}

    bool validGrid(int i, int j, vector<vector<char> >& grid){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return false;
        } else {
            return true;
        }
    }

    void deletedElements(int i, int j , vector<vector<char> >& grid){
            grid[i][j] = '0';
            if (validGrid(i-1, j, grid)) {
                myqueue.push({i-1, j});
            }
            if (validGrid(i+1, j, grid)) {
                myqueue.push({i+1, j});
            }
            if (validGrid(i, j-1, grid)) {
                myqueue.push({i, j-1});
            }
            if (validGrid(i, j+1, grid)) {
                myqueue.push({i, j+1});
            }
    }

	// using BFS to do grid broadcast
    void broadcastGrid(int i, int j, vector<vector<char> >& grid){
        if (grid[i][j] == '1') {
            numberOfIslands++;
            myqueue.push({i, j});

            while (!myqueue.empty()){
                pair<int, int> top = myqueue.front();
                myqueue.pop();

                deletedElements(top.first, top.second, grid);
                
            }   
        }
    }


    int numIslands(vector<vector<char> >& grid) {

		while(!myqueue.empty()) myqueue.pop();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == '1'){
					broadcastGrid(i, j, grid);
				}
            }
        }
        return numberOfIslands;
    }
};

void testcase_1(){
	Solution sol;
	vector<char> v1 = {'1','1','0','0','0'};
	vector<char> v2 = {'1','1','0','0','0'};
	vector<char> v3 = {'0','0','1','0','0'};
	vector<char> v4 = {'0','0','0','1','1'};

	vector<vector<char> > grid;
	grid.push_back(v1);
	grid.push_back(v2);
	grid.push_back(v3);
	grid.push_back(v4);

	int num = sol.numIslands(grid);

	cout << "num:" << num << endl;
}

void testcase_2(){
	Solution sol;
	vector<char> v1 = {'1'};
	vector<char> v2 = {'1'};

	vector<vector<char> > grid;
	grid.push_back(v1);
	grid.push_back(v2);

	int num = sol.numIslands(grid);

	cout << "num:" << num << endl;
}

int main(){

	testcase_2();

	return 0;
}
