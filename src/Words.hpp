#ifndef WORDS_H
#define WORDS_H
#include<iostream>
#include"string"

class Words{
private:
    BinarySTree bst;
public:
    int search (string word);
    void addWord(string word);
    void delateWord(string word);
    void editWord(string oldWord, string newWord );

};




#endif // WORDS_H
