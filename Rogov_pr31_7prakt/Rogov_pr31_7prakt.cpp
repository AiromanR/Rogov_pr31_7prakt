// Rogov_pr31_7prakt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <windows.h>

struct EventSystem {
    struct Node {

        int x;
        int y;
        Node* next;

        Node(int X, int Y) : x(X), y(Y), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void push_front(int X, int Y) // добавление в начало списка ~ хвост змеи
    {
        Node* node = new Node(X, Y);
        head->next = head;
        head = node;
        /*node->next = head;
        if (head != nullptr) {
            head->prev = node;
        }
        else {
            tail = node;
        }
        head = node;*/
    }

    void push_back(int X, int Y)  // добавление в конец списка ~ голова змеи
    {
        Node* node = new Node(X, Y);
        tail->next = node;
        tail = node;

    }

    void pop_front() {
        Node* saveToDelete = head;
        head = head->next;
        delete saveToDelete;

    }
    //void registerHandler(void(*handler)()) {
    //    Node* node = new Node(handler);

    //    if (head == nullptr) {
    //        head = node;
    //        tail = node;
    //    }
    //    else {
    //        tail->next = node;
    //        tail = node;
    //    }
    //    tail = node;
    //}

    //void triggerEvent() {
    //    for (Node* i = head; i != nullptr; i = i->next) {
    //        if (i->messages) {
    //            i->Handler.messageHandler(i->messages);
    //        }
    //        else {
    //            i->Handler.simpleHandler();
    //        }
    //    }
    //}
};


void displayArea(char area[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << area[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    EventSystem Snake;

    char area[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            area[i][j] = '~';
        }
    }
    area[4][0] = '%';
    area[4][1] = '%';
    area[4][2] = '%';
    int x = 0;
    int y = 0;
    displayArea(area);

    //while (true) {
    //    if (_kbhit() == 1) {
    //        system("cls");
    //        switch (_getch()) {
    //            case 'a':
    //                x--;
    //                std::cout << x << " " << y << std::endl;
    //                break;
    //            case 'w':
    //                y++;
    //                std::cout << x << " " << y << std::endl;
    //                break;
    //            case 'd':
    //                x++;
    //                std::cout << x << " " << y << std::endl;
    //                break;
    //            case 's':
    //                y--;
    //                std::cout << x << " " << y << std::endl;
    //                break;
    //        }
    //    }
    //}
}

