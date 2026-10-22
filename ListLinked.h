#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T>* first;
	    int n;
    public:
	    ListLinked(){
		    first = nullptr;
		    n = 0;
	    }
	    ~ListLinked() override{
		    while(first != nullptr){
			    Node<T>* aux = first->next;
			    delete first;
			    first = aux;
		}
	    }
	    
	    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango en insert()");
        }

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango en remove()");
        }

        Node<T>* to_delete;
        if (pos == 0) {
            to_delete = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            to_delete = prev->next;
            prev->next = to_delete->next;
        }

        T data = to_delete->data;
        delete to_delete;
        n--;
        return data;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango en get()");
        }

        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    int search(T e) override {
        Node<T>* aux = first;
        int index = 0;
        while (aux != nullptr) {
            if (aux->data == e) {
                return index;
            }
            aux = aux->next;
            index++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        return get(pos);
    }
    
    friend std::ostream&operator<<(std::ostream &out, ListLinked &list){
	    out << "[";
	    Node<T>* aux = list.first;
	    while (aux != nullptr){
		    out << aux->data;
		    if (aux ->next != nullptr){
			    out << ", ";
		    }
		    aux = aux->next;
            }
	    out << "]";
	    return out;
    }

};

#endif
