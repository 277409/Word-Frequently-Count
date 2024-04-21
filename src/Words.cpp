#include"Words.hpp"

int Words::search (string){
    return bst.search(word);
}

void Words::addWord(string word){
    bst.insert(word);
}

void Words::delateWord(string word){
    // call method delete in binaryTree
    // bst.delete(word);
}

void editWord(string oldWord, string newWord ){
    delateWord(oldWord);
    addWord(newWord);
}
