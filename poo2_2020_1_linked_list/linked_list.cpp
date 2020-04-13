#include "linked_list.h"

utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    size = 0;
    auto actual  = other.get_head();
    for (size_t i = 0; i < other.length(); i++){
        this->push_back(actual -> value);
        actual = actual -> next_;
    }
}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    while (!this -> isEmpty())
        this->pop_back();
    size = 0;
    auto actual  = other.get_head();
    for (size_t i = 0; i < other.length(); i++){
        this->push_back(actual -> value);
        actual = actual -> next_;
    }
    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t&& other) noexcept {
    size = other.size;
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t&& other) noexcept {
    while (!this -> isEmpty())
        this->pop_back();
    size = other.size;
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
    return *this;
}

utec::first::linked_list_t::~linked_list_t() {
    head = nullptr;
    tail = nullptr;
}

void utec::first::linked_list_t::push_front(int value) {
    head = new node_t{value, head};
    if (tail == nullptr) tail = head;
    size ++;
}

void utec::first::linked_list_t::push_back(int value) {
    auto node = new node_t{value, nullptr};
    if (tail != nullptr) tail -> next_ = node;
    tail = node;
    if (head == nullptr) head = tail;
    size++;
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if (index >= size){
        cout << "Index out of range" << endl;
        return;
    }
    if (index == 0){
        cout << "Can't insert at head. Try push_front method" << endl;
        return;
    }
    auto actual = head;
    for (size_t i = 1; i <= index; ++i){
        if (i == index) {
            auto node = new node_t{value, actual->next_};
            actual -> next_ = node;
            break;
        }
        actual = actual -> next_;
    }
    size++;
}

void utec::first::linked_list_t::pop_front() {
    if (head == tail){
        delete head;
        head = tail = nullptr;
        size = 0;
    }
    else {
        auto next = head -> next_;
        delete head;
        head = next;
        size--;
    }
}

void utec::first::linked_list_t::pop_back() {
    if (head == tail){
        delete tail;
        tail = head = nullptr;
        size = 0;
    }
    else {
        auto actual = head;
        for (size_t i = 1; i < size; i++){
            if (i + 1 == size){
                delete tail;
                tail = actual;
                size--;
            }
            actual = actual -> next_;
        }
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    if (index >= size){
        cout << "Index out of range" << endl;
        return;
    }
    if (index == 0){
        cout << "Can't erase head. Try pop_front method" << endl;
        return;
    }
    if (index == size-1){
        cout << "Can't erase tail. Try pop_back method" << endl;
        return;
    }
    auto actual = head;
    for (size_t i = 0; i < index; i++) {
        if (i + 1 == index) {
            auto aux = actual -> next_ -> next_;
            delete actual->next_;
            actual -> next_= aux;
            size--;
        }
        actual = actual -> next_;
    }
}

int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head;
    while (index --)
        actual = actual->next_;

    return actual -> value;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head;
    while (index --)
        actual = actual -> next_;
    return actual -> value;
}

void utec::first::linked_list_t::print() {
    for (size_t i = 0; i < size; i++) {
        cout << "Item " << i << ": " << this -> item(i) << endl;
    }
}


