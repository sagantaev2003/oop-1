#include <iostream>
using namespace std;

struct Zveno {
    int data;
    Zveno* next;
    Zveno(int d) : data(d), next(nullptr) {} 
};

// Создание списка из массива
Zveno* CreateFromArray(int arr[], int n) {
    if (n == 0) return nullptr;
    Zveno* head = nullptr;
    Zveno* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Zveno* node = new Zveno(arr[i]);
        if (!head) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Подсчёт элементов
int Count(Zveno* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

// Список в прямом порядке
void Print(Zveno* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Список в обратном порядке 
void PrintRevers(Zveno* head) {
    if (!head) return;
    PrintRevers(head->next);
    cout << head->data << " ";
}

// Добавить в начало
Zveno* AddFirst(Zveno* head, int x) {
    Zveno* node = new Zveno(x);
    node->next = head;
    return node;
}

// Добавить в конец
Zveno* AddLast(Zveno* head, int x) {
    Zveno* node = new Zveno(x);
    if (!head) return node;
    Zveno* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    return head;
}

// Удалить первый элемент со значением x
Zveno* Delete(Zveno* head, int x) {
    if (!head) return nullptr;
    if (head->data == x) {
        Zveno* tmp = head->next;
        delete head;
        return tmp;
    }
    Zveno* prev = head;
    Zveno* cur = head->next;
    while (cur) {
        if (cur->data == x) {
            prev->next = cur->next;
            delete cur;
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}

// Освободить память
void FreeList(Zveno* head) {
    while (head) {
        Zveno* tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main() {
    setlocale(LC_ALL, "RU");
    int arr[] = { 3, 7, 2, 9, 11, 4, 6, 33, 88, 34 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Zveno* head = CreateFromArray(arr, n);

    cout << "Количество элементов:  " << Count(head) << endl;
    Print(head);

    cout << "Список в обратном порядке: ";
    PrintRevers(head);
    cout << endl;

    cout << "Добавление 3 элемент в начале: ";

    head = AddFirst(head, 3);
    Print(head);

    cout << "Добавление 3 элемент в конце: ";

    head = AddLast(head, 3);
    Print(head);

    cout << "Удаление элемента 33: ";

    head = Delete(head, 33);
    Print(head);

    FreeList(head);

    return 0;
}
