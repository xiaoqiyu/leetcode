//
//  def.h
//  leetcode
//
//  Created by Xiaoqi Yu on 13/9/14.
//  Copyright (c) 2014 Xiaoqi Yu. All rights reserved.
//

#ifndef leetcode_def_h
#define leetcode_def_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

#endif
