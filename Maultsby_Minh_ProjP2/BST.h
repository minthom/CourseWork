#include <iostream>
#include "CLQueue.h"
struct TNode {
  public:
  int day;  // Represents what day of the year it was
  int wind_spd;  // Represents the wind speed
  TNode *left;
  TNode *right;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};


class BST {
  public:
  BST();
  BST(const BST& originalBST); //(Deep-)Copy constructor
  ~BST(); //Destructor
  
  
  //main BST functions that call helper functions using the root Node
  int GetItem(int gitem);
  void PutItem(int newitem, int wspeed);
  void DeleteItem(int ditem);
  int GetLength();
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  void PrintTree();
  void ResetTree(OrderType order);
  int GetNextItem();
  bool TravEmpty();

  
  private:
  //helper functions called to recursively view/manipulate sub-tree elements
  void Insert (TNode* &curnode, int new_item, int wspeed);  // This was changed for use with my dataset
  int FindItem(TNode* curnode, int gitem);  // This should probably be changed for a more complete implementation. However, it does not need to be changed to complete this assignment
  void Delete(TNode* &curnode, int ditem);  // Same goes for the rest of the functions that involve fetching specific values from nodes
  void DeleteNode(TNode* &curnode);
  int CountNodes(TNode* curnode);
  void PrintNodes(TNode* curnode);
  void CopyNodes(TNode*& copyNode, const TNode* origNode);
  void DestroyNodes(TNode*& curNode);
  void PreNodes(TNode* curNode);
  void InNodes(TNode* curNode);
  void PostNodes(TNode* curNode);
  
  TNode *root;
  CLQueue *TravQueue;
};
