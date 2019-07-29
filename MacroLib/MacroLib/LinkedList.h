#pragma once

#include "Node.h"

struct LinkedList {
	Node *head;
	Node *tail;
	int count;
};
typedef struct LinkedList LinkedList;

// 初始化鏈表
#define initLinkedList(list) \
    list.head = NULL;        \
    list.tail = NULL;        \
    list.count = 0;

// 建立並初始化鏈表
#define createLinkedList(name) \
    LinkedList name;           \
    initLinkedList(name)

// 判斷鏈表是否為空
#define isLinkedListEmpty(list) \
    list.count == 0


// 移動表頭到地址
#define moveHandToNodeAddress(list, nodeAddress) \
    list.head = nodeAddress;

// 地址指向表頭
#define nodeLinkToHandByNodeAddress(list, nodeAddress) \
     nodeAddress->next = list.head;

// 地址連接表頭
#define pushFrontByNodeAddress(list, nodeAddress)  \
    nodeLinkToHandByNodeAddress(list, nodeAddress) \
    moveHandToNodeAddress(list, nodeAddress)       \
    list.count++;


// 移動表尾到地址
#define moveTailToNodeAddress(list, nodeAddress) \
    list.tail = nodeAddress;

// 地址連接到表尾
#define nodeLinkToTailByNodeAddress(list, nodeAddress) \
     nodeAddress->next = list.tail;

// 表尾連接到地址
#define pushBackByNodeAddress(list, nodeAddress)   \
    nodeLinkToTailByNodeAddress(list, nodeAddress) \
    moveTailToNodeAddress(list, nodeAddress)       \
    list.count++;


// 
#define pushFrontByNodeAddress_Safe(list, nodeAddress) \
    pushFrontByNodeAddress(list, nodeAddress)          \
    if (isLinkedListEmpty(list)) {                     \
        moveTailToNodeAddress(list, nodeAddress)       \
    }

// 
#define pushBackByNodeAddress_Safe(list, nodeAddress) \
    pushBackByNodeAddress(list, nodeAddress)          \
    if (isLinkedListEmpty(list)) {                    \
        moveHandToNodeAddress(list, nodeAddress)      \
    }

//
#define pushFrontByNewNodeByNode(list, newNodeName, node) \
    newNodeByNode(newNodeName, node);                     \
    pushFrontByNodeAddress_Safe(list, newNodeName);

//
#define pushFrontByNewNodeByValue(list, newNodeName, value) \
    newNodeByValue(newNodeName, value)                      \
    if(newNodeName){ pushFrontByNodeAddress_Safe(list, newNodeName); }

//
#define pushFrontByNode(list, node) \
    pushFrontByNodeAddress_Safe(list, &node);

//
#define pushFrontByValue(list, value) \
    pushFrontByNewNodeByValue(list, uniqueVarName(macroNodeTempVar), value)

//
#define travelLinkedList(list, currentNodeName, ...)      \
    loop(list.count){                                     \
        __VA_ARGS__                                       \
        moveToNextNodeByNodeAddress_Safe(currentNodeName) \
    }

//
#define freeLinkedList_template(list, tmp1, tmp2)     \
    Node *tmp1 = list.head;                           \
    Node *tmp2 = getNextNodeByNodeAddress(list.head); \
    travelLinkedList(list, tmp2,                      \
        free(tmp1);                                   \
        tmp1 = tmp2;                                  \
    )                                                 \
    initLinkedList(list);

//
#define freeLinkedList(list)                                 \
    if(list.head){                                           \
    freeLinkedList_template(list,                            \
                            uniqueVarName(macroNodeTempVar), \
							uniqueVarName(macroNodeTempVar)) \
    }

//
#define printLinkedList_template(list, tmp)        \
    Node *tmp = list.head;                         \
    travelLinkedList(list, tmp,                    \
	    printf("%d ", getValueByNodeAddress(tmp)); \
    )

//
#define printLinkedList(list) \
    if(list.head){ printLinkedList_template(list, uniqueVarName(macroNodeTempVar)) }



