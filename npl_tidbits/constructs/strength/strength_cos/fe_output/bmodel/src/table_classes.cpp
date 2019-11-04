/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "table_classes.h"
#include "hash_crc.h"

#define BUCKET_SIZE    4

sfc_edb_profile_tab_t::sfc_edb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        sfc_edb_profile_entry_array[i] = new sfc_edb_profile_entry_t;
    }
}

sfc_edb_profile_tab_t::~sfc_edb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        delete sfc_edb_profile_entry_array[i];
    }
}

void sfc_edb_profile_tab_t::write_entry(_1bit *index, sfc_edb_profile_entry_t *sfc_edb_profile_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::write_entry() index = %d", (int)*index);
#endif
    sfc_edb_profile_entry_array[*index]->_VALID = sfc_edb_profile_entry->_VALID;
    sfc_edb_profile_entry_array[*index]->_INDEX = sfc_edb_profile_entry->_INDEX;
    sfc_edb_profile_entry_array[*index]->edb_index = sfc_edb_profile_entry->edb_index;
    sfc_edb_profile_entry_array[*index]->in_drop_vector = sfc_edb_profile_entry->in_drop_vector;
    sfc_edb_profile_entry_array[*index]->in_dst_mod = sfc_edb_profile_entry->in_dst_mod;
    sfc_edb_profile_entry_array[*index]->in_dst_port = sfc_edb_profile_entry->in_dst_port;
    sfc_edb_profile_entry_array[*index]->_LOOKUP0 = sfc_edb_profile_entry->_LOOKUP0;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0 = sfc_edb_profile_entry->_HIT_INDEX0;
}

void sfc_edb_profile_tab_t::find_index(sfc_edb_profile_entry_t *sfc_edb_profile_entry, int *idx, int *avbl_idx, int *pidx) {
    _1bit _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (sfc_edb_profile_entry->edb_index);
    if (sfc_edb_profile_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int sfc_edb_profile_tab_t::insert_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::insert_entry()");
#endif
    find_index(sfc_edb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::insert_entry() table full");
#endif
        return -3;
    }

    index = (_1bit) avbl_idx;
    sfc_edb_profile_entry->_VALID = 1;
    write_entry(&index, sfc_edb_profile_entry);
    return 0;
}

int sfc_edb_profile_tab_t::delete_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::delete_entry()");
#endif
    find_index(sfc_edb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    sfc_edb_profile_entry->_VALID = 0;
    write_entry(&index, sfc_edb_profile_entry);
    return 0;
}

int sfc_edb_profile_tab_t::lookup_entry(sfc_edb_profile_entry_t **sfc_edb_profile_entry) {
    sfc_edb_profile_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::lookup_entry()");
#endif
    find_index(*sfc_edb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    rentry = read_entry(&index);
    memcpy(*sfc_edb_profile_entry, rentry, sizeof(sfc_edb_profile_entry_t));
    return 0;
}

sfc_edb_profile_entry_t* sfc_edb_profile_tab_t::read_entry(_1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::read_entry() index = %d", (int)*index);
#endif
    return sfc_edb_profile_entry_array[*index];

}

sfc_edb_profile_entry_t* sfc_edb_profile_tab_t::lookup(int _lookup_idx_, _1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up sfc_edb_profile");
#endif

    sfc_edb_profile_entry_array[*index]->_INDEX = *index;
    sfc_edb_profile_entry_array[*index]->_LOOKUP0 = 1;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0(30,24) = SFC_EDB_PROFILE_ENUM;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::lookup() index = %d", (int)*index);
#endif

    return sfc_edb_profile_entry_array[*index];
}

sfc_mmu_profile_tab_t::sfc_mmu_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        sfc_mmu_profile_entry_array[i] = new sfc_mmu_profile_entry_t;
    }
}

sfc_mmu_profile_tab_t::~sfc_mmu_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        delete sfc_mmu_profile_entry_array[i];
    }
}

