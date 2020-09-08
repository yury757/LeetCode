#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;

enum State {
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END,
};

enum CharType {
    CHAR_NUMBER,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_SPACE,
    CHAR_ILLEGAL,
};

int main()
{
    void printVector(vector<int> v);
    void printVector(vector<string> v);
    void printTwoVector(vector<vector<int>> v);
    void printTwoVector(vector<vector<char>> v);
    void printTwoVector(vector<vector<string>> v);

    int countSubstrings(string s);

    vector<int> twoSum(vector<int> & nums, int target);

    void bfs(vector<vector<char>> & board, int sx, int sy);
    void dfs(vector<vector<char>> & board, vector<int> & click);
    vector<vector<char>> updateBoard(vector<vector<char>> & board, vector<int> & click);
    //vector<vector<char>> board = { {'E', 'E', 'E', 'E', 'E' },
    //                               {'E', 'E', 'M', 'E', 'E' },
    //                               {'E', 'E', 'E', 'E', 'E' },
    //                               {'E', 'E', 'E', 'E', 'E' } };
    //vector<int> click = { 3, 0 };
    //vector<vector<char>> s = updateBoard(board, click);
    //printTwoVector(board);

    struct TreeNode;
    void loopFindMode(TreeNode * root, TreeNode * &pre, int& max_mode, int& cur_mode, vector<int> & ModeVector);
    vector<int> findMode(TreeNode * root);

    int rangeBitwiseAnd(int m, int n);
    //cout << rangeBitwiseAnd(2147483647, 2147483647);
    //cout << rangeBitwiseAnd(3, 3);

    bool repeatedSubstringPattern(string s);
    //cout << repeatedSubstringPattern("ababa");


    void findSubsequences_dfs(int cur, int last, vector<int> & nums);
    vector<vector<int>> findSubsequences(vector<int> & nums);
    //vector<int> a = { 4, 6, 7, 7 };
    //printTwoVector(findSubsequences(a));

    vector<string> letterCombinations(string digits);
    void dfs17(string & digits, map<char, string> & digits2letter, int i);
    //printVector(letterCombinations("29467"));

    bool solve(vector<double> & l);
    bool judgePoint24(vector<int> & nums);
    //vector<int> v769 = { 1,2,3,4 };
    //cout << judgePoint24(v769);
    int dfs332(string start, vector<vector<string>> tickets);
    void dfs332_2(const string & curr);
    vector<string> findItinerary(vector<vector<string>> & tickets);
    //vector<vector<string>> tickets332 = { {"JFK", "SFO"}, { "JFK", "ATL" }, { "SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"} };
    //printVector(findItinerary(tickets332));

    bool judgeCircle(string moves);
    //cout << judgeCircle("UD");

    string reverseWords(string s);
    //cout << reverseWords("  a");

    string shortestPalindrome(string s);
    //cout << shortestPalindrome("aacecaaa");

    int inrooms_sum(vector<int> & rooms);
    bool dfs841(int start, vector<vector<int>> & rooms, vector<int> & inrooms);
    bool canVisitAllRooms(vector<vector<int>> & rooms);
    //vector<vector<int>> rooms = { {2, 3}, { }, { 2 }, {1, 3, 1} };
    //cout << canVisitAllRooms(rooms);

    bool dfs486(vector<int> nums, char person, int& a, int& b);
    bool PredictTheWinner(vector<int> & nums);
    //vector<int> nums486 = { 1, 5, 233, 7 };
    //cout << PredictTheWinner(nums486);

    CharType toCharType(char ch);
    bool isNumber(string s);
    //cout << isNumber("  3453.66E4");

    bool dfs51(vector<string> & queens, int& pos_x, int& pos_y, vector<int> & x, vector<int> & y, vector<int> & p, vector<int> & q, int last_y, int n);
    //vector<vector<string>> solveNQueens(int n);
    //printTwoVector(solveNQueens(5));

    void dfs257(TreeNode * root, string & string_temp257, vector<string> & res257);
    vector<string> binaryTreePaths(TreeNode * root);

    string int2str(int a);
    //cout << int2str(-234);

    int factorial(int n);
    void dfs60(vector<int> & nums, int& n, int& k, int& i, string & res60);
    //string getPermutation(int n, int k);
    //cout << getPermutation(8, 234);

    vector<int> topKFrequent(vector<int> & nums, int k);
    vector<int> v347 = { 1,1,1,2,2,3 };
    //vector<int> res347_temp = topKFrequent(v347, 2);
    //printVector(res347_temp);

    void dfs77(int start, int n, int k);
    vector<vector<int>> combine(int n, int k);
    printTwoVector(combine(4, 2));
}

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
}

void printVector(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
}

void printTwoVector(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << "\n";
    }
}

