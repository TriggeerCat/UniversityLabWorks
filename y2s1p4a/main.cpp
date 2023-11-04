#include <iostream>
#include <list>

class Ticket {
public:
    std::string destination;
    int flightNumber;
    std::string passengerName;
    std::string passengerInitials;
    std::string departureDate;

    Ticket(std::string destination, int flightNumber, std::string passengerName, std::string passengerInitials, std::string departureDate) {
        this->destination = std::move(destination);
        this->flightNumber = flightNumber;
        this->passengerName = std::move(passengerName);
        this->passengerInitials = std::move(passengerInitials);
        this->departureDate = std::move(departureDate);
    }

    void print() {
        std::cout << "Destination: " << destination << std::endl;
        std::cout << "Flight number: " << flightNumber << std::endl;
        std::cout << "Passenger name: " << passengerName << std::endl;
        std::cout << "Passenger initials: " << passengerInitials << std::endl;
        std::cout << "Departure date: " << departureDate << std::endl;
    }
};

void print(std::list<Ticket> &tickets)
{
    std::cout << "== Tickets ==\n";
    for (auto &ticket : tickets) {
        ticket.print();
        std::cout << std::endl;
    }
    std::cout << "== ======= ==\n\n\n";
}

void print(std::list<Ticket> &tickets, int flightNumber, std::string departureDate)
{
    bool isFound = false;
    std::cout << "== Tickets ==\n";
    for (auto &ticket : tickets) {
        if (ticket.flightNumber == flightNumber && ticket.departureDate == departureDate) {
            ticket.print();
            isFound = true;
            std::cout << std::endl;
        }
    }
    if (!isFound)
        std::cout << "Tickets by this flight and date not found\n";
    std::cout << "== ======= ==\n\n\n";
}

void print(std::list<Ticket> &tickets, std::string str, bool isDestination)
{
    bool isFound = false;
    std::cout << "== Tickets ==\n";
    for (auto &ticket : tickets) {
        if (isDestination) {
            if (ticket.destination == str) {
                ticket.print();
                isFound = true;
                std::cout << std::endl;
            }
        }
        else {
            if (ticket.departureDate == str) {
                ticket.print();
                isFound = true;
                std::cout << std::endl;
            }
        }
    }
    if (!isFound)
        if (!isDestination)
            std::cout << "Tickets by this date not found\n";
        else
            std::cout << "Tickets by this destination not found\n";
    std::cout << "== ======= ==\n\n\n";
}

int main() {
    std::list<Ticket> tickets = {{"Tokyo", 47, "Chang", "A.", "31.10.2023"},
                                 {"Hurricane", 87, "Kapkan", "W.", "26.10.2073"}};

    print(tickets);

    tickets.insert(tickets.cend(), {"Ternopil", 1, "Barmak", "R.", "06.09.2077"});

    print(tickets);

    tickets.erase(tickets.begin());

    print(tickets);

    print(tickets, 87, "26.10.2073");

    print(tickets, "Ternopil", true);

    print(tickets, "31.10.2023", false);

    return 0;
}

/*
Скласти програму обліку заявок на авіаквитки.
Кожна заявка містить: пункт призначення, номер рейсу, прізвище та ініціали пасажира, бажану дату вильоту.
Програма повинна забезпечувати вибір за допомогою меню і виконання однієї з наступних функцій:

• додавання заявок в список;
• видалення заявок;
• виведення заявок по заданому номеру рейсу і за датою вильоту;
• виведення всіх заявок, упорядкованих по пунктах призначення;
• виведення всіх заявок, упорядкованих по датах вильоту.

 */