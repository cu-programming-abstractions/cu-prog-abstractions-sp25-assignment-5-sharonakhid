#pragma once

#include "HashFunction.h"
#include "Demos/Utility.h"
#include "GUI/SimpleTest.h"
#include "GUI/MemoryDiagnostics.h"
#include <string>

class LinearProbingHashTable {
public:
    LinearProbingHashTable(HashFunction<std::string> hashFn);
    ~LinearProbingHashTable();

    bool isEmpty() const;
    int size() const;
    bool insert(const std::string& key);
    bool contains(const std::string& key) const;
    bool remove(const std::string& key);

private:
    enum class SlotType {
        EMPTY = 0x106B, FILLED = 0x107, TOMBSTONE = 0x103
    };

    struct Slot {
        std::string value;
        SlotType type;
        TRACK_ALLOCATIONS_OF(Slot);
    };

    Slot* elems = nullptr;
    HashFunction<std::string> hashFn;
    int size_ = 0;  // Renamed from `size`

    DISALLOW_COPYING_OF(LinearProbingHashTable);
    ALLOW_TEST_ACCESS();
    MAKE_PRINTERS_FOR(SlotType);
    MAKE_PRINTERS_FOR(Slot);
    MAKE_COMPARATORS_FOR(Slot);
};

