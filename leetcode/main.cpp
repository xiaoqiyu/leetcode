//
//  main.cpp
//  leetcode
//
//  Created by Xiaoqi Yu on 1/9/14.
//  Copyright (c) 2014 Xiaoqi Yu. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>
#include <set>
#include <stack>
#include <assert.h>
#include "skiplist.h"
#include "def.h"
#include "bt.h"

using namespace std;

//#define TESTSKIPLST
#define TESTSUBSET



bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> q;
    vector<TreeNode*> v;
    if(root == NULL)
        return true;
    TreeNode * r = root;
    q.push(root);
    while( !q.empty()){
        r = q.front();
        v.push_back(r);
        q.pop();
        if(r->left != NULL &&r->right != NULL){
            q.push(r->left);
            q.push(r->right);
        }
        
    }
    return true;
    
};

vector<int> grayCode(int n) {
    
    vector<int> ret1;
    if(n == 0){
        ret1.push_back(0);
        return ret1;
    }
    
    ret1 = grayCode(n-1);
    
    int tmp = 1 << (n-1);
  
    
    vector<int> ret(ret1);
    
   // cout<<"start"<<endl;
    
    int len = ret1.size();
    
   // for (int i = 0 ; i < len; ++i) {
     //   cout<<ret[i]<<endl;
    //}
    
  //  cout<<"//////////////////////////////"<<tmp<<endl;
    for(int i = 0; i < len; i++){
       // cout<<"push val\t"<< ret1[len-1-i]+tmp<<endl;
        ret.push_back(ret1[len-1-i]+tmp);
    }
    
    return ret;
    
}

vector< vector<int>> generate(int numRows){
    vector< vector<int>> ret;
    if(numRows == 0){
        return ret;
    }
    if(numRows == 1){
        vector<int> v;
        v.push_back(1);
        ret.push_back(v);
        return ret;
    }
    
    vector<int> v;
    v.push_back(1);
    ret.push_back(v);
    
    for(int i = 1; i < numRows; ++i){
        vector<int> v;
        v.push_back(1);
        for(int j = 1; j < i; ++j){
            int t = ret[i-1][j-1] + ret[i-1][j];
            v.push_back(t);
        }
        v.push_back(1);
        ret.push_back(v);
    }
    return ret;
}


void generate(int leftNum, int rightNum, string s,  vector<string> &result){
    if(leftNum == 0 && rightNum == 0){
        result.push_back(s);
    }
    
    if(leftNum > 0)
    {
        generate(leftNum - 1, rightNum, s+'(', result );
    }
    
    if(rightNum > 0 && leftNum < rightNum)
    {
        generate(leftNum, rightNum -1, s+')', result);
    }
    
}

string  substring(string str1, string str2, int m){
    int s1, s2, e1, e2;
    int r;
    
    s1 = s2 = 0;
    e1 = e2 = 0;
    r = 0;
    string ret;
    int flag = 0;
    while(r < m &&  e1 < str1.size() && e2 < str2.size()){
        if(e1 - s1 + 1 >= m){
            flag = 1;
            break;
        }
        
        if(str1[e1] == str2[e2]){
            e1++;
            e2++;
            r ++;
        }else{
            s1 = e1+1;
            s2 = e2+1;
            e1 = s1;
            e2 = s2;
            r = 0;
        }
        flag = 0;
    }
   // cout<<s1<<" "<<e1<<endl;
    if(flag == 1){
        ret = str1.substr(s1, e1);
    }
    return ret;
    
}


void generateSub(vector<int> &s, int step, vector<vector<int>> & result, vector<int> & output)
{
    for (int i = step; i < s.size(); i++) {
        output.push_back(s[i]);
        for(int k = 0; k < output.size(); ++k){
            cout<<output[k] <<" ";
        }
        cout<<endl;
        result.push_back(output);
        if(i < s.size() - 1)
            generateSub(s, i+1, result, output);
        output.pop_back();
    }
}

vector<vector<int>> Subsets(vector<int> & s)
{
    vector<vector<int>> result;
    vector<int> output;
    if(s.size() == 0) return result;
    result.push_back(output);
    sort(s.begin(), s.end());
    generateSub(s, 0, result, output);
    return result;
}

