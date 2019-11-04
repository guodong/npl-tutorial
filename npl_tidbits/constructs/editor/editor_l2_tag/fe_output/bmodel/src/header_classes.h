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

class grp_t {
public:
    vlan_t *outer_tag;
    vlan_t *inner_tag;
    l2_t *l2;

    void set_outer_tag(vlan_t *ref);
    void set_inner_tag(vlan_t *ref);
    void set_l2(l2_t *ref);

    grp_t(void);
    ~grp_t(void);

    void set_resetval();
    void deep_copy(grp_t *ref);
};

class ing_pkt_t : public packet_base_t {
public:
    _3bits _match_id;
    grp_t *grp;

    void set_grp(grp_t *ref);

    ing_pkt_t(void);
    ~ing_pkt_t(void);

    void set_resetval();
    void deep_copy(ing_pkt_t *ref);
};

class egr_pkt_t : public packet_base_t {
public:
    _3bits _match_id;
    grp_t *grp;

    void set_grp(grp_t *ref);

    egr_pkt_t(void);
    ~egr_pkt_t(void);

    void set_resetval();
    void deep_copy(egr_pkt_t *ref);
};

#endif
