/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _HEADER_CLASSES
#define _HEADER_CLASSES

#include "global_var.h"
#include "header_base_class.h"
#include "bit_types.h"

class l2_t : public header_base_t {
public:
    _48bits macda;
    _48bits macsa;
    _16bits ethertype;

    l2_t(void);
    ~l2_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(l2_t *ref);
};

class vlan_t : public header_base_t {
public:
    _3bits pcp;
    _1bit cfi;
    _12bits vid;
    _16bits ethertype;

    vlan_t(void);
    ~vlan_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(vlan_t *ref);
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
    _32bits sip;
    _32bits dip;
    _512bits option;

    ipv4_t(void);
    ~ipv4_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(ipv4_t *ref);
};

class group1_t {
public:
    l2_t *l2;
    vlan_t *vlan_tag;

    void set_l2(l2_t *ref);
    void set_vlan_tag(vlan_t *ref);

    group1_t(void);
    ~group1_t(void);

    void set_resetval();
    void deep_copy(group1_t *ref);
};

class group2_t {
public:
    ipv4_t *ipv4;

    void set_ipv4(ipv4_t *ref);

    group2_t(void);
    ~group2_t(void);

    void set_resetval();
    void deep_copy(group2_t *ref);
};

class ing_pkt_t : public packet_base_t {
public:
    _3bits _match_id;
    group2_t *group2;
    group1_t *group1;

    void set_group2(group2_t *ref);
    void set_group1(group1_t *ref);

    ing_pkt_t(void);
    ~ing_pkt_t(void);

    void set_resetval();
    void deep_copy(ing_pkt_t *ref);
};

#endif