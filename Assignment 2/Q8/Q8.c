#include<stdio.h>
#include<math.h>

int BinarytoDecimal(int size) {
    int decimal = 0;
    for (int i = 0; i < size; i++) {
        int bit;
        printf("Enter the %d bit: ", i + 1);
        scanf("%d", &bit);
        if (bit == 0 || bit == 1) 
            decimal += bit * (int)pow(2, i);
        else {
            printf("Invalid bit! Please enter 0 or 1.\n");
            i--;  
        }
    }
    return decimal;
}

void DecimaltoBinary(int decimal) {
    int binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

void DecimaltoHexaDecimal(int decimal) {
    char hex[32];
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10)
            hex[i] = remainder + '0';
        else
            hex[i] = remainder + 'A' - 10;
        decimal /= 16;
        i++;
    }
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
    return;
}

int HexaDecimaltoDecimal(int size) {
    int decimal = 0;
    int value;
    for (int i = size; i > 0; i--) {
        char decimal1;
        printf("Enter the number: ");
        scanf(" %c", &decimal1);
        if (decimal1 >= '0' && decimal1 <= '9')  value = decimal1 - '0';
        else if (decimal1 >= 'A' && decimal1 <= 'F') value = decimal1 - 'A' + 10;
        decimal +=  value * (int)pow(16,i-1);
        printf("The result: %d\n",decimal);
    }
    return decimal;
}
void BinarytoHexadecimal(int size) {
    int decimal = BinarytoDecimal(size);
    DecimaltoHexaDecimal(decimal);
    return;            
}
void HexadecimaltoBinary(int size){
    int decimal = HexaDecimaltoDecimal(size);
    DecimaltoBinary(decimal);
    return;
}
int main() {
    int size, choice, decimal;
    printf("Select an option:\n");
    printf("1.Binary to Decimal\t\t");
    printf("2.Decimal to Binary     \n");
    printf("3.Decimal to Hexadecimal\t");
    printf("4.Hexadecimal to Decimal\n");
    printf("5.Binary to Hexadecimal\t\t");
    printf("6.Hexadecimal to Binary\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the size of binary number: ");
            scanf("%d", &size);
            printf("Decimal Answer: %d\n", BinarytoDecimal(size));
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            DecimaltoBinary(decimal);
            break;
        case 3:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            DecimaltoHexaDecimal(decimal);
            break;
        case 4: 
            printf("Enter the size of hexadecimal number: ");
            scanf("%d", &size);
            printf("Decimal Answer: %d\n", HexaDecimaltoDecimal(size));
            break; 
        case 5:
            printf("Enter the size of binary to hexadecimal number : ");
            scanf("%d", &size);
            BinarytoHexadecimal(size);
            break;      
        case 6:
            printf("Enter the size of hexadecimal to binary: ");
            scanf("%d",&size);
            HexadecimaltoBinary(size);
            break;   
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}
