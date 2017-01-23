#ifndef trie_H_
#define trie_H_

#include <unordered_map>
#include <string>
#include <vector>

using std::vector;
using std::unordered_map;

const int NUMBER_SZ = 26;     // 26 letters, lower case assumed

class trie {
public:
    struct trieNode {
    public:
        trieNode *child[NUMBER_SZ];
        int words;
        int prefixes;
        bool isWord;

        trieNode() : isWord(false), words(0), prefixes(0)
        {
            for (auto &a:child) a = nullptr;  // must be &
        }

        ~trieNode()
        {
            for (int i = 0; i < NUMBER_SZ; ++i) {
                if (child[i] != nullptr) {
                    delete child[i];
                    child[i] = nullptr;
                }

            }
        }
    };

    trie();

    virtual ~trie();

    void insert(std::string word);

    void remove(std::string word);

    bool search(std::string key);

    bool startWith(std::string prefix);

    int count(std::string key);

    int countPrefix(std::string key);

private:
    trieNode *root;

    void _add(trieNode *root, std::string word);

    void _delete(trieNode *root, std::string word);

    bool _search(trieNode *root, std::string key);

    bool _startWith(trieNode *root, std::string prefix);

    int _count(trieNode *root, std::string key);

    int _count_prefix(trieNode *root, std::string key);
};

#endif
