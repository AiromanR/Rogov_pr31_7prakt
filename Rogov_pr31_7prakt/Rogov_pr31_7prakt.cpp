// Rogov_pr31_7prakt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <windows.h>

struct Snake {
    struct Node {
        int x;
        int y;
        Node* next;

        Node(int X, int Y) : x(X), y(Y), next(nullptr) {}
    };
    Node* head = nullptr;
    Node* tail = nullptr;

    struct Apple {
        int appleX = -1;
        int appleY = -1;
    };
    Apple apple;


public:
    void push_back(int X, int Y)  //добавление в конец списка ~ голова змеи
    {
        Node* node = new Node(X, Y);
        if (head == nullptr) {
            head = node;

        }
        else {
            tail->next = node;
        }
        tail = node;
    }

    void pop_front() //удаление начала списка ~ хвост змеи
    {
        Node* saveToDelete = head;
        head = head->next;
        delete saveToDelete;

    }

    void generateApple(char area[9][9]) {
        bool validPosition = false;
        while (!validPosition) {
            apple.appleX = rand() % 9;
            apple.appleY = rand() % 9;
            validPosition = true;

            for (Node* i = head; i != nullptr; i = i->next) {
                if (i->x == apple.appleX && i->y == apple.appleY) {
                    validPosition = false;
                    break;
                }
            }
        }  
    }

    bool checkApple() {
        if (tail->x == apple.appleX && tail->y == apple.appleY) return true;
        return false;
    }

    void createArea(char area[9][9]) {
        int appleX = rand() % 10;
        int appleY = rand() % 10;

        //создание пустой зоны
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                area[i][j] = '~';
            }
        }
        //создание змейки на зоне
        for (Node* i = head; i != nullptr; i = i->next) {
            area[i->y][i->x] = '@';
        }

        //добавление яблока на поле
        area[apple.appleY][apple.appleX] ='*';

        //вывод на экран
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << area[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool checkGameOver()
    {
        Node* i = tail; //голова змеи
        if ((i->x < 0) || (i->y < 0) || (i->x > 8) || (i->y > 8)) {
            return true; //проверка на границы
        }

        Node* j = head;
        while (j != tail) {
            if (j->x == tail->x && j->y == tail->y) {
                return true; //проверка на саму себя
            }
            j = j->next;
        }
        return false;
    }
};


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    Snake snake;

    char area[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            area[i][j] = '~';
        }
    }

    snake.push_back(0, 4);
    snake.push_back(1, 4);
    snake.push_back(2, 4);
    snake.push_back(3, 4);

    snake.generateApple(area);
    snake.createArea(area);

    int currentDirection = 3; //1 - налево, 2 - вверх, 3 - направо, 4 - вниз
    int snakeHeadX = 3; //текущее положение головы
    int snakeHeadY = 4;
    int dontPop = 0; 

    while (true) {
        if (_kbhit() == 1) {
            switch (_getch()) {
            case 'a':
                if (currentDirection != 3) currentDirection = 1;
                break;
            case 'w':
                if (currentDirection != 4) currentDirection = 2;
                break;
            case 'd':
                if (currentDirection != 1) currentDirection = 3;
                break;
            case 's':
                if (currentDirection != 2) currentDirection = 4;
                break;
            case 'q':
                dontPop++;
                break; //добавление размера
            }
        }

        switch (currentDirection) {
        case 1:
            snakeHeadX--; break;
        case 2:
            snakeHeadY--; break;
        case 3:
            snakeHeadX++; break;
        case 4:
            snakeHeadY++; break;
        }

        snake.push_back(snakeHeadX, snakeHeadY);

        if (snake.checkApple()) {
            dontPop++;
            snake.generateApple(area);
        }

        if (dontPop > 0) dontPop--;
            else snake.pop_front();

        if (snake.checkGameOver()) break;

        system("cls");
        snake.createArea(area);
        Sleep(333);
    }
    std::cout << "Столкновение. Игра окончена" << std::endl;
    system("pause");
}
