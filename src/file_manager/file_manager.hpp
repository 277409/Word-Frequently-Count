#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <iostream>
#include <map>
#include <vector>
using namespace std;


class FileManager{
private:

    string path{""};
    map<string,vector<string>> sentences;
    map<string,int> words;
    
public:
    FileManager(string path);

    void set_path(string path);
    // read words and sentence from file
    void read_file();

    map<string,int> get_words();
    map<string,vector<string>> get_sentences();

    vector<string> from_sentence_to_words(string sen);


    /* 
    * write in file : updating text in file.txt
    * take an array of sentences and update it 
     */
    void write_inFile(vector<string>);




    //read from paragraph -> wait to check connecting in qml
};



#endif