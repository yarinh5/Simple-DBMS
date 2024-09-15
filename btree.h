#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <map>
#include <mutex>

// מחלקה לניהול גרסאות
template <typename V>
struct VersionedValue {
    V value;
    int version;

    VersionedValue(const V& val, int ver) : value(val), version(ver) {}
};

// מחלקת B-tree עם תמיכה בגרסאות ונעילה
template <typename K, typename V>
class BTree {
public:
    void insert(const K& key, const V& value) {
        std::lock_guard<std::mutex> lock(treeMutex);
        int currentVersion = getCurrentVersion(key);
        tree[key] = VersionedValue<V>(value, currentVersion + 1);
    }

    bool search(const K& key, V& value) {
        std::lock_guard<std::mutex> lock(treeMutex);
        auto it = tree.find(key);
        if (it != tree.end()) {
            value = it->second.value;
            return true;
        }
        return false;
    }

    bool remove(const K& key) {
        std::lock_guard<std::mutex> lock(treeMutex);
        auto it = tree.find(key);
        if (it != tree.end()) {
            tree.erase(it);
            return true;
        }
        return false;
    }

    bool lockRecord(const K& key) {
        std::lock_guard<std::mutex> lock(treeMutex);
        if (lockedRecords.find(key) == lockedRecords.end()) {
            lockedRecords[key] = true;
            return true;
        }
        return false;
    }

    void unlockRecord(const K& key) {
        std::lock_guard<std::mutex> lock(treeMutex);
        lockedRecords.erase(key);
    }

    int getCurrentVersion(const K& key) {
        auto it = tree.find(key);
        if (it != tree.end()) {
            return it->second.version;
        }
        return 0;  // גרסה ראשונית
    }

private:
    std::map<K, VersionedValue<V>> tree;  // מאגר נתונים עם גרסאות
    std::map<K, bool> lockedRecords;  // שמירה על רשומות נעולות
    std::mutex treeMutex;  // נעילת ה-B-tree בזמן גישה
};

#endif