void printTwoVector(vector<vector<char>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << "\n";
    }
}

void printTwoVector(vector<vector<string>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << "\n";
    }
}

// 647.回文字符串
// 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
int countSubstrings(string s)
{
    int count = 0;
    int n = s.size();
    for (int i = 0; i < 2 * n - 1; i++) {
        int l = i / 2;
        int r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }
    return count;
}

// 1.两数之和
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return vector<int>{i, j};
            }
        }
    }
    throw new exception();
}

//529.扫雷游戏
//给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
//现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
//如果一个地雷（'M'）被挖出，游戏就结束了 - 把它改为 'X'。
//如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
//如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
//如果在此次点击中，若无更多方块可被揭露，则返回面板。

// 529.扫雷游戏 - 递归函数 - 深度优先搜索
void dfs(vector<vector<char>>& board, vector<int>& click) {
    if (board[click[0]][click[1]] != 'E') {
        return;
    }
    else {
        int c = 0;
        for (int i = max(click[0] - 1, 0); i <= min(int(board.size()) - 1, click[0] + 1); i++) {
            for (int j = max(click[1] - 1, 0); j <= min(int(board[0].size()) - 1, click[1] + 1); j++) {
                if (i == click[0] && j == click[1]) {
                    continue;
                }
                else {
                    if (board[i][j] == 'M') {
                        c++;
                    }
                }
            }
        }
        if (c == 0) {
            board[click[0]][click[1]] = 'B';
            for (int i = max(click[0] - 1, 0); i <= min(int(board.size()) - 1, click[0] + 1); i++) {
                for (int j = max(click[1] - 1, 0); j <= min(int(board[0].size()) - 1, click[1] + 1); j++) {
                    if (i == click[0] && j == click[1]) {
                        continue;
                    }
                    else {
                        vector<int> a = vector<int>{ i, j };
                        dfs(board, a);
                    }
                }
            }
        }
        else {
            board[click[0]][click[1]] = to_string(c)[0];
            return;
        }
    }
}


int dir_x[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dir_y[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

// 529.扫雷游戏 - 递归函数 - 广度优先搜索（官方代码）
void bfs(vector<vector<char>>& board, int sx, int sy) {
    queue<pair<int, int>> Q;
    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
    Q.push({ sx, sy });
    vis[sx][sy] = true;
    while (!Q.empty()) {
        auto pos = Q.front();
        Q.pop();
        int cnt = 0, x = pos.first, y = pos.second;
        for (int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                continue;
            }
            // 不用判断 M，因为如果有 M 的话游戏已经结束了
            cnt += board[tx][ty] == 'M';
        }
        if (cnt > 0) {
            // 规则 3
            board[x][y] = cnt + '0';
        }
        else {
            // 规则 2
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                // 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E' || vis[tx][ty]) {
                    continue;
                }
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = true;
            }
        }
    }
}
//作者：LeetCode - Solution
//链接：https://leetcode-cn.com/problems/minesweeper/solution/sao-lei-you-xi-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 529.扫雷游戏 - 执行函数
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';
    }
    else {
        //dfs(board, click);
        bfs(board, click[0], click[1]);
    }
    return board;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void loopFindMode(TreeNode* root, TreeNode*& pre, int& max_mode, int& cur_mode, vector<int>& ModeVector) {
    if (root == nullptr) {
        return;
    }
    loopFindMode(root->left, pre, max_mode, cur_mode, ModeVector);
    if (pre != nullptr && root->val == pre->val) {
        cur_mode++;
    }
    else {
        cur_mode = 1;
    }
    if (cur_mode > max_mode) {
        ModeVector.clear();
        ModeVector.push_back(root->val);
        max_mode = cur_mode;
    }
    else if (cur_mode == max_mode) {
        ModeVector.push_back(root->val);
    }
    pre = root;
    loopFindMode(root->right, pre, max_mode, cur_mode, ModeVector);
}

// 501. 二叉搜索树中的众数
//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
//假定 BST 有如下定义：
//结点左子树中所含结点的值小于等于当前结点的值
//结点右子树中所含结点的值大于等于当前结点的值
//左子树和右子树都是二叉搜索树
//例如：
//给定 BST[1, null, 2, 2],
vector<int> findMode(TreeNode* root) {
    vector<int> ModeVector;
    if (root == nullptr) {
        return ModeVector;
    }
    int max_mode = 0;
    int cur_mode = 1;
    int last_num;
    TreeNode* pre = nullptr;
    loopFindMode(root, pre, max_mode, cur_mode, ModeVector);
    return ModeVector;
}



// 111. 二叉树的最小深度
// 给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    //if (root->left == nullptr && root->right == nullptr) {
    //    return 1;
    //}
    if (root->left == nullptr) {
        return 1 + minDepth(root->right);
    }
    else if (root->right == nullptr) {
        return 1 + minDepth(root->left);
    }
    else {
        return min(1 + minDepth(root->left), 1 + minDepth(root->right));
    }
}