void sfc_mmu_profile_tab_t::write_entry(_1bit *index, sfc_mmu_profile_entry_t *sfc_mmu_profile_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::write_entry() index = %d", (int)*index);
#endif
    sfc_mmu_profile_entry_array[*index]->_VALID = sfc_mmu_profile_entry->_VALID;
    sfc_mmu_profile_entry_array[*index]->_INDEX = sfc_mmu_profile_entry->_INDEX;
    sfc_mmu_profile_entry_array[*index]->mmu_index = sfc_mmu_profile_entry->mmu_index;
    sfc_mmu_profile_entry_array[*index]->in_l2_pbm = sfc_mmu_profile_entry->in_l2_pbm;
    sfc_mmu_profile_entry_array[*index]->in_l3_pbm = sfc_mmu_profile_entry->in_l3_pbm;
    sfc_mmu_profile_entry_array[*index]->out_dst_port = sfc_mmu_profile_entry->out_dst_port;
    sfc_mmu_profile_entry_array[*index]->_LOOKUP0 = sfc_mmu_profile_entry->_LOOKUP0;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0 = sfc_mmu_profile_entry->_HIT_INDEX0;
}

void sfc_mmu_profile_tab_t::find_index(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry, int *idx, int *avbl_idx, int *pidx) {
    _1bit _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (sfc_mmu_profile_entry->mmu_index);
    if (sfc_mmu_profile_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int sfc_mmu_profile_tab_t::insert_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::insert_entry()");
#endif
    find_index(sfc_mmu_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::insert_entry() table full");
#endif
        return -3;
    }

    index = (_1bit) avbl_idx;
    sfc_mmu_profile_entry->_VALID = 1;
    write_entry(&index, sfc_mmu_profile_entry);
    return 0;
}

int sfc_mmu_profile_tab_t::delete_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::delete_entry()");
#endif
    find_index(sfc_mmu_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    sfc_mmu_profile_entry->_VALID = 0;
    write_entry(&index, sfc_mmu_profile_entry);
    return 0;
}

int sfc_mmu_profile_tab_t::lookup_entry(sfc_mmu_profile_entry_t **sfc_mmu_profile_entry) {
    sfc_mmu_profile_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::lookup_entry()");
#endif
    find_index(*sfc_mmu_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    rentry = read_entry(&index);
    memcpy(*sfc_mmu_profile_entry, rentry, sizeof(sfc_mmu_profile_entry_t));
    return 0;
}

sfc_mmu_profile_entry_t* sfc_mmu_profile_tab_t::read_entry(_1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::read_entry() index = %d", (int)*index);
#endif
    return sfc_mmu_profile_entry_array[*index];

}

sfc_mmu_profile_entry_t* sfc_mmu_profile_tab_t::lookup(int _lookup_idx_, _1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up sfc_mmu_profile");
#endif

    sfc_mmu_profile_entry_array[*index]->_INDEX = *index;
    sfc_mmu_profile_entry_array[*index]->_LOOKUP0 = 1;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0(30,24) = SFC_MMU_PROFILE_ENUM;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::lookup() index = %d", (int)*index);
#endif

    return sfc_mmu_profile_entry_array[*index];
}

sfc_iarb_profile_tab_t::sfc_iarb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        sfc_iarb_profile_entry_array[i] = new sfc_iarb_profile_entry_t;
    }
}

sfc_iarb_profile_tab_t::~sfc_iarb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        delete sfc_iarb_profile_entry_array[i];
    }
}

void sfc_iarb_profile_tab_t::write_entry(_1bit *index, sfc_iarb_profile_entry_t *sfc_iarb_profile_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::write_entry() index = %d", (int)*index);
#endif
    sfc_iarb_profile_entry_array[*index]->_VALID = sfc_iarb_profile_entry->_VALID;
    sfc_iarb_profile_entry_array[*index]->_INDEX = sfc_iarb_profile_entry->_INDEX;
    sfc_iarb_profile_entry_array[*index]->iarb_index = sfc_iarb_profile_entry->iarb_index;
    sfc_iarb_profile_entry_array[*index]->out_otpid_enable = sfc_iarb_profile_entry->out_otpid_enable;
    sfc_iarb_profile_entry_array[*index]->out_ts_enable = sfc_iarb_profile_entry->out_ts_enable;
    sfc_iarb_profile_entry_array[*index]->out_port_num = sfc_iarb_profile_entry->out_port_num;
    sfc_iarb_profile_entry_array[*index]->out_port_type_cfg = sfc_iarb_profile_entry->out_port_type_cfg;
    sfc_iarb_profile_entry_array[*index]->out_currenttime = sfc_iarb_profile_entry->out_currenttime;
    sfc_iarb_profile_entry_array[*index]->_LOOKUP0 = sfc_iarb_profile_entry->_LOOKUP0;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0 = sfc_iarb_profile_entry->_HIT_INDEX0;
}

