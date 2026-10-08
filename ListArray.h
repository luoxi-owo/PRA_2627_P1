#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T>{
	
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;
		void resize(int new_size){
			int* narr=new int[new_size];
			for(int i=0;i<size();i++){
				narr[i]=arr[i];
			}
			delete[] arr;
			max=new_size;
		}		

	public:
		void insert(int pos, T e)override{
			if(pos<0 || pos>size()-1){
				throw std::out_of_range("Error: Fuera de rango");
			}else{
				if(n>max){
					resize(size()+1);
				}
				int aux1=arr[pos];
				for(int i=pos;i<size()-1;i++){
					int aux2=arr[i+1];
					arr[i+1]=aux1;
					aux1=aux2;
				}
				arr[pos]=e;
			}
		}
		
		void append(T e)override{
			insert(size()-1,e);
		}
		
		void prepend(T e)override{
			insert(0,e);
		}
		
		T remove(int pos)override{	
			if(pos<0 || pos>size()-1){
				throw std::out_of_range("Error: Fuera de rango");
			}else{
				int a=arr[pos];
				for(int i=pos;i<size()-1;i++){
					arr[i]=arr[i+1];
				}
				resize(size()-1);
				return a;
			}
		}
	

			
		T get(int pos)override{
		
			if(pos<0 || pos>size()-1){
				throw std::out_of_range("Fuera de rango");
			}else{
				return arr[pos];
			}
		}

		int search(T e)override{
			for(int i=0;i<size()-1;i++){
				if (arr[i]==e){
					return i;
				}
			}
			return -1;
		}
		
		bool empty()override{
			if(size()==0){
				return true;
			}else{
				return false;
			}
		}
		
		int size()override{
			return n;
		}
		
		ListArray(){
			max=MINSIZE;
			n=0;
			arr= new T[max];

		}

		~ListArray() override{
			delete[] arr;
		}

		T operator[](int pos){
			if(pos<0 || pos>size()-1){
				throw std::out_of_range("Error: fuera de rango");
			}else{
				return arr[pos];
			}
		}

		friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list){
		for(int i=0;i<=list.n;i++){
			out << list.arr[i] << " ";
		}
		return out;
		}



		

};
