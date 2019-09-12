#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T back() {
            if(this->head!= nullptr)
                return this->head->prev->data;
            throw out_of_range("This list is empty");
        }

        void push_front(T value) {
            push_back(value);
            this->head=this->head->prev;
        }

         void push_back(T value) {
            auto nodo_nuevo=new Node<T>();
            nodo_nuevo->data=value;
            nodo_nuevo->next=this->head;
            if(this->head!=nullptr){
                this->head->prev->next=nodo_nuevo;
                nodo_nuevo->prev=this->head->prev;
                this->head->prev=nodo_nuevo;}
            else{
                this->head=nodo_nuevo;
                this->head->next=nodo_nuevo;
                this->head->prev=nodo_nuevo;
            }
            this->nodes++;
        }

        void pop_front() {
            if(this->head!= nullptr){
                auto temp=this->head;
                this->nodes--;
                if(this->nodes==0){
                    this->head= nullptr;
                }
                else{
                    this->head->prev->next=this->head->next;
                    this->head->next->prev=this->head->prev;
                    this->head=this->head->next;
                }
                delete temp;
            }
        }


        void pop_back() {
            if(this->head!= nullptr){
                auto temp=this->head->prev;
                this->nodes--;
                if(this->nodes==0){
                    this->head= nullptr;
                }
                else{
                    this->head->prev->prev->next=this->head;
                    this->head->prev=this->head->prev->prev;
                }
                delete temp;
            }
        }


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
                    while((index+contador)<this->size()){
                        temp=temp->prev;
                        contador++;
                    }
                }
                return temp->data;
            }
            throw out_of_range("This index doesnt exist");
        }

        void reverse() {
            if(this->nodes>1){
                Node<T>* anterior= this->head->prev;
                Node<T>* actual= this->head;
                Node<T>* siguiente= actual->next;
                for(int i=0;i<this->size();i++){
                    actual->next=anterior;
                    actual->prev=siguiente;
                    anterior=actual;
                    actual=siguiente;
                    siguiente=siguiente->next;}
                this->head=this->head->next;
            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->head);
        }

        void merge(CircularLinkedList<T> list) {
            for(int i=0;i<list.size();i++){
                this->push_back(list[i]);}
        }
};

#endif