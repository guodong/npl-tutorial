/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _TABLE_CLASSES
#define _TABLE_CLASSES

#include "bit_types.h"

#include "table_entry_classes.h"

typedef enum _table_enums_e_ {
    SFC_EDB_PROFILE_ENUM,
    SFC_MMU_PROFILE_ENUM,
    SFC_IARB_PROFILE_ENUM,
    DSCP_COS_MAPPING_TABLE_ENUM,
    PRI_COS_MAPPING_TABLE_ENUM,
    COS_STRENGTH_PROFILE_TABLE_ENUM,
} _table_enums_t_;

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

class dscp_cos_mapping_table_tab_t {
public:
    dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry_array[64];
    uint max_entries;

    dscp_cos_mapping_table_tab_t(void);
    ~dscp_cos_mapping_table_tab_t(void);

    void write_entry(_6bits *index, dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry);
    void find_index(dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry);
    int delete_entry(dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry);
    int lookup_entry(dscp_cos_mapping_table_entry_t **dscp_cos_mapping_table_entry);
    dscp_cos_mapping_table_entry_t* read_entry(_6bits *index);
    dscp_cos_mapping_table_entry_t* lookup(int _lookup_idx_, _6bits *index);
};

class pri_cos_mapping_table_tab_t {
public:
    pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry_array[8];
    uint max_entries;

    pri_cos_mapping_table_tab_t(void);
    ~pri_cos_mapping_table_tab_t(void);

    void write_entry(_3bits *index, pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry);
    void find_index(pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry);
    int delete_entry(pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry);
    int lookup_entry(pri_cos_mapping_table_entry_t **pri_cos_mapping_table_entry);
    pri_cos_mapping_table_entry_t* read_entry(_3bits *index);
    pri_cos_mapping_table_entry_t* lookup(int _lookup_idx_, _3bits *index);
};

class cos_strength_profile_table_tab_t {
public:
    cos_strength_profile_table_entry_t *cos_strength_profile_table_entry_array[8];
    uint max_entries;

    cos_strength_profile_table_tab_t(void);
    ~cos_strength_profile_table_tab_t(void);

    void write_entry(_3bits *index, cos_strength_profile_table_entry_t *cos_strength_profile_table_entry);
    void find_index(cos_strength_profile_table_entry_t *cos_strength_profile_table_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(cos_strength_profile_table_entry_t *cos_strength_profile_table_entry);
    int delete_entry(cos_strength_profile_table_entry_t *cos_strength_profile_table_entry);
    int lookup_entry(cos_strength_profile_table_entry_t **cos_strength_profile_table_entry);
    cos_strength_profile_table_entry_t* read_entry(_3bits *index);
    cos_strength_profile_table_entry_t* lookup(int _lookup_idx_, _3bits *index);
};

#endif