int main1(int argc, const char * argv[])
{

    // insert code here...

    std::cout << "Hello, World!\n";
#ifdef ZERO
    vector<int> vret;
    vret = grayCode(3);
    cout<<"code len is:\t"<<vret.size()<<endl;
    
    cout<<"test vector" <<endl;
    
    vector< vector<int>> ret;
    ret = generate(3);

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j <= i; ++j){
            cout<<ret[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    vector<string> ret;
    string s;
    generate(3, 3, s, ret);
    for(int i = 0; i < ret.size(); ++i)
    {
        cout << ret[i]<<endl;
    }
    
#endif
    
#ifdef TESTSUBSTR
    string str1 = "abcdeft";
    string str2 = "acbbcdef";
    string ret;
    ret = substring(str1, str2, 4);
    cout<<ret<<endl;
#endif
    
#ifdef TESTSKIPLST
    cout << "start skip list\n";
    skiplist *sl=createSkiplist();
    for(int i=1;i<=19;i++)
    {
        insert(sl,i,i*2);
    }
    printSL(sl);
    //搜索
    int i=search(sl,4);
    printf("i=%d\n",i);
    //删除
    bool b=deleteSL(sl,4);
    if(b)
        printf("删除成功\n");
    printSL(sl);
    system("pause");
    return 0;
#endif
    
#ifdef TESTSUBSET
    vector<vector<int>> ret;
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    ret = Subsets(input);
    
#endif
    
    return 0;
}

bool isHappy(int n){
    set<int> numset;
    set<int>::iterator iter;
    int sum = 0;
    int tmp = n;
    while((iter = numset.find(sum)) == numset.end())
    {
        numset.insert(sum);
        sum = 0;
        //int tmp = n;
         cout<<"tmp is:"<<tmp;
        while(tmp != 0){
            cout<<"tmp is:"<<tmp;
            sum += (tmp%10)*(tmp%10);
            tmp = tmp/10;
        }
        if(sum == 1)
            return true;
        else
            tmp = sum;
    }
    return false;
}

int hammingWeight(uint32_t n)
{
    int ret = 0;
    unsigned op = 1;
    for(int i = 0; i < 32; ++i)
    {
        cout <<i<<"op is:"<<op<<"  ";
        unsigned int tmp = n & op;
        
        if(tmp > 0)
            ret ++;
        cout<<tmp<<" "<< ret<<endl;
        op =  op <<1;
    }
    return ret;
}


/*
 *
 Tree + BFS + DFS + Binary Search Tree
 *
*/


TreeNode* inverTree(TreeNode* root){
    
    if(root == NULL)
        return NULL;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *leftnode, *rightnode, *tmpnode;
    TreeNode * ret;
    tmpnode = root;
    queue<int> vallst;
    while(!q.empty()){
        tmpnode = q.front();
        q.pop();
        vallst.push(tmpnode->val);
        if(tmpnode->right  != NULL)
            q.push(tmpnode->right);
        if(tmpnode -> left != NULL)
            q.push(tmpnode -> left);
    }
    bool isLeft = true;
    if(!vallst.empty()){
        ret = new TreeNode(vallst.front());
        vallst.pop();
    }
    tmpnode = ret;
    while(!vallst.empty()){
        int val = vallst.front();
        vallst.pop();
        TreeNode * tn = new TreeNode(val);
        if(isLeft){
            tmpnode->left = tn;
            isLeft = false;
            leftnode = tmpnode->left;
        }else{
            tmpnode -> right = tn;
            tmpnode = leftnode;
            isLeft = true;
        }
    }
    
    
    return ret;
}

TreeNode* reInvertTree(TreeNode * root){
    if(!root)
        return NULL;
    TreeNode *tmp =root->left;
    root -> left  = reInvertTree(root ->right);
    root -> right = reInvertTree(tmp);
    return root;
}

string binaryTreePath(TreeNode * root){
    
    return "a";
}

struct levelNode{
    TreeNode *node;
    int level;
    levelNode(TreeNode *n, int l):node(n), level(l){}
};

vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> ret;
    vector<int> tmplst;
    if(root == NULL)
        return ret;
    queue<levelNode> q;
    q.push(levelNode(root, 0));
    while(!q.empty()){
        levelNode  curNode = q.front();
        TreeNode *tmp = curNode.node;
        int curLevel = curNode.level;
        q.pop();
        
        if(curLevel == ret.size())
            ret.push_back(vector<int>(0, 0));
        ret[curLevel].push_back(tmp->val);
        if(tmp->left)
            q.push( levelNode(tmp->left, curLevel +1));
        if(tmp -> right)
            q.push( levelNode(tmp->right, curLevel + 1));
        
    }
    return ret;
}

