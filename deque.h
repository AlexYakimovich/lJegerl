#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

template <class InfoType>

class deque
{
private:

    struct QItem
    {
        InfoType info;
        QItem* next;
        QItem* prev;
        QItem(InfoType Ainfo) : info(Ainfo), prev(nullptr), next(nullptr) {}
    };

    QItem* first, * last;
    unsigned size;

    void Erase();
    void Clone(const deque& D);
    InfoType GetElement(int);
    bool Empty() const;

public:

    const InfoType GetFirst() const;
    const InfoType GetLast() const;
    unsigned GetSize();

    deque();
    deque(const deque&);
    ~deque();

    friend ostream& operator << (ostream&, const deque<InfoType>&);
    ostream& Print(ostream&);
    ostream& PrintReverse(ostream&);

    deque& operator = (const deque&);


    void PushLast(InfoType);
    bool PopLast();
    void PushFirst(InfoType);
    bool PopFirst();

    void dsort();
};




template <class InfoType>
bool deque <InfoType> ::Empty() const {
    if (first == nullptr)
        return true;
    return false;
}

template <class InfoType>
const InfoType deque <InfoType> ::GetFirst() const
{
    if (Empty())
    {
        throw runtime_error("Ïóñòîé äåê");
    }

    return first->info;
}
template <class InfoType>
const InfoType deque <InfoType> ::GetLast() const
{
    if (Empty())
    {
        throw runtime_error("Ïóñòîé äåê");
    }

    return last->info;
}
template <class InfoType>
ostream& operator << (ostream& s, const deque<InfoType>& D)
{

    for (int i = 0; i < D.size; i++)
    {
        s << D.getElement(i) << " ";
    }
    s << endl;
    for (int i = D.size - 1; i >= 0; i--)
    {
        s << D.getElement(i) << " ";
    }
    s << endl;

    return s;
}



template <class InfoType>
void deque <InfoType> ::Erase() {
    while (PopLast());
    size = 0;
}

template <class InfoType>
void deque <InfoType> ::Clone(const deque<InfoType>& D) {
    QItem* tmp = D.last;
    for (unsigned i = 0; i < D.size; i++)
    {
        PushLast(tmp->info);
        tmp = tmp->next;
    }
}

template <class InfoType>
InfoType deque <InfoType> ::GetElement(int number) {
    if (!Empty()) {
        QItem* tmp = last;
        for (int i = 0; i < number; i++)
        {
            tmp = tmp->next;
        }

        return tmp->info;
    }
    else {
        return NULL;
    }
}


template <class InfoType>
deque <InfoType> ::deque() : first(nullptr), last(nullptr), size(0) {

}

template <class InfoType>
deque<InfoType> ::deque(const deque<InfoType>& D) {
    size = 0;
    Clone(D);
}

template <class InfoType>
deque <InfoType> :: ~deque() {
    Erase();
}

template <class InfoType>
void deque <InfoType>::PushLast(InfoType Ainfo) {
    QItem* tmp = new QItem(Ainfo);
    if (size > 0)
    {
        tmp->prev = first;
        first->next = tmp;
    }
    else
    {
        last = tmp;
    }
    first = tmp;
    size++;
}
template <class InfoType>
void deque <InfoType>::PushFirst(InfoType Ainfo) {
    QItem* tmp = new QItem(Ainfo);
    if (size > 0)
    {
        tmp->next = last;
        last->prev = tmp;
    }
    else
    {
        first = tmp;
    }
    last = tmp;
    size++;
}

template <class InfoType>
bool deque <InfoType>::PopLast() {
    if (size == 0) {
        return false;
    }
    QItem* tmp = first;
    if (size > 1) {
        first = first->prev;
    }
    delete tmp;
    size--;
    first->next = nullptr;
    if (size == 0)
    {
        first = nullptr;
        last = nullptr;
    }
    return true;
}

template <class InfoType>
bool deque <InfoType>::PopFirst() {
    if (size == 0) {
        return false;
    }
    QItem* tmp = last;
    last = last->next;
    delete tmp;
    size--;
    if (last) {
        last->prev = nullptr;
    }
    if (size == 0)
    {
        first = nullptr;
        last = nullptr;
    }
    return true;
}
template <class InfoType>
deque<InfoType>& deque <InfoType>::operator = (const deque<InfoType>& D) {
    if (this != &D)
    {
        Erase();
        Clone(D);
    }
    return *this;

}

template <class InfoType>
unsigned deque <InfoType>::GetSize() {
    return size;
}

template<class InfoType>
ostream& deque<InfoType>::Print(ostream& s) {
    for (int i = 0; i < size; i++)
    {
        s << GetElement(i) << " ";
    }
    s << endl;
    return s;
}
template <class InfoType>
ostream& deque <InfoType> ::PrintReverse(ostream& s) {
    for (int i = size - 1; i >= 0; i--)
    {
        s << GetElement(i) << " ";
    }
    s << endl;
    return s;
}

template <class InfoType>
void deque <InfoType>::dsort() {
    vector <InfoType> massive;
    int dsize = size;
    for (int i = 0; i < dsize; i++)
    {
        massive.push_back(last->info);
        PopFirst();
    }
    sort(massive.rbegin(), massive.rend());
    for (int i = 0; i < dsize; i++)
    {
        InfoType tmp = massive[i];
        PushFirst(tmp);
    }
}

