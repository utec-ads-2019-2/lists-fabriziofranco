#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
public:
    ForwardList() : List<T>() {}

    T back() {
        if(this->tail!= nullptr)
            return this->tail->data;
        throw out_of_range("This list is empty");
    }

    void push_front(T value) {
        auto nodo_nuevo=new Node<T>();
        nodo_nuevo->data=value;
        nodo_nuevo->next=this->head;
        if(this->head==nullptr)
            this->tail=nodo_nuevo;
        this->head=nodo_nuevo;
        this->nodes++;
    }

    void push_back(T value) {
        auto nodo_nuevo=new Node<T>();
        nodo_nuevo->data=value;
        if(this->head==nullptr)
            this->head=this->tail=nodo_nuevo;
        else{
            this->tail->next=nodo_nuevo;
            this->tail=nodo_nuevo;}
        this->nodes++;
    }

    void pop_front() {
        if(this->head!= nullptr){
            auto temp=this->head;
            this->head=this->head->next;
            delete temp;
            this->nodes--;
            if(this->nodes==0)
                this->tail= nullptr;}
    }

    void pop_back() {
        if(this->nodes!=0){
            auto temp=this->tail; auto temp2=this->head;
            while(temp2->next!=temp && this->nodes!=1){
                    temp2=temp2->next;
            }
            this->tail=temp2;
            this->tail->next= nullptr;
            delete temp;
            this->nodes--;
            if(this->nodes==0){
                this->head=nullptr;
                this->tail=nullptr;}
        }
    }

    T operator[](int index) {
        if(this->head!= nullptr && index<this->nodes){
            auto contador=0;
            auto temp=this->head;
            while(contador!=index){
                temp=temp->next;
                contador++;
            }
            return temp->data;
        }
        throw out_of_range("This index doesnt exist");
    }


    void reverse() {
        if(this->nodes>1){
            Node<T>* anterior= nullptr;
            Node<T>* actual= this->head;
            Node<T>* siguiente= actual->next;
            while(actual!= nullptr){
                actual->next=anterior;
                anterior=actual;
                actual=siguiente;
                if(siguiente!= nullptr)
                    siguiente=siguiente->next;}
            Node<T>* temporal= this->head;
            this->head=this->tail;
            this->tail=temporal;}
    }

    string name() {
        return "Forward List";
    }

    ForwardIterator<T> begin(){
        return ForwardIterator<T> (this->head);
    }

    ForwardIterator<T> end(){
        return ForwardIterator<T> (this->tail->next);
    }

    void merge(ForwardList<T> list) {
        for(int i=0;i<list.size();i++){
            this->push_back(list[i]);
        }
    }
};

#endif



