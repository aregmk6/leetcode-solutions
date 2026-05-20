// Definition for a Node.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node
{
  public:
    int val;
    Node* next;
    Node* random;

    Node(int val_) : val(val_), next(nullptr), random(nullptr)
    {
    }
};

class Solution
{
    static constexpr int MAX_N = 1000;

    using OldNodePtr = Node*;
    using NewNodePtr = Node*;

    unordered_map<OldNodePtr, NewNodePtr> copied{};

    void rec(Node* target, Node* new_slot)
    {
        if (!target) {
            return;
        }

        Node* new_next;
        Node* new_rand;

        copied[target] = new_slot;

        if (target->next) {
            auto next_it = copied.find(target->next);
            if (next_it == copied.end()) {
                new_next = new Node{target->next->val};
                rec(target->next, new_next);
            } else {
                new_next = next_it->second;
            }
            new_slot->next = new_next;
        } else {
            new_slot->next = nullptr;
        }

        if (target->random) {
            auto rand_it = copied.find(target->random);
            if (rand_it == copied.end()) {
                new_rand = new Node{target->random->val};
                rec(target->random, new_rand);
            } else {
                new_rand = rand_it->second;
            }
            new_slot->random = new_rand;
        } else {
            new_slot->random = nullptr;
        }
    }

  public:
    Node* copyRandomList(Node* head)
    {
        if (!head) {
            return nullptr;
        }

        Node* new_head = new Node{head->val};
        rec(head, new_head);

        return new_head;
    }
};

struct Pair {
    int val;
    int rand;
};

Node* generator(vector<Pair> nodes)
{
    Node* head = new Node{nodes[0].val};
    Node* cur  = head;
    for (int i = 1; i < nodes.size(); ++i) {
        Node* n   = new Node{nodes[i].val};
        cur->next = n;
        cur       = cur->next;
    }

    cur = head;
    for (int i = 0; i < nodes.size(); ++i) {
        Node* point_to;
        int rand_idx = nodes[i].rand;
        if (rand_idx == -1) {
            point_to = nullptr;
        } else {
            point_to = head;
            for (int j = 0; j < rand_idx; ++j) {
                point_to = point_to->next;
            }
        }

        cur->random = point_to;
        cur         = cur->next;
    }

    return head;
}

int main()
{
    vector<Pair> gen{{{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}}};
    Node* list = generator(gen);

    Node* cur = list;
    while (cur) {
        cout << "[" << cur->val << ", " << cur->random << "]";
        cur = cur->next;
    }

    cout << endl;

    Solution s;

    Node* copy = s.copyRandomList(list);

    cur = copy;
    while (cur) {
        cout << "[" << cur->val << ", " << cur->random << "]";
        cur = cur->next;
    }

    cout << endl;

    return 0;
}
