#include <iostream>
using namespace std;


struct zveno {
    int info;
    zveno* next;
    zveno* prev;
};


zveno* createNode(int value) {
    zveno* node = new zveno;
    node->info = value;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

int main() {
    setlocale(LC_ALL, "RU");  //Установка кодировку на RU

    int data[] = { 3, 7, 2, 9, 11, 4, 6, 33, 88, 34 };
    int size = sizeof(data) / sizeof(data[0]);

    zveno* head = nullptr;  
    zveno* tail = nullptr;  

    // Создание двунаправленный список
    for (int i = 0; i < size; i++) {
        zveno* newNode = createNode(data[i]);

        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Вывод списка слева направо
    cout << "Список слева направо: ";
    zveno* current = head;
    while (current) {
        cout << current->info;
        if (current->next) cout << ", ";
        current = current->next;
    }
    cout << endl;

    // Вывод списка справа налево
    cout << "Список справа налево: ";
    current = tail;
    while (current) {
        cout << current->info;
        if (current->prev) cout << ", ";
        current = current->prev;
    }
    cout << endl;

    // Очистка памяти
    current = head;
    while (current) {
        zveno* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