void sfc_iarb_profile_tab_t::find_index(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry, int *idx, int *avbl_idx, int *pidx) {
    _1bit _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (sfc_iarb_profile_entry->iarb_index);
    if (sfc_iarb_profile_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int sfc_iarb_profile_tab_t::insert_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::insert_entry()");
#endif
    find_index(sfc_iarb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::insert_entry() table full");
#endif
        return -3;
    }

    index = (_1bit) avbl_idx;
    sfc_iarb_profile_entry->_VALID = 1;
    write_entry(&index, sfc_iarb_profile_entry);
    return 0;
}

int sfc_iarb_profile_tab_t::delete_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::delete_entry()");
#endif
    find_index(sfc_iarb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    sfc_iarb_profile_entry->_VALID = 0;
    write_entry(&index, sfc_iarb_profile_entry);
    return 0;
}

int sfc_iarb_profile_tab_t::lookup_entry(sfc_iarb_profile_entry_t **sfc_iarb_profile_entry) {
    sfc_iarb_profile_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::lookup_entry()");
#endif
    find_index(*sfc_iarb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    rentry = read_entry(&index);
    memcpy(*sfc_iarb_profile_entry, rentry, sizeof(sfc_iarb_profile_entry_t));
    return 0;
}

sfc_iarb_profile_entry_t* sfc_iarb_profile_tab_t::read_entry(_1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::read_entry() index = %d", (int)*index);
#endif
    return sfc_iarb_profile_entry_array[*index];

}

sfc_iarb_profile_entry_t* sfc_iarb_profile_tab_t::lookup(int _lookup_idx_, _1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up sfc_iarb_profile");
#endif

    sfc_iarb_profile_entry_array[*index]->_INDEX = *index;
    sfc_iarb_profile_entry_array[*index]->_LOOKUP0 = 1;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0(30,24) = SFC_IARB_PROFILE_ENUM;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::lookup() index = %d", (int)*index);
#endif

    return sfc_iarb_profile_entry_array[*index];
}

dscp_cos_mapping_table_tab_t::dscp_cos_mapping_table_tab_t() {
    uint i;

    max_entries = 64;
    for (i = 0; i < 64; i++) {
        dscp_cos_mapping_table_entry_array[i] = new dscp_cos_mapping_table_entry_t;
    }
}

dscp_cos_mapping_table_tab_t::~dscp_cos_mapping_table_tab_t() {
    uint i;

    max_entries = 64;
    for (i = 0; i < 64; i++) {
        delete dscp_cos_mapping_table_entry_array[i];
    }
}

void dscp_cos_mapping_table_tab_t::write_entry(_6bits *index, dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("dscp_cos_mapping_table::write_entry() index = %d", (int)*index);
#endif
    dscp_cos_mapping_table_entry_array[*index]->_VALID = dscp_cos_mapping_table_entry->_VALID;
    dscp_cos_mapping_table_entry_array[*index]->_INDEX = dscp_cos_mapping_table_entry->_INDEX;
    dscp_cos_mapping_table_entry_array[*index]->dscp = dscp_cos_mapping_table_entry->dscp;
    dscp_cos_mapping_table_entry_array[*index]->cos_strength_index = dscp_cos_mapping_table_entry->cos_strength_index;
    dscp_cos_mapping_table_entry_array[*index]->cos = dscp_cos_mapping_table_entry->cos;
    dscp_cos_mapping_table_entry_array[*index]->_LOOKUP0 = dscp_cos_mapping_table_entry->_LOOKUP0;
    dscp_cos_mapping_table_entry_array[*index]->_HIT_INDEX0 = dscp_cos_mapping_table_entry->_HIT_INDEX0;
}

void dscp_cos_mapping_table_tab_t::find_index(dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry, int *idx, int *avbl_idx, int *pidx) {
    _6bits _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (dscp_cos_mapping_table_entry->dscp);
    if (dscp_cos_mapping_table_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("dscp_cos_mapping_table::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int dscp_cos_mapping_table_tab_t::insert_entry(dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry) {
    int idx, avbl_idx, pidx;
    _6bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("dscp_cos_mapping_table::insert_entry()");
#endif
    find_index(dscp_cos_mapping_table_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("dscp_cos_mapping_table::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("dscp_cos_mapping_table::insert_entry() table full");
#endif
        return -3;
    }

    index = (_6bits) avbl_idx;
    dscp_cos_mapping_table_entry->_VALID = 1;
    write_entry(&index, dscp_cos_mapping_table_entry);
    return 0;
}

int dscp_cos_mapping_table_tab_t::delete_entry(dscp_cos_mapping_table_entry_t *dscp_cos_mapping_table_entry) {
    int idx, avbl_idx, pidx;
    _6bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("dscp_cos_mapping_table::delete_entry()");
#endif
    find_index(dscp_cos_mapping_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("dscp_cos_mapping_table::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_6bits) idx;
    dscp_cos_mapping_table_entry->_VALID = 0;
    write_entry(&index, dscp_cos_mapping_table_entry);
    return 0;
}

int dscp_cos_mapping_table_tab_t::lookup_entry(dscp_cos_mapping_table_entry_t **dscp_cos_mapping_table_entry) {
    dscp_cos_mapping_table_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _6bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("dscp_cos_mapping_table::lookup_entry()");
#endif
    find_index(*dscp_cos_mapping_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("dscp_cos_mapping_table::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_6bits) idx;
    rentry = read_entry(&index);
    memcpy(*dscp_cos_mapping_table_entry, rentry, sizeof(dscp_cos_mapping_table_entry_t));
    return 0;
}

dscp_cos_mapping_table_entry_t* dscp_cos_mapping_table_tab_t::read_entry(_6bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("dscp_cos_mapping_table::read_entry() index = %d", (int)*index);
#endif
    return dscp_cos_mapping_table_entry_array[*index];

}

dscp_cos_mapping_table_entry_t* dscp_cos_mapping_table_tab_t::lookup(int _lookup_idx_, _6bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up dscp_cos_mapping_table");
#endif

    dscp_cos_mapping_table_entry_array[*index]->_INDEX = *index;
    dscp_cos_mapping_table_entry_array[*index]->_LOOKUP0 = 1;
    dscp_cos_mapping_table_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    dscp_cos_mapping_table_entry_array[*index]->_HIT_INDEX0(30,24) = DSCP_COS_MAPPING_TABLE_ENUM;
    dscp_cos_mapping_table_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("dscp_cos_mapping_table::lookup() index = %d", (int)*index);
#endif

    return dscp_cos_mapping_table_entry_array[*index];
}

pri_cos_mapping_table_tab_t::pri_cos_mapping_table_tab_t() {
    uint i;

    max_entries = 8;
    for (i = 0; i < 8; i++) {
        pri_cos_mapping_table_entry_array[i] = new pri_cos_mapping_table_entry_t;
    }
}

pri_cos_mapping_table_tab_t::~pri_cos_mapping_table_tab_t() {
    uint i;

    max_entries = 8;
    for (i = 0; i < 8; i++) {
        delete pri_cos_mapping_table_entry_array[i];
    }
}

void pri_cos_mapping_table_tab_t::write_entry(_3bits *index, pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("pri_cos_mapping_table::write_entry() index = %d", (int)*index);
#endif
    pri_cos_mapping_table_entry_array[*index]->_VALID = pri_cos_mapping_table_entry->_VALID;
    pri_cos_mapping_table_entry_array[*index]->_INDEX = pri_cos_mapping_table_entry->_INDEX;
    pri_cos_mapping_table_entry_array[*index]->vlan_pri = pri_cos_mapping_table_entry->vlan_pri;
    pri_cos_mapping_table_entry_array[*index]->cos_strength_index = pri_cos_mapping_table_entry->cos_strength_index;
    pri_cos_mapping_table_entry_array[*index]->cos = pri_cos_mapping_table_entry->cos;
    pri_cos_mapping_table_entry_array[*index]->_LOOKUP0 = pri_cos_mapping_table_entry->_LOOKUP0;
    pri_cos_mapping_table_entry_array[*index]->_HIT_INDEX0 = pri_cos_mapping_table_entry->_HIT_INDEX0;
}

void pri_cos_mapping_table_tab_t::find_index(pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry, int *idx, int *avbl_idx, int *pidx) {
    _3bits _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (pri_cos_mapping_table_entry->vlan_pri);
    if (pri_cos_mapping_table_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("pri_cos_mapping_table::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int pri_cos_mapping_table_tab_t::insert_entry(pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry) {
    int idx, avbl_idx, pidx;
    _3bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("pri_cos_mapping_table::insert_entry()");
#endif
    find_index(pri_cos_mapping_table_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("pri_cos_mapping_table::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("pri_cos_mapping_table::insert_entry() table full");
#endif
        return -3;
    }

    index = (_3bits) avbl_idx;
    pri_cos_mapping_table_entry->_VALID = 1;
    write_entry(&index, pri_cos_mapping_table_entry);
    return 0;
}

int pri_cos_mapping_table_tab_t::delete_entry(pri_cos_mapping_table_entry_t *pri_cos_mapping_table_entry) {
    int idx, avbl_idx, pidx;
    _3bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("pri_cos_mapping_table::delete_entry()");
#endif
    find_index(pri_cos_mapping_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("pri_cos_mapping_table::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_3bits) idx;
    pri_cos_mapping_table_entry->_VALID = 0;
    write_entry(&index, pri_cos_mapping_table_entry);
    return 0;
}

int pri_cos_mapping_table_tab_t::lookup_entry(pri_cos_mapping_table_entry_t **pri_cos_mapping_table_entry) {
    pri_cos_mapping_table_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _3bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("pri_cos_mapping_table::lookup_entry()");
#endif
    find_index(*pri_cos_mapping_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("pri_cos_mapping_table::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_3bits) idx;
    rentry = read_entry(&index);
    memcpy(*pri_cos_mapping_table_entry, rentry, sizeof(pri_cos_mapping_table_entry_t));
    return 0;
}

pri_cos_mapping_table_entry_t* pri_cos_mapping_table_tab_t::read_entry(_3bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("pri_cos_mapping_table::read_entry() index = %d", (int)*index);
#endif
    return pri_cos_mapping_table_entry_array[*index];

}

pri_cos_mapping_table_entry_t* pri_cos_mapping_table_tab_t::lookup(int _lookup_idx_, _3bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up pri_cos_mapping_table");
#endif

    pri_cos_mapping_table_entry_array[*index]->_INDEX = *index;
    pri_cos_mapping_table_entry_array[*index]->_LOOKUP0 = 1;
    pri_cos_mapping_table_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    pri_cos_mapping_table_entry_array[*index]->_HIT_INDEX0(30,24) = PRI_COS_MAPPING_TABLE_ENUM;
    pri_cos_mapping_table_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("pri_cos_mapping_table::lookup() index = %d", (int)*index);
#endif

    return pri_cos_mapping_table_entry_array[*index];
}

cos_strength_profile_table_tab_t::cos_strength_profile_table_tab_t() {
    uint i;

    max_entries = 8;
    for (i = 0; i < 8; i++) {
        cos_strength_profile_table_entry_array[i] = new cos_strength_profile_table_entry_t;
    }
}

cos_strength_profile_table_tab_t::~cos_strength_profile_table_tab_t() {
    uint i;

    max_entries = 8;
    for (i = 0; i < 8; i++) {
        delete cos_strength_profile_table_entry_array[i];
    }
}

void cos_strength_profile_table_tab_t::write_entry(_3bits *index, cos_strength_profile_table_entry_t *cos_strength_profile_table_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("cos_strength_profile_table::write_entry() index = %d", (int)*index);
#endif
    cos_strength_profile_table_entry_array[*index]->_VALID = cos_strength_profile_table_entry->_VALID;
    cos_strength_profile_table_entry_array[*index]->_INDEX = cos_strength_profile_table_entry->_INDEX;
    cos_strength_profile_table_entry_array[*index]->cos_strength_profile_table_index = cos_strength_profile_table_entry->cos_strength_profile_table_index;
    cos_strength_profile_table_entry_array[*index]->cos_strength = cos_strength_profile_table_entry->cos_strength;
    cos_strength_profile_table_entry_array[*index]->_LOOKUP0 = cos_strength_profile_table_entry->_LOOKUP0;
    cos_strength_profile_table_entry_array[*index]->_HIT_INDEX0 = cos_strength_profile_table_entry->_HIT_INDEX0;
    cos_strength_profile_table_entry_array[*index]->_LOOKUP1 = cos_strength_profile_table_entry->_LOOKUP1;
    cos_strength_profile_table_entry_array[*index]->_HIT_INDEX1 = cos_strength_profile_table_entry->_HIT_INDEX1;
}

void cos_strength_profile_table_tab_t::find_index(cos_strength_profile_table_entry_t *cos_strength_profile_table_entry, int *idx, int *avbl_idx, int *pidx) {
    _3bits _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (cos_strength_profile_table_entry->cos_strength_profile_table_index);
    if (cos_strength_profile_table_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("cos_strength_profile_table::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int cos_strength_profile_table_tab_t::insert_entry(cos_strength_profile_table_entry_t *cos_strength_profile_table_entry) {
    int idx, avbl_idx, pidx;
    _3bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("cos_strength_profile_table::insert_entry()");
#endif
    find_index(cos_strength_profile_table_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("cos_strength_profile_table::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("cos_strength_profile_table::insert_entry() table full");
#endif
        return -3;
    }

    index = (_3bits) avbl_idx;
    cos_strength_profile_table_entry->_VALID = 1;
    write_entry(&index, cos_strength_profile_table_entry);
    return 0;
}

int cos_strength_profile_table_tab_t::delete_entry(cos_strength_profile_table_entry_t *cos_strength_profile_table_entry) {
    int idx, avbl_idx, pidx;
    _3bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("cos_strength_profile_table::delete_entry()");
#endif
    find_index(cos_strength_profile_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("cos_strength_profile_table::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_3bits) idx;
    cos_strength_profile_table_entry->_VALID = 0;
    write_entry(&index, cos_strength_profile_table_entry);
    return 0;
}

int cos_strength_profile_table_tab_t::lookup_entry(cos_strength_profile_table_entry_t **cos_strength_profile_table_entry) {
    cos_strength_profile_table_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _3bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("cos_strength_profile_table::lookup_entry()");
#endif
    find_index(*cos_strength_profile_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("cos_strength_profile_table::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_3bits) idx;
    rentry = read_entry(&index);
    memcpy(*cos_strength_profile_table_entry, rentry, sizeof(cos_strength_profile_table_entry_t));
    return 0;
}

cos_strength_profile_table_entry_t* cos_strength_profile_table_tab_t::read_entry(_3bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("cos_strength_profile_table::read_entry() index = %d", (int)*index);
#endif
    return cos_strength_profile_table_entry_array[*index];

}

cos_strength_profile_table_entry_t* cos_strength_profile_table_tab_t::lookup(int _lookup_idx_, _3bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up cos_strength_profile_table");
#endif

    cos_strength_profile_table_entry_array[*index]->_INDEX = *index;
    if (_lookup_idx_ == 0) {
        cos_strength_profile_table_entry_array[*index]->_LOOKUP0 = 1;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX0(30,24) = COS_STRENGTH_PROFILE_TABLE_ENUM;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
        cos_strength_profile_table_entry_array[*index]->_LOOKUP1 = 0;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX1 = 0;
    } else if (_lookup_idx_ == 1) {
        cos_strength_profile_table_entry_array[*index]->_LOOKUP1 = 1;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX1(31,31) = 1;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX1(30,24) = COS_STRENGTH_PROFILE_TABLE_ENUM;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX1(23,0) = *index;
        cos_strength_profile_table_entry_array[*index]->_LOOKUP0 = 0;
        cos_strength_profile_table_entry_array[*index]->_HIT_INDEX0 = 0;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("cos_strength_profile_table::lookup() index = %d", (int)*index);
#endif

    return cos_strength_profile_table_entry_array[*index];
}

