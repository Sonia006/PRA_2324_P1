#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
        int n;

    public:
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
    Node<T>* aux = first->next;
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