//201. 数字范围按位与
//给定范围[m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
//示例 1:
//输入: [5, 7]
//输出 : 4
//示例 2 :
//输入 : [0, 1]
//输出 : 0
int rangeBitwiseAnd(int m, int n) {
    // 朴素解法
    int bitwiseAnd = 0, i = 0;
    unsigned int p = 1;
    if (n > 0) {
        while (n >= p) {
            if (n - m < p && m % (p * 2) >= p && n % (p * 2) >= p) {
                bitwiseAnd += (int)p;
            }
            i++;
            p = (unsigned int)pow(2, i);
        }
    }
    return bitwiseAnd;

    // 官方题解
    //int shift = 0;
    //while (m < n) {
    //    m >>= 1;
    //    n >>= 1;
    //    ++shift;
    //}
    //return m << shift;
}

//459. 重复的子字符串
//给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
//示例 1:
//输入: "abab"
//输出 : True
//解释 : 可由子字符串 "ab" 重复两次构成。
//示例 2 :
//输入 : "aba"
//输出 : False
//示例 3 :
//输入 : "abcabcabcabc"
//输出 : True
//解释 : 可由子字符串 "abc" 重复四次构成。(或者子字符串 "abcabc" 重复两次构成。)
bool repeatedSubstringPattern(string s) {
    // 暴力算法O(nlogn) 或 O(n2)
    int i = 1, x = 1; // i表示重复字符串的长度
    for (int i = 1; i <= s.size() / 2; i++) {
        x = 1;
        if (s.size() % i != 0) {
            continue;
        }
        for (int l = i; l < s.size(); l += i) {
            if (s.substr(l - i, i) != s.substr(l, i)) {
                x = 0;
                break;
            }
        }
        if (x == 1) {
            return true;
        }
    }
    return false;

    // O(n)算法
    // TODO
}

vector<int> temp;
vector<vector<int>> ans;

void findSubsequences_dfs(int cur, int last, vector<int>& nums) {
    if (cur == nums.size()) {
        if (temp.size() >= 2) {
            ans.push_back(temp);
        }
        return;
    }
    if (nums[cur] >= last) {
        temp.push_back(nums[cur]);
        findSubsequences_dfs(cur + 1, nums[cur], nums);
        temp.pop_back();
    }
    if (nums[cur] != last) {
        findSubsequences_dfs(cur + 1, last, nums);
    }
}

//491. 递增子序列
//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
//示例 :
//输入: [4, 6, 7, 7]
//输出 : [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7, 7], [4, 7, 7]]
//说明 :
//给定数组的长度不会超过15。
//数组中的整数范围是 [-100, 100]。
//给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
vector<vector<int>> findSubsequences(vector<int>& nums) {
    findSubsequences_dfs(0, INT_MIN, nums);
    return ans;
}

string temp17 = "";
vector<string> ans17;

void dfs17(string& digits, map<char, string>& digits2letter, int i) {
    if (i >= digits.size()) {
        ans17.push_back(temp17);
        return;
    }
    for (int u = 0; u < digits2letter[digits[i]].size(); u++) {
        temp17 += digits2letter[digits[i]][u];
        dfs17(digits, digits2letter, i + 1);
        temp17.pop_back();
    }
}

//17. 电话号码的字母组合
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//2：abc，3：def，4：ghi，5：jkl，6：mno，7：pqrs，8：tuv，9：wxyz
vector<string> letterCombinations(string digits) {
    if (digits == "") {
        return {};
    }
    map<char, string> digits2letter = { {'2', "abc"} ,{'3', "def"} ,{'4', "ghi"} ,{'5', "jkl"} ,{'6', "mno"} ,{'7', "pqrs"} ,{'8', "tuv"} ,{'9', "wxyz"} };
    dfs17(digits, digits2letter, 0);
    return ans17;
}

static constexpr int TARGET = 24;
static constexpr double EPSILON = 1e-6;
static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

bool solve(vector<double>& l) {
    if (l.size() == 0) {
        return false;
    }
    if (l.size() == 1) {
        return fabs(l[0] - TARGET) < EPSILON;
    }
    int size = l.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                vector<double> list2 = vector<double>();
                for (int k = 0; k < size; k++) {
                    if (k != i && k != j) {
                        list2.emplace_back(l[k]);
                    }
                }
                for (int k = 0; k < 4; k++) {
                    if (k < 2 && i > j) {
                        continue;
                    }
                    if (k == ADD) {
                        list2.emplace_back(l[i] + l[j]);
                    }
                    else if (k == MULTIPLY) {
                        list2.emplace_back(l[i] * l[j]);
                    }
                    else if (k == SUBTRACT) {
                        list2.emplace_back(l[i] - l[j]);
                    }
                    else if (k == DIVIDE) {
                        if (fabs(l[j]) < EPSILON) {
                            continue;
                        }
                        list2.emplace_back(l[i] / l[j]);
                    }
                    if (solve(list2)) {
                        return true;
                    }
                    list2.pop_back();
                }
            }
        }
    }
    return false;
}

