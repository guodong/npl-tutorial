/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _TABLE_ENTRY_CLASSES
#define _TABLE_ENTRY_CLASSES

#include "bit_types.h"
#include "format_classes.h"

class vlan_protocol_table_entry_t {
public:
    _1bit _VALID;
    _1bit _INDEX;
    _1bit pkt_protocol;
    _12bits vid;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_1bit, int, int);
    void set_pkt_protocol(_1bit, int, int);
    void set_vid(_12bits, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    vlan_protocol_table_entry_t(void);
    ~vlan_protocol_table_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

class sfc_edb_profile_entry_t {
public:
    _1bit _VALID;
    _1bit _INDEX;
    _1bit edb_index;
    void* in_drop_vector;
    void* in_dst_mod;
    void* in_dst_port;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_1bit, int, int);
    void set_edb_index(_1bit, int, int);
    void set_in_drop_vector(void*, int, int);
    void set_in_dst_mod(void*, int, int);
    void set_in_dst_port(void*, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    sfc_edb_profile_entry_t(void);
    ~sfc_edb_profile_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

class sfc_mmu_profile_entry_t {
public:
    _1bit _VALID;
    _1bit _INDEX;
    _1bit mmu_index;
    void* in_l2_pbm;
    void* in_l3_pbm;
    void* out_dst_port;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_1bit, int, int);
    void set_mmu_index(_1bit, int, int);
    void set_in_l2_pbm(void*, int, int);
    void set_in_l3_pbm(void*, int, int);
    void set_out_dst_port(void*, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    sfc_mmu_profile_entry_t(void);
    ~sfc_mmu_profile_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

class sfc_iarb_profile_entry_t {
public:
    _1bit _VALID;
    _1bit _INDEX;
    _1bit iarb_index;
    void* out_otpid_enable;
    void* out_ts_enable;
    void* out_port_num;
    void* out_port_type_cfg;
    void* out_currenttime;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_1bit, int, int);
    void set_iarb_index(_1bit, int, int);
    void set_out_otpid_enable(void*, int, int);
    void set_out_ts_enable(void*, int, int);
    void set_out_port_num(void*, int, int);
    void set_out_port_type_cfg(void*, int, int);
    void set_out_currenttime(void*, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    sfc_iarb_profile_entry_t(void);
    ~sfc_iarb_profile_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

class vlan_strength_profile_table_entry_t {
public:
    _1bit _VALID;
    _2bits _INDEX;
    _2bits vlan_strength_profile_table_index;
    _4bits vlan_strength;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;
    _1bit _LOOKUP1;
    _32bits _HIT_INDEX1;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_2bits, int, int);
    void set_vlan_strength_profile_table_index(_2bits, int, int);
    void set_vlan_strength(_4bits, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    void set__LOOKUP1(_1bit, int, int);
    void set__HIT_INDEX1(_32bits, int, int);
    vlan_strength_profile_table_entry_t(void);
    ~vlan_strength_profile_table_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

class port_table_entry_t {
public:
    _1bit _VALID;
    _7bits _INDEX;
    _7bits port_num;
    _12bits default_vid;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_7bits, int, int);
    void set_port_num(_7bits, int, int);
    void set_default_vid(_12bits, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    port_table_entry_t(void);
    ~port_table_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

#endif
