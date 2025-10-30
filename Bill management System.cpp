#include <bits/stdc++.h>
using namespace std;

class Product {
public:
    string pname;
    float price;
    int quantity;

    Product() : price(0), quantity(0) {}

    float calcAmountWithGST() const {
        // GST = 18%
        return quantity * (price + (price * 18 / 100));
    }
};

class Customer {
public:
    string cname, address;
    long long number;
    vector<Product> products;
    bool isOldCustomer; // true = old, false = new

    float calcTotalBill() const {
        float total = 0;
        for (const auto &prod : products)
            total += prod.calcAmountWithGST();

        float discount = isOldCustomer ? 10 : 5; // 10% old, 5% new
        total -= (total * discount / 100);
        return total;
    }

    void printBill() const {
        cout << "\n**********************************************";
        cout << "\n          SHRI GANESH ENTERPRISES ";
        cout << "\n**********************************************";
        cout << "\n           // BILL OF PRODUCTS //";
        cout << "\n################################################\n";
        cout << "NAME\t\tADDRESS\t\tNUMBER\n";
        cout << cname << "\t\t" << address << "\t\t" << number << "\n";

        cout << "\nPRODUCT\tQUANTITY\tPRICE\t\tAMOUNT (with GST)";
        for (const auto &p : products) {
            cout << "\n" << p.pname << "\t" << p.quantity
                 << "\t\t" << fixed << setprecision(2) << p.price
                 << "\t\t" << p.calcAmountWithGST();
        }

        cout << "\n\nTOTAL NO OF PRODUCTS : " << products.size();
        cout << "\nTOTAL BILL = " << fixed << setprecision(2) << calcTotalBill();
        cout << "\n################################################\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "             SHRI GANESH ENTERPRISES            ";
    cout << "\n*************************************************\n";
    cout << "ENTER THE NUMBER OF CUSTOMERS: ";
    int n;
    cin >> n;

    vector<Customer> customers(n);

    for (int k = 0; k < n; k++) {
        cout << "\nNAME OF CUSTOMER " << k + 1 << ": ";
        cin >> customers[k].cname;
        cin.ignore(); // clear leftover newline

        cout << "ADDRESS OF CUSTOMER: ";
        getline(cin, customers[k].address);

        cout << "PHONE NUMBER OF CUSTOMER: ";
        cin >> customers[k].number;

        int m;
        cout << "\nNUMBER OF PRODUCTS: ";
        cin >> m;

        customers[k].products.resize(m);

        for (int j = 0; j < m; j++) {
            cout << "\nNAME OF PRODUCT " << j + 1 << ": ";
            cin >> customers[k].products[j].pname;

            cout << "PRICE OF PRODUCT: ";
            cin >> customers[k].products[j].price;

            cout << "QUANTITY: ";
            cin >> customers[k].products[j].quantity;
        }

        int ch;
        cout << "\nARE YOU OLD OR NEW CUSTOMER?";
        cout << "\nFOR OLD = 1 , NEW = 0";
        cout << "\nENTER YOUR STATUS: ";
        cin >> ch;

        customers[k].isOldCustomer = (ch == 1);

        // Print the bill for this customer
        customers[k].printBill();
    }

    return 0;
}

