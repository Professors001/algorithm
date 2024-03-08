#include <iostream>
#include <vector>

using namespace std;

void backtrack(int idx, int cur_weight, vector<bool> &chosen, const vector<int> &weight, const vector<int> &value, double &total_value, int &total_count, int w) {
  if (idx == weight.size()) {
    double sum = 0;
    for (int i = 0; i < weight.size(); i++) {
      if (chosen[i]) {
        sum += value[i];
      }
    }
    total_value += sum;
    total_count++;
    return;
  }

  if (cur_weight + weight[idx] <= w) {
    chosen[idx] = true;
    backtrack(idx + 1, cur_weight + weight[idx], chosen, weight, value, total_value, total_count, w);
    chosen[idx] = false;
  }

  backtrack(idx + 1, cur_weight, chosen, weight, value, total_value, total_count, w);
}

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> weight(n);
  vector<int> value(n);
  vector<bool> chosen(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> value[i];
  }

  double total_value = 0;
  int total_count = 0;
  backtrack(0, 0, chosen, weight, value, total_value, total_count, w);

  double avg_value = total_value / total_count;

  cout.precision(2);
  cout << fixed << avg_value << endl;
}