//679. 24 点游戏
//你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 * ， / ， + ， - ，(，) 的运算得到 24。
//注意:
//除法运算符  / 表示实数除法，而不是整数除法。例如 4 / (1 - 2 / 3) = 12 。
//每个运算符对两个数进行运算。特别是我们不能用  - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式  - 1 - 1 - 1 - 1 是不允许的。
//你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
bool judgePoint24(vector<int>& nums) {
    vector<double> l;
    for (const int& num : nums) {
        l.emplace_back(static_cast<double>(num));
    }
    return solve(l);
}

vector<string> ans332;
string max_str = "ZZZZZZZZZZZZZZ";

int dfs332(string start, vector<vector<string>> tickets) {
    if (tickets.size() == 0) return 1;
    vector<int> index332 = vector<int>();
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start) {
            index332.push_back(i);
        }
    }
    if (index332.size() == 0) return 0;
    while (true) {
        int sorted_num = 0, temp332 = 0;
        for (int u = 1; u < index332.size(); u++) {
            if (tickets[index332[u]][1] < tickets[index332[u - 1]][1]) {
                temp332 = index332[u - 1];
                index332[u - 1] = index332[u];
                index332[u] = temp332;
                sorted_num = 1;
            }
        }
        if (sorted_num == 0) {
            break;
        }
    }
    string next = max_str;
    for (int u : index332) {
        vector<vector<string>> temp332 = vector<vector<string>>();
        for (int i = 0; i < tickets.size(); i++) {
            if (i != u) {
                temp332.push_back(tickets[i]);
            }
        }
        if (dfs332(tickets[u][1], temp332) == 1) {
            next = min(next, tickets[u][1]);
        }
    }
    if (next != max_str) {
        ans332.push_back(next);
        return 1;
    }
    else {
        return 0;
    }
}

vector<string> reverse(vector<string> v) {
    vector<string> vr = vector<string>();
    for (int i = v.size() - 1; i >= 0; i--) {
        vr.push_back(v[i]);
    }
    return vr;
}

unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
vector<string> stk;

void dfs332_2(const string& curr) {
    while (vec.count(curr) && vec[curr].size() > 0) {
        string tmp = vec[curr].top();
        vec[curr].pop();
        dfs332_2(move(tmp));
    }
    stk.emplace_back(curr);
}

//332. 重新安排行程
//给定一个机票的字符串二维数组[from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
//说明 :
//如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程["JFK", "LGA"] 与["JFK", "LGB"] 相比就更小，排序更靠前
//所有的机场都用三个大写字母表示（机场代码）。
//假定所有机票至少存在一种合理的行程。
//示例 1 :
//输入 : [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//输出 : ["JFK", "MUC", "LHR", "SFO", "SJC"]
//示例 2 :
//输入 : [["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]
//输出 : ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]
//解释 : 另一种有效的行程是 ["JFK", "SFO", "ATL", "JFK", "ATL", "SFO"]。但是它自然排序更大更靠后。
vector<string> findItinerary(vector<vector<string>>& tickets) {
    //dfs332("JFK", tickets);
    //ans332.push_back("JFK");
    //return reverse(ans332);

    // 官方解法
    for (auto& it : tickets) {
        vec[it[0]].emplace(it[1]);
    }
    dfs332_2("JFK");

    reverse(stk.begin(), stk.end());
    return stk;
}

//657. 机器人能否返回原点
//在二维平面上，有一个机器人从原点(0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在(0, 0) 处结束。
//移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
//注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。
//示例 1:
//输入: "UD"
//输出 : true
//解释：机器人向上移动一次，然后向下移动一次。所有动作都具有相同的幅度，因此它最终回到它开始的原点。因此，我们返回 true。
//示例 2 :
//输入 : "LL"
//输出 : false
//解释：机器人向左移动两次。它最终位于原点的左侧，距原点有两次 “移动” 的距离。我们返回 false，因为它在移动结束时没有返回原点。
bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char m : moves) {
        switch (m) {
        case 'U': y++; break;
        case 'D': y--; break;
        case 'R': x++; break;
        case 'L': x--; break;
        }
    }
    return x == 0 && y == 0;
}


