#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;
        void resize(int new_size);

    public:
        //Metodos de clase List.h
        void insert(int pos, T e) override;
        void append(T e) override;
        void prepend(T e) override;
        T remove(int pos) override;
        T get(int pos) override;
        int search(T e) override;
        bool empty() override;
        int size() override;

        //Metodos propios
        ListArray();
        ~ListArray();
        T operator[](int pos);
        template <typename U>
        friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);
};

//Metodos propios
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
        throw std::out_of_range("posición inválida");
    }else{
        return arr[pos];
    }
}

template <typename T> 
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    out << "List => [";
    for(int i = 0; i < list.n ; i++){
        out << list.arr[i] << " ";
    }
    out <<"]";
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

//Metodos de clase List.h
template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) 
        throw std::out_of_range("posición inválida");
    if (n == max) 
        resize(max * 2);
    for (int i = n; i > pos; i--) 
        arr[i] = arr[i - 1];
    arr[pos] = e;
    n++;
}

template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}

template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) 
        throw std::out_of_range("posición inválida");
    T valor = arr[pos];
    for (int i = pos; i < n - 1; i++) 
        arr[i] = arr[i + 1];
    n--;
    if (n < max / 4 && max > MINSIZE) 
        resize(max / 2);
    return valor;
}

template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) 
        throw std::out_of_range("posición inválida");
    return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) 
            return i;
    }
    return -1;
}

template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}

template <typename T>
int ListArray<T>::size() {
    return n;
}
