#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    int K, N;
    vector<int> A;

    cin >> K >> N;
    A.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int maxDist = A[0] + K - A[N - 1];
    for (int i = 1; i < N; i++)
    {
        maxDist = max(maxDist, A[i] - A[i - 1]);
    }

    cout << K - maxDist << endl;
}