vector<vector<int>> levelOrderBottom(TreeNode* root){
    vector<vector<int>>levelNodeValues;
    if(!root)
        return levelNodeValues;
    vector<TreeNode *> *curLevel = new vector<TreeNode*>();
    vector<TreeNode *> *nextLevel = new vector<TreeNode*>();
    curLevel->push_back(root);
    
    while(!curLevel -> empty()){
        vector<int> curLevelValues;
        for (int i = 0; i < curLevel->size();i++) {
            TreeNode *curNode = (*curLevel)[i];
            curLevelValues.push_back(curNode->val);
            if(curNode->left) nextLevel->push_back(curNode->left);
            if(curNode -> right) nextLevel -> push_back(curNode->right);
        }
        levelNodeValues.push_back(curLevelValues);
        
        vector<TreeNode*> *tmp = curLevel;
        curLevel = nextLevel;
        nextLevel = tmp;
        nextLevel->clear();
        
    }
    reverse(levelNodeValues.begin(), levelNodeValues.end());
    return levelNodeValues;
}

void binaryTreePathsByLevel(vector<string>*ret, string strtmp, TreeNode *node) {
    if(node == NULL)
        return;
    strtmp += "->";
    strtmp += to_string(node->val);
    
    if(node->left == NULL && node -> right == NULL){
        ret->push_back(strtmp);
        return;
    }
    if(node->left){
        binaryTreePathsByLevel(ret, strtmp, node->left);
    }
    if(node ->right)
    {
        binaryTreePathsByLevel(ret, strtmp, node -> right);
    }
}

vector<string> binaryTreePaths(TreeNode *root){
    vector<string> ret;
    vector<string> *pVec = &ret;
    if (root == NULL)
        return ret;
    if(!root->left && !root->right){
        ret.push_back(to_string(root->val));
        return ret;
    }
    if(root -> left){
        binaryTreePathsByLevel(pVec, to_string(root->val), root->left);
    }
    if(root -> right){
        binaryTreePathsByLevel(pVec, to_string(root->val), root -> right);
    }
    return ret;
}

vector<int> rightSideView(TreeNode *root){
    vector<int> ret;
    if(!root)
        return ret;
    if(!root->left && ! root->right){
        ret.push_back(root->val);
        return ret;
    }
    queue<levelNode> q;
    q.push(levelNode(root, 0));
    while(!q.empty()){
        levelNode ln = q.front();
        TreeNode * curNode = ln.node;
        int curLevel = ln.level;
        q.pop();
        if(curNode->left)
            q.push( levelNode(curNode->left, curLevel + 1));
        if(curNode ->right)
            q.push( levelNode(curNode->right, curLevel + 1));
        int nextLevel;
        if(q.size() >= 1){
            nextLevel = q.front().level;
        }
        else{
            nextLevel = 0;
        }
        cout<<"next level:"<<nextLevel<<endl;
        if(curLevel != nextLevel)
            ret.push_back(curNode->val);
    }
    return ret;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
    multiset<long long> bst;
    for(int i = 0; i < nums.size(); ++i){
        if(bst.size() == k + 1)
            bst.erase(bst.find(nums[i-k-1]));
        auto lb = bst.lower_bound(nums[i] - t);
        if(lb != bst.end() && *lb - nums[i] <= t)
            return true;
        bst.insert(nums[i]);
    }
    return false;
}

bool isExistNode(TreeNode *root, TreeNode *node){
    if(!root)
        return false;
    bool retLeft = false;
    bool retRight = false;
    if(root == node)
        return true;
    if(root -> left)
        retLeft = isExistNode(root->left, node);
    if(root -> right)
        retRight = isExistNode(root -> right, node);
    return retLeft||retRight;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *ret = NULL;
    if(!root)
        return root;
    if(root == p || root == q )
        return root;
    if((isExistNode(root->left, p)&&isExistNode(root->right, q)) || (isExistNode(root->left, q)&&isExistNode(root->right, p)))
        return root;
    if ( isExistNode(root -> left , p) && isExistNode(root->left, q))
        ret = lowestCommonAncestor(root->left, p, q);
    if ( isExistNode(root -> right , p) && isExistNode(root->right, q))
        ret = lowestCommonAncestor(root->right, p, q);
    return ret;
}

bool verifyBST(TreeNode *root, bool left, bool right, int lmax, int rmin){
    if(root == NULL)
        return true;
    if(left && root->val >= lmax)
        return false;
    if(right && root->val <= rmin)
        return false;
    bool validLeft = verifyBST(root->left, true, right, root -> val, rmin);
    bool validRight = verifyBST(root -> right, left, true, lmax, root->val);
    return validLeft && validRight;
}
bool isValidBST(TreeNode* root) {
    return verifyBST(root, false, false, 0, 0);
}

