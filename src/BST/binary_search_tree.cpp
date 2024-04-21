#include "binary_search_tree.hpp"
#include <iostream>

//__________________methods__________________//

// insertion
void BinarySTree::insert(string word, int counter)
{
    if (!this->root)
    { // if my tree doesn't have any node, so create first node
        root = new TreeNode(counter, word);
        return;
    }
    insert(word, counter, this->root);
}
void BinarySTree::insert(string word, int counter, TreeNode *root)
{
    if (!root)
        return;
    if (counter >= root->counter)
    { // add in right of the node
        if (!root->right)
            root->right = new TreeNode(counter, word);
        else
            insert(word, counter, root->right);
    }
    // add in the left of node (counter of new word < current counter)
    else
    {
        if (!root->left)
            root->left = new TreeNode(counter, word);
        else
            insert(word, counter, root->left);
    }
}

// search in tree
TreeNode *BinarySTree::search(pair<int, string> word)
{
    return search(word, this->root);
}
TreeNode *BinarySTree::search(pair<int, string> word, TreeNode *root)
{
    if (!root)
        return nullptr;
    if (word.first == root->counter && word.second == root->word)
        return root;
    if (word.first >= root->counter)
        return search(word, root->right);
    return search(word, root->left);
}

// deletion
void BinarySTree::deleteNode(string word, TreeNode *root)
{
}
void BinarySTree::deleteNode(string word)
{
}

// editing word
void BinarySTree::editNode(string word)
{
}
void BinarySTree::editNode(string word, TreeNode *root)
{
    // not you should handle if tree is empty
    // if search if found (counter==1) delete, else counter-=1
}

// take a sorted vector and convert it to a binary search tree
void BinarySTree::fill_tree(vector<pair<string, int>> words)
{
}

// this function return a vector of all words to display it
vector<pair<string, int>> BinarySTree::display_tree()
{
    return display_tree(root);
}
vector<pair<string, int>> BinarySTree::display_tree(TreeNode *root)
{
    // if(!root)
    // return;
    vector<pair<string, int>> words;
    words = display_tree(root->right);
    words.push_back({root->word, root->counter});

    // how to concatenate two vectors?
}

// Destructor
