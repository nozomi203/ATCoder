#include "util/common.h"

int main() {
  s64 n, k;
  string s;
  cin >> n >> k >> s;
  map<string, s64> nums;
  for (s64 i = 0; i < n - k + 1; ++i) {
    const string s2 = s.substr(i, k);
    ++nums[s2];
  }

  vector<pair<s64, string>> nss;
  for (auto& [s, num] : nums) nss.push_back(make_pair(num, s));
  sort(nss.begin(), nss.end());
  const s64 nmax = nss.back().first;
  s64 i = nss.size();
  while (i > 0 && nss[i - 1].first == nmax) --i;
  cout << nmax << endl;
  for (; i < nss.size(); ++i) {
    auto& [n, s] = nss[i];
    cout << s;
    if (i < nss.size() - 1) cout << " ";
  }
  cout << endl;
}