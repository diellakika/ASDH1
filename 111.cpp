#include <iostream>
#include <string>
#include<vector>
#include <queue>
#include <stack>

using namespace std;
class MyStack {
public:
    MyStack() {

    }
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
private:
    queue<int>q1, q2;
};
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if (s2.empty()) {
            transferStack1ToStack2();
        }
        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }
    int peek() {
        if (s2.empty()) {
            transferStack1ToStack2();
        }
        return s2.top();
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int>s1, s2;
    void transferStack1ToStack2() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
#include <vector>
#include <algorithm>

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        std::vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};
class Solution3 {
public:
    int findCenter(vector<vector<int>>& edges) {

        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];
        if (a == c || a == d) {
            return a;
        }
        else {
            return b;
        }
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution4 {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
class Solution5 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        ListNode* p1 = firstHalf;
        ListNode* p2 = secondHalf;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        reverseList(secondHalf);

        return result;
    }

private:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
class Solution6 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }


        return slow;
    }
};
class Solution7 {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != nullptr) {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};
class Solution8 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        ListNode* currA = headA;
        ListNode* currB = headB;

        int diff = abs(lenA - lenB);
        if (lenA > lenB) {
            while (diff--) currA = currA->next;
        }
        else {
            while (diff--) currB = currB->next;
        }
        while (currA != nullptr && currB != nullptr && currA != currB) {
            currA = currA->next;
            currB = currB->next;
        }

        return currA;
    }

private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }
};
class Solution9 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution10 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        else if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
class Solution11 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if (!leftSubtree && !rightSubtree)
            return true;
        if (!leftSubtree || !rightSubtree)
            return false;

        return (leftSubtree->val == rightSubtree->val) &&
            isMirror(leftSubtree->left, rightSubtree->right) &&
            isMirror(leftSubtree->right, rightSubtree->left);
    }
};
class Solution12 {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};
class Solution13 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }

    int calculateDiameter(TreeNode* root, int& diameter) {
        if (!root)
            return 0;

        int leftDepth = calculateDiameter(root->left, diameter);
        int rightDepth = calculateDiameter(root->right, diameter);

        diameter = max(diameter, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }
};
class MyHashSet {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    const int size = 10000;

    std::vector<Node*> hashTable;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashSet() : hashTable(size, nullptr) {}


    void add(int key) {
        int index = hash(key);
        Node* curr = hashTable[index];
        while (curr) {
            if (curr->val == key)
                return;
            curr = curr->next;
        }

        Node* newNode = new Node(key);
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }


