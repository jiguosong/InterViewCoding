/*
 Implement a trie with insert, search, and startsWith methods.

 Note:
 You may assume that all inputs are consist of lowercase letters a-z.
 */

#include "trie.h"


trie::trie()
{
    root = new trieNode();
}

trie::~trie()
{
    delete root;
    root = nullptr;
}

void trie::insert(std::string word)
{
    _add(root, word);
}

void trie::_add(trieNode *root, std::string word)
{
    trieNode *p = root;
    for (auto c:word) {
        p->prefixes++;
        int idx = c - 'a';
        if (p->child[idx] == nullptr) p->child[idx] = new trieNode;
        p = p->child[idx];
    }

    p->isWord = true;
    p->words++;
}

bool trie::search(std::string key)
{
    return _search(root, key);
}

bool trie::_search(trieNode *root, std::string key)
{
    trieNode *p = root;

    for (auto c : key) {
        int idx = c - 'a';
        if (!p->child[idx]) return false;
        p = p->child[idx];
    }

    return p->isWord;
}

bool trie::startWith(std::string prefix)
{
    return _startWith(root, prefix);
}

bool trie::_startWith(trieNode *root, std::string prefix)
{
    trieNode *p = root;

    for (auto c : prefix) {
        int idx = c - 'a';
        if (!p->child[idx]) return false;
        p = p->child[idx];
    }

    return true;
}


int trie::count(std::string key)
{
    return _count(root, key);
}


int trie::_count(trieNode *root, std::string key)
{
    trieNode *p = root;

    for (auto c : key) {
        int idx = c - 'a';
        if (!p->child[idx]) return 0;
        p = p->child[idx];
    }

    return p->words;
}

int trie::countPrefix(std::string key)
{
    return _count_prefix(root, key);
}

int trie::_count_prefix(trieNode *root, std::string key)
{
    trieNode *p = root;

    for (auto c : key) {
        int idx = c - 'a';
        if (!p->child[idx]) return 0;
        p = p->child[idx];
    }

    return p->prefixes;
}

void trie::_delete(trieNode *root, std::string word)
{
    trieNode *p = root;

    for (auto c : word) {
        int idx = c - 'a';
        if (!p->child[idx]) return;
        p->prefixes--;
        p = p->child[idx];
    }

    p->words--;

    return;
}

void trie::remove(std::string word)
{
    if(_search(root, word))  _delete(root, word);
}























