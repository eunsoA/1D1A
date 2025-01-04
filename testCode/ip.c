#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert an integer to its binary representation
void intToBinary(int num, char *binary) {
    for (int i = 7; i >= 0; --i) {
        binary[7 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
}

// Function to print the binary representation of an IP address
void printBinaryIP(char *ip) {
    int octets[4];
    char binary[9];
    if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        printf("Invalid IP address format.\n");
        return;
    }

    for (int i = 0; i < 4; i++) {
        intToBinary(octets[i], binary);
        printf("%s", binary);
        if (i < 3) printf(".");
    }
    printf("\n");
}

// Function to calculate and print the usable IP range
void printUsableIPRange(char *ip, int cidr) {
    unsigned int baseIP = 0, subnetMask = 0xFFFFFFFF << (32 - cidr);
    unsigned int network, broadcast;

    int octets[4];
    if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        printf("Invalid IP address format.\n");
        return;
    }

    for (int i = 0; i < 4; i++) {
        baseIP = (baseIP << 8) | octets[i];
    }

    network = baseIP & subnetMask;
    broadcast = network | ~subnetMask;

    if (cidr < 31) {
        printf("%u.%u.%u.%u - %u.%u.%u.%u\n",
               (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, (network & 0xFF) + 1,
               (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, (broadcast & 0xFF) - 1);
    } else {
        printf("No usable IPs in this range (CIDR: %d).\n", cidr);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP> or <IP/CIDR>\n", argv[0]);
        return 1;
    }

    char *slash = strchr(argv[1], '/');
    if (slash) {
        // Handle CIDR notation
        *slash = '\0';
        int cidr = atoi(slash + 1);
        if (cidr < 0 || cidr > 32) {
            printf("Invalid CIDR value.\n");
            return 1;
        }
        printUsableIPRange(argv[1], cidr);
    } else {
        // Handle single IP
        printBinaryIP(argv[1]);
    }

    return 0;
}

