#include "storage.h"

#include "book.h"
#include "magazine.h"

template<typename T>

storage<T>::storage() {}

// Add an item to storage
template<typename T>
void storage<T>::addItem(const T& item)
{
    items.push_back(item);
}

// Remove item by index
template<typename T>
void storage<T>::removeItem(int index)
{
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
    }
}

// Get item by index
template<typename T>
T storage<T>::getItem(int index)
{
    if (index >= 0 && index < items.size()) {
        return items[index];
    }
    return T();
}

// Get total number of items
template<typename T>
int storage<T>::getSize()
{
    return items.size();
}

// Search for items by title
template<typename T>
std::vector<T> storage<T>::searchByTitle(const QString& title)
{
    std::vector<T> results;
    for (const T& item : items) {
        if (item.getTitle().contains(title, Qt::CaseInsensitive)) {
            results.push_back(item);
        }
    }
    return results;
}

// Get all items
template<typename T>
std::vector<T> storage<T>::getAllItems()
{
    return items;
}

template class storage<book>;
template class storage<Magazine>;

