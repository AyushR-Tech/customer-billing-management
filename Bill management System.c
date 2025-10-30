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
    int number;
};

// Function to calculate amount with 18% GST
float AmoGST(float price, int Q) {
    return Q * (price + (price * 18 / 100));
}

int main() {
    int n;
    printf("             SHRI GANESH ENTERPRISES            ");
    printf("\n *************************************************");
    printf("\n ENTER THE NO OF CUSTOMERS : ");
    scanf("%d", &n);

    struct customer c[20];
    struct product p[20];

    for (int k = 0; k < n; k++) {
        printf("\nNAME OF CUSTOMER %d: ", k + 1);
        scanf("%s", c[k].cname);

        printf("ADDRESS OF CUSTOMER: ");
        scanf(" %[^\n]s", c[k].address);  // read full line

        printf("PHONE NUMBER OF CUSTOMER: ");
        scanf("%d", &c[k].number);

        int m;
        printf("\nNUMBER OF PRODUCTS: ");
        scanf("%d", &m);

        float AmoPro[10];
        for (int j = 0; j < m; j++) {
            printf("\nNAME OF PRODUCT %d: ", j + 1);
            scanf("%s", p[j].pname);

            printf("PRICE OF PRODUCT: ");
            scanf("%f", &p[j].price);

            printf("QUANTITY: ");
            scanf("%d", &p[j].Quantity);

            AmoPro[j] = AmoGST(p[j].price, p[j].Quantity);
        }

        int ch;
        printf("\nARE YOU OLD OR NEW CUSTOMER?");
        printf("\nFOR OLD = 1 , NEW = 0");
        printf("\nENTER YOUR STATUS: ");
        scanf("%d", &ch);

        float final_price = 0;
        for (int i = 0; i < m; i++) {
            final_price += AmoPro[i];
        }

        float total_bill;
        if (ch == 0)
            total_bill = final_price - ((final_price * 5) / 100);
        else
            total_bill = final_price - ((final_price * 10) / 100);

        // Bill print
        printf("\n**********************************************");
        printf("\n          SHRI GANESH ENTERPRISES ");
        printf("\n**********************************************");
        printf("\n           // BILL OF PRODUCTS //");
        printf("\n################################################");
        printf("\nNAME\t\tADDRESS\t\tNUMBER");
        printf("\n%s\t\t%s\t\t%d", c[k].cname, c[k].address, c[k].number);

        printf("\n\nPRODUCT\tQUANTITY\tPRICE\t\tBILL");
        for (int i = 0; i < m; i++) {
            printf("\n%s\t%d\t\t%.2f\t\t%.2f", p[i].pname, p[i].Quantity, p[i].price, AmoPro[i]);
        }

        printf("\n\nTOTAL NO OF PRODUCTS : %d", m);
        printf("\nTOTAL BILL = %.2f", total_bill);
        printf("\n################################################\n");
    }

    return 0;
}

