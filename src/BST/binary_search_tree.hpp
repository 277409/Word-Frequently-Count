#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::pair;

struct TreeNode
{
    int counter{};
    string word{""};
    TreeNode*right{};
    TreeNode*left{};

    TreeNode(int counter,string word):counter(counter),word(word){}

};

class BinarySTree
{
private:
    TreeNode *root{};
public:
    BinarySTree()=default;

    void insert(string word,int counter);
    void insert(string word,int counter,TreeNode* root);

    void search(string word);
    void search(string word, TreeNode*root);

    void deleteNode(string word);
    void deleteNode(string word,TreeNode* root);

    void editNode(string word);
    void editNode(string word,TreeNode* root);
    
    void fill_tree(vector<string,int> words);

    vector<pair<string,int>> display_tree();
    vector<pair<string,int>> display_tree(TreeNode*root);

    ~BinarySTree();
};


#endif