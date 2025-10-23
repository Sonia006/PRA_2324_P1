#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
        int n;

    public:
        void insert(int pos, T e) override;
        void append(T e) override;
        void prepend(T e) override;
        T remove(int pos) override;
        T get(int pos) override;
        int search(T e) override;
        bool empty() override;
        int size() override;

        ListLinked();
        ~ListLinked();
        T operator[](int pos);

        template <typename U>
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<U> &list);
};

template <typename T>
ListLinked<T>::ListLinked(){
    this->first = nullptr;
    this->n = 0; 
}

template <typename T>
ListLinked<T>::~ListLinked(){
    while(first != nullptr){
        Node<T>* aux = first->next;
        delete first;
        first = aux;
    }
}

template <typename T>
T ListLinked<T>::operator[](int pos){
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición fuera de rango");
    }
    Node<T>* aux = first;
    for(int i = 0; i < pos; i++){
        aux = aux->next;
    }
    return aux->data;
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
    Node<T>* aux = list.first;
    out << "List => [";
    while (aux != nullptr) {
        out << aux->data << " ";
        aux = aux->next;
    }
    out << "]";
    return out;
}

template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) 
        throw std::out_of_range("posición inválida");
    Node<T>* nuevo = new Node<T>(e);
    Node<T>* aux = first;
    if(pos == 0){
        nuevo->next = first;
        first = nuevo;
    }else{
        for(int i = 0; i < pos - 1; i++){
            aux = aux->next;
        }
        nuevo->next = aux->next;
        aux->next = nuevo;
    }
    n++;
}

template <typename T>
void ListLinked<T>::append(T e) {
    insert(n, e);
}

template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= n) 
        throw std::out_of_range("posición inválida");
    Node<T>* aux = first;
    Node<T>* borrar;
    T valor;
    if(pos == 0){
        borrar = first;
        first = first->next;
    }else{
        for(int i= 0; i < pos - 1; i++){
            aux = aux->next;
        }
        borrar = aux->next;
        aux->next = borrar->next;
    }
    valor = borrar->data;
    delete borrar;
    n--;
    return valor;
    
}

template <typename T>
T ListLinked<T>::get(int pos) {
    if (pos < 0 || pos >= n) 
        throw std::out_of_range("posición inválida");
    Node<T>* aux = first;
    for(int i = 0; i < pos; i++){
        aux = aux->next;
    }
    return aux->data;
}

template <typename T>
int ListLinked<T>::search(T e){
    Node<T>* aux = first;
    int pos = 0;
    while (aux != nullptr) {
        if (aux->data == e)
            return pos;
        aux = aux->next;
        pos++;
    }
    return -1;
}


template <typename T>
bool ListLinked<T>::empty() {
    return n == 0;
}

template <typename T>
int ListLinked<T>::size() {
    return n;
}