//557. 反转字符串中的单词 III
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//示例：
//输入："Let's take LeetCode contest"
//输出："s'teL ekat edoCteeL tsetnoc"
//提示：
//在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
string reverseWords(string s) {
    stack<int> temp557;
    string res;
    for (char ss : s) {
        if (ss != ' ') {
            temp557.push(ss);
        }
        else {
            while (!temp557.empty()) {
                res.push_back(temp557.top());
                temp557.pop();
            }
            res.push_back(' ');
        }
    }
    while (!temp557.empty()) {
        res.push_back(temp557.top());
        temp557.pop();
    }
    return res;
}

//214. 最短回文串
//给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
//示例 1:
//输入: "aacecaaa"
//输出 : "aaacecaaa"
//示例 2 :
//输入 : "abcd"
//输出 : "dcbabcd"
string shortestPalindrome(string s) {
    // 官方代码，KMP
    int n = s.size();
    vector<int> fail(n, -1);
    for (int i = 1; i < n; ++i) {
        int j = fail[i - 1];
        while (j != -1 && s[j + 1] != s[i]) {
            j = fail[j];
        }
        if (s[j + 1] == s[i]) {
            fail[i] = j + 1;
        }
    }
    int best = -1;
    for (int i = n - 1; i >= 0; --i) {
        while (best != -1 && s[best + 1] != s[i]) {
            best = fail[best];
        }
        if (s[best + 1] == s[i]) {
            ++best;
        }
    }
    string add = (best == n - 1 ? "" : s.substr(best + 1, n));
    reverse(add.begin(), add.end());
    return add + s;
}

int inrooms_sum(vector<int>& rooms) {
    int inrooms_sumvalue = 0;
    for (int i : rooms) {
        inrooms_sumvalue += i;
    }
    return inrooms_sumvalue;
}

bool dfs841(int start, vector<vector<int>>& rooms, vector<int>& inrooms) {
    // 一开始理解成了每打开一扇门只能取走其中一把钥匙，可以重复进门，但是之前取走的钥匙就没了。
    // 因此算法设计成了每打开一扇门都要判断是否所有门都打开过，同时不能用计数的方式判断所有们是否打开过，因为有重复开门的情况。
    inrooms[start] = 1;
    if (inrooms_sum(inrooms) == rooms.size()) {
        return 1;
    }
    if (rooms[start].size() == 0) {
        return 0;
    }
    for (int i = 0; i < rooms[start].size(); i++) {
        if (inrooms[rooms[start][i]] != 0) {
            continue;
        }
        if (dfs841(rooms[start][i], rooms, inrooms)) {
            return 1;
        }
    }
    return 0;
}

//841. 钥匙和房间
//有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N - 1，并且房间里可能有一些钥匙能使你进入下一个房间。
//在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由[0, 1，...，N - 1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
//最初，除 0 号房间外的其余所有房间都被锁住。
//你可以自由地在房间之间来回走动。
//如果能进入每个房间返回 true，否则返回 false。
//示例 1：
//输入 : [[1], [2], [3], []]
//输出 : true
//解释 :
//    我们从 0 号房间开始，拿到钥匙 1。
//    之后我们去 1 号房间，拿到钥匙 2。
//    然后我们去 2 号房间，拿到钥匙 3。
//    最后我们去了 3 号房间。
//    由于我们能够进入每个房间，我们返回 true。
//    示例 2：
//
//    输入： [[1, 3], [3, 0, 1], [2], [0]]
//    输出：false
//    解释：我们不能进入 2 号房间。
//    提示：
//    1 <= rooms.length <= 1000
//    0 <= rooms[i].length <= 1000
//    所有房间中的钥匙数量总计不超过 3000。
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<int> inrooms = vector<int>(rooms.size(), 0);
    return dfs841(0, rooms, inrooms);
}

bool room_empty(vector<int> room) {
    for (int i : room) {
        if (i != -1) {
            return 0;
        }
    }
    return 1;
}

//841-2
//若将上题的题目逻辑改成：每次打开一扇门只能取走其中一把钥匙，下次再进入这扇门时原来的钥匙不见了，则相应的深度优先搜索算法如下
bool dfs841_2(int start, vector<vector<int>>& rooms, vector<int>& inrooms) {
    inrooms[start] = 1;
    if (inrooms_sum(inrooms) == rooms.size()) {
        return 1;
    }
    if (room_empty(rooms[start])) {
        return 0;
    }
    for (int i = 0; i < rooms[start].size(); i++) {
        if (rooms[start][i] == -1) {
            continue;
        }
        int start_temp = rooms[start][i];
        rooms[start][i] = -1;
        if (dfs841(start_temp, rooms, inrooms)) {
            return 1;
        }
        rooms[start][i] = start_temp;
    }
    return 0;
}

