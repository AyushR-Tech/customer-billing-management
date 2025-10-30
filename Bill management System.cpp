#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "             SHRI GANESH ENTERPRISES            \n";
    cout << "*************************************************\n";
    cout << "ENTER THE NUMBER OF CUSTOMERS: ";
    
    int n;
    cin >> n;
    
    for (int k = 0; k < n; k++) {
        cout << "\n=== CUSTOMER " << k + 1 << " ===\n";
        
        string cname, address;
        long long phone;
        
        cout << "NAME OF CUSTOMER: ";
        cin >> cname;
        
        cin.ignore();
        cout << "ADDRESS OF CUSTOMER: ";
        getline(cin, address);
        
        cout << "PHONE NUMBER: ";
        cin >> phone;
        
        int m;
        cout << "NUMBER OF PRODUCTS: ";
        cin >> m;
        
        string pname[50];
        float price[50];
        int quantity[50];
        float amount[50];
        
        for (int j = 0; j < m; j++) {
            cout << "\n--- PRODUCT " << j + 1 << " ---\n";
            cout << "NAME: ";
            cin >> pname[j];
            
            cout << "PRICE: ";
            cin >> price[j];
            
            cout << "QUANTITY: ";
            cin >> quantity[j];
            
            // Calculate amount with 18% GST
            amount[j] = quantity[j] * price[j] * 1.18;
        }
        
        int status;
        cout << "\nARE YOU OLD OR NEW CUSTOMER?\n";
        cout << "OLD = 1, NEW = 0\n";
        cout << "ENTER: ";
        cin >> status;
        
        // Calculate subtotal
        float subtotal = 0;
        for (int i = 0; i < m; i++) {
            subtotal += amount[i];
        }
        
        // Apply discount
        float discount = (status == 1) ? 10.0 : 5.0;
        float discountAmount = subtotal * discount / 100.0;
        float total = subtotal - discountAmount;
        
        // Print Bill
        cout << "\n**********************************************";
        cout << "\n          SHRI GANESH ENTERPRISES ";
        cout << "\n**********************************************";
        cout << "\n           // BILL OF PRODUCTS //";
        cout << "\n################################################\n";
        cout << "NAME: " << cname << "\n";
        cout << "ADDRESS: " << address << "\n";
        cout << "PHONE: " << phone << "\n";
        cout << "################################################\n";
        
        cout << "\nPRODUCT         QUANTITY    PRICE       AMOUNT\n";
        cout << "-----------------------------------------------\n";
        
        for (int i = 0; i < m; i++) {
            cout << left << setw(15) << pname[i]
                 << setw(12) << quantity[i]
                 << setw(12) << fixed << setprecision(2) << price[i]
                 << setw(12) << amount[i] << "\n";
        }
        
        cout << "-----------------------------------------------\n";
        cout << "TOTAL PRODUCTS: " << m << "\n";
        cout << "SUBTOTAL: " << fixed << setprecision(2) << subtotal << "\n";
        cout << "DISCOUNT (" << discount << "%): " << discountAmount << "\n";
        cout << "TOTAL BILL: " << total << "\n";
        cout << "################################################\n\n";
    }
    
    return 0;
}
