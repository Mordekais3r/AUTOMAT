/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister() : cashOnHand(5000) {}
    cashRegister(int initialCash) : cashOnHand(initialCash) {}

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int typeCost;

public:
    dispenserType() : numberOfItems(50), typeCost(50) {}
    dispenserType(int cost, int items) : numberOfItems(items), typeCost(cost) {}

    int getNoOfItems() const {
        return numberOfItems;
    }

    int getCost() const {
        return typeCost;
    }

    void makeSale() {
        numberOfItems--;
    }
};

void showSelection(const vector<dispenserType>& dispensers) {
    cout << "Меню товаров:" << endl;
    for (int i = 0; i < dispensers.size(); i++) {
        cout << i + 1 << ". Товар с ценой " << dispensers[i].getCost() << " руб. Количество: " << dispensers[i].getNoOfItems() << endl;
    }
}

int sellProduct(dispenserType& dispenser, cashRegister& register_) {
    int cost = dispenser.getCost();
    int items = dispenser.getNoOfItems();

    if (items == 0) {
        cout << "Извините, этот товар отсутствует." << endl;
        return 0;
    }

    cout << "Стоимость товара: " << cost << " руб." << endl;
    cout << "Внесите деньги: ";
    int payment;
    cin >> payment;

    if (payment < cost) {
        cout << "Недостаточно денег. Покупка отменена." << endl;
        return 0;
    }

    int change = payment - cost;
    register_.acceptAmount(cost);
    dispenser.makeSale();

    cout << "Спасибо за покупку! Ваша сдача: " << change << " руб." << endl;
    return change;
}

int main() {
    dispenserType candy(100, 20);
    dispenserType chips(50, 30);
    dispenserType gum(20, 40);
    dispenserType cookies(75, 25);

    vector<dispenserType> dispensers = {candy, chips, gum, cookies};
    cashRegister register_(5000);

    while (true) {
        showSelection(dispensers);
        cout << "Выберите товар (1-" << dispensers.size() << ") или 0 для выхода: ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > dispensers.size()) {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            continue;
        }

        sellProduct(dispensers[choice - 1], register_);
    }

    cout << "Программа завершена. Остаток в кассовом аппарате: " << register_.getCurrentBalance() << " руб." << endl;

    return 0;
}
