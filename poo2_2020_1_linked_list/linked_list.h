#ifndef POO2_2020_1_LINKED_LIST_LINKED_LIST_H
#define POO2_2020_1_LINKED_LIST_LINKED_LIST_H

#include <cctype>
#include <iostream>
using namespace std;

namespace  utec {
    struct node_t {
        int value = 0;
        node_t* next_ = nullptr;
    };

    inline namespace first {
        class linked_list_t {
        private:
            node_t* head = nullptr;
            node_t* tail = nullptr;
            size_t size = 0;
        public:
            // constructors
            linked_list_t() = default;
            linked_list_t(const linked_list_t& other);
            linked_list_t&operator=(const linked_list_t& other);
            linked_list_t(linked_list_t&& other) noexcept ;
            linked_list_t&operator=(linked_list_t&& other) noexcept ;

            // destructors
            ~linked_list_t();

            // add operations
            void push_front(int value);
            void push_back(int value);
            void insert(size_t index, int value);

            // remove operations
            void pop_front();
            void pop_back();
            void erase(size_t index);

            //traverse operations
            int& item(size_t index);
            const int& item(size_t index) const;

            // get size
            size_t length () const {return size;}

            //getters
            node_t* get_tail() const {return tail;}
            node_t* get_head() const { return  head;}

            //utility
            void print();
            bool isEmpty() { return size == 0; }

        };
    }
}


#endif //POO2_2020_1_LINKED_LIST_LINKED_LIST_H
