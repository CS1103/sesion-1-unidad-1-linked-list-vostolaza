#include <iostream>
#include <cassert>
#include <string>
#include "linked_list.h"

using namespace std;

int main() {

    utec::linked_list_t ll;

    // Probar el metodo push_front
    for (int i = 0; i < 10; ++i) {
        ll.push_front(i);
    }
    // Verifico el tamano
    assert(ll.length() == 10);

    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");

    // Probar el metodo pop_front
    for(int i = 0; i < 5; ++i){
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.length() == 5);
    // Probar el metodo pop_front
    for(int i = 0; i < 5; ++i){
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.length() == 0);

    // Probar el metodo push_back
    for (int i = 0; i < 10; ++i) {
        ll.push_back(i);
    }
    // Verifico el tamano
    assert(ll.length() == 10);

    result = "";
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "0 1 2 3 4 5 6 7 8 9 ");

    // Probar el metodo pop_back
    for(int i = 0; i < 5; ++i){
        ll.pop_back();
    }
    // Verifico el tamano
    assert(ll.length() == 5);

    // Probar el metodo insert
    ll.insert(3, 8);
    result = "";
    for (size_t i = 0; i < ll.length(); ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "0 1 2 8 3 4 ");

    // Probar el metodo erase
    ll.erase(3);
    result = "";
    for (size_t i = 0; i < ll.length(); ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "0 1 2 3 4 ");

    // Probar el operador copy
    utec::linked_list_t lcopy1;
    lcopy1 = ll;
    result = "";
    for (size_t i = 0; i < lcopy1.length(); ++i) {
        result += to_string(lcopy1.item(i)) + " ";
    }
    assert(result == "0 1 2 3 4 ");

    // Probando el constructor copy
    utec::linked_list_t lcopy2(ll);
    result = "";
    for (size_t i = 0; i < lcopy2.length(); ++i) {
        result += to_string(lcopy2.item(i)) + " ";
    }
    assert(result == "0 1 2 3 4 ");

    // Probando el constructor move

    utec::linked_list_t lmove = move(ll);
    result = "";
    for (size_t i = 0; i < lmove.length(); ++i) {
        result += to_string(lmove.item(i)) + " ";
    }
    assert(result == "0 1 2 3 4 ");




    cout << "Ejecucion Exitosa" << endl;
    return 0;
}