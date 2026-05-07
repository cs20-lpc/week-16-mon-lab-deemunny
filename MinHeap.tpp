template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (i > 0 && data.at(i) < data.at(parent(i))) {
        // int parentIndex = parent(i);
        int p = parent(i);
        swap(data.at(i),data.at(p));
        i = p;  
        print();      
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    while (left(i) < size()) {  // check left index is within bounds, otherwise no children
        int leftIndex = left(i);
        int rightIndex = right(i);
        int smolIndex = i;

        if (data.at(leftIndex) < data.at(smolIndex)) smolIndex = leftIndex;
        if (rightIndex < size() && data.at(rightIndex) < data.at(smolIndex)) smolIndex = rightIndex;

        if (smolIndex == i) return;
        else {
            swap(data.at(smolIndex),data.at(i));
            i = smolIndex;
        }
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    print();
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    if (size() == 0) throw runtime_error("Heap is empty, cannot remove root");
    
    T rootValue = data.front();
    // TODO: Implement removing the root element.
    // if (size() == 1) {
    //     data.pop_back();
    //} 
    
    swap(data.at(0), data.back());
    data.pop_back();        
    siftDown(0);
    print();

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    if (index == size() - 1) { // removing last item, just delete
        data.pop_back();
        print();
        return;
    }



    swap(data.at(index), data.back());
    data.pop_back();

    if (size() == 0) return;

    // TODO: Attempt sift-up then 
    siftUp(index);
    // sift-down to restore heap property
    siftDown(index);
    print();
}

template <typename T>
void MinHeap<T>::print() const {
    for (T x : data)
        cout << x << " ";
        cout << endl;
}