bool dfs486(vector<int> nums, char person, int& a, int& b) {
    // 执行用时：724 ms , 在所有 C++ 提交中击败了 5.45 % 的用户
    // 内存消耗：204.6 MB , 在所有 C++ 提交中击败了 5.08 % 的用户
    // 请参考官方算法
    if (nums.size() == 0) {
        return a >= b ? 1 : 0;
    }
    int get_num;
    get_num = nums[0];
    vector<int> temp486;
    for (int i = 1; i < nums.size(); i++) {
        temp486.push_back(nums[i]);
    }
    if (person == 'a') {
        a += get_num;
        if (dfs486(temp486, 'b', a, b) == 1) {
            a -= get_num;
            return 1;
        }
        a -= get_num;
    }
    else {
        b += get_num;
        if (dfs486(temp486, 'a', a, b) == 0) {
            b -= get_num;
            return 0;
        }
        b -= get_num;
    }
    get_num = nums[nums.size() - 1];
    nums.pop_back();
    if (person == 'a') {
        a += get_num;
        if (dfs486(nums, 'b', a, b) == 1) {
            a -= get_num;
            return 1;
        }
        a -= get_num;
        return 0;
    }
    else {
        b += get_num;
        if (dfs486(nums, 'a', a, b) == 0) {
            b -= get_num;
            return 0;
        }
        b -= get_num;
        return 1;
    }
}

//486. 预测赢家
//给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
//给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
//示例 1：
//输入：[1, 5, 2]
//输出：False
//解释：一开始，玩家1可以从1和2中进行选择。
//如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。
//所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
//因此，玩家 1 永远不会成为赢家，返回 False 。
//示例 2：
//输入：[1, 5, 233, 7]
//输出：True
//解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
//最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
//提示：
//1 <= 给定的数组长度 <= 20.
//数组里所有分数都为非负数且不会大于 10000000 。
//如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。
bool PredictTheWinner(vector<int>& nums) {
    int a = 0, b = 0;
    return dfs486(nums, 'a', a, b);
}

CharType toCharType(char ch) {
    if (ch >= '0' && ch <= '9') {
        return CHAR_NUMBER;
    }
    else if (ch == 'e' || ch == 'E') {
        return CHAR_EXP;
    }
    else if (ch == '.') {
        return CHAR_POINT;
    }
    else if (ch == '+' || ch == '-') {
        return CHAR_SIGN;
    }
    else if (ch == ' ') {
        return CHAR_SPACE;
    }
    else {
        return CHAR_ILLEGAL;
    }
}

//剑指 Offer 20. 表示数值的字符串
//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
//和我的思路一样，只是不知道这种思想名字原来叫有限状态自动机
bool isNumber(string s) {
    unordered_map<State, unordered_map<CharType, State>> transfer{
        {
            STATE_INITIAL, {
                {CHAR_SPACE, STATE_INITIAL},
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                {CHAR_SIGN, STATE_INT_SIGN},
            }
        }, {
            STATE_INT_SIGN, {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
            }
        }, {
            STATE_INTEGER, {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_EXP, STATE_EXP},
                {CHAR_POINT, STATE_POINT},
                {CHAR_SPACE, STATE_END},
            }
        }, {
            STATE_POINT, {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP},
                {CHAR_SPACE, STATE_END},
            }
        }, {
            STATE_POINT_WITHOUT_INT, {
                {CHAR_NUMBER, STATE_FRACTION},
            }
        }, {
            STATE_FRACTION,
            {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP},
                {CHAR_SPACE, STATE_END},
            }
        }, {
            STATE_EXP,
            {
                {CHAR_NUMBER, STATE_EXP_NUMBER},
                {CHAR_SIGN, STATE_EXP_SIGN},
            }
        }, {
            STATE_EXP_SIGN, {
                {CHAR_NUMBER, STATE_EXP_NUMBER},
            }
        }, {
            STATE_EXP_NUMBER, {
                {CHAR_NUMBER, STATE_EXP_NUMBER},
                {CHAR_SPACE, STATE_END},
            }
        }, {
            STATE_END, {
                {CHAR_SPACE, STATE_END},
            }
        }
    };

    int len = s.length();
    State st = STATE_INITIAL;

    for (int i = 0; i < len; i++) {
        CharType typ = toCharType(s[i]);
        if (transfer[st].find(typ) == transfer[st].end()) {
            return false;
        }
        else {
            st = transfer[st][typ];
        }
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
}

