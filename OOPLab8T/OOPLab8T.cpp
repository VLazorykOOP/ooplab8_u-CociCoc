// OOPLab8T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

template<typename T>
class LinkedList {
private:
    // Структура вузла списку
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head; // Початковий вузол списку
    int size; // Розмір списку
    
public:
    		// Конструктор за замовчуванням
    LinkedList() : head(nullptr), size(0) {}
    
   		 // Деструктор
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        size = 0;
    }
    
    // Повертає розмір списку
    int getSize() const {
        return size;
    }
  	  
  			  // Перевіряє, чи є список порожнім
    bool isEmpty() const {
        return head == nullptr;
    }
    
    		// Додає новий елемент до початку списку
    void addFirst(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
   			 // Додає новий елемент до кінця списку
    void addLast(const T& value) {
        if (isEmpty()) {
            addFirst(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        size++;
    }
    
    			// Видаляє елемент з початку списку
    void removeFirst() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        size--;
    }
    
   			 // Видаляє елемент з кінця списку
    void removeLast() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        if (getSize() == 1) {
            removeFirst();
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        size--;
    }
    
   			 // Повертає значення елемента з початку списку
    const T& getFirst() const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }
    
    				// Повертає значення елемента з кінця списку
    const T& getLast() const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }
};


