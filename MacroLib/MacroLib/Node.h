#pragma once

struct Node {
	int value;
	struct Node *next;
};
typedef struct Node Node;


//
#define nodeLinkToNode(node, anotherNode) \
    node.next = &anotherNode;

//
#define getValueByNodeAddress(node) \
    node->value

//
#define getNextNodeByNodeAddress(node) \
    node->next

//
#define moveToNextNodeByNodeAddress(node) \
    node = getNextNodeByNodeAddress(node);

//
#define moveToNextNodeByNodeAddress_Safe(node) \
    if(node != NULL){                          \
	    moveToNextNodeByNodeAddress(node)      \
	}

//
#define newNode(name) \
    Node* name = malloc(sizeof(Node));

//
#define newNodeByValue(name, inValue) \
    newNode(name);                    \
    (*name).value = inValue;          \
    (*name).next = NULL;

//
#define newNodeByNode(newNodeName, inNode) \
    newNode(name)                   \
    *name = inNode;

//
#define createNode(name) \
    Node name = {.value = 0, .next = NULL};

//
#define createNodeByValue(name, inValue) \
    createNode(name);                    \
    name.value = inValue;

//
#define createNodeByNode(name, inNode) \
    createNode(name);                  \
    name = inNode;

