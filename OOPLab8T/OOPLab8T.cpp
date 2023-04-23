// OOPLab8T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "example.h"
int main()
{
    int r;       
    std::cout << "Lab 8 \n";
     std::cout << " Run example press 1 \n";
     std::cin >> r; if (r == 1) example();
    #include <iostream>
#include <cstring>
 
template<typename T>
void removeMin(T* array, int size) {
    T minValue = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
        }
    }
    
    int numMinValues = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == minValue) {
            numMinValues++;
        }
    }
    
    T* newArray = new T[size - numMinValues];
    int newIndex = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] != minValue) {
            newArray[newIndex] = array[i];
            newIndex++;
        }
    }
    
    memcpy(array, newArray, (size - numMinValues) * sizeof(T));
    delete[] newArray;
}
 
// Специфікація для типу char*
void removeMin(char** array, int size) {
    char* minValue = array[0];
    for (int i = 1; i < size; i++) {
        if (strcmp(array[i], minValue) < 0) {
            minValue = array[i];
        }
    }
    
    int numMinValues = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], minValue) == 0) {
            numMinValues++;
        }
    }
    
    char** newArray = new char*[size - numMinValues];
    int newIndex = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], minValue) != 0) {
            newArray[newIndex] = array[i];
            newIndex++;
        }
    }
    
    for (int i = 0; i < size; i++) {
        delete[] array[i];
    }
    delete[] array;
    
    array = newArray;
}
 
int main() {
   							 // Приклад використання для типу int
    int intArray[] = {2, 5, 1, 3, 1, 7, 1};
    int intArraySize = sizeof(intArray) / sizeof(int);
    removeMin(intArray, intArraySize);
    for (int i = 0; i < intArraySize - 3; i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
  						  // Приклад використання для типу char*
    char* strArray[] = {"glue", "pencil”, "pencil-box", "pen", "diary”, "calculator”;
    int strArraySize = sizeof(strArray) / sizeof(char*);
    removeMin(strArray, strArraySize);
    for (int i = 0; i < strArraySize - 2; i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;
return 0;
}


}

