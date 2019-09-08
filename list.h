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
        void clear(){
            while(this->nodes!=0){
                pop_front();
            }
        }
        void sort(){
            if(this->head!= nullptr){
                T desordenado[this->nodes];
                auto temp=this->head;
                for(int i=0;i<this->nodes;i++){
                    desordenado[i]=temp->data;
                    temp=temp->next;}

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
        void print(){
            auto temp= this->head;
            for(int i=0;i<this->nodes;i++){
                cout<<this->operator[](i)<<" ";
            }
            cout<<endl;
        }
        virtual void reverse() = 0;
        virtual string name() = 0;
        ~List() {
            // TODO
        }
};

#endif