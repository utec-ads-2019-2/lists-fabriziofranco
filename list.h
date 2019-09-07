#ifndef LIST_H
#define LIST_H

#include "node.h"
template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        T front(){
            if(this->head!= nullptr)
                return this->head->data;
            throw out_of_range("This list is empty");
        };
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T operator[](int) = 0;

        bool empty(){
            return nodes==0;
        }
        int size(){
            return nodes;
        }
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        ~List() {
            // TODO
        }
};

#endif