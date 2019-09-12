#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

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
            else{
                this->head->prev=nodo_nuevo;}
            this->head=nodo_nuevo;
            this->nodes++;
        }

        void push_back(T value) {
            auto nodo_nuevo=new Node<T>();
            nodo_nuevo->data=value;
            if(this->head== nullptr){
                this->head=nodo_nuevo;}
            else{
                nodo_nuevo->prev=this->tail;
                this->tail->next=nodo_nuevo;}
            this->tail=nodo_nuevo;
            this->nodes++;
        }

        void pop_front() {
            if(this->head!= nullptr){
                auto temp=this->head;
                this->head=this->head->next;
                delete temp;
                this->nodes--;
                if(this->nodes==0){
                    this->tail= nullptr;
                }
                else{
                this->head->prev= nullptr;}
            }
        }

        void pop_back() {
            if(this->head!= nullptr){
                auto temp=this->tail;
                this->tail=this->tail->prev;
                delete temp;
                this->nodes--;
                if(this->nodes==0){
                    this->head= nullptr;
                }
                else{
                    this->tail->next= nullptr;}
            }}

        T operator[](int index) {
            if(this->head!= nullptr && index<this->nodes){
                auto contador=0;
                auto temp=this->head;
                if(index<=(this->size()/2)){
                    while(contador!=index){
                        temp=temp->next;
                        contador++;
                    }
                }
                else{
                    temp=this->tail;
                    while((index+contador)<this->size()-1){
                        temp=temp->prev;
                        contador++;
                    }
                }

                return temp->data;
            }
            throw out_of_range("This index doesnt exist");}

        void reverse() {
            if(this->nodes>1){
                Node<T>* anterior= nullptr;
                Node<T>* actual= this->head;
                Node<T>* siguiente= actual->next;
                while(actual!= nullptr){
                    actual->next=anterior;
                    actual->prev=siguiente;
                    anterior=actual;
                    actual=siguiente;
                    if(siguiente!= nullptr)
                        siguiente=siguiente->next;}
                Node<T>* temporal= this->head;
                this->head=this->tail;
                this->tail=temporal;}
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T> (this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T> (this->tail->next);
        }

        void merge(LinkedList<T> list) {
            for(int i=0;i<list.size();i++){
            this->push_back(list[i]);}
            }
};

#endif