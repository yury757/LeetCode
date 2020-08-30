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

int main()
{
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
    cout << shortestPalindrome("aacecaaa");
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
