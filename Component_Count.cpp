#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
  visited[i][j] = true;

  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      int x = i + dx;
      int y = j + dy;

      if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] == 1 && !visited[x][y]) {
        dfs(grid, visited, x, y);
      }
    }
  }
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<vector<int>> grid(N, vector<int>(M, 0));

  // Read the grid from input.
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<bool>> visited(N, vector<bool>(M, false));

  int num_connected_components = 0;
for (int i = 0; i < N; ++i) {
  for (int j = 0; j < M; ++j) {
    if (grid[i][j] == 1 && !visited[i][j]) {
      num_connected_components++;
      dfs(grid, visited, i, j);
    }
  }
}

  // Initialize the number of connected components.

  // Perform a depth-first search to find all connected components.
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 1 && !visited[i][j]) {
        num_connected_components++;
        dfs(grid, visited, i, j);
      }
    }
  }

  // If the number of connected components is not equal to K, then there is no solution.
  if (num_connected_components != K) {
    cout << 0 << endl;
    return 0;
  }

  // Calculate the number of ways to paint the grid.
  int num_ways = 1;
  for (int i = 0; i < K; ++i) {
    num_ways *= (N * M - i);
  }

  // Output the number of ways.
  cout << num_ways << endl;

  return 0;
}


