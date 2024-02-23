#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

class Solution {
public:
    struct wlStats
    { 
        int wins;
        int losses;

        wlStats(): wins(0), losses(0) {}
    };

    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) 
    {
        std::unordered_map<int, wlStats> umap;
        for( auto m : matches)
        {
            umap[m[0]].wins++;
            umap[m[1]].losses++;
        }

        #if 0
        std::cout << "Mapped Data\n";
        for( auto u : umap)
        {
            std::cout << "player " << u.first << ", wins: " << u.second.wins 
                << ", losses: " << u.second.losses << "\n";
        }
        #endif

        // create vector of players with 0 losses
        std::vector<int> zeroLoss;
        std::vector<int> oneLoss;
        for(const auto& u : umap)
        {
            if(u.second.losses == 0)
            {
                zeroLoss.push_back(u.first);
            }
            else if(u.second.losses == 1)
            {
                oneLoss.push_back(u.first);
            }
        }

        // sort player numbers into ascending order
        std::sort(zeroLoss.begin(), zeroLoss.end());
        std::sort(oneLoss.begin(), oneLoss.end());

        // create
        std::vector<std::vector<int>> result(2);
        result[0] = zeroLoss;
        result[1] = oneLoss;

        return result;
    }
};


void printResult(const std::vector<std::vector<int>> &v)
{
    std::cout << "\nPrint result\n";
    for(auto r : v)
    {
        for(auto x : r)
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

void test(std::vector<std::vector<int>> &matches, const std::vector<std::vector<int>> &expected)
{
    Solution s;
    std::vector<std::vector<int>> result;
    result = s.findWinners(matches);

    std::cerr << "result.size() " << result.size() << ", expected.size() " << expected.size() << "\n";
    assert(result.size() == expected.size());

    printResult(result);

    auto r = result.begin();
    auto e = expected.begin();
    for(; r < result.end() && e < expected.end(); ++r, ++e)
    {
        auto rr = r->begin();
        auto ee = e->begin();
        for(; rr < r->end() && ee < e->end(); ++rr, ++ee)
        {
            assert(*rr == *ee);
        }
    }
}

void runTests(void)
{
    {
        /*  Example 1:

            Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
            Output: [[1,2,10],[4,5,7,8]]

            Explanation:
            Players 1, 2, and 10 have not lost any matches.
            Players 4, 5, 7, and 8 each have lost one match.
            Players 3, 6, and 9 each have lost two matches.
            Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].   
        */
        std::vector<std::vector<int>> matches {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
        std::vector<std::vector<int>> expectedOutput {{1,2,10}, {4,5,7,8}};
        test(matches, expectedOutput);
    }

    {
        /*  Example 2:

            Input: matches = [[2,3],[1,3],[5,4],[6,4]]
            Output: [[1,2,5,6],[]]

            Explanation:
            Players 1, 2, 5, and 6 have not lost any matches.
            Players 3 and 4 each have lost two matches.
            Thus, answer[0] = [1,2,5,6] and answer[1] = []. 
        */
        std::vector<std::vector<int>> matches {{2,3},{1,3},{5,4},{6,4}};
        std::vector<std::vector<int>> expectedOutput {{1,2,5,6}, {}};
        test(matches, expectedOutput);
    }
}

int main(void)
{
    runTests();
    return 0;
}