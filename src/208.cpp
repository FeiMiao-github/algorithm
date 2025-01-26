#include <comm.h>

class Trie {
public:
    array<Trie *, 26> m_children;
    bool m_end;

    Trie() : m_end(false) {
        for (int i = 0; i < m_children.size(); i++)
            m_children[i] = nullptr;
    }

    void insert(string s) {
        auto node = this;
        for (auto c : s) {
            if (node->m_children[c - 'a'] == nullptr) {
                node->m_children[c - 'a'] = new Trie;
            }
            node = node->m_children[c - 'a'];
        }
        node->m_end = true;
    }

    bool search(string s) {
        auto node = this;
        for (auto c : s) {
            node = node->m_children[c - 'a'];
            if (!node)
                break;
        }
        return node && node->m_end;
    }

    bool startsWith(string prefix) {
        auto node = this;
        for (auto c : prefix) {
            node = node->m_children[c - 'a'];
            if (!node)
                break;
        }
        return node != nullptr;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    ug_check(t.search("apple"), true);
    ug_check(t.search("app"), false);
    ug_check(t.startsWith("app"), true);
    t.insert("app");
    ug_check(t.search("app"), true);
    return 0;
}