void setApp(){
    typedef set<int, less<int>> IntSet;
    IntSet s1;
    
    s1.insert(4);
    s1.insert(3);
    s1.insert(5);
    s1.insert(1);
    s1.insert(6);
    s1.insert(2);
    s1.insert(5);
    
    copy(s1.begin(), s1.end(), ostream_iterator<int>(cout, " "));
    cout << endl <<endl;
    
    pair<IntSet::iterator, bool> status = s1.insert(10);
    if(status.second)
        cout<<"4 is inserted as element"<<distance(s1.begin(), status.first) +1 <<endl;
    else
        cout<<"4 is already exists in s1"<<endl;
    copy(s1.begin(), s1.end(), ostream_iterator<int>(cout, " "));
    cout<<endl<<endl;
    
    set<int> s2(s1.begin(), s1.end());
    copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
    cout<< endl<<endl;
}

void preorder(TreeNode * root){
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while(cur != NULL || !s.empty()){
        while(cur != NULL){
            cout<<cur->val<<endl;
            s.push(cur);
            cur = cur -> left;
        }
        if(! s.empty()){
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }
}

void inOrder(TreeNode * root){
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while(cur != NULL || !s.empty()){
        while(cur != NULL){
            s.push(cur);
            cur = cur -> left;
        }
        if(! s.empty()){
            cur = s.top();
            cout<<cur->val<<endl;
            s.pop();
            cur = cur -> right;
        }
    }
    
}

void postOrder(TreeNode *root){
    stack<TreeNode *> s;
    TreeNode *cur = root;
    TreeNode *pre = NULL;
    s.push(root);
    while(!s.empty()){
        cur = s.top();
        if( (!cur->left && !cur->right) || (pre == cur->left || pre == cur->right)){
            cout<<cur->val<<endl;
            s.pop();
            pre = cur;
        }else{
            if(cur -> right)
                s.push(cur->right);
            if(cur -> left)
                s.push(cur->left);
        }
    }
}


/*
 *
 9.10 - 9.20 String + Binary Search
 *
 */
string simplifyPath(string path){
    
    vector<string> stack;
               assert(path[0]=='/');
                int i=0;
                while(i< path.size())
                    {
                             while(path[i] =='/' && i< path.size()) i++; //skip the begining '////'
                             if(i == path.size())
                                    break;
                            int start = i;
                            while(path[i]!='/' && i< path.size()) i++; //decide the end boundary
                            int end = i-1;
                             string element = path.substr(start, end-start+1);
                            if(element == "..")
                                 {
                                         if(stack.size() >0)
                                             stack.pop_back();
                                    }
                           else if(element!=".")
                                 stack.push_back(element);
                        }
               if(stack.size() ==0) return "/";
                string simpPath;
               for(int i =0; i<stack.size(); i++)
                  simpPath += "/" + stack[i];
                return simpPath;
   }

string addBinary(string a, string b) {
    string ret;
    int maxSize = a.size() > b.size() ? a.size():b.size();
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int carry = 0;
    int ai, bi,ci;
    for(int i  = 0; i < maxSize; ++i){
        if (a.size() >i)
            ai = a[i]-'0';
        else
            ai = 0;
        
        cout<<b.size()<<" "<<i<<endl;
        if (b.size() >i){
            cout<<"not zero"<<endl;
            bi = b[i]-'0';
        }
        else{
            cout<<"runhere"<<endl;
            bi = 0;
        }
        ci = (ai+bi+carry) % 2;
        carry  = (ai+bi+carry) / 2;
        
        cout<<i<<" "<<carry<<endl;
        cout<<ai<<" "<<bi<<" "<<ci<<endl;
        ret.insert(ret.begin(), ci+'0');
    }
    if(carry == 1){
        
        ret.insert(ret.begin(), '1');
    }
    return ret;
}

int lengthOfLongestSubstring(string s) {
    int map[256];
    int maxLen, len;
    len = maxLen = 0;
    for(int i = 0; i < 256; i ++){
        map[i] = -1;
    }
    for(int i = 0; i < s.size(); ++ i){
        char c = s[i];
        int lastidx = map[c];
        if(lastidx == -1){
            int curidx = i - len;
            for(int j = curidx; j < lastidx; ++j){
                map[s[j]] = -1;
            }
            curidx = lastidx + 1;
            len = i - curidx + 1;
            map[c] = i;
        }else{
            len++;
            map[c] = i;
            if(len > maxLen)
                maxLen = len;
        }
        
    }
    return maxLen;
}


/*
 *
 10.01-10.10
 *
 hash table + dynamic programming
 *
 */
bool isAnagram(string s, string t) {
    return true;
}


/*
 *
 Other topics
 *
 */
void testBlockSize(){
    int a, b;
    for(int n = 16; n < 128; ++n){
    b = log2(n);
    a = n - b;
    cout<<"N:B: "<<a<<" "<<b<<"; big block: " << a*a*pow(2,b)<<" ";
    cout<<"small block: "<< a/2 *pow(2, 2*b)<<endl;
    }
}

int main()
{
#if 0
    int i;
    double ret;
    cout<< hammingWeight(2147483648)<<endl;
    return 0;
    if(isHappy(7))
        cout<<"happy\n";
    else
        cout<<"not happy\n";
    return 0;
    for(i = 0; i < 100000; ++i)
    {
        double j = i;
        ret = 1 - 1/j;
        cout<<ret<<endl;
        cout<<"final result is: "<<pow(ret, -j)<<endl;
        cout<<"x is:"<<j <<endl;
    }
#endif

                
    /*
     *
     Tree + BFS + DFS + Binary Search Tree(9.01 - 9.10)
     *
     */
#if 0
    TreeNode * root = new TreeNode(1);
    root -> left =  new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    root -> right ->right = new TreeNode(7);
    //root -> left ->left ->left = new TreeNode(10);
    
    
    vector<vector<int>> ret = levelOrderBottom(root);
    vector<string> ret2 = binaryTreePaths(root);
    vector<int> ret3 = rightSideView(root);
    BiTree bt(root);
    //bt.printBt();
    
    vector<vector<int>>::iterator iter;
    vector<int>::iterator iter1;

    for(iter = ret.begin(); iter != ret.end(); ++iter){
        vector<int> subvector = *iter;
        for (iter1 = subvector.begin(); iter1 != subvector.end(); ++iter1) {
            cout<<*iter1<<" ";
        }
        cout<<endl;
    }
    
    cout<<"begin path"<<endl;
    vector<string> ::iterator iter2;
    for(iter2 = ret2.begin(); iter2 != ret2.end(); ++iter2){
        cout << *iter2 <<endl;
    }
    
    
    cout<<"begin right view"<<endl;
    for(iter1 = ret3.begin(); iter1 != ret3.end(); ++ iter1){
        cout<< *iter1<<endl;
    }
    
    cout<<"begin LCA"<<endl;
    cout<<lowestCommonAncestor(root, root->left, root->left->left)->val<<endl;
    
    cout<<"preorder"<<endl;
    preorder(root);
    
    TreeNode *testroot = new TreeNode(1);
    testroot ->left = new TreeNode(2);
    
    cout<<"Inorder"<<endl;
    inOrder(testroot);
    
    cout<<"postorder"<<endl;
    postOrder(root);
    /*
    root -> left -> left->left = new TreeNode(8);
    root -> left -> right->left = new TreeNode(5);
    root -> right -> left->left = new TreeNode(6);
    root -> right ->right->left = new TreeNode(7);
    
    root -> left -> left -> right= new TreeNode(4);
    root -> left -> right -> right = new TreeNode(5);
    root -> right -> left -> right= new TreeNode(6);
    root -> right ->right -> right = new TreeNode(7);
     */
    
    
    TreeNode * inroot = reInvertTree(root);
    
    vector<int> intLst;
    intLst.push_back(1);
    intLst.push_back(4);
    intLst.push_back(7);
    cout<<"contains duplicate"<<endl;
    cout<<containsNearbyAlmostDuplicate(intLst, 10, 2)<<endl;
    
    cout<<"begin set app"<<endl;
    //setApp();
    set<int, greater<int>> s1;
    set<int, greater<int>> s2;
    for(int i = 1; i < 6; ++i)
    {
        s1.insert(i);
        s2.insert(i);
    }
    s1.insert(9);
    if(s1 == s2)
        cout<<"equals"<<endl;
    else
        cout<<"not equals"<<endl;
    cout<< *s1.lower_bound(8)<<endl;
    
    auto a = "abc";
    cout<<a<<endl;
    
#endif //end of 1st phase
    
    /*
     *
     String + binary search
     *
     */
    cout<<"simplifypath"<<endl;
    cout<<simplifyPath("//home/")<<endl<<endl;
    
    //testBlockSize();
    //cout<<addBinary("11", "1")<<endl;
    
    cout<<lengthOfLongestSubstring("aba")<<endl;
   


    return 0;
}

