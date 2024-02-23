/*  Problem 931 (medium), Falling Path Sum

    Given an n x n array of integers matrix, return the minimum sum of any 
    falling path through matrix.

    A falling path starts at any element in the first row and chooses the 
    element in the next row that is either directly below or diagonally left/right. 
    
    Specifically, the next element from position (row, col) will be (row + 1, col - 1), 
    (row + 1, col), or (row + 1, col + 1).

    Constraints
        n == matrix.length == matrix[i].length
        1 <= n <= 100
        -100 <= matrix[i][j] <= 100
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cassert>


class Solution {
public:

    void printPath(const std::vector<int>& path)
    {
        std::cerr << "Path\n";
        for(auto p : path)
        {
            std::cerr << p << " ";
        }

        std::cerr << "\n";
    }

    int minFallingPathSum(std::vector<std::vector<int>>& matrix) 
    {
        int n = matrix.size();

        // dynamic programming, top down approach
        for(int r = 1; r < n; ++r)
        {
            for(int c = 0; c < n; ++c)
            {
                matrix[r][c] += minNeighbor(matrix[r-1], c, n);
            }
        }
        
        int min = matrix[n-1][0];
        for(int i = 1; i < n; ++i)
        {
            if(matrix[n-1][i] < min)
            {
                min = matrix[n-1][i];
            }
        }
    
        return min;
    }

    int minNeighbor(const std::vector<int>& rowVector, int col, int n)
    {
        int min = rowVector[col];           // center
       
        if( (col-1) >= 0 && rowVector[col-1] < min) // left
        {
            min = rowVector[col-1];
        }

        if( (col+ 1) < n && rowVector[col+1] < min) // right
        {
            min = rowVector[col+1];
        }

        return min;
    }
};


void test(std::vector<std::vector<int>> &matrix, int expected)
{
        Solution s;
        int minFallingPath = s.minFallingPathSum(matrix);
        std::cout << "min falling path: " << minFallingPath << "\n";
        assert(minFallingPath == expected);
}

void runTests(void)
{
    #if 0
    {
        // Example 1
        std::vector<std::vector<int>> matrix {{2,1,3},{6,5,4},{7,8,9}};
        test(matrix, 13);
    }

    {
        // Example 2
        std::vector<std::vector<int>> matrix {{-19, 57},{-40, -5}};
        test(matrix, -59);
    }

    #endif

    {
        // Testcase 21
        std::vector<std::vector<int>> matrix {{100,-42,-46,-41},{31,97,10,-10},{-58,-51,82,89},{51,81,69,-51}};
        test(matrix, -36);
    }
}


int main(void)
{
    runTests();
    return 0;
}