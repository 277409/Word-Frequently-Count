#include "file_manager.hpp"
#include <fstream>
#include <string>
#include <sstream>

FileManager::FileManager(string path) : path(path) {}

void FileManager::set_path(string path)
{
    this->path = path;
}

//___________________Methods___________________//

vector<string> FileManager::from_sentence_to_words(string sen)
{
    vector<string> result;
    istringstream iss{sen};

    string w;
    while (getline(iss, w, ' '))
        result.push_back(w);

    string last_w = result[(int)result.size()], s = "";

    for (const auto &ch : last_w)
    {
        if (ch == '.')
            break;
        s += ch;
    }
}

void FileManager::read_file()
{
    string line{""};

    vector<string> line_words;
    ifstream my_file(this->path);
    if (my_file.fail())
    {
        return;
    }

    string sentence{""};
    string half_sen{""};
    string remain_sen{""};

    while (getline(my_file, line))
    {

        bool is_found = false;

        if (line[(int)line.size() - 1] == '.')
        {
            sentence = line;
            if (remain_sen != "")
            {
                sentence = remain_sen + sentence;
            }
            line_words = from_sentence_to_words(sentence);
            this->sentences[sentence] = line_words;
        }

        // founding the end of sentence
        else
        {
            for (const auto &ch : line)
            {
                (is_found) ? half_sen += ch : sentence += ch;
                if (ch == '.')
                {
                    is_found = true;
                }
            }

            sentence = remain_sen + sentence;

            this->sentences[sentence] = line_words;
            remain_sen = half_sen;
        }
        half_sen = "";
        for (const auto &w : line_words)
        {
            if (this->words.count(w))
                words[w]++;
            else
                words[w] = 1;
        }
        line_words.clear();
    }
}

map<string, int> FileManager::get_words()
{
    return words;
}

map<string, vector<string>> FileManager::get_sentences()
{
    return this->sentences;
}