vector<vector<string>> res51;
void dfs51(vector<string>& queens, int& pos_x, int& pos_y, vector<int>& x, vector<int>& y, vector<int>& p, vector<int>& q, int last_y, int n) {
    if (x[pos_x] > 0 || y[pos_y] > 0 || p[pos_x + pos_y] > 0 || q[pos_x - pos_y + n - 1] > 0) { // 每次进来先判断当前坐标在四个轴是否已经有皇后了
        return;
    }
    if (pos_x == n - 1) { // pos_x坐标已经到底部，且当前坐标位置在上面没有被返回，说明是一个有效位置，则在当前位置摆放一个皇后，且把当前棋盘收藏到结果集中，再把这个皇后撤掉。下面已经没有更多行，因此返回。该行的右边位置是否有效的判断由上行皇后的下一个for循环来控制，因此不用判断右边位置，直接返回。
        queens[pos_x][pos_y] = 'Q';
        res51.push_back(queens);
        queens[pos_x][pos_y] = '.';
        return;
    }
    // 若pos_x坐标还没到底部，则在当前位置摆放一个皇后，为四个轴的相应位置+1
    x[pos_x] += 1;
    y[pos_y] += 1;
    p[pos_x + pos_y] += 1;
    q[pos_x - pos_y + n - 1] += 1;
    queens[pos_x][pos_y] = 'Q';
    // 该位置在之前已经摆好了的皇后的条件下是有效的，但不一定绝对是有效的，要判断下面行是否有有效位置可以摆放皇后
    // 因此行++， 列恢复为0，前往下一行找是否有有效位置
    pos_x++;
    pos_y = 0;
    for (int i = pos_y; i < n; i++) {
        // 这个循环和主函数中的循环是不是很像
        // 这里每次都要把i坐标当成旧的pox_y坐标传给下一行，下一行全部判断完毕时恢复pox_y坐标，pos_x坐标不用传递，直接-1就行
        dfs51(queens, pos_x, pos_y, x, y, p, q, i, n);
        pos_y++;
    }
    // 下一行循环完毕后，因为是pos_x和pos_y都是引用类型，因此要恢复原先的pos_x和pox_y
    pos_x--;
    pos_y = last_y;
    x[pos_x] -= 1; // 撤走皇后，并把该皇后位置在四个轴上的相应位置的值-1
    y[pos_y] -= 1;
    p[pos_x + pos_y] -= 1;
    q[pos_x - pos_y + n - 1] -= 1;
    queens[pos_x][pos_y] = '.';
    return; // 该位置判断完毕，由调用该函数的循环去执行pos_y++，即再去判断下一个位置。第一行的下一个位置是由主函数的for循环控制，以后行的下一个位置是由某个递归函数中的for循环控制。
}

//51. N 皇后
//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//上图为 8 皇后问题的一种解法。
//给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
//每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//示例：
//输入：4
//输出： [
//    [".Q..",  // 解法 1
//        "...Q",
//        "Q...",
//        "..Q."],
//
//        ["..Q.",  // 解法 2
//        "Q...",
//        "...Q",
//        ".Q.."]
//]
//解释: 4 皇后问题存在两个不同的解法。
//提示：
//皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
vector<vector<string>> solveNQueens(int n) {
    int pos_x = 0, pos_y = 0; // xy当前位置
    vector<int> x = vector<int>(n, 0); // x轴各个位置是否有皇后
    vector<int> y = vector<int>(n, 0); // y轴各个位置是否有皇后
    vector<int> p = vector<int>(2 * n - 1, 0); // 左斜轴各个位置是否有皇后
    vector<int> q = vector<int>(2 * n - 1, 0); // 右斜轴各个位置是否有皇后
    vector<string> queens = vector<string>(n, string(n, '.')); // 当前已经摆好的棋盘
    for (int i = 0; i < n; i++) {
        dfs51(queens, pos_x, pos_y, x, y, p, q, i, n);
        pos_y++;
    }
    return res51;
}

map<int, char> int2strmap = {
    {0, '0'},
    {1, '1'},
    {2, '2'},
    {3, '3'},
    {4, '4'},
    {5, '5'},
    {6, '6'},
    {7, '7'},
    {8, '8'},
    {9, '9'},
};

string int2str(int a) {
    string r;
    int nag = 0;
    if (a < 0) {
        nag = 1;
        a = -a;
    }
    while (true) {
        r.push_back(int2strmap[a % 10]);
        a = (int)(a / 10);
        if (a == 0) {
            break;
        }
    }
    if (nag = 1) r.push_back('-');
    reverse(r.begin(), r.end());
    return r;
}

void dfs257(TreeNode* root, string& string_temp257, vector<string>& res257) {
    if (root == nullptr) {
        return;
    }
    string string_num = to_string(root->val);
    string_temp257 += string_num;
    if (root->left == nullptr && root->right == nullptr) {
        res257.push_back(string_temp257);
    }
    string_temp257.append("->");
    dfs257(root->left, string_temp257, res257);
    dfs257(root->right, string_temp257, res257);
    string_temp257.pop_back();
    string_temp257.pop_back();
    for (int i = 0; i < string_num.size(); i++) {
        string_temp257.pop_back();
    }
}

