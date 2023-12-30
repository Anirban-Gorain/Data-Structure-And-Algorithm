#include<bits/stdc++.h>
using namespace std;

class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int>> &matrix, int n)
    {
        if(n == 1)
            return matrix[0][0];
            
        int ans = 0;
        
        // traverse all columns of 0th row
        for(int i = 0; i < n; i++){
            vector<vector<int>> second(n - 1, vector<int> (n - 1));
            
            // traverse all rows of second matrix
            for(int j = 1; j < n; j++){
                int x = 0;
                
                // traverse all columns of second matrix
                for(int k = 0; k < n; k++){
                    if(k == i)
                        continue;
                        
                    second[j - 1][x++] = matrix[j][k];
                }
            }
            
            ans += matrix[0][i] * determinantOfMatrix(second, n - 1) * ((i & 1) ? -1 : 1);
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

    

    return 0;

}