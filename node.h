#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol439
{
    struct TrieNode
    {
        vector<int> indexes;
        vector<TrieNode *> children;
        TrieNode() : children(26, nullptr){};
    };
}
#endif