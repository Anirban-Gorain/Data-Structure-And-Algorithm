#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> board)
    {
        int rows=board.size();
        int cols=board[0].size();

        vector<vector<int>> prefixSumRows(rows+1, vector<int> (cols+1, 0));

        for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=cols; j++)
            {
                // i=row, j=col

                prefixSumRows[i][j]=prefixSumRows[i][j-1]+board[i-1][j-1];
            }
        }

        int maxArea=0; 
        int psRow, psClm, peRow, peClm; // p=preserve, preserving the row and col for future.

        for(int stClm=1; stClm<=cols; stClm++)
        {
            for(int endClm=stClm; endClm<=cols; endClm++)
            {
                int combinePreSum=0;
                unordered_map<int, int> storePreSum; // sum, stRow
                storePreSum[0]=1;

                for(int row=1; row<=rows; row++)
                {
                    combinePreSum+=(prefixSumRows[row][endClm]-prefixSumRows[row][stClm-1]);

                    if(storePreSum.count(combinePreSum)==1)
                    {
                        int length=endClm-stClm+1;
                        int brewth=row-storePreSum[combinePreSum];
                        int area=length*brewth;

                        if(area>maxArea)
                        {
                            psRow=storePreSum[combinePreSum]+1;
                            peRow=row;
                            psClm=stClm;
                            peClm=endClm;
                            maxArea=area;
                        }
                    }
                    else
                        if(storePreSum.count(combinePreSum)==0)
                            storePreSum[combinePreSum]=row;
                }
            }
        }

        // Construction the final result.

        vector<vector<int>> ans;

        while(psRow<=peRow)
        {
            vector<int> ansRow;

            for(int clm=psClm; clm<=peClm; clm++)
            {
                ansRow.push_back(board[psRow-1][clm-1]);
            }

            psRow++;

            ans.push_back(ansRow);
        }

        return ans;
    }
};

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    // sumZeroMatrix({{9, 7, 16, 5}, {1,-6, -7, 3}, {1, 8, 7, 9}, {7, -2, 0, 10}});

    return 0;

}