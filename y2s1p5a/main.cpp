#include <iostream>
#include <deque>

class Person
{
private:
    std::string name;
    int value;
public:
    Person(std::string name, int value) : name(std::move(name)), value(value) {}
    void Print() const
    {
        std::cout << name << " " << value << std::endl;
    }
};

void PrintDeque(const std::deque<Person> &deque)
{
    std::cout << "Deque: ";
    for (const auto &item : deque)
    {
        item.Print();
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    //1
    std::deque<Person> deque1{{"Andriy", 100}, {"Roman", 0}, {"Nazar", -10}, {"Ihor", 20}};
    //2
    PrintDeque(deque1);
    //3
    deque1.pop_back();
    deque1.pop_back();
    deque1.insert(deque1.end(), {"Nazar", 10});
    //4
    PrintDeque(deque1);
    //5
    std::deque<Person> deque2{{"Kapkan", 87}, {"Artem", 70}};
    //6
    int n = 1;
    for (int i = 0; i < n; ++i)
    {
        deque1.erase(deque1.begin() + 2 + i);
    }
    deque1.insert(deque1.end(), deque2.begin(), deque2.end());
    //7
    PrintDeque(deque1);
    PrintDeque(deque2);
}

/*
1. Створити об’єкт-контейнер, дек, заповнити його даними, тип ***, де тип*** - користувацький тип обраної Вами предметної області.
2. Переглянути контейнер.
3. Змінити контейнер, видаливши з нього одні елементи і замінивши іншими.
4. Переглянути контейнер, використовуючи для доступу до його елементів ітератори.
5. Створити другий контейнер цього ж класу і заповнити його даними того ж типу, що і перший контейнер.
6. Змінити перший контейнер, видаливши з нього n елементів після заданого і добавивши потім в нього всі елементи з другого контейнера.
7. Переглянути перший і другий контейнери.
 */