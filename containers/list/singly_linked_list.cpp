#include <stdexcept>
#include <string>
namespace bac {

template<class T>
class singly_linked_list
{
public:
    singly_linked_list();
    //singly_linked_list(const singly_linked_list& other);
    //operator=(const singly_linked_list& other);
    ~singly_linked_list();
    //T* front();
    //T* back();
    //assign(const int& count, const T& value);
    void clear();
    void resize(const int& index, const T& data = T());
    void push_back(const T& data);
    void pop_back();
    void push_front(const T& data);
    void pop_front();
    void insert(const T& data, const int& index); // Index should be int to avoid overflow size_t with negative values.
    void remove_at(const int& index);
    //void swap(singly_linked_list& other);
    //void merge(singly_linked_list& other);
    //void reverse();
    //void sort();
    //void remove(const T& value);
    //template< class UnaryPredicate > void remove_if(UnaryPredicate p);
    size_t size() const { return this->list_size; }
    T const & operator[](const size_t& index) const;
    T& operator[](const size_t& index);

private:
    class node
    {
    public:

        node(const T& data = T(), node* pnext = nullptr)
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

    int list_size;
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
        this->pop_front();
    }
}
template<class T>
void singly_linked_list<T>::resize(const int& index, const T& data)
{
    if (index == 0) {
        this->clear();
    } else if (index < 0) {
        throw (std::invalid_argument(std::string("index cannot be negative")));
    } else if (index > this->list_size) {
        while (index > this->list_size)
        {
            this->push_back(data);
        }
    } else if (index < this->list_size) {
        while (index < this->list_size)
        {
            this->pop_back();
        }
    }
}

template<class T>
void singly_linked_list<T>::push_back(const T& data)
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
void singly_linked_list<T>::pop_back()
{
    if (list_size > 0) {
        this->remove_at(list_size - 1);
    }
}

template<class T>
void singly_linked_list<T>::push_front(const T& data)
{
    node* pnew_node = new node(data, this->phead);
    this->phead = pnew_node;
    ++list_size;
}

template<class T>
void singly_linked_list<T>::pop_front()
{
    if (list_size != 0) {
        node* temp = phead;
        this->phead = phead->pnext;
        delete temp;
        list_size--;
    }
}

template<class T>
void singly_linked_list<T>::insert(const T& data, const int& index)
{
    if (index == 0) {
        this->push_front(data);
    } else if (index < 0){
        throw (std::invalid_argument("index cannot be negative"));
    } else {

        if (index - list_size) {
            this->resize(index);
        }
        node* pprevious = this->phead;
        for (int i(0); i < index - 1; ++i) //index should be int to avoid overflow size_t with negative values.
        {
            pprevious = pprevious->pnext;
        }


        pprevious->pnext = new node(data, pprevious->pnext);
        ++list_size;
    }
}
template<class T>
void singly_linked_list<T>::remove_at(const int& index)
{
    if (index == 0) {
        this->pop_front();
    } else if (index < 0) {
         throw (std::invalid_argument("index cannot be negative"));
    } else if (this->list_size == 0 || this->list_size <= index) {
         throw (std::out_of_range("out of range"));
    } else {
        size_t counter = 0;
        node* pcurrent = this->phead;
        while (counter < index - 1) {
            pcurrent = pcurrent->pnext;
            counter++;
        }
        node* prequired_node = pcurrent->pnext;
        pcurrent->pnext = prequired_node->pnext;
        delete prequired_node;
        this->list_size--;
    }
}
// For const cast realization
template<class T>
T const & singly_linked_list<T>::operator[](const size_t& index) const
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
T& singly_linked_list<T>::operator[](const size_t& index)
{
    return const_cast<T&>(const_cast<const singly_linked_list<T>& >(*this)[index]);
}


} //namespace bac
