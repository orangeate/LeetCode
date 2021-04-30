#include "../global.h"
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = this;
        isEnd = false;
    }

    void addWord(string word)
    {
        root = this;
        for(const auto& c : word)
        {
            if(root->next[c - 'a'] == nullptr)
                root->next[c - 'a'] = new WordDictionary();
            root = root->next[c - 'a'];
        }
        root->isEnd = true;
    }

    bool search(string word)
    {
        root = this;
        return findword(root, word, 0);
    }

    bool findword(WordDictionary* root, string word, int index)
    {
        if(index == word.size())
            return root->isEnd;

        if(word[index] == '.')
        {
            for(int i = 0; i < R; i++)
            {
                if(root->next[i] != nullptr && findword(root->next[i], word, index+1) == true)
                    return true;
            }
            return false;
        }
        else
        {
            if(root->next[word[index] - 'a'] != nullptr)
                return findword(root->next[word[index] - 'a'], word, index+1);
            else
                return false;
        }
    }

private:
    WordDictionary *root;
    static const int R = 26;
    WordDictionary *next[R] = {nullptr};
    bool isEnd;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */