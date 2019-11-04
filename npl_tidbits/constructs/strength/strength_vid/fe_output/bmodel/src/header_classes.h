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

class snap_t : public header_base_t {
public:
    _48bits oui;
    _16bits ethertype;

    snap_t(void);
    ~snap_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(snap_t *ref);
};

class snap_llc_t : public header_base_t {
public:
    _48bits snap_llc;

    snap_llc_t(void);
    ~snap_llc_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(snap_llc_t *ref);
};

class llc_t : public header_base_t {
public:
    _24bits llc;

    llc_t(void);
    ~llc_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(llc_t *ref);
};

class group1_t {
public:
    l2_t *l2;
    vlan_t *vlan_tag;
    snap_t *snap;
    llc_t *llc;
    snap_llc_t *snap_or_llc;

    void set_l2(l2_t *ref);
    void set_vlan_tag(vlan_t *ref);
    void set_snap(snap_t *ref);
    void set_llc(llc_t *ref);
    void set_snap_or_llc(snap_llc_t *ref);

    group1_t(void);
    ~group1_t(void);

    void set_resetval();
    void deep_copy(group1_t *ref);
};

class ing_pkt_t : public packet_base_t {
public:
    _5bits _match_id;
    group1_t *group1;

    void set_group1(group1_t *ref);

    ing_pkt_t(void);
    ~ing_pkt_t(void);

    void set_resetval();
    void deep_copy(ing_pkt_t *ref);
};

#endif
