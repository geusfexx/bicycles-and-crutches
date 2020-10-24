#include <stdexcept>

namespace bac {

template<class T>
class singly_linked_list
{
public:
    singly_linked_list();
    //singly_linked_list(const singly_linked_list& other);
    //operator=(const singly_linked_list& other);
    ~singly_linked_list();
     void clear();
    void push_back(T data);
    void pop_front();
    size_t size() const { return this->list_size; }
    T const & operator[](const size_t index) const;
    T& operator[](const size_t index);
private:
    //template<class T>
    class node
    {
    public:

        node(T data = T(), node* pnext = nullptr)
        {
            this->data = data;
            this->pnext = pnext;
        }
        ~node()
        {
            this->data.~T();
            this->pnext = nullptr;
        }

        node* pnext;
        T data;
    };

    size_t list_size;
    node* phead;
};

template<class T>singly_linked_list<T>::singly_linked_list()
{
    this->list_size = 0;
    this->phead = nullptr;
}

/*
template<class T>singly_linked_list<T>::singly_linked_list(const singly_linked_list& other)
{
    this->list_size = other->list_size;
    //this->phead = ;
}
*/
template<class T>singly_linked_list<T>::~singly_linked_list()
{
    this->clear();
}

template<class T>
void singly_linked_list<T>::clear()
{
    while (this->list_size)
    {
        pop_front();
    }
}

template<class T>
void singly_linked_list<T>::push_back(T data)
{
    if (phead == nullptr) {
        phead = new node(data);
    } else {
        node* pcurrent = this->phead;
        while(pcurrent->pnext != nullptr) {
            pcurrent = pcurrent->pnext;
        }
        pcurrent->pnext = new node(data);
    }
    this->list_size++;
}

template<class T>
void singly_linked_list<T>::pop_front()
{
    node* temp = phead;
    phead = phead->pnext;
    delete temp;
    this->list_size--;
}


// For const cast realization
template<class T>
T const & singly_linked_list<T>::operator[](const size_t index) const
{
    if (this->list_size == 0 || this->list_size <= index) {
        throw (std::out_of_range("out of range"));
    } else {
        size_t counter = 0;
        node* pcurrent = this->phead;
        while (counter != index) {
            pcurrent = pcurrent->pnext;
            counter++;
        }
        return pcurrent->data;
    }
}

template<class T>
T& singly_linked_list<T>::operator[](const size_t index)
{
    return const_cast<T&>(const_cast<const singly_linked_list<T>& >(*this)[index]);
}


} //namespace bac
