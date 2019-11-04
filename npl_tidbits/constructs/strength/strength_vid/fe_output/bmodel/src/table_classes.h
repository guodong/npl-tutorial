/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _TABLE_CLASSES
#define _TABLE_CLASSES

#include "bit_types.h"

#include "table_entry_classes.h"

typedef enum _table_enums_e_ {
    VLAN_PROTOCOL_TABLE_ENUM,
    SFC_EDB_PROFILE_ENUM,
    SFC_MMU_PROFILE_ENUM,
    SFC_IARB_PROFILE_ENUM,
    VLAN_STRENGTH_PROFILE_TABLE_ENUM,
    PORT_TABLE_ENUM,
} _table_enums_t_;

class vlan_protocol_table_tab_t {
public:
    vlan_protocol_table_entry_t *vlan_protocol_table_entry_array[2];
    uint max_entries;

    vlan_protocol_table_tab_t(void);
    ~vlan_protocol_table_tab_t(void);

    void write_entry(_1bit *index, vlan_protocol_table_entry_t *vlan_protocol_table_entry);
    void find_index(vlan_protocol_table_entry_t *vlan_protocol_table_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(vlan_protocol_table_entry_t *vlan_protocol_table_entry);
    int delete_entry(vlan_protocol_table_entry_t *vlan_protocol_table_entry);
    int lookup_entry(vlan_protocol_table_entry_t **vlan_protocol_table_entry);
    vlan_protocol_table_entry_t* read_entry(_1bit *index);
    vlan_protocol_table_entry_t* lookup(int _lookup_idx_, _1bit *index);
};

class sfc_edb_profile_tab_t {
public:
    sfc_edb_profile_entry_t *sfc_edb_profile_entry_array[2];
    uint max_entries;

    sfc_edb_profile_tab_t(void);
    ~sfc_edb_profile_tab_t(void);

    void write_entry(_1bit *index, sfc_edb_profile_entry_t *sfc_edb_profile_entry);
    void find_index(sfc_edb_profile_entry_t *sfc_edb_profile_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry);
    int delete_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry);
    int lookup_entry(sfc_edb_profile_entry_t **sfc_edb_profile_entry);
    sfc_edb_profile_entry_t* read_entry(_1bit *index);
    sfc_edb_profile_entry_t* lookup(int _lookup_idx_, _1bit *index);
};

class sfc_mmu_profile_tab_t {
public:
    sfc_mmu_profile_entry_t *sfc_mmu_profile_entry_array[2];
    uint max_entries;

    sfc_mmu_profile_tab_t(void);
    ~sfc_mmu_profile_tab_t(void);

    void write_entry(_1bit *index, sfc_mmu_profile_entry_t *sfc_mmu_profile_entry);
    void find_index(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry);
    int delete_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry);
    int lookup_entry(sfc_mmu_profile_entry_t **sfc_mmu_profile_entry);
    sfc_mmu_profile_entry_t* read_entry(_1bit *index);
    sfc_mmu_profile_entry_t* lookup(int _lookup_idx_, _1bit *index);
};

class sfc_iarb_profile_tab_t {
public:
    sfc_iarb_profile_entry_t *sfc_iarb_profile_entry_array[2];
    uint max_entries;

    sfc_iarb_profile_tab_t(void);
    ~sfc_iarb_profile_tab_t(void);

    void write_entry(_1bit *index, sfc_iarb_profile_entry_t *sfc_iarb_profile_entry);
    void find_index(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry);
    int delete_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry);
    int lookup_entry(sfc_iarb_profile_entry_t **sfc_iarb_profile_entry);
    sfc_iarb_profile_entry_t* read_entry(_1bit *index);
    sfc_iarb_profile_entry_t* lookup(int _lookup_idx_, _1bit *index);
};

class vlan_strength_profile_table_tab_t {
public:
    vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry_array[4];
    uint max_entries;

    vlan_strength_profile_table_tab_t(void);
    ~vlan_strength_profile_table_tab_t(void);

    void write_entry(_2bits *index, vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry);
    void find_index(vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry);
    int delete_entry(vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry);
    int lookup_entry(vlan_strength_profile_table_entry_t **vlan_strength_profile_table_entry);
    vlan_strength_profile_table_entry_t* read_entry(_2bits *index);
    vlan_strength_profile_table_entry_t* lookup(int _lookup_idx_, _2bits *index);
};

class port_table_tab_t {
public:
    port_table_entry_t *port_table_entry_array[128];
    uint max_entries;

    port_table_tab_t(void);
    ~port_table_tab_t(void);

    void write_entry(_7bits *index, port_table_entry_t *port_table_entry);
    void find_index(port_table_entry_t *port_table_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(port_table_entry_t *port_table_entry);
    int delete_entry(port_table_entry_t *port_table_entry);
    int lookup_entry(port_table_entry_t **port_table_entry);
    port_table_entry_t* read_entry(_7bits *index);
    port_table_entry_t* lookup(int _lookup_idx_, _7bits *index);
};

#endif
