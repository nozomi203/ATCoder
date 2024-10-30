#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <limits>
#include <cmath>

using namespace std;

constexpr uint32_t kAlphabetSize = 26;

struct TreeNode
{
    TreeNode()
    {
        childNodes.fill(-1);
    }
    array<int32_t, kAlphabetSize> childNodes; // 子ノードへのインデックス
    uint32_t minStrLen{1000000};
};

int main()
{
    vector<TreeNode> treeNodes(1);
    uint32_t N;
    cin >> N;
    vector<uint32_t> answers;
    for (uint32_t n = 0; n < N; ++n)
    {
        string s;
        cin >> s;

        const uint32_t strLen = s.length();
        uint32_t minCost = strLen; // 最悪、空文字列にしてしまえばコストはs.length()

        uint32_t currNodeIdx = 0;
        for (uint32_t strIdx = 0; strIdx < s.length(); ++strIdx)
        {
            auto c = s[strIdx];
            const uint32_t idx = c - 'a'; // アルファベットをaを先頭としたときのインデックスに変換
            if (treeNodes[currNodeIdx].childNodes[idx] == -1)
            {
                treeNodes[currNodeIdx].childNodes[idx] = treeNodes.size();
                treeNodes.emplace_back();
            }
            currNodeIdx = treeNodes[currNodeIdx].childNodes[idx];
            const uint32_t costToReplace = (strLen - strIdx - 1) + (treeNodes[currNodeIdx].minStrLen - strIdx - 1);
            minCost = min(minCost, costToReplace);
            treeNodes[currNodeIdx].minStrLen = min(treeNodes[currNodeIdx].minStrLen, strLen);
        }
        answers.emplace_back(minCost);
    }
    for (auto answer : answers)
    {
        cout << answer << endl;
    }
}