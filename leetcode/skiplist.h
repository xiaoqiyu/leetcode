//
//  skiplist.h
//  leetcode
//
//  Created by Xiaoqi Yu on 13/9/14.
//  Copyright (c) 2014 Xiaoqi Yu. All rights reserved.
//

#ifndef __leetcode__skiplist__
#define __leetcode__skiplist__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX_LEVEL 10

//node of skip list
typedef struct nodeStructure
{
    int key;
    int value;
    struct nodeStructure *forward[1];
}nodeStructure;

//skip list
typedef struct skiplist
{
    int level;
    nodeStructure * header;
}skiplist;


//creat new node
nodeStructure* createNode(int level,int key,int value);

//初始化跳表
skiplist* createSkiplist();

//随机产生层数
int randomLevel();

//插入节点
bool insert(skiplist *sl,int key,int value);

//搜索指定key的value
int search(skiplist *sl,int key);

//删除指定的key
bool deleteSL(skiplist *sl,int key);

void printSL(skiplist *sl);


#endif /* defined(__leetcode__skiplist__) */