    void remove(int key) {
        int index = hash(key);
        Node* curr = hashTable[index];
        Node* prev = nullptr;
        while (curr) {
            if (curr->val == key) {
                if (prev)
                    prev->next = curr->next;
                else
                    hashTable[index] = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }


    bool contains(int key) {
        int index = hash(key);
        Node* curr = hashTable[index];
        while (curr) {
            if (curr->val == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    ~MyHashSet() {
        for (auto& list : hashTable) {
            while (list) {
                Node* temp = list;
                list = list->next;
                delete temp;
            }
        }
    }
};
class MyHashMap {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    const int size = 10000;
    std::vector<Node*> hashTable;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashMap() : hashTable(size, nullptr) {}

    void put(int key, int value) {
        int index = hash(key);
        Node* curr = hashTable[index];
        while (curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    int get(int key) {
        int index = hash(key);
        Node* curr = hashTable[index];
        while (curr) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        Node* curr = hashTable[index];
        Node* prev = nullptr;
        while (curr) {
            if (curr->key == key) {
                if (prev)
                    prev->next = curr->next;
                else
                    hashTable[index] = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    ~MyHashMap() {
        for (auto& list : hashTable) {
            while (list) {
                Node* temp = list;
                list = list->next;
                delete temp;
            }
        }
    }
};
class Solution14 {
public:
    bool hasTrailingZeros(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((nums[i] | nums[j]) % 2 == 0)
                    return true;
            }
        }
        return false;
    }
};
class Solution16 {
public:
    bool digitCount(std::string num) {
        std::vector<int> count(10, 0);
        int n = num.length();

        for (int i = 0; i < n; ++i) {
            int digit = num[i] - '0';
            count[digit]++;
        }

        for (int i = 0; i < n; ++i) {
            int digit = num[i] - '0';
            if (count[i] != digit)
                return false;
        }

        return true;
    }
};





int main() {
    int choice;
    cout << "Enter the number of the function you want to execute (1-19): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        MyStack myStack;
        myStack.push(1);
        myStack.push(2);
        cout << "Top element after push: " << myStack.top() << endl;
        cout << "Pop: " << myStack.pop() << endl;
        cout << "Empty: " << (myStack.empty() ? "true" : "false") << endl;
        break;
    }
    case 2: {
        MyQueue myQueue;
        myQueue.push(1);
        myQueue.push(2);
        cout << "Pop: " << myQueue.pop() << endl;
        cout << "Peek: " << myQueue.peek() << endl;
        cout << "Empty: " << (myQueue.empty() ? "true" : "false") << endl;
        break;
    }
    case 3: {
        Solution solution;
        int n;
        cout << "Enter the number of stairs: ";
        cin >> n;
        cout << "Number of ways to climb stairs: " << solution.climbStairs(n) << endl;
        break;
    }
    case 4: {
        vector<int> cost = { 10, 15, 20 };
        Solution2 solution2;
        cout << "Minimum cost to climb stairs: " << solution2.minCostClimbingStairs(cost) << endl;
        break;
    }
    case 5: {
        vector<vector<int>> edges = { {1, 2}, {2, 3}, {4, 2} };
        Solution3 solution3;
        cout << "Center of the graph: " << solution3.findCenter(edges) << endl;
        break;
    }
    case 6: {
        ListNode* head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = head->next;
        Solution4 solution4;
        cout << "Has cycle: " << (solution4.hasCycle(head) ? "true" : "false") << endl;
        break;
    }
    case 7: {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);
        Solution5 solution5;
        cout << "Is palindrome: " << (solution5.isPalindrome(head) ? "true" : "false") << endl;
        break;
    }
    case 8: {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        Solution6 solution6;
        ListNode* middle = solution6.middleNode(head);
        cout << "Middle node value: " << middle->val << endl;
        break;
    }
    case 9: {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(0);
        head->next->next = new ListNode(1);
        Solution7 solution7;
        cout << "Decimal value: " << solution7.getDecimalValue(head) << endl;
        break;
    }
    case 10: {
        ListNode* headA = new ListNode(4);
        headA->next = new ListNode(1);
        headA->next->next = new ListNode(8);
        headA->next->next->next = new ListNode(4);
        headA->next->next->next->next = new ListNode(5);

        ListNode* headB = new ListNode(5);
        headB->next = new ListNode(0);
        headB->next->next = new ListNode(1);
        headB->next->next->next = headA->next->next;

        Solution8 solution8;
        ListNode* intersection = solution8.getIntersectionNode(headA, headB);
        cout << "Intersection node value: " << intersection->val << endl;
        break;
    }
    case 11: {
        vector<int> nums = { 1, 3, 5, 6 };
        int target;
        cout << "Enter the target number: ";
        cin >> target;
        Solution9 solution9;
        cout << "Index to insert: " << solution9.searchInsert(nums, target) << endl;
        break;
    }
    case 12: {
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode* q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);

        Solution10 solution10;
        cout << "Is same tree: " << (solution10.isSameTree(p, q) ? "true" : "false") << endl;
        break;
    }
    case 13: {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(3);

        Solution11 solution11;
        cout << "Is symmetric tree: " << (solution11.isSymmetric(root) ? "true" : "false") << endl;
        break;
    }
    case 14: {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        Solution12 solution12;
        cout << "Max depth of binary tree: " << solution12.maxDepth(root) << endl;
        break;
    }
    case 15: {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        Solution13 solution13;
        cout << "Diameter of binary tree: " << solution13.diameterOfBinaryTree(root) << endl;
        break;
    }
    case 16: {
        MyHashSet hashSet;
        hashSet.add(1);
        hashSet.add(2);
        cout << "HashSet contains 1: " << (hashSet.contains(1) ? "true" : "false") << endl;
        break;
    }

    case 17: {
        MyHashMap hashMap;
        hashMap.put(1, 1);
        hashMap.put(2, 2);
        cout << "HashMap get value for key 1: " << hashMap.get(1) << endl;
        cout << "HashMap get value for key 3: " << hashMap.get(3) << endl;
        hashMap.remove(2);
        cout << "HashMap get value for key 2: " << hashMap.get(2) << endl;
        break;
    }

    case 18: {
        Solution14 solution14;
        vector<int> nums = { 1, 2, 3 };
        cout << "Has trailing zeros: " << (solution14.hasTrailingZeros(nums) ? "true" : "false") << endl;
        break;
    }
    case 19: {
        Solution16 solution16;
        string num;
        cout << "Enter a number string: ";
        cin >> num;
        cout << "Digit count match: " << (solution16.digitCount(num) ? "true" : "false") << endl;
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}
/*MyStack using Queues:
Push:
Time Complexity :
𝑂(𝑛)
O(n) - because elements from q1 are moved to q2.
Space Complexity :
𝑂(𝑛)
O(n) - because of the two queues used.
Pop :
    Time Complexity :
𝑂(1)
O(1).
Space Complexity :
𝑂(1)

Top :
    Time Complexity :
𝑂(1)

Space Complexity :
O(1).
Empty :
    Time Complexity :
O(1).
Space Complexity :
O(1).
MyQueue using Stacks :

    Push :
    Time Complexity :
O(1).
Space Complexity :
O(n) - because of the two stacks used.
Pop :
    Time Complexity : Amortized
    O(1) - as each element is moved once.
    Space Complexity :
O(1).
Peek :
    Time Complexity : Amortized
    O(1).
    Space Complexity :
O(1).
Empty :
    Time Complexity :
O(1).
Space Complexity :
O(1).
Climb Stairs :

Time Complexity :
O(n) - due to the loop.
Space Complexity :
O(n) - because of the dp array.
Min Cost Climbing Stairs :

Time Complexity :
O(n) - due to the loop.
Space Complexity :
O(n) - because of the dp array.
Find Center of Star Graph :

Time Complexity :
O(1).
Space Complexity :
O(1).
Detect Cycle in Linked List :

Time Complexity :
O(n) - where
𝑛
n is the number of nodes in the list.
Space Complexity :
O(1) - because it uses two pointers.
Check Palindrome Linked List :

Time Complexity :
O(n) - for traversing and reversing the list.
Space Complexity :
O(1) - because it uses pointers.
Find Middle of Linked List :

Time Complexity :
O(n) - single pass through the list.
Space Complexity :
O(1).
Binary Number to Integer in Linked List :

Time Complexity :
O(n) - single pass through the list.
Space Complexity :
O(1).
Intersection of Two Linked Lists :

Time Complexity :
O(n + m) - where
𝑛
n and
𝑚
m are the lengths of the two lists.
Space Complexity :
O(1).
Search Insert Position in Sorted Array :

Time Complexity :
O(logn) - binary search.
Space Complexity :
O(1).
Check if Two Trees are Same :

Time Complexity :

O(n) - where
𝑛
n is the number of nodes in the trees.
Space Complexity :

O(h) - where
ℎ
h is the height of the trees(due to recursion stack).
Check if Tree is Symmetric :

Time Complexity :

O(n) - where
𝑛
n is the number of nodes.
Space Complexity :

O(h) - where
ℎ
h is the height of the tree(due to recursion stack).
Max Depth of Binary Tree :

Time Complexity :

O(n) - where
𝑛
n is the number of nodes.
Space Complexity :

O(h) - where
ℎ
h is the height of the tree(due to recursion stack).
Diameter of Binary Tree :

Time Complexity :

O(n) - where
𝑛
n is the number of nodes.
Space Complexity :

O(h) - where
ℎ
h is the height of the tree(due to recursion stack).
MyHashSet :

    Add :
    Time Complexity :

O(1) - average case, assuming good hash function.
Space Complexity :

O(n) - where
𝑛
n is the number of elements.
Remove :
    Time Complexity :

O(1) - average case.
Space Complexity :

O(1).
Contains :
    Time Complexity :

O(1) - average case.
Space Complexity :

O(1).
MyHashMap :

    Put :
    Time Complexity :

O(1) - average case, assuming good hash function.
Space Complexity :

O(n) - where
𝑛
n is the number of elements.
Get :
    Time Complexity :

O(1) - average case.
Space Complexity :

O(1).
Remove :
    Time Complexity :

O(1) - average case.
Space Complexity :

O(1).
Has Trailing Zeros :

Time Complexity :

O(n2) - due to the nested loops.
Space Complexity :

O(1).
Digit Count Match :

Time Complexity :

O(n) - where
𝑛
n is the length of the string.
Space Complexity :
O(1) - as the count array has a fixed size of 10.*/