//
//  bt.h
//  leetcode
//
//  Created by Xiaoqi Yu on 13/9/14.
//  Copyright (c) 2014 Xiaoqi Yu. All rights reserved.
//

#ifndef leetcode_bt_h
#define leetcode_bt_h

#include <iostream>
#include "def.h"
#include <queue>

using namespace std;

class BiTree{
private:
    TreeNode * root;

public:
    BiTree(){
        root = new TreeNode(0);
    }
    BiTree(TreeNode * tree){
        root = tree;
    }
    void printBt(){
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * tmp = root;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp != NULL){
                cout<<tmp->val<<' ';
                if(tmp -> left != NULL)
                    q.push(tmp->left);
                if(tmp -> right != NULL)
                    q.push(tmp->right);
            }
            
        }
    }
};
#endif
