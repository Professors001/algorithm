#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> longest_increasing_subsequence(const vector<int>& nums) {
  vector<int> dp(nums.size(), 1);

  vector<int> parent(nums.size(), -1);

  for (int i = 1; i < nums.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        parent[i] = j;
      }
    }
  }

  int max_index = max_element(dp.begin(), dp.end()) - dp.begin();

  vector<int> lis;
  int i = max_index;
  while (i >= 0) {
    lis.push_back(nums[i]);
    i = parent[i];
  }

  reverse(lis.begin(), lis.end());

  return lis;
}

int main() {
  vector<int> nums = {2,5,1,0,7,3,4,6,99,10,8};
  vector<int> lis = longest_increasing_subsequence(nums);
  
  cout << "LIS: ";
  for (int num : lis) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}