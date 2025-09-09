#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h> 
// 7. Create a C program that accepts an IPv4 address and subnet mask in dotted decimal format, and outputs:
//     a. Network ID
//     b. Broadcast Address
//     c. First and Last Host Address
//     d. CIDR notation
//     e. Number of valid hosts
//     f. IP Address Class (A/B/C/D/E).

int main()
{
    char ip_str[16], mask_str[16];
    struct in_addr ip_addr, mask_addr, network_id, broadcast_addr;
    unsigned long num_hosts;
    int cidr, i;

    // Input IP address and subnet mask
    printf("Enter IPv4 address (dotted decimal): ");
    scanf("%15s", ip_str);
    printf("Enter subnet mask (dotted decimal): ");
    scanf("%15s", mask_str);

    // Convert to binary form
    if (inet_pton(AF_INET, ip_str, &ip_addr) != 1 || inet_pton(AF_INET, mask_str, &mask_addr) != 1) {
        fprintf(stderr, "Invalid IP address or subnet mask format.\n");
        return 1;
    }

    // Calculate Network ID
    network_id.s_addr = ip_addr.s_addr & mask_addr.s_addr;

    // Calculate Broadcast Address
    broadcast_addr.s_addr = network_id.s_addr | ~mask_addr.s_addr;

    // Calculate CIDR notation
    cidr = 0;
    for (i = 0; i < 32; i++) {
        if (mask_addr.s_addr & (1 << (31 - i))) {
            cidr++;
        }
    }

    // Calculate number of valid hosts
    num_hosts = (1UL << (32 - cidr)) - 2; // Subtracting network and broadcast addresses

    // Output results
    char network_str[16], broadcast_str[16], first_host_str[16], last_host_str[16];
    inet_ntop(AF_INET, &network_id, network_str, sizeof(network_str));
    inet_ntop(AF_INET, &broadcast_addr, broadcast_str, sizeof(broadcast_str));

    struct in_addr first_host, last_host;
    first_host.s_addr = htonl(ntohl(network_id.s_addr) + 1);
    last_host.s_addr = htonl(ntohl(broadcast_addr.s_addr) - 1);
    inet_ntop(AF_INET, &first_host, first_host_str, sizeof(first_host_str));
    inet_ntop(AF_INET, &last_host, last_host_str, sizeof(last_host_str));

    if ((ntohl(ip_addr.s_addr) & 0x80000000) == 0) {
        printf("IP Address Class: A\n");
    } else if ((ntohl(ip_addr.s_addr) & 0xC0000000) == 0x80000000) {
        printf("IP Address Class: B\n");
    } else if ((ntohl(ip_addr.s_addr) & 0xE0000000) == 0xC0000000) {
        printf("IP Address Class: C\n");
    } else if ((ntohl(ip_addr.s_addr) & 0xF0000000) == 0xE0000000) {
        printf("IP Address Class: D\n");
    } else {
        printf("IP Address Class: E\n");
    }
    printf("Network ID: %s\n", network_str);
    printf("Broadcast Address: %s\n", broadcast_str);
    printf("First Host Address: %s\n", first_host_str);
    printf("Last Host Address: %s\n", last_host_str);
    printf("CIDR Notation: /%d\n", cidr);
    printf("Number of Valid Hosts: %lu\n", num_hosts);
    return 0;

}