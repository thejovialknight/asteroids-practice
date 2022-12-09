#pragma once
#include "table.h"
#include <iostream>

template<typename T>
struct Handle {
    Table<T>* table = nullptr;
    int lookup_index = -1;
    
    Handle() {}
    Handle(Table<T>& table, int lookup_index) { link(table, lookup_index); }
    Handle(Table<T>& table, T value) { link(table, value); }
    // For handle to existing table data
    void link(Table<T>& tab, int index) {
        table = &tab;
        lookup_index = index;
    }
    // For handle to new table data
    void link(Table<T>& tab, T value) {
        table = &tab;
        lookup_index = table->add(value);    
    }

    // Returns reference to the data within the table
    T& unwrap() {
        if(table == nullptr) {
            std::cout << "Table not found!" << std::endl;
        }

        if(lookup_index == -1) {
            std::cout << "Handle being accessed is unlinked!" << std::endl;
        }

        return table->at(lookup_index);
    }

    void release() {
        if(table == nullptr) {
            throw "Table not found!";
        }

        table->remove(lookup_index);
        lookup_index = -1;
    }
};

