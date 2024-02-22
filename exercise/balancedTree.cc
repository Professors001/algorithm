#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

Node* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    Node* root = new Node(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

void preOrderTraversal(Node* root) {
    if (root) {
        cout << root->val << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    int size;
    cin >> size;
    vector<int> vec;

    for(int i = 0; i < size; i++) {
        int value;
        cin >> value;
        vec.push_back(value);
    }

    Node* root = sortedArrayToBST(vec, 0, vec.size() - 1);

    preOrderTraversal(root);

    return 0;
}
