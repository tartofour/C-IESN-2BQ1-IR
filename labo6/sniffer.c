#include <stdio.h>
#include <pcap/pcap.h>
#include <stdlib.h>
#include "interface.h"

#define SIZE_ETHERNET 14

void dump_hex(char * s, const u_char * data, int size)
{
    printf("%s (%d bytes at address : %p)\n", s, size, data);
    for (int i=0; i < size; i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

void print_pkthdr_info(const struct pcap_pkthdr *header)
{
    printf("Packet capture time : %d\n", header->ts);
    printf("Packet capture length: %d\n", header->caplen);
    printf("Packet total length: %d\n", header->len);
    printf("\n");
}

void print_ethernet_header(const struct sniff_ethernet *frame, int size)
{
    dump_hex("Destination address", frame->ether_dhost, size);
    dump_hex("Source address", frame->ether_shost, size);
    printf("Protocol type %u \n", frame->ether_type);
    printf("\n");
}

void print_ip_header(const struct sniff_ip *packet, int size)
{
    dump_hex("IP Header", (const u_char *) packet, size);
    dump_hex("Source address", (const u_char *) &packet->ip_src,4);
    dump_hex("Destination address", (const u_char *) &packet->ip_dst,4);
    printf("Time to live %u\n", packet->ip_ttl);
    printf("Protocol %u\n", packet->ip_p);
    printf("\n");
}
    
void print_tcp_header(const struct sniff_tcp *segment, int size)
{
    dump_hex("TCP Header", (const u_char *) segment, size);
    printf("\n");
}
    
void print_payload_content(const u_char *payload, int size)
{
    dump_hex("Payload", payload, size);
    printf("\n");
}
  
void my_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    print_pkthdr_info(header);

    const struct sniff_ethernet *ethernet;
    const struct sniff_ip *ip;
    const struct sniff_tcp *tcp;
    const char *payload;

	u_int size_ip;
	u_int size_tcp;	
	u_int size_payload;	
    
    if (packet == NULL)
    {
        printf("erreur");
        return;
    }

    printf("Start analyzing Ethernet Part\n");
    ethernet = (struct sniff_ethernet*)(packet);
    print_ethernet_header(ethernet, SIZE_ETHERNET);

    printf("Start analyzing IP Part\n");
    ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);    
    size_ip = IP_HL(ip)*4;

    if (size_ip < 20)
    {
        printf("    [-] Invalid IP header length %u bytes\n", size_ip);
        return; 
    }
  
    print_ip_header(ip, size_ip);
    

    printf("Start analyzing TCP Part\n");
    tcp = (struct sniff_tcp*)(packet + SIZE_ETHERNET + size_ip);
    size_tcp = TH_OFF(tcp)*4;
    if (size_tcp< 20)
    {
        printf("    [-] Invalid TCP header length %u bytes\n", size_ip);
        return;
    }
    print_tcp_header(tcp, size_tcp);
    
    printf("Start analyzing Application Part\n");
    payload = (u_char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);
    size_payload = header->caplen - SIZE_ETHERNET + size_ip + size_tcp;
    print_payload_content(payload, size_payload);
    return;
}


int main(int argc, char * argv[])
{
    char * device = argv[1];
    char error_buffer[PCAP_ERRBUF_SIZE];

    pcap_t * handle;
    int total_packet_count = 1;

    handle = pcap_create(device, error_buffer);
    pcap_set_timeout(handle, 10);
    pcap_activate(handle);
   
    pcap_loop(handle, total_packet_count, my_packet_handler, NULL);

}
