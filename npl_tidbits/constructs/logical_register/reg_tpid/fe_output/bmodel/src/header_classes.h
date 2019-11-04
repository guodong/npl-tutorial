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

class vlan_t : public header_base_t {
public:
    _3bits pcp;
    _1bit cfi;
    _12bits vid;
    _16bits ether_type;

    vlan_t(void);
    ~vlan_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(vlan_t *ref);
};

class grp_t {
public:
    ethernet_t *ether;
    vlan_t *vlan;

    void set_ether(ethernet_t *ref);
    void set_vlan(vlan_t *ref);

    grp_t(void);
    ~grp_t(void);

    void set_resetval();
    void deep_copy(grp_t *ref);
};

class ingress_pkt_t : public packet_base_t {
public:
    _2bits _match_id;
    grp_t *group;

    void set_group(grp_t *ref);

    ingress_pkt_t(void);
    ~ingress_pkt_t(void);

    void set_resetval();
    void deep_copy(ingress_pkt_t *ref);
};

#endif
