#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE;
        void resize(int new_size) override;

    public:
        ListArray() override;
        ~ListArray() override;
        T operator[](int pos) override;
        template <typename U>
        friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);
};

template <typename T> 
ListArray<T>::ListArray(){
    arr = new T[MINSIZE]; 
    max = MINSIZE;       
    n = 0;
}

template <typename T> 
ListArray<T>::~ListArray(){
    delete[] arr;
}

template <typename T> 
T ListArray<T>::operator[](int pos){
    if(pos > (n - 1) || pos < 0){
        throw std::out_of_range("mensaje descriptivo");
    }else{
        return arr[pos];
    }
}

template <typename T> 
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    for(int i = 0; i < list.n ; i++){
        out << list.arr[i] << " ";
    }
    return out;
}

template <typename T> 
void ListArray<T>::resize(int new_size){
    T* nuevo = new T[new_size];
    for(int i = 0; i < n; i++){
        nuevo[i] = arr[i];
    }
    delete[] arr;
    arr = nuevo;
    max = new_size;
}
