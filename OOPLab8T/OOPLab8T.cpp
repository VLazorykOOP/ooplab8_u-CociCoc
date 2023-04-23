// OOPLab8T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

template<typename T>
void mergeArrays(T* arr1, int size1, T* arr2, int size2, T* result, int& sizeResult) {
    std::unordered_set<T> seenValues;
    
    for (int i = 0; i < size1; i++) {
        if (seenValues.find(arr1[i]) == seenValues.end()) {
            seenValues.insert(arr1[i]);
            result[sizeResult] = arr1[i];
            sizeResult++;
        }
    }
    
    for (int i = 0; i < size2; i++) {
        if (seenValues.find(arr2[i]) == seenValues.end()) {
            seenValues.insert(arr2[i]);
            result[sizeResult] = arr2[i];
            sizeResult++;
        }
    }
}
 
// Специфікація для типу char*
void mergeArrays(char** arr1, int size1, char** arr2, int size2, char** result, int& sizeResult) {
    std::unordered_set<std::string> seenValues;
    
    for (int i = 0; i < size1; i++) {
        if (seenValues.find(std::string(arr1[i])) == seenValues.end()) {
            seenValues.insert(std::string(arr1[i]));
            result[sizeResult] = arr1[i];
            sizeResult++;
        }
    }
    
    for (int i = 0; i < size2; i++) {
        if (seenValues.find(std::string(arr2[i])) == seenValues.end()) {
            seenValues.insert(std::string(arr2[i]));
            result[sizeResult] = arr2[i];
            sizeResult++;
        }
    }
}
 
int main() {
    // Приклад використання для типу int
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {4, 5, 6, 7, 8};
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    int resultSize = 0;
    int* result = new int[size1 + size2];
    
    mergeArrays(arr1, size1, arr2, size2, result, resultSize);
    
    for (int i = 0; i < resultSize; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] result;
    
    // Приклад використання для типу char*
    char* strArr1[] = {"apple", "orange", "banana"};
    char* strArr2[] = {"banana", "peach", "kiwi"};
    int strSize1 = sizeof(strArr1) / sizeof(char*);
    int strSize2 = sizeof(strArr2) / sizeof(char*);
    int strResultSize = 0;
    char** strResult = new char*[strSize1 + strSize2];
    
    mergeArrays(strArr1, strSize1, strArr2, strSize2, strResult, strResultSize);
    
    for (int i = 0; i < strResultSize; i++) {
        std  ::cout << strResult[i] << " ";
}
std::cout << std::endl;
 
for (int i = 0; i < strResultSize; i++) {
    delete[] strResult[i];
}
delete[] strResult;
 
return 0;
}


