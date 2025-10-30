#include <stdio.h>
#include <string.h>

// Structure definitions
struct product {
    float price;
    int Quantity;
    char pname[20];
};

struct customer {
    char cname[20];
    char address[50];
    long long number;  // Changed to long long for 10-digit phone numbers
};

// Function to calculate amount with 18% GST
float AmoGST(float price, int Q) {
    return Q * (price + (price * 18.0 / 100.0));  // Use floating point division
}

int main() {
    int n;
    printf("             SHRI GANESH ENTERPRISES            \n");
    printf(" *************************************************\n");
    printf(" ENTER THE NO OF CUSTOMERS : ");
    scanf("%d", &n);
    
    // Validate input
    if (n <= 0 || n > 20) {
        printf("Invalid number of customers. Must be between 1 and 20.\n");
        return 1;
    }
    
    struct customer c[20];
    struct product p[20];
    
    int k;
    for(k = 0; k < n; k++) {
        printf("\n=== CUSTOMER %d ===\n", k + 1);
        printf("NAME OF CUSTOMER: ");
        scanf("%s", c[k].cname);
        
        printf("ADDRESS OF CUSTOMER: ");
        scanf(" %[^\n]", c[k].address);  // Fixed: removed 's' after %[^\n]
        
        printf("PHONE NUMBER OF CUSTOMER: ");
        scanf("%lld", &c[k].number);  // Changed to %lld for long long
        
        int m;
        printf("\nNUMBER OF PRODUCTS: ");
        scanf("%d", &m);
        
        // Validate product count
        if (m <= 0 || m > 20) {
            printf("Invalid number of products. Must be between 1 and 20.\n");
            k--;  // Retry this customer
            continue;
        }
        
        float AmoPro[20];  // Increased size to match product array
        int j;
        for (j = 0; j < m; j++) {
            printf("\n--- PRODUCT %d ---\n", j + 1);
            printf("NAME OF PRODUCT: ");
            scanf("%s", p[j].pname);
            
            printf("PRICE OF PRODUCT: ");
            scanf("%f", &p[j].price);
            
            printf("QUANTITY: ");
            scanf("%d", &p[j].Quantity);
            
            AmoPro[j] = AmoGST(p[j].price, p[j].Quantity);
        }
        
        int ch;
        printf("\nARE YOU OLD OR NEW CUSTOMER?\n");
        printf("FOR OLD = 1, NEW = 0\n");
        printf("ENTER YOUR STATUS: ");
        scanf("%d", &ch);
        
        // Calculate total before discount
        float final_price = 0;
        int i;
        for (i = 0; i < m; i++) {
            final_price += AmoPro[i];
        }
        
        // Apply discount (fixed logic: old customers get more discount)
        float total_bill;
        float discount_rate;
        if (ch == 1) {  // Old customer gets 10% discount
            discount_rate = 10.0;
            total_bill = final_price - ((final_price * 10.0) / 100.0);
        } else {  // New customer gets 5% discount
            discount_rate = 5.0;
            total_bill = final_price - ((final_price * 5.0) / 100.0);
        }
        
        // Bill print
        printf("\n**********************************************\n");
        printf("          SHRI GANESH ENTERPRISES \n");
        printf("**********************************************\n");
        printf("           // BILL OF PRODUCTS //\n");
        printf("################################################\n");
        printf("NAME: %s\n", c[k].cname);
        printf("ADDRESS: %s\n", c[k].address);
        printf("PHONE: %lld\n", c[k].number);
        printf("################################################\n");
        printf("\n%-15s %-10s %-10s %-10s\n", "PRODUCT", "QUANTITY", "PRICE", "AMOUNT");
        printf("-----------------------------------------------\n");
        
        for (i = 0; i < m; i++) {
            printf("%-15s %-10d %-10.2f %-10.2f\n", 
                   p[i].pname, p[i].Quantity, p[i].price, AmoPro[i]);
        }
        
        printf("-----------------------------------------------\n");
        printf("TOTAL NO OF PRODUCTS: %d\n", m);
        printf("SUBTOTAL: %.2f\n", final_price);
        printf("DISCOUNT (%.0f%%): %.2f\n", discount_rate, 
               final_price - total_bill);
        printf("TOTAL BILL: %.2f\n", total_bill);
        printf("################################################\n\n");
    }
    
    return 0;
}
