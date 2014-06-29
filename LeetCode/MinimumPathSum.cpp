#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int> > minSum;

		int i, j;
		

		for(i = 0;i < m; i++ )
		{
			vector<int> temp;
			for(j = 0;j < n; j++)
				temp.push_back(0);

			minSum.push_back(temp);
		}

		int lmin = 0;
		int umin = 0;
		int min = 0;

		minSum[0][0] = grid[0][0];

		for(i = 0; i < m; i ++)
			for(j = 0; j < n; j++)
			{
				if( i == 0 && j == 0)
					continue;

				if( i == 0)
					umin = INT_MAX;
				else
					umin = minSum[i - 1][j];

				if(j == 0)
					lmin = INT_MAX;
				else
					lmin = minSum[i][j - 1];

				min = (umin < lmin ? umin:lmin);
				minSum[i][j] = grid[i][j] + min;
			}

			return minSum[m - 1][n - 1];
	}

};

int main()
{
	Solution s;
	vector<vector<int> > grid;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	grid.push_back(temp);

	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	grid.push_back(temp);

	s.minPathSum(grid);
}
