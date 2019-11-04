/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "table_classes.h"
#include "hash_crc.h"

#define BUCKET_SIZE    4

vlan_protocol_table_tab_t::vlan_protocol_table_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        vlan_protocol_table_entry_array[i] = new vlan_protocol_table_entry_t;
    }
}

vlan_protocol_table_tab_t::~vlan_protocol_table_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        delete vlan_protocol_table_entry_array[i];
    }
}

void vlan_protocol_table_tab_t::write_entry(_1bit *index, vlan_protocol_table_entry_t *vlan_protocol_table_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_protocol_table::write_entry() index = %d", (int)*index);
#endif
    vlan_protocol_table_entry_array[*index]->_VALID = vlan_protocol_table_entry->_VALID;
    vlan_protocol_table_entry_array[*index]->_INDEX = vlan_protocol_table_entry->_INDEX;
    vlan_protocol_table_entry_array[*index]->pkt_protocol = vlan_protocol_table_entry->pkt_protocol;
    vlan_protocol_table_entry_array[*index]->vid = vlan_protocol_table_entry->vid;
    vlan_protocol_table_entry_array[*index]->_LOOKUP0 = vlan_protocol_table_entry->_LOOKUP0;
    vlan_protocol_table_entry_array[*index]->_HIT_INDEX0 = vlan_protocol_table_entry->_HIT_INDEX0;
}

