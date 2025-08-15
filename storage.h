#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <QString>

template<typename T>
class Storage
{
private:
    std::vector<T> items;

public:
    // Constructor
    Storage() {}

    // Add an item to storage
    void addItem(const T& item) {
        items.push_back(item);
    }

    // Remove item by index
    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    // Get item by index
    T getItem(int index) {
        if (index >= 0 && index < items.size()) {
            return items[index];
        }
        return T();
    }

    // Get total number of items
    int getSize() {
        return items.size();
    }

    // Search for items by title
    std::vector<T> searchByTitle(const QString& title) {
        std::vector<T> results;
        for (const T& item : items) {
            if (item.getTitle().contains(title, Qt::CaseInsensitive)) {
                results.push_back(item);
            }
        }
        return results;
    }

    // Get all items
    std::vector<T> getAllItems() {
        return items;
    }
};

#endif // STORAGE_H
