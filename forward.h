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

    void clear() {
        while(this->nodes!=0){
            pop_back();
    }}

    void sort() {
        if(this->head!= nullptr){
            T desordenado[this->nodes];
            auto temp=this->head;
            for(int i=0;i<this->nodes;i++){
                desordenado[i]=temp->data;
                temp=temp->next;
            }
            for(size_t numero_de_iteracion=0;numero_de_iteracion<this->nodes;numero_de_iteracion++){
                int id_del_minimo_elemento=numero_de_iteracion;
                for(size_t primer_elemento_considerado=numero_de_iteracion;primer_elemento_considerado<this->nodes;primer_elemento_considerado++){
                    if(desordenado[primer_elemento_considerado]<desordenado[id_del_minimo_elemento])
                        id_del_minimo_elemento=primer_elemento_considerado;
                }
                swap(desordenado[numero_de_iteracion],desordenado[id_del_minimo_elemento]);
            }
            temp=this->head;
            for(int i=0;i<this->nodes;i++){
                temp->data=desordenado[i];
                temp=temp->next;
            }

        }
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

    ForwardIterator<T> begin() {
        // TODO
    }

    ForwardIterator<T> end() {
        // TODO
    }

    void merge(ForwardList<T> list) {
        for(int i=0;i<list.size();i++){
            this->push_back(list[i]);
        }
    }
};

#endif



