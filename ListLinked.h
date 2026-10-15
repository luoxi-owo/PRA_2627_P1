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
		this->first=nullptr;
		this->n=0;
	}

	~ListLinked(){
		if(first==nullptr){}
		else{
			Node<T> aux=first->next;
			while(aux!=nullptr){
				aux=first->next;
				delete first;
				first=aux;
			}
		}
	}

	T operator[] (int pos){
		if(pos<0 || pos> n-1){
			throw std::out_of_range ("Fuera de rango");
		}else{
			return first(pos)->data;
		}
	}

	friend std::ostream& operator<<(std::ostream &out,ListLinked &list){
		Node<T> aux=list.first;
		while(aux!=nullptr){
			out << aux->data << " ";
			aux=aux->next;
		}
		return out;
	}
};

#endif // LIST_LINKED_H 
