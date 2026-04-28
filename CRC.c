#include <stdio.h>
#include <string.h>

void xor_operation(char *dividend, char *divisor, int start, int n) {
    for (int i = 0; i < n; i++) {
        if (dividend[start + i] == divisor[i])
            dividend[start + i] = '0';
        else
            dividend[start + i] = '1';
    }
}

void compute_crc(char data[], char divisor[]) {
    int data_len = strlen(data);
    int div_len = strlen(divisor);

    char temp[100];

    // Copy data to temp
    strcpy(temp, data);

    // Append zeros (n-1 zeros)
    for (int i = 0; i < div_len - 1; i++) {
        temp[data_len + i] = '0';
    }
    temp[data_len + div_len - 1] = '\0';

    int total_len = strlen(temp);

    // Division process
    for (int i = 0; i <= total_len - div_len; i++) {
        if (temp[i] == '1') {
            xor_operation(temp, divisor, i, div_len);
        }
    }

    // Extract CRC (last n-1 bits)
    char crc[20];
    for (int i = 0; i < div_len - 1; i++) {
        crc[i] = temp[total_len - (div_len - 1) + i];
    }
    crc[div_len - 1] = '\0';

    printf("\nCRC: %s", crc);

    // Final transmitted data
    printf("\nTransmitted Data: %s%s\n", data, crc);
}

int main() {
    char data[100];
    int choice;

    printf("Enter binary data: ");
    scanf("%s", data);

    printf("\nSelect CRC type:");
    printf("\n1. CRC-12");
    printf("\n2. CRC-16");
    printf("\n3. CRC-CCITT\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    char divisor[20];

    switch (choice) {
        case 1:
            strcpy(divisor, "1101011011"); // CRC-12
            break;
        case 2:
            strcpy(divisor, "11000000000000101"); // CRC-16
            break;
        case 3:
            strcpy(divisor, "10001000000100001"); // CRC-CCITT
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("Using divisor: %s\n", divisor);

    compute_crc(data, divisor);

    return 0;
}