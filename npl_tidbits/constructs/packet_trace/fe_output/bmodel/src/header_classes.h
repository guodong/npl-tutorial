/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _HEADER_CLASSES
#define _HEADER_CLASSES

#include "global_var.h"
#include "header_base_class.h"
#include "bit_types.h"

class ethernet_t : public header_base_t {
public:
    _48bits macda;
    _48bits macsa;
    _16bits ether_type;

    ethernet_t(void);
    ~ethernet_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(ethernet_t *ref);
};

class ipv4_t : public header_base_t {
public:
    _4bits version;
    _4bits hdr_len;
    _8bits tos;
    _16bits v4_length;
    _16bits id;
    _3bits flags;
    _13bits frag_offset;
    _8bits ttl;
    _8bits protocol;
    _16bits hdr_checksum;
    _32bits sa;
    _32bits da;
    _512bits option;

    ipv4_t(void);
    ~ipv4_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(ipv4_t *ref);
};

class group_t {
public:
    ethernet_t *ether;
    ipv4_t *ipv4;

    void set_ether(ethernet_t *ref);
    void set_ipv4(ipv4_t *ref);

    group_t(void);
    ~group_t(void);

    void set_resetval();
    void deep_copy(group_t *ref);
};

class ingress_pkt_t : public packet_base_t {
public:
    _2bits _match_id;
    group_t *group;

    void set_group(group_t *ref);

    ingress_pkt_t(void);
    ~ingress_pkt_t(void);

    void set_resetval();
    void deep_copy(ingress_pkt_t *ref);
};

#endif
