#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 7. Create a C program that accepts an IPv4 address and subnet mask in  dotted decimal format, and outputs:
//     a. Network ID
//     b. Broadcast Address
//     c. First and Last Host Address
//     d. CIDR notation
//     e. Number of valid hosts
//     f. IP Address Class (A/B/C/D/E).

void calculateNetworkDetails(char *ip, char *mask) {
    unsigned int ipParts[4], maskParts[4];
    unsigned int network[4], broadcast[4], firstHost[4], lastHost[4];
    int cidr, validHosts;

    sscanf(ip, "%u.%u.%u.%u", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    sscanf(mask, "%u.%u.%u.%u", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    for (int i = 0; i < 4; i++) {
        network[i] = ipParts[i] & maskParts[i];
        broadcast[i] = network[i] | (~maskParts[i] & 0xFF);
    }

    for (int i = 0; i < 4; i++) {
        firstHost[i] = network[i];
        lastHost[i] = broadcast[i];
    }
    firstHost[3] += 1;
    lastHost[3] -= 1;

    cidr = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            if (maskParts[i] & (1 << j)) {
                cidr++;
            } else {
                break;
            }
        }
    }

    validHosts = pow(2, 32 - cidr) - 2;

    char *ipClass;
    if (ipParts[0] >= 0 && ipParts[0] <= 127) {
        ipClass = "A";
    } else if (ipParts[0] >= 128 && ipParts[0] <= 191) {
        ipClass = "B";
    } else if (ipParts[0] >= 192 && ipParts[0] <= 223) {
        ipClass = "C";
    } else if (ipParts[0] >= 224 && ipParts[0] <= 239) {
        ipClass = "D";
    } else {
        ipClass = "E";
    }

    printf("Network ID: %u.%u.%u.%u\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("First Host Address: %u.%u.%u.%u\n", firstHost[0], firstHost[1], firstHost[2], firstHost[3]);
    printf("Last Host Address: %u.%u.%u.%u\n", lastHost[0], lastHost[1], lastHost[2], lastHost[3]);
    printf("CIDR Notation: /%d\n", cidr);
    printf("Number of Valid Hosts: %d\n", validHosts);
    printf("IP Address Class: %s\n", ipClass);
}

int main() {
    char ip[16], mask[16];
    printf("Enter IPv4 Address: ");
    scanf("%s", ip);
    printf("Enter Subnet Mask: ");
    scanf("%s", mask);

    calculateNetworkDetails(ip, mask);
    return 0;
}