//257. 二叉树的所有路径
//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//说明 : 叶子节点是指没有子节点的节点。
//示例 :
//输入:
//   1
//  / \
// 2   3
//  \
//   5
//输出: ["1->2->5", "1->3"]
//解释 : 所有根节点到叶子节点的路径为 : 1->2->5, 1->3
vector<string> binaryTreePaths(TreeNode* root) {
    string string_temp257;
    string string_num;
    vector<string> res257;
    if (root == nullptr) {
        return res257;
    }
    dfs257(root, string_temp257, res257);
    return res257;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        if (-n % 2 > 0) {
            return -factorial(-n);
        }
        else {
            return factorial(-n);
        }
    }
    else {
        return n * factorial(n - 1);
    }
}

void dfs60(vector<int>& nums, int& n, int& k, int& i, string &res60) {
    int m = factorial(n - 1);
    while (true) {
        if (n == 0) {
            break;
        }
        if (nums[i] == -1) {
            i++;
            continue;
        }
        if (k > m) {
            k = k - m;
            i++;
        }
        else {
            res60 += to_string(nums[i]);
            nums[i] = -1;
            n--;
            i = 0;
            dfs60(nums, n, k, i, res60);
            break;
        }
    }
}

//60. 第k个排列
//给出集合[1, 2, 3, …, n]，其所有元素共有 n!种排列。
//按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//给定 n 和 k，返回第 k 个排列。
//说明：
//给定 n 的范围是[1, 9]。
//给定 k 的范围是[1, n!]。
//示例 1:
//输入: n = 3, k = 3
//输出 : "213"
//示例 2 :
//    输入 : n = 4, k = 9
//    输出 : "2314"
string getPermutation(int n, int k) {
    if (k < n || n <= 0 || n > 9 || k <= 0) {
        throw new exception("输入参数错误");
    }
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        nums.push_back(i+1);
    }
    string res60;
    int i = 0;
    dfs60(nums, n, k, i, res60);
    return res60;
}

struct TreeNode2 {
    int val;
    TreeNode2 *left;
    TreeNode2 *right;
    TreeNode2(int x) : val(x), left(NULL), right(NULL) {}
};
 
vector<vector<int>> res107;

void dfs107(TreeNode2* root, int i) {
    if (root == nullptr) {
        return;
    }
    vector<int> temp107;
    if (res107.size() <= i) {
        res107.push_back(temp107);
    }
    res107[i].push_back(root->val);
    dfs107(root->left, i + 1);
    dfs107(root->right, i + 1);
}

//107. 二叉树的层次遍历 II
//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//例如：
//给定二叉树[3, 9, 20, null, null, 15, 7],
//   3
//  / \
// 9  20
//   / \
// 15   7
//返回其自底向上的层次遍历为：
//[
//    [15, 7],
//    [9, 20],
//    [3]
//]
vector<vector<int>> levelOrderBottom(TreeNode2* root) {
    dfs107(root, 0);
    reverse(res107.begin(), res107.end());
    return res107;
}

static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
}

//347. 前 K 个高频元素
//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//示例 1:
//输入: nums = [1, 1, 1, 2, 2, 3], k = 2
//输出 : [1, 2]
//示例 2 :
//输入 : nums = [1], k = 1
//输出 : [1]
//提示：
//你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
//你的算法的时间复杂度必须优于 O(n log n), n 是数组的大小。
//题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
//你可以按任意顺序返回答案。
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    vector<int> res347;
    for (int num : nums) {
        if (frequency.find(num) == frequency.end()) {
            frequency.emplace(num, 1);
        }
        else {
            frequency[num] += 1;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    for (auto& fre : frequency) {
        if (q.size() == k) {
            if (q.top().second < fre.second) {
                q.pop();
                q.emplace(fre.first, fre.second);
            }
        }
        else {
            q.emplace(fre.first, fre.second);
        }
    }
    while (!q.empty()) {
        res347.emplace_back(q.top().first);
        q.pop();
    }
    return res347;
}
vector<vector<int>> res77;
vector<int> nums_temp77;

void dfs77(int start, int n, int k) {
    if (n - start < k) {
        return;
    }
    if (k == 0) {
        res77.push_back(nums_temp77);
        return;
    }
    for (int i = start; i < n; i++) {
        nums_temp77.push_back(i + 1);
        dfs77(i + 1, n, k - 1);
        nums_temp77.pop_back();
    }
}
//77. 组合
//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//示例 :
//输入: n = 4, k = 2
//输出 :
//    [
//        [2, 4],
//        [3, 4],
//        [2, 3],
//        [1, 2],
//        [1, 3],
//        [1, 4],
//    ]
vector<vector<int>> combine(int n, int k) {
    dfs77(0, n, k);
    return res77;
}
