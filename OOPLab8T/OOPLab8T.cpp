// OOPLab8T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };
    
    Node* head;
    int size;
    
public:
    class Iterator {
    private:
        Node* node;
        
    public:
        Iterator(Node* n = nullptr) : node(n) {}
        
        T& operator*() const {
            return node->data;
        }
        
        Iterator& operator++() {
            node = node->next;
            return *this;
        }
        
        bool operator==(const Iterator& other) const {
            return node == other.node;
        }
        
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };
    
    List() : head(nullptr), size(0) {}
    
    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void push_front(const T& data) {
        head = new Node(data, head);
        size++;
    }
    
    void pop_front() {
        if (head == nullptr) {
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    
    int getSize() const {
        return size;
    }
    
    Iterator begin() const {
        return Iterator(head);
    }
    
    Iterator end() const {
        return Iterator(nullptr);
    }
};


#include <iostream>
 
int main() {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    std::cout << "List size: " << list.getSize() << std::endl;
    
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    list.pop_front();
    
    std::cout << "List size after pop: " << list.getSize() << std::endl;
    
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}



