#include <iostream>
using namespace std;


struct zveno {
    int info;       
    zveno* next;   
};

// Создает новый узел
zveno* createNode(int value) {
    zveno* node = new zveno;
    node->info = value;
    node->next = nullptr;
    return node;
}

int main() {
    // Входные данные
    int data[] = { 3, 7, 2, 9, 11, 4, 6, 33, 88, 34 };
    int size = sizeof(data) / sizeof(data[0]);

    zveno* first = nullptr;  
    zveno* last = nullptr;   

    // Создание список
    for (int i = 0; i < size; i++) {
        zveno* newNode = createNode(data[i]);

        if (!first) {
            first = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    // Список кольцевой,  последний указывает на первый
    if (last) {
        last->next = first;
    }

    // Вывод элементов списка 
    if (first) {
        zveno* current = first;
        do {
            cout << current->info;
            current = current->next;
            if (current != first) cout << ", ";
        } while (current != first);
        cout << endl;
    }

    // Очистка памяти
    if (first) {
        zveno* current = first->next;
        while (current != first) {
            zveno* temp = current;
            current = current->next;
            delete temp;
        }
        delete first;
    }

    return 0;
}