void vlan_protocol_table_tab_t::find_index(vlan_protocol_table_entry_t *vlan_protocol_table_entry, int *idx, int *avbl_idx, int *pidx) {
    _1bit _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (vlan_protocol_table_entry->pkt_protocol);
    if (vlan_protocol_table_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_protocol_table::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int vlan_protocol_table_tab_t::insert_entry(vlan_protocol_table_entry_t *vlan_protocol_table_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_protocol_table::insert_entry()");
#endif
    find_index(vlan_protocol_table_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_protocol_table::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_protocol_table::insert_entry() table full");
#endif
        return -3;
    }

    index = (_1bit) avbl_idx;
    vlan_protocol_table_entry->_VALID = 1;
    write_entry(&index, vlan_protocol_table_entry);
    return 0;
}

int vlan_protocol_table_tab_t::delete_entry(vlan_protocol_table_entry_t *vlan_protocol_table_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_protocol_table::delete_entry()");
#endif
    find_index(vlan_protocol_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_protocol_table::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    vlan_protocol_table_entry->_VALID = 0;
    write_entry(&index, vlan_protocol_table_entry);
    return 0;
}

int vlan_protocol_table_tab_t::lookup_entry(vlan_protocol_table_entry_t **vlan_protocol_table_entry) {
    vlan_protocol_table_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_protocol_table::lookup_entry()");
#endif
    find_index(*vlan_protocol_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_protocol_table::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    rentry = read_entry(&index);
    memcpy(*vlan_protocol_table_entry, rentry, sizeof(vlan_protocol_table_entry_t));
    return 0;
}

vlan_protocol_table_entry_t* vlan_protocol_table_tab_t::read_entry(_1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_protocol_table::read_entry() index = %d", (int)*index);
#endif
    return vlan_protocol_table_entry_array[*index];

}

vlan_protocol_table_entry_t* vlan_protocol_table_tab_t::lookup(int _lookup_idx_, _1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up vlan_protocol_table");
#endif

    vlan_protocol_table_entry_array[*index]->_INDEX = *index;
    vlan_protocol_table_entry_array[*index]->_LOOKUP0 = 1;
    vlan_protocol_table_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    vlan_protocol_table_entry_array[*index]->_HIT_INDEX0(30,24) = VLAN_PROTOCOL_TABLE_ENUM;
    vlan_protocol_table_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_protocol_table::lookup() index = %d", (int)*index);
#endif

    return vlan_protocol_table_entry_array[*index];
}

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

vlan_strength_profile_table_tab_t::vlan_strength_profile_table_tab_t() {
    uint i;

    max_entries = 4;
    for (i = 0; i < 4; i++) {
        vlan_strength_profile_table_entry_array[i] = new vlan_strength_profile_table_entry_t;
    }
}

vlan_strength_profile_table_tab_t::~vlan_strength_profile_table_tab_t() {
    uint i;

    max_entries = 4;
    for (i = 0; i < 4; i++) {
        delete vlan_strength_profile_table_entry_array[i];
    }
}

void vlan_strength_profile_table_tab_t::write_entry(_2bits *index, vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_strength_profile_table::write_entry() index = %d", (int)*index);
#endif
    vlan_strength_profile_table_entry_array[*index]->_VALID = vlan_strength_profile_table_entry->_VALID;
    vlan_strength_profile_table_entry_array[*index]->_INDEX = vlan_strength_profile_table_entry->_INDEX;
    vlan_strength_profile_table_entry_array[*index]->vlan_strength_profile_table_index = vlan_strength_profile_table_entry->vlan_strength_profile_table_index;
    vlan_strength_profile_table_entry_array[*index]->vlan_strength = vlan_strength_profile_table_entry->vlan_strength;
    vlan_strength_profile_table_entry_array[*index]->_LOOKUP0 = vlan_strength_profile_table_entry->_LOOKUP0;
    vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX0 = vlan_strength_profile_table_entry->_HIT_INDEX0;
    vlan_strength_profile_table_entry_array[*index]->_LOOKUP1 = vlan_strength_profile_table_entry->_LOOKUP1;
    vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX1 = vlan_strength_profile_table_entry->_HIT_INDEX1;
}

void vlan_strength_profile_table_tab_t::find_index(vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry, int *idx, int *avbl_idx, int *pidx) {
    _2bits _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (vlan_strength_profile_table_entry->vlan_strength_profile_table_index);
    if (vlan_strength_profile_table_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_strength_profile_table::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int vlan_strength_profile_table_tab_t::insert_entry(vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry) {
    int idx, avbl_idx, pidx;
    _2bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_strength_profile_table::insert_entry()");
#endif
    find_index(vlan_strength_profile_table_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_strength_profile_table::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_strength_profile_table::insert_entry() table full");
#endif
        return -3;
    }

    index = (_2bits) avbl_idx;
    vlan_strength_profile_table_entry->_VALID = 1;
    write_entry(&index, vlan_strength_profile_table_entry);
    return 0;
}

int vlan_strength_profile_table_tab_t::delete_entry(vlan_strength_profile_table_entry_t *vlan_strength_profile_table_entry) {
    int idx, avbl_idx, pidx;
    _2bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_strength_profile_table::delete_entry()");
#endif
    find_index(vlan_strength_profile_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_strength_profile_table::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_2bits) idx;
    vlan_strength_profile_table_entry->_VALID = 0;
    write_entry(&index, vlan_strength_profile_table_entry);
    return 0;
}

int vlan_strength_profile_table_tab_t::lookup_entry(vlan_strength_profile_table_entry_t **vlan_strength_profile_table_entry) {
    vlan_strength_profile_table_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _2bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_strength_profile_table::lookup_entry()");
#endif
    find_index(*vlan_strength_profile_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("vlan_strength_profile_table::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_2bits) idx;
    rentry = read_entry(&index);
    memcpy(*vlan_strength_profile_table_entry, rentry, sizeof(vlan_strength_profile_table_entry_t));
    return 0;
}

vlan_strength_profile_table_entry_t* vlan_strength_profile_table_tab_t::read_entry(_2bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_strength_profile_table::read_entry() index = %d", (int)*index);
#endif
    return vlan_strength_profile_table_entry_array[*index];

}

vlan_strength_profile_table_entry_t* vlan_strength_profile_table_tab_t::lookup(int _lookup_idx_, _2bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up vlan_strength_profile_table");
#endif

    vlan_strength_profile_table_entry_array[*index]->_INDEX = *index;
    if (_lookup_idx_ == 0) {
        vlan_strength_profile_table_entry_array[*index]->_LOOKUP0 = 1;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX0(30,24) = VLAN_STRENGTH_PROFILE_TABLE_ENUM;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
        vlan_strength_profile_table_entry_array[*index]->_LOOKUP1 = 0;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX1 = 0;
    } else if (_lookup_idx_ == 1) {
        vlan_strength_profile_table_entry_array[*index]->_LOOKUP1 = 1;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX1(31,31) = 1;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX1(30,24) = VLAN_STRENGTH_PROFILE_TABLE_ENUM;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX1(23,0) = *index;
        vlan_strength_profile_table_entry_array[*index]->_LOOKUP0 = 0;
        vlan_strength_profile_table_entry_array[*index]->_HIT_INDEX0 = 0;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("vlan_strength_profile_table::lookup() index = %d", (int)*index);
#endif

    return vlan_strength_profile_table_entry_array[*index];
}

port_table_tab_t::port_table_tab_t() {
    uint i;

    max_entries = 128;
    for (i = 0; i < 128; i++) {
        port_table_entry_array[i] = new port_table_entry_t;
    }
}

port_table_tab_t::~port_table_tab_t() {
    uint i;

    max_entries = 128;
    for (i = 0; i < 128; i++) {
        delete port_table_entry_array[i];
    }
}

void port_table_tab_t::write_entry(_7bits *index, port_table_entry_t *port_table_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("port_table::write_entry() index = %d", (int)*index);
#endif
    port_table_entry_array[*index]->_VALID = port_table_entry->_VALID;
    port_table_entry_array[*index]->_INDEX = port_table_entry->_INDEX;
    port_table_entry_array[*index]->port_num = port_table_entry->port_num;
    port_table_entry_array[*index]->default_vid = port_table_entry->default_vid;
    port_table_entry_array[*index]->_LOOKUP0 = port_table_entry->_LOOKUP0;
    port_table_entry_array[*index]->_HIT_INDEX0 = port_table_entry->_HIT_INDEX0;
}

void port_table_tab_t::find_index(port_table_entry_t *port_table_entry, int *idx, int *avbl_idx, int *pidx) {
    _7bits _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (port_table_entry->port_num);
    if (port_table_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("port_table::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int port_table_tab_t::insert_entry(port_table_entry_t *port_table_entry) {
    int idx, avbl_idx, pidx;
    _7bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("port_table::insert_entry()");
#endif
    find_index(port_table_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("port_table::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("port_table::insert_entry() table full");
#endif
        return -3;
    }

    index = (_7bits) avbl_idx;
    port_table_entry->_VALID = 1;
    write_entry(&index, port_table_entry);
    return 0;
}

int port_table_tab_t::delete_entry(port_table_entry_t *port_table_entry) {
    int idx, avbl_idx, pidx;
    _7bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("port_table::delete_entry()");
#endif
    find_index(port_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("port_table::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_7bits) idx;
    port_table_entry->_VALID = 0;
    write_entry(&index, port_table_entry);
    return 0;
}

int port_table_tab_t::lookup_entry(port_table_entry_t **port_table_entry) {
    port_table_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _7bits index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("port_table::lookup_entry()");
#endif
    find_index(*port_table_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("port_table::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_7bits) idx;
    rentry = read_entry(&index);
    memcpy(*port_table_entry, rentry, sizeof(port_table_entry_t));
    return 0;
}

port_table_entry_t* port_table_tab_t::read_entry(_7bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("port_table::read_entry() index = %d", (int)*index);
#endif
    return port_table_entry_array[*index];

}

port_table_entry_t* port_table_tab_t::lookup(int _lookup_idx_, _7bits *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up port_table");
#endif

    port_table_entry_array[*index]->_INDEX = *index;
    port_table_entry_array[*index]->_LOOKUP0 = 1;
    port_table_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    port_table_entry_array[*index]->_HIT_INDEX0(30,24) = PORT_TABLE_ENUM;
    port_table_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("port_table::lookup() index = %d", (int)*index);
#endif

    return port_table_entry_array[*index];
}

