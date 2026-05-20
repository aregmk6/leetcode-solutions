#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>

using namespace std;

class LFUCache
{

    struct EntryPtrLs;

    struct Entry {
        int value_;
        int key_;
        size_t counter_;
        list<Entry*>::iterator me_it_;
        list<EntryPtrLs>::iterator my_list_it_;
    };

    struct EntryPtrLs {
        list<Entry*> entries_;
        size_t counter_;
    };

    // [ ] -> [ ] -> ... -> [ ]
    //  ^      ^             ^
    //  0      1             n

    unordered_map<int, Entry> cache_;
    list<EntryPtrLs> lru_list_;

    int capacity_;

    void updateEntCounter(Entry& ent)
    {
        // get stuff ready
        ++ent.counter_;

        auto& my_list_it     = ent.my_list_it_;
        auto& my_list_struct = *my_list_it;

        my_list_struct.entries_.erase(ent.me_it_);
        size_t cur_counter    = my_list_struct.counter_;
        auto next_list_it     = next(my_list_it);
        EntryPtrLs* next_list = nullptr;

        // delete the list if empty
        if (my_list_struct.entries_.empty()) {
            lru_list_.erase(my_list_it);
        }

        if (next_list_it != lru_list_.end() &&
            next_list_it->counter_ > cur_counter + 1) {

            auto it = lru_list_.insert(next_list_it,
                                       EntryPtrLs{.counter_ = cur_counter + 1});
            next_list = &*it;

            // update my list it
            ent.my_list_it_ = it;
        } else if (next_list_it != lru_list_.end() &&
                   next_list_it->counter_ == cur_counter + 1) {
            next_list = &*next_list_it;

            // update my list it
            ent.my_list_it_ = next_list_it;
        } else {
            size_t new_counter = cur_counter + 1;
            lru_list_.push_back({.counter_ = new_counter});
            next_list = &lru_list_.back();

            // update my list it
            ent.my_list_it_ = prev(end(lru_list_));
        }

        next_list->entries_.push_front(&ent);

        // update me it
        ent.me_it_ = next_list->entries_.begin();

        assert(next_list->entries_.front()->counter_ == ent.counter_);
    }

    void insertNewEnt(int key, int value)
    {
        Entry new_ent{.value_ = value, .key_ = key, .counter_ = 0};
        auto p = cache_.insert({key, new_ent});

        if (!p.second) {
            // shouldn't happen
            std::cout << "bad insertion" << std::endl;
            throw;
        }

        Entry* ent_ptr       = &p.first->second;
        EntryPtrLs* ent_list = nullptr;

        if (lru_list_.empty()) {
            lru_list_.push_front({.counter_ = 0});
        }

        ent_list = &lru_list_.front();

        if (ent_list->counter_ > 0) {
            lru_list_.push_front({.counter_ = 0});
            ent_list = &lru_list_.front();
        }

        ent_ptr->my_list_it_ = lru_list_.begin();
        ent_list->entries_.push_front(ent_ptr);

        auto it         = ent_list->entries_.begin();
        ent_ptr->me_it_ = it;
    }

  public:
    LFUCache(int capacity) : capacity_(capacity)
    {
        lru_list_.push_front({.counter_ = 0});
    }

    int get(int key)
    {
        auto it = cache_.find(key);
        if (it == cache_.end()) {
            return -1;
        }
        updateEntCounter(it->second);

        return it->second.value_;
    }

    void put(int key, int value)
    {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            updateEntCounter(it->second);

            it->second.value_ = value;
        } else {
            if (cache_.size() == capacity_) {
                EntryPtrLs& inner_list = lru_list_.front();

                Entry* victim = inner_list.entries_.back();
                inner_list.entries_.pop_back();

                cache_.erase(victim->key_);

                if (inner_list.entries_.empty()) {
                    lru_list_.pop_front();
                }
            }
            insertNewEnt(key, value);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    testSpecificSequence();
    return 0;
}
