#include <iostream>
#include <string>
#include <vector>

struct TrieNode {
  char data;
  TrieNode *children[26];
  bool isEnd;
};

struct NodePrefixPair {
  TrieNode* endingNode;
  std::string prefix;
};

class Trie {
public:
  TrieNode *root;
  TrieNode *makeTrieNode(char data) {
    TrieNode *node = new TrieNode;
    node->data = data;
    node->isEnd = false;
    for (int i = 0; i < 26; i++) {
      node->children[i] = nullptr;
    }
    return node;
  }

  Trie() { root = makeTrieNode('*'); }

  void insert(const std::string &word) {
    TrieNode *node = root;
    for (auto ch : word) {
      if (!node->children[ch - 'a']) {
        node->children[ch - 'a'] = makeTrieNode(ch);
      }
      node = node->children[ch - 'a'];
    }
    node->isEnd = true;
  }

  int numLinks(TrieNode *node) {
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        count++;
      }
    }
    return count;
  }

  std::string findLongestPrefix(const std::string &word) {
    TrieNode *node = root;
    std::string longestPrefix = "";
    for (auto ch : word) {
      if (!node->isEnd && (numLinks(node) == 1) && node->children[ch - 'a']) {
        longestPrefix += node->children[ch - 'a']->data;
      } else {
        break;
      }
      node = node->children[ch - 'a'];
    }
    return longestPrefix;
  }

  NodePrefixPair findPrefixNode(const std::string &prefix) {
    TrieNode *node = root;
    for (auto ch : prefix) {
      if (node->children[ch - 'a']) {
        node = node->children[ch - 'a'];
      } else {
        return {nullptr, prefix};
      }
    }
    return {node, prefix};
  }

  void wordsWithPrefix(std::string &common, const NodePrefixPair& start) {
    if (!start.endingNode) {
      return;
    }

    if (start.endingNode->isEnd) {
      std::cout << start.prefix + common << std::endl;
    }

    for (int i = 0; i < 26; i++) {
      if (start.endingNode->children[i]) {
        common += start.endingNode->children[i]->data;
        wordsWithPrefix(common, {start.endingNode->children[i], start.prefix});
        common.erase(common.end() - 1, common.end());
      }
    }
  }

  bool search(const std::string &word) {
    TrieNode *node = root;
    for (auto ch : word) {
      if (!node->children[ch - 'a']) {
        return false;
      }
      node = node->children[ch - 'a'];
    }
    return node->isEnd;
  }
};

int main() {
  Trie trie;
  trie.insert("wind");
  trie.insert("turbine");
  trie.insert("toxic");
  trie.insert("wild");
  trie.insert("turbulence");
  trie.insert("willow");
  trie.insert("truck");
  trie.insert("trie");
  // std::cout << trie.findLongestPrefix("t") << std::endl;
  NodePrefixPair start = trie.findPrefixNode("tr");
  std::string commonInit = "";
  trie.wordsWithPrefix(commonInit, start);
}
